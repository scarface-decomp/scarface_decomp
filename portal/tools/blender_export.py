#!/usr/bin/env python3
"""
The portal's Blender exports, from the game files the person has copied (portal/tools/game_assets.py):
a whole map area at once (its shell and detail files, with the region and city files they need), or
every area of the city, one .glb each, into extracted/blender/<version>/. The work is p3d_gltf.py's; this
finds the files.

    model_glb(out, index, version, ...)  one copied file as a .glb (a character with the game's animations)
    areas(out, index, version)          the map areas there are copies of: the city's
                                        (packages/z04/<area>_shell.p3d, _detail.p3d ...), the
                                        interiors (packages/azones/*_pocket.p3d) and the changing
                                        places (packages/dzones/*_dzone.p3d)
    area_glb(out, index, version, key)  one area as a .glb
    CityJob                             every city area, in the background, and the sky round them
                                        (city_sky) and the sea (city_ocean); with an hour, the fog of that
                                        hour (city_fog)
    inspect(data)                       what a .p3d holds, in words, and whether Blender can show it
    find_blender(bin_dir) / open_in_blender(exe, files, save)
                                        start the person's own Blender with .glb files imported, saving
                                        a .blend beside them (a .glb double-clicked makes Blender try to
                                        open it as a .blend: "not a valid Blender file")

Your own copies, on your own computer; standard library only.
"""

from __future__ import annotations

import os
import struct
import re
import shutil
import subprocess
import sys
import threading
import time
from pathlib import Path
from typing import Callable, Dict, List, Optional, Sequence, Tuple

import game_assets as GA
import p3d_gltf as P3G
import cutscene as CUT
import stream_graph as SG
import torque_names as TN
import torque_script as TS

AREA_FOLDERS = ("packages/z04/", "packages/azones/", "packages/dzones/")
CITY = "packages/z04/"
OUT_NAME = "blender"


def _rows(index: Optional[dict], version: str) -> List[list]:
    return ((index or {}).get("versions", {}).get(version) or {}).get("files", [])


def areas(out: Path, index: Optional[dict], version: str) -> List[dict]:
    """[{key, name, place, files}] for every map area with a copied file, city areas first."""
    found: Dict[str, dict] = {}
    for row in _rows(index, version):
        path = row[0]
        low = path.lower()
        if not low.endswith(".p3d") or not row[4]:
            continue
        place = next((f for f in AREA_FOLDERS if f in low), None)
        if place is None or "/" in low.split(place, 1)[1]:
            continue
        stem = Path(path).stem
        if not any(w in stem.lower() for w in ("_shell", "_detail", "_pocket", "_dzone")):
            continue
        name = P3G._area(Path(path))
        key = place.split("/")[1] + "/" + name
        area = found.setdefault(key, {"key": key, "name": name, "place": place.split("/")[1], "files": []})
        area["files"].append(path)
    for key, area in list(found.items()):
        # A place the story changes (Tony's mansion: _TS0 to _TS3; the cargo ship: _CS0, _CS1) has a set
        # of files per stage. All of them in one scene put the wrecked mansion inside the rebuilt one:
        # the area is its last stage, and each earlier stage is an area of its own.
        stages = sorted({m.group(1).upper() for f in area["files"] for m in [STAGE_FILE.search(Path(f).stem)] if m})
        if stages:
            every = area["files"]
            area["files"], area["stage"] = _at_stage(every, stages[-1]), stages[-1]
            for st in stages[:-1]:
                found[key + "@" + st] = {"key": key + "@" + st, "name": area["name"] + " " + st, "place": area["place"],
                                         "files": _at_stage(every, st), "stage": st, "earlier": True}
    for area in found.values():
        # In the whole city: every area as it ends up, and every building's inside as it starts out
        # (not the same shop again owned, damaged, destroyed and condemned, one on top of the other).
        inside = area["place"] != "z04"
        area["city"] = not area.get("earlier") and not (inside and STATE_ZONE.search(area["name"]))
        area["file"] = area["name"] + (" (inside)" if inside else "")
    order = {f.split("/")[1]: i for i, f in enumerate(AREA_FOLDERS)}
    return sorted(found.values(), key=lambda a: (order[a["place"]], a["name"].lower()))


STAGE_FILE = re.compile(r"_((?:TS|CS)\d)$", re.I)
STATE_ZONE = re.compile(r"(?:\d\d)?(?:owned|damaged|destroyed|condemned|toast)(?:_\d+)?$", re.I)


def _at_stage(files: List[str], stage: str) -> List[str]:
    """An area's files as the place is at one stage: the files with no stage, and of each staged file the
    one for that stage (or the nearest one before it: a part the later stages don't change)."""
    kept, staged = [], {}
    for f in files:
        m = STAGE_FILE.search(Path(f).stem)
        if not m:
            kept.append(f)
        elif m.group(1).upper()[:2] == stage[:2] and m.group(1).upper() <= stage:
            base = Path(f).stem[:m.start()].lower()
            if base not in staged or STAGE_FILE.search(Path(staged[base]).stem).group(1).upper() < m.group(1).upper():
                staged[base] = f
    return kept + [staged[b] for b in sorted(staged)]


def city_areas(out: Path, index: Optional[dict], version: str) -> List[dict]:
    """The areas that make up the whole city, the buildings' insides with them."""
    found = areas(out, index, version)
    return [a for a in found if a["city"]] if any(a["place"] == "z04" for a in found) else []


_CENTRES: Dict[tuple, Optional[tuple]] = {}


def _centre(path: Path) -> Optional[tuple]:
    """Where a building's inside is: the middle of what its file places (None when it places nothing)."""
    try:
        key = (str(path), path.stat().st_mtime_ns)
        if key not in _CENTRES:
            lib = P3G.Library()
            src = lib.add(path.name, path.read_bytes(), main=True)
            at = [P3G.instance_trs(rec)[0] for _m, records in P3G.instance_objects(src) for rec in records if any(rec[:3])]
            _CENTRES[key] = tuple(sum(p[i] for p in at) / len(at) for i in range(3)) if at else None
        return _CENTRES[key]
    except (OSError, P3G.p3d.P3dError, struct.error):
        return None


def _glb_box(glb: bytes) -> Optional[Tuple[List[float], List[float]]]:
    """The box a .glb's meshes fill (lowest and highest corner), going by where each is put."""
    import json
    try:
        doc = json.loads(glb[20:20 + struct.unpack_from("<I", glb, 12)[0]])
    except (struct.error, ValueError):
        return None
    lo, hi = [1e18] * 3, [-1e18] * 3

    def walk(i: int, off: List[float]) -> None:
        n = doc["nodes"][i]
        if (n.get("extras") or {}).get("ocean"):
            return                                       # the sea reaches far past what it is round
        t = n["matrix"][12:15] if "matrix" in n else n.get("translation", [0, 0, 0])
        o = [off[k] + t[k] for k in range(3)]
        if "mesh" in n:
            for prim in doc["meshes"][n["mesh"]]["primitives"]:
                acc = doc["accessors"][prim["attributes"]["POSITION"]]
                if "min" in acc:
                    for k in range(3):
                        lo[k], hi[k] = min(lo[k], o[k] + acc["min"][k]), max(hi[k], o[k] + acc["max"][k])
        for c in n.get("children", []):
            walk(c, o)
    for r in doc["scenes"][0]["nodes"]:
        walk(r, [0.0, 0.0, 0.0])
    return (lo, hi) if lo[0] <= hi[0] else None


def insides_of(out: Path, index: Optional[dict], version: str, area: dict, glb: bytes) -> List[Path]:
    """The files of the buildings' insides that belong in a city area: the ones of the same name
    (babylonclub_01's pocket) and the ones whose furniture stands within the area."""
    box = _glb_box(glb)
    stem = re.sub(r"_\d+$", "", area["name"]).lower()
    found = []
    for other in areas(out, index, version):
        if other["place"] == "z04" or not other["city"]:
            continue
        paths = [p for p in (GA.file_on_disk(out, index, version, f) for f in other["files"]) if p is not None]
        same = re.sub(r"_\d+$", "", other["name"]).lower() == stem
        within = False
        if box and not same:
            for p in paths:
                c = _centre(p)
                if c and all(box[0][k] - 2 <= c[k] <= box[1][k] + 2 for k in (0, 2)):
                    within = True
        if same or within:
            found += paths
    return found


def _city_folder_path(index: Optional[dict], version: str) -> Optional[str]:
    """A path in the city's folder (for finding the shared files beside it)."""
    return next((r[0] for r in _rows(index, version) if CITY in r[0].lower() and r[4]), None)


def _library(out: Path, index: Optional[dict], version: str) -> List[Path]:
    anchor = _city_folder_path(index, version)
    return GA.files_beside(out, index, version, anchor, P3G.MAP_LIBRARY) if anchor else []


MORE_FOLDERS = ("/packages/dzones/", "/packages/azones/", "/packages/z04/")
MODEL_ENDINGS = (b"instanceshape", b"shape", b"instance")
MORE_PER_MODEL = 4


