#!/usr/bin/env python3
"""
Scarface: The World Is Yours — matching-decompilation portal server.

    python decomp_portal_server.py            (Windows; opens http://127.0.0.1:8085)
    python3 decomp_portal_server.py           (Linux/macOS; runs cl.exe under Wine)

Environment variables:
    SCARFACE_HOST         interface to listen on (default 127.0.0.1 — local only)
    SCARFACE_PORT         port (default 8085)
    SCARFACE_MAINTAINERS  comma-separated handles allowed to use "Sync Verified to GitHub"
    SCARFACE_NO_BROWSER   set to 1 to not open a browser on start
    SCARFACE_REPO_URL     GitHub page linked from the site (default: this checkout's "origin" remote)

Verification rules live in tools/msvc_verify.py and are shared with verify.py and
scripts/reverify_all.py. Progress and the leaderboard are computed from
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

BASE_DIR = Path(__file__).resolve().parent
sys.path.insert(0, str(BASE_DIR / "tools"))

import msvc_verify as MV  # noqa: E402
from disasm_synth import disassemble, synthesize_cpp  # noqa: E402
import decompme as DME  # noqa: E402
import lookalikes as LA  # noqa: E402
import game_files as GF  # noqa: E402
from registry_outputs import write_outputs  # noqa: E402
from sf_binaries import BinaryImage  # noqa: E402

BINARIES = {
    "pc": BASE_DIR / "binaries" / "Scarface.exe",
    "xb": BASE_DIR / "binaries" / "default.xbe",
    "proto": BASE_DIR / "binaries" / "game.xbe",
}
RECON_DIR = BASE_DIR / "reconstructed_src"
REPORTS_DIR = BASE_DIR / "reports"
PRIVATE_DIR = BASE_DIR / "private"                     # gitignored
AUTH_JSON = PRIVATE_DIR / "contributor_tokens.json"
LEGACY_AUTH_JSON = REPORTS_DIR / "contributor_tokens.json"
REGISTRY_JSON = REPORTS_DIR / "verified_registry.json"
QUEUE_JSON = REPORTS_DIR / "full_remaining_queue.json"
OVERLAY_JSON = REPORTS_DIR / "task_progress_state.json"
AUDIT_JSON = REPORTS_DIR / "decomp_audit_log.json"
PARTIAL_CPP = RECON_DIR / "Partial_Proven_Checkpoints.cpp"
INDEX_HTML = BASE_DIR / "website_kit" / "index.html"
HANDOFF_MD = BASE_DIR / "SCARFACE_DECOMP_AI_HANDOFF.md"
SCRIPTS_DIR = BASE_DIR / "binaries" / "scripts_and_data"

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
GROUPS: Dict[str, List[dict]] = {}          # look-alike group id -> tasks (tools/lookalikes.py)
BY_SYMBOL: Dict[str, List[dict]] = {}       # "Class::vfunc_NN" -> the same method in each build
BUILD_NAMES = {"xb": "the retail Xbox game", "pc": "the PC game", "proto": "the April 2006 prototype"}
PORT_STATUS: Dict[str, dict] = {}           # task id -> progress of carrying its match to its look-alikes
PORT_JOBS: "queue_mod.Queue" = queue_mod.Queue()
PORT_MAX = int(os.environ.get("SCARFACE_LOOKALIKE_MAX", "1000"))

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
        if p and p.exists():
            problem = GF.refusal(p)
            if problem:
                BINARY_PROBLEMS[b] = problem
            else:
                img = BinaryImage(p)
        _IMAGES[b] = img
    return _IMAGES[b]


def accepted_binaries() -> Dict[str, Path]:
    return {b: p for b, p in BINARIES.items() if image_for(b)}


def compiler_version() -> str:
    if "v" not in _COMPILER:
        _COMPILER["v"] = MV.compiler_version()
    return _COMPILER["v"]


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


def progress() -> dict:
    """The headline numbers are the released game (PC + Xbox). The April 2006 prototype (unreleased code,
    saved in the repository like everything else) is counted on its own under "prototype"."""
    entries = REGISTRY.get("entries", {})
    by_bin = Counter(e["bin"] for e in entries.values())
    retail = [e for e in entries.values() if e["bin"] != "proto"]
    remaining = sum(1 for t in ALL_TASKS if t["status"] != "VERIFIED" and t["bin"] != "proto")
    total = remaining + len(retail)
    proto_left = sum(1 for t in ALL_TASKS if t["status"] != "VERIFIED" and t["bin"] == "proto")
    proto_done = by_bin.get("proto", 0)
    return {
        "matched_functions": len(retail),
        "total_functions": total,
        "matched_percent": round(len(retail) / total * 100.0, 2) if total else 0.0,
        "matched_bytes": sum(int(e.get("size", 0)) for e in retail),
        "by_binary": {"pc": by_bin.get("pc", 0), "xbox": by_bin.get("xb", 0), "proto": proto_done},
        "prototype": {"matched": proto_done, "total": proto_done + proto_left},
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
        images = {b: image_for(b) for b in ("pc", "xb", "proto") if image_for(b)}
        if images:
            print("[*] Grouping look-alike functions (once; about 15 seconds)...")
            LA.annotate([t for t in tasks if "fva_int" in t], images)
            write_json(QUEUE_JSON, tasks)
    verified = set(REGISTRY["entries"])
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
    for t in ALL_TASKS:
        if t.get("lookalike_group"):
            GROUPS.setdefault(t["lookalike_group"], []).append(t)
        if "::" in t["symbol"]:
            BY_SYMBOL.setdefault(t["symbol"], []).append(t)
    for same in BY_SYMBOL.values():
        same.sort(key=lambda m: ("xb", "pc", "proto").index(m["bin"]) if m["bin"] in ("xb", "pc", "proto") else 9)
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
    code = img.read(t["fva_int"], int(t["size"])) if img else None
    return LA.signature(code, t["fva_int"], img)[1] if code else None


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
    """The same class method in the other builds (retail Xbox, PC, prototype), whatever its code."""
    return [m for m in BY_SYMBOL.get(t["symbol"], []) if m is not t and m["bin"] != t["bin"]] if "::" in t["symbol"] else []


def counterpart_starter(t: dict) -> Tuple[str, str]:
    """When the same method is already matched in another build but its code differs here, its C++ is
    still the best place to start: (code, id it came from) or ("", "")."""
    for m in counterparts(t):
        e = REGISTRY["entries"].get(task_key(m)) if m["status"] == "VERIFIED" else None
        if e and (e.get("code") or "").strip():
            head = (f"// {t['symbol']} is already matched in {BUILD_NAMES.get(m['bin'], m['bin'])} ({m['va']}); this is\n"
                    f"// that code. This build's machine code is different, so expect to change a few things.\n")
            return head + e["code"].strip() + "\n", m["id"]
    return "", ""


def live_task(t: dict) -> dict:
    out = {k: v for k, v in t.items() if k not in ("best_cpp",)}
    tb = target_bytes(t)
    out["target_hex"] = " ".join(f"{b:02X}" for b in tb) if tb else ""
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
        out["starter_cpp"] = code or synthesize_cpp(t["symbol"], t["va"], tb or b"", out["disasm_lines"])
        out["starter_from"], out["starter_kind"] = src, kind
    out["server_now"] = now_ts()
    return out


_SLUG_RE = re.compile(r"^[A-Za-z0-9_-]{1,64}$")


def decompme_prepare(t: dict) -> dict:
    """Everything the page needs to create a decomp.me scratch for this function."""
    img = image_for(t["bin"])
    if img is None:
        return {"ok": False, "error": f"binaries/{BINARIES[t['bin']].name} is missing, so there is nothing to send."}
    starter = live_task(t).get("starter_cpp", "")
    obj, fields = DME.prepare(img, t["fva_int"], int(t["size"]), t["symbol"], t["flags"], starter,
                              [BASE_DIR / "include", RECON_DIR])
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
    (scripts/reverify_all.py does the same, so the portal and the re-verifier agree)."""
    opts = [t["flags"]]
    if t["bin"] == "pc" and "/G6" in t["flags"]:
        opts.append(t["flags"].replace("/G6", "/G7"))
    return opts


