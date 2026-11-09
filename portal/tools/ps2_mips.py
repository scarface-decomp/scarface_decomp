#!/usr/bin/env python3
"""
A small MIPS R5900 (PlayStation 2 Emotion Engine) decoder and disassembler, standard library only.

It knows the instructions the game's compiler (Metrowerks CodeWarrior for PS2) writes: integer and
64-bit ALU, loads and stores including the 128-bit lq/sq, branches (normal and "likely"), the FPU with
the R5900 multiply-accumulate forms (mula.s, madda.s, ...), and the second integer pipeline (mult1,
div1, ...). Anything else (the parallel MMI instructions, VU0 macro mode, COP0) is written as
`.word 0x...`, which assembles to the same bytes, so a listing always reassembles to the original.

The text is GNU assembler syntax for `mips-linux-gnu-as -march=r5900`, the assembler decomp.me uses
for its PS2 platform. Real instructions are written instead of assembler macros (`daddu $a0, $s1,
$zero`, not `move`; `div $zero, $a0, $a1`, not `div`), because the macros can expand differently.

    decode(word, pc) -> Ins
    Ins.text(symbols)   GNU syntax, with labels and %hi/%lo symbols filled in by the caller
"""

from __future__ import annotations

from dataclasses import dataclass, field
from typing import Callable, Dict, List, Optional, Tuple

GPR = ["zero", "at", "v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7",
       "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra"]

LOADS = {0x20: "lb", 0x21: "lh", 0x22: "lwl", 0x23: "lw", 0x24: "lbu", 0x25: "lhu", 0x26: "lwr", 0x27: "lwu",
         0x1A: "ldl", 0x1B: "ldr", 0x1E: "lq", 0x37: "ld"}
STORES = {0x28: "sb", 0x29: "sh", 0x2A: "swl", 0x2B: "sw", 0x2C: "sdl", 0x2D: "sdr", 0x2E: "swr", 0x1F: "sq",
          0x3F: "sd"}
FP_MEM = {0x31: "lwc1", 0x39: "swc1"}
VU_MEM = {0x36: "lqc2", 0x3E: "sqc2"}
ALU_IMM_SIGNED = {0x08: "addi", 0x09: "addiu", 0x0A: "slti", 0x0B: "sltiu", 0x18: "daddi", 0x19: "daddiu"}
ALU_IMM_UNSIGNED = {0x0C: "andi", 0x0D: "ori", 0x0E: "xori"}
BRANCH_2 = {0x04: "beq", 0x05: "bne", 0x14: "beql", 0x15: "bnel"}
BRANCH_1 = {0x06: "blez", 0x07: "bgtz", 0x16: "blezl", 0x17: "bgtzl"}
REGIMM = {0x00: "bltz", 0x01: "bgez", 0x02: "bltzl", 0x03: "bgezl", 0x10: "bltzal", 0x11: "bgezal",
          0x12: "bltzall", 0x13: "bgezall"}
LIKELY = {"beql", "bnel", "blezl", "bgtzl", "bltzl", "bgezl", "bltzall", "bgezall", "bc1fl", "bc1tl"}

SHIFT_IMM = {0x00: "sll", 0x02: "srl", 0x03: "sra", 0x38: "dsll", 0x3A: "dsrl", 0x3B: "dsra", 0x3C: "dsll32",
             0x3E: "dsrl32", 0x3F: "dsra32"}
SHIFT_VAR = {0x04: "sllv", 0x06: "srlv", 0x07: "srav", 0x14: "dsllv", 0x16: "dsrlv", 0x17: "dsrav"}
THREE_REG = {0x0A: "movz", 0x0B: "movn", 0x20: "add", 0x21: "addu", 0x22: "sub", 0x23: "subu", 0x24: "and",
             0x25: "or", 0x26: "xor", 0x27: "nor", 0x2A: "slt", 0x2B: "sltu", 0x2C: "dadd", 0x2D: "daddu",
             0x2E: "dsub", 0x2F: "dsubu"}

