#!/usr/bin/env python3
"""
The portal's Blender exports, from the game files the person has copied (portal/tools/game_assets.py):
a whole map area at once (its shell and detail files, with the region and city files they need), or
every area of the city, one .glb each, into binaries/blender/<version>/. The work is p3d_gltf.py's; this
finds the files.

    model_glb(out, index, version, ...)  one copied file as a .glb (a character with the game's animations)
    areas(out, index, version)          the map areas there are copies of: the city's
                                        (packages/z04/<area>_shell.p3d, _detail.p3d ...), the
                                        interiors (packages/azones/*_pocket.p3d) and the changing
                                        places (packages/dzones/*_dzone.p3d)
    area_glb(out, index, version, key)  one area as a .glb
    CityJob                             every city area, in the background

Your own copies, on your own computer; standard library only.
"""

from __future__ import annotations

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
    elif any(c.id == P3G.SKIN for c in src.chunks):
        for f in animations(out, index, version):
            try:
                extra = lib.add(f.name, f.read_bytes(), main=False)
            except (OSError, P3G.p3d.P3dError):
                continue
            anims += [P3G.Ref(extra, c) for c in extra.chunks if c.id == P3G.ANIMATION]
    return P3G.export(lib, map_mode=is_map, anims=anims)


def area_glb(out: Path, index: Optional[dict], version: str, key: str,
             parsed: Optional[dict] = None, library: Optional[List[Tuple[str, bytes]]] = None) -> Tuple[bytes, "P3G.Report"]:
    """One map area (all its files) as a .glb, with what it needs from the shared files."""
    area = next((a for a in areas(out, index, version) if a["key"] == key), None)
    if area is None:
        raise P3G.ExportError("that map area isn't in your copied game files")
    lib = P3G.Library(parsed)
    for path in area["files"]:
        p = GA.file_on_disk(out, index, version, path)
        if p is not None:
            lib.add(p.name, p.read_bytes(), main=True, keep=False)
    if library is None:
        library = [(p.name, p.read_bytes()) for p in _library(out, index, version)]
    mine = {Path(f).name.lower() for f in area["files"]}
    for name, data in library:
        if name.lower() not in mine:
            lib.add(name, data, main=False)
    return P3G.export(lib, map_mode=True)


class CityJob:
    """Every city area of one version, one .glb each, into binaries/blender/<version>/, in a background
    thread. Areas line up when imported together."""

    def __init__(self, bin_dir: Path):
        self.bin_dir = bin_dir
        self.status: dict = {"running": False, "version": "", "done": 0, "total": 0, "area": "", "error": "",
                             "written": 0, "bytes": 0, "folder": ""}
        self._thread: Optional[threading.Thread] = None
        self._stop = threading.Event()
        self._lock = threading.Lock()
        self.busy: Optional[Callable[[], str]] = None      # something else that mustn't run with this (why, or "")

    @property
    def running(self) -> bool:
        return bool(self._thread and self._thread.is_alive())

    def folder(self, version: str = "") -> Path:
        base = self.bin_dir / OUT_NAME
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
                               bytes=0, folder=GA._show_path(self.folder(version)))
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
        except (OSError, P3G.p3d.P3dError) as e:
            self.status["error"] = f"{type(e).__name__}: {e}"
        finally:
            self.status.update(running=False, area="")
