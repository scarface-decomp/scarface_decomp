#!/usr/bin/env python3
"""
The game's chunk loaders: which class reads which .p3d chunk, and what it makes from it.

Every chunk of a .p3d file is read by a loader object (Pure3D's ...Loader classes, the game's own
renderer::WorldGeoLoader and the rest), or by a handler that a loader hands sub-chunks to
(DefaultFrameControllerHandler ...). Each loader's constructor gives the chunk id it reads to its base
class, so the program itself says which class reads which chunk. This reads that out of your own
default.xbe or Scarface.exe:

* the classes, from the program's own run-time type information (RTTI) and their vtables;
* each loader's constructor (the code that writes its vtable into a new object) and the chunk id in it;
* each of its virtual functions: the chunk ids and four-letter words they compare (a handler's
  "accepts" check: PSYS, BQG, TEX ...), and the classes whose vtables they or the constructors they
  call write (what the loader builds).

    python portal/tools/loader_registry.py                write reports/loader_registry.json
    python portal/tools/loader_registry.py --list xb      a table: chunk id, loader, what it builds

Only addresses, class names (the game's own RTTI) and chunk ids go into the report: no game bytes.
(Examiner's list E6, docs/cleanroom: a question that needs no clean room, read from the game alone.)
"""

from __future__ import annotations

import argparse
import bisect
import json
import re
import struct
import sys
from dataclasses import dataclass, field
from pathlib import Path
from typing import Dict, Iterable, List, Optional, Set, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parent))
from sf_binaries import BinaryImage, _cs, collect_call_targets, function_extent  # noqa: E402
import p3d  # noqa: E402
import queue_builder as Q  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]
FILES = {"xb": "default.xbe", "pc": "Scarface.exe"}
LOADER = re.compile(r"(Loader|Handler)$")
CTOR_MOST = 320                      # a constructor is a short function; longer ones register many loaders
BASES = {"core::IRefCount"}          # what every loader's own constructor writes first
VFUNC_MOST = 0x1000


@dataclass
class Slot:
    slot: int
    va: int
    chunk_ids: List[int] = field(default_factory=list)
    words: List[str] = field(default_factory=list)
    builds: List[str] = field(default_factory=list)


@dataclass
class Loader:
    cls: str
    raw: str
    vtable: int
    chunk_ids: List[int] = field(default_factory=list)          # from its constructor(s)
    constructors: List[int] = field(default_factory=list)
    registered_by: List[int] = field(default_factory=list)      # longer functions that write its vtable
    slots: List[Slot] = field(default_factory=list)

    def as_json(self) -> dict:
        return {"class": self.cls, "rtti": self.raw, "vtable": f"0x{self.vtable:08X}",
                "chunk_ids": [f"0x{v:08X}" for v in self.chunk_ids],
                "chunk_names": [p3d.NAMES.get(v, "") for v in self.chunk_ids],
                "constructors": [f"0x{v:08X}" for v in self.constructors],
                "registered_by": [f"0x{v:08X}" for v in self.registered_by],
                "slots": [{"slot": s.slot, "va": f"0x{s.va:08X}",
                           "chunk_ids": [f"0x{v:08X}" for v in s.chunk_ids], "words": s.words,
                           "builds": s.builds} for s in self.slots if s.chunk_ids or s.words or s.builds]}


def rtti_vtables(img: BinaryImage) -> Dict[int, Tuple[str, str]]:
    """{vtable address: (class, raw RTTI name)}: each MSVC complete-object locator whose pointer sits just
    before a vtable (the locator's signature and the class's offset both 0: the class's own vtable)."""
    d = img.data
    descriptors: Dict[int, Tuple[str, str]] = {}
    for m in re.finditer(rb"\.\?A[VU][A-Za-z0-9_@?$<>]+@@\x00", d):
        raw = m.group(0)[:-1].decode("ascii", "ignore")
        off = m.start() - 8                                  # TypeDescriptor: vftable pointer, spare, name
        sec = next((s for s in img.sections if s.raw <= off < s.raw + s.raw_size), None)
        if sec:
            descriptors[sec.va + off - sec.raw] = (Q.demangle_rtti(raw), raw)
    data = [s for s in img.sections if not s.is_code and s.raw_size]
    locators: Dict[int, Tuple[str, str]] = {}
    for s in data:
        blob = d[s.raw:s.raw + s.raw_size]
        for off in range(0, len(blob) - 20, 4):
            td = struct.unpack_from("<I", blob, off + 12)[0]
            if td in descriptors:
                sig, offset, cd = struct.unpack_from("<III", blob, off)
                if sig == 0 and offset == 0 and cd == 0:
                    locators[s.va + off] = descriptors[td]
    out: Dict[int, Tuple[str, str]] = {}
    for s in data:
        blob = d[s.raw:s.raw + s.raw_size]
        for off in range(0, len(blob) - 8, 4):
            ptr = struct.unpack_from("<I", blob, off)[0]
            if ptr in locators:
                out[s.va + off + 4] = locators[ptr]
    return out


