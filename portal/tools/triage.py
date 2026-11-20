#!/usr/bin/env python3
"""
Which unmatched functions to take next: ranked by how likely a match is per hour of work (the
examiner's question E13), not just by size.

For every function the project's list still has as TODO, from the program's own code and the other
reports:

* **twin matched**: its twin in another build is matched (reports/pairing_*.json): port that C++;
* **folded**: one body shared by several classes' vtables (reports/folded_functions.json): one match
  counts for all of them;
* **x87**: floating-point instructions (MSVC 7.1's x87 stack order is the hardest thing to reproduce);
* **fields**: how many different member offsets it reads and writes (a struct to work out first);
* **calls**, **branches** and its size.

Blockers on the retail Xbox (the examiner's answer to E3: its own code was built without C++ exception
handling, so no unwind states) are inlining, register choice, folding and unknown structs.

    python portal/tools/triage.py xb            write reports/triage_xb.json (best first)
"""

from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path
from typing import Dict, List, Optional

sys.path.insert(0, str(Path(__file__).resolve().parent))
from pairing import FILES, LISTS, listed  # noqa: E402
from sf_binaries import BinaryImage, _cs  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]
LONGEST = 0x2000


def features(img: BinaryImage, va: int, size: int) -> Optional[dict]:
    """Counts that make a function harder or easier to match, or None when its code isn't readable."""
    from capstone import x86_const as X
    blob = img.read(va, size)
    if not blob:
        return None
    md = _cs()
    md.detail = True
    n = x87 = calls = branches = 0
    fields = set()
    seen = 0
    for ins in md.disasm(blob, va):
        n += 1
        seen += ins.size
        if ins.mnemonic.startswith("f") and ins.mnemonic not in ("fs",):
            x87 += 1
        if ins.mnemonic == "call":
            calls += 1
        elif ins.group(X.X86_GRP_JUMP) and ins.mnemonic != "jmp":
            branches += 1
        for op in ins.operands:
            if op.type == X.X86_OP_MEM and op.mem.base and op.mem.base not in (X.X86_REG_ESP, X.X86_REG_EBP) \
                    and 0 < op.mem.disp < 0x1000:
                fields.add(op.mem.disp)
    if seen < size * 0.9:
        return None
    return {"instructions": n, "x87": x87, "calls": calls, "branches": branches, "fields": len(fields)}


def score(size: int, f: dict, twin: bool, shared: int) -> float:
    """Expected matches per hour, roughly: easy and wide-reaching first."""
    base = 60.0 / max(5.0, size ** 0.85)                     # small functions go fast
    base /= 1.0 + 0.15 * f["x87"] + 0.04 * f["fields"] + 0.03 * f["branches"]
    if twin:
        base = max(base * 6.0, 2.0)                          # porting the twin's C++ is mostly renaming
    if shared > 1:
        base *= min(4.0, 1.0 + 0.25 * shared)                # one match, several classes' slots
    return round(base, 3)


def report(b: str, bin_dir: Path, reports: Path, lists: Path) -> dict:
    img = BinaryImage(bin_dir / FILES[b])
    funcs = listed(lists / LISTS[b])
    twins: Dict[int, str] = {}
    for p in reports.glob("pairing_*.json"):
        try:
            got = json.loads(p.read_text(encoding="utf-8"))
        except (OSError, ValueError):
            continue
        cols = got.get("columns") or []
        if b not in cols:
            continue
        me, other = cols.index(b), 1 - cols.index(b)
        for row in got.get("pairs", []):
            if cols[other] in row[4].split("+") and b not in row[4].split("+"):
                twins[int(row[me], 16)] = f"{cols[other]} {row[other]}"
    shared: Dict[int, int] = {}
    try:
        folds = json.loads((reports / "folded_functions.json").read_text(encoding="utf-8"))
        for va, info in folds["versions"].get(b, {}).get("functions", {}).items():
            shared[int(va, 16)] = info["slots"]
    except (OSError, ValueError, KeyError):
        pass
    rows = []
    for va, (size, done) in funcs.items():
        if done or not 0 < size <= LONGEST:
            continue
        f = features(img, va, size)
        if f is None:
            continue
        reasons = []
        if va in twins:
            reasons.append(f"twin matched ({twins[va]})")
        if shared.get(va, 0) > 1:
            reasons.append(f"folded: {shared[va]} class slots")
        if f["x87"]:
            reasons.append(f"x87: {f['x87']}")
        if f["fields"] >= 8:
            reasons.append(f"fields: {f['fields']}")
        rows.append({"va": f"0x{va:08X}", "size": size, "score": score(size, f, va in twins, shared.get(va, 0)),
                     "why": reasons, **f})
    rows.sort(key=lambda r: (-r["score"], r["size"]))
    return {"what": f"unmatched functions of {FILES[b]}, best first by expected matches per hour "
                    "(portal/tools/triage.py; the examiner's question E13)",
            "bin": b, "count": len(rows), "twins": sum(1 for r in rows if any(w.startswith("twin") for w in r["why"])),
            "folded": sum(1 for r in rows if any(w.startswith("folded") for w in r["why"])), "queue": rows}


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("bin", choices=sorted(FILES))
    ap.add_argument("--bin-dir", type=Path, default=ROOT / "binaries")
    ap.add_argument("--out", type=Path)
    ap.add_argument("--most", type=int, default=2500, help="how many of the best to write (default 2500)")
    a = ap.parse_args(argv)
    if not (a.bin_dir / FILES[a.bin]).exists():
        print(f"{FILES[a.bin]} isn't in {a.bin_dir}.")
        return 1
    got = report(a.bin, a.bin_dir, ROOT / "reports", ROOT / "reconstructed_src")
    out = a.out or ROOT / "reports" / f"triage_{a.bin}.json"
    got["listed"] = min(len(got["queue"]), a.most)
    body = ",\n".join(json.dumps(r) for r in got["queue"][:a.most])
    head = json.dumps({k: v for k, v in got.items() if k != "queue"}, indent=1)[:-2]
    out.write_text(head + ',\n "queue": [\n' + body + "\n]}\n", encoding="utf-8")
    print(f"{got['count']:,} unmatched functions ranked; {got['twins']:,} have a matched twin to port, "
          f"{got['folded']:,} are folded bodies. Written {out.name}.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
