#!/usr/bin/env python3
"""
Re-verify every function this repository claims to have matched, using the same rules as the
portal (tools/msvc_verify.py), and rebuild reports/verified_registry.json from the results.

    python scripts/reverify_all.py              # Windows: uses tools/msvc71/bin/cl.exe
    python3 scripts/reverify_all.py --jobs 8    # Linux/macOS: runs cl.exe under Wine

A function counts as VERIFIED only if:
  * its C++ passes the genuine-C++ policy (no __asm/_emit/naked/section tricks),
  * the compiled function has exactly the original's length and bytes,
  * every relocation that can be checked points where the original points, and
  * it does not hard-code addresses from the 2006 binary (e.g. `*(int*)0x00419E48`).

Sources understood:
  * reconstructed_src/Crowdsourced_PC_Patch_Verified.cpp   (portal "[100% ... VERIFIED]" blocks)
  * reconstructed_src/stage0_*_sweep.cpp                    ("// VA 0x... (N B)" + one line of code)
  * every other reconstructed_src/*.cpp compiled as a whole translation unit, matching
    methods whose declarations carry "PC VA 0x..."/"Xbox 0x..." annotations.
Anything without a recorded address is reported as unattributed and not counted.
"""

from __future__ import annotations

import argparse
import concurrent.futures as cf
import datetime as dt
import hashlib
import json
import os
import re
import sys
import threading
from collections import Counter, defaultdict
from dataclasses import dataclass, field, asdict
from pathlib import Path
from typing import Dict, List, Optional, Tuple

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

from msvc_verify import (CoffObject, compare_function, compile_cpp, compiler_version,  # noqa: E402
                         decorated_hint, find_msvc71_bin, select_function)
from sf_binaries import BinaryImage, collect_call_targets, function_extent  # noqa: E402
from queue_builder import PC_PLAINTEXT  # noqa: E402
from registry_outputs import write_outputs  # noqa: E402

RECON = ROOT / "reconstructed_src"
REPORTS = ROOT / "reports"
BINARIES = {"pc": ROOT / "binaries" / "Scarface.exe", "xb": ROOT / "binaries" / "default.xbe",
            "proto": ROOT / "binaries" / "game.xbe"}
FLAGS = {
    "pc": ["/O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4", "/O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4"],
    "xb": ["/O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4"],
    "proto": ["/O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4"],
}
INCLUDES = [ROOT / "include", RECON]

STATUS_ORDER = ["VERIFIED", "MATCH_HARDCODED_ADDR", "MISMATCH", "POLICY", "COMPILE_ERROR", "UNMAPPED",
                "NO_CODE", "NO_TARGET"]


@dataclass
class Claim:
    source: str
    bin: str
    va: int
    symbol: str
    code: Optional[str]
    match: str = ""
    claimed_size: Optional[int] = None
    attributed_to: str = ""
    kind: str = "block"
    tu: Optional[str] = None
    extra: dict = field(default_factory=dict)   # carried into the registry entry (portal fields)
    # results
    status: str = ""
    size: int = 0
    matched: int = 0
    flags: str = ""
    detail: str = ""

    @property
    def key(self) -> str:
        return f"{self.bin}:0x{self.va:08X}"


# --------------------------------------------------------------------------- #
# Parsers
# --------------------------------------------------------------------------- #

def bin_for(va: int, hint: str = "") -> str:
    h = hint.lower()
    if "proto" in h:
        return "proto"
    if h.startswith("pc") or "pc va" in h or "pc " in h:
        return "pc"
    if "xbox" in h or "xbe" in h:
        return "xb"
    return "pc" if va >= 0x00400000 else "xb"


def member_match(cls: str, name: str, scopes: Tuple[str, ...] = ()) -> str:
    return decorated_hint("::".join(tuple(reversed(scopes)) + (cls,)), name)


def match_from_symbol(sym: str) -> str:
    parts = [p for p in re.split(r"::", sym) if p]
    if not parts:
        return ""
    if len(parts) == 1:
        return parts[0]
    return member_match(parts[-2], parts[-1], tuple(reversed(parts[:-2])))


