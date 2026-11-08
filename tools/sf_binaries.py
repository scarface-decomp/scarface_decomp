#!/usr/bin/env python3
"""
Readers for the retail binaries (PE Scarface.exe, Xbox default.xbe / game.xbe) and a
recursive-descent function-extent finder used to size functions for the work queue.

Nothing here modifies the binaries; they are only read.
"""

from __future__ import annotations

import hashlib
import struct
from dataclasses import dataclass, field
from pathlib import Path
from typing import Dict, Iterable, List, Optional, Set, Tuple

__all__ = ["Section", "BinaryImage", "function_extent", "collect_call_targets", "Extent"]


@dataclass(frozen=True)
class Section:
    name: str
    va: int
    vsize: int
    raw: int
    raw_size: int
    is_code: bool
    library: bool = False      # third-party code linked in (Xbox XDK / Bink sections), not game code


XBE_DATA_SECTIONS = {".rdata", ".data", ".data1", "DOLBY", "BINKDATA", "XON_RD", "XPPDATA"}


class BinaryImage:
    """Read-only view of a PE (.exe) or XBE file, addressed by virtual address."""

    def __init__(self, path: Path | str):
        self.path = Path(path)
        self.data = self.path.read_bytes()
        self.sha256 = hashlib.sha256(self.data).hexdigest()
        if self.data[:4] == b"XBEH":
            self.kind = "xbe"
            self.sections = self._xbe_sections()
        elif self.data[:2] == b"MZ":
            self.kind = "pe"
            self.sections = self._pe_sections()
        else:
            raise ValueError(f"{self.path.name}: not a PE or XBE file")

    # -- parsing ------------------------------------------------------------
    def _pe_sections(self) -> List[Section]:
        d = self.data
        e_lfanew = struct.unpack_from("<I", d, 0x3C)[0]
        nsec = struct.unpack_from("<H", d, e_lfanew + 6)[0]
        opt_sz = struct.unpack_from("<H", d, e_lfanew + 20)[0]
        self.image_base = struct.unpack_from("<I", d, e_lfanew + 52)[0]
        so = e_lfanew + 24 + opt_sz
        out = []
        for i in range(nsec):
            name, vsize, vaddr, rawsz, rawptr = struct.unpack_from("<8sIIII", d, so + i * 40)
            chars = struct.unpack_from("<I", d, so + i * 40 + 36)[0]
            out.append(Section(name.rstrip(b"\0").decode("latin-1"), self.image_base + vaddr, vsize, rawptr, rawsz,
                               bool(chars & 0x20000000) or bool(chars & 0x20)))
        return out

    def _xbe_sections(self) -> List[Section]:
        d = self.data
        base = struct.unpack_from("<I", d, 0x104)[0]
        self.image_base = base
        nsec = struct.unpack_from("<I", d, 0x11C)[0]
        shdr = struct.unpack_from("<I", d, 0x120)[0] - base
        out = []
        for i in range(nsec):
            o = shdr + i * 56
            flags, va, vs, raw, rs = struct.unpack_from("<IIIII", d, o)
            name_off = struct.unpack_from("<I", d, o + 20)[0] - base
            end = d.find(b"\0", name_off)
            name = d[name_off:end].decode("latin-1") if 0 <= name_off < len(d) else f"sec{i}"
            # XBE marks almost every section executable (flag 0x4), .rdata and .data included,
            # so the kind comes from the name.
            is_data = name in XBE_DATA_SECTIONS or name.startswith("$$")
            is_lib = not is_data and name != ".text"
            out.append(Section(name, va, vs, raw, rs, bool(flags & 0x4) and not is_data, is_lib))
        return out

    # -- access ---------------------------------------------------------------
    def section_of(self, va: int) -> Optional[Section]:
        for s in self.sections:
            if s.va <= va < s.va + max(s.vsize, s.raw_size):
                return s
        return None

    def va_to_off(self, va: int) -> Optional[int]:
        s = self.section_of(va)
        if not s or va - s.va >= s.raw_size:
            return None
        return s.raw + (va - s.va)

    def read(self, va: int, n: int) -> Optional[bytes]:
        """n bytes at va, or None if any of them is outside the file's raw data."""
        off = self.va_to_off(va)
        if off is None or n < 0:
            return None
        s = self.section_of(va)
        if va + n > s.va + s.raw_size:
            return None
        return self.data[off:off + n]

    def code_sections(self) -> List[Section]:
        return [s for s in self.sections if s.is_code]

    def game_code_sections(self) -> List[Section]:
        """Code written by the game's developers: excludes the Xbox XDK / Bink library sections."""
        return [s for s in self.sections if s.is_code and not s.library]


# --------------------------------------------------------------------------- #
# Function extents
# --------------------------------------------------------------------------- #

