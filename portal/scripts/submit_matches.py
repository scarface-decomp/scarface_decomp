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
import shlex
import sys
import urllib.error
import urllib.request
from pathlib import Path
from typing import Dict, Optional, Tuple

ROOT = Path(__file__).resolve().parents[2]
FOLDER = ROOT / "reports" / "to_submit"
QUEUE = ROOT / "reports" / "full_remaining_queue.json"
HEADER = re.compile(r"^//\s*(bin|va|what|how|spec|tool)\s*:\s*(.*?)\s*$", re.I)


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


def verify_options(text: str) -> Dict[str, str]:
    """--match and --flags from a '// verify: python portal/verify.py ...' line: a file whose function the
    portal can't pick by its own name (a template instantiation, a compiler helper) says which one it is."""
    m = re.search(r"^//\s*verify:\s*(.*)$", text, re.M)
    if not m:
        return {}
    try:
        words = shlex.split(m.group(1).split("   (")[0])
    except ValueError:
        return {}
    out = {}
    for flag, key in (("--match", "match"), ("--flags", "flags")):
        if flag in words[:-1]:
            out[key] = words[words.index(flag) + 1]
    return out


def submit(base: str, user: str, pin: str, path: Path) -> Tuple[bool, str]:
    """Claims and verifies one proposal. (accepted, what happened)."""
    text = path.read_text(encoding="utf-8")
    fields, code = read_proposal(text)
    tid = task_id(fields)
    if not tid:
        return False, "no '// bin:' and '// va:' lines at the top"
    task = call(base, "/api/task?id=" + tid)
    if not task.get("task"):
        return False, (f"the portal doesn't know {tid}: {task.get('error', 'no such function')} If it is a "
                       "newly listed function, close the portal, run python portal/tools/queue_builder.py and "
                       "start the portal again.")
    if task["task"].get("status") == "VERIFIED":
        return True, "already verified"
    claim = call(base, "/api/claim", {"user": user, "pin": pin, "id": tid})
    if claim.get("ok") is False:
        if recorded_meanwhile(base, tid):
            return True, "already verified (as a look-alike of one sent just before)"
        return False, "couldn't claim it: " + str(claim.get("error"))
    res = call(base, "/api/verify", {"user": user, "pin": pin, "id": tid, "cpp_code": code,
                                     "tool_used": fields.get("tool", "")[:120], "what": fields.get("what", "")[:160],
                                     "what_how": fields.get("how", ""),
                                     **verify_options(text)})
    if res.get("verified"):
        return True, f"verified, {res.get('total_bytes')} bytes"
    if recorded_meanwhile(base, tid):
        return True, "already verified (as a look-alike of one sent just before)"
    call(base, "/api/cancel", {"user": user, "pin": pin, "id": tid, "cpp_code": code})
    return False, res.get("error") or res.get("compiler_error") or f"not a match: {res.get('matched_bytes')} of {res.get('total_bytes')} bytes"


def recorded_meanwhile(base: str, tid: str) -> bool:
    """Whether the function is rebuilt now. While this script works through a folder, the portal matches the
    look-alikes of each function it records in the background (the same code at other addresses); one of
    them can be recorded between this script's look at it and its claim or its compile, and the portal then
    answers "Already verified." or "Your claim expired or was released while compiling." That is a
    success: the function is recorded, so its file can go."""
    task = call(base, "/api/task?id=" + tid).get("task") or {}
    return task.get("status") == "VERIFIED"


def queued_here(queue: Path = QUEUE) -> set:
    """The ids of the functions in this folder's work queue (empty when it has not been built yet)."""
    try:
        tasks = json.loads(queue.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        return set()
    return {t["id"] for t in tasks if isinstance(t, dict) and t.get("id")} if isinstance(tasks, list) else set()


def another_portal(base: str, files, here: set, root: Path = ROOT) -> Optional[str]:
    """What to do when the portal that answers is not the one of this folder, else None. Two copies of the
    project on one computer look the same in a browser, and a portal started before the work queue was
    rebuilt keeps its old list: either one answers "Function not found." for every file. This asks about one
    function this folder's work queue has; a portal that reads this folder's queue knows it."""
    for path in files:
        tid = task_id(read_proposal(path.read_text(encoding="utf-8"))[0])
        if not tid or tid not in here:
            continue
        if call(base, "/api/task?id=" + tid).get("task"):
            return None
        total = call(base, "/api/queue?limit=1").get("total")
        empty = " It has no functions at all: it runs from a copy of the project without the game files." if total == 0 else ""
        return (f"The portal answering at {base} is not this folder's: it doesn't know {tid}, which this folder's "
                f"work queue has.{empty}\n"
                "It was started from another copy of the project, or before the work queue was last rebuilt.\n"
                f"Close every portal window, then start the one in this folder: {root / 'START_PORTAL.bat'}\n"
                "Nothing was sent; the files are still in " + str(files[0].parent))
    return None


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
    wrong = another_portal(args.portal, files, queued_here())
    if wrong:
        print(wrong)
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
