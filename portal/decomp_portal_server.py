#!/usr/bin/env python3
"""
Scarface: The World Is Yours — matching-decompilation portal server.

    python portal/decomp_portal_server.py      (Windows; opens http://127.0.0.1:8085)
    python3 portal/decomp_portal_server.py    (Linux/macOS; runs cl.exe under Wine)

Environment variables:
    SCARFACE_HOST         interface to listen on (default 127.0.0.1 — local only)
    SCARFACE_PORT         port (default 8085)
    SCARFACE_MAINTAINERS  comma-separated handles allowed to use "Sync to GitHub"
    SCARFACE_NO_BROWSER   set to 1 to not open a browser on start
    SCARFACE_REPO_URL     GitHub page linked from the site (default: this checkout's "origin" remote)

Verification rules live in portal/tools/msvc_verify.py and are shared with portal/verify.py and
portal/scripts/reverify_all.py. Progress and the leaderboard are computed from
reports/verified_registry.json — never from hard-coded numbers.
"""

from __future__ import annotations

import base64
import datetime as dt
import hashlib
import hmac
import json
import os
import queue as queue_mod
import re
import secrets
import struct
import subprocess
import sys
import threading
import time
import urllib.error
import urllib.parse
import urllib.request
from collections import Counter
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from typing import Dict, List, Optional, Tuple

PORTAL_DIR = Path(__file__).resolve().parent         # portal/: the server, its page and tools
BASE_DIR = PORTAL_DIR.parent                          # the project folder: binaries/, reports/, ...
sys.path.insert(0, str(PORTAL_DIR / "tools"))

import msvc_verify as MV  # noqa: E402
from disasm_synth import disassemble, synthesize_cpp  # noqa: E402
import decompme as DME  # noqa: E402
import lookalikes as LA  # noqa: E402
import game_files as GF  # noqa: E402
import names as NAMES  # noqa: E402
import good_first as GOOD  # noqa: E402
import discord_feed as DISCORD  # noqa: E402
import media as MEDIA  # noqa: E402
import p3d_gltf as P3G  # noqa: E402
import blender_export as BX  # noqa: E402
import movies as MOVIES  # noqa: E402
import textures as TEXTURES  # noqa: E402
import game_assets as GA  # noqa: E402
import web_security as WS  # noqa: E402
sys.path.insert(0, str(PORTAL_DIR / "scripts"))
import extract_scripts as ES  # noqa: E402
import registry_outputs as RO  # noqa: E402
from registry_outputs import write_outputs  # noqa: E402
from sf_binaries import BinaryImage  # noqa: E402
import ps2_binary as PB  # noqa: E402
import ps2_overlay as PO  # noqa: E402
import ps2_verify as PV  # noqa: E402
from cpp_policy import check_genuine_cpp, format_violations  # noqa: E402

BINARIES = {
    "pc": BASE_DIR / "binaries" / "Scarface.exe",
    "xb": BASE_DIR / "binaries" / "default.xbe",
    "proto": BASE_DIR / "binaries" / "game.xbe",
    "ps2": BASE_DIR / "binaries" / "SLUS_211.11",
    # the PS2 program's code overlays, copied out of the PS2 disc at start (portal/scripts/extract_scripts.py)
    **{o.bin: PO.path_for(BASE_DIR / "binaries", o.bin) for o in PO.OVERLAYS},
}
RECON_DIR = BASE_DIR / "reconstructed_src"
REPORTS_DIR = BASE_DIR / "reports"
PRIVATE_DIR = PORTAL_DIR / "private"                   # gitignored
AUTH_JSON = PRIVATE_DIR / "contributor_tokens.json"
LEGACY_AUTH_JSON = REPORTS_DIR / "contributor_tokens.json"
REGISTRY_JSON = REPORTS_DIR / "verified_registry.json"
QUEUE_JSON = REPORTS_DIR / "full_remaining_queue.json"
OVERLAY_JSON = REPORTS_DIR / "task_progress_state.json"
AUDIT_JSON = REPORTS_DIR / "decomp_audit_log.json"
PARTIAL_CPP = RECON_DIR / "Partial_Proven_Checkpoints.cpp"
INDEX_HTML = PORTAL_DIR / "website_kit" / "index.html"
HANDOFF_MD = BASE_DIR / "docs" / "SCARFACE_DECOMP_AI_HANDOFF.md"
INCLUDE_DIR = RECON_DIR / "include"
SCRIPTS_DIR = BASE_DIR / "binaries" / "scripts_and_data"
# Sounds, textures, models, videos: copied out of the person's own game files, for their own use only
GAME_FILES = GA.Job(BASE_DIR / "binaries")
BLENDER = BX.CityJob(BASE_DIR / "binaries")


class _Kept:
    """The last few decoded sounds (or made movies), up to a size, the most recently used kept."""

    def __init__(self, limit: int):
        self.limit, self.size, self._items, self._lock = limit, 0, {}, threading.Lock()

    def get(self, key):
        with self._lock:
            hit = self._items.pop(key, None)
            if hit is not None:
                self._items[key] = hit                  # most recently used last
            return hit[0] if hit is not None else None

    def put(self, key, value, size: int) -> None:
        with self._lock:
            old = self._items.pop(key, None)
            if old is not None:
                self.size -= old[1]
            self._items[key] = (value, size)
            self.size += size
            while self.size > self.limit and len(self._items) > 1:
                _k, (_v, n) = next(iter(self._items.items()))
                del self._items[_k]
                self.size -= n


SOUNDS = _Kept(400 << 20)
MOVIES_JOB = MOVIES.MovieJob(BASE_DIR / "binaries")
TEXTURE_JOB = TEXTURES.TextureJob(BASE_DIR / "binaries")
SPEED_FILE = BASE_DIR / "binaries" / "portal_speed.json"


def _an_hour(h) -> bool:
    return isinstance(h, (int, float)) and not isinstance(h, bool) and 0 <= h <= 24