BLOCK_RE = re.compile(
    r"// =+\n// \[100% MSVC 7\.10 VERIFIED\] (?P<sym>\S+) \((?P<va>[^,]+), (?P<sz>\d+) B\)\n"
    r"// Lane: (?P<lane>[^|]*)\| Verified by: (?P<user>.*?) at [^\n]*\n"
    r"(?:// Target Bytes:[^\n]*\n)?// =+\n(?P<code>.*?)(?=\n// =+\n// \[|\Z)", re.S)


def parse_crowdsourced(path: Path) -> List[Claim]:
    text = path.read_text(encoding="utf-8", errors="replace")
    out = []
    for m in BLOCK_RE.finditer(text):
        va = int(re.search(r"0x([0-9A-Fa-f]+)", m.group("va")).group(1), 16)
        out.append(Claim(path.name, bin_for(va, m.group("va") + " " + m.group("lane")), va, m.group("sym"),
                         m.group("code").strip(), match_from_symbol(m.group("sym")), int(m.group("sz")),
                         m.group("user").strip(), "block"))
    return out


STAGE0_RE = re.compile(r"^// (?P<pc>PC )?VA 0x(?P<va>[0-9A-Fa-f]{8}) \((?P<sz>\d+) B\)(?P<rest>[^\n]*)\n(?P<next>[^\n]*)", re.M)


def parse_stage0(path: Path) -> List[Claim]:
    text = path.read_text(encoding="utf-8", errors="replace")
    out = []
    for m in STAGE0_RE.finditer(text):
        va = int(m.group("va"), 16)
        b = "pc" if m.group("pc") else bin_for(va)
        nxt = m.group("next").strip()
        sym_m = re.search(r"==>\s*(\S+)", m.group("rest"))
        sym = sym_m.group(1) if sym_m else f"sub_{va:08X}"
        if not nxt or nxt.startswith("/*") or nxt.startswith("//"):
            out.append(Claim(path.name, b, va, sym, None, claimed_size=int(m.group("sz")), kind="entry"))
            continue
        fn = re.search(r"(\w+)\s*\(", nxt)
        out.append(Claim(path.name, b, va, sym, nxt, fn.group(1) if fn else "", int(m.group("sz")), "", "entry"))
    return out


ANNOT_RE = re.compile(r"(?P<tag>PC VA|PC|Xbox|VA)\s*0x(?P<va>[0-9A-Fa-f]{6,8})(?:[^()\n]{0,40}?\((?P<sz>\d+)\s*B\))?")
DECL_RE = re.compile(r"(?:virtual\s+)?[\w:<>\*&\s]+?\b(?P<name>~?\w+)\s*\([^;{}]*\)\s*(?:const)?\s*(?:=\s*0)?\s*;")
CLASS_RE = re.compile(r"\b(class|struct)\s+(\w+)[^;{]*\{")


def parse_tu(path: Path) -> List[Claim]:
    """Method declarations annotated with an address, e.g. `virtual void vfunc_01(); // PC VA 0x006DDC60 (23 B)`."""
    text = path.read_text(encoding="utf-8", errors="replace")
    out: List[Claim] = []
    # class context by brace depth
    stack: List[Tuple[str, int]] = []
    depth = 0
    pending: Optional[str] = None
    for line in text.splitlines():
        cm = CLASS_RE.search(line)
        code_part = line.split("//")[0]
        if cm:
            pending = cm.group(2)
        for ch in code_part:
            if ch == "{":
                depth += 1
                if pending:
                    stack.append((pending, depth))
                    pending = None
            elif ch == "}":
                if stack and stack[-1][1] == depth:
                    stack.pop()
                depth -= 1
        am = ANNOT_RE.search(line)
        if not am or not stack:
            continue
        dm = DECL_RE.search(code_part)
        if not dm:
            continue
        cls = stack[-1][0]
        name = dm.group("name")
        va = int(am.group("va"), 16)
        b = bin_for(va, am.group("tag"))
        out.append(Claim(path.name, b, va, f"{cls}::{name}", None, member_match(cls, name),
                         int(am.group("sz")) if am.group("sz") else None, "", "tu", tu=path.name))
    return out


