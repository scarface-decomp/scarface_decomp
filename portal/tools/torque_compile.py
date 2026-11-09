"""Syntax tree (tsast) -> Scarface compiled TorqueScript, the way the game's own compiler lays it out
(Torque's two passes: precompile fills the string, float and identifier tables; compile writes the code)."""
from __future__ import annotations

import math
import re
import struct
from typing import List, Optional

from torque_names import compiled_name
from torque_ast import (FLT, NONE, STR, UINT, Assign, AssignOp, Break, Call, CommaCat, Conditional, Continue,
                   ExprStmt, FloatBinary, FloatConst, FloatUnary, FuncDecl, Ident, If, IntBinary, IntConst,
                   IntUnary, Loop, ObjectDecl, Return, SlotAccess, SlotAssign, SlotAssignOp, StrCat, StrConst,
                   StrEq, Var, assign_op_type, pref)

END_MARK = 0xCDCD
NAN_RAW = bytes.fromhex("0000c0ff")
CMP_OPS = {"==": 14, ">": 15, ">=": 16, "<": 17, "<=": 18, "!=": 19}
INT_OPS = {"^": 20, "%": 21, "&": 22, "|": 23, ">>": 27, "<<": 28}
FLT_OPS = {"+": 31, "-": 32, "*": 33, "/": 34}
CONV = {(UINT, FLT): 66, (UINT, STR): 67, (UINT, NONE): 68, (FLT, UINT): 63, (FLT, STR): 64, (FLT, NONE): 65,
        (STR, UINT): 60, (STR, FLT): 61, (STR, NONE): 62}
NUMBER = re.compile(r"[+-]?(\d+\.?\d*([eE][+-]?\d+)?|\.\d+([eE][+-]?\d+)?)$")
_LOWER = {c: c + 32 for c in range(65, 91)}


class CompileError(Exception):
    pass


def ascii_lower(s: str) -> str:
    return s.translate(_LOWER)


def string_to_number(s: str) -> float:
    """What Scarface's consoleStringToNumber (default.xbe 0x00068E60) gives for a constant string used
    as a number: "" and "false" are 0, numbers are themselves, hashed names (stx...) are 1, and any other
    word is NaN."""
    if s == "" or ascii_lower(s) == "false":
        return 0.0
    if NUMBER.match(s):
        return float(s)
    if s.startswith("stx") or s.startswith("ste"):
        return 1.0
    return math.nan


def u32_of(v: float) -> int:
    if math.isnan(v) or math.isinf(v):
        return 0
    return int(v) & 0xFFFFFFFF


class StringTable:
    def __init__(self, fill: int = 0xCD):
        self.entries = []          # (text, tag, offset)
        self.data = bytearray()
        self.fill = fill           # what the unused room after a short tagged string holds

    def add(self, s: str, case_sens: bool = True, tag: bool = False) -> int:
        for text, t, off in self.entries:
            if t != tag:
                continue
            if (text == s) if case_sens else (ascii_lower(text) == ascii_lower(s)):
                return off
        off = len(self.data)
        b = s.encode("latin-1") + b"\0"
        if tag and len(b) < 7:
            b += bytes([self.fill]) * (7 - len(b))     # room for the tag number, never written
        self.data += b
        self.entries.append((s, tag, off))
        return off

    def add_int(self, v: int) -> int:
        v &= 0xFFFFFFFF
        return self.add(str(v - (1 << 32) if v >= 1 << 31 else v))

    def add_float(self, v: float) -> int:
        return self.add("%.9g" % v)


class FloatTable:
    def __init__(self):
        self.values: List[float] = []

    def add(self, v: float) -> int:
        for i, x in enumerate(self.values):
            if x == v:                     # NaN never equals itself: each one gets its own entry
                return i
        self.values.append(v)
        return len(self.values) - 1

    def build(self) -> bytes:
        out = bytearray()
        for v in self.values:
            if math.isnan(v):
                out += NAN_RAW
            elif abs(v) > 3.4028234663852886e38 and not math.isinf(v):
                rounded = struct.unpack("<f", struct.pack("<f", math.copysign(3.4028234663852886e38, v)))[0]
                out += struct.pack("<f", math.copysign(math.inf, v)) if abs(v) >= 3.4028235677973366e38 \
                    else struct.pack("<f", rounded)
            else:
                out += struct.pack("<f", v)
        return bytes(out)


