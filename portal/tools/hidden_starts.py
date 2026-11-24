#!/usr/bin/env python3
"""
Functions the work queue can't find by following calls and vtables, read from the program's own tables
(the examiner's round Q14-Q20):

- static initializers: the C++ start-up table (__xc_a..__xc_z) the C runtime walks before main,
  found by its loop `mov esi, table; mov edi, end; ... call eax`;
- atexit destructor stubs: every `push stub; call atexit` (atexit found by its shape:
  `push [esp+4]; call _onexit`);
- class field accessors: the setter and getter of every field reports/fields.json lists;
- adjustors in second vtables: `sub ecx,N; jmp F` / `add ecx,-N; jmp F` in a vtable whose
  CompleteObjectLocator offset is not 0.

And what must never be a start: the exception-handling stubs (`mov eax, FuncInfo; jmp __CxxFrameHandler`)
and the unwind funclets their FuncInfo records point at. Those go to reports/queue_exclusions.json as
"nonstart".

    python portal/tools/hidden_starts.py            what it finds in binaries/
    python portal/tools/hidden_starts.py --write    add them to reports/extra_function_starts.json and
                                                    reports/queue_exclusions.json, then rebuild the queue:
                                                    python portal/tools/queue_builder.py

Addresses only: nothing from the game's files is written anywhere.
"""
from __future__ import annotations

import argparse
import json
import struct
import sys
from pathlib import Path
from typing import Dict, List, Optional, Set, Tuple

HERE = Path(__file__).resolve().parent
if str(HERE) not in sys.path:
    sys.path.insert(0, str(HERE))

from sf_binaries import BinaryImage  # noqa: E402

ROOT = HERE.parent.parent
FILES = {"xb": "default.xbe", "proto": "game.xbe"}
EH_MAGIC = 0x19930520


class Img:
    def __init__(self, img: BinaryImage):
        self.img = img

    def u32(self, va: int) -> Optional[int]:
        b = self.img.read(va, 4)
        return struct.unpack("<I", b)[0] if b and len(b) == 4 else None

    def code(self, va: Optional[int]) -> bool:
        s = self.img.section_of(va) if va is not None else None
        return bool(s and s.is_code and not s.library)

    def data(self, va: Optional[int]) -> bool:
        s = self.img.section_of(va) if va is not None else None
        return bool(s and not s.is_code)

    def code_blobs(self):
        for s in self.img.game_code_sections():
            yield s.va, self.img.data[s.raw:s.raw + s.raw_size]

    def data_blobs(self):
        for s in self.img.sections:
            if not s.is_code:
                yield s.va, self.img.data[s.raw:s.raw + min(s.vsize, s.raw_size)]

    def rel_calls(self, target: int, opcode: int = 0xE8):
        """Addresses of every `call target` (or jmp, opcode 0xE9) in the game's code."""
        for base, code in self.code_blobs():
            at = code.find(bytes([opcode]))
            while 0 <= at <= len(code) - 5:
                if (base + at + 5 + struct.unpack_from("<i", code, at + 1)[0]) & 0xFFFFFFFF == target:
                    yield base + at
                at = code.find(bytes([opcode]), at + 1)


# ---------------------------------------------------------------------------- the tables

