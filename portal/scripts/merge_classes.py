#!/usr/bin/env python3
"""Merge each class's per-function copies into one declaration and check it (docs/ROADMAP.md step 3).

    python portal/scripts/merge_classes.py              # count what merges; needs nothing but the repo
    python portal/scripts/merge_classes.py --verify     # also prove it, and write the results

Every matched member function carries its own copy of its class. This script merges the copies of each
class (portal/tools/class_merge.py). With --verify it then recompiles every function of the class with
the merged class in place of its own copy, using the game's compiler, and keeps the merged class only
for the functions that still compile to the game's exact bytes. A function that does not is left out
and named, and the merge is tried again without it.

--verify needs the game files in binaries/ and the compiler in portal/tools/msvc71/. It writes

    reports/classes.json                 every class: how it went, which functions the class is proven for
    reports/classes/<game>/<Class>.h     the merged class, for classes proven for two or more functions

The registry is not touched: each function's own recorded text stays the proof that it matches. The
merged classes are what a shared header is built from next.
"""

from __future__ import annotations

import argparse
import json
import re
import sys
from collections import Counter, defaultdict
from multiprocessing import Pool
from pathlib import Path
from typing import Dict, List, Optional, Tuple

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "portal" / "tools"))

import class_merge as CM  # noqa: E402

REGISTRY = ROOT / "reports" / "verified_registry.json"
OUT_JSON = ROOT / "reports" / "classes.json"
OUT_DIR = ROOT / "reports" / "classes"
FILES = {"xb": "default.xbe", "proto": "game.xbe", "pc": "Scarface.exe"}
INCLUDES = [ROOT / "reconstructed_src" / "include", ROOT / "reconstructed_src"]


def groups(entries: Dict[str, dict], only_bin: Optional[str] = None) -> Dict[Tuple[str, str], List[str]]:
    """Registry keys of member functions, by (game, class)."""
    out: Dict[Tuple[str, str], List[str]] = defaultdict(list)
    for key in sorted(entries):
        e = entries[key]
        if "::" in e["symbol"] and e["bin"] in FILES and only_bin in (None, e["bin"]):
            out[(e["bin"], e["symbol"].rsplit("::", 1)[0])].append(key)
    return out


def read_copies(entries: Dict[str, dict], keys: List[str]):
    """([(key, its class copy)], {key: why it can't be read})."""
    good, bad = [], {}
    for key in keys:
        try:
            good.append((key, CM.parse_class(entries[key]["code"], entries[key]["symbol"])))
        except CM.Unreadable as ex:
            bad[key] = str(ex)
    return good, bad


_IMAGES: dict = {}
_NAMES: dict = {}


def check(job: Tuple[str, dict, str]) -> Tuple[str, str]:
    """(key, "" when code compiles to the function's bytes, else why not)."""
    key, e, code = job
    import msvc_verify as MV
    import names as NAMES
    from sf_binaries import BinaryImage
    b = e["bin"]
    try:
        if b not in _IMAGES:
            _IMAGES[b] = BinaryImage(ROOT / "binaries" / FILES[b])
            _NAMES[b] = NAMES.addresses(NAMES.load(ROOT / "reports" / "names.json"), b)
        va, size = int(e["va"], 16), int(e["size"])
        target = _IMAGES[b].read(va, size)
        if not target or len(target) != size:
            return key, "the function's bytes are not in the game file"
        r = MV.verify_submission(code, target, e["flags"], e.get("match", ""), fn_va=va, image=_IMAGES[b],
                                 include_dirs=INCLUDES, known_names=_NAMES[b])
        if not r.get("ok"):
            return key, "does not compile: " + str(r.get("compiler_error") or r.get("error")).strip().splitlines()[-1][:160]
        if not r["is_exact"]:
            return key, f"{r['matched_bytes']} of {r['total_bytes']} bytes match"
        if r["reloc_unverified"] or r["hardcoded_addresses"]:
            return key, "a reference could not be checked"
        return key, ""
    except Exception as ex:                                   # one bad function must not stop the run
        return key, "error: " + repr(ex)[:160]


def header_path(b: str, cls: str) -> Path:
    return OUT_DIR / b / (re.sub(r"[^\w]+", "__", cls) + ".h")