NO_COMPILER_HELP = ("The 2003 compiler is not installed on this computer yet, so it can't verify here.\n"
                    "Install it once from your own VCToolkitSetup.exe:\n"
                    "    python scripts/setup_msvc71.py path/to/VCToolkitSetup.exe\n"
                    "Or, if your code scores 100% on decomp.me, post the decomp.me link in a GitHub issue "
                    "and a maintainer will verify it and credit you.")


def run_verify(t: dict, cpp_code: str) -> dict:
    if not MV.find_msvc71_bin():
        return {"ok": False, "compiler_error": NO_COMPILER_HELP}
    tb = target_bytes(t)
    if tb is None:
        return {"ok": False, "compiler_error": f"binaries/{BINARIES[t['bin']].name} is missing, so there is nothing to compare against."}
    best: Optional[dict] = None
    for flags in flag_options(t):
        res = MV.verify_submission(cpp_code, tb, flags, t.get("match_substr", ""), fn_va=t["fva_int"],
                                   image=image_for(t["bin"]), include_dirs=[BASE_DIR / "include", RECON_DIR])
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


def record_verified(t: dict, cpp_code: str, user: str, tool: str, res: dict, ported_from: str = "",
                    write: bool = True) -> None:
    key = task_key(t)
    REGISTRY["entries"][key] = {
        "bin": t["bin"], "va": f"0x{t['fva_int']:08X}", "size": int(t["size"]), "symbol": t["symbol"],
        "match": t.get("match_substr", ""),
        "flags": res.get("flags") or t["flags"], "source": "portal", "verified_by": user, "tool_used": tool,
        "verified_at": stamp(), "code": cpp_code.strip(),
        "note": f"{res.get('reloc_unverified', 0)} external relocation(s) unchecked" if res.get("reloc_unverified") else "",
    }
    if ported_from:
        REGISTRY["entries"][key]["ported_from"] = ported_from
    if write:
        save_registry()