def vtable_slots(img: BinaryImage, vtable: int, most: int = 256) -> List[int]:
    """The function addresses in a vtable, up to the first entry that isn't code."""
    out = []
    code = img.code_sections()
    for i in range(most):
        raw = img.read(vtable + 4 * i, 4)
        if raw is None:
            break
        va = struct.unpack("<I", raw)[0]
        if not any(c.va <= va < c.va + c.raw_size for c in code):
            break
        out.append(va)
    return out


def word(v: int) -> Optional[str]:
    """A four-letter word (PSYS, BQG, TEX: 2 to 4 capital letters or digits, low byte first), or None."""
    b = struct.pack("<I", v & 0xFFFFFFFF).rstrip(b"\0")
    if 2 <= len(b) <= 4 and b[0] >= 65 and all(48 <= c <= 57 or 65 <= c <= 90 for c in b):
        return b.decode("ascii")
    return None


def chunk_id_like(img: BinaryImage, v: int, known: Set[int]) -> bool:
    """Whether an immediate looks like a chunk id: a known one, or a number from 0x100 to 0x0FFFFFFF
    that is not an address in the program and not a four-letter word."""
    v &= 0xFFFFFFFF
    if v in known:
        return True
    return 0x100 <= v <= 0x0FFFFFFF and img.section_of(v) is None and word(v) is None and v & 0xFF00FF00 != 0


def immediates(img: BinaryImage, start: int, size: int) -> Iterable[Tuple[str, int, Optional[str]]]:
    """(mnemonic, immediate, memory base register for a store) for each instruction of a function."""
    from capstone import x86_const as X
    md = _cs()
    md.detail = True
    blob = img.read(start, size) or b""
    for ins in md.disasm(blob, start):
        mem_base = None
        imm = None
        for op in ins.operands:
            if op.type == X.X86_OP_IMM:
                imm = op.imm & 0xFFFFFFFF
            elif op.type == X.X86_OP_MEM and op.mem.disp == 0 and op.mem.index == 0:
                mem_base = ins.reg_name(op.mem.base) if op.mem.base else None
        if imm is not None:
            yield ins.mnemonic, imm, mem_base
        if ins.mnemonic == "call" and ins.operands and ins.operands[0].type == X.X86_OP_IMM:
            yield "call", ins.operands[0].imm & 0xFFFFFFFF, None


class Program:
    """One program's classes and functions, for the loader questions."""

    def __init__(self, img: BinaryImage):
        self.img = img
        self.vtables = rtti_vtables(img)
        self.starts = sorted(collect_call_targets(img) | {va for vt in self.vtables for va in vtable_slots(img, vt)})
        self.known = {k for k in p3d.NAMES if k > 0xFF}
        self._sizes: Dict[int, int] = {}

    def size(self, start: int) -> int:
        if start not in self._sizes:
            ext = function_extent(self.img, start, max_size=VFUNC_MOST)
            self._sizes[start] = ext.size if ext.ok else 0
        return self._sizes[start]

    def containing(self, va: int) -> Optional[int]:
        i = bisect.bisect_right(self.starts, va) - 1
        return self.starts[i] if i >= 0 else None

    def vtable_writes(self, vtable: int) -> List[int]:
        """Where the code stores this vtable into an object (mov dword [reg], vtable)."""
        pat = re.compile(re.escape(struct.pack("<I", vtable)))
        out = []
        for s in self.img.code_sections():
            if s.name != ".text":                            # the game's own code; not the protection's
                continue
            blob = self.img.data[s.raw:s.raw + s.raw_size]
            for m in pat.finditer(blob):
                o = m.start()
                if o >= 2 and blob[o - 2] == 0xC7 and blob[o - 1] < 8:      # C7 /0, [reg] with no displacement
                    out.append(s.va + o - 2)
        return out

    def written_vtable(self, start: int) -> Optional[str]:
        """The class whose vtable a function (a constructor) writes last into [reg]."""
        last = None
        for mnem, imm, base in immediates(self.img, start, self.size(start) or 64):
            if mnem == "mov" and base and imm in self.vtables:
                last = self.vtables[imm][0]
        return last

    def slot(self, i: int, va: int) -> Slot:
        out = Slot(i, va)
        if self.img.section_of(va) is None or self.size(va) == 0:
            return out
        for mnem, imm, base in immediates(self.img, va, self.size(va)):
            if mnem == "call":
                built = self.written_vtable(imm) if self.size(imm) and self.size(imm) <= CTOR_MOST * 4 else None
                if built and built not in out.builds and built not in BASES:
                    out.builds.append(built)
            elif mnem == "mov" and base and imm in self.vtables:
                if self.vtables[imm][0] not in out.builds and self.vtables[imm][0] not in BASES:
                    out.builds.append(self.vtables[imm][0])
            elif word(imm) and mnem in ("cmp", "mov", "push", "sub"):
                if word(imm) not in out.words:
                    out.words.append(word(imm))
            elif chunk_id_like(self.img, imm, self.known) and imm in self.known and mnem in ("cmp", "mov", "push", "sub"):
                if imm not in out.chunk_ids:
                    out.chunk_ids.append(imm)
        return out

    def loaders(self) -> List[Loader]:
        out = []
        for vt, (cls, raw) in sorted(self.vtables.items(), key=lambda kv: kv[1][0]):
            if not LOADER.search(cls.split("::")[-1].split("<")[0]):
                continue
            ld = Loader(cls, raw, vt)
            for site in self.vtable_writes(vt):
                fn = self.containing(site)
                if fn is None:
                    continue
                if 0 < self.size(fn) <= CTOR_MOST:
                    if fn not in ld.constructors:
                        ld.constructors.append(fn)
                    short = self.size(fn) <= 64              # a plain constructor: its one number is the id
                    for mnem, imm, _base in immediates(self.img, fn, self.size(fn)):
                        if mnem in ("push", "mov") and imm not in self.vtables and imm not in ld.chunk_ids and \
                                (imm in self.known or (short and chunk_id_like(self.img, imm, self.known))):
                            ld.chunk_ids.append(imm)
                elif fn not in ld.registered_by:
                    ld.registered_by.append(fn)
            ld.slots = [self.slot(i, va) for i, va in enumerate(vtable_slots(self.img, vt))]
            for sl in ld.slots:
                sl.builds = [b for b in sl.builds if b != ld.cls]
            out.append(ld)
        return out


