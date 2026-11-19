#!/usr/bin/env python3
"""Names for the Microsoft library code linked into the Xbox builds, from another game's linker map.

    python portal/scripts/names_from_xdk_map.py --map ears_godfather_r.map --xbe ears_godfather_r.xbe          # list
    python portal/scripts/names_from_xdk_map.py --map ears_godfather_r.map --xbe ears_godfather_r.xbe --write  # record

The source. The 5 February 2006 Xbox prototype of The Godfather was built with the same Xbox SDK (5849)
as Scarface's Xbox programs, and has its linker map beside its program. The map names every function of
that build, with the library each came from. The game itself is another studio's on another engine, and
nothing of it is taken. What the two games share is Microsoft's own code: the C runtime (LIBCMT) and the
Xbox libraries (XAPILIB, D3D8, D3DX8, DSOUND, XGRAPHICS), which the linker copies into every game
unchanged. You need your own copy of that prototype; neither file is ever put in this repository.

What is taken, and when. A library function's name, when:

  * the map says the function came from one of those Microsoft libraries;
  * its bytes are found exactly once in Scarface's program, comparing everything but the addresses inside
    it (calls, jumps and data addresses differ from program to program);
  * at least MIN_BYTES bytes long, with at least MIN_FIXED of them compared and the first three among them;
  * no two functions land on the same address;
  * the name is an ordinary one (a C function, a member function, a constructor or a destructor), only
    one function has it (an overloaded name is skipped), and nothing recorded already names that address
    or uses that name.

Besides the names it writes reports/library_functions.json: the matched functions that sit among the
game's own code (the C runtime and XAPILIB are linked into .text). They are Microsoft's, compiled with
other settings than the game's, so the portal leaves them out of the queue of functions to match.
"""

from __future__ import annotations

import argparse
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

BY = "Xbox SDK 5849 library code, named in The Godfather prototype's linker map"
LIBRARIES = ("libcmt", "xapilib", "d3d8", "d3dx8", "dsound", "xgraphics")
MIN_BYTES = 24
MIN_FIXED = 20
LONGEST = 2048
SDK = 5849
BINARIES = {"xb": "default.xbe", "proto": "game.xbe"}
MAP_LINE = re.compile(r"^\s*([0-9a-fA-F]{4}):([0-9a-fA-F]{8})\s+(\S+)\s+[0-9a-fA-F]{8}\s(.*?)(\S+):\S+\s*$")
SCHEMA = "scarface_library_functions_v1"
NOTE = ("Microsoft library functions (the C runtime, XAPILIB) linked in among the game's own code. They are "
        "not the game's and were not compiled with its settings, so they are not in the queue of functions "
        "to match. in_library_sections: the ones found in the libraries' own sections (D3D, DSOUND, XGRPH), "
        "which were never in the queue. Made by portal/scripts/names_from_xdk_map.py; their names are in reports/names.json.")


def xbe_sections(data: bytes) -> List[Tuple[str, int, int, int, int]]:
    """An Xbox program's sections: (name, address, size in memory, place in the file, size in the file)."""
    base = struct.unpack_from("<I", data, 0x104)[0]
    count, at = struct.unpack_from("<II", data, 0x11C)
    out = []
    for i in range(count):
        o = at - base + i * 0x38
        _flags, va, vsize, raw, rsize, name_at = struct.unpack_from("<6I", data, o)
        name = data[name_at - base:data.index(b"\0", name_at - base)].decode("latin-1")
        out.append((name, va, vsize, raw, rsize))
    return out


def sdk_versions(data: bytes) -> Dict[str, int]:
    """{library: build} from an Xbox program's list of the libraries it was linked with."""
    base = struct.unpack_from("<I", data, 0x104)[0]
    count, at = struct.unpack_from("<II", data, 0x160)
    o = at - base
    return {data[o + i * 16:o + i * 16 + 8].rstrip(b"\0").decode("latin-1"): struct.unpack_from("<H", data, o + i * 16 + 12)[0]
            for i in range(count)}


def parse_map(text: str) -> List[Tuple[int, int, str, str, bool]]:
    """A Microsoft linker map's symbols: (section number from 1, offset, symbol, library, is a function)."""
    out = []
    for line in text.splitlines():
        m = MAP_LINE.match(line)
        if m:
            out.append((int(m.group(1), 16), int(m.group(2), 16), m.group(3), m.group(5), "f" in m.group(4).split()))
    return out


