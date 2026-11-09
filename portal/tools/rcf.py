#!/usr/bin/env python3
"""
Read Radcore Cement Library archives (.rcf), the containers Scarface keeps its files in.

The game's scripts are inside `cement.rcf` (in the PC install folder, and on the Xbox and PS2 discs),
under `scriptc\\`: compiled TorqueScript (`.cso`, `.dso`) and the `.dtr` files that go with them.

Layout (little-endian), as documented by the community ToolKit (STWIY/ToolKit, `FileHandlers/rcf/RCF.h`):

    header       32 bytes "ATG CORE CEMENT LIBRARY" (NUL padded), then 7 x u32:
                 unknown, directory offset, directory size, names offset, names size, unknown, file count
    directory    file count x (u32 hash, u32 offset, u32 size), sorted by hash
    names        at names offset + 8: file count x (u32 date, u32, u32, u32 length, name[length - 1], 4 bytes)
                 in the order the files are stored, so name i belongs to the i-th directory entry by offset

Only reading is implemented. Nothing here writes or changes an archive.
"""

from __future__ import annotations

import struct
from dataclasses import dataclass
from pathlib import Path, PureWindowsPath
from typing import BinaryIO, Iterable, Iterator, List, Optional

MAGIC = b"ATG CORE CEMENT LIBRARY"
SCRIPT_EXTENSIONS = (".cso", ".dso", ".dtr", ".cs", ".ds")


class RcfError(ValueError):
    pass


@dataclass(frozen=True)
class RcfEntry:
    name: str        # path inside the archive, with backslashes as stored
    offset: int
    size: int
    hash: int
    date: int

    @property
    def parts(self) -> tuple:
        return PureWindowsPath(self.name).parts


class RcfArchive:
    def __init__(self, f: BinaryIO, base: int = 0):
        self.f = f
        self.base = base
        self.f.seek(0, 2)
        self.file_size = self.f.tell() - base
        head = self._read(0, 60)
        if len(head) < 60 or not head.startswith(MAGIC):
            raise RcfError("not a Radcore Cement Library (.rcf) file")
        (_unk1, dir_off, _dir_size, names_off, _names_size, _unk2, count) = struct.unpack_from("<7I", head, 32)
        if not (0 < count < 1_000_000) or dir_off + 12 * count > self.file_size or names_off > self.file_size:
            raise RcfError(f"unexpected header (count={count}, directory at {dir_off}, names at {names_off})")
        table = self._read(dir_off, 12 * count)
        # In name order: by where the data starts, and an empty file first when it starts where the next one does
        directory = sorted((struct.unpack_from("<3I", table, 12 * i) for i in range(count)), key=lambda e: (e[1], e[2]))
        names = []
        pos = names_off + 8
        for _ in range(count):
            date, _u2, _u3, length = struct.unpack("<4I", self._read(pos, 16))
            if not (1 <= length <= 1024):
                raise RcfError(f"bad name length {length} at {pos + 12}")
            raw = self._read(pos + 16, length - 1)
            names.append((raw.decode("latin-1"), date))
            pos += 16 + length + 3
        self.entries: List[RcfEntry] = []
        for (h, off, size), (name, date) in zip(directory, names):
            if off + size > self.file_size:
                raise RcfError(f"{name}: data runs past the end of the archive")
            self.entries.append(RcfEntry(name, off, size, h, date))

    def close(self) -> None:
        self.f.close()

    def __enter__(self) -> "RcfArchive":
        return self

    def __exit__(self, *exc) -> None:
        self.close()

    def _read(self, off: int, n: int) -> bytes:
        self.f.seek(self.base + off)
        return self.f.read(n)

    def read(self, entry: RcfEntry) -> bytes:
        return self._read(entry.offset, entry.size)

    def find(self, suffixes: Iterable[str] = SCRIPT_EXTENSIONS) -> Iterator[RcfEntry]:
        suffixes = tuple(s.lower() for s in suffixes)
        return (e for e in self.entries if e.name.lower().endswith(suffixes))


