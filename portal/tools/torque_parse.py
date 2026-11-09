"""TorqueScript text -> syntax tree (tsast). Reads the scripts tsprint writes (standard TorqueScript)."""
from __future__ import annotations

import re
import struct
from typing import List, Optional

from torque_names import PARENT_KEY, is_hashed, name_key
from torque_ast import (Assign, AssignOp, Break, Call, CommaCat, Conditional, Continue, ExprStmt, FloatBinary,
                   FloatConst, FloatUnary, FuncDecl, Ident, If, IntBinary, IntConst, IntUnary, Loop, ObjectDecl,
                   Return, SlotAccess, SlotAssign, SlotAssignOp, StrCat, StrConst, StrEq, Var)


class ParseError(Exception):
    pass


TOKEN = re.compile(r"""
    (?P<ws>\s+|//[^\n]*|/\*.*?\*/)
  | (?P<var>[%$][A-Za-z_][A-Za-z0-9_]*(?:::[A-Za-z0-9_]+)*)
  | (?P<float>\d+\.\d+(?:[eE][+-]?\d+)?|\d+[eE][+-]?\d+)
  | (?P<hex>0[xX][0-9a-fA-F]+)
  | (?P<int>\d+)
  | (?P<str>"(?:[^"\\]|\\.)*")
  | (?P<tag>'(?:[^'\\]|\\.)*')
  | (?P<ident>[A-Za-z_][A-Za-z0-9_]*)
  | (?P<op>!\$=|<<=|>>=|::|\$=|==|!=|<=|>=|&&|\|\||<<|>>|\+\+|--|\+=|-=|\*=|/=|%=|&=|\|=|\^=|[-+*/%&|^!~<>=?:;,.(){}\[\]@])
""", re.S | re.X)

KEYWORDS = {"function", "package", "new", "datablock", "if", "else", "while", "for", "do", "return", "break",
            "continue"}
BINARY = {"||": 3, "&&": 4, "|": 5, "^": 6, "&": 7, "==": 8, "!=": 8, "<": 9, "<=": 9, ">": 9, ">=": 9,
          "@": 10, "SPC": 10, "TAB": 10, "NL": 10, "$=": 10, "!$=": 10, "<<": 11, ">>": 11,
          "+": 12, "-": 12, "*": 13, "/": 13, "%": 13}
ASSIGN_OPS = {"=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>="}
ASSIGN, COND, UNARY = 1, 2, 14


def unescape(body: str) -> str:
    out, i = [], 0
    while i < len(body):
        ch = body[i]
        if ch != "\\":
            out.append(ch)
            i += 1
            continue
        nxt = body[i + 1]
        if nxt == "x":
            out.append(chr(int(body[i + 2:i + 4], 16)))
            i += 4
            continue
        out.append({"n": "\n", "t": "\t", "r": "\r"}.get(nxt, nxt))
        i += 2
    return "".join(out)


def var_name(text: str) -> str:
    """Variables are hashed with their % or $ ("%this"); a hashed name stands for itself."""
    return text[1:] if is_hashed(text[1:]) else text


class Tok:
    __slots__ = ("kind", "text", "pos")

    def __init__(self, kind, text, pos):
        self.kind, self.text, self.pos = kind, text, pos

    def __repr__(self):
        return f"{self.kind}:{self.text}"


def tokenize(src: str) -> List[Tok]:
    out, pos = [], 0
    while pos < len(src):
        m = TOKEN.match(src, pos)
        if not m:
            line = src.count("\n", 0, pos) + 1
            raise ParseError(f"line {line}: unexpected {src[pos:pos + 20]!r}")
        kind = m.lastgroup
        if kind != "ws":
            out.append(Tok(kind, m.group(), pos))
        pos = m.end()
    out.append(Tok("eof", "", pos))
    return out


