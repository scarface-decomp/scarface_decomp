#!/usr/bin/env python3
"""Lists the props whose state entries and frame controllers disagree by place (SPEC-009 section 2.2).

    python portal/scripts/check_prop_order.py extracted/game_files/PC

The game hands a prop's i-th frame controller the state's i-th entry and never compares names; the
exports match them by name. If this prints nothing, the two ways agree on every file it read. Read-only.
"""

from __future__ import annotations

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))

import p3d  # noqa: E402
import p3d_gltf as G  # noqa: E402


def main(argv=None) -> int:
    args = sys.argv[1:] if argv is None else argv
    folder = Path(args[0]) if args else Path("extracted/game_files/PC")
    files = found = 0
    for path in sorted(folder.rglob("*.p3d")):
        try:
            data = path.read_bytes()
            chunks = p3d.read_tree(data)
        except (OSError, p3d.P3dError):
            continue
        files += 1
        for prop, state, i, name, there in G.prop_order_mismatches(data, chunks):
            found += 1
            print(f"{path.relative_to(folder)}: {prop}, state {state}, entry {i}: {name} (by place: {there or 'none'})")
    print(f"{files} files read, {found} entries that name another controller than the one in their place")
    return 0


if __name__ == "__main__":
    sys.exit(main())
