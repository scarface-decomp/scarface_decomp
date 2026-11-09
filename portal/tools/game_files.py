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
    multi-gigabyte image never has to be unpacked to disk. A .7z is read by sevenzip.py, which needs
    nothing installed (7-Zip or py7zr are used only for unusual compression);
  * takes Scarface.exe 1.00.2 out of the official 1.00.2 patch, which carries the whole file, so
    the PC game doesn't have to be installed; a wrong Scarface.exe is moved aside (never deleted)
    when the patch has the right one. It also picks up an installed, patched Scarface.exe from
    Program Files when it finds one.

Every file is checked against the SHA-256 of the build the project uses; a different build is kept
but flagged, because the function addresses in the work queue would not line up.

    python portal/tools/game_files.py            # report and unpack whatever it can
"""
from __future__ import annotations

import hashlib
import os
import shutil
import struct
import subprocess
import sys
import zipfile
from pathlib import Path
from typing import Callable, Dict, Iterator, List, Optional, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parent))
import sevenzip  # noqa: E402

# The only copies the project accepts (docs/GAME_VERSIONS.md). Every function's address and bytes
# come from these exact files, so a match only means something against them.
# name -> (accepted sha256 values, what it is)
# default.xbe: the file as it is on the disc (4,718,592 bytes), or the longer copy some tools write,
# which pads it to the header's image size with bytes from the next file on the disc. Every section
# of the program is in the first 4,718,592 bytes, so both give identical functions.
EXPECTED: Dict[str, Tuple[Tuple[str, ...], str]] = {
    "default.xbe": (("dbcf8a3df01f94b879a4a3e642a9f6c3ab5027cc31bdb0229f10e0c6d140b0d6",
                     "b15dd7cb1cda9cd2ada8d13709c6409e8ff8a824de1e449a12257c69cc1954a0"),
                    "Xbox, US disc"),
    "Scarface.exe": (("1c1dd03ff81592acfa43c45f461fbdc4818503c739cd2f127e0a61fe6a6969c6",),
                     "PC, US version 1.00.2"),
    "game.xbe": (("ecd980d0f25c444d263c968b8e4032e1707e0e684a422483890257ee12ec0384",),
                 "Xbox prototype, April 20 2006"),
}
PC_EXE_SIZE = 8462848
GUIDE = "docs/GAME_VERSIONS.md"
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


def describe(path: Path) -> str:
    """What a game file says about itself (version, build date, region), for telling people why it
    isn't the accepted one."""
    import datetime
    try:
        data = path.read_bytes()
    except OSError as e:
        return f"unreadable ({e})"
    size = f"{len(data):,} bytes"
    if data[:4] == b"XBEH" and len(data) > 0x180:
        try:
            base, = struct.unpack_from("<I", data, 0x104)
            built, = struct.unpack_from("<I", data, 0x114)
            cert = struct.unpack_from("<I", data, 0x118)[0] - base
            title_id, = struct.unpack_from("<I", data, cert + 8)
            region, = struct.unpack_from("<I", data, cert + 0xA0)
            disc, = struct.unpack_from("<I", data, cert + 0xAC)
            regions = [n for bit, n in ((1, "North America"), (2, "Japan"), (4, "rest of the world")) if region & bit]
            when = datetime.datetime.fromtimestamp(built, datetime.timezone.utc).strftime("%Y-%m-%d")
            return (f"an Xbox program built {when}, title ID {title_id:08X}, disc version {disc}, "
                    f"regions: {', '.join(regions) or 'none'}{' (debug build)' if region & 0x80000000 else ''}; {size}")
        except struct.error:
            return f"an Xbox program with a damaged header; {size}"
    if data[:2] == b"MZ":
        mark = "FileVersion".encode("utf-16le")
        i = data.find(mark)
        if i > 0:
            raw = data[i + len(mark):i + len(mark) + 40].decode("utf-16le", "replace")
            ver = "".join(ch for ch in raw.lstrip("\0").split("\0")[0] if ch.isdigit() or ch == ".").strip(".")
            if ver:
                return f"a Windows program, file version {ver}; {size}"
        return f"a Windows program; {size}"
    return f"not a game program; {size}"


