#!/usr/bin/env python3
"""
Shared engine code: Scarface's Xbox functions that are also in another Radical Entertainment game built
with the same Xbox kit and compiler, byte for byte once the addresses in them are set aside.

Radical's other 2005 Xbox games (Crash Tag Team Racing, The Incredible Hulk: Ultimate Destruction) were
built on the same engine with Xbox SDK 5849. A function that is in one of them too is engine code, not
code written for Scarface. None of those games has debug symbols, so this gives no names; it says which
open functions are the engine's, which is where a spec written from older engine source is most likely to
apply, and it carries a lead from one game to the next.

It also reads the `.XTLID` section some Xbox programs still carry: a list of (library, number, address)
for the Microsoft library functions linked in. Where one of those functions is also in Scarface, the
number says which library function Scarface's copy is.

    python portal/tools/sibling_twins.py --sibling crash=PATH/default.xbe --sibling hulk=PATH/default.xbe
        writes reports/sibling_twins.json from your own copies of those games

Addresses, sizes and Microsoft's library numbers only: nothing from any game's files is written.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import struct
import sys
import time
from collections import defaultdict
from pathlib import Path
from typing import Dict, List, Optional, Set, Tuple

HERE = Path(__file__).resolve().parent
if str(HERE) not in sys.path:
    sys.path.insert(0, str(HERE))
if str(HERE.parent) not in sys.path:
    sys.path.insert(0, str(HERE.parent))

import hidden_starts as HS                                                   # noqa: E402
import lookalikes as LA                                                      # noqa: E402
from sf_binaries import BinaryImage, collect_call_targets, function_extent   # noqa: E402

ROOT = HERE.parent.parent
OUT = ROOT / "reports" / "sibling_twins.json"
MIN_SIZE = 16           # shorter functions (a `ret`, a getter) are the same in every program


def shapes(img: BinaryImage, starts: Set[int], known: Optional[Set[int]] = None) -> Dict[int, Tuple[str, int]]:
    """{start: (shape, size)} for every start whose extent can be worked out. Same shape = same code apart
    from the addresses in it (lookalikes.signature)."""
    known = known if known is not None else starts
    out: Dict[int, Tuple[str, int]] = {}
    for va in sorted(starts):
        e = function_extent(img, va, known)
        if not e.ok or e.size < 1:
            continue
        code = img.read(va, e.size)
        if not code:
            continue
        try:
            shape, relocs = LA.signature(code, va, img)
        except Exception:
            continue
        out[va] = (shape, e.size)
        _ADDRESSES.setdefault(id(img), {})[va] = [r.offset for r in relocs]     # for identities(): found once
    return out


def own_starts(img: BinaryImage) -> Set[int]:
    """The function starts a program shows by itself: every call target and every vtable slot in its own
    code section."""
    im = HS.Img(img)
    starts = {t for t in collect_call_targets(img) if im.code(t)}
    for _vt, _off, slots in HS.vtables(im):
        starts.update(s for s in slots if im.code(s))
    return starts


def twins(target: Dict[int, Tuple[str, int]], siblings: Dict[str, Dict[int, Tuple[str, int]]],
          min_size: int = MIN_SIZE) -> Dict[int, dict]:
    """{va: {"size": n, "in": {sibling: its address there, or None when several functions there have the
    shape}}} for every function of the target at least min_size bytes long that a sibling has too."""
    by_shape: Dict[str, Dict[str, List[int]]] = {}
    for key, funcs in siblings.items():
        d: Dict[str, List[int]] = defaultdict(list)
        for va, (shape, _size) in funcs.items():
            d[shape].append(va)
        by_shape[key] = d
    out: Dict[int, dict] = {}
    for va, (shape, size) in target.items():
        if size < min_size:
            continue
        found = {key: (d[shape][0] if len(d[shape]) == 1 else None) for key, d in by_shape.items() if shape in d}
        if found:
            out[va] = {"size": size, "in": found}
    return out


def xtl_ids(img: BinaryImage) -> List[Tuple[int, int, int]]:
    """(library, number, address) for every entry of the program's `.XTLID` section; [] when it has none.
    The section is a list of pairs: an id (library in the high half, number in the low half) and the
    address of that library function in this program."""
    sec = next((s for s in img.sections if s.name == ".XTLID"), None)
    if sec is None:
        return []
    raw = img.data[sec.raw:sec.raw + sec.raw_size]
    out = []
    for at in range(0, len(raw) - 7, 8):
        ident, va = struct.unpack_from("<II", raw, at)
        if img.section_of(va) is not None:
            out.append((ident >> 16, ident & 0xFFFF, va))
    return out


_IDENTITIES: Dict[int, tuple] = {}
_ADDRESSES: Dict[int, Dict[int, List[int]]] = {}       # {id(image): {start: where its code holds addresses}}
KERNEL_KEYS = (0x5B6D40B6, 0xEFB1F152)       # what a retail and a debug program XOR the table's address with
STUB = 32                                    # up to this many bytes a function is mostly the addresses in it


def kernel_cells(img: BinaryImage) -> Dict[int, int]:
    """{address of an import cell: the number of the kernel function it stands for}. An Xbox program reaches
    the kernel through a table of cells the loader fills in; in the file each cell holds 0x80000000 + the
    kernel function's number and a zero ends the table. The header gives the table's address at 0x158,
    XORed with a key. {} for a program without one."""
    head = img.data[0x158:0x15C]
    if len(head) < 4 or img.data[:4] != b"XBEH":
        return {}
    for key in KERNEL_KEYS:
        at = struct.unpack("<I", head)[0] ^ key
        if img.section_of(at) is None:
            continue
        out: Dict[int, int] = {}
        while len(out) < 512:
            raw = img.read(at + 4 * len(out), 4)
            cell = struct.unpack("<I", raw)[0] if raw and len(raw) == 4 else 0
            if not cell & 0x80000000:
                break
            out[at + 4 * len(out)] = cell & 0x7FFFFFFF
        if out:
            return out
    return {}


def identities(img: BinaryImage, mine: Dict[int, Tuple[str, int]]) -> Dict[int, str]:
    """{start: identity}: the shape, plus what the shape leaves out and a library function is told by. Two
    library functions can be the same bytes apart from one address: which kernel function they reach
    (`mov eax, [cell]; mov eax, [eax]; ret` is both GetTickCount and XGetAVPack), or which function a
    forwarder calls. So the identity adds the kernel functions' numbers, in the order the code uses them,
    and for a function of up to STUB bytes the same of each function it calls."""
    cached = _IDENTITIES.get(id(img))
    if cached is not None and cached[0] is mine:
        return cached[1]
    cells = kernel_cells(img)
    first: Dict[int, str] = {}
    calls: Dict[int, List[int]] = {}
    for va, (shape, size) in mine.items():
        code = img.read(va, size) or b""
        offsets = _ADDRESSES.get(id(img), {}).get(va)
        if offsets is None:
            try:
                offsets = [r.offset for r in LA.signature(code, va, img)[1]]
            except Exception:
                offsets = []
        reached = []
        for at in offsets:
            if at + 4 > len(code):
                continue
            value = struct.unpack_from("<I", code, at)[0]
            if value in cells:
                reached.append(f"|k{cells[value]}")
            elif size <= STUB and at and code[at - 1] in (0xE8, 0xE9):
                calls.setdefault(va, []).append((va + at + 4 + struct.unpack_from("<i", code, at)[0]) & 0xFFFFFFFF)
        first[va] = shape + "".join(reached)
    out = {va: ident + "".join("|c" + hashlib.sha1(first.get(callee, "?").encode("ascii")).hexdigest()[:12]
                               for callee in calls.get(va, []))
           for va, ident in first.items()}
    _IDENTITIES[id(img)] = (mine, out)          # one program's shapes are asked about once for each sibling
    return out


def library_ids(target: Dict[int, Tuple[str, int]], sibling_img: BinaryImage,
                sibling: Dict[int, Tuple[str, int]], target_img: Optional[BinaryImage] = None
                ) -> Dict[int, List[Tuple[int, int]]]:
    """{target va: [(library, number), ...]} for the sibling's numbered library functions that the target has
    too, where exactly one target function has the same identity (identities: the shape, the kernel
    functions it reaches and, for a stub, what it calls). Without `target_img` only the shape is compared.
    Two numbers on one address means the sibling has two library functions that cannot be told apart."""
    theirs = identities(sibling_img, sibling)
    mine = identities(target_img, target) if target_img is not None else {va: v[0] for va, v in target.items()}
    if target_img is None:
        theirs = {va: v[0] for va, v in sibling.items()}
    by_identity: Dict[str, List[int]] = defaultdict(list)
    for va, ident in mine.items():
        by_identity[ident].append(va)
    out: Dict[int, List[Tuple[int, int]]] = defaultdict(list)
    for lib, number, va in xtl_ids(sibling_img):
        if va in theirs and len(by_identity.get(theirs[va], [])) == 1:
            out[by_identity[theirs[va]][0]].append((lib, number))
    return dict(out)


def merge_library_ids(per_sibling: Dict[str, Dict[int, List[Tuple[int, int]]]], names: Dict[int, Optional[str]]) -> List[dict]:
    """One row per function: its numbers, which siblings' lists gave them, and the name the project already
    has for it. Ordered by library and number, which is the order of the public headers."""
    ids: Dict[int, Set[Tuple[int, int]]] = defaultdict(set)
    who: Dict[int, Set[str]] = defaultdict(set)
    for key, found in per_sibling.items():
        for va, pairs in found.items():
            ids[va].update(pairs)
            who[va].add(key)
    rows = []
    for va in ids:
        row = {"va": f"0x{va:08X}", "ids": [{"library": lib, "number": n} for lib, n in sorted(ids[va])],
               "from": sorted(who[va])}
        if names.get(va):
            row["name"] = names[va]
        rows.append(row)
    return sorted(rows, key=lambda r: (r["ids"][0]["library"], r["ids"][0]["number"], r["va"]))


def describe(key: str, path: Path, img: BinaryImage) -> dict:
    d = img.data
    base = struct.unpack_from("<I", d, 0x104)[0]
    stamp = struct.unpack_from("<I", d, 0x114)[0]
    count, at = struct.unpack_from("<II", d, 0x160)
    sdk = sorted({struct.unpack_from("<H", d, at - base + 16 * i + 12)[0] for i in range(count)})
    cert = struct.unpack_from("<I", d, 0x118)[0] - base
    title = d[cert + 0xC:cert + 0x5C].decode("utf-16-le", "replace").rstrip("\0")
    return {"key": key, "title": title, "built": time.strftime("%Y-%m-%d", time.gmtime(stamp)), "sdk": sdk,
            "sha1": hashlib.sha1(d).hexdigest(), "library_ids": len(xtl_ids(img))}


def build(bin_dir: Path, sibling_paths: Dict[str, Path], progress=print) -> dict:
    names = {}
    try:
        names = json.loads((ROOT / "reports" / "names.json").read_text(encoding="utf-8"))["names"]
    except (OSError, ValueError, KeyError):
        pass
    sib_imgs = {key: BinaryImage(p) for key, p in sibling_paths.items()}
    sib_shapes = {}
    for key, img in sib_imgs.items():
        progress(f"reading {key} ...")
        sib_shapes[key] = shapes(img, own_starts(img))
    out = {"schema": "scarface_sibling_twins_v1",
           "what": "Scarface Xbox functions that another Radical Entertainment Xbox game has too, byte for byte "
                   "once the addresses in them are set aside (portal/tools/sibling_twins.py): shared engine code. "
                   "Functions under 16 bytes and Microsoft's library functions are left out. `in` gives the "
                   "function's address in each sibling's program (null when several functions there are the same). "
                   "library_ids: Microsoft library functions a sibling's own `.XTLID` list numbers, found in "
                   "Scarface by the same comparison; the numbers follow the order of the public Windows and Xbox "
                   "headers, so a function between two named ones is the one declared between them. Leads to "
                   "check, made from the founder's own copies of the games. No game bytes.",
           "siblings": [describe(key, sibling_paths[key], img) for key, img in sib_imgs.items()],
           "functions": {}, "library_ids": {}}
    for b, fname in HS.FILES.items():
        p = bin_dir / fname
        if not p.is_file():
            continue
        img = BinaryImage(p)
        known, not_game = HS.known_starts(HS.Img(img), b)
        progress(f"reading {b} ...")
        mine = shapes(img, known, known)
        game = {va: v for va, v in mine.items() if va not in not_game}
        found = twins(game, sib_shapes)
        out["functions"][b] = [{"va": f"0x{va:08X}", "size": d["size"],
                                "in": {k: (f"0x{v:08X}" if v is not None else None) for k, v in sorted(d["in"].items())}}
                               for va, d in sorted(found.items())]
        per_sibling = {key: library_ids(mine, simg, sib_shapes[key], img) for key, simg in sib_imgs.items()}
        out["library_ids"][b] = merge_library_ids(per_sibling, {int(k.split(":")[1], 16): v.get("name")
                                                                for k, v in names.items() if k.startswith(b + ":")})
    return out


def open_by_class(report: dict, tasks: List[dict], verified: Set[str], b: str = "xb") -> List[dict]:
    """The shared functions of one program that are still open, by the class whose table they sit in
    (the queue's `Class::vfunc_NN` symbols; everything else is under ""), most bytes first. For choosing
    which class to describe next: a class here is engine code that older source of the same engine may fit."""
    by_va = {t["fva_int"]: t for t in tasks if t.get("bin") == b and "fva_int" in t}
    groups: Dict[str, List[dict]] = defaultdict(list)
    for row in report.get("functions", {}).get(b, []):
        va = int(row["va"], 16)
        t = by_va.get(va)
        if t is None or f"{b}:0x{va:08X}" in verified:
            continue
        cls = t["symbol"].rsplit("::", 1)[0] if "::" in t.get("symbol", "") else ""
        groups[cls].append({"va": row["va"], "size": int(row["size"])})
    out = [{"class": cls, "open": len(rows), "bytes": sum(r["size"] for r in rows),
            "functions": [r["va"] for r in sorted(rows, key=lambda r: r["va"])]}
           for cls, rows in groups.items()]
    return sorted(out, key=lambda r: (r["class"] == "", -r["bytes"], r["class"]))


def write_classes(report_path: Path, out_path: Path) -> int:
    report = json.loads(report_path.read_text(encoding="utf-8"))
    tasks = json.loads((ROOT / "reports" / "full_remaining_queue.json").read_text(encoding="utf-8"))
    verified = set(json.loads((ROOT / "reports" / "verified_registry.json").read_text(encoding="utf-8"))["entries"])
    for waiting in (ROOT / "reports" / "to_submit").glob("*_????????.cpp"):       # matched, not recorded yet
        b, _, va = waiting.stem.partition("_")
        verified.add(f"{b}:0x{va}")
    rows = open_by_class(report, tasks, verified)
    out = {"schema": "scarface_open_shared_by_class_v1",
           "what": "Open Xbox functions that a sibling game has too (reports/sibling_twins.json), by the class whose "
                   "table they sit in, most bytes first; the last row is the ones in no table. Written by "
                   "portal/tools/sibling_twins.py --classes from the work queue, the registry and the matches "
                   "waiting in reports/to_submit on the day in `as_of`; it is a snapshot for planning and goes "
                   "out of date as functions are matched.",
           "as_of": time.strftime("%Y-%m-%d"), "classes": len([r for r in rows if r["class"]]),
           "open": sum(r["open"] for r in rows), "bytes": sum(r["bytes"] for r in rows), "xb": rows}
    out_path.write_text(json.dumps(out, indent=1) + "\n", encoding="utf-8")
    print(f"{out['open']:,} open shared functions ({out['bytes']:,} bytes) in {out['classes']:,} classes -> {out_path.name}")
    return 0


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--sibling", action="append", default=[], metavar="KEY=PATH",
                    help="another game's default.xbe from your own copy, e.g. crash=D:/ctr/default.xbe")
    ap.add_argument("--bin-dir", type=Path, default=ROOT / "binaries")
    ap.add_argument("--out", type=Path, default=OUT)
    ap.add_argument("--classes", action="store_true",
                    help="from the report already written, list the open shared functions by class "
                         "(reports/open_shared_by_class.json); needs no sibling program")
    a = ap.parse_args(argv)
    if a.classes:
        return write_classes(a.out, a.out.with_name("open_shared_by_class.json"))
    paths = {}
    for s in a.sibling:
        key, _, p = s.partition("=")
        if not key or not Path(p).is_file():
            print(f"--sibling {s}: give KEY=PATH to a default.xbe")
            return 1
        paths[key] = Path(p)
    if not paths:
        print("Give at least one --sibling KEY=PATH.")
        return 1
    report = build(a.bin_dir, paths)
    a.out.write_text(json.dumps(report, indent=1) + "\n", encoding="utf-8")
    for b, rows in report["functions"].items():
        print(f"{b}: {len(rows):,} functions shared with a sibling; {len(report['library_ids'].get(b, [])):,} "
              f"numbered library functions")
    return 0


if __name__ == "__main__":
    sys.exit(main())
