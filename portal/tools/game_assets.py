#!/usr/bin/env python3
"""
Copy the game's own files out of your copies of the game, for personal use: sounds, textures and
models, videos, scripts, everything on the disc or in the game folder.

Every version found in binaries/ is read: the Xbox game, the PC game, the PS2 disc and the April 2006
Xbox prototype. The PC game needs no installing: its disc image (.iso) is read directly. The disc keeps
the game in Microsoft cabinet files (Data1.cab, Data11.cab), which are unpacked here (ms_cab.py) and
named and placed by the disc's own installer database (SCARFACE.MSI), exactly as installing would.
patch01.rcf from the official 1.00.2 patch is added when the patch is in binaries/ too. Each file is written in the folder it has inside the game.
Files packed in .rcf archives are unpacked into a folder named after the archive
(cement.rcf/art/...), so every file keeps its place.

Four layouts:

  unique   no duplicates. A file that is exactly the same in two or more versions is written once,
           in Shared/. What only one version has goes in its own folder, Exclusive to <version>/,
           and the files a version has in a different form from the others in <version>/.
  every    every version complete in its own folder.
  best     one copy of every file the versions share, in Best/: where they have it in different
           forms, the highest-quality one (sounds: sample rate, then channels, then codec; videos:
           picture size; models and textures: texture size, then colour depth). Ties go to PC,
           Xbox, PS2, then the prototype, and the 1.00.2 patch's files win over the ones they
           replace. What only one version has goes in Exclusive to <version>/.
  pc       the PC first: the whole PC version in PC/ (with the 1.00.2 patch's files where it
           changes one), then only what the PC doesn't have from the others: what only one of
           them has in Exclusive to <version>/, and what two or more of them have, once (the
           highest-quality copy), in Not on the PC/.

And two ways to arrange the folders: as in the game, or by type first (Sounds, Textures, Models,
Animations, Videos, Scripts & text, Other), each keeping the game's own folders below that. Pure3D
files (.p3d) are sorted by what is inside them: meshes make a model, textures alone a texture file.

The output goes in binaries/game_files/. binaries/ is in .gitignore, so these files are never
committed or uploaded: they stay on this computer, for your own use.

    python portal/tools/game_assets.py                    # the versions found
    python portal/tools/game_assets.py --extract unique   # or: --extract every, best, pc

How it reads: a disc image is read front to back once, even inside a .7z (which can only be read in
order). Directories and .rcf archive tables are read as they go past, and each file is copied when
its bytes go past. Files are stored by their content first (so a file several versions share is
written once), then moved to their places. A run that is stopped carries on where it left off.
"""

from __future__ import annotations

import argparse
import contextlib
import fnmatch
import hashlib
import heapq
import io
import json
import os
import queue as queue_mod
import shutil
import struct
import subprocess
import sys
import tempfile
import threading
import time
import zipfile
from dataclasses import dataclass
from pathlib import Path, PurePath, PurePosixPath
from typing import BinaryIO, Callable, Dict, Iterable, Iterator, List, Optional, Tuple

HERE = Path(__file__).resolve().parent
if str(HERE) not in sys.path:
    sys.path.insert(0, str(HERE))

import game_files as GF  # noqa: E402
import ms_cab as CAB  # noqa: E402
import msi_reader as MR  # noqa: E402
import sevenzip  # noqa: E402
from rcf import MAGIC as RCF_MAGIC, RcfArchive, RcfError, safe_output_path  # noqa: E402

ROOT = HERE.parent.parent
BIN_DIR = ROOT / "binaries"
OUT_NAME = "game_files"
SECTOR = 2048
CHUNK = 1 << 20

# Also the order Shared/ takes a file's place from when versions keep it in different folders.
VERSIONS = ("xbox", "pc", "ps2", "prototype")
LABELS = {"xbox": "Xbox", "pc": "PC", "ps2": "PS2", "prototype": "Xbox 2006 prototype"}
SHARED = "Shared"
CHANGED_BY_YOU = "Changed by you"
MODES = ("unique", "every", "best", "pc")
MODE_LABELS = {"unique": "No duplicates", "every": "Every version complete", "best": "Best version of each file",
               "pc": "The PC first, then what only the others have"}
FOLDERS = ("game", "type")
FOLDER_LABELS = {"game": "As in the game", "type": "By type"}
BEST = "Best"
NOT_ON_PC = "Not on the PC"        # the PC-first layout: files two or more other versions have, but not the PC


def exclusive(version: str) -> str:
    """The folder for what only this version has."""
    return f"Exclusive to {LABELS[version]}"
PREFER = ("pc", "xbox", "ps2", "prototype")     # who wins a tie in quality
P3D_MAGIC = b"P3D\xff"
P3D_SNIFF_MAX = 64 << 20                         # bigger .p3d files are not looked inside
RSD_SNIFF = 4096                                 # a sound's header, its source name and a WMA sound's own header
NESTED_MAX = 3                                   # archives inside archives (the dialogue is packed that way)
ASF_STREAM = bytes.fromhex("9107DCB7B7A9CF118EE600C00C205365")   # ASF Stream Properties object
SOUND_CODECS = {"PCM": 4, "PCMB": 4, "OOGV": 3, "OGG": 3, "WMA": 3, "XMA": 3, "AT3+": 2,
                "XADP": 1, "RADP": 1, "VAG": 1, "WADP": 1, "GADP": 1}
STATUS_LABELS = {"only": "Only in this version", "changed": "Different in this version",
                 "shared": "The same in another version"}

KINDS = (
    ("sounds", "Sounds", (".rsd", ".rsf", ".rsp", ".wav", ".vag", ".adp", ".xwb", ".xsb", ".wma", ".mp3",
                          ".ogg", ".snd", ".vab", ".aud")),
    ("textures", "Textures", (".dds", ".tga", ".png", ".bmp", ".jpg", ".xpr", ".tm2", ".tx2")),
    ("models", "Models", (".p3d",)),             # a .p3d holding no mesh is sorted by what it does hold
    ("animations", "Animations", ()),
    ("videos", "Videos", (".bik", ".rmv", ".xmv", ".pss", ".wmv", ".sfd", ".mpg", ".m2v")),
    ("scripts", "Scripts & text", (".cso", ".dso", ".cs", ".ds", ".dtr", ".fsc", ".txt", ".xml", ".ini",
                                   ".cfg", ".csv")),
)
KIND_LABELS = dict([(k, label) for k, label, _ in KINDS] + [("other", "Other")])
_KIND_OF_EXT = {ext: k for k, _, exts in KINDS for ext in exts}

SKIP_DIRS = {"scripts_and_data", OUT_NAME, "_unpacked", "_to_delete",
             "ps2_overlays",               # the PS2 code overlays copied out by extract_scripts.py, not a game
             "blender"}                    # the map exports blender_export.py writes
PC_DISC_NOTE = ("put the PC disc image (.iso) in binaries/ as it is: the portal reads it without installing "
                "anything. An installed game folder works too.")
PC_IN_ARCHIVE_NOTE = ("this looks like the PC disc packed in a .zip/.7z: unpack the .iso into binaries/ and the "
                      "portal reads it from there (the PC disc can't be read from inside an archive)")

Log = Callable[[str], None]


class Stopped(Exception):
    """The person pressed Stop."""


def kind_of(path: str, info: Optional[dict] = None) -> str:
    """Sounds, textures, models, animations, videos, scripts & text or other. A Pure3D file is sorted
    by what is inside it, when that is known (sniff())."""
    kind = _KIND_OF_EXT.get(PurePosixPath(path).suffix.lower(), "other")
    if kind == "models" and info and info.get("p3d"):
        return info["p3d"]
    return kind


def _p3d_info(path: str, data: bytes) -> Optional[dict]:
    """What a Pure3D file holds: its top-level chunks say whether it is a model (a mesh or skin), only
    textures, or animation; the texture chunks anywhere in it give their size and colour depth."""
    if data[:4] != P3D_MAGIC or len(data) < 12:
        return None
    top, pixels, bits = set(), 0, 0
    stack = [(struct.unpack_from("<I", data, 4)[0], min(struct.unpack_from("<I", data, 8)[0], len(data)), 1)]
    walked = 0
    while stack and walked < 200_000:
        off, end, depth = stack.pop()
        while off + 12 <= end:
            walked += 1
            cid, head, total = struct.unpack_from("<III", data, off)
            if total < 12 or head < 12 or head > total or off + total > end:
                break
            if depth == 1:
                top.add(cid)
            if cid == 0x19000 and off + 13 <= len(data):          # Texture: name, version, width, height, bpp
                p = off + 13 + data[off + 12]
                if p + 16 <= off + head:
                    _ver, w, h, bpp = struct.unpack_from("<IIII", data, p)
                    if w <= 16384 and h <= 16384 and bpp <= 64:
                        pixels += w * h
                        bits += w * h * bpp
            if head < total:
                stack.append((off + head, off + total, depth + 1))
            off += total
    if not top:
        return None                         # nothing readable inside: sorted by its name alone
    if top & {0x10000, 0x10001}:            # Mesh, Skin
        kind = "models"
    elif 0x19000 in top:
        kind = "textures"
    elif 0x121000 in top:                   # Animation
        kind = "animations"
    elif "subtitle" in path.lower() or "textbible" in path.lower():
        kind = "scripts"
    else:
        kind = "other"
    out = {"p3d": kind}
    if pixels:
        out.update(tex=pixels, bits=bits)
    return out


def _sniff_wants(path: str, size: int) -> int:
    """How much of a file sniff() needs: -1 all of it, n the first n bytes, 0 nothing."""
    low = path.lower()
    if low.endswith(".p3d"):
        return -1 if size <= P3D_SNIFF_MAX else 0
    if low.endswith(".rsd"):
        return RSD_SNIFF
    return {".bik": 64, ".rmv": 16}.get(low[-4:], 0)                # a video's header