def save_registry() -> None:
    REGISTRY["compiler"] = compiler_version()
    write_json(REGISTRY_JSON, REGISTRY)
    write_outputs(REGISTRY, RECON_DIR)


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


def port_lookalikes(t: dict, cpp_code: str, user: str, tool: str) -> dict:
    """Rewrite t's matched C++ for each look-alike, compile and verify it. Only exact matches whose
    every address is checked are recorded, credited to the same person."""
    targets = lookalike_targets(t, user)
    st = PORT_STATUS.setdefault(t["id"], {})
    st.update(running=True, total=len(targets), tried=0, matched=0, matched_ids=[])
    src_relocs = relocs_for(t)
    unsaved = 0
    for m in targets:
        dst_relocs = relocs_for(m)
        ported = (LA.port_code(cpp_code, t, src_relocs, m, dst_relocs)
                  if src_relocs is not None and dst_relocs is not None else None)
        res = run_verify(m, ported) if ported else {"ok": False}
        st["tried"] += 1
        if not (res.get("ok") and res.get("verified") and not res.get("reloc_unverified")):
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


def queue_port(t: dict, cpp_code: str, user: str, tool: str) -> int:
    """Start carrying t's match to its look-alikes in the background; returns how many will be tried."""
    n = len(lookalike_targets(t, user))
    if not n:
        return 0
    PORT_STATUS[t["id"]] = {"running": True, "total": n, "tried": 0, "matched": 0, "matched_ids": []}
    if not _PORT_THREAD:
        th = threading.Thread(target=_port_worker, name="lookalikes", daemon=True)
        th.start()
        _PORT_THREAD.append(th)
    PORT_JOBS.put((t, cpp_code, user, tool))
    return n


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


def _http_json(url: str, body: Optional[dict], headers: dict, timeout: int = 180) -> Tuple[int, dict, str]:
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


def _err(status: int, raw: str, key: str) -> str:
    text = raw[:300].replace(key, "***") if key else raw[:300]
    return f"HTTP {status}: {text}"


def _rejects_temperature(st: int, raw: str) -> bool:
    """Newer reasoning models only accept their default temperature and answer 400 when one is set."""
    return st == 400 and "temperature" in raw.lower()


def _openai_style(url: str, key: str, model: str, prompt: str, extra_headers: Optional[dict] = None) -> Tuple[bool, str, str]:
    body = {"model": model, "messages": [{"role": "system", "content": SYSTEM_PROMPT}, {"role": "user", "content": prompt}]}
    if not re.match(r"^o\d", model):
        body["temperature"] = 0.2
    headers = {"Authorization": f"Bearer {key}"} if key else {}
    headers.update(extra_headers or {})
    st, j, raw = _http_json(url, body, headers)
    if "temperature" in body and _rejects_temperature(st, raw):
        body.pop("temperature")
        st, j, raw = _http_json(url, body, headers)
    if st != 200:
        return False, _err(st, raw, key), model
    try:
        return True, j["choices"][0]["message"]["content"] or "", j.get("model", model)
    except Exception:
        return False, "Unexpected response shape: " + raw[:200], model


