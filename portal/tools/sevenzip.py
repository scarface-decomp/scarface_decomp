#!/usr/bin/env python3
"""
A small .7z reader that needs nothing beyond Python itself.

The portal only ever needs one file out of a game download (default.xbe or cement.rcf from the disc
image packed inside), so this reads the archive's index and streams a single member out, without
unpacking anything else to disk. It handles what game downloads use: LZMA, LZMA2, the x86 (BCJ) and
other branch filters, Delta, Deflate, BZip2 and stored files, solid or not, with or without a
compressed index. Anything else (PPMd, BCJ2, encrypted archives) raises Unsupported, and the caller
falls back to py7zr or the 7-Zip program if one is installed.

    with SevenZip(path) as z:
        z.members()                    # [(name, size), ...]
        with z.open(name) as f:        # a file-like object: f.read(n)
            ...
"""

from __future__ import annotations

import bz2
import io
import lzma
import struct
import zlib
from pathlib import Path
from typing import BinaryIO, Dict, List, Optional, Tuple

SIGNATURE = b"7z\xbc\xaf\x27\x1c"
CHUNK = 1 << 20


class Unsupported(Exception):
    """The archive uses something this reader does not handle."""


class _Buf:
    def __init__(self, data: bytes):
        self.d, self.p = data, 0

    def byte(self) -> int:
        if self.p >= len(self.d):
            raise Unsupported("the archive's index ends early")
        b = self.d[self.p]
        self.p += 1
        return b

    def take(self, n: int) -> bytes:
        if self.p + n > len(self.d):
            raise Unsupported("the archive's index ends early")
        out = self.d[self.p:self.p + n]
        self.p += n
        return out

    def num(self) -> int:
        first = self.byte()
        mask, value = 0x80, 0
        for i in range(8):
            if not first & mask:
                return value | ((first & (mask - 1)) << (8 * i))
            value |= self.byte() << (8 * i)
            mask >>= 1
        return value

    def bits(self, n: int) -> List[bool]:
        out, cur, mask = [], 0, 0
        for _ in range(n):
            if mask == 0:
                cur, mask = self.byte(), 0x80
            out.append(bool(cur & mask))
            mask >>= 1
        return out

    def defined(self, n: int) -> List[bool]:
        all_defined = self.byte()
        return [True] * n if all_defined else self.bits(n)


class _Coder:
    def __init__(self, method: bytes, n_in: int, n_out: int, props: bytes):
        self.method, self.n_in, self.n_out, self.props = method, n_in, n_out, props


class _Folder:
    def __init__(self):
        self.coders: List[_Coder] = []
        self.bind_pairs: List[Tuple[int, int]] = []
        self.packed: List[int] = []
        self.unpack_sizes: List[int] = []

    def main_size(self) -> int:
        bound = {out for _in, out in self.bind_pairs}
        for i, size in enumerate(self.unpack_sizes):
            if i not in bound:
                return size
        return self.unpack_sizes[-1] if self.unpack_sizes else 0


class _Streams:
    def __init__(self):
        self.pack_pos = 0
        self.pack_sizes: List[int] = []
        self.folders: List[_Folder] = []
        self.sub_counts: List[int] = []
        self.sub_sizes: List[int] = []
        self.folder_crc: List[bool] = []