def refusal(path: Path) -> Optional[str]:
    """None if the file is the accepted one (or isn't there); otherwise why it can't be used."""
    path = Path(path)
    if path.name not in EXPECTED or check(path) != "different":
        return None
    want = EXPECTED[path.name][1]
    msg = (f"binaries/{path.name} is not the {want} copy this project uses. It is {describe(path)}. "
           f"Other versions and regions have different code at different addresses, so matches made "
           f"against it would not count.")
    patch = _patch_installer(path.parent) if path.name == "Scarface.exe" else None
    if patch and _exe_in_patch(patch):
        msg += (f" The patch ({patch.name}) is in the folder and has the right Scarface.exe inside: start the "
                f"portal again and it uses that one instead.")
    elif patch:
        msg += (f" The patch ({patch.name}) is in the folder, but it can't be read directly: run it to update "
                f"your installed game, then copy the updated Scarface.exe from the game's install folder into "
                f"binaries/.")
    elif path.name == "Scarface.exe":
        msg += (" Put the official 1.00.2 patch in binaries/ and start the portal again: it takes the right "
                "Scarface.exe out of the patch.")
    return msg + f" See {GUIDE} for the accepted versions."


def _patch_installer(folder: Path) -> Optional[Path]:
    """The PC game's patch sitting in the folder, if any: a program with Scarface.exe inside it (the
    official 1.00.2 update, whatever it is called), or one named like a patch or update."""
    try:
        exes = [p for p in sorted(Path(folder).iterdir()) if p.is_file() and p.suffix.lower() == ".exe"
                and p.name.lower() != "scarface.exe"]
    except OSError:
        return None
    for p in exes:
        if _exe_in_patch(p):
            return p
    return next((p for p in exes if "patch" in p.name.lower() or "update" in p.name.lower()), None)


def _exe_in_patch(p: Path) -> Optional[str]:
    """The name of Scarface.exe inside a patch program that carries a zip, or None."""
    if not _is_zip(p) or p.suffix.lower() != ".exe":
        return None
    try:
        with zipfile.ZipFile(p) as z:
            return next((n for n in z.namelist() if Path(n).name.lower() == "scarface.exe"), None)
    except (OSError, zipfile.BadZipFile):
        return None


def _pc_disc_in(folder: Path) -> Optional[Path]:
    try:
        return next((p for p in sorted(Path(folder).iterdir())
                     if p.is_file() and p.suffix.lower() in DISC_IMAGES and _is_pc_disc(p)), None)
    except OSError:
        return None


def startup(bin_dir: Path, log: Log = print) -> bool:
    """At portal start: when a game file is missing but its download is in binaries/ (a disc image, the
    .zip/.7z it came in, the file one folder down, or the PC patch), copy it out once. Says nothing when
    there is nothing to do, so a set-up folder starts as quietly as before."""
    bin_dir = Path(bin_dir)
    if not bin_dir.exists():
        return False
    need_xbox = check(bin_dir / "default.xbe") == "missing"
    need_proto = check(bin_dir / "game.xbe") == "missing"
    pc_state = check(bin_dir / "Scarface.exe")
    patch = _patch_installer(bin_dir) if pc_state != "ok" else None
    need_pc = bool(patch and _exe_in_patch(patch)) and (pc_state == "missing" or _patch_has_accepted_exe(patch))
    if not (need_xbox or need_proto or need_pc):
        return False
    sources = _candidates(bin_dir)
    packed = [s for s in sources if s.name.lower().endswith(ARCHIVES + DISC_IMAGES) or s.parent != bin_dir]
    if not need_pc:
        if need_xbox and not packed:
            return False                        # nothing to unpack; the banner below says what is missing
        if not need_xbox and not any("proto" in str(s.relative_to(bin_dir)).lower() for s in packed):
            return False                        # only the optional prototype is missing, and it isn't here
    log("[*] Getting the game files out of the downloads in binaries/ (only needed once)...")
    prepare(bin_dir, log)                       # this also gives the PC steps when they apply
    return True