def _more_library(out: Path, index: Optional[dict], version: str) -> List[Path]:
    """Where else a placed model can be. The game keeps one copy of each prop's model, in whichever file
    needed it first: a mansion's piano bench with the building's inside, a beach's crates with the beach
    next door. So the interiors' files and the other areas' files are looked in too."""
    found = []
    for row in _rows(index, version):
        low = "/" + row[0].lower().replace("\\", "/")
        if low.endswith(".p3d") and any(f in low for f in MORE_FOLDERS):
            p = GA.file_on_disk(out, index, version, row[0])
            if p is not None:
                found.append(p)
    return found


def _files_naming(paths: Sequence, names, skip=()) -> List[Tuple[str, bytes]]:
    """The fewest files among paths (Path or [name, path]) that hold the named models: (name, bytes).
    A file that has a model's own parts (woodcrateAInstanceShape) is taken before one that only
    mentions the name, which may be nothing but another area placing the same prop."""
    wanted = [n.lower().encode("latin-1", "replace") for n in names if n]
    skip = {s.lower() for s in skip}
    sure: Dict[bytes, List[Path]] = {}
    maybe: Dict[bytes, List[Path]] = {}
    for item in paths:
        path = Path(item[1]) if isinstance(item, (list, tuple)) else Path(item)
        if path.name.lower() in skip:
            continue
        try:
            low = path.read_bytes().lower()
        except OSError:
            continue
        for w in wanted:
            if w not in low:
                continue
            if any(w + e in low for e in MODEL_ENDINGS):
                sure.setdefault(w, []).append(path)
            else:
                maybe.setdefault(w, []).append(path)
    chosen: List[Path] = []
    for w in wanted:
        holders = sure.get(w) or maybe.get(w, [])[:MORE_PER_MODEL]
        if holders and not any(h in chosen for h in holders):
            chosen.extend(holders[:1] if w in sure else holders)
    out = []
    for path in chosen:
        try:
            out.append((path.name, path.read_bytes()))
        except OSError:
            continue
    return out


def animations(out: Path, index: Optional[dict], version: str) -> List[Path]:
    """The copied animation files (art/animations/*.p3d): 30 files, 6 MB on the PC."""
    found = []
    for row in _rows(index, version):
        low = row[0].lower()
        if "/art/animations/" in low and low.endswith(".p3d") and "/" not in low.split("/art/animations/", 1)[1]:
            p = GA.file_on_disk(out, index, version, row[0])
            if p is not None:
                found.append(p)
    return found


def _files_with(paths: Sequence, names, skip=(), most: int = 8) -> List[Tuple[str, bytes]]:
    """The files among paths that mention any of the names (a texture's, say), fewest first: (name, bytes)."""
    wanted = {n.lower().encode("latin-1", "replace") for n in names if n}
    skip = {s.lower() for s in skip}
    out = []
    for path in paths:
        path = Path(path)
        if not wanted or len(out) >= most:
            break
        if path.name.lower() in skip:
            continue
        try:
            data = path.read_bytes()
        except OSError:
            continue
        low = data.lower()
        has = {w for w in wanted if w in low}
        if has:
            out.append((path.name, data))
            wanted -= has
    return out


def model_glb(out: Path, index: Optional[dict], version: str, game_path: str, data: bytes) -> Tuple[bytes, "P3G.Report"]:
    """One copied .p3d file as a .glb. A map area also gets its region's and the city's shared files; a
    character gets the game's animations (art/animations), each as an action. What is still missing
    after that (a sign's lettering kept in the city's shared textures, a prop kept with another area) is
    looked for in the city's files, and the model made again with the ones that have it."""
    name = Path(game_path).name
    scene = CUT.scene_name(game_path)
    if scene:                                   # a cutscene's file: the whole cutscene, everybody in it
        try:
            return cutscene_glb(out, index, version, scene)
        except P3G.ExportError:
            if game_path.lower().endswith(".fsc"):
                raise

    def make(extra: List[Tuple[str, bytes]]):
        lib = P3G.Library()
        src = lib.add(name, data, main=True)
        have = {name.lower()}
        is_map = bool(P3G._world_geo(lib, src) or P3G.instance_objects(src))
        anims = []

        def also(n: str, d: bytes, main: bool = False):
            if n.lower() in have:
                return None
            have.add(n.lower())
            try:
                return lib.add(n, d, main=main)
            except P3G.p3d.P3dError:
                return None
        if is_map:
            for f in GA.files_beside(out, index, version, game_path, P3G.MAP_LIBRARY):
                try:
                    also(f.name, f.read_bytes())
                except OSError:
                    pass
        elif _moves_only(src):
            actor = stand_in(out, index, version)          # the people's animations, on Tony
            if actor is not None:
                try:
                    also(actor.name, actor.read_bytes(), main=True)
                except OSError:
                    pass
        elif any(c.id == P3G.SKIN for c in src.chunks):
            for f in animations(out, index, version):
                try:
                    more = also(f.name, f.read_bytes())
                except OSError:
                    continue
                if more is not None:
                    anims += [P3G.Ref(more, c) for c in more.chunks if c.id == P3G.ANIMATION]
        for n, d in extra:
            also(n, d)
        return P3G.export(lib, map_mode=is_map, anims=anims, ocean=is_map), have
    (glb, report), have = make([])
    extra: List[Tuple[str, bytes]] = []
    if report.unplaced:
        extra += _files_naming(_more_library(out, index, version), report.unplaced, have)
    if report.missing_textures:
        skip = have | {n.lower() for n, _d in extra}
        extra += _files_with(_library(out, index, version), report.missing_textures, skip)
    if extra:
        try:
            (glb2, report2), _h = make(extra)
        except P3G.ExportError:
            return glb, report
        if (len(report2.missing_textures), sum(report2.unplaced.values())) < \
                (len(report.missing_textures), sum(report.unplaced.values())):
            return glb2, report2
    return glb, report


def _scene_rows(index: Optional[dict], version: str) -> Dict[str, str]:
    return {("/" + r[0].lower().replace("\\", "/")): r[0] for r in _rows(index, version) if r[4]}


_NEXT: Dict[tuple, Dict[str, str]] = {}


def plays_next(out: Path, index: Optional[dict], version: str) -> Dict[str, str]:
    """Which cutscene the game plays straight after another, from the copied mission scripts (see
    cutscene.plays_next): {cutscene (lower): the next (lower)}. Worked out once for a copy."""
    rows = _scene_rows(index, version)
    key = (version, len(rows), str(out))
    if key not in _NEXT:
        texts = []
        for low, path in rows.items():
            if "/scriptc/" not in low or not low.endswith((".cso", ".dso")):
                continue
            p = GA.file_on_disk(out, index, version, path)
            try:
                raw = p.read_bytes() if p is not None else b""
                if b"NIS_" in raw:
                    texts.append(TS.decompile(raw))
            except Exception:  # a script the decompiler can't read tells nothing: the rest still do
                continue
        _NEXT[key] = CUT.plays_next(texts, TN.compiled_name)
    return _NEXT[key]


def cutscenes(out: Path, index: Optional[dict], version: str) -> List[dict]:
    """The copied cutscenes, one entry each: [{name, then: [the ones the game plays straight after]}]. A
    cutscene kept twice (PAL_<name>, for European televisions) is listed once; one that only ever plays
    on the end of another is listed under that one."""
    rows = _scene_rows(index, version)
    found: Dict[str, str] = {}
    for low in rows:
        m = re.search(r"/art/nis/fsc/([^/]+)\.fsc$", low)
        if m:
            found[m.group(1)] = Path(rows[low]).stem
    after = plays_next(out, index, version) if found else {}
    out_: List[dict] = []
    follows = {b for a, b in after.items() if a in found}
    for low in sorted(found):
        if low.startswith("pal_") and low[4:] in found:
            continue
        chain, at = [], low
        while at in after and after[at] in found and after[at] not in chain and after[at] != low and len(chain) < 6:
            at = after[at]
            chain.append(found[at])
        out_.append({"name": found[low], "then": chain, "follows": low in follows})
    return out_


