#!/usr/bin/env python3
"""
Starter C++ for one function, written from its disassembly.

This is a small "lifter", not a decompiler. It walks the instructions once, keeps track of what
each register holds (this, an argument, a field, a call's result...), and writes the side effects
(stores, calls, returns, branches) as C++. Branches become `if (...) goto L_xx;`, and the simple
shapes are then folded into `if { }`, `if { } else { }` and `do { } while ()`.

What makes it useful for matching:

* Calls and globals use the relocation names the project verifies against: `sub_XXXXXXXX` for a
  function, `DAT_XXXXXXXX` for data, declared `extern "C"`, so a correct guess scores 100% on
  decomp.me and passes the portal's address check. No address is ever written as a number.
* A call made with ECX set up becomes a method call (`m_Field18.sub_X()`, `m_Field54->sub_X()`),
  and `call [vtable+N]` a virtual call, so the generated calling convention matches.
* The output always compiles: anything it does not understand is left as a `// TODO:` comment
  instead of a guess that would not build.

The result is a starting point. Field names and types are placeholders to rename.
"""

from __future__ import annotations

import re
import struct
from typing import Dict, Iterable, List, Optional, Sequence, Set, Tuple

R32 = ["eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi"]
SUBREG: Dict[str, Tuple[str, int, bool]] = {}
for _i, _r in enumerate(R32):
    SUBREG[_r] = (_r, 4, False)
for _i, _r in enumerate(["ax", "cx", "dx", "bx", "sp", "bp", "si", "di"]):
    SUBREG[_r] = (R32[_i], 2, False)
for _i, _r in enumerate(["al", "cl", "dl", "bl"]):
    SUBREG[_r] = (R32[_i], 1, False)
for _i, _r in enumerate(["ah", "ch", "dh", "bh"]):
    SUBREG[_r] = (R32[_i], 1, True)
SIZES = {"byte": 1, "word": 2, "dword": 4, "qword": 8, "tbyte": 10}
JCC = {"je": "==", "jz": "==", "jne": "!=", "jnz": "!=", "jl": "<", "jnge": "<", "jge": ">=", "jnl": ">=",
       "jle": "<=", "jng": "<=", "jg": ">", "jnle": ">", "jb": "u<", "jc": "u<", "jnae": "u<", "jae": "u>=",
       "jnb": "u>=", "jnc": "u>=", "jbe": "u<=", "jna": "u<=", "ja": "u>", "jnbe": "u>", "js": "s", "jns": "ns",
       "jp": "p", "jpe": "p", "jnp": "np", "jpo": "np"}
SETCC = {"set" + k[1:]: v for k, v in JCC.items()}
ARITH = {"add": "+", "sub": "-", "and": "&", "or": "|", "xor": "^", "shl": "<<", "sal": "<<", "shr": ">>",
         "sar": ">>", "imul": "*"}
NEG = {"==": "!=", "!=": "==", "<": ">=", ">=": "<", ">": "<=", "<=": ">"}
CTYPE = {"int": "int", "uint": "unsigned int", "bool": "bool", "char": "char", "uchar": "unsigned char",
         "short": "short", "ushort": "unsigned short", "float": "float", "double": "double", "void": "void"}


def ctype(t: str) -> str:
    if t.startswith("ptr:"):
        return ctype(t[4:]) + "*"
    if t.startswith("obj:"):
        return t[4:]
    return CTYPE.get(t, t)


def hexnum(v: int) -> str:
    if -0x10000 < v < 0x10000:
        return str(v)
    return f"-0x{-v:X}" if v < 0 else f"0x{v:X}"


def s32(v: int) -> int:
    v &= 0xFFFFFFFF
    return v - (1 << 32) if v & 0x80000000 else v


# --------------------------------------------------------------------------- #
# Operands and instructions
# --------------------------------------------------------------------------- #

class Reg:
    def __init__(self, name: str):
        self.name = name
        self.parent, self.size, self.high = SUBREG[name]


class Imm:
    def __init__(self, value: int):
        self.value = value & 0xFFFFFFFF
        self.sym: Optional[str] = None


class Mem:
    def __init__(self, base, index, scale, disp, size, seg):
        self.base, self.index, self.scale, self.disp, self.size, self.seg = base, index, scale, disp, size, seg
        self.sym: Optional[str] = None
        self.sized = size is not None


class FpuReg:
    def __init__(self, i: int):
        self.i = i


_MEM_RE = re.compile(r"^(?:(byte|word|dword|qword|tbyte|xmmword) ptr )?(?:(\w\w):)?\[([^\]]*)\]$")


def parse_operand(s: str):
    s = s.strip()
    m = _MEM_RE.match(s)
    if m:
        base = index = None
        scale, disp = 1, 0
        for sign, term in re.findall(r"([+-]?)([^+-]+)", m.group(3).replace(" ", "")):
            if "*" in term:
                r, sc = term.split("*")
                if r in SUBREG:
                    index, scale = SUBREG[r][0], int(sc, 0)
                    continue
            if term in SUBREG:
                if base is None:
                    base = SUBREG[term][0]
                else:
                    index = SUBREG[term][0]
                continue
            try:
                v = int(term, 0)
            except ValueError:
                return None
            disp += -v if sign == "-" else v
        size = SIZES.get(m.group(1)) if m.group(1) else None
        return Mem(base, index, scale, disp, size, m.group(2))
    if s in SUBREG:
        return Reg(s)
    m = re.match(r"^st(?:\((\d)\))?$", s)
    if m:
        return FpuReg(int(m.group(1) or 0))
    try:
        return Imm(int(s, 0))
    except ValueError:
        return None


class Insn:
    def __init__(self, off: int, size: int, text: str):
        self.off, self.size, self.text = off, size, text
        parts = text.split(None, 1)
        self.mn = parts[0] if parts else ""
        rest = parts[1] if len(parts) > 1 else ""
        if self.mn in ("rep", "repe", "repne", "lock") and rest:
            more = rest.split(None, 1)
            self.mn = self.mn + " " + more[0]
            rest = more[1] if len(more) > 1 else ""
        self.ops_text = [o.strip() for o in rest.split(",")] if rest else []
        self.ops = [parse_operand(o) for o in self.ops_text]
        self.ok = all(o is not None for o in self.ops)
        self.branch: Optional[int] = None      # internal target offset (jmp/jcc)
        self.ext: Optional[str] = None         # external call/jmp target symbol
        self.ext_va: Optional[int] = None
        sized = [o.size for o in self.ops if isinstance(o, Reg)]
        for o in self.ops:
            if isinstance(o, Mem) and o.size is None:
                o.size = sized[0] if sized and self.mn not in ("movzx", "movsx", "lea") else 4


def parse_disasm(disasm: Sequence[str]) -> List[Insn]:
    out = []
    for ln in disasm:
        if "|" not in ln:
            continue
        left, right = ln.split("|", 1)
        m = re.match(r"\s*\+([0-9A-Fa-f]+):\s*((?:[0-9A-Fa-f]{2}\s?)+)", left)
        if not m:
            continue
        out.append(Insn(int(m.group(1), 16), len(m.group(2).split()), right.strip()))
    return out


def attach_relocs(insns: List[Insn], target: bytes, va: Optional[int], relocs) -> None:
    """Give operands the names of the relocations that cover them (sub_/DAT_ symbols)."""
    by_off: Dict[int, str] = {}
    kinds: Dict[int, int] = {}
    for r in relocs or []:
        off, sym, kind = (r.offset, r.symbol, r.kind) if hasattr(r, "offset") else (r[0], r[1], r[2])
        by_off[off] = sym
        kinds[off] = kind
    n = len(target)
    for ins in insns:
        fields = [o for o in by_off if ins.off <= o < ins.off + ins.size]
        is_branch = ins.mn == "call" or ins.mn.startswith("j")
        if is_branch and len(ins.ops) == 1 and isinstance(ins.ops[0], Imm):
            dest = ins.ops[0].value
            rel_target = (ins.off + ins.size + s32(struct.unpack_from("<i", target, ins.off + ins.size - 4)[0])) \
                if ins.size >= 5 and ins.off + ins.size <= n else dest
            if 0 <= dest < n and ins.mn != "call":
                ins.branch = dest
            else:
                sym = next((by_off[f] for f in fields if kinds.get(f) == 0x14), None)
                if sym and sym.startswith("_"):
                    ins.ext = sym[1:]
                elif va is not None:
                    ins.ext_va = (va + (dest if dest < (1 << 31) else dest - (1 << 32))) & 0xFFFFFFFF
                    ins.ext = f"sub_{ins.ext_va:08X}"
                else:
                    ins.ext = f"sub_{rel_target & 0xFFFFFFFF:08X}"
            continue
        for f in fields:
            sym = by_off[f]
            if not sym.startswith("_"):
                continue          # a place inside this function (jump table) or the function itself
            if f + 4 > n:
                continue
            val = struct.unpack_from("<I", target, f)[0]
            for o in ins.ops:
                if isinstance(o, Mem) and o.sym is None and (o.disp & 0xFFFFFFFF) == val:
                    o.sym = sym[1:]
                    break
                if isinstance(o, Imm) and o.sym is None and o.value == val:
                    o.sym = sym[1:]
                    break


# --------------------------------------------------------------------------- #
# Expressions
# --------------------------------------------------------------------------- #

class E:
    atomic = True
    impure = False

    def t(self, cx) -> str:
        return "int"

    def r(self, cx) -> str:
        raise NotImplementedError

    def kids(self) -> Iterable["E"]:
        return ()


def par(cx, e: E) -> str:
    s = e.r(cx)
    return s if e.atomic else f"({s})"


def conv(cx, e: E, want: Optional[str]) -> str:
    t = e.t(cx)
    if want is None or want == t or want == "void":
        return e.r(cx)
    if want.startswith("ptr:"):
        if isinstance(e, Num) and e.v == 0:
            return "0"
        if t.startswith("ptr:") and want == "ptr:void":
            return e.r(cx)
        return f"({ctype(want)}){par(cx, e)}"
    if t.startswith("ptr:"):
        return e.r(cx) if want == "bool" else f"({ctype(want)}){par(cx, e)}"
    if t in ("float", "double") and want not in ("float", "double"):
        return f"({ctype(want)}){par(cx, e)}"
    return e.r(cx)


class Num(E):
    def __init__(self, v: int):
        self.v = v

    def r(self, cx):
        return hexnum(self.v)


class FNum(E):
    def __init__(self, v: float):
        self.v = v

    def t(self, cx):
        return "float"

    def r(self, cx):
        return f"{self.v:.1f}f"


class Unknown(E):
    """A register whose value the lifter could not follow; it renders as 0 and is flagged."""
    def __init__(self, what: str):
        self.what = what

    def r(self, cx):
        cx.note(f"{self.what} is not known here (left as 0)")
        return "0"


