#!/usr/bin/env python3
"""
C++ for the smallest PS2 functions, written from their instructions.

Thousands of PS2 functions are two or three instructions: an empty function, a function that returns
one member of its object, one that stores its argument in a member, one that returns a constant or a
global. Their source can only be a line or two, so it is written here from the instructions themselves
and then compiled and checked like any other submission: nothing counts unless the game's compiler
turns it back into the same bytes.

The text is the same for every function of the same shape (no address in the class's name), so one
compile serves all of them: the portal keeps each compiled object and reuses it.

    sources(words, va, gp) -> [C++ text, ...]      what to try, the likeliest first ([] when no shape fits)

words are the function's instructions as 32-bit numbers; gp is the program's small-data pointer.
"""

from __future__ import annotations

from typing import List, Tuple

JR_RA = 0x03E00008
NOP = 0x00000000
V0, A0, A1, GP = 2, 4, 5, 28
F0, F12 = 0, 12

LOADS = {0x20: ("signed char", "a signed byte"), 0x24: ("unsigned char", "a byte"), 0x21: ("short", "a 16-bit number"),
         0x25: ("unsigned short", "an unsigned 16-bit number"), 0x23: ("int", "the 32-bit value")}
STORES = {0x28: ("char", "a byte"), 0x29: ("short", "a 16-bit number"), 0x2B: ("int", "a 32-bit value")}


def _s16(v: int) -> int:
    return v - 0x10000 if v & 0x8000 else v


def _fields(w: int) -> Tuple[int, int, int, int]:
    return w >> 26, (w >> 21) & 31, (w >> 16) & 31, w & 0xFFFF


def _object(member_type: str, off: int, method: str) -> str:
    """A class with one member of member_type at +off and one method."""
    pad = f"    char m_pad00[0x{off:X}];\n" if off else ""
    return (f"class Object\n{{\npublic:\n    {method};\n{pad}    {member_type} m_Field{off:X}; // +0x{off:X}\n}};\n\n")


def _getter(member_type: str, what: str, off: int) -> str:
    return (f"// Returns {what} at +0x{off:X} of its object.\n" + _object(member_type, off, f"{member_type} Get()")
            + f"{member_type} Object::Get()\n{{\n    return m_Field{off:X};\n}}\n")


def _setter(member_type: str, what: str, off: int) -> str:
    return (f"// Stores its argument as {what} at +0x{off:X} of its object.\n"
            + _object(member_type, off, f"void Set({member_type} value)")
            + f"void Object::Set({member_type} value)\n{{\n    m_Field{off:X} = value;\n}}\n")


def _two(words: Tuple[int, ...], gp: int) -> List[str]:
    """jr ra with one instruction in its delay slot."""
    w = words[1]
    if w == NOP:
        return ["// Does nothing.\nvoid Nothing()\n{\n}\n"]
    op, rs, rt, imm = _fields(w)
    off = _s16(imm)
    if rs == A0 and rt == V0 and op in LOADS and off >= 0:
        typ, what = LOADS[op]
        out = [_getter(typ, what, off)]
        if op == 0x24:
            out.append(_getter("bool", "the true/false value", off))
        if op == 0x23:
            out.append(_getter("unsigned int", "the 32-bit value", off))
        return out
    if op == 0x31 and rs == A0 and rt == F0 and off >= 0:                     # lwc1 f0, off(a0)
        return [_getter("float", "the float", off)]
    if rs == A0 and rt == A1 and op in STORES and off >= 0:
        typ, what = STORES[op]
        out = [_setter(typ, what, off)]
        if op == 0x28:
            out.append(_setter("bool", "a true/false value", off))
        return out
    if op == 0x39 and rs == A0 and rt == F12 and off >= 0:                    # swc1 f12, off(a0)
        return [_setter("float", "a float", off)]
    if op == 0x09 and rs == A0 and rt == V0 and off > 0:                      # addiu v0, a0, off
        return [f"// Returns the address of the member at +0x{off:X} of its object.\n"
                + _object("int", off, "int* Get()") + f"int* Object::Get()\n{{\n    return &m_Field{off:X};\n}}\n"]
    if w in (0x0080102D, 0x00801021, 0x00801025):                             # move v0, a0
        return ["// Returns its object.\nclass Object\n{\npublic:\n    Object* Get();\n};\n\n"
                "Object* Object::Get()\n{\n    return this;\n}\n"]
    if w in (0x0000102D, 0x00001021, 0x00001025):                             # move v0, zero
        return ["// Returns 0.\nint Zero()\n{\n    return 0;\n}\n", "// Returns false.\nbool No()\n{\n    return false;\n}\n"]
    if op == 0x09 and rs == 0 and rt == V0:                                   # li v0, imm (signed)
        out = [f"// Returns {off}.\nint Number()\n{{\n    return {off};\n}}\n"]
        if off == 1:
            out.append("// Returns true.\nbool Yes()\n{\n    return true;\n}\n")
        return out
    if op == 0x0D and rs == 0 and rt == V0:                                   # ori v0, zero, imm
        return [f"// Returns 0x{imm:X}.\nunsigned int Number()\n{{\n    return 0x{imm:X};\n}}\n"]
    if rs == GP and rt == V0 and op in LOADS and gp:
        typ, what = LOADS[op]
        name = f"D_{(gp + off) & 0xFFFFFFFF:08X}"
        return [f"// Returns {what} kept in the global {name}.\nextern {typ} {name};\n\n"
                f"{typ} Get()\n{{\n    return {name};\n}}\n"]
    return []


def _three(words: Tuple[int, ...]) -> List[str]:
    """lui v0, hi; jr ra; then a load from, or the address of, that global."""
    op0, rs0, rt0, hi = _fields(words[0])
    if op0 != 0x0F or rs0 != 0 or rt0 != V0 or words[1] != JR_RA:
        return []
    op, rs, rt, imm = _fields(words[2])
    if rs != V0 or rt != V0:
        return []
    name = f"D_{((hi << 16) + _s16(imm)) & 0xFFFFFFFF:08X}"
    if op in LOADS:
        typ, what = LOADS[op]
        return [f"// Returns {what} kept in the global {name}.\nextern {typ} {name}[];\n\n"
                f"{typ} Get()\n{{\n    return {name}[0];\n}}\n",
                f"// Returns {what} kept in the global {name}.\nextern {typ} {name};\n\n"
                f"{typ} Get()\n{{\n    return {name};\n}}\n"]
    if op == 0x09:
        return [f"// Returns the address of the global {name}.\nextern char {name}[];\n\n"
                f"char* Get()\n{{\n    return {name};\n}}\n"]
    return []


def sources(words: Tuple[int, ...], va: int = 0, gp: int = 0) -> List[str]:
    """C++ to try for a function made of these instructions, the likeliest first."""
    words = tuple(words)
    if len(words) == 2 and words[0] == JR_RA:
        return _two(words, gp)
    if len(words) == 3:
        return _three(words)
    return []