def plain_name(symbol: str) -> Optional[str]:
    """A linker symbol as an ordinary C++ name, or None for one this doesn't read (operators, templates,
    compiler helpers): _memcpy -> memcpy, _XMemAlloc@8 -> XMemAlloc, ?Set@CompMask@XGRAPHICS@@QAEXH@Z ->
    XGRAPHICS::CompMask::Set, ??0Foo@@QAE@XZ -> Foo::Foo, ??1Foo@@UAE@XZ -> Foo::~Foo."""
    if symbol.startswith("?"):
        special = ""
        body = symbol[1:]
        if body.startswith("?"):
            special, body = body[1:2], body[2:]
            if special not in ("0", "1"):
                return None
        head = body.split("@@", 1)[0]
        parts = head.split("@")
        if "@@" not in body or not all(re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", p) for p in parts):
            return None
        if special:
            parts = [("~" if special == "1" else "") + parts[0]] + parts
        name = "::".join(reversed(parts))
    else:
        m = re.fullmatch(r"[_@]([A-Za-z_][A-Za-z0-9_]*?)(@\d+)?", symbol)
        if not m:
            return None
        name = m.group(1)
    return name if NAMES.NAME_RE.match(name) and not NAMES.DEFAULT_RE.match(name) else None


def _read(data: bytes, sections, va: int, n: int) -> bytes:
    for _name, v, _vs, raw, rsize in sections:
        if v <= va < v + rsize:
            return data[raw + va - v:raw + va - v + min(n, v + rsize - va)]
    return b""


def pattern(body: bytes, va: int, lo: int, hi: int) -> Optional[re.Pattern]:
    """A function's bytes as something to look for in another program: the addresses in it (any four
    bytes that point into its own program, and the distance of a call or jump that lands there) match
    anything. None when too little is left to compare."""
    mask = bytearray(len(body))
    for j in range(len(body) - 3):
        value = struct.unpack_from("<I", body, j)[0]
        if lo <= value < hi:
            mask[j:j + 4] = b"\1\1\1\1"
        if j and body[j - 1] in (0xE8, 0xE9) and lo <= va + j + 4 + struct.unpack_from("<i", body, j)[0] < hi:
            mask[j:j + 4] = b"\1\1\1\1"
    if len(body) < MIN_BYTES or mask.count(0) < MIN_FIXED or any(mask[:3]):
        return None
    return re.compile(b"".join(b"." if m else re.escape(body[k:k + 1]) for k, m in enumerate(mask)), re.S)


def find(symbols, theirs: bytes, ours: bytes) -> Dict[int, Tuple[str, str, int, str]]:
    """{address in our program: (symbol, library, bytes, our section)} for every library function of their
    program found exactly once in ours."""
    their_sections, our_sections = xbe_sections(theirs), xbe_sections(ours)
    lo = min(s[1] for s in their_sections)
    hi = max(s[1] + s[2] for s in their_sections)
    placed = sorted((their_sections[seg - 1][1] + off, sym, lib.lower(), func)
                    for seg, off, sym, lib, func in symbols if 1 <= seg <= len(their_sections))
    hay = b"".join(ours[raw:raw + rsize] for _n, _v, _vs, raw, rsize in our_sections)
    spans, at = [], 0
    for name, v, _vs, _raw, rsize in our_sections:
        spans.append((at, v, rsize, name))
        at += rsize
    found: Dict[int, Tuple[str, str, int, str]] = {}
    twice = set()
    for i, (va, sym, lib, func) in enumerate(placed):
        if lib not in LIBRARIES or not func:
            continue
        nxt = next((p[0] for p in placed[i + 1:i + 60] if p[0] > va), va)
        body = _read(theirs, their_sections, va, min(nxt - va, LONGEST)).rstrip(b"\xcc\x90")
        pat = pattern(body, va, lo, hi)
        if pat is None:
            continue
        hits = [m.start() for _, m in zip(range(2), pat.finditer(hay))]
        if len(hits) != 1:
            continue
        o, v, _rs, section = next(s for s in spans if s[0] <= hits[0] < s[0] + s[2])
        address = v + hits[0] - o
        if address in found:
            twice.add(address)
        found[address] = (sym, lib, len(body), section)
    return {a: f for a, f in found.items() if a not in twice}


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--map", type=Path, required=True, help="the other game's linker map")
    ap.add_argument("--xbe", type=Path, required=True, help="the program that map describes")
    ap.add_argument("--write", action="store_true", help="record the names and the library functions")
    args = ap.parse_args(argv)
    theirs = args.xbe.read_bytes()
    symbols = parse_map(args.map.read_text(encoding="latin-1"))
    names_file = ROOT / "reports" / "names.json"
    data = NAMES.load(names_file)
    recorded = data.setdefault("names", {})
    library: Dict[str, List[str]] = {}
    elsewhere: Dict[str, List[str]] = {}
    added = Counter()
    for b, file in BINARIES.items():
        path = ROOT / "binaries" / file
        if not path.is_file():
            print(f"{b}: binaries/{file} isn't here, skipped")
            continue
        ours = path.read_bytes()
        mine, their_sdk = sdk_versions(ours), sdk_versions(theirs)
        if any(mine.get(k) != SDK or their_sdk.get(k) != SDK for k in ("XAPILIB", "LIBCMT", "D3D8")):
            print(f"{b}: not both built with SDK {SDK}, skipped")
            continue
        found = find(symbols, theirs, ours)
        by_lib = Counter(lib for _s, lib, _n, _sec in found.values())
        print(f"{b}: {len(found)} library functions found once: " + ", ".join(f"{k} {v}" for k, v in sorted(by_lib.items())))
        own = sorted(a for a, f in found.items() if f[3] == ".text")
        library[b] = [f"0x{a:08X}" for a in own]
        elsewhere[b] = [f"0x{a:08X}" for a, f in sorted(found.items()) if f[3] != ".text"]
        print(f"{b}: {len(own)} of them among the game's own code (.text)")
        # an overloaded name would be two addresses' name: neither gets it
        times = Counter(plain_name(f[0]) for f in found.values())
        taken = {v.get("name") for k, v in recorded.items() if k.startswith(b + ":") and isinstance(v, dict)}
        for a, (sym, lib, size, _section) in sorted(found.items()):
            key = f"{b}:0x{a:08X}"
            name = plain_name(sym)
            if name is None or key in recorded or times[name] > 1 or name in taken:
                continue
            recorded[key] = {"name": name, "by": BY,
                             "why": f"The same {size} bytes as {sym} ({lib}) in that build, addresses apart, and found "
                                    f"only once in this program."}
            added[b] += 1
    print("names: " + (", ".join(f"{b} {n}" for b, n in sorted(added.items())) or "none new"))
    if args.write:
        names_file.write_text(json.dumps(data, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
        (ROOT / "reports" / "library_functions.json").write_text(
            json.dumps({"schema": SCHEMA, "note": NOTE, "functions": library, "in_library_sections": elsewhere}, indent=2) + "\n", encoding="utf-8")
        print("written: reports/names.json, reports/library_functions.json")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