def cutscene_glb(out: Path, index: Optional[dict], version: str, scene: str, join: bool = True) -> Tuple[bytes, "P3G.Report"]:
    """A cutscene (art/nis/<scene>) with its people, vehicles and camera, from the copied files: its
    script says who is in it, its stream files hold what they do (see cutscene.py). With join, the
    cutscenes the game plays straight after it are joined on."""
    rows = _scene_rows(index, version)

    def named(ending: str) -> Optional[Path]:
        ending = ending.lower()
        hit = next((path for low, path in rows.items() if low.endswith(ending)), None)
        return GA.file_on_disk(out, index, version, hit) if hit else None

    def parts(name: str):
        fsc = named(f"/art/nis/fsc/{name}.fsc")
        if fsc is None:
            raise P3G.ExportError("that cutscene's script isn't in your copied game files")
        folder = f"/art/nis/{name}/".lower()
        streams = []
        for low, path in rows.items():
            m = re.search(re.escape(folder) + r"stream(\d+)\.p3d$", low)
            if m:
                p = GA.file_on_disk(out, index, version, path)
                if p is not None:
                    streams.append((int(m.group(1)), p))
        if not streams:
            raise P3G.ExportError("that cutscene's animations aren't in your copied game files")
        return CUT.read_script(fsc.read_text(encoding="latin-1")), [(p.name, p.read_bytes()) for _n, p in sorted(streams)]

    def model(kind: str, wanted: str) -> Optional[Tuple[str, bytes]]:
        if kind == "tony":
            suits = ([wanted.lower() + ".p3d"] if wanted else []) + list(CUT.TONY_FILES)
            p = next((q for q in (named("/art/nis/characters/" + f) for f in suits) if q), None) \
                or stand_in(out, index, version)
        elif kind == "vehicle":
            p = named(f"/art/vehicles/{wanted}.p3d")
        elif kind == "weapons":
            p = named("/art/stateprops/weapons_test/guns.p3d")
        else:
            p = next((q for q in (named(f"/art/characters/{d}{wanted}.p3d") for d in ("npc/", "pc/", "")) if q), None)
        try:
            return (p.name, p.read_bytes()) if p is not None else None
        except OSError:
            return None
    script, pieces = parts(scene)
    then = []
    if join:
        entry = next((c for c in cutscenes(out, index, version) if c["name"].lower() == scene.lower()), None)
        for name in (entry or {}).get("then", []):
            try:
                then.append((name,) + parts(name))
            except P3G.ExportError:
                break
    # The street or room it happens in: what the game keeps loaded at that spot (the stream graph).
    area: List[Tuple[str, bytes]] = []
    library: List[Tuple[str, bytes]] = []
    graph = named("/art/levels/z04/streamgraph.p3d")
    spots = [w for w in (CUT.where(sc, st) for sc, st in [(script, pieces)] + [(sc, st) for _n, sc, st in then]) if w]
    if spots and graph is not None:
        try:
            triggers = SG.triggers(graph.read_bytes())
            seen = set()
            for spot in spots:
                loaded = SG.loaded_at(triggers, spot[0], spot[1])
                if not loaded.inside:
                    continue
                for package, slot in loaded.packages:
                    if slot in ("Shell", "Detail") and package.lower() not in seen:
                        seen.add(package.lower())
                        p = named(f"/packages/z04/{package}.p3d")
                        if p is not None:
                            area.append((p.name, p.read_bytes()))
            if area:
                library = [(p.name, p.read_bytes()) for p in _library(out, index, version)]
        except (OSError, P3G.p3d.P3dError, struct.error, ValueError, IndexError):
            area, library = [], []
    try:
        glb, report = CUT.export(scene, script, pieces, model, area, library, then)
    except P3G.ExportError:
        raise
    except (P3G.p3d.P3dError, struct.error, ValueError, IndexError, KeyError):
        if not area:
            raise
        return CUT.export(scene, script, pieces, model, then=then)          # the map wouldn't come in: the cast without it
    if report.unplaced and area:                             # props kept with another area (see area_from_files)
        have = [n for n, _d in area] + [n for n, _d in library]
        extra = _files_naming(_more_library(out, index, version), report.unplaced, have)
        if extra:
            again = CUT.export(scene, script, pieces, model, area, library + extra, then)
            if sum(again[1].unplaced.values()) < sum(report.unplaced.values()):
                return again
    return glb, report


MODEL_CHUNKS = (P3G.SKIN, P3G.COMPOSITE, P3G.MESH)
STAND_INS = ("art/characters/pc/mcp_blacksuittony.p3d", "art/characters/npc/chartemp_npc_blacksuittony.p3d")


def _moves_only(src: "P3G.Source") -> bool:
    """Animations for people (not a camera's), and nothing to show them on."""
    if any(c.id in MODEL_CHUNKS for c in src.chunks):
        return False
    return any(c.id == P3G.ANIMATION and (P3G.p3d.fields(src.data, c).get("type") or "").upper() != "CAM"
               for c in src.chunks)


def stand_in(out: Path, index: Optional[dict], version: str) -> Optional[Path]:
    """Tony, for showing the people's animations on (every person in the game has the same 27 joints). From
    this version's copied files, or another's: a copy that keeps only what one version has (The PC first,
    No duplicates) leaves the others without him, and their animations would have nobody to play on."""
    others = [v for v in GA.PREFER if v != version and v in (index or {}).get("versions", {})]
    for v in [version] + others:
        rows = _rows(index, v)
        for want in STAND_INS:
            for row in rows:
                if row[0].lower().endswith(want):
                    p = GA.file_on_disk(out, index, v, row[0])
                    if p is not None:
                        return p
    return None


CHECK_MAX = 16 << 20        # bigger files aren't tried ahead of time: Open in Blender says so if they can't be shown


def cant_show(out: Path, index: Optional[dict], version: str, game_path: str, data: bytes) -> str:
    """Why Open in Blender would have nothing to show for this copied file, or "" when it would work (or the
    file is a map area or too big to try ahead of time). The portal asks before it offers the button."""
    if len(data) > CHECK_MAX:
        return ""
    scene = CUT.scene_name(game_path)
    if scene:
        try:
            cutscene_glb(out, index, version, scene)
            return ""
        except P3G.ExportError as e:
            if not Path(game_path).name.lower().startswith("stream"):
                return f"This cutscene can't be shown: {e}."
        except (OSError, P3G.p3d.P3dError, ValueError, KeyError, IndexError):
            return ""
    try:
        lib = P3G.Library()
        src = lib.add(Path(game_path).name, data, main=True)
        if P3G._world_geo(lib, src) or P3G.instance_objects(src):
            return ""
        if _moves_only(src):
            if stand_in(out, index, version) is None:
                return ("Animations with nobody to show them on: Tony's model isn't among your copied files. "
                        "Copy the PC version's files and they play on him.")
            return ""
        P3G.export(lib)
    except P3G.ExportError:
        label = GA.LABELS.get(version, version)
        return (f"Blender has nothing to show from the {label}'s copy of this file: its models are stored in a form "
                "the portal can't turn into a scene yet. Try the same file under another version.")
    except (P3G.p3d.P3dError, ValueError, KeyError, IndexError):
        return ""
    return ""


def city_counts(out: Path, index: Optional[dict]) -> Dict[str, int]:
    """How many city areas each version's copied files hold: {version: areas}."""
    return {v: len(city_areas(out, index, v))
            for v in (index or {}).get("versions", {})}


def inspect(data: bytes) -> dict:
    """What a .p3d holds, for the portal: {what (in words), kind, pictures, blender, lines}."""
    import media as MEDIA
    try:
        lib = P3G.Library()
        src = lib.add("file.p3d", data)
    except P3G.p3d.P3dError as e:
        return {"kind": "unknown", "what": f"Not a Pure3D file the portal can read ({e}).", "pictures": 0,
                "blender": False, "lines": []}
    count: Dict[int, int] = {}
    for c in P3G.p3d.walk(src.chunks):
        count[c.id] = count.get(c.id, 0) + 1
    top = {}
    for c in src.chunks:
        top[c.id] = top.get(c.id, 0) + 1
    pictures = count.get(0x19000, 0)
    lines = MEDIA.subtitles(data) if top.get(MEDIA.SUBTITLE) else []
    moves = cams = 0
    for c in src.chunks:
        if c.id == P3G.ANIMATION:
            if (P3G.p3d.fields(data, c).get("type") or "").upper() == "CAM":
                cams += 1
            else:
                moves += 1
    cameras = top.get(P3G.CAMERA, 0)
    world, placed = P3G._world_geo(lib, src), sum(len(r) for _m, r in P3G.instance_objects(src))
    skins, comps, meshes = top.get(P3G.SKIN, 0), top.get(P3G.COMPOSITE, 0), top.get(P3G.MESH, 0)

    def n(k: int, one: str, many: str) -> str:
        return f"{k:,} {one if k == 1 else many}"
    parts, kind = [], "other"
    if lines:
        kind = "subtitles"
        parts.append("Subtitles: the words of the sound with the same name")
    elif world or placed:
        kind = "map"
        parts.append("A map area" + (": its buildings and ground" if world else "")
                     + (f", and {n(placed, 'object', 'objects')} placed on it" if placed else ""))
    elif skins:
        kind = "character"
        parts.append(n(skins, "character (or other skinned model) with its skeleton",
                       "characters (or other skinned models) with their skeletons"))
    elif comps or meshes:
        kind = "models"
        parts.append(n(comps or meshes, "model", "models"))
    if cameras:
        kind = kind if kind != "other" else "camera"
        parts.append(n(cameras, "camera", "cameras") + (" with its move" if cams == 1 and cameras == 1 else
                                                       f" and {n(cams, 'camera move', 'camera moves')}" if cams else ""))
    if moves:
        kind = kind if kind != "other" else "animations"
        parts.append(n(moves, "animation", "animations")
                     + (" (shown on Tony: everyone in the game has the same skeleton)" if kind == "animations" else ""))
    if pictures:
        kind = kind if kind != "other" else "pictures"
        parts.append(n(pictures, "picture", "pictures"))
    if not parts:
        parts.append("Game data with nothing to show: " + ", ".join(
            sorted({P3G.p3d.NAMES.get(c.id, hex(c.id)) for c in src.chunks})[:6]))
    blender = bool(world or placed or skins or comps or meshes or cameras or moves)
    return {"kind": kind, "what": "; ".join(parts) + ".", "pictures": pictures, "blender": blender,
            "lines": [{"language": lang, "text": text} for lang, text in lines]}