def open_rcf(path: Path) -> RcfArchive:
    """An .rcf file, or the CEMENT.RCF inside a disc image (.iso, ISO 9660, as on the PS2 disc)."""
    f = open(path, "rb")
    try:
        if path.suffix.lower() == ".iso":
            hit = find_in_iso(f, "CEMENT.RCF")
            if hit is None:
                raise RcfError("no CEMENT.RCF on this disc image (the PC disc keeps it inside DATA*.CAB; "
                               "use cement.rcf from an installed copy instead)")
            return RcfArchive(f, base=hit[0])
        return RcfArchive(f)
    except BaseException:
        f.close()           # Windows cannot delete a file that is still open (WinError 32)
        raise


def find_in_iso(f: BinaryIO, name: str, sector: int = 2048):
    """(byte offset, size) of a file anywhere in an ISO 9660 image, by file name; None if absent."""
    f.seek(16 * sector)
    pvd = f.read(sector)
    if pvd[1:6] != b"CD001":
        raise RcfError("not an ISO 9660 disc image")
    want = name.upper()
    todo = [(struct.unpack_from("<I", pvd, 158)[0], struct.unpack_from("<I", pvd, 166)[0])]
    seen = set()
    while todo:
        lba, size = todo.pop()
        if lba in seen or size > 64 * 1024 * 1024:
            continue
        seen.add(lba)
        f.seek(lba * sector)
        data = f.read(size)
        i = 0
        while i < len(data):
            n = data[i]
            if n == 0:
                i = (i // sector + 1) * sector
                continue
            rec = data[i:i + n]
            ext, sz, flags, nl = struct.unpack_from("<I", rec, 2)[0], struct.unpack_from("<I", rec, 10)[0], rec[25], rec[32]
            ident = rec[33:33 + nl]
            if ident not in (b"\0", b"\1"):
                if flags & 2:
                    todo.append((ext, sz))
                elif ident.decode("latin-1").split(";")[0].upper() == want:
                    return ext * sector, sz
            i += n
    return None


def safe_output_path(root: Path, name: str) -> Optional[Path]:
    """Where an archive member goes under root; None for names that would escape it."""
    parts = [p for p in PureWindowsPath(name.replace("/", "\\")).parts if p not in ("", "\\")]
    if not parts or any(p in (".", "..") or ":" in p for p in parts):
        return None
    out = root.joinpath(*parts)
    try:
        out.resolve().relative_to(root.resolve())
    except ValueError:
        return None
    return out


def build_rcf(files: List[tuple]) -> bytes:
    """A small, valid archive from [(name, data)], for tests. Mirrors the layout read above."""
    count = len(files)
    header_size = 60
    names = bytearray(8)
    for name, _data in files:
        raw = name.encode("latin-1")
        names += struct.pack("<4I", 0x45000000, 0, 0, len(raw) + 1) + raw + b"\0" * 4
    dir_off = 2048
    names_off = dir_off + 12 * count
    data_off = (names_off + len(names) + 2047) // 2048 * 2048
    blob = bytearray()
    entries = []
    for i, (name, data) in enumerate(files):
        entries.append(((0x9E3779B1 * (i + 7)) & 0xFFFFFFFF, data_off + len(blob), len(data)))
        blob += data + b"\0" * (-len(data) % 2048)
    directory = b"".join(struct.pack("<3I", *e) for e in sorted(entries))
    out = bytearray(MAGIC.ljust(32, b"\0"))
    out += struct.pack("<7I", 0x00020001, dir_off, len(directory), names_off, len(names), 0, count)
    out += b"\0" * (dir_off - len(out)) + directory + names
    out += b"\0" * (data_off - len(out)) + blob
    assert len(out) >= header_size
    return bytes(out)
