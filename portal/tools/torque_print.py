"""Syntax tree (tsast) -> TorqueScript text."""
from __future__ import annotations

import math
import re
import struct
from typing import Dict, List, Optional

from torque_names import name_key

from torque_ast import (Assign, AssignOp, Break, Call, CommaCat, Conditional, Continue, ExprStmt, FloatBinary,
                   FloatConst, FloatUnary, FuncDecl, Ident, If, IntBinary, IntConst, IntUnary, Loop, ObjectDecl,
                   Return, SlotAccess, SlotAssign, SlotAssignOp, StrCat, StrConst, StrEq, Var)

ASSIGN, COND, ATOM, UNARY, POSTFIX = 1, 2, 20, 14, 15
BINARY = {"||": 3, "&&": 4, "|": 5, "^": 6, "&": 7, "==": 8, "!=": 8, "<": 9, "<=": 9, ">": 9, ">=": 9,
          "@": 10, "SPC": 10, "TAB": 10, "NL": 10, "$=": 10, "!$=": 10, "<<": 11, ">>": 11,
          "+": 12, "-": 12, "*": 13, "/": 13, "%": 13}
CAT = {None: "@", " ": "SPC", "\t": "TAB", "\n": "NL"}
INDENT = "    "
NAN_RAW = bytes.fromhex("0000c0ff")


IDENT_RE = re.compile(r"[A-Za-z_][A-Za-z0-9_]*$")
VAR_RE = re.compile(r"[%$][A-Za-z_][A-Za-z0-9_]*(::[A-Za-z0-9_]+)*$")
KEYWORDS = {"function", "package", "new", "datablock", "if", "else", "while", "for", "do", "return", "break",
            "continue", "SPC", "TAB", "NL", "true", "false"}


class PrintError(Exception):
    pass


def fmt_float(raw: bytes) -> str:
    """The shortest decimal that reads back as these four bytes, in Torque's number syntax."""
    v = struct.unpack("<f", raw)[0]
    if math.isnan(v):
        # Scarface turns a word that is not a number into NaN when a number is needed ("abc" == 1)
        if raw != NAN_RAW:
            raise PrintError(f"unusual NaN {raw.hex()} in the float table")
        return "-nan"
    if math.isinf(v):
        return ("-" if v < 0 else "") + "1e39"
    for p in range(1, 18):
        s = "%.*g" % (p, v)
        if struct.pack("<f", float(s)) == raw:
            break
    neg = s.startswith("-")
    s = s.lstrip("-")
    if "e" in s:
        m, e = s.split("e")
        s = (m if "." in m else m + ".0") + "e" + e
    elif "." not in s:
        s += ".0"
    return ("-" if neg else "") + s


def quote(s: str, tag: bool = False) -> str:
    q = "'" if tag else '"'
    out = [q]
    for ch in s:
        o = ord(ch)
        if ch == "\\":
            out.append("\\\\")
        elif ch == q:
            out.append("\\" + q)
        elif ch == "\n":
            out.append("\\n")
        elif ch == "\t":
            out.append("\\t")
        elif ch == "\r":
            out.append("\\r")
        elif o < 0x20 or o >= 0x7F:
            out.append("\\x%02x" % o)
        else:
            out.append(ch)
    out.append(q)
    return "".join(out)