@dataclass
class Extent:
    start: int
    size: int
    ok: bool
    reason: str = ""
    has_jump_table: bool = False
    tail_calls: List[int] = field(default_factory=list)


def _cs():
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    md.skipdata = False
    return md


def collect_call_targets(img: BinaryImage) -> Set[int]:
    """Targets of every E8 rel32 that lands inside an executable section (cheap byte scan, no decoding)."""
    targets: Set[int] = set()
    for s in img.code_sections():
        blob = img.data[s.raw:s.raw + s.raw_size]
        lo, hi = s.va, s.va + s.raw_size
        i = blob.find(b"\xE8")
        while i != -1 and i + 5 <= len(blob):
            rel = struct.unpack_from("<i", blob, i + 1)[0]
            tgt = s.va + i + 5 + rel
            if lo <= tgt < hi:
                targets.add(tgt)
            i = blob.find(b"\xE8", i + 1)
    return targets


def function_extent(img: BinaryImage, start: int, known_starts: Optional[Set[int]] = None,
                    max_size: int = 0x4000) -> Extent:
    """
    Size a function by recursive descent: follow conditional and unconditional jumps that stay
    inside the function, stop paths at ret / int3 / jumps to other known function starts, and
    include jump tables MSVC places right after the code.
    """
    import capstone
    from capstone import x86_const as X

    known_starts = known_starts or set()
    sec = img.section_of(start)
    if not sec:
        return Extent(start, 0, False, "address not in any section")
    limit = min(sec.va + sec.raw_size, start + max_size)
    blob = img.read(start, limit - start)
    if not blob:
        return Extent(start, 0, False, "address not backed by file data")
    if blob[0] in (0xCC, 0x00):
        return Extent(start, 0, False, "starts with padding")

    md = _cs()
    work = [start]
    seen: Set[int] = set()
    end = start
    tables: List[Tuple[int, int]] = []
    tails: List[int] = []
    bad = ""

    def inside(t: int) -> bool:
        return start <= t < limit and (t == start or t not in known_starts)

    idx_tables: List[int] = []
    while work:
        addr = work.pop()
        if addr in seen or not (start <= addr < limit):
            continue
        for insn in md.disasm(blob[addr - start:], addr):
            if insn.address in seen:
                break
            seen.add(insn.address)
            end = max(end, insn.address + insn.size)
            mn = insn.mnemonic
            if mn in ("ret", "retf", "iret", "hlt"):
                break
            if mn == "int3":
                if insn.address == start:
                    bad = "int3 at entry"
                break
            if mn == "movzx" and len(insn.operands) == 2 and insn.operands[1].type == X.X86_OP_MEM:
                m = insn.operands[1].mem
                d = m.disp & 0xFFFFFFFF
                if insn.operands[1].size == 1 and m.base != 0 and start <= d < limit:
                    idx_tables.append(d)        # switch byte-index table
            if insn.group(capstone.CS_GRP_JUMP):
                op = insn.operands[0] if insn.operands else None
                if op is not None and op.type == X.X86_OP_IMM:
                    tgt = op.imm & 0xFFFFFFFF
                    if mn == "jmp":
                        if inside(tgt):
                            work.append(tgt)
                        else:
                            tails.append(tgt)
                        break
                    if inside(tgt):            # conditional jump: follow both edges
                        work.append(tgt)
                    continue
                if op is not None and op.type == X.X86_OP_MEM and mn == "jmp":
                    m = op.mem
                    tva = m.disp & 0xFFFFFFFF
                    if m.index != 0 and m.scale == 4 and m.base == 0 and start <= tva < limit:
                        n = 0
                        while n < 1024:
                            ent = img.read(tva + 4 * n, 4)
                            if not ent:
                                break
                            t = struct.unpack("<I", ent)[0]
                            if not (start <= t < limit):
                                break
                            work.append(t)
                            n += 1
                        if n:
                            tables.append((tva, tva + 4 * n))
                break                           # indirect jmp ends this path

    if bad:
        return Extent(start, 0, False, bad)

    # MSVC emits the dword jump table, then the optional byte index table, right after the code.
    has_table = bool(tables)
    n_cases = max((te - tv) // 4 for tv, te in tables) if tables else 0
    for tva, tend in sorted(tables):
        if end <= tva <= end + 3:              # alignment padding before the table
            end = max(end, tend)
    for itv in sorted(set(idx_tables)):
        if end <= itv <= end + 3 and n_cases:
            k = 0
            while itv + k < limit and (itv + k) not in known_starts:
                b = img.read(itv + k, 1)
                if not b or b[0] >= n_cases:
                    break
                k += 1
            end = max(end, itv + k)
    size = end - start
    if size <= 0:
        return Extent(start, 0, False, "no instructions decoded")
    return Extent(start, size, True, "", has_table, tails)