# COP1 single-precision operations: name, operand layout
FPU_S = {0x00: ("add.s", "dst"), 0x01: ("sub.s", "dst"), 0x02: ("mul.s", "dst"), 0x03: ("div.s", "dst"),
         0x04: ("sqrt.s", "dt"), 0x05: ("abs.s", "ds"), 0x06: ("mov.s", "ds"), 0x07: ("neg.s", "ds"),
         0x16: ("rsqrt.s", "dst"), 0x18: ("adda.s", "st"), 0x19: ("suba.s", "st"), 0x1A: ("mula.s", "st"),
         0x1C: ("madd.s", "dst"), 0x1D: ("msub.s", "dst"), 0x1E: ("madda.s", "st"), 0x1F: ("msuba.s", "st"),
         0x24: ("trunc.w.s", "ds"), 0x28: ("max.s", "dst"), 0x29: ("min.s", "dst"), 0x30: ("c.f.s", "st"),
         0x32: ("c.eq.s", "st"), 0x34: ("c.lt.s", "st"), 0x36: ("c.le.s", "st")}


def _s16(v: int) -> int:
    return v - 0x10000 if v & 0x8000 else v


def _hex(v: int) -> str:
    return f"-0x{-v:X}" if v < 0 else f"0x{v:X}"


@dataclass
class Ins:
    """One decoded instruction. `ops` holds operand tokens; text() turns them into GNU syntax."""
    addr: int
    word: int
    mn: str                                  # mnemonic, or ".word"
    ops: List[tuple] = field(default_factory=list)
    target: Optional[int] = None             # branch or jump destination
    kind: str = ""                           # "branch", "jump", "call", "jr", "jalr", or ""
    likely: bool = False
    hi_reg: Optional[int] = None             # lui: the register it sets
    lo_base: Optional[int] = None            # an instruction whose 16-bit immediate can be a %lo()
    imm: int = 0
    writes: Tuple[int, ...] = ()             # general registers written

    @property
    def has_delay_slot(self) -> bool:
        return self.kind in ("branch", "jump", "call", "jr", "jalr")

    @property
    def is_raw(self) -> bool:
        return self.mn == ".word"

    def text(self, label: Optional[Callable[[int], Optional[str]]] = None,
             reloc: Optional[str] = None) -> str:
        """GNU syntax. label(addr) names a branch/jump destination (None: write a .word instead).
        reloc is "%hi(sym)" for a lui or "%lo(sym)" for a lo user, replacing the number."""
        if self.mn == ".word":
            return f".word 0x{self.word:08X}"
        parts = []
        for op in self.ops:
            k = op[0]
            if k == "r":
                parts.append("$" + GPR[op[1]])
            elif k == "f":
                parts.append(f"$f{op[1]}")
            elif k == "vf":
                parts.append(f"$vf{op[1]}")
            elif k == "imm":
                parts.append(reloc if reloc and op[2] else _hex(op[1]))
            elif k == "uimm":
                parts.append(reloc if reloc and op[2] else f"0x{op[1]:X}")
            elif k == "dec":
                parts.append(str(op[1]))
            elif k == "mem":
                off = reloc if reloc else _hex(op[1])
                parts.append(f"{off}($" + GPR[op[2]] + ")")
            elif k == "tgt":
                name = label(op[1]) if label else None
                if name is None:
                    return f".word 0x{self.word:08X}"
                parts.append(name)
        return f"{self.mn} {', '.join(parts)}" if parts else self.mn


def _raw(addr: int, word: int) -> Ins:
    return Ins(addr, word, ".word")


