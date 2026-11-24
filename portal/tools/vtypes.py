"""Which class an object is, where the program's own instructions prove it: constructors, which classes
are ever really built, and the global pointers whose class is certain. Used by callgraph.py to resolve
virtual calls made through those globals (the examiner's rounds Q18 and Q24).

Constructors and destructors, as MSVC 7.1 writes them:
- a constructor runs its bases' constructors first, then stores its own vtable pointer, then its body;
- a destructor stores its own vtable pointer first, runs its body, then its bases' destructors (or, for a
  deleting destructor, calls operator delete).
So in a function, the last vtable pointer stored at an object's start says which class it built, unless
what follows is a destructor's (a call on the same object to a function that stores a base class's
vtable, or operator delete).

instantiated(C): some function makes C's vtable the last one at an object's start, is not a destructor,
and is not only a base part of a bigger object (a constructor all of whose callers then store a subclass's
vtable). The family-leaf rule: when calls through a pointer use virtual function k, the object's class has
more than k virtual functions; when exactly one instantiated class (or several that agree on every slot
used) fits, the calls are resolved.

Typed globals (pointer globals whose object class is proven):
- new + constructor: every non-zero store to G is the result of a call to a constructor of C, or an
  object the same function has just stored C's vtable into (an inlined constructor);
- out-parameter: G is passed (pushed as an address) to a factory whose last act is storing, through that
  argument, an object a constructor of C just built, and nothing else stores a non-zero value in G;
- family-leaf: the virtual calls made through G fit one instantiated class.
"""
from __future__ import annotations

import re
import struct
from collections import defaultdict
from typing import Dict, List, Optional, Set, Tuple

REGS = ("eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi")
ABS = re.compile(r"dword ptr \[0x([0-9a-f]+)\]$")
BASE = re.compile(r"dword ptr \[(e[a-z]{2})(?: ([+-]) (0x[0-9a-f]+|\d+))?\]$")


class Facts:
    """Per function: its instructions' vtable stores, direct calls, and constructor shape."""

    def __init__(self, md, img, rt, funcs: Dict[int, int], operator_delete: Optional[int] = None):
        self.img, self.rt, self.funcs = img, rt, funcs
        self.delete = operator_delete
        self.stores: Dict[int, List[Tuple[int, str, int, int]]] = {}      # f -> [(addr, base reg, disp, vtable)]
        self.calls: Dict[int, List[Tuple[int, int, Optional[str]]]] = {}  # f -> [(addr, target, ecx source)]
        self.ret_pop: Dict[int, int] = {}
        self.callers: Dict[int, Set[int]] = defaultdict(set)
        self.ins: Dict[int, list] = {}
        for f, size in funcs.items():
            code = img.img.read(f, size) or b""
            ins = list(md.disasm(code, f))
            self.ins[f] = ins
            st, cl = [], []
            ecx_from: Optional[str] = "this"
            this_regs = {"ecx"}
            for i in ins:
                m, ops = i.mnemonic, [o.strip() for o in i.op_str.split(",")] if i.op_str else []
                if m == "mov" and len(ops) == 2:
                    d, s = ops
                    b = BASE.match(d)
                    if b and s.startswith("0x") and int(s, 16) in rt.vtables:
                        disp = int(b.group(3), 0) * (-1 if b.group(2) == "-" else 1) if b.group(3) else 0
                        base = "this" if b.group(1) in this_regs else b.group(1)
                        st.append((i.address, base, disp, int(s, 16)))
                    if d in REGS:
                        if s in this_regs:
                            this_regs.add(d)
                        else:
                            this_regs.discard(d)
                        if d == "ecx":
                            ecx_from = "this" if s in this_regs else s
                elif m == "call" and ops and ops[0].startswith("0x"):
                    t = int(ops[0], 16)
                    cl.append((i.address, t, ecx_from))
                    self.callers[t].add(f)
                    this_regs.discard("eax"); this_regs.discard("edx")
                    if "ecx" in this_regs:
                        this_regs.discard("ecx")
                    ecx_from = None
                elif m == "ret":
                    self.ret_pop[f] = int(ops[0], 0) if ops else 0
                elif ops and ops[0] in REGS and m not in ("cmp", "test", "push"):
                    this_regs.discard(ops[0])
                    if ops[0] == "ecx":
                        ecx_from = None
            self.stores[f] = st
            self.calls[f] = cl

    def final_on_this(self, f: int) -> Optional[int]:
        """The vtable a function leaves at the start of its own object (this), if it stores any there."""
        last = None
        for _a, base, disp, vt in self.stores.get(f, []):
            if base == "this" and disp == 0:
                last = vt
        return last

    def finals(self, f: int) -> List[Tuple[int, str, int]]:
        """[(address, base, vtable)]: per object start written in f, the last vtable stored there."""
        last: Dict[str, Tuple[int, int]] = {}
        for a, base, disp, vt in self.stores.get(f, []):
            if disp == 0:
                last[base] = (a, vt)
        return [(a, base, vt) for base, (a, vt) in last.items()]

    def is_destructor_store(self, f: int, at: int, base: str, vt: int) -> bool:
        cls = self.rt.vtables[vt][0]
        bases = {b for b, _ in self.rt.bases.get(cls, [])}
        # an inlined base destructor: a subclass's vtable stored first at the same place, then this one
        for a, b2, disp, v2 in self.stores.get(f, []):
            if a < at and b2 == base and disp == 0 and \
                    cls in {b for b, _ in self.rt.bases.get(self.rt.vtables[v2][0], [])}:
                return True
        for a, t, ecx in self.calls.get(f, []):
            if a <= at:
                continue
            if self.delete is not None and t == self.delete:
                return True
            if ecx == base or (base == "this" and ecx == "this"):
                fv = self.final_on_this(t)
                if fv is not None and self.rt.vtables[fv][0] in bases:
                    return True
        return False


