#!/usr/bin/env python3
"""
Mock backend for website_kit/index.html, for front-end work without cl.exe or the game binaries.

    python3 tools/mock_portal_api.py --port 8765
    open http://127.0.0.1:8765/

It implements the same JSON endpoints the page calls (/api/state, /api/queue, /api/task,
/api/login, /api/claim, /api/cancel, /api/verify, /api/fast-synthesize, /api/ai-proxy,
/api/git-sync, /api/scripts, /api/upload-script) with fake data:

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
CONFIG = {"lease_sec": LEASE_SEC, "no_login": False, "legacy_claim": False}
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
            "starter_cpp": f"// starter for {tid}\nvoid Func{i:04d}() {{}}\n",
            "best_code": "",
        }
    return tasks


TASKS = make_tasks()
USERS: dict = {}
AUDIT: list = []
SOURCES = {"Original_Binary_Order_PC_1002.cpp": "// VERIFIED 1:1 MATCH\nvoid a() {}\n",
           "core/DriveThread.cpp": "// VERIFIED 1:1 MATCH\nvoid b() {}\n"}
SCRIPTS = [{"name": "init.cso", "ext": "cso", "size": 128, "format": "TorqueScript bytecode",
            "opcode_count": 12, "decompiled_code": "function init() {}", "disasm": "0000 FUNC_DECL"}]


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
                                   "repo_url": "https://github.com/example-org/scarface_decomp"})
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
                return self._json({"ok": True, "files": SCRIPTS})
            if u.path == "/__calls":
                return self._json(CALLS)
        self._json({"ok": False, "error": "not found"}, 404)

    def do_POST(self):
        u = urlparse(self.path)
        length = int(self.headers.get("Content-Length") or 0)
        body = json.loads(self.rfile.read(length) or b"{}")
        summary = {k: (v if k not in ("hex_data", "prompt", "cpp_code") else f"<{len(str(v))} chars>") for k, v in body.items()}
        with LOCK:
            CALLS.append((u.path, summary))
        if u.path == "/__reset":
            with LOCK:
                TASKS.clear(); TASKS.update(make_tasks()); USERS.clear(); AUDIT.clear(); CALLS.clear()
                DELAYS.update(body.get("delays", {}))
                CONFIG["lease_sec"] = int(body.get("lease_sec", LEASE_SEC))
                CONFIG["no_login"] = bool(body.get("no_login"))
                CONFIG["legacy_claim"] = bool(body.get("legacy_claim"))
            return self._json({"ok": True})
        if u.path == "/api/login" and CONFIG["no_login"]:
            self.send_error(404)          # like decomp_portal_server.py today
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
        if u.path == "/api/git-sync":
            user, err = auth(body)
            return self._json({"ok": not err, "message": "Pushed 0 files.", "error": err})
        if u.path == "/api/upload-script":
            name = body.get("filename", "file.bin")
            size = len(body.get("hex_data", "")) // 2
            with LOCK:
                SCRIPTS[:] = [s for s in SCRIPTS if s["name"] != name] + [{
                    "name": name, "ext": name.rsplit(".", 1)[-1], "size": size, "format": "uploaded",
                    "opcode_count": 1, "decompiled_code": f"// {name}", "disasm": "0000 ?"}]
            return self._json({"ok": True, "files": SCRIPTS, "selected": name})
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
