#!/usr/bin/env python3
"""
Get the game files the portal needs into binaries/, unpacking them from the downloads people have.

The portal reads three files (see binaries/README.md):

    default.xbe    the retail Xbox game          (most of the work)
    Scarface.exe   the PC game, version 1.00.2   (the readable part of it)
    game.xbe       the April 20, 2006 Xbox prototype (optional, its own lane)

People usually have these packed: the Xbox game as a disc image (.iso) inside a .7z, the prototype
as a .zip of its folder, the PC game as an installer .iso plus the 1.00.2 patch. This module looks
in binaries/ (and one folder down) and:

  * copies a loose default.xbe / game.xbe / Scarface.exe found in a subfolder;
  * takes the file out of a .zip or .7z that holds it directly (the prototype .zip);
  * reads default.xbe straight out of an Xbox disc image (full Redump image or trimmed XISO),
    whether the image is loose or inside a .zip / .7z. Only the bytes needed are kept, so a
    multi-gigabyte image never has to be unpacked to disk;
  * explains the steps for the PC version, which has to be installed and patched first, and picks
    up an installed, patched Scarface.exe from Program Files when it finds one.

Every file is checked against the SHA-256 of the build the project uses; a different build is kept
but flagged, because the function addresses in the work queue would not line up.

    python tools/game_files.py            # report and unpack whatever it can
"""
from __future__ import annotations

import hashlib
import os
import shutil
import struct
import sys
import zipfile
from pathlib import Path
from typing import Callable, Dict, Iterator, List, Optional, Tuple

# name -> (accepted sha256 values, what it is)
# default.xbe: the file as it is on the disc (4,718,592 bytes), or the longer copy some tools write,
# which pads it to the header's image size with bytes from the next file on the disc. Every section
# of the program is in the first 4,718,592 bytes, so both give identical functions.
EXPECTED: Dict[str, Tuple[Tuple[str, ...], str]] = {
    "default.xbe": (("dbcf8a3df01f94b879a4a3e642a9f6c3ab5027cc31bdb0229f10e0c6d140b0d6",
                     "b15dd7cb1cda9cd2ada8d13709c6409e8ff8a824de1e449a12257c69cc1954a0"),
                    "Xbox retail game (USA/Europe disc)"),
    "Scarface.exe": (("1c1dd03ff81592acfa43c45f461fbdc4818503c739cd2f127e0a61fe6a6969c6",),
                     "PC game, US version 1.00.2"),
    "game.xbe": (("ecd980d0f25c444d263c968b8e4032e1707e0e684a422483890257ee12ec0384",),
                 "Xbox prototype, April 20 2006"),
}
PC_EXE_SIZE = 8462848
REQUIRED_ONE_OF = ("default.xbe", "Scarface.exe")
ARCHIVES = (".zip", ".7z")
DISC_IMAGES = (".iso", ".xiso")
SKIP_DIRS = {"scripts_and_data", "ps2", "wii", "_unpacked"}

XBOX_MAGIC = b"MICROSOFT*XBOX*MEDIA"
# Where the game's file system starts inside the image: trimmed XISO, then full XGD1/XGD2/XGD3 images.
XDVDFS_BASES = (0, 0x18300000, 0x0FD90000, 0x02080000)
SECTOR = 2048
CHUNK = 4 << 20
MIN_DISC_IMAGE = 100 << 20          # anything smaller inside an archive is not a disc image

Log = Callable[[str], None]


class _Done(Exception):
    """Raised from inside a decompression stream once every byte we need has gone past."""


# --------------------------------------------------------------------------- #
# Checking files
# --------------------------------------------------------------------------- #

def sha256_of(path: Path) -> str:
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for block in iter(lambda: f.read(CHUNK), b""):
            h.update(block)
    return h.hexdigest()


def check(path: Path) -> str:
    """'ok', 'different' (another build) or 'missing'."""
    if not path.exists():
        return "missing"
    return "ok" if sha256_of(path) in EXPECTED[path.name][0] else "different"


