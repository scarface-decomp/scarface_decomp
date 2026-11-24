#!/usr/bin/env python3
"""
The game's typed script commands: script names bound straight to the classes' own C++ functions.

script_commands.py reads the commands whose handler takes its arguments as text. The game has a second
way to register a command (the examiner's round Q4-Q13 found it): a small object, CScript::MethodN<...>
or CScript::FunctionN<...>, holds a pointer to the real C++ function, and the object's own class name in
the program's run-time type information spells out that function's whole signature:

    .?AV?$Method5@X_NW4EMeleeAttackType@CharacterObject@@H_NPBD@CScript@@
      = void (bool, CharacterObject::EMeleeAttackType, int, bool, const char*)

The start-up code registers each one through a helper per signature:

    push  ""                         (not used)
    push  most arguments
    push  fewest arguments
    [push 0                           a this adjustment, for some helpers]
    push  the C++ function            <- what this module is after
    push  ""                         (the help text; always empty)
    push  "TheCommandName"
    [push "TheClass"                  for a method, or a plain function registered for a class]
    call  the helper for that signature

So the program itself says: this address is CharacterObject::SetIsMeleeAttacking, and these are its
return and argument types. This also reads the two kinds of text-argument handlers that only pass the
call on: `mov ecx,[esp+4]; jmp F` (F is the class's method of that name) and
`mov ecx,[esp+4]; mov eax,[ecx]; jmp [eax+N]` (the command is that virtual function of the class), and the
default argument values the start-up code installs on some typed commands right after registering them
(found again by class and name, FindTypedFunctor; a small allocation per argument, stored in the binding
object's table at +4).

    python portal/tools/script_typed.py                  what it finds in binaries/
    python portal/tools/script_typed.py --write          add the names to reports/names.json
    python portal/tools/script_typed.py --json           reports/script_typed_bindings.json
    python portal/tools/script_typed.py --starts         put the functions it found that the work queue
                                                         lacks into reports/extra_function_starts.json

Addresses, names and types only: nothing from the game's files is written anywhere.
"""
from __future__ import annotations

import argparse
import bisect
import json
import re
import struct
import sys
from pathlib import Path
from typing import Dict, List, Optional, Tuple

HERE = Path(__file__).resolve().parent
if str(HERE) not in sys.path:
    sys.path.insert(0, str(HERE))

import names as NAMES  # noqa: E402
import registry_outputs as RO  # noqa: E402
import script_commands as SC  # noqa: E402
from sf_binaries import BinaryImage  # noqa: E402

ROOT = HERE.parent.parent
BY = "the game's own typed script binding (portal/tools/script_typed.py)"
BY_FORWARD = "the game's own script command table: the handler only passes the call on (portal/tools/script_typed.py)"
FUNCTOR = re.compile(rb"\.\?AV\?\$(Method|Function)(\d+)@([A-Za-z0-9_@?$]+?)@CScript@@\0")
REGS = ("eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi")


# ---------------------------------------------------------------------------- the signature in a type name

class BadType(ValueError):
    pass


