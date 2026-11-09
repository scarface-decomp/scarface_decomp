#!/usr/bin/env python3
"""
Read Microsoft cabinet files (.cab) with nothing but the Python standard library: one cabinet, or a
set that spans several (the PC game's Data1.cab and Data11.cab), stored or MSZIP-compressed.

Used to take the PC game's files off its disc without installing it (portal/tools/game_assets.py).
Quantum and LZX compression are not supported; a cabinet that uses them is reported as such.

Layout (Microsoft's cabinet format, MS-CAB), all little-endian:

    CFHEADER   "MSCF", size, offset of the file list, version, folder and file counts, flags, set id,
               index in the set; optional reserved areas; names of the previous/next cabinet
    CFFOLDER   per folder: where its data blocks start, how many there are, the compression
    CFFILE     per file: size, offset in its folder's uncompressed data, folder, date, attributes, name
    CFDATA     per block: checksum, compressed size, uncompressed size (0 = the block continues in the
               next cabinet), then the data. MSZIP data is "CK" + a deflate stream that may refer back
               to the previous block's output.

A folder can run on into the next cabinet of a set: its rest is that cabinet's first folder, and a
file that starts before the break is listed in both cabinets (here it is taken from the first).
"""

from __future__ import annotations

import struct
import zlib
from dataclasses import dataclass
from typing import BinaryIO, Callable, Iterator, List, Optional, Sequence, Tuple

FROM_PREV, TO_NEXT, PREV_AND_NEXT = 0xFFFD, 0xFFFE, 0xFFFF
HAS_PREV, HAS_NEXT, HAS_RESERVE = 1, 2, 4
NAME_IS_UTF8 = 0x80
WINDOW = 32768


class CabError(ValueError):
    pass


def checksum(data: bytes, seed: int = 0) -> int:
    """The cabinet checksum: the XOR of the data's 32-bit little-endian words, the last 1-3 bytes taken
    high byte first (as Microsoft's code does)."""
    n4 = len(data) // 4 * 4
    x, words = int.from_bytes(data[:n4], "little"), n4 // 4
    while words > 1:                                  # XOR the two halves until one word is left
        half = (words + 1) // 2
        x = (x & ((1 << (32 * half)) - 1)) ^ (x >> (32 * half))
        words = half
    rest, ul = data[n4:], 0
    for b in rest:
        ul = (ul << 8) | b
    return seed ^ x ^ ul


@dataclass
class CabFile:
    name: str
    size: int
    offset: int        # where it starts in its folder's uncompressed data
    folder: int        # the folder, counted across the whole set
    attribs: int


class _Cabinet:
    def __init__(self, f: BinaryIO, base: int, label: str):
        self.f, self.base, self.label = f, base, label
        head = self.read(0, 36)
        if len(head) < 36 or head[:4] != b"MSCF":
            raise CabError(f"{label}: not a cabinet file")
        (self.size,) = struct.unpack_from("<I", head, 8)
        (files_at,) = struct.unpack_from("<I", head, 16)
        _vmin, _vmaj, n_folders, n_files, self.flags, self.set_id, self.index = struct.unpack_from("<BBHHHHH", head, 24)
        pos, self.res_folder, self.res_data = 36, 0, 0
        if self.flags & HAS_RESERVE:
            res_header, self.res_folder, self.res_data = struct.unpack("<HBB", self.read(36, 4))
            pos = 40 + res_header
        strings = (2 if self.flags & HAS_PREV else 0) + (2 if self.flags & HAS_NEXT else 0)
        if strings:                                   # previous / next cabinet and disk names
            area, k = self.read(pos, 1024), 0
            for _ in range(strings):
                end = area.find(b"\0", k)
                if end < 0:
                    raise CabError(f"{label}: bad header")
                k = end + 1
            pos += k
        table = self.read(pos, n_folders * (8 + self.res_folder))
        self.folders: List[Tuple[int, int, int]] = []          # (where its blocks start, how many, compression)
        for i in range(n_folders):
            self.folders.append(struct.unpack_from("<IHH", table, i * (8 + self.res_folder)))
        first_data = min((off for off, _n, _t in self.folders), default=self.size)
        listing = self.read(files_at, max(0, first_data - files_at) or 65536)
        self.files: List[Tuple[str, int, int, int, int]] = []   # (name, size, offset, folder, attributes)
        p = 0
        for _ in range(n_files):
            if p + 16 > len(listing):
                listing += self.read(files_at + len(listing), 65536)
            size, offset, folder, _date, _time, attribs = struct.unpack_from("<IIHHHH", listing, p)
            end = listing.find(b"\0", p + 16)
            while end < 0:
                more = self.read(files_at + len(listing), 65536)
                if not more:
                    raise CabError(f"{label}: the file list ends early")
                listing += more
                end = listing.find(b"\0", p + 16)
            raw = listing[p + 16:end]
            name = raw.decode("utf-8" if attribs & NAME_IS_UTF8 else "latin-1", "replace")
            self.files.append((name, size, offset, folder, attribs))
            p = end + 1

    def read(self, off: int, n: int) -> bytes:
        self.f.seek(self.base + off)
        return self.f.read(n)