def _place(dest: Path, data_or_src, log: Log, origin: str) -> None:
    """Write bytes (or copy a file) to dest atomically, then report how it compares."""
    dest.parent.mkdir(parents=True, exist_ok=True)
    part = dest.with_name(dest.name + ".part")
    if isinstance(data_or_src, (bytes, bytearray)):
        part.write_bytes(data_or_src)
    else:
        shutil.copyfile(data_or_src, part)
    os.replace(part, dest)
    state = check(dest)
    note = "" if state == "ok" else "  (a different build from the one this project uses; see below)"
    log(f"    + {dest.name}: taken from {origin}{note}")


# --------------------------------------------------------------------------- #
# Xbox disc images (XDVDFS)
# --------------------------------------------------------------------------- #

def _dir_entries(table: bytes) -> Iterator[Tuple[str, int, int, int]]:
    """(name, start sector, size, attributes) for every entry in one XDVDFS directory table."""
    seen, todo = set(), [0]
    while todo:
        off = todo.pop()
        if off in seen or off + 14 > len(table):
            continue
        seen.add(off)
        left, right, sector, size, attrs, nlen = struct.unpack_from("<HHIIBB", table, off)
        if left == 0xFFFF and right == 0xFFFF:
            continue
        name = table[off + 14:off + 14 + nlen].decode("latin-1")
        yield name, sector, size, attrs
        if left:
            todo.append(left * 4)
        if right:
            todo.append(right * 4)


def _volume(desc: bytes) -> Optional[Tuple[int, int]]:
    """Root directory (sector, size) from a volume descriptor, or None if it isn't one."""
    if len(desc) < 0x800 or desc[:20] != XBOX_MAGIC or desc[0x7EC:0x7EC + 20] != XBOX_MAGIC:
        return None
    return struct.unpack_from("<II", desc, 20)


def _find_in_root(root: bytes, name: str) -> Optional[Tuple[int, int]]:
    for n, sector, size, attrs in _dir_entries(root):
        if n.lower() == name.lower() and not attrs & 0x10:
            return sector, size
    return None


def read_from_disc_file(path: Path, name: str = "default.xbe") -> Optional[bytes]:
    """Read one file from the root of an Xbox disc image on disk (random access, fast)."""
    with open(path, "rb") as f:
        def read_at(off: int, n: int) -> bytes:
            f.seek(off)
            return f.read(n)
        for base in XDVDFS_BASES:
            vol = _volume(read_at(base + 32 * SECTOR, SECTOR))
            if not vol:
                continue
            root = read_at(base + vol[0] * SECTOR, vol[1])
            hit = _find_in_root(root, name)
            if hit:
                data = read_at(base + hit[0] * SECTOR, hit[1])
                return data if len(data) == hit[1] else None
    return None