def area_glb(out: Path, index: Optional[dict], version: str, key: str,
             parsed: Optional[dict] = None, library: Optional[List[Tuple[str, bytes]]] = None,
             insides: bool = True, opts: Optional[dict] = None, ocean: bool = True) -> Tuple[bytes, "P3G.Report"]:
    """One map area (all its files) as a .glb, with what it needs from the shared files. A city area
    opened by itself comes with its buildings' insides (the club's furniture in the club); the whole
    city leaves them out (insides=False), where each inside is a file of its own. opts: the hour, weather
    and fog for P3G.export (city_options). ocean: the sea round it (the whole city has one sea of its own
    instead, city_ocean)."""
    opts = dict(opts or {}, ocean=ocean)
    area = next((a for a in areas(out, index, version) if a["key"] == key), None)
    if area is None:
        raise P3G.ExportError("that map area isn't in your copied game files")
    files = []
    for path in area["files"]:
        p = GA.file_on_disk(out, index, version, path)
        if p is not None:
            files.append((p.name, p.read_bytes()))
    if library is None:
        library = [(p.name, p.read_bytes()) for p in _library(out, index, version)]
    more = _more_library(out, index, version)
    if insides and area["place"] == "z04":
        try:
            first, _r = area_from_files(files, library, parsed)
        except P3G.ExportError:
            first = b""
        have = {n.lower() for n, _d in files}
        for p in insides_of(out, index, version, area, first):
            if p.name.lower() not in have:
                have.add(p.name.lower())
                files.append((p.name, p.read_bytes()))
    return area_from_files(files, library, parsed, more, opts)


def area_from_files(files: List[Tuple[str, bytes]], library: List[Tuple[str, bytes]],
                    parsed: Optional[dict] = None, more: Optional[Sequence] = None,
                    opts: Optional[dict] = None) -> Tuple[bytes, "P3G.Report"]:
    """A map area's .glb from its own files and the shared ones (names and bytes). Props still without a
    model after that are looked for in the more files (the interiors'), and the area is made again with
    the ones that have them. opts: the hour, weather and fog for P3G.export, if any."""
    def make(extra: List[Tuple[str, bytes]]):
        lib = P3G.Library(parsed)
        for name, data in files:
            lib.add(name, data, main=True, keep=False)
        mine = {n.lower() for n, _d in files}
        for name, data in list(library) + extra:
            if name.lower() not in mine:
                lib.add(name, data, main=False)
                mine.add(name.lower())
        return P3G.export(lib, map_mode=True, **(opts or {}))
    glb, report = make([])
    if report.unplaced and more:
        extra = _files_naming(more, report.unplaced, [n for n, _d in files] + [n for n, _d in library])
        if extra:
            glb2, report2 = make(extra)
            if sum(report2.unplaced.values()) < sum(report.unplaced.values()):
                return glb2, report2
    return glb, report


SKY_FILE = "sky.glb"                             # extracted/blender/<version>/: the city's sky
OCEAN_FILE = P3G.OCEAN_FILE                      # extracted/blender/<version>/: the city's sea
FOG_SCRIPTS = "scripts_and_data"                 # binaries/scripts_and_data/<version>/scriptc/: the scripts copied out


def city_scripts(out: Path, index: Optional[dict], version: str, bin_dir: Optional[Path] = None) -> Dict[str, Path]:
    """The game's scripts with the fog (fog.find_scripts: {"miami": graphanims.cso, "islands":
    island_envobjects.cso}): among the version's copied files, else the scripts copied out of the game into
    binaries/scripts_and_data/ (this version's folder first)."""
    import fog as FOG
    found: List[Path] = []
    for row in _rows(index, version):
        low = row[0].lower().replace("\\", "/")
        if low.endswith(("scriptc/" + FOG.MIAMI_SCRIPT, "scriptc/" + FOG.ISLAND_SCRIPT)):
            p = GA.file_on_disk(out, index, version, row[0])
            if p is not None:
                found.append(p)
    scripts = FOG.find_scripts(found)
    if bin_dir is not None:
        base = Path(bin_dir) / FOG_SCRIPTS
        others = sorted(p for p in base.iterdir() if p.is_dir() and p.name != version) if base.is_dir() else []
        for folder in [base / version] + others:
            for place, path in FOG.find_scripts([folder]).items():
                scripts.setdefault(place, path)
    return scripts


def city_fog(out: Path, index: Optional[dict], version: str, hour: float, weather: str = "clear",
             bin_dir: Optional[Path] = None) -> Tuple[Optional[dict], str]:
    """Miami's fog at an hour in a weather (fog.fog_at), from the copied miami_lod.p3d's tod object and the
    game's scripts; and "" or why there is none."""
    import fog as FOG
    script = city_scripts(out, index, version, bin_dir).get("miami")
    if script is None:
        return None, f"No fog: the game's script scriptc/{FOG.MIAMI_SCRIPT} isn't among the copied files."
    lod = next((p for p in _library(out, index, version) if p.stem.lower() == "miami_lod"), None)
    try:
        tod = FOG.tod_object(lod.read_bytes()) if lod is not None else {}
        if not tod:
            return None, "No fog: the tod object (in miami_lod.p3d) isn't among the copied files."
        found = FOG.fog_at(hour, tod, FOG.read_objects(script), weather)
    except (OSError, P3G.p3d.P3dError, FOG.FogError) as e:
        return None, f"No fog: {e}"
    if found is None:
        return None, f"No fog: {script.name} has none of the EnvironmentObjects the tod object names."
    return found, ""


def city_options(out: Path, index: Optional[dict], version: str, hour: Optional[float] = None,
                 weather: str = "clear", bin_dir: Optional[Path] = None) -> Tuple[dict, List[str]]:
    """What the city's exports are made with (P3G.export's hour, weather and fog), and notes for the person.
    Nothing for the default (no hour, clear weather): the areas come out as they always have."""
    opts: dict = {}
    notes: List[str] = []
    if weather != "clear":
        opts["weather"] = weather
    if hour is not None:
        opts.update(hour=hour, weather=weather)
        fog, why = city_fog(out, index, version, hour, weather, bin_dir)
        if fog:
            opts["fog"] = fog
        else:
            notes.append(why)
    return opts, notes


def _common(out: Path, index: Optional[dict], version: str) -> Optional[Path]:
    """The copied Common.p3d (the sky is in it): the one beside the city's files, else any."""
    beside = [p for p in _library(out, index, version) if p.name.lower() == "common.p3d"]
    if beside:
        return beside[0]
    for row in _rows(index, version):
        if row[0].lower().replace("\\", "/").rsplit("/", 1)[-1] == "common.p3d":
            p = GA.file_on_disk(out, index, version, row[0])
            if p is not None:
                return p
    return None


def _city_box(folder: Path) -> Optional[Tuple[List[float], List[float]]]:
    """The box the city's area files in folder fill (glTF's space), reading only their JSON."""
    lo, hi = [1e18] * 3, [-1e18] * 3
    for p in sorted(folder.glob("*.glb")):
        if p.name in (SKY_FILE, OCEAN_FILE):
            continue
        try:
            with open(p, "rb") as f:
                head = f.read(20)
                glb = head + f.read(struct.unpack_from("<I", head, 12)[0])
        except (OSError, struct.error):
            continue
        box = _glb_box(glb)
        if box:
            lo = [min(a, b) for a, b in zip(lo, box[0])]
            hi = [max(a, b) for a, b in zip(hi, box[1])]
    return (lo, hi) if lo[0] <= hi[0] else None


def city_sky(out: Path, index: Optional[dict], version: str, folder: Path, opts: Optional[dict] = None) -> str:
    """The sky round the city exported into folder (Common.p3d's, for the weather, posed and coloured for
    the hour if there is one), as folder/sky.glb: centred on the city and big enough to surround it, since a
    scene can't move it with the camera the way the game does (P3G.sky_export). "" when written, or why not."""
    opts = opts or {}
    common = _common(out, index, version)
    if common is None:
        return "No sky: Common.p3d isn't among the copied files."
    box = _city_box(folder)
    centre, reach = (0.0, 0.0), 0.0
    if box:
        centre = ((box[0][0] + box[1][0]) / 2, (box[0][2] + box[1][2]) / 2)
        reach = ((box[1][0] - box[0][0]) ** 2 + (box[1][2] - box[0][2]) ** 2) ** 0.5 / 2
    try:
        lib = P3G.Library()
        lib.add(common.name, common.read_bytes(), main=True)
        glb, _r = P3G.sky_export(lib, opts.get("hour"), opts.get("weather", "clear"), centre, reach, opts.get("fog"))
    except (OSError, P3G.p3d.P3dError, P3G.ExportError) as e:
        return f"No sky: {e}."
    (folder / SKY_FILE).write_bytes(glb)
    return ""