DEF_RE = re.compile(r"^(?!\s)(?:[\w:<>\*&,]+\s+)*?(?:(?P<cls>[\w<>]+)::)?(?P<name>~?\w+)\s*\([^;{}]*\)\s*(?:const)?\s*\{?\s*$")
NEAR_RE = re.compile(r"(?P<tag>default\.xbe|Xbox|PC v1\.00\.2|PC VA|PC|VA|ADDR|BATCH[^(]*\()\s*[:@]?\s*0x(?P<va>[0-9A-Fa-f]{8})"
                     r"(?:[^\n]{0,30}?\(?(?P<sz>\d+)\s*(?:B\b|bytes))?")


def parse_defs(path: Path) -> List[Claim]:
    """Definitions preceded (within 12 lines) by an address comment, e.g. `/* BATCH #01 (0x00029F40, 14B) */`."""
    lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
    out: List[Claim] = []
    for i, line in enumerate(lines):
        m = DEF_RE.match(line)
        if not m or line.lstrip().startswith(("return", "if", "for", "while", "switch", "#", "//", "/*", "*")):
            continue
        if not (line.rstrip().endswith("{") or (i + 1 < len(lines) and lines[i + 1].strip().startswith("{"))):
            continue
        name, cls = m.group("name"), m.group("cls")
        seen_bins = set()
        for j in range(i - 1, max(-1, i - 13), -1):
            if DEF_RE.match(lines[j]) and lines[j].rstrip().endswith("{"):
                break                                   # previous function: stop looking
            for am in NEAR_RE.finditer(lines[j]):
                va = int(am.group("va"), 16)
                tag = am.group("tag")
                b = "pc" if tag.startswith("PC") else ("xb" if tag in ("default.xbe", "Xbox") else bin_for(va))
                if b in seen_bins:
                    continue
                seen_bins.add(b)
                sym = f"{cls}::{name}" if cls else name
                match = member_match(cls, name) if cls else name
                out.append(Claim(path.name, b, va, sym, None, match,
                                 int(am.group("sz")) if am.group("sz") else None, "", "tu", tu=path.name))
    return out


