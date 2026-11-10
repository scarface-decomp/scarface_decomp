#!/usr/bin/env python3
"""
Mock backend for portal/website_kit/index.html, for front-end work without cl.exe or the game binaries.

    python3 portal/tools/mock_portal_api.py --port 8765
    open http://127.0.0.1:8765/

It implements the same JSON endpoints the page calls (/api/state, /api/queue, /api/task,
/api/login, /api/claim, /api/cancel, /api/verify, /api/fast-synthesize, /api/ai-proxy,
/api/git-sync, /api/scripts, /api/upload-script, /api/decompme) with fake data. It also plays
decomp.me (POST /api/scratch, GET /scratch/<slug>/claim) so the decomp.me button can be tested offline:

  * C++ containing MATCH_ALL verifies 100%; containing COMPILE_ERROR fails to compile.
  * The fake AI returns MATCH_ALL code for functions whose symbol contains "Easy"; for the others it
    gives up (GIVE UP:) once it has made three tries.
  * Login accepts any handle; the first PIN used for a handle becomes its PIN.
"""

from __future__ import annotations

import argparse
import json
import os
import struct
import sys
import threading
import time
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from urllib.parse import parse_qs, urlparse

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "website_kit"))
FONTS = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "..", "docs", "fonts"))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import web_security as WS  # noqa: E402  (the real portal's headers, so the tests run the page under them)

PAGE_CSP = WS.page_policy(("https://decomp.me",))
LOCK = threading.Lock()
LEASE_SEC = 15 * 60
DELAYS = {"verify": 0.15, "ai": 0.25, "fast": 0.05}
CONFIG = {"lease_sec": LEASE_SEC, "no_login": False, "legacy_claim": False, "dme_browser_fail": False}
SCRATCHES: list = []      # fields of each fake decomp.me scratch created
CALLS: list = []          # (endpoint, payload-summary) for tests


def make_tasks(n=200):
    tasks = {}
    for i in range(n):
        size = [12, 28, 52, 96][i % 4]
        tier = ["TIER_1_QUICK", "TIER_2_SMALL", "TIER_3_MEDIUM", "TIER_4_LARGE"][i % 4]
        sub = ["core::", "audio::", "pure3d::", "fe::", "AIAction"][i % 5]
        easy = "Easy" if i % 3 == 0 else "Hard"
        tid = f"t{i:04d}"
        tasks[tid] = {
            "id": tid, "symbol": f"{sub}{easy}Func{i:04d}", "va": f"0x{0x401000 + i * 0x40:08X}",
            "size": size, "status": "UNCLAIMED", "claimed_by": "", "claim_expires_at": 0,
            "best_matched_bytes": 0, "best_pct": 0, "best_diff_details": [], "tier": tier,
            "tier_label": tier.replace("_", " ").title(), "est_label": "~15 mins",
            "flags": "/nologo /c /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4", "hint": "Mock function.",
            "target_hex": " ".join(f"{(i + k) & 0xFF:02X}" for k in range(size)),
            "disasm_lines": [f"{0x401000 + i * 0x40 + k:08X}  nop" for k in range(4)],
            "decompme_slug": "",
            "starter_cpp": f"// starter for {tid}\nvoid Func{i:04d}() {{}}\n",
            "best_code": "",
        }
    return tasks


TASKS = make_tasks()
USERS: dict = {}
AUDIT: list = []
SOURCES = {"Original_Binary_Order_PC_1002.cpp": "// VERIFIED 1:1 MATCH\nvoid a() {}\n",
           "core/DriveThread.cpp": "// VERIFIED 1:1 MATCH\nvoid b() {}\n"}
def _script(path, version, compare="", code="function init() {}"):
    return {"path": path, "name": path.rsplit("/", 1)[-1], "version": version, "ext": path.rsplit(".", 1)[-1].upper(),
            "size": 128, "compare": compare, "format": "TorqueScript bytecode", "opcode_count": 12,
            "decompiled_code": code, "disasm": "0000 FUNC_DECL"}


SCRIPTS = [_script("xbox/scriptc/init.cso", "xbox"), _script("xbox/scriptc/missions/mission_manager.cso", "xbox"),
           _script("prototype/scriptc/init.cso", "prototype", "same"),
           _script("prototype/scriptc/missions/mission_manager.cso", "prototype", "changed", "// older"),
           _script("prototype/scriptc/editor.cso", "prototype", "only here", "// cut from retail")]
SCRIPT_LABELS = {"xbox": "Retail game (Xbox; the PS2 disc has the same files)", "prototype": "Xbox prototype, April 2006",
                 "uploads": "Files you loaded"}


def script_list(selected=""):
    keys = ("path", "name", "version", "ext", "size", "compare")
    counts = {}
    for s in SCRIPTS:
        counts[s["version"]] = counts.get(s["version"], 0) + 1
    out = {"ok": True, "files": [{k: s[k] for k in keys} for s in SCRIPTS],
           "versions": [{"id": v, "label": SCRIPT_LABELS.get(v, v), "count": n} for v, n in counts.items()]}
    if selected:
        out["selected"] = selected
    return out


def now():
    return int(time.time())


