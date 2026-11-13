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

The hash is the name's (name_hash, from the clean-room spec docs/cleanroom/SPEC-004-xbox-functions.md; the
Xbox game's sub_00251310). Opening an archive checks that every name hashes to the entry it is paired with by
offset; where one doesn't, the names are paired by hash instead, with a warning (RcfWarning). find_name finds
an entry by its path through the hash, as the game does.

Only reading is implemented. Nothing here writes or changes an archive.
"""

from __future__ import annotations

import struct
import warnings
from dataclasses import dataclass
from pathlib import Path, PureWindowsPath
from typing import BinaryIO, Dict, Iterable, Iterator, List, Optional, Sequence

MAGIC = b"ATG CORE CEMENT LIBRARY"
SCRIPT_EXTENSIONS = (".cso", ".dso", ".dtr", ".cs", ".ds")


class RcfError(ValueError):
    pass


class RcfWarning(UserWarning):
    """An archive whose names don't all hash to the directory entries they are paired with by offset."""


def name_hash(path: str) -> int:
    """The 32-bit number an archive's directory is sorted by, from a path as the name table has it (with
    backslashes): one leading backslash skipped, then for each character, taken as a signed byte, 0x20 added
    when it is below 'a' (0x61), and hash = hash * 31 + that, kept to 32 bits. 0 for an empty path. (SPEC-004
    section 1; the Xbox game's sub_00251310.)"""
    raw = path.encode("latin-1", "replace")
    if raw[:1] == b"\\":
        raw = raw[1:]
    h = 0
    for b in raw:
        c = b - 256 if b >= 0x80 else b
        if c < 0x61:
            c += 0x20
        h = (h * 31 + c) & 0xFFFFFFFF
    return h


def pair_names(directory: Sequence[tuple], names: Sequence[str]) -> tuple:
    """Which directory entry each name belongs to: (indexes into directory, one per name; how many names were
    paired by hash). directory is (hash, offset, size) in name order (by offset). When every name hashes to the
    entry at its own place, that is the pairing (0 by hash). Otherwise each name takes an unused entry with its
    hash (its own place first), and the names that match none take the entries left over, in order."""
    own = list(range(min(len(directory), len(names))))
    if all(name_hash(names[i]) == directory[i][0] for i in own):
        return own, 0
    by_hash: Dict[int, List[int]] = {}
    for j, (h, _off, _size) in enumerate(directory):
        by_hash.setdefault(h, []).append(j)
    used, chosen = set(), []
    for i, name in enumerate(names[:len(directory)]):
        free = [j for j in by_hash.get(name_hash(name), []) if j not in used]
        j = (i if i in free else free[0]) if free else None
        if j is not None:
            used.add(j)
        chosen.append(j)
    hashed = sum(1 for j in chosen if j is not None)
    left = iter(j for j in range(len(directory)) if j not in used)
    return [j if j is not None else next(left) for j in chosen], hashed


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
        order, self.paired_by_hash = pair_names(directory, [n for n, _d in names])
        if self.paired_by_hash or any(name_hash(n) != directory[j][0] for (n, _d), j in zip(names, order)):
            wrong = sum(1 for i, (n, _d) in enumerate(names[:len(directory)]) if name_hash(n) != directory[i][0])
            unpaired = sum(1 for (n, _d), j in zip(names, order) if name_hash(n) != directory[j][0])
            warnings.warn(f"{wrong} of {count} names don't hash to the entry they are paired with by offset: "
                          f"{self.paired_by_hash} paired by their hash instead"
                          + (f", {unpaired} kept by offset (no entry has their hash)" if unpaired else ""),
                          RcfWarning, stacklevel=2)
        self.entries: List[RcfEntry] = []
        for (name, date), j in zip(names, order):
            h, off, size = directory[j]
            if off + size > self.file_size:
                raise RcfError(f"{name}: data runs past the end of the archive")
            self.entries.append(RcfEntry(name, off, size, h, date))
        self._by_hash: Dict[int, List[RcfEntry]] = {}
        for e in self.entries:
            self._by_hash.setdefault(e.hash, []).append(e)

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

    def find_name(self, path: str) -> Optional[RcfEntry]:
        """The entry for a path inside the archive (with backslashes or slashes, a leading one or not), found
        through its hash as the game finds it, so letter case doesn't matter. Where two entries share the
        hash, the one with that name. None when the archive has no entry with the hash."""
        want = path.replace("/", "\\")
        hits = self._by_hash.get(name_hash(want), [])
        bare = want[1:] if want.startswith("\\") else want
        return next((e for e in hits if e.name.lstrip("\\").lower() == bare.lower()), hits[0] if hits else None)


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


def build_rcf(files: List[tuple], hashes: Optional[Sequence[int]] = None,
              name_order: Optional[Sequence[int]] = None) -> bytes:
    """A small, valid archive from [(name, data)], for tests. Mirrors the layout read above: the data in the
    order given, the directory sorted by each name's hash (name_hash; hashes overrides them), the names in the
    data's order unless name_order gives another (indexes into files)."""
    count = len(files)
    header_size = 60
    names = bytearray(8)
    for k in (name_order if name_order is not None else range(count)):
        raw = files[k][0].encode("latin-1")
        names += struct.pack("<4I", 0x45000000, 0, 0, len(raw) + 1) + raw + b"\0" * 4
    dir_off = 2048
    names_off = dir_off + 12 * count
    data_off = (names_off + len(names) + 2047) // 2048 * 2048
    blob = bytearray()
    entries = []
    for i, (name, data) in enumerate(files):
        entries.append((hashes[i] if hashes is not None else name_hash(name), data_off + len(blob), len(data)))
        blob += data + b"\0" * (-len(data) % 2048)
    directory = b"".join(struct.pack("<3I", *e) for e in sorted(entries))
    out = bytearray(MAGIC.ljust(32, b"\0"))
    out += struct.pack("<7I", 0x00020001, dir_off, len(directory), names_off, len(names), 0, count)
    out += b"\0" * (dir_off - len(out)) + directory + names
    out += b"\0" * (data_off - len(out)) + blob
    assert len(out) >= header_size
    return bytes(out)