def instantiated(fx: Facts) -> Dict[str, List[int]]:
    """{class: [functions that build one]} by the rule in the module's docstring."""
    ctor_of: Dict[int, List[str]] = defaultdict(list)       # f -> classes it leaves as final (not as destructor)
    for f in fx.funcs:
        for a, base, vt in fx.finals(f):
            if not fx.is_destructor_store(f, a, base, vt):
                ctor_of[f].append(fx.rt.vtables[vt][0])
    out: Dict[str, List[int]] = defaultdict(list)
    for f, classes in ctor_of.items():
        for cls in classes:
            callers = fx.callers.get(f, set())
            only_base = bool(callers) and fx.final_on_this(f) is not None and \
                fx.rt.vtables[fx.final_on_this(f)][0] == cls and all(
                    any(cls in {b for b, _ in fx.rt.bases.get(d, [])} for d in ctor_of.get(g, [])) for g in callers)
            if not only_base:
                out[cls].append(f)
    return dict(out)


def returns_this(fx: Facts, f: int) -> bool:
    """f ends `mov eax, R; [pop ...;] ret` with R its own object (a constructor returns this)."""
    ins = fx.ins.get(f, [])
    for j in range(len(ins) - 1, -1, -1):
        if ins[j].mnemonic == "ret":
            k = j - 1
            while k >= 0 and ins[k].mnemonic == "pop":
                k -= 1
            if k < 0:
                return False
            i = ins[k]
            ops = [o.strip() for o in i.op_str.split(",")]
            if i.mnemonic != "mov" or ops[0] != "eax" or len(ops) != 2:
                return False
            # R holds this: copied from ecx before any other write to it
            src = ops[1]
            for i2 in ins[:k]:
                o2 = [o.strip() for o in i2.op_str.split(",")] if i2.op_str else []
                if i2.mnemonic == "mov" and o2 and o2[0] == src:
                    return len(o2) == 2 and o2[1] == "ecx"
            return src == "ecx"
    return False