class This(E):
    def t(self, cx):
        return "ptr:" + cx.cls_ref

    def r(self, cx):
        return "this"


class Arg(E):
    def __init__(self, i: int):
        self.i = i

    def t(self, cx):
        return cx.arg_types.get(self.i, "int")

    def r(self, cx):
        return f"a{self.i}"


class Local(E):
    def __init__(self, name: str):
        self.name = name

    def t(self, cx):
        return cx.locals.get(self.name, "int")

    def r(self, cx):
        return self.name


class Var(E):
    def __init__(self, name: str, typ: str = "int"):
        self.name, self.typ = name, typ

    def t(self, cx):
        return self.typ

    def r(self, cx):
        return self.name


class Temp(E):
    def __init__(self, d: "SDef"):
        self.d = d

    @property
    def impure(self):
        return self.d.inline and self.d.value.impure

    def t(self, cx):
        return self.d.value.t(cx)

    def r(self, cx):
        return self.d.value.r(cx) if self.d.inline else self.d.name

    @property
    def atomic(self):
        return not self.d.inline or self.d.value.atomic

    def kids(self):
        return (self.d.value,) if self.d.inline else ()


class Field(E):
    impure = True

    def __init__(self, off: int, size: int, kind: str):
        self.off, self.size, self.kind = off, size, kind

    def t(self, cx):
        f = cx.field_ok(self.off, self.size, self.kind)
        return f if f else self.kind

    def r(self, cx):
        if cx.field_ok(self.off, self.size, self.kind):
            return f"m_Field{self.off:02X}"
        if not self.off:
            return f"*({ctype(self.kind)}*)this"
        sign = "-" if self.off < 0 else "+"
        return f"*({ctype(self.kind)}*)((char*)this {sign} 0x{abs(self.off):X})"

    @property
    def atomic(self):
        return True


class FieldAddr(E):
    def __init__(self, off: int):
        self.off = off

    def t(self, cx):
        f = cx.field_ok(self.off, None)
        return ("ptr:" + f[4:] if f.startswith("obj:") else "ptr:" + f) if f else "ptr:char"

    def r(self, cx):
        if cx.field_ok(self.off, None):
            return f"&m_Field{self.off:02X}"
        return f"((char*)this {'-' if self.off < 0 else '+'} 0x{abs(self.off):X})"

    @property
    def atomic(self):
        return False


class Glob(E):
    impure = True

    def __init__(self, sym: str, size: int, kind: str):
        self.sym, self.size, self.kind = sym, size, kind

    def _same(self, g) -> bool:
        return g["size"] == self.size and (g["type"] in ("float", "double")) == (self.kind in ("float", "double"))

    def t(self, cx):
        g = cx.globals[self.sym]
        return g["type"] if g["form"] == "scalar" and self._same(g) else self.kind

    def r(self, cx):
        g = cx.globals[self.sym]
        if g["form"] == "scalar" and self._same(g):
            return self.sym
        if g["form"] == "array" and self._same(g):
            return f"{self.sym}[0]"
        return f"*({ctype(self.kind)}*)&{self.sym}"


class GlobElem(E):
    impure = True

    def __init__(self, sym: str, idx: E, size: int, kind: str):
        self.sym, self.idx, self.size, self.kind = sym, idx, size, kind

    def t(self, cx):
        g = cx.globals[self.sym]
        return g["type"] if g["size"] == self.size else self.kind

    def r(self, cx):
        g = cx.globals[self.sym]
        if g["form"] == "array" and g["size"] == self.size:
            return f"{self.sym}[{conv(cx, self.idx, 'int')}]"
        return f"(({ctype(self.kind)}*)&{self.sym})[{conv(cx, self.idx, 'int')}]"

    def kids(self):
        return (self.idx,)


class GlobAddr(E):
    def __init__(self, sym: str):
        self.sym = sym

    def t(self, cx):
        g = cx.globals[self.sym]
        return "ptr:" + (g["type"] if g["form"] != "object" else "Object")

    def r(self, cx):
        g = cx.globals[self.sym]
        return self.sym if g["form"] in ("array", "address") else f"&{self.sym}"



class Deref(E):
    impure = True

    def __init__(self, addr: E, size: int, kind: str):
        self.addr, self.size, self.kind = addr, size, kind

    def t(self, cx):
        return self.kind

    def r(self, cx):
        at = self.addr.t(cx)
        if at == "ptr:" + self.kind:
            return f"*{par(cx, self.addr)}"
        if at in ("float", "double"):
            return f"*({ctype(self.kind)}*)(int){par(cx, self.addr)}"
        return f"*({ctype(self.kind)}*){par(cx, self.addr)}"

    def kids(self):
        return (self.addr,)


class AddrOf(E):
    def __init__(self, e: E):
        self.e = e

    def t(self, cx):
        return "ptr:" + self.e.t(cx)

    def r(self, cx):
        return f"&{self.e.r(cx)}"

    def kids(self):
        return (self.e,)

    atomic = False


class Bin(E):
    atomic = False

    def __init__(self, op: str, a: E, b: E):
        self.op, self.a, self.b = op, a, b

    @property
    def impure(self):
        return self.a.impure or self.b.impure

    def t(self, cx):
        if self.op in ("&", "|", "^", "<<", ">>", "%"):
            return "int"
        ta, tb = self.a.t(cx), self.b.t(cx)
        return "float" if "float" in (ta, tb) or "double" in (ta, tb) else "int"

    def r(self, cx):
        want = None if self.t(cx) == "float" else "int"
        return f"{self._side(cx, self.a, want)} {self.op} {self._side(cx, self.b, want)}"

    def _side(self, cx, e, want):
        s = conv(cx, e, want)
        if isinstance(e, Bin) and e.op == self.op and self.op in ("+", "*", "&", "|", "^") and e is self.a:
            return s
        return s if e.atomic else f"({s})"

    def kids(self):
        return (self.a, self.b)


class Un(E):
    atomic = False

    def __init__(self, op: str, a: E):
        self.op, self.a = op, a

    @property
    def impure(self):
        return self.a.impure

    def t(self, cx):
        return self.a.t(cx) if self.a.t(cx) in ("float", "double") else "int"

    def r(self, cx):
        return f"{self.op}{par(cx, self.a)}"

    def kids(self):
        return (self.a,)


class Cast(E):
    atomic = False

    def __init__(self, typ: str, a: E):
        self.typ, self.a = typ, a

    @property
    def impure(self):
        return self.a.impure

    def t(self, cx):
        return self.typ

    def r(self, cx):
        return f"({ctype(self.typ)}){par(cx, self.a)}"

    def kids(self):
        return (self.a,)


class Cmp(E):
    atomic = False

    def __init__(self, op: str, a: E, b: E, unsigned: bool = False):
        self.op, self.a, self.b, self.unsigned = op, a, b, unsigned

    @property
    def impure(self):
        return self.a.impure or self.b.impure

    def t(self, cx):
        return "bool"

    def neg(self) -> "Cmp":
        return Cmp(NEG[self.op], self.a, self.b, self.unsigned)

    def r(self, cx):
        zero = isinstance(self.b, Num) and self.b.v == 0
        if zero and self.op in ("!=", "==") and not self.unsigned:
            return self.a.r(cx) if self.op == "!=" else f"!{par(cx, self.a)}"
        if self.unsigned:
            return f"(unsigned int){par(cx, self.a)} {self.op} (unsigned int){par(cx, self.b)}"
        fl = any(t in ("float", "double") for t in (self.a.t(cx), self.b.t(cx)))
        sides = []
        for e in (self.a, self.b):
            s = e.r(cx) if fl or not e.t(cx).startswith("ptr:") or isinstance(e, Num) else conv(cx, e, "int")
            sides.append(s if e.atomic or isinstance(e, Num) else f"({s})")
        return f"{sides[0]} {self.op} {sides[1]}"

    def kids(self):
        return (self.a, self.b)


class Callee:
    def __init__(self, name: str, kind: str, owner: Optional[str] = None, slot: Optional[int] = None):
        self.name, self.kind, self.owner, self.slot = name, kind, owner, slot
        self.conv = "cdecl"
        self.arg_types: Optional[List[str]] = None
        self.variadic = False
        self.ret_hint = "int"
        self.used = False

    def note_args(self, types: List[str]) -> None:
        if self.arg_types is None:
            self.arg_types = list(types)
            self.overloads = [list(types)]
        elif len(self.arg_types) != len(types):
            if self.kind == "func":
                self.variadic = True
                self.conv = "cdecl"
            elif all(len(o) != len(types) for o in self.overloads):
                self.overloads.append(list(types))   # same address, another C++ overload

    @property
    def ret(self) -> str:
        return self.ret_hint if self.used else "void"

    def params(self, ts: Optional[List[str]] = None) -> str:
        if ts is None and self.variadic and self.conv == "cdecl" and self.kind == "func":
            return "..."
        ts = self.arg_types or [] if ts is None else ts
        return ", ".join(ctype(t) for t in ts) if ts else ("void" if self.kind == "func" else "")

    def decls(self, virtual: bool = False) -> List[str]:
        kw = "virtual " if virtual else ""
        return [f"    {kw}{ctype(self.ret)} {self.name}({self.params(o)});"
                for o in (getattr(self, "overloads", None) or [self.arg_types or []])][:1 if virtual else None]


class Call(E):
    impure = True
    atomic = True

    def __init__(self, callee: Callee, obj: Optional[E], args: List[E], fptr: Optional[E] = None):
        self.callee, self.obj, self.args, self.fptr = callee, obj, args, fptr

    def t(self, cx):
        return self.callee.ret

    def _args(self, cx):
        ts = self.callee.arg_types or []
        for o in getattr(self.callee, "overloads", None) or []:
            if len(o) == len(self.args):
                ts = o
        out = []
        for i, a in enumerate(self.args):
            if i < len(ts) and not self.callee.variadic:
                want = ts[i]
            else:
                want = "double" if a.t(cx) in ("float", "double") else "int"
            out.append(conv(cx, a, want))
        return ", ".join(out)

    def r(self, cx):
        c = self.callee
        args = self._args(cx)
        if c.kind == "fptr":
            conv_kw = "__stdcall" if c.conv == "stdcall" else "__cdecl"
            ft = f"{ctype(c.ret)} ({conv_kw}*)({c.params() or 'void'})"
            return f"(({ft}){conv(cx, self.fptr, 'int')})({args})"
        if c.kind == "func":
            clash = any(c.name in st["methods"] for st in cx.structs.values())
            return f"{'::' if clash else ''}{c.name}({args})"
        return f"{cx.obj_access(self.obj, c.owner)}{c.name}({args})"

    def kids(self):
        out = list(self.args)
        if self.obj is not None:
            out.append(self.obj)
        if self.fptr is not None:
            out.append(self.fptr)
        return out


# --------------------------------------------------------------------------- #
# Statements
# --------------------------------------------------------------------------- #

