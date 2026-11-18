#!/usr/bin/env python3
"""Names for shared engine classes' virtual functions, from another Radical game's linker map.

    python portal/scripts/names_from_shar_map.py --map SRR2.MAP --elf SLUS_206.24            # list
    python portal/scripts/names_from_shar_map.py --map SRR2.MAP --elf SLUS_206.24 --write    # record

The source. The 10 July 2003 PS2 prototype of The Simpsons: Hit & Run has a linker map on its disc
(SRR2.MAP, beside the program SLUS_206.24). The map lists every function of that build by name. Hit &
Run and Scarface share Radical's engine, so some of its classes are Scarface's classes three years
earlier. You need your own copy of that disc; neither file is ever put in this repository. Only the
map and the program are read: nothing from that game's source code, which this project does not use.

What is taken, and when. Only names of virtual functions, by their slot:

  * the Hit & Run class and the Scarface class are the same class under the engine's renaming
    (tCamera -> pure3d::Camera, pddiShader -> pure3d::pddiShader, Scrooby::Page ->
    pure3d::frontend::Page), and Scarface's class information has exactly that class;
  * both tables of virtual functions have the same number of slots, and at least MIN_SLOTS;
  * the slot's function has one name in Hit & Run's table (an overloaded name is skipped: the two
    compilers order overloads differently), and it is not a destructor, an operator or a pure slot;
  * Scarface's function in that slot is already known as <Class>::vfunc_<that slot>;
  * nothing recorded already disagrees, and no two classes give one function two names.

A table that gained or lost a slot between 2003 and 2006 is left alone. Each name records the class
and slot it came from. It is evidence, not proof: a class can keep its size and still have had a
function replaced.
"""

from __future__ import annotations

import argparse
import importlib.util
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

BY = "the Hit & Run prototype's linker map"
MIN_SLOTS = 6
MAP_LINE = re.compile(r"^([0-9a-fA-F]{8}) ([0-9a-fA-F]{8})\s+\S+\s+(\S.*?)\s*$")
SLOT = re.compile(r"^(.*)::vfunc_(\d+)$")
IDENT = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")


def parse_map(text: str) -> Tuple[Dict[int, str], Dict[str, Tuple[int, int]]]:
    """({address: symbol} for everything with a size, {mangled class: (address, size)} for the tables
    of virtual functions, which the map calls _vt$<class>)."""
    symbols: Dict[int, str] = {}
    tables: Dict[str, Tuple[int, int]] = {}
    for line in text.splitlines():
        m = MAP_LINE.match(line)
        if not m:
            continue
        addr, size, what = int(m.group(1), 16), int(m.group(2), 16), m.group(3)
        if what.startswith(".") or what.endswith((".o", ")")) or "\\" in what or "/" in what:
            continue                                           # a section, an object file, a library member
        if what.startswith("_vt$"):
            tables[what[4:]] = (addr, size)
        elif size:
            symbols.setdefault(addr, what)
    return symbols, tables


def class_name(mangled: str) -> Optional[str]:
    """`7tCamera` -> tCamera, `Q27Scrooby4Page` -> Scrooby::Page (the old GNU scheme); None for
    anything else (templates, mostly)."""
    parts, count = [], 1
    if mangled.startswith("Q") and mangled[1:2].isdigit():
        count, mangled = int(mangled[1]), mangled[2:]
    for _ in range(count):
        m = re.match(r"(\d+)", mangled)
        if not m:
            return None
        n = int(m.group(1))
        name, mangled = mangled[len(m.group(1)):len(m.group(1)) + n], mangled[len(m.group(1)) + n:]
        if len(name) != n or not IDENT.match(name):
            return None
        parts.append(name)
    return "::".join(parts) if not mangled else None


def method_name(symbol: str) -> Optional[str]:
    """`SetFOV__7tCameraf` -> SetFOV; None for destructors, operators, pure slots and anything odd."""
    if symbol.startswith(("_._", "_$_", "__")):
        return None
    m = re.match(r"^([A-Za-z_][A-Za-z0-9_]*?)__(?=[Q\d])", symbol)
    return m.group(1) if m else None


def elf_reader(elf: bytes):
    """read(address, size) over a 32-bit little-endian ELF's loaded segments."""
    phoff, = struct.unpack_from("<I", elf, 0x1C)
    phsize, phnum = struct.unpack_from("<HH", elf, 0x2A)
    segs = [struct.unpack_from("<8I", elf, phoff + i * phsize) for i in range(phnum)]

    def read(va: int, n: int) -> bytes:
        for kind, off, vaddr, _p, filesz, _m, _f, _a in segs:
            if kind == 1 and vaddr <= va and va + n <= vaddr + filesz:
                return elf[off + va - vaddr:off + va - vaddr + n]
        return b""
    return read


def their_tables(symbols: Dict[int, str], tables: Dict[str, Tuple[int, int]], read) -> Dict[str, List[Optional[str]]]:
    """{class: its slots' method names (None where there is no usable name)}. This compiler's table
    is 8 bytes a slot (two 16-bit adjustments, then the function), with one entry before the first
    slot (the class's type information) and an empty one after the last."""
    out: Dict[str, List[Optional[str]]] = {}
    for mangled, (addr, size) in tables.items():
        cls = class_name(mangled)
        raw = read(addr, size)
        if not cls or len(raw) != size or size < 24 or size % 8:
            continue
        entries = [struct.unpack_from("<hhI", raw, i) for i in range(0, size, 8)]
        if entries[-1][2] != 0:
            continue
        out[cls] = [method_name(symbols.get(fn, "")) for _d, _i, fn in entries[1:-1]]
    return out


