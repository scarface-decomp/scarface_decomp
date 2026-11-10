#!/usr/bin/env python3
"""
The PS2 game program, SLUS_211.11 (US), read for the PS2 lane of the decomp: where its functions are,
how big they are, which of them are the game's own code, and each one written out as GNU assembly
for decomp.me.

The program is a plain ELF for the Emotion Engine (MIPS R5900). It has no symbol names, so:

* functions are found from what the code itself says: every `jal`/`j` target, every function address
  stored in the data (virtual function tables, callbacks), every function address built with
  `lui`/`addiu`, and whatever starts right after another function ends;
* each function's size is found by following its branches (recursive descent), so padding between
  functions is not counted;
* the game's code was built with Metrowerks CodeWarrior, which never writes "branch likely"
  instructions; the Sony libraries linked in (built with GCC) use them all the time. Functions with
  them are marked as library code and left out of the work queue.

Addresses inside a function's machine code (calls, globals, strings) are found from the code: `jal`
targets, `lui`/`%lo` pairs and `$gp`-relative accesses. They are written as symbols (func_XXXXXXXX,
D_XXXXXXXX), the names the PS2 decomp convention uses, so a C++ guess that names them the same way
links to the same places.

    Ps2Image(path)                         the program, addressed by virtual address
    find_functions(img) -> {va: Func}      every function, with size and whether it is game code
    function_asm(img, va, size, name)      GNU assembly of one function, ready for decomp.me
"""

from __future__ import annotations

import hashlib
import re
import struct
from dataclasses import dataclass, field
from pathlib import Path
from typing import Dict, Iterable, List, Optional, Set, Tuple

from ps2_mips import GPR, Ins, decode, ends_path

PS2_NAME = "SLUS_211.11"
PT_LOAD = 1
JR_RA = 0x03E00008


@dataclass(frozen=True)
class Segment:
    va: int
    off: int
    filesz: int
    memsz: int
    flags: int

    @property
    def is_exec(self) -> bool:
        return bool(self.flags & 1)


