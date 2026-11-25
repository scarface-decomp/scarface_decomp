#!/usr/bin/env python3
"""
Find out how the PS2 game was built: compile one function's C++ with every build of its compiler, and
with several optimisation settings, and say how close each gets to the game's bytes.

    python portal/scripts/ps2_flag_probe.py                       the current round of questions (below)
    python portal/scripts/ps2_flag_probe.py --sweep               the first two questions, every optimisation setting
    python portal/scripts/ps2_flag_probe.py FILE.cpp --va 0x003EB610
    python portal/scripts/ps2_flag_probe.py FILE.cpp --va 0x003EB610 --flags "-O4,p -lang c++ -str readonly -Cpp_exceptions off"
    python portal/scripts/ps2_flag_probe.py FILE.cpp --va 0x003EB610 --compiler mwcps2-3.0.1b87-031208

The portal must be running and your decomp.me tab connected (docs/PS2.md). Nothing is recorded: a probe
only compiles and compares. It is light on decomp.me: one compile per line, two seconds apart, and a text
already compiled with the same build and flags is not compiled again.

The first two questions came from the first PS2 easy-pass runs (November 2026):

* 0x003EB610 sets up two arguments and jumps into another function. Answered on 25 November 2026: with
  C++ exceptions on the compiler makes an ordinary call; `-Cpp_exceptions off` makes the jump, and is now
  one of the lane's flags.
* 0x00392940 stores a float and returns 1, with the store first. The lane's build puts the store last with
  every optimisation setting, the scheduler and the peephole pass off among them. Open.

The game does both everywhere (1,772 functions end in such a jump, in every part of the code; the examiner's
census, November 2026), so the answer is one build or one setting for the whole game.

Without arguments the probe runs the current round (ROUND, below): 32 compiles that ask whether the 3.0 line
of builds, which do store the float first, could be the game's compiler after all, and whether a `#pragma` or
another way of writing it changes the lane's own build, and what the easy pass's first jump shape compiles to. `--sweep` runs the first two questions with the lane's
build and 16 other settings; `--all-builds` adds the other 22 builds with the lane's flags.

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

TAIL = " -lang c++ -str readonly -Cpp_exceptions off"
LANE_COMPILER, LANE_FLAGS = "mwcps2-3.0.1b103-040528", "-O3" + TAIL
# Optimisation levels, then what the compiler's own help says level 3 adds ("instruction scheduling, tail call
# optimization") and the peephole pass switched off one at a time, RTTI off, and the lane's flags as they were
# before C++ exceptions were turned off (the first run's answer to the first question).
FLAG_SETS = [o + TAIL for o in ("-O3,p", "-O3,s", "-O4", "-O4,p", "-O4,s", "-O2", "-O2,p", "-O3 -opt speed",
                                "-O3 -opt space", "-O4,p -inline auto")]
FLAG_SETS += ["-O3" + TAIL + x for x in (" -opt noschedule", " -opt nopeephole", " -RTTI off",
                                         " -RTTI off -opt noschedule")]
FLAG_SETS += ["-O4,p" + TAIL + " -opt noschedule", "-O3 -lang c++ -str readonly"]
# Every CodeWarrior for PS2 build decomp.me has, oldest first (the same list as portal/tools/ps2_verify.py BUILDS).
BUILDS = ["mwcps2-2.3-991202", "mwcps2-2.3.3-000906", "mwcps2-2.4-001213", "mwcps2-3.0-011126", "mwcps2-3.0.1-020123",
          "mwcps2-3.0.3-020716", "mwcps2-3.0b22-020926", "mwcps2-3.0b38-030307", "mwcps2-3.0.1b44-030325",
          "mwcps2-3.0.1b51-030512", "mwcps2-3.0b50-030527", "mwcps2-3.0b52-030722", "mwcps2-3.0.1b74-030811",
          "mwcps2-3.0.1b75-030916", "mwcps2-3.0.1b87-031208", "mwcps2-3.0.1b95-040309", "mwcps2-3.0.1b103-040528",
          "mwcps2-3.0.1b119-040914", "mwcps2-3.0.1b145-050209", "mwcps2-3.0.1b151-050317", "mwcps2-3.0.1b198-051011",
          "mwcps2-3.0.1b205-051227", "mwcps2-3.0.1b210-060308"]
CHUNK = 12                    # the portal takes at most this many compiles a call


def default_tries(all_builds: bool = False) -> list:
    """The lane's build with its own flags and with every other setting (are the flags right?); with
    all_builds, every other build with the lane's flags first (is the compiler right?)."""
    builds = [{"compiler": b, "flags": LANE_FLAGS} for b in BUILDS if b != LANE_COMPILER] if all_builds else []
    return builds + [{"compiler": LANE_COMPILER, "flags": f} for f in [LANE_FLAGS] + FLAG_SETS]