def speed_settings() -> dict:
    """The Speed switches (binaries/portal_speed.json): every processor core, and the graphics card; and the
    In Blender box's choices: the Xbox tones, frames a second, and the city's time of day (None: as stored) and weather."""
    try:
        d = json.loads(SPEED_FILE.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        d = {}
    return {"cores": d.get("cores") is not False, "gpu": d.get("gpu") is not False, "xbox_look": d.get("xbox_look") is True,
            "fps": d.get("fps") if d.get("fps") in BX.FRAME_RATES else 30,
            "city_hour": d.get("city_hour") if _an_hour(d.get("city_hour")) else None,
            "city_weather": "rain" if d.get("city_weather") == "rain" else "clear"}


def apply_texture_look(on: bool) -> None:
    """Exports for Blender give PC textures the Xbox's tones when on. Kept in the environment so the city
    export's helper processes, started from this one, do the same."""
    if on:
        os.environ[BX.P3G.LOOK_ENV] = "xbox"
    else:
        os.environ.pop(BX.P3G.LOOK_ENV, None)


GAME_FILES.use_cores = lambda: speed_settings()["cores"]
BLENDER.use_cores = lambda: speed_settings()["cores"]
MOVIES_JOB.use_gpu = lambda: speed_settings()["gpu"]
apply_texture_look(speed_settings()["xbox_look"])
# a copy moves the files the exports read: never at the same time
GAME_FILES.busy = lambda: ("The city is being exported for Blender from your copied files. Wait for it to "
                           "finish, or stop it, then copy." if BLENDER.running else
                           "The textures are being exported from your copied files. Wait for that to finish, "
                           "or stop it, then copy." if TEXTURE_JOB.running else "")
BLENDER.busy = lambda: ("Your game files are being copied. Export the city when that's done."
                        if GAME_FILES.running else "")
TEXTURE_JOB.busy = lambda: ("Your game files are being copied. Export the textures when that's done."
                            if GAME_FILES.running else "")

HOST = os.environ.get("SCARFACE_HOST", "127.0.0.1")
PORT = int(os.environ.get("SCARFACE_PORT", "8085"))
MAINTAINERS = {h.strip() for h in os.environ.get("SCARFACE_MAINTAINERS", "RRutherrfordd (Founder)").split(",") if h.strip()}
MIN_NEW_PIN_LEN = 8
MAX_BODY = 48 * 1024 * 1024
OVERLAY_SCORER = "msvc_verify_v2"        # checkpoints scored by the old (truncating) verifier are reset

STATE_LOCK = threading.RLock()
AUTH_LOCK = threading.Lock()
ALL_TASKS: List[dict] = []
TASK_BY_ID: Dict[str, dict] = {}
REGISTRY: dict = {"entries": {}}
_IMAGES: Dict[str, Optional[BinaryImage]] = {}
_FAILS: Dict[str, List[float]] = {}
_COMPILER: Dict[str, str] = {}
GROUPS: Dict[str, List[dict]] = {}          # look-alike group id -> tasks (portal/tools/lookalikes.py)
BY_SYMBOL: Dict[str, List[dict]] = {}       # "Class::vfunc_NN" -> the same method in each build
PS2_BY_TWIN: Dict[int, List[dict]] = {}     # Xbox address -> PS2 functions paired with it
BUILD_NAMES = {"xb": "the retail Xbox game", "pc": "the PC game", "proto": "the April 2006 prototype",
               "ps2": "the PS2 game", **{b: PO.describe_bin(b) for b in PO.BINS}}
BIN_ORDER = ("xb", "pc", "proto", "ps2") + PO.BINS
PORT_STATUS: Dict[str, dict] = {}           # task id -> progress of carrying its match to its look-alikes
PORT_JOBS: "queue_mod.Queue" = queue_mod.Queue()
PORT_MAX = int(os.environ.get("SCARFACE_LOOKALIKE_MAX", "1000"))

if (BASE_DIR / "private").is_dir() and not PRIVATE_DIR.exists():   # older copies kept it at the top
    (BASE_DIR / "private").rename(PRIVATE_DIR)
for d in (RECON_DIR, REPORTS_DIR, PRIVATE_DIR):
    d.mkdir(parents=True, exist_ok=True)


# =========================================================================== #
# Small utilities
# =========================================================================== #

def now_ts() -> int:
    return int(time.time())


def stamp() -> str:
    return dt.datetime.now().strftime("%Y-%m-%d %H:%M:%S")


def read_json(path: Path, default):
    try:
        return json.loads(path.read_text(encoding="utf-8"))
    except Exception:
        return default


def write_json(path: Path, obj) -> None:
    tmp = path.with_suffix(path.suffix + ".tmp")
    tmp.write_text(json.dumps(obj, indent=2), encoding="utf-8")
    os.replace(tmp, path)


BINARY_PROBLEMS: Dict[str, str] = {}    # lane -> why its file in binaries/ is refused


def image_for(b: str) -> Optional[BinaryImage]:
    """The game file for a lane, or None if it is missing or not the accepted US version
    (docs/GAME_VERSIONS.md): matches against any other copy would not count."""
    if b not in _IMAGES:
        p = BINARIES.get(b)
        img = None
        if b in PO.BY_BIN:                  # an overlay: the PS2 program with it loaded
            base = image_for("ps2")
            problem = PO.refusal(p, b) if p else None
            if problem:
                BINARY_PROBLEMS[b] = problem
            elif base is not None and p.exists():
                img = PB.Ps2Image.with_overlay(base, p.read_bytes(), p.name)
        elif p and p.exists():
            problem = GF.refusal(p)
            if problem:
                BINARY_PROBLEMS[b] = problem
            else:
                img = PB.Ps2Image(p) if b == "ps2" else BinaryImage(p)
        _IMAGES[b] = img
    return _IMAGES[b]


def accepted_binaries() -> Dict[str, Path]:
    return {b: p for b, p in BINARIES.items() if image_for(b)}


def compiler_version() -> str:
    if "v" not in _COMPILER:
        _COMPILER["v"] = MV.compiler_version()
    return _COMPILER["v"]


def compiler_build() -> str:
    """'13.10.3052' or '13.10.3077': stored with each match, so a match made with either Toolkit release
    can be told apart later."""
    m = re.search(r"Version (\d+\.\d+\.\d+)", compiler_version())
    return m.group(1) if m else ""


# =========================================================================== #
# Contributor handles + PINs (private/contributor_tokens.json, never committed)
# =========================================================================== #

def _kdf(pin: str, salt: bytes) -> Tuple[str, str]:
    try:
        from argon2.low_level import Type, hash_secret_raw
        raw = hash_secret_raw(secret=pin.encode(), salt=salt, time_cost=3, memory_cost=65536,
                              parallelism=2, hash_len=32, type=Type.ID)
        return "argon2id", raw.hex()
    except ImportError:
        return "pbkdf2", hashlib.pbkdf2_hmac("sha256", pin.encode(), salt, 300_000).hex()


def _make_token(pin: str) -> str:
    salt = secrets.token_bytes(16)
    scheme, h = _kdf(pin, salt)
    return f"{scheme}${salt.hex()}${h}"


def _check_token(stored: str, user: str, pin: str) -> Tuple[bool, bool]:
    """(matches, is_legacy_format)."""
    parts = stored.split("$")
    if len(parts) == 3:                                          # current: scheme$salt$hash
        scheme, salt_hex, want = parts
        salt = bytes.fromhex(salt_hex)
        if scheme == "argon2id":
            try:
                from argon2.low_level import Type, hash_secret_raw
            except ImportError:
                raise RuntimeError("This handle's PIN was stored with Argon2; run: pip install argon2-cffi")
            got = hash_secret_raw(secret=pin.encode(), salt=salt, time_cost=3, memory_cost=65536,
                                  parallelism=2, hash_len=32, type=Type.ID).hex()
        else:
            got = hashlib.pbkdf2_hmac("sha256", pin.encode(), salt, 300_000).hex()
        return hmac.compare_digest(got, want), False
    legacy_salt = ("scarface_decomp_salt_" + user.lower()).encode()
    if len(parts) == 2 and parts[0] == "argon2id":               # old: deterministic salt
        try:
            from argon2.low_level import Type, hash_secret_raw
        except ImportError:
            raise RuntimeError("This handle's PIN was stored with Argon2; run: pip install argon2-cffi")
        got = hash_secret_raw(secret=pin.encode(), salt=legacy_salt, time_cost=3, memory_cost=65536,
                              parallelism=2, hash_len=32, type=Type.ID).hex()
        return hmac.compare_digest(got, parts[1]), True
    if len(parts) == 2 and parts[0] == "pbkdf2":
        got = hashlib.pbkdf2_hmac("sha256", pin.encode(), legacy_salt, 200_000).hex()
        return hmac.compare_digest(got, parts[1]), True
    if len(stored) == 64:                                        # oldest: sha256(user:pin)
        got = hashlib.sha256((user.lower() + ":" + pin).encode()).hexdigest()
        return hmac.compare_digest(got, stored), True
    return False, False


def _migrate_legacy_auth() -> None:
    if LEGACY_AUTH_JSON.exists() and not AUTH_JSON.exists():
        os.replace(LEGACY_AUTH_JSON, AUTH_JSON)
        print(f"[*] Moved {LEGACY_AUTH_JSON.name} to private/ (it must not be committed).")


_HANDLE_RE = re.compile(r"^[A-Za-z0-9][A-Za-z0-9 _.\-()']{1,39}$")     # for new handles; old ones keep working


def authenticate(user: str, pin: str, allow_register: bool = True) -> Tuple[bool, str]:
    user = (user or "").strip()
    pin = (pin or "").strip()
    if not user or not pin:
        return False, "Sign in with a handle and PIN first."
    if len(user) > 64 or any(ord(c) < 32 for c in user):
        return False, "Handles are 1-64 printable characters."
    if len(pin) > 128:
        return False, "PIN is too long."
    with AUTH_LOCK:
        _migrate_legacy_auth()
        fails = [t for t in _FAILS.get(user.lower(), []) if t > time.time() - 600]
        if len(fails) >= 8:
            return False, "Too many failed attempts for this handle; wait 10 minutes."
        auth = read_json(AUTH_JSON, {})
        existing = next((k for k in auth if k.lower() == user.lower()), None)
        if existing is not None and existing != user:
            return False, f"Handle '{existing}' is already registered (handles are not case-sensitive)."
        if existing is not None:
            try:
                ok, legacy = _check_token(auth[existing], existing, pin)
            except RuntimeError as e:
                return False, str(e)
            if not ok:
                _FAILS[user.lower()] = fails + [time.time()]
                return False, f"Handle '{user}' is locked with a different PIN."
            if legacy:
                auth[existing] = _make_token(pin)
                write_json(AUTH_JSON, auth)
            _FAILS.pop(user.lower(), None)
            return True, "OK"
        if not allow_register:
            return False, "Unknown handle."
        if not _HANDLE_RE.match(user):
            return False, ("Handles use letters, numbers, spaces and _ . - ( ) ' and are 2-40 characters long, "
                           "starting with a letter or number.")
        if len(pin) < MIN_NEW_PIN_LEN:
            return False, f"New handles need a PIN/password of at least {MIN_NEW_PIN_LEN} characters."
        auth[user] = _make_token(pin)
        write_json(AUTH_JSON, auth)
        return True, "Registered"


# =========================================================================== #
# Verified registry, progress, leaderboard
# =========================================================================== #

def load_registry() -> None:
    global REGISTRY
    REGISTRY = read_json(REGISTRY_JSON, {"schema": "scarface_verified_registry_v1", "entries": {}})
    REGISTRY.setdefault("entries", {})


DEFAULT_REPO_URL = "https://github.com/scarface-decomp/scarface_decomp"


def repo_url() -> str:
    """The GitHub page for this checkout: SCARFACE_REPO_URL, else the "origin" remote, else the default."""
    env = os.environ.get("SCARFACE_REPO_URL", "").strip()
    if env:
        return env.rstrip("/")
    try:
        out = subprocess.run(["git", "remote", "get-url", "origin"], cwd=BASE_DIR, capture_output=True,
                             text=True, timeout=10).stdout.strip()
    except (OSError, subprocess.SubprocessError):
        out = ""
    m = re.match(r"^(?:https://|git@)(github\.com)[/:]([^/\s]+)/([^/\s]+?)(?:\.git)?/?$", out)
    return f"https://github.com/{m.group(2)}/{m.group(3)}" if m else DEFAULT_REPO_URL


REPO_URL = repo_url()


def task_key(t: dict) -> str:
    return f"{t['bin']}:0x{t['fva_int']:08X}"


_LISTED: Dict[str, int] = {}


def listed_totals() -> Dict[str, int]:
    """How many functions each version has, from the project's own lists (reconstructed_src/). The count for a
    version whose game file isn't in binaries/: its functions aren't in the work queue then, and without
    this the matched ones would look like all there are ("1,590 of 1,590, 100%")."""
    if not _LISTED:
        try:
            _LISTED.update({b: len(fns) for b, fns in RO.known_from_files(RECON_DIR).items()})
        except Exception:  # noqa: BLE001 - the lists are a help, never a reason not to start
            pass
        _LISTED.setdefault("", 0)
    return _LISTED


def progress() -> dict:
    """The headline numbers are the released game on PC and Xbox (one compiler, one code base). The April 2006
    prototype (unreleased code) and the PS2 game (another compiler) are counted on their own rows,
    under "prototype" and "ps2"."""
    entries = REGISTRY.get("entries", {})
    by_bin = Counter(e["bin"] for e in entries.values())
    retail = [e for e in entries.values() if e["bin"] != "proto" and not PO.is_ps2(e["bin"])]
    left = Counter(t["bin"] for t in ALL_TASKS if t["status"] != "VERIFIED")
    have = set(accepted_binaries())
    missing = [b for b in ("xb", "pc") if b not in have]
    # a version whose game file isn't here still has all its functions: count them from the project's lists
    for b in ("xb", "pc", "proto"):
        if b not in have and not left.get(b):
            left[b] = max(0, listed_totals().get(b, 0) - by_bin.get(b, 0))
    remaining = sum(n for b, n in left.items() if b != "proto" and not PO.is_ps2(b))
    ps2_left = sum(1 for t in ALL_TASKS if t["status"] != "VERIFIED" and PO.is_ps2(t["bin"]))
    ps2_done = sum(n for b, n in by_bin.items() if PO.is_ps2(b))       # the program and its overlays
    total = remaining + len(retail)
    proto_left = left.get("proto", 0)
    proto_done = by_bin.get("proto", 0)
    return {
        "matched_functions": len(retail),
        "no_game": "xb" in missing,         # nothing to work on until the Xbox game is in binaries/
        "total_functions": total,
        "matched_percent": round(len(retail) / total * 100.0, 2) if total else 0.0,
        "matched_bytes": sum(int(e.get("size", 0)) for e in retail),
        "by_binary": {"pc": by_bin.get("pc", 0), "xbox": by_bin.get("xb", 0), "proto": proto_done, "ps2": ps2_done},
        "prototype": {"matched": proto_done, "total": proto_done + proto_left},
        "ps2": {"matched": ps2_done, "total": ps2_done + ps2_left,
                "matched_bytes": sum(int(e.get("size", 0)) for e in entries.values() if PO.is_ps2(e["bin"])),
                "compiler": PV.COMPILER},
        "total_label": "verified / (verified + functions in the work queue), retail PC and Xbox",
        "compiler": compiler_version(),
    }


def leaderboard() -> dict:
    c = Counter((e.get("verified_by") or "Imported (unattributed)") for e in REGISTRY.get("entries", {}).values())
    return dict(c.most_common())


def append_audit(entry: dict) -> None:
    log = read_json(AUDIT_JSON, [])
    log.insert(0, entry)
    write_json(AUDIT_JSON, log[:250])


# =========================================================================== #
# Work queue
# =========================================================================== #

def tier_meta(size: int) -> dict:
    from queue_builder import tier
    return tier(size)


def load_tasks() -> None:
    global ALL_TASKS, TASK_BY_ID
    tasks = read_json(QUEUE_JSON, None)
    have = accepted_binaries()
    missing_lanes = sorted(b for b in have if not any(t.get("bin") == b for t in tasks or []))
    if not tasks or missing_lanes:
        from queue_builder import build_queue, seed_data
        if not tasks:
            print("[*] Building the work queue from the game files (first run; takes a few minutes)...")
        else:
            names = ", ".join(BINARIES[b].name for b in missing_lanes)
            print(f"[*] New game files found ({names}); adding their functions to the work queue (a few minutes)...")
        tasks = build_queue(have, tasks, set(REGISTRY["entries"]), progress=print, **seed_data(BASE_DIR))
        write_json(QUEUE_JSON, tasks)
    if any("lookalikes" not in t for t in tasks if "fva_int" in t):
        images = {b: image_for(b) for b in BIN_ORDER if image_for(b)}
        if images:
            print("[*] Grouping look-alike functions (once; about 15 seconds)...")
            LA.annotate([t for t in tasks if "fva_int" in t], images)
            write_json(QUEUE_JSON, tasks)
    verified = set(REGISTRY["entries"])
    tasks = drop_non_code(tasks, verified)
    out = []
    for t in tasks:
        if "fva_int" not in t or t.get("bin") not in BINARIES:
            continue
        t.update(tier_meta(int(t.get("size", 1))))
        t.setdefault("status", "UNCLAIMED")
        t.setdefault("claimed_by", "")
        t.setdefault("claim_expires_at", 0)
        t.setdefault("best_matched_bytes", 0)
        t.setdefault("best_pct", 0.0)
        t.setdefault("best_by", "")
        t.setdefault("best_cpp", "")
        t.setdefault("best_diff_details", [])
        t.setdefault("match_substr", "")
        if task_key(t) in verified:
            t["status"] = "VERIFIED"
        out.append(t)
    ALL_TASKS = out
    TASK_BY_ID = {t["id"]: t for t in ALL_TASKS}
    GROUPS.clear()
    BY_SYMBOL.clear()
    PS2_BY_TWIN.clear()
    for t in ALL_TASKS:
        if t.get("xbox_twin"):
            PS2_BY_TWIN.setdefault(int(t["xbox_twin"], 16), []).append(t)
        if t.get("lookalike_group"):
            GROUPS.setdefault(t["lookalike_group"], []).append(t)
        if "::" in t["symbol"]:
            BY_SYMBOL.setdefault(t["symbol"], []).append(t)
    for same in BY_SYMBOL.values():
        same.sort(key=lambda m: BIN_ORDER.index(m["bin"]) if m["bin"] in BIN_ORDER else 99)
    for t in ALL_TASKS:
        t["in_retail"] = in_retail(t)
    overlay = read_json(OVERLAY_JSON, {})
    for tid, data in overlay.items():
        t = TASK_BY_ID.get(tid)
        if not t or t["status"] == "VERIFIED":
            continue
        for k in ("status", "claimed_by", "claim_expires_at", "best_by", "best_cpp", "starter_cpp", "decompme_slug"):
            if data.get(k) not in (None, ""):
                t[k] = data[k]
        if data.get("scorer") == OVERLAY_SCORER:
            t["best_matched_bytes"] = data.get("best_matched_bytes", 0)
            t["best_pct"] = data.get("best_pct", 0.0)
        if t["status"] not in ("UNCLAIMED", "CLAIMED", "PARTIAL"):
            t["status"] = "UNCLAIMED"
        if t["status"] == "PARTIAL" and not t.get("best_matched_bytes"):
            t["status"] = "UNCLAIMED"


def drop_non_code(tasks: List[dict], verified: set) -> List[dict]:
    """Queues built before a check existed can hold data that looked like a function start (a single
    `retf`, the middle of an instruction). No C++ can match those, so they are taken out, once."""
    from queue_builder import CODE_CHECK
    todo = [t for t in tasks if "fva_int" in t and t.get("code_check", 0) < CODE_CHECK and not PO.is_ps2(t.get("bin"))]
    if not todo:
        return tasks
    from sf_binaries import not_compiled_reason
    known = {f"{f['bin']}:0x{int(f['va'], 16):08X}"
             for f in (read_json(REPORTS_DIR / "known_functions.json", {}) or {}).get("functions", [])
             if isinstance(f, dict) and "va" in f and "bin" in f}
    drop = set()
    for t in todo:
        img = image_for(t.get("bin"))
        if img is None:
            continue
        key = task_key(t)
        if key not in verified and key not in known and not_compiled_reason(img, t["fva_int"], int(t["size"])):
            drop.add(id(t))
        t["code_check"] = CODE_CHECK
    kept = [t for t in tasks if id(t) not in drop]
    if drop:
        print(f"[*] Took {len(drop):,} non-functions (data the compiler could not have made) out of the work queue.")
    write_json(QUEUE_JSON, kept)
    return kept


def save_overlay(t: dict) -> None:
    overlay = read_json(OVERLAY_JSON, {})
    overlay[t["id"]] = {
        "status": t["status"], "claimed_by": t.get("claimed_by", ""), "claim_expires_at": t.get("claim_expires_at", 0),
        "best_matched_bytes": t.get("best_matched_bytes", 0), "best_pct": t.get("best_pct", 0.0),
        "best_by": t.get("best_by", ""), "best_cpp": t.get("best_cpp", ""), "scorer": OVERLAY_SCORER,
        "decompme_slug": t.get("decompme_slug", ""),
    }
    write_json(OVERLAY_JSON, overlay)


def expire_leases() -> None:
    n = now_ts()
    with STATE_LOCK:
        for t in ALL_TASKS:
            if t["status"] == "CLAIMED" and t.get("claim_expires_at", 0) and n >= t["claim_expires_at"]:
                t["claimed_by"] = ""
                t["claim_expires_at"] = 0
                t["status"] = "PARTIAL" if t.get("best_matched_bytes", 0) > 0 else "UNCLAIMED"
                save_overlay(t)


def target_bytes(t: dict) -> Optional[bytes]:
    img = image_for(t["bin"])
    return img.read(t["fva_int"], int(t["size"])) if img else None


def relocs_for(t: dict) -> Optional[list]:
    img = image_for(t["bin"])
    if PO.is_ps2(t["bin"]):
        return PB.as_relocs(img, t["fva_int"], int(t["size"])) if img else None
    code = img.read(t["fva_int"], int(t["size"])) if img else None
    return LA.signature(code, t["fva_int"], img)[1] if code else None


def starter_relocs(t: dict, tb: Optional[bytes]) -> Optional[list]:
    """The function's relocations, so the starter names calls and globals (sub_/DAT_) instead of numbers."""
    img = image_for(t["bin"])
    if img is None or not tb or PO.is_ps2(t["bin"]):
        return None
    try:
        return DME.find_relocations(tb, t["fva_int"], img)
    except Exception:            # Capstone missing or an odd function: the starter still works without them
        return None


def lookalike_starter(t: dict) -> Tuple[str, str]:
    """C++ from an already matched look-alike, rewritten for t: (code, id it came from) or ("", "")."""
    mine = None
    for m in LA.members(GROUPS, t):
        e = REGISTRY["entries"].get(task_key(m)) if m["status"] == "VERIFIED" else None
        if not e or not (e.get("code") or "").strip():
            continue
        if mine is None:
            mine = relocs_for(t)
            if mine is None:
                return "", ""
        theirs = relocs_for(m)
        ported = LA.port_code(e["code"], m, theirs, t, mine) if theirs is not None else None
        if ported:
            return ported, m["id"]
    return "", ""


def counterparts(t: dict) -> List[dict]:
    """The same class method in the other builds (retail Xbox, PC, prototype, PS2), whatever its code. A PS2
    function paired with an Xbox one (portal/tools/ps2_pairing.py) has that one as its counterpart even
    when neither has a name."""
    out = [m for m in BY_SYMBOL.get(t["symbol"], []) if m is not t and m["bin"] != t["bin"]] if "::" in t["symbol"] else []
    twin = TASK_BY_ID.get("xb_" + t["xbox_twin"][2:]) if t.get("xbox_twin") else None
    if twin is not None and twin not in out:
        out.insert(0, twin)
    if t["bin"] == "xb":
        out += [m for m in PS2_BY_TWIN.get(t["fva_int"], []) if m not in out]
    return out


def in_retail(t: dict) -> str:
    """For a prototype function that is also in the released game: "code" when the machine code is the same
    (matching the retail one matches this one too, through its look-alike group), "method" when the same class
    method is in retail with different code (an older version of it). "" for everything else."""
    if t["bin"] != "proto":
        return ""
    if any(m["bin"] != "proto" for m in LA.members(GROUPS, t)):
        return "code"
    return "method" if counterparts(t) else ""


def in_default_queue(t: dict) -> bool:
    """The queue lists the released game plus the prototype's own code. Prototype functions that are also in
    retail are left out (lane PROTO_IN_RETAIL lists them), so nobody does the same function twice. PS2
    functions have their own lane (another compiler, checked through decomp.me)."""
    return not t.get("in_retail") and not PO.is_ps2(t.get("bin"))


def counterpart_starter(t: dict) -> Tuple[str, str]:
    """When the same method is already matched in another build but its code differs here, its C++ is
    still the best place to start: (code, id it came from) or ("", "")."""
    for m in counterparts(t):
        e = REGISTRY["entries"].get(task_key(m)) if m["status"] == "VERIFIED" else None
        if e and (e.get("code") or "").strip():
            head = (f"// {t['symbol']} is already matched in {BUILD_NAMES.get(m['bin'], m['bin'])} ({m['va']}); this is\n"
                    f"// that code. This build's machine code is different, so expect to change a few things.\n")
            if PO.is_ps2(t["bin"]) or PO.is_ps2(m["bin"]):
                head += ("// The PS2 game was built with another compiler (CodeWarrior, not Visual C++): the C++ is\n"
                         "// the same source, but names, calls and globals may need other declarations.\n")
            return head + e["code"].strip() + "\n", m["id"]
    return "", ""


def ps2_starter(t: dict) -> str:
    """A first draft for a PS2 function: its address, how to build it, and declarations for what it uses,
    named after their addresses (func_XXXXXXXX, D_XXXXXXXX) so the verifier can check every one."""
    img = image_for(t["bin"])
    va, size = t["fva_int"], int(t["size"])
    calls, data = [], []
    for r in (PB.references(img, va, size) if img else []):
        if r.kind == "26" and r.address != va:
            n = PB.func_name(r.address)
            if n not in calls:
                calls.append(n)
        elif r.kind in ("lo", "gp"):
            n = (PB.func_name if img.is_code(r.address) else PB.data_name)(r.address)
            if n not in data and n not in calls:
                data.append(n)
    me = t["symbol"] if t["symbol"].startswith("func_") else PB.func_name(va)
    lines = [f"// {t['symbol']} ({t['va']}, {size} bytes) from {PO.describe_bin(t['bin'])}.",
             f"// Compiled on decomp.me with {PV.COMPILER}, flags {PV.FLAGS}.",
             "// Name what it uses after their addresses (func_XXXXXXXX, D_XXXXXXXX) so each one can be checked."]
    if "::" in t["symbol"]:
        lines.append(f"// The Xbox game calls it {t['symbol']}; once that one is matched, its C++ is a better start.")
    lines.append("")
    lines += [f'extern "C" void {n}();' for n in calls]
    lines += [f"extern int {n};" for n in data]
    if calls or data:
        lines.append("")
    lines += [f'extern "C" void {me}() {{', "}", ""]
    return "\n".join(lines)


_NAMES_CACHE: list = [None, {}]


def community_name(t: dict) -> Optional[dict]:
    """A name people worked out for this function (reports/names.json), re-read when the file changes."""
    path = REPORTS_DIR / "names.json"
    try:
        mtime = path.stat().st_mtime
    except OSError:
        return None
    if _NAMES_CACHE[0] != mtime:
        names = NAMES.load(path).get("names", {})
        _NAMES_CACHE[:] = [mtime, names if isinstance(names, dict) else {}]
    info = _NAMES_CACHE[1].get(NAMES.key_for(t))
    return info if isinstance(info, dict) and isinstance(info.get("name"), str) else None


_GUIDE: Optional[Dict[Tuple[str, int], dict]] = None


def guide_note(t: dict) -> Optional[dict]:
    """What the function guide (docs/function_guide.json, from the clean-room specs) says a function does:
    {"what_it_does", "spec", "low_confidence"}, or None when it isn't in the guide."""
    global _GUIDE
    if _GUIDE is None:
        _GUIDE = {}
        for e in (read_json(BASE_DIR / "docs" / "function_guide.json", {}) or {}).get("functions", []):
            try:
                _GUIDE[(str(e["bin"]), int(str(e["va"]), 16))] = e
            except (KeyError, ValueError, TypeError):
                continue
    try:
        e = _GUIDE.get((str(t.get("bin")), int(str(t.get("va")), 16)))
    except (ValueError, TypeError):
        return None
    if not e or not e.get("what_it_does"):
        return None
    return {"what_it_does": str(e["what_it_does"]), "spec": str(e.get("spec") or ""),
            "low_confidence": e.get("confidence") == "low"}


def live_task(t: dict) -> dict:
    out = {k: v for k, v in t.items() if k not in ("best_cpp",)}
    note = guide_note(t)
    if note:
        out["guide"] = note
    entry = REGISTRY["entries"].get(task_key(t)) if t.get("status") == "VERIFIED" else None
    if entry and entry.get("what"):
        out["what"], out["what_by"] = entry["what"], entry.get("what_by") or entry.get("verified_by", "")
    named = community_name(t) if t.get("status") != "VERIFIED" else None
    if named:
        out["known_name"] = {"name": named["name"], "by": str(named.get("by", "")), "why": str(named.get("why", ""))}
    tb = target_bytes(t)
    out["target_hex"] = " ".join(f"{b:02X}" for b in tb) if tb else ""
    if PO.is_ps2(t["bin"]):
        img = image_for(t["bin"])
        missing = "SLUS_211.11" if t["bin"] == "ps2" else f"SLUS_211.11 or {PO.FOLDER}/{PO.BY_BIN[t['bin']].file}"
        out["disasm_lines"] = (PB.disassembly_lines(img, t["fva_int"], int(t["size"])) if tb
                               else [f"({missing} is not in binaries/)"])
        out["compiler_label"] = f"{PV.COMPILER} on decomp.me ({PV.FLAGS})"
    else:
        out["disasm_lines"] = disassemble(tb) if tb else ["(binary not present in binaries/)"]
    others = LA.members(GROUPS, t)
    out["lookalikes"] = len(others)
    out["lookalike_done"] = sum(1 for m in others if m["status"] == "VERIFIED")
    out["lookalike_list"] = [{k: m[k] for k in ("id", "symbol", "va", "status")} for m in others[:12]]
    out["counterparts"] = [{"id": m["id"], "build": BUILD_NAMES.get(m["bin"], m["bin"]), "va": m["va"],
                            "status": m["status"]} for m in counterparts(t)]
    if (t.get("best_cpp") or "").strip():
        out["starter_cpp"] = t["best_cpp"]
    elif not (t.get("starter_cpp") or "").strip():
        code, src, kind = "", "", ""
        if t["status"] != "VERIFIED" and out["lookalike_done"]:
            code, src = lookalike_starter(t)
            kind = "lookalike" if code else ""
        if not code and t["status"] != "VERIFIED":
            code, src = counterpart_starter(t)
            kind = "counterpart" if code else ""
        if not code and PO.is_ps2(t["bin"]):
            code = ps2_starter(t)
        out["starter_cpp"] = code or synthesize_cpp(t["symbol"], t["va"], tb or b"", out["disasm_lines"],
                                                    relocs=starter_relocs(t, tb))
        out["starter_from"], out["starter_kind"] = src, kind
    out["server_now"] = now_ts()
    return out


_SLUG_RE = re.compile(r"^[A-Za-z0-9_-]{1,64}$")


def ps2_scratch_fields(t: dict, starter: str) -> dict:
    img = image_for(t["bin"])
    name = t["symbol"] if t["symbol"].startswith("func_") else PB.func_name(t["fva_int"])
    asm = PB.function_asm(img, t["fva_int"], int(t["size"]), name)
    src, ctx = DME._inline_project_includes(starter or "", [INCLUDE_DIR])
    where = "" if t["bin"] == "ps2" else f", {PO.BY_BIN[t['bin']].label} overlay"
    head = (f"// Scarface: The World Is Yours (PS2{where}), {t['symbol']} at {t['va']}, {t['size']} bytes.\n"
            f"// From {DME.PROJECT_SITE}: when this shows 100%, paste the C++ into the portal and press Compile & Verify.\n")
    return PV.scratch_fields(f"Scarface (PS2) {t['symbol']}", asm, head + src, ctx, name,
                             os.environ.get("SCARFACE_DECOMPME_PRESET_PS2", ""))


def decompme_prepare(t: dict) -> dict:
    """Everything the page needs to create a decomp.me scratch for this function."""
    img = image_for(t["bin"])
    if img is None:
        return {"ok": False, "error": f"binaries/{BINARIES[t['bin']].name} is missing, so there is nothing to send."}
    if PO.is_ps2(t["bin"]):
        slug = t.get("decompme_slug", "")
        return {"ok": True, "api": PV.DECOMPME_URL, "json": ps2_scratch_fields(t, live_task(t).get("starter_cpp", "")),
                "existing_url": f"{PV.DECOMPME_URL}/scratch/{slug}" if slug else ""}
    starter = live_task(t).get("starter_cpp", "")
    obj, fields = DME.prepare(img, t["fva_int"], int(t["size"]), t["symbol"], t["flags"], starter,
                              [INCLUDE_DIR, RECON_DIR], build=t["bin"])
    slug = t.get("decompme_slug", "")
    return {"ok": True, "api": DME.DECOMPME_URL, "obj_b64": base64.b64encode(obj).decode("ascii"),
            "fields": fields, "existing_url": f"{DME.DECOMPME_URL}/scratch/{slug}" if slug else ""}


def queue_item(t: dict, n: int) -> dict:
    return {k: t.get(k) for k in ("id", "lane", "symbol", "va", "size", "tier", "tier_label", "est_label",
                                   "lease_minutes", "status", "claimed_by", "best_matched_bytes", "best_pct", "best_by",
                                   "lookalikes")} | {
        "claim_remaining_sec": max(0, t.get("claim_expires_at", 0) - n) if t["status"] == "CLAIMED" else None}


# =========================================================================== #
# Verification
# =========================================================================== #

def flag_options(t: dict) -> List[str]:
    """The task's flags first. PC also tries /G7, because a few PC functions only match with it
    (portal/scripts/reverify_all.py does the same, so the portal and the re-verifier agree)."""
    opts = [t["flags"]]
    if t["bin"] == "pc" and "/G6" in t["flags"]:
        opts.append(t["flags"].replace("/G6", "/G7"))
    return opts


NO_COMPILER_HELP = ("The 2003 compiler is not installed on this computer yet, so it can't verify here.\n"
                    "Install it once from your own VCToolkitSetup.exe: put it in the project folder, open a\n"
                    "terminal there (in File Explorer, type powershell in the folder's address bar and press\n"
                    "Enter) and run:\n"
                    "    python portal/scripts/setup_msvc71.py VCToolkitSetup.exe\n"
                    "Or, if your code scores 100% on decomp.me, post the decomp.me link in a GitHub issue "
                    "and a maintainer will verify it and credit you.")


PS2_UNREACHABLE = ("PS2 functions are compiled on decomp.me (the game's PS2 compiler can't be installed here), and "
                   "decomp.me turns away programs that aren't a browser, so this goes through your browser: "
                   "follow the steps that just opened. ({why})")


def ps2_job(t: dict, cpp_code: str) -> dict:
    """What the page's decomp.me connection has to do for a PS2 compile: make the function's scratch if it
    has none, then compile the C++ there and send back the object."""
    src, ctx = DME._inline_project_includes(cpp_code, [INCLUDE_DIR])
    job = {"slug": t.get("decompme_slug", ""),
           "compile": {"compiler": PV.COMPILER, "compiler_flags": PV.FLAGS, "source_code": src.replace("\r\n", "\n"),
                       "context": ctx.replace("\r\n", "\n"), "include_objects": True}}
    if not job["slug"]:
        job["create"] = {"json": ps2_scratch_fields(t, cpp_code)}
    return job


def run_verify_ps2(t: dict, cpp_code: str, object_b64: str = "", slug: str = "") -> dict:
    """Compile on decomp.me with the PS2 compiler, then compare the object with the game here. The object
    comes either from here (when this computer can reach decomp.me's API) or from the page, which compiled
    it through decomp.me in the browser (object_b64)."""
    violations = check_genuine_cpp(cpp_code)
    if violations:
        return {"ok": False, "compiler_error": format_violations(violations), "policy_violation": True}
    img, tb = image_for(t["bin"]), target_bytes(t)
    if img is None or tb is None:
        missing = "SLUS_211.11" if t["bin"] == "ps2" else f"SLUS_211.11 or {PO.FOLDER}/{PO.BY_BIN[t['bin']].file}"
        return {"ok": False, "compiler_unavailable": True,
                "compiler_error": f"binaries/{missing} is missing, so there is nothing to compare against."}
    if slug and _SLUG_RE.match(slug) and slug != t.get("decompme_slug"):
        with STATE_LOCK:
            t["decompme_slug"] = slug
            save_overlay(t)
    if object_b64:
        try:
            res = {"ok": True, "object": base64.b64decode(object_b64), "output": ""}
        except (ValueError, TypeError):
            return {"ok": False, "compiler_error": "The page sent an object that could not be read."}
    else:
        slug = t.get("decompme_slug", "")
        if not slug:
            made = PV.create_scratch(ps2_scratch_fields(t, cpp_code))
            if not made.get("ok"):
                return {"ok": False, "compiler_unavailable": True, "need_browser": True, "job": ps2_job(t, cpp_code),
                        "compiler_error": PS2_UNREACHABLE.format(why=made.get("error", ""))}
            slug = made["slug"]
            with STATE_LOCK:
                t["decompme_slug"] = slug
                save_overlay(t)
        src, ctx = DME._inline_project_includes(cpp_code, [INCLUDE_DIR])
        res = PV.compile_on_decompme(slug, src, ctx)
    if not res.get("ok"):
        if res.get("compiler_error") is not None:
            return {"ok": False, "compiler_error": res["compiler_error"]}
        return {"ok": False, "compiler_unavailable": True, "need_browser": True, "job": ps2_job(t, cpp_code),
                "compiler_error": PS2_UNREACHABLE.format(why=res.get("error", ""))}
    try:
        obj = PV.parse_object(res["object"])
    except (ValueError, IndexError, struct.error) as e:
        return {"ok": False, "compiler_error": f"Could not read the object decomp.me sent back: {e}"}
    known = {e2["symbol"]: int(e2["va"], 16) for e2 in REGISTRY["entries"].values()
             if e2.get("bin") in ("ps2", t["bin"]) and e2.get("symbol")}     # the program's, and its own overlay's
    fn, cmp = PV.best_function(tb, obj, t["fva_int"], img, known)
    if fn is None:
        return {"ok": False, "compiler_error": "The C++ compiled, but it has no function in it."}
    out = {"ok": True, **cmp, "compiled_sym": obj.name_of(fn), "compiled_hex": " ".join(f"{b:02X}" for b in fn.data),
           "flags": PV.FLAGS, "compiler_output": res.get("output", "")}
    out["verified"] = bool(out["is_exact"] and not out.get("hardcoded_addresses"))
    out["bytes_exact"] = out["is_exact"]
    out["is_exact"] = out["verified"]
    return out


def run_verify(t: dict, cpp_code: str, object_b64: str = "", slug: str = "") -> dict:
    if PO.is_ps2(t["bin"]):
        return run_verify_ps2(t, cpp_code, object_b64, slug)
    if not MV.find_msvc71_bin():
        return {"ok": False, "compiler_error": NO_COMPILER_HELP, "compiler_unavailable": True}
    tb = target_bytes(t)
    if tb is None:
        return {"ok": False, "compiler_unavailable": True,
                "compiler_error": f"binaries/{BINARIES[t['bin']].name} is missing, so there is nothing to compare against."}
    best: Optional[dict] = None
    for flags in flag_options(t):
        res = MV.verify_submission(cpp_code, tb, flags, t.get("match_substr", ""), fn_va=t["fva_int"],
                                   image=image_for(t["bin"]), include_dirs=[INCLUDE_DIR, RECON_DIR])
        res["flags"] = flags
        if not res.get("ok"):
            # A compile error or policy rejection does not depend on /G6 vs /G7.
            return best or res
        res["verified"] = bool(res["is_exact"] and not res.get("hardcoded_addresses"))
        res["bytes_exact"] = res["is_exact"]
        res["is_exact"] = res["verified"]       # the page treats is_exact as "counts as verified"
        if best is None or res["verified"] or res.get("matched_bytes", 0) > best.get("matched_bytes", 0):
            best = res
        if res["verified"]:
            break
    return best


WHAT_MAX = 160


def clean_what(text) -> str:
    """A function's one-line, plain-English description: one line of ordinary text, at most WHAT_MAX characters."""
    if not isinstance(text, str):
        return ""
    text = re.sub(r"[\x00-\x1f\x7f]+", " ", text)
    return re.sub(r"\s+", " ", text).strip()[:WHAT_MAX]


def record_verified(t: dict, cpp_code: str, user: str, tool: str, res: dict, ported_from: str = "",
                    write: bool = True, what: str = "") -> None:
    key = task_key(t)
    REGISTRY["entries"][key] = {
        "bin": t["bin"], "va": f"0x{t['fva_int']:08X}", "size": int(t["size"]), "symbol": t["symbol"],
        "match": t.get("match_substr", ""),
        "flags": res.get("flags") or t["flags"], "source": "portal", "verified_by": user, "tool_used": tool,
        "verified_at": stamp(), "compiler": PV.COMPILER if PO.is_ps2(t["bin"]) else compiler_build(), "code": cpp_code.strip(),
        "note": f"{res.get('reloc_unverified', 0)} external relocation(s) unchecked" if res.get("reloc_unverified") else "",
    }
    if ported_from:
        REGISTRY["entries"][key]["ported_from"] = ported_from
    if clean_what(what):
        REGISTRY["entries"][key]["what"] = clean_what(what)
    if write:
        save_registry()


def describe_verified(t: dict, what: str, user: str) -> Optional[str]:
    """Set (or clear) what a verified function does. Returns an error, or None."""
    e = REGISTRY["entries"].get(task_key(t))
    if not e:
        return "Only rebuilt functions can be described here: write it when you verify the function."
    what = clean_what(what)
    if what == (e.get("what") or ""):
        return None
    if what:
        e.update(what=what, what_by=user, what_at=stamp())
    else:
        for k in ("what", "what_by", "what_at"):
            e.pop(k, None)
    save_registry()
    return None


def _unchecked(e: dict) -> int:
    m = re.match(r"(\d+) external relocation", e.get("note") or "")
    return int(m.group(1)) if m else 0


def revise_verified(t: dict, cpp_code: str, user: str, res: dict) -> bool:
    """A verified function compiled again, exactly, from different code (names cleaned up, comments
    added): keep the new text. Credit stays with whoever matched it first. Only for functions matched
    in the portal (the others are rebuilt from their source files) and never when more addresses
    would go unchecked."""
    e = REGISTRY["entries"].get(task_key(t))
    if not e or e.get("source") != "portal" or e.get("excerpt") or not res.get("verified"):
        return False
    new = cpp_code.strip()
    if not new or new == (e.get("code") or "").strip():
        return False
    if res.get("reloc_unverified", 0) > _unchecked(e):
        return False
    e.update(code=new, revised_by=user, revised_at=stamp(), compiler=PV.COMPILER if PO.is_ps2(t["bin"]) else compiler_build())
    save_registry()
    return True


def save_registry() -> None:
    REGISTRY["compiler"] = compiler_version()
    write_json(REGISTRY_JSON, REGISTRY)
    write_outputs(REGISTRY, RECON_DIR, queue=ALL_TASKS)


def refresh_outputs() -> None:
    """Rewrite the generated files as this version of the portal writes them, before they are committed. They
    are otherwise written when a match is saved, so right after an update the ones on disk are still the
    older portal's: committing those failed the check on GitHub (a file the update added, such as
    docs/sitemap.xml, missing or out of date). A problem here never stops the push."""
    try:
        write_outputs(REGISTRY, RECON_DIR, queue=ALL_TASKS)
    except Exception:  # noqa: BLE001
        import traceback
        traceback.print_exc()


# =========================================================================== #
# Look-alikes: carry a new match over to functions with the same machine code
# =========================================================================== #

def lookalike_summary() -> dict:
    """How many functions are look-alikes of another one (so one match covers them)."""
    return {"groups": len(GROUPS), "extra": sum(len(v) - 1 for v in GROUPS.values()), "functions": len(ALL_TASKS)}


def _held_by_someone_else(m: dict, user: str) -> bool:
    return (m["status"] == "CLAIMED" and m.get("claimed_by") not in ("", user)
            and now_ts() < m.get("claim_expires_at", 0))


def lookalike_targets(t: dict, user: str) -> List[dict]:
    """Unmatched look-alikes of t that nobody else is working on right now."""
    with STATE_LOCK:
        return [m for m in LA.members(GROUPS, t)
                if m["status"] != "VERIFIED" and not _held_by_someone_else(m, user)][:PORT_MAX]


CATCHUP_JSON = PRIVATE_DIR / "lookalike_catchup.json"   # this computer's earlier tries (gitignored)


def _catchup_sig(t: dict, cpp_code: str) -> str:
    """Which match was tried: a revised match (new code) is tried again."""
    return hashlib.sha1((task_key(t) + "\n" + cpp_code.strip()).encode("utf-8")).hexdigest()[:16]


def catchup_targets(t: dict, cpp_code: str, user: str, tried: dict) -> List[dict]:
    sig = _catchup_sig(t, cpp_code)
    return [m for m in lookalike_targets(t, user) if tried.get(task_key(m)) != sig]


def port_lookalikes(t: dict, cpp_code: str, user: str, tool: str, catchup: bool = False) -> dict:
    """Rewrite t's matched C++ for each look-alike, compile and verify it. Only exact matches whose
    every address is checked are recorded, credited to the same person. A catch-up run (an earlier match,
    see catch_up_lookalikes) skips look-alikes this computer already tried with the same code."""
    tried = read_json(CATCHUP_JSON, {}) if catchup and CATCHUP_JSON.exists() else {}
    sig = _catchup_sig(t, cpp_code) if catchup else ""
    targets = catchup_targets(t, cpp_code, user, tried) if catchup else lookalike_targets(t, user)
    st = PORT_STATUS.setdefault(t["id"], {})
    st.update(running=True, total=len(targets), tried=0, matched=0, matched_ids=[])
    src_relocs = relocs_for(t)
    unsaved = 0
    for m in targets:
        dst_relocs = relocs_for(m)
        ported = (LA.port_code(cpp_code, t, src_relocs, m, dst_relocs)
                  if src_relocs is not None and dst_relocs is not None else None)
        if ported and PO.is_ps2(m["bin"]) and not src_relocs and not dst_relocs:
            # No addresses in either: the two are the same bytes, and only the function's own name changed
            # in the C++, so the compiled code is the same too. Nothing to send to decomp.me.
            res = {"ok": True, "verified": True, "flags": PV.FLAGS, "reloc_unverified": 0}
        else:
            res = run_verify(m, ported) if ported else {"ok": False}
            if PO.is_ps2(m["bin"]):
                time.sleep(1.0)                      # decomp.me does the compiling: one a second
        st["tried"] += 1
        if not (res.get("ok") and res.get("verified") and not res.get("reloc_unverified")):
            if catchup and not res.get("compiler_unavailable"):
                tried[task_key(m)] = sig
            continue
        with STATE_LOCK:
            if m["status"] == "VERIFIED" or _held_by_someone_else(m, user):
                continue
            record_verified(m, ported, user, tool, res, ported_from=t["id"], write=False)
            m.update(status="VERIFIED", claimed_by="", claim_expires_at=0)
            save_overlay(m)
            st["matched"] += 1
            st["matched_ids"].append(m["id"])
            unsaved += 1
            if unsaved >= 50:
                save_registry()
                unsaved = 0
    with STATE_LOCK:
        if unsaved:
            save_registry()
        if catchup and tried:
            try:
                write_json(CATCHUP_JSON, tried)
            except OSError:
                pass
        if st["matched"]:
            append_audit({"time": stamp(), "user": user, "action": "VERIFIED",
                          "symbol": f"{st['matched']} look-alike(s) of {t['symbol']}", "va": t["va"],
                          "bytes": "same code, own addresses"})
            print(f"[+] {st['matched']} look-alike(s) of {t['symbol']} matched too -> {len(REGISTRY['entries'])} total")
        st["running"] = False
    return st


def _port_worker() -> None:
    while True:
        job = PORT_JOBS.get()
        try:
            port_lookalikes(*job)
        except Exception:  # keep the worker alive
            import traceback
            traceback.print_exc()
            st = PORT_STATUS.get(job[0]["id"])
            if st:
                st["running"] = False
        finally:
            PORT_JOBS.task_done()


_PORT_THREAD: List[threading.Thread] = []


def porting_left() -> int:
    """How many look-alikes the background worker still has to try. While this is above zero the count of
    new matches can keep rising with nobody pressing anything: each one that matches is a new match."""
    return sum(max(0, int(st.get("total", 0)) - int(st.get("tried", 0)))
               for st in list(PORT_STATUS.values()) if st.get("running"))


def queue_port(t: dict, cpp_code: str, user: str, tool: str, catchup: bool = False, tried: Optional[dict] = None) -> int:
    """Start carrying t's match to its look-alikes in the background; returns how many will be tried."""
    n = len(catchup_targets(t, cpp_code, user, tried or {}) if catchup else lookalike_targets(t, user))
    if not n:
        return 0
    PORT_STATUS[t["id"]] = {"running": True, "total": n, "tried": 0, "matched": 0, "matched_ids": []}
    if not _PORT_THREAD:
        th = threading.Thread(target=_port_worker, name="lookalikes", daemon=True)
        th.start()
        _PORT_THREAD.append(th)
    PORT_JOBS.put((t, cpp_code, user, tool, catchup))
    return n


def catch_up_lookalikes() -> int:
    """A match only carries over to its look-alikes when it is made. Matches made before a look-alike was in
    the queue (a game file added later, such as the prototype, or matches pulled from GitHub) never did, so
    at startup each one is tried on its unmatched look-alikes in the background. That is how the
    prototype's copies of retail code fill in by themselves. Returns how many functions will be tried."""
    if not MV.find_msvc71_bin():
        return 0
    tried = read_json(CATCHUP_JSON, {}) if CATCHUP_JSON.exists() else {}
    with STATE_LOCK:
        sources = []
        for members in GROUPS.values():
            if all(m["status"] == "VERIFIED" for m in members):
                continue
            src = next((m for m in members if m["status"] == "VERIFIED" and not PO.is_ps2(m["bin"])
                        and ((REGISTRY["entries"].get(task_key(m)) or {}).get("code") or "").strip()), None)
            if src:
                sources.append(src)
    total = 0
    for t in sources:
        e = REGISTRY["entries"][task_key(t)]
        total += queue_port(t, e["code"], e.get("verified_by") or "Imported (unattributed)",
                            e.get("tool_used") or "", catchup=True, tried=tried)
    return total


# =========================================================================== #
# AI proxy (the contributor's own key; never logged or stored)
# =========================================================================== #

_BASE_PROMPT = ("You reconstruct C++ for Microsoft Visual C++ .NET 2003 (MSVC 7.1) so that it compiles to the exact "
                "target bytes. Write normal, readable C++ only: no inline assembly, no __declspec(naked), no section "
                "pragmas, no byte arrays. Reply with one ```cpp code block.")


def _load_system_prompt() -> str:
    """The base rules plus the measured code-generation facts from the AI handoff file."""
    try:
        text = HANDOFF_MD.read_text(encoding="utf-8")
        start = text.index("## Code generation facts")
        end = text.find("\n## ", start + 5)
        return _BASE_PROMPT + "\n\n" + text[start:end if end != -1 else None].strip()
    except (OSError, ValueError):
        return _BASE_PROMPT


SYSTEM_PROMPT = _load_system_prompt()


AI_TIMEOUT = 900           # seconds per request: at high reasoning a model can think for many minutes on a big function
OLLAMA_TIMEOUT = 1200      # a model running on this computer can be much slower
# Every provider is asked to reason at this level (the connection test is left at the model's default, to stay
# cheap). A model that doesn't take the setting gets the same request again without it.
REASONING = "high"
QUICK_BYTES = 8                    # the page's TINY_BYTES: functions this small are asked quickly, a few times at most
ANTHROPIC_MAX_TOKENS = 64000   # thinking counts toward max_tokens, so high effort needs room
# Anthropic API version. In 2026-10-21 temperature/top_p/top_k were removed (sending one is a 400 on every model).
ANTHROPIC_VERSION = "2026-10-21"
ANTHROPIC_OLD_VERSION = "2023-06-01"
TEST_PROMPT = "Reply with the single word OK."


def _http_json(url: str, body: Optional[dict], headers: dict, timeout: int = AI_TIMEOUT) -> Tuple[int, dict, str]:
    data = json.dumps(body).encode() if body is not None else None
    req = urllib.request.Request(url, data=data, headers={"Content-Type": "application/json", **headers},
                                 method="POST" if body is not None else "GET")
    try:
        with urllib.request.urlopen(req, timeout=timeout) as r:
            raw = r.read().decode("utf-8", "replace")
            return r.status, (json.loads(raw) if raw.strip() else {}), raw
    except urllib.error.HTTPError as e:
        raw = e.read().decode("utf-8", "replace")
        try:
            return e.code, json.loads(raw), raw
        except Exception:
            return e.code, {}, raw


_HTTP_HINTS = {
    401: "The API key was rejected. Check that you pasted the whole key.",
    403: "This key can't use that model (or billing isn't set up for it).",
    404: "Model not found. Check the model name.",
    429: "Rate limit or quota reached. Wait a minute, or check your plan and billing.",
    529: "The provider is overloaded right now. Try again in a minute.",
}


def _err(status: int, raw: str, key: str) -> str:
    text = raw[:300].replace(key, "***") if key else raw[:300]
    hint = _HTTP_HINTS.get(status) or (_HTTP_HINTS[401] if status == 400 and "api key not valid" in raw.lower() else "")
    if not hint and status >= 500:
        hint = "The provider had a problem. Try again in a minute."
    return f"{hint} (HTTP {status}: {text})" if hint else f"HTTP {status}: {text}"


def _rejects_temperature(st: int, raw: str) -> bool:
    """Newer reasoning models only accept their default temperature and answer 400 when one is set."""
    return st == 400 and "temperature" in raw.lower()


def _default_temperature_only(model: str) -> bool:
    """OpenAI reasoning models (o-series, GPT-5 and later) take only their default temperature; leaving it out
    saves a rejected request. Works for OpenRouter names too (openai/gpt-6.1-sol)."""
    m = model.lower().rsplit("/", 1)[-1].lstrip("~")
    return bool(re.match(r"^(o\d|gpt-([5-9]|\d\d))", m))


def _no_text(reason: str) -> str:
    reason = (reason or "").lower()
    if reason in ("length", "max_tokens", "max_output_tokens"):
        return "The model ran out of output space before it finished. Try again, or pick a model with more output."
    if reason in ("refusal", "safety", "content_filter", "prohibited_content", "blocklist", "recitation"):
        return f"The model declined to answer ({reason}). Try again or use another model."
    return f"The model sent back no text ({reason or 'no reason given'}). Try again."


def _openai_style(url: str, key: str, model: str, prompt: str, extra_headers: Optional[dict] = None,
                  system: str = "", timeout: int = AI_TIMEOUT, reasoning: Optional[dict] = None) -> Tuple[bool, str, str]:
    """reasoning: extra body fields that ask for more thinking ({"reasoning_effort": "high"} on OpenAI and
    compatible servers, {"reasoning": {"effort": "high"}} on OpenRouter). Dropped again if the server refuses them."""
    msgs = ([{"role": "system", "content": system}] if system else []) + [{"role": "user", "content": prompt}]
    body = {"model": model, "messages": msgs, **(reasoning or {})}
    if not _default_temperature_only(model):
        body["temperature"] = 0.2
    headers = {"Authorization": f"Bearer {key}"} if key else {}
    headers.update(extra_headers or {})
    st, j, raw = _http_json(url, body, headers, timeout)
    for _ in range(2):
        if "temperature" in body and _rejects_temperature(st, raw):
            body.pop("temperature")
        elif reasoning and st in (400, 422) and any(k in body for k in reasoning):
            for k in reasoning:               # an older or non-reasoning model that doesn't take the setting
                body.pop(k, None)
        else:
            break
        st, j, raw = _http_json(url, body, headers, timeout)
    if st != 200:
        return False, _err(st, raw, key), model
    try:
        choice = j["choices"][0]
        msg = choice["message"]
    except Exception:
        return False, "Unexpected answer from the provider: " + (raw[:200].replace(key, "***") if key else raw[:200]), model
    text = msg.get("content") or ""
    if isinstance(text, list):                   # some compatible servers send content parts
        text = "".join(part.get("text", "") for part in text if isinstance(part, dict))
    if not str(text).strip():
        return False, _no_text("refusal" if msg.get("refusal") else choice.get("finish_reason", "")), model
    return True, text, j.get("model", model)


def _gemini(key: str, model: str, prompt: str, system: str = "", reasoning: str = "") -> Tuple[bool, str, str]:
    """Gemini 3 and later are meant to run at their default temperature (lower can make them loop), so none
    is sent. reasoning sets the thinking level (dropped for a model that refuses it). A retired model name (404)
    is swapped for one the key can use."""
    base = "https://generativelanguage.googleapis.com/v1beta"
    body = {"contents": [{"role": "user", "parts": [{"text": prompt}]}]}
    if system:
        body["system_instruction"] = {"parts": [{"text": system}]}
    hdr = {"x-goog-api-key": key}

    def call(m: str):
        url = f"{base}/models/{urllib.parse.quote(m)}:generateContent"
        b = dict(body, generationConfig={"thinkingConfig": {"thinkingLevel": reasoning}}) if reasoning else body
        st, j, raw = _http_json(url, b, hdr)
        if reasoning and st == 400 and "think" in raw.lower():     # a model without thinking levels
            st, j, raw = _http_json(url, body, hdr)
        if st != 200:
            return False, _err(st, raw, key), m, st
        cand = (j.get("candidates") or [{}])[0]
        parts = (cand.get("content") or {}).get("parts") or []
        text = "".join(p.get("text", "") for p in parts if not p.get("thought"))
        if not text.strip():
            reason = cand.get("finishReason") or (j.get("promptFeedback") or {}).get("blockReason") or ""
            return False, _no_text(str(reason)), m, st
        return True, text, m, st

    m = model.replace("models/", "").strip()
    ok, text, used, st = call(m)
    if ok or st != 404:
        return ok, text, used
    st2, j2, raw2 = _http_json(f"{base}/models", None, hdr, timeout=30)       # model retired: pick one that exists
    if st2 == 200:
        names = [x["name"].replace("models/", "") for x in j2.get("models", [])
                 if "generateContent" in (x.get("supportedGenerationMethods") or []) and "gemini" in x.get("name", "")
                 and not any(k in x.get("name", "") for k in ("image", "tts", "embedding", "live", "audio"))]
        for alt in names[:3]:
            ok, alt_text, used, _ = call(alt)
            if ok:
                return True, alt_text, used
    return False, text + f" No replacement was found for '{m}'; pick another model.", m


def _anthropic(key: str, model: str, prompt: str, system: str = "", reasoning: str = "") -> Tuple[bool, str, str]:
    """reasoning: the effort level, with adaptive thinking (Claude 4.6 and later). An older model that doesn't take
    them gets the request again without."""
    body = {"model": model, "max_tokens": 16000, "messages": [{"role": "user", "content": prompt}]}
    if system:
        body["system"] = system
    if reasoning:
        body.update(max_tokens=ANTHROPIC_MAX_TOKENS, thinking={"type": "adaptive"}, output_config={"effort": reasoning})
    url = "https://api.anthropic.com/v1/messages"
    hdrs = {"x-api-key": key, "anthropic-version": ANTHROPIC_VERSION}
    st, j, raw = _http_json(url, body, hdrs)
    if st == 400 and "anthropic-version" in raw.lower():      # an older API that doesn't know the new version
        hdrs["anthropic-version"] = ANTHROPIC_OLD_VERSION
        st, j, raw = _http_json(url, body, hdrs)
    low = raw.lower()
    if reasoning and st == 400 and any(w in low for w in ("thinking", "effort", "output_config", "max_tokens")):
        for k in ("thinking", "output_config"):
            body.pop(k, None)
        body["max_tokens"] = 16000
        st, j, raw = _http_json(url, body, hdrs)
    if st != 200:
        return False, _err(st, raw, key), model
    text = "".join(b.get("text", "") for b in j.get("content", []) if b.get("type") == "text")
    if not text.strip():
        return False, _no_text(j.get("stop_reason", "")), model
    return True, text, j.get("model", model)


def _ollama(model: str, prompt: str, system: str = "", reasoning: str = "") -> Tuple[bool, str, str]:
    """reasoning turns thinking on: gpt-oss models take a level, the other thinking models only on/off. A model
    that can't think gets the request again without it."""
    msgs = ([{"role": "system", "content": system}] if system else []) + [{"role": "user", "content": prompt}]
    body = {"model": model, "stream": False, "options": {"temperature": 0.2}, "messages": msgs}
    if reasoning:
        body["think"] = reasoning if "gpt-oss" in model.lower() else True
    url = "http://127.0.0.1:11434/api/chat"
    st, j, raw = _http_json(url, body, {}, OLLAMA_TIMEOUT)
    if reasoning and st == 400 and "think" in raw.lower():
        body.pop("think")
        st, j, raw = _http_json(url, body, {}, OLLAMA_TIMEOUT)
    if st == 404:
        return False, f"Ollama doesn't have '{model}' yet. Download it first: ollama pull {model}", model
    if st != 200:
        return False, _err(st, raw, ""), model
    text = (j.get("message") or {}).get("content", "")
    if not text.strip():
        return False, _no_text(j.get("done_reason", "")), model
    return True, text, j.get("model", model)


def _chat_url(url: str) -> str:
    """An OpenAI-compatible base URL ('https://host/v1') gets '/chat/completions' added; a full URL is kept."""
    u = url.strip().rstrip("/")
    if re.search(r"/chat/completions$", u):
        return u
    return u + ("/chat/completions" if re.search(r"/v\d+[a-z]*$", u) else "/v1/chat/completions")


def ai_call(cfg: dict) -> dict:
    provider = (cfg.get("provider") or "").strip()
    model = (cfg.get("model") or "").strip()
    key = (cfg.get("api_key") or "").strip()
    test = bool(cfg.get("is_test"))
    prompt = TEST_PROMPT if test else (cfg.get("prompt") or "")
    system = "" if test else SYSTEM_PROMPT          # the test only checks the key and the model, cheaply
    if not prompt:
        return {"ok": False, "error": "Empty prompt."}
    if provider not in ("gemini", "openai", "argon", "custom_api", "anthropic", "ollama"):
        return {"ok": False, "error": f"Unknown provider '{provider}'."}
    if provider not in ("ollama", "custom_api") and not key:
        return {"ok": False, "error": "Paste an API key first."}
    if provider == "custom_api" and not re.match(r"^https?://", (cfg.get("custom_url") or "").strip()):
        return {"ok": False, "error": "Custom URL must start with http:// or https://"}
    if not model and provider != "gemini":
        return {"ok": False, "error": "Pick a model, or type its name."}
    label = {"argon": "OpenRouter", "custom_api": "the custom URL", "ollama": "Ollama"}.get(provider, provider.title())
    # a function of a few bytes doesn't need minutes of thinking: the page asks for a quick answer for those
    effort = "" if test else ("low" if cfg.get("quick") else REASONING)
    try:
        if provider == "gemini":
            ok, text, used = _gemini(key, model or "gemini-flash-latest", prompt, system, effort)
        elif provider == "openai":
            # Only reasoning models take reasoning_effort; an older one (gpt-4.1) would refuse the request.
            r = {"reasoning_effort": effort} if effort and _default_temperature_only(model) else None
            ok, text, used = _openai_style("https://api.openai.com/v1/chat/completions", key, model, prompt,
                                           system=system, reasoning=r)
        elif provider == "argon":
            ok, text, used = _openai_style("https://openrouter.ai/api/v1/chat/completions", key, model, prompt,
                                           {"X-Title": "Scarface Decomp Portal"}, system=system,
                                           reasoning={"reasoning": {"effort": effort}} if effort else None)
        elif provider == "custom_api":
            ok, text, used = _openai_style(_chat_url(cfg["custom_url"]), key, model, prompt, system=system,
                                           reasoning={"reasoning_effort": effort} if effort else None)
        elif provider == "anthropic":
            ok, text, used = _anthropic(key, model, prompt, system, effort)
        else:
            ok, text, used = _ollama(model, prompt, system, effort)
    except urllib.error.URLError as e:
        reason = getattr(e, "reason", e)
        if isinstance(reason, TimeoutError):
            return {"ok": False, "error": f"{label} took too long to answer. Try again, or pick a faster model."}
        if provider == "ollama":
            return {"ok": False, "error": "Could not reach Ollama on this computer (127.0.0.1:11434). "
                                          "Is it running? Start it with: ollama serve"}
        return {"ok": False, "error": f"Could not reach {label}: {reason}"}
    except TimeoutError:
        return {"ok": False, "error": f"{label} took too long to answer. Try again, or pick a faster model."}
    except Exception as e:  # never echo the key
        return {"ok": False, "error": f"{type(e).__name__}: {str(e).replace(key, '***') if key else e}"}
    return {"ok": True, "reply": text, "used_model": used} if ok else {"ok": False, "error": text}


# =========================================================================== #
# Git sync (maintainers only)
# =========================================================================== #

# docs/feed.xml and docs/functions.json are made from the registry too (registry_outputs.py): the website's feed
# and its list of rebuilt functions, so they go up with every sync.
GIT_PATHS = ["reconstructed_src", "reports/verified_registry.json", "reports/reverify_report.md",
             "reports/decomp_audit_log.json", "reports/progress.json", "README.md", "docs/feed.xml", "docs/functions.json",
             "docs/sitemap.xml"]


NOT_A_CLONE = ("This folder isn't connected to GitHub: it was downloaded as a ZIP, so it has no .git folder. "
               "Connect it once with the commands under \"Downloaded the ZIP?\" in docs/CONTRIBUTING.md, "
               "then press Sync again.")
PUSH_BEHIND = ("Saved here, but GitHub has newer changes than this folder. Run \"git pull\" in the project "
               "folder, then press Sync again.")


def _same_folder(a: str, b: Path) -> bool:
    return os.path.normcase(os.path.realpath(a)) == os.path.normcase(os.path.realpath(str(b)))


def announce_on_discord() -> dict:
    """After a push: post the new matches to the Discord webhook set up on this computer, if any
    (portal/tools/discord_feed.py). Never fails the push."""
    try:
        with STATE_LOCK:
            main = [t for t in ALL_TASKS if t["bin"] in ("pc", "xb")]
            done = sum(1 for t in main if t["status"] == "VERIFIED")
            good = GOOD.rank(ALL_TASKS, 3)
            registry = {"entries": dict(REGISTRY.get("entries", {}))}
        res = DISCORD.announce_new(BASE_DIR, registry, done, len(main), good)
    except Exception as e:  # noqa: BLE001 - a Discord problem must not break syncing
        res = {"skipped": f"error: {e}"}
    if res.get("posted"):
        print(f"[discord] posted {res['posted']} new match(es)")
    return res


def git_sync(user: str, base: Path = BASE_DIR) -> dict:
    def run(args, timeout=120):
        p = subprocess.run(["git"] + args, cwd=base, capture_output=True, text=True, timeout=timeout)
        return p.returncode, (p.stdout + p.stderr).strip()
    try:
        rc, top = run(["rev-parse", "--show-toplevel"])
        if rc or not _same_folder(top, base):       # no .git here (a ZIP download), or a folder inside another repo
            return {"ok": False, "error": NOT_A_CLONE}
        rc, out = run(["add", "--"] + [p for p in GIT_PATHS if (base / p).exists()])
        if rc:
            return {"ok": False, "error": "git add failed: " + out[-400:]}
        rc, out = run(["diff", "--cached", "--quiet"])
        if rc == 0:
            return {"ok": True, "message": "Nothing new to commit; GitHub is up to date."}
        n = len(REGISTRY.get("entries", {}))
        rc, out = run(["commit", "-m", f"Verified functions: {n} total (synced from portal by {user})"])
        if rc:
            return {"ok": False, "error": "git commit failed: " + out[-400:]}
        rc, out = run(["push"], timeout=300)
        if rc and ("fetch first" in out or "non-fast-forward" in out):
            return {"ok": False, "error": PUSH_BEHIND}
        if rc:
            return {"ok": False, "error": "Committed locally, but git push failed: " + out[-400:]}
        threading.Thread(target=announce_on_discord, name="discord", daemon=True).start()
        return {"ok": True, "message": f"Pushed {n} verified functions to GitHub."}
    except FileNotFoundError:
        return {"ok": False, "error": "git is not installed or not on PATH."}
    except subprocess.TimeoutExpired:
        return {"ok": False, "error": "git timed out."}


# =========================================================================== #
# Submitting work (everyone) and importing it (maintainers)
# =========================================================================== #
# Every match is saved in reports/verified_registry.json the moment it verifies, so closing the portal
# loses nothing. "Submit your work" gets the matches that are not on GitHub yet to the project: a maintainer's
# press commits and pushes them; anyone else's packs them into one file to post in the Discord or a GitHub
# issue. A maintainer imports that file, which compiles every function again before it is added under the
# name of whoever matched it.

SUBMISSION_FORMAT = "scarface-decomp-submission"
SUBMISSION_FIELDS = ("bin", "va", "size", "symbol", "flags", "verified_by", "tool_used", "verified_at", "code",
                     "ported_from", "revised_by", "note", "what", "what_by")
IMPORT_MAX = 20000
_PUBLISHED: Dict[str, object] = {"head": None, "keys": frozenset(), "what": {}}
IMPORT_STATUS: Dict[str, object] = {"running": False}


def _git_head(base: Path = BASE_DIR) -> Optional[str]:
    """The checked-out commit, read from .git without running git (cheap enough for every page refresh)."""
    g = base / ".git"
    try:
        head = (g / "HEAD").read_text(encoding="utf-8").strip()
        if not head.startswith("ref: "):
            return head or None
        ref = head[5:]
        if (g / ref).exists():
            return (g / ref).read_text(encoding="utf-8").strip() or None
        if (g / "packed-refs").exists():
            for line in (g / "packed-refs").read_text(encoding="utf-8").splitlines():
                if line.endswith(" " + ref):
                    return line.split(" ", 1)[0]
    except OSError:
        pass
    return None


def published_keys(base: Path = BASE_DIR) -> frozenset:
    """Matches already on GitHub: the registry as of this folder's last commit."""
    head = _git_head(base)
    if head is None:
        return frozenset()
    if _PUBLISHED["head"] != head:
        keys: frozenset = frozenset()
        what: Dict[str, str] = {}
        try:
            p = subprocess.run(["git", "show", "HEAD:reports/verified_registry.json"], cwd=base,
                               capture_output=True, timeout=60)
            if p.returncode == 0:
                entries = json.loads(p.stdout.decode("utf-8")).get("entries", {})
                keys = frozenset(entries)
                what = {k: e.get("what", "") for k, e in entries.items() if isinstance(e, dict)}
        except (OSError, ValueError, subprocess.TimeoutExpired):
            pass
        _PUBLISHED.update(head=head, keys=keys, what=what)
    return _PUBLISHED["keys"]  # type: ignore[return-value]


def pending_descriptions() -> Dict[str, dict]:
    """Descriptions written here for functions already on GitHub, not on GitHub yet."""
    pub = published_keys()
    old = _PUBLISHED.get("what") or {}
    with STATE_LOCK:
        return {k: {"what": e.get("what", ""), "what_by": e.get("what_by", "")}
                for k, e in REGISTRY.get("entries", {}).items()
                if k in pub and (e.get("what") or "") != (old.get(k) or "")}


def pending_keys() -> List[str]:
    """Matches saved on this computer that are not on GitHub yet."""
    pub = published_keys()
    with STATE_LOCK:
        return [k for k in REGISTRY.get("entries", {}) if k not in pub]


def make_submission(user: str) -> dict:
    with STATE_LOCK:
        entries = {k: {f: e[f] for f in SUBMISSION_FIELDS if f in e}
                   for k in pending_keys() for e in [REGISTRY["entries"][k]]
                   if (e.get("code") or "").strip() and not e.get("excerpt")}
    described = pending_descriptions()
    return {"format": SUBMISSION_FORMAT, "version": 1, "submitted_by": user, "created": stamp(),
            "compiler": compiler_version(), "count": len(entries) + len(described), "entries": entries,
            "descriptions": described}


def submission_filename(user: str) -> str:
    slug = re.sub(r"[^A-Za-z0-9]+", "-", user).strip("-")[:40] or "contributor"
    return f"scarface-submission-{slug}-{dt.datetime.now().strftime('%Y-%m-%d-%H%M')}.json"


def import_submission(bundle: dict, importer: str) -> dict:
    """Compile every function of a submission again, exactly as a match made here is checked, and add the ones
    that match under the name of whoever matched them. Progress is in IMPORT_STATUS."""
    st = IMPORT_STATUS
    entries = bundle.get("entries") if isinstance(bundle, dict) else None
    who_sent = str((bundle or {}).get("submitted_by") or "unknown")[:64] if isinstance(bundle, dict) else "unknown"
    st.clear()
    st.update(running=True, submitted_by=who_sent, total=len(entries) if isinstance(entries, dict) else 0,
              done=0, added=0, already=0, failed=[], error="")
    try:
        if not isinstance(bundle, dict) or bundle.get("format") != SUBMISSION_FORMAT or not isinstance(entries, dict):
            st["error"] = "That file is not a submission from the Scarface portal."
            return st
        with STATE_LOCK:
            by_key = {task_key(t): t for t in ALL_TASKS}
        added = 0
        for key, e in list(entries.items())[:IMPORT_MAX]:
            st["done"] += 1
            e = e if isinstance(e, dict) else {}
            t = by_key.get(str(key))
            code = e.get("code") if isinstance(e.get("code"), str) else ""
            who = str(e.get("verified_by") or who_sent)[:64]
            tool = str(e.get("tool_used") or "")[:120]
            name = str(e.get("symbol") or key)[:120]
            if t is None:
                st["failed"].append({"symbol": name, "reason": "not in this portal's function list (is that game file here?)"})
                continue
            if t["status"] == "VERIFIED":
                st["already"] += 1
                continue
            if not code.strip() or len(code) > 200_000:
                st["failed"].append({"symbol": t["symbol"], "reason": "no code"})
                continue
            res = run_verify(t, code)
            if not (res.get("ok") and res.get("verified")):
                why = (res.get("compiler_error") or res.get("error") or "").strip().splitlines()
                st["failed"].append({"symbol": t["symbol"], "reason": why[0][:200] if why else
                                     f"{res.get('matched_bytes', 0)} of {res.get('total_bytes', t['size'])} bytes match"})
                continue
            with STATE_LOCK:
                if t["status"] == "VERIFIED":
                    st["already"] += 1
                    continue
                record_verified(t, code, who, tool, res, write=False, what=clean_what(e.get("what")))
                REGISTRY["entries"][task_key(t)].update(imported_by=importer, imported_at=stamp())
                if REGISTRY["entries"][task_key(t)].get("what") and e.get("what_by"):
                    REGISTRY["entries"][task_key(t)]["what_by"] = str(e["what_by"])[:64]
                t.update(status="VERIFIED", claimed_by="", claim_expires_at=0)
                save_overlay(t)
                added += 1
                st["added"] = added
            if not res.get("reloc_unverified"):
                queue_port(t, code, who, tool)
        # descriptions of functions that are rebuilt already: text only, nothing to compile
        described = 0
        notes = bundle.get("descriptions") if isinstance(bundle.get("descriptions"), dict) else {}
        with STATE_LOCK:
            for key, d in list(notes.items())[:IMPORT_MAX]:
                e = REGISTRY["entries"].get(str(key))
                what = clean_what((d or {}).get("what")) if isinstance(d, dict) else ""
                if not e or not what or what == e.get("what"):
                    continue
                e.update(what=what, what_by=str(d.get("what_by") or who_sent)[:64], what_at=stamp())
                described += 1
            st["described"] = described
        with STATE_LOCK:
            if added or described:
                save_registry()
                append_audit({"time": stamp(), "user": importer, "action": "VERIFIED",
                              "symbol": f"{added} function(s) submitted by {who_sent}", "va": "",
                              "bytes": "checked again on import"})
                print(f"[+] Imported {added} function(s) submitted by {who_sent} -> {len(REGISTRY['entries'])} total")
    except Exception as ex:  # noqa: BLE001 - report it on the page instead of losing the thread
        st["error"] = f"{type(ex).__name__}: {ex}"
    finally:
        st["running"] = False
    return st


# =========================================================================== #
# Scripts tab
# =========================================================================== #

SCRIPT_EXTS = (".cso", ".dso", ".dtr", ".cs")
# Folders under binaries/scripts_and_data/ and what they hold. Retail scripts are the same files on
# the Xbox and PS2 discs (docs/SCRIPTS.md), so either folder name means "retail".
SCRIPT_VERSIONS = {
    "xbox": "Retail game (Xbox; the PS2 disc has the same files)",
    "ps2": "Retail game (PS2 disc; the Xbox disc has the same files)",
    "pc": "PC game (installed copy)",
    "prototype": "Xbox prototype, April 2006",
    "uploads": "Files you loaded",
}
RETAIL_SCRIPT_DIRS = ("xbox", "ps2")
_SCRIPT_INDEX: Dict[str, object] = {"key": None, "items": [], "versions": []}


def _script_version(rel: Path) -> str:
    return rel.parts[0] if len(rel.parts) > 1 else "uploads"


def script_index() -> Tuple[List[dict], List[dict]]:
    """Every script file under binaries/scripts_and_data/, without reading their contents in detail.

    Files in a non-retail folder (the prototype) are compared with the retail copy at the same path:
    'same', 'changed', or 'only here' (scripts that never shipped)."""
    if not SCRIPTS_DIR.exists():
        return [], []
    paths = [p for p in SCRIPTS_DIR.rglob("*") if p.is_file() and p.suffix.lower() in SCRIPT_EXTS]
    key = tuple(sorted((str(p), p.stat().st_mtime_ns, p.stat().st_size) for p in paths))
    if _SCRIPT_INDEX["key"] == key:
        return _SCRIPT_INDEX["items"], _SCRIPT_INDEX["versions"]
    retail: Dict[str, str] = {}
    rows = []
    for p in paths:
        rel = p.relative_to(SCRIPTS_DIR)
        version = _script_version(rel)
        inner = "/".join(rel.parts[1:] if version != "uploads" or len(rel.parts) > 1 else rel.parts).lower()
        digest = hashlib.sha1(p.read_bytes()).hexdigest()
        if version in RETAIL_SCRIPT_DIRS:
            retail.setdefault(inner, digest)
        rows.append((p, rel, version, inner, digest))
    items = []
    counts: Counter = Counter()
    for p, rel, version, inner, digest in rows:
        compare = ""
        if retail and version not in RETAIL_SCRIPT_DIRS and version != "uploads":
            compare = "only here" if inner not in retail else ("same" if retail[inner] == digest else "changed")
        counts[version] += 1
        items.append({"path": rel.as_posix(), "name": p.name, "version": version, "ext": p.suffix[1:].upper(),
                      "size": p.stat().st_size, "compare": compare})
    order = list(SCRIPT_VERSIONS)
    items.sort(key=lambda x: (order.index(x["version"]) if x["version"] in order else 9, x["path"].lower()))
    versions = [{"id": v, "label": SCRIPT_VERSIONS.get(v, v), "count": counts[v]}
                for v in sorted(counts, key=lambda v: order.index(v) if v in order else 9)]
    _SCRIPT_INDEX.update(key=key, items=items, versions=versions)
    return items, versions


_SCRIPT_NAMES: Dict[str, Tuple[tuple, dict]] = {}


def script_names(version: str) -> dict:
    """Readable names for the hashed identifiers in one version folder's scripts, recovered from the
    user's own game files (torque_script.names_for); worked out once per folder."""
    import torque_script as TS
    if _SCRIPT_INDEX["key"] is None:
        script_index()
    key = _SCRIPT_INDEX["key"]                       # changes when script_index() sees the files change
    cached = _SCRIPT_NAMES.get(version)
    if cached and cached[0] == key:
        return cached[1]
    folder = SCRIPTS_DIR / version if version != "uploads" else SCRIPTS_DIR
    files = [p for p in folder.rglob("*") if p.is_file() and p.suffix.lower() in (".cso", ".dso", ".cs")] \
        if folder.is_dir() else []
    names = TS.names_for(files, BASE_DIR / "binaries")
    _SCRIPT_NAMES[version] = (key, names)
    return names


def script_text(rel: str) -> dict:
    """Just the readable TorqueScript of one file, for downloads (the 1:1 check result is already known)."""
    p = (SCRIPTS_DIR / rel).resolve()
    if not rel or SCRIPTS_DIR.resolve() not in p.parents or not p.is_file():
        return {"ok": False}
    ext = p.suffix.lower()
    if ext in (".cso", ".dso"):
        import torque_script as TS
        try:
            return {"ok": True, "format": "TorqueScript", "decompiled_code": TS.decompile(p.read_bytes(), script_names(_script_version(Path(rel))))}
        except Exception as e:  # noqa: BLE001 - one odd file shouldn't stop the download
            return {"ok": True, "format": "could not be read", "decompiled_code": f"// {p.name}: {e}"}
    return script_detail(rel)


def script_detail(rel: str) -> dict:
    """One script file: readable TorqueScript checked byte for byte, and its instruction listing."""
    from cso_dso_dtr_decompiler import verify_and_decompile_cso_dso, verify_and_decompile_dtr
    p = (SCRIPTS_DIR / rel).resolve()
    if not rel or SCRIPTS_DIR.resolve() not in p.parents or not p.is_file() or p.suffix.lower() not in SCRIPT_EXTS:
        return {"ok": False, "error": "No such script file."}
    raw = p.read_bytes()
    ext = p.suffix.lower()
    if ext == ".cs":
        text = raw.decode("latin-1")
        return {"ok": True, "path": rel, "format": "TorqueScript source (plain text, left in the game files)",
                "size": len(raw), "opcode_count": 0, "decompiled_code": text,
                "disasm": "(plain source: nothing to disassemble)"}
    try:
        if ext == ".dtr":
            res = verify_and_decompile_dtr(raw, p.name, BASE_DIR / "binaries")
        else:
            res = verify_and_decompile_cso_dso(raw, p.name, script_names(_script_version(Path(rel))))
    except Exception as e:  # noqa: BLE001 - one odd file shouldn't break the tab
        res = {"ok": False, "error": str(e)}
    if not res.get("ok"):
        return {"ok": True, "path": rel, "format": "could not be read", "size": len(raw), "opcode_count": 0,
                "decompiled_code": f"// {p.name}: {res.get('error')}", "disasm": ""}
    return {"ok": True, "path": rel, "format": res["format"], "size": res["size"],
            "opcode_count": res["opcode_count"], "disasm": res["disasm"], "decompiled_code": res["decompiled_code"]}


# ---------------------------------------------------------------------------
# Every script checked once: decompiled, compiled again, compared. Results are kept per file (size and
# modification time) in binaries/scripts_and_data/.decompile_check.json (never committed), so a file is
# only checked again when it changes.
SCRIPT_CHECK_FILE = SCRIPTS_DIR / ".decompile_check.json"
_SCRIPT_CHECK: Dict[str, object] = {"running": False, "results": {}}


def _check_key(p: Path) -> list:
    st = p.stat()
    return [st.st_size, st.st_mtime_ns]


def check_scripts(verbose: bool = True) -> dict:
    """Decompile and recompile every .cso/.dso under binaries/scripts_and_data/; {path: exact}."""
    import torque_script as TS
    cache = read_json(SCRIPT_CHECK_FILE, {}) if SCRIPT_CHECK_FILE.exists() else {}
    results: Dict[str, bool] = {}
    _SCRIPT_CHECK["running"] = True
    try:
        items, versions = script_index()
        for v in versions:
            files = [i for i in items if i["version"] == v["id"] and i["ext"] in ("CSO", "DSO")]
            todo = [i for i in files if (cache.get(i["path"]) or [None])[:2] != _check_key(SCRIPTS_DIR / i["path"])]
            names = script_names(v["id"]) if todo else {}
            for i in files:
                p = SCRIPTS_DIR / i["path"]
                hit = cache.get(i["path"])
                if hit and hit[:2] == _check_key(p):
                    results[i["path"]] = bool(hit[2])
                    continue
                try:
                    ok = TS.check(p.read_bytes(), names)[1]
                except Exception:  # noqa: BLE001 - one odd file is a "no", not a crash
                    ok = False
                results[i["path"]] = ok
                cache[i["path"]] = _check_key(p) + [ok]
                _SCRIPT_CHECK["results"] = dict(results)
            if verbose and files:
                n = sum(1 for i in files if results.get(i["path"]))
                print(f"[*] Game scripts, {v['label']}: {n:,} of {len(files):,} decompile to TorqueScript "
                      "that compiles back byte for byte")
        if SCRIPTS_DIR.is_dir():
            write_json(SCRIPT_CHECK_FILE, {k: v for k, v in cache.items() if k in results})
    finally:
        _SCRIPT_CHECK["results"] = results
        _SCRIPT_CHECK["running"] = False
    return results


def script_check_summary() -> dict:
    """{"running": bool, "versions": [{id, label, compiled, checked, exact}]} for the dashboard."""
    items, versions = script_index()
    res = _SCRIPT_CHECK["results"]
    out = []
    for v in versions:
        files = [i["path"] for i in items if i["version"] == v["id"] and i["ext"] in ("CSO", "DSO")]
        if files:
            out.append({"id": v["id"], "label": v["label"], "compiled": len(files),
                        "checked": sum(1 for f in files if f in res), "exact": sum(1 for f in files if res.get(f))})
    return {"running": bool(_SCRIPT_CHECK["running"]), "versions": out}


def script_list_payload(selected: str = "") -> dict:
    items, versions = script_index()
    res = _SCRIPT_CHECK["results"]
    items = [dict(i, exact=res.get(i["path"])) for i in items]
    out = {"ok": True, "files": items, "versions": versions, "check": script_check_summary()}
    if selected:
        out["selected"] = selected
    return out


def list_sources(full: bool = False) -> Dict[str, str]:
    out = {}
    for p in sorted(list(RECON_DIR.rglob("*.cpp")) + list(RECON_DIR.rglob("*.h")) + list(RECON_DIR.rglob("*.hpp"))):
        rel = str(p.relative_to(RECON_DIR)).replace("\\", "/")
        text = p.read_text(encoding="utf-8", errors="ignore")
        if not full:
            lines = text.splitlines()
            if len(lines) > 220:
                text = "\n".join(lines[:220]) + f"\n\n// ... ({len(lines) - 220} more lines; open the file for the rest) ..."
        out[rel] = text
    return out


# =========================================================================== #
# HTTP
# =========================================================================== #

# --------------------------------------------------------------------------- decomp.me through the browser
# decomp.me turns away programs that aren't a browser, and its pages cut the link to windows opened from other
# sites (Cross-Origin-Opener-Policy), so the person's own decomp.me tab does the calls: a bookmark clicked
# there asks this portal for jobs (/api/dme-bridge/next), makes scratches and compiles on decomp.me, and sends
# the results back (/api/dme-bridge/result). Only decomp.me's own pages may do that (CORS, by Origin).
DME_BRIDGE_ORIGIN = os.environ.get("SCARFACE_DECOMPME_ORIGIN", "https://decomp.me").rstrip("/")
BRIDGE_PATHS = ("/api/dme-bridge/next", "/api/dme-bridge/result")
# The page's Content-Security-Policy (see tools/web_security.py): it may call the portal and decomp.me only.
PAGE_CSP = WS.page_policy((DME.DECOMPME_URL, PV.DECOMPME_URL, DME_BRIDGE_ORIGIN))
# The site's fonts (docs/fonts/), served here too so the portal needs no font site.
FONTS_DIR = BASE_DIR / "docs" / "fonts"
FONT_FILE = re.compile(r"^/fonts/([a-z0-9-]+\.(?:css|woff2))$")
BRIDGE_POLL_SECONDS = 25
BRIDGE_JOB_SECONDS = 180


class Bridge:
    def __init__(self):
        self.cond = threading.Condition()
        self.jobs: List[dict] = []
        self.results: Dict[int, dict] = {}
        self.taken: Dict[int, float] = {}
        self.last_seen = 0.0
        self.seq = 0

    def connected(self) -> bool:
        return time.time() - self.last_seen < BRIDGE_POLL_SECONDS + 15

    def run(self, job: dict, timeout: Optional[float] = None) -> dict:
        """Hand a job to the decomp.me tab and wait for its answer."""
        timeout = BRIDGE_JOB_SECONDS if timeout is None else timeout
        with self.cond:
            self.seq += 1
            jid = self.seq
            self.jobs.append(dict(job, id=jid))
            self.cond.notify_all()
            end = time.time() + timeout
            while jid not in self.results:
                left = end - time.time()
                if left <= 0:
                    self.jobs = [j for j in self.jobs if j["id"] != jid]
                    self.taken.pop(jid, None)
                    return {"ok": False, "error": "your decomp.me tab didn't answer in time (is it still open?)"}
                self.cond.wait(min(left, 1.0))
            self.taken.pop(jid, None)
            return self.results.pop(jid)

    def next(self, wait: Optional[float] = None) -> Optional[dict]:
        """The next job for the decomp.me tab, waiting up to `wait` seconds for one."""
        wait = BRIDGE_POLL_SECONDS if wait is None else wait
        with self.cond:
            self.last_seen = time.time()
            end = time.time() + wait
            while not self.jobs:
                left = end - time.time()
                if left <= 0:
                    return None
                self.cond.wait(left)
            job = self.jobs.pop(0)
            self.taken[job["id"]] = time.time()
            self.last_seen = time.time()
            return job

    def result(self, res: dict) -> bool:
        with self.cond:
            jid = res.get("id")
            if not isinstance(jid, int) or jid not in self.taken:
                return False
            self.results[jid] = res
            self.taken.pop(jid, None)
            self.cond.notify_all()
            return True


BRIDGE = Bridge()


class Handler(BaseHTTPRequestHandler):
    server_version = "ScarfaceDecomp/2"

    def log_message(self, fmt, *args):
        pass

    def send_header(self, keyword, value):
        if keyword.lower() == "content-type":
            self._ctype = value
        super().send_header(keyword, value)

    def end_headers(self):
        """Every answer gets the security headers (tools/web_security.py): no framing, and a policy that fits
        what it is."""
        path = urllib.parse.urlparse(getattr(self, "path", "")).path
        for k, v in WS.headers(getattr(self, "_ctype", ""), PAGE_CSP, shared=path in BRIDGE_PATHS):
            super().send_header(k, v)
        self._ctype = ""
        super().end_headers()

    def _download(self, kind: str, q1) -> None:
        """/download/functions|scripts|sources?format=zip|txt&only=verified (&build=xb|pc|proto, &version=...)"""
        import downloads as DL
        fmt = "txt" if q1("format") == "txt" else "zip"
        only = q1("only") == "verified"
        day = dt.datetime.now().strftime("%Y-%m-%d")
        tag = "verified-" if only else ""
        if kind == "functions":
            build = q1("build", "all")
            builds = [b for b in DL.BUILD_ORDER if build in ("all", b) or (build == "ps2" and PO.is_ps2(b))]
            if not builds:
                return self._json({"ok": False, "error": "Unknown game file."}, 400)
            with STATE_LOCK:
                reg = {"compiler": REGISTRY.get("compiler", ""), "entries": dict(REGISTRY.get("entries", {}))}
                queue = list(ALL_TASKS)
            counts = {b: (sum(1 for e in reg["entries"].values() if e.get("bin") == b),
                          sum(1 for t in queue if t.get("bin") == b)) for b in builds}
            if only and not any(c[0] for c in counts.values()):
                return self._json({"ok": False, "error": "Nothing verified yet in that game file."}, 404)
            files = DL.function_files(reg, queue, builds, only, write_outputs, RO.BIN_INFO, by_class=fmt == "zip")
            readme = DL.functions_readme(builds, only, counts)
            title = "SCARFACE: THE WORLD IS YOURS: DECOMPILED FUNCTIONS" + (" (VERIFIED ONLY)" if only else "")
            name = f"scarface-functions-{tag}{'all' if build == 'all' else RO.BIN_INFO[build][1]}-{day}"
        elif kind == "scripts":
            version = q1("version", "all")
            items, versions = script_index()
            if not items:
                return self._json({"ok": False, "error": "No game scripts here yet: they are copied out of your game files when the portal starts."}, 404)
            import dtr_format as DTR

            def dtr_exact(rel: str) -> bool:
                try:
                    return DTR.round_trip((SCRIPTS_DIR / rel).read_bytes())[0]
                except Exception:  # noqa: BLE001
                    return False
            files, stats = DL.script_files(items, script_text, dict(_SCRIPT_CHECK["results"]), only,
                                           None if version == "all" else [version], dtr_exact=dtr_exact)
            if not files:
                return self._json({"ok": False, "error": "No script files match that choice." +
                                   (" The 1:1 check is still running; try again in a minute." if _SCRIPT_CHECK["running"] else "")}, 404)
            readme = DL.scripts_readme(only, stats, [v["id"] for v in versions if version in ("all", v["id"])])
            title = "SCARFACE: THE WORLD IS YOURS: GAME SCRIPTS AS TORQUESCRIPT" + (" (1:1 ONLY)" if only else "")
            name = f"scarface-game-scripts-{tag}{version}-{day}"
        else:
            def regenerate() -> Dict[str, str]:
                with STATE_LOCK:
                    reg = {"compiler": REGISTRY.get("compiler", ""), "entries": dict(REGISTRY.get("entries", {}))}
                files = DL.function_files(reg, [], DL.BUILD_ORDER, True, write_outputs, RO.BIN_INFO)
                out = {}
                for rel, text in files.items():           # back to reconstructed_src/ layout
                    folder, rest = rel.split("/", 1)
                    out[rest if rest.startswith("Original_Binary_Order") else folder + "/" + rest.replace("by_class/", "", 1)] = text
                return out
            files = DL.source_files(RECON_DIR, only, regenerate)
            readme = ("Scarface: The World Is Yours: reconstructed_src/, the project's C++\n"
                      f"Downloaded from the local portal on {DL.stamp()}.\n\n"
                      "Original_Binary_Order_*.cpp: each game file's functions in address order (where they are in the game).\n"
                      + ("Verified functions only.\n" if only else
                         "Functions not matched yet are listed in their place as // [TODO] lines.\n")
                      + "pc/, xbox/, proto/: the verified code grouped by class. include/: shared headers.\n\n" + DL.ONE_TO_ONE + "\n")
            title = "SCARFACE: THE WORLD IS YOURS: SOURCE FILES (reconstructed_src)" + (" (VERIFIED ONLY)" if only else "")
            name = f"scarface-source-files-{tag}{day}"
        if fmt == "zip":
            data = DL.to_zip({"README.txt": readme, **files}, name)
            return self._send(200, data, "application/zip", {"Content-Disposition": f'attachment; filename="{name}.zip"'})
        text = DL.to_txt(files, title, readme.splitlines())
        return self._send(200, text.encode("utf-8"), "text/plain; charset=utf-8",
                          {"Content-Disposition": f'attachment; filename="{name}.txt"'})

    def _send(self, code: int, body: bytes, ctype: str, extra: Optional[dict] = None):
        self.send_response(code)
        self.send_header("Content-Type", ctype)
        self.send_header("Cache-Control", "no-store")
        if urllib.parse.urlparse(getattr(self, "path", "")).path in BRIDGE_PATHS and self._bridge_origin():
            self.send_header("Access-Control-Allow-Origin", DME_BRIDGE_ORIGIN)
            self.send_header("Vary", "Origin")
        for k, v in (extra or {}).items():
            self.send_header(k, v)
        self.send_header("Content-Length", str(len(body)))
        try:
            self.end_headers()
            self.wfile.write(body)
        except ConnectionError:
            # The page stopped waiting (Stop & Save, a closed tab, a timeout). Nothing to report.
            self.close_connection = True

    def _json(self, obj, code: int = 200):
        self._send(code, json.dumps(obj).encode(), "application/json; charset=utf-8")

    def _body(self) -> Optional[dict]:
        try:
            n = int(self.headers.get("Content-Length", "0"))
        except ValueError:
            n = -1
        if n < 0 or n > MAX_BODY:
            self._json({"ok": False, "error": "Request too large."}, 413)
            return None
        raw = self.rfile.read(n) if n else b"{}"
        try:
            body = json.loads(raw.decode("utf-8"))
            if not isinstance(body, dict):
                raise ValueError
            return body
        except Exception:
            self._json({"ok": False, "error": "Request body must be a JSON object."}, 400)
            return None

    def _allowed(self) -> bool:
        """The portal is for this computer's browser. Refuse requests that a web page on another site
        makes through the visitor's browser (cross-site POSTs), and requests whose Host header names
        some other site (DNS rebinding). Answers with 403 and returns False when refused."""
        local = HOST in ("127.0.0.1", "localhost", "::1")
        host = (self.headers.get("Host") or "").strip().lower()
        hostname = host.rsplit(":", 1)[0] if not host.startswith("[") else host.split("]")[0] + "]"
        if local and host and hostname not in ("127.0.0.1", "localhost", "[::1]"):
            self._json({"ok": False, "error": "This portal only answers on localhost."}, 403)
            return False
        path = urllib.parse.urlparse(self.path).path
        if WS.refuse_cross_site_get(self.command, path, self.headers.get("Sec-Fetch-Site", ""),
                                    self.headers.get("Sec-Fetch-Mode", ""), path in BRIDGE_PATHS and self._bridge_origin()):
            self._json({"ok": False, "error": "Requests from other websites are not accepted."}, 403)
            return False
        if self.command == "POST":
            origin = (self.headers.get("Origin") or "").strip().lower()
            site = (self.headers.get("Sec-Fetch-Site") or "").strip().lower()
            ok_origin = not origin or urllib.parse.urlparse(origin).netloc == host
            if urllib.parse.urlparse(self.path).path in BRIDGE_PATHS and origin == DME_BRIDGE_ORIGIN.lower():
                return True                       # decomp.me's own page, answering a job (see Bridge)
            if site == "cross-site" or not ok_origin:
                self._json({"ok": False, "error": "Requests from other websites are not accepted."}, 403)
                return False
        return True

    def _bridge_origin(self) -> bool:
        return (self.headers.get("Origin") or "").strip().rstrip("/").lower() == DME_BRIDGE_ORIGIN.lower()

    def do_OPTIONS(self):
        """CORS preflight, only for decomp.me asking about the bridge. Chrome also asks before a public site
        may reach this computer (Private Network Access): say yes to decomp.me only."""
        path = urllib.parse.urlparse(self.path).path
        if path not in BRIDGE_PATHS or not self._bridge_origin():
            self.send_response(403)
            self.send_header("Content-Length", "0")
            self.end_headers()
            return
        self.send_response(204)
        self.send_header("Access-Control-Allow-Origin", DME_BRIDGE_ORIGIN)
        self.send_header("Access-Control-Allow-Methods", "GET, POST")
        self.send_header("Access-Control-Allow-Headers", "Content-Type")
        self.send_header("Access-Control-Allow-Private-Network", "true")
        self.send_header("Access-Control-Max-Age", "600")
        self.send_header("Vary", "Origin")
        self.send_header("Content-Length", "0")
        self.end_headers()

    # ---------------------------------------------------------------- GET
    def do_GET(self):
        if not self._allowed():
            return
        expire_leases()
        u = urllib.parse.urlparse(self.path)
        qs = urllib.parse.parse_qs(u.query)
        q1 = lambda k, d="": (qs.get(k) or [d])[0]  # noqa: E731
        if u.path in ("/", "/index.html"):
            return self._send(200, INDEX_HTML.read_bytes(), "text/html; charset=utf-8")
        m = FONT_FILE.match(u.path)
        if m:
            f = FONTS_DIR / m.group(1)
            if not f.is_file():
                return self._send(404, b"", "text/plain")
            return self._send(200, f.read_bytes(), "text/css; charset=utf-8" if f.suffix == ".css" else "font/woff2")
        if u.path in ("/favicon.ico", "/favicon.svg"):     # browsers ask for it on their own
            icon = BASE_DIR / "docs" / "favicon.svg"
            if icon.exists():
                return self._send(200, icon.read_bytes(), "image/svg+xml")
            return self._send(204, b"", "image/svg+xml")
        if u.path in ("/download/functions", "/download/scripts", "/download/sources"):
            return self._download(u.path.rsplit("/", 1)[1], q1)
        if u.path == "/download/ai-handoff":
            data = HANDOFF_MD.read_bytes() if HANDOFF_MD.exists() else b"# AI handoff\n"
            return self._send(200, data, "text/markdown; charset=utf-8",
                              {"Content-Disposition": 'attachment; filename="SCARFACE_DECOMP_AI_HANDOFF.md"'})
        if u.path == "/api/health":
            return self._json({"ok": True, "compiler": compiler_version(),
                               "binaries": {k: bool(image_for(k)) for k in BINARIES}})
        if u.path == "/api/state":
            with STATE_LOCK:
                listed = [t for t in ALL_TASKS if in_default_queue(t)]
                tiers = Counter(t["tier"] for t in listed if t["status"] != "VERIFIED")
                tiers["PARTIAL"] = sum(1 for t in listed if t["status"] == "PARTIAL")
                remaining = sum(1 for t in listed if t["status"] != "VERIFIED")
                copies = Counter(t["in_retail"] for t in ALL_TASKS if t.get("in_retail") and t["status"] != "VERIFIED")
                return self._json({"progress": progress(), "leaderboard": leaderboard(),
                                   "audit_log": read_json(AUDIT_JSON, []), "sources": list_sources(),
                                   "tier_counts": dict(tiers), "total_remaining_indexed": remaining,
                                   "repo_url": REPO_URL, "lookalikes": lookalike_summary(),
                                   "binary_problems": BINARY_PROBLEMS, "scripts": script_check_summary(),
                                   "proto_in_retail": {"same_code": copies["code"], "same_method": copies["method"]},
                                   "pending": len(pending_keys()) + len(pending_descriptions()), "porting": porting_left(),
                                   "maintainers": sorted(MAINTAINERS)})
        if u.path == "/api/source":
            name = q1("name")
            p = (RECON_DIR / name).resolve()
            if not name or RECON_DIR.resolve() not in p.parents or not p.is_file():
                return self._json({"ok": False, "error": "No such file."}, 404)
            return self._json({"ok": True, "name": name, "content": p.read_text(encoding="utf-8", errors="ignore")})
        if u.path == "/api/scripts":
            return self._json(script_list_payload())
        if u.path == "/api/script":
            res = script_detail(q1("path"))
            return self._json(res, 200 if res["ok"] else 404)
        if u.path == "/api/queue":
            try:
                page = max(1, int(q1("page", "1")))
                limit = max(10, min(200, int(q1("limit", "80"))))
            except ValueError:
                return self._json({"ok": False, "error": "page/limit must be numbers"}, 400)
            lane, tier, sort_by, q = q1("lane", "ALL"), q1("tier", "ALL"), q1("sort", "DEFAULT"), q1("q").strip().lower()
            with STATE_LOCK:
                items = []
                if lane == "GOOD_FIRST":
                    picks = {p["id"]: p["why"] for p in GOOD.rank(ALL_TASKS)}
                    for t in ALL_TASKS:
                        if t["id"] in picks and (tier == "ALL" or t.get("tier") == tier) and (
                                not q or q in t["symbol"].lower() or q in t["va"].lower()):
                            items.append(dict(t, good_first=picks[t["id"]]))
                    order = list(picks)
                    items.sort(key=lambda x: order.index(x["id"]))
                    n = now_ts()
                    start = (page - 1) * limit
                    return self._json({"total": len(items), "page": page, "limit": limit,
                                       "items": [dict(queue_item(t, n), good_first=t["good_first"]) for t in items[start:start + limit]]})
                for t in ALL_TASKS:
                    st = t["status"]
                    if lane in ("UNCLAIMED", "CLAIMED", "VERIFIED") and st != lane:
                        continue
                    if lane == "PARTIAL" and not (st == "PARTIAL" or (t.get("best_matched_bytes", 0) > 0 and st != "VERIFIED")):
                        continue
                    if lane not in ("ALL", "UNCLAIMED", "CLAIMED", "PARTIAL", "VERIFIED", "PROTO_IN_RETAIL") and lane not in t["lane"]:
                        continue
                    if lane != "VERIFIED" and st == "VERIFIED" and sort_by != "VERIFIED_FIRST":
                        continue
                    if tier != "ALL" and t.get("tier") != tier:
                        continue
                    if q and q not in t["symbol"].lower() and q not in t["va"].lower():
                        continue
                    if lane == "PROTO_IN_RETAIL":
                        if not t.get("in_retail"):
                            continue
                    elif not q and lane != "VERIFIED" and not in_default_queue(t) and not (
                            PO.is_ps2(t["bin"]) and lane != "ALL"):
                        continue
                    items.append(t)
                if sort_by == "DEFAULT":
                    # One function of each look-alike group first, biggest group first: matching it
                    # also matches the rest of its group.
                    items.sort(key=lambda x: -x.get("lookalikes", 0) if x.get("lookalike_rep") else 0)
                elif sort_by == "SIZE_ASC":
                    items.sort(key=lambda x: x["size"])
                elif sort_by == "SIZE_DESC":
                    items.sort(key=lambda x: -x["size"])
                elif sort_by == "PARTIAL_FIRST":
                    items.sort(key=lambda x: (-x.get("best_pct", 0.0), x["size"]))
                elif sort_by == "VERIFIED_FIRST":
                    items.sort(key=lambda x: x["status"] != "VERIFIED")
                n = now_ts()
                start = (page - 1) * limit
                return self._json({"total": len(items), "page": page, "limit": limit,
                                   "items": [queue_item(t, n) for t in items[start:start + limit]]})
        if u.path == "/api/decompme":
            with STATE_LOCK:
                t = TASK_BY_ID.get(q1("id"))
                if t and q1("fresh") == "1":
                    t["decompme_slug"] = ""
            if not t:
                return self._json({"ok": False, "error": "Function not found."}, 404)
            try:
                return self._json(decompme_prepare(t))
            except (ValueError, RuntimeError) as e:
                return self._json({"ok": False, "error": str(e)}, 400)
        if u.path == "/api/import-status":
            return self._json(dict(IMPORT_STATUS, failed=list(IMPORT_STATUS.get("failed", []))[:200]))
        if u.path == "/api/lookalikes":
            with STATE_LOCK:
                t = TASK_BY_ID.get(q1("id"))
                if not t:
                    return self._json({"ok": False, "error": "Function not found."}, 404)
                st = dict(PORT_STATUS.get(t["id"], {"running": False, "total": 0, "tried": 0, "matched": 0,
                                                     "matched_ids": []}))
                others = LA.members(GROUPS, t)
                st.update(ok=True, lookalikes=len(others),
                          done=sum(1 for m in others if m["status"] == "VERIFIED"),
                          progress=progress(), leaderboard=leaderboard())
            return self._json(st)
        if u.path == "/api/game-files":
            return self._json(dict(GAME_FILES.overview(), ok=True))
        if u.path == "/api/game-files/areas":
            out = GA.out_dir(GAME_FILES.bin_dir)
            found = BX.areas(out, GAME_FILES.index(), q1("version"))
            return self._json({"ok": True, "areas": [dict(a, files=len(a["files"])) for a in found],
                               "city_by_version": BX.city_counts(out, GAME_FILES.index()),
                               "city": dict(BLENDER.status),
                               "city_files": len(list(BLENDER.folder(q1("version")).glob("*.glb")))
                               if q1("version") in GA.LABELS else 0,
                               "city_current": q1("version") in GA.LABELS and BX.city_current(BLENDER.folder(q1("version"))),
                               "city_made": BX.city_made(BLENDER.folder(q1("version"))) if q1("version") in GA.LABELS else None})
        if u.path == "/api/game-files/cutscenes":
            found = BX.cutscenes(GA.out_dir(GAME_FILES.bin_dir), GAME_FILES.index(), q1("version")) \
                if q1("version") in GA.LABELS else []
            return self._json({"ok": True, "cutscenes": found})
        if u.path == "/api/game-files/blender":
            return self._json(dict(BLENDER.status, ok=True))
        if u.path == "/api/game-files/textures":
            return self._json(dict(TEXTURE_JOB.status, ok=True, made=(TEXTURE_JOB.folder() / "INDEX.txt").is_file()))
        if u.path == "/api/game-files/speed":
            ffmpeg = MOVIES.find_ffmpeg(GAME_FILES.bin_dir)
            card = MOVIES.graphics_card(ffmpeg)
            st = speed_settings()
            return self._json({"ok": True, "use_cores": st["cores"], "use_gpu": st["gpu"], "xbox_look": st["xbox_look"],
                               "fps": st["fps"], "city_hour": st["city_hour"], "city_weather": st["city_weather"],
                               "cores": os.cpu_count() or 1,
                               "workers": BX.workers_wanted(True), "ffmpeg": ffmpeg is not None,
                               "gpu": card[1] if card else ""})
        if u.path == "/api/game-files/list":
            try:
                offset, limit = max(0, int(q1("offset", "0"))), min(500, max(1, int(q1("limit", "200"))))
            except ValueError:
                return self._json({"ok": False, "error": "offset/limit must be numbers"}, 400)
            res = GA.list_files(GAME_FILES.index(), q1("version"), q1("status"), q1("kind"), q1("q"), offset, limit)
            return self._json(dict(res, ok=True))
        if u.path == "/api/dme-bridge/next":
            if not self._bridge_origin():
                return self._json({"ok": False, "error": "Only decomp.me's own page may ask for jobs."}, 403)
            return self._json({"ok": True, "job": BRIDGE.next()})
        if u.path == "/api/dme-bridge/status":
            return self._json({"ok": True, "connected": BRIDGE.connected(), "origin": DME_BRIDGE_ORIGIN})
        if u.path == "/api/game-files/blender-app":
            exe = BX.find_blender(GAME_FILES.bin_dir)
            return self._json({"ok": True, "found": exe is not None, "path": str(exe) if exe else ""})
        if u.path in ("/api/game-files/sound", "/api/game-files/pictures", "/api/game-files/picture",
                      "/api/game-files/model", "/api/game-files/inspect", "/api/game-files/subtitles",
                      "/api/game-files/movie", "/api/game-files/movie-status"):
            return self.get_game_file_preview(u.path.rsplit("/", 1)[1], q1)
        if u.path == "/api/task":
            with STATE_LOCK:
                t = TASK_BY_ID.get(q1("id"))
                payload = live_task(t) if t else None
            if not payload:
                return self._json({"ok": False, "error": "Function not found."}, 404)
            return self._json({"ok": True, "task": payload})
        self._json({"ok": False, "error": "Not found."}, 404)

    # --------------------------------------------------------------- POST
    def do_POST(self):
        if not self._allowed():
            return
        expire_leases()
        body = self._body()
        if body is None:
            return
        path = urllib.parse.urlparse(self.path).path
        route = {
            "/api/login": self.post_login, "/api/claim": self.post_claim, "/api/cancel": self.post_cancel,
            "/api/verify": self.post_verify, "/api/fast-synthesize": self.post_synth, "/api/ai-proxy": self.post_ai,
            "/api/git-sync": self.post_git, "/api/upload-script": self.post_upload,
            "/api/submit": self.post_submit, "/api/import-submission": self.post_import,
            "/api/decompme": self.post_decompme,
            "/api/game-files/start": self.post_game_files_start, "/api/game-files/stop": self.post_game_files_stop,
            "/api/game-files/blender": self.post_game_files_blender,
            "/api/game-files/blender-stop": self.post_game_files_blender_stop,
            "/api/game-files/open-in-blender": self.post_game_files_open_in_blender,
            "/api/game-files/blender-path": self.post_game_files_blender_path,
            "/api/game-files/movie": self.post_game_files_movie,
            "/api/game-files/textures": self.post_game_files_textures,
            "/api/game-files/speed": self.post_game_files_speed,
            "/api/game-files/textures-stop": self.post_game_files_textures_stop,
            "/api/game-files/ffmpeg-path": self.post_game_files_ffmpeg_path,
            "/api/game-files/ffmpeg-install": self.post_game_files_ffmpeg_install,
            "/api/game-files/open": self.post_game_files_open,
            "/api/dme-bridge/run": self.post_bridge_run, "/api/dme-bridge/result": self.post_bridge_result,
            "/api/describe": self.post_describe,
        }.get(path)
        if not route:
            return self._json({"ok": False, "error": "Not found."}, 404)
        try:
            route(body)
        except Exception as e:  # keep the server alive and say what happened
            import traceback
            traceback.print_exc()
            self._json({"ok": False, "error": f"Server error: {type(e).__name__}: {e}"}, 500)

    def _auth(self, body) -> Optional[str]:
        ok, msg = authenticate(body.get("user", ""), body.get("pin", ""))
        if not ok:
            self._json({"ok": False, "error": msg}, 403)
            return None
        return body["user"].strip()

    def post_login(self, body):
        ok, msg = authenticate(body.get("user", ""), body.get("pin", ""))
        self._json({"ok": ok, "message": msg} if ok else {"ok": False, "error": msg}, 200 if ok else 403)

    def post_claim(self, body):
        user = self._auth(body)
        if not user:
            return
        with STATE_LOCK:
            t = TASK_BY_ID.get(body.get("id"))
            if not t:
                return self._json({"ok": False, "error": "Function not found."}, 404)
            if t["status"] == "VERIFIED":
                return self._json({"ok": False, "error": "Already verified.", "task": live_task(t)})
            if t["status"] == "CLAIMED" and t.get("claimed_by") != user and now_ts() < t.get("claim_expires_at", 0):
                return self._json({"ok": False, "error": f"Claimed by {t['claimed_by']}.", "task": live_task(t)})
            t["status"] = "CLAIMED"
            t["claimed_by"] = user
            t["claim_expires_at"] = now_ts() + int(t.get("lease_minutes", 30)) * 60
            save_overlay(t)
            return self._json({"ok": True, "task": live_task(t)})

    def post_cancel(self, body):
        user = self._auth(body)
        if not user:
            return
        with STATE_LOCK:
            t = TASK_BY_ID.get(body.get("id"))
            if not t:
                return self._json({"ok": False, "error": "Function not found."}, 404)
            if t["status"] != "CLAIMED" or t.get("claimed_by") != user:
                return self._json({"ok": False, "error": "You do not hold the claim on this function."}, 403)
        code = (body.get("cpp_code") or "").strip()
        res = run_verify(t, code) if code else {"ok": False}
        with STATE_LOCK:
            if t.get("claimed_by") != user:            # claim changed while we compiled
                return self._json({"ok": False, "error": "Your claim expired while saving."}, 409)
            if res.get("ok") and res["matched_bytes"] > t.get("best_matched_bytes", 0):
                t.update(best_matched_bytes=res["matched_bytes"], best_pct=res["match_percent"], best_by=user,
                         best_cpp=code, best_diff_details=res["diff_details"])
                with open(PARTIAL_CPP, "a", encoding="utf-8") as f:
                    f.write("// ============================================================================\n"
                            f"// [PARTIAL {res['matched_bytes']}/{res['total_bytes']} B] {t['symbol']} ({t['va']}) | {user} at {stamp()}\n"
                            "// ============================================================================\n"
                            f"{code}\n\n")
            t["claimed_by"] = ""
            t["claim_expires_at"] = 0
            t["status"] = "PARTIAL" if t.get("best_matched_bytes", 0) > 0 else "UNCLAIMED"
            save_overlay(t)
            if t["status"] == "PARTIAL":
                append_audit({"time": stamp(), "user": user, "action": "PARTIAL", "symbol": t["symbol"], "va": t["va"],
                              "bytes": f"{t['best_matched_bytes']}/{t['size']} B"})
            return self._json({"ok": True, "task": live_task(t)})

    def post_verify(self, body):
        user = self._auth(body)
        if not user:
            return
        code = body.get("cpp_code") or ""
        tool = (body.get("tool_used") or "").strip()[:120]
        with STATE_LOCK:
            t = TASK_BY_ID.get(body.get("id"))
            if not t:
                return self._json({"ok": False, "error": "Function not found."}, 404)
            already = t["status"] == "VERIFIED"
            if not already and (t["status"] != "CLAIMED" or t.get("claimed_by") != user):
                return self._json({"ok": False, "error": "Claim the function before compiling."}, 403)
        res = run_verify(t, code, str(body.get("object_b64") or ""), str(body.get("slug") or ""))   # outside the lock
        if not res.get("ok"):
            return self._json(res)
        newly = False
        with STATE_LOCK:
            if not already and (t["status"] != "CLAIMED" or t.get("claimed_by") != user):
                return self._json({"ok": False, "error": "Your claim expired or was released while compiling."}, 409)
            if not already and res["matched_bytes"] > t.get("best_matched_bytes", 0):
                t.update(best_matched_bytes=res["matched_bytes"], best_pct=res["match_percent"], best_by=user,
                         best_cpp=code, best_diff_details=res["diff_details"])
                save_overlay(t)
            if res["verified"] and not already:
                record_verified(t, code, user, tool, res, what=clean_what(body.get("what")))
                t.update(status="VERIFIED", claimed_by="", claim_expires_at=0)
                save_overlay(t)
                append_audit({"time": stamp(), "user": user, "action": "VERIFIED", "symbol": t["symbol"], "va": t["va"],
                              "bytes": f"{t['size']}/{t['size']} B"})
                newly = True
                print(f"[+] VERIFIED by {user}: {t['symbol']} ({t['va']}) -> {len(REGISTRY['entries'])} total")
            revised = bool(already and body.get("keep_revision") and revise_verified(t, code, user, res))
            if revised:
                append_audit({"time": stamp(), "user": user, "action": "REVISED", "symbol": t["symbol"], "va": t["va"]})
            out = dict(res)
            entry = REGISTRY["entries"].get(task_key(t))
            out.update(newly_promoted=newly, revised=revised,
                       saved_to=RO.entry_path(entry) if entry and t["status"] == "VERIFIED" else "",
                       progress=progress(), leaderboard=leaderboard(), task=live_task(t),
                       target_hex=" ".join(f"{b:02X}" for b in (target_bytes(t) or b"")))
        # Same machine code elsewhere: try this code there too (in the background, verified one by one).
        out["lookalikes_queued"] = queue_port(t, code, user, tool) if newly and not res.get("reloc_unverified") else 0
        return self._json(out)

    def post_decompme(self, body):
        """Remember a scratch the page created ({id, slug}), or create one from here ({id, create: true})
        when the browser could not reach decomp.me itself."""
        with STATE_LOCK:
            t = TASK_BY_ID.get(body.get("id"))
        if not t:
            return self._json({"ok": False, "error": "Function not found."}, 404)
        if body.get("create"):
            prep = decompme_prepare(t)
            if not prep.get("ok"):
                return self._json(prep, 400)
            if PO.is_ps2(t["bin"]):
                res = PV.create_scratch(prep["json"])
            else:
                res = DME.create_scratch(base64.b64decode(prep["obj_b64"]), prep["fields"])
            if not res.get("ok"):
                return self._json(res, 502)
            slug = res["slug"]
        else:
            slug = str(body.get("slug", ""))
            res = {"ok": True}
        if not _SLUG_RE.match(slug):
            return self._json({"ok": False, "error": "That does not look like a decomp.me scratch id."}, 400)
        with STATE_LOCK:
            t["decompme_slug"] = slug
            save_overlay(t)
        return self._json(res)

    def post_synth(self, body):
        with STATE_LOCK:
            t = TASK_BY_ID.get(body.get("id"))
            if not t:
                return self._json({"ok": False, "error": "Function not found."}, 404)
            tb = target_bytes(t) or b""
        return self._json({"ok": True, "cpp_code": synthesize_cpp(t["symbol"], t["va"], tb, disassemble(tb),
                                                                 relocs=starter_relocs(t, tb))})

    def post_ai(self, body):
        self._json(ai_call(body))

    def post_git(self, body):
        user = self._auth(body)
        if not user:
            return
        if user not in MAINTAINERS:
            return self._json({"ok": False, "error": "Only maintainers can push to GitHub. To share your matches, open a pull request (docs/CONTRIBUTING.md) or post them in #help on Discord."}, 403)
        with STATE_LOCK:
            refresh_outputs()
            res = git_sync(user)
        self._json(res)

    def post_submit(self, body):
        """Maintainers: commit and push. Everyone else: one file with the matches not on GitHub yet."""
        user = self._auth(body)
        if not user:
            return
        if user in MAINTAINERS:
            with STATE_LOCK:
                refresh_outputs()
                res = git_sync(user)
            return self._json(dict(res, mode="pushed", pending=len(pending_keys()) + len(pending_descriptions())))
        bundle = make_submission(user)
        if not bundle["count"]:
            return self._json({"ok": True, "mode": "nothing", "pending": 0,
                               "message": "Everything you matched is already on GitHub."})
        self._json({"ok": True, "mode": "file", "count": bundle["count"], "filename": submission_filename(user),
                    "bundle": bundle, "pending": bundle["count"]})

    # Game files (sounds, textures, models, videos) from the person's own copies. No sign-in: it is their
    # own computer and their own game; nothing is sent anywhere.
    def post_describe(self, body):
        """What a rebuilt function does, in one plain-English line (anyone signed in; credited to them)."""
        user = self._auth(body)
        if not user:
            return
        with STATE_LOCK:
            t = TASK_BY_ID.get(body.get("id"))
            if not t:
                return self._json({"ok": False, "error": "Function not found."}, 404)
            err = describe_verified(t, body.get("what"), user)
            if err:
                return self._json({"ok": False, "error": err}, 409)
            append_audit({"time": stamp(), "user": user, "action": "DESCRIBED", "symbol": t["symbol"], "va": t["va"]})
            task = live_task(t)
        self._json({"ok": True, "task": task, "pending": len(pending_keys()) + len(pending_descriptions())})

    def post_bridge_run(self, body):
        """From the portal page: have the decomp.me tab make a scratch and/or compile, and wait for it."""
        if self._bridge_origin():
            return self._json({"ok": False, "error": "Not for decomp.me."}, 403)
        job = body.get("job")
        if not isinstance(job, dict) or not (job.get("create") or job.get("compile")):
            return self._json({"ok": False, "error": "Nothing to do."}, 400)
        if not BRIDGE.connected():
            return self._json({"ok": False, "not_connected": True, "error": "Your decomp.me tab isn't connected."})
        clean = {k: job[k] for k in ("slug", "create", "compile") if k in job}
        self._json(BRIDGE.run(clean))

    def post_bridge_result(self, body):
        if not self._bridge_origin():
            return self._json({"ok": False, "error": "Only decomp.me's own page may send results."}, 403)
        res = {k: body.get(k) for k in ("id", "ok", "slug", "claim_token", "success", "compiler_output", "right_object", "error")
               if k in body}
        res["ok"] = bool(res.get("ok"))
        for k in ("slug", "claim_token", "compiler_output", "right_object", "error"):
            if k in res and not isinstance(res[k], str):
                res[k] = ""
        if res.get("slug") and not _SLUG_RE.match(res["slug"]):
            res.update(ok=False, slug="", error="decomp.me sent back an odd scratch name")
        self._json({"ok": BRIDGE.result(res)})

    def get_game_file_preview(self, what: str, q1) -> None:
        """Play a sound, show a texture or hand over a model as a .glb for Blender, from the person's own copied
        game files. Only for a browser on this computer, and only for pages of the portal itself: the files are
        theirs, not something to serve on."""
        peer = (self.client_address[0] if self.client_address else "").split("%")[0]
        if peer not in ("127.0.0.1", "::1", "::ffff:127.0.0.1"):
            return self._json({"ok": False, "error": "Previews only work on the computer the portal runs on."}, 403)
        if (self.headers.get("Sec-Fetch-Site") or "").strip().lower() == "cross-site":
            return self._json({"ok": False, "error": "Requests from other websites are not accepted."}, 403)
        if what == "model" and q1("area"):
            return self._send_area(q1("version"), q1("area"))
        if what == "model" and q1("scene"):
            return self._send_cutscene(q1("version"), q1("scene"))
        if what == "subtitles":                       # what is said in a sound, from its subtitle file
            sub = GA.companion(GAME_FILES.index(), q1("version"), q1("path"))
            p = GAME_FILES.file_path(q1("version"), sub) if sub else None
            try:
                lines = MEDIA.subtitles(p.read_bytes()) if p is not None else []
            except OSError:
                lines = []
            return self._json({"ok": True, "lines": [{"language": a, "text": b} for a, b in lines]})
        path = GAME_FILES.file_path(q1("version"), q1("path"))
        if path is not None and what == "sound":
            return self._send_sound(path, q1("path"))
        if path is not None and what == "movie-status":
            return self._json(dict(MOVIES_JOB.status(path), ok=True))
        if path is not None and what == "movie":
            made = MOVIES_JOB.ready(path)
            if made is None:
                return self._json({"ok": False, "error": "That movie isn't made into a video yet."}, 404)
            return self._send_file_ranged(made, "video/mp4")
        if path is None:
            if GAME_FILES.running:
                return self._json({"ok": False, "error": "Your game files are being copied: that one isn't "
                                   "ready yet. Try again when the copy is done."}, 409)
            return self._json({"ok": False, "error": "That file isn't in your copied game files (copy them first)."}, 404)
        try:
            data = path.read_bytes()
            if what == "inspect":
                info = BX.inspect(data)
                if info["blender"]:            # only offer Blender what this copy can really show
                    why = BX.cant_show(GA.out_dir(GAME_FILES.bin_dir), GAME_FILES.index(), q1("version"), q1("path"), data)
                    if why:
                        info.update(blender=False, blender_why=why)
                if info["lines"]:
                    info["sound"] = GA.companion(GAME_FILES.index(), q1("version"), q1("path")) or ""
                return self._json(dict(info, ok=True))
            if what == "model":
                return self._send_model(q1("version"), q1("path"), path, data)
            if what == "pictures":
                return self._json({"ok": True, "pictures": [
                    {"i": i, "name": t.name, "width": t.width, "height": t.height, "kind": t.kind}
                    for i, t in enumerate(MEDIA.textures(data))]})
            try:
                i = int(q1("i", "0"))
            except ValueError:
                return self._json({"ok": False, "error": "i must be a number"}, 400)
            return self._send(200, MEDIA.texture_png(data, i), "image/png")
        except MEDIA.MediaError as e:
            return self._json({"ok": False, "error": str(e)}, 415)
        except OSError as e:
            return self._json({"ok": False, "error": f"Couldn't read the file: {e}"}, 500)

    def _send_sound(self, path: Path, game_path: str) -> None:
        """A sound the browser can play, from a part of it on when the player asks (so you can skip ahead).
        Decoded once and kept for a while: skipping asks for the same sound again from another point."""
        try:
            st = path.stat()
            key = (str(path), st.st_mtime_ns, st.st_size)
            hit = SOUNDS.get(key)
            if hit is None:
                hit = MEDIA.playable(path.read_bytes())
                SOUNDS.put(key, hit, len(hit[0]))
        except MEDIA.MediaError as e:
            return self._json({"ok": False, "error": f"Can't play it: {e}."}, 415)
        except OSError as e:
            return self._json({"ok": False, "error": f"Couldn't read the file: {e}"}, 500)
        body, mime, ext = hit
        name = re.sub(r'[^A-Za-z0-9._-]', "_", Path(game_path.replace("\\", "/")).stem) + ext
        self._send_ranged(body, mime, {"Content-Disposition": f'inline; filename="{name}"'})

    def _send_file_ranged(self, path: Path, ctype: str) -> None:
        """A file from disk, or the part a Range header asks for, read as it is sent (movies are big)."""
        try:
            total = path.stat().st_size
        except OSError:
            return self._json({"ok": False, "error": "That video went missing."}, 404)
        start, end, code = 0, total - 1, 200
        m = re.fullmatch(r"\s*bytes=(\d*)-(\d*)\s*", self.headers.get("Range") or "")
        if m and (m.group(1) or m.group(2)):
            if m.group(1):
                start = int(m.group(1))
                end = min(int(m.group(2)), total - 1) if m.group(2) else total - 1
            else:
                start = max(0, total - int(m.group(2)))
            if start >= total or end < start:
                return self._send(416, b"", ctype, {"Content-Range": f"bytes */{total}", "Accept-Ranges": "bytes"})
            code = 206
        self.send_response(code)
        self.send_header("Content-Type", ctype)
        self.send_header("Accept-Ranges", "bytes")
        self.send_header("Cache-Control", "no-store")
        if code == 206:
            self.send_header("Content-Range", f"bytes {start}-{end}/{total}")
        self.send_header("Content-Length", str(end - start + 1))
        try:
            self.end_headers()
            with open(path, "rb") as f:
                f.seek(start)
                left = end - start + 1
                while left > 0:
                    piece = f.read(min(1 << 20, left))
                    if not piece:
                        break
                    self.wfile.write(piece)
                    left -= len(piece)
        except (ConnectionError, OSError):
            self.close_connection = True

    def _send_ranged(self, body: bytes, ctype: str, extra: Optional[dict] = None) -> None:
        """The whole of body, or the part a Range header asks for (what media players need to seek)."""
        extra = dict(extra or {}, **{"Accept-Ranges": "bytes"})
        total = len(body)
        m = re.fullmatch(r"\s*bytes=(\d*)-(\d*)\s*", self.headers.get("Range") or "")
        if not m or not (m.group(1) or m.group(2)):
            return self._send(200, body, ctype, extra)
        if m.group(1):
            start = int(m.group(1))
            end = min(int(m.group(2)), total - 1) if m.group(2) else total - 1
        else:
            start, end = max(0, total - int(m.group(2))), total - 1
        if start >= total or end < start:
            return self._send(416, b"", ctype, dict(extra, **{"Content-Range": f"bytes */{total}"}))
        self._send(206, body[start:end + 1], ctype, dict(extra, **{"Content-Range": f"bytes {start}-{end}/{total}"}))

    def _send_model(self, version: str, game_path: str, path: Path, data: bytes) -> None:
        """A copied .p3d file as a glTF scene (.glb) for Blender. A map area also gets its region's and the city's
        shared files from the same folder; a character gets the game's animations."""
        try:
            glb, _report = BX.model_glb(GA.out_dir(GAME_FILES.bin_dir), GAME_FILES.index(), version, game_path, data)
        except P3G.p3d.P3dError as e:
            return self._json({"ok": False, "error": str(e)}, 415)
        except P3G.ExportError as e:
            return self._json({"ok": False, "error": f"Nothing to show in Blender: {e}."}, 415)
        name = re.sub(r'[^A-Za-z0-9._-]', "_", Path(game_path.replace("\\", "/")).stem) + ".glb"
        self._send(200, glb, "model/gltf-binary", {"Content-Disposition": f'attachment; filename="{name}"'})

    def _send_cutscene(self, version: str, scene: str) -> None:
        """A cutscene, with the ones the game plays straight after it, as one .glb."""
        try:
            glb, _report = BX.cutscene_glb(GA.out_dir(GAME_FILES.bin_dir), GAME_FILES.index(), version, scene)
        except P3G.ExportError as e:
            return self._json({"ok": False, "error": f"{str(e)[:1].upper()}{str(e)[1:]}."}, 404)
        except (OSError, P3G.p3d.P3dError) as e:
            return self._json({"ok": False, "error": f"Couldn't read the cutscene's files: {e}"}, 500)
        name = re.sub(r'[^A-Za-z0-9._-]', "_", scene) + ".glb"
        self._send(200, glb, "model/gltf-binary", {"Content-Disposition": f'attachment; filename="{name}"'})

    def _send_area(self, version: str, key: str) -> None:
        """A whole map area (its shell and detail files) as one .glb."""
        try:
            glb, _report = BX.area_glb(GA.out_dir(GAME_FILES.bin_dir), GAME_FILES.index(), version, key)
        except P3G.ExportError as e:
            return self._json({"ok": False, "error": f"{str(e)[:1].upper()}{str(e)[1:]}."}, 404)
        except (OSError, P3G.p3d.P3dError) as e:
            return self._json({"ok": False, "error": f"Couldn't read the area's files: {e}"}, 500)
        name = re.sub(r'[^A-Za-z0-9._-]', "_", key.rsplit("/", 1)[-1]) + ".glb"
        self._send(200, glb, "model/gltf-binary", {"Content-Disposition": f'attachment; filename="{name}"'})

    def post_game_files_blender(self, body):
        """Every map area of the city as .glb files in extracted/blender/<version>/, and the sky round them;
        optionally at an hour ("hour": 0 to 24, with its fog) and in a weather ("weather": clear or rain). The sea
        comes too (ocean.glb), unless "ocean" is false."""
        try:
            hour = float(body["hour"]) if body.get("hour") not in (None, "") else None
        except (TypeError, ValueError):
            return self._json({"ok": False, "error": "The hour is from 0 to 24."}, 400)
        sea = {"ocean": False} if body.get("ocean") is False else {}
        err = BLENDER.start(str(body.get("version", "")), GAME_FILES.index(), hour, str(body.get("weather") or "clear"),
                            **sea)
        if err:
            return self._json({"ok": False, "error": err}, 409 if "Already" in err or "being" in err else 400)
        self._json(dict(BLENDER.status, ok=True))

    def _local_only(self) -> bool:
        peer = (self.client_address[0] if self.client_address else "").split("%")[0]
        if HOST not in ("127.0.0.1", "localhost", "::1") or peer not in ("127.0.0.1", "::1", "::ffff:127.0.0.1"):
            self._json({"ok": False, "error": "That only works on the computer the portal runs on."}, 403)
            return False
        return True

    def post_game_files_open_in_blender(self, body):
        """Make the scene (a copied file, a map area, or the city exported before) and start the person's own
        Blender with it imported; Blender saves it as a .blend beside the .glb for next time."""
        if not self._local_only():
            return
        version = str(body.get("version", ""))
        if version not in GA.LABELS:
            return self._json({"ok": False, "error": "Pick a version."}, 400)
        exe = BX.find_blender(GAME_FILES.bin_dir)
        if exe is None:
            return self._json({"ok": False, "need_blender": True, "error": "Couldn't find Blender on this computer. "
                               "Install it from blender.org, or tell the portal where blender.exe is."}, 404)
        folder = BLENDER.folder(version)
        out = GA.out_dir(GAME_FILES.bin_dir)
        try:
            if body.get("city"):
                files = sorted(folder.glob("*.glb"))
                if not files:
                    return self._json({"ok": False, "error": "Export the city first: then it opens as one scene."}, 404)
                glbs, save = files, folder / f"{GA.LABELS[version]} city.blend"
            elif body.get("scene"):
                scene = str(body["scene"])
                glb, _r = BX.cutscene_glb(out, GAME_FILES.index(), version, scene)
                name = re.sub(r'[^A-Za-z0-9._-]', "_", scene)
                glbs, save = [folder / BX.OPENED / f"{name}.glb"], folder / BX.OPENED / f"{name}.blend"
                glbs[0].parent.mkdir(parents=True, exist_ok=True)
                glbs[0].write_bytes(glb)
            elif body.get("area"):
                key = str(body["area"])
                glb, _r = BX.area_glb(out, GAME_FILES.index(), version, key)
                name = re.sub(r'[^A-Za-z0-9._-]', "_", key.rsplit("/", 1)[-1])
                glbs, save = [folder / BX.OPENED / f"{name}.glb"], folder / BX.OPENED / f"{name}.blend"
                glbs[0].parent.mkdir(parents=True, exist_ok=True)
                glbs[0].write_bytes(glb)
            else:
                game_path = str(body.get("path", ""))
                path = GAME_FILES.file_path(version, game_path)
                if path is None:
                    return self._json({"ok": False, "error": "That file isn't in your copied game files."}, 404)
                glb, _r = BX.model_glb(out, GAME_FILES.index(), version, game_path, path.read_bytes())
                name = re.sub(r'[^A-Za-z0-9._-]', "_", Path(game_path.replace("\\", "/")).stem)
                glbs, save = [folder / BX.OPENED / f"{name}.glb"], folder / BX.OPENED / f"{name}.blend"
                glbs[0].parent.mkdir(parents=True, exist_ok=True)
                glbs[0].write_bytes(glb)
            reopened = bool(body.get("city")) and BX.saved_scene(save, glbs)
            if reopened:                       # the city was brought in and saved before: open that, at once
                BX.open_blend(exe, save)
            else:
                BX.open_in_blender(exe, glbs, save, GA.made_dir(GAME_FILES.bin_dir, BX.OUT_NAME) / "_scripts",
                                   speed_settings()["fps"])
        except P3G.ExportError as e:
            return self._json({"ok": False, "error": f"Nothing to show in Blender: {e}."}, 415)
        except (OSError, P3G.p3d.P3dError) as e:
            return self._json({"ok": False, "error": f"Couldn't open it in Blender: {e}"}, 500)
        self._json({"ok": True, "blender": str(exe), "saved": GA._show_path(save), "files": len(glbs),
                    "reopened": reopened})

    def post_game_files_movie(self, body):
        """Start making a movie into a video the browser plays (once; it is kept)."""
        if not self._local_only():
            return
        path = GAME_FILES.file_path(str(body.get("version", "")), str(body.get("path", "")))
        if path is None:
            return self._json({"ok": False, "error": "That file isn't in your copied game files."}, 404)
        st = MOVIES_JOB.start(path)
        self._json(dict(st, ok=st.get("state") != "error"), 200 if st.get("state") != "error" else 424)

    def post_game_files_textures(self, body):
        """Every texture as a .png, into extracted/textures/ (PC first; see portal/tools/textures.py)."""
        sources, _notes = GAME_FILES.sources()
        err = TEXTURE_JOB.start(GAME_FILES.index(), sources)
        if err:
            return self._json({"ok": False, "error": err}, 409 if "Already" in err or "being" in err else 400)
        self._json(dict(TEXTURE_JOB.status, ok=True))

    def post_game_files_speed(self, body):
        st = speed_settings()
        for k, field in (("cores", "use_cores"), ("gpu", "use_gpu"), ("xbox_look", "xbox_look")):
            if isinstance(body.get(field), bool):
                st[k] = body[field]
        if body.get("fps") in BX.FRAME_RATES:
            st["fps"] = body["fps"]
        if "city_hour" in body and (body["city_hour"] in (None, "") or _an_hour(body["city_hour"])):
            st["city_hour"] = body["city_hour"] if _an_hour(body["city_hour"]) else None     # None: as stored
        if body.get("city_weather") in P3G.WEATHERS:
            st["city_weather"] = body["city_weather"]
        try:
            SPEED_FILE.parent.mkdir(parents=True, exist_ok=True)
            SPEED_FILE.write_text(json.dumps(st), encoding="utf-8")
        except OSError as e:
            return self._json({"ok": False, "error": f"Couldn't keep the setting: {e}"}, 500)
        apply_texture_look(st["xbox_look"])
        self._json({"ok": True, "use_cores": st["cores"], "use_gpu": st["gpu"], "xbox_look": st["xbox_look"],
                    "fps": st["fps"], "city_hour": st["city_hour"], "city_weather": st["city_weather"]})

    def post_game_files_textures_stop(self, body):
        TEXTURE_JOB.stop()
        self._json({"ok": True})

    def post_game_files_ffmpeg_path(self, body):
        if not self._local_only():
            return
        err = MOVIES.remember_ffmpeg(GAME_FILES.bin_dir, str(body.get("path", "")))
        if err:
            return self._json({"ok": False, "error": err}, 400)
        self._json({"ok": True})

    def post_game_files_ffmpeg_install(self, body):
        if not self._local_only():
            return
        if MOVIES.find_ffmpeg(GAME_FILES.bin_dir):
            return self._json({"ok": True, "message": "FFmpeg is already installed. Press Try again."})
        ok, message = MOVIES.install_ffmpeg()
        self._json({"ok": ok, "message": message, "error": "" if ok else message}, 200 if ok else 400)

    def post_game_files_blender_path(self, body):
        if not self._local_only():
            return
        err = BX.remember_blender(GAME_FILES.bin_dir, str(body.get("path", "")))
        if err:
            return self._json({"ok": False, "error": err}, 400)
        self._json({"ok": True, "path": str(BX.find_blender(GAME_FILES.bin_dir) or "")})

    def post_game_files_blender_stop(self, body):
        BLENDER.stop()
        self._json({"ok": True})

    def post_game_files_start(self, body):
        versions = body.get("versions")
        if not isinstance(versions, list) or not all(isinstance(v, str) for v in versions):
            return self._json({"ok": False, "error": "Pick at least one version."}, 400)
        err = GAME_FILES.start(versions, str(body.get("mode", "")), str(body.get("folders") or "game"),
                               check=bool(body.get("check")))
        if err:
            return self._json({"ok": False, "error": err, "up_to_date": err.startswith("Already copied")},
                              409 if "Already" in err or "being" in err else 400)
        self._json({"ok": True, "status": dict(GAME_FILES.status)})

    def post_game_files_stop(self, body):
        GAME_FILES.stop()
        self._json({"ok": True})

    def post_game_files_open(self, body):
        if HOST not in ("127.0.0.1", "localhost", "::1"):
            return self._json({"ok": False, "error": "Folders can only be opened when the portal runs on this computer."}, 403)
        which = str(body.get("folder", ""))
        if which.startswith("blender:"):
            folder = BLENDER.folder(which[8:])
            folder = folder if folder.is_dir() else None
        elif which == "textures":
            folder = TEXTURE_JOB.folder() if TEXTURE_JOB.folder().is_dir() else None
        else:
            folder = GAME_FILES.folder_for(which)
        if folder is None:
            return self._json({"ok": False, "error": "That folder isn't there yet."}, 404)
        try:
            GA.open_folder(folder)
        except OSError as e:
            return self._json({"ok": False, "error": f"Couldn't open the folder: {e}"}, 500)
        self._json({"ok": True, "folder": GA._show_path(folder)})

    def post_import(self, body):
        user = self._auth(body)
        if not user:
            return
        if user not in MAINTAINERS:
            return self._json({"ok": False, "error": "Only maintainers can import submissions."}, 403)
        if not MV.find_msvc71_bin():
            return self._json({"ok": False, "error": NO_COMPILER_HELP})
        if IMPORT_STATUS.get("running"):
            return self._json({"ok": False, "error": "A submission is already being imported."}, 409)
        bundle = body.get("bundle")
        n = len(bundle.get("entries") or {}) if isinstance(bundle, dict) and isinstance(bundle.get("entries"), dict) else 0
        IMPORT_STATUS.clear()
        IMPORT_STATUS.update(running=True, total=n, done=0, added=0, already=0, failed=[], error="")
        threading.Thread(target=import_submission, args=(bundle, user), name="import", daemon=True).start()
        self._json({"ok": True, "started": True, "total": n})

    def post_upload(self, body):
        from cso_dso_dtr_decompiler import verify_and_decompile_cso_dso, verify_and_decompile_dtr
        name = os.path.basename((body.get("filename") or "").strip())
        ext = Path(name).suffix.lower()
        if not name or ext not in (".cso", ".dso", ".dtr"):
            return self._json({"ok": False, "error": "Only .cso, .dso and .dtr files are supported."})
        try:
            raw = bytes.fromhex(body.get("hex_data") or "")
        except ValueError:
            return self._json({"ok": False, "error": "File data was not valid hex."}, 400)
        res = verify_and_decompile_dtr(raw, name) if ext == ".dtr" else verify_and_decompile_cso_dso(raw, name)
        if not res.get("ok"):
            return self._json({"ok": False, "error": f"Could not parse {name}: {res.get('error')}"})
        (SCRIPTS_DIR / "uploads").mkdir(parents=True, exist_ok=True)
        (SCRIPTS_DIR / "uploads" / name).write_bytes(raw)
        self._json(script_list_payload("uploads/" + name))


# =========================================================================== #
# Startup
# =========================================================================== #

def main() -> None:
    try:
        import capstone  # noqa: F401
    except ImportError:
        sys.exit("Capstone is required (function sizes, disassembly, address checks): pip install -r portal/requirements.txt")
    _migrate_legacy_auth()
    load_registry()
    GA.move_made(BASE_DIR / "binaries")
    if not GF.startup(BASE_DIR / "binaries"):
        GF.pc_help(BASE_DIR / "binaries")
    try:
        ES.auto_extract(BASE_DIR / "binaries")          # the game's scripts, for the Game Scripts tab
    except Exception as e:  # noqa: BLE001 - the scripts are a bonus; never stop the portal over them
        print(f"[!] Could not copy the game's scripts out: {e}")
    load_tasks()
    if not MV.find_msvc71_bin():
        print("[!] The 2003 compiler is not installed yet. You can still browse functions and use decomp.me;")
        print("    to verify here, put VCToolkitSetup.exe in the project folder and run, from that folder:")
        print("    python portal/scripts/setup_msvc71.py VCToolkitSetup.exe")
    p = progress()
    url = f"http://{'localhost' if HOST in ('127.0.0.1', '0.0.0.0') else HOST}:{PORT}"
    print("=" * 78)
    print(" SCARFACE: THE WORLD IS YOURS — MATCHING DECOMP PORTAL")
    print("=" * 78)
    print(f"  URL        : {url}")
    print(f"  Compiler   : {p['compiler']}")
    print(f"  Verified   : {p['matched_functions']:,} functions (PC {p['by_binary']['pc']:,}, Xbox {p['by_binary']['xbox']:,})")
    print(f"  Work queue : {sum(1 for t in ALL_TASKS if t['status'] != 'VERIFIED' and in_default_queue(t)):,} functions")
    if p.get("no_game"):
        print("  NO GAME YET: put the US Xbox disc image (.iso, .zip or .7z) in the binaries folder and start the")
        print("               portal again. Until then there is nothing to work on (docs/GAME_VERSIONS.md).")
    print(f"  Look-alikes: {len(GROUPS):,} groups; a match in one is tried on the rest of its group")
    if any(t["bin"] == "proto" for t in ALL_TASKS):
        pp = p["prototype"]
        print(f"  Prototype  : {pp['matched']:,} / {pp['total']:,} (April 2006 Xbox build, unreleased code; counted on its own)")
        same = sum(1 for t in ALL_TASKS if t.get("in_retail") == "code")
        older = sum(1 for t in ALL_TASKS if t.get("in_retail") == "method")
        if same or older:
            print(f"               {same:,} are the same code as retail (matched along with it) and {older:,} are older")
            print("               versions of retail functions; both are left out of the work queue")
    print(f"  Maintainers: {', '.join(sorted(MAINTAINERS))}")
    print("=" * 78)
    for b, problem in BINARY_PROBLEMS.items():
        print(f"[!] NOT USED: {problem}")
    if not (BASE_DIR / ".git").exists():
        print("[!] This folder was downloaded as a ZIP, not with git clone. Don't update it with a new ZIP: that")
        print("    would replace your verified functions. Connect it to Git once (docs/CONTRIBUTING.md,")
        print('    "Downloaded the ZIP?"), then update with: git pull')
    # Check the game's scripts in the background: the portal is usable meanwhile.
    threading.Thread(target=check_scripts, name="script-check", daemon=True).start()
    n = catch_up_lookalikes()
    if n:
        print(f"[*] Trying earlier matches on {n:,} look-alike(s) in the background (for example the prototype's")
        print("    copies of retail code); they are recorded as they match.")
    if os.environ.get("SCARFACE_NO_BROWSER") != "1":
        if os.name == "nt":
            subprocess.Popen(["cmd", "/c", "start", url])
        else:
            import webbrowser
            threading.Timer(1.0, lambda: webbrowser.open(url)).start()
    ThreadingHTTPServer((HOST, PORT), Handler).serve_forever()


if __name__ == "__main__":
    main()