def city_ocean(out: Path, index: Optional[dict], version: str, folder: Path, opts: Optional[dict] = None) -> str:
    """The sea round the city exported into folder (P3G.sea_export), as folder/ocean.glb: one sea for every
    area, at height 0, reaching past the box the areas fill, with ocean_text's picture and the sky's colour
    for the hour and weather from the copied Common.p3d (without it, a plain sea). "" when written, or why not."""
    opts = opts or {}
    box = _city_box(folder)
    if box is None:
        return "No sea: none of the city's areas came out."
    try:
        lib = P3G.Library()
        common = _common(out, index, version)
        if common is not None:
            lib.add(common.name, common.read_bytes(), main=False)
        glb, _r = P3G.sea_export(lib, box[0], box[1], opts.get("hour"), opts.get("weather", "clear"))
    except (OSError, P3G.p3d.P3dError, P3G.ExportError) as e:
        return f"No sea: {e}."
    (folder / OCEAN_FILE).write_bytes(glb)
    return ""


def workers_wanted(use_cores: bool = True) -> int:
    """How many processes to export with: one per processor core but one (left for everything else), at
    most 8 (each holds the shared map files)."""
    return max(1, min(8, (os.cpu_count() or 2) - 1)) if use_cores else 1


def city_worker(job_file: str) -> int:
    """A worker process of the city export: the areas in job_file (JSON: library [[name, path]], areas
    [{name, files: [[name, path]], dest}]), each written to its dest; a line of JSON per area on stdout."""
    import json
    job = json.loads(Path(job_file).read_text(encoding="utf-8"))
    library = [(n, Path(p).read_bytes()) for n, p in job["library"]]
    more = job.get("more") or []
    opts = job.get("opts") or None
    parsed: dict = {}
    for area in job["areas"]:
        try:
            files = [(n, Path(p).read_bytes()) for n, p in area["files"]]
            glb, _r = area_from_files(files, library, parsed, more, opts)
            Path(area["dest"]).write_bytes(glb)
            print(json.dumps({"area": area["name"], "bytes": len(glb)}), flush=True)
        except (P3G.ExportError, OSError, P3G.p3d.P3dError) as e:
            print(json.dumps({"area": area["name"], "error": str(e)}), flush=True)
    return 0


class CityJob:
    """Every city area of one version, one .glb each, into extracted/blender/<version>/, in a background
    thread, and the sky round them (sky.glb, city_sky) and the sea (ocean.glb, city_ocean; ocean=False leaves
    it out). Areas line up when imported together. With use_cores, several worker processes share the areas
    (city_worker), one per processor core but one. With an hour, the sky is posed and coloured for it and
    every file carries that hour's fog; the weather picks the sky and the fog (clear when not given). Both
    are kept beside the files once the city is whole (city_made), so the page can tell a city at another hour
    from the one it asks for."""

    def __init__(self, bin_dir: Path):
        self.bin_dir = bin_dir
        self.status: dict = {"running": False, "version": "", "done": 0, "total": 0, "area": "", "error": "",
                             "written": 0, "bytes": 0, "folder": "", "hour": None, "weather": "clear", "notes": [],
                             "ocean": True}
        self._thread: Optional[threading.Thread] = None
        self._stop = threading.Event()
        self._lock = threading.Lock()
        self.busy: Optional[Callable[[], str]] = None      # something else that mustn't run with this (why, or "")
        self.use_cores: Callable[[], bool] = lambda: True

    @property
    def running(self) -> bool:
        return bool(self._thread and self._thread.is_alive())

    def folder(self, version: str = "") -> Path:
        base = GA.made_dir(self.bin_dir, OUT_NAME)
        return base / GA.LABELS[version] if version in GA.LABELS else base

    def start(self, version: str, index: Optional[dict], hour: Optional[float] = None,
              weather: str = "clear", ocean: bool = True) -> Optional[str]:
        """None when started, or why not. hour: 0 to 24, or None; weather: clear or rain; ocean: the sea too."""
        with self._lock:
            if self.running:
                return "Already exporting the city. Wait for it to finish or press Stop."
            why = self.busy() if self.busy is not None else ""
            if why:
                return why
            if version not in GA.LABELS:
                return "Pick a version."
            if hour is not None and not 0 <= hour <= 24:
                return "The hour is from 0 to 24."
            if weather not in P3G.WEATHERS:
                return "The weather is clear or rain."
            out = GA.out_dir(self.bin_dir)
            todo = city_areas(out, index, version)
            if not todo:
                return "None of the city's map areas are in your copied game files for that version: copy them first."
            self._stop.clear()
            self.status.update(running=True, version=version, done=0, total=len(todo), area="", error="", written=0,
                               bytes=0, folder=GA._show_path(self.folder(version)), hour=hour, weather=weather,
                               notes=[], workers=min(len(todo), workers_wanted(self.use_cores())), ocean=bool(ocean))
            self._thread = threading.Thread(target=self._run, args=(version, index, todo), daemon=True)
            self._thread.start()
            return None

    def stop(self) -> None:
        self._stop.set()

    def _run(self, version: str, index: Optional[dict], todo: List[dict]) -> None:
        out = GA.out_dir(self.bin_dir)
        dest = self.folder(version)
        try:
            dest.mkdir(parents=True, exist_ok=True)
            try:                                 # the hour and weather of the city before: gone till this one is whole
                (dest / CITY_LOOK).unlink()
            except OSError:
                pass
            opts, notes = city_options(out, index, version, self.status.get("hour"), self.status.get("weather", "clear"),
                                       self.bin_dir)
            self.status["notes"] = list(notes)
            if self.status.get("workers", 1) > 1:
                self._run_parallel(out, index, version, todo, dest, opts)
                if not self._stop.is_set():
                    self._sky(out, index, version, dest, opts)
                    self._ocean(out, index, version, dest, opts)
                    self._made(dest)
                return
            library = [(p.name, p.read_bytes()) for p in _library(out, index, version)]
            parsed: dict = {}
            for area in todo:
                if self._stop.is_set():
                    self.status["error"] = "Stopped."
                    break
                self.status["area"] = area["name"]
                try:
                    glb, _report = area_glb(out, index, version, area["key"], parsed, library, insides=False,
                                            opts=opts, ocean=False)
                except P3G.ExportError:
                    glb = b""
                if glb:
                    (dest / (area["file"] + ".glb")).write_bytes(glb)
                    self.status["written"] += 1
                    self.status["bytes"] += len(glb)
                self.status["done"] += 1
                time.sleep(0)
            if not self._stop.is_set():
                self._sky(out, index, version, dest, opts)
                self._ocean(out, index, version, dest, opts)
                self._made(dest)
        except (OSError, P3G.p3d.P3dError) as e:
            self.status["error"] = f"{type(e).__name__}: {e}"
        finally:
            self.status.update(running=False, area="")

    def _sky(self, out: Path, index: Optional[dict], version: str, dest: Path, opts: dict) -> None:
        """The sky round the city (city_sky); an earlier export's sky goes first, so a sky never stays from
        another weather or hour."""
        self.status["area"] = "the sky"
        try:
            (dest / SKY_FILE).unlink()
        except OSError:
            pass
        why = city_sky(out, index, version, dest, opts)
        if why:
            self.status["notes"].append(why)

    def _ocean(self, out: Path, index: Optional[dict], version: str, dest: Path, opts: dict) -> None:
        """The sea round the city (city_ocean), unless it is left out; an earlier export's sea goes first."""
        try:
            (dest / OCEAN_FILE).unlink()
        except OSError:
            pass
        if not self.status.get("ocean", True):
            return
        self.status["area"] = "the sea"
        why = city_ocean(out, index, version, dest, opts)
        if why:
            self.status["notes"].append(why)

    def _made(self, dest: Path) -> None:
        """The city is whole: which exporter made it (CITY_MADE), and at what hour in what weather (CITY_LOOK)."""
        import json
        (dest / CITY_MADE).write_text(_made_by(), encoding="utf-8")
        (dest / CITY_LOOK).write_text(json.dumps({"hour": self.status.get("hour"),
                                                  "weather": self.status.get("weather") or "clear"}), encoding="utf-8")

    def _run_parallel(self, out: Path, index: Optional[dict], version: str, todo: List[dict], dest: Path,
                      opts: Optional[dict] = None) -> None:
        """The areas shared out between worker processes (python blender_export.py --city-worker job.json)."""
        import json
        n = self.status["workers"]
        library = [[p.name, str(p)] for p in _library(out, index, version)]
        more = [[p.name, str(p)] for p in _more_library(out, index, version)]
        jobs: List[List[dict]] = [[] for _ in range(n)]
        for i, area in enumerate(sorted(todo, key=lambda a: -len(a["files"]))):     # big ones first, spread out
            files = []
            for path in area["files"]:
                p = GA.file_on_disk(out, index, version, path)
                if p is not None:
                    files.append([p.name, str(p)])
            jobs[i % n].append({"name": area["name"], "files": files, "dest": str(dest / (area["file"] + ".glb"))})
        work = GA.made_dir(self.bin_dir, OUT_NAME) / "_scripts"
        work.mkdir(parents=True, exist_ok=True)
        flags = getattr(subprocess, "CREATE_NO_WINDOW", 0) if os.name == "nt" else 0
        procs = []
        for i, areas_ in enumerate(jobs):
            if not areas_:
                continue
            job = work / f"city_job_{i}.json"
            job.write_text(json.dumps({"library": library, "more": more, "areas": areas_, "opts": opts or {}}),
                           encoding="utf-8")
            procs.append(subprocess.Popen([sys.executable, str(Path(__file__).resolve()), "--city-worker", str(job)],
                                          stdout=subprocess.PIPE, stderr=subprocess.DEVNULL, stdin=subprocess.DEVNULL,
                                          text=True, creationflags=flags))
        lock = threading.Lock()

        def follow(proc: subprocess.Popen) -> None:
            for line in proc.stdout:
                try:
                    got = json.loads(line)
                except ValueError:
                    continue
                with lock:
                    self.status["area"] = got.get("area", "")
                    self.status["done"] += 1
                    if got.get("bytes"):
                        self.status["written"] += 1
                        self.status["bytes"] += got["bytes"]
        readers = [threading.Thread(target=follow, args=(p,), daemon=True) for p in procs]
        for t in readers:
            t.start()
        while any(p.poll() is None for p in procs):
            if self._stop.is_set():
                for p in procs:
                    p.kill()
                self.status["error"] = "Stopped."
                break
            time.sleep(0.2)
        for t in readers:
            t.join(5)
        for job in work.glob("city_job_*.json"):
            try:
                job.unlink()
            except OSError:
                pass


