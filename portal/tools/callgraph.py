"""Who calls whom in the Xbox game, read from its own instructions: the order to describe (and match)
functions in, leaves first, and what each one touches.

    python portal/tools/callgraph.py                 -> reports/callgraph_xb.json (needs binaries/default.xbe)
    python portal/tools/callgraph.py --strings       ... also the text each function uses (for your own
                                                      copy only: work/callgraph_xb_strings.json, not committed)

For every function (the registry's and the queue's):
- calls: direct calls, and jumps to another function's start (a tail call). A function that is only a jump
  (a thunk) is folded into its target; so is an adjustor (`sub ecx,N; jmp F` or `add ecx,-N; jmp F`, what a
  second vtable of a class with two bases holds), listed under "adjustors" with how far it moves this.
- virtual: calls through a vtable that can be told for certain, [target, how]:
    own   the function's own class (ecx at entry, or a register copied from it), slot = offset / 4
    base  a base-class part of this (lea ecx,[this+N], N a base's place from the class hierarchy): that
          part's vtable in this class
    ctor  an object whose vtable the function itself just stored (mov [reg], vtable)
    global the object a pointer global holds, when its class is proven (portal/tools/vtypes.py: one
          constructor's result stored, a factory's out-parameter, or the only built class with that
          many virtual functions); listed under "typed_globals" with the rule and its evidence
  A function's class is the class whose vtable holds it (the most basic one, when several do), or the
  class its name in reports/names.json or the registry gives.
- unresolved: calls through a register or memory that these rules can't tell.
- globals: fixed data addresses it reads or writes; casts: its dynamic_casts as [from, to] class pairs (the
  two type descriptors pushed for __RTDynamicCast, whose address comes from reports/names.json);
  strings: how many text constants it uses.
- order: Tarjan's strongly connected components over the direct calls, leaves first (a function comes
  after everything it calls, except inside a cycle).

The class hierarchy is the program's own run-time type information: each vtable is preceded by its
CompleteObjectLocator (offset, type descriptor, ClassHierarchyDescriptor -> BaseClassArray with each base's
mdisp).
"""
from __future__ import annotations

import json
import re
import struct
import sys
from collections import defaultdict
from pathlib import Path
from typing import Dict, List, Optional, Set, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parent))

ROOT = Path(__file__).resolve().parents[2]
REGS32 = ("eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi")
CLOBBERED = ("eax", "ecx", "edx")


# ---------------------------------------------------------------------------- the image

class Img:
    def __init__(self, image):
        self.img = image
        self.code = [(s.va, s.va + s.vsize) for s in image.sections if s.is_code and not s.library]
        self.data = [(s.va, s.va + s.vsize) for s in image.sections if not s.is_code]
        self.raw = [(s.va, s.va + min(s.vsize, s.raw_size)) for s in image.sections if not s.is_code]

    def u32(self, va: int) -> Optional[int]:
        b = self.img.read(va, 4)
        return struct.unpack("<I", b)[0] if b and len(b) == 4 else None

    def in_code(self, va) -> bool:
        return va is not None and any(a <= va < b for a, b in self.code)

    def in_data(self, va) -> bool:
        return va is not None and any(a <= va < b for a, b in self.data)

    def cstr(self, va: int, most: int = 120) -> Optional[str]:
        b = self.img.read(va, most)
        if not b:
            return None
        end = b.find(b"\0")
        if end < 4 or not all(0x20 <= c < 0x7F or c in (9, 10, 13) for c in b[:end]):
            return None
        return b[:end].decode("latin-1")


def type_name(img: Img, td: int) -> Optional[str]:
    """The decorated name of a type descriptor (".?AVFoo@@"), if td is one."""
    if not img.in_data(td):
        return None
    s = img.cstr(td + 8, 200)
    return s if s and s.startswith(".?A") else None


def plain(decorated: str) -> str:
    """.?AVFoo@bar@@ -> bar::Foo; templates keep their decorated arguments."""
    body = decorated[4:-2] if decorated.endswith("@@") else decorated[4:]
    if body.startswith("?$"):
        return body
    return "::".join(reversed([p for p in body.split("@") if p]))