def expire_claims():
    t = now()
    for task in TASKS.values():
        if task["status"] == "CLAIMED" and task["claim_expires_at"] <= t:
            task["status"] = "PARTIAL" if task["best_matched_bytes"] else "UNCLAIMED"
            task["claimed_by"] = ""


def public_task(task):
    out = {k: v for k, v in task.items() if k != "best_code"}
    out["server_now"] = now()
    if task["best_code"]:
        out["starter_cpp"] = task["best_code"]
    return out


def progress():
    matched = sum(1 for t in TASKS.values() if t["status"] == "VERIFIED")
    total = len(TASKS)
    return {"matched_functions": matched, "total_functions": total,
            "matched_percent": round(matched / total * 100, 2)}


def leaderboard():
    board = {}
    for e in AUDIT:
        if e["action"] == "VERIFIED":
            board[e["user"]] = board.get(e["user"], 0) + 1
    return board


def tier_counts():
    out = {}
    for t in TASKS.values():
        if t["status"] != "VERIFIED":
            out[t["tier"]] = out.get(t["tier"], 0) + 1
    return out


def auth(body):
    user, pin = (body.get("user") or "").strip(), (body.get("pin") or "").strip()
    if not user or not pin:
        return None, "Sign in first."
    if CONFIG["no_login"]:                 # real server registers a handle on first use
        USERS.setdefault(user, pin)
    if USERS.get(user) != pin:
        return None, f"Handle '{user}' is locked with a PIN. Enter the matching PIN or change handle."
    return user, None


IMPORT: dict = {"running": False}

# Game files (sounds, textures, models, videos): a fake run that takes about two seconds
GF_KINDS = [{"id": "sounds", "label": "Sounds"}, {"id": "videos", "label": "Videos"},
            {"id": "models", "label": "Models & textures"}, {"id": "scripts", "label": "Scripts & text"},
            {"id": "other", "label": "Other"}]
GF_VERSIONS = [
    {"version": "xbox", "label": "Xbox", "found": True, "kind": "disc", "size": 3360096256,
     "source": "Scarface - The World Is Yours (USA, Europe).7z (Scarface - The World Is Yours (USA, Europe).xiso.iso)"},
    {"version": "pc", "label": "PC", "found": True, "kind": "pcdisc", "size": 2344373373,
     "source": "Scarface-The-World-Is-Yours_Win_EN_ISO-Version.iso + Scarface-The-World-Is-Yours_Patch_Win_EN_Patch-v1002.exe"},
    {"version": "ps2", "label": "PS2", "found": True, "kind": "disc", "size": 3791028224,
     "source": "Scarface - The World Is Yours (ps2).7z (Scarface - The World Is Yours (USA).iso)"},
    {"version": "prototype", "label": "Xbox 2006 prototype", "found": True, "kind": "zip", "size": 3789570048,
     "source": "Scarface - The World Is Yours (Apr 20, 2006 prototype).zip"},
]
GF: dict = {"status": {"running": False, "phase": "", "done": 0, "total": 0, "files": 0, "label": "", "message": "",
                       "error": ""}, "summary": None, "files": {}, "copy": None, "movies": {},
      "textures": {"running": False, "phase": "", "written": 0, "made": False}, "speed": {"cores": True, "gpu": True}}
GF_LINE = "Say hello to my little friend!"
BLENDER: dict = {"running": False, "version": "", "done": 0, "total": 0, "area": "", "error": "", "written": 0,
                 "bytes": 0, "folder": ""}
GF_AREAS = [{"key": "z04/stripmall_01", "name": "stripmall_01", "place": "z04", "files": 3},
            {"key": "z04/havana_01", "name": "havana_01", "place": "z04", "files": 2},
            {"key": "azones/donutshop_01", "name": "donutshop_01", "place": "azones", "files": 1}]


def blender_run(version):
    """A made-up city export: three areas, a moment each."""
    BLENDER.update(running=True, version=version, done=0, total=3, written=0, bytes=0, error="",
                   folder=f"binaries/blender/{version.upper()}")
    for a in GF_AREAS[:2] + [{"name": "bridge_01"}]:
        BLENDER["area"] = a["name"]
        time.sleep(0.25)
        BLENDER["done"] += 1
        BLENDER["written"] += 1
        BLENDER["bytes"] += 4 << 20
    BLENDER.update(running=False, area="")


def gf_fake_files(version):
    rows = []
    names = {"xbox": "cement.rcf/art/", "pc": "cement.rcf/art/", "ps2": "CEMENT.RCF/art/", "prototype": "art/"}[version]
    for i in range(260):
        st = "only" if i % 3 == 0 else ("changed" if i % 3 == 1 else "shared")
        ext = [".rsd", ".p3d", ".bik", ".cso", ".dat"][i % 5]
        kind = {".rsd": "sounds", ".p3d": "models", ".bik": "videos", ".cso": "scripts", ".dat": "other"}[ext]
        path = f"{names}{kind}/{version}_{i:03d}{ext}"
        rows.append({"path": path, "size": 1000 + i * 37, "status": st, "kind": kind,
                     "placed": ("Shared/" if st == "shared" else "") + path})
    return rows