class S:
    def exprs(self) -> List[E]:
        return []


class SDef(S):
    def __init__(self, name: str, value: E):
        self.name, self.value = name, value
        self.uses = 0
        self.inline = False

    def exprs(self):
        return [self.value]


class SAssign(S):
    def __init__(self, lhs: E, rhs: E, op: str = "="):
        self.lhs, self.rhs, self.op = lhs, rhs, op

    def exprs(self):
        return [self.lhs, self.rhs]


class SIf(S):
    def __init__(self, cond: E, label: str):
        self.cond, self.label = cond, label

    def exprs(self):
        return [self.cond]


class SGoto(S):
    def __init__(self, label: str):
        self.label = label


class SLabel(S):
    def __init__(self, name: str):
        self.name = name


class SRet(S):
    def __init__(self, val: Optional[E], fval: Optional[E]):
        self.val, self.fval = val, fval

    def exprs(self):
        return [e for e in (self.val, self.fval) if e is not None]


class SComment(S):
    def __init__(self, text: str):
        self.text = text


class SBlock(S):
    def __init__(self, kind: str, cond: E, body: List[S], other: Optional[List[S]] = None):
        self.kind, self.cond, self.body, self.other = kind, cond, body, other or []

    def exprs(self):
        return [self.cond]


def walk(e: E):
    yield e
    for k in e.kids():
        yield from walk(k)


def neg(c: E) -> E:
    if isinstance(c, Cmp):
        return c.neg()
    return Cmp("==", c, Num(0))


# --------------------------------------------------------------------------- #
# Names: class, namespaces, templates
# --------------------------------------------------------------------------- #

def split_scopes(q: str) -> List[str]:
    parts, depth, cur, i = [], 0, "", 0
    while i < len(q):
        ch = q[i]
        if ch == "<":
            depth += 1
        elif ch == ">":
            depth -= 1
        if depth == 0 and q.startswith("::", i):
            parts.append(cur)
            cur, i = "", i + 2
            continue
        cur += ch
        i += 1
    parts.append(cur)
    return [p.strip() for p in parts if p.strip()]


_ID = re.compile(r"^[A-Za-z_]\w*$")


def plan_names(symbol: str) -> dict:
    """{ns: [..], cls: str|None, meth: str, template: None|(name, [args])} with C++-safe names."""
    scopes = split_scopes(symbol or "")
    if not scopes:
        return {"ns": [], "cls": None, "meth": "fn", "template": None}
    meth = re.sub(r"\W", "_", scopes[-1])
    if not re.match(r"^[A-Za-z_~]", meth):
        meth = "fn_" + meth
    if len(scopes) == 1:
        return {"ns": [], "cls": None, "meth": meth, "template": None}
    cls, ns = scopes[-2], scopes[:-2]
    tmpl = None
    m = re.fullmatch(r"(\w+)<(.*)>", cls)
    if m and all(_ID.match(n) for n in ns):
        args = [a.strip() for a in _split_args(m.group(2))]
        if args and all(re.fullmatch(r"-?\d+", a) or all(_ID.match(p) for p in split_scopes(a)) for a in args):
            tmpl = (m.group(1), args)
    if tmpl is None:
        ns = [re.sub(r"\W", "_", n) for n in ns]
        cls = re.sub(r"\W", "_", cls)
        if not re.match(r"^[A-Za-z_]", cls):
            cls = "C_" + cls
    return {"ns": ns, "cls": cls if tmpl is None else tmpl[0], "meth": meth, "template": tmpl}


def _split_args(s: str) -> List[str]:
    out, depth, cur = [], 0, ""
    for ch in s:
        if ch == "<":
            depth += 1
        elif ch == ">":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur)
            cur = ""
            continue
        cur += ch
    out.append(cur)
    return out


# --------------------------------------------------------------------------- #
# Register use (for liveness)
# --------------------------------------------------------------------------- #

def _regs_in(op) -> Set[str]:
    if isinstance(op, Reg):
        return {op.parent}
    if isinstance(op, Mem):
        return {r for r in (op.base, op.index) if r}
    return set()


def reads_writes(ins: Insn, has_value: bool) -> Tuple[Set[str], Set[str]]:
    if getattr(ins, "save", False):
        return set(), set()                  # prologue push / epilogue pop of a callee-saved register
    mn, ops = ins.mn, ins.ops
    rd: Set[str] = set()
    wr: Set[str] = set()
    for o in ops:
        if isinstance(o, Mem):
            rd |= _regs_in(o)
    dst = ops[0] if ops else None
    if mn in ("mov", "movzx", "movsx", "lea") or mn in SETCC:
        if isinstance(dst, Reg):
            wr.add(dst.parent)
        for o in ops[1:]:
            if isinstance(o, Reg):
                rd.add(o.parent)
    elif mn in ("xor", "sub") and len(ops) == 2 and isinstance(ops[0], Reg) and isinstance(ops[1], Reg) \
            and ops[0].parent == ops[1].parent:
        wr.add(ops[0].parent)
    elif mn in ("cmp", "test"):
        for o in ops:
            rd |= _regs_in(o)
    elif mn == "push":
        rd |= _regs_in(dst)
    elif mn == "pop":
        if isinstance(dst, Reg):
            wr.add(dst.parent)
    elif mn == "call":
        rd |= _regs_in(dst)
        wr |= {"eax", "ecx", "edx"}
    elif mn in ("ret", "retn"):
        if has_value:
            rd.add("eax")
    elif mn == "jmp":
        if ins.branch is None:
            rd |= {"ecx", "eax"} | _regs_in(dst)
    elif mn.startswith("j"):
        pass
    elif mn == "cdq":
        rd.add("eax")
        wr.add("edx")
    elif mn in ("div", "idiv", "mul") or (mn == "imul" and len(ops) == 1):
        rd |= {"eax", "edx"} | _regs_in(dst)
        wr |= {"eax", "edx"}
    elif mn == "fnstsw":
        wr.add("eax")
    elif mn.startswith("rep") or mn in ("movsd", "movsb", "stosd", "stosb"):
        rd |= {"ecx", "esi", "edi", "eax"}
        wr |= {"ecx", "esi", "edi"}
    elif mn.startswith("f"):
        pass
    else:
        for o in ops:
            if isinstance(o, Reg):
                rd.add(o.parent)
        if isinstance(dst, Reg):
            wr.add(dst.parent)
    rd.discard("esp")
    wr.discard("esp")
    return rd, wr


# --------------------------------------------------------------------------- #
# The lifter
# --------------------------------------------------------------------------- #

