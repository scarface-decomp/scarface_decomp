#!/usr/bin/env python3
"""
Which child chunks each loader handles, read from the program's own dispatch loops (the examiner's
question F3).

A loader reads its chunk's own fields, then goes through its children in a loop:

    while (more()) { id = current_id(); switch (id) { ... }; next(); }

On the retail Xbox, more() is sub_00240630 and current_id() is sub_00240670 (the examiner's notes to
section F). The compiler turns each switch into a chain of compares and subtractions on the id
(cmp eax, 0x121201 / ja / sub eax, 0x10003 / je / dec eax / jne ...) or a jump table. This follows the
id's register through every branch from each call of current_id(), keeping track of what has been
subtracted, and so reads off every child id the loop handles and where its case starts. Each case is
described by the first function it calls.

    python portal/tools/chunk_dispatch.py         write reports/chunk_dispatch.json

The function holding each loop is named by its class and slot where it is a virtual function of a class
the program's RTTI names (ParticleSystemLoader::vfunc_06 ...). Only addresses, ids and names go in the
report.
"""

from __future__ import annotations

import argparse
import json
import struct
import sys
from dataclasses import dataclass, field
from pathlib import Path
from typing import Dict, List, Optional, Set, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parent))
from loader_registry import rtti_vtables, vtable_slots  # noqa: E402
from sf_binaries import BinaryImage, _cs  # noqa: E402
import p3d  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]
# The stream reader's functions, per program (the examiner's notes to section F; retail Xbox only so far).
CURRENT_ID = {"xb": 0x00240670}
MORE = {"xb": 0x00240630}
FILES = {"xb": "default.xbe"}
STEPS = 400                        # instructions followed along one path from the call
PATHS = 200                        # paths followed from one call


@dataclass
class Case:
    id: int
    at: int                                        # where its code starts
    calls: List[int] = field(default_factory=list)  # the first functions it calls


@dataclass
class Dispatch:
    site: int                                      # the call of current_id()
    function: int                                  # the function holding the loop
    owner: str = ""                                # Class::vfunc_NN, when it is one
    called_from: List[str] = field(default_factory=list)   # the virtual functions that call it, when it isn't
    cases: List[Case] = field(default_factory=list)
    default: Optional[int] = None


class Code:
    """One instruction at a time, by address, with capstone's details."""

    def __init__(self, img: BinaryImage):
        self.img = img
        self.md = _cs()
        self.md.detail = True
        self._cache: Dict[int, object] = {}

    def at(self, va: int):
        if va not in self._cache:
            raw = self.img.read(va, 16)
            ins = next(self.md.disasm(raw, va), None) if raw else None
            self._cache[va] = ins
        return self._cache[va]


def _imm(ins, i: int) -> Optional[int]:
    from capstone import x86_const as X
    if len(ins.operands) > i and ins.operands[i].type == X.X86_OP_IMM:
        return ins.operands[i].imm & 0xFFFFFFFF
    return None


def _reg(ins, i: int) -> Optional[int]:
    from capstone import x86_const as X
    if len(ins.operands) > i and ins.operands[i].type == X.X86_OP_REG:
        return ins.operands[i].reg
    return None


def _wide(reg: int) -> int:
    """The 32-bit register a register is part of (al, ax -> eax)."""
    from capstone import x86_const as X
    parts = {X.X86_REG_AL: X.X86_REG_EAX, X.X86_REG_AX: X.X86_REG_EAX, X.X86_REG_CL: X.X86_REG_ECX,
             X.X86_REG_CX: X.X86_REG_ECX, X.X86_REG_DL: X.X86_REG_EDX, X.X86_REG_DX: X.X86_REG_EDX,
             X.X86_REG_BL: X.X86_REG_EBX, X.X86_REG_BX: X.X86_REG_EBX}
    return parts.get(reg, reg)


def _writes(ins, reg: int) -> bool:
    """Whether an instruction changes a register (other than the arithmetic this follows)."""
    try:
        _read, written = ins.regs_access()
    except Exception:
        return False
    return any(_wide(r) == reg for r in written)


