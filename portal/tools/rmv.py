#!/usr/bin/env python3
"""
The PS2's movies (.rmv, "RadMovie", in MOVIES.RCF): a 2 KB header, the picture as a raw PS2 IPU stream
(the MPEG-2 style video the PS2's IPU chip decodes), then the sound as an ordinary Radical .rsd file.

    0x00  "rmvps212"
    0x08  u16 width, u16 height, u32 frame count, u32 file size
    0x14  u32 where the picture starts (0x800)
    0x18  u32 number of sound tracks (1 in every movie on the disc)
    0x1C  u32 x 16  where each sound track starts (the picture ends there)
    0x5C  u32 x 16  each sound track's size
    0x9C  u32 frames per second x 100 (2997)
          0xAD bytes up to 0x800; the picture is padded with 0xAD to the next 2 KB as well

Nothing plays IPU streams directly, but they are the same as Sony's .ipu files without their 16-byte
header, which FFmpeg reads. This splits a movie into an .ipu file and a .wav file:

    python portal/tools/rmv.py extracted/game_files/.../radical.rmv --out somewhere/
    ffmpeg -r 29.97 -i radical.ipu -i radical.wav -c:v libx264 -pix_fmt yuv420p radical.mp4

Your own copies, on your own computer; standard library only.
"""

from __future__ import annotations

import argparse
import struct
import sys
from dataclasses import dataclass, field
from pathlib import Path
from typing import BinaryIO, List, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parent))
import media  # noqa: E402

MAGIC = b"rmvps212"
HEADER = 0xA0
PAD = 0xAD
MAX_TRACKS = 16


class RmvError(ValueError):
    pass


@dataclass
class Rmv:
    width: int
    height: int
    frames: int
    file_size: int
    video_start: int
    fps: float
    tracks: List[Tuple[int, int]] = field(default_factory=list)    # (offset, size) of each sound

    @property
    def video_end(self) -> int:
        """Where the picture stops: the first sound track, or the end of the file."""
        return min([o for o, _ in self.tracks] or [self.file_size])

    @property
    def seconds(self) -> float:
        return self.frames / self.fps if self.fps else 0.0


def read_header(head: bytes) -> Rmv:
    """The facts in a movie's first 0xA0 bytes."""
    if len(head) < HEADER or head[:8] != MAGIC:
        raise RmvError("not a PS2 .rmv movie")
    w, h, frames, size, start, count = struct.unpack_from("<HHIIII", head, 8)
    offsets = struct.unpack_from("<16I", head, 0x1C)
    sizes = struct.unpack_from("<16I", head, 0x5C)
    fps = struct.unpack_from("<I", head, 0x9C)[0] / 100
    if count > MAX_TRACKS or start < HEADER:
        raise RmvError("a damaged .rmv header")
    tracks = [(offsets[i], sizes[i]) for i in range(count)]
    return Rmv(w, h, frames, size, start, fps, tracks)


def ipu_header(info: Rmv, video_bytes: int) -> bytes:
    """Sony's 16-byte .ipu header: "ipum", u32 size after this field's end, u16 width, u16 height,
    u32 frames."""
    return b"ipum" + struct.pack("<IHHI", video_bytes + 8, info.width, info.height, info.frames)


def _copy(f: BinaryIO, start: int, end: int, out: BinaryIO, piece: int = 1 << 20) -> int:
    """Copy [start, end) and drop the 0xAD padding at its end. Returns the bytes written."""
    f.seek(start)
    tail = b""
    written = 0
    left = end - start
    while left > 0:
        chunk = f.read(min(piece, left))
        if not chunk:
            break
        left -= len(chunk)
        data = tail + chunk
        keep = len(data) - 4096 if left > 0 else len(data.rstrip(bytes([PAD])))
        keep = max(0, keep)
        out.write(data[:keep])
        written += keep
        tail = data[keep:] if left > 0 else b""
    return written


def split(path: Path, out_dir: Path, wav: bool = True) -> List[Path]:
    """Write <name>.ipu and each sound track as <name>.rsd (and .wav, decoded) into out_dir."""
    out_dir.mkdir(parents=True, exist_ok=True)
    stem = path.stem
    made: List[Path] = []
    with open(path, "rb") as f:
        info = read_header(f.read(HEADER))
        ipu = out_dir / f"{stem}.ipu"
        with open(ipu, "wb") as o:
            o.write(b"\0" * 16)
            n = _copy(f, info.video_start, info.video_end, o)
            o.seek(0)
            o.write(ipu_header(info, n))
        made.append(ipu)
        for i, (off, size) in enumerate(info.tracks):
            f.seek(off)
            sound = f.read(size)
            name = stem if len(info.tracks) == 1 else f"{stem}_{i + 1}"
            rsd = out_dir / f"{name}.rsd"
            rsd.write_bytes(sound)
            made.append(rsd)
            if wav:
                try:
                    data, _mime, ext = media.playable(sound)
                except media.MediaError as e:
                    print(f"  (sound track {i + 1} not decoded: {e})", file=sys.stderr)
                    continue
                target = out_dir / f"{name}{ext}"
                target.write_bytes(data)
                made.append(target)
    return made


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description="Split a PS2 .rmv movie into an .ipu picture and its sound.")
    ap.add_argument("movie", type=Path)
    ap.add_argument("--out", type=Path, help="folder for the results (default: next to the movie)")
    ap.add_argument("--info", action="store_true", help="only show what the header says")
    ap.add_argument("--no-wav", action="store_true", help="keep the sound as .rsd only")
    a = ap.parse_args(argv)
    try:
        with open(a.movie, "rb") as f:
            info = read_header(f.read(HEADER))
    except (OSError, RmvError) as e:
        print(f"{a.movie}: {e}", file=sys.stderr)
        return 1
    print(f"{a.movie.name}: {info.width}x{info.height}, {info.frames:,} frames at {info.fps:g} fps "
          f"({info.seconds:.1f} s), {len(info.tracks)} sound track(s)")
    if a.info:
        return 0
    made = split(a.movie, a.out or a.movie.parent, wav=not a.no_wav)
    for p in made:
        print(f"  wrote {p}")
    ipu = made[0]
    sound = next((p for p in made if p.suffix == ".wav"), None)
    cmd = f'ffmpeg -r {info.fps:g} -i "{ipu}"' + (f' -i "{sound}"' if sound else "")
    print(f"To watch it: {cmd} -c:v libx264 -pix_fmt yuv420p \"{ipu.with_suffix('.mp4')}\"")
    return 0


if __name__ == "__main__":
    sys.exit(main())
