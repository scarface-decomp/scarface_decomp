#!/usr/bin/env python3
"""One declaration per class, merged from what each matched function declares (docs/ROADMAP.md step 3).

Every matched function carries its own copy of its class, holding only what that function uses. This
module reads those copies and merges them:

    parse_class(code, symbol)   the class a function declares for itself: members with their offsets,
                                virtual functions by slot, other member functions
    merge(decls)                one class from several copies, and where they disagree
    render(merged)              the merged class as C++
    with_class(code, decl, merged)   a function's code with its own copy replaced by the merged class

Nothing here proves anything. A merged class is accepted only when every function of the class still
compiles to the game's bytes with it (portal/scripts/merge_classes.py does that with the real compiler).
The parser reads the plain declarations the portal's starter code writes, which nearly all matched code
keeps; a class it can't read (a base class, a template, a member that is another object) is reported
and left alone.

Standard library only.
"""

from __future__ import annotations

import re
from collections import Counter, defaultdict
from typing import Dict, List, Optional, Tuple

SIZES = {"char": 1, "bool": 1, "unsigned char": 1, "__int8": 1, "short": 2, "unsigned short": 2, "wchar_t": 2,
         "int": 4, "unsigned int": 4, "unsigned": 4, "long": 4, "unsigned long": 4, "float": 4,
         "double": 8, "__int64": 8, "unsigned __int64": 8}
PACK = 4                                    # /Zp4: nothing is aligned to more than 4 bytes
PLACEHOLDER = re.compile(r"^(m_Field|m_pad|vfunc_|sub_|m_)[0-9A-Fa-f_]*(bit\d)?$")


class Unreadable(Exception):
    """This class declaration is outside what the parser reads; the message says why."""


class Member:
    def __init__(self, off: int, size: int, ctype: str, name: str, count: Optional[int] = None,
                 bit: Optional[int] = None, width: Optional[int] = None):
        self.off, self.size, self.ctype, self.name = off, size, ctype, name
        self.count, self.bit, self.width = count, bit, width

    @property
    def key(self):
        return (self.off, self.bit)

    def decl(self, name: Optional[str] = None) -> str:
        name = self.name if name is None else name
        if self.bit is not None:
            return f"{self.ctype} {name} : {self.width};"
        return f"{self.ctype} {name}{f'[0x{self.count:X}]' if self.count is not None else ''};"


class Method:
    def __init__(self, name: str, ret: str, params: str, tail: str = ""):
        self.name, self.ret, self.params, self.tail = name, ret, params, tail

    @property
    def sig(self):
        return (self.ret, norm_params(self.params), self.tail)

    def decl(self, virtual: bool = False, name: Optional[str] = None) -> str:
        return f"{'virtual ' if virtual else ''}{self.ret} {name or self.name}({self.params}){self.tail};"


class ClassDecl:
    def __init__(self):
        self.name = ""                       # the class's own name, without namespaces
        self.keyword = "class"
        self.start = self.end = 0            # where the declaration sits in the code (through its `;`)
        self.members: List[Member] = []      # data members that are not padding
        self.virtuals: List[Method] = []     # by slot
        self.methods: List[Method] = []
        self.own = ""                        # the member function this code defines
        self.size = 0


def strip_comments(text: str) -> str:
    """text with comments blanked out (same length, so positions still line up)."""
    def blank(m):
        return re.sub(r"[^\n]", " ", m.group(0))
    return re.sub(r"//[^\n]*|/\*.*?\*/", blank, text, flags=re.S)


def norm_params(params: str) -> Tuple[str, ...]:
    """Parameter types without their names: ('int', 'float') for `int a1, float a2`."""
    params = params.strip()
    if params in ("", "void"):
        return ()
    out = []
    for p in params.split(","):
        p = re.sub(r"\s+", " ", p.strip())
        m = re.match(r"^(.*?[\w\*&>])\s+(\w+)$", p)
        if m and m.group(2) not in SIZES and m.group(2) not in ("int", "char", "long", "short", "unsigned"):
            p = m.group(1)
        out.append(p.replace(" *", "*").replace(" &", "&"))
    return tuple(out)


def split_class(symbol: str) -> Tuple[List[str], str, str]:
    """(namespaces, class name, member name) of `pure3d::d3dContext::vfunc_04`. Raises Unreadable
    for a symbol that is not a plain member of a plain class."""
    if "<" in symbol:
        raise Unreadable("template")
    parts = symbol.split("::")
    if len(parts) < 2:
        raise Unreadable("not a member function")
    return parts[:-2], parts[-2], parts[-1]