def decode(word: int, pc: int) -> Ins:
    op = word >> 26
    rs, rt, rd, sa, fn = (word >> 21) & 31, (word >> 16) & 31, (word >> 11) & 31, (word >> 6) & 31, word & 63
    imm = word & 0xFFFF
    simm = _s16(imm)
    btarget = (pc + 4 + (simm << 2)) & 0xFFFFFFFF

    if word == 0:
        return Ins(pc, word, "nop")
    if op == 0x00:
        if fn in SHIFT_IMM and rs == 0:
            return Ins(pc, word, SHIFT_IMM[fn], [("r", rd), ("r", rt), ("dec", sa)], writes=(rd,))
        if sa:
            return _raw(pc, word)
        if fn in SHIFT_VAR:
            return Ins(pc, word, SHIFT_VAR[fn], [("r", rd), ("r", rt), ("r", rs)], writes=(rd,))
        if fn in THREE_REG:
            return Ins(pc, word, THREE_REG[fn], [("r", rd), ("r", rs), ("r", rt)], writes=(rd,))
        if fn == 0x08 and rt == 0 and rd == 0:
            return Ins(pc, word, "jr", [("r", rs)], kind="jr")
        if fn == 0x09 and rt == 0 and rd != rs:
            ops = [("r", rs)] if rd == 31 else [("r", rd), ("r", rs)]
            return Ins(pc, word, "jalr", ops, kind="jalr", writes=(rd,))
        if fn in (0x10, 0x12) and rs == 0 and rt == 0:
            return Ins(pc, word, "mfhi" if fn == 0x10 else "mflo", [("r", rd)], writes=(rd,))
        if fn in (0x11, 0x13) and rt == 0 and rd == 0:
            return Ins(pc, word, "mthi" if fn == 0x11 else "mtlo", [("r", rs)])
        if fn in (0x18, 0x19):
            name = "mult" if fn == 0x18 else "multu"
            ops = [("r", rd), ("r", rs), ("r", rt)] if rd else [("r", rs), ("r", rt)]
            return Ins(pc, word, name, ops, writes=(rd,) if rd else ())
        if fn in (0x1A, 0x1B) and rd == 0:
            return Ins(pc, word, "div" if fn == 0x1A else "divu", [("r", 0), ("r", rs), ("r", rt)])
        return _raw(pc, word)
    if op == 0x01:
        if rt in REGIMM:
            name = REGIMM[rt]
            return Ins(pc, word, name, [("r", rs), ("tgt", btarget)], target=btarget, kind="branch",
                       likely=name in LIKELY, writes=(31,) if "al" in name else ())
        return _raw(pc, word)
    if op in (0x02, 0x03):
        t = ((pc + 4) & 0xF0000000) | ((word & 0x03FFFFFF) << 2)
        return Ins(pc, word, "j" if op == 2 else "jal", [("tgt", t)], target=t,
                   kind="jump" if op == 2 else "call", writes=(31,) if op == 3 else ())
    if op in BRANCH_2:
        name = BRANCH_2[op]
        return Ins(pc, word, name, [("r", rs), ("r", rt), ("tgt", btarget)], target=btarget, kind="branch",
                   likely=name in LIKELY)
    if op in BRANCH_1:
        if rt:
            return _raw(pc, word)
        name = BRANCH_1[op]
        return Ins(pc, word, name, [("r", rs), ("tgt", btarget)], target=btarget, kind="branch",
                   likely=name in LIKELY)
    if op in ALU_IMM_SIGNED:
        lo = op in (0x09, 0x19)                      # addiu/daddiu can carry a %lo()
        return Ins(pc, word, ALU_IMM_SIGNED[op], [("r", rt), ("r", rs), ("imm", simm, lo)],
                   lo_base=rs if lo else None, imm=simm, writes=(rt,))
    if op in ALU_IMM_UNSIGNED:
        return Ins(pc, word, ALU_IMM_UNSIGNED[op], [("r", rt), ("r", rs), ("uimm", imm, False)], imm=imm,
                   writes=(rt,))
    if op == 0x0F:
        if rs:
            return _raw(pc, word)
        return Ins(pc, word, "lui", [("r", rt), ("uimm", imm, True)], hi_reg=rt, imm=imm, writes=(rt,))
    if op in LOADS:
        return Ins(pc, word, LOADS[op], [("r", rt), ("mem", simm, rs)], lo_base=rs, imm=simm, writes=(rt,))
    if op in STORES:
        return Ins(pc, word, STORES[op], [("r", rt), ("mem", simm, rs)], lo_base=rs, imm=simm)
    if op in FP_MEM:
        return Ins(pc, word, FP_MEM[op], [("f", rt), ("mem", simm, rs)], lo_base=rs, imm=simm)
    if op in VU_MEM:
        return Ins(pc, word, VU_MEM[op], [("vf", rt), ("mem", simm, rs)], lo_base=rs, imm=simm)
    if op == 0x11:
        return _cop1(pc, word, rs, rt, rd, sa, fn, btarget)
    if op == 0x1C:
        return _mmi(pc, word, rs, rt, rd, sa, fn)
    return _raw(pc, word)


