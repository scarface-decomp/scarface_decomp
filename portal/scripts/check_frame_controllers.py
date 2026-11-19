#!/usr/bin/env python3
"""Counts every frame controller (0x121201) in your game files by cycle mode, cycles and "for ever", and
lists any that do not play "as the animation says" (SPEC-011 section 3: every one seen so far is ANIM, 0
cycles, for ever). Read-only.

    python portal/scripts/check_frame_controllers.py extracted/game_files/PC
"""

from __future__ import annotations

import sys
from collections import Counter
from pathlib import Path
from typing import List, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))

import p3d  # noqa: E402

MARK = b"\x01\x12\x12\x00"                       # the chunk id as it sits in the file


def controllers(folder: Path) -> Tuple[Counter, Counter, List[Tuple[str, str, str]]]:
    """(count by mode/cycles/for ever/version, count by type, the ones not ANIM/0/for ever)."""
    modes, types, odd = Counter(), Counter(), []
    for path in sorted(folder.rglob("*.p3d")):
        try:
            data = path.read_bytes()
        except OSError:
            continue
        if MARK not in data:
            continue
        try:
            tree = p3d.read_tree(data)
        except p3d.P3dError:
            continue
        for c in p3d.walk(tree):
            if c.id != 0x121201:
                continue
            f = p3d.fields(data, c)
            key = f"{f['cycle mode']}/{f['cycles']}/{'for ever' if f['for ever'] else 'counted'}/v{f['version']}"
            modes[key] += 1
            types[f["type"]] += 1
            if f["mode"] or f["cycles"] or not f["for ever"]:
                odd.append((str(path.relative_to(folder)), f["name"], key))
    return modes, types, odd


def main(argv=None) -> int:
    args = sys.argv[1:] if argv is None else argv
    folder = Path(args[0]) if args else Path("extracted/game_files/PC")
    modes, types, odd = controllers(folder)
    print("by mode/cycles/for ever/version:", dict(modes))
    print("by type:", dict(types))
    for path, name, key in odd:
        print(f"{path}: {name} plays {key}")
    print(f"{sum(modes.values())} frame controllers, {len(odd)} not ANIM/0/for ever")
    return 0


if __name__ == "__main__":
    sys.exit(main())