def cases_from(code: Code, start: int, reg: int, everything: bool = False) -> Tuple[List[Tuple[int, int]], Optional[int]]:
    """[(id, case start)] and the default case's start: following reg (holding the id) from start along
    every branch, keeping the amount subtracted from it (the compiler's switch by subtraction over sorted
    case values: each sub, dec, add and inc moves what the next compare means). everything: keep every
    value (four-letter words too), not only those in the chunk-id range."""
    from capstone import x86_const as X
    found: Dict[int, int] = {}
    defaults: List[int] = []
    todo: List[Tuple[int, int, int, Optional[int]]] = [(start, reg, 0, None)]   # (address, reg, subtracted, last compared)
    seen: Set[Tuple[int, int, int, Optional[int]]] = set()
    paths = 0
    while todo and paths < PATHS:
        va, r, off, cmp_val = todo.pop()
        paths += 1
        for _ in range(STEPS):
            key = (va, r, off, cmp_val)                  # paths meeting at one je with different compares
            if key in seen:
                break
            seen.add(key)
            ins = code.at(va)
            if ins is None:
                break
            m, nxt = ins.mnemonic, va + ins.size
            target = _imm(ins, 0) if ins.group(X.X86_GRP_JUMP) else None
            if m == "cmp" and _reg(ins, 0) and _wide(_reg(ins, 0)) == r and _imm(ins, 1) is not None:
                cmp_val = (_imm(ins, 1) + off) & 0xFFFFFFFF
            elif m == "test" and _reg(ins, 0) and _wide(_reg(ins, 0)) == r and _reg(ins, 1) == _reg(ins, 0):
                cmp_val = off & 0xFFFFFFFF
            elif m == "sub" and _reg(ins, 0) and _wide(_reg(ins, 0)) == r and _imm(ins, 1) is not None:
                off = (off + _imm(ins, 1)) & 0xFFFFFFFF
                cmp_val = off
            elif m == "add" and _reg(ins, 0) and _wide(_reg(ins, 0)) == r and _imm(ins, 1) is not None:
                off = (off - _imm(ins, 1)) & 0xFFFFFFFF
                cmp_val = off
            elif m == "dec" and _reg(ins, 0) and _wide(_reg(ins, 0)) == r:
                off = (off + 1) & 0xFFFFFFFF
                cmp_val = off
            elif m == "inc" and _reg(ins, 0) and _wide(_reg(ins, 0)) == r:
                off = (off - 1) & 0xFFFFFFFF
                cmp_val = off
            elif m == "mov" and _reg(ins, 1) and _wide(_reg(ins, 1)) == r and _reg(ins, 0):
                todo.append((nxt, _wide(_reg(ins, 0)), off, cmp_val))       # a copy holds it too
            elif m == "jmp" and target is None:                            # a jump table: jmp [reg*4 + table]
                op = ins.operands[0]
                if op.type == X.X86_OP_MEM and _wide(op.mem.index) == r and op.mem.scale == 4 and cmp_val is not None:
                    for i in range(min(cmp_val - off + 1 if cmp_val >= off else 0, 256)):
                        raw = code.img.read(op.mem.disp + 4 * i, 4)
                        if raw is None:
                            break
                        found.setdefault((off + i) & 0xFFFFFFFF, struct.unpack("<I", raw)[0])
                break
            elif m in ("je", "jz") and target is not None and cmp_val is not None:
                found.setdefault(cmp_val, target)
            elif m in ("jne", "jnz") and target is not None and cmp_val is not None:
                found.setdefault(cmp_val, nxt)
                va = target
                continue
            elif m == "jmp" and target is not None:
                va = target
                continue
            elif ins.group(X.X86_GRP_JUMP) and target is not None:          # ja, jb ...: both ways
                todo.append((target, r, off, cmp_val))
            elif m in ("ret", "call") or (m != "cmp" and _writes(ins, r)):
                if not found:
                    break
                defaults.append(va)
                break
            va = nxt
    cases = sorted((i, t) for i, t in found.items() if everything or 0x100 <= i <= 0x0FFFFFFF)
    starts = {t for _i, t in cases}
    default = next((d for d in defaults if d not in starts), None)
    return cases, default