TAIL_CALL = ('extern int D_00808F50;\nextern int D_00808F54;\nextern "C" void func_006E3100(int*, int*);\n\n'
             "void Forward()\n{\n    func_006E3100(&D_00808F50, &D_00808F54);\n}\n")
FLOAT_CLASS = "class Object\n{\npublic:\n    %s Set(float value);\n    char m_pad00[0xC];\n    float m_FieldC; // +0xC\n};\n\n"
FLOAT_STORE = FLOAT_CLASS % "bool" + "bool Object::Set(float value)\n{\n    m_FieldC = value;\n    return true;\n}\n"
DOT = ("struct Vector3\n{\n    float x, y, z;\n};\n\n"
       "float Dot(const Vector3* a, const Vector3* b)\n{\n    return a->x * b->x + a->y * b->y + a->z * b->z;\n}\n")

BUILT_IN = [
    (0x003EB610, "a call as the last statement (the game jumps)", TAIL_CALL),
    (0x00392940, "a float stored, then 1 returned (the game stores first)", FLOAT_STORE),
]

# The round of 25 November 2026. The float store comes first only in the 3.0 line of builds (3.0.3, 3.0 builds 38,
# 50 and 52), which were ruled out because they "never write madda.s chains". But every build has a setting
# called usefloatacc, so that may only have been their default. Three questions, one compile a line:
#   1. do the 3.0-line builds make the jump and the store-first order with the lane's flags?
#   2. do they write the game's multiply-accumulate chain (0x0066DFF0, a dot product) with a setting turned on?
#   3. does a setting or another way of writing it make the lane's own build store the float first?
OLD_LINE = ["mwcps2-3.0.3-020716", "mwcps2-3.0b38-030307", "mwcps2-3.0b50-030527", "mwcps2-3.0b52-030722"]


def on(builds: list) -> list:
    return [{"compiler": b, "flags": LANE_FLAGS} for b in builds]


def pragma(*names: str) -> str:
    return "".join(f"#pragma {n}\n" for n in names) + "\n"


ROUND = (
    [(0x003EB610, "the jump, on the 3.0-line builds", TAIL_CALL, on(OLD_LINE)),
     (0x00392940, "the float store, on the 3.0-line builds", FLOAT_STORE, on(OLD_LINE)),
     (0x0066DFF0, "a dot product (the game writes mula.s, madda.s, madd.s)", DOT,
      on([LANE_COMPILER, "mwcps2-3.0.1b87-031208"] + OLD_LINE))]
    + [(0x0066DFF0, f"the dot product with #pragma {' and '.join(n)}", pragma(*n) + DOT, on(OLD_LINE[2:]))
       for n in (("usefloatacc on",), ("fastmath on",), ("usefloatacc on", "fastmath on"))]
    + [(0x00392940, f"the float store with #pragma {n}", pragma(n) + FLOAT_STORE, on([LANE_COMPILER]))
       for n in ("schedule off", "peephole off", "usefloatacc off", "fastmath on", "memoryrewrite off",
                 "conditional_move off")]
    + [(0x00392940, "the float store, returning int", FLOAT_CLASS % "int"
        + "int Object::Set(float value)\n{\n    m_FieldC = value;\n    return 1;\n}\n", on([LANE_COMPILER])),
       (0x00392940, "the float store, written as one expression", FLOAT_CLASS % "bool"
        + "bool Object::Set(float value)\n{\n    return (m_FieldC = value, true);\n}\n", on([LANE_COMPILER])),
       (0x00392940, "the float store, as a plain function", "struct Object\n{\n    char m_pad00[0xC];\n    float m_FieldC;\n};\n\n"
        "int Set(Object* object, float value)\n{\n    object->m_FieldC = value;\n    return 1;\n}\n", on([LANE_COMPILER]))]
    # 4. The easy pass's first run with exceptions off: the jump shape it tried first (a global read from its
    #    full address, then the jump) failed four times. What does that text compile to? And two other ways.
    + [(0x0038EC30, "a jump after reading a global, as the easy pass writes it",
        'extern int D_0081DFE8[];\nextern "C" void func_0047EEF0(int);\n\n'
        "void Forward()\n{\n    func_0047EEF0(D_0081DFE8[0]);\n}\n", on([LANE_COMPILER])),
       (0x0038EC30, "that jump, with the global as a pointer to an object",
        'struct Manager;\nextern Manager* D_0081DFE8;\nextern "C" void func_0047EEF0(Manager*);\n\n'
        "void Forward()\n{\n    func_0047EEF0(D_0081DFE8);\n}\n", on([LANE_COMPILER])),
       (0x0037DBF0, "a jump passing the object, one of its members and a zero",
        'extern "C" void func_0039A050(void*, int, int);\n\n'
        "class Object\n{\npublic:\n    void Forward();\n    char m_pad00[0xD0];\n    int m_FieldD0; // +0xD0\n};\n\n"
        "void Object::Forward()\n{\n    func_0039A050(this, m_FieldD0, 0);\n}\n", on([LANE_COMPILER]))]
)


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


