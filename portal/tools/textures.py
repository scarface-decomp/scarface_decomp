#!/usr/bin/env python3
"""
Every texture in the game as a picture (.png), from the game files the person copied (game_assets.py), into
binaries/textures/. The game keeps its textures inside its Pure3D (.p3d) files: each model, map area and
menu carries its own.

    textures/PC/<folder>/<file>/<texture>.png   every texture the PC has, in a folder named after the file
                                                it is in. Where another version has the same picture
                                                at a higher resolution, that one is used instead.
    textures/Exclusive to <version>/...         what only that version has: textures the PC doesn't have
                                                at all, or a different picture under a name the PC uses
                                                (the prototype's older menu icons and carpets)
    textures/Not on the PC/...                  what several of the other versions have but the PC
                                                doesn't (the biggest of them)
    textures/INDEX.txt                          what came from where

The PC's textures are the base. Checked against every texture of the other versions: the Xbox's are the
same size as the PC's (or smaller), the PS2's the same or smaller, and the 2006 prototype has 48 bigger
ones. Of those, the world textures (a garbage bag, a stone wall, a shelf of tapes) are the same picture
at twice the resolution, and are used; the rest (menu icons, a bank's carpet) are different pictures
with the same name, and go to the prototype's own folder. A texture of the same name and size is the
same picture, so only textures whose sizes differ are compared (media.likeness(): 0.99 and up for the
same art, 0.2 and below for different art).

The other versions' files that differ from the PC's were not copied by the PC-first layout: they are
read from the version's disc image (or folder) in binaries/, reading only the files with textures.

Your own copies, on your own computer; standard library only.
"""

from __future__ import annotations

import hashlib
import json
import os
import re
import threading
import time
from pathlib import Path
from typing import Callable, Dict, Iterable, List, Optional, Tuple

import game_assets as GA
import media

OUT_NAME = "textures"
MANIFEST = ".written.json"
SAME_PICTURE = 0.8               # media.likeness() at least this: the same art


def _safe(name: str) -> str:
    stem = re.sub(r"\.(tga|bmp|png|dds|jpg|jpeg|tif|tiff)$", "", name.strip(), flags=re.I)
    stem = re.sub(r'[<>:"/\\|?*\x00-\x1f]', "_", stem).strip(" .") or "texture"
    return stem + ".png"


def _folder(game_path: str) -> str:
    """Where a file's textures go: its path in the game, without its archive and .p3d."""
    g = GA.game_path(game_path)
    g = re.sub(r"\.p3d$", "", g, flags=re.I)
    parts = [re.sub(r'[<>:"\\|?*\x00-\x1f]', "_", p).strip(" .") or "_" for p in g.split("/") if p not in ("", ".", "..")]
    return "/".join(parts)


class _Want(GA.Sink):
    """A reader's sink that hands over only the files asked for (and lets the rest go by)."""

    def __init__(self, wanted: set, got: Callable[[str, bytes], None]):
        self.wanted, self.got = wanted, got

    def file(self, path: str, size: int, chunks: Iterable[bytes]) -> str:
        if path in self.wanted:
            self.got(path, b"".join(chunks))
        else:
            for _ in chunks:
                pass
        return path

    def same(self, path: str, size: int, sha: str) -> None:
        pass


