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
  * The fake AI returns MATCH_ALL code for functions whose symbol contains "Easy".
  * Login accepts any handle; the first PIN used for a handle becomes its PIN.
"""

from __future__ import annotations

import argparse
import json
import os
import threading
import time
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from urllib.parse import parse_qs, urlparse

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "website_kit"))
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
                       "error": ""}, "summary": None, "files": {}}


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
    labels = {"unique": "No duplicates", "every": "Every version complete", "best": "Best version of each file"}
    out = {"mode": mode, "mode_label": labels.get(mode, mode), "folders": folders,
           "created": "2026-11-09 09:30", "versions": {}}
    for v in GF_VERSIONS:
        if not v["found"]:
            continue
        rows = gf_fake_files(v["version"])
        for i, r in enumerate(rows):
            r["picked"] = mode == "best" and (v["version"] == "pc" or r["status"] == "only")
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
    if mode == "best":
        out["best"] = {"files": sum(x["picked"] for x in out["versions"].values()),
                       "from": {k: x["picked"] for k, x in out["versions"].items()}}
    return out


def gf_run(versions, mode, folders="game"):
    total = sum(v["size"] for v in GF_VERSIONS if v["found"] and v["version"] in versions)
    st = GF["status"]
    for i in range(1, 11):
        time.sleep(0.15)
        with LOCK:
            if st.get("stop"):
                st.update(running=False, phase="stopped", stop=False,
                          message="Stopped. Press Copy again to carry on where it left off.")
                return
            st.update(phase="reading", label="Xbox" if i < 5 else "PS2", done=total * i // 10, total=total, files=i * 1234)
    with LOCK:
        st.update(phase="placing")
    time.sleep(0.2)
    with LOCK:
        GF["summary"] = gf_summary(mode, folders)
        st.update(running=False, phase="done", message="Done")


class Handler(BaseHTTPRequestHandler):
    def log_message(self, *a):
        pass

    def _json(self, obj, code=200):
        data = json.dumps(obj).encode()
        self.send_response(code)
        self.send_header("Content-Type", "application/json")
        self.send_header("Content-Length", str(len(data)))
        self.end_headers()
        self.wfile.write(data)

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
                                   "free": 128 * 2**30, "summary": GF["summary"],
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
                off, lim = int(q.get("offset", 0)), int(q.get("limit", 200))
                return self._json({"ok": True, "total": len(rows), "offset": off, "files": rows[off:off + lim]})
            if u.path == "/api/queue":
                items = list(TASKS.values())
                lane, tier, query = q.get("lane", "ALL"), q.get("tier", "ALL"), q.get("q", "").lower()
                if lane in ("UNCLAIMED", "CLAIMED", "VERIFIED", "PARTIAL"):
                    items = [t for t in items if t["status"] == lane]
                if tier != "ALL":
                    items = [t for t in items if t["tier"] == tier]
                if query:
                    items = [t for t in items if query in t["symbol"].lower() or query in t["va"].lower()]
                page, limit = int(q.get("page", 1)), int(q.get("limit", 80))
                sl = items[(page - 1) * limit: page * limit]
                return self._json({"total": len(items), "items": [
                    {**{k: t[k] for k in ("id", "symbol", "va", "size", "status", "claimed_by", "best_matched_bytes", "best_pct", "est_label")},
                     "claim_remaining_sec": max(0, t["claim_expires_at"] - now()) if t["status"] == "CLAIMED" else None}
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
                    AUDIT.append({"action": "VERIFIED", "symbol": t["symbol"], "user": user, "va": t["va"],
                                  "bytes": f"{size}/{size} B", "time": time.strftime("%H:%M:%S")})
                    promoted = True
                return self._json({"ok": True, "is_exact": exact, "matched_bytes": matched, "total_bytes": size,
                                   "match_percent": round(matched / size * 100, 1), "diff_details": diff,
                                   "compiled_hex": " ".join(d["compiled"] for d in diff), "progress": progress(),
                                   "leaderboard": leaderboard(), "sources": SOURCES, "task": public_task(t),
                                   "newly_promoted": promoted})
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
            GF["status"].update(running=True, phase="preparing", done=0, total=0, files=0, error="", stop=False)
            threading.Thread(target=gf_run, args=(versions, body.get("mode", "unique"), body.get("folders", "game")),
                             daemon=True).start()
            return self._json({"ok": True, "status": {k: v for k, v in GF["status"].items() if k != "stop"}})
        if u.path == "/api/game-files/stop":
            GF["status"]["stop"] = True
            return self._json({"ok": True})
        if u.path == "/api/game-files/open":
            folder = body.get("folder", "")
            known = ("", "shared", "best", "xbox", "pc", "ps2", "prototype")
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