def _gemini(key: str, model: str, prompt: str) -> Tuple[bool, str, str]:
    base = "https://generativelanguage.googleapis.com/v1beta"
    body = {"system_instruction": {"parts": [{"text": SYSTEM_PROMPT}]},
            "contents": [{"role": "user", "parts": [{"text": prompt}]}],
            "generationConfig": {"temperature": 0.2}}
    hdr = {"x-goog-api-key": key}

    def call(m: str):
        url = f"{base}/models/{urllib.parse.quote(m)}:generateContent"
        st, j, raw = _http_json(url, body, hdr)
        if _rejects_temperature(st, raw) and body.get("generationConfig"):
            body.pop("generationConfig")
            st, j, raw = _http_json(url, body, hdr)
        if st == 200:
            parts = ((j.get("candidates") or [{}])[0].get("content") or {}).get("parts") or []
            return True, "".join(p.get("text", "") for p in parts), m, st
        return False, _err(st, raw, key), m, st

    m = model.replace("models/", "").strip()
    ok, text, used, st = call(m)
    if ok or st != 404:
        return ok, text, used
    st2, j2, raw2 = _http_json(f"{base}/models", None, hdr, timeout=30)       # model retired: pick one that exists
    if st2 == 200:
        names = [x["name"].replace("models/", "") for x in j2.get("models", [])
                 if "generateContent" in (x.get("supportedGenerationMethods") or []) and "gemini" in x.get("name", "")
                 and not any(k in x.get("name", "") for k in ("image", "tts", "embedding"))]
        for alt in names[:3]:
            ok, text, used, _ = call(alt)
            if ok:
                return True, text, used
    return False, text + f" (and no replacement model was found for '{m}')", m


def ai_call(cfg: dict) -> dict:
    provider = (cfg.get("provider") or "").strip()
    model = (cfg.get("model") or "").strip()
    key = (cfg.get("api_key") or "").strip()
    prompt = "Reply with the single word OK." if cfg.get("is_test") else (cfg.get("prompt") or "")
    if not prompt:
        return {"ok": False, "error": "Empty prompt."}
    if provider != "ollama" and not key:
        return {"ok": False, "error": "Paste an API key first."}
    try:
        if provider == "gemini":
            ok, text, used = _gemini(key, model or "gemini-flash-latest", prompt)
        elif provider == "openai":
            ok, text, used = _openai_style("https://api.openai.com/v1/chat/completions", key, model, prompt)
        elif provider == "argon":
            ok, text, used = _openai_style("https://openrouter.ai/api/v1/chat/completions", key, model, prompt,
                                           {"X-Title": "Scarface Decomp Portal"})
        elif provider == "custom_api":
            url = (cfg.get("custom_url") or "").strip()
            if not re.match(r"^https?://", url):
                return {"ok": False, "error": "Custom URL must start with http:// or https://"}
            ok, text, used = _openai_style(url, key, model, prompt)
        elif provider == "anthropic":
            body = {"model": model, "max_tokens": 8192, "system": SYSTEM_PROMPT, "temperature": 0.2,
                    "messages": [{"role": "user", "content": prompt}]}
            hdrs = {"x-api-key": key, "anthropic-version": "2023-06-01"}
            st, j, raw = _http_json("https://api.anthropic.com/v1/messages", body, hdrs)
            if _rejects_temperature(st, raw):
                body.pop("temperature")
                st, j, raw = _http_json("https://api.anthropic.com/v1/messages", body, hdrs)
            if st != 200:
                ok, text, used = False, _err(st, raw, key), model
            else:
                ok, used = True, j.get("model", model)
                text = "".join(b.get("text", "") for b in j.get("content", []) if b.get("type") == "text")
        elif provider == "ollama":
            st, j, raw = _http_json("http://127.0.0.1:11434/api/chat",
                                    {"model": model, "stream": False, "options": {"temperature": 0.2},
                                     "messages": [{"role": "system", "content": SYSTEM_PROMPT}, {"role": "user", "content": prompt}]}, {})
            ok, used = st == 200, model
            text = (j.get("message") or {}).get("content", "") if ok else _err(st, raw, "")
        else:
            return {"ok": False, "error": f"Unknown provider '{provider}'."}
    except urllib.error.URLError as e:
        return {"ok": False, "error": f"Could not reach {provider}: {getattr(e, 'reason', e)}"}
    except Exception as e:  # never echo the key
        return {"ok": False, "error": f"{type(e).__name__}: {str(e).replace(key, '***') if key else e}"}
    return {"ok": True, "reply": text, "used_model": used} if ok else {"ok": False, "error": text}