class Export:
    """One export: the PC's textures, then each other version's, then the sharper and the exclusive ones."""

    def __init__(self, bin_dir: Path, index: dict, sources: Dict[str, GA.Source], status: dict,
                 stop: Callable[[], bool], log: Callable[[str], None] = print):
        self.bin_dir, self.index, self.sources, self.status, self.stop, self.log = bin_dir, index, sources, status, stop, log
        self.files_out = GA.out_dir(bin_dir)
        self.root = bin_dir / OUT_NAME
        self.versions = [v for v in GA.VERSIONS if v in index.get("versions", {})]
        self.main = "pc" if "pc" in self.versions else (self.versions[0] if self.versions else "")
        self.table: Dict[str, List[Tuple[int, int, str]]] = {}         # name -> (w, h, where under main)
        self.sharper: Dict[str, Tuple[str, int, int, bytes, str]] = {}  # name -> (version, w, h, png, file)
        self.extra: Dict[str, List[tuple]] = {}         # key -> (v, w, h, png, file, texture name, note)
        self._thumbs: Dict[Tuple[str, int], List[float]] = {}           # (where under main, size): thumbnail
        self._seen: set = set()                                         # (name, bytes) already looked at
        self.written: List[str] = []
        self.lines: List[str] = []
        self.unreadable: Dict[str, int] = {}

    # ------------------------------------------------------------------ writing

    def _write(self, rel: str, png: bytes) -> None:
        p = self.root / rel
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_bytes(png)
        self.written.append(rel)
        self.status["written"] = len(self.written)

    def _clear_last(self) -> None:
        """Remove what the last export wrote (and only that), so nothing stale is left."""
        try:
            old = json.loads((self.root / MANIFEST).read_text(encoding="utf-8"))
        except (OSError, ValueError):
            return
        for rel in old.get("files", []):
            try:
                (self.root / rel).unlink()
            except OSError:
                pass
        for dirpath, _d, _f in sorted(os.walk(self.root), key=lambda t: -len(t[0])):
            if Path(dirpath) != self.root:
                try:
                    os.rmdir(dirpath)
                except OSError:
                    pass

    # ------------------------------------------------------------------ reading

    def _rows(self, v: str) -> List[list]:
        return [r for r in self.index["versions"][v].get("files", [])
                if r[0].lower().endswith(".p3d") and len(r) > 5 and r[5] and r[5].get("tex")]

    def _textures(self, data: bytes) -> List[media.Texture]:
        try:
            return media.textures(data)
        except Exception:  # noqa: BLE001 - a damaged file: its textures are left out
            return []

    def run(self) -> None:
        if not self.main:
            raise GA.Stopped()
        self._clear_last()
        self.root.mkdir(parents=True, exist_ok=True)
        label = GA.LABELS[self.main]
        main_rows = self._rows(self.main)
        self.status.update(phase="main", label=label, done=0, total=len(main_rows))
        main_shas = set()
        for i, r in enumerate(main_rows):
            if self.stop():
                raise GA.Stopped()
            main_shas.add(r[2])
            p = GA.file_on_disk(self.files_out, self.index, self.main, r[0])
            if p is None:
                self.unreadable[self.main] = self.unreadable.get(self.main, 0) + 1
                continue
            data = p.read_bytes()
            folder, used = _folder(r[0]), set()
            for t in self._textures(data):
                name = _safe(t.name)
                while name.lower() in used:                           # two textures, one name: keep both
                    name = name[:-4] + "_" + ".png"
                used.add(name.lower())
                try:
                    png = media.picture_png(data, t)
                except media.MediaError:
                    continue
                rel = f"{label}/{folder}/{name}"
                self._write(rel, png)
                self.table.setdefault(t.name.lower(), []).append((t.width, t.height, rel))
            self.status["done"] = i + 1
        for v in self.versions:
            if v != self.main:
                self._other(v, main_shas)
        self._finish(label)

    def _other(self, v: str, main_shas: set) -> None:
        rows = [r for r in self._rows(v) if r[2] not in main_shas]      # the same bytes: the same textures
        self.status.update(phase="other", label=GA.LABELS[v], done=0, total=len(rows), read=0, to_read=0)
        on_disc: Dict[str, list] = {}
        for i, r in enumerate(rows):
            if self.stop():
                raise GA.Stopped()
            p = GA.file_on_disk(self.files_out, self.index, v, r[0])
            if p is not None:
                self._look(v, r[0], p.read_bytes())
            else:
                on_disc[r[0]] = r
            self.status["done"] = i + 1
        if not on_disc:
            return
        src = self.sources.get(v)
        if src is None:
            self.unreadable[v] = self.unreadable.get(v, 0) + len(on_disc)
            self.log(f"    {len(on_disc):,} {GA.LABELS[v]} files with textures aren't copied and its disc isn't in binaries/")
            return
        self.status.update(phase="disc", to_read=src.size, read=0)
        if src.kind == "folder":                                       # a folder: just the files wanted
            for path in list(on_disc):
                f = src.path / path
                if f.is_file():
                    self._look(v, path, f.read_bytes())
                    del on_disc[path]
        if on_disc:
            def got(path: str, data: bytes) -> None:
                self._look(v, path, data)
                on_disc.pop(path, None)

            def progress(pos: int) -> None:
                self.status["read"] = pos
            self.log(f"[*] {GA.LABELS[v]}: reading {len(on_disc):,} files with textures from {src.name}")
            GA.READERS[src.kind](src, _Want(set(on_disc), got), progress, self.stop, self.log)
        if on_disc:
            self.unreadable[v] = self.unreadable.get(v, 0) + len(on_disc)

    def _look(self, v: str, path: str, data: bytes) -> None:
        """Each texture of another version's file: the PC has it (same size: the same picture; bigger and
        the same picture: sharper; a different picture: this version's own), or it doesn't."""
        for t in self._textures(data):
            key = t.name.lower()
            mine = self.table.get(key)
            if not mine:
                self._extra(key, v, t, data, path, "")
                continue
            w, h, rel = max(mine, key=lambda m: m[0] * m[1])
            if t.width * t.height == w * h:
                continue
            seen = (key, hashlib.sha1(data[t.offset:t.offset + t.size]).digest())
            if seen in self._seen:                                     # the same texture in another file
                continue
            self._seen.add(seen)
            n = media.thumb_size(t.width, t.height, w, h)
            try:
                theirs = media.pixels(data, t)
                if (rel, n) not in self._thumbs:
                    self._thumbs[(rel, n)] = media.thumb(*media.decode_png((self.root / rel).read_bytes()), n=n)
            except (media.MediaError, OSError, ValueError):
                continue
            if media.correlate(media.thumb(*theirs, n=n), self._thumbs[(rel, n)]) >= SAME_PICTURE:
                if t.width * t.height > w * h:
                    best = self.sharper.get(key)
                    if best is None or t.width * t.height > best[1] * best[2]:
                        self.sharper[key] = (v, t.width, t.height, media.png(*theirs), path)
            else:
                self._extra(key + "|" + v, v, t, data, path, f"a different picture from the {GA.LABELS[self.main]}'s "
                            f"{t.name} ({w}x{h})")

    def _extra(self, key: str, v: str, t: media.Texture, data: bytes, path: str, note: str) -> None:
        have = self.extra.setdefault(key, [])
        if any(e[0] == v for e in have):                               # once per version
            return
        try:
            png = media.picture_png(data, t)
        except media.MediaError:
            return
        have.append((v, t.width, t.height, png, path, t.name, note))

    # ------------------------------------------------------------------ the rest

    def _finish(self, label: str) -> None:
        self.status.update(phase="writing", label="")
        for key, (v, w, h, png, path) in sorted(self.sharper.items()):
            for mw, mh, rel in self.table.get(key, []):
                self._write(rel, png)
                self.lines.append(f"{rel}: {w}x{h} from the {GA.LABELS[v]} ({path}); the {label}'s is {mw}x{mh}")
        for key, found in sorted(self.extra.items()):
            v, w, h, png, path, tname, note = max(found, key=lambda e: e[1] * e[2])
            top = GA.exclusive(v) if len(found) == 1 else GA.NOT_ON_PC
            rel = f"{top}/{_folder(path)}/{_safe(tname)}"
            if (self.root / rel).exists():                             # two of a name in one folder
                rel = rel[:-4] + f" ({GA.LABELS[v]}).png"
            self._write(rel, png)
            also = ", ".join(GA.LABELS[e[0]] for e in found if e[0] != v)
            self.lines.append(f"{rel}: {w}x{h} from the {GA.LABELS[v]}" + (f" (also in {also})" if also else "")
                              + (f"; {note}" if note else ""))
        sharp = len(self.sharper)
        extra = sum(1 for k in self.extra)
        head = [f"Textures from your copy of Scarface: The World Is Yours, {time.strftime('%Y-%m-%d %H:%M')}.",
                f"{label}/ has every texture the {label} has, as .png, in a folder named after the file it is in.",
                f"{sharp:,} of them are the same picture at a higher resolution in another version, and that one "
                "is used (listed below).",
                f"{extra:,} textures the {label} doesn't have, or has as a different picture under the same name, "
                "are in the Exclusive to ... and Not on the PC folders (listed below).", ""]
        if self.unreadable:
            head.append("Not read: " + ", ".join(f"{n:,} {GA.LABELS[v]} files" for v, n in self.unreadable.items())
                        + " (not copied, and the disc image wasn't in binaries/).")
            head.append("")
        (self.root / "INDEX.txt").write_text("\n".join(head + sorted(self.lines)) + "\n", encoding="utf-8")
        (self.root / MANIFEST).write_text(json.dumps({"files": self.written}), encoding="utf-8")
        self.status.update(sharper=sharp, extra=extra)


