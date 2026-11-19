#!/usr/bin/env python3
"""Export everything from your copied game files once and say what went wrong or is missing.

    python portal/scripts/check_exports.py                    # the PC's cutscenes and map areas
    python portal/scripts/check_exports.py --version xbox     # another version
    python portal/scripts/check_exports.py --only cutscenes   # or: areas

It makes each cutscene and each map area the way the portal does for Blender, keeps nothing, and writes a
report to extracted/blender/<version>/export_check.md (beside your exports, which are yours only):

  * what could not be made at all, and why;
  * cutscenes: who is in each, whose model was not found, whose face moves, the scene's own props, the
    sound track and the spoken lines, and the parts of a cutscene that plays on into others;
  * map areas: how many props were placed, and which could not be (with the models they need), the
    pictures the game itself does not have, and the drawables that could not be read.

Run it after copying your game files again or after updating the project: the numbers at the top should
not go down. It takes a while (every scene and every area is built once): a few minutes to half an hour.
"""

from __future__ import annotations

import argparse
import sys
import time
from collections import Counter
from pathlib import Path
from typing import Dict, List

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "portal" / "tools"))

import blender_export as BX  # noqa: E402
import game_assets as GA  # noqa: E402
import p3d_gltf as P3G  # noqa: E402


def check_cutscenes(out: Path, index: dict, version: str, log=print) -> List[dict]:
    rows = []
    for c in BX.cutscenes(out, index, version):
        if c.get("mission") or c.get("follows"):
            continue
        name = c["name"]
        row: Dict = {"name": name}
        t = time.time()
        try:
            _glb, r = BX.cutscene_glb(out, index, version, name, join=False)
            row["cast"] = list(r.cast)
            row["props"] = list(r.scene_props)
            row["left_out"] = sorted(r.missing_drawables)
            row["sound"] = bool(BX.cutscene_sounds(out, index, version, name))
            row["lines"] = len(BX.cutscene_captions(out, index, version, name))
        except (P3G.ExportError, OSError, ValueError) as e:
            row["error"] = str(e)
        row["seconds"] = round(time.time() - t, 1)
        rows.append(row)
        log(f"  {name}: " + (row.get("error") or f"{len(row['cast'])} people, {row['seconds']} s"))
    return rows


def check_areas(out: Path, index: dict, version: str, log=print) -> List[dict]:
    rows = []
    parsed: dict = {}
    library = [(p.name, p.read_bytes()) for p in BX._library(out, index, version)]
    for a in BX.areas(out, index, version):
        row: Dict = {"name": a["key"]}
        try:
            _glb, r = BX.area_glb(out, index, version, a["key"], parsed, library, insides=False)
            row.update(placed=r.placed, unplaced=dict(r.unplaced), at_origin=r.at_origin,
                       missing_drawables=sorted(r.missing_drawables), missing_textures=sorted(r.missing_textures),
                       unread=r.unread_groups)
        except (P3G.ExportError, OSError, ValueError) as e:
            row["error"] = str(e)
        rows.append(row)
        log(f"  {a['key']}: " + (row.get("error") or f"{row['placed']} props placed"))
    return rows


def report(version: str, scenes: List[dict], areas: List[dict]) -> str:
    out = [f"# What the exports of the {GA.LABELS.get(version, version)} files hold", "",
           f"Made by `portal/scripts/check_exports.py` on {time.strftime('%Y-%m-%d %H:%M')}.", ""]
    if scenes:
        ok = [s for s in scenes if "error" not in s]
        people = [p for s in ok for p in s["cast"]]
        out += ["## Cutscenes", "",
                "| | |", "| :--- | ---: |",
                f"| cutscenes | {len(scenes)} |",
                f"| made | {len(ok)} |",
                f"| people in them | {len(people)} |",
                f"| people whose model was found | {sum(1 for p in people if p.get('model'))} |",
                f"| bodies that move | {sum(1 for p in people if p.get('body') == 'moves')} |",
                f"| faces that move | {sum(1 for p in people if p.get('face') == 'moves')} |",
                f"| scenes' own props | {sum(len(s['props']) for s in ok)} |",
                f"| with a sound track | {sum(1 for s in ok if s['sound'])} |",
                f"| with spoken lines | {sum(1 for s in ok if s['lines'])} |", ""]
        bad = [s for s in scenes if "error" in s]
        if bad:
            out += ["Not made:", ""] + [f"* `{s['name']}`: {s['error']}" for s in bad] + [""]
        missing = [(s["name"], p["name"], p.get("template", "")) for s in ok for p in s["cast"] if not p.get("model")]
        if missing:
            out += ["People whose model was not found:", ""] + [f"* `{a}`: {b} (`{c}`)" for a, b, c in missing] + [""]
        lost = Counter(x for s in ok for x in s["left_out"])
        if lost:
            out += ["Left out (not found or not readable), how many scenes:", ""] + \
                   [f"* `{k}`: {v}" for k, v in lost.most_common(40)] + [""]
    if areas:
        ok = [a for a in areas if "error" not in a]
        unplaced = Counter()
        for a in ok:
            unplaced.update(a["unplaced"])
        out += ["## Map areas", "", "| | |", "| :--- | ---: |",
                f"| areas | {len(areas)} |", f"| made | {len(ok)} |",
                f"| props placed | {sum(a['placed'] for a in ok)} |",
                f"| props not placed (their model not found) | {sum(unplaced.values())} |",
                f"| props at (0, 0, 0), left out | {sum(a['at_origin'] for a in ok)} |",
                f"| pictures the game does not have | {len({t for a in ok for t in a['missing_textures']})} |",
                f"| parts that could not be read | {sum(a['unread'] for a in ok)} |", ""]
        bad = [a for a in areas if "error" in a]
        if bad:
            out += ["Not made:", ""] + [f"* `{a['name']}`: {a['error']}" for a in bad] + [""]
        if unplaced:
            out += ["Props not placed, by model:", ""] + [f"* `{k}`: {v}" for k, v in unplaced.most_common(40)] + [""]
        lost = Counter(x for a in ok for x in a["missing_drawables"])
        if lost:
            out += ["Drawables not found, how many areas:", ""] + [f"* `{k}`: {v}" for k, v in lost.most_common(40)] + [""]
    return "\n".join(out) + "\n"


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--version", default="pc", choices=sorted(GA.LABELS))
    ap.add_argument("--only", choices=("cutscenes", "areas"))
    args = ap.parse_args(argv)
    out = GA.out_dir(ROOT / "binaries")
    index = GA.load_index(out)
    if not index or args.version not in (index.get("versions") or {}):
        print("Copy your game files first (the portal's Game files tab): there is nothing to check.")
        return 2
    scenes = [] if args.only == "areas" else (print("Cutscenes:") or check_cutscenes(out, index, args.version))
    areas = [] if args.only == "cutscenes" else (print("Map areas:") or check_areas(out, index, args.version))
    text = report(args.version, scenes, areas)
    dest = GA.made_dir(ROOT / "binaries", BX.OUT_NAME) / GA.LABELS[args.version] / "export_check.md"
    dest.parent.mkdir(parents=True, exist_ok=True)
    dest.write_text(text, encoding="utf-8")
    print("\n" + text.split("\n## ", 1)[-1][:2000])
    print(f"Written: {dest}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
