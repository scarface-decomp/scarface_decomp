#!/usr/bin/env python3
"""
Find out how the PS2 game was built: compile one function's C++ with every build of its compiler, and
with several optimisation settings, and say how close each gets to the game's bytes.

    python portal/scripts/ps2_flag_probe.py                       the two built-in questions (below)
    python portal/scripts/ps2_flag_probe.py FILE.cpp --va 0x003EB610
    python portal/scripts/ps2_flag_probe.py FILE.cpp --va 0x003EB610 --flags "-O4,p -lang c++ -str readonly"
    python portal/scripts/ps2_flag_probe.py FILE.cpp --va 0x003EB610 --compiler mwcps2-3.0.1b87-031208

The portal must be running and your decomp.me tab connected (docs/PS2.md). Nothing is recorded: a probe
only compiles and compares. It is light on decomp.me: one compile per line, two seconds apart, and a text
already compiled with the same build and flags is not compiled again. Without arguments it tries all 23
builds with the lane's flags, then the lane's build with 11 other settings: 34 compiles a function.

The two built-in questions come from the first PS2 easy-pass runs (November 2026):

* 0x003EB610 sets up two arguments and jumps into another function. With the lane's build and flags the
  compiler makes an ordinary call instead. What turns the call into a jump?
* 0x00392940 stores a float and returns 1, with the store first. The lane's build and flags put the store
  last. What keeps it first?

The game does both everywhere (1,772 functions end in such a jump, in every part of the code; the examiner's
census, November 2026), so the answer is one build or one setting for the whole game.

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
LANE_COMPILER, LANE_FLAGS = "mwcps2-3.0.1b103-040528", "-O3" + TAIL
FLAG_SETS = [o + TAIL for o in ("-O3,p", "-O3,s", "-O4", "-O4,p", "-O4,s", "-O2", "-O2,p", "-O3 -opt speed",
                                "-O3 -opt space", "-O4,p -inline auto", "-O3 -schedule off")]
# Every CodeWarrior for PS2 build decomp.me has, oldest first (the same list as portal/tools/ps2_verify.py BUILDS).
BUILDS = ["mwcps2-2.3-991202", "mwcps2-2.3.3-000906", "mwcps2-2.4-001213", "mwcps2-3.0-011126", "mwcps2-3.0.1-020123",
          "mwcps2-3.0.3-020716", "mwcps2-3.0b22-020926", "mwcps2-3.0b38-030307", "mwcps2-3.0.1b44-030325",
          "mwcps2-3.0.1b51-030512", "mwcps2-3.0b50-030527", "mwcps2-3.0b52-030722", "mwcps2-3.0.1b74-030811",
          "mwcps2-3.0.1b75-030916", "mwcps2-3.0.1b87-031208", "mwcps2-3.0.1b95-040309", "mwcps2-3.0.1b103-040528",
          "mwcps2-3.0.1b119-040914", "mwcps2-3.0.1b145-050209", "mwcps2-3.0.1b151-050317", "mwcps2-3.0.1b198-051011",
          "mwcps2-3.0.1b205-051227", "mwcps2-3.0.1b210-060308"]
CHUNK = 12                    # the portal takes at most this many compiles a call


def default_tries() -> list:
    """Every build with the lane's flags (is the compiler right?), then the lane's build with other
    optimisation settings (are the flags right?)."""
    return ([{"compiler": b, "flags": LANE_FLAGS} for b in BUILDS]
            + [{"compiler": LANE_COMPILER, "flags": f} for f in FLAG_SETS])


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


def show(rows: list) -> bool:
    hit = False
    for row in rows:
        label = f"{row['compiler'].replace('mwcps2-', ''):<18} {row['flags']}"
        if not row["compiled"]:
            print(f"  {label:<62} did not compile: {row['error'].splitlines()[0] if row['error'] else ''}")
            continue
        mark = "MATCH" if row["verified"] else ("same bytes, an address unchecked" if row["exact"] else "")
        hit = hit or row["exact"]
        print(f"  {label:<62} {row['matched_bytes']:>3}/{row['total_bytes']} bytes, compiled {row['compiled_size']:>3} B  {mark}")
        print(f"      {words(row['compiled_hex'])}")
    return hit


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("file", nargs="?", help="a C++ file to probe with (default: the two built-in questions)")
    ap.add_argument("--va", help="the PS2 function's address, with a file")
    ap.add_argument("--flags", action="append", help="a flag set to try (repeatable)")
    ap.add_argument("--compiler", action="append", help="a build to try, e.g. mwcps2-3.0.1b87-031208 (repeatable)")
    ap.add_argument("--portal", default="http://127.0.0.1:8085", help="where your portal is running")
    args = ap.parse_args()
    if bool(args.file) != bool(args.va):
        ap.error("give a file and --va together, or neither")
    cases = BUILT_IN if not args.file else [(int(args.va, 16), args.file, Path(args.file).read_text(encoding="utf-8"))]
    if args.flags or args.compiler:
        tries = [{"compiler": c, "flags": f} for c in (args.compiler or [LANE_COMPILER]) for f in (args.flags or [LANE_FLAGS])]
    else:
        tries = default_tries()
    user = input("Your handle: ").strip()
    creds = {"user": user, "pin": getpass.getpass("Your PIN (not shown): ")}
    n = len(tries) * len(cases)
    print(f"{len(tries)} compile(s) on each of {len(cases)} function(s): about {n * 3 // 60 + 1} minute(s). "
          "Leave your decomp.me tab open.")
    hits = []
    for va, what, code in cases:
        print(f"\n0x{va:08X}: {what}")
        for i in range(0, len(tries), CHUNK):
            try:
                res = call(args.portal, "/api/ps2-probe", dict(creds, id=f"ps2_{va:08X}", cpp_code=code, tries=tries[i:i + CHUNK]))
            except OSError:
                print("The portal isn't answering at", args.portal, "- start it (START_PORTAL.bat) and try again.")
                return 1
            if show(res.get("rows", [])):
                hits.append(va)
            if not res.get("ok"):
                print("  " + (res.get("error") or "the portal could not do it"))
                return 1
    print("\nA line that says MATCH is the build and flags that part of the game was made with." if hits else
          "\nNothing gave the game's bytes. The lines above still show what each build and setting changed.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
