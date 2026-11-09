"""Scarface compiled TorqueScript (.cso/.dso) -> syntax tree (tsast)."""
from __future__ import annotations

import struct
from dataclasses import dataclass
from typing import Dict, List, Optional, Tuple

from torque_ast import (FLT, NONE, STR, UINT, Assign, AssignOp, Break, Call, CommaCat, Conditional, Continue,
                   ExprStmt, FloatBinary, FloatConst, FloatUnary, FuncDecl, Ident, If, IntBinary, IntConst,
                   IntUnary, Loop, ObjectDecl, Return, SlotAccess, SlotAssign, SlotAssignOp, StrCat, StrConst,
                   StrEq, Var)

# opcode -> (name, operand kinds). S identifier (2 codes, patched at load), U uint (2 codes, high half first),
# F float table index (2), Z string table offset (2), C one code, J jump target (code index),
# A argc followed by argc identifiers.
OPS = {
    0: ("FUNC_DECL", "SSSCJA"), 1: ("CREATE_OBJECT", "SCJ"), 4: ("ADD_OBJECT", "C"), 5: ("END_OBJECT", "C"),
    6: ("JMPIFFNOT", "J"), 7: ("JMPIFNOT", "J"), 8: ("JMPIFF", "J"), 9: ("JMPIF", "J"),
    10: ("JMPIFNOT_NP", "J"), 11: ("JMPIF_NP", "J"), 12: ("JMP", "J"), 13: ("RETURN", ""),
    14: ("CMPEQ", ""), 15: ("CMP15", ""), 16: ("CMP16", ""), 17: ("CMP17", ""), 18: ("CMP18", ""), 19: ("CMPNE", ""),
    20: ("XOR", ""), 21: ("MOD", ""), 22: ("BITAND", ""), 23: ("BITOR", ""), 24: ("NOT", ""), 25: ("NOTF", ""),
    26: ("ONESCOMPLEMENT", ""), 27: ("SHR", ""), 28: ("SHL", ""), 29: ("AND", ""), 30: ("OR", ""),
    31: ("ADD", ""), 32: ("SUB", ""), 33: ("MUL", ""), 34: ("DIV", ""), 35: ("NEG", ""),
    36: ("SETCURVAR_LOCAL", "S"), 37: ("SETCURVAR_GLOBAL", "S"),
    38: ("SETCURVAR_LOCAL_CREATE", "S"), 39: ("SETCURVAR_GLOBAL_CREATE", "S"),
    40: ("SETCURVAR_ARRAY_LOCAL", ""), 41: ("SETCURVAR_ARRAY_GLOBAL", ""),
    42: ("SETCURVAR_ARRAY_LOCAL_CREATE", ""), 43: ("SETCURVAR_ARRAY_GLOBAL_CREATE", ""),
    44: ("LOADVAR_UINT", ""), 45: ("LOADVAR_FLT", ""), 46: ("LOADVAR_STR", ""),
    47: ("SAVEVAR_UINT", ""), 48: ("SAVEVAR_FLT", ""), 49: ("SAVEVAR_STR", ""),
    50: ("SETCUROBJECT", ""), 51: ("SETCUROBJECT_NEW", ""), 52: ("SETCURFIELD", "S"), 53: ("SETCURFIELD_ARRAY", ""),
    54: ("LOADFIELD_UINT", ""), 55: ("LOADFIELD_FLT", ""), 56: ("LOADFIELD_STR", ""),
    57: ("SAVEFIELD_UINT", ""), 58: ("SAVEFIELD_FLT", ""), 59: ("SAVEFIELD_STR", ""),
    60: ("STR_TO_UINT", ""), 61: ("STR_TO_FLT", ""), 62: ("STR_TO_NONE", ""), 63: ("FLT_TO_UINT", ""),
    64: ("FLT_TO_STR", ""), 65: ("FLT_TO_NONE", ""), 66: ("UINT_TO_FLT", ""), 67: ("UINT_TO_STR", ""),
    68: ("UINT_TO_NONE", ""),
    69: ("LOADIMMED_UINT", "U"), 70: ("LOADIMMED_FLT", "F"), 71: ("TAG_TO_STR", "Z"), 72: ("LOADIMMED_STR", "Z"),
    73: ("LOADIMMED_IDENT", "S"), 74: ("CALLFUNC_RESOLVE", "SSC"), 75: ("CALLFUNC", "SSC"),
    77: ("ADVANCE_STR", ""), 78: ("ADVANCE_STR_APPENDCHAR", "C"), 79: ("ADVANCE_STR_COMMA", ""),
    80: ("ADVANCE_STR_NUL", ""), 81: ("REWIND_STR", ""), 82: ("TERMINATE_REWIND_STR", ""), 83: ("COMPARE_STR", ""),
    84: ("PUSH", ""), 85: ("PUSH_FRAME", ""),
}
WIDTH = {"S": 2, "U": 2, "F": 2, "Z": 2, "C": 1, "J": 1}
END_MARK = 0xCDCD      # the compiler pads the code count to an even number with MSVC's fill value