class CabSet:
    """One cabinet or a set of them, given in any order as (file object, where the cabinet starts in
    it, a name for messages)."""

    def __init__(self, volumes: Sequence[Tuple[BinaryIO, int, str]]):
        cabs = sorted((_Cabinet(*v) for v in volumes), key=lambda c: c.index)
        if not cabs:
            raise CabError("no cabinet files")
        for i, c in enumerate(cabs):
            if c.set_id != cabs[0].set_id:
                raise CabError(f"{c.label} belongs to another set of cabinets")
            if c.index != cabs[0].index + i:
                raise CabError(f"a cabinet is missing before {c.label}")
        if cabs[0].flags & HAS_PREV:
            raise CabError(f"{cabs[0].label} is not the first cabinet of its set")
        self.cabs = cabs
        self.pieces: List[List[Tuple[int, int, int]]] = []   # per folder: (cabinet, where its blocks start, how many)
        self.kinds: List[int] = []
        where = {}
        for ci, c in enumerate(cabs):
            continues = ci > 0 and any(f[3] in (FROM_PREV, PREV_AND_NEXT) for f in c.files)
            for fi, (off, n, kind) in enumerate(c.folders):
                if fi == 0 and continues:
                    if not self.pieces:
                        raise CabError(f"{c.label} continues a folder no earlier cabinet has")
                    self.pieces[-1].append((ci, off, n))
                else:
                    self.pieces.append([(ci, off, n)])
                    self.kinds.append(kind)
                where[(ci, fi)] = len(self.pieces) - 1
        self.files: List[CabFile] = []
        for ci, c in enumerate(cabs):
            for name, size, offset, folder, attribs in c.files:
                if folder in (FROM_PREV, PREV_AND_NEXT):
                    continue                    # it starts in the cabinet before, where it is listed too
                fi = len(c.folders) - 1 if folder == TO_NEXT else folder
                if (ci, fi) not in where:
                    raise CabError(f"{c.label}: {name} is in a folder that isn't there")
                self.files.append(CabFile(name, size, offset, where[(ci, fi)], attribs))
        last = cabs[-1]
        if last.flags & HAS_NEXT and any(f[3] in (TO_NEXT, PREV_AND_NEXT) for f in last.files):
            raise CabError(f"the cabinet after {last.label} is missing")

    def folder_files(self, folder: int) -> List[CabFile]:
        return sorted((f for f in self.files if f.folder == folder), key=lambda f: f.offset)

    def compressed_size(self) -> int:
        return sum(c.size for c in self.cabs)

    def chunks(self, folder: int, progress: Optional[Callable[[int], None]] = None,
               verify: bool = True) -> Iterator[bytes]:
        """A folder's uncompressed data, block by block (at most 32 KB each)."""
        kind = self.kinds[folder] & 0x0F
        if kind not in (0, 1):
            name = {2: "Quantum", 3: "LZX"}.get(kind, f"type {kind}")
            raise CabError(f"this cabinet uses {name} compression, which the portal can't read")
        history, pending = b"", b""
        for ci, off, n in self.pieces[folder]:
            cab = self.cabs[ci]
            head_len = 8 + cab.res_data
            pos = off
            for _ in range(n):
                head = cab.read(pos, head_len)
                if len(head) < head_len:
                    raise CabError(f"{cab.label} ends early")
                csum, packed, size = struct.unpack_from("<IHH", head)
                data = cab.read(pos + head_len, packed)
                if len(data) != packed:
                    raise CabError(f"{cab.label} ends early")
                if verify and csum and checksum(head[4:8], checksum(data)) != csum:
                    raise CabError(f"{cab.label}: a block's checksum is wrong (the file is damaged)")
                pos += head_len + packed
                if progress:
                    progress(head_len + packed)
                if size == 0:                   # the block goes on in the next cabinet
                    pending += data
                    continue
                data, pending = pending + data, b""
                if kind == 0:
                    out = data
                else:
                    if data[:2] != b"CK":
                        raise CabError(f"{cab.label}: an MSZIP block without its CK mark")
                    try:
                        d = zlib.decompressobj(-15, zdict=history) if history else zlib.decompressobj(-15)
                        out = d.decompress(data[2:]) + d.flush()
                    except zlib.error as e:
                        raise CabError(f"{cab.label}: a block could not be unpacked ({e})") from None
                if len(out) != size:
                    raise CabError(f"{cab.label}: a block unpacked to {len(out)} bytes, not {size}")
                history = (history + out)[-WINDOW:]
                yield out
        if pending:
            raise CabError("the last block of a folder is cut off (is a cabinet of the set missing?)")