def main(argv=None) -> int:
    import argparse
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--city-worker", metavar="JOB", help="(used by the portal) export the areas in a job file")
    a = ap.parse_args(argv)
    if a.city_worker:
        return city_worker(a.city_worker)
    ap.print_help()
    return 0



# --------------------------------------------------------------------------- the person's own Blender

BLENDER_PATH_FILE = "blender_path.txt"           # extracted/blender/: where blender.exe is, if it isn't found
CITY_MADE = "made_by.txt"                        # extracted/blender/<version>/: which exporter made the city
CITY_LOOK = "made_with.json"                     # extracted/blender/<version>/: the hour and weather it is at


def city_current(folder: Path) -> bool:
    """Whether the city in folder was exported by this version of the exporter (not one from before props
    came in whole and at full detail)."""
    try:
        made = (folder / CITY_MADE).read_text(encoding="utf-8").split()
        return int(made[0]) >= P3G.EXPORT_VERSION and (made[1:2] == ["xbox"]) == (texture_look() == "xbox")
    except (OSError, ValueError, IndexError):
        return False


def city_made(folder: Path) -> Optional[dict]:
    """The hour (None: the sky as stored) and the weather the city in folder was exported at, {"hour", "weather"};
    None when that isn't known: exported before the portal kept it, or stopped part-way (a mix of the two)."""
    import json
    try:
        made = json.loads((folder / CITY_LOOK).read_text(encoding="utf-8"))
        hour, weather = made.get("hour"), made.get("weather")
    except (OSError, ValueError, AttributeError):
        return None
    an_hour = hour is None or isinstance(hour, (int, float)) and not isinstance(hour, bool) and 0 <= hour <= 24
    return {"hour": hour, "weather": weather} if an_hour and weather in P3G.WEATHERS else None


def texture_look() -> str:
    """"xbox" when PC textures are exported with the Xbox's tones, else ""."""
    return "xbox" if os.environ.get(P3G.LOOK_ENV) == "xbox" else ""


def _made_by() -> str:
    return str(P3G.EXPORT_VERSION) + (" xbox" if texture_look() else "")
OPENED = "Opened"                                # extracted/blender/<version>/Opened/: single files and areas