class Parser:
    def __init__(self, src: str):
        self.src = src
        self.toks = tokenize(src)
        self.i = 0

    # ------------------------------------------------------------------ helpers
    @property
    def tok(self) -> Tok:
        return self.toks[self.i]

    def peek(self, k: int = 1) -> Tok:
        return self.toks[min(self.i + k, len(self.toks) - 1)]

    def at(self, text: str) -> bool:
        t = self.tok
        return t.text == text and t.kind in ("op", "ident")

    def eat(self, text: str) -> Tok:
        if not self.at(text):
            self.fail(f"expected {text!r}")
        t = self.tok
        self.i += 1
        return t

    def take(self) -> Tok:
        t = self.tok
        self.i += 1
        return t

    def fail(self, msg: str):
        line = self.src.count("\n", 0, self.tok.pos) + 1
        raise ParseError(f"line {line}: {msg}, found {self.tok.text!r}")

    def ident(self) -> str:
        if self.tok.kind != "ident":
            self.fail("expected a name")
        return self.take().text

    # ------------------------------------------------------------------ statements
    def program(self) -> list:
        out = []
        while self.tok.kind != "eof":
            if self.at("package") and self.peek().kind == "ident":
                self.take()
                pkg = self.ident()
                self.eat("{")
                while not self.at("}"):
                    f = self.function()
                    f.package = pkg
                    out.append(f)
                self.eat("}")
                self.eat(";")
            else:
                out.append(self.statement())
        return out

    def function(self) -> FuncDecl:
        self.eat("function")
        name = self.ident()
        ns = None
        if self.at("::"):
            self.take()
            ns, name = name, self.ident()
        self.eat("(")
        args = []
        while not self.at(")"):
            t = self.take()
            if t.kind != "var" or not t.text.startswith("%"):
                self.fail("expected an argument like %name")
            args.append(var_name(t.text))
            if not self.at(")"):
                self.eat(",")
        self.eat(")")
        body = self.block()
        return FuncDecl(name, ns, None, args, body or None)

    def block(self) -> list:
        self.eat("{")
        out = []
        while not self.at("}"):
            out.append(self.statement())
        self.eat("}")
        return out

    def statement(self):
        t = self.tok
        if t.kind == "ident":
            w = t.text
            if w == "function":
                return self.function()
            if w == "if":
                self.take()
                self.eat("(")
                test = self.expr()
                self.eat(")")
                then = self.block()
                els = None
                if self.at("else"):
                    self.take()
                    els = [self.statement()] if self.at("if") else self.block()
                return If(test, then, els)
            if w == "while":
                self.take()
                self.eat("(")
                test = self.expr()
                self.eat(")")
                return Loop(None, test, self.block(), None)
            if w == "for":
                self.take()
                self.eat("(")
                init = None if self.at(";") else self.expr()
                self.eat(";")
                test = self.expr()
                self.eat(";")
                end = None if self.at(")") else self.expr()
                self.eat(")")
                return Loop(init, test, self.block(), end)
            if w == "do":
                self.take()
                body = self.block()
                self.eat("while")
                self.eat("(")
                test = self.expr()
                self.eat(")")
                self.eat(";")
                return Loop(None, test, body, None, is_do=True)
            if w == "return":
                self.take()
                if self.at(";"):
                    self.take()
                    return Return(None)
                e = self.expr()
                self.eat(";")
                return Return(e)
            if w in ("break", "continue"):
                self.take()
                self.eat(";")
                return Break() if w == "break" else Continue()
        e = self.expr()
        self.eat(";")
        return ExprStmt(e)

    # ------------------------------------------------------------------ expressions
    def expr(self, min_prec: int = 0):
        left = self.unary()
        while True:
            t = self.tok
            op = t.text if t.kind in ("op", "ident") else None
            if op in ASSIGN_OPS and min_prec <= ASSIGN:
                self.take()
                left = self.assignment(left, op)
                continue
            if op == "?" and min_prec <= COND:
                self.take()
                a = self.expr(COND + 1)
                self.eat(":")
                b = self.expr(COND + 1)
                left = Conditional(left, a, b)
                continue
            p = BINARY.get(op) if op is not None else None
            if p is None or p < min_prec or (t.kind == "ident" and op not in ("SPC", "TAB", "NL")):
                return left
            self.take()
            right = self.expr(p + 1)
            left = self.binary(op, left, right)

    @staticmethod
    def binary(op, left, right):
        if op in ("+", "-", "*", "/"):
            return FloatBinary(op, left, right)
        if op in ("$=", "!$="):
            return StrEq(left, right, op == "$=")
        if op in ("@", "SPC", "TAB", "NL"):
            return StrCat(left, right, {"@": None, "SPC": " ", "TAB": "\t", "NL": "\n"}[op])
        return IntBinary(op, left, right)

    def assignment(self, target, op):
        value = self.expr(ASSIGN)
        if isinstance(target, Var):
            return Assign(target, value) if op == "=" else AssignOp(target, op[:-1], value)
        if isinstance(target, SlotAccess):
            if op == "=":
                return SlotAssign(target.obj, target.slot, target.index, value)
            return SlotAssignOp(target.obj, target.slot, target.index, op[:-1], value)
        self.fail("cannot assign to this")

    def unary(self):
        t = self.tok
        if t.kind == "op" and t.text in ("!", "~"):
            self.take()
            return IntUnary(t.text, self.unary())
        if t.kind == "op" and t.text == "-":
            self.take()
            return FloatUnary(self.unary())
        return self.postfix(self.primary())

    def postfix(self, n):
        while True:
            if self.at("."):
                self.take()
                name = self.ident()
                if self.at("("):
                    n = Call(name, None, [n] + self.args(), 1)
                    continue
                index = self.index() if self.at("[") else None
                n = SlotAccess(n, name, index)
                continue
            if self.at("++") or self.at("--"):
                op = self.take().text[0]
                one = IntConst(1)
                if isinstance(n, Var):
                    return AssignOp(n, op, one)
                if isinstance(n, SlotAccess):
                    return SlotAssignOp(n.obj, n.slot, n.index, op, one)
                self.fail("++/-- needs a variable or field")
            return n

    def args(self) -> list:
        self.eat("(")
        out = []
        while not self.at(")"):
            out.append(self.expr(ASSIGN))
            if not self.at(")"):
                self.eat(",")
        self.eat(")")
        return out

    def index(self):
        self.eat("[")
        n = self.expr(ASSIGN)
        while self.at(","):
            self.take()
            n = CommaCat(n, self.expr(ASSIGN))
        self.eat("]")
        return n

    def primary(self):
        t = self.tok
        k = t.kind
        if k == "int":
            self.take()
            return IntConst(int(t.text))
        if k == "hex":
            self.take()
            return IntConst(int(t.text, 16))
        if k == "float":
            self.take()
            return FloatConst(struct.pack("<f", float(t.text)), t.text)
        if k == "str":
            self.take()
            return StrConst(unescape(t.text[1:-1]))
        if k == "tag":
            self.take()
            return StrConst(unescape(t.text[1:-1]), tag=True)
        if k == "var":
            self.take()
            index = self.index() if self.at("[") else None
            return Var(var_name(t.text), t.text[0] == "%", index)
        if k == "op" and t.text == "(":
            self.take()
            e = self.expr()
            self.eat(")")
            return e
        if k == "ident":
            if t.text in ("new", "datablock"):
                return self.object()
            self.take()
            if self.at("::"):
                self.take()
                name = self.ident()
                args = self.args()
                return Call(name, t.text, args, 2 if name_key(t.text) == PARENT_KEY else 0)
            if self.at("("):
                return Call(t.text, None, self.args(), 0)
            return Ident(t.text)
        self.fail("expected an expression")

    def object(self) -> ObjectDecl:
        datablock = self.take().text == "datablock"
        if self.at("("):
            self.take()
            cls = self.expr()
            self.eat(")")
        else:
            cls = Ident(self.ident())
        self.eat("(")
        name, parent, args = StrConst(""), None, []
        if not self.at(")"):
            if not self.at(",") and not self.at(":"):
                name = self.expr(ASSIGN)
            if self.at(":"):
                self.take()
                parent = self.ident()
            while self.at(","):
                self.take()
                args.append(self.expr(ASSIGN))
        self.eat(")")
        o = ObjectDecl(cls, name, parent, datablock, args)
        self.eat("{")
        while not self.at("}"):
            if self.at("new") or self.at("datablock"):
                o.subs.append(self.object())
                self.eat(";")
                continue
            slot = self.ident()
            index = self.index() if self.at("[") else None
            self.eat("=")
            o.slots.append(SlotAssign(None, slot, index, self.expr(ASSIGN)))
            self.eat(";")
        self.eat("}")
        return o


def parse(src: str) -> list:
    return Parser(src).program()
