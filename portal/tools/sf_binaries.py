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
from typing import Dict, List, Optional, Set, Tuple

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


# Instructions Visual C++ never generates from C++ in 32-bit code. Where one of them is reached from a
# "function" start, the start is really data or the middle of an instruction, and no C++ can match it.
NEVER_COMPILED = frozenset({
    "retf", "iret", "iretd", "into", "bound", "arpl", "les", "lds", "lss", "lfs", "lgs", "daa", "das", "aaa",
    "aas", "aam", "aad", "salc", "int1", "enter", "sal", "pushal", "popal"})
# A path the compiler writes never stops right after one of these (it ends in ret, jmp or a call that
# does not return). Running into padding or the end straight after one means the bytes are not code.
_NOT_A_PATH_END = frozenset({"add", "adc", "sub", "sbb", "inc", "dec", "cmp", "test", "and", "or", "xor",
                             "clc", "stc", "cmc", "hlt"})


def not_compiled_reason(img: "BinaryImage", start: int, size: int) -> str:
    """Why start..start+size cannot be a function the compiler made ("" when it can be). Follows the
    code from the start the way it runs (jump tables are not followed, so their data is never read)."""
    import capstone
    from capstone import x86_const as X

    blob = img.read(start, size)
    if not blob or len(blob) < size:
        return "no file data at this address"
    end = start + size
    md = _cs()
    work = [start]
    seen: Set[int] = set()
    while work:
        addr = work.pop()
        if addr in seen or not (start <= addr < end):
            continue
        prev = None
        for insn in md.disasm(blob[addr - start:], addr):
            if insn.address in seen:
                break
            seen.add(insn.address)
            mn = insn.mnemonic
            if mn in NEVER_COMPILED:
                return f"'{mn}' at +0x{insn.address - start:X}: the compiler never makes that, so these bytes are not a function"
            if mn == "ret" and insn.operands and insn.operands[0].imm % 4:
                # arguments are pushed four bytes at a time, so a function never pops an odd count: these
                # bytes are the middle of another instruction that happens to read as a return
                return (f"'ret 0x{insn.operands[0].imm:X}' at +0x{insn.address - start:X} pops a number of bytes that is "
                        "not a multiple of 4: not a function")
            if mn == "int3" or mn == "ret":
                if mn == "int3" and prev is not None and prev.mnemonic in _NOT_A_PATH_END:
                    return f"runs into padding after '{prev.mnemonic}' at +0x{prev.address - start:X}: not a function"
                break
            if insn.group(capstone.CS_GRP_JUMP):
                op = insn.operands[0] if insn.operands else None
                if op is not None and op.type == X.X86_OP_IMM:
                    work.append(op.imm & 0xFFFFFFFF)
                    if mn == "jmp":
                        break
                    prev = insn
                    continue
                break
            prev = insn
        else:
            stop = prev.address + prev.size if prev is not None else addr
            if stop < end:
                return f"bytes at +0x{stop - start:X} are not an instruction: not a function"
            if prev is not None and prev.mnemonic in _NOT_A_PATH_END:
                return f"ends after '{prev.mnemonic}' without returning: not a function"
    return ""


def instruction_starts(img: "BinaryImage", start: int, size: int) -> Dict[int, int]:
    """{address: length} of every instruction reached by running start..start+size from its start (the
    same walk as not_compiled_reason: jump tables are not followed)."""
    import capstone
    from capstone import x86_const as X

    blob = img.read(start, size)
    if not blob:
        return {}
    end = start + size
    md = _cs()
    work = [start]
    seen: Dict[int, int] = {}
    while work:
        addr = work.pop()
        if addr in seen or not (start <= addr < end):
            continue
        for insn in md.disasm(blob[addr - start:], addr):
            if insn.address in seen:
                break
            seen[insn.address] = insn.size
            if insn.mnemonic in ("ret", "int3"):
                break
            if insn.group(capstone.CS_GRP_JUMP):
                op = insn.operands[0] if insn.operands else None
                if op is not None and op.type == X.X86_OP_IMM:
                    work.append(op.imm & 0xFFFFFFFF)
                    if insn.mnemonic == "jmp":
                        break
                    continue
                break
    return seen


def settle_overlaps(img: "BinaryImage", sizes: Dict[int, int], certain: Set[int], called: Set[int],
                    proven: Set[int]) -> Tuple[Dict[int, int], Set[int]]:
    """Where one function's bytes run over the start of another, work out which of the two is wrong.

    sizes: {start: size} as first measured. certain: starts that are functions beyond doubt (in a table of
    virtual functions). called: starts some call instruction names. proven: starts whose size an exact match
    proved (never changed, never dropped). Returns ({start: corrected size}, {starts that are not functions}).

    * A function measured past a start that is certainly a function (in a virtual table, proven, or called
      and standing right after a return or padding) followed a jump out of itself: it is measured again and
      has to end before that start. A thunk (`sub ecx, 4; jmp method`) measured as thousands of bytes is the
      usual case.
    * A start nobody can vouch for (only a call names it), off the 16-byte boundary functions are placed on,
      that falls in the middle of an instruction of the function around it is not a function: the "call" was
      data or the inside of another instruction that happened to read as one."""
    import bisect

    def after_an_end(va: int) -> bool:
        before = img.read(va - 3, 3) or b"\0\0\0"
        return before[2] in (0xCC, 0xC3, 0x90) or before[0] == 0xC2

    def solid(va: int) -> bool:
        return va in certain or va in proven or (va in called and after_an_end(va))

    known = set(certain) | set(called) | set(proven)
    starts = sorted(sizes)
    new: Dict[int, int] = {}
    for i, va in enumerate(starts):
        if va in proven:
            continue
        end = va + sizes[va]
        j = bisect.bisect_right(starts, va)
        wall = next((s for s in starts[j:bisect.bisect_left(starts, end)] if solid(s)), None)
        if wall is None:
            continue
        e = function_extent(img, va, known, max_size=wall - va)
        if e.ok and 1 <= e.size <= wall - va and not not_compiled_reason(img, va, e.size):
            new[va] = e.size
    size = {**sizes, **new}
    drop: Set[int] = set()
    cover_end, around = 0, None
    walked: Dict[int, Dict[int, int]] = {}
    for va in starts:
        if va < cover_end and around is not None and va % 16 and not around % 16 \
                and va not in certain and va not in proven:
            if around not in walked:
                walked[around] = instruction_starts(img, around, size[around])
            if any(a < va < a + n for a, n in walked[around].items()):
                drop.add(va)
                continue
        if va + size[va] > cover_end:
            cover_end, around = va + size[va], va
    return new, drop


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
