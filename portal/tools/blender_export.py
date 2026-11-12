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
    CityJob                             every city area, in the background
    inspect(data)                       what a .p3d holds, in words, and whether Blender can show it
    find_blender(bin_dir) / open_in_blender(exe, files, save)
                                        start the person's own Blender with .glb files imported, saving
                                        a .blend beside them (a .glb double-clicked makes Blender try to
                                        open it as a .blend: "not a valid Blender file")

Your own copies, on your own computer; standard library only.
"""

from __future__ import annotations

import os
import shutil
import subprocess
import sys
import threading
import time
from pathlib import Path
from typing import Callable, Dict, List, Optional, Tuple

import game_assets as GA
import p3d_gltf as P3G

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
    order = {f.split("/")[1]: i for i, f in enumerate(AREA_FOLDERS)}
    return sorted(found.values(), key=lambda a: (order[a["place"]], a["name"].lower()))


def _city_folder_path(index: Optional[dict], version: str) -> Optional[str]:
    """A path in the city's folder (for finding the shared files beside it)."""
    return next((r[0] for r in _rows(index, version) if CITY in r[0].lower() and r[4]), None)


def _library(out: Path, index: Optional[dict], version: str) -> List[Path]:
    anchor = _city_folder_path(index, version)
    return GA.files_beside(out, index, version, anchor, P3G.MAP_LIBRARY) if anchor else []


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


def model_glb(out: Path, index: Optional[dict], version: str, game_path: str, data: bytes) -> Tuple[bytes, "P3G.Report"]:
    """One copied .p3d file as a .glb. A map area also gets its region's and the city's shared files; a
    character gets the game's animations (art/animations), each as an action."""
    lib = P3G.Library()
    src = lib.add(Path(game_path).name, data, main=True)
    is_map = bool(P3G._world_geo(lib, src) or P3G.instance_objects(src))
    anims = []
    if is_map:
        for f in GA.files_beside(out, index, version, game_path, P3G.MAP_LIBRARY):
            try:
                lib.add(f.name, f.read_bytes(), main=False)
            except (OSError, P3G.p3d.P3dError):
                pass
    elif _moves_only(src):
        actor = stand_in(out, index, version)          # the people's animations, on Tony
        if actor is not None:
            try:
                lib.add(actor.name, actor.read_bytes(), main=True)
            except (OSError, P3G.p3d.P3dError):
                pass
    elif any(c.id == P3G.SKIN for c in src.chunks):
        for f in animations(out, index, version):
            try:
                extra = lib.add(f.name, f.read_bytes(), main=False)
            except (OSError, P3G.p3d.P3dError):
                continue
            anims += [P3G.Ref(extra, c) for c in extra.chunks if c.id == P3G.ANIMATION]
    return P3G.export(lib, map_mode=is_map, anims=anims)


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
    return {v: sum(1 for a in areas(out, index, v) if a["place"] == "z04")
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
             parsed: Optional[dict] = None, library: Optional[List[Tuple[str, bytes]]] = None) -> Tuple[bytes, "P3G.Report"]:
    """One map area (all its files) as a .glb, with what it needs from the shared files."""
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
    return area_from_files(files, library, parsed)


def area_from_files(files: List[Tuple[str, bytes]], library: List[Tuple[str, bytes]],
                    parsed: Optional[dict] = None) -> Tuple[bytes, "P3G.Report"]:
    """A map area's .glb from its own files and the shared ones (names and bytes)."""
    lib = P3G.Library(parsed)
    for name, data in files:
        lib.add(name, data, main=True, keep=False)
    mine = {n.lower() for n, _d in files}
    for name, data in library:
        if name.lower() not in mine:
            lib.add(name, data, main=False)
    return P3G.export(lib, map_mode=True)


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
    parsed: dict = {}
    for area in job["areas"]:
        try:
            files = [(n, Path(p).read_bytes()) for n, p in area["files"]]
            glb, _r = area_from_files(files, library, parsed)
            Path(area["dest"]).write_bytes(glb)
            print(json.dumps({"area": area["name"], "bytes": len(glb)}), flush=True)
        except (P3G.ExportError, OSError, P3G.p3d.P3dError) as e:
            print(json.dumps({"area": area["name"], "error": str(e)}), flush=True)
    return 0