# The comparison opcodes, in Torque's order (EQ, GR, GE, LT, LE, NE). The scripts confirm it: counting loops
# read "while (%i < %count)" this way (284 loops), and would read "%i > %count" the other way.
CMP = {14: "==", 15: ">", 16: ">=", 17: "<", 18: "<=", 19: "!="}
INT_OPS = {20: "^", 21: "%", 22: "&", 23: "|", 27: ">>", 28: "<<"}
FLT_OPS = {31: "+", 32: "-", 33: "*", 34: "/"}


class DecompileError(Exception):
    pass


@dataclass
class Insn:
    ip: int
    op: int
    args: list           # values (identifiers resolved to names or None)
    nxt: int


def disassemble(codes: List[int], ident_at: Dict[int, str]) -> List[Insn]:
    """The instructions. The compiler pads the code to an even count with one code it never writes:
    0xCDCD (MSVC's fill) in the retail scripts, leftover memory in the April 2006 prototype; see
    padding()."""
    out, ip, n = [], 0, len(codes)
    pad = padding(codes)
    if pad is not None:
        n -= 1
    while ip < n:
        op = codes[ip]
        if op not in OPS:
            raise DecompileError(f"unknown opcode {op} at {ip}")
        _, kinds = OPS[op]
        start, ip = ip, ip + 1
        args = []
        for k in kinds:
            if k == "A":
                argc = codes[ip]
                ip += 1
                names = []
                for _ in range(argc):
                    names.append(ident_at.get(ip))
                    ip += 2
                args.append(names)
                continue
            if ip + WIDTH[k] > n:
                raise DecompileError(f"instruction at {start} runs past the end")
            if k == "S":
                args.append(ident_at.get(ip))
            elif WIDTH[k] == 2:
                args.append((codes[ip] << 16) | codes[ip + 1])
            else:
                args.append(codes[ip])
            ip += WIDTH[k]
        out.append(Insn(start, op, args, ip))
    return out


def padding(codes: List[int]) -> Optional[int]:
    """The value of the padding code at the end, or None if the count needed none. The program always
    ends with RETURN (13), so an even count whose last code is not that RETURN was padded."""
    n = len(codes)
    if n < 2 or n % 2:
        return None
    if codes[-1] == END_MARK:
        return END_MARK
    if codes[-1] != 13:
        return codes[-1]
    # ends in 13: a real RETURN unless the instructions end one code earlier
    ip = 0
    while ip < n:
        op = codes[ip]
        if op not in OPS:
            return None
        kinds = OPS[op][1]
        size = 1 + sum(WIDTH.get(k, 0) for k in kinds)
        if "A" in kinds:
            at = ip + 1 + sum(WIDTH[k] for k in kinds.replace("A", ""))
            if at >= n:
                return None
            size += 1 + 2 * codes[at]
        if ip + size == n - 1 and op == 13:
            return 13
        ip += size
    return None


CONSUMED = object()       # a string that has been used
EMPTY = object()          # the fresh slot ADVANCE_STR leaves on top


class Slot:
    __slots__ = ("node", "sep")

    def __init__(self, node):
        self.node = node
        self.sep = None        # set by ADVANCE_STR*: "@", a character, "," or "NUL"


@dataclass
class LoopCtx:
    brk: int
    cont: Optional[int] = None


