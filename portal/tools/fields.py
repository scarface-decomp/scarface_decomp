#!/usr/bin/env python3
"""
The script-visible fields of every class, read from the Xbox program's own start-up code (the examiner's ask 2).

Every console class lists its fields once, in its init function, with addField (default.xbe 0x00073780):

    addField(name, type, ?, ?, offset, count, extra, setter, getter)        nine arguments, pushed right to left

The type is an id that the program names when it registers its types (0x0006FEB0: id, name, size, getter, setter),
so the type's own name comes from the program too ("TypeS16", "TypeBool" ...). A field kept by a setter (setter or
getter not 0) has no offset of its own. A class's init function is what its ConcreteClassRep<Class> (from the
program's class information) jumps to from its third slot; a field function reached from there, or from a function
that one calls (a parent class's), belongs to the nearest class that reaches it.

    python portal/tools/fields.py            writes reports/fields.json

Output: {"what", "types": {id: name}, "classes": {Class: {"size", "init", "fields": [{name, stx, type, type_id,
offset, count, extra, setter_va, getter_va, site_va}]}}, "unowned": [...]}. stx is the name as compiled scripts
store it (torque_names), so a script's hashed field can be looked up here.

Only the program's own bytes are read. No leaked source is used. You need your own copy of the game.
"""

from __future__ import annotations

import argparse
import json
import re
import struct
import sys
from collections import defaultdict
from pathlib import Path
from typing import Dict, List, Optional, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parent))
from sf_binaries import BinaryImage, _cs, function_extent  # noqa: E402
import loader_registry as LR  # noqa: E402
import torque_names as TN  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]
XBE = ROOT / "binaries" / "default.xbe"
OUT = ROOT / "reports" / "fields.json"
ADD_FIELD = {"xb": 0x00073780}
REGISTER_TYPE = {"xb": 0x0006FEB0}
REP = re.compile(r"ConcreteClassRep<(.+)>$")
DEPTH = 3


def text_at(img: BinaryImage, va: int) -> Optional[str]:
    raw = img.read(va, 96) if va else None
    if not raw:
        return None
    z = raw.split(b"\0")[0]
    return z.decode("latin-1") if z and all(32 <= c < 127 for c in z) else None


class Code:
    """A function's instructions, decoded once."""

    def __init__(self, img: BinaryImage):
        self.img, self.md, self.cache = img, _cs(), {}
        self.padded, self.starts_cache, self.calls_cache = None, {}, None
        self.known: set = set()                              # function starts known for certain (class-init entries)
        self.prog = LR.Program(img)

    def start_of(self, va: int) -> int:
        """Where the function holding va begins: the nearest 16-byte boundary before it that follows int3 padding
        (the program's own function list misses many class-init functions, so this doesn't rely on it); a
        boundary after a bare ret only when no padded one decodes straight through to va."""
        if va in self.starts_cache:
            return self.starts_cache[va]
        import bisect
        if self.padded is None:
            sec = next(s for s in self.img.sections if s.name == ".text")
            data = self.img.data[sec.raw:sec.raw + sec.raw_size]
            self.padded = sorted(set([sec.va + k for k in range(16, len(data), 16) if data[k - 1] == 0xCC and data[k] != 0xCC])
                                 | self.known)
        k = bisect.bisect_right(self.padded, va) - 1
        out = self.prog.containing(va)
        known = sorted(a for a in self.known if va - 0x2000 < a <= va)
        for a in known[::-1]:                                # a class-init entry wins when it runs through to va
            ins = list(self.md.disasm(self.img.read(a, va - a + 16) or b"", a))
            if any(x.address == va for x in ins) and not any(x.mnemonic == "ret" for x in ins if x.address < va):
                self.starts_cache[va] = a
                return a
        for a in self.padded[max(0, k - 3):k + 1][::-1]:
            ins = list(self.md.disasm(self.img.read(a, va - a + 16) or b"", a))
            if any(x.address == va for x in ins):
                out = a
                break
        self.starts_cache[va] = out
        return out

    def function(self, va: int, to: Optional[int] = None) -> List:
        """The instructions of the function starting at va (a start), up to its first ret or to `to`."""
        key = (va, to)
        if key not in self.cache:
            end = (to + 16) if to else va + max(function_extent(self.img, va).size, 16)
            ins = []
            for x in self.md.disasm(self.img.read(va, end - va) or b"", va):
                ins.append(x)
                if to is None and x.mnemonic in ("ret", "int3"):
                    break
            self.cache[key] = ins
        return self.cache[key]

    def calls_to(self, target: int) -> List[int]:
        return [a for a in callers(self, target) if (self.img.read(a, 1) or b"\0")[0] == 0xE8]

    def arguments(self, site: int, n: int) -> Optional[List[Optional[int]]]:
        """The n values pushed for the call at site (first argument first); None where one isn't a constant."""
        ins = self.function(self.start_of(site), to=site)
        idx = next((i for i, x in enumerate(ins) if x.address == site), None)
        if idx is None:
            return None
        regs: Dict[str, Optional[int]] = {}
        for x in ins[:idx]:                                  # what each register holds, read straight through
            if x.mnemonic == "mov" and x.op_str.count(",") == 1:
                dst, src = [t.strip() for t in x.op_str.split(",")]
                if re.fullmatch(r"e[a-ds][xip]|e[sd]i", dst):
                    regs[dst] = int(src, 16) if re.fullmatch(r"0x[0-9a-f]+|\d+", src) else None
            elif x.mnemonic == "xor" and len(set(t.strip() for t in x.op_str.split(","))) == 1:
                regs[x.op_str.split(",")[0].strip()] = 0
            elif x.mnemonic == "call":
                for r in ("eax", "ecx", "edx"):
                    regs.pop(r, None)
        pushed = []
        for x in reversed(ins[:idx]):
            if x.mnemonic == "call":
                break
            if x.mnemonic == "push":
                op = x.op_str.strip()
                pushed.append(int(op, 16) if re.fullmatch(r"0x[0-9a-f]+|\d+", op) else regs.get(op))
                if len(pushed) == n:
                    return pushed
        return pushed + [None] * (n - len(pushed)) if pushed else None

    def targets(self, start: int) -> List[int]:
        """The functions start calls or jumps to directly."""
        out = []
        for x in self.function(start):
            if x.mnemonic in ("call", "jmp") and re.fullmatch(r"0x[0-9a-f]+", x.op_str):
                t = int(x.op_str, 16)
                if not start <= t < x.address:
                    out.append(t)
        return out


