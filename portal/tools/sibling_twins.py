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
            shape, _relocs = LA.signature(code, va, img)
        except Exception:
            continue
        out[va] = (shape, e.size)
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


def library_ids(target: Dict[int, Tuple[str, int]], sibling_img: BinaryImage,
                sibling: Dict[int, Tuple[str, int]]) -> Dict[int, List[Tuple[int, int]]]:
    """{target va: [(library, number), ...]} for the sibling's numbered library functions that the target has
    too, where exactly one target function has the shape. Two numbers on one address means the sibling has
    two library functions of that shape (they differ only in which kernel function they call)."""
    by_shape: Dict[str, List[int]] = defaultdict(list)
    for va, (shape, _size) in target.items():
        by_shape[shape].append(va)
    out: Dict[int, List[Tuple[int, int]]] = defaultdict(list)
    for lib, number, va in xtl_ids(sibling_img):
        if va in sibling and len(by_shape.get(sibling[va][0], [])) == 1:
            out[by_shape[sibling[va][0]][0]].append((lib, number))
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
        per_sibling = {key: library_ids(mine, simg, sib_shapes[key]) for key, simg in sib_imgs.items()}
        out["library_ids"][b] = merge_library_ids(per_sibling, {int(k.split(":")[1], 16): v.get("name")
                                                                for k, v in names.items() if k.startswith(b + ":")})
    return out


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--sibling", action="append", default=[], metavar="KEY=PATH",
                    help="another game's default.xbe from your own copy, e.g. crash=D:/ctr/default.xbe")
    ap.add_argument("--bin-dir", type=Path, default=ROOT / "binaries")
    ap.add_argument("--out", type=Path, default=OUT)
    a = ap.parse_args(argv)
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