class CityJob:
    """Every city area of one version, one .glb each, into extracted/blender/<version>/, in a background
    thread. Areas line up when imported together. With use_cores, several worker processes share the
    areas (city_worker), one per processor core but one."""

    def __init__(self, bin_dir: Path):
        self.bin_dir = bin_dir
        self.status: dict = {"running": False, "version": "", "done": 0, "total": 0, "area": "", "error": "",
                             "written": 0, "bytes": 0, "folder": ""}
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

    def start(self, version: str, index: Optional[dict]) -> Optional[str]:
        """None when started, or why not."""
        with self._lock:
            if self.running:
                return "Already exporting the city. Wait for it to finish or press Stop."
            why = self.busy() if self.busy is not None else ""
            if why:
                return why
            if version not in GA.LABELS:
                return "Pick a version."
            out = GA.out_dir(self.bin_dir)
            todo = [a for a in areas(out, index, version) if a["place"] == "z04"]
            if not todo:
                return "None of the city's map areas are in your copied game files for that version: copy them first."
            self._stop.clear()
            self.status.update(running=True, version=version, done=0, total=len(todo), area="", error="", written=0,
                               bytes=0, folder=GA._show_path(self.folder(version)),
                               workers=min(len(todo), workers_wanted(self.use_cores())))
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
            if self.status.get("workers", 1) > 1:
                self._run_parallel(out, index, version, todo, dest)
                if not self._stop.is_set():
                    (dest / CITY_MADE).write_text(_made_by(), encoding="utf-8")
                return
            library = [(p.name, p.read_bytes()) for p in _library(out, index, version)]
            parsed: dict = {}
            for area in todo:
                if self._stop.is_set():
                    self.status["error"] = "Stopped."
                    break
                self.status["area"] = area["name"]
                try:
                    glb, _report = area_glb(out, index, version, area["key"], parsed, library)
                except P3G.ExportError:
                    glb = b""
                if glb:
                    (dest / (area["name"] + ".glb")).write_bytes(glb)
                    self.status["written"] += 1
                    self.status["bytes"] += len(glb)
                self.status["done"] += 1
                time.sleep(0)
            if not self._stop.is_set():
                (dest / CITY_MADE).write_text(_made_by(), encoding="utf-8")
        except (OSError, P3G.p3d.P3dError) as e:
            self.status["error"] = f"{type(e).__name__}: {e}"
        finally:
            self.status.update(running=False, area="")

    def _run_parallel(self, out: Path, index: Optional[dict], version: str, todo: List[dict], dest: Path) -> None:
        """The areas shared out between worker processes (python blender_export.py --city-worker job.json)."""
        import json
        n = self.status["workers"]
        library = [[p.name, str(p)] for p in _library(out, index, version)]
        jobs: List[List[dict]] = [[] for _ in range(n)]
        for i, area in enumerate(sorted(todo, key=lambda a: -len(a["files"]))):     # big ones first, spread out
            files = []
            for path in area["files"]:
                p = GA.file_on_disk(out, index, version, path)
                if p is not None:
                    files.append([p.name, str(p)])
            jobs[i % n].append({"name": area["name"], "files": files, "dest": str(dest / (area["name"] + ".glb"))})
        work = GA.made_dir(self.bin_dir, OUT_NAME) / "_scripts"
        work.mkdir(parents=True, exist_ok=True)
        flags = getattr(subprocess, "CREATE_NO_WINDOW", 0) if os.name == "nt" else 0
        procs = []
        for i, areas_ in enumerate(jobs):
            if not areas_:
                continue
            job = work / f"city_job_{i}.json"
            job.write_text(json.dumps({"library": library, "areas": areas_}), encoding="utf-8")
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