class Sim:
    """The Torque VM's stacks, holding syntax nodes instead of values."""

    def __init__(self):
        self.ints: list = []
        self.flts: list = []
        self.strs: List[Slot] = []
        self.frames: list = []
        self.objs: List[ObjectDecl] = []
        self.obj_open: List[bool] = []          # still taking fields (before ADD_OBJECT)
        self.var: Optional[Var] = None
        self.var_create = False
        self.cur_obj = None
        self.field: Optional[str] = None
        self.field_index = None
        self.aop = None                          # the Var an assign-op just loaded (x op= v)
        self.field_aop = None                    # the field an assign-op just loaded (o.f op= v)

    # string stack: the top slot is the string being written; ADVANCE_STR* starts a new one above it
    def load(self, node):
        if self.strs:
            self.strs[-1].node = node
        else:
            self.strs.append(Slot(node))

    def advance(self, sep):
        if not self.has_str():
            raise DecompileError("advance without a string")
        self.strs[-1].sep = sep
        self.strs.append(Slot(EMPTY))

    def take(self):
        if not self.has_str():
            raise DecompileError("string stack: nothing to take")
        n = self.strs[-1].node
        self.strs[-1].node = CONSUMED
        return n

    def has_str(self) -> bool:
        return bool(self.strs) and self.strs[-1].node not in (CONSUMED, EMPTY) and self.strs[-1].sep is None

    def idle(self) -> bool:
        return (not self.ints and not self.flts and not self.frames and not self.objs
                and all(s.node in (CONSUMED, EMPTY) and s.sep is None for s in self.strs))

    def values(self) -> List[Tuple[object, str]]:
        """What is left: [(node, type)]."""
        out = [(n, UINT) for n in self.ints] + [(n, FLT) for n in self.flts]
        live = [s for s in self.strs if s.node not in (CONSUMED, EMPTY) or s.sep is not None]
        if live:
            if len(live) == 1 and live[0].sep is None and live[0] is self.strs[-1]:
                out.append((live[0].node, STR))
            else:
                out.append((None, "bad"))
        if self.frames or self.objs:
            out.append((None, "bad"))
        return out


def f32(raw: bytes) -> float:
    return struct.unpack("<f", raw)[0]


