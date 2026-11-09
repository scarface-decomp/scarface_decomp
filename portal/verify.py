#!/usr/bin/env python3
"""
Command-line verifier: same rules as the portal, for people who work in their own editor.

    python portal/verify.py --status
    python portal/verify.py my_func.cpp --va 0x006DE620 --bin pc
    python portal/verify.py my_func.cpp --va 0x00011F20 --bin xb --match vfunc_03@Collidable@ --show-diff
    python portal/verify.py my_func.cpp --va 0x003DD090 --bin ps2 [--scratch SLUG]

PS2 functions are compiled on decomp.me (the PS2 compiler can't be installed here) and compared here;
--scratch names any PS2 scratch to compile through, otherwise one is created for the function.

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
            "proto": ROOT / "binaries" / "game.xbe", "ps2": ROOT / "binaries" / "SLUS_211.11"}
REGISTRY = ROOT / "reports" / "verified_registry.json"
QUEUE = ROOT / "reports" / "full_remaining_queue.json"
DEFAULT_FLAGS = "/O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4"


def status() -> int:
    reg = json.loads(REGISTRY.read_text(encoding="utf-8")) if REGISTRY.exists() else {"entries": {}}
    entries = reg.get("entries", {})
    queue = json.loads(QUEUE.read_text(encoding="utf-8")) if QUEUE.exists() else []
    open_tasks = [t for t in queue if f"{t.get('bin')}:0x{t.get('fva_int', 0):08X}" not in entries]
    remaining = sum(1 for t in open_tasks if t.get("bin") in ("pc", "xb"))   # the released game on PC + Xbox
    proto_left = sum(1 for t in open_tasks if t.get("bin") == "proto")
    ps2_left = sum(1 for t in open_tasks if t.get("bin") == "ps2")
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
    if by_bin.get("ps2", 0) or ps2_left:
        print(f" PS2                : {by_bin.get('ps2', 0):,} of {by_bin.get('ps2', 0) + ps2_left:,} (own compiler, checked on decomp.me)")
    if by_bin.get("proto", 0) or proto_left:
        print(f" Xbox prototype     : {by_bin.get('proto', 0):,} of {by_bin.get('proto', 0) + proto_left:,} (unreleased code, counted on its own)")
    print(f" Verified bytes     : {sum(int(e.get('size', 0)) for e in entries.values() if e['bin'] != 'ps2'):,}")
    print("-" * 72)
    board = Counter((e.get("verified_by") or "Imported (unattributed)") for e in entries.values())
    for i, (u, n) in enumerate(board.most_common(10), 1):
        print(f"   #{i:<2} {u:<34} {n:,}")
    print("=" * 72)
    return 0


def check_ps2(args) -> int:
    import ps2_binary as PB
    import ps2_verify as PV
    from cpp_policy import check_genuine_cpp, format_violations
    from game_files import refusal
    if not BINARIES["ps2"].exists():
        print("binaries/SLUS_211.11 is missing; see binaries/README.md.")
        return 2
    problem = refusal(BINARIES["ps2"])
    if problem:
        print(problem)
        return 2
    img = PB.Ps2Image(BINARIES["ps2"])
    va = int(args.va, 16)
    size = args.size
    if QUEUE.exists() and not size:
        for t in json.loads(QUEUE.read_text(encoding="utf-8")):
            if t.get("bin") == "ps2" and t.get("fva_int") == va:
                size = int(t["size"])
                break
    if not size:
        f = PB.find_functions(img).get(va)
        if not f:
            print(f"0x{va:08X} is not the start of a PS2 function. Pass --size.")
            return 2
        size = f.size
    target = img.read(va, size)
    code = Path(args.file).read_text(encoding="utf-8")
    bad = check_genuine_cpp(code)
    if bad:
        print(format_violations(bad))
        return 1
    slug = args.scratch
    if not slug:
        made = PV.create_scratch(PV.scratch_fields(f"Scarface (PS2) func_{va:08X}", PB.function_asm(img, va, size), code))
        if not made.get("ok"):
            print(made.get("error"))
            return 2
        slug = made["slug"]
        print(f"Created {made['url']}")
    print(f"{PV.COMPILER} on decomp.me, flags {PV.FLAGS}\nTarget ps2:0x{va:08X}, {size} bytes")
    res = PV.compile_on_decompme(slug, code)
    if not res.get("ok"):
        print("\n" + (res.get("compiler_error") or res.get("error") or "compile failed"))
        return 1
    obj = PV.parse_object(res["object"])
    fn, r = PV.best_function(target, obj, va, img)
    if fn is None:
        print("The C++ compiled, but it has no function in it.")
        return 1
    verified = r["is_exact"] and not r["hardcoded_addresses"]
    print(f"Function : {obj.name_of(fn)} ({r['compiled_size']} bytes)")
    print(f"Result   : {r['matched_bytes']}/{r['total_bytes']} bytes ({r['match_percent']}%)"
          f" | relocations checked {r['reloc_checked']}, unchecked {r['reloc_unverified']}")
    for line in r["notes"] + r["reloc_mismatch"]:
        print("  - " + line)
    for line in r["hardcoded_addresses"]:
        print("  - hard-coded address: " + line)
    print("\nVERIFIED" if verified else "\nNOT VERIFIED")
    return 0 if verified else 1


def check(args) -> int:
    if args.bin == "ps2":
        return check_ps2(args)
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
    ap.add_argument("--scratch", help="PS2: a decomp.me scratch id to compile through")
    a = ap.parse_args()
    if a.status or not a.file:
        return status()
    if not a.va:
        ap.error("--va is required when verifying a file")
    return check(a)


if __name__ == "__main__":
    sys.exit(main())
