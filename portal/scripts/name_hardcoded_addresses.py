#!/usr/bin/env python3
"""
Replace hard-coded 2006 addresses in the imported sweep files with address-named symbols.

A function such as

    unsigned int __cdecl sub_001CDC80(void) { return 0x00439DA4; }

compiles to the same bytes as the game, but the address is baked into the source as a number, so it
could never be relinked and the verifier does not count it (MATCH_HARDCODED_ADDR). Written as

    extern "C" char DAT_00439DA4; void* __cdecl sub_001CDC80(void) { return &DAT_00439DA4; }

the address becomes a relocation. The verifier checks every DAT_xxxxxxxx / sub_xxxxxxxx symbol
against the address in its name, so the function is VERIFIED only if the original really uses that
address at that spot.

Only lines whose function the last portal/scripts/reverify_all.py run reported as MATCH_HARDCODED_ADDR are
touched, and only the three shapes below. Run reverify_all.py again afterwards.

    python portal/scripts/name_hardcoded_addresses.py            # rewrite in place
    python portal/scripts/name_hardcoded_addresses.py --dry-run  # only count
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

PORTAL = Path(__file__).resolve().parent.parent      # portal/
ROOT = PORTAL.parent                                  # the project folder
sys.path.insert(0, str(PORTAL / "tools"))
from sf_binaries import BinaryImage  # noqa: E402

BINARIES = {"pc": ROOT / "binaries" / "Scarface.exe", "xb": ROOT / "binaries" / "default.xbe"}
REPORT = ROOT / "reports" / "reverify_report.md"
FILES = sorted((ROOT / "reconstructed_src" / "imported").glob("stage0_*.cpp"))

ROW_RE = re.compile(r"^\| (pc|xb|proto):0x([0-9A-F]{8}) \| .*? \| MATCH_HARDCODED_ADDR \|", re.M)
HEAD_RE = re.compile(r"^// (PC )?VA 0x([0-9A-Fa-f]{8}) \(\d+ B\)")

SHAPES = [
    # return <address>;  ->  return &DAT_<address>;   (a code address becomes sub_<address>)
    (re.compile(r"^unsigned int __cdecl (\w+)\(void\) \{ return 0x([0-9A-Fa-f]{1,8}); \}\s*$"),
     lambda fn, a, code: (f'void* __cdecl {fn}(void) {{ return (void*)&{fn}; }}' if fn == f"sub_{a}" else   # its own address
                          f'extern "C" void sub_{a}(); void* __cdecl {fn}(void) {{ return (void*)&sub_{a}; }}' if code else
                          f'extern "C" char DAT_{a}; void* __cdecl {fn}(void) {{ return &DAT_{a}; }}')),
    # return *(const unsigned int*)<address>;  ->  return DAT_<address>;
    (re.compile(r"^unsigned int __cdecl (\w+)\(void\) \{ return \*\(const unsigned int\*\)0x([0-9A-Fa-f]{1,8}); \}\s*$"),
     lambda fn, a, code: f'extern "C" const unsigned int DAT_{a}; unsigned int __cdecl {fn}(void) {{ return DAT_{a}; }}'),
    # return *(const float*)<address>;  ->  return DAT_<address>;
    (re.compile(r"^float __cdecl (\w+)\(void\) \{ return \*\(const float\*\)0x([0-9A-Fa-f]{1,8}); \}\s*$"),
     lambda fn, a, code: f'extern "C" const float DAT_{a}; float __cdecl {fn}(void) {{ return DAT_{a}; }}'),
]


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--dry-run", action="store_true")
    args = ap.parse_args()
    if not REPORT.exists():
        raise SystemExit("Run portal/scripts/reverify_all.py first; it writes reports/reverify_report.md.")
    wanted = {(b, int(v, 16)) for b, v in ROW_RE.findall(REPORT.read_text(encoding="utf-8"))}
    images = {b: BinaryImage(p) for b, p in BINARIES.items() if p.exists()}

    def in_code(b: str, addr: int) -> bool:
        img = images.get(b)
        return bool(img) and any(s.is_code and s.va <= addr < s.va + max(s.vsize, s.raw_size) for s in img.sections)
    total = 0
    for path in FILES:
        lines = path.read_text(encoding="utf-8").splitlines(keepends=True)
        changed = 0
        for i in range(len(lines) - 1):
            h = HEAD_RE.match(lines[i])
            if not h:
                continue
            va = int(h.group(2), 16)
            b = "pc" if h.group(1) or va >= 0x00400000 else "xb"     # same rule as reverify_all.bin_for
            if (b, va) not in wanted:
                continue
            for rx, make in SHAPES:
                m = rx.match(lines[i + 1])
                if m:
                    eol = "\r\n" if lines[i + 1].endswith("\r\n") else "\n"
                    addr = int(m.group(2), 16)
                    lines[i + 1] = make(m.group(1), f"{addr:08X}", in_code(b, addr)) + eol
                    changed += 1
                    break
        print(f"{path.name}: {changed} function(s) rewritten")
        total += changed
        if changed and not args.dry_run:
            path.write_text("".join(lines), encoding="utf-8", newline="")
    print(f"total: {total} of {len(wanted)} MATCH_HARDCODED_ADDR functions")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