def by_chunk(loaders: List[Loader]) -> Dict[str, dict]:
    """{chunk id: {name, loaders, builds}}: the registry turned round."""
    out: Dict[str, dict] = {}
    for ld in loaders:
        built = sorted({b for s in ld.slots for b in s.builds if b != ld.cls})
        for cid in ld.chunk_ids:
            row = out.setdefault(f"0x{cid:08X}", {"name": p3d.NAMES.get(cid, ""), "loaders": [], "builds": []})
            row["loaders"].append(ld.cls)
            row["builds"] += [b for b in built if b not in row["builds"]]
    return dict(sorted(out.items()))


def report(bin_dir: Path) -> dict:
    out = {"what": "chunk loaders read from the program's own RTTI and code (portal/tools/loader_registry.py)",
           "versions": {}}
    for b, name in FILES.items():
        path = bin_dir / name
        if not path.exists():
            continue
        prog = Program(BinaryImage(path))
        loaders = prog.loaders()
        readable = any(ld.chunk_ids for ld in loaders)       # Scarface.exe's .text is packed on disk
        out["versions"][b] = {"file": name, "code_readable": readable,
                              "note": "" if readable else "the classes come from its RTTI, but its code isn't "
                                                          "readable on disk (packed): no constructors or chunk ids",
                              "loaders": [ld.as_json() for ld in loaders], "by_chunk": by_chunk(loaders),
                              "unknown_chunks": sorted(f"0x{c:08X}" for ld in loaders for c in ld.chunk_ids
                                                       if c not in p3d.NAMES)}
    return out


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--bin-dir", type=Path, default=ROOT / "binaries")
    ap.add_argument("--out", type=Path, default=ROOT / "reports" / "loader_registry.json")
    ap.add_argument("--list", metavar="VERSION", choices=sorted(FILES), help="print the table for xb or pc")
    a = ap.parse_args(argv)
    got = report(a.bin_dir)
    if not got["versions"]:
        print(f"Neither default.xbe nor Scarface.exe is in {a.bin_dir}.")
        return 1
    if a.list:
        for cid, row in got["versions"].get(a.list, {}).get("by_chunk", {}).items():
            print(f"{cid}  {row['name'] or '?':32}  {', '.join(row['loaders'])}  ->  {', '.join(row['builds']) or '-'}")
        return 0
    a.out.write_text(json.dumps(got, indent=1) + "\n", encoding="utf-8")
    for b, v in got["versions"].items():
        print(f"{v['file']}: {len(v['loaders'])} loaders and handlers, {len(v['by_chunk'])} chunk ids, "
              f"{len(v['unknown_chunks'])} not yet in p3d.NAMES")
    print(f"written {a.out.relative_to(ROOT) if a.out.is_relative_to(ROOT) else a.out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
