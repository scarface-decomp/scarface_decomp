#!/usr/bin/env python3
"""
Disassembly for the Workbench and the local C++ "starter" synthesizer.

Disassembly uses Capstone when it is installed (`pip install capstone`), otherwise a small
built-in decoder. Both produce lines in ONE format the synthesizer understands:

    +0A: 8B 44 24 04          | mov eax, [esp+0x4]

(memory operands without size prefixes or spaces, displacements in hex). The previous server
printed `[esp+4]` without "|" while the synthesizer looked for `| ... [esp+0x4]`, so the
multi-instruction path never matched anything.
"""

from __future__ import annotations

import re
import struct
from typing import List, Tuple

R32 = ["eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi"]
R8 = ["al", "cl", "dl", "bl", "ah", "ch", "dh", "bh"]
JCC = ["jo", "jno", "jb", "jae", "je", "jne", "jbe", "ja", "js", "jns", "jp", "jnp", "jl", "jge", "jle", "jg"]


def _norm_mem(op: str) -> str:
    """'dword ptr [esp + 4]' -> '[esp+0x4]' (keeps 'byte ptr' etc. only for immediate stores)."""
    def fix(m):
        inner = m.group(1).replace(" ", "")
        inner = re.sub(r"(?:(?<=[+\-])|^)(\d+)(?=$|[+\-*])", lambda d: hex(int(d.group(1))), inner)
        inner = re.sub(r"0x0+([0-9a-f])", r"0x\1", inner)
        return "[" + inner + "]"
    return re.sub(r"\[([^\]]+)\]", fix, op)


def disassemble(code: bytes, base: int = 0) -> List[str]:
    try:
        import capstone
        md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        out = []
        end = 0
        for insn in md.disasm(code, 0):
            ops = insn.op_str
            # Size prefixes are dropped where a register already gives the size, but kept for
            # movzx/movsx and stores of a constant, where they are the only clue.
            keep = insn.mnemonic in ("movzx", "movsx") or "," not in ops or re.search(r",\s*(0x[0-9a-f]+|\d+)$", ops)
            ops = re.sub(r"\b(dword|word|byte|qword|tbyte) ptr (?=\[)", lambda m: m.group(0) if keep else "", ops)
            ops = _norm_mem(ops)
            hx = " ".join(f"{b:02X}" for b in insn.bytes)
            out.append(f"+{insn.address:02X}: {hx:<20} | {insn.mnemonic} {ops}".rstrip())
            end = insn.address + insn.size
        if end < len(code):
            out += _builtin(code[end:], end)
        return out
    except ImportError:
        return _builtin(code, 0)


def _builtin(raw: bytes, start: int) -> List[str]:
    """Fallback decoder for the common MSVC prologue/epilogue/field-access forms."""
    lines: List[str] = []
    i, n = 0, len(raw)
    while i < n:
        b0 = raw[i]
        ins, ln = f"db 0x{b0:02X}", 1
        if b0 == 0xC3:
            ins, ln = "ret", 1
        elif b0 == 0xC2 and i + 3 <= n:
            ins, ln = f"ret 0x{struct.unpack_from('<H', raw, i + 1)[0]:x}", 3
        elif 0x50 <= b0 <= 0x57:
            ins = f"push {R32[b0 - 0x50]}"
        elif 0x58 <= b0 <= 0x5F:
            ins = f"pop {R32[b0 - 0x58]}"
        elif 0xB8 <= b0 <= 0xBF and i + 5 <= n:
            ins, ln = f"mov {R32[b0 - 0xB8]}, 0x{struct.unpack_from('<I', raw, i + 1)[0]:x}", 5
        elif b0 == 0xB0 and i + 2 <= n:
            ins, ln = f"mov al, 0x{raw[i + 1]:x}", 2
        elif b0 in (0xE8, 0xE9) and i + 5 <= n:
            rel = struct.unpack_from("<i", raw, i + 1)[0]
            ins, ln = f"{'call' if b0 == 0xE8 else 'jmp'} rel32 0x{(start + i + 5 + rel) & 0xFFFFFFFF:x}", 5
        elif b0 == 0xEB and i + 2 <= n:
            ins, ln = f"jmp 0x{start + i + 2 + struct.unpack_from('<b', raw, i + 1)[0]:x}", 2
        elif 0x70 <= b0 <= 0x7F and i + 2 <= n:
            ins, ln = f"{JCC[b0 - 0x70]} 0x{start + i + 2 + struct.unpack_from('<b', raw, i + 1)[0]:x}", 2
        elif b0 in (0x89, 0x8B, 0x88, 0x8A, 0x8D, 0x3B, 0x39, 0x85, 0x33, 0x03, 0x2B) and i + 2 <= n:
            dec = _modrm(raw, i + 1)
            if dec:
                mem, reg, mlen = dec
                is8 = b0 in (0x88, 0x8A)
                r = (R8 if is8 else R32)[reg]
                mn = {0x89: "mov", 0x8B: "mov", 0x88: "mov", 0x8A: "mov", 0x8D: "lea", 0x3B: "cmp", 0x39: "cmp",
                      0x85: "test", 0x33: "xor", 0x03: "add", 0x2B: "sub"}[b0]
                if b0 in (0x8B, 0x8A, 0x8D, 0x3B, 0x33, 0x03, 0x2B):
                    ins = f"{mn} {r}, {mem}"
                else:
                    ins = f"{mn} {mem}, {r}"
                ln = 1 + mlen
        elif b0 == 0xC7 and i + 2 <= n:
            dec = _modrm(raw, i + 1)
            if dec and i + 1 + dec[2] + 4 <= n:
                mem, _, mlen = dec
                imm = struct.unpack_from("<I", raw, i + 1 + mlen)[0]
                ins, ln = f"mov dword ptr {mem}, 0x{imm:x}", 1 + mlen + 4
        elif b0 == 0xC6 and i + 2 <= n:
            dec = _modrm(raw, i + 1)
            if dec and i + 1 + dec[2] + 1 <= n:
                mem, _, mlen = dec
                ins, ln = f"mov byte ptr {mem}, 0x{raw[i + 1 + mlen]:x}", 1 + mlen + 1
        elif b0 == 0x83 and i + 3 <= n and (raw[i + 1] >> 6) == 3:
            sub = ["add", "or", "adc", "sbb", "and", "sub", "xor", "cmp"][(raw[i + 1] >> 3) & 7]
            imm = struct.unpack_from("<b", raw, i + 2)[0]
            ins, ln = f"{sub} {R32[raw[i + 1] & 7]}, {imm:#x}" if imm >= 0 else f"{sub} {R32[raw[i + 1] & 7]}, -{-imm:#x}", 3
        hx = " ".join(f"{b:02X}" for b in raw[i:i + ln])
        lines.append(f"+{start + i:02X}: {hx:<20} | {ins}")
        i += ln
    return lines