def city_current(folder: Path) -> bool:
    """Whether the city in folder was exported by this version of the exporter (not one from before props
    came in whole and at full detail)."""
    try:
        made = (folder / CITY_MADE).read_text(encoding="utf-8").split()
        return int(made[0]) >= P3G.EXPORT_VERSION and (made[1:2] == ["xbox"]) == (texture_look() == "xbox")
    except (OSError, ValueError, IndexError):
        return False


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
import bpy, traceback
FILES = %(files)r
SAVE = %(save)r
NOTE = (SAVE or (FILES[0] if FILES else "scene")) + ".import-error.txt"


def bring_in():
    for o in list(bpy.data.objects):            # the start-up cube, light and camera
        bpy.data.objects.remove(o, do_unlink=True)
    problems = []
    for f in FILES:
        try:
            try:                                 # no helper ball for the bones (Blender 4.2 and later)
                bpy.ops.import_scene.gltf(filepath=f, disable_bone_shape=True)
            except TypeError:
                bpy.ops.import_scene.gltf(filepath=f)
        except Exception:  # one area that won't come in shouldn't stop the rest
            problems.append(f + "\n" + traceback.format_exc())
    scene = bpy.context.scene
    tidy(scene)
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
        try:
            bpy.ops.wm.save_as_mainfile(filepath=SAVE)
        except Exception as e:
            print("Couldn't save", SAVE, e)


def tidy(scene):
    # Stand the people up, and show one copy of each model.
    # Blender puts the first animation it reads on each skeleton. A character comes with the whole library
    # (hundreds, a chicken's first), so the model it landed on lay twisted on the floor: with a library that
    # size, every skeleton is put back in its rest pose and the animations wait in the Action list.
    # Models come at two levels of detail (..._high and ..._low, the far-away stand-in): the low one is
    # hidden, not removed, so the scene shows one of each.
    library = len(bpy.data.actions) > 20
    if library:
        for a in bpy.data.actions:               # kept in the saved .blend though nothing is playing them
            a.use_fake_user = True
    for o in scene.objects:
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


def in_the_window():
    wm = bpy.context.window_manager
    win = bpy.context.window or (wm.windows[0] if wm and wm.windows else None)
    if win is None:
        return bring_in()
    where = {"window": win}
    area = next((a for a in win.screen.areas if a.type == "VIEW_3D"), None)
    if area is not None:
        where["area"] = area
        region = next((r for r in area.regions if r.type == "WINDOW"), None)
        if region is not None:
            where["region"] = region
    with bpy.context.temp_override(**where):
        bring_in()


def later():
    try:
        in_the_window()
    except Exception:
        traceback.print_exc()
    return None                                  # once


if bpy.app.background:
    bring_in()
else:
    bpy.app.timers.register(later, first_interval=0.5)
"""


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


def open_in_blender(exe: Path, files: List[Path], save: Optional[Path], work: Path) -> None:
    """Start Blender (not waiting for it) with the .glb files imported into a new scene, saved as save."""
    work.mkdir(parents=True, exist_ok=True)
    script = work / "open_in_blender.py"
    script.write_text(OPEN_SCRIPT % {"files": [str(f.resolve()) for f in files],
                                     "save": str(save.resolve()) if save else None}, encoding="utf-8")
    flags = 0
    if os.name == "nt":
        flags = getattr(subprocess, "DETACHED_PROCESS", 0) | getattr(subprocess, "CREATE_NEW_PROCESS_GROUP", 0)
    subprocess.Popen([str(exe), "--python", str(script)], cwd=str(work), stdin=subprocess.DEVNULL,
                     stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, close_fds=True, creationflags=flags)


if __name__ == "__main__":
    raise SystemExit(main())