def _read_streams(b: _Buf) -> _Streams:
    s = _Streams()
    while True:
        prop = b.byte()
        if prop == 0x00:
            break
        if prop == 0x06:                                    # pack info
            s.pack_pos = b.num()
            n = b.num()
            while True:
                p = b.byte()
                if p == 0x00:
                    break
                if p == 0x09:
                    s.pack_sizes = [b.num() for _ in range(n)]
                elif p == 0x0A:
                    d = b.defined(n)
                    b.take(4 * sum(d))
                else:
                    raise Unsupported(f"pack info property {p}")
        elif prop == 0x07:                                  # folders
            if b.byte() != 0x0B:
                raise Unsupported("folder list expected")
            nf = b.num()
            if b.byte() != 0:
                raise Unsupported("external folder list")
            for _ in range(nf):
                f = _Folder()
                n_in = n_out = 0
                for _c in range(b.num()):
                    flags = b.byte()
                    method = b.take(flags & 0x0F)
                    ci, co = (b.num(), b.num()) if flags & 0x10 else (1, 1)
                    props = b.take(b.num()) if flags & 0x20 else b""
                    if flags & 0x80:
                        raise Unsupported("alternative coder methods")
                    f.coders.append(_Coder(method, ci, co, props))
                    n_in, n_out = n_in + ci, n_out + co
                f.bind_pairs = [(b.num(), b.num()) for _ in range(n_out - 1)]
                n_packed = n_in - len(f.bind_pairs)
                if n_packed == 1:
                    bound_in = {i for i, _o in f.bind_pairs}
                    f.packed = [next(i for i in range(n_in) if i not in bound_in)]
                else:
                    f.packed = [b.num() for _ in range(n_packed)]
                s.folders.append(f)
            if b.byte() != 0x0C:
                raise Unsupported("unpack sizes expected")
            for f in s.folders:
                f.unpack_sizes = [b.num() for _ in range(sum(c.n_out for c in f.coders))]
            while True:
                p = b.byte()
                if p == 0x00:
                    break
                if p == 0x0A:
                    s.folder_crc = b.defined(len(s.folders))
                    b.take(4 * sum(s.folder_crc))
                else:
                    raise Unsupported(f"folder property {p}")
        elif prop == 0x08:                                  # sub-streams: the files inside each folder
            counts = [1] * len(s.folders)
            sizes: List[int] = []
            p = b.byte()
            if p == 0x0D:
                counts = [b.num() for _ in s.folders]
                p = b.byte()
            if p == 0x09:
                for f, n in zip(s.folders, counts):
                    if n == 0:
                        continue
                    part = [b.num() for _ in range(n - 1)]
                    sizes += part + [f.main_size() - sum(part)]
                p = b.byte()
            else:
                for f, n in zip(s.folders, counts):
                    if n == 1:
                        sizes.append(f.main_size())
            while p != 0x00:
                if p == 0x0A:
                    crc = s.folder_crc or [False] * len(s.folders)
                    # streams whose checksum isn't already known from their folder
                    unknown = sum(n for n, known in zip(counts, crc) if not (n == 1 and known))
                    d = b.defined(unknown)
                    b.take(4 * sum(d))
                else:
                    raise Unsupported(f"sub-stream property {p}")
                p = b.byte()
            s.sub_counts, s.sub_sizes = counts, sizes
        else:
            raise Unsupported(f"streams property {prop}")
    if not s.sub_counts:
        s.sub_counts = [1] * len(s.folders)
        s.sub_sizes = [f.main_size() for f in s.folders]
    return s