# ---------------------------------------------------------------------------- RTTI: vtables and classes

class Rtti:
    """vtables (start -> (class, offset of the part it is for, [slots])) and each class's bases."""

    def __init__(self, img: Img, starts: Set[int]):
        self.vtables: Dict[int, Tuple[str, int, List[int]]] = {}
        self.bases: Dict[str, List[Tuple[str, int]]] = {}
        self.of_class: Dict[Tuple[str, int], int] = {}            # (class, part offset) -> vtable
        for lo, hi in img.raw:
            raw = img.img.read(lo, hi - lo) or b""
            for i in range(0, len(raw) - 8, 4):
                col = struct.unpack_from("<I", raw, i)[0]
                if not img.in_data(col):
                    continue
                first = struct.unpack_from("<I", raw, i + 4)[0]
                if first not in starts:
                    continue
                hdr = img.img.read(col, 20)
                if not hdr or len(hdr) < 20:
                    continue
                sig, off, _cd, td, chd = struct.unpack("<5I", hdr)
                name = sig == 0 and type_name(img, td)
                if not name:
                    continue
                vt = lo + i + 4
                slots = []
                j = i + 4
                while j + 4 <= len(raw):
                    f = struct.unpack_from("<I", raw, j)[0]
                    if not img.in_code(f) or (slots and lo + j != vt + 4 * len(slots)):
                        break
                    if j > i + 4 and self._looks_like_col(img, raw, j, starts):
                        break
                    slots.append(f)
                    j += 4
                cls = plain(name)
                self.vtables[vt] = (cls, off, slots)
                self.of_class.setdefault((cls, off), vt)
                if cls not in self.bases:
                    self.bases[cls] = self._bases(img, chd)

    @staticmethod
    def _looks_like_col(img: Img, raw: bytes, j: int, starts: Set[int]) -> bool:
        if j + 8 > len(raw):
            return False
        col = struct.unpack_from("<I", raw, j)[0]
        nxt = struct.unpack_from("<I", raw, j + 4)[0]
        return img.in_data(col) and nxt in starts and img.u32(col) == 0 and \
            bool(type_name(img, img.u32(col + 12) or 0))

    @staticmethod
    def _bases(img: Img, chd: int) -> List[Tuple[str, int]]:
        hdr = img.img.read(chd, 16)
        if not hdr or len(hdr) < 16:
            return []
        _sig, _attr, n, bca = struct.unpack("<4I", hdr)
        out = []
        for k in range(1, min(n, 64)):                    # entry 0 is the class itself
            bcd = img.u32(bca + 4 * k)
            if bcd is None:
                break
            td, mdisp = img.u32(bcd), img.u32(bcd + 8)
            name = type_name(img, td or 0)
            if name and mdisp is not None:
                out.append((plain(name), struct.unpack("<i", struct.pack("<I", mdisp))[0]))
        return out

    def class_of_function(self) -> Dict[int, str]:
        """function -> the most basic class whose primary vtable holds it."""
        holders: Dict[int, Set[str]] = defaultdict(set)
        for cls, off, slots in self.vtables.values():
            if off == 0:
                for f in slots:
                    holders[f].add(cls)
        out = {}
        for f, classes in holders.items():
            # the most basic: the one with the fewest bases
            out[f] = min(classes, key=lambda c: (len(self.bases.get(c, [])), c))
        return out


# ---------------------------------------------------------------------------- one function

MEM = re.compile(r"(?:dword ptr )?\[(\w+)(?: ?([+-]) ?(0x[0-9a-f]+|\d+))?\]$")


def _mem(op: str) -> Optional[Tuple[str, int]]:
    m = MEM.match(op.strip())
    if not m or m.group(1) not in REGS32:
        return None
    n = int(m.group(3), 0) if m.group(3) else 0
    return m.group(1), -n if m.group(2) == "-" else n


