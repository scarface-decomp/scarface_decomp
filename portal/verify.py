#!/usr/bin/env python3
"""
Command-line verifier: same rules as the portal, for people who work in their own editor.

    python portal/verify.py --status
    python portal/verify.py my_func.cpp --va 0x006DE620 --bin pc
    python portal/verify.py my_func.cpp --va 0x00011F20 --bin xb --match vfunc_03@Collidable@ --show-diff

The function size is taken from the work queue when the address is in it, otherwise from
disassembling the original (override with --size).
"""

from __future__ import annotations

import argparse
import json
import sys
from collections import Counter
from pathlib import Path

PORTAL = Path(__file__).resolve().parent
ROOT = PORTAL.parent                      # the project folder
sys.path.insert(0, str(PORTAL / "tools"))

BINARIES = {"pc": ROOT / "binaries" / "Scarface.exe", "xb": ROOT / "binaries" / "default.xbe",
            "proto": ROOT / "binaries" / "game.xbe"}
REGISTRY = ROOT / "reports" / "verified_registry.json"
QUEUE = ROOT / "reports" / "full_remaining_queue.json"
DEFAULT_FLAGS = "/O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4"


def status() -> int:
    reg = json.loads(REGISTRY.read_text(encoding="utf-8")) if REGISTRY.exists() else {"entries": {}}
    entries = reg.get("entries", {})
    queue = json.loads(QUEUE.read_text(encoding="utf-8")) if QUEUE.exists() else []
    open_tasks = [t for t in queue if f"{t.get('bin')}:0x{t.get('fva_int', 0):08X}" not in entries]
    remaining = sum(1 for t in open_tasks if t.get("bin") != "proto")      # the retail game, as the portal counts it
    proto_left = len(open_tasks) - remaining
    by_bin = Counter(e["bin"] for e in entries.values())
    retail = by_bin.get("pc", 0) + by_bin.get("xb", 0)
    total = remaining + retail
    print("=" * 72)
    print(" SCARFACE: THE WORLD IS YOURS — MATCHING DECOMP STATUS")
    print("=" * 72)
    print(f" Compiler           : {reg.get('compiler', 'unknown')}")
    print(f" Verified functions : {retail:,}  (PC {by_bin.get('pc', 0):,}, Xbox {by_bin.get('xb', 0):,})")
    print(f" Work queue         : {remaining:,} functions")
    if total:
        print(f" Progress           : {retail / total * 100:.2f}% of {total:,} indexed functions")
    if by_bin.get("proto", 0) or proto_left:
        print(f" Xbox prototype     : {by_bin.get('proto', 0):,} of {by_bin.get('proto', 0) + proto_left:,} (unreleased code, counted on its own)")
    print(f" Verified bytes     : {sum(int(e.get('size', 0)) for e in entries.values()):,}")
    print("-" * 72)
    board = Counter((e.get("verified_by") or "Imported (unattributed)") for e in entries.values())
    for i, (u, n) in enumerate(board.most_common(10), 1):
        print(f"   #{i:<2} {u:<34} {n:,}")
    print("=" * 72)
    return 0


def check(args) -> int:
    from msvc_verify import verify_submission, compiler_version
    from sf_binaries import BinaryImage, collect_call_targets, function_extent
    b = args.bin
    if not BINARIES[b].exists():
        print(f"binaries/{BINARIES[b].name} is missing; see binaries/README.md.")
        return 2
    from game_files import refusal
    problem = refusal(BINARIES[b])
    if problem:
        print(problem)
        return 2
    img = BinaryImage(BINARIES[b])
    va = int(args.va, 16)
    size = args.size
    match = args.match or ""
    flags = args.flags
    if QUEUE.exists() and not size:
        for t in json.loads(QUEUE.read_text(encoding="utf-8")):
            if t.get("bin") == b and t.get("fva_int") == va:
                size = t["size"]
                match = match or t.get("match_substr", "")
                flags = args.flags if args.flags != DEFAULT_FLAGS else t.get("flags", flags)
                break
    if not size:
        ext = function_extent(img, va, collect_call_targets(img))
        if not ext.ok:
            print(f"Could not size the function at 0x{va:08X}: {ext.reason}. Pass --size.")
            return 2
        size = ext.size
    target = img.read(va, size)
    if target is None:
        print("Address is not backed by file data.")
        return 2
    code = Path(args.file).read_text(encoding="utf-8")
    print(f"{compiler_version()}\nTarget {b}:0x{va:08X}, {size} bytes, flags {flags}")
    r = verify_submission(code, target, flags, match, fn_va=va, image=img,
                          include_dirs=[ROOT / "reconstructed_src" / "include", ROOT / "reconstructed_src", Path(args.file).resolve().parent])
    if not r.get("ok"):
        print("\n" + r["compiler_error"])
        return 1
    verified = r["is_exact"] and not r["hardcoded_addresses"]
    print(f"Function : {r['compiled_sym']} ({r['compiled_size']} bytes)")
    print(f"Result   : {r['matched_bytes']}/{r['total_bytes']} bytes ({r['match_percent']}%)"
          f" | relocations checked {r['reloc_checked']}, unchecked {r['reloc_unverified']}")
    for line in r["notes"] + r["reloc_mismatch"]:
        print("  - " + line)
    for line in r["hardcoded_addresses"]:
        print("  - hard-coded address: " + line)
    if args.show_diff or not verified:
        print("\n  off  target compiled")
        for d in r["diff_details"]:
            if d["status"] != "match" or args.show_diff:
                print(f"  {d['idx']:4X}   {d['target']:>2}    {d['compiled']:>2}   {d['status']}")
    print("\nVERIFIED" if verified else "\nNOT VERIFIED")
    return 0 if verified else 1


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("file", nargs="?", help="C++ file to verify")
    ap.add_argument("--status", action="store_true", help="print verified/queue totals")
    ap.add_argument("--va", help="original function address (hex)")
    ap.add_argument("--bin", choices=sorted(BINARIES), default="pc")
    ap.add_argument("--size", type=int, default=0)
    ap.add_argument("--match", help="substring of the compiled symbol name to compare")
    ap.add_argument("--flags", default=DEFAULT_FLAGS)
    ap.add_argument("--show-diff", action="store_true")
    a = ap.parse_args()
    if a.status or not a.file:
        return status()
    if not a.va:
        ap.error("--va is required when verifying a file")
    return check(a)


if __name__ == "__main__":
    sys.exit(main())