def signature(kind: str, count: int, body: str) -> Tuple[str, List[str]]:
    """(return type, [argument types]) from the template arguments of a functor's decorated class name.
    Names seen are numbered for back references, the template's own name being 0."""
    seen = [f"{kind}{count}"]
    pos = 0

    def name() -> str:
        nonlocal pos
        parts = []
        while True:
            if pos >= len(body):
                raise BadType(body)
            ch = body[pos]
            if ch == "@":
                pos += 1
                break
            if ch.isdigit():
                pos += 1
                if int(ch) >= len(seen):
                    raise BadType(body)
                parts.append(seen[int(ch)])
                continue
            end = body.find("@", pos)
            if end < 0:
                raise BadType(body)
            part = body[pos:end]
            pos = end + 1
            if not re.fullmatch(r"[A-Za-z_]\w*", part):
                raise BadType(body)
            if len(seen) < 10:
                seen.append(part)
            parts.append(part)
        return "::".join(reversed(parts))

    def one() -> str:
        nonlocal pos
        if pos >= len(body):
            raise BadType(body)
        ch = body[pos]
        pos += 1
        simple = {"X": "void", "D": "char", "E": "unsigned char", "F": "short", "G": "unsigned short", "H": "int",
                  "I": "unsigned int", "J": "long", "K": "unsigned long", "M": "float", "N": "double"}
        if ch in simple:
            return simple[ch]
        if ch == "_":
            ch2 = body[pos]
            pos += 1
            if ch2 == "N":
                return "bool"
            raise BadType(body)
        if ch in "PA":                               # pointer / reference: A = plain, B = const
            cv = body[pos]
            pos += 1
            if cv not in "AB":
                raise BadType(body)
            inner = one()
            return ("const " if cv == "B" else "") + inner + ("*" if ch == "P" else "&")
        if ch in "VU":                               # class / struct
            return name()
        if ch == "W":                                # enum (W4 = int-sized)
            pos += 1
            return name()
        raise BadType(body)

    types = []
    while pos < len(body):
        types.append(one())
    if len(types) != count + 1:
        raise BadType(f"{body}: {len(types) - 1} argument types for {kind}{count}")
    return types[0], types[1:]


# ---------------------------------------------------------------------------- reading the image

class Image:
    def __init__(self, img: BinaryImage, functions: Dict[int, dict]):
        self.img = img
        self.starts = sorted(functions)
        self.sizes = {a: int(f["size"]) for a, f in functions.items()}
        self.symbols = {a: str(f.get("symbol", "")) for a, f in functions.items()}

    def u32(self, va: int) -> Optional[int]:
        b = self.img.read(va, 4)
        return struct.unpack("<I", b)[0] if b and len(b) == 4 else None

    def game_code(self, va: Optional[int]) -> bool:
        s = self.img.section_of(va) if va is not None else None
        return bool(s and s.is_code and not s.library)

    def data(self, va: Optional[int]) -> bool:
        s = self.img.section_of(va) if va is not None else None
        return bool(s and not s.is_code)

    def text(self, va: int) -> Optional[str]:
        """A zero-ended ASCII string at va ("" included)."""
        if not self.data(va):
            return None
        off = self.img.va_to_off(va)
        if off is None:
            return None
        end = self.img.data.find(b"\0", off, off + 96)
        if end < off:
            return None
        try:
            return self.img.data[off:end].decode("ascii")
        except UnicodeDecodeError:
            return None

    def function_at(self, va: int) -> Optional[int]:
        i = bisect.bisect_right(self.starts, va) - 1
        if i < 0:
            return None
        s = self.starts[i]
        return s if va < s + self.sizes[s] else None

    def run_holding(self, va: int, most: int = 0x6000) -> Optional[Tuple[int, int]]:
        """(start, size) of the code va is in: its function, or, for start-up code the function list
        doesn't have, the stretch from the end of the function before it up to the next one."""
        f = self.function_at(va)
        if f is not None:
            return f, self.sizes[f]
        i = bisect.bisect_right(self.starts, va) - 1
        if i < 0:
            return None
        start = self.starts[i] + self.sizes[self.starts[i]]
        end = self.starts[i + 1] if i + 1 < len(self.starts) else va + 16
        return (start, end - start) if va - start <= most else None

    def data_sections(self):
        for s in self.img.sections:
            if not s.is_code:
                n = min(s.vsize, s.raw_size)
                yield s.va, self.img.data[s.raw:s.raw + n]

    def code_sections(self):
        for s in self.img.game_code_sections():
            yield s.va, self.img.data[s.raw:s.raw + s.raw_size]