# =========================================================================== #
# Git sync (maintainers only)
# =========================================================================== #

GIT_PATHS = ["reconstructed_src", "reports/verified_registry.json", "reports/reverify_report.md",
             "reports/decomp_audit_log.json", "reports/progress.json", "README.md"]


def git_sync(user: str) -> dict:
    def run(args, timeout=120):
        p = subprocess.run(["git"] + args, cwd=BASE_DIR, capture_output=True, text=True, timeout=timeout)
        return p.returncode, (p.stdout + p.stderr).strip()
    try:
        rc, out = run(["add", "--"] + [p for p in GIT_PATHS if (BASE_DIR / p).exists()])
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
        if rc:
            return {"ok": False, "error": "Committed locally, but git push failed: " + out[-400:]}
        return {"ok": True, "message": f"Pushed {n} verified functions to GitHub."}
    except FileNotFoundError:
        return {"ok": False, "error": "git is not installed or not on PATH."}
    except subprocess.TimeoutExpired:
        return {"ok": False, "error": "git timed out."}


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


def script_detail(rel: str) -> dict:
    """What one script file contains: the exact round-trip check, its strings and its bytecode."""
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
        res = verify_and_decompile_dtr(raw, p.name) if ext == ".dtr" else verify_and_decompile_cso_dso(raw, p.name)
    except Exception as e:  # noqa: BLE001 - one odd file shouldn't break the tab
        res = {"ok": False, "error": str(e)}
    if not res.get("ok"):
        return {"ok": True, "path": rel, "format": "could not be read", "size": len(raw), "opcode_count": 0,
                "decompiled_code": f"// {p.name}: {res.get('error')}", "disasm": ""}
    return {"ok": True, "path": rel, "format": res["format"], "size": res["size"],
            "opcode_count": res["opcode_count"], "disasm": res["disasm"], "decompiled_code": res["decompiled_code"]}


def script_list_payload(selected: str = "") -> dict:
    items, versions = script_index()
    out = {"ok": True, "files": items, "versions": versions}
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

