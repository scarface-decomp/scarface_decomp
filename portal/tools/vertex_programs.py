#!/usr/bin/env python3
"""
The Xbox program's vertex programs, read as the GPU reads them (the examiner's block G1).

The pddi shaders' vertex programs sit in the program's data as Xbox vertex-shader binaries: a u16 type
0x2078, a u16 count, then count instructions of 16 bytes (four words; the first is always 0). This finds
every one (a header whose instructions all have a zero first word and only the last one marked final)
and writes each out as readable assembly, in the usual register names:

    python portal/tools/vertex_programs.py                 list them
    python portal/tools/vertex_programs.py 0x45E3D0        one, as assembly

Registers: v0..v15 the vertex's inputs (v0 position, v2 normal, v3 and v4 colours, v9 and v10 texture
coordinates), r0..r12 scratch (r12 is the position the last steps scale to the screen), c[n] the
constants the CPU uploads (c[n] is the push-buffer slot n + 96: 0x32E5F0 uploads slot 0x8A to c[42]),
oD0 / oB0 the front and back colours, oPos, oFog, oT0..oT3. "add r8.xyz & oD0.xyz, r8, r8" writes both.

Only the program's own bytes are read. No leaked source is used. You need your own copy of the game.
"""

from __future__ import annotations

import argparse
import struct
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import List, Sequence, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parent))
from sf_binaries import BinaryImage  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]
XBE = ROOT / "binaries" / "default.xbe"
TYPE = 0x2078
MOST = 136                                             # the GPU holds 136 instructions

MAC = ["nop", "mov", "mul", "add", "mad", "dp3", "dph", "dp4", "dst", "min", "max", "slt", "sge", "arl",
       "?14", "?15"]
ILU = ["nop", "mov", "rcp", "rcc", "rsq", "exp", "log", "lit"]
OUT = {0: "oPos", 3: "oD0", 4: "oD1", 5: "oFog", 6: "oPts", 7: "oB0", 8: "oB1",
       9: "oT0", 10: "oT1", 11: "oT2", 12: "oT3"}
TWO = {"mul", "add", "dp3", "dph", "dp4", "dst", "min", "max", "slt", "sge"}


def _bits(v: int, lo: int, hi: int) -> int:
    return (v >> lo) & ((1 << (hi - lo + 1)) - 1)


def _swizzle(x: int, y: int, z: int, w: int) -> str:
    s = "".join("xyzw"[i] for i in (x, y, z, w))
    if s == "xyzw":
        return ""
    return "." + (s[0] if len(set(s)) == 1 else s)


def _mask(m: int) -> str:
    s = "".join(c for i, c in enumerate("xyzw") if m & (8 >> i))
    return "" if s == "xyzw" else "." + s


@dataclass
class Source:
    negate: bool
    swizzle: str
    temp: int
    kind: int                                          # 1 scratch, 2 input, 3 constant


def _sources(w1: int, w2: int, w3: int) -> Tuple[Source, Source, Source]:
    a = Source(bool(_bits(w1, 8, 8)), _swizzle(_bits(w1, 6, 7), _bits(w1, 4, 5), _bits(w1, 2, 3), _bits(w1, 0, 1)),
               _bits(w2, 28, 31), _bits(w2, 26, 27))
    b = Source(bool(_bits(w2, 25, 25)),
               _swizzle(_bits(w2, 23, 24), _bits(w2, 21, 22), _bits(w2, 19, 20), _bits(w2, 17, 18)),
               _bits(w2, 13, 16), _bits(w2, 11, 12))
    c = Source(bool(_bits(w2, 10, 10)), _swizzle(_bits(w2, 8, 9), _bits(w2, 6, 7), _bits(w2, 4, 5), _bits(w2, 2, 3)),
               (_bits(w2, 0, 1) << 2) | _bits(w3, 30, 31), _bits(w3, 28, 29))
    return a, b, c