def types(code: Code, build: str) -> Dict[int, str]:
    out = {}
    for site in code.calls_to(REGISTER_TYPE[build]):
        a = code.arguments(site, 2)
        if a and a[0] is not None and a[1] is not None:
            name = text_at(code.img, a[1])
            if name and name.startswith("Type"):
                out[a[0]] = name
    return out


def classes(code: Code) -> Tuple[Dict[int, Tuple[str, int]], Dict[str, int]]:
    """({function: (class, depth)}, {class: object size}): each ConcreteClassRep's init slot, followed DEPTH calls
    deep; the size is what its create slot asks the allocator for."""
    owner: Dict[int, Tuple[str, int]] = {}
    sizes: Dict[str, int] = {}
    for vt, (name, _) in LR.rtti_vtables(code.img).items():
        m = REP.match(name)
        if not m:
            continue
        cls, slots = m.group(1), LR.vtable_slots(code.img, vt)
        size = None
        if len(slots) > 1:                                   # create: push size, call the allocator
            ins = code.function(slots[1])[:8]
            size = next((int(x.op_str, 16) for x in ins if x.mnemonic == "push" and re.fullmatch(r"0x[0-9a-f]+", x.op_str)), None)
            if size:
                sizes[cls] = size
        frontier = list(slots[2:3])
        for depth in range(1, DEPTH + 1):
            nxt = []
            for f in frontier:
                if f not in owner or owner[f][1] > depth:
                    owner[f] = (cls, depth)
                nxt += code.targets(f)
            frontier = nxt
    return owner, sizes


def callers(code: Code, target: int) -> List[int]:
    """Where target is called or jumped to directly (rel32), from one index of every such instruction."""
    if code.calls_cache is None:
        sec = next(s for s in code.img.sections if s.name == ".text")
        data = code.img.data[sec.raw:sec.raw + sec.raw_size]
        idx: Dict[int, List[int]] = defaultdict(list)
        for k in range(len(data) - 5):
            if data[k] in (0xE8, 0xE9):
                idx[(sec.va + k + 5 + struct.unpack_from("<i", data, k + 1)[0]) & 0xFFFFFFFF].append(sec.va + k)
        code.calls_cache = idx
    return code.calls_cache.get(target, [])


def harvest(img: BinaryImage, build: str = "xb") -> dict:
    code = Code(img)
    names = types(code, build)
    owner, sizes = classes(code)
    code.known = set(owner)
    out: Dict[str, dict] = {}
    unowned = []
    for site in sorted(code.calls_to(ADD_FIELD[build])):
        a = code.arguments(site, 9)
        if not a:
            continue
        name = text_at(img, a[0] or 0)
        if not name:
            continue
        fn = code.start_of(site)
        if fn not in owner:                                  # a helper: owned by whoever calls it
            for c in callers(code, fn):
                f2 = code.start_of(c)
                if f2 in owner:
                    owner[fn] = (owner[f2][0], owner[f2][1] + 1)
                    break
        setter, getter = a[7] or 0, a[8] or 0
        row = {"name": name, "stx": TN.compiled_name(name), "type": names.get(a[1], f"type {a[1]}"), "type_id": a[1],
               "offset": None if (setter or getter) else a[4], "count": a[5], "extra": a[6],
               "setter_va": f"0x{setter:08X}" if setter else None, "getter_va": f"0x{getter:08X}" if getter else None,
               "site_va": f"0x{site:08X}"}
        if fn in owner:
            cls = owner[fn][0]
            c = out.setdefault(cls, {"size": sizes.get(cls), "init": f"0x{fn:08X}", "fields": []})
            c["fields"].append(row)
        else:
            unowned.append(dict(row, function=f"0x{fn:08X}"))
    for c in out.values():
        c["fields"].sort(key=lambda r: int(r["site_va"], 16))
    return {"what": "script fields per class, from the program's addField calls (portal/tools/fields.py; the examiner's ask 2)",
            "build": build, "types": {str(k): v for k, v in sorted(names.items())},
            "classes": dict(sorted(out.items())), "unowned": unowned}


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--xbe", default=str(XBE))
    ap.add_argument("--out", default=str(OUT))
    a = ap.parse_args(argv)
    if not Path(a.xbe).exists():
        print(f"no {a.xbe}: you need your own copy of the game", file=sys.stderr)
        return 1
    report = harvest(BinaryImage(a.xbe))
    Path(a.out).write_text(json.dumps(report, indent=1) + "\n")
    n = sum(len(c["fields"]) for c in report["classes"].values())
    print(f"{len(report['classes'])} classes, {n} fields, {len(report['unowned'])} unowned, "
          f"{len(report['types'])} types -> {a.out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
