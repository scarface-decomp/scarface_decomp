#!/usr/bin/env python3
"""Give PS2 functions the names of their Xbox twins.

    python portal/scripts/names_to_ps2.py            # list them
    python portal/scripts/names_to_ps2.py --write    # add the new ones to reports/names.json

The portal pairs PS2 functions with Xbox ones when it builds its work list (portal/tools/ps2_pairing.py:
the text only the two of them use, matching places in tables of virtual functions) and keeps the pairing
in reports/full_remaining_queue.json, so run the portal once first. A PS2 function gets its twin's name
when the Xbox function has one in reports/names.json, the pairing says why the two are the same, and no
other PS2 function in the same file claims the same twin.
"""

from __future__ import annotations

import argparse
import json
import re
import sys
from collections import Counter
from pathlib import Path
from typing import Dict, List, Tuple

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "portal" / "tools"))

import names as NAMES  # noqa: E402

BY = "the portal's PS2 to Xbox pairing"
SAME = re.compile(r"Same function as Xbox 0x[0-9A-Fa-f]+: (.+)$")


def twins(tasks: List[dict], names: Dict[str, dict]) -> List[Tuple[str, str, str]]:
    """[(names.json key, name, why)] for PS2 tasks whose Xbox twin is named."""
    xbox = {k[3:].lower(): v["name"] for k, v in names.items() if k.startswith("xb:")}
    found = []
    for t in tasks:
        twin = (t.get("xbox_twin") or "").lower()
        reason = SAME.search(t.get("hint") or "")
        if str(t.get("bin", "")).startswith("ps2") and twin in xbox and reason:
            found.append((t["bin"], t["fva_int"], twin, xbox[twin], reason.group(1).rstrip(".")))
    claims = Counter((b, twin) for b, _va, twin, _n, _r in found)
    out = []
    for b, va, twin, name, reason in found:
        if claims[(b, twin)] != 1:
            continue                                           # two PS2 functions, one twin: not settled
        why = (f"The same function as the Xbox game's {name} (0x{int(twin, 16):08X}): {reason}. "
               "The name is the Xbox function's, from reports/names.json.")
        out.append((f"{b}:0x{va:08X}", name, why))
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--write", action="store_true", help="add the new names to reports/names.json")
    args = ap.parse_args()
    queue = ROOT / "reports" / "full_remaining_queue.json"
    if not queue.exists():
        print("reports/full_remaining_queue.json is not there: start the portal once, which builds it.", file=sys.stderr)
        return 1
    tasks = json.loads(queue.read_text(encoding="utf-8"))
    tasks = tasks if isinstance(tasks, list) else tasks.get("tasks", [])
    path = ROOT / "reports" / "names.json"
    data = NAMES.load(path)
    names = data.setdefault("names", {})
    added = 0
    for key, name, why in twins(tasks, names):
        b = key.split(":")[0]
        if key in names or any(k.startswith(b + ":") and v["name"] == name for k, v in names.items()):
            continue
        added += 1
        if args.write:
            names[key] = {"name": name, "by": BY, "why": why}
        else:
            print(f"  {key}  {name}")
    print(f"{added} PS2 functions take a name from their Xbox twin.")
    if args.write and added:
        path.write_text(json.dumps(data, indent=2, ensure_ascii=False) + "\n", encoding="utf-8", newline="\n")
    return 0


if __name__ == "__main__":
    sys.exit(main())