def argument_switch(img: BinaryImage, fn: int) -> List[Tuple[int, int]]:
    """[(value, case start)] of a function that switches on its first argument (a handler's "accepts" check,
    vfunc_04): the register loaded from [ebp+8] or [esp+4] near its start, followed as cases_from does."""
    from capstone import x86_const as X
    code = Code(img)
    va = fn
    for _ in range(8):
        ins = code.at(va)
        if ins is None:
            break
        if ins.mnemonic == "mov" and len(ins.operands) == 2 and ins.operands[1].type == X.X86_OP_MEM:
            m = ins.operands[1].mem
            if (m.base, m.disp) in ((X.X86_REG_EBP, 8), (X.X86_REG_ESP, 4)) and _reg(ins, 0):
                return cases_from(code, va + ins.size, _wide(_reg(ins, 0)), everything=True)[0]
        va += ins.size
    return []


def word_of(v: int) -> str:
    """A four-letter word as text (0x53595350 -> PSYS), or the number."""
    raw = struct.pack("<I", v).rstrip(b"\0")
    return raw.decode("ascii") if raw and all(48 <= c <= 57 or 65 <= c <= 90 for c in raw) else f"0x{v:08X}"


def accepted_by(img: BinaryImage, fn: int, accept: int) -> List[str]:
    """The values a handler's accepts check (fn) says yes to: its cases whose code is the "yes" path."""
    return sorted(word_of(v) for v, at in argument_switch(img, fn) if at == accept)


def says_yes(img: BinaryImage, va: int) -> bool:
    """Whether code starts by returning true (mov al, 1 / mov eax, 1)."""
    raw = img.read(va, 5) or b""
    return raw[:2] == b"\xB0\x01" or raw[:5] == b"\xB8\x01\x00\x00\x00"


def handler_accepts(img: BinaryImage) -> Dict[str, List[str]]:
    """{handler class: what its accepts check (vfunc_04) says yes to}, for every class named ...Handler."""
    out: Dict[str, List[str]] = {}
    for vt, (cls, _raw) in rtti_vtables(img).items():
        if not cls.endswith("Handler"):
            continue
        slots = vtable_slots(img, vt)
        if len(slots) <= 4:
            continue
        yes = sorted({word_of(v) for v, at in argument_switch(img, slots[4]) if says_yes(img, at)})
        if yes:
            out[cls] = yes
    return dict(sorted(out.items()))


def first_calls(code: Code, start: int, most: int = 2, steps: int = 60) -> List[int]:
    """The first functions a case calls, straight down from its start."""
    from capstone import x86_const as X
    out: List[int] = []
    va = start
    for _ in range(steps):
        ins = code.at(va)
        if ins is None or ins.mnemonic in ("ret", "jmp"):
            break
        if ins.mnemonic == "call" and _imm(ins, 0) is not None:
            out.append(_imm(ins, 0))
            if len(out) >= most:
                break
        va += ins.size
    return out


def containing(starts: List[int], va: int) -> Optional[int]:
    import bisect
    i = bisect.bisect_right(starts, va) - 1
    return starts[i] if i >= 0 else None


