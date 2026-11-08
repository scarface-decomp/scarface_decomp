#!/usr/bin/env python3
"""
Copy the game's script files out of your own cement.rcf, for the script work (docs/SCRIPTS.md).

    python scripts/extract_scripts.py "C:\\Games\\Scarface\\cement.rcf"

Writes every .cso, .dso, .dtr (and any .cs / .ds source left in the archive) into binaries/scripts_and_data/,
keeping the archive's folders, where the portal's Scripts tab finds them. binaries/ is never committed, so the files stay on your computer.
Use --list to only show what is there.
"""

from __future__ import annotations

import argparse
import collections
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

from rcf import SCRIPT_EXTENSIONS, RcfError, open_rcf, safe_output_path  # noqa: E402


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("rcf", type=Path, help="path to cement.rcf from your own copy of the game")
    ap.add_argument("--out", type=Path, default=ROOT / "binaries" / "scripts_and_data")
    ap.add_argument("--list", action="store_true", help="list the script files without extracting")
    a = ap.parse_args(argv)
    if not a.rcf.is_file():
        print(f"Not found: {a.rcf}")
        return 1
    try:
        arc = open_rcf(a.rcf)
    except (RcfError, OSError) as e:
        print(f"Could not read {a.rcf}: {e}")
        return 1
    found = list(arc.find(SCRIPT_EXTENSIONS))
    kinds = collections.Counter(Path(e.name).suffix.lower() for e in found)
    print(f"{a.rcf.name}: {len(arc.entries):,} files, {len(found):,} of them scripts "
          + ", ".join(f"{n} {k}" for k, n in sorted(kinds.items())))
    if a.list:
        for e in found:
            print(f"  {e.size:>8,}  {e.name}")
        return 0
    written = 0
    for e in found:
        out = safe_output_path(a.out, e.name)
        if out is None:
            print(f"  skipped unsafe name: {e.name!r}")
            continue
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_bytes(arc.read(e))
        written += 1
    print(f"Wrote {written:,} files to {a.out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