def functor_vtables(im: Image) -> Dict[int, dict]:
    """{vtable: {kind, count, td, ret, args, invoke}} for every CScript::MethodN / FunctionN class."""
    datas = list(im.data_sections())
    tds = {}
    for base, raw in datas:
        for m in FUNCTOR.finditer(raw):
            tds[base + m.start() - 8] = m
    out = {}
    for base, raw in datas:
        for td, m in tds.items():
            want = struct.pack("<I", td)
            at = raw.find(want)
            while at >= 0:
                col = base + at - 12
                if at >= 12 and at % 4 == 0 and raw[at - 12:at - 8] == b"\0\0\0\0":
                    ref = struct.pack("<I", col)
                    for b2, r2 in datas:
                        p = r2.find(ref)
                        while p >= 0:
                            if p % 4 == 0:
                                vt = b2 + p + 4
                                kind, count = m.group(1).decode(), int(m.group(2))
                                try:
                                    ret, args = signature(kind, count, m.group(3).decode("ascii"))
                                except BadType:
                                    ret, args = None, None
                                out[vt] = {"kind": kind, "count": count, "td": m.group(0)[:-1].decode("ascii"),
                                           "ret": ret, "args": args, "invoke": im.u32(vt)}
                            p = r2.find(ref, p + 1)
                at = raw.find(want, at + 1)
    return out


def helpers(im: Image, vtables: Dict[int, dict]) -> Dict[int, int]:
    """{helper function: functor vtable}: the functions that store a functor's vtable into a new object."""
    out = {}
    for base, code in im.code_sections():
        for vt in vtables:
            want = struct.pack("<I", vt)
            at = code.find(want)
            while at >= 0:
                if at >= 2 and code[at - 2] == 0xC7 and code[at - 1] in (0x00, 0x01, 0x02, 0x03, 0x06, 0x07):
                    f = im.function_at(base + at)
                    if f is not None:
                        out[f] = vt
                at = code.find(want, at + 1)
    return out


def _calls_to(im: Image, targets) -> List[Tuple[int, int]]:
    """[(call address, target)] for every direct call to one of targets."""
    targets = set(targets)
    out = []
    for base, code in im.code_sections():
        at = code.find(b"\xE8")
        while at >= 0 and at + 5 <= len(code):
            t = (base + at + 5 + struct.unpack_from("<i", code, at + 1)[0]) & 0xFFFFFFFF
            if t in targets:
                out.append((base + at, t))
            at = code.find(b"\xE8", at + 1)
    return out


def pushes_before(im: Image, md, sites: List[int]) -> Dict[int, List[Optional[int]]]:
    """{call site: the values pushed before it, last first}, following constants through registers from the
    start of the function the site is in."""
    by_fn: Dict[Tuple[int, int], List[int]] = {}
    for s in sites:
        run = im.run_holding(s)
        if run is not None:
            by_fn.setdefault(run, []).append(s)
    out = {}
    for (f, size), wanted in by_fn.items():
        wanted = set(wanted)
        reg: Dict[str, int] = {}
        stack: List[Optional[int]] = []
        for i in md.disasm(im.img.read(f, size) or b"", f):
            if i.mnemonic == "int3":                     # padding between functions: a new one starts
                reg, stack = {}, []
                continue
            if i.address in wanted:
                out[i.address] = stack[::-1][:10]
            m, ops = i.mnemonic, [o.strip() for o in i.op_str.split(",")] if i.op_str else []
            if m == "push" and ops:
                o = ops[0]
                stack.append(int(o, 16) if o.startswith("0x") else int(o) if o.isdigit() else reg.get(o))
            elif m == "call":
                for r in ("eax", "ecx", "edx"):
                    reg.pop(r, None)
            elif m == "mov" and len(ops) == 2 and ops[0] in REGS:
                if re.fullmatch(r"0x[0-9a-f]+|\d+", ops[1]):
                    reg[ops[0]] = int(ops[1], 0)
                elif ops[1] in reg:
                    reg[ops[0]] = reg[ops[1]]
                else:
                    reg.pop(ops[0], None)
            elif m in ("xor", "sub") and len(ops) == 2 and ops[0] == ops[1] and ops[0] in REGS:
                reg[ops[0]] = 0
            elif m == "add" and ops and ops[0] == "esp" and len(ops) == 2 and re.fullmatch(r"0x[0-9a-f]+|\d+", ops[1]):
                n = int(ops[1], 0) // 4
                del stack[max(0, len(stack) - n):]
            elif ops and ops[0] in REGS and m not in ("cmp", "test"):
                reg.pop(ops[0], None)
    return out