class Handler(BaseHTTPRequestHandler):
    server_version = "ScarfaceDecomp/2"

    def log_message(self, fmt, *args):
        pass

    def _send(self, code: int, body: bytes, ctype: str, extra: Optional[dict] = None):
        self.send_response(code)
        self.send_header("Content-Type", ctype)
        self.send_header("Cache-Control", "no-store")
        self.send_header("X-Content-Type-Options", "nosniff")
        for k, v in (extra or {}).items():
            self.send_header(k, v)
        self.send_header("Content-Length", str(len(body)))
        self.end_headers()
        self.wfile.write(body)

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
        if self.command == "POST":
            origin = (self.headers.get("Origin") or "").strip().lower()
            site = (self.headers.get("Sec-Fetch-Site") or "").strip().lower()
            ok_origin = not origin or urllib.parse.urlparse(origin).netloc == host
            if site == "cross-site" or not ok_origin:
                self._json({"ok": False, "error": "Requests from other websites are not accepted."}, 403)
                return False
        return True

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
        if u.path == "/download/ai-handoff":
            data = HANDOFF_MD.read_bytes() if HANDOFF_MD.exists() else b"# AI handoff\n"
            return self._send(200, data, "text/markdown; charset=utf-8",
                              {"Content-Disposition": 'attachment; filename="SCARFACE_DECOMP_AI_HANDOFF.md"'})
        if u.path == "/api/health":
            return self._json({"ok": True, "compiler": compiler_version(),
                               "binaries": {k: bool(image_for(k)) for k in BINARIES}})
        if u.path == "/api/state":
            with STATE_LOCK:
                tiers = Counter(t["tier"] for t in ALL_TASKS if t["status"] != "VERIFIED")
                tiers["PARTIAL"] = sum(1 for t in ALL_TASKS if t["status"] == "PARTIAL")
                remaining = sum(1 for t in ALL_TASKS if t["status"] != "VERIFIED")
                return self._json({"progress": progress(), "leaderboard": leaderboard(),
                                   "audit_log": read_json(AUDIT_JSON, []), "sources": list_sources(),
                                   "tier_counts": dict(tiers), "total_remaining_indexed": remaining,
                                   "repo_url": REPO_URL, "lookalikes": lookalike_summary(),
                                   "binary_problems": BINARY_PROBLEMS})
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
                for t in ALL_TASKS:
                    st = t["status"]
                    if lane in ("UNCLAIMED", "CLAIMED", "VERIFIED") and st != lane:
                        continue
                    if lane == "PARTIAL" and not (st == "PARTIAL" or (t.get("best_matched_bytes", 0) > 0 and st != "VERIFIED")):
                        continue
                    if lane not in ("ALL", "UNCLAIMED", "CLAIMED", "PARTIAL", "VERIFIED") and lane not in t["lane"]:
                        continue
                    if lane != "VERIFIED" and st == "VERIFIED" and sort_by != "VERIFIED_FIRST":
                        continue
                    if tier != "ALL" and t.get("tier") != tier:
                        continue
                    if q and q not in t["symbol"].lower() and q not in t["va"].lower():
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
            "/api/decompme": self.post_decompme,
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
        res = run_verify(t, code)                           # compile outside the lock
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
                record_verified(t, code, user, tool, res)
                t.update(status="VERIFIED", claimed_by="", claim_expires_at=0)
                save_overlay(t)
                append_audit({"time": stamp(), "user": user, "action": "VERIFIED", "symbol": t["symbol"], "va": t["va"],
                              "bytes": f"{t['size']}/{t['size']} B"})
                newly = True
                print(f"[+] VERIFIED by {user}: {t['symbol']} ({t['va']}) -> {len(REGISTRY['entries'])} total")
            out = dict(res)
            out.update(newly_promoted=newly, progress=progress(), leaderboard=leaderboard(), task=live_task(t),
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
        return self._json({"ok": True, "cpp_code": synthesize_cpp(t["symbol"], t["va"], tb, disassemble(tb))})

    def post_ai(self, body):
        self._json(ai_call(body))

    def post_git(self, body):
        user = self._auth(body)
        if not user:
            return
        if user not in MAINTAINERS:
            return self._json({"ok": False, "error": "Only maintainers can push to GitHub (set SCARFACE_MAINTAINERS)."}, 403)
        with STATE_LOCK:
            res = git_sync(user)
        self._json(res)

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
        sys.exit("Capstone is required (function sizes, disassembly, address checks): pip install -r requirements.txt")
    _migrate_legacy_auth()
    load_registry()
    load_tasks()
    if not MV.find_msvc71_bin():
        print("[!] The 2003 compiler is not installed yet. You can still browse functions and use decomp.me;")
        print("    to verify here, run: python scripts/setup_msvc71.py path/to/VCToolkitSetup.exe")
    p = progress()
    url = f"http://{'localhost' if HOST in ('127.0.0.1', '0.0.0.0') else HOST}:{PORT}"
    print("=" * 78)
    print(" SCARFACE: THE WORLD IS YOURS — MATCHING DECOMP PORTAL")
    print("=" * 78)
    print(f"  URL        : {url}")
    print(f"  Compiler   : {p['compiler']}")
    print(f"  Verified   : {p['matched_functions']:,} functions (PC {p['by_binary']['pc']:,}, Xbox {p['by_binary']['xbox']:,})")
    print(f"  Work queue : {sum(1 for t in ALL_TASKS if t['status'] != 'VERIFIED'):,} functions")
    print(f"  Look-alikes: {len(GROUPS):,} groups; a match in one is tried on the rest of its group")
    if any(t["bin"] == "proto" for t in ALL_TASKS):
        pp = p["prototype"]
        print(f"  Prototype  : {pp['matched']:,} / {pp['total']:,} (April 2006 Xbox build, unreleased code; counted on its own)")
    print(f"  Maintainers: {', '.join(sorted(MAINTAINERS))}")
    print("=" * 78)
    for b, problem in BINARY_PROBLEMS.items():
        print(f"[!] NOT USED: {problem}")
    if os.environ.get("SCARFACE_NO_BROWSER") != "1":
        if os.name == "nt":
            subprocess.Popen(["cmd", "/c", "start", url])
        else:
            import webbrowser
            threading.Timer(1.0, lambda: webbrowser.open(url)).start()
    ThreadingHTTPServer((HOST, PORT), Handler).serve_forever()


if __name__ == "__main__":
    main()