def pc_help(bin_dir: Path, log: Log = print) -> None:
    """At portal start: if there is no usable Scarface.exe but the PC download or patch is in binaries/,
    take a patched copy from the installed game if there is one, or say exactly what to do. The PC disc
    image can't be used on its own (it holds the game before the 1.00.2 patch), and neither can a patch whose
    Scarface.exe can't be read; then the game has to be installed and patched."""
    bin_dir = Path(bin_dir)
    exe = bin_dir / "Scarface.exe"
    if exe.exists():
        return                                   # accepted, or refused with its own message
    patch, disc = _patch_installer(bin_dir), _pc_disc_in(bin_dir)
    if not (patch or disc):
        return
    hit = _installed_pc_exe()
    if hit and check(hit) == "ok":
        _place(exe, hit, log, f"your installed, patched game ({hit.parent})")
        return
    for line in _pc_steps(disc, patch):
        log(line)


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
    note = "" if state == "ok" else "  (not the accepted version; see below)"
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

def _is_zip(p: Path) -> bool:
    """A .zip, or a program with a zip inside (like the PC game's 1.00.2 patch)."""
    low = p.name.lower()
    if low.endswith(".zip"):
        return True
    if low.endswith(".exe") and low != "scarface.exe":
        try:
            return zipfile.is_zipfile(p)
        except OSError:
            return False
    return False


def _is_archive(p: Path) -> bool:
    return p.name.lower().endswith(".7z") or _is_zip(p)


def _seven_zip_program() -> Optional[str]:
    """The 7-Zip program, if it is installed (only needed for unusual .7z files)."""
    for name in ("7z", "7za", "7zz"):
        hit = shutil.which(name)
        if hit:
            return hit
    for root in filter(None, {os.environ.get(k) for k in ("ProgramFiles", "ProgramFiles(x86)", "ProgramW6432")}):
        exe = Path(root) / "7-Zip" / "7z.exe"
        if exe.exists():
            return str(exe)
    return None


NO_7Z = ("this .7z uses a kind of compression the portal can't read by itself; install 7-Zip "
         "(7-zip.org) and start the portal again, or unpack the .7z and put the .iso in binaries/")


def _members(archive: Path) -> List[Tuple[str, int]]:
    if _is_zip(archive):
        with zipfile.ZipFile(archive) as z:
            return [(i.filename, i.file_size) for i in z.infolist() if not i.is_dir()]
    try:
        with sevenzip.SevenZip(archive) as z:
            return z.members()
    except sevenzip.Unsupported:
        pass
    exe = _seven_zip_program()
    if exe:
        out = subprocess.run([exe, "l", "-slt", "-ba", str(archive)], capture_output=True, text=True,
                             errors="replace").stdout
        found, name, size, is_dir = [], None, 0, False
        for line in out.splitlines() + [""]:
            if line.startswith("Path = "):
                name = line[7:]
            elif line.startswith("Size = "):
                size = int(line[7:] or 0)
            elif line.startswith("Attributes = ") and "D" in line[13:].split(" ")[0]:
                is_dir = True
            elif not line.strip() and name is not None:
                if not is_dir:
                    found.append((name.replace("\\", "/"), size))
                name, size, is_dir = None, 0, False
        return found
    py7zr = _py7zr()
    with py7zr.SevenZipFile(archive) as z:
        return [(i.filename, i.uncompressed) for i in z.list() if not i.is_directory]


def _py7zr():
    try:
        import py7zr  # noqa: F401
        return py7zr
    except ImportError:
        raise RuntimeError(NO_7Z)


