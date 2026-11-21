#!/usr/bin/env python3
"""
A command-line way to work on functions, for a coding agent (or a person who lives in a terminal).
No browser, no AI key and no PIN: it reads the same files the portal does and checks with the same rules.

    python portal/agent.py next --bin xb --max-size 40      functions still open, smallest first
    python portal/agent.py packet xb 0x00248810             everything known about one, and a starter file
    python portal/agent.py check work/xb_00248810.cpp       compile it and compare with the original bytes
    python portal/agent.py keep work/xb_00248810.cpp        an exact match goes to reports/to_submit/

A match is only *recorded* by the portal, under a person's handle: after `keep`, the person runs
`python portal/scripts/submit_matches.py`. See AGENTS.md for the whole loop and the rules.
"""
from __future__ import annotations

import argparse
import json
import re
import shutil
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "portal" / "tools"))
sys.path.insert(0, str(ROOT / "portal"))

import names as NAMES  # noqa: E402
import ps2_overlay as PO  # noqa: E402
import readability as READ  # noqa: E402
import registry_outputs as RO  # noqa: E402

BINARIES = {"pc": ROOT / "binaries" / "Scarface.exe", "xb": ROOT / "binaries" / "default.xbe",
            "proto": ROOT / "binaries" / "game.xbe"}
QUEUE = ROOT / "reports" / "full_remaining_queue.json"
WORK = ROOT / "work"
TO_SUBMIT = ROOT / "reports" / "to_submit"
DEFAULT_FLAGS = "/O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4"
HEADER = re.compile(r"^//\s*(bin|va|what|tool|spec):\s*(.*)$", re.M)
CLASSMATES = 3


def registry() -> dict:
    p = ROOT / "reports" / "verified_registry.json"
    return json.loads(p.read_text(encoding="utf-8")).get("entries", {}) if p.exists() else {}


def functions() -> list:
    """Every function the project knows of on the Xbox, PC and prototype builds: the portal's queue when this
    computer has one, otherwise the address-order lists that come with the repository."""
    if QUEUE.exists():
        return [t for t in json.loads(QUEUE.read_text(encoding="utf-8")) if t.get("bin") in BINARIES and "fva_int" in t]
    return [t for b, fns in RO.known_from_files(ROOT / "reconstructed_src").items() if b in BINARIES for t in fns.values()]


def key_of(b: str, va: int) -> str:
    return f"{b}:0x{va:08X}"


def find(b: str, va: int) -> dict:
    for t in functions():
        if t["bin"] == b and t["fva_int"] == va:
            return t
    sys.exit(f"{key_of(b, va)} is not a function the project knows of. `next` lists the ones that are open.")


def image(b: str):
    from sf_binaries import BinaryImage
    from game_files import refusal
    path = BINARIES[b]
    if not path.exists():
        sys.exit(f"binaries/{path.name} is missing: this needs your own copy of the game (binaries/README.md).")
    problem = refusal(path)
    if problem:
        sys.exit(problem)
    return BinaryImage(path)


def flags_for(t: dict, target=None) -> list:
    import msvc_verify as MV
    return MV.flag_options(t["bin"], t.get("flags") or DEFAULT_FLAGS, target)


def known_names(b: str) -> dict:
    return NAMES.addresses(NAMES.load(ROOT / "reports" / "names.json"), b)


def cmd_next(args) -> int:
    done = registry()
    rows = [t for t in functions() if key_of(t["bin"], t["fva_int"]) not in done
            and (not args.bin or t["bin"] == args.bin) and args.min_size <= int(t["size"]) <= args.max_size]
    rows.sort(key=lambda t: (int(t["size"]), t["bin"], t["fva_int"]))
    waiting = {p.stem.lower() for p in TO_SUBMIT.glob("*.cpp")} if TO_SUBMIT.exists() else set()
    rows = [t for t in rows if f"{t['bin']}_{t['fva_int']:08x}" not in waiting]
    print(f"{len(rows):,} open functions match. Smallest first:")
    for t in rows[args.skip:args.skip + args.n]:
        print(f"  {t['bin']:<5} 0x{t['fva_int']:08X}  {int(t['size']):>5} B  {t.get('symbol', '')}")
    return 0