REPORT = Path(__file__).resolve().parents[2] / "work" / "ps2_probe.txt"     # work/ is never committed
LINES: list = []


def say(text: str = "") -> None:
    """Print a line and keep it for the report file: the screen scrolls, and a transcript loses lines."""
    print(text, flush=True)
    LINES.append(text)


def save(path: Path = REPORT) -> bool:
    try:
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text("\n".join(LINES) + "\n", encoding="utf-8")
        return True
    except OSError:
        return False


def show(rows: list) -> list:
    """Print each try; the ones that gave the game's bytes, as (build and flags, what kind of match)."""
    hits = []
    for row in rows:
        label = f"{row['compiler'].replace('mwcps2-', ''):<18} {row['flags']}"
        if not row["compiled"]:
            say(f"  {label:<62} did not compile: {row['error'].splitlines()[0] if row['error'] else ''}")
            continue
        mark = "MATCH" if row["verified"] else ("same bytes, an address unchecked" if row["exact"] else "")
        if row["exact"]:
            hits.append((" ".join(label.split()), mark))
        say(f"  {label:<62} {row['matched_bytes']:>3}/{row['total_bytes']} bytes, compiled {row['compiled_size']:>3} B  {mark}")
        say(f"      {words(row['compiled_hex'])}")
    return hits


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("file", nargs="?", help="a C++ file to probe with (default: the two built-in questions)")
    ap.add_argument("--va", help="the PS2 function's address, with a file")
    ap.add_argument("--flags", action="append", help="a flag set to try (repeatable)")
    ap.add_argument("--compiler", action="append", help="a build to try, e.g. mwcps2-3.0.1b87-031208 (repeatable)")
    ap.add_argument("--sweep", action="store_true",
                    help="the first two questions with every optimisation setting (17 compiles a function)")
    ap.add_argument("--all-builds", action="store_true",
                    help="also try every other CodeWarrior build with the lane's flags (22 more compiles a function)")
    ap.add_argument("--portal", default="http://127.0.0.1:8085", help="where your portal is running")
    args = ap.parse_args()
    if bool(args.file) != bool(args.va):
        ap.error("give a file and --va together, or neither")
    if args.file:
        code = Path(args.file).read_text(encoding="utf-8")
        tries = ([{"compiler": c, "flags": f} for c in (args.compiler or [LANE_COMPILER]) for f in (args.flags or [LANE_FLAGS])]
                 if args.flags or args.compiler else default_tries(args.all_builds))
        cases = [(int(args.va, 16), args.file, code, tries)]
    elif args.flags or args.compiler:
        tries = [{"compiler": c, "flags": f} for c in (args.compiler or [LANE_COMPILER]) for f in (args.flags or [LANE_FLAGS])]
        cases = [(va, what, code, tries) for va, what, code in BUILT_IN]
    elif args.sweep or args.all_builds:
        cases = [(va, what, code, default_tries(args.all_builds)) for va, what, code in BUILT_IN]
    else:
        cases = list(ROUND)
    user = input("Your handle: ").strip()
    creds = {"user": user, "pin": getpass.getpass("Your PIN (not shown): ")}
    n = sum(len(tries) for _, _, _, tries in cases)
    say(f"{n} compile(s) on {len({va for va, _, _, _ in cases})} function(s): about {n * 3 // 60 + 1} minute(s). "
        "Leave your decomp.me tab open.")
    hits, rc = [], 0
    for va, what, code, tries in cases:
        say(f"\n0x{va:08X}: {what}")
        for i in range(0, len(tries), CHUNK):
            try:
                res = call(args.portal, "/api/ps2-probe", dict(creds, id=f"ps2_{va:08X}", cpp_code=code, tries=tries[i:i + CHUNK]))
            except OSError:
                say(f"The portal isn't answering at {args.portal} - start it (START_PORTAL.bat) and try again.")
                rc = 1
                break
            hits += [(va, f"{what}: {label}", mark) for label, mark in show(res.get("rows", []))]
            if not res.get("ok"):
                say("  " + (res.get("error") or "the portal could not do it"))
                rc = 1
                break
        if rc:
            break
    say()
    for line in summary(hits):
        say(line)
    if save():
        print(f"\nAll of the above is saved in {REPORT}")
    return rc


def summary(hits: list) -> list:
    """The closing lines: every try that gave the game's bytes, again, so none is lost off the screen."""
    if not hits:
        return ["Nothing gave the game's bytes. The lines above still show what each build and setting changed."]
    out = ["Gave the game's bytes:"]
    out += [f"  0x{va:08X}  {label}  ({mark})" for va, label, mark in hits]
    out.append("A line that says MATCH is the build and flags that part of the game was made with. \"same bytes, an "
               "address unchecked\" is as good for this question: only an address the test code can't know differs.")
    return out


if __name__ == "__main__":
    sys.exit(main())