OPEN_SCRIPT = r"""
# Made by the Scarface decomp portal: import the game's scenes, then save them as a .blend beside them.
#
# The import runs once Blender's window is up, inside that window. Run straight from --python (and after
# reloading the start-up file), Blender's own importer had no window to work in: a map came in, but anything
# with a skeleton stopped half-way and left only the importer's helper ball (an "Icosphere") in the scene.
import bpy, json, re, struct, traceback
FILES = %(files)r
SAVE = %(save)r
FPS = %(fps)r
STATE = {"at": 0, "problems": [], "undo": None}
NOTE = (SAVE or (FILES[0] if FILES else "scene")) + ".import-error.txt"


def bring_one(f, problems):
    try:
        # Bones drawn towards the next joint, not as spikes pointing every way; and no helper ball for
        # them (Blender 4.2 and later). Older Blenders don't know every option: fewer are tried in turn.
        for options in ({"disable_bone_shape": True, "bone_heuristic": "TEMPERANCE"},
                        {"bone_heuristic": "TEMPERANCE"}, {}):
            try:
                bpy.ops.import_scene.gltf(filepath=f, **options)
                break
            except TypeError:
                continue
    except Exception:  # one area that won't come in shouldn't stop the rest
        problems.append(f + "\n" + traceback.format_exc())


def same_pictures():
    # Every area brings its own copy of the textures it shares with the others (the road, the palms):
    # keep one of each, so the city takes a fraction of the memory and saves quickly.
    seen = {}
    for img in list(bpy.data.images):
        try:
            pf = img.packed_file
            key = (re.sub(r"\.\d{3}$", "", img.name), pf.size if pf else 0)
            first = seen.get(key)
            if first is None:
                seen[key] = img
            elif key[1]:
                img.user_remap(first)
                bpy.data.images.remove(img)
        except Exception:
            pass


def say(text):
    print(text or "")
    try:
        for win in bpy.context.window_manager.windows:
            if text:
                win.workspace.status_text_set(text)
            else:
                win.workspace.status_text_set(None)
    except Exception:
        pass


def start():
    for o in list(bpy.data.objects):            # the start-up cube, light and camera
        bpy.data.objects.remove(o, do_unlink=True)
    # FPS is 30, or 60 or 120 when asked: Blender fills in between the game's poses, so they play
    # smoother at the same speed.
    try:                                         # the game's animations are made for 30 frames a second: set
        bpy.context.scene.render.fps = FPS       # before they come in, or Blender lays their keys out for its
        bpy.context.scene.render.fps_base = 1.0  # own 24 and they play slow and jerky
    except Exception:
        pass
    try:                                         # Blender copies the whole scene for Undo after every import:
        STATE["undo"] = bpy.context.preferences.edit.use_global_undo      # with a city, most of the wait
        bpy.context.preferences.edit.use_global_undo = False
    except Exception:
        pass


def fog_of(path):
    # The fog an export made with an hour carries in its scene's extras (portal/tools/fog.py), read from the
    # .glb itself: its JSON part, after the 12-byte header and the part's own 8.
    try:
        with open(path, "rb") as f:
            head = f.read(20)
            if head[:4] != b"glTF":
                return None
            text = f.read(struct.unpack_from("<I", head, 12)[0])
        if b'"fog"' not in text:
            return None
        doc = json.loads(text)
        scene = (doc.get("scenes") or [{}])[doc.get("scene", 0)]
        return (scene.get("extras") or {}).get("fog")
    except Exception:
        return None


def linear(c):
    # the game's colours are screen (sRGB) colours; Blender's colour settings are linear
    return c / 12.92 if c <= 0.04045 else ((c + 0.055) / 1.055) ** 2.4


def show_fog(scene, fog):
    # The game's fog is plain linear fog by distance from the camera, from the start to the end distance, in
    # the fog colour: here the world's mist (from the start, over the distance to the end, fading in a straight
    # line; the Mist pass shows it), and the world's colour is the fog colour.
    if not fog or not fog.get("enabled"):
        return False
    world = scene.world
    if world is None:
        world = scene.world = bpy.data.worlds.new("Scarface")
    start, end = float(fog.get("start", 0.0)), float(fog.get("end", 0.0))
    mist = world.mist_settings
    mist.start = start
    mist.depth = max(0.0, end - start)
    mist.falloff = "LINEAR"
    try:
        mist.use_mist = True                     # Blenders that still have the switch
    except Exception:
        pass
    colour = [linear(c) for c in fog.get("color", (0.0, 0.0, 0.0))]
    world.color = colour
    try:
        if world.node_tree is None:
            world.use_nodes = True
        for node in world.node_tree.nodes:
            if node.type == "BACKGROUND":
                node.inputs[0].default_value = colour + [1.0]
    except Exception:
        pass
    for layer in scene.view_layers:
        try:
            layer.use_pass_mist = True
        except Exception:
            pass
    scene["scarface_fog"] = json.dumps(fog)
    return True


def own(thing, key):
    # A setting the export left in a glTF "extras": Blender's glTF importer keeps them as custom properties
    # (of the object for a node's, of the material for a material's). None when it isn't there.
    try:
        return thing.get(key)
    except Exception:
        return None


def output_of(tree):
    return next((n for n in tree.nodes if n.type == "OUTPUT_MATERIAL"), None)


def picture_of(tree):
    return next((n for n in tree.nodes if n.type == "TEX_IMAGE"), None)


def add_light(mat):
    # The game adds these surfaces' light to what is behind them (BLMD 2). The export made the picture ready for
    # ordinary blending (its brightness as alpha, its colour divided by that), so colour x alpha is the light:
    # here that light as an Emission shader, added to a Transparent BSDF that lets everything behind through.
    tree = mat.node_tree
    out = output_of(tree)
    if out is None:
        return False
    nodes, links = tree.nodes, tree.links
    pic = picture_of(tree)
    light = nodes.new("ShaderNodeEmission")
    if pic is not None:
        times = nodes.new("ShaderNodeVectorMath")
        times.operation = "MULTIPLY"
        links.new(pic.outputs["Color"], times.inputs[0])
        links.new(pic.outputs["Alpha"], times.inputs[1])
        links.new(times.outputs[0], light.inputs["Color"])
    else:                                        # no picture: nothing to add
        light.inputs["Color"].default_value = (0.0, 0.0, 0.0, 1.0)
    through = nodes.new("ShaderNodeBsdfTransparent")
    both = nodes.new("ShaderNodeAddShader")
    links.new(through.outputs[0], both.inputs[0])
    links.new(light.outputs[0], both.inputs[1])
    links.new(both.outputs[0], out.inputs["Surface"])
    return True


def darken(mat):
    # The game takes these surfaces' colour away from what is behind them (BLMD 3 subtracts). The export made the
    # picture black with an alpha of its brightness (the largest of its red, green and blue): here a Transparent
    # BSDF in the colour of 1 minus that brightness, which multiplies what is behind by it, close to subtracting
    # the brightness where what is behind is bright.
    tree = mat.node_tree
    out = output_of(tree)
    if out is None:
        return False
    nodes, links = tree.nodes, tree.links
    pic = picture_of(tree)
    through = nodes.new("ShaderNodeBsdfTransparent")
    if pic is not None:
        left = nodes.new("ShaderNodeMath")
        left.operation = "SUBTRACT"
        left.inputs[0].default_value = 1.0
        links.new(pic.outputs["Alpha"], left.inputs[1])
        links.new(left.outputs[0], through.inputs["Color"])
    links.new(through.outputs[0], out.inputs["Surface"])
    return True


def see_through(mat, depth):
    # Eevee: blended, drawn after the solid surfaces (Blender 4.2 and later call it the render method, older
    # ones the blend mode); blended surfaces don't write depth. For the ones the game draws without writing
    # depth (decals, glows, lit windows, shadow decals, the sky): every layer shown, and no shadow cast.
    for name, value in (("surface_render_method", "BLENDED"), ("blend_method", "BLEND")):
        try:
            setattr(mat, name, value)
        except Exception:
            pass
    if depth:
        return
    for name in ("use_transparency_overlap", "show_transparent_back"):
        try:
            setattr(mat, name, True)
        except Exception:
            pass
    try:
        mat.shadow_method = "NONE"
    except Exception:
        pass
    out = output_of(mat.node_tree) if getattr(mat, "node_tree", None) else None
    if out is None or not out.inputs["Surface"].links:
        return
    nodes, links = mat.node_tree.nodes, mat.node_tree.links
    surface = out.inputs["Surface"].links[0].from_socket
    path = nodes.new("ShaderNodeLightPath")      # what the light finds on its way: nothing (Cycles' shadows)
    clear = nodes.new("ShaderNodeBsdfTransparent")
    pick = nodes.new("ShaderNodeMixShader")
    links.new(path.outputs["Is Shadow Ray"], pick.inputs[0])
    links.new(surface, pick.inputs[1])
    links.new(clear.outputs[0], pick.inputs[2])
    links.new(pick.outputs[0], out.inputs["Surface"])


def below(o):
    try:
        return list(o.children_recursive)
    except Exception:
        out = []
        for c in getattr(o, "children", ()):
            out += [c] + below(c)
        return out


def gather(scene, name, objects, shown=True):
    # The objects in a collection of their own, which the Outliner's tick box shows or hides.
    if not objects:
        return None
    coll = bpy.data.collections.new(name)
    scene.collection.children.link(coll)
    for o in objects:
        for c in list(o.users_collection):
            c.objects.unlink(o)
        coll.objects.link(o)
    if not shown:
        try:
            layer = next(lc for lc in bpy.context.view_layer.layer_collection.children if lc.collection == coll)
            layer.exclude = True
        except Exception:
            coll.hide_viewport = coll.hide_render = True
    return coll


def far_away(o):
    # A world geometry the game draws only when the camera is farther than its near distance (a stand-in for
    # something close by): the export marks it "hidden" and gives its "drawDistance".
    try:
        return bool(own(o, "hidden")) and float((own(o, "drawDistance") or {}).get("near") or 0) > 0
    except Exception:
        return False


def game_looks(scene):
    # What the exports leave in extras (docs/FORMATS.md, "Exporting to Blender"): how the game puts each
    # see-through surface over what is behind it ("blend"), and which it draws without writing depth
    # ("depthWrite"); then the shadow decals, the low-detail hull (switched off when the export says it is
    # "hidden": it would cover the detailed areas), the far-away stand-ins (always "hidden", so switched off)
    # and the sea, each in a collection of its own.
    for mat in list(bpy.data.materials):
        blend, depth = own(mat, "blend"), own(mat, "depthWrite")
        depth = True if depth is None else bool(depth)
        if blend is None or not getattr(mat, "node_tree", None):
            continue                             # solid: as the importer made it
        try:
            if blend == "add":
                add_light(mat)
            elif blend == "darken":
                darken(mat)
            if blend in ("add", "darken") or not depth:
                see_through(mat, depth)
        except Exception:
            traceback.print_exc()
    groups = {"Shadow decals": [], "Low-detail hull": [], "Far-away stand-ins": [], "Sea": []}
    hidden = False
    for o in list(scene.objects):
        if own(o, "shadowDecal"):
            groups["Shadow decals"].append(o)
        elif own(o, "lowDetailHull") and not far_away(o):
            groups["Low-detail hull"] += [o] + below(o)
            hidden = hidden or bool(own(o, "hidden"))
        elif own(o, "hidden"):
            groups["Far-away stand-ins"] += [o] + below(o)
        elif own(o, "ocean"):
            groups["Sea"].append(o)
    off = {"Low-detail hull": hidden, "Far-away stand-ins": True}
    for name, objects in groups.items():
        try:
            gather(scene, name, objects, shown=not off.get(name))
        except Exception:
            traceback.print_exc()


def finish(problems):
    try:
        if STATE.get("undo") is not None:
            bpy.context.preferences.edit.use_global_undo = STATE["undo"]
    except Exception:
        pass
    scene = bpy.context.scene
    tidy(scene)
    try:                                         # see-through surfaces as the game blends them; the groups
        game_looks(scene)
    except Exception:
        traceback.print_exc()
    try:                                         # the first file that has fog (each export with an hour has)
        show_fog(scene, next((f for f in (fog_of(p) for p in FILES) if f), None))
    except Exception:
        traceback.print_exc()
    ends = [a.frame_range[1] for a in bpy.data.actions]
    if ends:
        scene.frame_start, scene.frame_end = 0, int(max(ends))
    cams = [o for o in scene.objects if o.type == "CAMERA"]
    if cams and scene.camera is None:
        scene.camera = cams[0]
    for screen in bpy.data.screens:
        for area in screen.areas:
            for space in area.spaces:
                if space.type == "VIEW_3D":
                    space.clip_start, space.clip_end = 0.05, 50000.0
    try:
        bpy.ops.view3d.view_all()
    except Exception:
        pass
    shown = [o for o in scene.objects if o.type in ("MESH", "ARMATURE", "CAMERA", "EMPTY")]
    if problems or not shown:
        try:
            with open(NOTE, "w", encoding="utf-8") as out:
                out.write("Blender " + bpy.app.version_string + " couldn't bring this in.\n\n" + "\n".join(problems))
        except OSError:
            pass
    if SAVE and shown:                           # never save a scene with nothing of the game in it
        say("Scarface: saving the scene, so next time it opens at once...")
        try:
            bpy.ops.wm.save_as_mainfile(filepath=SAVE)
        except Exception as e:
            print("Couldn't save", SAVE, e)
    say("")


def bring_in():
    # all at once: when Blender has no window (run with --background)
    problems = []
    start()
    for f in FILES:
        bring_one(f, problems)
    if len(FILES) > 1:
        same_pictures()
    finish(problems)


def tidy(scene):
    # Stand the people up, and show one copy of each model.
    # Blender puts the first animation it reads on each skeleton. A character comes with the whole library
    # (hundreds, a chicken's first), so the model it landed on lay twisted on the floor: with a library that
    # size, every skeleton is put back in its rest pose and the animations wait in the Action list.
    # Models come at two levels of detail (..._high and ..._low, the far-away stand-in): the low one is
    # hidden, not removed, so the scene shows one of each.
    library = len(bpy.data.actions) > 20 and not any(a.name.startswith("Cutscene ") for a in bpy.data.actions)
    if library:
        for a in bpy.data.actions:               # kept in the saved .blend though nothing is playing them
            a.use_fake_user = True
    for o in scene.objects:
        if o.type == "ARMATURE":
            try:                                 # thin sticks: the skeleton doesn't cover the model
                o.data.display_type = "STICK"
            except Exception:
                pass
        if o.type == "ARMATURE" and library:
            if o.animation_data is not None:
                o.animation_data.action = None
            for b in o.pose.bones:
                b.location = (0.0, 0.0, 0.0)
                b.rotation_quaternion = (1.0, 0.0, 0.0, 0.0)
                b.rotation_euler = (0.0, 0.0, 0.0)
                b.scale = (1.0, 1.0, 1.0)
    names = {o.name.lower() for o in scene.objects}
    for o in scene.objects:
        low = o.name.lower()
        for a, b in (("_low", "_high"), ("low", "high"), ("_lod1", "_lod0"), ("_l", "_h")):
            i = low.rfind(a)
            if i > 0 and (a.startswith("_") and a not in ("_l",) or low.endswith(a) or low.endswith(a + "shape")):
                twin = low[:i] + b + low[i + len(a):]
                if twin in names and twin != low:
                    try:
                        o.hide_set(True)
                    except Exception:
                        o.hide_viewport = True
                    break
    if library:
        try:
            scene.frame_set(0)
        except Exception:
            pass


def in_the_window(what, *args):
    wm = bpy.context.window_manager
    win = bpy.context.window or (wm.windows[0] if wm and wm.windows else None)
    if win is None:
        return what(*args)
    where = {"window": win}
    area = next((a for a in win.screen.areas if a.type == "VIEW_3D"), None)
    if area is not None:
        where["area"] = area
        region = next((r for r in area.regions if r.type == "WINDOW"), None)
        if region is not None:
            where["region"] = region
    with bpy.context.temp_override(**where):
        return what(*args)


def later():
    # One file each time Blender calls back, so its window keeps answering and says how far along it is
    # (a whole city in one go left it "Not Responding" for many minutes).
    try:
        i = STATE["at"]
        if i == 0:
            in_the_window(start)
        if i < len(FILES):
            if len(FILES) > 1:
                say("Scarface: bringing in area {} of {}...".format(i + 1, len(FILES)))
            in_the_window(bring_one, FILES[i], STATE["problems"])
            if len(FILES) > 1:
                same_pictures()
            STATE["at"] = i + 1
            return 0.01
        in_the_window(finish, STATE["problems"])
    except Exception:
        traceback.print_exc()
    return None                                  # done


if bpy.app.background:
    bring_in()
else:
    bpy.app.timers.register(later, first_interval=0.5)
"""