class Ps2Image:
    """Read-only view of a PS2 ELF program, addressed by virtual address."""

    kind = "ps2"

    def __init__(self, path):
        self.path = Path(path)
        self.data = self.path.read_bytes()
        self.sha256 = hashlib.sha256(self.data).hexdigest()
        d = self.data
        if d[:4] != b"\x7fELF" or d[4] != 1 or d[5] != 1 or struct.unpack_from("<H", d, 18)[0] != 8:
            raise ValueError(f"{self.path.name}: not a 32-bit little-endian MIPS ELF program")
        self.entry = struct.unpack_from("<I", d, 0x18)[0]
        phoff = struct.unpack_from("<I", d, 0x1C)[0]
        phent, phnum = struct.unpack_from("<HH", d, 0x2A)
        segs = []
        for i in range(phnum):
            typ, off, va, _pa, filesz, memsz, flags, _align = struct.unpack_from("<8I", d, phoff + i * phent)
            if typ == PT_LOAD and (filesz or memsz):
                segs.append(Segment(va, off, filesz, memsz, flags))
        self.segments = segs
        self._main = max((s for s in segs if s.is_exec and s.filesz), key=lambda s: s.filesz)
        # the segment the program starts in (start-up code and libraries), if it isn't the main one
        self._lib_segment = next((s for s in segs if s.va <= self.entry < s.va + s.filesz), None)
        self.code_start, self.code_end = self._code_bounds()
        self.gp = self._find_gp()
        lo = min(s.va for s in segs)
        hi = max(s.va + s.memsz for s in segs if s.va < 0x01000000)      # leave out the scratchpad (0x70000000)
        self.lo, self.hi = lo, hi
        self._extra_code: List[Tuple[int, int]] = []     # code that is not this image's own (see with_overlay)
        self._scan = segs                                 # segments searched for stored function addresses

    @classmethod
    def with_overlay(cls, base: "Ps2Image", overlay: bytes, name: str = "") -> "Ps2Image":
        """The program with one of its code overlays loaded at the overlay's address (CEMENT.RCF/Overlays,
        portal/tools/ps2_overlay.py). The overlay's code is this image's own code: find_functions() finds
        its functions only. Calls and data references can still reach the program's functions and globals,
        so they get the same func_/D_ names as in the program."""
        if overlay[:4] != b"MWo3" or len(overlay) < 0x40:
            raise ValueError(f"{name or 'overlay'}: not a CodeWarrior overlay (MWo3)")
        load, text, _data, bss = struct.unpack_from("<4I", overlay, 8)
        img = cls.__new__(cls)
        img.path = Path(name or "overlay.bin")
        img.data = base.data + overlay
        img.sha256 = hashlib.sha256(overlay).hexdigest()
        img.entry = base.entry
        seg = Segment(load, len(base.data), len(overlay), len(overlay) + bss, 7)
        img.segments = [seg] + [s for s in base.segments if s.filesz]
        img._main = seg
        img._lib_segment = base._lib_segment
        start, end = load + 0x40, load + 0x40 + text
        while start < end and not overlay[start - load:start - load + 16].strip(b"\0"):
            start += 16                                   # the code section starts with zero padding
        img.code_start, img.code_end = start, end
        img.gp = base.gp
        img.lo, img.hi = min(base.lo, load), max(base.hi, load + len(overlay) + bss)
        img._extra_code = [(base.code_start, base.code_end)]
        # The overlays were linked together with the program, whose data holds their virtual tables: look
        # for stored function addresses there too (only the ones that start a function in this overlay count).
        m = base._main
        code = base.code_end - m.va
        data = Segment(base.code_end, m.off + code, m.filesz - code, m.memsz - code, m.flags)
        img._scan = [seg, data] + [s for s in base.segments if s.filesz and s not in (m, base._lib_segment)]
        img.base = base
        return img

    # -- reading ---------------------------------------------------------------
    def segment_of(self, va: int) -> Optional[Segment]:
        for s in self.segments:
            if s.va <= va < s.va + s.filesz:
                return s
        return None

    def read(self, va: int, n: int) -> Optional[bytes]:
        s = self.segment_of(va)
        if s is None or va + n > s.va + s.filesz:
            return None
        o = s.off + (va - s.va)
        return self.data[o:o + n]

    def word(self, va: int) -> int:
        b = self.read(va, 4)
        return struct.unpack("<I", b)[0] if b else 0

    def words(self, va: int, n: int) -> Tuple[int, ...]:
        b = self.read(va, 4 * n) or b""
        return struct.unpack(f"<{len(b) // 4}I", b)

    def in_image(self, va: int) -> bool:
        return self.lo <= va < self.hi

    def is_game_code(self, va: int) -> bool:
        return self.code_start <= va < self.code_end

    def is_code(self, va: int) -> bool:
        """Code anywhere in the program: the game's, or the start-up code and libraries in front of it."""
        if self.is_game_code(va) or any(lo <= va < hi for lo, hi in self._extra_code):
            return True
        s = self.segment_of(va)
        return bool(s and s.is_exec and s is not self._main and s.va < self.code_start
                    and va < s.va + s.filesz and s is self._lib_segment)

    # -- layout ---------------------------------------------------------------
    def _code_bounds(self) -> Tuple[int, int]:
        """The main program segment holds the code first and the data after it: the code ends after the
        last `jr $ra` that is followed by padding or another function."""
        s = self._main
        w = struct.unpack_from(f"<{s.filesz // 4}I", self.data, s.off)
        last = max((i for i, x in enumerate(w) if x == JR_RA), default=0)
        end = s.va + 4 * (last + 2)
        return s.va, (end + 15) & ~15

    def _find_gp(self) -> int:
        """$gp as the start-up code sets it (`lui`/`addiu` into a register, then `daddu $gp, reg, $zero`)."""
        vals: Dict[int, int] = {}
        pc = self.entry
        for _ in range(96):
            w = self.word(pc)
            ins = decode(w, pc)
            if ins.mn == "lui":
                vals[ins.hi_reg] = ins.imm << 16
            elif ins.mn in ("addiu", "daddiu") and ins.lo_base in vals:
                vals[ins.writes[0]] = (vals[ins.lo_base] + ins.imm) & 0xFFFFFFFF
            elif ins.mn in ("daddu", "addu", "or") and ins.writes and ins.writes[0] == 28:
                src = ins.ops[1][1] if ins.ops[2][1] == 0 else ins.ops[2][1]
                if src in vals:
                    return vals[src]
            elif ins.writes and ins.writes[0] == 28 and ins.mn in ("addiu", "daddiu") and 28 in vals:
                return vals[28]
            pc += 4
        return 0


@dataclass
class Func:
    va: int
    size: int
    library: bool = False            # built with GCC (a Sony library), not CodeWarrior: not in the queue
    jump_table: bool = False
    called: bool = False
    how: str = ""                    # how the start was found