def initializer_tables(im: Img) -> List[Tuple[int, int]]:
    """[(first, end)] of the start-up tables: `mov esi, first; [mov eax, esi;] mov edi, end` (BE imm32 then
    BF imm32 within a few bytes) over a stretch of data that holds code addresses and zeros."""
    out = []
    for base, code in im.code_blobs():
        for op1, op2 in ((0xBE, 0xBF), (0xBF, 0xBE)):
            at = code.find(bytes([op1]))
            while 0 <= at <= len(code) - 12:
                k = next((at + d for d in (5, 7) if code[at + d] == op2), None)
                if k is not None:
                    a, b = struct.unpack_from("<I", code, at + 1)[0], struct.unpack_from("<I", code, k + 1)[0]
                    if im.data(a) and im.data(b) and 8 <= b - a <= 0x10000 and (b - a) % 4 == 0:
                        words = [im.u32(a + 4 * i) for i in range((b - a) // 4)]
                        live = [w for w in words if w not in (0, 0xFFFFFFFF, None)]
                        if len(live) >= 2 and all(im.code(w) or (im.img.section_of(w) and im.img.section_of(w).is_code)
                                                  for w in live):
                            out.append((a, b))
                at = code.find(bytes([op1]), at + 1)
    return sorted(set(out))


def initializers(im: Img) -> Set[int]:
    """Every function the start-up tables point at, in the game's own code."""
    out = set()
    for a, b in initializer_tables(im):
        for i in range((b - a) // 4):
            w = im.u32(a + 4 * i)
            if w not in (0, 0xFFFFFFFF) and im.code(w):
                out.add(w)
    return out


def find_atexit(im: Img) -> Optional[int]:
    """atexit: `push [esp+4]; call _onexit; ...` (FF 74 24 04 E8). The most-called function of that shape."""
    best, most = None, 0
    for base, code in im.code_blobs():
        at = code.find(b"\xFF\x74\x24\x04\xE8")
        while at >= 0:
            va = base + at
            if at == 0 or code[at - 1] in (0xCC, 0xC3, 0x90):
                n = sum(1 for _ in im.rel_calls(va))
                if n > most:
                    best, most = va, n
            at = code.find(b"\xFF\x74\x24\x04\xE8", at + 1)
    return best if most >= 10 else None


def atexit_stubs(im: Img, atexit: Optional[int]) -> Set[int]:
    """The destructor stubs: `push stub; call atexit`."""
    out = set()
    if atexit is None:
        return out
    for site in im.rel_calls(atexit):
        b = im.img.read(site - 5, 5)
        if b and b[0] == 0x68:
            stub = struct.unpack_from("<I", b, 1)[0]
            if im.code(stub):
                out.add(stub)
    return out


def field_accessors(fields_path: Path, b: str) -> Set[int]:
    """Setters and getters reports/fields.json lists (it is read from one version, its "build")."""
    try:
        f = json.loads(fields_path.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        return set()
    if f.get("build", "xb") != b:
        return set()
    out = set()
    rows = [x for c in f.get("classes", {}).values() for x in c.get("fields", [])] + list(f.get("unowned", []))
    for x in rows:
        for k in ("setter_va", "getter_va"):
            if x.get(k):
                out.add(int(x[k], 16))
    return out


def vtables(im: Img) -> List[Tuple[int, int, List[int]]]:
    """[(vtable, COL offset, slots)] for every vtable with a CompleteObjectLocator before it."""
    out = []
    datas = list(im.data_blobs())
    for base, raw in datas:
        for i in range(0, len(raw) - 8, 4):
            col = struct.unpack_from("<I", raw, i)[0]
            first = struct.unpack_from("<I", raw, i + 4)[0]
            if not im.data(col) or not im.code(first):
                continue
            hdr = im.img.read(col, 20)
            if not hdr or len(hdr) < 20:
                continue
            sig, off, _cd, td, _chd = struct.unpack("<5I", hdr)
            name = im.img.read(td + 8, 4) if sig == 0 and im.data(td) else None
            if name != b".?AV" and name != b".?AU":
                continue
            slots, j = [], i + 4
            while j + 4 <= len(raw):
                f = struct.unpack_from("<I", raw, j)[0]
                if not im.code(f):
                    break
                slots.append(f)
                j += 4
            out.append((base + i + 4, off, slots))
    return out


def adjustors(im: Img, vts=None) -> Dict[int, Tuple[int, int]]:
    """{thunk: (target, this-delta)} for `sub ecx,N; jmp F` / `add ecx,-N; jmp F` in vtables of a class's
    second (or later) part."""
    out = {}
    for _vt, off, slots in vts if vts is not None else vtables(im):
        if off == 0:
            continue
        for s in slots:
            b = im.img.read(s, 8) or b""
            if len(b) == 8 and b[:2] in (b"\x83\xE9", b"\x83\xC1") and b[3] == 0xE9:
                n = struct.unpack("<b", b[2:3])[0]
                delta = -n if b[1] == 0xE9 else n
                if delta < 0:
                    out[s] = ((s + 8 + struct.unpack("<i", b[4:8])[0]) & 0xFFFFFFFF, delta)
    return out


def eh(im: Img, frame_handler: Optional[int]) -> Tuple[Set[int], Set[int]]:
    """(handler stubs, unwind funclets and catch blocks): never functions of their own."""
    stubs, funclets = set(), set()
    if frame_handler is None:
        return stubs, funclets
    for site in im.rel_calls(frame_handler, 0xE9):
        b = im.img.read(site - 5, 5)
        if not b or b[0] != 0xB8:
            continue
        info = struct.unpack_from("<I", b, 1)[0]
        if im.u32(info) != EH_MAGIC:
            continue
        stubs.add(site - 5)
        states, unwind = im.u32(info + 4) or 0, im.u32(info + 8)
        for k in range(min(states, 4096)):
            act = im.u32(unwind + 8 * k + 4) if unwind else None
            if act and im.code(act):
                funclets.add(act)
        tries, tmap = im.u32(info + 12) or 0, im.u32(info + 16)
        for t in range(min(tries, 256)):
            n, handlers = im.u32(tmap + 20 * t + 12) or 0, im.u32(tmap + 20 * t + 16)
            for h in range(min(n, 64)):
                addr = im.u32(handlers + 16 * h + 12) if handlers else None
                if addr and im.code(addr):
                    funclets.add(addr)
    return stubs, funclets


# ---------------------------------------------------------------------------- putting it together

def names_by_address(b: str) -> Dict[str, int]:
    try:
        names = json.loads((ROOT / "reports" / "names.json").read_text(encoding="utf-8"))["names"]
    except (OSError, ValueError, KeyError):
        return {}
    return {v["name"]: int(k.split(":")[1], 16) for k, v in names.items() if k.startswith(b + ":")}


def scan(bin_dir: Path) -> Dict[str, dict]:
    out = {}
    for b, fname in FILES.items():
        p = bin_dir / fname
        if not p.is_file():
            continue
        im = Img(BinaryImage(p))
        named = names_by_address(b)
        atexit = named.get("atexit") or find_atexit(im)
        stubs, funclets = eh(im, named.get("__CxxFrameHandler"))
        found = {
            "initializers": initializers(im),
            "atexit stubs": atexit_stubs(im, atexit),
            "field accessors": field_accessors(ROOT / "reports" / "fields.json", b),
            "adjustors": set(adjustors(im)),
        }
        never = stubs | funclets
        for k in found:
            found[k] -= never
        out[b] = {"starts": found, "eh stubs": stubs, "eh funclets": funclets,
                  "tables": initializer_tables(im), "atexit": atexit}
    return out


def write(found: Dict[str, dict]) -> Tuple[int, int]:
    sp = ROOT / "reports" / "extra_function_starts.json"
    starts = json.loads(sp.read_text(encoding="utf-8"))
    added = 0
    for b, d in found.items():
        have = set(starts["starts"].get(b, []))
        new = {f"0x{v:08X}" for s in d["starts"].values() for v in s} - have
        starts["starts"][b] = sorted(have | new)
        added += len(new)
    sp.write_text(json.dumps(starts, indent=1) + "\n", encoding="utf-8")
    ep = ROOT / "reports" / "queue_exclusions.json"
    ex = json.loads(ep.read_text(encoding="utf-8"))
    excluded = 0
    for b, d in found.items():
        rows = ex["starts"].setdefault(b, [])
        have = {r["va"] for r in rows}
        for v in sorted(d["eh stubs"]):
            if f"0x{v:08X}" not in have:
                rows.append({"va": f"0x{v:08X}", "kind": "nonstart",
                             "why": "exception-handling stub: mov eax, FuncInfo; jmp __CxxFrameHandler (compiler-made)"})
                excluded += 1
        for v in sorted(d["eh funclets"]):
            if f"0x{v:08X}" not in have:
                rows.append({"va": f"0x{v:08X}", "kind": "nonstart",
                             "why": "unwind funclet or catch block named by a FuncInfo record (part of its parent function)"})
                excluded += 1
        rows.sort(key=lambda r: r["va"])
    ep.write_text(json.dumps(ex, indent=1) + "\n", encoding="utf-8")
    return added, excluded


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--bin-dir", type=Path, default=ROOT / "binaries")
    a = ap.parse_args(argv)
    found = scan(a.bin_dir)
    if not found:
        print(f"Neither default.xbe nor game.xbe is in {a.bin_dir}.")
        return 1
    for b, d in found.items():
        tabs = ", ".join(f"0x{x:08X}-0x{y:08X}" for x, y in d["tables"])
        print(f"{b}: start-up tables {tabs}; atexit 0x{(d['atexit'] or 0):08X}")
        for k, v in d["starts"].items():
            print(f"    {len(v):5,}  {k}")
        print(f"    {len(d['eh stubs']):5,}  exception stubs and {len(d['eh funclets']):,} funclets (never starts)")
    if a.write:
        added, excluded = write(found)
        print(f"extra_function_starts.json: {added:,} added; queue_exclusions.json: {excluded:,} added. "
              "Now rebuild the queue: python portal/tools/queue_builder.py")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
