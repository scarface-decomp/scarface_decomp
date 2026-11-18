#!/usr/bin/env python3
"""Function names the game's own program gives away (needs the game files in binaries/).

    python portal/scripts/names_from_messages.py            # list what it finds
    python portal/scripts/names_from_messages.py --write    # add the new ones to reports/names.json

Two sources, both the game's own text and class information:

1. Log messages. The Xbox program keeps messages such as "SaveGameController::SaveInit" and
   "GameOverHUD::ActivateElement", each handed to a logging call by exactly one function. A message
   that starts with Class::Method names the function it is in. It is taken only when one function
   uses it, pushes it as an argument, and (for a function the class information already places in a
   class) the class is the same.

2. Shared slots. A virtual function keeps its slot in every class that derives from the class that
   declares it. When the messages name slot 44 of several HUD classes ActivateElement, and the game's
   class information (RTTI) says those classes derive from HUDElement2, whose own table has that slot,
   then slot 44 of every class deriving from HUDElement2 is its ActivateElement. A slot is carried to
   other classes only when at least two classes' messages agree on it.

Nothing here reads anything but the program files; no outside names are used.
"""

from __future__ import annotations

import argparse
import bisect
import json
import re
import struct
import sys
from collections import Counter
from pathlib import Path
from typing import Dict, List, Optional, Tuple

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "portal" / "tools"))

import names as NAMES  # noqa: E402
import queue_builder as QB  # noqa: E402
import registry_outputs as RO  # noqa: E402
from sf_binaries import BinaryImage  # noqa: E402

FILES = {"xb": "default.xbe", "proto": "game.xbe", "pc": "Scarface.exe"}
BY = "the game's own text and class information"
NOT_FUNCTIONS = ("Con::", "om::String", "std::")           # console variables and type names, not functions
MESSAGE = re.compile(rb"(?<![\x21-\x7e])((?:[A-Za-z_]\w*::)+[A-Za-z_]\w*)([\x20-\x7e]*)\x00")
SLOT = re.compile(r"^(.*)::vfunc_(\d+)$")


def messages(img: BinaryImage, funcs: List[Tuple[int, int, str]]) -> List[Tuple[str, str, int, str]]:
    """[(Class::Method, the whole message, the function's address, its symbol)] for every message that
    exactly one known function pushes as an argument."""
    d = img.data
    secs = [(s.va, d[s.raw:s.raw + s.raw_size]) for s in img.sections]
    starts = [f[0] for f in funcs]

    def function_at(va: int) -> Optional[Tuple[int, int, str]]:
        i = bisect.bisect_right(starts, va) - 1
        return funcs[i] if i >= 0 and va < funcs[i][0] + funcs[i][1] else None
    out = []
    for va, data in secs:
        for m in MESSAGE.finditer(data):
            name = m.group(1).decode("ascii")
            if name.startswith(NOT_FUNCTIONS):
                continue
            users, pushed, stray = Counter(), 0, 0
            pattern = re.escape(struct.pack("<I", va + m.start(1)))
            for va2, data2 in secs:
                for r in re.finditer(pattern, data2):
                    fn = function_at(va2 + r.start())
                    if fn is None:
                        stray += 1
                    else:
                        users[fn] += 1
                        pushed += r.start() > 0 and data2[r.start() - 1] == 0x68       # push imm32
            if len(users) == 1 and pushed and not stray:
                fn = next(iter(users))
                out.append((name, (m.group(1) + m.group(2)).decode("ascii"), fn[0], fn[2]))
    return out


def hierarchy(img: BinaryImage) -> Tuple[Dict[str, List[str]], Dict[str, List[int]]]:
    """From the program's class information: {class: its base classes}, {class: its table of virtual
    functions (the longest one found), as addresses}."""
    d, secs = img.data, img.sections

    def offset(va: int) -> Optional[int]:
        for s in secs:
            if s.va <= va < s.va + s.raw_size:
                return s.raw + va - s.va
        return None
    types = {}
    for m in re.finditer(rb"\.\?A[VU][A-Za-z0-9_@?$<>]+@@\x00", d):
        o = m.start() - 8
        s = next((s for s in secs if s.raw <= o < s.raw + s.raw_size), None)
        if s:
            types[s.va + o - s.raw] = QB.demangle_rtti(m.group(0)[:-1].decode("ascii"))
    code = img.code_sections()

    def in_code(va: int) -> bool:
        return any(c.va <= va < c.va + c.raw_size for c in code)
    data_secs = [s for s in secs if not s.is_code and s.raw_size]
    locators = {}
    for s in data_secs:
        blob = d[s.raw:s.raw + s.raw_size]
        for o in range(0, len(blob) - 20, 4):
            sig, voff, cd, ptd, pchd = struct.unpack_from("<5I", blob, o)
            if ptd in types and sig == 0 and cd == 0 and voff == 0:
                locators[s.va + o] = (types[ptd], pchd)
    bases: Dict[str, List[str]] = {}
    tables: Dict[str, List[int]] = {}
    for s in data_secs:
        blob = d[s.raw:s.raw + s.raw_size]
        for o in range(0, len(blob) - 8, 4):
            p = struct.unpack_from("<I", blob, o)[0]
            if p not in locators:
                continue
            cls, pchd = locators[p]
            fns: List[int] = []
            while o + 8 + len(fns) * 4 <= len(blob):
                at = o + 4 + len(fns) * 4
                f = struct.unpack_from("<I", blob, at)[0]
                if not in_code(f) or (fns and struct.unpack_from("<I", blob, at)[0] in locators):
                    break
                fns.append(f)
            if len(fns) > len(tables.get(cls, [])):
                tables[cls] = fns
            h = offset(pchd)
            if h is None or cls in bases:
                continue
            _sig, _attr, count, parr = struct.unpack_from("<4I", d, h)
            a = offset(parr)
            found = []
            for i in range(count if a is not None and count < 64 else 0):
                bd = offset(struct.unpack_from("<I", d, a + 4 * i)[0])
                t = struct.unpack_from("<I", d, bd)[0] if bd is not None else None
                if t in types:
                    found.append(types[t])
            bases[cls] = found[1:]                             # the first is the class itself
    return bases, tables