# --------------------------------------------------------------------------- #
# Finding functions
# --------------------------------------------------------------------------- #

def _code_words(img: Ps2Image) -> Tuple[int, Tuple[int, ...]]:
    return img.code_start, img.words(img.code_start, (img.code_end - img.code_start) // 4)


def _after_function_end(w: Tuple[int, ...], k: int) -> bool:
    """Index k (a word) sits where a function can start: after padding, or right after the delay slot
    of a `jr $ra` / unconditional jump."""
    if k <= 0:
        return True
    if w[k - 1] == 0:
        return True
    if k >= 2:
        prev = decode(w[k - 2], 0)
        if prev.kind in ("jr", "jump"):
            return True
    return False


def jump_tables(img: Ps2Image) -> Dict[int, int]:
    """{table address: number of entries} for every switch statement in the game code. CodeWarrior writes
    `sltiu $at, $vN, count`, ..., `lui $x, %hi(table)` + `addiu`/`lw %lo(table)`, ..., `jr $vN`; the
    table's entries are places inside that function, not functions of their own."""
    base, w = _code_words(img)
    out: Dict[int, int] = {}
    for i, x in enumerate(w):
        if (x & 0xFC1FFFFF) != 0x00000008 or (x >> 21) & 31 == 31:      # jr $reg, not $ra
            continue
        lo_i = max(0, i - 24)
        win_va = base + 4 * lo_i
        refs = [r for r in references(img, win_va, 4 * (i - lo_i + 1)) if r.kind == "lo"]
        if not refs:
            continue
        table = refs[-1].address
        count = 0
        for j in range(i - 1, lo_i - 1, -1):          # the bound check: sltiu $at, $reg, count
            ins = decode(w[j], base + 4 * j)
            if ins.mn == "sltiu" and ins.imm > 0:
                count = ins.imm
                break
        if not count:                                  # no bound found: take entries while they point near
            pc = base + 4 * i
            for k in range(1024):
                t = img.word(table + 4 * k)
                if not (img.is_game_code(t) and abs(t - pc) < 0x40000):
                    break
                count += 1
        if count:
            out[table] = max(out.get(table, 0), count)
    return out


def call_targets(img: Ps2Image, segments: Optional[List[Segment]] = None) -> Tuple[Set[int], Set[int]]:
    """(jal targets, j targets) inside the game code, from every executable segment (or the ones given)."""
    calls: Set[int] = set()
    jumps: Set[int] = set()
    for s in img.segments if segments is None else segments:
        if not s.is_exec or not s.filesz:
            continue
        w = struct.unpack_from(f"<{s.filesz // 4}I", img.data, s.off)
        for i, x in enumerate(w):
            op = x >> 26
            if op in (2, 3):
                pc = s.va + 4 * i
                t = ((pc + 4) & 0xF0000000) | ((x & 0x03FFFFFF) << 2)
                if img.is_game_code(t):
                    (calls if op == 3 else jumps).add(t)
    return calls, jumps


def _after_a_return(w: Tuple[int, ...], k: int) -> bool:
    """Stricter than _after_function_end: index k follows a `jr`/`j` and its delay slot, with only zero
    padding in between (a `nop` inside a function doesn't count)."""
    j = k - 1
    while j >= 0 and w[j] == 0:
        j -= 1
    if j < 0:
        return True
    for i in (j, j - 1):                                  # the jump itself, or the one before its delay slot
        if i >= 0 and decode(w[i], 0).kind in ("jr", "jump") and i + 1 < k:
            return True
    return False


def data_pointers(img: Ps2Image, tables: Optional[Dict[int, int]] = None) -> Set[int]:
    """Addresses of code stored in the data: virtual function tables and callback tables. Switch jump
    tables are left out (their entries are places inside a function), and so is anything that doesn't
    sit where a function can start."""
    base, w = _code_words(img)
    tables = jump_tables(img) if tables is None else tables
    in_table: Set[int] = set()
    for t, n in tables.items():
        in_table.update(range(t, t + 4 * n, 4))
    out: Set[int] = set()
    for s in img._scan:
        if not s.filesz:
            continue
        lo = s.off
        hi = s.off + s.filesz
        if s is img._main:
            lo = s.off + (img.code_end - s.va)          # only the data part of the main segment
        n = (hi - lo) // 4
        if n <= 0:
            continue
        seg_va = s.va + (lo - s.off)
        # An overlay's virtual tables are in the program's data, among those of the other overlays, which
        # load at the same addresses: an address from there only counts where a function ends right before.
        shared = s is not img._main and img._extra_code
        for idx, x in enumerate(struct.unpack_from(f"<{n}I", img.data, lo)):
            if seg_va + 4 * idx in in_table:
                continue
            if img.is_game_code(x) and x % 16 == 0:          # CodeWarrior aligns functions to 16 bytes
                k = (x - base) // 4
                if _after_a_return(w, k) if shared else _after_function_end(w, k):
                    out.add(x)
    return out


def _extent(w: Tuple[int, ...], base: int, start: int, limit: int) -> Tuple[int, bool, bool]:
    """(end address, has a jump table, uses branch-likely) of the function at start, following branches
    but never past limit (the next known function)."""
    seen: Set[int] = set()
    todo = [start]
    end = start
    jt = likely = False
    while todo:
        pc = todo.pop()
        while base <= pc < limit and pc not in seen:
            seen.add(pc)
            ins = decode(w[(pc - base) // 4], pc)
            end = max(end, pc + 4)
            if ins.likely:
                likely = True
            if ins.has_delay_slot:
                if pc + 4 < limit:
                    seen.add(pc + 4)
                    d = decode(w[(pc + 4 - base) // 4], pc + 4)
                    if d.likely:
                        likely = True
                    end = max(end, pc + 8)
                if ins.kind == "branch" and ins.target is not None and start <= ins.target < limit:
                    todo.append(ins.target)
                if ins.kind == "jr" and ins.ops and ins.ops[0][1] != 31:
                    jt = True                       # a switch: its cases are reached through a table
                if ends_path(ins):
                    break
                pc += 8
                continue
            pc += 4
    return end, jt, likely


def find_functions(img: Ps2Image, extra_starts: Iterable[int] = ()) -> Dict[int, Func]:
    base, w = _code_words(img)
    limit_all = img.code_end
    if img._extra_code:
        # An overlay (Ps2Image.with_overlay): the program calls into all six overlays at the same addresses,
        # so its calls only count where a function ends right before; the overlay's own calls always do.
        calls, jumps = call_targets(img, [img._main])
        pc, pj = call_targets(img, [s for s in img.segments if s is not img._main])
        ok = lambda t: base <= t < limit_all and _after_a_return(w, (t - base) // 4)      # noqa: E731
        calls |= {t for t in pc if ok(t)}
        jumps |= {t for t in pj if ok(t)}
    else:
        calls, jumps = call_targets(img)
    ptrs = data_pointers(img)
    starts: Dict[int, str] = {}
    for t in sorted(ptrs):
        starts[t] = "stored in the data (a vtable or callback)"
    for t in sorted(jumps):
        if _after_function_end(w, (t - base) // 4):     # not a jump inside a function
            starts[t] = "jumped to (a tail call)"
    for t in sorted(calls):
        starts[t] = "called directly"
    for t in extra_starts:
        if img.is_game_code(t):
            starts.setdefault(t, "listed in reports/extra_function_starts.json")
    starts.setdefault(base, "start of the code")
    starts = {va: how for va, how in starts.items() if base <= va < limit_all}
    funcs: Dict[int, Func] = {}
    order = sorted(starts)
    i = 0
    while i < len(order):
        va = order[i]
        nxt = order[i + 1] if i + 1 < len(order) else limit_all
        end, jt, likely = _extent(w, base, va, nxt)
        if jt:
            # a switch's cases can't all be followed: take everything up to the next function,
            # less the padding (but keep a delay slot that happens to be a nop)
            end = nxt
            while end - 4 > va and w[(end - 4 - base) // 4] == 0:
                end -= 4
            if decode(w[(end - 4 - base) // 4], end - 4).has_delay_slot:
                end += 4
        if any(w[(va - base) // 4:(end - base) // 4]):          # all zeros is padding, never a function
            funcs[va] = Func(va, end - va, library=likely, jump_table=jt, called=va in calls, how=starts[va])
        # whatever starts after this function's end and before the next known one is a function too
        k = (end - base) // 4
        while k < (nxt - base) // 4 and w[k] == 0:
            k += 1
        gap = base + 4 * k
        if gap < nxt and gap % 8 == 0 and gap not in starts:
            starts[gap] = "found right after the function before it"
            order.insert(i + 1, gap)
        i += 1
    _mark_libraries(funcs)
    return funcs


def _mark_libraries(funcs: Dict[int, Func]) -> None:
    """GCC-built library code comes in runs (one library at a time). A function with no branch-likely of its
    own that sits between two library functions, with no game function in between, is library code too;
    so is one that is 8- but not 16-byte aligned (CodeWarrior aligns every function to 16 bytes)."""
    order = sorted(funcs)
    for va in order:
        if va % 16:
            funcs[va].library = True
    lib = [funcs[v].library for v in order]
    i = 0
    while i < len(order):
        if lib[i]:
            j = i + 1
            while j < len(order) and not lib[j]:
                j += 1
            if j < len(order) and j - i - 1 <= 8:     # a short gap between two library functions
                for k in range(i + 1, j):
                    funcs[order[k]].library = True
            i = j
        else:
            i += 1


# --------------------------------------------------------------------------- #
# Addresses inside a function, and its assembly
# --------------------------------------------------------------------------- #

@dataclass(frozen=True)
class Ref:
    """An address field in a function: offset of the instruction from the function start,
    kind "26" (jal/j), "hi" (lui), "lo" (the %lo user) or "gp" ($gp-relative), and the address."""
    offset: int
    kind: str
    address: int


def func_name(va: int) -> str:
    return f"func_{va:08X}"


def data_name(va: int) -> str:
    return f"D_{va:08X}"


def references(img: Ps2Image, va: int, size: int, code: Optional[bytes] = None) -> List[Ref]:
    """The address fields of one function (see Ref). %hi/%lo pairs are matched in address order: a `lui`
    gives its register an upper half, and the next instructions that add a 16-bit offset to that register
    (addiu, a load or a store) complete the address. `addu reg, reg, x` keeps the pairing (array indexing)."""
    code = code if code is not None else img.read(va, size)
    if not code:
        return []
    w = struct.unpack(f"<{len(code) // 4}I", code[:len(code) // 4 * 4])
    out: List[Ref] = []
    hi: Dict[int, Tuple[int, int]] = {}          # register -> (offset of its lui, upper half)
    used_hi: Dict[int, int] = {}                 # lui offset -> first address it was paired with
    for i, x in enumerate(w):
        pc = va + 4 * i
        ins = decode(x, pc)
        off = 4 * i
        if ins.kind in ("call", "jump") and ins.target is not None:
            out.append(Ref(off, "26", ins.target))
        if ins.lo_base is not None and ins.mn not in ("lui",):
            if ins.lo_base == 28 and img.gp:
                out.append(Ref(off, "gp", (img.gp + ins.imm) & 0xFFFFFFFF))
            elif ins.lo_base in hi:
                lui_off, upper = hi[ins.lo_base]
                addr = (upper + ins.imm) & 0xFFFFFFFF
                if img.in_image(addr):
                    out.append(Ref(off, "lo", addr))
                    if lui_off not in used_hi:
                        used_hi[lui_off] = addr
        if ins.hi_reg is not None:
            hi[ins.hi_reg] = (off, ins.imm << 16)
        elif ins.writes:
            keep = (ins.mn in ("addu", "daddu") and ins.writes[0] in hi
                    and ins.writes[0] in (ins.ops[1][1], ins.ops[2][1]))
            for r in ins.writes:
                if not keep and r in hi:
                    del hi[r]
    for lui_off, addr in used_hi.items():
        out.append(Ref(lui_off, "hi", addr))
    return sorted(out, key=lambda r: (r.offset, r.kind))


def function_asm(img: Ps2Image, va: int, size: int, name: str = "",
                 names: Optional[Dict[int, str]] = None) -> str:
    """The function as GNU assembly for decomp.me's PS2 platform (`glabel name`, then one instruction a
    line, branch targets as local labels, addresses as symbols)."""
    code = img.read(va, size)
    if code is None:
        raise ValueError(f"0x{va:08X}+{size} is outside {img.path.name}")
    names = names or {}
    me = name or func_name(va)
    refs = {(r.offset, r.kind): r for r in references(img, va, size, code)}
    w = struct.unpack(f"<{size // 4}I", code)
    targets = set()
    for i, x in enumerate(w):
        ins = decode(x, va + 4 * i)
        if ins.kind == "branch" and ins.target is not None and va <= ins.target < va + size:
            targets.add(ins.target)

    def sym(addr: int) -> str:
        if addr == va:
            return me
        if addr in names:
            return names[addr]
        return func_name(addr) if img.is_code(addr) else data_name(addr)

    def label(addr: int) -> Optional[str]:
        if va <= addr < va + size:
            return me if addr == va else f".L{addr:08X}"
        return sym(addr)

    lines = [f"glabel {me}"]
    for i, x in enumerate(w):
        pc = va + 4 * i
        ins = decode(x, pc)
        off = 4 * i
        reloc = None
        if (off, "hi") in refs:
            reloc = f"%hi({sym(refs[(off, 'hi')].address)})"
        elif (off, "lo") in refs:
            reloc = f"%lo({sym(refs[(off, 'lo')].address)})"
        elif (off, "gp") in refs:
            reloc = f"%gp_rel({sym(refs[(off, 'gp')].address)})"
        if pc in targets:
            lines.append(f".L{pc:08X}:")
        if ins.kind == "branch" and ins.target is not None and not (va <= ins.target < va + size):
            text = f".word 0x{x:08X}"            # a branch out of the function: keep the bytes
        else:
            text = ins.text(label, reloc)
        lines.append(f"    {text}")
    return "\n".join(lines) + "\n"


def disassembly_lines(img: Ps2Image, va: int, size: int) -> List[str]:
    """Readable listing for the portal: address, bytes, instruction."""
    code = img.read(va, size) or b""
    refs = {(r.offset, r.kind): r for r in references(img, va, size, code)}
    out = []
    for i in range(len(code) // 4):
        pc = va + 4 * i
        x = struct.unpack_from("<I", code, 4 * i)[0]
        ins = decode(x, pc)

        def label(a: int) -> str:
            if va <= a < va + size:
                return f".L{a:08X}"
            return func_name(a) if img.is_code(a) else f"0x{a:08X}"
        off = 4 * i
        reloc = None
        for kind, fmt in (("hi", "%hi({})"), ("lo", "%lo({})"), ("gp", "%gp_rel({})")):
            if (off, kind) in refs:
                a = refs[(off, kind)].address
                reloc = fmt.format(func_name(a) if img.is_code(a) else data_name(a))
        out.append(f"{pc:08X}  {x:08X}  {ins.text(label, reloc)}")
    return out


def signature(img: Ps2Image, va: int, size: int) -> Tuple[str, List[Ref]]:
    """The function's machine code with every address field blanked, and those fields: two functions with
    the same signature are look-alikes (the same code apart from the addresses it uses)."""
    code = bytearray(img.read(va, size) or b"")
    refs = references(img, va, size, bytes(code))
    for r in refs:
        o = r.offset
        x = struct.unpack_from("<I", code, o)[0]
        x &= 0xFC000000 if r.kind == "26" else 0xFFFF0000
        struct.pack_into("<I", code, o, x)
    return hashlib.sha1(bytes(code)).hexdigest()[:16] + f":{size}", refs


_ADDR_NAME = re.compile(r"^(?:func|sub|D|DAT|jtbl|lbl)_([0-9A-Fa-f]{8})$")


def address_named(name: str) -> Optional[int]:
    """The address a symbol is named after (func_0037A780, D_007A7BF0), or None."""
    m = _ADDR_NAME.match(name or "")
    return int(m.group(1), 16) if m else None


def strings_used(img: Ps2Image, va: int, size: int, min_len: int = 4) -> List[str]:
    """Text the function refers to (string literals), for pairing it with the same function in other builds."""
    out = []
    for r in references(img, va, size):
        if r.kind not in ("lo", "gp"):
            continue
        seg = img.segment_of(r.address)
        if seg is None:
            continue
        b = img.read(r.address, min(200, seg.va + seg.filesz - r.address))
        if not b:
            continue
        end = b.find(b"\0")
        if end < min_len:
            continue
        s = b[:end]
        if all(32 <= c < 127 or c in (9, 10, 13) for c in s):
            out.append(s.decode("ascii"))
    return out


REF_KINDS = {"26": 26, "hi": 5, "lo": 6, "gp": 7}       # the ELF relocation each field becomes


def as_relocs(img: Ps2Image, va: int, size: int):
    """The function's address fields as portal/tools/decompme.Reloc records (offset, symbol, kind), so the
    look-alike tools (portal/tools/lookalikes.py) can pair and port PS2 functions like the others."""
    from decompme import Reloc
    out = []
    for r in references(img, va, size):
        name = (func_name(r.address) if r.address != va else "@self") if img.is_code(r.address) else data_name(r.address)
        out.append(Reloc(r.offset, name, REF_KINDS[r.kind]))
    return out