def constructor_class(fx: Facts, f: int, built: Dict[str, List[int]]) -> Optional[str]:
    """The class f constructs on its own object (it returns it), if f is one of that class's builders."""
    v = fx.final_on_this(f)
    if v is None or not returns_this(fx, f):
        return None
    cls = fx.rt.vtables[v][0]
    return cls if f in built.get(cls, []) or any(f in fs for fs in built.values()) else None


def _writable(img, va: int) -> bool:
    s = img.img.section_of(va)
    return bool(s and not s.is_code and s.name != ".rdata")


def typed_globals(fx: Facts, built: Dict[str, List[int]]) -> Dict[int, Tuple[str, str, str]]:
    """{global: (class, rule, evidence)} for pointer globals whose object's class is proven."""
    ctor_cls = {f: constructor_class(fx, f, built) for f in fx.funcs}
    stores: Dict[int, List[Tuple[int, int, Optional[str]]]] = defaultdict(list)   # G -> [(addr, f, class or None)]
    factories: Dict[int, Tuple[int, str]] = {}                                    # f -> (argument index, class)
    for f, ins in fx.ins.items():
        reg_cls: Dict[str, str] = {}
        reg_arg: Dict[str, int] = {}
        pro = 0
        for i in ins:
            if i.mnemonic == "push":
                pro += 1
            else:
                break
        last_call_cls: Optional[str] = None
        zero: Set[str] = set()
        for i in ins:
            m, ops = i.mnemonic, [o.strip() for o in i.op_str.split(",")] if i.op_str else []
            if m in ("xor", "sub") and len(ops) == 2 and ops[0] == ops[1] and ops[0] in REGS:
                zero.add(ops[0])
                continue
            if ops and ops[0] in zero and m not in ("cmp", "test", "push"):
                zero.discard(ops[0])
            if m == "call":
                zero -= {"eax", "ecx", "edx"}
                t = int(ops[0], 16) if ops and ops[0].startswith("0x") else None
                last_call_cls = ctor_cls.get(t) if t else None
                for r in ("eax", "ecx", "edx"):
                    reg_cls.pop(r, None); reg_arg.pop(r, None)
                if last_call_cls:
                    reg_cls["eax"] = last_call_cls
                continue
            if m == "mov" and len(ops) == 2:
                d, s = ops
                g = ABS.match(d)
                if g:
                    G = int(g.group(1), 16)
                    if s in ("0", "0x0") or s in zero:
                        continue
                    stores[G].append((i.address, f, reg_cls.get(s)))
                    continue
                b = BASE.match(d)
                if b and not b.group(3) and s.startswith("0x") and int(s, 16) in fx.rt.vtables and \
                        b.group(1) != "esp":
                    reg_cls[b.group(1)] = fx.rt.vtables[int(s, 16)][0]     # a constructor inlined here
                    continue
                if b and b.group(1) in reg_arg and not b.group(3) and s in reg_cls:
                    factories[f] = (reg_arg[b.group(1)], reg_cls[s])
                if d in REGS:
                    reg_cls.pop(d, None); reg_arg.pop(d, None); zero.discard(d)
                    if s in zero:
                        zero.add(d)
                    if s in reg_cls:
                        reg_cls[d] = reg_cls[s]
                    mm = re.fullmatch(r"dword ptr \[esp \+ (0x[0-9a-f]+|\d+)\]", s)
                    if mm:
                        k = int(mm.group(1), 0) - 4 - 4 * pro
                        if k >= 0 and k % 4 == 0:
                            reg_arg[d] = k // 4
                continue
            if m in ("xor", "sub") and len(ops) == 2 and ops[0] == ops[1]:
                continue                       # a null on the failure path: still that class, or none
            if ops and ops[0] in REGS and m not in ("cmp", "test", "push"):
                reg_cls.pop(ops[0], None); reg_arg.pop(ops[0], None)
    out: Dict[int, Tuple[str, str, str]] = {}
    for G, rows in stores.items():
        classes = {c for _a, _f, c in rows}
        if len(classes) == 1 and None not in classes:
            c = classes.pop()
            out[G] = (c, "new + constructor", ", ".join(f"0x{a:08X}" for a, _f, _c in rows[:3]))
    # out-parameters: the address of G pushed as the factory's argument
    for f, ins in fx.ins.items():
        pushes: List[Tuple[int, Optional[int]]] = []
        for i in ins:
            m, ops = i.mnemonic, [o.strip() for o in i.op_str.split(",")] if i.op_str else []
            if m == "push":
                pushes.append((i.address, int(ops[0], 16) if ops and ops[0].startswith("0x") else None))
            elif m == "call":
                t = int(ops[0], 16) if ops and ops[0].startswith("0x") else None
                if t in factories:
                    k, cls = factories[t]
                    if len(pushes) > k:
                        G = pushes[-1 - k][1]
                        if G is not None and _writable(fx.img, G) and G not in stores and G not in out:
                            out[G] = (cls, "out-parameter", f"0x{i.address:08X} -> factory 0x{t:08X}")
                pushes = []
            elif m in ("add",) and ops and ops[0] == "esp":
                pushes = []
    return out