def sniff(path: str, data: bytes) -> Optional[dict]:
    """The facts that say how good a copy of a file is: a sound's codec, channels and sample rate, a
    video's picture size, a model's textures (and what kind of .p3d it is)."""
    low = path.lower()
    try:
        if low.endswith(".rsd") and data[:3] == b"RSD" and len(data) >= 20:
            channels, _bits, rate = struct.unpack_from("<3I", data, 8)
            out = {"codec": data[4:8].decode("latin-1").strip(), "ch": channels, "rate": rate}
            if data[0x14:0x18] == b"****":          # the name the sound had on the developers' machines
                end = data.find(b"\0", 0x18)
                if end > 0x18:
                    out["name"] = data[0x18:end].decode("latin-1")
            if out["codec"] == "WMA":               # its header's rate field isn't one: the WMA header says
                out["rate"], i = 0, data.find(ASF_STREAM)
                fmt = i + 16 + 8 + 16 + 16 + 8 + 4 + 4 + 2 + 4
                if i >= 0 and fmt + 12 <= len(data):
                    _tag, ch, rate, per_sec = struct.unpack_from("<HHII", data, fmt)
                    out.update(ch=ch, rate=rate, kbps=per_sec * 8 // 1000)
            return out
        if low.endswith(".bik") and data[:3] == b"BIK" and len(data) >= 28:
            w, h = struct.unpack_from("<II", data, 20)
            return {"w": w, "h": h}
        if low.endswith(".rmv") and data[:8] == b"rmvps212" and len(data) >= 12:     # the PS2's movies
            w, h = struct.unpack_from("<HH", data, 8)
            return {"w": w, "h": h}
        if low.endswith(".p3d"):
            return _p3d_info(path, data)
    except struct.error:
        return None
    return None


def quality(info: Optional[dict]) -> tuple:
    """Bigger is better: (sample rate, channels, codec) for sounds, picture size for videos,
    (texture pixels, texture bits) for models and textures; () when there is nothing to compare."""
    if not info:
        return ()
    if "rate" in info:
        return (info.get("rate") or 0, info.get("ch") or 0, SOUND_CODECS.get((info.get("codec") or "").upper(), 2))
    if "w" in info:
        return ((info.get("w") or 0) * (info.get("h") or 0),)
    if "tex" in info:
        return (info.get("tex") or 0, info.get("bits") or 0)
    return ()


def describe(info: Optional[dict]) -> str:
    """The quality facts in words, for the index files."""
    if not info:
        return ""
    if "rate" in info:
        ch = {1: "mono", 2: "stereo", 6: "5.1 surround"}.get(info.get("ch"), f"{info.get('ch')} channels")
        codec = {"OOGV": "Ogg Vorbis", "XADP": "Xbox ADPCM", "RADP": "Radical ADPCM", "VAG": "PS2 ADPCM",
                 "WMA": "WMA", "PCM": "PCM"}.get(info.get("codec"), info.get("codec"))
        kbps = f" {info['kbps']} kbps" if info.get("kbps") else ""
        rate = f", {info['rate']:,} Hz" if info.get("rate") else ""
        return f"{codec}{kbps}{rate}, {ch}"
    if "w" in info:
        return f"{info['w']}x{info['h']} video"
    if "tex" in info:
        return f"{info['tex']:,} texture pixels"
    return ""


def _is_patch(path: str) -> bool:
    first = path.split("/", 1)[0].lower()
    return first.startswith("patch") and first.endswith(".rcf")


def sound_name(info: Optional[dict]) -> str:
    """A sound's original name as a path in the game's tree, e.g. art/sound/music/miami/dj/03.rsd
    (the files are Radical's .rsd sounds, so they keep that ending)."""
    name = (info or {}).get("name") or ""
    parts = [p for p in name.replace("\\", "/").split("/") if p and not p.endswith(":")]
    if "scarface" in [p.lower() for p in parts]:
        parts = parts[[p.lower() for p in parts].index("scarface") + 1:]
    if not parts or any(p in (".", "..") for p in parts):
        return ""
    stem = parts[-1].rsplit(".", 1)[0] if "." in parts[-1] else parts[-1]
    return "/".join(parts[:-1] + [stem + ".rsd"])


def game_path(path: str) -> str:
    """A file's place in the game without the .rcf archive it is packed in: the path the game asks for."""
    return "/".join(p for p in path.split("/") if not p.lower().endswith(".rcf")) or path


def compare_key(path: str) -> str:
    """The name two versions' copies of a file share: lower case, without the .rcf archive folder,
    so 'cement.rcf/art/x.p3d' (Xbox) and 'art/x.p3d' (the prototype, loose) are the same file."""
    parts = [p for p in path.replace("\\", "/").lower().split("/") if p and not p.endswith(".rcf")]
    return "/".join(parts)


def _fmt_bytes(n: int) -> str:
    for unit in ("bytes", "KB", "MB", "GB"):
        if n < 1024 or unit == "GB":
            return f"{n:,} {unit}" if unit == "bytes" else f"{n:.1f} {unit}"
        n /= 1024
    return f"{n:.1f} GB"


def _os(p: Path) -> str:
    """A path Windows accepts even past 260 characters."""
    s = str(p)
    if os.name == "nt" and not s.startswith("\\\\?\\"):
        s = "\\\\?\\" + os.path.abspath(s)
    return s


# --------------------------------------------------------------------------- #
# Where the game's files come from
# --------------------------------------------------------------------------- #

@dataclass
class Source:
    version: str
    path: Path            # the download, disc image or game folder
    kind: str             # "zip" (a game folder in a .zip), "disc" (a disc image), "folder"
    member: str = ""      # the disc image inside a .zip or .7z
    size: int = 0         # bytes that will be read, for the progress bar
    fs: str = ""          # disc file system: "xdvdfs" (Xbox) or "iso" (PS2)
    extra: str = ""       # PC disc: the 1.00.2 patch, whose patch01.rcf is added

    @property
    def label(self) -> str:
        return LABELS[self.version]

    @property
    def name(self) -> str:
        name = self.path.name + (f" ({Path(self.member).name})" if self.member else "")
        return name + (f" + {Path(self.extra).name}" if self.extra else "")

    def signature(self) -> str:
        stamps = []
        for p in [self.path] + ([Path(self.extra)] if self.extra else []):
            try:
                st = p.stat()
                stamps.append(f"{st.st_size}:{int(st.st_mtime)}" if not p.is_dir() else str(self.size))
            except OSError:
                stamps.append("?")
        return f"{self.kind}|{self.path.name}|{self.member}|{'|'.join(stamps)}"

    def to_json(self) -> dict:
        return {"version": self.version, "label": self.label, "source": self.name, "size": self.size,
                "kind": self.kind}


def _version_from_name(name: str) -> str:
    low = name.lower()
    if "proto" in low:
        return "prototype"
    if "ps2" in low or "slus" in low or "sles" in low or "playstation" in low:
        return "ps2"
    if "xbox" in low:
        return "xbox"
    return ""


def _peek_fs(head: bytes) -> Tuple[str, str]:
    """(file system, version guess) from the first 66 KB of a disc image."""
    if len(head) >= 0x10800 and GF._volume(head[0x10000:0x10800]):
        return "xdvdfs", "xbox"
    pvd = head[16 * SECTOR:17 * SECTOR]
    if len(pvd) == SECTOR and pvd[1:6] == b"CD001":
        system = pvd[8:40].decode("latin-1", "replace").strip().upper()
        if "PLAYSTATION" in system:
            return "iso", "ps2"
        return "iso", ""
    return "", ""


def _read_exact(f, n: int) -> bytes:
    out = bytearray()
    while len(out) < n:
        piece = f.read(n - len(out))
        if not piece:
            break
        out += piece
    return bytes(out)


def _disc_source(path: Path, member: str = "", size: int = 0, notes: Optional[List[str]] = None) -> Optional[Source]:
    """A disc image, loose or inside a .zip/.7z."""
    label = Path(member).name if member else path.name
    try:
        with _open_stream(path, member) as (f, _):
            head = _read_exact(f, 0x10800)
    except (OSError, sevenzip.Unsupported, zipfile.BadZipFile, RuntimeError) as e:
        if notes is not None:
            notes.append(f"{label}: could not be read ({e})")
        return None
    fs, version = _peek_fs(head)
    named = _version_from_name(path.name + " " + member)
    if fs == "iso" and not version and not named:
        if not member:
            files = _pc_disc_root(path)
            if files is not None and _pc_layout(files):
                return Source("pc", path, "pcdisc", size=_pc_cab_bytes(files))
        elif notes is not None:
            notes.append(f"{label}: {PC_IN_ARCHIVE_NOTE}")
            return None
        if notes is not None:
            notes.append(f"{label}: not a Scarface disc the portal knows (Xbox, PS2 or PC)")
        return None
    if not fs:
        fs = "xdvdfs"                  # full Xbox images keep their file system further in
    version = named or version or "xbox"
    if not size:
        try:
            size = path.stat().st_size
        except OSError:
            size = 0
    return Source(version, path, "disc", member, size, fs)


def _zip_game_source(path: Path, notes: List[str]) -> Optional[Source]:
    """A .zip with a game folder in it (the prototype)."""
    try:
        with zipfile.ZipFile(path) as z:
            infos = [i for i in z.infolist() if not i.is_dir()]
    except (OSError, zipfile.BadZipFile) as e:
        notes.append(f"{path.name}: could not be read ({e})")
        return None
    names = [i.filename.lower() for i in infos]
    version = _version_from_name(path.name)
    if not version:
        if any(n.endswith("default.xbe") for n in names):
            version = "xbox"
        elif any(n.endswith("scarface.exe") for n in names):
            version = "pc"
        elif any(n.endswith("game.xbe") for n in names):
            version = "prototype"
    if not version:
        return None
    return Source(version, path, "zip", "", sum(i.file_size for i in infos))


def _folder_size(folder: Path) -> int:
    total = 0
    for dirpath, _dirs, files in os.walk(folder):
        for f in files:
            try:
                total += os.path.getsize(os.path.join(dirpath, f))
            except OSError:
                pass
    return total


def _folder_version(folder: Path) -> str:
    named = _version_from_name(folder.name)
    if named:
        return named
    if (folder / "default.xbe").is_file():
        return "xbox"
    if (folder / "game.xbe").is_file():
        return "prototype"
    if any((folder / n).is_file() for n in ("Scarface.exe", "scarface.exe")):
        return "pc"
    if any((folder / n).is_file() for n in ("cement.rcf", "CEMENT.RCF")):
        return "pc"                    # an installed game's folder
    return ""


def find_sources(bin_dir: Path = BIN_DIR, installed_pc: bool = True) -> Tuple[Dict[str, Source], List[str]]:
    """Every version of the game found in binaries/ (and an installed PC game), with notes on files
    that could not be used. One source per version: the first one found wins."""
    found: Dict[str, Source] = {}
    notes: List[str] = []

    def add(src: Optional[Source]) -> None:
        if src and src.version in LABELS and src.version not in found:
            found[src.version] = src

    entries = sorted(bin_dir.iterdir(), key=lambda p: p.name.lower()) if bin_dir.is_dir() else []
    for p in entries:
        low = p.name.lower()
        if p.is_dir():
            if p.name in SKIP_DIRS:
                continue
            disc = _pc_folder_root(p)
            if _pc_layout(disc):                      # a copy of the PC disc: read like the disc image
                add(Source("pc", p, "pcdisc", size=_pc_cab_bytes(disc)))
                continue
            v = _folder_version(p)
            if v:
                add(Source(v, p, "folder", size=_folder_size(p)))
        elif low.endswith(GF.ARCHIVES):
            try:
                images = GF.disc_images_in(p)
            except Exception as e:  # noqa: BLE001 - reported, the rest still works
                notes.append(f"{p.name}: could not be read ({e})")
                continue
            if images:
                member, size = max(images, key=lambda m: m[1])
                add(_disc_source(p, member, size, notes))
            elif low.endswith(".zip"):
                add(_zip_game_source(p, notes))
        elif low.endswith(GF.DISC_IMAGES):
            add(_disc_source(p, notes=notes))
    if installed_pc and "pc" not in found:
        exe = GF._installed_pc_exe()
        if exe is not None and exe.parent.is_dir():
            add(Source("pc", exe.parent, "folder", size=_folder_size(exe.parent)))
    pc = found.get("pc")
    if pc is not None and pc.kind == "pcdisc":
        patch = GF._patch_installer(bin_dir)
        rcfs = _patch_rcfs(patch) if patch else []
        if rcfs:
            pc.extra = str(patch)
            pc.size += sum(size for _n, size in rcfs)
    if "pc" not in found and not any(PC_IN_ARCHIVE_NOTE in n for n in notes):
        notes.append(f"PC: not found. {PC_DISC_NOTE[0].upper() + PC_DISC_NOTE[1:]}")
    return found, notes


# --------------------------------------------------------------------------- #
# Reading
# --------------------------------------------------------------------------- #

class _Prefetch:
    """Reads a packed member ahead on a second thread, so unpacking it (zlib and lzma let other threads run
    while they work) overlaps with the hashing and reading of tables here. A file object: read(n), close()."""

    BLOCK = 8 << 20

    def __init__(self, f, depth: int = 4):
        self.f, self.q = f, queue_mod.Queue(depth)
        self.buf, self.off, self.done, self.err = b"", 0, False, None
        self.stopping = threading.Event()
        self.thread = threading.Thread(target=self._run, name="prefetch", daemon=True)
        self.thread.start()

    def _run(self) -> None:
        size = 256 << 10                   # small at first: a quick look at a disc's start unpacks little
        try:
            while not self.stopping.is_set():
                block = self.f.read(size)
                size = min(size * 2, self.BLOCK)
                self._put(block)
                if not block:
                    return
        except BaseException as e:  # noqa: BLE001 - handed to the reader
            self.err = e
            self._put(b"")

    def _put(self, block: bytes) -> None:
        while not self.stopping.is_set():
            try:
                self.q.put(block, timeout=0.2)
                return
            except queue_mod.Full:
                continue

    def read(self, n: int = -1) -> bytes:
        out = []
        while n != 0:
            if self.off >= len(self.buf):
                if self.done:
                    break
                self.buf, self.off = self.q.get(), 0
                if not self.buf:
                    self.done = True
                    if self.err is not None:
                        raise self.err
                    break
            take = self.buf[self.off:] if n < 0 else self.buf[self.off:self.off + n]
            self.off += len(take)
            out.append(take)
            if n > 0:
                n -= len(take)
        return b"".join(out)

    def close(self) -> None:
        self.stopping.set()
        self.thread.join(timeout=10)


class _open_stream:
    """The disc image as a file object read front to back: a loose file, a .zip member, or a .7z
    member (read with the built-in reader, or the 7-Zip program for unusual compression)."""

    def __init__(self, path: Path, member: str = ""):
        self.path, self.member = path, member
        self._close: List[Callable[[], None]] = []

    def __enter__(self):
        if not self.member:
            f = open(self.path, "rb")
            self._close.append(f.close)
            return f, True
        if self.path.name.lower().endswith(".zip"):
            z = zipfile.ZipFile(self.path)
            self._close.append(z.close)
            f = z.open(self.member)
            ahead = _Prefetch(f)
            self._close[:0] = [ahead.close, f.close]
            return ahead, False
        try:
            z = sevenzip.SevenZip(self.path)
            self._close.append(z.close)
            f = z.open(self.member)
            ahead = _Prefetch(f)
            self._close[:0] = [ahead.close, f.close]
            return ahead, False
        except sevenzip.Unsupported:
            self.__exit__()
            exe = GF._seven_zip_program()
            if not exe:
                raise RuntimeError(GF.NO_7Z)
            proc = subprocess.Popen([exe, "e", "-so", str(self.path), self.member],
                                    stdout=subprocess.PIPE, stderr=subprocess.DEVNULL)

            def done():
                proc.kill()
                proc.wait()
            self._close.append(done)
            return proc.stdout, False

    def __exit__(self, *exc):
        while self._close:
            try:
                self._close.pop(0)()
            except Exception:  # noqa: BLE001 - closing what is left
                pass


class _Forward:
    """Reads a stream front to back. skip_to() moves ahead: seeks when it can, reads past otherwise."""

    def __init__(self, f, seekable: bool, on_move: Callable[[int], None]):
        self.f, self.seekable, self.pos, self.on_move = f, seekable, 0, on_move

    def skip_to(self, off: int) -> None:
        if off < self.pos:
            raise ValueError("behind")
        if self.seekable:
            self.f.seek(off)
            self.pos = off
        while self.pos < off:
            n = len(self.f.read(min(8 * CHUNK, off - self.pos)))
            if not n:
                raise EOFError("the disc image ends early")
            self.pos += n
            self.on_move(self.pos)
        self.on_move(self.pos)

    def read(self, n: int) -> bytes:
        data = _read_exact(self.f, n)
        self.pos += len(data)
        self.on_move(self.pos)
        if len(data) < n:
            raise EOFError("the disc image ends early")
        return data

    def chunks(self, n: int) -> Iterator[bytes]:
        while n > 0:
            piece = self.read(min(CHUNK, n))
            n -= len(piece)
            yield piece


def _iso_entries(table: bytes) -> Iterator[Tuple[str, int, int, bool]]:
    """(name, start sector, size, is directory) for each record of an ISO 9660 directory."""
    pos = 0
    while pos + 33 <= len(table):
        n = table[pos]
        if n == 0:                                    # records never cross a sector: skip to the next one
            pos = (pos // SECTOR + 1) * SECTOR
            continue
        lba = struct.unpack_from("<I", table, pos + 2)[0]
        size = struct.unpack_from("<I", table, pos + 10)[0]
        flags, nlen = table[pos + 25], table[pos + 32]
        ident = table[pos + 33:pos + 33 + nlen]
        if ident not in (b"\0", b"\1"):
            name = ident.decode("latin-1").split(";")[0]
            if not flags & 2 and name.endswith(".") and "." not in name[:-1]:
                name = name[:-1]
            yield name, lba, size, bool(flags & 2)
        pos += n


def _rcf_members(dir_table: bytes, names: bytes, count: int, rcf_size: int) -> List[Tuple[str, int, int]]:
    """(name, offset, size) of each file in an .rcf, from its directory and names tables (rcf.py has
    the layout)."""
    # In name order: by where the data starts, and an empty file first when it starts where the next one does
    directory = sorted((struct.unpack_from("<3I", dir_table, 12 * i) for i in range(count)), key=lambda e: (e[1], e[2]))
    out, pos = [], 8
    for h, off, size in directory:
        if pos + 16 > len(names):
            raise RcfError("the names table is shorter than its directory")
        length = struct.unpack_from("<I", names, pos + 12)[0]
        if not (1 <= length <= 1024) or pos + 16 + length - 1 > len(names):
            raise RcfError(f"bad name length {length}")
        name = names[pos + 16:pos + 16 + length - 1].decode("latin-1")
        pos += 16 + length + 3
        if off + size > rcf_size:
            raise RcfError(f"{name}: data runs past the end of the archive")
        out.append((name, off, size))
    return out


def _member_path(rcf_path: str, name: str) -> str:
    inner = "/".join(p for p in name.replace("\\", "/").split("/") if p not in ("", ".", ".."))
    return f"{rcf_path}/{inner}"


class Sink:
    """Where a reader puts each file: file() stores the bytes and returns their SHA-1; same() records a
    file whose bytes were already stored (a disc can point two names at the same data)."""

    def file(self, path: str, size: int, chunks: Iterable[bytes]) -> str:
        raise NotImplementedError

    def same(self, path: str, size: int, sha: str) -> None:
        raise NotImplementedError


def read_disc(src: Source, sink: Sink, progress: Callable[[int], None], stop: Callable[[], bool],
              log: Log = print) -> None:
    """Every file on a disc image, with the .rcf archives on it unpacked, in one pass when the disc's
    tables come before what they describe (another pass picks up anything that came earlier)."""
    seq = [0]
    heap: List[tuple] = []
    state = {"xvd": False, "fs": src.fs}

    def push(start: int, task: tuple) -> None:
        seq[0] += 1
        heapq.heappush(heap, (start, seq[0], task))

    if src.fs == "xdvdfs":
        for base in GF.XDVDFS_BASES:
            push(base + 32 * SECTOR, ("xvd", base))
    else:
        push(16 * SECTOR, ("pvd",))

    def handle(r: _Forward, start: int, task: tuple) -> None:
        kind = task[0]
        if kind == "xvd":
            if state["xvd"]:
                return
            vol = GF._volume(r.read(SECTOR))
            if vol:
                state["xvd"] = True
                if vol[1]:
                    push(task[1] + vol[0] * SECTOR, ("xdir", task[1], "", vol[1]))
        elif kind == "pvd":
            pvd = r.read(SECTOR)
            if pvd[1:6] != b"CD001":
                raise RcfError("not a disc image the portal can read")
            push(struct.unpack_from("<I", pvd, 158)[0] * SECTOR, ("idir", "", struct.unpack_from("<I", pvd, 166)[0]))
        elif kind == "xdir":
            _, base, prefix, size = task
            for name, sector, fsize, attrs in GF._dir_entries(r.read(size)):
                if attrs & 0x10:
                    if fsize:
                        push(base + sector * SECTOR, ("xdir", base, prefix + name + "/", fsize))
                else:
                    file(base + sector * SECTOR, prefix + name, fsize)
        elif kind == "idir":
            _, prefix, size = task
            for name, lba, fsize, is_dir in _iso_entries(r.read(size)):
                if is_dir:
                    push(lba * SECTOR, ("idir", prefix + name + "/", fsize))
                else:
                    file(lba * SECTOR, prefix + name, fsize)
        elif kind == "rcf":
            _, path, size, depth = task
            head = r.read(60)
            if not head.startswith(RCF_MAGIC):
                done[(start, size)] = sink.file(path, size, _prepend(head, r.chunks(size - 60)))
                return
            (_u1, dir_off, _dir_size, names_off, names_size, _u2, count) = struct.unpack_from("<7I", head, 32)
            if not (0 < count < 1_000_000) or dir_off + 12 * count > size or names_off > size:
                log(f"      ! {path}: the archive's header doesn't make sense; kept as one file")
                done[(start, size)] = sink.file(path, size, _prepend(head, r.chunks(size - 60)))
                return
            arc = {"path": path, "start": start, "size": size, "count": count, "depth": depth}
            names_len = min(max(names_size, 8), size - names_off)
            push(start + dir_off, ("rcfdir", arc, 12 * count))
            push(start + names_off, ("rcfnames", arc, names_len))
        elif kind in ("rcfdir", "rcfnames"):
            _, arc, n = task
            arc[kind] = r.read(n)
            if "rcfdir" in arc and "rcfnames" in arc:
                try:
                    members = _rcf_members(arc["rcfdir"], arc["rcfnames"], arc["count"], arc["size"])
                except RcfError as e:
                    log(f"      ! {arc['path']}: {e}")
                    return
                for name, off, size in members:
                    file(arc["start"] + off, _member_path(arc["path"], name), size, arc["depth"] + 1)
        elif kind == "file":
            _, path, size = task
            done[(start, size)] = sink.file(path, size, r.chunks(size))

    def file(start: int, path: str, size: int, depth: int = 0) -> None:
        if size == 0:
            sink.same(path, 0, EMPTY_SHA)
        elif path.lower().endswith(".rcf") and size >= 60 and depth < NESTED_MAX:
            push(start, ("rcf", path, size, depth))
        else:
            push(start, ("file", path, size))

    done: Dict[Tuple[int, int], str] = {}      # (where, size) -> sha of a file already copied
    for pass_no in range(1, 6):
        if not heap:
            break
        later: List[tuple] = []
        if pass_no > 1:
            log(f"      reading the disc again for {len(heap):,} file(s) stored before their tables (pass {pass_no})")
        with _open_stream(src.path, src.member) as (f, seekable):
            r = _Forward(f, seekable, progress)
            while heap:
                if stop():
                    raise Stopped()
                start, n, task = heapq.heappop(heap)
                if task[0] == "xvd" and state["xvd"]:
                    continue                      # the Xbox file system is already found
                if task[0] in ("file", "rcf") and (start, task[2]) in done:
                    sink.same(task[1], task[2], done[(start, task[2])])
                    continue
                if start < r.pos:
                    later.append((start, n, task))
                    continue
                r.skip_to(start)
                handle(r, start, task)
        for item in later:
            heapq.heappush(heap, item)
        if src.fs == "xdvdfs" and not state["xvd"] and pass_no == 1:
            heap = []
            push(16 * SECTOR, ("pvd",))           # not an Xbox file system after all
            state["fs"] = "iso"
    if heap:
        raise RcfError(f"{len(heap)} file(s) could not be reached on the disc")
    if src.fs == "xdvdfs" and not state["xvd"] and state["fs"] == "xdvdfs":
        raise RcfError("no Xbox file system found on the disc image")


EMPTY_SHA = hashlib.sha1(b"").hexdigest()


def _prepend(head: bytes, rest: Iterable[bytes]) -> Iterator[bytes]:
    yield head
    yield from rest


def _rcf_file(arc_path: str, f, base: int, sink: Sink, stop: Callable[[], bool], log: Log, depth: int = 0) -> bool:
    """Unpack an .rcf that can be read anywhere (a file on disk), and the archives inside it. False if it
    isn't one."""
    try:
        arc = RcfArchive(f, base=base)
    except RcfError as e:
        log(f"      ! {arc_path}: {e}; kept as one file")
        return False
    for e in arc.entries:
        if stop():
            raise Stopped()
        member = _member_path(arc_path, e.name)
        if (e.name.lower().endswith(".rcf") and e.size >= 60 and depth + 1 < NESTED_MAX
                and _rcf_file(member, f, base + e.offset, sink, stop, log, depth + 1)):
            continue

        def chunks(e=e):
            left, off = e.size, e.offset
            while left > 0:
                piece = arc._read(off, min(CHUNK, left))
                if not piece:
                    raise EOFError(f"{e.name}: the archive ends early")
                off += len(piece)
                left -= len(piece)
                yield piece
        sink.file(member, e.size, chunks())
    return True


def _file_chunks(f) -> Iterator[bytes]:
    while True:
        piece = f.read(CHUNK)
        if not piece:
            return
        yield piece


def read_zip(src: Source, sink: Sink, progress: Callable[[int], None], stop: Callable[[], bool],
             log: Log = print) -> None:
    """Every file in a .zip of a game folder; one top folder they all share (like Scarface/) is left out."""
    with zipfile.ZipFile(src.path) as z:
        infos = sorted((i for i in z.infolist() if not i.is_dir()), key=lambda i: i.header_offset)
        tops = {i.filename.split("/", 1)[0] for i in infos}
        strip = len(tops) == 1 and all("/" in i.filename for i in infos)
        done = 0
        for info in infos:
            if stop():
                raise Stopped()
            name = info.filename.split("/", 1)[1] if strip else info.filename
            if name.lower().endswith(".rcf"):
                _zip_rcf(z, info, name, sink, stop, log)
            else:
                with z.open(info) as f:
                    sink.file(name, info.file_size, _file_chunks(f))
            done += info.file_size
            progress(done)


def read_folder(src: Source, sink: Sink, progress: Callable[[int], None], stop: Callable[[], bool],
                log: Log = print) -> None:
    """Every file in an installed game's folder."""
    done = 0
    for dirpath, dirs, files in os.walk(src.path):
        dirs.sort(key=str.lower)
        for fname in sorted(files, key=str.lower):
            if stop():
                raise Stopped()
            full = Path(dirpath) / fname
            rel = full.relative_to(src.path).as_posix()
            try:
                size = full.stat().st_size
                with open(full, "rb") as f:
                    if not (rel.lower().endswith(".rcf") and _rcf_file(rel, f, 0, sink, stop, log)):
                        f.seek(0)
                        sink.file(rel, size, _file_chunks(f))
            except OSError as e:
                log(f"      ! {rel}: {e}")
                continue
            done += size
            progress(done)


def _zip_rcf(z: zipfile.ZipFile, info: zipfile.ZipInfo, name: str, sink: Sink, stop: Callable[[], bool], log: Log) -> None:
    """An .rcf inside a .zip: copied to a temporary file (an archive needs reading out of order), unpacked."""
    with tempfile.TemporaryFile() as tmp:
        with z.open(info) as f:
            shutil.copyfileobj(f, tmp, CHUNK)
        if not _rcf_file(name, tmp, 0, sink, stop, log):
            tmp.seek(0)
            sink.file(name, info.file_size, _file_chunks(tmp))


# --------------------------------------------------------------------------- #
# The PC disc, read without installing
# --------------------------------------------------------------------------- #

def _pc_disc_root(path: Path) -> Optional[Dict[str, Tuple[Path, int, int]]]:
    """The files in the top folder of a disc image: NAME -> (image, where, size)."""
    try:
        with open(path, "rb") as f:
            f.seek(16 * SECTOR)
            pvd = f.read(SECTOR)
            if len(pvd) < SECTOR or pvd[1:6] != b"CD001":
                return None
            lba, size = struct.unpack_from("<I", pvd, 158)[0], struct.unpack_from("<I", pvd, 166)[0]
            if not 0 < size <= 1 << 20:
                return None
            f.seek(lba * SECTOR)
            table = f.read(size)
    except OSError:
        return None
    return {name.upper(): (path, start * SECTOR, fsize)
            for name, start, fsize, is_dir in _iso_entries(table) if not is_dir}


def _pc_folder_root(folder: Path) -> Dict[str, Tuple[Path, int, int]]:
    """The files in the top of a folder the PC disc was copied into (its subfolders are not read)."""
    out = {}
    try:
        for p in folder.iterdir():
            if p.is_file():
                out[p.name.upper()] = (p, 0, p.stat().st_size)
    except OSError:
        pass
    return out


def _pc_layout(files: Optional[Dict[str, Tuple[Path, int, int]]]) -> bool:
    return bool(files) and any(n.endswith(".MSI") for n in files) and "DATA1.CAB" in files


def _pc_cab_bytes(files: Dict[str, Tuple[Path, int, int]]) -> int:
    return sum(size for n, (_p, _o, size) in files.items() if n.startswith("DATA") and n.endswith(".CAB"))


def _patch_rcfs(patch: Path) -> List[Tuple[str, int]]:
    """The .rcf archives inside the official patch (1.00.2 adds patch01.rcf to the game folder)."""
    try:
        with zipfile.ZipFile(patch) as z:
            return [(i.filename, i.file_size) for i in z.infolist()
                    if i.filename.lower().endswith(".rcf") and not i.is_dir()]
    except (OSError, zipfile.BadZipFile):
        return []


def _msi_layout(msi: "MR.Msi") -> Tuple[Dict[str, str], List[str]]:
    """From the installer database: each cabinet entry's name -> where the file goes in the game folder,
    and the cabinets in disk order (a name starting with # is a cabinet stored inside the .msi)."""
    dirs = MR.directory_paths(msi.table("Directory"))
    comp_dir = {r.get("Component"): r.get("Directory_") for r in msi.table("Component")}
    files = msi.table("File")
    root = dirs.get("INSTALLDIR")
    if root is None:                     # no INSTALLDIR: the folder most files go to
        counts: Dict[PurePath, int] = {}
        for r in files:
            d = dirs.get(comp_dir.get(r.get("Component_")) or "", PurePath())
            counts[d] = counts.get(d, 0) + 1
        root = max(counts, key=counts.get) if counts else PurePath()
    names = {}
    for r in files:
        d = dirs.get(comp_dir.get(r.get("Component_")) or "", root)
        try:
            rel = PurePath(d).relative_to(root)
        except ValueError:
            rel = PurePath("Other installer folders") / d
        names[r["File"]] = PurePosixPath(*rel.parts, MR.long_name(r.get("FileName") or r["File"])).as_posix()
    cabs = [r["Cabinet"] for r in sorted(msi.table("Media"), key=lambda r: r.get("DiskId") or 0) if r.get("Cabinet")]
    return names, cabs


class _ChunkReader:
    """A file object over a stream of byte chunks (a cabinet folder's data), read front to back."""

    def __init__(self, chunks: Iterable[bytes]):
        self._it, self._buf, self._off = iter(chunks), b"", 0

    def read(self, n: int = -1) -> bytes:
        out = bytearray()
        while n < 0 or len(out) < n:
            if self._off >= len(self._buf):
                try:
                    self._buf, self._off = next(self._it), 0
                except StopIteration:
                    break
                continue
            take = len(self._buf) - self._off if n < 0 else min(n - len(out), len(self._buf) - self._off)
            out += self._buf[self._off:self._off + take]
            self._off += take
        return bytes(out)


def _rcf_forward(path: str, size: int, r: _Forward, sink: Sink, stop: Callable[[], bool], log: Log,
                 depth: int = 0) -> None:
    """Unpack an .rcf that can only be read front to back (it comes out of a cabinet), and the archives
    inside it: its header and tables come first, then the files in order of where they are."""
    start = r.pos
    head = r.read(min(60, size))
    bad = len(head) < 60 or not head.startswith(RCF_MAGIC)
    if not bad:
        (_u1, dir_off, _ds, names_off, names_size, _u2, count) = struct.unpack_from("<7I", head, 32)
        bad = not (0 < count < 1_000_000) or min(dir_off, names_off) < 60 or dir_off + 12 * count > size or names_off > size
    if bad:
        sink.file(path, size, _prepend(head, r.chunks(size - len(head))))
        return
    names_len = min(max(names_size, 8), size - names_off)
    tables = {}
    for off, kind, n in sorted([(dir_off, "dir", 12 * count), (names_off, "names", names_len)]):
        if start + off < r.pos:
            raise RcfError(f"{path}: its tables overlap")
        r.skip_to(start + off)
        tables[kind] = r.read(n)
    members = _rcf_members(tables["dir"], tables["names"], count, size)
    done: Dict[Tuple[int, int], str] = {}
    missed = 0
    for name, off, msize in members:
        if stop():
            raise Stopped()
        member = _member_path(path, name)
        if (off, msize) in done:
            sink.same(member, msize, done[(off, msize)])
        elif msize == 0:
            sink.same(member, 0, EMPTY_SHA)
        elif start + off < r.pos:
            missed += 1                  # stored inside the tables: can't happen in the game's archives
        else:
            r.skip_to(start + off)
            if member.lower().endswith(".rcf") and msize >= 60 and depth + 1 < NESTED_MAX:
                _rcf_forward(member, msize, r, sink, stop, log, depth + 1)
            else:
                done[(off, msize)] = sink.file(member, msize, r.chunks(msize))
    if missed:
        log(f"      ! {path}: {missed} file(s) stored before the archive's tables were left out")
    r.skip_to(start + size)


def read_pc_disc(src: Source, sink: Sink, progress: Callable[[int], None], stop: Callable[[], bool],
                 log: Log = print) -> None:
    """The PC game off its disc image (or a copy of the disc in a folder), without installing it."""
    files = _pc_disc_root(src.path) if src.path.is_file() else _pc_folder_root(src.path)
    if not _pc_layout(files):
        raise RcfError(f"{src.path.name}: no installer database and Data1.cab in its top folder")
    with contextlib.ExitStack() as stack:
        def open_at(key: str) -> Tuple[BinaryIO, int, int]:
            path, off, size = files[key]
            return stack.enter_context(open(path, "rb")), off, size

        msis = sorted((n for n in files if n.endswith(".MSI")), key=lambda n: ("SCARFACE" not in n, n))
        f, off, size = open_at(msis[0])
        f.seek(off)
        msi = MR.Msi(f.read(size))
        names, cabs = _msi_layout(msi)
        volumes = []
        for cab in cabs:
            if cab.startswith("#"):
                volumes.append((io.BytesIO(msi.streams.get(cab[1:], b"")), 0, cab[1:]))
                continue
            if cab.upper() not in files:
                raise RcfError(f"{cab} is not on the disc")
            fo, at, _size = open_at(cab.upper())
            volumes.append((fo, at, cab))
        cabset = CAB.CabSet(volumes)
        moved = [0]

        def advance(n: int) -> None:
            moved[0] += n
            progress(moved[0])

        for folder in range(len(cabset.pieces)):
            r = _Forward(_ChunkReader(cabset.chunks(folder, advance)), False, lambda pos: None)
            done: Dict[Tuple[int, int], str] = {}
            for entry in cabset.folder_files(folder):
                if stop():
                    raise Stopped()
                path = names.get(entry.name, entry.name)
                if (entry.offset, entry.size) in done:
                    sink.same(path, entry.size, done[(entry.offset, entry.size)])
                    continue
                if entry.offset < r.pos:
                    raise CAB.CabError(f"{entry.name} overlaps the file before it")
                r.skip_to(entry.offset)
                if path.lower().endswith(".rcf") and entry.size >= 60:
                    _rcf_forward(path, entry.size, r, sink, stop, log)
                else:
                    done[(entry.offset, entry.size)] = sink.file(path, entry.size, r.chunks(entry.size))
    if src.extra:                        # patch01.rcf from the 1.00.2 patch goes in the game folder too
        with zipfile.ZipFile(src.extra) as z:
            for info in z.infolist():
                if info.filename.lower().endswith(".rcf") and not info.is_dir():
                    if stop():
                        raise Stopped()
                    _zip_rcf(z, info, info.filename.rsplit("/", 1)[-1], sink, stop, log)
                    moved[0] += info.file_size
                    progress(moved[0])


READERS = {"disc": read_disc, "zip": read_zip, "folder": read_folder, "pcdisc": read_pc_disc}


# --------------------------------------------------------------------------- #
# Storing by content, then placing
# --------------------------------------------------------------------------- #

class Store:
    """Files kept by the SHA-1 of their bytes, so one that several versions share is written once."""

    def __init__(self, root: Path):
        self.root = root
        (root / "tmp").mkdir(parents=True, exist_ok=True)

    def path(self, sha: str) -> Path:
        return self.root / sha[:2] / sha

    def has(self, sha: str) -> bool:
        return os.path.isfile(_os(self.path(sha)))

    def put(self, chunks: Iterable[bytes], keep: Callable[[str], bool] = lambda sha: True) -> Tuple[str, int]:
        """Store a file's bytes; with keep, only when keep(sha) says it's wanted (the hash is known only at
        the end, so the bytes go to a temporary file first)."""
        h, n = hashlib.sha1(), 0
        fd, tmp = tempfile.mkstemp(dir=_os(self.root / "tmp"))
        try:
            with os.fdopen(fd, "wb") as out:
                for piece in chunks:
                    h.update(piece)
                    out.write(piece)
                    n += len(piece)
            sha = h.hexdigest()
            dest = self.path(sha)
            if os.path.isfile(_os(dest)) or not keep(sha):
                os.remove(tmp)
            else:
                os.makedirs(_os(dest.parent), exist_ok=True)
                os.replace(tmp, _os(dest))
            return sha, n
        except BaseException:
            try:
                os.remove(tmp)
            except OSError:
                pass
            raise


class _Collect(Sink):
    """Stores each file (the ones keep(sha) wants), and notes what sniff() says about it: [path, size, sha, facts]."""

    def __init__(self, store: Store, files: List[list], status: dict, keep: Callable[[str], bool] = lambda sha: True):
        self.store, self.files, self.status, self.keep = store, files, status, keep
        self.facts: Dict[str, Optional[dict]] = {}

    def file(self, path: str, size: int, chunks: Iterable[bytes]) -> str:
        want = _sniff_wants(path, size)
        seen = bytearray()

        def tee():
            for piece in chunks:
                if want < 0:
                    seen.extend(piece)
                elif len(seen) < want:
                    seen.extend(piece[:want - len(seen)])
                yield piece
        sha, n = self.store.put(tee() if want else chunks, self.keep)
        facts = sniff(path, bytes(seen)) if want else None
        self.facts[sha] = facts
        self.files.append([path, n, sha, facts])
        self.status["files"] += 1
        return sha

    def same(self, path: str, size: int, sha: str) -> None:
        if sha == EMPTY_SHA and not self.store.has(sha):
            self.store.put(())
        self.files.append([path, size, sha, self.facts.get(sha)])
        self.status["files"] += 1


class _ListSink(Sink):
    """Only lists each file: [path, size, sha, facts], with nothing written (for comparing versions)."""

    def __init__(self, files: List[list], status: dict):
        self.files, self.status = files, status
        self.facts: Dict[str, Optional[dict]] = {}

    def file(self, path: str, size: int, chunks: Iterable[bytes]) -> str:
        want = _sniff_wants(path, size)
        seen = bytearray()
        h, n = hashlib.sha1(), 0
        for piece in chunks:
            h.update(piece)
            n += len(piece)
            if want < 0:
                seen.extend(piece)
            elif len(seen) < want:
                seen.extend(piece[:want - len(seen)])
        sha = h.hexdigest()
        facts = sniff(path, bytes(seen)) if want else None
        self.facts[sha] = facts
        self.files.append([path, n, sha, facts])
        self.status["files"] += 1
        return sha

    def same(self, path: str, size: int, sha: str) -> None:
        self.files.append([path, size, sha, self.facts.get(sha)])
        self.status["files"] += 1


CATALOGS = "catalogs"


def list_versions(versions: List[str], bin_dir: Path = BIN_DIR, status: Optional[Status] = None,
                  stop: Callable[[], bool] = lambda: False, log: Log = print,
                  sources: Optional[Dict[str, Source]] = None) -> Dict[str, List[list]]:
    """Read the chosen versions and list their files ([path, size, sha, facts]) without copying anything.
    The lists are kept in binaries/game_files/catalogs/ and reused while the game files stay the same."""
    status = status if status is not None else new_status()
    if sources is None:
        sources, _notes = find_sources(bin_dir)
    chosen = [v for v in VERSIONS if v in versions and v in sources]
    folder = out_dir(bin_dir) / CATALOGS
    folder.mkdir(parents=True, exist_ok=True)
    status.update(running=True, phase="listing", error="", message="", versions=chosen, started=time.time(),
                  finished=0, done=0, files=0, total=sum(sources[v].size for v in chosen))
    out: Dict[str, List[list]] = {}
    done_before = 0
    for v in chosen:
        src = sources[v]
        path = folder / f"catalog-{v}.json"
        try:
            with open(path, encoding="utf-8") as f:
                cat = json.load(f)
            if cat.get("complete") and cat.get("signature") == src.signature():
                out[v] = cat["files"]
                log(f"[=] {src.label}: already listed ({len(out[v]):,} files)")
                done_before += src.size
                continue
        except (OSError, ValueError):
            pass
        log(f"[*] {src.label}: listing {src.name} ...")
        status.update(version=v, label=src.label, message=f"Listing {src.label}")
        files: List[list] = []

        def progress(pos: int, base=done_before, cap=src.size) -> None:
            status["done"] = base + min(pos, cap) if cap else base

        READERS[src.kind](src, _ListSink(files, status), progress, stop, log)
        _write_json(path, {"signature": src.signature(), "complete": True, "files": files})
        out[v] = files
        done_before += src.size
        log(f"    + {len(files):,} files")
    status.update(running=False, phase="done", finished=time.time(), message="Done")
    return out


def _safe_rel(place: str) -> bool:
    parts = place.split("/")
    return all(p not in ("", ".", "..") and ":" not in p and "\\" not in p for p in parts)


def _row(row: list) -> Tuple[str, int, str, Optional[dict]]:
    """A catalog row: [path, size, sha] or [path, size, sha, facts]."""
    return row[0], row[1], row[2], (row[3] if len(row) > 3 else None)


def plan(catalogs: Dict[str, List[list]], mode: str, folders: str = "game"
         ) -> Tuple[Dict[str, List[list]], List[Tuple[str, str]]]:
    """Where every file goes. Returns (per version: [path, size, sha, status, placed at, facts, written],
    and the (sha, place) list to write). Status: 'shared' when another version has the same bytes,
    'changed' when another version has that file with different bytes, 'only' otherwise. 'written' is 1
    for the row whose bytes are the ones at its place (with no duplicates, the first version's copy of a
    shared file; for Best, the best version's)."""
    order = [v for v in VERSIONS if v in catalogs]
    holders: Dict[str, List[str]] = {}
    key_versions: Dict[str, set] = {}
    for v in order:
        for row in catalogs[v]:
            path, _size, sha, _facts = _row(row)
            if v not in holders.setdefault(sha, []):
                holders[sha].append(v)
            key_versions.setdefault(compare_key(path), set()).add(v)
    taken: Dict[str, str] = {}             # lower-case place -> sha (Windows folders ignore case)
    places: List[Tuple[str, str]] = []

    def where(top: str, path: str, facts: Optional[dict]) -> str:
        if folders == "type":
            named = sound_name(facts) if path.lower().endswith(".rsd") else ""
            return f"{top}/{KIND_LABELS[kind_of(path, facts)]}/{named or path}"
        return f"{top}/{path}"

    def take(sha: str, place: str) -> Optional[str]:
        if not _safe_rel(place):
            return ""                      # a name that would leave the folder: never written
        low = place.lower()
        if low in taken:
            return place if taken[low] == sha else None
        taken[low] = sha
        places.append((sha, place))
        return place

    def take_free(sha: str, place: str) -> str:
        got = take(sha, place)
        n = 2
        while got is None:
            stem, dot, ext = place.rpartition(".")
            alt = f"{stem} ({n}).{ext}" if dot and "/" not in ext else f"{place} ({n})"
            got = take(sha, alt)
            n += 1
        return got

    result: Dict[str, List[list]] = {v: [] for v in order}
    for v in order:
        for row in catalogs[v]:
            path, size, sha, facts = _row(row)
            owners = holders[sha]
            if len(owners) > 1:
                status = "shared"
            elif len(key_versions[compare_key(path)]) > 1:
                status = "changed"
            else:
                status = "only"
            placed, written = "", 0
            if mode == "every":
                placed, written = take_free(sha, where(LABELS[v], path, facts)), 1
            elif mode == "unique":
                if status == "only":
                    placed, written = take_free(sha, where(exclusive(v), path, facts)), 1
                elif status == "changed":
                    placed, written = take_free(sha, where(LABELS[v], path, facts)), 1
                elif v == owners[0]:
                    placed = take(sha, where(SHARED, path, facts))
                    if placed is None:
                        placed = take_free(sha, where(LABELS[v], path, facts))
                    written = 1
            result[v].append([path, size, sha, status, placed, facts, written])
    if mode in ("best", "pc"):
        groups: Dict[str, List[Tuple[str, int]]] = {}
        for v in order:
            for i, row in enumerate(result[v]):
                groups.setdefault(compare_key(row[0]), []).append((v, i))
        sha_place: Dict[str, str] = {}

        def score(c: Tuple[str, int]) -> tuple:
            v, i = c
            path, size, _sha, _st, _pl, facts, _w = result[v][i]
            first = (v == "pc",) if mode == "pc" else ()       # PC first: the PC's copy whenever it has one
            return first + (quality(facts), _is_patch(path), -PREFER.index(v) if v in PREFER else -99, size)
        for _key, cands in groups.items():
            v, i = max(cands, key=score)
            row = result[v][i]
            only = all(result[cv][ci][3] == "only" for cv, ci in cands)
            if mode == "pc":
                top = LABELS["pc"] if v == "pc" else exclusive(v) if only else NOT_ON_PC
            else:
                top = exclusive(v) if only else BEST
            if row[2] in sha_place:                    # the same bytes are already there under another name
                place = sha_place[row[2]]
            else:
                place = take_free(row[2], where(top, game_path(row[0]), row[5]))
                sha_place[row[2]] = place
                row[6] = 1 if place else 0                 # a name that would leave the folder: never written
            for cv, ci in cands:
                result[cv][ci][4] = place
    elif mode == "unique":
        first_place: Dict[str, str] = {}
        for sha, place in places:
            if place:
                first_place.setdefault(sha, place)
        for v in order:
            for row in result[v]:
                if not row[4]:
                    row[4] = first_place.get(row[2], "")
    return result, places


# --------------------------------------------------------------------------- #
# A run
# --------------------------------------------------------------------------- #

INDEX_JSON = ".index.json"
WORK = ".work"


def out_dir(bin_dir: Path = BIN_DIR) -> Path:
    return bin_dir / OUT_NAME


def load_index(out: Path) -> Optional[dict]:
    try:
        with open(out / INDEX_JSON, encoding="utf-8") as f:
            data = json.load(f)
        return data if isinstance(data, dict) and "versions" in data else None
    except (OSError, ValueError):
        return None


PLACING = "placing.json"              # in .work/ while files are being put in place: what goes where
PLACED = "placed.txt"                 # ... and how many of those are done


class There:
    """What the last copy left in the folder: the files still as they were copied (by place), the ones
    changed since (a mod?), and how many are gone."""

    def __init__(self) -> None:
        self.good: Dict[str, Tuple[str, Path]] = {}     # place -> (sha, path), still as copied
        self.changed: Dict[str, Tuple[Path, str, Optional[int]]] = {}   # place -> (path, sha copied, stamp)
        self.by_sha: Dict[str, Path] = {}               # sha -> a good file with those bytes
        self.missing = 0                                # places of the last copy with nothing there
        self.cut = False                                # a copy was cut off while putting files in place

    def _good(self, place: str, sha: str, p: Path) -> None:
        self.good[place] = (sha, p)
        self.changed.pop(place, None)
        self.by_sha.setdefault(sha, p)


def _size(p: Optional[Path]) -> int:
    try:
        return os.stat(_os(p)).st_size if p is not None and os.path.isfile(_os(p)) else -1
    except OSError:
        return -1


def _place_path(out: Path, place: str) -> Optional[Path]:
    """Where a place from a copy's index is (they were checked to stay in the folder when they were made)."""
    return out.joinpath(*place.split("/")) if place and _safe_rel(place) else None


def what_is_there(out: Path, index: Optional[dict]) -> There:
    """Look at every file the last copy wrote (one stat each). A copy that was cut off while putting files
    in place left a list of where it was putting them: what it had put there counts as copied too."""
    there = There()
    work = out / WORK
    try:
        with open(work / PLACING, encoding="utf-8") as f:
            cut = json.load(f).get("places", [])
        there.cut = True
    except (OSError, ValueError, AttributeError):
        cut = []
    try:
        done = int((work / PLACED).read_text().strip() or 0)
    except (OSError, ValueError):
        done = 0
    cut_at: Dict[str, Tuple[str, int]] = {}
    for i, (sha, place, size) in enumerate(cut):
        p = _place_path(out, place)
        if i < done:                              # surely put there: it's the new file
            if _size(p) == size:
                there._good(place, sha, p)
        else:
            cut_at[place] = (sha, size)
    stamps = (index or {}).get("stamps", {})
    for info in (index or {}).get("versions", {}).values():
        for row in info.get("files", []):
            placed = row[4]
            written = row[6] if len(row) > 6 else 1       # older indexes: every placed row was written
            if not placed or not written or placed in there.good or placed in there.changed:
                continue
            p = _place_path(out, placed)
            try:
                st = os.stat(_os(p)) if p is not None else None
            except OSError:
                st = None
            if st is None:
                if placed not in cut_at:
                    there.missing += 1
                continue
            if st.st_size == row[1] and (placed not in stamps or int(st.st_mtime) == stamps[placed]):
                there._good(placed, row[2], p)
            elif placed in cut_at and st.st_size == cut_at[placed][1]:
                there._good(placed, cut_at[placed][0], p)          # the cut-off copy got this far
            else:
                there.changed[placed] = (p, row[2], stamps.get(placed))
    for place, (sha, size) in cut_at.items():
        if place not in there.good and place not in there.changed:
            p = _place_path(out, place)
            if _size(p) == size:
                there._good(place, sha, p)
    return there


def up_to_date(index: Optional[dict], there: There, sources: Dict[str, Source], versions: List[str],
               mode: str, folders: str) -> bool:
    """The last copy was made with these choices from these same game files, and every file is still there
    (files changed since count as there: they're yours)."""
    return same_settings(index, sources, versions, mode, folders) and not there.cut and not there.missing


def same_settings(index: Optional[dict], sources: Dict[str, Source], versions: List[str], mode: str,
                  folders: str) -> bool:
    """The last copy was made with these choices, from these same game files."""
    if not index or index.get("mode") != mode or index.get("folders", "game") != folders:
        return False
    had = index.get("versions", {})
    if set(had) != set(versions):
        return False
    return all(v in sources and had[v].get("signature") == sources[v].signature() for v in versions)


def same_choices(index: Optional[dict], sources: Dict[str, Source]) -> Optional[dict]:
    """What the last copy was made with, for the portal's buttons, and whether the game files it came from
    are still the same."""
    if not index:
        return None
    had = index.get("versions", {})
    return {"versions": [v for v in VERSIONS if v in had], "mode": index.get("mode", ""),
            "folders": index.get("folders", "game"), "created": index.get("created", ""),
            "current": all(v in sources and had[v].get("signature") == sources[v].signature() for v in had)}


def _write_json(path: Path, data) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    tmp = path.with_suffix(path.suffix + ".tmp")
    with open(tmp, "w", encoding="utf-8") as f:
        json.dump(data, f, separators=(",", ":"))
    os.replace(tmp, path)


def _catalog_from_index(index: Optional[dict], src: Source) -> Optional[List[list]]:
    """A version's list of files from the last copy, if it was made from these same game files."""
    info = (index or {}).get("versions", {}).get(src.version)
    if not info or info.get("signature") != src.signature():
        return None
    return [[r[0], r[1], r[2], r[5] if len(r) > 5 else None] for r in info.get("files", [])]


def _catalog_read(work: Path, src: Source) -> Optional[List[list]]:
    """A version's list of files from a copy that stopped after reading it."""
    try:
        with open(work / f"catalog-{src.version}.json", encoding="utf-8") as f:
            cat = json.load(f)
    except (OSError, ValueError):
        return None
    if not cat.get("complete") or cat.get("signature") != src.signature():
        return None
    return cat.get("files", [])


def _readers_for(missing: set, catalogs: Dict[str, List[list]], sources: Dict[str, Source]) -> List[str]:
    """The fewest versions to read again for the files no copy has any more (the smaller disc on a tie)."""
    shas = {v: {r[2] for r in rows} for v, rows in catalogs.items()}
    left, pick = set(missing), []
    while left:
        v = max(shas, key=lambda v: (len(left & shas[v]), -sources[v].size))
        if not left & shas[v]:
            break
        pick.append(v)
        left -= shas[v]
    return pick


class Status(dict):
    """What the run is doing, for the portal's progress bar (a plain dict the server sends as JSON)."""


def new_status() -> Status:
    return Status(running=False, phase="", version="", label="", done=0, total=0, files=0,
                  message="", error="", started=0, finished=0, mode="", versions=[], placed=0, to_place=0)


def run(versions: List[str], mode: str, bin_dir: Path = BIN_DIR, status: Optional[Status] = None,
        stop: Callable[[], bool] = lambda: False, log: Log = print,
        sources: Optional[Dict[str, Source]] = None, folders: str = "game") -> dict:
    """Read the chosen versions and write them out in the chosen layout. Returns the index.

    The last copy stays as it is while the game is read: only at the end, when every file is at hand, are
    files moved, and that part can't be stopped halfway. Files already where they belong are left alone,
    and only what no copy has any more is read from the game again."""
    if mode not in MODES:
        raise ValueError(f"mode must be one of {MODES}")
    if folders not in FOLDERS:
        raise ValueError(f"folders must be one of {FOLDERS}")
    status = status if status is not None else new_status()
    if sources is None:
        sources, _notes = find_sources(bin_dir)
    chosen = [v for v in VERSIONS if v in versions and v in sources]
    if not chosen:
        raise ValueError("none of those versions were found in binaries/")
    out = out_dir(bin_dir)
    work = out / WORK
    out.mkdir(parents=True, exist_ok=True)
    status.update(running=True, phase="preparing", error="", message="Looking at your last copy", mode=mode,
                  versions=chosen, started=time.time(), finished=0, done=0, files=0, placed=0, to_place=0, total=0)
    old = load_index(out)
    there = what_is_there(out, old)
    if up_to_date(old, there, sources, chosen, mode, folders):
        log("[=] Already copied with these choices, and every file is still there: nothing to do.")
        status.update(running=False, phase="done", finished=time.time(), files=sum(
            len(i.get("files", [])) for i in old["versions"].values()), message="Already copied")
        return old
    store = Store(work / "store")

    def read(vs: List[str], keep: Callable[[str], bool]) -> None:
        status["total"] += sum(sources[v].size for v in vs)
        for v in vs:
            if stop():
                raise Stopped()
            src = sources[v]
            status.update(phase="reading", version=v, label=src.label, message=f"Reading {src.label} from {src.name}")
            log(f"[*] {src.label}: reading {src.name} ...")
            files: List[list] = []
            base = status["done"]

            def progress(pos: int, base=base, cap=src.size) -> None:
                status["done"] = base + min(pos, cap) if cap else base

            READERS[src.kind](src, _Collect(store, files, status, keep), progress, stop, log)
            _write_json(work / f"catalog-{v}.json", {"signature": src.signature(), "complete": True, "files": files})
            catalogs[v] = files
            status["done"] = base + src.size
            log(f"    + {len(files):,} files")

    # 1. Each version's list of files: from the last copy, from a copy that stopped, or read now
    catalogs: Dict[str, List[list]] = {}
    for v in chosen:
        cat = _catalog_from_index(old, sources[v]) or _catalog_read(work, sources[v])
        if cat is not None:
            log(f"[=] {sources[v].label}: already read ({len(cat):,} files)")
            catalogs[v] = cat
    read([v for v in chosen if v not in catalogs], lambda sha: sha not in there.by_sha)

    # 2. Where everything goes, and the files no copy has any more: read from the fewest versions
    def unavailable(places: List[Tuple[str, str]]) -> set:
        stays = _yours(there, places)
        return {sha for sha, p in places if p not in stays and sha not in there.by_sha and not store.has(sha)}

    rows, places = plan(catalogs, mode, folders)
    missing = unavailable(places)
    if missing:
        again = _readers_for(missing, catalogs, sources)
        log(f"[*] {len(missing):,} file(s) aren't in the folder any more: reading {', '.join(sources[v].label for v in again)} again")
        read(again, lambda sha: sha in missing)
        rows, places = plan(catalogs, mode, folders)
        lost = unavailable(places)
        if lost:
            raise RuntimeError(f"{len(lost):,} file(s) couldn't be found in the game any more")
    if stop():
        raise Stopped()

    # 3. Everything in its place: from here on there is no stopping halfway
    status.update(phase="placing", version="", label="", message="Putting every file in its place",
                  files=sum(len(c) for c in catalogs.values()))
    index = _put_in_place(out, store, rows, places, there, sources, mode, folders, log, status)
    shutil.rmtree(_os(work), ignore_errors=True)
    status.update(running=False, phase="done", finished=time.time(), message="Done")
    return index


def _yours(there: There, places: List[Tuple[str, str]]) -> Dict[str, Optional[int]]:
    """The files you changed that stay where they are: the file they were made from still goes there."""
    new_at = dict((place, sha) for sha, place in places)
    return {place: stamp for place, (_p, sha, stamp) in there.changed.items() if new_at.get(place) == sha}


def _aside(out: Path, place: str, p: Path) -> bool:
    """Move a file out of the way, into Changed by you/, without covering one already there."""
    dest = safe_output_path(out / CHANGED_BY_YOU, place)
    if dest is None:
        return False
    n, cand = 2, dest
    while os.path.exists(_os(cand)):
        stem, dot, ext = dest.name.rpartition(".")
        cand = dest.with_name(f"{stem} ({n}).{ext}" if dot else f"{dest.name} ({n})")
        n += 1
    os.makedirs(_os(cand.parent), exist_ok=True)
    os.replace(_os(p), _os(cand))
    return True


def _put_in_place(out: Path, store: Store, rows: Dict[str, List[list]], places: List[Tuple[str, str]],
                  there: There, sources: Dict[str, Source], mode: str, folders: str, log: Log,
                  status: Status) -> dict:
    """Move the files into the new layout. What is already where it belongs stays; the last copy's other
    files go back to the store (or away, if nothing needs them); files you changed go to Changed by you/.
    A list of what goes where is kept in .work/ until the end, so a copy cut off here (the portal closed,
    the computer off) carries on next time without reading the game again."""
    work = out / WORK
    sizes = {r[2]: r[1] for v in rows for r in rows[v]}
    _write_json(work / PLACING, {"places": [[sha, place, sizes.get(sha, 0)] for sha, place in places]})
    (work / PLACED).write_text("0")
    new_at = dict((place, sha) for sha, place in places)
    keep = {place for place, (sha, _p) in there.good.items() if new_at.get(place) == sha}
    yours = _yours(there, places)
    first: Dict[str, Path] = {}
    for place in keep:
        first.setdefault(there.good[place][0], there.good[place][1])
    moved_aside = 0
    for place, (p, _sha, _stamp) in there.changed.items():
        if place in yours:
            continue
        try:
            moved_aside += _aside(out, place, p)
        except OSError:
            pass
    for place, (sha, p) in there.good.items():
        if place in keep:
            continue
        try:
            if sha in sizes and sha not in first and not store.has(sha):
                os.makedirs(_os(store.path(sha).parent), exist_ok=True)
                os.replace(_os(p), _os(store.path(sha)))
            else:
                os.remove(_os(p))
        except OSError:
            pass
    status.update(placed=0, to_place=len(places))
    stamps: Dict[str, int] = {}
    reused = 0
    for i, (sha, place_rel) in enumerate(places):
        dest = safe_output_path(out, place_rel)
        if dest is None:
            log(f"      ! skipped a file with an unsafe name: {place_rel!r}")
            continue
        if place_rel in yours:
            if yours[place_rel] is not None:
                stamps[place_rel] = yours[place_rel]           # still seen as changed by you next time
        else:
            if place_rel in keep:
                reused += 1
            else:
                if os.path.isfile(_os(dest)):          # not one of ours: kept, out of the way
                    moved_aside += _aside(out, place_rel, dest)
                os.makedirs(_os(dest.parent), exist_ok=True)
                if sha in first:
                    shutil.copyfile(_os(first[sha]), _os(dest))
                else:
                    os.replace(_os(store.path(sha)), _os(dest))
                    first[sha] = dest
            try:
                stamps[place_rel] = int(os.stat(_os(dest)).st_mtime)
            except OSError:
                pass
        if (i + 1) % 500 == 0 or i + 1 == len(places):
            status["placed"] = i + 1
            (work / PLACED).write_text(str(i + 1))
    if moved_aside:
        log(f"    {moved_aside:,} file(s) you changed or added were moved to {CHANGED_BY_YOU}/")
    if yours:
        log(f"    {len(yours):,} file(s) you changed were left as they are")
    if reused:
        log(f"    {reused:,} file(s) were already in place")
    _remove_empty_folders(out)
    for f in out.glob("INDEX - *.txt"):
        try:
            f.unlink()
        except OSError:
            pass
    index = {
        "format": "scarface-game-files", "version": 2, "mode": mode, "folders": folders,
        "created": time.strftime("%Y-%m-%d %H:%M"),
        "stamps": stamps,
        "versions": {v: {"label": LABELS[v], "source": sources[v].name, "signature": sources[v].signature(),
                         "files": rows[v]} for v in rows},
    }
    _write_json(out / INDEX_JSON, index)
    write_readmes(out, index)
    for f in (PLACING, PLACED):
        try:
            (work / f).unlink()
        except OSError:
            pass
    return index


def _remove_empty_folders(out: Path) -> None:
    """The layout folders a copy left empty (never Changed by you/ or anything else of yours)."""
    for name in [SHARED, BEST, NOT_ON_PC] + list(LABELS.values()) + [exclusive(v) for v in LABELS]:
        top = out / name
        if top.is_dir():
            for dirpath, _dirs, _files in sorted(os.walk(_os(top)), key=lambda t: -len(t[0])):
                try:
                    os.rmdir(dirpath)
                except OSError:
                    pass



# --------------------------------------------------------------------------- #
# Summaries and the index files people read
# --------------------------------------------------------------------------- #

def _facts(row: list) -> Optional[dict]:
    return row[5] if len(row) > 5 else None


def _written(row: list) -> bool:
    return bool(row[6]) if len(row) > 6 else bool(row[4])


def summary(index: Optional[dict]) -> Optional[dict]:
    """Counts per version, per status and per kind of file, for the portal. With the Best layout, also how
    many of the files in Best/ came from each version."""
    if not index:
        return None
    mode = index.get("mode")
    out = {"mode": mode, "mode_label": MODE_LABELS.get(mode, ""), "folders": index.get("folders", "game"),
           "folders_label": FOLDER_LABELS.get(index.get("folders", "game"), ""),
           "created": index.get("created"), "versions": {}}
    best_total = 0
    for v, info in index.get("versions", {}).items():
        files = info.get("files", [])
        s = {"label": info.get("label", LABELS.get(v, v)), "source": info.get("source", ""),
             "files": len(files), "bytes": sum(r[1] for r in files),
             "only": 0, "changed": 0, "shared": 0, "own_bytes": 0, "kinds": {}, "picked": 0}
        for row in files:
            path, size, _sha, st = row[:4]
            s[st] += 1
            if mode in ("best", "pc") and _written(row):
                s["picked"] += 1
            if st != "shared":
                s["own_bytes"] += size
                k = s["kinds"].setdefault(kind_of(path, _facts(row)), {"only": 0, "changed": 0})
                k[st] += 1
        best_total += s["picked"]
        out["versions"][v] = s
    if mode == "best":
        out["best"] = {"files": best_total, "from": {v: x["picked"] for v, x in out["versions"].items()}}
    elif mode == "pc":
        out["pc_first"] = {"files": best_total, "from": {v: x["picked"] for v, x in out["versions"].items()}}
    return out


def list_files(index: Optional[dict], version: str, status: str = "", kind: str = "", query: str = "",
               offset: int = 0, limit: int = 200) -> dict:
    """A page of one version's files, for the portal's list. status 'picked': the ones this version gave
    to the Best (or PC-first) layout."""
    rows = ((index or {}).get("versions", {}).get(version) or {}).get("files", [])
    q = query.strip().lower()
    best = (index or {}).get("mode") in ("best", "pc")
    hits = [r for r in rows
            if (not status or r[3] == status or (status == "own" and r[3] != "shared")
                or (status == "picked" and best and _written(r)))
            and (not kind or kind_of(r[0], _facts(r)) == kind)
            and (not q or q in r[0].lower() or q in sound_name(_facts(r)).lower())]
    page = hits[offset:offset + limit]
    return {"total": len(hits), "offset": offset,
            "files": [{"path": r[0], "size": r[1], "status": r[3], "kind": kind_of(r[0], _facts(r)), "placed": r[4],
                       "picked": bool(best and _written(r)), "quality": describe(_facts(r)),
                       "name": sound_name(_facts(r))}
                      for r in page]}


def write_readmes(out: Path, index: dict) -> None:
    summ = summary(index) or {"versions": {}}
    mode, folders = index.get("mode"), index.get("folders", "game")
    lines = [
        "Scarface: The World Is Yours - game files from your own copies",
        "=" * 64,
        "",
        f"Made by the Scarface decomp portal on {index.get('created')}, for your personal use.",
        "These files belong to the game's owners: don't share or upload them.",
        "",
        f"Layout: {MODE_LABELS.get(mode, mode)}",
    ]
    if mode == "unique":
        lines += [f"  {SHARED}/  files that are exactly the same in two or more versions, kept once"]
        for v, s in summ["versions"].items():
            lines.append(f"  {exclusive(v)}/  what only the {s['label']} version has ({s['only']:,} files)")
            lines.append(f"  {s['label']}/  files the {s['label']} version has in a different form from the others")
    elif mode == "best":
        lines += [f"  {BEST}/  one copy of every file the versions share. Where they have it in different forms, the",
                  "         highest-quality one: sounds by sample rate, then channels, then codec; videos by",
                  "         picture size; models and textures by texture size, then colour depth. Ties go to",
                  "         PC, Xbox, PS2, then the prototype, and the 1.00.2 patch's files win."]
        for v, n in summ.get("best", {}).get("from", {}).items():
            lines.append(f"         {n:>7,} from {LABELS.get(v, v)}")
        for v, s in summ["versions"].items():
            lines.append(f"  {exclusive(v)}/  what only the {s['label']} version has ({s['only']:,} files)")
    elif mode == "pc":
        picked = summ.get("pc_first", {}).get("from", {})
        lines += [f"  {LABELS['pc']}/  the whole PC version ({picked.get('pc', 0):,} files, with the 1.00.2 patch's files"
                  " where it changes one)"]
        for v, s in summ["versions"].items():
            if v != "pc":
                lines.append(f"  {exclusive(v)}/  what only the {s['label']} version has ({s['only']:,} files)")
        lines += [f"  {NOT_ON_PC}/  what two or more of the other versions have but the PC doesn't, once (the",
                  "         highest-quality copy, as in the Best layout)"]
        for v, n in picked.items():
            if v != "pc" and n:
                lines.append(f"         {n:>7,} files in all from {LABELS.get(v, v)}")
    else:
        for s in summ["versions"].values():
            lines.append(f"  {s['label']}/  the whole {s['label']} version")
    lines += [""]
    if folders == "type":
        lines += ["Folders: by type first (" + ", ".join(KIND_LABELS[k] for k, _l, _e in KINDS) + ", Other), then",
                  "the folders the file has inside the game."]
    else:
        lines += ["Every file keeps the folder it has inside the game."]
    if mode in ("best", "pc"):
        lines += ["The .rcf archive a file is packed in is left out of its path: it is where the game looks",
                  "for it (each version packs its files into different archives)."]
    else:
        lines += ["Files that the game packs in .rcf archives are in a folder named after the archive (for",
                  "example cement.rcf/)."]
    lines += [
        "",
        f"{'':22}{'files':>9}{'only here':>12}{'different':>12}{'shared':>9}",
    ]
    for s in summ["versions"].values():
        lines.append(f"{s['label']:22}{s['files']:>9,}{s['only']:>12,}{s['changed']:>12,}{s['shared']:>9,}")
    lines += [
        "",
        "  only here   no other version has a file at that place",
        "  different   another version has that file, but its bytes are different",
        "  shared      another version has exactly the same file",
        "",
        "\"INDEX - <version>.txt\" lists every file of a version and where it is."
        + (" \"INDEX - Best.txt\" says where each file in Best/ came from and why." if mode == "best" else ""),
        "",
        "Opening them: .bik videos play in VLC. .rsd sounds play in foobar2000 with the vgmstream",
        "component. .p3d files are Radical's Pure3D format (models, textures, animation): Lucas' Pure3D",
        "Editor opens them (Donut Team's Mod Bakery has a version for Scarface). Scripts (.cso, .dso) can",
        "be read in the portal's Game scripts view.",
        "",
    ]
    (out / "README.txt").write_text("\n".join(lines), encoding="utf-8")
    best_rows: Dict[str, List[Tuple[str, list]]] = {}
    for v, info in index.get("versions", {}).items():
        label = info.get("label", LABELS.get(v, v))
        rows = info.get("files", [])
        groups = {"only": [], "changed": [], "shared": []}
        for r in rows:
            groups[r[3]].append(r)
            if mode == "best" and r[4]:
                best_rows.setdefault(r[4], []).append((v, r))
        text = [f"{label}: {len(rows):,} files, read from {info.get('source', '')}", ""]
        for st, title in (("only", "ONLY IN THIS VERSION"), ("changed", "DIFFERENT IN THIS VERSION"),
                          ("shared", "THE SAME IN ANOTHER VERSION")):
            text.append(f"{title} ({len(groups[st]):,})")
            for r in sorted(groups[st], key=lambda r: r[0].lower()):
                where = f"   -> {r[4]}" if r[4] and r[4] != f"{label}/{r[0]}" else ""
                named = sound_name(_facts(r))
                text.append(f"  {r[1]:>12,}  {r[0]}{where}" + (f"   [{named}]" if named else ""))
            text.append("")
        (out / f"INDEX - {label}.txt").write_text("\n".join(text), encoding="utf-8")
    if mode == "best":
        text = ["Best/: where each file came from, and the other versions' forms of it", ""]
        best_rows = {k: c for k, c in best_rows.items() if k.startswith(BEST + "/")}
        for place in sorted(best_rows, key=str.lower):
            cands = best_rows[place]
            pick = next(((v, r) for v, r in cands if _written(r)), cands[0])
            why = describe(_facts(pick[1]))
            text.append(f"{place}")
            text.append(f"    from {LABELS.get(pick[0], pick[0])}: {pick[1][0]}" + (f"  ({why})" if why else ""))
            for v, r in cands:
                if r is not pick[1]:
                    other = describe(_facts(r))
                    same = " (the same bytes)" if r[2] == pick[1][2] else ""
                    text.append(f"    also {LABELS.get(v, v)}: {r[0]}" + (f"  ({other})" if other else "") + same)
        (out / "INDEX - Best.txt").write_text("\n".join(text) + "\n", encoding="utf-8")


# --------------------------------------------------------------------------- #
# The portal's background job
# --------------------------------------------------------------------------- #

class Job:
    """One extraction at a time, in a background thread."""

    def __init__(self, bin_dir: Path = BIN_DIR, log: Log = print):
        self.bin_dir, self.log = bin_dir, log
        self.status = new_status()
        self._stop = threading.Event()
        self._thread: Optional[threading.Thread] = None
        self._lock = threading.Lock()
        self._index_cache: Tuple[tuple, Optional[dict]] = ((), None)
        self.busy: Optional[Callable[[], str]] = None      # something else that mustn't run with a copy (why, or "")
        self._sources_cache: Tuple[tuple, Optional[Tuple[Dict[str, Source], List[str]]]] = ((), None)

    def sources(self) -> Tuple[Dict[str, Source], List[str]]:
        """find_sources(), worked out again only when something in binaries/ changes."""
        try:
            key = tuple(sorted((p.name, p.stat().st_size, int(p.stat().st_mtime))
                               for p in self.bin_dir.iterdir() if p.name not in SKIP_DIRS))
        except OSError:
            key = ()
        if self._sources_cache[1] is None or self._sources_cache[0] != key:
            self._sources_cache = (key, find_sources(self.bin_dir))
        return self._sources_cache[1]

    @property
    def running(self) -> bool:
        return bool(self._thread and self._thread.is_alive())

    def start(self, versions: List[str], mode: str, folders: str = "game", check: bool = False) -> Optional[str]:
        """None when started, or why not. A copy with the same choices as the last one only starts with check:
        it then looks at every file and puts back the ones that went missing (or says they're all there)."""
        with self._lock:
            if self.running:
                return "Already copying the game's files. Wait for it to finish or press Stop."
            sources, _notes = self.sources()
            chosen = [v for v in versions if v in sources]
            if not chosen:
                return "None of those versions were found in binaries/."
            if mode not in MODES:
                return "Pick a layout."
            if folders not in FOLDERS:
                return "Pick how to arrange the folders."
            if self.busy is not None:
                why = self.busy()
                if why:
                    return why
            index = self.index()
            cut = (out_dir(self.bin_dir) / WORK / PLACING).is_file()
            if not check and not cut and same_settings(index, sources, chosen, mode, folders):
                return ("Already copied with these choices: there's nothing to copy. To put back files that went "
                        "missing, press Check for missing files.")
            need = sum(sources[v].size for v in chosen) - _reusable_bytes(index)
            free = _free_space(self.bin_dir)
            if free is not None and free < need * 1.05:
                return (f"Not enough free space: this needs up to {_fmt_bytes(need)} and the drive has "
                        f"{_fmt_bytes(free)} free.")
            self._stop.clear()
            self.status.update(new_status(), running=True, phase="preparing", mode=mode, versions=chosen)
            self._thread = threading.Thread(target=self._run, args=(chosen, mode, sources, folders),
                                            name="game-files", daemon=True)
            self._thread.start()
            return None

    def stop(self) -> None:
        """Stop reading. Putting files in place, the short last part, always finishes."""
        self._stop.set()

    def _run(self, versions: List[str], mode: str, sources: Dict[str, Source], folders: str = "game") -> None:
        try:
            run(versions, mode, self.bin_dir, self.status, self._stop.is_set, self.log, sources, folders)
        except Stopped:
            self.status.update(running=False, phase="stopped", finished=time.time(),
                               message=("Stopped. Your last copy is as it was. Press Copy again to carry on "
                                        "where it left off." if self.index() else
                                        "Stopped. Press Copy again to carry on where it left off."))
        except Exception as e:  # noqa: BLE001 - shown in the portal
            import traceback
            traceback.print_exc()
            self.status.update(running=False, phase="error", finished=time.time(), error=str(e) or type(e).__name__)
        finally:
            self.status["running"] = False

    def index(self) -> Optional[dict]:
        p = out_dir(self.bin_dir) / INDEX_JSON
        try:
            st = p.stat()
        except OSError:
            return None
        key = (st.st_mtime_ns, st.st_size, st.st_ino)      # a new index is a new file (written, then swapped in)
        if self._index_cache[0] != key:
            self._index_cache = (key, load_index(out_dir(self.bin_dir)))
        return self._index_cache[1]

    def overview(self) -> dict:
        sources, notes = self.sources()
        out = out_dir(self.bin_dir)
        return {
            "versions": [dict(sources[v].to_json(), found=True) if v in sources
                         else {"version": v, "label": LABELS[v], "found": False} for v in VERSIONS],
            "notes": notes, "folder": _show_path(out), "free": _free_space(self.bin_dir),
            "summary": summary(self.index()), "status": dict(self.status),
            "copy": same_choices(self.index(), sources),
            "interrupted": not self.running and (out / WORK / PLACING).is_file(),
            "modes": [{"id": m, "label": MODE_LABELS[m]} for m in MODES],
            "folders": [{"id": f, "label": FOLDER_LABELS[f]} for f in FOLDERS],
            "kinds": [{"id": k, "label": KIND_LABELS[k]} for k in [k for k, _, _ in KINDS] + ["other"]],
        }

    def file_path(self, version: str, path: str) -> Optional[Path]:
        """Where a copied file is. While a copy is putting files in place, one waiting in the store."""
        out, index = out_dir(self.bin_dir), self.index()
        found = file_on_disk(out, index, version, path)
        if found is None and self.running:
            for row in ((index or {}).get("versions", {}).get(version) or {}).get("files", []):
                if row[0] == path:
                    p = Store.__new__(Store)
                    p.root = out / WORK / "store"
                    q = p.path(row[2])
                    return q if _size(q) == row[1] else None
        return found

    def files_beside(self, version: str, path: str, patterns: Tuple[str, ...]) -> List[Path]:
        return files_beside(out_dir(self.bin_dir), self.index(), version, path, patterns)

    def folder_for(self, version: str) -> Optional[Path]:
        """The folder to open: a version's, Shared/ ('shared') or the whole output ('') - if it exists."""
        out = out_dir(self.bin_dir)
        if version == "":
            p = out
        elif version == "shared":
            p = out / SHARED
        elif version == "best":
            p = out / BEST
        elif version == "notpc":
            p = out / NOT_ON_PC
        elif version.startswith("only:") and version[5:] in LABELS:
            p = out / exclusive(version[5:])
        elif version in LABELS:
            p = out / LABELS[version]
        else:
            return None
        return p if p.is_dir() else None


def file_on_disk(out: Path, index: Optional[dict], version: str, path: str, max_size: int = 256 << 20) -> Optional[Path]:
    """Where one of a version's files was copied to, for previewing it in the portal. None when the file isn't
    in the list, wasn't copied, has changed size since, or is too big to preview."""
    for row in ((index or {}).get("versions", {}).get(version) or {}).get("files", []):
        if row[0] != path:
            continue
        if not row[4] or row[1] > max_size:
            return None
        p = safe_output_path(out, row[4])
        try:
            return p if p is not None and p.is_file() and p.stat().st_size == row[1] else None
        except OSError:
            return None
    return None


_PAIRS: Dict[Tuple[int, str], Dict[str, Dict[str, str]]] = {}


def companion(index: Optional[dict], version: str, path: str) -> Optional[str]:
    """A sound's subtitle file, or a subtitle file's sound: art/sound/rsd/<x>/<name>.rsd and
    art/subtitles/<x>/<name>.p3d go together (in whichever archive)."""
    key = (id(index), version)
    pairs = _PAIRS.get(key)
    if pairs is None:
        _PAIRS.clear()                               # one index at a time is plenty
        pairs = {"rsd": {}, "p3d": {}}
        for row in ((index or {}).get("versions", {}).get(version) or {}).get("files", []):
            low = row[0].lower()
            for kind, marker in (("rsd", "/art/sound/rsd/"), ("p3d", "/art/subtitles/")):
                if marker in "/" + low and low.endswith("." + kind):
                    pairs[kind][low.rsplit("/", 2)[-2] + "/" + low.rsplit("/", 1)[-1][:-4]] = row[0]
        _PAIRS[key] = pairs
    low = path.lower()
    for kind, other in (("rsd", "p3d"), ("p3d", "rsd")):
        if low.endswith("." + kind) and "/" in low:
            return pairs[other].get(low.rsplit("/", 2)[-2] + "/" + low.rsplit("/", 1)[-1][:-4])
    return None


def files_beside(out: Path, index: Optional[dict], version: str, path: str, patterns: Tuple[str, ...]) -> List[Path]:
    """The copied files in the same game folder as path whose names match one of the patterns (letter case
    ignored), for tools that need a file's neighbours (a map area's region and shared files)."""
    folder = path.rsplit("/", 1)[0].lower() + "/" if "/" in path else ""
    want = tuple(p.lower() for p in patterns)
    found = []
    for row in ((index or {}).get("versions", {}).get(version) or {}).get("files", []):
        low = row[0].lower()
        if row[0] == path or not low.startswith(folder) or "/" in low[len(folder):]:
            continue
        if any(fnmatch.fnmatchcase(low[len(folder):], p) for p in want):
            p = file_on_disk(out, index, version, row[0])
            if p is not None:
                found.append(p)
    return found


def _reusable_bytes(index: Optional[dict]) -> int:
    """Space an earlier run's files already take, which a new run reuses."""
    seen, total = set(), 0
    for info in (index or {}).get("versions", {}).values():
        for row in info.get("files", []):
            if row[2] not in seen:
                seen.add(row[2])
                total += row[1]
    return total


def _free_space(path: Path) -> Optional[int]:
    try:
        return shutil.disk_usage(path if path.exists() else path.parent).free
    except OSError:
        return None


def _show_path(p: Path) -> str:
    try:
        return p.relative_to(ROOT).as_posix()
    except ValueError:
        return str(p)


def open_folder(path: Path) -> None:
    """Show a folder in Explorer / Finder / the file manager."""
    if os.name == "nt":
        os.startfile(str(path))  # noqa: S606 - a folder the portal made
    elif sys.platform == "darwin":
        subprocess.Popen(["open", str(path)])
    else:
        subprocess.Popen(["xdg-open", str(path)])


# --------------------------------------------------------------------------- #

def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--extract", choices=MODES, help="copy the files out in this layout")
    ap.add_argument("--list", action="store_true", help="only list each version's files (for portal/tools/version_report.py)")
    ap.add_argument("--folders", choices=FOLDERS, default="game", help="as in the game, or by type first")
    ap.add_argument("--versions", default=",".join(VERSIONS), help="which versions (default: all found)")
    ap.add_argument("--bin", type=Path, default=BIN_DIR, help="the folder with your game files")
    a = ap.parse_args(argv)
    sources, notes = find_sources(a.bin)
    for v in VERSIONS:
        s = sources.get(v)
        print(f"  {LABELS[v]:22} {s.name + '  (' + _fmt_bytes(s.size) + ')' if s else 'not found'}")
    for n in notes:
        print(f"  note: {n}")
    if a.list:
        list_versions([v.strip() for v in a.versions.split(",")], a.bin, log=print, sources=sources)
        print(f"Lists written to {out_dir(a.bin) / CATALOGS}")
        return 0
    if not a.extract:
        return 0
    status = new_status()
    last = [0.0]

    def log(msg: str) -> None:
        print(msg, flush=True)

    def stop() -> bool:
        if time.time() - last[0] > 5 and status.get("total"):
            last[0] = time.time()
            print(f"      {status['done'] / max(1, status['total']):.0%}  {status['files']:,} files", flush=True)
        return False

    index = run([v.strip() for v in a.versions.split(",")], a.extract, a.bin, status, stop, log, sources, a.folders)
    for v, s in (summary(index) or {}).get("versions", {}).items():
        print(f"  {s['label']:22} {s['files']:>7,} files: {s['only']:,} only here, {s['changed']:,} different, "
              f"{s['shared']:,} shared")
    print(f"Written to {out_dir(a.bin)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