def load_old_registry() -> dict:
    p = REPORTS / "verified_registry.json"
    try:
        return json.loads(p.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        return {}


def is_generated(path: Path) -> bool:
    with open(path, encoding="utf-8", errors="replace") as fh:
        return "GENERATED from reports/verified_registry.json" in fh.read(400)


def count_unattributed(path: Path) -> int:
    text = path.read_text(encoding="utf-8", errors="replace")
    return len(re.findall(r"^[A-Za-z_][\w:<>\*\s&]*\b\w+\s*\([^;]*\)\s*(?:const)?\s*\{", text, re.M))


# --------------------------------------------------------------------------- #
# Verification
# --------------------------------------------------------------------------- #

class Targets:
    def __init__(self):
        self.images: Dict[str, BinaryImage] = {}
        self.starts: Dict[str, set] = {}
        from game_files import refusal
        for k, p in BINARIES.items():
            if p.exists():
                problem = refusal(p)
                if problem:
                    print(f"[!] NOT USED: {problem}")
                    continue
                img = BinaryImage(p)
                self.images[k] = img
                self.starts[k] = collect_call_targets(img)

    def target(self, c: Claim) -> Tuple[Optional[bytes], str]:
        img = self.images.get(c.bin)
        if img is None:
            return None, f"binary for '{c.bin}' not present"
        if c.bin == "pc" and not (PC_PLAINTEXT[0] <= c.va < PC_PLAINTEXT[1]):
            return None, (f"PC address is outside the readable PC code (0x{PC_PLAINTEXT[0]:08X}-0x{PC_PLAINTEXT[1]:08X}); "
                          "verify this function against the Xbox build instead")
        ext = function_extent(img, c.va, self.starts[c.bin])
        size = ext.size if ext.ok else (c.claimed_size or 0)
        note = ""
        if ext.ok and c.claimed_size and c.claimed_size != ext.size:
            note = f"recorded size {c.claimed_size} B, actual function is {ext.size} B"
        if not size:
            return None, ext.reason or "could not size the function"
        data = img.read(c.va, size)
        if data is None:
            return None, "address is not backed by file data"
        return data, note


def judge(c: Claim, target: bytes, obj: bytes, flags: str, img) -> Tuple[str, int, str]:
    coff = CoffObject(obj)
    best: Optional[Tuple[str, int, str]] = None
    for alt in (c.match or "").split("|"):
        res = judge_one(coff, alt, target, c.va, img)
        if best is None or STATUS_ORDER.index(res[0]) < STATUS_ORDER.index(best[0]) or \
                (res[0] == best[0] and res[1] > best[1]):
            best = res
    return best


def judge_one(coff: CoffObject, match: str, target: bytes, va: int, img) -> Tuple[str, int, str]:
    fn, why = select_function(coff.functions(), match)
    if fn is None:
        return "UNMAPPED", 0, why
    c_va = va
    r = compare_function(target, fn, coff, fn_va=c_va, image=img)
    if r.is_exact and r.hardcoded_addresses:
        return "MATCH_HARDCODED_ADDR", r.matched, "; ".join(r.hardcoded_addresses[:3])
    if r.is_exact:
        extra = f"{r.reloc_unverified} external relocation(s) unchecked" if r.reloc_unverified else ""
        return "VERIFIED", r.matched, extra
    reason = "; ".join((r.reloc_mismatch + r.notes)[:3]) or f"{r.matched}/{r.total} bytes"
    return "MISMATCH", r.matched, reason


def verify_one(c: Claim, T: Targets) -> Claim:
    if c.code is None:
        c.status, c.detail = "NO_CODE", "only a comment; no C++ was written"
        return c
    target, note = T.target(c)
    if target is None:
        c.status, c.detail = "NO_TARGET", note
        return c
    c.size = len(target)
    best = None
    for flags in FLAGS[c.bin]:
        cr = compile_cpp(c.code, flags, include_dirs=INCLUDES)
        if not cr.ok:
            st = "POLICY" if cr.policy_violation else "COMPILE_ERROR"
            res = (st, 0, cr.error.splitlines()[0] if cr.error else "", flags)
            if st == "POLICY":
                best = res
                break
        else:
            st, m, why = judge(c, target, cr.obj, flags, T.images[c.bin])
            res = (st, m, why, flags)
        if best is None or STATUS_ORDER.index(res[0]) < STATUS_ORDER.index(best[0]) or \
                (res[0] == best[0] and res[1] > best[1]):
            best = res
        if best[0] == "VERIFIED":
            break
    c.status, c.matched, c.detail, c.flags = best
    if note and c.status != "VERIFIED":
        c.detail = (c.detail + "; " if c.detail else "") + note
    return c


def verify_tu(path: Path, claims: List[Claim], T: Targets) -> List[Claim]:
    """Compile a whole file once per flag set and check each annotated method in it."""
    code = path.read_text(encoding="utf-8", errors="replace")
    by_bin = defaultdict(list)
    for c in claims:
        by_bin[c.bin].append(c)
    for b, group in by_bin.items():
        if b not in T.images:
            for c in group:
                c.status, c.detail = "NO_TARGET", f"binary for '{b}' not present"
            continue
        compiled = []
        err = ""
        policy = False
        for flags in FLAGS[b]:
            cr = compile_cpp(code, flags, include_dirs=INCLUDES)
            if cr.ok:
                compiled.append((flags, cr.obj))
            else:
                err, policy = cr.error, cr.policy_violation
                if policy:
                    break
        for c in group:
            target, note = T.target(c)
            if target is None:
                c.status, c.detail = "NO_TARGET", note
                continue
            c.size = len(target)
            if not compiled:
                c.status = "POLICY" if policy else "COMPILE_ERROR"
                c.detail = (err.splitlines()[0] if err else "translation unit does not compile")
                continue
            best = None
            for flags, obj in compiled:
                st, m, why = judge(c, target, obj, flags, T.images[b])
                cand = (st, m, why, flags)
                if best is None or STATUS_ORDER.index(st) < STATUS_ORDER.index(best[0]) or \
                        (st == best[0] and m > best[1]):
                    best = cand
            c.status, c.matched, c.detail, c.flags = best
            c.code = None if c.status != "VERIFIED" else _extract_definition(code, c)
            if note and c.status != "VERIFIED":
                c.detail = (c.detail + "; " if c.detail else "") + note
    return claims


def _extract_definition(code: str, c: Claim) -> str:
    cls, name = c.symbol.split("::")[-2:]
    m = re.search(rf"[^\n;{{}}]*\b{re.escape(cls)}::{re.escape(name)}\s*\([^)]*\)[^{{;]*\{{", code)
    if not m:
        return f"// defined in reconstructed_src/{c.source}"
    i, depth = m.end(), 1
    while i < len(code) and depth:
        depth += {"{": 1, "}": -1}.get(code[i], 0)
        i += 1
    return code[m.start():i].strip()


# --------------------------------------------------------------------------- #
# Main
# --------------------------------------------------------------------------- #

def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--jobs", type=int, default=max(1, min(8, (os.cpu_count() or 2))))
    ap.add_argument("--limit", type=int, default=0, help="only check the first N claims (debugging)")
    args = ap.parse_args()

    if not find_msvc71_bin():
        print("cl.exe not found in tools/msvc71/bin", file=sys.stderr)
        return 2
    version = compiler_version()
    print("Compiler:", version)
    T = Targets()
    print("Binaries:", ", ".join(f"{k}={v.path.name} ({v.sha256[:12]})" for k, v in T.images.items()))

    singles: List[Claim] = []
    tus: Dict[str, List[Claim]] = {}
    unattributed: Dict[str, int] = {}
    for p in sorted(RECON.glob("*.cpp")) + sorted((RECON / "imported").glob("*.cpp")):
        if is_generated(p):
            continue                    # written from the registry; checking it again would be circular
        rel = p.relative_to(RECON).as_posix()
        if p.name == "Crowdsourced_PC_Patch_Verified.cpp":
            got = parse_crowdsourced(p)
            singles += got
        elif p.name.startswith("stage0_"):
            got = parse_stage0(p)
            singles += got
        elif p.name in ("Partial_Proven_Checkpoints.cpp",) or p.name.startswith("verify_"):
            continue
        else:
            got = parse_tu(p)
            have = {(c.bin, c.va) for c in got}
            got += [c for c in parse_defs(p) if (c.bin, c.va) not in have]
            if got:
                tus[rel] = got
            n = count_unattributed(p) - len(got)
            if n > 0:
                unattributed[rel] = n
        for c in got:
            c.source = rel
            if c.tu:
                c.tu = rel

    # Functions verified in the portal live only in the registry; check them again too, or this run
    # would drop them.
    old_registry = load_old_registry()
    for key, e in old_registry.get("entries", {}).items():
        if e.get("source") != "portal" or not (e.get("code") or "").strip():
            continue
        c = Claim("portal", e["bin"], int(e["va"], 16), e["symbol"], e["code"],
                  e.get("match") or match_from_symbol(e["symbol"]), int(e["size"]), e.get("verified_by", ""), "portal")
        c.extra = {k: e[k] for k in ("verified_at", "tool_used") if k in e}
        singles.append(c)

    if args.limit:
        singles = singles[:args.limit]
        tus = dict(list(tus.items())[:1])

    total = len(singles) + sum(len(v) for v in tus.values())
    done = 0
    lock = threading.Lock()
    results: List[Claim] = []

    def tick(n=1):
        nonlocal done
        with lock:
            done += n
            if done % 50 == 0 or done == total:
                print(f"  {done}/{total} checked", flush=True)

    with cf.ThreadPoolExecutor(max_workers=args.jobs) as ex:
        futs = [ex.submit(verify_one, c, T) for c in singles]
        futs += [ex.submit(verify_tu, RECON / name, cl, T) for name, cl in tus.items()]
        for f in cf.as_completed(futs):
            r = f.result()
            if isinstance(r, list):
                results.extend(r)
                tick(len(r))
            else:
                results.append(r)
                tick()

    # Deduplicate by address. Best status wins; on a tie, prefer a claim with an author, then portal
    # work, then hand-written files, so attribution survives and the result does not depend on the order
    # in which the checks finished.
    kind_rank = {"portal": 0, "tu": 1, "block": 2, "entry": 3}

    def rank(c: Claim):
        return (STATUS_ORDER.index(c.status), 0 if c.attributed_to else 1, kind_rank.get(c.kind, 9), c.source, -c.matched)

    best: Dict[str, Claim] = {}
    for c in results:
        cur = best.get(c.key)
        if cur is None or rank(c) < rank(cur):
            best[c.key] = c

    now = dt.datetime.now(dt.timezone.utc).strftime("%Y-%m-%dT%H:%M:%SZ")
    registry = {
        "schema": "scarface_verified_registry_v1",
        "generated_at": now,
        "compiler": version,
        "binaries": {k: {"file": v.path.name, "sha256": v.sha256} for k, v in T.images.items()},
        "rules": "exact length + bytes, checked relocations, no hard-coded addresses, genuine C++ policy",
        "entries": {},
    }
    if load_old_registry().get("reset"):
        registry["reset"] = load_old_registry()["reset"]      # keep the record of the 2026-11-08 restart
    for k, c in sorted(best.items()):
        if c.status == "VERIFIED":
            registry["entries"][k] = {
                "bin": c.bin, "va": f"0x{c.va:08X}", "size": c.size, "symbol": c.symbol, "match": c.match,
                "flags": c.flags, "source": c.source, "verified_by": c.attributed_to or "",
                **c.extra, "reverified_at": now, "code": c.code or "", "note": c.detail,
            }
            if c.kind == "tu":
                registry["entries"][k]["excerpt"] = True
    REPORTS.mkdir(exist_ok=True)
    tmp = REPORTS / "verified_registry.json.tmp"
    tmp.write_text(json.dumps(registry, indent=2), encoding="utf-8")
    tmp.replace(REPORTS / "verified_registry.json")
    write_outputs(registry, RECON)

    # Report
    by_file = defaultdict(Counter)
    for c in results:
        by_file[c.source][c.status] += 1
    status_tot = Counter(c.status for c in best.values())
    lines = [
        "# Re-verification report",
        "",
        f"Generated {now} by `scripts/reverify_all.py` with **{version}**.",
        "",
        "A function counts as VERIFIED only with exact length and bytes, checked relocations, no hard-coded",
        "2006 addresses, and no inline assembly. Addresses are deduplicated across files.",
        "",
        "| Status | Functions (unique addresses) |",
        "|---|---|",
    ]
    for st in STATUS_ORDER:
        lines.append(f"| {st} | {status_tot.get(st, 0):,} |")
    by_bin = Counter(c.bin for c in best.values() if c.status == "VERIFIED")
    lines += ["", f"VERIFIED by binary: " + ", ".join(f"{k}: {v}" for k, v in sorted(by_bin.items())) or "none", ""]
    lines += ["## By source file", "", "| File | " + " | ".join(STATUS_ORDER) + " |", "|---|" + "---|" * len(STATUS_ORDER)]
    for f in sorted(by_file):
        lines.append(f"| {f} | " + " | ".join(str(by_file[f].get(s, 0)) for s in STATUS_ORDER) + " |")
    if unattributed:
        lines += ["", "## Not checked: no address recorded", "",
                  "These files define functions without recording which original function each one is, "
                  "so they cannot be verified or counted:", ""]
        for f, n in sorted(unattributed.items()):
            lines.append(f"- `{f}`: about {n} function definitions")
    reasons = Counter((c.status, re.sub(r"0x[0-9A-Fa-f]+|\d+", "N", c.detail)[:110]) for c in best.values()
                      if c.status not in ("VERIFIED", "NO_CODE"))
    lines += ["", "## Most common reasons", "", "| Status | Reason | Count |", "|---|---|---|"]
    for (st, why), n in reasons.most_common(25):
        lines.append(f"| {st} | {why or '-'} | {n} |")
    lines += ["", "## Every checked address", "", "| Address | Symbol | Source | Status | Bytes | Flags | Detail |",
              "|---|---|---|---|---|---|---|"]
    for k, c in sorted(best.items()):
        lines.append(f"| {k} | `{c.symbol}` | {c.source} | {c.status} | {c.matched}/{c.size} | {c.flags} | "
                     f"{c.detail.replace('|', '/')[:140]} |")
    (REPORTS / "reverify_report.md").write_text("\n".join(lines) + "\n", encoding="utf-8")
    print()
    for st in STATUS_ORDER:
        print(f"{st:22s} {status_tot.get(st, 0):6,}")
    print("Wrote reports/verified_registry.json and reports/reverify_report.md")
    return 0


if __name__ == "__main__":
    sys.exit(main())