def slot_candidates(fx: Facts, built: Dict[str, List[int]]) -> List[Tuple[str, int, List[int]]]:
    """[(class, vtable, slots)] for every vtable of an instantiated class (all parts, every offset)."""
    return [(cls, vt, slots) for vt, (cls, _off, slots) in fx.rt.vtables.items() if cls in built]


def family_leaf(cands, used: Set[int]) -> Optional[Dict[int, int]]:
    """{slot: target} when every candidate vtable long enough for the largest slot used agrees on each."""
    if not used:
        return None
    top = max(used)
    fit = [slots for _c, _v, slots in cands if len(slots) > top]
    if not fit:
        return None
    out = {}
    for k in used:
        targets = {s[k] for s in fit}
        if len(targets) != 1:
            return None
        out[k] = targets.pop()
    return out


def global_vcall_slots(fx: Facts) -> Dict[int, Set[int]]:
    """{global: slots} of the virtual calls made on the object a pointer global holds:
    mov r, [G]; mov e, [r]; call [e + 4k]  (also through ecx)."""
    out: Dict[int, Set[int]] = defaultdict(set)
    for f, ins in fx.ins.items():
        holds: Dict[str, int] = {}
        vt: Dict[str, int] = {}
        for i in ins:
            m, ops = i.mnemonic, [o.strip() for o in i.op_str.split(",")] if i.op_str else []
            if m == "mov" and len(ops) == 2 and ops[0] in REGS:
                d, s = ops
                g = ABS.match(s)
                b = BASE.match(s)
                holds.pop(d, None); vt.pop(d, None)
                if g:
                    holds[d] = int(g.group(1), 16)
                elif b and b.group(1) in holds and not b.group(3):
                    vt[d] = holds[b.group(1)]
                elif s in holds:
                    holds[d] = holds[s]
                continue
            if m == "call":
                if ops:
                    b = BASE.match(ops[0])
                    if b and b.group(1) in vt and b.group(2) != "-":
                        off = int(b.group(3), 0) if b.group(3) else 0
                        if off % 4 == 0:
                            out[vt[b.group(1)]].add(off // 4)
                for r in ("eax", "ecx", "edx"):
                    holds.pop(r, None); vt.pop(r, None)
                continue
            if ops and ops[0] in REGS and m not in ("cmp", "test", "push"):
                holds.pop(ops[0], None); vt.pop(ops[0], None)
    return dict(out)


def all_typed_globals(fx: Facts) -> Tuple[Dict[int, Tuple[str, str, str]], Dict[str, List[int]]]:
    """Typed globals by all three rules, and the instantiated classes."""
    built = instantiated(fx)
    typed = typed_globals(fx, built)
    cands = slot_candidates(fx, built)
    for G, used in global_vcall_slots(fx).items():
        if G in typed or not _writable(fx.img, G):
            continue
        top = max(used)
        fit = {c for c, _v, slots in cands if len(slots) > top}
        if len(fit) == 1 and family_leaf(cands, used):
            typed[G] = (fit.pop(), "family-leaf", f"virtual functions up to {top} used; one built class has that many")
    return typed, built