def dispatches(img: BinaryImage, current_id: int) -> List[Dispatch]:
    """Every loop in the program's own code that calls current_id(), with its cases."""
    from capstone import x86_const as X
    from sf_binaries import collect_call_targets
    code = Code(img)
    owners: Dict[int, str] = {}
    for vt, (cls, _raw) in rtti_vtables(img).items():
        for slot, va in enumerate(vtable_slots(img, vt)):
            owners.setdefault(va, f"{cls}::vfunc_{slot:02d}")
    starts = sorted(collect_call_targets(img) | set(owners))
    callers: Dict[int, Set[int]] = {}
    for sec in img.code_sections():
        if sec.name != ".text":
            continue
        blob = img.data[sec.raw:sec.raw + sec.raw_size]
        for i in range(len(blob) - 5):
            if blob[i] == 0xE8:
                to = (sec.va + i + 5 + struct.unpack_from("<i", blob, i + 1)[0]) & 0xFFFFFFFF
                callers.setdefault(to, set()).add(sec.va + i)

    def owned_callers(fn: int, depth: int = 3) -> List[str]:
        """The class virtual functions that call fn, up to depth calls away."""
        found, todo, seen = [], [fn], {fn}
        for _ in range(depth):
            nxt = []
            for f in todo:
                for site in callers.get(f, ()):
                    c = containing(starts, site)
                    if c is None or c in seen:
                        continue
                    seen.add(c)
                    if c in owners:
                        found.append(owners[c])
                    else:
                        nxt.append(c)
            if found:
                break
            todo = nxt
        return sorted(set(found))[:6]
    out: List[Dispatch] = []
    for sec in img.code_sections():
        if sec.name != ".text":
            continue
        blob = img.data[sec.raw:sec.raw + sec.raw_size]
        for i in range(len(blob) - 5):
            if blob[i] != 0xE8:
                continue
            site = sec.va + i
            if (site + 5 + struct.unpack_from("<i", blob, i + 1)[0]) & 0xFFFFFFFF != current_id:
                continue
            ins = code.at(site)
            if ins is None or ins.mnemonic != "call":
                continue
            cases, default = cases_from(code, site + 5, X.X86_REG_EAX)
            if not cases:
                continue
            fn = containing(starts, site) or site
            d = Dispatch(site, fn, owners.get(fn, ""), cases=[Case(i_, t, first_calls(code, t)) for i_, t in cases],
                         default=default)
            if not d.owner:
                d.called_from = owned_callers(fn)
            out.append(d)
    return out


def report(bin_dir: Path) -> dict:
    out = {"what": "child chunks each loader's dispatch loop handles, read from the program's own code "
                   "(portal/tools/chunk_dispatch.py; the examiner's question F3)", "versions": {}}
    names = {}
    try:
        for k, v in json.loads((ROOT / "reports" / "names.json").read_text(encoding="utf-8"))["names"].items():
            names[k] = v.get("name", "")
    except (OSError, ValueError, KeyError):
        pass
    for b, name in FILES.items():
        path = bin_dir / name
        if not path.exists():
            continue
        found = dispatches(BinaryImage(path), CURRENT_ID[b])

        def label(va: int) -> str:
            return names.get(f"{b}:0x{va:08X}", "") or f"sub_{va:08X}"
        rows = []
        for d in found:
            rows.append({"site": f"0x{d.site:08X}", "function": f"0x{d.function:08X}", "owner": d.owner,
                         "called_from": d.called_from,
                         "default": f"0x{d.default:08X}" if d.default else None,
                         "cases": [{"id": f"0x{c.id:08X}", "chunk": p3d.NAMES.get(c.id, ""), "at": f"0x{c.at:08X}",
                                    "calls": [label(v) for v in c.calls]} for c in d.cases]})
        ids = sorted({c["id"] for r in rows for c in r["cases"]})
        out["versions"][b] = {"file": name, "loops": len(rows), "ids": len(ids),
                              "handler_accepts": handler_accepts(BinaryImage(path)),
                              "unnamed_ids": [i for i in ids if int(i, 16) not in p3d.NAMES], "dispatches": rows}
    return out


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--bin-dir", type=Path, default=ROOT / "binaries")
    ap.add_argument("--out", type=Path, default=ROOT / "reports" / "chunk_dispatch.json")
    a = ap.parse_args(argv)
    got = report(a.bin_dir)
    if not got["versions"]:
        print(f"default.xbe isn't in {a.bin_dir}.")
        return 1
    a.out.write_text(json.dumps(got, indent=1) + "\n", encoding="utf-8")
    for b, v in got["versions"].items():
        print(f"{v['file']}: {v['loops']} dispatch loops, {v['ids']} child ids ({len(v['unnamed_ids'])} not in p3d.NAMES)")
    print(f"written {a.out.name}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
