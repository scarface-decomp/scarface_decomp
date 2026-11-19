#!/usr/bin/env python3
"""Compile recorded matches again and say whether each still comes out byte for byte. Changes nothing.

    python portal/scripts/recheck_matches.py                  # 300 matches picked at random
    python portal/scripts/recheck_matches.py --sample 2000    # more
    python portal/scripts/recheck_matches.py --all            # every one (hours)
    python portal/scripts/recheck_matches.py --bin xb         # one version: pc, xb or proto

Every match in reports/verified_registry.json was compiled and compared when it was recorded. This
does it again with your compiler (portal/tools/msvc71) and your copy of the game, with the same rules
as the portal: the same length, the same bytes, the calls and data going to the same places, no
hard-coded addresses. The PS2's matches are not covered (another compiler).

It writes work/recheck_matches.md and ends with code 1 when any match no longer comes out the same.
Nothing in the registry is changed: a match that fails here is reported for a maintainer to look at.
"""

from __future__ import annotations

import argparse
import json
import random
import sys
import time
from collections import Counter
from pathlib import Path
from typing import Callable, Dict, List, Optional, Tuple

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "portal" / "tools"))

BINARIES = {"pc": "Scarface.exe", "xb": "default.xbe", "proto": "game.xbe"}
INCLUDES = [ROOT / "reconstructed_src" / "include", ROOT / "reconstructed_src"]


def pick(entries: Dict[str, dict], bins: List[str], sample: Optional[int], seed: int) -> List[str]:
    keys = sorted(k for k, e in entries.items() if e.get("bin") in bins and e.get("code"))
    if sample is None or sample >= len(keys):
        return keys
    return sorted(random.Random(seed).sample(keys, sample))


def check_one(entry: dict, image, known: Dict[str, int], verify: Callable, options: Callable) -> Tuple[bool, str]:
    """(still the same, what was found) for one recorded match."""
    va, size = int(entry["va"], 16), int(entry["size"])
    target = image.read(va, size)
    if target is None or len(target) != size:
        return False, "the game's bytes at that address could not be read"
    best: dict = {}
    for flags in [entry["flags"]] + [f for f in options(entry["bin"], entry["flags"], target) if f != entry["flags"]]:
        r = verify(entry["code"], target, flags, entry.get("match", ""), fn_va=va, image=image, known_names=known,
                   include_dirs=INCLUDES)
        if r.get("ok") and r.get("is_exact") and not r.get("hardcoded_addresses"):
            return True, flags
        if not best or r.get("matched_bytes", -1) > best.get("matched_bytes", -1):
            best = r
    if not best.get("ok"):
        return False, "does not compile: " + (best.get("compiler_error") or "").strip().splitlines()[0][:200] \
            if (best.get("compiler_error") or "").strip() else "does not compile"
    if best.get("hardcoded_addresses"):
        return False, "hard-coded address: " + best["hardcoded_addresses"][0]
    return False, f"{best.get('matched_bytes')}/{best.get('total_bytes')} bytes the same"


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--sample", type=int, default=300, help="how many, picked at random (default 300)")
    ap.add_argument("--all", action="store_true", help="every recorded match")
    ap.add_argument("--bin", choices=sorted(BINARIES), help="only this version")
    ap.add_argument("--seed", type=int, default=int(time.strftime("%Y%m%d")), help="for the random pick")
    args = ap.parse_args(argv)
    from msvc_verify import compiler_version, find_msvc71_bin, flag_options, verify_submission
    from sf_binaries import BinaryImage
    import names as NAMES
    if find_msvc71_bin() is None:
        print("The compiler isn't set up: run python portal/doctor.py and follow what it says.")
        return 2
    bins = [args.bin] if args.bin else [b for b, f in BINARIES.items() if (ROOT / "binaries" / f).is_file()]
    if not bins:
        print("No game program in binaries/: see binaries/README.md.")
        return 2
    entries = json.loads((ROOT / "reports" / "verified_registry.json").read_text(encoding="utf-8"))["entries"]
    keys = pick(entries, bins, None if args.all else args.sample, args.seed)
    images = {b: BinaryImage(ROOT / "binaries" / BINARIES[b]) for b in bins}
    names = NAMES.load(ROOT / "reports" / "names.json")
    known = {b: NAMES.addresses(names, b) for b in bins}
    print(f"{compiler_version()}\nChecking {len(keys)} recorded matches ({', '.join(bins)})...")
    failed: List[Tuple[str, str]] = []
    counts: Counter = Counter()
    started = time.time()
    for n, key in enumerate(keys, 1):
        e = entries[key]
        try:
            same, why = check_one(e, images[e["bin"]], known[e["bin"]], verify_submission, flag_options)
        except Exception as ex:                    # one that can't be checked doesn't stop the rest
            same, why = False, f"could not be checked: {type(ex).__name__}: {ex}"
        counts[(e["bin"], same)] += 1
        if not same:
            failed.append((key, why))
            print(f"  NOT THE SAME  {key}: {why}")
        if n % 25 == 0:
            print(f"  {n}/{len(keys)} checked, {len(failed)} not the same ({time.time() - started:.0f} s)")
    lines = ["# Recorded matches compiled again", "",
             f"{compiler_version()}, {time.strftime('%Y-%m-%d %H:%M')}, "
             f"{'every match' if args.all else f'{len(keys)} picked at random (seed {args.seed})'}.", "",
             "| Version | Still the same | Not the same |", "| :--- | ---: | ---: |"]
    for b in bins:
        lines.append(f"| {b} | {counts[(b, True)]} | {counts[(b, False)]} |")
    lines += [""] + ([f"* `{k}`: {why}" for k, why in failed] or ["Every one came out the same."]) + [""]
    dest = ROOT / "work" / "recheck_matches.md"
    dest.parent.mkdir(parents=True, exist_ok=True)
    dest.write_text("\n".join(lines), encoding="utf-8")
    print(f"\n{len(keys) - len(failed)} of {len(keys)} came out the same. Written: {dest}")
    return 1 if failed else 0


if __name__ == "__main__":
    raise SystemExit(main())