def analyse(md, img: Img, rt: Rtti, start: int, size: int, cls: Optional[str], starts: Set[int],
            td_names: Dict[int, str], dyn_cast: Optional[int] = None,
            typed: Optional[Dict[int, int]] = None) -> dict:
    """typed: {pointer global: the vtable of the class its object is proven to be} (vtypes.py)."""
    typed = typed or {}
    code = img.img.read(start, size) or b""
    ins = list(md.disasm(code, start))
    targets = {int(i.op_str, 16) for i in ins if i.mnemonic.startswith("j") and i.op_str.startswith("0x")}
    calls, virtual, globals_, casts, strings = [], [], set(), set(), set()
    unresolved = 0
    entry = {"ecx": ("this", 0)} if cls else {}
    st: Dict[str, tuple] = dict(entry)
    # a callee-saved register written once (mov esi, ecx) still holds this after a branch joins
    writes = defaultdict(int)
    for i in ins:
        d = i.op_str.split(",")[0].strip()
        if d in REGS32 and i.mnemonic not in ("push", "cmp", "test", "call"):
            writes[d] += 1
    pushed: List[Optional[int]] = []                 # the last values pushed (a type descriptor, or None)
    const: Dict[str, int] = {}                       # registers holding a type descriptor's address
    for i in ins:
        if i.address in targets:
            st = {r: v for r, v in st.items() if v[0] == "this" and r in ("ebx", "esi", "edi", "ebp")
                  and writes[r] <= 1}
        m, ops = i.mnemonic, [o.strip() for o in i.op_str.split(",")] if i.op_str else []
        if m == "push" and ops:
            v = int(ops[0], 16) if ops[0].startswith("0x") else const.get(ops[0])
            pushed.append(v if v in td_names else None)
        elif m == "mov" and len(ops) == 2 and ops[0] in REGS32:
            if ops[1].startswith("0x") and int(ops[1], 16) in td_names:
                const[ops[0]] = int(ops[1], 16)
            else:
                const.pop(ops[0], None)
        elif m == "call":
            if dyn_cast is not None and ops and ops[0] == f"0x{dyn_cast:x}" and len(pushed) >= 5:
                # pushed last to first: pointer, vfDelta, from, to, isReference
                src, dst = pushed[-3], pushed[-4]
                if src is not None and dst is not None:
                    casts.add((td_names[src], td_names[dst]))
            for r in CLOBBERED:
                const.pop(r, None)
        # constants: strings, globals, type descriptors
        for o in ops:
            for h in re.findall(r"0x[0-9a-f]{5,8}", o):
                v = int(h, 16)
                if not img.in_data(v):
                    continue
                if v in td_names:
                    if m == "push" and dyn_cast is None:
                        casts.add(td_names[v])
                elif "[" in o:
                    globals_.add(v)
                elif img.cstr(v):
                    strings.add(img.cstr(v))
                elif v not in rt.vtables:
                    globals_.add(v)
        if m == "call":
            if ops and ops[0].startswith("0x"):
                calls.append(int(ops[0], 16))
            else:
                mm = _mem(ops[0]) if ops else None
                hit = None
                if mm and mm[0] in st and st[mm[0]][0] == "vt":
                    vt, how = st[mm[0]][1], st[mm[0]][2]
                    slots = rt.vtables.get(vt, (None, 0, []))[2]
                    if mm[1] % 4 == 0 and 0 <= mm[1] // 4 < len(slots):
                        hit = (slots[mm[1] // 4], how)
                if hit:
                    virtual.append(hit)
                else:
                    unresolved += 1
            for r in CLOBBERED:
                st.pop(r, None)
            continue
        if m == "jmp" and ops and ops[0].startswith("0x"):
            t = int(ops[0], 16)
            if not (start <= t < start + size) and t in starts:
                calls.append(t)
            continue
        if m in ("push", "pop", "cmp", "test") or not ops:
            if m == "pop" and ops:
                st.pop(ops[0], None)
            continue
        dst = ops[0]
        src = ops[1] if len(ops) > 1 else None
        if m == "mov" and dst.startswith("dword ptr [") and src and src.startswith("0x"):
            mm = _mem(dst)
            v = int(src, 16)
            if mm and mm[1] == 0 and v in rt.vtables:
                st[mm[0]] = ("obj", v)                    # this object is now of that vtable's class
            continue
        if dst not in REGS32:
            continue
        new = None
        if m == "mov" and src in st:
            new = st[src]
        elif m == "lea" and src and _mem(src) and _mem(src)[0] in st and st[_mem(src)[0]][0] == "this":
            base = _mem(src)
            new = ("this", st[base[0]][1] + base[1])
        elif m == "add" and dst in st and st[dst][0] == "this" and src and re.fullmatch(r"0x[0-9a-f]+|\d+", src):
            new = ("this", st[dst][1] + int(src, 0))
        elif m == "mov" and src and _mem(src) and _mem(src)[0] in st:
            obj = st[_mem(src)[0]]
            if obj[0] == "this" and cls:
                off = obj[1] + _mem(src)[1]               # [this+N]: the vptr of the part at N
                vt = rt.of_class.get((cls, off))
                if vt is not None:
                    new = ("vt", vt, "own" if off == 0 else "base")
            elif obj[0] == "obj" and _mem(src)[1] == 0:
                new = ("vt", obj[1], obj[2] if len(obj) > 2 else "ctor")
        elif m == "mov" and src and re.fullmatch(r"dword ptr \[0x[0-9a-f]+\]", src) and \
                int(src[11:-1], 16) in typed:
            new = ("obj", typed[int(src[11:-1], 16)], "global")
        if new is None:
            st.pop(dst, None)
        else:
            st[dst] = new
    return {"calls": calls, "virtual": virtual, "unresolved": unresolved, "globals": sorted(globals_),
            "casts": sorted(casts, key=str), "strings": sorted(strings)}


# ---------------------------------------------------------------------------- the graph

def tarjan(nodes: List[int], edges: Dict[int, List[int]]) -> List[List[int]]:
    """Strongly connected components, each after the ones it calls (iterative)."""
    index, low, on, stack, out = {}, {}, set(), [], []
    counter = 0
    for root in nodes:
        if root in index:
            continue
        work = [(root, iter(edges.get(root, ())))]
        index[root] = low[root] = counter
        counter += 1
        stack.append(root)
        on.add(root)
        while work:
            v, it = work[-1]
            for w in it:
                if w not in index:
                    index[w] = low[w] = counter
                    counter += 1
                    stack.append(w)
                    on.add(w)
                    work.append((w, iter(edges.get(w, ()))))
                    break
                if w in on:
                    low[v] = min(low[v], index[w])
            else:
                work.pop()
                if work:
                    low[work[-1][0]] = min(low[work[-1][0]], low[v])
                if low[v] == index[v]:
                    comp = []
                    while True:
                        w = stack.pop()
                        on.discard(w)
                        comp.append(w)
                        if w == v:
                            break
                    out.append(sorted(comp))
    return out


def functions(b: str = "xb") -> Dict[int, int]:
    """start -> size of every function the project knows (matched and open)."""
    out = {}
    q = json.loads((ROOT / "reports" / "full_remaining_queue.json").read_text())
    for t in q:
        if t.get("bin") == b:
            out[int(t["fva_int"])] = int(t["size"])
    reg = json.loads((ROOT / "reports" / "verified_registry.json").read_text())["entries"]
    for k, e in reg.items():
        if k.startswith(b + ":"):
            out[int(e["va"], 16)] = int(e["size"])
    return out


def class_names(b: str = "xb") -> Dict[int, str]:
    """function -> class from its name (names.json first, then the registry's symbol)."""
    out = {}
    reg = json.loads((ROOT / "reports" / "verified_registry.json").read_text())["entries"]
    for k, e in reg.items():
        if k.startswith(b + ":") and "::" in (e.get("symbol") or ""):
            out[int(e["va"], 16)] = e["symbol"].rsplit("::", 1)[0]
    try:
        names = json.loads((ROOT / "reports" / "names.json").read_text())["names"]
    except (OSError, ValueError, KeyError):
        names = {}
    for k, v in names.items():
        if k.startswith(b + ":") and "::" in v["name"]:
            out[int(k.split(":")[1], 16)] = v["name"].rsplit("::", 1)[0]
    return out


def named_address(b: str, name: str) -> Optional[int]:
    """Where the function reports/names.json calls name is."""
    try:
        names = json.loads((ROOT / "reports" / "names.json").read_text())["names"]
    except (OSError, ValueError, KeyError):
        return None
    return next((int(k.split(":")[1], 16) for k, v in names.items()
                 if k.startswith(b + ":") and v.get("name") == name), None)


def dynamic_cast_address(b: str = "xb") -> Optional[int]:
    """Where __RTDynamicCast is, by its name in reports/names.json."""
    return named_address(b, "__RTDynamicCast")


def build(image, b: str = "xb") -> Tuple[dict, dict]:
    from capstone import CS_ARCH_X86, CS_MODE_32, Cs
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    img = Img(image)
    funcs = functions(b)
    starts = set(funcs)
    rt = Rtti(img, starts)
    td_names = {}
    # every type descriptor the class hierarchies name, by address, for the casts
    for lo, hi in img.raw:
        raw = img.img.read(lo, hi - lo) or b""
        for m in re.finditer(rb"\.\?A[VU][A-Za-z0-9_@?$]+@@\0", raw):
            td = lo + m.start() - 8
            td_names[td] = plain(m.group(0)[:-1].decode("latin-1"))
    by_vtable = rt.class_of_function()
    by_name = class_names(b)
    known = {c for c, _ in rt.of_class}
    # a thunk is a function that is just a jump to another
    thunk, adjust = {}, {}
    for f in funcs:
        b8 = img.img.read(f, 8) or b""
        if b8[:1] == b"\xE9":
            t = (f + 5 + struct.unpack("<i", b8[1:5])[0]) & 0xFFFFFFFF
            if t in starts and t != f:
                thunk[f] = t
        elif len(b8) == 8 and b8[:2] in (b"\x83\xE9", b"\x83\xC1") and b8[3] == 0xE9:
            t = (f + 8 + struct.unpack("<i", b8[4:8])[0]) & 0xFFFFFFFF
            n = struct.unpack("<b", b8[2:3])[0]
            delta = -n if b8[1] == 0xE9 else n                  # sub ecx,n / add ecx,n
            if t in starts and t != f and delta < 0:            # forward (+n) is a call on a member, not a thunk
                thunk[f] = t
                adjust[f] = delta
    dyn_cast = dynamic_cast_address(b)
    import vtypes
    fx = vtypes.Facts(md, img, rt, funcs, named_address(b, "OperatorDelete"))
    typed_globals, built = vtypes.all_typed_globals(fx)
    typed_vt = {g: rt.of_class[(c, 0)] for g, (c, _r, _e) in typed_globals.items() if (c, 0) in rt.of_class}

    def through(t):
        seen = set()
        while t in thunk and t not in seen:
            seen.add(t)
            t = thunk[t]
        return t

    out, strings = {}, {}
    for f, size in sorted(funcs.items()):
        if f in thunk:
            continue
        cls = by_vtable.get(f) or (by_name.get(f) if by_name.get(f) in known else None)
        a = analyse(md, img, rt, f, size, cls, starts, td_names, dyn_cast, typed_vt)
        row = {}
        calls = list(dict.fromkeys(through(t) for t in a["calls"] if t in starts and through(t) != f))
        if calls:
            row["calls"] = [f"0x{t:08X}" for t in calls]
        virt = list(dict.fromkeys((through(t), how) for t, how in a["virtual"] if t in starts))
        if virt:
            row["virtual"] = [[f"0x{t:08X}", how] for t, how in virt]
        if a["unresolved"]:
            row["unresolved"] = a["unresolved"]
        if a["globals"]:
            row["globals"] = [f"0x{g:08X}" for g in a["globals"]]
        if a["casts"]:
            row["casts"] = [list(c) if isinstance(c, tuple) else c for c in a["casts"]]
        if a["strings"]:
            row["strings"] = len(a["strings"])
            strings[f"0x{f:08X}"] = a["strings"]
        if cls:
            row["class"] = cls
        out[f"0x{f:08X}"] = row
    edges = {int(k, 16): [int(t, 16) for t in v.get("calls", [])] for k, v in out.items()}
    order = tarjan(sorted(edges), edges)
    graph = {
        "what": "Xbox call graph from the game's own instructions (portal/tools/callgraph.py): direct calls and "
                "tail jumps, the vtable calls that can be told for certain (own class, base part, just-built "
                "object), what is left unresolved, globals, dynamic_cast targets, how many strings; 'order' "
                "is the strongly connected components, leaves first.",
        "functions_seen": len(out), "thunks": {f"0x{k:08X}": f"0x{through(k):08X}" for k in sorted(thunk)},
        "adjustors": {f"0x{k:08X}": [f"0x{thunk[k]:08X}", adjust[k]] for k in sorted(adjust)},
        "casts": sum(len(v.get("casts", [])) for v in out.values()),
        "vtables": len(rt.vtables), "classes": len(rt.bases),
        "edges_direct": sum(len(v.get("calls", [])) for v in out.values()),
        "edges_virtual": {how: sum(1 for v in out.values() for _, h in v.get("virtual", []) if h == how)
                          for how in ("own", "base", "ctor", "global")},
        "instantiated_classes": len(built),
        "typed_globals": {f"0x{g:08X}": {"class": c, "rule": r, "evidence": e}
                          for g, (c, r, e) in sorted(typed_globals.items())},
        "unresolved": sum(v.get("unresolved", 0) for v in out.values()),
        "functions": out,
        "order": [[f"0x{f:08X}" for f in comp] for comp in order],
    }
    return graph, strings


def write(graph: dict, path: Path) -> None:
    """One function (and one component) per line."""
    head = {k: v for k, v in graph.items() if k not in ("functions", "order", "thunks", "adjustors", "typed_globals")}
    text = json.dumps(head, indent=1)[:-2] + ",\n"
    text += ' "thunks": ' + json.dumps(graph["thunks"]) + ",\n"
    text += ' "adjustors": ' + json.dumps(graph.get("adjustors", {})) + ",\n"
    text += ' "typed_globals": {\n' + ",\n".join(f"  {json.dumps(k)}: {json.dumps(v)}"
                                                  for k, v in graph.get("typed_globals", {}).items()) + "\n },\n"
    text += ' "functions": {\n' + ",\n".join(f" {json.dumps(k)}: {json.dumps(v)}" for k, v in graph["functions"].items())
    text += "\n },\n \"order\": [\n" + ",\n".join(" " + json.dumps(c) for c in graph["order"]) + "\n ]\n}\n"
    path.write_text(text, newline="\n")


def load(path: Optional[Path] = None) -> dict:
    try:
        return json.loads((path or ROOT / "reports" / "callgraph_xb.json").read_text())
    except (OSError, ValueError):
        return {}


def rank(graph: dict) -> Dict[str, int]:
    """function -> its place in the leaves-first order (functions in one cycle share a place)."""
    return {f: n for n, comp in enumerate(graph.get("order", [])) for f in comp}


def main(argv=None) -> int:
    import argparse
    ap = argparse.ArgumentParser(description="Build the Xbox call graph from your own default.xbe.")
    ap.add_argument("--out", type=Path, default=ROOT / "reports" / "callgraph_xb.json")
    ap.add_argument("--strings", action="store_true",
                    help="also write work/callgraph_xb_strings.json: the text each function uses (your copy only)")
    a = ap.parse_args(argv)
    sys.path.insert(0, str(ROOT / "portal"))
    import agent
    graph, strings = build(agent.image("xb"))
    write(graph, a.out)
    if a.strings:
        p = ROOT / "work" / "callgraph_xb_strings.json"
        p.parent.mkdir(exist_ok=True)
        p.write_text(json.dumps(strings, indent=0, ensure_ascii=False))
    print(f"{graph['functions_seen']:,} functions, {graph['edges_direct']:,} direct calls, virtual "
          f"{graph['edges_virtual']}, {graph['unresolved']:,} unresolved, {graph['vtables']:,} vtables "
          f"-> {a.out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