class Compiler:
    def __init__(self, style: str = "stx"):
        self.style = style
        # The retail compiler's memory was filled with 0xCD (MSVC debug heap); the prototype's with zeros.
        fill = 0xCD if style == "stx" else 0x00
        self.gstr, self.fstr = StringTable(fill), StringTable(fill)
        self.gflt, self.fflt = FloatTable(), FloatTable()
        self.strs, self.flts = self.gstr, self.gflt
        self.idents: list = []        # [offset, [code indexes]] newest first, as Torque writes them
        self.code: List[int] = []
        self.idx: dict = {}

    # ------------------------------------------------------------------ helpers
    def ident(self, name: str):
        self.gstr.add(compiled_name(name, self.style))

    def keep(self, n, index: int):
        """Precompile decides a constant's table index; compile uses it (a loop test is compiled
        twice but precompiled once, and NaN never matches an earlier entry)."""
        self.idx[id(n)] = index

    def index(self, n) -> int:
        try:
            return self.idx[id(n)]
        except KeyError:
            raise CompileError(f"{type(n).__name__} was not precompiled") from None

    def float_of(self, n) -> float:
        if isinstance(n, FloatConst):
            if n.text:
                return float(n.text)
            v = struct.unpack("<f", n.raw)[0]
            return math.nan if n.raw == NAN_RAW else v
        if isinstance(n, IntConst):
            return float(n.value)
        if isinstance(n, StrConst):
            return string_to_number(n.value)
        if isinstance(n, Ident):
            return string_to_number(compiled_name(n.name, self.style))
        raise CompileError(type(n).__name__)

    def emit(self, *vals: int) -> int:
        at = len(self.code)
        self.code.extend(vals)
        return at

    def u(self, v: int):
        v &= 0xFFFFFFFF
        self.emit(v >> 16, v & 0xFFFF)

    def ste(self, name: Optional[str]):
        ip = len(self.code)
        if name:
            off = self.gstr.add(compiled_name(name, self.style), case_sens=False)
            for e in self.idents:
                if e[0] == off:
                    e[1].insert(1, ip)
                    break
            else:
                self.idents.insert(0, [off, [ip]])
        self.emit(0, 0)

    def conv(self, src: str, dst: str):
        if src != dst:
            self.emit(CONV[(src, dst)])

    # ------------------------------------------------------------------ precompile (tables only)
    def pre(self, n, t: str):
        if isinstance(n, IntConst):
            if t == STR:
                self.keep(n, self.strs.add_int(n.value))
            elif t == FLT:
                self.keep(n, self.flts.add(float(n.value)))
        elif isinstance(n, FloatConst):
            if t == STR:
                self.keep(n, self.strs.add_float(self.float_of(n)))
            elif t == FLT:
                self.keep(n, self.flts.add(self.float_of(n)))
        elif isinstance(n, StrConst):
            if t == STR:
                self.keep(n, self.strs.add(n.value, True, n.tag))
            elif t == FLT:
                self.keep(n, self.flts.add(self.float_of(n)))
        elif isinstance(n, Ident):
            if t == STR:
                self.ident(n.name)
            elif t == FLT:
                self.keep(n, self.flts.add(self.float_of(n)))
        elif isinstance(n, Var):
            if t == NONE:
                return
            self.ident(n.name)
            if n.index is not None:
                self.pre(n.index, STR)
        elif isinstance(n, Assign):
            sub = self.assign_type(n, t)
            self.pre(n.expr, sub)
            self.ident(n.var.name)
            if n.var.index is not None:
                self.pre(n.var.index, STR)
        elif isinstance(n, AssignOp):
            self.ident(n.var.name)
            self.pre(n.expr, assign_op_type(n.op))
            if n.var.index is not None:
                self.pre(n.var.index, STR)
        elif isinstance(n, FloatBinary):
            self.pre(n.left, FLT)
            self.pre(n.right, FLT)
        elif isinstance(n, IntBinary):
            sub = FLT if n.op in CMP_OPS else UINT
            # Torque writes "left->precompile() + right->precompile()", and C++ leaves the order to the
            # compiler: the retail scripts' compiler did the left side first, the prototype's the right.
            for side in ((n.right, n.left) if self.style == "ste" else (n.left, n.right)):
                self.pre(side, sub)
        elif isinstance(n, (StrEq, StrCat, CommaCat)):
            self.pre(n.left, STR)
            self.pre(n.right, STR)
        elif isinstance(n, IntUnary):
            self.pre(n.expr, UINT if self.unary_int(n) else FLT)
        elif isinstance(n, FloatUnary):
            self.pre(n.expr, FLT)
        elif isinstance(n, Conditional):
            self.pre(n.test, UINT if pref(n.test) == UINT else FLT)
            self.pre(n.true, t)
            self.pre(n.false, t)
        elif isinstance(n, Call):
            self.ident(n.name)
            if n.ns:
                self.ident(n.ns)
            for a in n.args:
                self.pre(a, STR)
        elif isinstance(n, SlotAccess):
            if t == NONE:
                return
            self.ident(n.slot)
            if n.index is not None:
                self.pre(n.index, STR)
            self.pre(n.obj, STR)
        elif isinstance(n, SlotAssign):
            self.ident(n.slot)
            self.pre(n.value, STR)
            if n.obj is not None:
                self.pre(n.obj, STR)
            if n.index is not None:
                self.pre(n.index, STR)
        elif isinstance(n, SlotAssignOp):
            self.ident(n.slot)
            self.pre(n.value, assign_op_type(n.op))
            if n.index is not None:
                self.pre(n.index, STR)
            self.pre(n.obj, STR)
        elif isinstance(n, ObjectDecl):
            self.pre_object(n)
        else:
            raise CompileError(f"precompile: {type(n).__name__}")

    def pre_object(self, o: ObjectDecl):
        if o.parent:
            self.ident(o.parent)
        for a in o.args:
            self.pre(a, STR)
        self.pre(o.class_expr, STR)
        self.pre(o.name_expr, STR)
        for s in o.slots:
            self.pre(s, NONE)
        for sub in o.subs:
            self.pre_object(sub)

    def pre_stmt(self, s):
        if isinstance(s, ExprStmt):
            self.pre(s.expr, NONE)
        elif isinstance(s, Return):
            if s.expr is not None:
                self.pre(s.expr, STR)
        elif isinstance(s, If):
            self.pre(s.test, UINT if pref(s.test) == UINT else FLT)
            for x in s.then:
                self.pre_stmt(x)
            for x in s.else_ or []:
                self.pre_stmt(x)
        elif isinstance(s, Loop):
            if s.init is not None:
                self.pre(s.init, NONE)
            self.pre(s.test, UINT if pref(s.test) == UINT else FLT)
            for x in s.body:
                self.pre_stmt(x)
            if s.end is not None:
                self.pre(s.end, NONE)
        elif isinstance(s, (Break, Continue)):
            pass
        elif isinstance(s, FuncDecl):
            self.strs, self.flts = self.fstr, self.fflt
            self.ident(s.name)
            if s.ns:
                self.ident(s.ns)
            if s.package:
                self.ident(s.package)
            for x in s.body or []:
                self.pre_stmt(x)
            self.strs, self.flts = self.gstr, self.gflt
        else:
            raise CompileError(f"precompile: {type(s).__name__}")

    # ------------------------------------------------------------------ compile
    @staticmethod
    def assign_type(n: Assign, t: str) -> str:
        sub = pref(n.expr)
        if sub == NONE:
            sub = t
        if sub == NONE:
            sub = STR
        return sub

    @staticmethod
    def unary_int(n: IntUnary) -> bool:
        return not (n.op == "!" and pref(n.expr) in (FLT, STR))

    def comp(self, n, t: str):
        e = self.emit
        if isinstance(n, IntConst):
            if t == UINT:
                e(69)
                self.u(n.value)
            elif t == STR:
                e(72)
                self.u(self.index(n))
            elif t == FLT:
                e(70)
                self.u(self.index(n))
        elif isinstance(n, (FloatConst, StrConst, Ident)):
            if t == NONE:
                return
            if t == STR:
                if isinstance(n, Ident):
                    e(73)
                    self.ste(n.name)
                else:
                    e(71 if isinstance(n, StrConst) and n.tag else 72)
                    self.u(self.index(n))
            elif t == UINT:
                e(69)
                self.u(u32_of(self.float_of(n)))
            else:
                e(70)
                self.u(self.index(n))
        elif isinstance(n, Var):
            if t == NONE:
                return
            if n.index is not None:
                e(73)
                self.ste(n.name)
                e(77)
                self.comp(n.index, STR)
                e(81)
                e(40 if n.local else 41)
            else:
                e(36 if n.local else 37)
                self.ste(n.name)
            e({UINT: 44, FLT: 45, STR: 46}[t])
        elif isinstance(n, Assign):
            sub = self.assign_type(n, t)
            self.comp(n.expr, sub)
            v = n.var
            if v.index is not None:
                if sub == STR:
                    e(77)
                e(73)
                self.ste(v.name)
                e(77)
                self.comp(v.index, STR)
                e(81)
                e(42 if v.local else 43)
                if sub == STR:
                    e(82)
            else:
                e(38 if v.local else 39)
                self.ste(v.name)
            e({UINT: 47, FLT: 48, STR: 49}[sub])
            self.conv(sub, t)
        elif isinstance(n, AssignOp):
            sub = assign_op_type(n.op)
            self.comp(n.expr, sub)
            v = n.var
            if v.index is None:
                e(38 if v.local else 39)
                self.ste(v.name)
            else:
                e(73)
                self.ste(v.name)
                e(77)
                self.comp(v.index, STR)
                e(81)
                e(42 if v.local else 43)
            e(45 if sub == FLT else 44)
            e(FLT_OPS[n.op] if sub == FLT else INT_OPS[n.op])
            e(48 if sub == FLT else 47)
            self.conv(sub, t)
        elif isinstance(n, FloatBinary):
            self.comp(n.right, FLT)
            self.comp(n.left, FLT)
            e(FLT_OPS[n.op])
            self.conv(FLT, t)
        elif isinstance(n, IntBinary):
            if n.op in ("&&", "||"):
                self.comp(n.left, UINT)
                e(11 if n.op == "||" else 10)
                at = e(0)
                self.comp(n.right, UINT)
                self.code[at] = len(self.code)
            else:
                sub = FLT if n.op in CMP_OPS else UINT
                self.comp(n.right, sub)
                self.comp(n.left, sub)
                e(CMP_OPS[n.op] if n.op in CMP_OPS else INT_OPS[n.op])
            self.conv(UINT, t)
        elif isinstance(n, StrEq):
            self.comp(n.left, STR)
            e(80)
            self.comp(n.right, STR)
            e(83)
            if not n.eq:
                e(24)
            self.conv(UINT, t)
        elif isinstance(n, (StrCat, CommaCat)):
            self.comp(n.left, STR)
            if isinstance(n, CommaCat):
                e(79)
            elif n.char is None:
                e(77)
            else:
                e(78, ord(n.char))
            self.comp(n.right, STR)
            e(81)
            if t in (UINT, FLT):
                e(60 if t == UINT else 61)
        elif isinstance(n, IntUnary):
            integer = self.unary_int(n)
            self.comp(n.expr, UINT if integer else FLT)
            e((24 if integer else 25) if n.op == "!" else 26)
            self.conv(UINT, t)
        elif isinstance(n, FloatUnary):
            self.comp(n.expr, FLT)
            e(35)
            self.conv(FLT, t)
        elif isinstance(n, Conditional):
            integer = pref(n.test) == UINT
            self.comp(n.test, UINT if integer else FLT)
            e(7 if integer else 6)
            j1 = e(0)
            self.comp(n.true, t)
            e(12)
            j2 = e(0)
            self.code[j1] = len(self.code)
            self.comp(n.false, t)
            self.code[j2] = len(self.code)
        elif isinstance(n, Call):
            e(85)
            for a in n.args:
                self.comp(a, STR)
                e(84)
            e(75 if n.call_type in (1, 2) else 74)
            self.ste(n.name)
            self.ste(n.ns)
            e(n.call_type)
            self.conv(STR, t)
        elif isinstance(n, SlotAccess):
            if t == NONE:
                return
            if n.index is not None:
                self.comp(n.index, STR)
                e(77)
            self.comp(n.obj, STR)
            e(50, 52)
            self.ste(n.slot)
            if n.index is not None:
                e(82, 53)
            e({UINT: 54, FLT: 55, STR: 56}[t])
        elif isinstance(n, SlotAssign):
            self.comp(n.value, STR)
            e(77)
            if n.index is not None:
                self.comp(n.index, STR)
                e(77)
            if n.obj is not None:
                self.comp(n.obj, STR)
                e(50)
            else:
                e(51)
            e(52)
            self.ste(n.slot)
            if n.index is not None:
                e(82, 53)
            e(82, 59)
            self.conv(STR, t)
        elif isinstance(n, SlotAssignOp):
            sub = assign_op_type(n.op)
            self.comp(n.value, sub)
            if n.index is not None:
                self.comp(n.index, STR)
                e(77)
            self.comp(n.obj, STR)
            e(50, 52)
            self.ste(n.slot)
            if n.index is not None:
                e(82, 53)
            e(55 if sub == FLT else 54)
            e(FLT_OPS[n.op] if sub == FLT else INT_OPS[n.op])
            e(58 if sub == FLT else 57)
            self.conv(sub, t)
        elif isinstance(n, ObjectDecl):
            e(69)
            self.u(0)
            self.comp_object(n, True)
            self.conv(UINT, t)
        else:
            raise CompileError(f"compile: {type(n).__name__}")

    def comp_object(self, o: ObjectDecl, root: bool):
        e = self.emit
        e(85)
        self.comp(o.class_expr, STR)
        e(84)
        self.comp(o.name_expr, STR)
        e(84)
        for a in o.args:
            self.comp(a, STR)
            e(84)
        e(1)
        self.ste(o.parent)
        e(int(o.datablock))
        fail = e(0)
        for s in o.slots:
            self.comp(s, NONE)
        e(4, int(root))
        for sub in o.subs:
            self.comp_object(sub, False)
        e(5, int(root or o.datablock))
        self.code[fail] = len(self.code)

    def comp_block(self, stmts, loop):
        for s in stmts or []:
            self.comp_stmt(s, loop)

    def comp_stmt(self, s, loop):
        e = self.emit
        if isinstance(s, ExprStmt):
            self.comp(s.expr, NONE)
        elif isinstance(s, Return):
            if s.expr is not None:
                self.comp(s.expr, STR)
            e(13)
        elif isinstance(s, If):
            integer = pref(s.test) == UINT
            self.comp(s.test, UINT if integer else FLT)
            e(7 if integer else 6)
            j1 = e(0)
            self.comp_block(s.then, loop)
            if s.else_ is not None:
                e(12)
                j2 = e(0)
                self.code[j1] = len(self.code)
                self.comp_block(s.else_, loop)
                self.code[j2] = len(self.code)
            else:
                self.code[j1] = len(self.code)
        elif isinstance(s, Loop):
            integer = pref(s.test) == UINT
            ctx = {"brk": [], "cont": []}
            if s.init is not None:
                self.comp(s.init, NONE)
            if not s.is_do:
                self.comp(s.test, UINT if integer else FLT)
                e(7 if integer else 6)
                ctx["brk"].append(e(0))
            start = len(self.code)
            self.comp_block(s.body, ctx)
            cont = len(self.code)
            if s.end is not None:
                self.comp(s.end, NONE)
            self.comp(s.test, UINT if integer else FLT)
            e(9 if integer else 8, start)
            brk = len(self.code)
            for at in ctx["brk"]:
                self.code[at] = brk
            for at in ctx["cont"]:
                self.code[at] = cont
        elif isinstance(s, Break):
            if loop is None:
                raise CompileError("break outside a loop")
            e(12)
            loop["brk"].append(e(0))
        elif isinstance(s, Continue):
            if loop is None:
                raise CompileError("continue outside a loop")
            e(12)
            loop["cont"].append(e(0))
        elif isinstance(s, FuncDecl):
            e(0)
            self.ste(s.name)
            self.ste(s.ns)
            self.ste(s.package)
            e(int(s.body is not None))
            end = e(0)
            e(len(s.args))
            for a in s.args:
                self.ste(a)
            self.strs, self.flts = self.fstr, self.fflt
            self.comp_block(s.body, None)
            self.strs, self.flts = self.gstr, self.gflt
            e(13)
            self.code[end] = len(self.code)
        else:
            raise CompileError(f"compile: {type(s).__name__}")