def gf_summary(mode, folders="game"):
    labels = {"unique": "No duplicates", "every": "Every version complete", "best": "Best version of each file",
              "pc": "The PC first, then what only the others have"}
    out = {"mode": mode, "mode_label": labels.get(mode, mode), "folders": folders,
           "created": "2026-11-09 09:30", "versions": {}}
    for v in GF_VERSIONS:
        if not v["found"]:
            continue
        rows = gf_fake_files(v["version"])
        for i, r in enumerate(rows):
            r["picked"] = mode in ("best", "pc") and (v["version"] == "pc" or r["status"] == "only")
            r["quality"] = "Ogg Vorbis, 48,000 Hz, mono" if r["kind"] == "sounds" else ""
        GF["files"][v["version"]] = rows
        s = {"label": v["label"], "source": v["source"], "files": len(rows), "bytes": sum(r["size"] for r in rows),
             "only": 0, "changed": 0, "shared": 0, "own_bytes": 0, "kinds": {}}
        for r in rows:
            s[r["status"]] += 1
            if r["status"] != "shared":
                k = s["kinds"].setdefault(r["kind"], {"only": 0, "changed": 0})
                k[r["status"]] += 1
        s["picked"] = sum(1 for r in rows if r["picked"])
        out["versions"][v["version"]] = s
    if mode in ("best", "pc"):
        out["best" if mode == "best" else "pc_first"] = {"files": sum(x["picked"] for x in out["versions"].values()),
                                                         "from": {k: x["picked"] for k, x in out["versions"].items()}}
    return out