class DiscStream:
    """
    Takes an Xbox disc image as a stream of chunks, in order, and keeps only what is needed to read
    one file from it: the volume descriptor, the root directory, then the file. Raises _Done as soon
    as there is nothing left to wait for. If the directory or the file sits earlier in the image than
    the part that says where it is, `missed` is set and another pass, started with `known`, picks it
    up (at most three passes, and real discs need one).
    """

    def __init__(self, name: str, known: Optional[dict] = None, sink=None):
        self.name = name
        self.sink = sink                      # a file to write the found file into, instead of memory
        self.written = 0
        self.pos = 0
        self._lo = 0                          # where the chunk being looked at starts
        self.known = dict(known or {})
        self.missed = False
        self.result: Optional[bytes] = None
        self.wants: Dict[str, List] = {}      # label -> [start, end, buffer]
        if "file" in self.known:
            self._want("file", *self.known["file"])
        elif "root" in self.known:
            self._want("root", *self.known["root"])
        else:
            for base in XDVDFS_BASES:
                self._want(f"vd{base}", base + 32 * SECTOR, base + 33 * SECTOR)

    def _want(self, label: str, start: int, end: int) -> None:
        if not label.startswith("vd"):
            self.known[label] = (start, end)
        if start < self._lo:
            self.missed = True
        else:
            self.wants[label] = [start, end, bytearray()]

    def feed(self, chunk: bytes) -> None:
        lo, hi = self.pos, self.pos + len(chunk)
        self._lo, self.pos = lo, hi
        changed = True
        while changed:                    # something found in this chunk may point into this chunk
            changed = False
            for label, w in list(self.wants.items()):
                start, end, buf = w
                to_sink = label == "file" and self.sink is not None
                have = self.written if to_sink else len(buf)
                a, b = max(lo, start + have), min(hi, end)
                if a < b:
                    if to_sink:
                        self.sink.write(chunk[a - lo:b - lo])
                        self.written += b - a
                    else:
                        buf += chunk[a - lo:b - lo]
                    have += b - a
                if start + have >= end:
                    del self.wants[label]
                    self._complete(label, b"" if to_sink else bytes(buf))
                    changed = True
        if not self.wants:
            raise _Done()

    def _complete(self, label: str, data: bytes) -> None:
        if label.startswith("vd"):
            vol = _volume(data)
            if vol:
                base = int(label[2:])
                self.known["base"] = base
                for other in [k for k in self.wants if k.startswith("vd")]:
                    del self.wants[other]
                self._want("root", base + vol[0] * SECTOR, base + vol[0] * SECTOR + vol[1])
        elif label == "root":
            hit = _find_in_root(data, self.name)
            if hit:
                start = self.known["base"] + hit[0] * SECTOR
                self._want("file", start, start + hit[1])
        elif label == "file":
            self.result = data if self.sink is None else b"(written to file)"


def _pull(stream: DiscStream, fileobj, total: int, log: Log, what: str) -> None:
    shown = 0
    try:
        while True:
            chunk = fileobj.read(CHUNK)
            if not chunk:
                return
            stream.feed(chunk)
            shown = _progress(stream.pos, total, shown, log, what)
    except _Done:
        return


def _progress(pos: int, total: int, shown: int, log: Log, what: str) -> int:
    step = 512 << 20
    if total and pos - shown >= step:
        log(f"      reading {what}: {pos / 2**30:.1f} of {total / 2**30:.1f} GB")
        return pos
    return shown


# --------------------------------------------------------------------------- #
# Archives
# --------------------------------------------------------------------------- #

def _members(archive: Path) -> List[Tuple[str, int]]:
    if archive.suffix.lower() == ".zip":
        with zipfile.ZipFile(archive) as z:
            return [(i.filename, i.file_size) for i in z.infolist() if not i.is_dir()]
    py7zr = _py7zr()
    with py7zr.SevenZipFile(archive) as z:
        return [(i.filename, i.uncompressed) for i in z.list() if not i.is_directory]


def _py7zr():
    try:
        import py7zr  # noqa: F401
        return py7zr
    except ImportError:
        raise RuntimeError("reading .7z files needs the py7zr package: pip install -r requirements.txt")


def _read_member(archive: Path, member: str) -> bytes:
    if archive.suffix.lower() == ".zip":
        with zipfile.ZipFile(archive) as z:
            return z.read(member)
    py7zr = _py7zr()
    from py7zr.io import BytesIOFactory
    factory = BytesIOFactory(limit=256 << 20)
    with py7zr.SevenZipFile(archive) as z:
        z.extract(targets=[member], factory=factory)
    return factory.get(member).getvalue()


def _disc_in_archive(archive: Path, member: str, size: int, name: str, log: Log,
                     dest: Optional[Path] = None) -> Optional[bytes]:
    """Read `name` from the root of the disc image `member` inside a .zip/.7z. With `dest`, the file
    is written there as it streams past (for big files) and b'(written to file)' is returned."""
    what = f"{archive.name} \u2192 {Path(member).name}"
    known: Optional[dict] = None
    for attempt in range(3):
        if attempt:
            log("      what it needs sits early in the image; reading it again from the start")
        sink = open(dest, "wb") if dest is not None else None
        try:
            stream = DiscStream(name, known, sink)
            if archive.suffix.lower() == ".zip":
                with zipfile.ZipFile(archive) as z, z.open(member) as f:
                    _pull(stream, f, size, log, what)
            else:
                _stream_7z(archive, member, size, stream, log, what)
        finally:
            if sink:
                sink.close()
        if stream.result is not None or not stream.missed:
            return stream.result
        known = stream.known
    return None


