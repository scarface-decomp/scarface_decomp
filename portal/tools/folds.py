#!/usr/bin/env python3
"""
Folded functions: one body the linker kept for many (the examiner's question E2).

The Microsoft linker folds identical functions into one (/OPT:ICF): an empty destructor, a "return 0"
virtual, the same template made for two classes. Every class whose vtable points at that one address
then shares it. Matching that body once must not be credited to one class's method: the C++ that
matches it is the same for all of them, and its name is only one of theirs.

This lists, from the program's own RTTI and vtables, every function that sits in the vtables of two or
more different classes, and in which slot of each:

    python portal/tools/folds.py              write reports/folded_functions.json

Only addresses, class names (the game's own RTTI) and slot numbers go into the report.
"""

from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path
from typing import Dict, List, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parent))
from loader_registry import FILES, rtti_vtables, vtable_slots  # noqa: E402
from sf_binaries import BinaryImage  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]
FILES = dict(FILES, proto="game.xbe")
SOME = 6                                          # class slots named per function in the report


def folded(img: BinaryImage) -> Dict[int, List[Tuple[str, int]]]:
    """{function: [(class, slot), ...]} for every function in the vtables of two or more classes."""
    users: Dict[int, List[Tuple[str, int]]] = {}
    for vt, (cls, _raw) in rtti_vtables(img).items():
        for slot, va in enumerate(vtable_slots(img, vt)):
            users.setdefault(va, [])
            if (cls, slot) not in users[va]:
                users[va].append((cls, slot))
    return {va: sorted(u) for va, u in users.items() if len({c for c, _s in u}) > 1}


def report(bin_dir: Path) -> dict:
    out = {"what": "functions shared by the vtables of several classes: one body, folded by the linker "
                   "(portal/tools/folds.py; the examiner's question E2)", "versions": {}}
    for b, name in FILES.items():
        path = bin_dir / name
        if not path.exists():
            continue
        got = folded(BinaryImage(path))
        out["versions"][b] = {"file": name, "folded": len(got),
                              "functions": {f"0x{va:08X}": {"slots": len(u), "classes": len({c for c, _s in u}),
                                                            "some": [f"{c}::vfunc_{s:02d}" for c, s in u[:SOME]]}
                                            for va, u in sorted(got.items())}}
    return out


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--bin-dir", type=Path, default=ROOT / "binaries")
    ap.add_argument("--out", type=Path, default=ROOT / "reports" / "folded_functions.json")
    a = ap.parse_args(argv)
    got = report(a.bin_dir)
    if not got["versions"]:
        print(f"No game program in {a.bin_dir}.")
        return 1
    a.out.write_text(json.dumps(got, indent=1) + "\n", encoding="utf-8")
    for b, v in got["versions"].items():
        users = sum(u["slots"] for u in v["functions"].values())
        print(f"{v['file']}: {v['folded']:,} functions are shared by {users:,} class slots")
    print(f"written {a.out.name}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