def gf_run(versions, mode, folders="game", all_there=False):
    total = sum(v["size"] for v in GF_VERSIONS if v["found"] and v["version"] in versions)
    st = GF["status"]
    if all_there:                         # a check of a copy with nothing missing
        time.sleep(1.2)
        with LOCK:
            st.update(running=False, phase="done", message="Already copied", files=4000)
        return
    for i in range(1, 11):
        time.sleep(0.15)
        with LOCK:
            if st.get("stop"):
                st.update(running=False, phase="stopped", stop=False,
                          message="Stopped. Press Copy again to carry on where it left off.")
                return
            st.update(phase="reading", label="Xbox" if i < 5 else "PS2", done=total * i // 10, total=total, files=i * 1234)
    with LOCK:
        st.update(phase="placing", placed=0, to_place=4000)
    for i in range(1, 5):
        time.sleep(0.4)                       # long enough for the page's once-a-second look to see it
        with LOCK:
            st["placed"] = i * 1000
    with LOCK:
        GF["summary"] = gf_summary(mode, folders)
        GF["copy"] = {"versions": [v["version"] for v in GF_VERSIONS if v["found"] and v["version"] in versions],
                      "mode": mode, "folders": folders, "created": GF["summary"]["created"], "current": True}
        st.update(running=False, phase="done", message="Done")


class Handler(BaseHTTPRequestHandler):
    def log_message(self, *a):
        pass

    def send_header(self, keyword, value):
        if keyword.lower() == "content-type":
            self._ctype = value
        super().send_header(keyword, value)

    def end_headers(self):
        for k, v in WS.headers(getattr(self, "_ctype", ""), PAGE_CSP, shared=urlparse(self.path).path.startswith("/api/dme-bridge/")):
            super().send_header(k, v)
        self._ctype = ""
        super().end_headers()

    def _json(self, obj, code=200):
        data = json.dumps(obj).encode()
        self.send_response(code)
        self.send_header("Content-Type", "application/json")
        self.send_header("Content-Length", str(len(data)))
        self.end_headers()
        self.wfile.write(data)

    def _bytes(self, data, ctype):
        self.send_response(200)
        self.send_header("Content-Type", ctype)
        self.send_header("Content-Length", str(len(data)))
        self.end_headers()
        self.wfile.write(data)

    def _game_file_preview(self, what, q):
        """Made-up previews: a short tone for sounds, two small pictures for .p3d files."""
        import math
        sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
        import media
        row = next((r for r in GF["files"].get(q.get("version", ""), []) if r["path"] == q.get("path")), None)
        if not row:
            return self._json({"ok": False, "error": "That file isn't in your copied game files (copy them first)."}, 404)
        if what == "sound":
            pcm = b"".join(struct.pack("<h", int(8000 * math.sin(i / 8))) for i in range(4410))
            return self._bytes(media._wav(pcm, 1, 22050), "audio/wav")
        if what == "pictures":
            return self._json({"ok": True, "pictures": [{"i": 0, "name": "wall.bmp", "width": 8, "height": 8, "kind": "p3di"},
                                                        {"i": 1, "name": "sign.tga", "width": 16, "height": 8, "kind": "dds"}]})
        w = 8 if q.get("i") == "0" else 16
        return self._bytes(media.png(w, 8, bytes([200, 30, 30, 255]) * (w * 8)), "image/png")

    def do_GET(self):
        u = urlparse(self.path)
        q = {k: v[0] for k, v in parse_qs(u.query).items()}
        with LOCK:
            expire_claims()
            CALLS.append((u.path, q))
            if u.path in ("/", "/index.html"):
                with open(os.path.join(ROOT, "index.html"), "rb") as f:
                    data = f.read()
                self.send_response(200)
                self.send_header("Content-Type", "text/html; charset=utf-8")
                self.send_header("Content-Length", str(len(data)))
                self.end_headers()
                self.wfile.write(data)
                return
            if u.path.startswith("/fonts/") and os.path.basename(u.path) in os.listdir(FONTS):
                with open(os.path.join(FONTS, os.path.basename(u.path)), "rb") as f:
                    return self._bytes(f.read(), "text/css" if u.path.endswith(".css") else "font/woff2")
            if u.path == "/api/state":
                return self._json({"progress": progress(), "leaderboard": leaderboard(), "audit_log": AUDIT[-50:][::-1],
                                   "sources": SOURCES, "tier_counts": tier_counts(),
                                   "total_remaining_indexed": sum(tier_counts().values()),
                                   "repo_url": "https://github.com/example-org/scarface_decomp",
                                   "pending": sum(1 for t in TASKS.values() if t["status"] == "VERIFIED"),
                                   "maintainers": ["Founder"]})
            if u.path == "/api/import-status":
                return self._json(IMPORT)
            if u.path == "/api/game-files":
                return self._json({"ok": True, "versions": GF_VERSIONS, "folder": "binaries/game_files",
                                   "free": 128 * 2**30, "summary": GF["summary"], "copy": GF["copy"],
                                   "interrupted": bool(CONFIG.get("gf_interrupted")),
                                   "status": {k: v for k, v in GF["status"].items() if k != "stop"},
                                   "notes": CONFIG.get("gf_notes", []),
                                   "modes": [{"id": "unique", "label": "No duplicates"},
                                             {"id": "every", "label": "Every version complete"}],
                                   "kinds": GF_KINDS})
            if u.path == "/api/game-files/list":
                rows = GF["files"].get(q.get("version", ""), [])
                st, kind, query = q.get("status", ""), q.get("kind", ""), q.get("q", "").lower()
                rows = [r for r in rows if (not st or r["status"] == st or (st == "own" and r["status"] != "shared")
                                            or (st == "picked" and r.get("picked")))
                        and (not kind or r["kind"] == kind) and (not query or query in r["path"].lower())]
                order = ["sounds", "textures", "models", "animations", "videos", "scripts", "other"]
                rows = sorted(rows, key=lambda r: (order.index(r["kind"]) if r["kind"] in order else 9, r["path"]))
                kinds = {}
                for r in rows:
                    kinds[r["kind"]] = kinds.get(r["kind"], 0) + 1
                off, lim = int(q.get("offset", 0)), int(q.get("limit", 200))
                return self._json({"ok": True, "total": len(rows), "offset": off, "kinds": kinds,
                                   "files": rows[off:off + lim]})
            if u.path in ("/api/game-files/sound", "/api/game-files/pictures", "/api/game-files/picture"):
                return self._game_file_preview(u.path.rsplit("/", 1)[1], q)
            if u.path == "/api/game-files/inspect":
                if q.get("path", "").endswith("_021.p3d"):                       # a subtitle file and its sound
                    return self._json({"ok": True, "kind": "subtitles", "what": "Subtitles: the words of the sound "
                                       "with the same name.", "pictures": 0, "blender": False,
                                       "lines": [{"language": "English", "text": GF_LINE}],
                                       "sound": q["path"].replace("models/", "sounds/").replace("_021.p3d", "_020.rsd")})
                return self._json({"ok": True, "kind": "models", "what": "1 model; 2 pictures.", "pictures": 2,
                                   "blender": True, "lines": []})
            if u.path == "/api/game-files/subtitles":
                return self._json({"ok": True, "lines": [{"language": "English", "text": GF_LINE}]})
            if u.path == "/api/game-files/blender-app":
                return self._json({"ok": True, "found": CONFIG.get("blender", True),
                                   "path": "C:\\Program Files\\Blender Foundation\\Blender 4.2\\blender.exe"
                                   if CONFIG.get("blender", True) else ""})
            if u.path == "/api/game-files/movie-status":
                return self._json(dict(GF["movies"].get(q.get("path", ""), {"state": "none", "progress": 0}), ok=True))
            if u.path == "/api/game-files/movie":
                return self._bytes(b"\0\0\0\x18ftypmp42", "video/mp4")
            if u.path == "/api/game-files/areas":
                return self._json({"ok": True, "areas": GF_AREAS if GF["summary"] else [], "city": dict(BLENDER),
                                   "city_files": BLENDER["written"], "city_current": True})
            if u.path == "/api/game-files/blender":
                return self._json(dict(BLENDER, ok=True))
            if u.path == "/api/game-files/textures":
                return self._json(dict(GF["textures"], ok=True))
            if u.path == "/api/game-files/speed":
                return self._json({"ok": True, "use_cores": GF["speed"]["cores"], "use_gpu": GF["speed"]["gpu"],
                                   "cores": 8, "workers": 7, "ffmpeg": True, "gpu": "NVIDIA"})
            if u.path == "/api/game-files/model":
                if CONFIG.get("model_error"):
                    return self._json({"ok": False, "error": "Nothing to show in Blender: nothing in these files to export."}, 415)
                return self._bytes(b"glTF" + bytes(8), "model/gltf-binary")
            if u.path == "/api/queue":
                items = list(TASKS.values())
                lane, tier, query = q.get("lane", "ALL"), q.get("tier", "ALL"), q.get("q", "").lower()
                if lane in ("UNCLAIMED", "CLAIMED", "VERIFIED", "PARTIAL"):
                    items = [t for t in items if t["status"] == lane]
                why = {}
                if lane == "GOOD_FIRST":               # the "Easy" ones that fit stand in for the real picks
                    why = {t["id"]: "the game's class information names it" for t in items
                           if "Easy" in t["symbol"] and t["size"] <= 32 and t["status"] == "UNCLAIMED"}
                    items = [t for t in items if t["id"] in why]
                if tier != "ALL":
                    items = [t for t in items if t["tier"] == tier]
                if query:
                    items = [t for t in items if query in t["symbol"].lower() or query in t["va"].lower()]
                page, limit = int(q.get("page", 1)), int(q.get("limit", 80))
                sl = items[(page - 1) * limit: page * limit]
                return self._json({"total": len(items), "items": [
                    {**{k: t[k] for k in ("id", "symbol", "va", "size", "status", "claimed_by", "best_matched_bytes", "best_pct", "est_label")},
                     "claim_remaining_sec": max(0, t["claim_expires_at"] - now()) if t["status"] == "CLAIMED" else None,
                     **({"good_first": why[t["id"]]} if t["id"] in why else {})}
                    for t in sl]})
            if u.path == "/api/task":
                t = TASKS.get(q.get("id", ""))
                return self._json({"ok": True, "task": public_task(t)} if t else {"ok": False, "error": "No such task."})
            if u.path == "/api/scripts":
                return self._json(script_list())
            if u.path == "/api/script":
                hit = next((x for x in SCRIPTS if x["path"] == q.get("path")), None)
                return self._json({"ok": True, **hit} if hit else {"ok": False, "error": "No such script file."},
                                  200 if hit else 404)
            if u.path == "/api/decompme":
                t = TASKS.get(q.get("id", ""))
                if not t:
                    return self._json({"ok": False, "error": "Function not found."}, 404)
                api = f"http://127.0.0.1:{self.server.server_address[1]}"
                slug = "" if q.get("fresh") == "1" else t["decompme_slug"]
                return self._json({"ok": True, "api": api, "obj_b64": "TAEAAA==",
                                   "fields": {"name": t["symbol"], "compiler": "msvc7.1", "platform": "win32",
                                              "compiler_flags": t["flags"], "source_code": t["starter_cpp"],
                                              "context": "", "diff_label": ""},
                                   "existing_url": f"{api}/scratch/{slug}" if slug else ""})
            if u.path.startswith("/scratch/"):
                data = b"<!doctype html><title>fake decomp.me</title><p>scratch</p>"
                self.send_response(200)
                self.send_header("Content-Type", "text/html")
                self.send_header("Content-Length", str(len(data)))
                self.end_headers()
                self.wfile.write(data)
                return
            if u.path in ("/download/functions", "/download/scripts", "/download/sources"):
                kind = u.path.rsplit("/", 1)[1]
                if kind == "scripts" and q.get("only") == "verified" and q.get("version") == "prototype":
                    return self._json({"ok": False, "error": "No script files match that choice."}, 404)
                ext = "txt" if q.get("format") == "txt" else "zip"
                name = f"scarface-{kind}-{'verified-' if q.get('only') == 'verified' else ''}{q.get('build') or q.get('version') or 'all'}.{ext}"
                data = (f"// {kind}\n// [TODO] 0x00401000 core::Func0000 (12 B)\n").encode() if ext == "txt" else b"PK\x05\x06" + b"\0" * 18
                self.send_response(200)
                self.send_header("Content-Type", "text/plain; charset=utf-8" if ext == "txt" else "application/zip")
                self.send_header("Content-Disposition", f'attachment; filename="{name}"')
                self.send_header("Content-Length", str(len(data)))
                self.end_headers()
                self.wfile.write(data)
                return
            if u.path == "/__calls":
                return self._json(CALLS)
        self._json({"ok": False, "error": "not found"}, 404)

    def do_POST(self):
        u = urlparse(self.path)
        length = int(self.headers.get("Content-Length") or 0)
        if u.path == "/api/scratch":            # fake decomp.me
            raw = self.rfile.read(length)
            with LOCK:
                CALLS.append((u.path, {"bytes": len(raw)}))
                if CONFIG["dme_browser_fail"]:
                    return self._json({"detail": "Service unavailable"}, 503)
                fields = {}
                text = raw.decode("latin-1")
                for name in ("compiler", "platform", "compiler_flags", "source_code"):
                    key = f'name="{name}"\r\n\r\n'
                    i = text.find(key)
                    if i >= 0:
                        fields[name] = text[i + len(key): text.find("\r\n--", i)]
                fields["has_target_obj"] = 'name="target_obj"' in text
                SCRATCHES.append(fields)
                slug = f"mock{len(SCRATCHES)}"
            return self._json({"slug": slug, "claim_token": "tok" + slug, "score": 10, "max_score": 100}, 201)
        body = json.loads(self.rfile.read(length) or b"{}")
        summary = {k: (v if k not in ("hex_data", "prompt", "cpp_code") else f"<{len(str(v))} chars>") for k, v in body.items()}
        with LOCK:
            CALLS.append((u.path, summary))
        if u.path == "/__reset":
            with LOCK:
                TASKS.clear(); TASKS.update(make_tasks()); USERS.clear(); AUDIT.clear(); CALLS.clear()
                GF["status"] = {"running": False, "phase": "", "done": 0, "total": 0, "files": 0, "label": "",
                                "message": "", "error": ""}
                GF["summary"] = None
                GF["files"] = {}
                GF["copy"] = None
                GF["movies"] = {}
                GF["textures"] = {"running": False, "phase": "", "written": 0, "made": False}
                GF["speed"] = {"cores": True, "gpu": True}
                CONFIG["blender"] = not body.get("no_blender")
                CONFIG["ffmpeg"] = not body.get("no_ffmpeg")
                CONFIG["model_error"] = bool(body.get("model_error"))
                CONFIG["gf_missing"] = bool(body.get("gf_missing"))
                CONFIG["gf_interrupted"] = bool(body.get("gf_interrupted"))
                DELAYS.update(body.get("delays", {}))
                CONFIG["lease_sec"] = int(body.get("lease_sec", LEASE_SEC))
                CONFIG["no_login"] = bool(body.get("no_login"))
                CONFIG["legacy_claim"] = bool(body.get("legacy_claim"))
                CONFIG["dme_browser_fail"] = bool(body.get("dme_browser_fail"))
                SCRATCHES.clear()
            return self._json({"ok": True})
        if u.path == "/api/login" and CONFIG["no_login"]:
            self.send_error(404)          # like portal/decomp_portal_server.py today
            return
        if u.path == "/api/login":
            with LOCK:
                user, pin = (body.get("user") or "").strip(), (body.get("pin") or "").strip()
                if not user or not pin:
                    return self._json({"ok": False, "error": "Handle and PIN required."})
                if USERS.setdefault(user, pin) != pin:
                    return self._json({"ok": False, "error": "Wrong PIN for this handle."})
                return self._json({"ok": True})
        if u.path == "/api/claim":
            with LOCK:
                expire_claims()
                user, err = auth(body)
                t = TASKS.get(body.get("id"))
                if err or not t:
                    return self._json({"ok": False, "error": err or "No such task."})
                if t["status"] == "CLAIMED" and t["claimed_by"] != user:
                    if CONFIG["legacy_claim"]:      # real server answers ok:true and leaves the claim alone
                        return self._json({"ok": True, "task": public_task(t)})
                    return self._json({"ok": False, "error": "Already claimed by " + t["claimed_by"], "task": public_task(t)})
                if t["status"] == "VERIFIED":
                    return self._json({"ok": False, "error": "Already verified.", "task": public_task(t)})
                t.update(status="CLAIMED", claimed_by=user, claim_expires_at=now() + CONFIG["lease_sec"])
                return self._json({"ok": True, "task": public_task(t)})
        if u.path == "/api/cancel":
            with LOCK:
                user, err = auth(body)
                t = TASKS.get(body.get("id"))
                if err or not t:
                    return self._json({"ok": False, "error": err or "No such task."})
                if t["status"] != "CLAIMED" or t["claimed_by"] != user:
                    return self._json({"ok": False, "error": "You do not hold this claim."})
                t.update(status="PARTIAL" if t["best_matched_bytes"] else "UNCLAIMED", claimed_by="", claim_expires_at=0)
                AUDIT.append({"action": "CHECKPOINT", "symbol": t["symbol"], "user": user, "va": t["va"],
                              "bytes": f"{t['best_matched_bytes']}/{t['size']} B", "time": time.strftime("%H:%M:%S")})
                return self._json({"ok": True, "task": public_task(t), "sources": SOURCES})
        if u.path == "/api/verify":
            time.sleep(DELAYS["verify"])
            with LOCK:
                user, err = auth(body)
                t = TASKS.get(body.get("id"))
                if err or not t:
                    return self._json({"ok": False, "error": err or "No such task."})
                if t["status"] != "VERIFIED" and (t["status"] != "CLAIMED" or t["claimed_by"] != user):
                    return self._json({"ok": False, "error": "Claim the function first."})
                code = body.get("cpp_code", "")
                if "COMPILE_ERROR" in code:
                    return self._json({"ok": False, "compiler_error": "submission.cpp(3) : error C2143: syntax error"})
                size = t["size"]
                exact = "MATCH_ALL" in code
                matched = size if exact else min(size - 1, 4 + len(code) % (size - 4))
                diff = [{"idx": k, "target": "90", "compiled": "90" if k < matched else "CC",
                         "status": "match" if k < matched else "diff"} for k in range(size)]
                promoted = False
                if matched >= t["best_matched_bytes"]:
                    t["best_matched_bytes"], t["best_pct"], t["best_code"], t["best_diff_details"] = matched, round(matched / size * 100, 1), code, diff
                if exact and t["status"] != "VERIFIED":
                    t.update(status="VERIFIED", claimed_by="", claim_expires_at=0)
                    if str(body.get("what") or "").strip():
                        t.update(what=" ".join(str(body["what"]).split())[:160], what_by=user)
                    AUDIT.append({"action": "VERIFIED", "symbol": t["symbol"], "user": user, "va": t["va"],
                                  "bytes": f"{size}/{size} B", "time": time.strftime("%H:%M:%S")})
                    promoted = True
                return self._json({"ok": True, "is_exact": exact, "matched_bytes": matched, "total_bytes": size,
                                   "match_percent": round(matched / size * 100, 1), "diff_details": diff,
                                   "compiled_hex": " ".join(d["compiled"] for d in diff), "progress": progress(),
                                   "leaderboard": leaderboard(), "sources": SOURCES, "task": public_task(t),
                                   "newly_promoted": promoted})
        if u.path == "/api/describe":
            with LOCK:
                user, err = auth(body)
                t = TASKS.get(body.get("id"))
                if err or not t:
                    return self._json({"ok": False, "error": err or "No such task."})
                if t["status"] != "VERIFIED":
                    return self._json({"ok": False, "error": "Only rebuilt functions can be described here."}, 409)
                t.update(what=" ".join(str(body.get("what") or "").split())[:160], what_by=user)
                return self._json({"ok": True, "task": public_task(t), "pending": 1})
        if u.path == "/api/fast-synthesize":
            time.sleep(DELAYS["fast"])
            t = TASKS.get(body.get("id"))
            return self._json({"ok": bool(t), "cpp_code": f"// synth\nvoid {t['symbol'].split('::')[-1]}() {{ int a; }}\n" if t else ""})
        if u.path == "/api/ai-proxy":
            if body.get("is_test"):
                return self._json({"ok": True, "used_model": body.get("model")})
            time.sleep(DELAYS["ai"])
            prompt = body.get("prompt", "")
            easy = "EasyFunc" in prompt.split("Function:")[1].split("\n")[0] if "Function:" in prompt else False
            if not easy and "Attempt 3:" in prompt:      # like a real model: it decides it can't get closer
                return self._json({"ok": True, "reply": "GIVE UP: the mock can't get any closer."})
            code = "// ai\nvoid f() { /* MATCH_ALL */ }" if easy else "// ai attempt\nvoid f() { int x = 1; }"
            return self._json({"ok": True, "reply": "Here you go:\n```cpp\n" + code + "\n```\n"})
        if u.path == "/api/decompme":
            with LOCK:
                t = TASKS.get(body.get("id", ""))
                if not t:
                    return self._json({"ok": False, "error": "Function not found."}, 404)
                if body.get("create"):
                    api = f"http://127.0.0.1:{self.server.server_address[1]}"
                    slug = "server1"
                    t["decompme_slug"] = slug
                    return self._json({"ok": True, "slug": slug, "url": f"{api}/scratch/{slug}",
                                       "claim_url": f"{api}/scratch/{slug}/claim?token=srv"})
                t["decompme_slug"] = str(body.get("slug", ""))
                return self._json({"ok": True})
        if u.path == "/api/game-files/start":
            versions = body.get("versions") or []
            if GF["status"].get("running"):
                return self._json({"ok": False, "error": "Already copying the game's files. Wait for it to finish or press Stop."}, 409)
            if not any(v["found"] and v["version"] in versions for v in GF_VERSIONS):
                return self._json({"ok": False, "error": "None of those versions were found in binaries/."}, 400)
            had = GF["copy"]
            same = (had and had["mode"] == body.get("mode") and had["folders"] == (body.get("folders") or "game")
                    and sorted(had["versions"]) == sorted(v["version"] for v in GF_VERSIONS
                                                          if v["found"] and v["version"] in versions))
            if same and not body.get("check") and not CONFIG.get("gf_interrupted"):
                return self._json({"ok": False, "up_to_date": True, "error": "Already copied with these choices: "
                                   "there's nothing to copy."}, 409)
            CONFIG["gf_interrupted"] = False
            GF["status"].update(running=True, phase="preparing", done=0, total=0, files=0, error="", stop=False,
                                message="")
            all_there = same and not CONFIG.get("gf_missing")
            threading.Thread(target=gf_run, args=(versions, body.get("mode", "unique"), body.get("folders", "game"),
                                                  all_there), daemon=True).start()
            return self._json({"ok": True, "status": {k: v for k, v in GF["status"].items() if k != "stop"}})
        if u.path == "/api/game-files/stop":
            GF["status"]["stop"] = True
            return self._json({"ok": True})
        if u.path == "/api/game-files/blender":
            if BLENDER["running"]:
                return self._json({"ok": False, "error": "Already exporting the city."}, 409)
            threading.Thread(target=blender_run, args=(str(body.get("version", "")),), daemon=True).start()
            return self._json(dict(BLENDER, ok=True, running=True, total=3))
        if u.path == "/api/game-files/blender-stop":
            return self._json({"ok": True})
        if u.path == "/api/game-files/open-in-blender":
            if not CONFIG.get("blender", True):
                return self._json({"ok": False, "need_blender": True, "error": "Couldn't find Blender on this computer. "
                                   "Install it from blender.org, or tell the portal where blender.exe is."}, 404)
            name = "PC city" if body.get("city") else (body.get("area") or body.get("path") or "x").split("/")[-1].split(".")[0]
            return self._json({"ok": True, "blender": "blender.exe", "files": 3 if body.get("city") else 1,
                               "saved": f"binaries/blender/PC/{'' if body.get('city') else 'Opened/'}{name}.blend"})
        if u.path == "/api/game-files/blender-path":
            if "blender" not in str(body.get("path", "")).lower():
                return self._json({"ok": False, "error": "That isn't Blender: pick blender.exe in the folder Blender is installed in."}, 400)
            CONFIG["blender"] = True
            return self._json({"ok": True, "path": body["path"]})
        if u.path == "/api/game-files/movie":
            if not CONFIG.get("ffmpeg", True):
                return self._json({"ok": False, "state": "error", "need_ffmpeg": True, "error": "Movies need FFmpeg, "
                                   "a free video tool."}, 424)
            path = str(body.get("path", ""))
            GF["movies"][path] = {"state": "converting", "progress": 0.0}

            def make():
                for i in range(1, 4):
                    time.sleep(0.4)
                    GF["movies"][path] = {"state": "converting", "progress": i / 4}
                GF["movies"][path] = {"state": "done", "progress": 1.0}
            threading.Thread(target=make, daemon=True).start()
            return self._json({"ok": True, "state": "converting", "progress": 0.0})
        if u.path == "/api/game-files/textures":
            st = GF["textures"]
            if st.get("running"):
                return self._json({"ok": False, "error": "Already exporting the textures."}, 409)

            def run():
                for phase, label, total in (("main", "PC", 4), ("other", "Xbox 2006 prototype", 2), ("writing", "", 1)):
                    for i in range(total):
                        st.update(phase=phase, label=label, done=i, total=total, written=st["written"] + 50)
                        time.sleep(0.5)
                st.update(running=False, phase="done", sharper=7, extra=172, made=True)
            st.update(running=True, phase="starting", written=0, done=0, total=0, error="", folder="binaries/textures")
            threading.Thread(target=run, daemon=True).start()
            return self._json(dict(st, ok=True))
        if u.path == "/api/game-files/speed":
            GF["speed"].update(cores=bool(body.get("use_cores")), gpu=bool(body.get("use_gpu")))
            return self._json({"ok": True})
        if u.path == "/api/game-files/textures-stop":
            return self._json({"ok": True})
        if u.path == "/api/game-files/ffmpeg-path":
            if "ffmpeg" not in str(body.get("path", "")).lower():
                return self._json({"ok": False, "error": "That isn't FFmpeg."}, 400)
            CONFIG["ffmpeg"] = True
            return self._json({"ok": True})
        if u.path == "/api/game-files/open" and str(body.get("folder", "")).startswith("blender:"):
            return self._json({"ok": True, "folder": "binaries/blender"})
        if u.path == "/api/game-files/open":
            folder = body.get("folder", "")
            known = ("", "shared", "best", "notpc", "xbox", "pc", "ps2", "prototype", "textures")
            if (folder not in known and not (folder.startswith("only:") and folder[5:] in known)) or not GF["summary"]:
                return self._json({"ok": False, "error": "That folder isn't there yet."}, 404)
            return self._json({"ok": True, "folder": "binaries/game_files"})
        if u.path == "/api/submit":
            user, err = auth(body)
            if err:
                return self._json({"ok": False, "error": err}, 403)
            done = {t["id"]: {"symbol": t["symbol"], "code": t.get("best_cpp") or "int f();", "verified_by": user}
                    for t in TASKS.values() if t["status"] == "VERIFIED"}
            if user == "Founder":
                return self._json({"ok": True, "mode": "pushed", "pending": 0, "message": f"Pushed {len(done)} verified functions to GitHub."})
            if not done:
                return self._json({"ok": True, "mode": "nothing", "pending": 0, "message": "Everything you matched is already on GitHub."})
            return self._json({"ok": True, "mode": "file", "count": len(done), "pending": len(done),
                               "filename": f"scarface-submission-{user}.json",
                               "bundle": {"format": "scarface-decomp-submission", "submitted_by": user, "entries": done}})
        if u.path == "/api/import-submission":
            user, err = auth(body)
            if err or user != "Founder":
                return self._json({"ok": False, "error": err or "Only maintainers can import submissions."}, 403)
            entries = (body.get("bundle") or {}).get("entries") or {}
            IMPORT.clear()
            IMPORT.update(running=False, total=len(entries), done=len(entries), added=max(0, len(entries) - 1),
                          already=0, failed=[{"symbol": "core::Bad", "reason": "4 of 12 bytes match"}] if entries else [], error="")
            return self._json({"ok": True, "started": True, "total": len(entries)})
        if u.path == "/api/git-sync":
            user, err = auth(body)
            return self._json({"ok": not err, "message": "Pushed 0 files.", "error": err})
        if u.path == "/api/upload-script":
            name = body.get("filename", "file.bin")
            size = len(body.get("hex_data", "")) // 2
            with LOCK:
                path = "uploads/" + name
                SCRIPTS[:] = [s for s in SCRIPTS if s["path"] != path] + [
                    {**_script(path, "uploads", code=f"// {name}"), "size": size, "format": "uploaded"}]
            return self._json(script_list(path))
        self._json({"ok": False, "error": "not found"}, 404)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", type=int, default=8765)
    args = ap.parse_args()
    srv = ThreadingHTTPServer(("127.0.0.1", args.port), Handler)
    print(f"Mock portal on http://127.0.0.1:{args.port}/")
    srv.serve_forever()


if __name__ == "__main__":
    main()
