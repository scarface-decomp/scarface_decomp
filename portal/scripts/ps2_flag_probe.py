#!/usr/bin/env python3
"""
Find out how a part of the PS2 game was built: compile one function's C++ with several optimisation
settings and say how close each gets to the game's bytes.

    python portal/scripts/ps2_flag_probe.py                       the two built-in questions (below)
    python portal/scripts/ps2_flag_probe.py FILE.cpp --va 0x003EB610
    python portal/scripts/ps2_flag_probe.py FILE.cpp --va 0x003EB610 --flags "-O4,p -lang c++ -str readonly"

The portal must be running and your decomp.me tab connected (docs/PS2.md). Nothing is recorded: a probe
only compiles and compares. It is light on decomp.me: one compile per flag set, two seconds apart, at most
twelve flag sets a call, and a text already compiled with the same flags is not compiled again.

The two built-in questions come from the first PS2 easy-pass runs (November 2026):

* 0x003EB610 sets up two arguments and jumps into another function. With the lane's flags the compiler
  makes an ordinary call instead. Which setting turns the call into a jump?
* 0x00392940 stores a float and returns 1, with the store first. With the lane's flags the compiler puts
  the store last. Which setting keeps the store first?

It asks for your handle and PIN (the PIN isn't shown, stored or printed).
"""

from __future__ import annotations

import argparse
import getpass
import json
import sys
import urllib.error
import urllib.request
from pathlib import Path

TAIL = " -lang c++ -str readonly"
FLAG_SETS = [o + TAIL for o in ("-O3", "-O3,p", "-O3,s", "-O4", "-O4,p", "-O4,s", "-O2", "-O2,p",
                                "-O3 -opt speed", "-O3 -opt space", "-O4,p -inline auto", "-O3 -schedule off")]

BUILT_IN = [
    (0x003EB610, "a call as the last statement (the game jumps)",
     'extern int D_00808F50;\nextern int D_00808F54;\nextern "C" void func_006E3100(int*, int*);\n\n'
     "void Forward()\n{\n    func_006E3100(&D_00808F50, &D_00808F54);\n}\n"),
    (0x00392940, "a float stored, then 1 returned (the game stores first)",
     "class Object\n{\npublic:\n    bool Set(float value);\n    char m_pad00[0xC];\n    float m_FieldC; // +0xC\n};\n\n"
     "bool Object::Set(float value)\n{\n    m_FieldC = value;\n    return true;\n}\n"),
]


def call(base: str, path: str, body: dict) -> dict:
    req = urllib.request.Request(base + path, data=json.dumps(body).encode(), headers={"Content-Type": "application/json"})
    try:
        with urllib.request.urlopen(req, timeout=600) as r:
            return json.loads(r.read().decode("utf-8", "replace"))
    except urllib.error.HTTPError as e:
        try:
            return json.loads(e.read().decode("utf-8", "replace"))
        except ValueError:
            return {"ok": False, "error": f"the portal answered {e.code}"}


def words(hex_text: str) -> str:
    """Compiled bytes as 32-bit instruction words, the way the portal's disassembly shows them."""
    b = bytes.fromhex(hex_text.replace(" ", "")) if hex_text else b""
    return " ".join(f"{int.from_bytes(b[i:i + 4], 'little'):08X}" for i in range(0, len(b) - len(b) % 4, 4))


def show(what: str, va: int, res: dict) -> bool:
    print(f"\n0x{va:08X}: {what}")
    if not res.get("ok"):
        print("  " + (res.get("error") or "the portal could not do it"))
    hit = False
    for row in res.get("rows", []):
        if not row["compiled"]:
            print(f"  {row['flags']:<44} did not compile: {row['error'].splitlines()[0] if row['error'] else ''}")
            continue
        mark = "MATCH" if row["verified"] else ("same bytes, an address unchecked" if row["exact"] else "")
        hit = hit or row["exact"]
        print(f"  {row['flags']:<44} {row['matched_bytes']:>3}/{row['total_bytes']} bytes, compiled {row['compiled_size']:>3} B  {mark}")
        print(f"      {words(row['compiled_hex'])}")
    return hit


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("file", nargs="?", help="a C++ file to probe with (default: the two built-in questions)")
    ap.add_argument("--va", help="the PS2 function's address, with a file")
    ap.add_argument("--flags", action="append", help="a flag set to try (repeatable; default: twelve usual ones)")
    ap.add_argument("--portal", default="http://127.0.0.1:8085", help="where your portal is running")
    args = ap.parse_args()
    if bool(args.file) != bool(args.va):
        ap.error("give a file and --va together, or neither")
    cases = BUILT_IN if not args.file else [(int(args.va, 16), args.file, Path(args.file).read_text(encoding="utf-8"))]
    sets = args.flags or FLAG_SETS
    user = input("Your handle: ").strip()
    creds = {"user": user, "pin": getpass.getpass("Your PIN (not shown): ")}
    print(f"Trying {len(sets)} flag set(s) on {len(cases)} function(s): about {len(sets) * len(cases) * 3} seconds.")
    any_hit = False
    for va, what, code in cases:
        try:
            res = call(args.portal, "/api/ps2-probe", dict(creds, id=f"ps2_{va:08X}", cpp_code=code, flag_sets=sets))
        except OSError:
            print("The portal isn't answering at", args.portal, "- start it (START_PORTAL.bat) and try again.")
            return 1
        any_hit = show(what, va, res) or any_hit
        if res.get("not_connected"):
            return 1
    print("\nA flag set that says MATCH is how that part of the game was built." if any_hit else
          "\nNo flag set gave the game's bytes. The lines above still show what each one changed.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
