#!/usr/bin/env python3
"""
The game's script commands, and the function in the program that carries each one out.

The game runs on scripts (TorqueScript, see docs/SCRIPTS.md). Every command a script can call, such as
GetGameTime() or %tony.AddHealth(...), is a C++ function the program registers under that name when it
starts. The registering is a tiny piece of start-up code per command:

    push  most arguments
    push  fewest arguments
    push  help text (or 0)
    push  the function that does the work        <- what this module is after
    push  "TheCommandName"
    push  "TheClass" (or 0 for a plain command)
    mov   ecx, the record to fill in
    call  the record's constructor
    ret

So the program itself says which function is DBChangeDirtyCash and which is CharacterObject's
AddHealth: no guessing, and nothing from outside the game. This reads those pieces out of your own
default.xbe or game.xbe (the PC's copy of this start-up code isn't readable on disk) and writes the
names into reports/names.json for the functions the work queue still calls sub_XXXXXXXX.

    python portal/tools/script_commands.py                 what it finds in binaries/
    python portal/tools/script_commands.py --write         add the names to reports/names.json
    python portal/tools/script_commands.py --list xb       every command and its function

A function gets the name Script::<Command>, or Script::<Class>_<Command> for a class's command: it
is the script system's handler (it takes the object, a count and the arguments as text), not the class's
own C++ method of the same name, which it usually calls.

That these commands exist, and what many of them do, was known from the game's modding scene first:
ScarfaceHook (ermaccer) and ScarfaceEX call them by name. They are credited in docs/CREDITS.md.

Addresses and names only: nothing from the game's files is written anywhere.
"""
from __future__ import annotations

import argparse
import json
import re
import struct
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Dict, List, Optional, Tuple

HERE = Path(__file__).resolve().parent
if str(HERE) not in sys.path:
    sys.path.insert(0, str(HERE))

import names as NAMES  # noqa: E402
import registry_outputs as RO  # noqa: E402
from sf_binaries import BinaryImage  # noqa: E402

ROOT = HERE.parent.parent
FILES = {"xb": "default.xbe", "proto": "game.xbe"}
LABELS = {"xb": "the Xbox game", "proto": "the April 2006 prototype"}
BY = "the game's own script command table (portal/tools/script_commands.py)"
IDENT = re.compile(r"[A-Za-z_][A-Za-z0-9_]*\Z")
DEFAULT = re.compile(r"(sub|func|FUN|thunk)_[0-9A-Fa-f]+\Z")

_PUSH = rb"(?:\x6A(.)|\x68(.{4}))"                    # push imm8 / push imm32
_STUB = re.compile(_PUSH + _PUSH + _PUSH + rb"\x68(.{4})\x68(.{4})" + _PUSH + rb"\xB9(.{4})\xE8(.{4})\xC3", re.S)


@dataclass(frozen=True)
class Command:
    cls: str            # "" for a plain command
    name: str
    handler: int        # the function that carries it out
    fewest: int         # arguments, counting the command's own name (and the object, for a class's)
    most: int
    at: int             # where the start-up code registers it

    @property
    def script_name(self) -> str:
        return f"{self.cls}::{self.name}" if self.cls else self.name

    @property
    def function_name(self) -> str:
        return f"Script::{self.cls}_{self.name}" if self.cls else f"Script::{self.name}"


def _text(img: BinaryImage, va: int) -> Optional[str]:
    """The name at va: a short run of letters, digits and _ ending in a zero byte."""
    raw = img.read(va, 1)
    if raw is None:
        return None
    off = img.va_to_off(va)
    end = img.data.find(b"\0", off, off + 96)
    if end <= off:
        return None
    try:
        s = img.data[off:end].decode("ascii")
    except UnicodeDecodeError:
        return None
    return s if IDENT.match(s) else None


def find(img: BinaryImage) -> List[Command]:
    """Every script command the program registers, in the order its start-up code does."""
    def num(short: Optional[bytes], long: Optional[bytes]) -> int:
        return short[0] if short is not None else struct.unpack("<I", long)[0]
    found: List[Command] = []
    for sec in img.game_code_sections():
        code = img.data[sec.raw:sec.raw + sec.raw_size]
        for m in _STUB.finditer(code):
            g = m.groups()
            most, fewest = num(g[0], g[1]), num(g[2], g[3])
            handler, name_va = struct.unpack("<I", g[6])[0], struct.unpack("<I", g[7])[0]
            cls_va = num(g[8], g[9])
            name = _text(img, name_va)
            if name is None or fewest > most or most > 64:
                continue
            cls = _text(img, cls_va) if cls_va else ""
            if cls is None:
                continue
            target = img.section_of(handler)
            if target is None or not target.is_code or target.library:
                continue
            found.append(Command(cls, name, handler, fewest, most, sec.va + m.start()))
    return found