class TextureJob:
    """The export, in the background."""

    def __init__(self, bin_dir: Path):
        self.bin_dir = bin_dir
        self.status: dict = {"running": False, "phase": "", "label": "", "done": 0, "total": 0, "written": 0,
                             "read": 0, "to_read": 0, "error": "", "sharper": 0, "extra": 0,
                             "folder": GA._show_path(bin_dir / OUT_NAME)}
        self._thread: Optional[threading.Thread] = None
        self._stop = threading.Event()
        self._lock = threading.Lock()
        self.busy: Optional[Callable[[], str]] = None

    @property
    def running(self) -> bool:
        return bool(self._thread and self._thread.is_alive())

    def folder(self) -> Path:
        return self.bin_dir / OUT_NAME

    def start(self, index: Optional[dict], sources: Dict[str, GA.Source]) -> Optional[str]:
        with self._lock:
            if self.running:
                return "Already exporting the textures. Wait for it to finish or press Stop."
            why = self.busy() if self.busy is not None else ""
            if why:
                return why
            if not index or not index.get("versions"):
                return "Copy the game files first: the textures are taken from them."
            self._stop.clear()
            self.status.update(running=True, phase="starting", label="", done=0, total=0, written=0, read=0,
                               to_read=0, error="", sharper=0, extra=0)
            self._thread = threading.Thread(target=self._run, args=(index, sources), daemon=True, name="textures")
            self._thread.start()
            return None

    def stop(self) -> None:
        self._stop.set()

    def _run(self, index: dict, sources: Dict[str, GA.Source]) -> None:
        try:
            Export(self.bin_dir, index, sources, self.status, self._stop.is_set, print).run()
            self.status["phase"] = "done"
        except GA.Stopped:
            self.status.update(phase="stopped", error="Stopped.")
        except Exception as e:  # noqa: BLE001 - shown in the portal
            import traceback
            traceback.print_exc()
            self.status.update(phase="error", error=f"{type(e).__name__}: {e}")
        finally:
            self.status["running"] = False


def main(argv=None) -> int:
    import argparse
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--bin", type=Path, default=GA.BIN_DIR, help="the folder with your game files")
    a = ap.parse_args(argv)
    index = GA.load_index(GA.out_dir(a.bin))
    if not index:
        print("Copy the game files first (python portal/tools/game_assets.py --extract pc).")
        return 1
    sources, _notes = GA.find_sources(a.bin)
    status: dict = {}
    Export(a.bin, index, sources, status, lambda: False).run()
    print(f"{status.get('written', 0):,} pictures written to {a.bin / OUT_NAME}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