def find(b: str, img: BinaryImage, known: Dict[int, dict]) -> Dict[int, Tuple[str, str]]:
    """{address: (name, why)} for one version."""
    funcs = sorted((va, t["size"], t["symbol"]) for va, t in known.items())
    out: Dict[int, Tuple[str, str]] = {}
    by_slot: Dict[int, Tuple[str, List[str]]] = {}
    for name, whole, va, symbol in messages(img, funcs):
        cls, method = name.split("::")[0], name.split("::")[1]
        own = symbol.rsplit("::", 1)[0] if "::" in symbol else None
        if own is not None and own.split("::")[-1] != cls:
            continue                                           # the message is about another class's function
        shown = whole if len(whole) <= 70 else whole[:67] + "..."
        why = (f'The only function that uses the message "{shown}" (it hands it to a logging call), '
               "so the message names the function it is in.")
        if own:
            why += f" The game's class information already puts this function in {own}'s table."
        out.setdefault(va, ((own or cls) + "::" + method, why))
        m = SLOT.match(symbol)
        if m:
            by_slot.setdefault(int(m.group(2)), (method, []))[1].append(m.group(1))
    bases, tables = hierarchy(img)
    for slot, (method, said) in sorted(by_slot.items()):
        said = sorted(set(said))
        if len(said) < 2:
            continue                                           # one class's word is not enough to name a base's slot
        shared = [c for c in bases.get(said[0], []) if all(c in bases.get(o, []) for o in said) and len(tables.get(c, [])) > slot]
        if not shared:
            continue
        base = shared[0]                                       # the nearest base that has the slot
        for cls in sorted(c for c, bl in bases.items() if base in bl or c == base):
            if len(tables.get(cls, [])) <= slot:
                continue
            va = tables[cls][slot]
            m = SLOT.match(known.get(va, {}).get("symbol", ""))
            if not m or int(m.group(2)) != slot or not (m.group(1) == base or base in bases.get(m.group(1), [])):
                continue
            why = (f"Slot {slot} of {base}'s table of virtual functions is {method}: {len(said)} of its derived classes "
                   f"({', '.join(said[:5])}) say so in their own log messages. The game's class information says "
                   f"{m.group(1)} derives from {base}, and this function is in slot {slot} of its table.")
            out.setdefault(va, (m.group(1) + "::" + method, why))
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--write", action="store_true", help="add the new names to reports/names.json")
    args = ap.parse_args()
    path = ROOT / "reports" / "names.json"
    data = NAMES.load(path)
    names = data.setdefault("names", {})
    known = RO.known_from_files(ROOT / "reconstructed_src")
    added = 0
    for b, fname in FILES.items():
        exe = ROOT / "binaries" / fname
        if not exe.exists():
            print(f"{b}: binaries/{fname} is not there; skipped")
            continue
        found = find(b, BinaryImage(exe), known.get(b, {}))
        taken = {v["name"] for k, v in names.items() if k.startswith(b + ":")}
        new = 0
        for va, (name, why) in sorted(found.items()):
            key = f"{b}:0x{va:08X}"
            if key in names or name in taken or not NAMES.NAME_RE.match(name):
                continue
            new += 1
            taken.add(name)
            if args.write:
                names[key] = {"name": name, "by": BY, "why": why}
            else:
                print(f"  {key}  {name}")
        added += new
        print(f"{b}: {len(found)} functions named by the program itself, {new} not recorded yet")
    if args.write and added:
        path.write_text(json.dumps(data, indent=2, ensure_ascii=False) + "\n", encoding="utf-8", newline="\n")
        print(f"Added {added} names to reports/names.json.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