class Printer:
    def __init__(self, names: Optional[Dict[int, str]] = None):
        self.lines: List[str] = []
        self.names = names or {}

    def n(self, raw: Optional[str]) -> Optional[str]:
        """A name, recovered when the names table knows it (it must hash to the same key)."""
        d = self.names.get(name_key(raw)) if raw else None
        if d and IDENT_RE.match(d) and d not in KEYWORDS and name_key(d) == name_key(raw):
            return d
        return raw

    def vname(self, raw: str, local: bool) -> str:
        d = self.names.get(name_key(raw))
        if d and VAR_RE.match(d) and (d[0] == "%") == local and name_key(d) == name_key(raw):
            return d
        return ("%" if local else "$") + raw

    # ------------------------------------------------------------------ expressions
    def e(self, n, need: int = 0, depth: int = 0) -> str:
        text, prec = self.expr(n, depth)
        return f"({text})" if prec < need else text

    def expr(self, n, depth: int):
        if isinstance(n, IntConst):
            return str(n.value), ATOM
        if isinstance(n, FloatConst):
            if n.raw == NAN_RAW:
                return quote("nan"), ATOM      # any word that is not a number
            s = fmt_float(n.raw)
            if s.startswith("-"):            # only a quoted number gives a negative constant
                return quote(s), ATOM
            return s, ATOM
        if isinstance(n, StrConst):
            return quote(n.value, n.tag), ATOM
        if isinstance(n, Ident):
            return self.n(n.name), ATOM
        if isinstance(n, Var):
            return self.var(n, depth), ATOM
        if isinstance(n, Assign):
            return f"{self.var(n.var, depth)} = {self.e(n.expr, ASSIGN, depth)}", ASSIGN
        if isinstance(n, AssignOp):
            return self.assign_op(self.var(n.var, depth), n.op, n.expr, depth)
        if isinstance(n, (FloatBinary, IntBinary)):
            p = BINARY[n.op]
            if isinstance(n, FloatBinary) or n.op in ("==", "!=", "<", "<=", ">", ">="):
                # operands are read as numbers whatever they are, so 4.0 can be written 4
                return f"{self.num(n.left, p, depth)} {n.op} {self.num(n.right, p + 1, depth)}", p
            return f"{self.e(n.left, p, depth)} {n.op} {self.e(n.right, p + 1, depth)}", p
        if isinstance(n, StrEq):
            op = "$=" if n.eq else "!$="
            return f"{self.text_arg(n.left, 10, depth)} {op} {self.text_arg(n.right, 11, depth)}", 10
        if isinstance(n, StrCat):
            if n.char not in CAT:
                raise PrintError(f"string join with character {n.char!r}")
            return f"{self.text_arg(n.left, 10, depth)} {CAT[n.char]} {self.text_arg(n.right, 11, depth)}", 10
        if isinstance(n, CommaCat):
            raise PrintError("comma join outside an array index")
        if isinstance(n, IntUnary):
            return f"{n.op}{self.e(n.expr, UNARY, depth)}", UNARY
        if isinstance(n, FloatUnary):
            inner = self.num(n.expr, UNARY, depth)
            return f"-{inner}" if not inner.startswith("-") else f"-({inner})", UNARY
        if isinstance(n, Conditional):
            return (f"{self.e(n.test, COND + 1, depth)} ? {self.e(n.true, COND + 1, depth)} : "
                    f"{self.e(n.false, COND + 1, depth)}"), COND
        if isinstance(n, Call):
            return self.call(n, depth), POSTFIX
        if isinstance(n, SlotAccess):
            return self.slot(n.obj, n.slot, n.index, depth), POSTFIX
        if isinstance(n, SlotAssign):
            if n.obj is None:
                raise PrintError("field of a new object outside its declaration")
            return f"{self.slot(n.obj, n.slot, n.index, depth)} = {self.text_arg(n.value, ASSIGN, depth)}", ASSIGN
        if isinstance(n, SlotAssignOp):
            return self.assign_op(self.slot(n.obj, n.slot, n.index, depth), n.op, n.value, depth)
        if isinstance(n, ObjectDecl):
            return self.object(n, depth), ATOM
        raise PrintError(f"cannot print {type(n).__name__}")

    def text_arg(self, n, need: int, depth: int) -> str:
        """An operand that is always read as text: "3" can be written 3 (the same string either way)."""
        if isinstance(n, StrConst) and not n.tag and re.fullmatch(r"0|[1-9][0-9]{0,9}", n.value) \
                and int(n.value) < 2 ** 31:
            return n.value
        return self.e(n, need, depth)

    def num(self, n, need: int, depth: int) -> str:
        """An operand that is always read as a number: whole numbers without the .0."""
        if isinstance(n, FloatConst) and n.raw != NAN_RAW:
            v = struct.unpack("<f", n.raw)[0]
            if v == int(v) and 0 <= v < 2 ** 31 and not (v == 0 and n.raw[3] & 0x80):
                return str(int(v))
        return self.e(n, need, depth)

    def assign_op(self, target: str, op: str, value, depth: int):
        if op in ("+", "-") and ((isinstance(value, IntConst) and value.value == 1)
                                 or (isinstance(value, FloatConst) and value.raw == struct.pack("<f", 1.0))):
            return f"{target}{op}{op}", UNARY
        v = self.num(value, ASSIGN, depth) if op in ("+", "-", "*", "/") else self.e(value, ASSIGN, depth)
        return f"{target} {op}= {v}", ASSIGN

    def index(self, n, depth: int) -> str:
        parts = []
        while isinstance(n, CommaCat):
            parts.append(n.right)
            n = n.left
        parts.append(n)
        return ", ".join(self.text_arg(p, ASSIGN, depth) for p in reversed(parts))

    def var(self, v: Var, depth: int) -> str:
        s = self.vname(v.name, v.local)
        return s + (f"[{self.index(v.index, depth)}]" if v.index is not None else "")

    def target(self, obj, depth: int) -> str:
        t = self.e(obj, POSTFIX, depth)
        if isinstance(obj, (IntConst, FloatConst)):
            t = f"({t})"
        return t

    def slot(self, obj, name: str, index, depth: int) -> str:
        s = f"{self.target(obj, depth)}.{self.n(name)}"
        return s + (f"[{self.index(index, depth)}]" if index is not None else "")

    def call(self, c: Call, depth: int) -> str:
        name = self.n(c.name)
        if c.call_type == 1:
            args = ", ".join(self.text_arg(a, ASSIGN, depth) for a in c.args[1:])
            return f"{self.target(c.args[0], depth)}.{name}({args})"
        args = ", ".join(self.text_arg(a, ASSIGN, depth) for a in c.args)
        return (f"{self.n(c.ns)}::" if c.ns else "") + f"{name}({args})"

    def object(self, o: ObjectDecl, depth: int) -> str:
        kw = "datablock" if o.datablock else "new"
        cls = self.n(o.class_expr.name) if isinstance(o.class_expr, Ident) else f"({self.e(o.class_expr, 0, depth)})"
        head = []
        name = "" if isinstance(o.name_expr, StrConst) and o.name_expr.value == "" and not o.name_expr.tag \
            else self.e(o.name_expr, ASSIGN, depth)
        if o.parent is not None:
            name += f" : {self.n(o.parent)}"
        if name or o.args:
            head.append(name)
        head += [self.text_arg(a, ASSIGN, depth) for a in o.args]
        text = f"{kw} {cls}({', '.join(head)})"
        if not o.slots and not o.subs:
            return text + " {}"
        pad = INDENT * (depth + 1)
        body = []
        for s in o.slots:
            t = self.n(s.slot) + (f"[{self.index(s.index, depth + 1)}]" if s.index is not None else "")
            body.append(f"{pad}{t} = {self.text_arg(s.value, ASSIGN, depth + 1)};")
        for sub in o.subs:
            body.append(f"{pad}{self.object(sub, depth + 1)};")
        return text + "\n" + INDENT * depth + "{\n" + "\n".join(body) + "\n" + INDENT * depth + "}"

    # ------------------------------------------------------------------ statements
    def block(self, stmts, depth: int):
        for s in stmts:
            self.stmt(s, depth)

    def stmt(self, s, depth: int):
        pad = INDENT * depth
        w = self.lines.append
        if isinstance(s, ExprStmt):
            w(f"{pad}{self.e(s.expr, 0, depth)};")
        elif isinstance(s, Return):
            w(f"{pad}return {self.text_arg(s.expr, 0, depth)};" if s.expr is not None else f"{pad}return;")
        elif isinstance(s, Break):
            w(f"{pad}break;")
        elif isinstance(s, Continue):
            w(f"{pad}continue;")
        elif isinstance(s, If):
            w(f"{pad}if ({self.e(s.test, 0, depth)})")
            self.braced(s.then, depth)
            els = s.else_
            while els is not None:
                if len(els) == 1 and isinstance(els[0], If):
                    w(f"{pad}else if ({self.e(els[0].test, 0, depth)})")
                    self.braced(els[0].then, depth)
                    els = els[0].else_
                else:
                    w(f"{pad}else")
                    self.braced(els, depth)
                    els = None
        elif isinstance(s, Loop):
            if s.is_do:
                w(f"{pad}do")
                self.braced(s.body, depth)
                self.lines[-1] += f" while ({self.e(s.test, 0, depth)});"
            elif s.init is not None or s.end is not None:
                init = self.e(s.init, 0, depth) if s.init is not None else ""
                end = self.e(s.end, 0, depth) if s.end is not None else ""
                w(f"{pad}for ({init}; {self.e(s.test, 0, depth)}; {end})")
                self.braced(s.body, depth)
            else:
                w(f"{pad}while ({self.e(s.test, 0, depth)})")
                self.braced(s.body, depth)
        elif isinstance(s, FuncDecl):
            name = (f"{self.n(s.ns)}::" if s.ns else "") + self.n(s.name)
            args = ", ".join(self.vname(a, True) for a in s.args)
            if s.body is None:
                w(f"{pad}function {name}({args}) {{}}")
            else:
                if not s.body:
                    raise PrintError(f"function {name} has a body flag but no statements")
                w(f"{pad}function {name}({args})")
                self.braced(s.body, depth)
        else:
            raise PrintError(f"cannot print statement {type(s).__name__}")

    def braced(self, stmts, depth: int):
        pad = INDENT * depth
        self.lines.append(f"{pad}{{")
        self.block(stmts, depth + 1)
        self.lines.append(f"{pad}}}")


def to_text(stmts, names: Optional[Dict[int, str]] = None) -> str:
    p = Printer(names)
    i = 0
    while i < len(stmts):
        s = stmts[i]
        if isinstance(s, FuncDecl) and s.package:
            j = i
            while j < len(stmts) and isinstance(stmts[j], FuncDecl) and stmts[j].package == s.package:
                j += 1
            p.lines.append(f"package {p.n(s.package)}")
            p.lines.append("{")
            for f in stmts[i:j]:
                p.stmt(f, 1)
                p.lines.append("")
            if p.lines[-1] == "":
                p.lines.pop()
            p.lines.append("};")
            p.lines.append("")
            i = j
            continue
        p.stmt(s, 0)
        if isinstance(s, FuncDecl):
            p.lines.append("")
        i += 1
    return "\n".join(p.lines).rstrip("\n") + "\n"