def header_text(b: str, cls: str, mg: "CM.Merged", proven: List[dict]) -> str:
    ns = cls.split("::")[:-1]
    lines = [f"// {cls} ({b}): one declaration merged from its matched functions.",
             f"// Proven for {len(proven)} functions: each compiles to the game's bytes with this class",
             "// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual",
             "// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.", ""]
    lines += [f"namespace {n} {{" for n in ns]
    lines.append(CM.render(mg))
    lines += ["}" for _n in ns]
    return "\n".join(lines) + "\n"


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--verify", action="store_true", help="recompile every function with its merged class and write the results")
    ap.add_argument("--bin", choices=sorted(FILES), help="only this game file")
    ap.add_argument("--jobs", type=int, default=3)
    ap.add_argument("--limit", type=int, default=0, help="only the first N classes (for a quick try)")
    args = ap.parse_args()

    entries = json.loads(REGISTRY.read_text(encoding="utf-8"))["entries"]
    todo = sorted(groups(entries, args.bin).items())
    if args.limit:
        todo = todo[:args.limit]

    state: Dict[Tuple[str, str], dict] = {}
    for (b, cls), keys in todo:
        good, bad = read_copies(entries, keys)
        state[(b, cls)] = {"functions": len(keys), "good": good, "left_out": dict(bad), "merged": None, "proven": []}

    def merge_all(which) -> None:
        for bc in which:
            st = state[bc]
            st["merged"] = CM.merge([d for _k, d in st["good"]], bc[1].split("::")[:-1]) if len(st["good"]) >= 2 else None

    merge_all(state)
    counts = Counter()
    for bc, st in state.items():
        mg = st["merged"]
        kind = ("unreadable" if not st["good"] else "one function" if mg is None
                else "conflict" if mg.conflicts else "merges")
        counts[kind] += 1
        counts[kind + " (functions)"] += st["functions"]
    print(f"{len(state)} classes, {sum(s['functions'] for s in state.values())} matched member functions")
    for kind in ("merges", "conflict", "one function", "unreadable"):
        print(f"  {kind:13} {counts[kind]:5} classes, {counts[kind + ' (functions)']:5} functions")
    if not args.verify:
        print("Nothing is proven yet: run with --verify (needs the game files and the compiler).")
        return 0

    import msvc_verify as MV
    if not MV.find_msvc71_bin():
        print("The compiler is missing (portal/tools/msvc71/bin/cl.exe).", file=sys.stderr)
        return 1
    pending = [bc for bc, st in state.items() if st["merged"] is not None and not st["merged"].conflicts]
    for rnd in range(4):
        jobs = []
        for bc in pending:
            st = state[bc]
            for i, (key, decl) in enumerate(st["good"]):
                jobs.append((key, entries[key], CM.with_class(entries[key]["code"], decl, st["merged"], i)))
        if not jobs:
            break
        print(f"round {rnd + 1}: compiling {len(jobs)} functions of {len(pending)} classes ...", flush=True)
        with Pool(args.jobs) as pool:
            results = dict(pool.imap_unordered(check, jobs, chunksize=4))
        again = []
        for bc in pending:
            st = state[bc]
            failed = [(k, d) for k, d in st["good"] if results[k]]
            if not failed:
                st["proven"] = [k for k, _d in st["good"]]
                continue
            for k, _d in failed:
                st["left_out"][k] = "with the merged class: " + results[k]
            st["good"] = [(k, d) for k, d in st["good"] if not results[k]]
            again.append(bc)                                   # try again without the ones that failed
        merge_all(again)
        pending = [bc for bc in again if state[bc]["merged"] is not None and not state[bc]["merged"].conflicts]

    if OUT_DIR.exists():
        for old in OUT_DIR.rglob("*.h"):
            old.unlink()
    report = {}
    total = Counter()
    for (b, cls), st in sorted(state.items()):
        mg = st["merged"]
        proven = [entries[k] for k in st["proven"]]
        row = {"functions": st["functions"], "proven": len(proven)}
        if len(proven) >= 2:
            path = header_path(b, cls)
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(header_text(b, cls, mg, proven), encoding="utf-8", newline="\n")
            row["header"] = path.relative_to(ROOT).as_posix()
            row["proven_functions"] = sorted(e["va"] for e in proven)
            if mg.notes:
                row["choices"] = mg.notes
            total["classes with a proven declaration"] += 1
            total["functions proven against a merged class"] += len(proven)
        if mg is not None and mg.conflicts:
            row["conflicts"] = mg.conflicts
        if st["left_out"]:
            row["left_out"] = {entries[k]["va"]: why for k, why in sorted(st["left_out"].items())}
        report[f"{b}:{cls}"] = row
    out = {"what": "Each class merged from its matched functions' own copies; see portal/scripts/merge_classes.py.",
           "compiler": MV.compiler_version(),
           "classes": len(state), "member_functions": sum(s["functions"] for s in state.values()),
           "classes_proven": total["classes with a proven declaration"],
           "functions_proven": total["functions proven against a merged class"],
           "by_class": report}
    OUT_JSON.write_text(json.dumps(out, indent=1, ensure_ascii=False) + "\n", encoding="utf-8", newline="\n")
    print(f"{out['classes_proven']} classes have a proven declaration, covering {out['functions_proven']} functions.")
    print(f"Wrote {OUT_JSON.relative_to(ROOT)} and {OUT_DIR.relative_to(ROOT)}/")
    return 0


if __name__ == "__main__":
    sys.exit(main())