def _cop1(pc: int, word: int, rs: int, rt: int, fs: int, fd: int, fn: int, btarget: int) -> Ins:
    low = word & 0x7FF
    if rs in (0, 4) and low == 0:
        return Ins(pc, word, "mfc1" if rs == 0 else "mtc1", [("r", rt), ("f", fs)], writes=(rt,) if rs == 0 else ())
    if rs in (2, 6) and low == 0:
        return Ins(pc, word, "cfc1" if rs == 2 else "ctc1", [("r", rt), ("dec", fs)], writes=(rt,) if rs == 2 else ())
    if rs == 8 and rt in (0, 1, 2, 3):
        name = ("bc1f", "bc1t", "bc1fl", "bc1tl")[rt]
        return Ins(pc, word, name, [("tgt", btarget)], target=btarget, kind="branch", likely=name in LIKELY)
    if rs == 16 and fn in FPU_S:
        name, lay = FPU_S[fn]
        ft = rt
        if lay == "dst":
            ops = [("f", fd), ("f", fs), ("f", ft)]
        elif lay == "dt":
            # The R5900 reads sqrt.s's operand from ft, but GNU as writes it into fs, so only the
            # $f0 case reassembles to the same bytes; anything else stays .word.
            if fs or ft:
                return _raw(pc, word)
            ops = [("f", fd), ("f", 0)]
        elif lay == "ds":
            if ft:
                return _raw(pc, word)
            ops = [("f", fd), ("f", fs)]
        else:                                        # "st": accumulator forms and compares
            if fd:
                return _raw(pc, word)
            ops = [("f", fs), ("f", ft)]
        return Ins(pc, word, name, ops)
    if rs == 20 and fn == 0x20 and rt == 0:
        return Ins(pc, word, "cvt.s.w", [("f", fd), ("f", fs)])
    return _raw(pc, word)


def _mmi(pc: int, word: int, rs: int, rt: int, rd: int, sa: int, fn: int) -> Ins:
    """The few MMI-space instructions with plain integer meanings; the parallel ones stay .word."""
    if sa:
        return _raw(pc, word)
    if fn in (0x00, 0x01, 0x20, 0x21, 0x18, 0x19):
        name = {0x00: "madd", 0x01: "maddu", 0x20: "madd1", 0x21: "maddu1", 0x18: "mult1", 0x19: "multu1"}[fn]
        ops = [("r", rd), ("r", rs), ("r", rt)] if rd else [("r", rs), ("r", rt)]
        return Ins(pc, word, name, ops, writes=(rd,) if rd else ())
    if fn in (0x1A, 0x1B) and rd == 0:
        return Ins(pc, word, "div1" if fn == 0x1A else "divu1", [("r", 0), ("r", rs), ("r", rt)])
    if fn in (0x10, 0x12) and rs == 0 and rt == 0:
        return Ins(pc, word, "mfhi1" if fn == 0x10 else "mflo1", [("r", rd)], writes=(rd,))
    if fn in (0x11, 0x13) and rt == 0 and rd == 0:
        return Ins(pc, word, "mthi1" if fn == 0x11 else "mtlo1", [("r", rs)])
    return _raw(pc, word)


def ends_path(ins: Ins) -> bool:
    """After this instruction (and its delay slot) the code does not fall through."""
    if ins.kind == "jr":
        return True
    if ins.kind == "jump":
        return True
    if ins.mn == "beq" and ins.word >> 16 == 0x1000:            # beq $zero, $zero: an unconditional branch
        return True
    return False