def _modrm(raw: bytes, p: int):
    if p >= len(raw):
        return None
    m = raw[p]
    mod, reg, rm = m >> 6, (m >> 3) & 7, m & 7
    ln = 1
    if mod == 3:
        return R32[rm], reg, 1
    base = R32[rm]
    if rm == 4:
        if p + 1 >= len(raw):
            return None
        sib = raw[p + 1]
        ln += 1
        idx, sc, bs = (sib >> 3) & 7, 1 << (sib >> 6), sib & 7
        base = R32[bs] + (f"+{R32[idx]}*{sc}" if idx != 4 else "")
        if bs == 5 and mod == 0:
            if p + 6 > len(raw):
                return None
            d = struct.unpack_from("<I", raw, p + 2)[0]
            return f"[{(R32[idx] + '*' + str(sc) + '+') if idx != 4 else ''}0x{d:x}]", reg, 6
    if mod == 0:
        if rm == 5:
            if p + 5 > len(raw):
                return None
            return f"[0x{struct.unpack_from('<I', raw, p + 1)[0]:x}]", reg, 5
        return f"[{base}]", reg, ln
    if mod == 1:
        if p + ln >= len(raw):
            return None
        d = struct.unpack_from("<b", raw, p + ln)[0]
        return (f"[{base}+0x{d:x}]" if d >= 0 else f"[{base}-0x{-d:x}]"), reg, ln + 1
    if p + ln + 4 > len(raw):
        return None
    d = struct.unpack_from("<i", raw, p + ln)[0]
    return (f"[{base}+0x{d:x}]" if d >= 0 else f"[{base}-0x{-d:x}]"), reg, ln + 4


# --------------------------------------------------------------------------- #
# Starter C++ synthesizer
# --------------------------------------------------------------------------- #

def sanitize_class_and_method(sym: str) -> Tuple[str, str, List[str]]:
    clean = re.sub(r"[^A-Za-z0-9_:]", "_", sym)
    parts = [p for p in clean.split("::") if p]
    if len(parts) >= 2:
        ns, cls, meth = parts[:-2], parts[-2], parts[-1]
    else:
        ns, cls, meth = [], "", parts[0] if parts else "fn"
    if cls and not re.match(r"^[A-Za-z_]", cls):
        cls = "C_" + cls
    if not re.match(r"^[A-Za-z_~]", meth):
        meth = "fn_" + meth
    return cls, meth, ns


def synthesize_cpp(symbol: str, va: str, target: bytes, disasm: List[str], relocs=None) -> str:
    """
    Compilable starter C++ for one function, written from its instructions (see starter_synth.py).
    relocs: the function's relocations (decompme.find_relocations), so calls and globals get their
    sub_XXXXXXXX / DAT_XXXXXXXX names instead of numbers. Without them, call targets are still named
    from the disassembly but data addresses stay numbers.
    """
    from starter_synth import synthesize
    try:
        return synthesize(symbol, va, target, disasm, relocs)
    except Exception as e:                                   # a starter must never break the page
        cls, meth, ns = sanitize_class_and_method(symbol)
        return (f"// {symbol} ({va}, {len(target)} bytes)\n"
                f"// The starter generator could not follow this function ({type(e).__name__}); write it from the\n"
                "// disassembly.\n\n"
                + (f"class {cls} {{ public: void {meth}(); }};\n\nvoid {cls}::{meth}()\n{{\n}}\n" if cls
                   else f"void __cdecl {meth}(void)\n{{\n}}\n"))
