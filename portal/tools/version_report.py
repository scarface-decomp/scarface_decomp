#!/usr/bin/env python3
"""
What differs between Scarface's versions, as public lists of names: docs/VERSIONS.md and docs/versions.json
(shown on the website's versions page).

Made from each version's list of files (portal/tools/game_assets.py --list, or an earlier copy made by the
portal's Game files section). Only names, sizes, types and descriptions such as "Ogg Vorbis, 48,000 Hz,
stereo" go into the report: no file contents, no hashes. Nothing from the game itself is published.

    python portal/tools/version_report.py --scan     read your game files first (takes a while), then write
    python portal/tools/version_report.py            write from the lists already made
"""

from __future__ import annotations

import argparse
import datetime as dt
import json
from collections import Counter, defaultdict
from pathlib import Path
from typing import Dict, List, Optional

import game_assets as GA

ROOT = Path(__file__).resolve().parents[2]
SCHEMA = "scarface_versions_v1"
STATUSES = ("only", "changed", "shared")
FULL_LIST = 250                   # a version with no more exclusives than this has them all listed here


def catalogs_from_disk(bin_dir: Path) -> Dict[str, List[list]]:
    """The lists --list made, or else the ones in the index of an earlier copy."""
    out: Dict[str, List[list]] = {}
    folder = GA.out_dir(bin_dir) / GA.CATALOGS
    for v in GA.VERSIONS:
        try:
            cat = json.loads((folder / f"catalog-{v}.json").read_text(encoding="utf-8"))
        except (OSError, ValueError):
            continue
        if cat.get("complete"):
            out[v] = cat["files"]
    if out:
        return out
    index = GA.load_index(GA.out_dir(bin_dir)) or {}
    for v, info in index.get("versions", {}).items():
        out[v] = [[r[0], r[1], r[2], r[5] if len(r) > 5 else None] for r in info.get("files", [])]
    return out


def _name(path: str, facts: Optional[dict]) -> str:
    """A sound's original name (sounds are stored under a hash of it)."""
    return GA.sound_name(facts) if path.lower().endswith(".rsd") else ""


def _desc(path: str, facts: Optional[dict]) -> str:
    text, name = GA.describe(facts), _name(path, facts)
    return f"{name} ({text})" if name and text else (name or text)


def build(catalogs: Dict[str, List[list]], today: Optional[str] = None) -> dict:
    rows, _places = GA.plan(catalogs, "unique")
    versions, only = [], {}
    by_key: Dict[str, Dict[str, list]] = defaultdict(dict)
    changed_keys = set()
    for v in GA.VERSIONS:
        if v not in rows:
            continue
        r = rows[v]
        kinds: Dict[str, Dict[str, int]] = defaultdict(lambda: dict({s: 0 for s in STATUSES}, bytes_only=0))
        for path, size, _sha, status, _placed, facts, *_ in r:
            k = GA.kind_of(path, facts)
            kinds[k][status] += 1
            if status == "only":
                kinds[k]["bytes_only"] += size
            key = GA.compare_key(path)
            by_key[key].setdefault(v, [size, k, GA.describe(facts), _name(path, facts)])
            if status == "changed":
                changed_keys.add(key)
        counts = Counter(row[3] for row in r)
        versions.append({"id": v, "label": GA.LABELS[v], "files": len(r), "bytes": sum(row[1] for row in r),
                         "only": counts["only"], "changed": counts["changed"], "shared": counts["shared"],
                         "kinds": {k: kinds[k] for k in sorted(kinds, key=_kind_order)}})
        only[v] = sorted([row[0], row[1], GA.kind_of(row[0], row[5]), _desc(row[0], row[5])]
                         for row in r if row[3] == "only")
    diff = []
    for key in sorted(changed_keys):
        per = by_key[key]
        first = next(iter(per.values()))
        name = next((per[v][3] for v in GA.VERSIONS if v in per and per[v][3]), "")
        diff.append([key, first[1], name, [[v, per[v][0], per[v][2]] for v in GA.VERSIONS if v in per]])
    return {"schema": SCHEMA, "generated": today or dt.date.today().isoformat(),
            "kinds": {k: GA.KIND_LABELS[k] for k in sorted(GA.KIND_LABELS, key=_kind_order)},
            "versions": versions, "only": only, "changed": diff}


def _kind_order(k: str) -> int:
    order = [k2 for k2, _l, _e in GA.KINDS] + ["other"]
    return order.index(k) if k in order else len(order)


def _size(n: int) -> str:
    for unit in ("bytes", "KB", "MB", "GB"):
        if n < 1024 or unit == "GB":
            return f"{n:,} {unit}" if unit == "bytes" else f"{n:,.1f} {unit}"
        n /= 1024
    return str(n)


def _top_folders(paths: List[str], n: int = 8) -> List[tuple]:
    c: Counter = Counter()
    for p in paths:
        parts = GA.compare_key(p).split("/")
        c["/".join(parts[:2]) + ("/" if len(parts) > 2 else "")] += 1
    return c.most_common(n)