class Decompiler:
    def __init__(self, script):
        self.s = script
        self.codes = script.codes
        self.gstr = script.global_strings
        self.fstr = script.function_strings
        self.gflt = script._gf_raw
        self.fflt = script._ff_raw
        self.ident_at: Dict[int, str] = {}
        for off, locs in script.idents:
            name = self._cstr(self.gstr, off)
            for loc in locs:
                self.ident_at[loc] = name
        self.ins = disassemble(self.codes, self.ident_at)
        self.at = {i.ip: i for i in self.ins}
        self.end = self.ins[-1].nxt if self.ins else 0
        # do-while loops: a backward conditional jump that is not the bottom of a while/for loop
        self.do_loops: Dict[int, List[int]] = {}
        for i in self.ins:
            if i.op in (8, 9) and i.args[0] <= i.ip:
                s = i.args[0]
                head = self.at.get(s - 2)
                if head is not None and head.op in (6, 7) and head.args[0] == i.nxt:
                    continue
                self.do_loops.setdefault(s, []).append(i.ip)
        for s in self.do_loops:
            self.do_loops[s].sort(reverse=True)

    @staticmethod
    def _cstr(table: bytes, off: int) -> str:
        if off > len(table):
            raise DecompileError(f"string offset {off} outside its table")
        end = table.find(b"\0", off)
        return table[off:end if end >= 0 else len(table)].decode("latin-1")

    def string(self, off: int, fn: bool) -> str:
        return self._cstr(self.fstr if fn else self.gstr, off)

    def float_raw(self, idx: int, fn: bool) -> bytes:
        t = self.fflt if fn else self.gflt
        if 4 * idx + 4 > len(t):
            raise DecompileError(f"float index {idx} outside its table")
        return t[4 * idx:4 * idx + 4]

    # ------------------------------------------------------------------ entry
    def decompile(self) -> list:
        last = self.ins[-1] if self.ins else None
        if last is None or last.op != 13:
            raise DecompileError("the script does not end with RETURN")
        stmts, _ = self.run(0, last.ip, None, False, "block")
        tidy(stmts)
        return stmts

    # ------------------------------------------------------------------ core
    def expr(self, start: int, end: int, fn: bool):
        """A range that leaves exactly one value: (node, type)."""
        stmts, vals = self.run(start, end, None, fn, "expr")
        if stmts or len(vals) != 1 or vals[0][1] == "bad":
            raise DecompileError(f"{start}..{end} is not a single expression")
        return vals[0]

    def run(self, start: int, end: int, loop: Optional[LoopCtx], fn: bool, mode: str, active_do=()):
        sim = Sim()
        out: list = []
        ip = start
        stmt_start = start

        def emit(stmt):
            stmt._ip = stmt_start
            # fields of an object being declared
            if sim.objs and sim.obj_open[-1] and isinstance(stmt, ExprStmt) and isinstance(stmt.expr, SlotAssign) \
                    and stmt.expr.obj is None:
                sim.objs[-1].slots.append(stmt.expr)
                return
            if sim.objs:
                raise DecompileError(f"statement inside an object declaration at {stmt_start}")
            out.append(stmt)

        while ip < end:
            if mode != "expr" and ip == stmt_start and sim.idle() and ip in self.do_loops:
                todo = [q for q in self.do_loops[ip] if (ip, q) not in active_do and q < end]
                if todo:
                    q = todo[0]
                    ctx = LoopCtx(brk=q + 2)
                    body, vals = self.run(ip, q, ctx, fn, "do", active_do + ((ip, q),))
                    jmp = self.at[q]
                    if len(vals) != 1 or vals[0][1] not in ((UINT if jmp.op == 9 else FLT),):
                        raise DecompileError(f"do-while at {ip}: no test value")
                    st = Loop(None, vals[0][0], body, None, is_do=True)
                    self._split_end(st, ctx)
                    emit(st)
                    ip = q + 2
                    stmt_start = ip
                    continue
            ins = self.at.get(ip)
            if ins is None:
                raise DecompileError(f"no instruction starts at {ip}")
            op, a = ins.op, ins.args

            if op == 0:                                         # function declaration
                if fn or not sim.idle():
                    raise DecompileError("function inside a function")
                name, ns, pkg, has_body, fend, argv = a
                ret = self.at.get(fend - 1)
                if ret is None or ret.op != 13:
                    raise DecompileError(f"function {name} does not end with RETURN")
                body, _ = self.run(ins.nxt, fend - 1, None, True, "block")
                if not has_body and body:
                    raise DecompileError(f"function {name}: statements but no body flag")
                emit(FuncDecl(name, ns, pkg, argv, body if has_body else None))
                ip = stmt_start = fend
                continue

            if op in (6, 7):                                    # JMPIFFNOT / JMPIFNOT
                t = a[0]
                test = (sim.ints if op == 7 else sim.flts).pop() if (sim.ints if op == 7 else sim.flts) else None
                if test is None:
                    raise DecompileError(f"conditional jump at {ip} without a test value")
                statement_level = mode != "expr" and sim.idle()
                back = self.at.get(t - 2)
                if statement_level and back is not None and back.op in (8, 9) and back.args[0] == ins.nxt:
                    st, ip = self._loop(sim, out, test, ins, t, stmt_start, loop, fn, (back.op == 9))
                    emit(st)
                    stmt_start = ip
                    continue
                cond = self._try_conditional(ins, t, fn, end)
                if cond is not None:
                    (tn, typ), (fnode, ftyp), e = cond
                    node = Conditional(test, tn, fnode)
                    if typ == STR:
                        sim.load(node)
                    else:
                        (sim.ints if typ == UINT else sim.flts).append(node)
                    ip = e
                    continue
                if not statement_level:
                    raise DecompileError(f"conditional jump at {ip} inside an expression is not ?:")
                st, ip = self._if(test, ins, t, end, loop, fn, active_do)
                emit(st)
                stmt_start = ip
                continue

            if op in (10, 11):                                  # && ||
                t = a[0]
                if not sim.ints:
                    raise DecompileError(f"&&/|| at {ip} without a left value")
                left = sim.ints.pop()
                right, typ = self.expr(ins.nxt, t, fn)
                if typ != UINT:
                    raise DecompileError(f"&&/|| at {ip}: right side is {typ}")
                sim.ints.append(IntBinary("&&" if op == 10 else "||", left, right))
                ip = t
                continue

            if op == 12:                                        # JMP: break / continue
                if mode == "expr" or not sim.idle() or loop is None:
                    raise DecompileError(f"jump at {ip} outside a loop")
                t = a[0]
                if t == loop.brk:
                    emit(Break())
                else:
                    if loop.cont is not None and loop.cont != t:
                        raise DecompileError(f"continue at {ip} goes to {t}, earlier ones to {loop.cont}")
                    loop.cont = t
                    emit(Continue())
                ip = stmt_start = ins.nxt
                continue

            if op in (8, 9):
                raise DecompileError(f"unexpected backward jump at {ip}")

            if op == 13:                                        # return
                if mode == "expr":
                    raise DecompileError("return inside an expression")
                if sim.has_str() and not sim.ints and not sim.flts:
                    emit(Return(sim.take()))
                elif sim.idle():
                    emit(Return(None))
                else:
                    raise DecompileError(f"return at {ip} with values left over")
                ip = stmt_start = ins.nxt
                sim.strs.clear()
                continue

            self.step(sim, ins, fn, emit)
            ip = ins.nxt
            if mode != "expr" and sim.idle():
                sim.strs.clear()
                stmt_start = ip

        if mode == "block":
            if not sim.idle():
                raise DecompileError(f"values left over at the end of {start}..{end}")
            return out, []
        return out, sim.values()

    # ------------------------------------------------------------------ statements
    def _if(self, test, ins, t, end, loop, fn, active_do):
        j = self.at.get(t - 2)
        if j is not None and j.op == 12 and t <= j.args[0] <= end and t - 2 >= ins.nxt:
            then, _ = self.run(ins.nxt, t - 2, loop, fn, "block", active_do)
            els, _ = self.run(t, j.args[0], loop, fn, "block", active_do)
            return If(test, then, els), j.args[0]
        then, _ = self.run(ins.nxt, t, loop, fn, "block", active_do)
        return If(test, then, None), t

    def _loop(self, sim, out, test, ins, t, stmt_start, outer, fn, integer):
        """while/for: [init] test JMPIF(F)NOT brk; body; [end]; test; JMPIF(F) body; brk:"""
        p = ins.ip
        n = p - stmt_start
        tp = t - 2 - n
        if tp < ins.nxt or not self._same_code(stmt_start, p, tp):
            raise DecompileError(f"loop at {p}: the test is not repeated at the bottom")
        ctx = LoopCtx(brk=t)
        body, _ = self.run(ins.nxt, tp, ctx, fn, "block")
        st = Loop(None, test, body, None)
        self._split_end(st, ctx, tp)
        return st, t

    def _same_code(self, a: int, a_end: int, b: int) -> bool:
        """Whether the code at b repeats a..a_end, with jumps inside it moved along by b - a."""
        d = b - a
        ip = a
        while ip < a_end:
            x, y = self.at.get(ip), self.at.get(ip + d)
            if x is None or y is None or x.op != y.op or x.nxt - x.ip != y.nxt - y.ip:
                return False
            kinds = OPS[x.op][1]
            if "J" in kinds:
                if any((u + d if k == "J" else u) != v for k, u, v in zip(kinds, x.args, y.args)):
                    return False
            elif x.args != y.args:
                return False
            ip = x.nxt
        return ip == a_end

    def _split_end(self, st: Loop, ctx: LoopCtx, test_start: Optional[int] = None):
        """Move the loop's end expression (for(;;X)) out of the body when continue statements show
        where it starts."""
        if ctx.cont is None or ctx.cont == test_start:
            return
        tail = [s for s in st.body if getattr(s, "_ip", -1) >= ctx.cont]
        if len(tail) == 1 and isinstance(tail[0], ExprStmt):
            st.body = st.body[:-1]
            st.end = tail[0].expr
        elif tail:
            raise DecompileError("loop end expression is not a single expression")

    def _try_conditional(self, ins, t, fn, end):
        j = self.at.get(t - 2)
        if j is None or j.op != 12 or j.args[0] < t or t - 2 < ins.nxt:
            return None
        e = j.args[0]
        try:
            tv = self.expr(ins.nxt, t - 2, fn)
            fv = self.expr(t, e, fn)
        except DecompileError:
            return None
        if tv[1] != fv[1] or tv[1] == "bad":
            return None
        return tv, fv, e

    # ------------------------------------------------------------------ one instruction
    def step(self, sim: Sim, ins: Insn, fn: bool, emit):
        op, a = ins.op, ins.args
        if op == 1:                                     # CREATE_OBJECT parent, datablock, fail
            if not sim.frames:
                raise DecompileError("CREATE_OBJECT without a frame")
            fr = sim.frames.pop()
            if len(fr) < 2:
                raise DecompileError("CREATE_OBJECT without class and name")
            sim.objs.append(ObjectDecl(fr[0], fr[1], a[0], bool(a[1]), fr[2:]))
            sim.obj_open.append(True)
            sim.objs[-1]._fail = a[2]
            sim.objs[-1]._start = None
        elif op == 4:                                   # ADD_OBJECT root
            if not sim.objs or not sim.obj_open[-1]:
                raise DecompileError("ADD_OBJECT without an object")
            sim.obj_open[-1] = False
            sim.objs[-1]._root = bool(a[0])
        elif op == 5:                                   # END_OBJECT
            if not sim.objs or sim.obj_open[-1]:
                raise DecompileError("END_OBJECT without ADD_OBJECT")
            o = sim.objs.pop()
            sim.obj_open.pop()
            if o._fail != ins.nxt:
                raise DecompileError(f"object at {ins.ip}: fail jump {o._fail}, ends at {ins.nxt}")
            if bool(a[0]) != (o._root or o.datablock):
                raise DecompileError("END_OBJECT flag")
            if sim.objs:
                if o._root:
                    raise DecompileError("root object inside an object")
                sim.objs[-1].subs.append(o)
            else:
                if not o._root or not sim.ints or not (isinstance(sim.ints[-1], IntConst) and sim.ints[-1].value == 0):
                    raise DecompileError("object declaration without its 0")
                sim.ints[-1] = o
        elif op in CMP:
            if len(sim.flts) < 2:
                raise DecompileError("compare needs two floats")
            left = sim.flts.pop()
            right = sim.flts.pop()
            sim.ints.append(IntBinary(CMP[op], left, right))
        elif op in INT_OPS:
            if len(sim.ints) < 2:
                raise DecompileError("int op needs two values")
            left = sim.ints.pop()
            right = sim.ints.pop()
            sim.ints.append(IntBinary(INT_OPS[op], left, right))
        elif op == 24:
            e = sim.ints.pop()
            prev = self.at.get(ins.ip - 1)
            if isinstance(e, StrEq) and e.eq and prev is not None and prev.op == 83:
                sim.ints.append(StrEq(e.left, e.right, False))      # a !$= b
            else:
                sim.ints.append(IntUnary("!", e))
        elif op == 25:
            sim.ints.append(IntUnary("!", sim.flts.pop()))
        elif op == 26:
            sim.ints.append(IntUnary("~", sim.ints.pop()))
        elif op in FLT_OPS:
            if len(sim.flts) < 2:
                raise DecompileError("float op needs two values")
            left = sim.flts.pop()
            right = sim.flts.pop()
            sim.flts.append(FloatBinary(FLT_OPS[op], left, right))
        elif op == 35:
            sim.flts.append(FloatUnary(sim.flts.pop()))
        elif 36 <= op <= 39:
            if a[0] is None:
                raise DecompileError("variable without a name")
            sim.var = Var(a[0], op in (36, 38))
            sim.var_create = op in (38, 39)
            sim.aop = None
        elif 40 <= op <= 43:
            s = sim.take()
            if not (isinstance(s, StrCat) and s.char is None and isinstance(s.left, Ident)):
                raise DecompileError("array variable without name @ index")
            sim.var = Var(s.left.name, op in (40, 42), s.right)
            sim.var_create = op in (42, 43)
            sim.aop = None
        elif op in (44, 45, 46):
            if sim.var is None:
                raise DecompileError("LOADVAR without a variable")
            v = Var(sim.var.name, sim.var.local, sim.var.index)
            if sim.var_create:
                sim.aop = v
            self._push(sim, v, op - 44)
        elif op in (47, 48, 49):
            if sim.var is None:
                raise DecompileError("SAVEVAR without a variable")
            val = self._pop(sim, op - 47)
            if not sim.var_create:
                raise DecompileError("SAVEVAR after a plain SETCURVAR")
            if sim.aop is not None:                      # SETCURVAR_CREATE; LOADVAR; op; SAVEVAR
                if not (isinstance(val, (FloatBinary, IntBinary)) and val.left is sim.aop):
                    raise DecompileError("assign-op without its operation")
                node = AssignOp(sim.var, val.op, val.right)
            else:
                node = Assign(sim.var, val)
            sim.aop = None
            self._push(sim, node, op - 47)
        elif op == 50:
            sim.cur_obj = sim.take()
        elif op == 51:
            sim.cur_obj = None
        elif op == 52:
            sim.field, sim.field_index = a[0], None
        elif op == 53:
            sim.field_index = sim.take()
        elif op in (54, 55, 56):
            if sim.cur_obj is None:
                raise DecompileError("LOADFIELD on a new object")
            n = SlotAccess(sim.cur_obj, sim.field, sim.field_index)
            sim.field_aop = n
            self._push(sim, n, op - 54)
        elif op in (57, 58, 59):
            val = self._pop(sim, op - 57)
            if op == 59:                                 # only plain assignments save strings
                node = SlotAssign(sim.cur_obj, sim.field, sim.field_index, val)
            else:                                        # x.f op= v: ... LOADFIELD; op; SAVEFIELD
                fa = getattr(sim, "field_aop", None)
                if not (isinstance(val, (FloatBinary, IntBinary)) and fa is not None and val.left is fa):
                    raise DecompileError("number SAVEFIELD that is not an assign-op")
                node = SlotAssignOp(fa.obj, fa.slot, fa.index, val.op, val.right)
            sim.field_aop = None
            self._push(sim, node, op - 57)
        elif op == 60:
            sim.ints.append(sim.take())
        elif op == 61:
            sim.flts.append(sim.take())
        elif op == 62:
            emit(ExprStmt(sim.take()))
        elif op == 63:
            sim.ints.append(sim.flts.pop())
        elif op == 64:
            sim.load(sim.flts.pop())
        elif op == 65:
            emit(ExprStmt(sim.flts.pop()))
        elif op == 66:
            sim.flts.append(sim.ints.pop())
        elif op == 67:
            sim.load(sim.ints.pop())
        elif op == 68:
            emit(ExprStmt(sim.ints.pop()))
        elif op == 69:
            sim.ints.append(IntConst(a[0]))
        elif op == 70:
            sim.flts.append(FloatConst(self.float_raw(a[0], fn)))
        elif op == 71:
            sim.load(StrConst(self.string(a[0], fn), tag=True))
        elif op == 72:
            sim.load(StrConst(self.string(a[0], fn)))
        elif op == 73:
            if a[0] is None:
                raise DecompileError("LOADIMMED_IDENT without a name")
            sim.load(Ident(a[0]))
        elif op in (74, 75):
            if not sim.frames:
                raise DecompileError("call without a frame")
            args = sim.frames.pop()
            name, ns, ct = a
            if (op == 75) != (ct in (1, 2)):
                raise DecompileError(f"call type {ct} with opcode {op}")
            if ct == 1 and not args:
                raise DecompileError("method call without an object")
            sim.load(Call(name, ns, args, ct))
        elif op in (77, 78, 79, 80):
            sim.advance({77: "@", 79: ",", 80: "NUL"}.get(op) or chr(a[0]))
        elif op == 81:
            if len(sim.strs) < 2:
                raise DecompileError("rewind without two strings")
            s2 = sim.strs.pop()
            s1 = sim.strs[-1]
            if s1.sep is None or s1.node in (CONSUMED, EMPTY) or s2.node in (CONSUMED, EMPTY) or s2.sep is not None:
                raise DecompileError("rewind of a consumed string")
            if s1.sep == ",":
                s1.node = CommaCat(s1.node, s2.node)
            elif s1.sep == "NUL":
                raise DecompileError("rewind after ADVANCE_STR_NUL")
            else:
                s1.node = StrCat(s1.node, s2.node, None if s1.sep == "@" else s1.sep)
            s1.sep = None
        elif op == 82:
            if len(sim.strs) < 2 or sim.strs[-1].node not in (CONSUMED, EMPTY):
                raise DecompileError("terminate-rewind of a live string")
            sim.strs.pop()
            if sim.strs[-1].sep != "@":
                raise DecompileError("terminate-rewind after a special advance")
            sim.strs[-1].sep = None
        elif op == 83:
            if len(sim.strs) < 2:
                raise DecompileError("compare without two strings")
            s2 = sim.strs.pop()
            s1 = sim.strs[-1]
            if s1.sep != "NUL" or s2.node in (CONSUMED, EMPTY):
                raise DecompileError("compare without ADVANCE_STR_NUL")
            sim.ints.append(StrEq(s1.node, s2.node, True))
            s1.node, s1.sep = CONSUMED, None
        elif op == 84:
            if not sim.frames:
                raise DecompileError("push without a frame")
            sim.frames[-1].append(sim.take())
        elif op == 85:
            sim.frames.append([])
        else:
            raise DecompileError(f"opcode {op} ({OPS[op][0]}) at {ins.ip} not handled")

    @staticmethod
    def _push(sim, node, kind):
        if kind == 0:
            sim.ints.append(node)
        elif kind == 1:
            sim.flts.append(node)
        else:
            sim.load(node)

    @staticmethod
    def _pop(sim, kind):
        if kind == 0:
            if not sim.ints:
                raise DecompileError("int stack empty")
            return sim.ints.pop()
        if kind == 1:
            if not sim.flts:
                raise DecompileError("float stack empty")
            return sim.flts.pop()
        return sim.take()


