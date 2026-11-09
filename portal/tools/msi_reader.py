"""
Read a Windows Installer (.msi) package with the Python standard library only, and unpack its files
without running it.

Used by portal/scripts/setup_msvc71.py. The Visual C++ Toolkit 2003 package runs InstallShield's 2004
script engine even for an administrative install (`msiexec /a`), and that engine fails on Windows 10 and 11
(error 1603, or an "IDS_ERROR26" box). Its files are simply in a cabinet inside the package, so they are
read from there instead: the cabinet is unpacked with Windows' own expand.exe (it uses LZX compression),
and each file is put in its folder from the package's File, Component and Directory tables.

An .msi is an OLE compound file. Its streams have encoded names, strings live in one string pool, and
tables are stored column by column. Only what is needed to read tables and streams is implemented.
"""
from __future__ import annotations

import os
import shutil
import struct
import subprocess
from pathlib import Path, PurePath
from typing import Callable, Dict, List, Optional

B64 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz._"
OLE_MAGIC = b"\xD0\xCF\x11\xE0\xA1\xB1\x1A\xE1"


class CompoundFile:
    """The streams of an OLE compound file (the container format of .msi packages)."""

    def __init__(self, data: bytes):
        if data[:8] != OLE_MAGIC:
            raise ValueError("not an OLE compound file")
        self.d = data
        self.ss = 1 << struct.unpack_from("<H", data, 0x1E)[0]
        self.mss = 1 << struct.unpack_from("<H", data, 0x20)[0]
        nfat, dir0 = struct.unpack_from("<II", data, 0x2C)
        self.cutoff, minifat0, _n, difat0, ndifat = struct.unpack_from("<IIIII", data, 0x38)
        fat_secs = list(struct.unpack_from("<109I", data, 0x4C))
        sec = difat0
        for _ in range(ndifat):
            arr = struct.unpack_from(f"<{self.ss // 4}I", data, self._off(sec))
            fat_secs += arr[:-1]
            sec = arr[-1]
        self.fat: List[int] = []
        for fs in [x for x in fat_secs if x < 0xFFFFFFFA][:nfat]:
            self.fat += struct.unpack_from(f"<{self.ss // 4}I", data, self._off(fs))
        self.minifat: List[int] = []
        if minifat0 < 0xFFFFFFFA:
            raw = self._read(minifat0)
            self.minifat = list(struct.unpack(f"<{len(raw) // 4}I", raw[:len(raw) // 4 * 4]))
        dirs = self._read(dir0)
        self.entries = []
        for i in range(len(dirs) // 128):
            e = dirs[i * 128:(i + 1) * 128]
            nl = struct.unpack_from("<H", e, 0x40)[0]
            start, size = struct.unpack_from("<IQ", e, 0x74)
            if self.ss == 512:
                size &= 0xFFFFFFFF
            self.entries.append((e[:max(0, nl - 2)].decode("utf-16-le", "replace"), e[0x42], start, size))
        root = self.entries[0]
        self.ministream = self._read(root[2])[:root[3]]

    def _off(self, sec: int) -> int:
        return (sec + 1) * self.ss

    @staticmethod
    def _chain(start: int, fat: List[int]) -> List[int]:
        out, sec, seen = [], start, set()
        while sec < 0xFFFFFFFA and sec < len(fat) and sec not in seen:
            seen.add(sec)
            out.append(sec)
            sec = fat[sec]
        return out

    def _read(self, start: int) -> bytes:
        return b"".join(self.d[self._off(s):self._off(s) + self.ss] for s in self._chain(start, self.fat))

    def streams(self) -> Dict[str, bytes]:
        out = {}
        for name, typ, start, size in self.entries:
            if typ != 2:                                # 2 = stream
                continue
            if size < self.cutoff:
                raw = b"".join(self.ministream[s * self.mss:(s + 1) * self.mss] for s in self._chain(start, self.minifat))
            else:
                raw = self._read(start)
            out[name] = raw[:size]
        return out


def decode_stream_name(name: str) -> str:
    """MSI packs stream names two characters per UTF-16 unit; tables start with '!'."""
    out = []
    for ch in name:
        c = ord(ch)
        if 0x3800 <= c < 0x4800:
            c -= 0x3800
            out.append(B64[c & 0x3F])
            out.append(B64[(c >> 6) & 0x3F])
        elif 0x4800 <= c < 0x4840:
            out.append(B64[c - 0x4800])
        elif c == 0x4840:
            out.append("!")
        else:
            out.append(ch)
    return "".join(out)


class Msi:
    STRING = 0x0800

    def __init__(self, data: bytes):
        self.streams = {decode_stream_name(n): b for n, b in CompoundFile(data).streams().items()}
        pool, text = self.streams["!_StringPool"], self.streams["!_StringData"]
        flags = struct.unpack_from("<H", pool, 2)[0]
        self.sref = 3 if flags & 0x8000 else 2           # bytes per string reference
        self.strings: List[Optional[str]] = [None]
        pos, i = 0, 4
        while i + 4 <= len(pool):
            length, refs = struct.unpack_from("<HH", pool, i)
            i += 4
            if length == 0 and refs != 0 and i + 4 <= len(pool):
                # A string over 64 KB: its length is the next entry's two words (low, high).
                lo, hi = struct.unpack_from("<HH", pool, i)
                i += 4
                length = (hi << 16) | lo
            self.strings.append(text[pos:pos + length].decode("cp1252", "replace"))
            pos += length
        raw = self.streams.get("!_Columns", b"")
        n = len(raw) // (self.sref * 2 + 4)
        cols, o = [], 0
        for width in (self.sref, 2, self.sref, 2):     # Table, Number, Name, Type
            cols.append([int.from_bytes(raw[o + k * width:o + (k + 1) * width], "little") for k in range(n)])
            o += n * width
        self.columns: Dict[str, list] = {}
        for t, num, name, typ in zip(*cols):
            self.columns.setdefault(self.strings[t], []).append((num ^ 0x8000, self.strings[name], typ ^ 0x8000))
        for v in self.columns.values():
            v.sort()

    def table(self, name: str) -> List[dict]:
        cols, data = self.columns.get(name), self.streams.get("!" + name)
        if not cols or data is None:
            return []
        widths = [self.sref if (ty & self.STRING or (ty & 0xFF) == 0) else (4 if (ty & 0xFF) == 4 else 2)
                  for _n, _c, ty in cols]
        rows = len(data) // sum(widths)
        out: List[dict] = [{} for _ in range(rows)]
        o = 0
        for (_n, cname, ty), w in zip(cols, widths):
            for k in range(rows):
                v = int.from_bytes(data[o + k * w:o + (k + 1) * w], "little")
                if w == self.sref and (ty & self.STRING or (ty & 0xFF) == 0):
                    out[k][cname] = self.strings[v] if 0 < v < len(self.strings) else None
                else:
                    out[k][cname] = None if v == 0 else v - (0x8000 if w == 2 else 0x80000000)
            o += rows * w
        return out


def long_name(field: str) -> str:
    """'MICROS~1|Microsoft Visual C++ Toolkit 2003' -> the long name; a Directory's target part only."""
    return (field or "").split(":")[0].split("|")[-1]


def directory_paths(rows: List[dict]) -> Dict[str, PurePath]:
    """Each Directory key -> its path below the install root ('.' and SourceDir add nothing)."""
    by = {r["Directory"]: r for r in rows}
    done: Dict[str, PurePath] = {}

    def path(key: str, depth: int = 0) -> PurePath:
        if key in done:
            return done[key]
        r = by.get(key)
        if r is None or depth > 64:
            return PurePath()
        parent = r.get("Directory_Parent")
        base = path(parent, depth + 1) if parent and parent != key else PurePath()
        seg = long_name(r.get("DefaultDir") or ".")
        done[key] = base / seg if seg not in ("", ".", "SourceDir") else base
        return done[key]

    for k in by:
        path(k)
    return done


def _safe(rel: PurePath) -> bool:
    return not rel.is_absolute() and all(p not in ("..", "") and ":" not in p for p in rel.parts)


def windows_expand(cab: Path, dest: Path) -> None:
    exe = Path(os.environ.get("SystemRoot", r"C:\Windows")) / "System32" / "expand.exe"
    res = subprocess.run([str(exe if exe.exists() else "expand"), str(cab), "-F:*", str(dest)],
                         capture_output=True, text=True)
    if res.returncode != 0:
        raise RuntimeError(f"expand.exe could not unpack {cab.name}: {(res.stdout + res.stderr).strip()[-400:]}")


def unpack(msi_bytes: bytes, dest: Path, expand: Callable[[Path, Path], None] = windows_expand) -> int:
    """Unpack every file of the package into dest, in its folder. Returns how many files were placed."""
    m = Msi(msi_bytes)
    work = dest / "_cab"
    work.mkdir(parents=True, exist_ok=True)
    for media in m.table("Media"):
        cab = media.get("Cabinet") or ""
        if not cab.startswith("#"):
            raise RuntimeError(f"The package expects an outside cabinet ({cab or 'none'}); only built-in ones are supported.")
        data = m.streams.get(cab[1:])
        if data is None:
            raise RuntimeError(f"Cabinet {cab[1:]} is not in the package.")
        (work / cab[1:]).write_bytes(data)
        expand(work / cab[1:], work)
    dirs = directory_paths(m.table("Directory"))
    comp_dir = {c["Component"]: c["Directory_"] for c in m.table("Component")}
    placed = 0
    for f in m.table("File"):
        src = work / f["File"]
        rel = dirs.get(comp_dir.get(f["Component_"], ""), PurePath()) / long_name(f["FileName"])
        if not src.exists() or not _safe(rel):
            continue
        out = dest / rel
        out.parent.mkdir(parents=True, exist_ok=True)
        shutil.move(str(src), str(out))
        placed += 1
    shutil.rmtree(work, ignore_errors=True)
    return placed