def instruction(words: Sequence[int]) -> List[str]:
    """One 128-bit instruction as one or two lines of assembly (the MAC and the ILU unit can both run)."""
    _w0, w1, w2, w3 = words
    constant, vin, relative = _bits(w1, 13, 20) - 96, _bits(w1, 9, 12), _bits(w3, 1, 1)

    def name(s: Source) -> str:
        reg = {1: f"r{s.temp}", 2: f"v{vin}", 3: f"c[{constant}{'+a0.x' if relative else ''}]"}.get(s.kind, "?")
        return ("-" if s.negate else "") + reg + s.swizzle

    a, b, c = _sources(w1, w2, w3)
    mac, ilu = _bits(w1, 21, 24), _bits(w1, 25, 27)
    temp_mask, temp = _bits(w3, 24, 27), _bits(w3, 20, 23)
    ilu_mask, out_mask = _bits(w3, 16, 19), _bits(w3, 12, 15)
    to_output, address, from_ilu = _bits(w3, 11, 11), _bits(w3, 3, 10), _bits(w3, 2, 2)
    out = (OUT.get(address, f"o{address}") if to_output else f"c[{address - 96}]")
    lines = []
    if mac:
        op = MAC[mac]
        srcs = {"mad": [a, b, c], "add": [a, c], "mov": [a], "arl": [a]}.get(op, [a, b] if op in TWO else [a])
        dst = [f"r{temp}{_mask(temp_mask)}"] if temp_mask else []
        if out_mask and not from_ilu:
            dst.append(out + _mask(out_mask))
        if op == "arl":
            dst = ["a0.x"]
        lines.append(f"{op} {' & '.join(dst) or '-'}, {', '.join(name(s) for s in srcs)}")
    if ilu:
        dst = [f"r1{_mask(ilu_mask)}"] if ilu_mask else []
        if out_mask and from_ilu:
            dst.append(out + _mask(out_mask))
        lines.append(f"{ILU[ilu]} {' & '.join(dst) or '-'}, {name(c)}")
    return lines


@dataclass
class Program:
    address: int
    count: int
    words: List[Tuple[int, int, int, int]]

    def assembly(self) -> List[str]:
        out = []
        for i, w in enumerate(self.words):
            out += [f"{i:3}  {line}" for line in instruction(w)]
        return out

    def reads(self) -> List[int]:
        """The constants the program reads (D3D numbering), in order."""
        seen: List[int] = []
        for w in self.words:
            if any(s.kind == 3 for s in _sources(w[1], w[2], w[3])):
                n = _bits(w[1], 13, 20) - 96
                if n not in seen:
                    seen.append(n)
        return seen


def read_program(data: bytes, offset: int, address: int = 0) -> Program:
    kind, count = struct.unpack_from("<HH", data, offset)
    if kind != TYPE or not 1 <= count <= MOST or offset + 4 + count * 16 > len(data):
        raise ValueError(f"no vertex program at {address or offset:#x}")
    words = [struct.unpack_from("<4I", data, offset + 4 + i * 16) for i in range(count)]
    finals = [i for i, w in enumerate(words) if w[3] & 1]
    if any(w[0] for w in words) or finals != [count - 1]:
        raise ValueError(f"no vertex program at {address or offset:#x}")
    return Program(address, count, words)


def programs(img: BinaryImage) -> List[Program]:
    """Every vertex program in the program's data sections."""
    found = []
    for sec in img.sections:
        if sec.is_code:
            continue
        data = img.data[sec.raw:sec.raw + sec.raw_size]
        for off in range(0, len(data) - 4, 4):
            if data[off:off + 2] != b"\x78\x20":
                continue
            try:
                found.append(read_program(data, off, sec.va + off))
            except ValueError:
                pass
    return found


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("address", nargs="?", help="one program, as assembly")
    ap.add_argument("--xbe", default=str(XBE))
    a = ap.parse_args(argv)
    if not Path(a.xbe).exists():
        print(f"no {a.xbe}: you need your own copy of the game", file=sys.stderr)
        return 1
    img = BinaryImage(a.xbe)
    if a.address:
        va = int(a.address, 0)
        raw = img.read(va, 4 + MOST * 16) or b""
        try:
            p = read_program(raw, 0, va)
        except ValueError as e:
            print(e, file=sys.stderr)
            return 1
        print(f"{va:#x}: {p.count} instructions; reads c{p.reads()}")
        print("\n".join(p.assembly()))
        return 0
    for p in programs(img):
        print(f"{p.address:#x}  {p.count:3} instructions  reads c{p.reads()}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