def markdown(report: dict) -> str:
    vs = report["versions"]
    labels = report["kinds"]
    out = [
        "# What differs between the versions",
        "",
        "Every file of each version of *Scarface: The World Is Yours*, compared with the others. Generated by",
        "`portal/tools/version_report.py` from the game files on " + report["generated"] + "; the website's",
        "[versions page](https://scarface-decomp.pages.dev/versions.html) has the full lists, searchable.",
        "Only names, sizes and descriptions are listed here: nothing from the files themselves.",
        "",
        "A file is **only here** when no other version has it, **different** when another version has it in",
        "another form (another sound codec, other textures, other code), and **the same** when another version",
        "has exactly the same bytes. Files are matched by their path in the game, ignoring the `.rcf` archive",
        "they are packed in and upper or lower case.",
        "",
        "| Version | Files | Size | Only here | Different | The same |",
        "| :--- | ---: | ---: | ---: | ---: | ---: |",
    ]
    for v in vs:
        out.append(f"| {v['label']} | {v['files']:,} | {_size(v['bytes'])} | {v['only']:,} | {v['changed']:,} | {v['shared']:,} |")
    out += ["", "## Only in one version, by type", "",
            "| Type | " + " | ".join(v["label"] for v in vs) + " |",
            "| :--- | " + " | ".join("---:" for _ in vs) + " |"]
    for k, label in labels.items():
        cells = []
        for v in vs:
            info = v["kinds"].get(k)
            cells.append(f"{info['only']:,} ({_size(info['bytes_only'])})" if info and info["only"] else "")
        if any(cells):
            out.append(f"| {label} | " + " | ".join(cells) + " |")
    out += ["", "## Different in another version, by type", "",
            "| Type | " + " | ".join(v["label"] for v in vs) + " |",
            "| :--- | " + " | ".join("---:" for _ in vs) + " |"]
    for k, label in labels.items():
        cells = [f"{v['kinds'][k]['changed']:,}" if k in v["kinds"] and v["kinds"][k]["changed"] else "" for v in vs]
        if any(cells):
            out.append(f"| {label} | " + " | ".join(cells) + " |")
    for v in vs:
        files = report["only"].get(v["id"], [])
        if not files:
            continue
        out += ["", f"## Only in the {v['label']} version", ""]
        if len(files) <= FULL_LIST:
            out += [f"{len(files):,} files:", "", "| File | Type | Size | What |", "| :--- | :--- | ---: | :--- |"]
            out += [f"| `{f[0]}` | {labels.get(f[2], f[2])} | {_size(f[1])} | {f[3].replace('|', '/').replace('*', chr(92) + '*')} |" for f in files]
        else:
            out += [f"{len(files):,} files. Where most of them are:", ""]
            out += [f"* `{folder}`: {n:,}" for folder, n in _top_folders([f[0] for f in files], 12)]
    out += ["", "## Making this page", "",
            "With your own copies of the versions in `binaries/` ([GAME_VERSIONS.md](GAME_VERSIONS.md)):", "",
            "```", "python portal/tools/version_report.py --scan", "```", "",
            "It reads every version (this takes a while), keeps the lists in `extracted/game_files/catalogs/`",
            "(never committed), and writes this file, `docs/versions.json` and `docs/versions-changed.json`.", ""]
    return "\n".join(out)


def _lines(obj) -> str:
    """JSON with one list entry per line, so a new comparison shows in git as the lines that changed."""
    def dump(v) -> str:
        return json.dumps(v, separators=(",", ":"), ensure_ascii=False)

    def value(v, depth: int) -> str:
        if isinstance(v, dict) and depth < 2:
            inner = ",\n".join(f"{dump(k)}:{value(x, depth + 1)}" for k, x in v.items())
            return "{\n" + inner + "\n}"
        if isinstance(v, list) and v and depth <= 2:
            return "[\n" + ",\n".join(dump(x) for x in v) + "\n]"
        return dump(v)
    return value(obj, 0) + "\n"


def write(report: dict, docs: Path) -> List[Path]:
    """VERSIONS.md, versions.json (the page's summary and exclusives) and versions-changed.json (every file
    that differs, which the page loads when asked: it is the big one)."""
    small = {k: v for k, v in report.items() if k != "changed"}
    small["changed_file"] = "versions-changed.json"
    (docs / "versions.json").write_text(_lines(small), encoding="utf-8", newline="\n")
    (docs / "versions-changed.json").write_text(_lines({"schema": SCHEMA, "generated": report["generated"],
                                                        "changed": report["changed"]}), encoding="utf-8", newline="\n")
    (docs / "VERSIONS.md").write_text(markdown(report), encoding="utf-8", newline="\n")
    return [docs / "VERSIONS.md", docs / "versions.json", docs / "versions-changed.json"]


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--scan", action="store_true", help="read your game files first (all versions found)")
    ap.add_argument("--bin", type=Path, default=GA.BIN_DIR, help="the folder with your game files")
    a = ap.parse_args(argv)
    if a.scan:
        GA.list_versions(list(GA.VERSIONS), a.bin, log=print)
    catalogs = catalogs_from_disk(a.bin)
    if len(catalogs) < 2:
        print("Need at least two versions' lists: run with --scan (your game files go in binaries/).")
        return 1
    for p in write(build(catalogs), ROOT / "docs"):
        print(f"wrote {p.relative_to(ROOT).as_posix()}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
