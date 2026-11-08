#!/usr/bin/env python3
"""
Scarface's compiled TorqueScript files (.cso, .dso): read them exactly, and write them back.

This is step 2 of docs/SCRIPTS.md. A file is taken apart into its pieces and put back together, and
the result must be byte-identical to the original before anything is built on top of it. On the 635
compiled scripts in the PS2 release's cement.rcf, every one round-trips exactly.

Layout (little-endian; documented by Broken Face and Meth0d, see docs/CREDITS.md):

    u32 version                       always 1 in Scarface
    u32 size, bytes                   global string table: NUL-terminated strings
    u32 count, f32[count]             global float table
    u32 size, bytes                   function string table
    u32 count, f32[count]             function float table
    u32 count, codes[count]           bytecode: a code is one byte, or 0xFF + u16 for values >= 0xFF
    u32 count, idents[count]          identifier table: u32 string offset, u32 n, u32 code index[n]
                                      (the string offsets the engine patches into the bytecode on load)

Nothing follows the identifier table. The values left at the patch locations in the file are whatever
the compiler wrote there (often 0xCDCD, MSVC's fill pattern), so they are kept as they are.
"""

from __future__ import annotations

import struct
from dataclasses import dataclass, field
from typing import Dict, List, Tuple


class DsoError(ValueError):
    pass


@dataclass
class CompiledScript:
    version: int
    global_strings: bytes
    global_floats: List[float]
    function_strings: bytes
    function_floats: List[float]
    codes: List[int]
    idents: List[Tuple[int, List[int]]] = field(default_factory=list)
    _gf_raw: bytes = b""
    _ff_raw: bytes = b""

    @staticmethod
    def strings(table: bytes) -> Dict[int, str]:
        """{offset: string} for a string table."""
        out, pos = {}, 0
        while pos < len(table):
            end = table.find(b"\0", pos)
            end = len(table) if end < 0 else end
            out[pos] = table[pos:end].decode("latin-1")
            pos = end + 1
        return out


def parse(raw: bytes) -> CompiledScript:
    pos = 0

    def u32() -> int:
        nonlocal pos
        if pos + 4 > len(raw):
            raise DsoError(f"file ends inside a number at byte {pos}")
        v = struct.unpack_from("<I", raw, pos)[0]
        pos += 4
        return v

    def take(n: int, what: str) -> bytes:
        nonlocal pos
        if n > len(raw) - pos:
            raise DsoError(f"{what} needs {n:,} bytes at byte {pos}, only {len(raw) - pos:,} left")
        b = raw[pos:pos + n]
        pos += n
        return b

    version = u32()
    gstr = take(u32(), "global string table")
    ng = u32()
    gf_raw = take(4 * ng, "global float table")
    fstr = take(u32(), "function string table")
    nf = u32()
    ff_raw = take(4 * nf, "function float table")
    ncode = u32()
    codes: List[int] = []
    for _ in range(ncode):
        if pos >= len(raw):
            raise DsoError(f"bytecode ends after {len(codes):,} of {ncode:,} codes")
        b = raw[pos]
        if b == 0xFF:
            if pos + 3 > len(raw):
                raise DsoError("bytecode ends inside a 2-byte code")
            v = struct.unpack_from("<H", raw, pos + 1)[0]
            if v < 0xFF:
                raise DsoError(f"code {len(codes)} is escaped although it fits in a byte; not seen in Scarface")
            codes.append(v)
            pos += 3
        else:
            codes.append(b)
            pos += 1
    idents = []
    for _ in range(u32()):
        off, n = u32(), u32()
        if n > ncode:
            raise DsoError(f"identifier entry lists {n:,} locations but the bytecode has {ncode:,} codes")
        idents.append((off, [u32() for _ in range(n)]))
    if pos != len(raw):
        raise DsoError(f"{len(raw) - pos:,} unexpected bytes after the identifier table")
    return CompiledScript(version, gstr, list(struct.unpack(f"<{ng}f", gf_raw)), fstr,
                          list(struct.unpack(f"<{nf}f", ff_raw)), codes, idents, gf_raw, ff_raw)


def build(s: CompiledScript) -> bytes:
    gf = s._gf_raw if len(s._gf_raw) == 4 * len(s.global_floats) else struct.pack(f"<{len(s.global_floats)}f", *s.global_floats)
    ff = s._ff_raw if len(s._ff_raw) == 4 * len(s.function_floats) else struct.pack(f"<{len(s.function_floats)}f", *s.function_floats)
    out = bytearray(struct.pack("<I", s.version))
    out += struct.pack("<I", len(s.global_strings)) + s.global_strings
    out += struct.pack("<I", len(s.global_floats)) + gf
    out += struct.pack("<I", len(s.function_strings)) + s.function_strings
    out += struct.pack("<I", len(s.function_floats)) + ff
    out += struct.pack("<I", len(s.codes))
    for c in s.codes:
        if not 0 <= c <= 0xFFFF:
            raise DsoError(f"code value {c} does not fit in 16 bits")
        out += bytes([c]) if c < 0xFF else b"\xff" + struct.pack("<H", c)
    out += struct.pack("<I", len(s.idents))
    for off, locs in s.idents:
        out += struct.pack("<II", off, len(locs)) + b"".join(struct.pack("<I", l) for l in locs)
    return bytes(out)


def round_trip(raw: bytes) -> Tuple[bool, str]:
    """(exact, message): whether the file is read completely and rebuilt byte for byte."""
    try:
        s = parse(raw)
    except DsoError as e:
        return False, str(e)
    again = build(s)
    if again == raw:
        return True, "rebuilt byte for byte"
    first = next((i for i, (a, b) in enumerate(zip(again, raw)) if a != b), min(len(again), len(raw)))
    return False, f"rebuilt file differs from byte {first}"


def listing(raw: bytes, name: str = "script.cso") -> str:
    """A readable account of what the file holds: its strings, numbers and size. Not a decompilation."""
    s = parse(raw)
    ok, msg = round_trip(raw)
    g, f = CompiledScript.strings(s.global_strings), CompiledScript.strings(s.function_strings)
    lines = [
        f"// {name}: compiled TorqueScript v{s.version}, {len(raw):,} bytes, {len(s.codes):,} codes",
        f"// Exact round trip: {'yes, ' if ok else 'NO, '}{msg}.",
        "// Turning the bytecode into readable TorqueScript is the next step (docs/SCRIPTS.md).",
        "",
        f"// Global strings ({len(g)})",
    ]
    lines += [f"//   [{off:5d}] {text!r}" for off, text in g.items()]
    lines += ["", f"// Function strings ({len(f)})"]
    lines += [f"//   [{off:5d}] {text!r}" for off, text in f.items()]
    if s.global_floats or s.function_floats:
        lines += ["", "// Floats: global " + ", ".join(f"{v:g}" for v in s.global_floats)
                  + "; function " + ", ".join(f"{v:g}" for v in s.function_floats)]
    lines += ["", f"// Identifier references: {len(s.idents)} strings patched into "
              f"{sum(len(l) for _, l in s.idents)} places in the bytecode"]
    return "\n".join(lines)


def hex_codes(s: CompiledScript, per_line: int = 16) -> str:
    rows = []
    for i in range(0, len(s.codes), per_line):
        rows.append(f"{i:05d}  " + " ".join(f"{c:02X}" if c < 0x100 else f"{c:04X}" for c in s.codes[i:i + per_line]))
    return "\n".join(rows)