# ---------------------------------------------------------------------------- readability
def _vars(n, out: set):
    if isinstance(n, Var):
        out.add((n.name, n.local))
    for v in getattr(n, "__dict__", {}).values():
        if isinstance(v, list):
            for x in v:
                _vars(x, out)
        elif hasattr(v, "__dict__"):
            _vars(v, out)
    return out


def _has_continue(stmts) -> bool:
    for s in stmts:
        if isinstance(s, Continue):
            return True
        if isinstance(s, If) and (_has_continue(s.then) or _has_continue(s.else_ or [])):
            return True
    return False


def tidy(stmts: list):
    """Write counting loops as for loops. `%i = 0; while (%i < %n) { ...; %i++; }` and
    `for (%i = 0; %i < %n; %i++) { ... }` compile to the same bytes when the body has no continue."""
    i = 0
    while i < len(stmts):
        s = stmts[i]
        for block in _blocks(s):
            tidy(block)
        if isinstance(s, Loop) and not s.is_do and s.init is None and s.end is None and len(s.body) >= 2 \
                and not _has_continue(s.body):
            last = s.body[-1]
            if isinstance(last, ExprStmt) and isinstance(last.expr, (Assign, AssignOp)) \
                    and (last.expr.var.name, last.expr.var.local) in _vars(s.test, set()):
                s.end = last.expr
                s.body = s.body[:-1]
                prev = stmts[i - 1] if i else None
                if isinstance(prev, ExprStmt) and isinstance(prev.expr, Assign) \
                        and prev.expr.var.name == last.expr.var.name and prev.expr.var.index is None:
                    s.init = prev.expr
                    del stmts[i - 1]
                    i -= 1
        i += 1