def _read_member(archive: Path, member: str) -> bytes:
    if _is_zip(archive):
        with zipfile.ZipFile(archive) as z:
            return z.read(member)
    try:
        with sevenzip.SevenZip(archive) as z:
            return z.read(member)
    except sevenzip.Unsupported:
        pass
    exe = _seven_zip_program()
    if exe:
        return subprocess.run([exe, "e", "-so", str(archive), member], capture_output=True).stdout
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
            if _is_zip(archive):
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
    try:
        with sevenzip.SevenZip(archive) as z, z.open(member) as f:
            _pull(stream, f, size, log, what)
        return
    except sevenzip.Unsupported:
        pass
    exe = _seven_zip_program()
    if exe:
        proc = subprocess.Popen([exe, "e", "-so", str(archive), member], stdout=subprocess.PIPE,
                                stderr=subprocess.DEVNULL)
        try:
            _pull(stream, proc.stdout, size, log, what)
        finally:
            proc.kill()
            proc.wait()
        return
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
    patch = _patch_installer(bin_dir)
    if status["Scarface.exe"] == "different" and patch and _patch_has_accepted_exe(patch):
        aside = _free_name(bin_dir / "Scarface.exe.not-used")
        os.replace(bin_dir / "Scarface.exe", aside)
        log(f"    - Scarface.exe was not the accepted 1.00.2 copy; moved it to {aside.name}")
        status["Scarface.exe"] = "missing"
    missing = [n for n, s in status.items() if s == "missing"]
    pc_disc = None
    if missing:
        sources = _candidates(bin_dir)
        for src in sources:
            if src.name.lower().endswith(DISC_IMAGES) and _is_pc_disc(src):
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


def _patch_has_accepted_exe(patch: Path) -> bool:
    member = _exe_in_patch(patch)
    if not member:
        return False
    try:
        data = _read_member(patch, member)
    except Exception:  # noqa: BLE001
        return False
    return hashlib.sha256(data).hexdigest() in EXPECTED["Scarface.exe"][0]


def _free_name(path: Path) -> Path:
    if not path.exists():
        return path
    k = 2
    while path.with_name(f"{path.name}.{k}").exists():
        k += 1
    return path.with_name(f"{path.name}.{k}")


def _from_sources(name: str, sources: List[Path], bin_dir: Path, log: Log) -> bool:
    dest = bin_dir / name
    # 1. the file itself, one folder down (someone unzipped the prototype into binaries/)
    for src in sources:
        if src.name.lower() == name.lower() and src.parent != bin_dir:
            _place(dest, src, log, str(src.relative_to(bin_dir)))
            return True
    # 2. an archive holding the file directly (for Scarface.exe, also the 1.00.2 patch)
    for src in sources:
        if not _is_archive(src):
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
        except Exception as e:  # noqa: BLE001
            log(f"    ! could not open {src.name}: {e}")
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
            log(f"  {name:<13} NOT USED: it is not the {what} copy this project uses.")
            log(f"  {'':<13} It is {describe(bin_dir / name)}.")
            log(f"  {'':<13} Only the {what} copy is accepted; see {GUIDE}.")
    if all(status[n] == "missing" for n in REQUIRED_ONE_OF):
        log("")
        log("  No game files yet, so the portal has nothing to show.")
        log("  Put the Xbox game in the binaries folder and start the portal again: default.xbe, or the")
        log("  Xbox disc image (.iso, or the .7z / .zip it came in). That is where almost all of the work is.")
        log("  Optional: the PC game's Scarface.exe, version 1.00.2 (see below), for the PC-only functions.")
    if status["Scarface.exe"] == "missing" and (pc_disc or patch):
        log("")
        for line in _pc_steps(pc_disc, patch):
            log(line)


def _pc_steps(pc_disc: Optional[Path], patch: Optional[Path]) -> List[str]:
    if not patch:
        return [
            "  For the PC functions (optional): put the official 1.00.2 patch in the binaries folder and",
            "  start the portal again. It takes the right Scarface.exe straight out of the patch; nothing",
            "  has to be installed. The PC disc image on its own only has the older 1.00 version.",
        ]
    return [
        f"  For the PC functions (optional), Scarface.exe couldn't be read out of {patch.name}.",
        "  Install the game, run the patch to update it, then copy Scarface.exe from the game's install",
        "  folder into the binaries folder. The portal also looks in Program Files for a patched copy",
        "  each time it starts, and uses it if it finds one.",
    ]


def main() -> int:
    root = Path(__file__).resolve().parents[2]           # the project folder
    status = prepare(root / "binaries")
    return 0 if any(status[n] != "missing" for n in REQUIRED_ONE_OF) else 1


if __name__ == "__main__":
    sys.exit(main())