def type_size(ctype: str) -> int:
    t = re.sub(r"\b(const|volatile|signed|struct|class)\b", "", ctype)
    t = re.sub(r"\s+", " ", t).strip()
    if "*" in t:
        return 4
    if t not in SIZES:
        raise Unreadable(f"a member of type {ctype.strip()}")
    return SIZES[t]


def parse_class(code: str, symbol: str) -> ClassDecl:
    """The class `symbol` belongs to, as this code declares it. Raises Unreadable."""
    _ns, name, own = split_class(symbol)
    text = strip_comments(code)
    m = None
    for m in re.finditer(r"\b(class|struct)\s+" + re.escape(name) + r"\b\s*([^;{(]*)\{", text):
        break
    if m is None:
        raise Unreadable("no declaration of the class")
    if m.group(2).strip():
        raise Unreadable("a base class")
    if re.search(r"template\s*<[^;{}]*>\s*$", text[:m.start()]):
        raise Unreadable("template")
    depth, k = 1, m.end()
    while depth and k < len(text):
        depth += {"{": 1, "}": -1}.get(text[k], 0)
        k += 1
    if depth:
        raise Unreadable("unbalanced braces")
    body = text[m.end():k - 1]
    end = re.match(r"\s*;", text[k:])
    if not end or "{" in body:
        raise Unreadable("something nested in the class")
    d = ClassDecl()
    d.name, d.keyword, d.own = name, m.group(1), own
    d.start, d.end = m.start(), k + end.end()

    pos = 0                                  # next free byte
    unit = None                              # the bitfield unit being filled: [offset, size, bits used]
    for stmt in body.split(";"):
        stmt = re.sub(r"\b(public|private|protected)\s*:", " ", stmt)
        stmt = re.sub(r"\s+", " ", stmt).strip()
        if not stmt:
            continue
        if "(" in stmt:
            fm = re.match(r"^(virtual )?(static )?(.+?[\s\*&])(~?\w+) ?\((.*)\) ?(const)?( ?= ?0)?$", stmt)
            if not fm or fm.group(2) or "(" in fm.group(3) or fm.group(4).startswith("~"):
                raise Unreadable(f"a member the parser does not read: {stmt[:40]}")
            meth = Method(fm.group(4), fm.group(3).strip(), fm.group(5).strip(), " const" if fm.group(6) else "")
            if fm.group(1):
                if not d.virtuals and pos:
                    raise Unreadable("virtual functions after data members")
                d.virtuals.append(meth)
                pos = max(pos, 4)
            else:
                d.methods.append(meth)
            continue
        if re.match(r"^(typedef|enum|friend|static|using|union)\b", stmt):
            raise Unreadable(f"a member the parser does not read: {stmt[:40]}")
        dm = re.match(r"^(.+?[\s\*])(\w+)? ?(?:\[ ?(\w+) ?\])? ?(?:: ?(\d+))?$", stmt + ("" if " " in stmt else " "))
        if not dm:
            raise Unreadable(f"a member the parser does not read: {stmt[:40]}")
        ctype, mname, count, bits = dm.group(1).strip(), dm.group(2) or "", dm.group(3), dm.group(4)
        if ctype in ("unsigned", "signed", "const") and mname in ("char", "short", "int", "long"):
            ctype, mname = f"{ctype} {mname}", ""          # `unsigned char : 3;` (unnamed filler bits)
        size = type_size(ctype)
        align = min(size, PACK)
        if bits is not None:
            width = int(bits)
            if count is not None or width > size * 8:
                raise Unreadable("a bitfield the parser does not read")
            if unit is None or unit[1] != size or unit[2] + width > size * 8 or width == 0:
                pos = (pos + align - 1) // align * align
                unit = [pos, size, 0]
                pos += size
            if mname:
                d.members.append(Member(unit[0] + unit[2] // 8, 1, ctype, mname, bit=unit[2] % 8, width=width)
                                 if size == 1 else Member(unit[0], size, ctype, mname, bit=unit[2], width=width))
            unit[2] += width
            continue
        unit = None
        n = None
        if count is not None:
            try:
                n = int(count, 0)
            except ValueError:
                raise Unreadable("an array whose size is a name")
        pos = (pos + align - 1) // align * align
        total = size * (n if n is not None else 1)
        if not re.match(r"^_?m?_?pad", mname, re.I) and mname:
            d.members.append(Member(pos, total, ctype, mname, count=n))
        pos += total
    d.size = pos
    return d


def placeholder(name: str) -> bool:
    """True for a stand-in name (m_Field1C, vfunc_07, sub_00123456): one that says where, not what."""
    return bool(PLACEHOLDER.match(name))


class Merged:
    def __init__(self, namespaces: List[str], name: str):
        self.namespaces, self.name = namespaces, name
        self.keyword = "class"
        self.members: List[Member] = []
        self.virtuals: List[Method] = []
        self.methods: List[Method] = []
        self.notes: List[str] = []           # choices made between copies that disagreed
        self.conflicts: List[str] = []       # disagreements that stop the merge
        self.renames: Dict[int, Dict[str, str]] = {}    # copy index -> {its name: the merged name}


def _pick(options: Counter) -> str:
    """The most used option; a real name or type beats a stand-in, then the alphabetically first."""
    return sorted(options, key=lambda o: (-options[o], o))[0]


def merge(decls: List[ClassDecl], namespaces: List[str]) -> Merged:
    """One class from the copies in decls (all of the same class). Where copies only differ by one
    being more specific, the specific one is taken and noted; where they can't both be right, the
    conflict is listed and the class should not be used."""
    mg = Merged(namespaces, decls[0].name)
    mg.keyword = "struct" if all(d.keyword == "struct" for d in decls) else "class"
    mg.renames = {i: {} for i in range(len(decls))}

    # Virtual functions, by slot. A function knows its own signature; the other copies usually hold
    # a `virtual void vfunc_NN();` stand-in there, or the signature they call it with.
    slots: Dict[int, List[Tuple[int, Method, bool]]] = defaultdict(list)
    for i, d in enumerate(decls):
        for pos, v in enumerate(d.virtuals):
            num = re.match(r"^vfunc_(\d+)$", v.name)
            own = v.name == d.own
            if num and int(num.group(1)) != pos:
                if not own:
                    mg.conflicts.append(f"virtual {v.name} is declared at slot {pos} by {d.own}")
                    continue
                pos = int(num.group(1))                    # its own slot is in its name; the copy is short
            slots[pos].append((i, v, own))
    for pos in range(max(slots) + 1 if slots else 0):
        cands = slots.get(pos, [])
        stand_in = Method(f"vfunc_{pos:02d}", "void", "")
        real = [(i, v, own) for i, v, own in cands if not (v.sig == stand_in.sig and placeholder(v.name))]
        owners = [(i, v) for i, v, own in real if own]
        if not real:
            mg.virtuals.append(stand_in)
            continue
        sigs = Counter(v.sig for _i, v, _o in real)
        chosen = owners[0][1] if owners else next(v for _i, v, _o in real if v.sig == _pick(Counter({s: n for s, n in sigs.items()})))
        if len({v.sig for _i, v in owners}) > 1:
            mg.conflicts.append(f"slot {pos} is defined with two signatures")
        elif len(sigs) > 1:
            mg.notes.append(f"slot {pos}: copies disagree on the signature; took `{chosen.decl(True)}`")
        names = Counter(v.name for _i, v, _o in real if not placeholder(v.name))
        name = _pick(names) if names else f"vfunc_{pos:02d}"
        if len(names) > 1:
            mg.notes.append(f"slot {pos}: several names ({', '.join(sorted(names))}); took {name}")
        mg.virtuals.append(Method(name, chosen.ret, chosen.params, chosen.tail))
        for i, v, _o in cands:
            if v.name != name:
                mg.renames[i][v.name] = name

    # Other member functions: every one any copy declares. Same name and parameters twice is one
    # function; if the copies disagree on what it returns, the one that returns something is kept.
    seen: Dict[Tuple[str, Tuple[str, ...], str], Method] = {}
    for d in decls:
        for f in d.methods:
            key = (f.name, norm_params(f.params), f.tail)
            old = seen.get(key)
            if old is None:
                seen[key] = f
            elif old.ret != f.ret:
                if "void" in (old.ret, f.ret):
                    seen[key] = f if old.ret == "void" else old
                    mg.notes.append(f"{f.name}: void in one copy, {seen[key].ret} in another; took {seen[key].ret}")
                else:
                    mg.conflicts.append(f"{f.name} returns {old.ret} in one copy and {f.ret} in another")
    mg.methods = sorted(seen.values(), key=lambda f: (f.name, norm_params(f.params)))

    # Data members, by offset.
    at: Dict[Tuple[int, Optional[int]], List[Tuple[int, Member]]] = defaultdict(list)
    for i, d in enumerate(decls):
        for mb in d.members:
            at[mb.key].append((i, mb))
    for key in sorted(at, key=lambda k: (k[0], -1 if k[1] is None else k[1])):
        group = at[key]
        shapes = Counter((mb.size, mb.count, mb.width) for _i, mb in group)
        if len(shapes) > 1:
            mg.conflicts.append(f"+0x{key[0]:X}: copies disagree on its size "
                                f"({', '.join(sorted({mb.decl() for _i, mb in group}))})")
            continue
        types = Counter(mb.ctype for _i, mb in group)
        ctype = _pick(types)
        if len(types) > 1:
            mg.notes.append(f"+0x{key[0]:X}: declared as {', '.join(sorted(types))}; took {ctype}")
        names = Counter(mb.name for _i, mb in group if not placeholder(mb.name))
        first = group[0][1]
        name = _pick(names) if names else first.name
        if len(names) > 1:
            mg.notes.append(f"+0x{key[0]:X}: several names ({', '.join(sorted(names))}); took {name}")
        mg.members.append(Member(first.off, first.size, ctype, name, first.count, first.bit, first.width))
        for i, mb in group:
            if mb.name != name:
                mg.renames[i][mb.name] = name
    last_end, last = 0, None
    for mb in mg.members:
        if mb.bit is None and mb.off < last_end:
            mg.conflicts.append(f"+0x{mb.off:X} {mb.name} overlaps +0x{last.off:X} {last.name}")
        if mb.bit is None or last is None or last.off != mb.off:
            if mb.bit is not None and mb.off < last_end:
                mg.conflicts.append(f"+0x{mb.off:X}: used as single bits and as a whole")
        if mb.off + mb.size > last_end:
            last_end, last = mb.off + mb.size, mb
    names = Counter(mb.name for mb in mg.members)
    for name, n in names.items():
        if n > 1:
            mg.conflicts.append(f"two members are named {name}")
    return mg


BUILT_IN = {"void", "const", "volatile", "signed", "unsigned", "struct", "class", "char", "bool", "short", "int",
            "long", "float", "double", "wchar_t", "__int8", "__int16", "__int32", "__int64"}


def other_types(mg: Merged) -> List[str]:
    """Plain type names the merged class mentions (a member that points at one, a parameter). A copy
    that does not use such a member has no declaration of its type, so the class declares them first."""
    found = set()
    texts = [mb.ctype for mb in mg.members]
    for f in mg.virtuals + mg.methods:
        texts += [f.ret] + list(norm_params(f.params))
    for text in texts:
        if "::" in text or "<" in text or "(" in text:
            continue
        found |= {w for w in re.findall(r"[A-Za-z_]\w*", text) if w not in BUILT_IN and w != mg.name}
    return sorted(found)


def render(mg: Merged, indent: str = "") -> str:
    """The merged class as C++, after forward declarations of the types it points at (no namespaces
    around it)."""
    out = [f"{indent}class {t};" for t in other_types(mg)]
    out += [f"{indent}{mg.keyword} {mg.name}", f"{indent}{{", f"{indent}public:"]
    for v in mg.virtuals:
        out.append(f"{indent}    {v.decl(True)}")
    for f in mg.methods:
        out.append(f"{indent}    {f.decl()}")
    pos = 4 if mg.virtuals else 0
    k = 0
    members = mg.members
    while k < len(members):
        mb = members[k]
        if mb.off > pos:
            out.append(f"{indent}    char m_pad{pos:02X}[0x{mb.off - pos:X}];")
        if mb.bit is None:
            out.append(f"{indent}    {mb.decl()} // +0x{mb.off:02X}")
            pos = mb.off + mb.size
            k += 1
            continue
        bit = 0                                           # the bits of one storage unit, lowest first
        size = type_size(mb.ctype)
        while k < len(members) and members[k].off == mb.off and members[k].bit is not None:
            b = members[k]
            if b.bit > bit:
                out.append(f"{indent}    {b.ctype} : {b.bit - bit};")
            out.append(f"{indent}    {b.decl()} // +0x{b.off:02X}, bit {b.bit}")
            bit = b.bit + b.width
            k += 1
        pos = mb.off + size
    out.append(f"{indent}}};")
    return "\n".join(out)


def with_class(code: str, decl: ClassDecl, mg: Merged, index: int) -> str:
    """code with its own copy of the class (decl, copy number index of the merge) replaced by the
    merged class, and its own names for members replaced by the merged names."""
    line_start = code.rfind("\n", 0, decl.start) + 1
    indent = code[line_start:decl.start] if not code[line_start:decl.start].strip() else ""
    head, tail = code[:decl.start], code[decl.end:]
    for old, new in mg.renames.get(index, {}).items():
        tail = re.sub(r"\b" + re.escape(old) + r"\b", new, tail)
    return head + render(mg, indent).lstrip() + tail