def find(img: BinaryImage, functions: Dict[int, dict]) -> Tuple[List[dict], List[str]]:
    """(every typed registration, problems): rows {at, kind, cls, name, fn, fewest, most, ret, args, ...}."""
    from capstone import CS_ARCH_X86, CS_MODE_32, Cs
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    im = Image(img, functions)
    vts = functor_vtables(im)
    hs = helpers(im, vts)
    calls = _calls_to(im, hs)
    pushed = pushes_before(im, md, [c for c, _ in calls])
    rows, problems = [], []
    for site, helper in sorted(calls):
        v = vts[hs[helper]]
        a = pushed.get(site)
        where = f"0x{site:08X}"
        if a is None:
            problems.append(f"{where}: not inside a known function")
            continue
        lead = 3 if v["kind"] == "Method" else 2            # [class,] name, help text come before the function
        if lead == 2 and len(a) > 3 and not im.game_code(a[2]) and im.game_code(a[3]):
            lead = 3                                         # a plain function registered in a class's namespace
        if len(a) < lead + 4 or any(x is None for x in a[:lead + 1]):
            problems.append(f"{where}: a pushed value could not be followed")
            continue
        cls = im.text(a[0]) if lead == 3 else ""
        name, usage, fn = im.text(a[lead - 2]), im.text(a[lead - 1]), a[lead]
        rest = a[lead + 1:]
        adjust = None
        if len(rest) >= 4 and rest[0] is not None and not im.data(rest[2]) and im.data(rest[3]):
            adjust, rest = rest[0], rest[1:]
        if not im.data(rest[2] if len(rest) > 2 else None) or rest[0] is None or rest[1] is None:
            problems.append(f"{where}: the argument counts are not where expected")
            continue
        fewest, most = rest[0], rest[1]
        if not cls and lead == 3 or name is None or not SC.IDENT.match(name) or \
                (cls and not SC.IDENT.match(cls)) or usage is None or not im.game_code(fn) or \
                fewest > most or most > 64 or v["ret"] is None:
            problems.append(f"{where}: does not read as a registration (class {cls!r}, name {name!r})")
            continue
        if usage or adjust:
            problems.append(f"{where}: {cls}::{name} has help text {usage!r} or a this adjustment {adjust!r}; "
                            "check its argument order by hand")
            continue
        rows.append({"at": site, "kind": v["kind"], "cls": cls, "name": name, "fn": fn, "fewest": fewest,
                     "most": most, "ret": v["ret"], "args": v["args"], "functor": v["td"],
                     "functor_vtable": hs[helper], "invoke": v["invoke"], "helper": helper})
    return rows, problems


def prototype(r: dict) -> str:
    q = f"{r['cls']}::" if r["cls"] else ""
    return f"{r['ret']} {q}{r['name']}({', '.join(r['args'])})"


# ---------------------------------------------------------------------------- default arguments

