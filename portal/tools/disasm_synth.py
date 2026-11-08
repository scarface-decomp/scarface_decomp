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
from typing import Dict, List, Tuple

R32 = ["eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi"]
R8 = ["al", "cl", "dl", "bl", "ah", "ch", "dh", "bh"]
JCC = ["jo", "jno", "jb", "jae", "je", "jne", "jbe", "ja", "js", "jns", "jp", "jnp", "jl", "jge", "jle", "jg"]


def _norm_mem(op: str) -> str:
    """'dword ptr [esp + 4]' -> '[esp+0x4]' (keeps 'byte ptr' etc. only for immediate stores)."""
    def fix(m):
        inner = m.group(1).replace(" ", "")
        inner = re.sub(r"(?<=[+\-\[])(\d+)(?=[\]+\-*])", lambda d: hex(int(d.group(1))), inner)
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
            ops = re.sub(r"\b(dword|word|byte|qword|tbyte) ptr (?=\[)", lambda m: "" if "," in ops and not re.search(r",\s*(0x[0-9a-f]+|\d+)$", ops) else m.group(0), ops)
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


def _num(s: str) -> int:
    return int(s, 0)


def synthesize_cpp(symbol: str, va: str, target: bytes, disasm: List[str]) -> str:
    """
    Produce compilable starter C++ from the target's instructions. It is a starting point for a
    human or an AI, not a decompiler: field types default to int and callee signatures are guesses.
    """
    n = len(target)
    cls, meth, ns = sanitize_class_and_method(symbol)
    is_method = bool(cls)
    ins = [ln.split("|", 1)[1].strip() for ln in disasm if "|" in ln]

    # Calling convention / arguments from the return instruction and stack reads.
    argc = 0
    m = re.search(r"\bret 0x([0-9a-f]+)$", ins[-1]) if ins else None
    if m:
        argc = int(m.group(1), 16) // 4
    else:
        offs = [int(x, 16) for l in ins for x in re.findall(r"\[esp\+0x([0-9a-f]+)\]", l)]
        pushes = 0
        for l in ins:
            if l.startswith("push"):
                pushes += 1
            if re.search(r"\[esp\+0x", l):
                break
        offs = [o - 4 * pushes for o in offs]
        if offs:
            argc = max(0, max(o for o in offs if 0 < o <= 0x40) // 4) if any(0 < o <= 0x40 for o in offs) else 0
    params = ", ".join(f"int a{i + 1}" for i in range(argc))

    fields: Dict[int, str] = {}
    this_regs = {"ecx"} if is_method else set()
    reg: Dict[str, str] = {}
    stmts: List[str] = []
    externs: List[str] = []
    ret_expr = None
    calls = 0

    def field(off: int, typ: str = "int") -> str:
        fields.setdefault(off, typ)
        return f"m_Field{off:02X}"

    for l in ins:
        mm = re.match(r"mov (e\w\w), (e\w\w)$", l)
        if mm:
            dst, src = mm.groups()
            if src in this_regs:
                this_regs.add(dst)
            reg[dst] = reg.get(src, src)
            continue
        mm = re.match(r"mov (e\w\w), \[esp\+0x([0-9a-f]+)\]$", l)
        if mm:
            idx = max(1, int(mm.group(2), 16) // 4)
            reg[mm.group(1)] = f"a{min(idx, argc) if argc else idx}"
            continue
        mm = re.match(r"(mov|lea) (e\w\w), \[(e\w\w)\+0x([0-9a-f]+)\]$", l)
        if mm and mm.group(3) in this_regs:
            off = int(mm.group(4), 16)
            name = field(off)
            reg[mm.group(2)] = ("&" if mm.group(1) == "lea" else "") + name
            continue
        mm = re.match(r"mov \[(e\w\w)\+0x([0-9a-f]+)\], (e\w\w)$", l)
        if mm and mm.group(1) in this_regs:
            stmts.append(f"    {field(int(mm.group(2), 16))} = {reg.get(mm.group(3), '0')};")
            continue
        mm = re.match(r"mov (dword|byte) ptr \[(e\w\w)\+0x([0-9a-f]+)\], (0x[0-9a-f]+|\d+)$", l)
        if mm and mm.group(2) in this_regs:
            v = _num(mm.group(4))
            if mm.group(1) == "dword" and v >= 0x80000000:
                v -= 1 << 32
            stmts.append(f"    {field(int(mm.group(3), 16), 'char' if mm.group(1) == 'byte' else 'int')} = {v};")
            continue
        mm = re.match(r"xor (e\w\w), \1$", l)
        if mm:
            reg[mm.group(1)] = "0"
            continue
        mm = re.match(r"mov (e\w\w), (0x[0-9a-f]+|\d+)$", l)
        if mm:
            reg[mm.group(1)] = str(_num(mm.group(2)))
            continue
        if l.startswith("call"):
            fn = f"Callee{calls:02d}"
            calls += 1
            externs.append(f"int __cdecl {fn}(...);  // TODO: real name/signature (target is a relocation)")
            stmts.append(f"    {fn}();")
            reg["eax"] = f"{fn}()"
            continue
    if any(re.match(r"(mov|xor|or|lea) eax", l) for l in ins) or reg.get("eax", "").startswith("Callee"):
        ret_expr = reg.get("eax")
    if ins and ins[-1].startswith("jmp") and not stmts:
        externs.append("void __cdecl TailCallee();  // TODO: tail-call target")
        stmts.append("    TailCallee();")

    ret_type = "int" if ret_expr not in (None, "") else "void"
    if ret_expr in ("this",) and is_method:
        ret_type = f"{cls}*"
    if ret_type != "void":
        stmts.append(f"    return {ret_expr};")
    elif not stmts:
        stmts.append("    return;")

    hdr = [f"// {symbol} ({va}, {n} bytes)",
           "// Starter code generated from the disassembly. Field names/types and callee signatures are guesses;",
           "// rename and retype them as you work it out. Only the C++ below is compiled.", ""]
    body = []
    open_ns = "".join(f"namespace {x} {{ " for x in ns)
    close_ns = " ".join("}" for _ in ns)
    if externs:
        body += externs + [""]
    if is_method:
        decl = [f"class {cls} {{", "public:"]
        decl.append("    virtual " + f"{ret_type} {meth}({params});")
        if fields:
            last = 0
            for off in sorted(fields):
                if off < 4:
                    continue
                if off > last + 4 and off - (last + 4) > 0:
                    pad = off - max(4, last + 4)
                    if pad > 0:
                        decl.append(f"    char m_pad{max(4, last + 4):02X}[0x{pad:X}];")
                decl.append(f"    {fields[off]} m_Field{off:02X}; // +0x{off:02X}")
                last = off
        decl.append("};")
        body += decl + ["", f"{ret_type} {cls}::{meth}({params}) {{"] + stmts + ["}"]
    else:
        body += [f"{ret_type} __cdecl {meth}({params}) {{"] + stmts + ["}"]
    text = "\n".join(body)
    if ns:
        text = open_ns + "\n" + text + "\n" + close_ns
    return "\n".join(hdr) + text + "\n"