def _blocks(s):
    if isinstance(s, If):
        return [s.then] + ([s.else_] if s.else_ is not None else [])
    if isinstance(s, Loop):
        return [s.body]
    if isinstance(s, FuncDecl) and s.body:
        return [s.body]
    return []


# ---------------------------------------------------------------------------- instruction listing
def listing(script, names: Optional[Dict[int, str]] = None) -> str:
    """One line per instruction: code index, opcode name and operands (strings, numbers and names
    resolved). Jumps show the code index they go to."""
    from torque_names import name_key
    d = Decompiler(script)
    names = names or {}
    fn_end = -1
    out = []

    def nm(x):
        if x is None:
            return "-"
        return names.get(name_key(x), x)

    for i in d.ins:
        if i.op == 0:
            fn_end = i.args[4]
        fn = i.ip < fn_end
        name, kinds = OPS[i.op]
        parts = []
        for k, v in zip(kinds.replace("A", "") + ("A" if "A" in kinds else ""), i.args):
            if k == "S":
                parts.append(nm(v))
            elif k == "Z":
                parts.append(repr(d.string(v, fn)))
            elif k == "F":
                parts.append(repr(round(f32(d.float_raw(v, fn)), 7)))
            elif k == "J":
                parts.append(f"-> {v}")
            elif k == "A":
                parts.append("(" + ", ".join(nm(x) for x in v) + ")")
            elif name == "ADVANCE_STR_APPENDCHAR":
                parts.append(repr(chr(v)))
            else:
                parts.append(str(v))
        out.append(f"{i.ip:6d}  {name:<24} {' '.join(parts)}".rstrip())
    return "\n".join(out) + "\n"
