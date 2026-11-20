#!/usr/bin/env python3
"""
Compare two versions' script files, as extract_scripts.py copies them out (binaries/scripts_and_data/<version>/):
which are the same byte for byte, which differ, and which only one version has.

    python portal/scripts/diff_scripts.py xbox pc                   # writes reports/scriptc_xbox_pc_diff.json
    python portal/scripts/diff_scripts.py xbox pc --text out_dir    # also the decompiled-text diff of each change

The report holds paths, sizes, sha256 and where the bytes first differ; the text diffs (the game's own script
text) are written only where you ask, on your own computer, never into the repository.
"""

from __future__ import annotations

import argparse
import difflib
import hashlib
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "portal" / "tools"))
SCRIPTS = ROOT / "binaries" / "scripts_and_data"


def files(root: Path) -> dict:
    return {p.relative_to(root).as_posix().lower(): p for p in sorted(root.rglob("*"))
            if p.is_file() and not p.name.startswith(".")}


def text_diff(a: bytes, b: bytes, name_a: str, name_b: str) -> list:
    import torque_script as TS
    try:
        return list(difflib.unified_diff(TS.decompile(a).splitlines(), TS.decompile(b).splitlines(),
                                         name_a, name_b, n=2, lineterm=""))
    except Exception as e:  # noqa: BLE001 - a file the decompiler can't read is reported, not fatal
        return [f"could not decompile: {e}"]


def compare(a_root: Path, b_root: Path, a: str = "a", b: str = "b", text_dir: Path = None) -> dict:
    fa, fb = files(a_root), files(b_root)
    same, differ = [], []
    for k in sorted(set(fa) & set(fb)):
        x, y = fa[k].read_bytes(), fb[k].read_bytes()
        if x == y:
            same.append(k)
            continue
        row = {"path": k, f"{a}_size": len(x), f"{b}_size": len(y),
               "first_diff_off": next((i for i, (p, q) in enumerate(zip(x, y)) if p != q), min(len(x), len(y))),
               f"{a}_sha256": hashlib.sha256(x).hexdigest(), f"{b}_sha256": hashlib.sha256(y).hexdigest()}
        if k.endswith((".cso", ".dso")):
            lines = text_diff(x, y, f"{a}/{k}", f"{b}/{k}")
            changed = [s for s in lines if s[:1] in "+-" and not s.startswith(("+++", "---"))]
            row["text_lines_changed"] = len(changed)
            row["only_compiler_padding"] = bool(changed) and all("compiler padding" in s for s in changed)
            if text_dir:
                text_dir.mkdir(parents=True, exist_ok=True)
                (text_dir / (k.replace("/", "__") + ".diff")).write_text("\n".join(lines) + "\n", encoding="utf-8")
        differ.append(row)
    return {"what": f"script files: {a} vs {b}, byte for byte (portal/scripts/diff_scripts.py)",
            "counts": {"identical": len(same), "differ": len(differ), f"{a}_only": len(set(fa) - set(fb)),
                       f"{b}_only": len(set(fb) - set(fa))},
            "identical": same, "differ": differ,
            f"{a}_only": sorted(set(fa) - set(fb)), f"{b}_only": sorted(set(fb) - set(fa))}


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("a", help="a version folder under binaries/scripts_and_data (xbox, pc, ps2, prototype) or a path")
    ap.add_argument("b")
    ap.add_argument("--out", type=Path, default=None, help="default: reports/scriptc_<a>_<b>_diff.json")
    ap.add_argument("--text", type=Path, default=None, help="also write each change's decompiled-text diff here")
    o = ap.parse_args(argv)
    ra, rb = (Path(v) if Path(v).is_dir() else SCRIPTS / v for v in (o.a, o.b))
    for r in (ra, rb):
        if not r.is_dir():
            print(f"no {r}: copy that version's scripts out first (portal/scripts/extract_scripts.py)")
            return 1
    na, nb = Path(o.a).name, Path(o.b).name
    rep = compare(ra, rb, na, nb, o.text)
    out = o.out or ROOT / "reports" / f"scriptc_{na}_{nb}_diff.json"
    out.write_text(json.dumps(rep, indent=1) + "\n")
    print(f"{rep['counts']} -> {out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
