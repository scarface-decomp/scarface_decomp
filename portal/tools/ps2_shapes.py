#!/usr/bin/env python3
"""
C++ for the smallest PS2 functions, written from their instructions.

Thousands of PS2 functions are two to four instructions: an empty function, a function that returns
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


# ---- three and four instructions ---------------------------------------------------------------------------

SIZES = {"char": 1, "signed char": 1, "unsigned char": 1, "bool": 1, "short": 2, "unsigned short": 2}
V1, A2 = 3, 6
MOVE_V0_A0 = (0x0080102D, 0x00801021, 0x00801025)


def _class(members: List[Tuple[int, str]], method: str, extra: str = "") -> str:
    """A class with these (offset, type) members, padded to their places, and one method."""
    lines, at = [], 0
    for off, typ in sorted(set(members)):
        if off > at:
            lines.append(f"    char m_pad{at:02X}[0x{off - at:X}];")
        lines.append(f"    {typ} m_Field{off:X}; // +0x{off:X}")
        at = off + SIZES.get(typ, 4)
    return extra + "class Object\n{\npublic:\n    " + method + ";\n" + "\n".join(lines) + "\n};\n\n"


def _store(w: int):
    """(type, what, offset, base register, source) for sb/sh/sw/swc1, else None."""
    op, rs, rt, imm = _fields(w)
    if op in STORES:
        return STORES[op][0], STORES[op][1], _s16(imm), rs, ("r", rt)
    if op == 0x39:
        return "float", "a float", _s16(imm), rs, ("f", rt)
    return None


def _float_text(bits: int) -> str:
    import struct
    v = struct.unpack("<f", struct.pack("<I", bits & 0xFFFFFFFF))[0]
    text = repr(v)
    if "e" not in text and "." not in text:
        text += ".0"
    return text + "f"


def _three_more(words: Tuple[int, ...], gp: int) -> List[str]:
    """One instruction, jr ra, one instruction in the delay slot."""
    w0, w2 = words[0], words[2]
    if words[1] != JR_RA:
        return []
    if w0 == 0x44800000 and w2 == NOP:                                     # mtc1 zero, f0
        return ["// Returns 0.0.\nfloat Zero()\n{\n    return 0.0f;\n}\n"]
    op0, rs0, rt0, imm0 = _fields(w0)
    op2, rs2, rt2, imm2 = _fields(w2)
    st0, st2 = _store(w0), _store(w2)
    # store the argument, return a constant
    if st0 and st0[3] == A0 and st0[4] in (("r", A1), ("f", F12)) and st0[2] >= 0 and op2 == 0x09 and rs2 == 0 and rt2 == V0:
        typ, what, off = st0[0], st0[1], st0[2]
        n = _s16(imm2)
        rets = [("bool", "true")] if n == 1 else []
        rets.append(("int", str(n)))
        return [f"// Stores its argument as {what} at +0x{off:X} of its object and returns {val}.\n"
                + _class([(off, typ)], f"{ret} Set({typ} value)")
                + f"{ret} Object::Set({typ} value)\n{{\n    m_Field{off:X} = value;\n    return {val};\n}}\n" for ret, val in rets]
    # store a constant
    if op0 == 0x09 and rs0 == 0 and rt0 == V1 and st2 and st2[4] == ("r", V1) and st2[0] != "float":
        typ, what, off, n = st2[0], st2[1], st2[2], _s16(imm0)
        if st2[3] == A0 and off >= 0:
            types = [typ] + (["bool"] if typ == "char" and n in (0, 1) else [])
            return [f"// Sets the member at +0x{off:X} of its object to {n}.\n" + _class([(off, t)], "void Set()")
                    + f"void Object::Set()\n{{\n    m_Field{off:X} = {('true' if n else 'false') if t == 'bool' else n};\n}}\n" for t in types]
        if st2[3] == GP and gp:
            name = f"D_{(gp + off) & 0xFFFFFFFF:08X}"
            return [f"// Sets the global {name} to {n}.\nextern {typ} {name};\n\nvoid Set()\n{{\n    {name} = {n};\n}}\n"]
    # a member of the object a member points to
    if op0 == 0x23 and rt0 == V0 and rs2 == V0 and (op2 in LOADS and rt2 == V0 or op2 == 0x31 and rt2 == F0):
        typ, what = ("float", "the float") if op2 == 0x31 else LOADS[op2]
        off0, off2 = _s16(imm0), _s16(imm2)
        inner = (f"struct Inner\n{{\n" + (f"    char m_pad00[0x{off2:X}];\n" if off2 else "")
                 + f"    {typ} m_Field{off2:X}; // +0x{off2:X}\n}};\n\n")
        if off2 < 0:
            return []
        if rs0 == A0 and off0 >= 0:
            return [f"// Returns {what} at +0x{off2:X} of the object its member at +0x{off0:X} points to.\n"
                    + _class([(off0, "Inner*")], f"{typ} Get()", inner)
                    + f"{typ} Object::Get()\n{{\n    return m_Field{off0:X}->m_Field{off2:X};\n}}\n"]
        if rs0 == GP and gp:
            name = f"D_{(gp + off0) & 0xFFFFFFFF:08X}"
            return [f"// Returns {what} at +0x{off2:X} of the object the global {name} points to.\n" + inner
                    + f"extern Inner* {name};\n\n{typ} Get()\n{{\n    return {name}->m_Field{off2:X};\n}}\n"]
    # is a member not zero?
    if rs0 == A0 and rt0 == V0 and op0 in (0x23, 0x24) and w2 == 0x0002102B and _s16(imm0) >= 0:      # sltu v0, zero, v0
        typ, off = ("int" if op0 == 0x23 else "unsigned char"), _s16(imm0)
        return [f"// Says whether the member at +0x{off:X} of its object is not zero.\n" + _class([(off, typ)], "bool IsSet()")
                + f"bool Object::IsSet()\n{{\n    return m_Field{off:X} != 0;\n}}\n"]
    # a 32-bit constant
    if op0 == 0x0F and rs0 == 0 and rt0 == V0 and op2 == 0x0D and rs2 == V0 and rt2 == V0:
        n = (imm0 << 16) | imm2
        return [f"// Returns 0x{n:08X}.\nunsigned int Number()\n{{\n    return 0x{n:08X};\n}}\n",
                f"// Returns 0x{n:08X}.\nint Number()\n{{\n    return 0x{n:08X};\n}}\n"]
    # two stores
    if st0 and st2 and st0[3] == A0 and st2[3] == A0 and st0[2] >= 0 and st2[2] >= 0 and st0[2] != st2[2]:
        a, b = (st0[2], st0[0]), (st2[2], st2[0])
        if st0[4] == ("r", 0) and st2[4] == ("r", 0):
            head = f"// Sets the members at +0x{a[0]:X} and +0x{b[0]:X} of its object to zero.\n" + _class([a, b], "void Clear()")
            first, second = f"    m_Field{a[0]:X} = 0;\n", f"    m_Field{b[0]:X} = 0;\n"
            return [head + "void Object::Clear()\n{\n" + x + y + "}\n" for x, y in ((first, second), (second, first))]
        if st0[4] == ("r", A1) and st2[4] == ("r", A2):
            return [f"// Stores its two arguments at +0x{a[0]:X} and +0x{b[0]:X} of its object.\n"
                    + _class([a, b], f"void Set({a[1]} first, {b[1]} second)")
                    + f"void Object::Set({a[1]} first, {b[1]} second)\n{{\n    m_Field{a[0]:X} = first;\n    m_Field{b[0]:X} = second;\n}}\n"]
    # clear a member and return the object
    if st0 and st0[3] == A0 and st0[4] == ("r", 0) and st0[2] >= 0 and w2 in MOVE_V0_A0:
        off, typ = st0[2], st0[0]
        return [f"// Sets the member at +0x{off:X} of its object to zero and returns the object.\n"
                + _class([(off, typ)], "Object* Clear()")
                + f"Object* Object::Clear()\n{{\n    m_Field{off:X} = 0;\n    return this;\n}}\n"]
    return []


def _four(words: Tuple[int, ...], gp: int) -> List[str]:
    w0, w1, w2, w3 = words
    op0, rs0, rt0, imm0 = _fields(w0)
    if op0 == 0x0F and rs0 == 0 and rt0 == V0 and w1 == 0x44820000 and w2 == JR_RA and w3 == NOP:     # lui v0; mtc1 v0, f0
        text = _float_text(imm0 << 16)
        return [f"// Returns {text[:-1]}.\nfloat Number()\n{{\n    return {text};\n}}\n"]
    op1, rs1, rt1, imm1 = _fields(w1)
    op3, rs3, rt3, imm3 = _fields(w3)
    if (op0 == 0x23 and rt0 == V1 and op1 == 0x09 and rs1 == V1 and rt1 == V1 and w2 == JR_RA
            and op3 == 0x2B and rt3 == V1 and rs3 == rs0 and imm3 == imm0):                           # lw; addiu; jr ra; sw
        off, n = _s16(imm0), _s16(imm1)
        change = f"+= {n}" if n >= 0 else f"-= {-n}"
        if rs0 == A0 and off >= 0:
            return [f"// Adds {n} to the member at +0x{off:X} of its object.\n" + _class([(off, "int")], "void Step()")
                    + f"void Object::Step()\n{{\n    m_Field{off:X} {change};\n}}\n"]
        if rs0 == GP and gp:
            name = f"D_{(gp + off) & 0xFFFFFFFF:08X}"
            return [f"// Adds {n} to the global {name}.\nextern int {name};\n\nvoid Step()\n{{\n    {name} {change};\n}}\n"]
    return []


# ---- functions that end by jumping into another one --------------------------------------------------------
#
# At -O3 the compiler turns a call that is the last thing a function does into a jump, when the function
# needs no stack frame of its own (the examiner's reading of the compiler's own option text, round PS2).
# So `void f() { g(&a, &b); }` becomes: set up the arguments, `j g`, with one of them in the delay slot.
# These are tried as a family: the pass stops trying a family that has not matched once in a few tries.

A_REGS = {4: 0, 5: 1}                 # a0, a1
AT, T9 = 1, 25
JR_T9 = 0x03200008


def _jump_target(w: int, pc: int) -> int:
    return ((pc + 4) & 0xF0000000) | ((w & 0x03FFFFFF) << 2)


def _tail_args(i0: int, i2: int, gp: int):
    """What a0/a1 hold at the jump, from the two instructions around it: ({reg index: (expression, C type)},
    declarations, parameters used) or None."""
    args, decls, used = {}, [], set()
    op0, rs0, rt0, imm0 = _fields(i0)
    op2, rs2, rt2, imm2 = _fields(i2)

    def simple(w: int) -> bool:
        """One instruction that sets a0 or a1 from $gp or from an incoming argument."""
        op, rs, rt, imm = _fields(w)
        off = _s16(imm)
        if w in (0x0080282D, 0x00802821, 0x00802825):                 # move a1, a0
            args[1] = ("p0", "void*")
            used.add(0)
            return True
        if rt not in A_REGS:
            return False
        k = A_REGS[rt]
        if op == 0x09 and rs == GP and gp:                            # addiu aK, gp, N
            name = f"D_{(gp + off) & 0xFFFFFFFF:08X}"
            decls.append(f"extern int {name};")
            args[k] = (f"&{name}", "int*")
            return True
        if op == 0x23 and rs == GP and gp:                            # lw aK, N(gp)
            name = f"D_{(gp + off) & 0xFFFFFFFF:08X}"
            decls.append(f"extern int {name};")
            args[k] = (name, "int")
            return True
        if op == 0x23 and rs in A_REGS and off >= 0:                  # lw aK, N(aJ)
            j = A_REGS[rs]
            used.add(j)
            args[k] = (f"p{j}->m_Field{off:X}", "int", j, off)
            return True
        return False

    if op0 == 0x0F and rs0 == 0 and rs2 == rt0 and rt2 == A0 and rt0 in (AT, A0):          # lui; then a0 from it
        name = f"D_{((imm0 << 16) + _s16(imm2)) & 0xFFFFFFFF:08X}"
        if op2 == 0x23 and rt0 == AT:
            return {0: (f"{name}[0]", "int")}, [f"extern int {name}[];"], set()
        if op2 == 0x09 and rt0 == A0:
            return {0: (name, "char*")}, [f"extern char {name}[];"], set()
        return None
    if op0 == 0x23 and rs0 == A0 and rt0 == V0 and op2 == 0x23 and rs2 == V0 and rt2 == A0:  # a0 = p0->x->y
        o1, o2 = _s16(imm0), _s16(imm2)
        if o1 < 0 or o2 < 0:
            return None
        return {0: (f"p0->m_Field{o1:X}->m_Field{o2:X}", "int", 0, o1, o2)}, [], {0}
    if i2 == NOP:
        return (args, decls, used) if simple(i0) and 0 in args else None
    if not (simple(i0) and simple(i2)) or len(args) != 2:
        return None
    return args, decls, used


def _tail_call(words: Tuple[int, ...], va: int, gp: int) -> List[str]:
    """instruction; j target; instruction."""
    if len(words) != 3 or (words[1] >> 26) != 0x02:
        return []
    got = _tail_args(words[0], words[2], gp)
    if got is None:
        return []
    args, decls, used = got
    target = f"func_{_jump_target(words[1], va + 4):08X}"
    structs, params = [], []
    for j in sorted(used):
        fields = [a for a in args.values() if len(a) >= 4 and a[2] == j]
        if not fields:
            params.append(f"void* p{j}")
            continue
        if len(fields[0]) == 5:                                        # p0->x->y
            _e, _t, _j, o1, o2 = fields[0]
            structs.append("struct Inner\n{\n" + (f"    char m_pad00[0x{o2:X}];\n" if o2 else "")
                           + f"    int m_Field{o2:X}; // +0x{o2:X}\n}};\n")
            structs.append(f"struct Arg{j}\n{{\n" + (f"    char m_pad00[0x{o1:X}];\n" if o1 else "")
                           + f"    Inner* m_Field{o1:X}; // +0x{o1:X}\n}};\n")
        else:
            off = fields[0][3]
            structs.append(f"struct Arg{j}\n{{\n" + (f"    char m_pad00[0x{off:X}];\n" if off else "")
                           + f"    int m_Field{off:X}; // +0x{off:X}\n}};\n")
        params.append(f"Arg{j}* p{j}")
    if 1 in used and 0 not in used:
        params.insert(0, "void*")                                      # a1 is read, so there is a first argument
    order = sorted(args)
    if order != list(range(len(order))):
        return []                                                      # a1 set but not a0: not this shape
    call = ", ".join(args[k][0] for k in order)
    proto = ", ".join(args[k][1] for k in order)
    head = (f"// Passes {len(order)} value{'s' if len(order) != 1 else ''} on to {target} and lets it return to this "
            "function's caller (the call is a jump).\n")
    body = "\n".join(structs + sorted(set(decls)) + [f'extern "C" void {target}({proto});'])
    return [head + body + f"\n\nvoid Forward({', '.join(params)})\n{{\n    {target}({call});\n}}\n"]


def _virtual_forward(words: Tuple[int, ...]) -> List[str]:
    """lw t9, N(a0); lw t9, M(t9); jr t9; nop -- and the same through a pointer member first."""
    w = list(words)
    through = None
    if len(w) == 5:
        op, rs, rt, imm = _fields(w[0])
        if op != 0x23 or rs != A0 or rt != A0 or _s16(imm) < 0:
            return []
        through, w = _s16(imm), w[1:]
    if len(w) != 4 or w[2] != JR_T9 or w[3] != NOP:
        return []
    op0, rs0, rt0, imm0 = _fields(w[0])
    op1, rs1, rt1, imm1 = _fields(w[1])
    if not (op0 == 0x23 and rs0 == A0 and rt0 == T9 and op1 == 0x23 and rs1 == T9 and rt1 == T9):
        return []
    vptr, slot_off = _s16(imm0), _s16(imm1)
    if vptr < 0 or slot_off < 0 or slot_off % 4 or vptr % 4:
        return []
    out = []
    for first in (8, 0):                         # the table's first method at +8 (after two header words), or at +0
        if slot_off < first:
            continue
        k = (slot_off - first) // 4
        if k > 400:
            continue
        methods = "".join(f"    virtual void Method{i}();\n" for i in range(k + 1))
        pad = f"    char m_pad00[0x{vptr:X}];\n" if vptr else ""
        if through is None:
            out.append(f"// Calls its own virtual method number {k} and lets it return to this function's caller.\n"
                       f"class Object\n{{\npublic:\n{pad}{methods}    void Forward();\n}};\n\n"
                       f"void Object::Forward()\n{{\n    Method{k}();\n}}\n")
        else:
            tpad = f"    char m_pad00[0x{through:X}];\n" if through else ""
            out.append(f"// Calls virtual method number {k} of the object its member at +0x{through:X} points to, and lets "
                       "it return to this function's caller.\n"
                       f"class Inner\n{{\npublic:\n{pad}{methods}}};\n\n"
                       f"class Object\n{{\npublic:\n    void Forward();\n{tpad}    Inner* m_Field{through:X}; // +0x{through:X}\n}};\n\n"
                       f"void Object::Forward()\n{{\n    m_Field{through:X}->Method{k}();\n}}\n")
    return out


def family(words: Tuple[int, ...]) -> str:
    """'' for the shapes that have matched from the first night on; a name for a family still on trial (the
    pass stops trying a family that has not matched once in its first few tries)."""
    words = tuple(words)
    if len(words) == 3 and (words[1] >> 26) == 0x02:
        return "tail call"
    if len(words) in (4, 5) and words[-2] == JR_T9:
        return "virtual forward"
    return ""


def sources(words: Tuple[int, ...], va: int = 0, gp: int = 0) -> List[str]:
    """C++ to try for a function made of these instructions, the likeliest first."""
    words = tuple(words)
    if len(words) == 2 and words[0] == JR_RA:
        return _two(words, gp)
    if len(words) == 3:
        return _three(words) or _three_more(words, gp) or _tail_call(words, va, gp)
    if len(words) == 4:
        return _four(words, gp) or _virtual_forward(words)
    if len(words) == 5:
        return _virtual_forward(words)
    return []