def find_functor_lookup(im: Image, functions: Dict[int, dict]) -> Optional[int]:
    """The function that finds a typed command's binding object by class and name (FindTypedFunctor):
    by its name in reports/names.json, else the function called right after registrations whose result's
    +8 byte (the argument count) is compared at once."""
    try:
        names = json.loads((ROOT / "reports" / "names.json").read_text(encoding="utf-8"))["names"]
    except (OSError, ValueError, KeyError):
        names = {}
    for k, v in names.items():
        if v.get("name") == "FindTypedFunctor" and k.split(":")[0] in ("xb", "proto"):
            va = int(k.split(":")[1], 16)
            if va in functions:
                return va
    seen: Dict[int, int] = {}
    for base, code in im.code_sections():
        at = code.find(b"\x80\x7E\x08")                     # cmp byte ptr [esi+8], N
        while at >= 0:
            # ... call F; mov esi, eax; add esp, 8; test esi, esi; je ..; cmp byte [esi+8], N
            for back in range(14, 22):
                p = at - back
                if p >= 0 and code[p] == 0xE8 and code[p + 5:p + 7] == b"\x8B\xF0":
                    t = (base + p + 5 + struct.unpack_from("<i", code, p + 1)[0]) & 0xFFFFFFFF
                    if t in functions:
                        seen[t] = seen.get(t, 0) + 1
            at = code.find(b"\x80\x7E\x08", at + 1)
    best = max(seen.items(), key=lambda kv: kv[1], default=(None, 0))
    return best[0] if best[1] >= 3 else None