def _blocks(stream: bytes, kind: int, block: int) -> List[Tuple[bytes, int]]:
    out, history = [], b""
    for i in range(0, len(stream), block):
        raw = stream[i:i + block]
        if kind == 1:
            c = zlib.compressobj(9, zlib.DEFLATED, -15, zdict=history) if history else zlib.compressobj(9, zlib.DEFLATED, -15)
            out.append((b"CK" + c.compress(raw) + c.flush(), len(raw)))
        else:
            out.append((raw, len(raw)))
        history = (history + raw)[-WINDOW:]
    return out


def _cabinet(index: int, last: bool, folders: List[List[Tuple[bytes, int]]], entries, kind: int, set_id: int) -> bytes:
    flags = (HAS_PREV if index else 0) | (HAS_NEXT if not last else 0)
    strings = (b"Data1.cab\0DISK1\0" if index else b"") + (b"" if last else b"Data11.cab\0DISK1\0")
    file_list = b"".join(struct.pack("<IIHHHH", size, off, folder, 0x3C21, 0, 0x20) + name.encode() + b"\0"
                         for name, size, off, folder in entries)
    files_at = 36 + len(strings) + 8 * len(folders)
    pos = files_at + len(file_list)
    table, blob = b"", b""
    for blocks in folders:
        table += struct.pack("<IHH", pos + len(blob), len(blocks), kind)
        for data, size in blocks:
            head = struct.pack("<HH", len(data), size)
            blob += struct.pack("<I", checksum(head, checksum(data))) + head + data
    header = (b"MSCF" + struct.pack("<IIIII", 0, pos + len(blob), 0, files_at, 0)
              + struct.pack("<BBHHHHH", 3, 1, len(folders), len(entries), flags, set_id, index))
    return header + strings + table + file_list + blob


def write_cabinets(files: Sequence[Tuple[str, bytes]], split_in: Optional[int] = None, cut: int = 500, kind: int = 1,
                   block: int = WINDOW, set_id: int = 1111) -> List[bytes]:
    """Cabinets holding `files`, for tests; mirrors the reader above. With split_in, the set is two
    cabinets laid out like the PC game's: the first ends inside files[split_in], `cut` bytes into a
    compressed block (real sets always split inside a block), and the second goes on with the rest of that
    file, then a new folder with the files after it."""
    if split_in is None:
        blocks = _blocks(b"".join(d for _n, d in files), kind, block)
        entries, pos = [], 0
        for name, data in files:
            entries.append((name, len(data), pos, 0))
            pos += len(data)
        return [_cabinet(0, True, [blocks], entries, kind, set_id)]
    first, after = files[:split_in + 1], files[split_in + 1:]
    starts, pos = [], 0
    for _n, data in first:
        starts.append(pos)
        pos += len(data)
    blocks = _blocks(b"".join(d for _n, d in first), kind, block)
    span_start, span_len = starts[-1], len(first[-1][1])
    k = (span_start + span_len // 2) // block
    if not (span_start < k * block < span_start + span_len):
        raise ValueError("files[split_in] must be at least two blocks long")
    head_part, tail_part = list(blocks[:k]), list(blocks[k:])
    if cut:
        data, size = tail_part[0]
        head_part.append((data[:cut], 0))
        tail_part[0] = (data[cut:], size)
    entries0 = [(n, len(d), off, 0) for (n, d), off in zip(first[:-1], starts[:-1])]
    entries0.append((first[-1][0], span_len, span_start, TO_NEXT))
    entries1 = [(first[-1][0], span_len, span_start, FROM_PREV)]
    folders1 = [tail_part]
    if after:
        pos = 0
        for name, data in after:
            entries1.append((name, len(data), pos, 1))
            pos += len(data)
        folders1.append(_blocks(b"".join(d for _n, d in after), kind, block))
    return [_cabinet(0, False, [head_part], entries0, kind, set_id),
            _cabinet(1, True, folders1, entries1, kind, set_id)]
