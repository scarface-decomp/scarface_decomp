#!/usr/bin/env python3
"""Send prepared matches to your local portal, so it compiles, checks and records them under your name.

A match written away from the portal (by an AI working from a clean-room spec, say) is only a proposal:
the portal is the one thing that can record a function as verified. Each proposal is a .cpp file in
reports/to_submit/ that starts with a few comment lines:

    // bin: xb
    // va: 0x00243FA0
    // what: The game's name key: h = (h * 65599) & 0x7FFFFFFF, each character folded and XORed in.
    // spec: docs/cleanroom/SPEC-006-lights-placed-props-reflection.md section 5
    // tool: Claude

then the C++ itself. With the portal running:

    python portal/scripts/submit_matches.py

It asks for your handle and PIN (the PIN isn't shown, stored or printed), claims each function, has the
portal verify it, and deletes the files the portal accepted. A file the portal doesn't accept is left
where it is, with the reason. Standard library only.
"""

from __future__ import annotations

import argparse
import getpass
import json
import re
import sys
import urllib.error
import urllib.request
from pathlib import Path
from typing import Dict, Optional, Tuple

ROOT = Path(__file__).resolve().parents[2]
FOLDER = ROOT / "reports" / "to_submit"
HEADER = re.compile(r"^//\s*(bin|va|what|spec|tool)\s*:\s*(.*?)\s*$", re.I)


def read_proposal(text: str) -> Tuple[Dict[str, str], str]:
    """A proposal's header fields (bin, va, what, spec, tool) and the whole C++ text."""
    fields: Dict[str, str] = {}
    for line in text.splitlines():
        m = HEADER.match(line)
        if m:
            fields.setdefault(m.group(1).lower(), m.group(2))
        elif line.strip() and not line.lstrip().startswith("//"):
            break
    return fields, text


def task_id(fields: Dict[str, str]) -> Optional[str]:
    """The portal's id for the function: its program and address (xb_00243FA0)."""
    try:
        va = int(fields["va"], 16)
    except (KeyError, ValueError):
        return None
    which = fields.get("bin", "").lower()
    return f"{which}_{va:08X}" if which else None


def call(base: str, path: str, body: Optional[dict] = None) -> dict:
    req = urllib.request.Request(base + path, data=json.dumps(body).encode() if body is not None else None,
                                 headers={"Content-Type": "application/json"} if body is not None else {})
    try:
        with urllib.request.urlopen(req, timeout=300) as r:
            return json.loads(r.read().decode("utf-8", "replace"))
    except urllib.error.HTTPError as e:
        try:
            return json.loads(e.read().decode("utf-8", "replace"))
        except ValueError:
            return {"ok": False, "error": f"the portal answered {e.code}"}


def submit(base: str, user: str, pin: str, path: Path) -> Tuple[bool, str]:
    """Claims and verifies one proposal. (accepted, what happened)."""
    fields, code = read_proposal(path.read_text(encoding="utf-8"))
    tid = task_id(fields)
    if not tid:
        return False, "no '// bin:' and '// va:' lines at the top"
    task = call(base, "/api/task?id=" + tid)
    if not task.get("task"):
        return False, f"the portal doesn't know {tid}: {task.get('error', 'no such function')}"
    if task["task"].get("status") == "VERIFIED":
        return True, "already verified"
    claim = call(base, "/api/claim", {"user": user, "pin": pin, "id": tid})
    if claim.get("ok") is False:
        return False, "couldn't claim it: " + str(claim.get("error"))
    res = call(base, "/api/verify", {"user": user, "pin": pin, "id": tid, "cpp_code": code,
                                     "tool_used": fields.get("tool", "")[:120], "what": fields.get("what", "")[:160]})
    if res.get("verified"):
        return True, f"verified, {res.get('total_bytes')} bytes"
    call(base, "/api/cancel", {"user": user, "pin": pin, "id": tid, "cpp_code": code})
    return False, res.get("error") or f"not a match: {res.get('matched_bytes')} of {res.get('total_bytes')} bytes"


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--portal", default="http://127.0.0.1:8085", help="where your portal is running")
    ap.add_argument("--folder", default=str(FOLDER))
    args = ap.parse_args()
    files = sorted(Path(args.folder).glob("*.cpp"))
    if not files:
        print("Nothing to send: no .cpp files in", args.folder)
        return 0
    try:
        call(args.portal, "/api/queue?limit=10")
    except OSError:
        print("The portal isn't answering at", args.portal, "- start it (START_PORTAL.bat) and try again.")
        return 1
    user = input("Your handle: ").strip()
    pin = getpass.getpass("Your PIN (not shown): ")
    failed = 0
    for path in files:
        ok, said = submit(args.portal, user, pin, path)
        print(("  ok   " if ok else "  NO   ") + path.name + ": " + said)
        if ok:
            path.unlink()
        else:
            failed += 1
    print(f"{len(files) - failed} of {len(files)} recorded. Commit reports/ and reconstructed_src/ as the portal left them.")
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