def cmd_packet(args) -> int:
    import decompme as DME
    from disasm_synth import disassemble, synthesize_cpp
    b, va = args.bin, int(args.va, 16)
    t = find(b, va)
    size = int(t["size"])
    img = image(b)
    tb = img.read(va, size)
    if not tb:
        sys.exit(f"Could not read {size} bytes at {key_of(b, va)}.")
    done = registry()
    entry = done.get(key_of(b, va))
    try:
        relocs = DME.find_relocations(tb, va, img)
    except Exception:
        relocs = None
    lines = disassemble(tb)
    symbol = t.get("symbol") or f"sub_{va:08X}"
    label = f"{'PC ' if b == 'pc' else 'Proto ' if b == 'proto' else ''}0x{va:08X}"
    print(f"{symbol}  ({b} 0x{va:08X}, {size} bytes)" + ("   ALREADY MATCHED" if entry else ""))
    print(f"flags: {' | '.join(flags_for(t, tb))}")
    names = NAMES.load(ROOT / "reports" / "names.json").get("names", {})
    own = names.get(key_of(b, va))
    if isinstance(own, dict) and own.get("name"):
        print(f"name on record: {own['name']}  ({own.get('why', '')})")
    print("\ntarget bytes:\n  " + " ".join(f"{x:02X}" for x in tb[:512]) + (" ..." if size > 512 else ""))
    print("\ndisassembly:")
    for ln in lines:
        print("  " + ln)
    by_address = {a: n for n, a in known_names(b).items()}
    called = sorted({int(m, 16) for m in re.findall(r"0x([0-9a-fA-F]{5,8})", "\n".join(lines))} & set(by_address))
    if called:
        print("\nnames on record for addresses it uses (call them by name; the address is still checked):")
        for a in called:
            print(f"  0x{a:08X}  {by_address[a]}")
    cls = "::".join(symbol.split("::")[:-1])
    mates = [e for k, e in done.items() if cls and k.startswith(b + ":") and k != key_of(b, va)
             and e.get("symbol", "").startswith(cls + "::") and not e.get("excerpt")]
    mates.sort(key=lambda e: (READ.grade(e.get("code", ""))["left"], -int(e.get("size", 0))))
    for e in mates[:CLASSMATES]:
        print(f"\n--- already matched in the same class: {e['symbol']} ({e['va']}, {e['size']} bytes) ---")
        print(e.get("code", "").strip()[:5000])
    WORK.mkdir(exist_ok=True)
    out = WORK / f"{b}_{va:08X}.cpp"
    if not out.exists() or args.force:
        body = entry["code"] if entry else synthesize_cpp(symbol, label, tb, lines, relocs=relocs)
        out.write_text(f"// bin: {b}\n// va: 0x{va:08X}\n// what: \n// tool: \n\n{body.rstrip()}\n", encoding="utf-8")
        print(f"\nstarter written to {out.relative_to(ROOT)}")
    else:
        print(f"\n{out.relative_to(ROOT)} is already there (kept; --force writes the starter again)")
    return 0


def header(text: str) -> dict:
    return {k: v.strip() for k, v in HEADER.findall(text)}


def check(path: Path) -> tuple:
    """(verified, result, task, text) for a work file. verified: exact bytes, every address checked, real C++."""
    import msvc_verify as MV
    text = path.read_text(encoding="utf-8")
    h = header(text)
    if h.get("bin") not in BINARIES or not re.fullmatch(r"0x[0-9A-Fa-f]{8}", h.get("va", "")):
        sys.exit(f"{path}: it needs '// bin: xb|pc|proto' and '// va: 0x........' lines at the top (`packet` writes them).")
    b, va = h["bin"], int(h["va"], 16)
    t = find(b, va)
    if not MV.find_msvc71_bin():
        sys.exit("The 2003 compiler is not installed here (python portal/scripts/setup_msvc71.py, see docs/CONTRIBUTING.md).")
    img = image(b)
    tb = img.read(va, int(t["size"]))
    best = None
    for flags in flags_for(t, tb):
        r = MV.verify_submission(text, tb, flags, t.get("match_substr", ""), fn_va=va, image=img,
                                 include_dirs=[ROOT / "reconstructed_src" / "include", ROOT / "reconstructed_src"],
                                 known_names=known_names(b))
        r["flags"] = flags
        if best is None or (r.get("ok") and r.get("matched_bytes", 0) > best.get("matched_bytes", -1)):
            best = r
        if r.get("ok") and r.get("is_exact"):
            break
    ok = bool(best.get("ok") and best.get("is_exact") and not best.get("hardcoded_addresses")
              and not best.get("reloc_unverified"))
    return ok, best, t, text