def defaults(img: BinaryImage, functions: Dict[int, dict]) -> List[dict]:
    """[{at, cls, name, arg, value, text}] for the default argument values the start-up code installs on a
    typed command right after registering it: FindTypedFunctor(class, name), then for each argument k a
    small allocation whose value is stored and put in the binding object's table (+4) at k * 4."""
    from capstone import CS_ARCH_X86, CS_MODE_32, Cs
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    im = Image(img, functions)
    look = find_functor_lookup(im, functions)
    if look is None:
        return []
    sites = [c for c, _ in _calls_to(im, [look])]
    pushed = pushes_before(im, md, sites)
    out = []
    for site in sorted(sites):
        a = pushed.get(site) or []
        if len(a) < 2 or a[0] is None or a[1] is None:
            continue
        cls, name = (im.text(a[0]) if a[0] else ""), im.text(a[1])
        if name is None or cls is None:
            continue
        reg: Dict[str, Tuple[str, int]] = {"eax": ("functor", 0)}
        consts: Dict[str, int] = {}
        for i in md.disasm(img.read(site + 5, 0x200) or b"", site + 5):
            m, ops = i.mnemonic, [o.strip() for o in i.op_str.split(",")] if i.op_str else []
            if m in ("ret", "int3"):
                break
            if m == "push" and ops and ops[0].startswith("0x") and im.text(int(ops[0], 16)) == "":
                break                                        # the next registration starts (its empty help text)
            if len(ops) == 2 and m == "mov":
                d, src = ops
                mm = re.fullmatch(r"(?:dword|byte|word) ptr \[(\w+)(?: \+ (0x[0-9a-f]+|\d+))?\]", src)
                md_ = re.fullmatch(r"(byte|word|dword) ptr \[(\w+)(?: \+ (0x[0-9a-f]+|\d+))?\]", d)
                if d in REGS and src in reg:
                    reg[d] = reg[src]
                elif d in REGS and re.fullmatch(r"0x[0-9a-f]+|\d+", src):
                    consts[d] = int(src, 0)
                    reg.pop(d, None)
                elif d in REGS and mm and mm.group(1) in reg:
                    off = int(mm.group(2), 0) if mm.group(2) else 0
                    kind, k = reg[mm.group(1)]
                    if kind == "functor" and off == 4:
                        reg[d] = ("table", 0)
                    elif kind == "table":
                        reg[d] = ("slot", off // 4)
                    else:
                        reg.pop(d, None)
                elif md_ and md_.group(2) in reg and reg[md_.group(2)][0] == "slot":
                    off = int(md_.group(3), 0) if md_.group(3) else 0
                    v = int(src, 0) if re.fullmatch(r"0x[0-9a-f]+|\d+", src) else consts.get(src)
                    if off == 0 and v is not None:
                        k = reg[md_.group(2)][1]
                        text = im.text(v) if im.data(v) else None
                        out.append({"at": site, "cls": cls, "name": name, "arg": k, "size": md_.group(1),
                                    "value": v, "text": text})
                elif d in REGS:
                    reg.pop(d, None)
                    consts.pop(d, None)
            elif m == "call":
                for r in ("eax", "ecx", "edx"):
                    if reg.get(r, ("",))[0] != "functor":
                        reg.pop(r, None)
                if ops and ops[0].startswith("0x") and int(ops[0], 16) == look:
                    break
            elif ops and ops[0] in REGS and m not in ("cmp", "test", "push"):
                reg.pop(ops[0], None)
                consts.pop(ops[0], None)
    return out


# ---------------------------------------------------------------------------- handlers that only forward

def forwards(img: BinaryImage, functions: Dict[int, dict], commands: List["SC.Command"]) -> List[dict]:
    """Text-argument handlers that only pass the call on to the class's own function:
    {cls, name, handler, target, how: "jmp" | "vslot", [slot, vtable]}."""
    im = Image(img, functions)
    vt_of: Dict[str, int] = {}

    def class_vtable(cls: str) -> Optional[int]:
        if cls not in vt_of:
            vt_of[cls] = 0
            want = f".?AV{cls}@@\0".encode()
            for base, raw in im.data_sections():
                at = raw.find(want)
                if at < 8:
                    continue
                td = struct.pack("<I", base + at - 8)
                for b2, r2 in im.data_sections():
                    p = r2.find(td)
                    while p >= 0:
                        # a CompleteObjectLocator for the whole object: signature 0, offset 0, then td at +12
                        if p >= 12 and p % 4 == 0 and r2[p - 12:p - 4] == b"\0" * 8:
                            ref = struct.pack("<I", b2 + p - 12)
                            for b3, r3 in im.data_sections():
                                q = r3.find(ref)
                                if q >= 0 and q % 4 == 0:
                                    vt_of[cls] = b3 + q + 4
                        p = r2.find(td, p + 1)
        return vt_of[cls] or None

    out = []
    for c in sorted(commands, key=lambda c: c.at):
        if not c.cls:
            continue
        b = img.read(c.handler, 12) or b""
        if b[:5] == b"\x8B\x4C\x24\x04\xE9":
            t = (c.handler + 9 + struct.unpack_from("<i", b, 5)[0]) & 0xFFFFFFFF
            if im.game_code(t):
                out.append({"cls": c.cls, "name": c.name, "handler": c.handler, "target": t, "how": "jmp", "at": c.at})
        elif b[:6] == b"\x8B\x4C\x24\x04\x8B\x01" and b[6] == 0xFF and b[7] in (0x60, 0xA0, 0x20):
            disp = 0 if b[7] == 0x20 else b[8] if b[7] == 0x60 else struct.unpack_from("<I", b, 8)[0]
            vt = class_vtable(c.cls)
            t = im.u32(vt + disp) if vt and disp % 4 == 0 else None
            if im.game_code(t):
                out.append({"cls": c.cls, "name": c.name, "handler": c.handler, "target": t, "how": "vslot",
                            "slot": disp // 4, "vtable": vt, "at": c.at})
    return out


# ---------------------------------------------------------------------------- names

def names_for(rows: List[dict], fwd: List[dict], functions: Dict[int, dict], b: str,
              img: Optional[BinaryImage] = None) -> Dict[str, dict]:
    """reports/names.json entries: Class::Name for each bound function the queue has without its own name.
    A function bound under several names takes the first; the others are listed."""
    out: Dict[str, dict] = {}
    used = set()
    by_fn: Dict[int, List[dict]] = {}
    for r in rows:
        by_fn.setdefault(r["fn"], []).append(r)
    # a bound address that is only `jmp F` passes the call on to F (recorded in the table, and F listed as a
    # start); F keeps no name from this, since a tail call can go to a member's or another class's function
    if img is not None:
        for fn, group in list(by_fn.items()):
            b5 = img.read(fn, 5) or b""
            if b5[:1] == b"\xE9":
                t = (fn + 5 + struct.unpack("<i", b5[1:])[0]) & 0xFFFFFFFF
                for r in group:
                    r["thunk_to"] = t       # F may be another class's function (a member's): not named after it
    for fn in sorted(by_fn):
        f = functions.get(fn)
        if f is None or not SC.DEFAULT.match(str(f.get("symbol", "")).split("::")[-1]):
            continue
        group = sorted(by_fn[fn], key=lambda r: r["at"])
        r = group[0]
        name = f"{r['cls']}::{r['name']}" if r["cls"] else r["name"]
        if name in used:
            continue
        used.add(name)
        why = (f"The start-up code at 0x{r['at']:08X} registers this function as the typed script command "
               f"{name}; the binding object's own class name gives its signature: {prototype(r)}.")
        if len(group) > 1:
            why += " Also registered as " + ", ".join(
                (f"{g['cls']}::" if g["cls"] else "") + g["name"] for g in group[1:6]) + "."
        out[f"{b}:0x{fn:08X}"] = {"name": name, "by": BY, "why": why}
    by_t: Dict[int, List[dict]] = {}
    for r in fwd:
        by_t.setdefault(r["target"], []).append(r)
    for t in sorted(by_t):
        f = functions.get(t)
        key = f"{b}:0x{t:08X}"
        if key in out or f is None or not SC.DEFAULT.match(str(f.get("symbol", "")).split("::")[-1]):
            continue
        r = sorted(by_t[t], key=lambda r: r["at"])[0]
        name = f"{r['cls']}::{r['name']}"
        if name in used:
            continue
        used.add(name)
        if r["how"] == "jmp":
            why = (f"The handler of the script command {name} (0x{r['handler']:08X}) is only "
                   f"`mov ecx,[esp+4]; jmp` to this function: the class's own function of that name.")
        else:
            why = (f"The handler of the script command {name} (0x{r['handler']:08X}) only calls virtual function "
                   f"{r['slot']} of the object, and this is {r['cls']}'s (its vtable at 0x{r['vtable']:08X}).")
        out[key] = {"name": name, "by": BY_FORWARD, "why": why}
    return out


def merge(data: dict, new: Dict[str, dict]) -> int:
    """Add the names, never replacing one from another source; a Script:: handler name is not in the way
    (it names the handler, a different function)."""
    names = data.setdefault("names", {})
    taken = {(k.split(":")[0], v.get("name")) for k, v in names.items() if isinstance(v, dict)}
    changed = 0
    for key, info in new.items():
        have = names.get(key)
        if isinstance(have, dict) and have.get("by") not in (BY, BY_FORWARD):
            continue
        if have == info or (have is None and (key.split(":")[0], info["name"]) in taken):
            continue
        names[key] = info
        changed += 1
    data["names"] = dict(sorted(names.items()))
    return changed


def scan(bin_dir: Path, recon_dir: Path) -> Dict[str, dict]:
    known = RO.known_from_files(recon_dir)
    out = {}
    for b, fname in SC.FILES.items():
        path = bin_dir / fname
        if not path.is_file():
            continue
        img = BinaryImage(path)
        funcs = known.get(b, {})
        rows, problems = find(img, funcs)
        fwd = forwards(img, funcs, SC.find(img))
        dflt = defaults(img, funcs)
        cmds = SC.find(img)
        names = names_for(rows, fwd, funcs, b, img)            # also marks the bound jmp thunks
        starts = {r["fn"] for r in rows} | {r["target"] for r in fwd} | {c.handler for c in cmds}
        starts |= {r["thunk_to"] for r in rows if r.get("thunk_to")}
        out[b] = {"rows": rows, "problems": problems, "forwards": fwd, "defaults": dflt, "names": names,
                  "new_starts": sorted(s for s in starts if s not in funcs)}
    return out


def add_starts(found: Dict[str, dict], path: Path) -> int:
    """List the functions the bindings point at that the work queue doesn't have (they are only reached
    through these pointers) in reports/extra_function_starts.json, so the next queue build sizes them."""
    data = json.loads(path.read_text(encoding="utf-8"))
    added = 0
    for b, d in found.items():
        have = set(data["starts"].get(b, []))
        new = {f"0x{s:08X}" for s in d["new_starts"]} - have
        data["starts"][b] = sorted(have | new)
        added += len(new)
    path.write_text(json.dumps(data, indent=1) + "\n", encoding="utf-8")
    return added


def table(found: Dict[str, dict]) -> dict:
    h = lambda v: f"0x{v:08X}"  # noqa: E731
    t = {"what": "Typed script commands: script names the program binds straight to C++ functions, with the "
                 "signature its own binding object spells out, and the text-argument handlers that only pass "
                 "the call on (portal/tools/script_typed.py; the examiner's round Q4-Q13).", "versions": {}}
    for b, d in found.items():
        t["versions"][b] = {
            "typed": [dict({"class": r["cls"], "name": r["name"], "function": h(r["fn"]), "prototype": prototype(r),
                       "returns": r["ret"], "arguments": r["args"], "fewest": r["fewest"], "most": r["most"],
                       "registered_at": h(r["at"]), "functor": r["functor"]},
                           **({"defaults": {str(x["arg"]): (x["text"] if x["text"] is not None else x["value"])
                                            for x in d["defaults"] if (x["cls"], x["name"]) == (r["cls"], r["name"])}}
                              if any((x["cls"], x["name"]) == (r["cls"], r["name"]) for x in d["defaults"]) else {}),
                           **({"thunk_to": h(r["thunk_to"])} if r.get("thunk_to") else {}))
                      for r in sorted(d["rows"], key=lambda r: (r["cls"], r["name"].lower(), r["at"]))],
            "forwards": [dict({"class": r["cls"], "name": r["name"], "handler": h(r["handler"]),
                               "function": h(r["target"]), "how": r["how"]},
                              **({"slot": r["slot"], "vtable": h(r["vtable"])} if r["how"] == "vslot" else {}))
                         for r in sorted(d["forwards"], key=lambda r: (r["cls"], r["name"].lower()))],
        }
    return t


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--write", action="store_true", help="add the names to reports/names.json")
    ap.add_argument("--starts", action="store_true",
                    help="list the bound functions and handlers the work queue doesn't have in "
                         "reports/extra_function_starts.json")
    ap.add_argument("--bin-dir", type=Path, default=ROOT / "binaries")
    ap.add_argument("--json", nargs="?", const=ROOT / "reports" / "script_typed_bindings.json", type=Path,
                    metavar="PATH", help="write the whole table (default reports/script_typed_bindings.json)")
    a = ap.parse_args(argv)
    found = scan(a.bin_dir, ROOT / "reconstructed_src")
    if not found:
        print(f"Neither default.xbe nor game.xbe is in {a.bin_dir}: put your game files there first.")
        return 1
    for b, d in found.items():
        fns = {r["fn"] for r in d["rows"]}
        print(f"{SC.LABELS[b]}: {len(d['rows']):,} typed commands on {len(fns):,} functions; "
              f"{len(d['forwards']):,} handlers that only pass the call on; {len(d['names']):,} names.")
        for p in d["problems"]:
            print(f"    check: {p}")
    if a.starts:
        n = add_starts(found, ROOT / "reports" / "extra_function_starts.json")
        print(f"reports/extra_function_starts.json: {n:,} starts added. Build the queue again "
              "(python portal/tools/queue_builder.py), then run this with --write.")
    if a.json:
        a.json.write_text(json.dumps(table(found), indent=1) + "\n", encoding="utf-8")
        print(f"{a.json}: written")
    if a.write:
        path = ROOT / "reports" / "names.json"
        data = NAMES.load(path)
        data.setdefault("schema", NAMES.SCHEMA)
        total = sum(merge(data, d["names"]) for d in found.values())
        path.write_text(json.dumps(data, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
        print(f"reports/names.json: {total:,} names added or updated.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
