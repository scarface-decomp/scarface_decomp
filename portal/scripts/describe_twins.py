#!/usr/bin/env python3
"""Copy the one-line descriptions of rebuilt Xbox functions to their rebuilt twins in the prototype and the
PC, where the twin is the same code.

The twins come from reports/pairing_xb_proto.json and reports/pairing_xb_pc.json (portal/tools/pairing.py).
Only pairs found by "shape" are used: the same instructions, registers and small numbers (offsets, sizes)
on both sides, only addresses differing. Twins paired by their strings, their calls or their place in the
file can differ in what they do, so their descriptions are left to be written. A twin is also left out
when its class name differs from the Xbox function's, since the sentence may name the class.

    python portal/scripts/describe_twins.py          write reports/to_submit/descriptions_twins.json
    python portal/scripts/submit_descriptions.py     then send it to the portal (a maintainer)

Each copied description keeps its words; it is credited to whoever wrote the Xbox one, with
"(from the Xbox twin)", and counted as "twin" on the website.
"""

from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "portal" / "tools"))
import descriptions as DESC  # noqa: E402

OUT = ROOT / "reports" / "to_submit" / "descriptions_twins.json"
SUFFIX = " (from the Xbox twin)"


def owner(symbol: str) -> str:
    """The class part of a symbol ("" for a free function)."""
    return symbol.rsplit("::", 1)[0] if "::" in symbol else ""


def plan(entries: dict, pairings: dict) -> dict:
    """{key: {"what", "by", "how": "twin", "from"}} for every rebuilt twin that can take its Xbox description."""
    out = {}
    for other, pairing in pairings.items():
        for row in pairing.get("pairs", []):
            xb_va, other_va, how = row[0], row[1], row[3]
            if how != "shape":
                continue
            src, dst = entries.get(f"xb:{xb_va}"), entries.get(f"{other}:{other_va}")
            if not src or not dst or not (src.get("what") or "").strip() or (dst.get("what") or "").strip():
                continue
            if DESC.how_of(src) == "twin":
                continue                                    # only first-hand descriptions are copied
            a, b = owner(src.get("symbol", "")), owner(dst.get("symbol", ""))
            if a and b and a != b:
                continue
            by = str(src.get("what_by") or src.get("verified_by") or "unknown")
            out[f"{other}:{other_va}"] = {"what": src["what"], "by": (by[:64 - len(SUFFIX)] + SUFFIX),
                                          "how": "twin", "from": f"xb:{xb_va}"}
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--out", default=str(OUT))
    args = ap.parse_args()
    entries = json.loads((ROOT / "reports" / "verified_registry.json").read_text(encoding="utf-8"))["entries"]
    pairings = {}
    for other in ("proto", "pc"):
        path = ROOT / "reports" / f"pairing_xb_{other}.json"
        if path.exists():
            pairings[other] = json.loads(path.read_text(encoding="utf-8"))
    notes = plan(entries, pairings)
    if not notes:
        print("Nothing to copy: every rebuilt same-code twin of a described Xbox function is described already.")
        return 0
    Path(args.out).parent.mkdir(parents=True, exist_ok=True)
    Path(args.out).write_text(json.dumps({"schema": "scarface_descriptions_v1", "by": "copied from the Xbox twin",
                                          "descriptions": notes}, indent=1, ensure_ascii=False) + "\n",
                              encoding="utf-8")
    per = {}
    for k in notes:
        per[k.split(":")[0]] = per.get(k.split(":")[0], 0) + 1
    print(f"{len(notes)} descriptions to copy ({', '.join(f'{n} {b}' for b, n in sorted(per.items()))}) -> "
          f"{Path(args.out).relative_to(ROOT) if Path(args.out).is_relative_to(ROOT) else args.out}")
    print("Send them with: python portal/scripts/submit_descriptions.py")
    return 0


if __name__ == "__main__":
    sys.exit(main())