def report(r: dict) -> None:
    if not r.get("ok"):
        print("DID NOT COMPILE\n" + str(r.get("compiler_error") or r.get("error") or "")[:4000])
        return
    print(f"function : {r.get('compiled_sym')} ({r.get('compiled_size')} bytes), flags {r['flags']}")
    print(f"result   : {r['matched_bytes']}/{r['total_bytes']} bytes | addresses checked {r['reloc_checked']}, "
          f"unchecked {r['reloc_unverified']}")
    aligned = r["total_bytes"] - r["matched_bytes"] <= 4 * len(r.get("reloc_mismatch") or [])
    for line in (r.get("notes") or []) + ((r.get("reloc_mismatch") or []) if aligned else []) + \
            ["hard-coded address: " + x for x in r.get("hardcoded_addresses") or []]:
        print("  - " + line)
    wrong = [d for d in r.get("diff_details") or [] if d.get("status") == "diff"]
    for d in wrong[:16]:
        print(f"  +0x{d['idx']:X}: original {d['target']}  yours {d['compiled']}")
    if len(wrong) > 16:
        print(f"  ... and {len(wrong) - 16} more bytes differ")


def cmd_check(args) -> int:
    ok, r, _t, text = check(Path(args.file))
    report(r)
    if ok:
        g = READ.grade(text)
        print("MATCH: byte for byte, every address checked."
              + (f" Still to name: {', '.join(g['stand_ins'][:8])}" if g["left"] else " Nothing left to name."))
        return 0
    if r.get("ok") and r.get("is_exact"):
        print("The bytes match, but it is not accepted yet: an address is hard-coded or could not be checked. "
              "Use sub_XXXXXXXX / DAT_XXXXXXXX names (or a name from reports/names.json) for what it calls and reads.")
    return 1


def cmd_keep(args) -> int:
    path = Path(args.file)
    ok, r, t, text = check(path)
    report(r)
    if not ok:
        print("Not kept: it has to match byte for byte with every address checked.")
        return 1
    h = header(text)
    if len(h.get("what", "")) < 12 or not (h.get("tool") or h.get("spec")):
        print("Not kept yet: fill in '// what:' (one plain sentence on what the function does) and '// tool:' "
              "(what wrote the code, e.g. the model's name) at the top of the file.")
        return 1
    if key_of(t["bin"], t["fva_int"]) in registry():
        print("This function is already matched in the registry. A better version of it is made in the portal.")
        return 1
    TO_SUBMIT.mkdir(parents=True, exist_ok=True)
    dest = TO_SUBMIT / f"{t['bin']}_{t['fva_int']:08X}.cpp"
    shutil.copyfile(path, dest)
    print(f"Kept: {dest.relative_to(ROOT)}. A person records it with: python portal/scripts/submit_matches.py")
    return 0


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("next", help="functions still open, smallest first")
    p.add_argument("--bin", choices=sorted(BINARIES))
    p.add_argument("--min-size", type=int, default=1)
    p.add_argument("--max-size", type=int, default=10 ** 9)
    p.add_argument("-n", type=int, default=20)
    p.add_argument("--skip", type=int, default=0)
    p.set_defaults(fn=cmd_next)
    p = sub.add_parser("packet", help="everything known about one function, and a starter file in work/")
    p.add_argument("bin", choices=sorted(BINARIES))
    p.add_argument("va")
    p.add_argument("--force", action="store_true")
    p.set_defaults(fn=cmd_packet)
    p = sub.add_parser("check", help="compile a work file and compare it with the original")
    p.add_argument("file")
    p.set_defaults(fn=cmd_check)
    p = sub.add_parser("keep", help="put an exact match in reports/to_submit/ for a person to record")
    p.add_argument("file")
    p.set_defaults(fn=cmd_keep)
    args = ap.parse_args(argv)
    return args.fn(args)


if __name__ == "__main__":
    sys.exit(main())