def _lzma_filters(folder: _Folder) -> Optional[List[dict]]:
    """The folder as one lzma filter chain (outermost first), or None if it isn't one."""
    coders = folder.coders
    if any(c.n_in != 1 or c.n_out != 1 for c in coders) or len(folder.packed) != 1:
        return None
    # Follow the data from the packed stream to the folder's output: with one input and one output per
    # coder, in-stream k and out-stream k both belong to coder k, and a bind pair (in, out) feeds coder
    # `out`'s output into coder `in`. lzma wants the chain in encoding order, the reverse of decoding.
    feeds = {out: inn for inn, out in folder.bind_pairs}
    order, k = [], folder.packed[0]
    while k is not None and k not in order:
        order.append(k)
        k = feeds.get(k)
    if len(order) != len(coders):
        return None
    coders = [coders[k] for k in reversed(order)]
    out = []
    for c in coders:
        m, p = c.method, c.props
        if m == b"\x21":
            if len(p) < 1:
                raise Unsupported("LZMA2 without properties")
            d = 0xFFFFFFFF if p[0] >= 40 else (2 | (p[0] & 1)) << (p[0] // 2 + 11)
            out.append({"id": lzma.FILTER_LZMA2, "dict_size": d})
        elif m == b"\x03\x01\x01":
            if len(p) < 5:
                raise Unsupported("LZMA without properties")
            lc, rest = p[0] % 9, p[0] // 9
            out.append({"id": lzma.FILTER_LZMA1, "lc": lc, "lp": rest % 5, "pb": rest // 5,
                        "dict_size": struct.unpack_from("<I", p, 1)[0]})
        elif m == b"\x03\x03\x01\x03":
            out.append({"id": lzma.FILTER_X86})
        elif m == b"\x03\x03\x02\x05":
            out.append({"id": lzma.FILTER_POWERPC})
        elif m == b"\x03\x03\x04\x01":
            out.append({"id": lzma.FILTER_IA64})
        elif m == b"\x03\x03\x05\x01":
            out.append({"id": lzma.FILTER_ARM})
        elif m == b"\x03\x03\x07\x01":
            out.append({"id": lzma.FILTER_ARMTHUMB})
        elif m == b"\x03\x03\x08\x05":
            out.append({"id": lzma.FILTER_SPARC})
        elif m == b"\x03":
            out.append({"id": lzma.FILTER_DELTA, "dist": (p[0] + 1) if p else 1})
        else:
            return None
    if out and out[-1]["id"] not in (lzma.FILTER_LZMA1, lzma.FILTER_LZMA2):
        return None
    return out


class _FolderReader(io.RawIOBase):
    """The decoded output of one folder, read front to back."""

    def __init__(self, fh: BinaryIO, start: int, packed: int, folder: _Folder):
        self.fh, self.left, self.size = fh, packed, folder.main_size()
        self.done = 0
        fh.seek(start)
        c = folder.coders
        self.kind = None
        filters = _lzma_filters(folder)
        if filters is not None:
            self.kind, self.dec = "lzma", lzma.LZMADecompressor(lzma.FORMAT_RAW, filters=filters)
        elif len(c) == 1 and c[0].method == b"\x00":
            self.kind = "copy"
        elif len(c) == 1 and c[0].method == b"\x04\x01\x08":
            self.kind, self.dec = "zlib", zlib.decompressobj(-15)
        elif len(c) == 1 and c[0].method == b"\x04\x02\x02":
            self.kind, self.dec = "bz2", bz2.BZ2Decompressor()
        else:
            names = ", ".join(x.method.hex() for x in c)
            raise Unsupported(f"compression method {names}")

    def readable(self) -> bool:
        return True

    def _input(self) -> bytes:
        if self.left <= 0:
            return b""
        data = self.fh.read(min(CHUNK, self.left))
        self.left -= len(data)
        if not data:
            self.left = 0
        return data

    def read(self, n: int = -1) -> bytes:
        if n is None or n < 0:
            n = self.size - self.done
        n = min(n, self.size - self.done)
        out = bytearray()
        while len(out) < n:
            want = n - len(out)
            if self.kind == "copy":
                take = min(want, self.left)
                got = self.fh.read(take) if take > 0 else b""
                self.left -= len(got)
                if not got:
                    break
            elif self.kind in ("lzma", "bz2"):
                if self.dec.eof:
                    break
                if self.dec.needs_input:
                    data = self._input()
                    got = self.dec.decompress(data, max_length=want)
                    if not data and not got:
                        break
                else:
                    got = self.dec.decompress(b"", max_length=want)
            else:                                           # zlib (Deflate)
                data = self.dec.unconsumed_tail or self._input()
                got = self.dec.decompress(data, want) if data else self.dec.flush()
                if not data and not got:
                    break
            out += got
        self.done += len(out)
        return bytes(out)


class _Member(io.RawIOBase):
    def __init__(self, folder_reader: _FolderReader, skip: int, size: int):
        self.r, self.left = folder_reader, size
        while skip > 0:
            got = self.r.read(min(CHUNK * 4, skip))
            if not got:
                raise Unsupported("the archive ends before the file starts")
            skip -= len(got)

    def readable(self) -> bool:
        return True

    def read(self, n: int = -1) -> bytes:
        if n is None or n < 0:
            n = self.left
        data = self.r.read(min(n, self.left)) if self.left > 0 else b""
        self.left -= len(data)
        return data


class SevenZip:
    def __init__(self, path):
        self.path = Path(path)
        self.fh = open(self.path, "rb")
        try:
            self._read_index()
        except Exception:
            self.fh.close()
            raise

    def __enter__(self):
        return self

    def __exit__(self, *exc):
        self.close()

    def close(self) -> None:
        self.fh.close()

    # --- the index ---
    def _read_index(self) -> None:
        head = self.fh.read(32)
        if len(head) < 32 or head[:6] != SIGNATURE:
            raise Unsupported("not a .7z file")
        off, size = struct.unpack_from("<QQ", head, 12)
        self.fh.seek(32 + off)
        data = self.fh.read(size)
        if len(data) != size:
            raise Unsupported("the archive is cut short")
        for _ in range(4):
            b = _Buf(data)
            kind = b.byte()
            if kind == 0x17:                                  # the index is itself compressed
                s = _read_streams(b)
                if not s.folders:
                    raise Unsupported("empty compressed index")
                f = s.folders[0]
                start = 32 + s.pack_pos
                r = _FolderReader(self.fh, start, s.pack_sizes[0], f)
                data = r.read(f.main_size())
                continue
            if kind != 0x01:
                raise Unsupported(f"unknown index type {kind}")
            self._read_header(b)
            return
        raise Unsupported("index nested too deeply")

    def _read_header(self, b: _Buf) -> None:
        streams = _Streams()
        names: List[str] = []
        empty: List[bool] = []
        while True:
            prop = b.byte()
            if prop == 0x00:
                break
            if prop == 0x02:                                # archive properties: skip
                while b.byte() != 0x00:
                    b.take(b.num())
            elif prop == 0x03:
                _read_streams(b)
            elif prop == 0x04:
                streams = _read_streams(b)
            elif prop == 0x05:
                n = b.num()
                empty = [False] * n
                while True:
                    p = b.byte()
                    if p == 0x00:
                        break
                    size = b.num()
                    if p == 0x0E:
                        empty = b.bits(n)
                        b.take(max(0, size - (n + 7) // 8))
                    elif p == 0x11:
                        raw = b.take(size)
                        if raw[0] != 0:
                            raise Unsupported("external file names")
                        names = raw[1:].decode("utf-16-le").split("\x00")[:n]
                    else:
                        b.take(size)
            else:
                raise Unsupported(f"header property {prop}")
        # Map files to (folder, offset inside the folder's output, size).
        self.entries: Dict[str, Tuple[int, int, int]] = {}
        self.order: List[Tuple[str, int]] = []
        self.streams = streams
        fi, in_folder, offset = 0, 0, 0
        si = 0
        for i, name in enumerate(names):
            if i < len(empty) and empty[i]:
                continue                                    # a folder or an empty file
            while fi < len(streams.folders) and in_folder >= streams.sub_counts[fi]:
                fi, in_folder, offset = fi + 1, 0, 0
            if fi >= len(streams.folders):
                break
            size = streams.sub_sizes[si]
            self.entries[name.replace("\\", "/")] = (fi, offset, size)
            self.order.append((name.replace("\\", "/"), size))
            offset += size
            in_folder += 1
            si += 1
        # where each folder's packed data starts
        self.folder_start: List[Tuple[int, int]] = []
        pos, pi = 32 + streams.pack_pos, 0
        for f in streams.folders:
            n = len(f.packed)
            sizes = streams.pack_sizes[pi:pi + n]
            self.folder_start.append((pos, sum(sizes) if n == 1 else -1))
            pos += sum(sizes)
            pi += n

    # --- reading ---
    def members(self) -> List[Tuple[str, int]]:
        return list(self.order)

    def open(self, name: str) -> io.RawIOBase:
        key = name.replace("\\", "/")
        if key not in self.entries:
            raise KeyError(name)
        fi, offset, size = self.entries[key]
        start, packed = self.folder_start[fi]
        if packed < 0:
            raise Unsupported("a coder with several packed streams (BCJ2)")
        return _Member(_FolderReader(open(self.path, "rb"), start, packed, self.streams.folders[fi]), offset, size)

    def read(self, name: str) -> bytes:
        with self.open(name) as f:
            return f.read()