def our_class(theirs: str) -> Optional[str]:
    """The Scarface name of a Hit & Run engine class, by the engine's own renaming; None for classes
    outside the three families this is known for."""
    if theirs.startswith("Scrooby::") and theirs.count("::") == 1:
        return "pure3d::frontend::" + theirs.split("::")[1]
    if "::" in theirs:
        return None
    if theirs.startswith("pddi"):
        return "pure3d::" + theirs
    if theirs.startswith("t") and theirs[1:2].isupper():
        return "pure3d::" + theirs[1:]
    return None


def find(theirs: Dict[str, List[Optional[str]]], ours: Dict[str, List[int]], known: Dict[int, dict],
         recorded: Dict[int, str]) -> Tuple[Dict[int, Tuple[str, str]], Counter]:
    """({address: (name, why)}, counts of what happened). ours: Scarface's tables from its class
    information; known: its functions; recorded: names already in reports/names.json, by address."""
    stats: Counter = Counter()
    proposals: Dict[int, List[Tuple[str, str]]] = {}
    for cls, slots in sorted(theirs.items()):
        mine = our_class(cls)
        if mine is None or mine not in ours:
            continue
        stats["classes in both games"] += 1
        table = ours[mine]
        if len(table) != len(slots) or len(slots) < MIN_SLOTS:
            stats["tables of different sizes, or too small"] += 1
            continue
        often = Counter(n for n in slots if n)
        picks = []
        for i, name in enumerate(slots):
            m = SLOT.match(known.get(table[i], {}).get("symbol", ""))
            if not name or often[name] != 1 or not m or int(m.group(2)) != i:
                continue
            picks.append((table[i], m.group(1) + "::" + name, i))
        if any(recorded.get(va, n).split("::")[-1] != n.split("::")[-1] for va, n, _i in picks):
            stats["classes that disagree with a recorded name"] += 1
            continue
        stats["classes used"] += 1
        for va, name, i in picks:
            why = (f"Hit & Run's 10 July 2003 PS2 prototype has a linker map (SRR2.MAP). Its class {cls} is this game's "
                   f"{mine}: both tables of virtual functions have {len(slots)} slots, and slot {i} of {cls} is "
                   f"{name.split('::')[-1]} in that map.")
            proposals.setdefault(va, []).append((name, why))
    out: Dict[int, Tuple[str, str]] = {}
    for va, found in proposals.items():
        if len({n.split("::")[-1] for n, _w in found}) > 1:
            stats["functions two classes name differently"] += 1
            continue
        out[va] = found[0]
    return out, stats


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--map", required=True, help="SRR2.MAP from your own copy of the prototype's disc")
    ap.add_argument("--elf", required=True, help="SLUS_206.24 from the same disc")
    ap.add_argument("--write", action="store_true", help="add the new names to reports/names.json")
    ap.add_argument("--out", help="write what was found to this JSON file instead (nothing is recorded)")
    args = ap.parse_args()

    import registry_outputs as RO
    from sf_binaries import BinaryImage
    spec = importlib.util.spec_from_file_location("names_from_messages", Path(__file__).with_name("names_from_messages.py"))
    NM = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(NM)

    exe = ROOT / "binaries" / "default.xbe"
    if not exe.exists():
        print("binaries/default.xbe is not there.", file=sys.stderr)
        return 1
    symbols, tables = parse_map(Path(args.map).read_text(encoding="latin-1"))
    theirs = their_tables(symbols, tables, elf_reader(Path(args.elf).read_bytes()))
    _bases, ours = NM.hierarchy(BinaryImage(exe))
    known = RO.known_from_files(ROOT / "reconstructed_src").get("xb", {})
    path = ROOT / "reports" / "names.json"
    data = NAMES.load(path)
    names = data.setdefault("names", {})
    recorded = {int(k[3:], 16): v["name"] for k, v in names.items() if k.startswith("xb:")}
    found, stats = find(theirs, ours, known, recorded)
    print(f"The map: {len(symbols):,} symbols, {len(theirs):,} classes with a table.")
    for what, n in stats.items():
        print(f"  {what}: {n}")
    taken = set(recorded.values())
    new = []
    for va, (name, why) in sorted(found.items()):
        if va in recorded or name in taken or not NAMES.NAME_RE.match(name):
            continue
        taken.add(name)
        new.append((f"xb:0x{va:08X}", name, why))
    print(f"{len(found)} functions named, {len(new)} not recorded yet.")
    if args.out:
        Path(args.out).write_text(json.dumps(new, indent=1), encoding="utf-8")
    elif args.write:
        for key, name, why in new:
            names[key] = {"name": name, "by": BY, "why": why}
        if new:
            path.write_text(json.dumps(data, indent=2, ensure_ascii=False) + "\n", encoding="utf-8", newline="\n")
    else:
        for key, name, _why in new:
            print(f"  {key}  {name}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