def disc_images_in(archive: Path) -> List[Tuple[str, int]]:
    """(member, size) of every disc image inside a .zip/.7z."""
    return [(m, n) for m, n in _members(archive) if m.lower().endswith(DISC_IMAGES) and n >= MIN_DISC_IMAGE]


def _stream_7z(archive: Path, member: str, size: int, stream: DiscStream, log: Log, what: str) -> None:
    py7zr = _py7zr()
    from py7zr.io import NullIO, Py7zIO, WriterFactory

    class Sink(Py7zIO):
        def __init__(self):
            self.shown = 0

        def write(self, s):
            stream.feed(bytes(s))
            self.shown = _progress(stream.pos, size, self.shown, log, what)
            return len(s)

        def read(self, size=None):
            return b""

        def seek(self, offset, whence=0):
            return stream.pos

        def flush(self):
            return None

        def size(self):
            return stream.pos

    class Factory(WriterFactory):
        def create(self, filename):
            return Sink() if filename == member else NullIO()

    try:
        with py7zr.SevenZipFile(archive) as z:
            z.extract(targets=[member], factory=Factory())
    except _Done:
        pass


# --------------------------------------------------------------------------- #
# Looking for sources
# --------------------------------------------------------------------------- #

def _candidates(bin_dir: Path) -> List[Path]:
    out: List[Path] = []
    for p in sorted(bin_dir.iterdir()) if bin_dir.exists() else []:
        if p.is_dir() and p.name not in SKIP_DIRS:
            for q in sorted(p.rglob("*")):
                if q.is_file() and len(q.relative_to(p).parts) <= 3:
                    out.append(q)
        elif p.is_file():
            out.append(p)
    return out


def _is_xbox_image(path: Path) -> bool:
    try:
        with open(path, "rb") as f:
            for base in XDVDFS_BASES:
                f.seek(base + 32 * SECTOR)
                if f.read(20) == XBOX_MAGIC:
                    return True
    except OSError:
        pass
    return False


def _is_pc_disc(path: Path) -> bool:
    try:
        with open(path, "rb") as f:
            f.seek(0x8001)
            return f.read(5) == b"CD001" and not _is_xbox_image(path)
    except OSError:
        return False


def _installed_pc_exe() -> Optional[Path]:
    """A patched Scarface.exe in Program Files, if there is one (Windows only, quick look)."""
    if os.name != "nt":
        return None
    roots = {os.environ.get(k) for k in ("ProgramFiles(x86)", "ProgramFiles", "ProgramW6432")}
    for root in filter(None, roots):
        base = Path(root)
        if not base.exists():
            continue
        for depth_glob in ("*/Scarface.exe", "*/*/Scarface.exe", "*/*/*/Scarface.exe"):
            try:
                for hit in base.glob(depth_glob):
                    if hit.stat().st_size == PC_EXE_SIZE:
                        return hit
            except OSError:
                continue
    return None


def prepare(bin_dir: Path, log: Log = print) -> Dict[str, str]:
    """
    Make sure binaries/ has what it can. Returns {file name: 'ok' | 'different' | 'missing'}.
    Never deletes or changes the user's own downloads.
    """
    bin_dir = Path(bin_dir)
    status = {n: check(bin_dir / n) for n in EXPECTED}
    missing = [n for n, s in status.items() if s == "missing"]
    pc_disc = patch = None
    if missing:
        sources = _candidates(bin_dir)
        for src in sources:
            low = src.name.lower()
            if low.endswith(".exe") and "patch" in low:
                patch = src
            if low.endswith(DISC_IMAGES) and _is_pc_disc(src):
                pc_disc = src
        for name in list(missing):
            got = _from_sources(name, sources, bin_dir, log)
            if got:
                missing.remove(name)
        if "Scarface.exe" in missing:
            hit = _installed_pc_exe()
            if hit:
                _place(bin_dir / "Scarface.exe", hit, log, f"your installed game ({hit.parent})")
                missing.remove("Scarface.exe")
    status = {n: check(bin_dir / n) for n in EXPECTED}
    _report(status, bin_dir, pc_disc, patch, log)
    return status