def open_blend(exe: Path, blend: Path) -> None:
    """Start Blender (not waiting for it) on a scene saved earlier."""
    flags = 0
    if os.name == "nt":
        flags = getattr(subprocess, "DETACHED_PROCESS", 0) | getattr(subprocess, "CREATE_NEW_PROCESS_GROUP", 0)
    subprocess.Popen([str(exe), str(blend)], cwd=str(blend.parent), stdin=subprocess.DEVNULL,
                     stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, close_fds=True, creationflags=flags)


def saved_scene(blend: Path, glbs: Sequence[Path]) -> bool:
    """Whether blend was saved from these very files (it is newer than each of them)."""
    try:
        made = blend.stat().st_mtime
        return blend.stat().st_size > 0 and all(g.stat().st_mtime <= made for g in glbs)
    except OSError:
        return False


def _versioned(p: Path) -> tuple:
    digits = "".join(ch if ch.isdigit() else " " for ch in p.parent.name).split()
    return tuple(int(d) for d in digits)


def _from_registry() -> List[Path]:
    """Where Windows opens .blend files with (the Blender installer sets this)."""
    if os.name != "nt":
        return []
    try:
        import winreg
    except ImportError:
        return []
    found = []
    for root, key in ((winreg.HKEY_CLASSES_ROOT, r"blendfile\shell\open\command"),
                      (winreg.HKEY_CURRENT_USER, r"Software\Classes\blendfile\shell\open\command")):
        try:
            with winreg.OpenKey(root, key) as k:
                cmd = str(winreg.QueryValue(k, None) or "")
        except OSError:
            continue
        exe = cmd.split('"')[1] if cmd.startswith('"') else cmd.split(" ")[0]
        if exe:
            found.append(Path(exe))
    return found


def find_blender(bin_dir: Path) -> Optional[Path]:
    """The person's Blender: the one they told the portal about, $BLENDER, on the PATH, the one .blend
    files open with, or the newest in the usual places."""
    tries: List[Path] = []
    try:
        told = (GA.made_dir(bin_dir, OUT_NAME) / BLENDER_PATH_FILE).read_text(encoding="utf-8").strip().strip('"')
        if told:
            tries.append(Path(told))
    except OSError:
        pass
    if os.environ.get("BLENDER"):
        tries.append(Path(os.environ["BLENDER"]))
    which = shutil.which("blender")
    if which:
        tries.append(Path(which))
    tries += _from_registry()
    if os.name == "nt":
        for base in {os.environ.get("ProgramFiles", r"C:\Program Files"), os.environ.get("ProgramW6432", r"C:\Program Files")}:
            tries += sorted(Path(base, "Blender Foundation").glob("Blender*/blender.exe"), key=_versioned, reverse=True)
        for base in (os.environ.get("ProgramFiles(x86)", r"C:\Program Files (x86)"), os.environ.get("ProgramFiles", "")):
            if base:
                tries.append(Path(base, "Steam", "steamapps", "common", "Blender", "blender.exe"))
        local = os.environ.get("LOCALAPPDATA")
        if local:
            tries.append(Path(local, "Microsoft", "WindowsApps", "blender.exe"))
    elif sys.platform == "darwin":
        tries.append(Path("/Applications/Blender.app/Contents/MacOS/Blender"))
    else:
        tries += [Path("/snap/bin/blender"), Path("/usr/bin/blender"), Path("/usr/local/bin/blender")]
    for t in tries:
        try:
            if t.is_file():
                return t.with_name("blender.exe") if t.name.lower() == "blender-launcher.exe" and \
                    t.with_name("blender.exe").is_file() else t
        except OSError:
            continue
    return None


def remember_blender(bin_dir: Path, exe: str) -> Optional[str]:
    """Keep where the person's Blender is. None when kept, or why not."""
    exe = exe.strip().strip('"')
    p = Path(exe)
    if p.is_dir():
        p = next((p / n for n in ("blender.exe", "blender", "Blender") if (p / n).is_file()), p / "blender.exe")
    if not p.is_file() or "blender" not in p.name.lower():
        return "That isn't Blender: pick blender.exe in the folder Blender is installed in."
    GA.made_dir(bin_dir, OUT_NAME).mkdir(parents=True, exist_ok=True)
    (GA.made_dir(bin_dir, OUT_NAME) / BLENDER_PATH_FILE).write_text(str(p), encoding="utf-8")
    return None


FRAME_RATES = (30, 60, 120)


def open_in_blender(exe: Path, files: List[Path], save: Optional[Path], work: Path, fps: int = 30) -> None:
    """Start Blender (not waiting for it) with the .glb files imported into a new scene, saved as save."""
    work.mkdir(parents=True, exist_ok=True)
    script = work / "open_in_blender.py"
    script.write_text(OPEN_SCRIPT % {"files": [str(f.resolve()) for f in files],
                                     "save": str(save.resolve()) if save else None,
                                     "fps": fps if fps in FRAME_RATES else 30}, encoding="utf-8")
    flags = 0
    if os.name == "nt":
        flags = getattr(subprocess, "DETACHED_PROCESS", 0) | getattr(subprocess, "CREATE_NEW_PROCESS_GROUP", 0)
    subprocess.Popen([str(exe), "--python", str(script)], cwd=str(work), stdin=subprocess.DEVNULL,
                     stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, close_fds=True, creationflags=flags)


if __name__ == "__main__":
    raise SystemExit(main())
