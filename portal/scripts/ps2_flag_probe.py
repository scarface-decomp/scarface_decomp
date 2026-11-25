#!/usr/bin/env python3
"""
Find out how the PS2 game was built: compile one function's C++ with every build of its compiler, and
with several optimisation settings, and say how close each gets to the game's bytes.

    python portal/scripts/ps2_flag_probe.py                       the current round of questions (below)
    python portal/scripts/ps2_flag_probe.py --sweep               the first two questions, every optimisation setting
    python portal/scripts/ps2_flag_probe.py --recheck             30 matched functions, on build 3.0b52 and the lane's build
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

Without arguments the probe runs the current round (ROUND, below). `--sweep` runs the first two questions with
the lane's build and 16 other settings; `--all-builds` adds the other 22 builds with the lane's flags.
`--recheck` compiles functions that are already matched again, with another build or with the lane's own.

It asks for your handle and PIN (the PIN isn't shown, stored or printed).
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

# The round that follows the one of 25 November 2026 (docs/PS2.md has what that one showed). Three things the
# lane's build gets wrong all look like one cause, the instruction scheduler: the game keeps the order the
# source has (float store before the return value; each pair of float loads next to its multiply) and still
# fills its delay slots. On build 103, `#pragma schedule off` keeps the order but leaves the delay slot empty.
# So: which 3.0.1 build keeps the order AND fills the slot with the scheduler off? One compile a line.
#   1. the float store with `#pragma schedule off`, on every other 3.0.1 build;
#   2. the dot product (0x0066DFF0) with `#pragma schedule off`, on every 3.0.1 build;
#   3. a jump after reading a global (0x0038EC30: the game uses $at for the address, build 103 uses $v0), on the
#      3.0-line builds, with the scheduler off, and with the global as a member of a larger object.
OLD_LINE = ["mwcps2-3.0.3-020716", "mwcps2-3.0b38-030307", "mwcps2-3.0b50-030527", "mwcps2-3.0b52-030722"]
NEW_LINE = [b for b in BUILDS if "-3.0.1b" in b]                # 3.0.1 builds 44 to 210
SCHEDULE_OFF = "#pragma schedule off\n\n"
READ_GLOBAL = ('extern int D_0081DFE8[];\nextern "C" void func_0047EEF0(int);\n\n'
               "void Forward()\n{\n    func_0047EEF0(D_0081DFE8[0]);\n}\n")


def on(builds: list) -> list:
    return [{"compiler": b, "flags": LANE_FLAGS} for b in builds]


ROUND = [
    (0x00392940, "the float store with #pragma schedule off", SCHEDULE_OFF + FLOAT_STORE,
     on([b for b in NEW_LINE if b != LANE_COMPILER])),
    (0x0066DFF0, "the dot product with #pragma schedule off", SCHEDULE_OFF + DOT, on(NEW_LINE)),
    (0x0038EC30, "a jump after reading a global, on the 3.0-line builds", READ_GLOBAL, on(OLD_LINE)),
    (0x0038EC30, "that jump with #pragma schedule off", SCHEDULE_OFF + READ_GLOBAL,
     on([LANE_COMPILER, "mwcps2-3.0.1b87-031208", "mwcps2-3.0.1b95-040309"])),
    (0x0038EC30, "that jump, with the global as the first member of a larger object",
     'struct Manager\n{\n    int m_Field0;\n    int m_Rest[3];\n};\n\nextern Manager D_0081DFE8;\n'
     'extern "C" void func_0047EEF0(int);\n\nvoid Forward()\n{\n    func_0047EEF0(D_0081DFE8.m_Field0);\n}\n',
     on([LANE_COMPILER])),
]


REGISTRY = Path(__file__).resolve().parents[2] / "reports" / "verified_registry.json"


def shape_of(code: str) -> str:
    """A match's C++ without its comments and numbers: functions written the same way have the same shape."""
    text = re.sub(r"//[^\n]*", "", code)
    text = re.sub(r"\b(m_Field|m_pad|D_|func_|Method|Arg)[0-9A-Fa-f]+", r"\1N", text)      # names made from an offset or address
    return re.sub(r"\s+", " ", re.sub(r"0x[0-9A-Fa-f]+|\d+", "N", text)).strip()


def recheck_cases(count: int, compilers: list, registry: Path = REGISTRY) -> list:
    """count functions the registry already has matched for the main PS2 program, one for each way of writing
    one (half of them the commonest ways, half the largest functions), each to be compiled again with every
    build in compilers and the lane's flags. It answers "does this build also make what has been matched?" for a build other than the lane's,
    and "do the matches recorded before exceptions were turned off still hold?" for the lane's own."""
    entries = [e for e in json.loads(registry.read_text(encoding="utf-8")).get("entries", {}).values()
               if e.get("bin") == "ps2" and e.get("code")]
    by_shape: dict = {}
    for e in sorted(entries, key=lambda e: e["va"]):
        by_shape.setdefault(shape_of(e["code"]), []).append(e)
    common = [g[0] for g in sorted(by_shape.values(), key=lambda g: (-len(g), g[0]["va"]))[:count // 2]]
    large = [g[0] for g in sorted(by_shape.values(), key=lambda g: (-int(g[0]["size"]), g[0]["va"])) if g[0] not in common]
    picked = common + large[:count - len(common)]         # half the commonest ways, half the largest functions
    return [(int(e["va"], 16), f"matched already ({e['size']} bytes; {len(by_shape[shape_of(e['code'])])} written this way)",
             e["code"], on(compilers)) for e in picked]


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
    ap.add_argument("--recheck", type=int, nargs="?", const=30, metavar="N",
                    help="compile N functions that are already matched (one for each way of writing one) with the "
                         "last 3.0-line build and the lane's build, or with --compiler; default 30")
    ap.add_argument("--portal", default="http://127.0.0.1:8085", help="where your portal is running")
    args = ap.parse_args()
    if bool(args.file) != bool(args.va):
        ap.error("give a file and --va together, or neither")
    if args.recheck:
        cases = recheck_cases(args.recheck, args.compiler or [OLD_LINE[-1], LANE_COMPILER])
    elif args.file:
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
    tally: dict = {}                       # build -> [gave the game's bytes, compiled, the addresses that did not]
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
            for row in res.get("rows", []):
                t = tally.setdefault(row["compiler"], [0, 0, []])
                t[1] += 1
                if row.get("exact"):
                    t[0] += 1
                else:
                    t[2].append(f"0x{va:08X}")
            if not res.get("ok"):
                say("  " + (res.get("error") or "the portal could not do it"))
                rc = 1
                break
        if rc:
            break
    say()
    for line in (recheck_summary(tally) if args.recheck else summary(hits)):
        say(line)
    if save():
        print(f"\nAll of the above is saved in {REPORT}")
    return rc


def recheck_summary(tally: dict) -> list:
    """How many of the functions already matched each build gives back, and which it does not."""
    out = ["Of the functions already matched:"]
    for compiler, (good, total, missed) in tally.items():
        out.append(f"  {compiler.replace('mwcps2-', ''):<18} gives the game's bytes for {good} of {total}"
                   + (f"; not for {', '.join(missed)}" if missed else ""))
    return out


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