class Lifter:
    def __init__(self, symbol: str, va: Optional[int], target: bytes, insns: List[Insn]):
        self.symbol, self.va, self.target, self.insns = symbol, va, target, insns
        self.names = plan_names(symbol)
        self.notes: List[str] = []
        self.fields: Dict[int, dict] = {}
        self.globals: Dict[str, dict] = {}
        self.funcs: Dict[str, Callee] = {}
        self.structs: Dict[str, dict] = {}
        self.locals: Dict[str, str] = {}
        self.arg_types: Dict[int, str] = {}
        self.max_arg = 0
        self.temps = 0
        self.stmts: List[S] = []
        self.labels: Set[str] = set()
        self.layout: Dict[int, str] = {}
        self.own_slot: Optional[int] = None
        m = re.fullmatch(r"vfunc_(\d+)", self.names["meth"])
        if self.names["cls"] and m:
            self.own_slot = int(m.group(1))
        self.is_method = bool(self.names["cls"])
        self.cls_ref = "Object"

    # ---- bookkeeping used while rendering ----
    def note(self, text: str) -> None:
        if text not in self.notes:
            self.notes.append(text)

    def field_ok(self, off: int, size: Optional[int], kind: Optional[str] = None) -> str:
        f = self.layout.get(off)
        if not f:
            return ""
        if kind is not None and (kind in ("float", "double")) != (f in ("float", "double")):
            return ""
        if size is not None and (f.startswith("obj:") or self.fields[off]["size"] != size):
            return ""
        return f

    def struct(self, name: str) -> dict:
        return self.structs.setdefault(name, {"methods": {}, "virtuals": {}})

    def obj_access(self, obj: Optional[E], owner: str) -> str:
        if isinstance(obj, This) or obj is None:
            return ""
        if isinstance(obj, FieldAddr) and self.field_ok(obj.off, None).startswith("obj:"):
            return f"m_Field{obj.off:02X}."
        if isinstance(obj, Field) and self.field_ok(obj.off, 4) == "ptr:" + owner:
            return f"m_Field{obj.off:02X}->"
        if isinstance(obj, GlobAddr) and self.globals[obj.sym]["form"] == "object":
            return f"{obj.sym}."
        if obj.t(self) == "ptr:" + owner:
            return f"{par(self, obj)}->"
        return f"(({owner}*){conv(self, obj, 'int')})->"

    def use_field(self, off: int, size: int, kind: str) -> None:
        f = self.fields.get(off)
        if f is None:
            self.fields[off] = {"size": size, "kind": kind}
        elif f["size"] == size and kind.startswith(("ptr:", "obj:")) and not f["kind"].startswith(("ptr:", "obj:")):
            f["kind"] = kind
        elif f["size"] == size and f["kind"] == "bool" and kind in ("char", "uchar"):
            f["kind"] = kind

    def use_global(self, sym: str, form: str, size: int = 4, kind: str = "int") -> None:
        """form: address (only its address is used), object (used as `this`), scalar or array."""
        g = self.globals.get(sym)
        if form == "address":
            kind = "char"
        if g is None:
            self.globals[sym] = {"form": form, "size": size, "type": kind}
        elif form == "object":
            if g["form"] == "address":
                g["form"] = "object"
        elif form in ("scalar", "array"):
            if g["form"] in ("address", "object") or (form == "array" and g["form"] == "scalar"):
                g.update({"form": form, "size": size, "type": kind})

    def callee(self, name: str, kind: str = "func", owner: Optional[str] = None, slot: Optional[int] = None) -> Callee:
        if kind == "func":
            if name not in self.funcs:
                self.funcs[name] = Callee(name, "func")
            return self.funcs[name]
        st = self.struct(owner)
        if kind == "virtual":
            if slot not in st["virtuals"]:
                st["virtuals"][slot] = Callee(name, "virtual", owner, slot)
            return st["virtuals"][slot]
        if name not in st["methods"]:
            st["methods"][name] = Callee(name, "method", owner)
        return st["methods"][name]

    # ---- control flow / liveness ----
    def analyse(self) -> None:
        ins = self.insns
        written: Set[str] = set()
        saved: Set[str] = set()
        for x in ins:                        # mark register saves/restores so they are not uses
            if x.mn == "push" and x.ops and isinstance(x.ops[0], Reg) and x.ops[0].size == 4 \
                    and x.ops[0].parent in ("ebx", "ebp", "esi", "edi") and x.ops[0].parent not in written \
                    and x.ops[0].parent not in saved:
                x.save = True
                saved.add(x.ops[0].parent)
            elif x.mn == "pop" and x.ops and isinstance(x.ops[0], Reg) and x.ops[0].parent in saved:
                x.save = True
            else:
                written |= reads_writes(x, False)[1]
        self.index = {x.off: i for i, x in enumerate(ins)}
        leaders = {0}
        for i, x in enumerate(ins):
            if x.branch is not None and x.branch in self.index:
                leaders.add(self.index[x.branch])
            if x.mn.startswith("j") or x.mn in ("ret", "retn"):
                if i + 1 < len(ins):
                    leaders.add(i + 1)
        self.leaders = sorted(leaders)
        self.block_of = {}
        blocks = []
        for bi, start in enumerate(self.leaders):
            end = self.leaders[bi + 1] if bi + 1 < len(self.leaders) else len(ins)
            blocks.append((start, end))
            for k in range(start, end):
                self.block_of[k] = bi
        self.blocks = blocks
        succ: List[List[int]] = []
        for bi, (s, e) in enumerate(blocks):
            last = ins[e - 1]
            out = []
            if last.mn in ("ret", "retn") or (last.mn == "jmp" and last.branch is None):
                pass
            elif last.mn == "jmp":
                if last.branch in self.index:
                    out.append(self.block_of[self.index[last.branch]])
            else:
                if last.mn.startswith("j") and last.branch in self.index:
                    out.append(self.block_of[self.index[last.branch]])
                if bi + 1 < len(blocks):
                    out.append(bi + 1)
            succ.append(out)
        self.succ = succ
        self.preds = [[p for p in range(len(blocks)) if b in succ[p]] for b in range(len(blocks))]
        self.has_value = self._has_value()
        rw = [reads_writes(x, self.has_value) for x in ins]
        live_in = [set() for _ in blocks]
        changed = True
        while changed:
            changed = False
            for bi in reversed(range(len(blocks))):
                s, e = blocks[bi]
                live = set().union(*[live_in[x] for x in succ[bi]]) if succ[bi] else set()
                for k in reversed(range(s, e)):
                    r, w = rw[k]
                    live = (live - w) | r
                if live != live_in[bi]:
                    live_in[bi] = live
                    changed = True
        self.live_after: List[Set[str]] = [set() for _ in ins]
        for bi, (s, e) in enumerate(blocks):
            live = set().union(*[live_in[x] for x in succ[bi]]) if succ[bi] else set()
            for k in reversed(range(s, e)):
                self.live_after[k] = set(live)
                r, w = rw[k]
                live = (live - w) | r
        writes: Dict[str, List[int]] = {}
        for k, (_r, w) in enumerate(rw):
            for reg in w:
                writes.setdefault(reg, []).append(k)
        self.writes = writes
        self.entry_live = live_in[0] if blocks else set()
        self.thiscall = self.is_method or ("ecx" in self.entry_live and "ecx" in self._read_before_write())
        if self.thiscall and not self.is_method:
            self.names["cls"] = "Class_" + (f"{self.va:08X}" if self.va is not None else "Unknown")
            self.is_method = True
        stable = set()
        for reg in R32:
            ws = writes.get(reg, [])
            if not ws:
                stable.add(reg)
            elif len(ws) == 1 and self.block_of.get(ws[0]) == 0 and self._stable_def(ins[ws[0]], ws[0]):
                stable.add(reg)
        self.targets = {x.branch for x in ins if x.branch is not None and x.branch in self.index}
        self.vars = set()
        for bi in range(0, len(blocks)):
            if ins[blocks[bi][0]].off in self.targets:
                self.vars |= live_in[bi]
        if any(x.mn == "mov" and len(x.ops) == 2 and isinstance(x.ops[0], Reg) and x.ops[0].name == "ebp"
               and isinstance(x.ops[1], Reg) and x.ops[1].name == "esp" for x in ins):
            stable.add("ebp")
        self.stable = stable
        self.vars -= stable
        self.vars -= {"esp"}

    def _read_before_write(self) -> Set[str]:
        seen_w: Set[str] = set()
        out: Set[str] = set()
        s, e = self.blocks[0] if self.blocks else (0, 0)
        for k in range(s, e):
            x = self.insns[k]
            if x.mn == "push" and isinstance(x.ops[0], Reg) and x.ops[0].parent == "ecx" and k == s:
                continue
            r, w = reads_writes(x, False)
            if x.mn == "call":
                r = r - {"ecx"}
            out |= r - seen_w
            seen_w |= w
        return out

    def _stable_def(self, x: Insn, k: int) -> bool:
        if x.mn in ("xor", "sub") and len(x.ops) == 2 and isinstance(x.ops[1], Reg) and x.ops[0].parent == x.ops[1].parent:
            return True
        if x.mn == "mov" and isinstance(x.ops[1], Imm):
            return True
        if x.mn == "mov" and isinstance(x.ops[1], Reg) and x.ops[1].parent == "ecx" and "ecx" not in \
                {w for kk in range(0, k) for w in reads_writes(self.insns[kk], False)[1]}:
            return True
        if x.mn == "mov" and isinstance(x.ops[1], Mem) and x.ops[1].base == "esp" and x.ops[1].index is None:
            return True
        return False

    def _has_value(self) -> bool:
        ins = self.insns
        for bi, (s, e) in enumerate(self.blocks):
            if ins[e - 1].mn not in ("ret", "retn"):
                continue
            todo, seen = [(bi, e - 1)], set()
            while todo:
                b, k = todo.pop()
                if (b, k) in seen:
                    continue
                seen.add((b, k))
                found = None
                bs = self.blocks[b][0]
                while k >= bs:
                    x = ins[k]
                    _r, w = reads_writes(x, False)
                    if x.mn.startswith("f") and x.mn not in ("fnstsw",):
                        pass
                    if "eax" in w:
                        found = x
                        break
                    k -= 1
                if found is not None:
                    if found.mn != "call" and not (found.mn == "pop") and found.mn != "fnstsw":
                        return True
                    continue
                for p in self.preds[b]:
                    todo.append((p, self.blocks[p][1] - 1))
        return False

    # ---- simulation ----
    def run(self) -> None:
        ins = self.insns
        self.analyse()
        reg: Dict[str, Optional[E]] = {r: None for r in R32}
        if self.is_method:
            reg["ecx"] = This()
        self.var_val: Dict[str, Optional[E]] = {}
        for r in sorted(self.vars):
            if r in self.entry_live:
                self.stmts.append(SAssign(Var("r_" + r), reg[r] if reg[r] is not None else Num(0)))
                self.var_val[r] = reg[r]
            reg[r] = Var("r_" + r)
        self.reg = reg
        self.fpu: List[E] = []
        self.flags = None
        self.depth = 0
        self.frame: Optional[int] = None
        self.pushes: List[Tuple[int, E]] = []
        self.prologue = True
        self.saved: Set[str] = set()
        self.written: Set[str] = set()
        self.ecx_set = False
        self.last_call: Optional[SDef] = None
        self.stack_ok = True
        self.ret_pop: Optional[int] = None
        self.calls_made = 0
        self.local_size = 0
        saved_state: Dict[int, Tuple[int, List[E]]] = {}
        dead = False
        for i, x in enumerate(ins):
            if x.off in self.targets:
                if dead and x.off in saved_state:
                    self.depth, self.fpu = saved_state[x.off][0], list(saved_state[x.off][1])
                if dead:
                    self.pushes = []
                self.stmts.append(SLabel(f"L_{x.off:02X}"))
                self.var_val = {}
                for r in R32:
                    if r in self.vars:
                        reg[r] = Var("r_" + r)
                    elif r not in self.stable:
                        reg[r] = None
                self.flags = self.flags if not dead else None
                self.last_call = None
                dead = False
            if dead:
                continue
            self.i = i
            try:
                handled = self.step(x)
            except Exception as e:      # never let one odd instruction break the starter
                handled = False
                self.note(f"could not follow '{x.text}' ({type(e).__name__})")
            if not handled:
                self.stmts.append(SComment(f"TODO: {x.text}"))
                for w in reads_writes(x, False)[1]:
                    self.set_reg(w, Unknown(w))
            self.written |= reads_writes(x, False)[1]
            if x.branch is not None:
                saved_state.setdefault(x.branch, (self.depth, list(self.fpu)))
            if x.mn in ("ret", "retn") or x.mn == "jmp":
                dead = True

    # ---- register helpers ----
    def set_reg(self, r: str, val: E) -> None:
        if r == "esp":
            return
        if r in self.vars:
            v = Var("r_" + r)
            self.stmts.append(SAssign(v, val))
            self.reg[r] = v
            self.var_val[r] = val if isinstance(val, (This, Arg, Num, GlobAddr, FieldAddr)) else None
        else:
            self.reg[r] = val
        if r == "ecx":
            self.ecx_set = True

    def get_reg(self, op: Reg) -> E:
        v = self.reg.get(op.parent)
        if isinstance(v, Var) and op.parent in self.var_val and self.var_val[op.parent] is not None:
            v = self.var_val[op.parent]
        if v is None:
            v = Unknown(op.name)
        if op.size == 4:
            return v
        if op.high:
            return Unknown(op.name)
        t = v.t(self) if not isinstance(v, Unknown) else "int"
        if op.size == 1:
            if isinstance(v, Temp) and isinstance(v.d.value, Call):
                v.d.value.callee.ret_hint = "bool"
                return v
            if t in ("bool", "char", "uchar") or isinstance(v, Num):
                return v
            return Cast("uchar", v)
        if t in ("short", "ushort") or isinstance(v, Num):
            return v
        return Cast("ushort", v)

    def flush(self) -> None:
        """Before a side effect: give live register values that read memory a temporary."""
        live = self.live_after[self.i]
        for r in R32:
            v = self.reg.get(r)
            if v is None or r in self.vars or r not in live:
                continue
            if v.impure and not isinstance(v, (Temp, Var)):
                self.reg[r] = self.define(v)

    def define(self, val: E) -> Temp:
        self.temps += 1
        d = SDef(f"t{self.temps}", val)
        self.stmts.append(d)
        return Temp(d)

    def kind_for(self, size: int, signed: Optional[bool] = None, fl: bool = False) -> str:
        if fl:
            return "double" if size == 8 else "float"
        if size == 1:
            return "char" if signed else "uchar"
        if size == 2:
            return "short" if signed else "ushort"
        return "int"

    # ---- memory ----
    def stack_slot(self, m: Mem) -> Optional[int]:
        if m.index is not None:
            return None
        if m.base == "esp":
            return m.disp - self.depth if self.stack_ok else None
        if m.base == "ebp" and self.frame is not None:
            return m.disp - self.frame
        return None

    def mem(self, m: Mem, kind: str, field_kind: Optional[str] = None) -> Optional[E]:
        if m.seg:
            return None
        if m.base in ("esp", "ebp") and (m.base == "esp" or self.frame is not None):
            slot = self.stack_slot(m)
            if slot is None:
                return None
            if slot >= 4 and slot % 4 == 0:
                n = slot // 4
                self.max_arg = max(self.max_arg, n)
                if kind in ("float", "double"):
                    self.arg_types[n] = kind
                return Arg(n)
            if slot < 0:
                name = f"local_{-slot:X}"
                self.locals.setdefault(name, kind if m.size != 1 else "uchar")
                return Local(name)
            return None
        size = m.size
        if m.sym and m.base is None and m.index is None:
            self.use_global(m.sym, "scalar", size, kind)
            return Glob(m.sym, size, kind)
        if m.sym and m.base is None and m.index is not None:
            self.use_global(m.sym, "array" if m.scale == size else "scalar", size, kind)
            idx = self.reg_val(m.index)
            if m.scale == size:
                return GlobElem(m.sym, idx, size, kind)
            return Deref(Bin("+", Cast("int", GlobAddr(m.sym)), Bin("*", idx, Num(m.scale))), size, kind)
        base = self.reg_val(m.base) if m.base else None
        if isinstance(base, This) and m.index is None and not m.sym:
            self.use_field(m.disp, size, field_kind or kind)
            return Field(m.disp, size, field_kind or kind)
        if isinstance(base, FieldAddr) and m.index is None and not m.sym:
            off = base.off + m.disp
            self.use_field(off, size, field_kind or kind)
            return Field(off, size, field_kind or kind)
        addr = self.addr_expr(m, base)
        return Deref(addr, size, kind) if addr is not None else None

    def addr_expr(self, m: Mem, base: Optional[E] = None) -> Optional[E]:
        if m.seg:
            return None
        if m.base in ("esp", "ebp") and (m.base == "esp" or self.frame is not None):
            v = self.mem(Mem(m.base, None, 1, m.disp, 4, None), "int")
            return AddrOf(v) if v is not None else None
        parts: List[E] = []
        if m.base:
            b = base if base is not None else self.reg_val(m.base)
            if isinstance(b, This) and m.index is None and not m.sym:
                if m.disp == 0:
                    return b
                self.use_field(m.disp, 4, "int") if m.disp not in self.fields else None
                return FieldAddr(m.disp)
            parts.append(b)
        if m.index:
            idx = self.reg_val(m.index)
            parts.append(Bin("*", idx, Num(m.scale)) if m.scale != 1 else idx)
        if m.sym:
            self.use_global(m.sym, "address")
            g = GlobAddr(m.sym)
            if not parts:
                return g
            parts.insert(0, Cast("int", g))
        elif m.disp or not parts:
            parts.append(Num(s32(m.disp)))
        e = parts[0]
        for p in parts[1:]:
            e = Bin("+", e, p)
        return e

    def reg_val(self, r: str) -> E:
        v = self.reg.get(r)
        return v if v is not None else Unknown(r)

    def value(self, op, kind: str = "int", field_kind: Optional[str] = None) -> Optional[E]:
        if isinstance(op, Reg):
            return self.get_reg(op)
        if isinstance(op, Imm):
            if op.sym:
                self.use_global(op.sym, "address")
                return GlobAddr(op.sym)
            return Num(s32(op.value))
        if isinstance(op, Mem):
            return self.mem(op, kind, field_kind)
        return None

    def store(self, op, val: E) -> bool:
        if isinstance(op, Reg):
            if op.size == 4 or not op.high:
                self.set_reg(op.parent, val)
                return True
            return False
        if isinstance(op, Mem):
            slot = self.stack_slot(op) if op.base in ("esp", "ebp") else None
            if slot is not None and slot < 0:
                for k, (ps, _pe) in enumerate(self.pushes):
                    if ps == slot:                       # filling in an argument pushed earlier (push ecx / fstp [esp])
                        self.pushes[k] = (ps, val)
                        if op.size == 8:
                            self.pushes = [p for p in self.pushes if p[0] != slot + 4]
                        return True
            t = val.t(self)
            kind = t if t in ("float", "double") else self.kind_for(op.size, None)
            if op.size == 1 and (t == "bool" or (isinstance(val, Num) and val.v in (0, 1))):
                kind = "bool"
            lhs = self.mem(op, kind, kind)
            if lhs is None:
                return False
            self.flush()
            self.stmts.append(SAssign(lhs, val))
            return True
        return False

    # ---- one instruction ----
    def step(self, x: Insn) -> bool:
        mn, ops = x.mn, x.ops
        if not x.ok:
            return False
        if mn in ("nop", "int3", "align", "fnop"):
            return True
        if mn == "lea" and isinstance(ops[0], Reg) and isinstance(ops[1], Mem) and ops[1].base == ops[0].parent \
                and ops[1].index is None and ops[1].disp == 0:
            return True                                      # lea esp,[esp] / lea ecx,[ecx]: padding
        if mn == "mov" and isinstance(ops[0], Reg) and isinstance(ops[1], Reg) and ops[0].name == ops[1].name:
            return True
        if not (mn == "push" or (mn == "sub" and isinstance(ops[0], Reg) and ops[0].parent == "esp")
                or (mn == "mov" and isinstance(ops[0], Reg) and ops[0].parent == "ebp")):
            self.prologue = False
        if mn == "push":
            return self.do_push(x)
        if mn == "pop":
            if isinstance(ops[0], Reg):
                popped = self.pushes and self.pushes[-1][0] == -self.depth
                self.depth -= 4
                if popped:
                    self.pushes.pop()
                if ops[0].parent in self.saved and not popped:
                    pass                                     # restoring a saved register (epilogue)
                elif ops[0].parent not in self.vars:
                    self.reg[ops[0].parent] = None
                if ops[0].parent == "ebp":
                    self.frame = None
                return True
            return False
        if isinstance(ops[0], Reg) if ops else False:
            if ops[0].parent == "esp":
                return self.do_esp(x)
            if ops[0].parent == "ebp" and mn == "mov" and isinstance(ops[1], Reg) and ops[1].parent == "esp":
                self.frame = self.depth
                return True
        if mn in ("mov", "movzx", "movsx"):
            src = ops[1]
            signed = True if mn == "movsx" else (False if mn == "movzx" else None)
            if isinstance(src, Mem):
                size = src.size
                kind = self.kind_for(size, signed)
                fk = kind
                if size == 1 and mn == "mov":
                    fk = "bool"
                if size == 1 and mn == "movzx":
                    fk = "uchar"
                if mn == "mov" and size == 1:
                    slot = self.stack_slot(src) if src.base in ("esp", "ebp") else None
                    if slot is not None and slot >= 4:
                        self.arg_types.setdefault(slot // 4, "bool")
                val = self.mem(src, fk if size == 1 else kind, fk)
            else:
                val = self.value(src)
                if mn in ("movzx", "movsx") and isinstance(src, Reg) and src.size < 4:
                    val = Cast(self.kind_for(src.size, signed), val) if not isinstance(val, Num) else val
            if val is None:
                return False
            return self.store(ops[0], val)
        if mn == "lea":
            a = self.addr_expr(ops[1])
            if a is None:
                return False
            return self.store(ops[0], a)
        if mn in ("xor", "sub") and isinstance(ops[0], Reg) and isinstance(ops[1], Reg) and ops[0].parent == ops[1].parent:
            self.flags = ("res", Num(0))
            return self.store(ops[0], Num(0) if ops[0].size != 1 else Num(0))
        if mn in ("cmp", "test"):
            a = self.value(ops[0], field_kind=None)
            b = self.value(ops[1])
            if a is None or b is None:
                return False
            if mn == "test" and isinstance(ops[0], Reg) and isinstance(ops[1], Reg) and ops[0].name == ops[1].name:
                self.flags = ("res", a)
            elif mn == "test" and isinstance(ops[0], Reg) and ops[0].name == "ah" and isinstance(self.reg.get("eax"), FSW):
                self.flags = ("fpu", b.v if isinstance(b, Num) else 0, self.reg["eax"])
            elif mn == "test":
                self.flags = ("res", Bin("&", a, b))
            else:
                self.flags = ("cmp", a, b)
            return True
        if mn in ARITH or mn in ("inc", "dec", "neg", "not", "adc", "sbb"):
            return self.do_arith(x)
        if mn.startswith("j") and mn != "jmp":
            return self.do_jcc(x)
        if mn == "jmp":
            if x.branch is not None:
                if x.branch not in self.index:
                    return False
                self.flush()
                self.stmts.append(SGoto(f"L_{x.branch:02X}"))
                return True
            if isinstance(ops[0], Mem) and ops[0].index is not None and not ops[0].sym:
                self.stmts.append(SComment(f"TODO: switch statement ({x.text}, a jump table)"))
                self.note("it ends in a switch (jump table) that is not written out")
                return True
            return self.do_call(x, tail=True)
        if mn == "call":
            return self.do_call(x)
        if mn in ("ret", "retn"):
            val = self.reg.get("eax") if self.has_value else None
            fval = self.fpu[-1] if self.fpu else None
            self.flush()
            self.stmts.append(SRet(val, fval))
            if ops and isinstance(ops[0], Imm):
                self.ret_pop = max(self.ret_pop or 0, ops[0].value)
            return True
        if mn == "leave" and self.frame is not None:
            self.depth = self.frame - 4
            self.frame = None
            return True
        if mn in SETCC:
            c = self.cond(JCC["j" + mn[3:]])
            if c is None:
                return False
            return self.store(ops[0], c)
        if mn == "cdq":
            self.set_reg("edx", Unknown("edx (sign of eax)"))
            return False
        if mn.startswith("f"):
            return self.do_fpu(x)
        return False

    def do_push(self, x: Insn) -> bool:
        op = x.ops[0]
        # Saving a callee-saved register it has not touched yet is the prologue, not an argument.
        if isinstance(op, Reg) and op.size == 4 and op.parent in ("ebx", "ebp", "esi", "edi") \
                and op.parent not in self.written and op.parent not in self.saved:
            self.saved.add(op.parent)
            self.depth += 4
            return True
        if isinstance(op, Reg) and op.parent == "ecx" and self.i == 0:
            self.depth += 4                                  # push ecx first thing: room for a 4-byte local
            self.locals.setdefault(f"local_{self.depth:X}", "int")
            return True
        if isinstance(op, Imm) and not op.sym:
            v: E = Num(s32(op.value))
        else:
            v = self.value(op)
        if v is None:
            return False
        if isinstance(op, Reg) and op.parent == "ecx":
            self.ecx_set = False
        self.depth += 4
        self.pushes.append((-self.depth, v))
        return True

    def do_esp(self, x: Insn) -> bool:
        mn, ops = x.mn, x.ops
        if mn in ("sub", "add") and isinstance(ops[1], Imm):
            n = s32(ops[1].value)
            if mn == "sub":
                if not self.prologue and (self.pushes or self.calls_made):
                    for _ in range(n // 4):
                        self.depth += 4
                        self.pushes.append((-self.depth, Num(0)))
                    self.depth += n % 4
                else:
                    self.depth += n
                    self.local_size += n
                return True
            self.depth -= n
            while self.pushes and self.pushes[-1][0] < -self.depth:
                self.pushes.pop()
            return True
        if mn == "and":
            self.stack_ok = False
            self.note("the stack is realigned (and esp); stack variables are left as TODOs")
            return True
        if mn == "mov" and isinstance(ops[1], Reg) and ops[1].parent == "ebp" and self.frame is not None:
            self.depth = self.frame
            return True
        return False

    def do_arith(self, x: Insn) -> bool:
        mn, ops = x.mn, x.ops
        dst = ops[0]
        if mn in ("adc", "sbb"):
            return False
        if mn in ("inc", "dec"):
            src: E = Num(1)
            op = "+" if mn == "inc" else "-"
        elif mn in ("neg", "not"):
            cur = self.value(dst)
            if cur is None:
                return False
            new: E = Un("-" if mn == "neg" else "~", cur)
            self.flags = ("res", new)
            if isinstance(dst, Mem):
                return self.store(dst, new)
            return self.store(dst, new)
        else:
            if mn == "imul" and len(ops) == 3:
                a, b = self.value(ops[1]), self.value(ops[2])
                if a is None or b is None:
                    return False
                return self.store(dst, Bin("*", a, b))
            if mn == "imul" and len(ops) == 1:
                return False
            s = self.value(ops[1]) if len(ops) > 1 else None
            if s is None:
                return False
            src, op = s, ARITH[mn]
        if isinstance(dst, Mem):
            lhs = self.mem(dst, self.kind_for(dst.size, mn == "sar"))
            if lhs is None:
                return False
            self.flush()
            if mn in ("and",) and isinstance(src, Num) and src.v == 0:
                self.stmts.append(SAssign(lhs, Num(0)))
            else:
                self.stmts.append(SAssign(lhs, src, op + "="))
            self.flags = ("res", lhs)
            return True
        cur = self.value(dst)
        if cur is None:
            return False
        if mn == "sub":
            self.flags = ("cmp", cur, src)
        if mn == "shr" and not isinstance(cur, Num):
            cur = Cast("uint", cur) if cur.t(self) == "int" else cur
        new = Bin(op, cur, src)
        if mn == "and" and isinstance(src, Num) and src.v == 0:
            new = Num(0)
        if mn != "sub":
            self.flags = ("res", new)
        if isinstance(dst, Reg) and dst.parent in self.vars:
            self.flush()
            self.stmts.append(SAssign(Var("r_" + dst.parent), src, op + "="))
            if mn != "sub":
                self.flags = ("res", Var("r_" + dst.parent))
            return True
        return self.store(dst, new)

    def cond(self, op: str) -> Optional[E]:
        f = self.flags
        if f is None:
            return None
        if f[0] == "fpu":
            return self.fpu_cond(op, f[1], f[2])
        if op in ("p", "np"):
            return None
        if f[0] == "cmp":
            a, b = f[1], f[2]
        else:
            a, b = f[1], Num(0)
        if op == "s":
            return Cmp("<", a, Num(0))
        if op == "ns":
            return Cmp(">=", a, Num(0))
        uns = op.startswith("u")
        o = op[1:] if uns else op
        if uns and isinstance(b, Num) and b.v == 0:
            if o == ">":
                return Cmp("!=", a, b)
            if o == "<=":
                return Cmp("==", a, b)
        return Cmp(o, a, b, uns and o not in ("==", "!="))

    def fpu_cond(self, op: str, mask: int, fsw: "FSW") -> Optional[E]:
        a, b = fsw.a, fsw.b
        table = {0x41: {"==": ">", "p": ">", "!=": "<=", "np": "<="},
                 0x45: {"==": ">", "p": ">", "!=": "<=", "np": "<="},
                 0x01: {"==": ">=", "!=": "<"},
                 0x05: {"==": ">=", "p": ">=", "!=": "<", "np": "<"},
                 0x40: {"==": "!=", "!=": "==", "np": "!=", "p": "=="},
                 0x44: {"==": "!=", "p": "!=", "!=": "==", "np": "=="}}
        o = table.get(mask, {}).get(op)
        return Cmp(o, a, b) if o else None

    def do_jcc(self, x: Insn) -> bool:
        if x.branch is None or x.branch not in self.index:
            return False
        c = self.cond(JCC.get(x.mn, ""))
        if c is None:
            return False
        self.flush()
        self.stmts.append(SIf(c, f"L_{x.branch:02X}"))
        return True

    def args_for_call(self, x: Insn) -> Tuple[List[E], bool]:
        """The pushed arguments (first argument first) and whether the caller pops them (cdecl)."""
        i = self.i
        nxt = None
        for k in range(i + 1, min(i + 5, len(self.insns))):
            y = self.insns[k]
            if y.off in getattr(self, "targets", ()):
                break
            touches = y.mn in ("push", "pop", "call", "ret", "retn", "leave") or y.mn.startswith("j") or any(
                isinstance(o, Reg) and o.parent == "esp" for o in y.ops[:1])
            if touches:
                nxt = y
                i = k - 1
                break
        cleanup = None
        if nxt is not None and nxt.mn == "add" and isinstance(nxt.ops[0], Reg) and nxt.ops[0].parent == "esp" \
                and isinstance(nxt.ops[1], Imm):
            nbytes = s32(nxt.ops[1].value)
            if self.local_size and nbytes == self.local_size:
                cleanup = None                               # that is the frame going away, not arguments
            elif self.local_size and nbytes == self.local_size + 4 * len(self.pushes):
                cleanup = len(self.pushes)
            else:
                cleanup = nbytes // 4
        elif nxt is not None and nxt.mn == "pop" and isinstance(nxt.ops[0], Reg) and nxt.ops[0].parent in ("ecx", "edx", "eax"):
            k, cleanup = self.insns.index(nxt), 0
            while k < len(self.insns) and self.insns[k].mn == "pop" and isinstance(self.insns[k].ops[0], Reg) \
                    and self.insns[k].ops[0].parent in ("ecx", "edx", "eax") and cleanup < len(self.pushes):
                cleanup += 1
                k += 1
        n = len(self.pushes) if cleanup is None else min(cleanup, len(self.pushes))
        taken = self.pushes[len(self.pushes) - n:] if n else []
        args = [e for _s, e in reversed(taken)]
        if cleanup is None:                                  # the callee pops them
            self.pushes = self.pushes[:len(self.pushes) - n]
            self.depth -= 4 * n
        return args, cleanup is not None and n > 0

    def do_call(self, x: Insn, tail: bool = False) -> bool:
        op = x.ops[0] if x.ops else None
        if tail:
            args: List[E] = [Arg(k) for k in range(1, self.max_arg_for_tail() + 1)]
            caller_pops = False
        else:
            args, caller_pops = self.args_for_call(x)
        convn = "cdecl" if caller_pops or not args else "stdcall"
        ecx = self.reg.get("ecx")
        method_obj = ecx if (self.ecx_set and not caller_pops and ecx is not None
                             and not isinstance(ecx, (Unknown, Num))) else None
        call: Optional[Call] = None
        if x.ext and isinstance(op, Imm):
            if method_obj is not None:
                # The same function called on two objects means they share a class: reuse its type.
                known = next((n for n, st in self.structs.items() if x.ext in st["methods"]
                              and n not in ("@self", "Object") and not n.startswith("Object")), None)
                owner = self.owner_of(method_obj, as_type=known)
                call = Call(self.callee(x.ext, "method", owner), method_obj, args)
            else:
                c = self.callee(x.ext, "func")
                c.conv = "stdcall" if (c.conv == "stdcall" or convn == "stdcall") and not c.variadic else "cdecl"
                call = Call(c, None, args)
        elif isinstance(op, Mem) and op.sym and op.base is None and op.index is None:
            self.use_global(op.sym, "scalar", 4, "int")
            c = Callee(op.sym, "fptr")
            c.conv = convn
            call = Call(c, None, args, Glob(op.sym, 4, "int"))
        elif isinstance(op, Mem) and op.base and op.index is None and not op.sym:
            vt = self.reg_val(op.base)
            if isinstance(vt, Temp) and not vt.d.inline:
                vt = vt.d.value
            obj: Optional[E] = None
            if isinstance(vt, Field) and vt.off == 0:
                obj = This()
            elif isinstance(vt, Deref):
                obj = vt.addr
            if obj is not None and op.disp % 4 == 0 and not isinstance(obj, (Unknown, Num)):
                if isinstance(obj, This):
                    self.has_vptr = True
                    if self.fields.get(0, {}).get("size") == 4:
                        self.fields.pop(0)
                slot = op.disp // 4
                owner = self.owner_of(obj, virtual=True)
                if owner == "Object":
                    # Unknown objects share one placeholder type; a slot used with another argument
                    # count must belong to a different type, so give it one.
                    k = 1
                    while True:
                        prev = self.struct(owner)["virtuals"].get(slot)
                        if prev is None or len(prev.arg_types or []) == len(args):
                            break
                        k += 1
                        owner = f"Object{k}"
                call = Call(self.callee(f"vfunc_{slot:02d}", "virtual", owner, slot), obj, args)
            else:
                f = self.value(op)
                if f is None:
                    return False
                c = Callee("fptr", "fptr")
                c.conv = convn
                call = Call(c, None, args, f)
        elif isinstance(op, Reg):
            c = Callee("fptr", "fptr")
            c.conv = convn
            call = Call(c, None, args, self.get_reg(op))
        if call is None:
            return False
        call.callee.note_args([a.t(self) if a.t(self) in ("float", "double") else "int" for a in args])
        self.flush()
        self.calls_made += 1
        d = self.define(call).d
        self.last_call = d
        self.ecx_set = False
        for r in ("ecx", "edx"):
            if r not in self.vars:
                self.reg[r] = None
        if "eax" in self.vars:
            if "eax" in self.live_after[self.i]:
                self.stmts.append(SAssign(Var("r_eax"), Temp(d)))
        else:
            self.reg["eax"] = Temp(d)
        if tail:
            self.stmts.append(SRet(Temp(d) if self.has_value else None, None))
        return True

    def max_arg_for_tail(self) -> int:
        n = 0
        for y in self.insns:
            if y.mn in ("ret", "retn") and y.ops and isinstance(y.ops[0], Imm):
                n = max(n, y.ops[0].value // 4)
        return max(n, self.max_arg)

    def owner_of(self, obj: E, virtual: bool = False, as_type: Optional[str] = None) -> str:
        if isinstance(obj, This):
            return "@self"
        if isinstance(obj, FieldAddr) and not virtual:
            name = as_type or (f"Field{obj.off:02X}" if obj.off >= 0 else f"FieldM{-obj.off:02X}")
            f = self.fields.get(obj.off)
            if f is None or not f["kind"].startswith("ptr:"):
                self.fields[obj.off] = {"size": 1, "kind": "obj:" + name}
            return name
        if isinstance(obj, Field):
            name = as_type or (f"Field{obj.off:02X}" if obj.off >= 0 else f"FieldM{-obj.off:02X}")
            self.use_field(obj.off, 4, "ptr:" + name)
            return name
        if isinstance(obj, GlobAddr):
            self.use_global(obj.sym, "object")
            return "Object"
        return "Object"

    # ---- x87 ----
    def st(self, i: int) -> Optional[E]:
        if len(self.fpu) > i:
            return self.fpu[-1 - i]
        if i == 0 and not self.fpu and self.last_call is not None and isinstance(self.last_call.value, Call):
            self.last_call.value.callee.ret_hint = "float"
            return Temp(self.last_call)
        return None

    def fpop(self) -> None:
        if self.fpu:
            self.fpu.pop()

    def do_fpu(self, x: Insn) -> bool:
        mn, ops = x.mn, x.ops
        if mn in ("fld", "fild"):
            if isinstance(ops[0], FpuReg):
                v = self.st(ops[0].i)
                if v is None:
                    return False
                self.fpu.append(v)
                return True
            m = ops[0]
            fl = mn == "fld"
            v = self.mem(m, self.kind_for(m.size, True, fl=fl))
            if v is None:
                return False
            self.fpu.append(v if fl else Cast("float", v))
            return True
        if mn in ("fldz", "fld1"):
            self.fpu.append(FNum(0.0 if mn == "fldz" else 1.0))
            return True
        if mn in ("fst", "fstp", "fistp", "fist"):
            top = self.st(0)
            if top is None:
                return False
            if ops and isinstance(ops[0], FpuReg):
                if ops[0].i and len(self.fpu) > ops[0].i:
                    self.fpu[-1 - ops[0].i] = top
                if mn == "fstp":
                    self.fpop()
                return True
            m = ops[0]
            val = top if mn in ("fst", "fstp") else Cast("int", top)
            if mn in ("fst", "fstp") and m.size == 8:
                val = Cast("double", top) if top.t(self) != "double" else top
            ok = self.store(m, val)
            if mn in ("fstp", "fistp"):
                self.fpop()
            return ok
        base = mn[:-1] if mn.endswith("p") else mn
        ops_map = {"fadd": "+", "fsub": "-", "fmul": "*", "fdiv": "/", "fsubr": "-r", "fdivr": "/r"}
        if base in ops_map:
            op = ops_map[base]
            rev = op.endswith("r")
            op = op[0]
            if ops and isinstance(ops[0], Mem):
                top = self.st(0)
                other = self.mem(ops[0], self.kind_for(ops[0].size, True, fl=True))
                if top is None or other is None:
                    return False
                if self.fpu:
                    self.fpu[-1] = Bin(op, other, top) if rev else Bin(op, top, other)
                else:
                    self.fpu.append(Bin(op, other, top) if rev else Bin(op, top, other))
                return True
            popping = mn.endswith("p")
            if popping:                                     # faddp st(1): st1 = st1 op st0, pop
                i = ops[0].i if ops else 1
                a, b = self.st(i), self.st(0)
                if a is None or b is None or len(self.fpu) <= i:
                    return False
                res = Bin(op, b, a) if rev else Bin(op, a, b)
                self.fpu[-1 - i] = res
                self.fpop()
                return True
            if len(ops) == 2 and isinstance(ops[0], FpuReg) and isinstance(ops[1], FpuReg):
                d, s_ = ops[0].i, ops[1].i
                a, b = self.st(d), self.st(s_)
                if a is None or b is None or len(self.fpu) <= max(d, s_):
                    return False
                self.fpu[-1 - d] = Bin(op, b, a) if rev else Bin(op, a, b)
                return True
            return False
        if mn == "fchs":
            top = self.st(0)
            if top is None:
                return False
            self.fpu[-1] = Un("-", top)
            return True
        if mn == "fxch":
            i = ops[0].i if ops else 1
            if len(self.fpu) <= i:
                return False
            self.fpu[-1], self.fpu[-1 - i] = self.fpu[-1 - i], self.fpu[-1]
            return True
        if mn in ("fcom", "fcomp", "fcompp", "fucom", "fucomp", "fucompp"):
            a = self.st(0)
            if a is None:
                return False
            if mn.endswith("pp"):
                b = self.st(1)
            elif ops and isinstance(ops[0], Mem):
                b = self.mem(ops[0], self.kind_for(ops[0].size, True, fl=True))
            else:
                b = self.st(ops[0].i if ops else 1)
            if b is None:
                return False
            self.pending_fcmp = (a, b)
            for _ in range(2 if mn.endswith("pp") else 1 if mn.endswith("p") else 0):
                self.fpop()
            return True
        if mn == "fnstsw":
            pf = getattr(self, "pending_fcmp", None)
            if pf is None:
                return False
            self.reg["eax"] = FSW(*pf)
            return True
        return False


class FSW(E):
    """The FPU status word after a compare (fnstsw ax); only `test ah, mask` reads it."""
    def __init__(self, a: E, b: E):
        self.a, self.b = a, b

    def r(self, cx):
        return "0"


# --------------------------------------------------------------------------- #
# Clean-up and rendering
# --------------------------------------------------------------------------- #

def _count_uses(stmts: List[S]) -> None:
    for st in stmts:
        for e in st.exprs():
            for n in walk(e):
                if isinstance(n, Temp):
                    n.d.uses += 1
        if isinstance(st, SBlock):
            _count_uses(st.body)
            _count_uses(st.other)


def _uses_in(st: S, d: SDef) -> int:
    n = 0
    for e in st.exprs():
        for node in walk(e):
            if isinstance(node, Temp) and node.d is d:
                n += 1
    return n


def inline_temps(stmts: List[S]) -> None:
    _count_uses(stmts)
    for st in stmts:
        if isinstance(st, SDef) and st.uses and isinstance(st.value, Call):
            st.value.callee.used = True
    for i, st in enumerate(stmts):
        if isinstance(st, SDef) and st.uses == 1 and i + 1 < len(stmts) and _uses_in(stmts[i + 1], st) == 1:
            st.inline = True


def label_refs(stmts: List[S], out: Optional[Dict[str, int]] = None) -> Dict[str, int]:
    out = out if out is not None else {}
    for st in stmts:
        if isinstance(st, (SIf, SGoto)):
            out[st.label] = out.get(st.label, 0) + 1
        if isinstance(st, SBlock):
            label_refs(st.body, out)
            label_refs(st.other, out)
    return out


def structure(stmts: List[S]) -> List[S]:
    for _ in range(200):
        refs = label_refs(stmts)
        changed = False
        out: List[S] = []
        dead = False
        for st in stmts:                                    # unreachable code, unused labels, goto next
            if isinstance(st, SLabel):
                if refs.get(st.name, 0) == 0:
                    changed = True
                    continue
                dead = False
            if dead:
                changed = True
                continue
            out.append(st)
            if isinstance(st, (SRet, SGoto)):
                dead = True
        stmts = out
        for i, st in enumerate(stmts):
            if isinstance(st, SGoto) and i + 1 < len(stmts) and isinstance(stmts[i + 1], SLabel) \
                    and stmts[i + 1].name == st.label:
                stmts = stmts[:i] + stmts[i + 1:]
                changed = True
                break
        if changed:
            continue
        refs = label_refs(stmts)
        for i, st in enumerate(stmts):
            if isinstance(st, SIf):
                j = next((k for k in range(i + 1, len(stmts)) if isinstance(stmts[k], SLabel)), None)
                if j is not None and stmts[j].name == st.label:
                    body = stmts[i + 1:j]
                    if body and isinstance(body[-1], SGoto) and refs.get(st.label) == 1:
                        l2 = body[-1].label
                        k = next((q for q in range(j + 1, len(stmts)) if isinstance(stmts[q], SLabel)), None)
                        if k is not None and stmts[k].name == l2 and refs.get(l2) == 1:
                            blk = SBlock("ifelse", neg(st.cond), body[:-1], stmts[j + 1:k])
                            stmts = stmts[:i] + [blk] + stmts[k:]
                            changed = True
                            break
                    blk = SBlock("if", neg(st.cond), body)
                    stmts = stmts[:i] + [blk] + stmts[j:]
                    changed = True
                    break
                k = next((q for q in range(i - 1, -1, -1) if isinstance(stmts[q], SLabel)), None)
                if k is not None and stmts[k].name == st.label and refs.get(st.label) == 1:
                    blk = SBlock("do", st.cond, stmts[k + 1:i])
                    stmts = stmts[:k] + [blk] + stmts[i + 1:]
                    changed = True
                    break
        if not changed:
            return stmts
    return stmts


class Renderer:
    def __init__(self, lf: Lifter):
        self.lf = lf

    def ret_type(self) -> Tuple[str, bool]:
        lf = self.lf
        rets: List[SRet] = []

        def collect(ss):
            for s in ss:
                if isinstance(s, SRet):
                    rets.append(s)
                if isinstance(s, SBlock):
                    collect(s.body)
                    collect(s.other)
        collect(lf.stmts)
        if any(r.fval is not None for r in rets) and not lf.has_value:
            vals = [r.fval for r in rets if r.fval is not None]
            return ("double" if any(v.t(lf) == "double" for v in vals) else "float"), True
        if not lf.has_value:
            return "void", False
        vals = [r.val for r in rets if r.val is not None and not isinstance(r.val, Unknown)]
        for v in vals:
            if isinstance(v, Temp) and isinstance(v.d.value, Call):
                v.d.value.callee.used = True
        ts = {v.t(lf) for v in vals if not (isinstance(v, Num) and v.v == 0)}
        ones = all(isinstance(v, Num) and v.v in (0, 1) for v in vals if isinstance(v, Num))
        others = {v.t(lf) for v in vals if not isinstance(v, Num)}
        if ts and all(t == "ptr:" + lf.cls_ref for t in ts):
            return "ptr:" + lf.cls_ref, False
        if ones and others <= {"bool"} and (others or lf.byte_ret):
            return "bool", False
        if ts and all(t.startswith("ptr:") for t in ts):
            return "ptr:void", False
        if ts and ts <= {"float"}:
            return "float", False
        return "int", False


def synthesize(symbol: str, va_label: str, target: bytes, disasm: Sequence[str], relocs=None) -> str:
    m = re.search(r"0x([0-9A-Fa-f]+)", va_label or "")
    va = int(m.group(1), 16) if m else None
    insns = parse_disasm(disasm)
    attach_relocs(insns, target, va, relocs)
    lf = Lifter(symbol, va, target, insns)
    lf.has_vptr = lf.own_slot is not None
    lf.byte_ret = any(x.mn == "mov" and x.ops and isinstance(x.ops[0], Reg) and x.ops[0].name == "al" for x in insns)
    if insns:
        lf.run()
    else:
        lf.has_value = False
        lf.thiscall = lf.is_method
    return render(lf, symbol, va_label, len(target))


def render(lf: Lifter, symbol: str, va_label: str, n: int) -> str:
    names = lf.names
    is_method = lf.is_method
    cls = names["cls"]
    tmpl = names["template"]
    if is_method:
        lf.cls_ref = (cls if not tmpl else f"{cls}<{', '.join(tmpl[1])}>")
    stmts = lf.stmts
    inline_temps(stmts)
    rt, _fl = Renderer(lf).ret_type()
    stmts = structure(stmts)
    # Fields: lay out the class (offsets are what matter; types are guesses).
    has_vptr = is_method and (lf.has_vptr or bool(lf.struct("@self")["virtuals"]))
    pos = 4 if has_vptr else 0
    layout: Dict[int, str] = {}
    decls: List[str] = []
    if is_method:
        for off in sorted(lf.fields):
            f = lf.fields[off]
            size = f["size"] if not f["kind"].startswith("obj:") else 1
            align = 1 if f["kind"].startswith("obj:") else min(size, 4)
            if off < pos or off % align:
                continue
            if off > pos:
                decls.append(f"    char m_pad{pos:02X}[0x{off - pos:X}];")
            layout[off] = f["kind"]
            decls.append(f"    {ctype(f['kind'])} m_Field{off:02X}; // +0x{off:02X}")
            pos = off + size
    lf.layout = layout

    # Types of things the code uses, now that every use is known.
    argc = lf.max_arg_for_tail() if lf.insns else 0
    if getattr(lf, "ret_pop", None) is not None:
        argc = max(argc, lf.ret_pop // 4)
    params = ", ".join(f"{ctype(lf.arg_types.get(k, 'int'))} a{k}" for k in range(1, argc + 1))
    body = render_body(lf, stmts, rt)

    out: List[str] = []
    out.append(f"// {symbol} ({va_label}, {n} bytes)")
    out.append("// Starter code written from the disassembly. Names and types are guesses; rename and")
    out.append("// retype them as you work it out. Calls and globals already use their real addresses.")
    if lf.notes:
        for t in lf.notes[:6]:
            out.append(f"// Note: {t}.")
    out.append("")

    # helper structs (objects this function calls methods on)
    for name in sorted(k for k in lf.structs if k != "@self"):
        out += struct_decl(lf, name, lf.structs[name]) + [""]
    # extern "C" globals and functions
    ext: List[str] = []
    for sym in sorted(lf.globals):
        g = lf.globals[sym]
        if g["form"] == "scalar":
            ext.append(f'extern "C" {ctype(g["type"])} {sym};')
        elif g["form"] == "array":
            ext.append(f'extern "C" {ctype(g["type"])} {sym}[];')
        elif g["form"] == "object":
            ext.append(f'extern "C" Object {sym};')
        else:
            ext.append(f'extern "C" char {sym}[];')
    for name in sorted(lf.funcs):
        c = lf.funcs[name]
        kw = "__stdcall" if c.conv == "stdcall" else "__cdecl"
        ext.append(f'extern "C" {ctype(c.ret)} {kw} {name}({c.params()});')
    if ext:
        out += ext + [""]

    sig_ret = ctype(rt)
    if not is_method:
        kw = "__stdcall" if getattr(lf, "ret_pop", 0) else "__cdecl"
        out.append(f"{sig_ret} {kw} {names['meth']}({params or 'void'})")
        out.append("{")
        out += body
        out.append("}")
        return "\n".join(out) + "\n"

    own = lf.struct("@self")
    members: List[str] = []
    virt = dict(own["virtuals"])
    own_decl = f"{sig_ret} {names['meth']}({', '.join(ctype(lf.arg_types.get(k, 'int')) + f' a{k}' for k in range(1, argc + 1))})"
    if lf.own_slot is not None:
        virt[lf.own_slot] = "@own"
    if virt:
        for s in range(0, max(virt) + 1):
            c = virt.get(s)
            if c == "@own":
                members.append(f"    virtual {own_decl};")
            elif c is None:
                members.append(f"    virtual void vfunc_{s:02d}();")
            else:
                members += c.decls(virtual=True)
    if lf.own_slot is None:
        members.append(f"    {own_decl};")
    for mname in sorted(own["methods"]):
        if mname == names["meth"]:
            continue                          # it calls itself
        members += own["methods"][mname].decls()
    cbody = [f"class {cls}", "{", "public:"] + members + decls + ["};"]
    defn = [f"{sig_ret} {lf.cls_ref if tmpl else cls}::{names['meth']}({params})", "{"] + body + ["}"]
    ns = names["ns"]
    if tmpl:
        fwd = []
        tparams = []
        for k, a in enumerate(tmpl[1]):
            if re.fullmatch(r"-?\d+", a):
                tparams.append(f"int N{k}")
                continue
            tparams.append(f"class T{k}")
            if a in ("bool", "char", "short", "int", "long", "float", "double", "unsigned", "signed"):
                continue
            parts = split_scopes(a)
            fwd.append("".join(f"namespace {p} {{ " for p in parts[:-1]) + f"class {parts[-1]};" + " }" * (len(parts) - 1))
        out += fwd + ([""] if fwd else [])
        cbody[0] = f"template <{', '.join(tparams)}> class {cls}"
        full = "::".join(ns + [lf.cls_ref])
        defn[0] = f"template <> {sig_ret if not rt.startswith('ptr:') else ctype(rt).replace(lf.cls_ref, full)} " \
                  f"{full}::{names['meth']}({params})"
        if ns:
            out.append("".join(f"namespace {p} {{ " for p in ns))
            out += cbody
            out.append(" ".join("}" for _ in ns))
        else:
            out += cbody
        out += [""] + defn
        return "\n".join(out) + "\n"
    if ns:
        out.append(" ".join(f"namespace {p} {{" for p in ns))
        out.append("")
    out += cbody + [""] + defn
    if ns:
        out += ["", " ".join("}" for _ in ns)]
    return "\n".join(out) + "\n"


def struct_decl(lf: Lifter, name: str, st: dict) -> List[str]:
    lines = [f"struct {name}", "{"]
    if st["virtuals"]:
        for s in range(0, max(st["virtuals"]) + 1):
            c = st["virtuals"].get(s)
            if c is None:
                lines.append(f"    virtual void vfunc_{s:02d}();")
            else:
                lines += c.decls(virtual=True)
    for mname in sorted(st["methods"]):
        lines += st["methods"][mname].decls()
    lines.append("};")
    return lines


def render_body(lf: Lifter, stmts: List[S], rt: str) -> List[str]:
    lines: List[str] = []
    decl_types: Dict[str, List[str]] = {}

    def add_decl(t: str, name: str):
        decl_types.setdefault(ctype(t), [])
        if name not in decl_types[ctype(t)]:
            decl_types[ctype(t)].append(name)

    for name in sorted(lf.locals):
        add_decl(lf.locals[name], name)
    for r in sorted(lf.vars):
        add_decl("int", "r_" + r)

    def collect_defs(ss):
        for s in ss:
            if isinstance(s, SDef) and not s.inline and (s.uses or not isinstance(s.value, Call)):
                if s.uses:
                    t = s.value.t(lf)
                    add_decl(t if t != "void" else "int", s.name)
            if isinstance(s, SBlock):
                collect_defs(s.body)
                collect_defs(s.other)
    collect_defs(stmts)

    def emit(ss: List[S], ind: str, last_level: bool):
        for k, s in enumerate(ss):
            if isinstance(s, SDef):
                if s.inline:
                    continue
                if s.uses:
                    lines.append(f"{ind}{s.name} = {s.value.r(lf)};")
                elif isinstance(s.value, Call):
                    lines.append(f"{ind}{s.value.r(lf)};")
            elif isinstance(s, SAssign):
                lt = s.lhs.t(lf)
                want = lt if s.op == "=" else (None if lt in ("float", "double") else "int")
                if s.op == "=" and lt == "bool" and isinstance(s.rhs, Num):
                    rhs = "true" if s.rhs.v else "false"
                else:
                    rhs = conv(lf, s.rhs, want)
                lhs = s.lhs.r(lf)
                if s.op in ("&=", "|=", "^=", "<<=", ">>=") and lt in ("float", "double"):
                    lhs = f"*(int*)&{lhs}"                   # bit operations on a float (fabs and friends)
                lines.append(f"{ind}{lhs} {s.op} {rhs};")
            elif isinstance(s, SIf):
                lines.append(f"{ind}if ({s.cond.r(lf)}) goto {s.label};")
            elif isinstance(s, SGoto):
                lines.append(f"{ind}goto {s.label};")
            elif isinstance(s, SLabel):
                lines.append(f"{s.name}:")
                if k + 1 == len(ss):
                    lines.append(f"{ind};")
            elif isinstance(s, SRet):
                if last_level and k + 1 == len(ss) and rt == "void":
                    continue
                if rt == "void":
                    lines.append(f"{ind}return;")
                    continue
                v = s.fval if rt in ("float", "double") and s.fval is not None else s.val
                if v is None or isinstance(v, (Unknown, FSW)):
                    lines.append(f"{ind}return 0;")
                elif rt == "bool" and isinstance(v, Num):
                    lines.append(f"{ind}return {'true' if v.v else 'false'};")
                else:
                    lines.append(f"{ind}return {conv(lf, v, rt)};")
            elif isinstance(s, SComment):
                lines.append(f"{ind}// {s.text}")
            elif isinstance(s, SBlock):
                if s.kind == "do":
                    lines.append(f"{ind}do {{")
                    emit(s.body, ind + "    ", False)
                    lines.append(f"{ind}}} while ({s.cond.r(lf)});")
                else:
                    lines.append(f"{ind}if ({s.cond.r(lf)}) {{")
                    emit(s.body, ind + "    ", False)
                    if s.kind == "ifelse":
                        lines.append(f"{ind}}} else {{")
                        emit(s.other, ind + "    ", False)
                    lines.append(f"{ind}}}")

    emit(stmts, "    ", True)
    body_lines = lines
    fixed: List[str] = []
    for k, ln in enumerate(body_lines):
        fixed.append(ln)
        if ln.endswith(":") and not ln.startswith(" ") and (k + 1 == len(body_lines) or body_lines[k + 1].strip() == "}"):
            fixed.append("    ;")
    body_lines = fixed
    head = []
    for t, ns in decl_types.items():
        if t.endswith("*"):
            head += [f"    {t} {n};" for n in ns]
        else:
            head.append(f"    {t} {', '.join(ns)};")
    out = head + ([""] if head and body_lines else []) + body_lines
    return out
