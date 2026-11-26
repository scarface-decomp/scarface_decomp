#!/usr/bin/env python3
"""Take recorded matches out of the registry again, for a stated reason, and keep the record of it.

    python portal/scripts/reopen_matches.py            # apply reports/reopened_matches.json
    python portal/scripts/reopen_matches.py --check    # say what it would do, change nothing

A match is withdrawn when the bytes it was checked against turn out not to be the game's code: so far only
the retail PC game's functions whose first bytes the copy protection replaced with a jump of its own
(docs/GAME_VERSIONS.md). reports/reopened_matches.json lists each one with the reason; this script removes
them from reports/verified_registry.json and fills in who had recorded it and when, so nothing is lost
from the record. Then run `python portal/tools/registry_outputs.py` to bring the generated files in line.
The repository check refuses a registry that still holds a withdrawn match.
"""

from __future__ import annotations

import argparse
import json
import os
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
REGISTRY = ROOT / "reports" / "verified_registry.json"
REOPENED = ROOT / "reports" / "reopened_matches.json"
KEPT = ("size", "symbol", "verified_by", "verified_at", "tool_used", "flags")


def apply(registry: dict, reopened: dict) -> list:
    """Remove every listed match from registry["entries"], copying who/when/what into its row. Returns the keys
    removed this time."""
    removed = []
    entries = registry.get("entries", {})
    for row in reopened.get("matches", []):
        e = entries.pop(row["key"], None)
        if e is None:
            continue
        row["was"] = {k: e[k] for k in KEPT if k in e}
        removed.append(row["key"])
    return removed


def write_json(path: Path, obj) -> None:
    tmp = path.with_suffix(path.suffix + ".tmp")
    tmp.write_text(json.dumps(obj, indent=2), encoding="utf-8")
    os.replace(tmp, path)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--check", action="store_true", help="say what would be removed and change nothing")
    args = ap.parse_args()
    registry = json.loads(REGISTRY.read_text(encoding="utf-8"))
    reopened = json.loads(REOPENED.read_text(encoding="utf-8"))
    removed = apply(registry, reopened)
    for key in removed:
        print("withdrawn:", key)
    if not removed:
        print("Nothing to do: none of the listed matches is in the registry.")
        return 0
    if args.check:
        print(f"{len(removed)} match(es) would be withdrawn. Run without --check to do it.")
        return 0
    write_json(REGISTRY, registry)
    write_json(REOPENED, reopened)
    print(f"{len(removed)} match(es) withdrawn. Now run: python portal/tools/registry_outputs.py")
    return 0


if __name__ == "__main__":
    sys.exit(main())