def compile_script(stmts, style: str = "stx", pad: int = END_MARK) -> bytes:
    """style: which game's compiler to copy. "stx", the retail game (PS2, Xbox, PC): names written as
    stx + 8 letters, unused bytes 0xCD. "ste", the April 2006 prototype: names as ste + decimal, unused
    bytes 0, and the right side of a comparison or &&/|| put in the tables before the left.
    pad: the code that fills the count to an even number: 0xCDCD in retail; the prototype's compiler
    left whatever was in memory, so its scripts say which (torque_script.PAD_LINE)."""
    c = Compiler(style)
    for s in stmts:
        c.pre_stmt(s)
    for s in stmts:
        c.comp_stmt(s, None)
    c.emit(13)
    if len(c.code) % 2:
        c.emit(pad)
    out = bytearray(struct.pack("<I", 1))
    out += struct.pack("<I", len(c.gstr.data)) + c.gstr.data
    out += struct.pack("<I", len(c.gflt.values)) + c.gflt.build()
    out += struct.pack("<I", len(c.fstr.data)) + c.fstr.data
    out += struct.pack("<I", len(c.fflt.values)) + c.fflt.build()
    out += struct.pack("<I", len(c.code))
    for v in c.code:
        out += bytes([v]) if v < 0xFF else b"\xff" + struct.pack("<H", v)
    out += struct.pack("<I", len(c.idents))
    for off, ips in c.idents:
        out += struct.pack("<II", off, len(ips)) + b"".join(struct.pack("<I", i) for i in ips)
    return bytes(out)