def names_for(commands: List[Command], functions: Dict[int, dict], b: str) -> Tuple[Dict[str, dict], Dict[str, int]]:
    """reports/names.json entries for the commands whose function the queue has without a name of its own,
    and a count of what happened to the rest. One name per function: when several commands share one (the
    game points a few at the same do-nothing function), it is named after the first and the others are listed."""
    by_handler: Dict[int, List[Command]] = {}
    for c in commands:
        by_handler.setdefault(c.handler, []).append(c)
    out: Dict[str, dict] = {}
    counts = {"named": 0, "has a name already": 0, "not in the work queue": 0, "shared by several commands": 0}
    used = set()
    for handler in sorted(by_handler):
        group = sorted(by_handler[handler], key=lambda c: c.at)
        f = functions.get(handler)
        if f is None:
            counts["not in the work queue"] += 1
            continue
        if not DEFAULT.match(str(f.get("symbol", "")).split("::")[-1]):
            counts["has a name already"] += 1
            continue
        first = group[0]
        if len(group) > 1:
            counts["shared by several commands"] += 1
        name = first.function_name
        if name in used:                       # two classes' commands that would read the same
            name = f"{name}_{handler:08X}"
        used.add(name)
        n = first.most - (2 if first.cls else 1)
        few = first.fewest - (2 if first.cls else 1)
        args = (f"{max(few, 0)} to {max(n, 0)} arguments" if few != n else
                f"{max(n, 0)} argument" + ("" if n == 1 else "s"))
        why = (f"The start-up code at 0x{first.at:08X} registers this function as the script command "
               f"{first.script_name} ({args}).")
        if len(group) > 1:
            why += " Also registered as " + ", ".join(c.script_name for c in group[1:6]) + (
                " and others" if len(group) > 6 else "") + "."
        out[f"{b}:0x{handler:08X}"] = {"name": name, "by": BY, "why": why}
        counts["named"] += 1
    return out, counts


def merge(data: dict, new: Dict[str, dict]) -> int:
    """Add the names to a names file, never replacing one a person wrote. Returns how many were added or
    brought up to date."""
    names = data.setdefault("names", {})
    taken = {(k.split(":")[0], v.get("name")) for k, v in names.items() if isinstance(v, dict)}
    changed = 0
    for key, info in new.items():
        have = names.get(key)
        if isinstance(have, dict) and have.get("by") != BY:
            continue                                             # somebody's own name wins
        if have == info:
            continue
        if have is None and (key.split(":")[0], info["name"]) in taken:
            continue
        names[key] = info
        changed += 1
    data["names"] = dict(sorted(names.items()))
    return changed


def scan(bin_dir: Path, recon_dir: Path) -> Dict[str, Tuple[List[Command], Dict[str, dict], Dict[str, int]]]:
    """{version: (commands, names, counts)} for the game files that are there."""
    known = RO.known_from_files(recon_dir)
    out = {}
    for b, fname in FILES.items():
        path = bin_dir / fname
        if not path.is_file():
            continue
        commands = find(BinaryImage(path))
        out[b] = (commands,) + names_for(commands, known.get(b, {}), b)
    return out


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--write", action="store_true", help="add the names to reports/names.json")
    ap.add_argument("--list", metavar="VERSION", choices=sorted(FILES), help="print every command of xb or proto")
    ap.add_argument("--bin-dir", type=Path, default=ROOT / "binaries")
    args = ap.parse_args(argv)
    found = scan(args.bin_dir, ROOT / "reconstructed_src")
    if not found:
        print(f"Neither default.xbe nor game.xbe is in {args.bin_dir}: put your game files there first "
              "(docs/GAME_VERSIONS.md).")
        return 1
    if args.list:
        commands = found.get(args.list, ([],))[0]
        for c in sorted(commands, key=lambda c: (c.cls, c.name.lower())):
            print(f"0x{c.handler:08X}  {c.script_name}")
        return 0
    path = ROOT / "reports" / "names.json"
    data = NAMES.load(path)
    data.setdefault("schema", NAMES.SCHEMA)
    total = 0
    for b, (commands, new, counts) in found.items():
        classes = len({c.cls for c in commands if c.cls})
        print(f"{LABELS[b]}: {len(commands):,} script commands ({classes} classes have their own).")
        for what, n in counts.items():
            if n:
                print(f"    {n:5,}  {what}")
        total += merge(data, new) if args.write else sum(1 for k, v in new.items() if data.get("names", {}).get(k) != v)
    if args.write:
        path.write_text(json.dumps(data, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
        print(f"reports/names.json: {total:,} names added or updated.")
    else:
        print(f"{total:,} names would be added to reports/names.json. Run again with --write to add them.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