def _from_sources(name: str, sources: List[Path], bin_dir: Path, log: Log) -> bool:
    dest = bin_dir / name
    # 1. the file itself, one folder down (someone unzipped the prototype into binaries/)
    for src in sources:
        if src.name.lower() == name.lower() and src.parent != bin_dir:
            _place(dest, src, log, str(src.relative_to(bin_dir)))
            return True
    # 2. an archive holding the file directly
    for src in sources:
        if not src.name.lower().endswith(ARCHIVES):
            continue
        try:
            members = _members(src)
        except Exception as e:  # noqa: BLE001 - a broken or unreadable download shouldn't stop the portal
            log(f"    ! could not open {src.name}: {e}")
            continue
        for member, _ in members:
            if Path(member).name.lower() == name.lower():
                log(f"    unpacking {name} from {src.name}...")
                _place(dest, _read_member(src, member), log, src.name)
                return True
    if name != "default.xbe":
        return False
    # 3. an Xbox disc image, loose or inside an archive
    for src in sources:
        if src.name.lower().endswith(DISC_IMAGES) and _is_xbox_image(src):
            log(f"    reading default.xbe from the disc image {src.name}...")
            data = read_from_disc_file(src)
            if data:
                _place(dest, data, log, src.name)
                return True
    for src in sources:
        if not src.name.lower().endswith(ARCHIVES):
            continue
        try:
            members = _members(src)
        except Exception:  # noqa: BLE001
            continue
        for member, size in members:
            if member.lower().endswith(DISC_IMAGES) and size >= MIN_DISC_IMAGE:
                log(f"    reading default.xbe from {Path(member).name} inside {src.name}")
                log("      (this reads through the packed disc image once; a minute or two)")
                try:
                    data = _disc_in_archive(src, member, size, "default.xbe", log)
                except Exception as e:  # noqa: BLE001
                    log(f"    ! could not read {src.name}: {e}")
                    data = None
                if data:
                    _place(dest, data, log, f"{src.name} → {Path(member).name}")
                    return True
    return False


def _report(status: Dict[str, str], bin_dir: Path, pc_disc, patch, log: Log) -> None:
    for name, state in status.items():
        what = EXPECTED[name][1]
        if state == "ok":
            log(f"  {name:<13} ready ({what})")
        elif state == "different":
            log(f"  {name:<13} found, but it is not the {what} build the project uses. Functions may")
            log(f"  {'':<13} not line up; use the {what} build if you can.")
    if all(status[n] == "missing" for n in REQUIRED_ONE_OF):
        log("")
        log("  No game files yet, so the portal has nothing to show.")
        log("  Put any of these in the binaries folder and start the portal again:")
        log("    - the Xbox game: default.xbe, or the Xbox disc image (.iso, or the .7z / .zip it came in)")
        log("    - the PC game's Scarface.exe, version 1.00.2 (see below)")
    if status["Scarface.exe"] == "missing" and (pc_disc or patch):
        log("")
        log("  For the PC functions, Scarface.exe has to come from an installed, patched game:")
        log(f"    1. Install the game{' from ' + pc_disc.name if pc_disc else ''} (on Windows, double-click the .iso,")
        log("       then run its setup).")
        log(f"    2. Run the 1.00.2 patch{' (' + patch.name + ')' if patch else ''}.")
        log("    3. Copy Scarface.exe from the game's install folder into the binaries folder.")
        log("  The portal also checks Program Files for a patched copy each time it starts.")


def main() -> int:
    root = Path(__file__).resolve().parent.parent
    status = prepare(root / "binaries")
    return 0 if any(status[n] != "missing" for n in REQUIRED_ONE_OF) else 1


if __name__ == "__main__":
    sys.exit(main())
