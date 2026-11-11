#!/usr/bin/env python3
"""
Turn the game's own sound and texture files into things a browser can play and show, for the portal's
Game files view (your own copies, on your own computer; nothing is uploaded). Standard library only.

Sounds are Radical's .rsd files: a 2 KB header, then the audio in the platform's own codec.

    header    "RSD6", codec (4 chars), channels (u32), bits (u32), sample rate (u32), "****",
              the path the sound had on the developers' machines, "no description", padding to 0x800
    OOGV      PC: an Ogg Vorbis stream; browsers play it as it is
    WMA       Xbox music and score: 8 bytes, then an ASF (Windows Media) file; browsers don't play WMA,
              so it is offered as a .wma for your own player
    XADP      Xbox: Xbox ADPCM (IMA ADPCM in 36-byte blocks per channel), decoded to WAV here; the
              cutscenes' six channels are mixed down to stereo
    VAG       PS2: PS2 ADPCM (16-byte frames of 28 samples), decoded to WAV here
    RADP      Xbox prototype: Radical's IMA ADPCM (20-byte blocks per channel), decoded to WAV here
    PCM       16-bit PCM, wrapped as WAV

Textures live in Pure3D (.p3d) files: a Texture chunk (0x19000) holds Image chunks (0x19001) whose Image
Data chunk (0x19002) is the picture:

    PC        a PNG file (format 1), shown as it is
    Xbox      a DDS file (formats 6/8/10: DXT1, DXT3, DXT5, or uncompressed), decoded to PNG here
    PS2       Pure3D's own "P3DI" image with a palette (formats 11/12: 4- or 8-bit), decoded to PNG here

    sound_info(data) / playable(data) -> (bytes, mime type, file extension)
    textures(data) -> [Texture] / texture_png(data, index) or picture_png(data, texture) -> PNG bytes
"""

from __future__ import annotations

import array
import functools
import io
import struct
import sys
import wave
import zlib
from dataclasses import dataclass
from typing import List, Optional, Tuple

RSD_DATA = 0x800
IMA_STEP = [7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 19, 21, 23, 25, 28, 31, 34, 37, 41, 45, 50, 55, 60, 66, 73, 80, 88,
            97, 107, 118, 130, 143, 157, 173, 190, 209, 230, 253, 279, 307, 337, 371, 408, 449, 494, 544, 598, 658,
            724, 796, 876, 963, 1060, 1166, 1282, 1411, 1552, 1707, 1878, 2066, 2272, 2499, 2749, 3024, 3327, 3660,
            4026, 4428, 4871, 5358, 5894, 6484, 7132, 7845, 8630, 9493, 10442, 11487, 12635, 13899, 15289, 16818,
            18500, 20350, 22385, 24623, 27086, 29794, 32767]
IMA_INDEX = [-1, -1, -1, -1, 2, 4, 6, 8, -1, -1, -1, -1, 2, 4, 6, 8]
VAG_COEF = [(0, 0), (60, 0), (115, -52), (98, -55), (122, -60)]
VAG_STEREO_INTERLEAVE = 0x10           # RSD6 VAG with two channels: one 16-byte frame of each in turn
MAX_SECONDS = 15 * 60                  # longer than this is not decoded for previewing


class MediaError(ValueError):
    pass


# --------------------------------------------------------------------------- sounds

def sound_info(data: bytes) -> Optional[dict]:
    if len(data) < 0x20 or data[:3] != b"RSD":
        return None
    codec = data[4:8].decode("latin-1").strip("\0 ")
    channels, bits, rate = struct.unpack_from("<3I", data, 8)
    out = {"version": data[3:4].decode("latin-1"), "codec": codec, "channels": channels, "bits": bits, "rate": rate}
    if data[0x14:0x18] == b"****":
        end = data.find(b"\0", 0x18)
        if end > 0x18:
            out["source_name"] = data[0x18:end].decode("latin-1")
    return out


def _wav(pcm: bytes, channels: int, rate: int) -> bytes:
    buf = io.BytesIO()
    with wave.open(buf, "wb") as w:
        w.setnchannels(channels)
        w.setsampwidth(2)
        w.setframerate(rate)
        w.writeframes(pcm)
    return buf.getvalue()


def _clamp16(v: int) -> int:
    return -32768 if v < -32768 else 32767 if v > 32767 else v


@functools.lru_cache(maxsize=1)
def _xadp_table() -> Tuple[Tuple[int, ...], Tuple[int, ...]]:
    """For each (step index, nibble): the signed change to the sample, and the next step index."""
    diffs, nexts = [], []
    for index in range(89):
        step = IMA_STEP[index]
        for nib in range(16):
            d = step >> 3
            if nib & 1:
                d += step >> 2
            if nib & 2:
                d += step >> 1
            if nib & 4:
                d += step
            diffs.append(-d if nib & 8 else d)
            nexts.append(min(88, max(0, index + IMA_INDEX[nib])))
    return tuple(diffs), tuple(nexts)


def decode_xbox_adpcm(body: bytes, channels: int) -> bytes:
    """Xbox ADPCM: blocks of 36 bytes per channel. First each channel's header (int16 predictor, u8 step
    index, u8 0), then 4-byte runs (8 samples, low nibble first) taking turns channel by channel, eight runs
    each: 64 samples per channel per block. Any number of channels (the cutscenes' sound has six)."""
    if not 1 <= channels <= 8:
        raise MediaError(f"Xbox ADPCM with {channels} channels")
    diffs, nexts = _xadp_table()
    block = 36 * channels
    blocks = len(body) // block
    out = array.array("h", bytes(2 * 64 * channels * blocks))
    for b in range(blocks):
        base = b * block
        first = b * 64 * channels
        for c in range(channels):
            pred, index = struct.unpack_from("<hB", body, base + 4 * c)
            if index > 88:
                index = 88
            pos = first + c
            for k in range(8):
                o = base + 4 * channels + 4 * (k * channels + c)
                for byte in body[o:o + 4]:
                    t = (index << 4) | (byte & 15)
                    pred += diffs[t]
                    pred = -32768 if pred < -32768 else 32767 if pred > 32767 else pred
                    index = nexts[t]
                    out[pos] = pred
                    pos += channels
                    t = (index << 4) | (byte >> 4)
                    pred += diffs[t]
                    pred = -32768 if pred < -32768 else 32767 if pred > 32767 else pred
                    index = nexts[t]
                    out[pos] = pred
                    pos += channels
    if sys.byteorder == "big":
        out.byteswap()
    return out.tobytes()


# Where each channel goes when more than two are mixed down for the browser, in the WAVE order (front
# left, front right, centre, low frequency, back left, back right, side left, side right): (left, right)
_MIX = {3: [(1, 0), (0, 1), (.7071, .7071)],
        4: [(1, 0), (0, 1), (.7071, 0), (0, .7071)],
        5: [(1, 0), (0, 1), (.7071, .7071), (.7071, 0), (0, .7071)],
        6: [(1, 0), (0, 1), (.7071, .7071), (0, 0), (.7071, 0), (0, .7071)],
        7: [(1, 0), (0, 1), (.7071, .7071), (0, 0), (.7071, 0), (0, .7071), (.5, .5)],
        8: [(1, 0), (0, 1), (.7071, .7071), (0, 0), (.7071, 0), (0, .7071), (.7071, 0), (0, .7071)]}


def downmix(pcm: bytes, channels: int) -> bytes:
    """16-bit PCM with 3 to 8 channels as stereo, as loud as it can be without clipping."""
    if channels <= 2:
        return pcm
    src = array.array("h")
    src.frombytes(pcm[:len(pcm) // (2 * channels) * 2 * channels])
    if sys.byteorder == "big":
        src.byteswap()
    mix = _MIX.get(channels) or [((1.0, 0.0) if c % 2 == 0 else (0.0, 1.0)) for c in range(channels)]
    frames = len(src) // channels
    left = [0.0] * frames
    right = [0.0] * frames
    for c, (gl, gr) in enumerate(mix):
        if not gl and not gr:
            continue
        col = src[c::channels]
        if gl:
            left = [a + gl * v for a, v in zip(left, col)]
        if gr:
            right = [a + gr * v for a, v in zip(right, col)]
    peak = max(max(map(abs, left), default=0), max(map(abs, right), default=0), 1.0)
    scale = min(1.0, 32767 / peak)
    out = array.array("h", bytes(4 * frames))
    out[0::2] = array.array("h", (int(v * scale) for v in left))
    out[1::2] = array.array("h", (int(v * scale) for v in right))
    if sys.byteorder == "big":
        out.byteswap()
    return out.tobytes()


@functools.lru_cache(maxsize=1)
def _radp_table() -> Tuple[Tuple[int, ...], Tuple[int, ...]]:
    """For each (step index, nibble): the signed change to the sample, and the next step index."""
    diffs, nexts = [], []
    for index in range(89):
        step = IMA_STEP[index]
        for nib in range(16):
            d = ((2 * (nib & 7) + 1) * step) >> 3
            diffs.append(-d if nib & 8 else d)
            nexts.append(min(88, max(0, index + IMA_INDEX[nib])))
    return tuple(diffs), tuple(nexts)


def decode_radp(body: bytes, channels: int) -> bytes:
    """Radical's IMA ADPCM ("RADP", the Xbox prototype's sounds). Blocks of 20 bytes per channel: for each
    channel an int16 step index and an int16 sample, then 16 rows of one byte per channel; each row gives
    every channel its low nibble, then every channel its high nibble (32 samples per channel per block).
    Matches FFmpeg's adpcm_ima_rad decoder."""
    if channels not in (1, 2):
        raise MediaError(f"Radical ADPCM with {channels} channels")
    diffs, nexts = _radp_table()
    block = 20 * channels
    out = []
    for b in range(0, len(body) - block + 1, block):
        state = []
        for c in range(channels):
            index, pred = struct.unpack_from("<hh", body, b + 4 * c)
            state.append([pred, min(88, max(0, index))])
        o = b + 4 * channels
        for _row in range(16):
            row = body[o:o + channels]
            o += channels
            for shift in (0, 4):
                for c in range(channels):
                    s = state[c]
                    k = (s[1] << 4) | ((row[c] >> shift) & 15)
                    p = s[0] + diffs[k]
                    s[0] = -32768 if p < -32768 else 32767 if p > 32767 else p
                    s[1] = nexts[k]
                    out.append(s[0])
    return struct.pack(f"<{len(out)}h", *out)


def _vag_channel(body: bytes) -> List[int]:
    out: List[int] = []
    h1 = h2 = 0
    for f in range(0, len(body) - 15, 16):
        pf, flags = body[f], body[f + 1]
        if flags == 7:                                         # end of the sound
            break
        shift, pred = pf & 15, min(pf >> 4, 4)
        c1, c2 = VAG_COEF[pred]
        for byte in body[f + 2:f + 16]:
            for nib in (byte & 15, byte >> 4):
                s = (nib << 12) & 0xFFFF
                if s & 0x8000:
                    s -= 0x10000
                s = (s >> shift) + ((h1 * c1 + h2 * c2 + 32) >> 6)
                s = _clamp16(s)
                out.append(s)
                h2, h1 = h1, s
    return out


def decode_vag(body: bytes, channels: int) -> bytes:
    """PS2 ADPCM. Two channels take turns frame by frame (16 bytes of the left, 16 of the right, ...);
    checked against the PC versions of the same music and of the movies' sound."""
    if channels == 1:
        return b"".join(struct.pack("<h", s) for s in _vag_channel(body))
    if channels != 2:
        raise MediaError(f"PS2 ADPCM with {channels} channels")
    il = VAG_STEREO_INTERLEAVE
    parts = [bytearray(), bytearray()]
    for i, o in enumerate(range(0, len(body), il)):
        parts[i % 2] += body[o:o + il]
    left, right = _vag_channel(bytes(parts[0])), _vag_channel(bytes(parts[1]))
    n = min(len(left), len(right))
    return b"".join(struct.pack("<hh", left[i], right[i]) for i in range(n))


def playable(data: bytes) -> Tuple[bytes, str, str]:
    """(bytes, MIME type, extension) of a sound the browser can play, or a WMA for your own player."""
    if data[:4] == b"OggS":
        return data, "audio/ogg", ".ogg"
    if data[:4] == b"RIFF" and data[8:12] == b"WAVE":
        return data, "audio/wav", ".wav"
    info = sound_info(data)
    if not info:
        raise MediaError("not a Radical .rsd sound")
    body = data[RSD_DATA:]
    codec, ch, rate = info["codec"].upper(), info["channels"] or 1, info["rate"] or 22050
    if codec in ("OOGV", "OGG"):
        return body, "audio/ogg", ".ogg"
    if codec == "WMA":
        i = body.find(bytes.fromhex("3026B2758E66CF11A6D900AA0062CE6C"))     # the ASF header
        return (body[i:] if i >= 0 else body), "audio/x-ms-wma", ".wma"
    if rate and len(body) / max(1, rate * ch) > MAX_SECONDS * 0.6:
        raise MediaError("too long to preview")
    if codec == "XADP":
        if ch > 2:                                      # browsers are surest with stereo
            return _wav(downmix(decode_xbox_adpcm(body, ch), ch), 2, rate), "audio/wav", ".wav"
        return _wav(decode_xbox_adpcm(body, ch), ch, rate), "audio/wav", ".wav"
    if codec == "VAG":
        return _wav(decode_vag(body, ch), ch, rate), "audio/wav", ".wav"
    if codec == "RADP":
        return _wav(decode_radp(body, ch), ch, rate), "audio/wav", ".wav"
    if codec in ("PCM", "PCMB"):
        pcm = body if codec == "PCM" else b"".join(body[i:i + 2][::-1] for i in range(0, len(body) - 1, 2))
        return _wav(pcm[:len(pcm) // (2 * ch) * 2 * ch], ch, rate), "audio/wav", ".wav"
    raise MediaError(f"the {info['codec']} codec can't be previewed")


# --------------------------------------------------------------------------- subtitles

SUBTITLE = 0x0100500A


def subtitles(data: bytes) -> List[Tuple[str, str]]:
    """The lines a subtitle file (art/subtitles/<x>/<name>.p3d, named like the sound it goes with) holds:
    [(language, text)]. Each is a 0x0100500A chunk: the language (u32 length, then the letters, ended and
    padded to 4 bytes), two numbers (-1), the length of the text in UTF-16 units, then the text."""
    out: List[Tuple[str, str]] = []
    if data[:4] != b"P3D\xff":
        return out
    p, end = 12, min(len(data), struct.unpack_from("<I", data, 8)[0] if len(data) >= 12 else 0)
    while p + 12 <= end:
        cid, head, size = struct.unpack_from("<3I", data, p)
        if size < 12 or p + size > len(data):
            break
        if cid == SUBTITLE:
            try:
                q = p + 12
                n = struct.unpack_from("<I", data, q)[0]
                lang = data[q + 4:q + 4 + n].split(b"\0")[0].decode("latin-1")
                q += 4 + ((n + 4) & ~3)
                count = struct.unpack_from("<I", data, q + 8)[0]
                text = data[q + 12:q + 12 + 2 * count].decode("utf-16-le", "replace")
                out.append((lang, " ".join(text.replace("\0", " ").split())))
            except (struct.error, UnicodeDecodeError):
                pass
        p += size
    return out


# --------------------------------------------------------------------------- textures

@dataclass
class Texture:
    name: str
    width: int
    height: int
    bpp: int
    format: int
    kind: str           # "png", "dds", "p3di" or "unknown"
    offset: int         # where the picture's bytes start in the .p3d
    size: int


def _chunks(data: bytes, off: int, end: int):
    while off + 12 <= end:
        cid, head, total = struct.unpack_from("<III", data, off)
        if total < 12 or head < 12 or head > total or off + total > end:
            return
        yield cid, off, head, total
        off += total


def textures(data: bytes, limit: int = 2000) -> List[Texture]:
    """Every picture in a Pure3D file, in order. A lone PNG, DDS or P3DI picture is a list of one."""
    if data[:4] != b"P3D\xff" or len(data) < 12:
        try:
            if data[:4] == b"\x89PNG":
                w, h = struct.unpack_from(">II", data, 16)
                return [Texture("", w, h, 32, 0, "png", 0, len(data))]
            if data[:4] == b"DDS ":
                h, w = struct.unpack_from("<II", data, 12)
                return [Texture("", w, h, 0, 0, "dds", 0, len(data))]
            if data[:4] == b"P3DI":
                w, h, bpp = struct.unpack_from("<III", data, 8)
                return [Texture("", w, h, bpp, 0, "p3di", 0, len(data))]
        except struct.error:
            pass
        return []
    out: List[Texture] = []
    stack = [(12, min(struct.unpack_from("<I", data, 8)[0], len(data)))]
    while stack and len(out) < limit:
        off, end = stack.pop()
        found = list(_chunks(data, off, end))
        for cid, o, head, total in reversed(found):
            if head < total:
                stack.append((o + head, o + total))
        for cid, o, head, total in found:
            if cid != 0x19001 or o + 13 > len(data):
                continue
            n = data[o + 12]
            name = data[o + 13:o + 13 + n].split(b"\0")[0].decode("latin-1")
            p = o + 13 + n
            if p + 28 > o + head:
                continue
            _ver, w, h, bpp, _pal, _alpha, fmt = struct.unpack_from("<7I", data, p)
            for c2, o2, h2, t2 in _chunks(data, o + head, o + total):
                if c2 == 0x19002 and o2 + 16 <= len(data):
                    size = struct.unpack_from("<I", data, o2 + 12)[0]
                    start = o2 + 16
                    head4 = data[start:start + 4]
                    kind = ("png" if head4 == b"\x89PNG" else "dds" if head4 == b"DDS " else
                            "p3di" if head4 == b"P3DI" else "unknown")
                    out.append(Texture(name, w, h, bpp, fmt, kind, start, min(size, len(data) - start)))
                    break
    out.sort(key=lambda t: t.offset)
    return out


def png(width: int, height: int, rgba: bytes) -> bytes:
    """An RGBA picture as a PNG file."""
    raw = b"".join(b"\0" + rgba[y * width * 4:(y + 1) * width * 4] for y in range(height))

    def chunk(kind: bytes, body: bytes) -> bytes:
        return struct.pack(">I", len(body)) + kind + body + struct.pack(">I", zlib.crc32(kind + body) & 0xFFFFFFFF)
    return (b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", struct.pack(">IIBBBBB", width, height, 8, 6, 0, 0, 0))
            + chunk(b"IDAT", zlib.compress(raw, 6)) + chunk(b"IEND", b""))


def _565(c: int) -> Tuple[int, int, int]:
    r, g, b = (c >> 11) & 31, (c >> 5) & 63, c & 31
    return (r << 3) | (r >> 2), (g << 2) | (g >> 4), (b << 3) | (b >> 2)


def _dxt_colors(block: bytes, dxt1: bool):
    c0, c1 = struct.unpack_from("<HH", block, 0)
    a, b = _565(c0), _565(c1)
    if c0 > c1 or not dxt1:
        cols = [a + (255,), b + (255,), tuple((2 * x + y) // 3 for x, y in zip(a, b)) + (255,),
                tuple((x + 2 * y) // 3 for x, y in zip(a, b)) + (255,)]
    else:
        cols = [a + (255,), b + (255,), tuple((x + y) // 2 for x, y in zip(a, b)) + (255,), (0, 0, 0, 0)]
    bits = struct.unpack_from("<I", block, 4)[0]
    return [cols[(bits >> (2 * i)) & 3] for i in range(16)]


def decode_dxt(data: bytes, w: int, h: int, kind: int) -> bytes:
    """DXT1 (kind 1), DXT3 (3) or DXT5 (5) to RGBA."""
    out = bytearray(w * h * 4)
    bsize = 8 if kind == 1 else 16
    bw, bh = (w + 3) // 4, (h + 3) // 4
    for by in range(bh):
        for bx in range(bw):
            o = (by * bw + bx) * bsize
            blk = data[o:o + bsize]
            if len(blk) < bsize:
                return bytes(out)
            if kind == 1:
                px = _dxt_colors(blk, True)
            else:
                px = _dxt_colors(blk[8:], False)
                if kind == 3:
                    alpha = [((blk[i // 2] >> (4 * (i & 1))) & 15) * 17 for i in range(16)]
                else:
                    a0, a1 = blk[0], blk[1]
                    if a0 > a1:
                        tab = [a0, a1] + [((7 - i) * a0 + i * a1) // 7 for i in range(1, 7)]
                    else:
                        tab = [a0, a1] + [((5 - i) * a0 + i * a1) // 5 for i in range(1, 5)] + [0, 255]
                    bits = int.from_bytes(blk[2:8], "little")
                    alpha = [tab[(bits >> (3 * i)) & 7] for i in range(16)]
                px = [p[:3] + (alpha[i],) for i, p in enumerate(px)]
            for i, p in enumerate(px):
                x, y = bx * 4 + (i & 3), by * 4 + (i >> 2)
                if x < w and y < h:
                    q = (y * w + x) * 4
                    out[q:q + 4] = bytes(p)
    return bytes(out)


def decode_dds(dds: bytes) -> Tuple[int, int, bytes]:
    if dds[:4] != b"DDS " or len(dds) < 128:
        raise MediaError("not a DDS picture")
    h, w = struct.unpack_from("<II", dds, 12)
    pf_flags, fourcc, bitcount, rmask, gmask, bmask, amask = struct.unpack_from("<I4sIIIII", dds, 80)
    body = dds[128:]
    if pf_flags & 4:
        kind = {b"DXT1": 1, b"DXT2": 3, b"DXT3": 3, b"DXT4": 5, b"DXT5": 5}.get(fourcc)
        if not kind:
            raise MediaError(f"the {fourcc.decode('latin-1')} picture format can't be shown")
        return w, h, decode_dxt(body, w, h, kind)
    if bitcount in (32, 24, 16) and rmask:
        step = bitcount // 8
        out = bytearray()

        def ch(v: int, mask: int) -> int:
            if not mask:
                return 255
            shift = (mask & -mask).bit_length() - 1
            top = mask >> shift
            return ((v & mask) >> shift) * 255 // top
        for i in range(w * h):
            v = int.from_bytes(body[i * step:(i + 1) * step], "little")
            out += bytes((ch(v, rmask), ch(v, gmask), ch(v, bmask), ch(v, amask) if amask else 255))
        return w, h, bytes(out)
    raise MediaError("this DDS picture format can't be shown")


def _ps2_csm1(i: int) -> int:
    """PS2 256-colour palettes are stored in the GS's CSM1 order: in each block of 32 entries, the second
    and third groups of 8 are swapped."""
    return (i & ~0x18) | ((i & 0x08) << 1) | ((i & 0x10) >> 1)


# The PS2's graphics chip (GS) keeps textures in its own block order. The game's square 4- and 8-bit
# textures are stored pre-arranged for a 32-bit upload, so showing them means working out, for each pixel,
# where the GS would read it from. Tables from the GS manual (PSMCT32, PSMT8 and PSMT4 layouts).
_BLOCK32 = ((0, 1, 4, 5, 16, 17, 20, 21), (2, 3, 6, 7, 18, 19, 22, 23),
            (8, 9, 12, 13, 24, 25, 28, 29), (10, 11, 14, 15, 26, 27, 30, 31))
_BLOCK4 = ((0, 2, 8, 10), (1, 3, 9, 11), (4, 6, 12, 14), (5, 7, 13, 15),
           (16, 18, 24, 26), (17, 19, 25, 27), (20, 22, 28, 30), (21, 23, 29, 31))
_COL32 = ((0, 1, 4, 5, 8, 9, 12, 13), (2, 3, 6, 7, 10, 11, 14, 15),
          (16, 17, 20, 21, 24, 25, 28, 29), (18, 19, 22, 23, 26, 27, 30, 31),
          (32, 33, 36, 37, 40, 41, 44, 45), (34, 35, 38, 39, 42, 43, 46, 47),
          (48, 49, 52, 53, 56, 57, 60, 61), (50, 51, 54, 55, 58, 59, 62, 63))
_C8A = ((0, 4, 16, 20, 32, 36, 48, 52, 2, 6, 18, 22, 34, 38, 50, 54),
        (8, 12, 24, 28, 40, 44, 56, 60, 10, 14, 26, 30, 42, 46, 58, 62),
        (33, 37, 49, 53, 1, 5, 17, 21, 35, 39, 51, 55, 3, 7, 19, 23),
        (41, 45, 57, 61, 9, 13, 25, 29, 43, 47, 59, 63, 11, 15, 27, 31))
_C8B = ((96, 100, 112, 116, 64, 68, 80, 84, 98, 102, 114, 118, 66, 70, 82, 86),
        (104, 108, 120, 124, 72, 76, 88, 92, 106, 110, 122, 126, 74, 78, 90, 94),
        (65, 69, 81, 85, 97, 101, 113, 117, 67, 71, 83, 87, 99, 103, 115, 119),
        (73, 77, 89, 93, 105, 109, 121, 125, 75, 79, 91, 95, 107, 111, 123, 127))
_COL8 = _C8A + _C8B + tuple(tuple(v + 128 for v in r) for r in _C8A + _C8B)
_C4A = ((0, 8, 32, 40, 64, 72, 96, 104, 2, 10, 34, 42, 66, 74, 98, 106,
         4, 12, 36, 44, 68, 76, 100, 108, 6, 14, 38, 46, 70, 78, 102, 110),
        (16, 24, 48, 56, 80, 88, 112, 120, 18, 26, 50, 58, 82, 90, 114, 122,
         20, 28, 52, 60, 84, 92, 116, 124, 22, 30, 54, 62, 86, 94, 118, 126),
        (65, 73, 97, 105, 1, 9, 33, 41, 67, 75, 99, 107, 3, 11, 35, 43,
         69, 77, 101, 109, 5, 13, 37, 45, 71, 79, 103, 111, 7, 15, 39, 47),
        (81, 89, 113, 121, 17, 25, 49, 57, 83, 91, 115, 123, 19, 27, 51, 59,
         85, 93, 117, 125, 21, 29, 53, 61, 87, 95, 119, 127, 23, 31, 55, 63))
_C4B = ((192, 200, 224, 232, 128, 136, 160, 168, 194, 202, 226, 234, 130, 138, 162, 170,
         196, 204, 228, 236, 132, 140, 164, 172, 198, 206, 230, 238, 134, 142, 166, 174),
        (208, 216, 240, 248, 144, 152, 176, 184, 210, 218, 242, 250, 146, 154, 178, 186,
         212, 220, 244, 252, 148, 156, 180, 188, 214, 222, 246, 254, 150, 158, 182, 190),
        (129, 137, 161, 169, 193, 201, 225, 233, 131, 139, 163, 171, 195, 203, 227, 235,
         133, 141, 165, 173, 197, 205, 229, 237, 135, 143, 167, 175, 199, 207, 231, 239),
        (145, 153, 177, 185, 209, 217, 241, 249, 147, 155, 179, 187, 211, 219, 243, 251,
         149, 157, 181, 189, 213, 221, 245, 253, 151, 159, 183, 191, 215, 223, 247, 255))
_COL4 = _C4A + _C4B + tuple(tuple(v + 256 for v in r) for r in _C4A + _C4B)


def _gs32(x: int, y: int, bw: int) -> int:
    """Byte address of a 32-bit pixel. bw: buffer width in 64-pixel units."""
    return ((y >> 5) * bw + (x >> 6)) * 8192 + _BLOCK32[(y >> 3) & 3][(x >> 3) & 7] * 256 + _COL32[y & 7][x & 7] * 4


def _gs8(x: int, y: int, bw: int) -> int:
    """Byte address of an 8-bit pixel."""
    return ((y >> 6) * (bw >> 1) + (x >> 7)) * 8192 + _BLOCK32[(y >> 4) & 3][(x >> 4) & 7] * 256 + _COL8[y & 15][x & 15]


def _gs4(x: int, y: int, bw: int) -> int:
    """Nibble address of a 4-bit pixel."""
    return ((y >> 7) * (bw >> 1) + (x >> 7)) * 16384 + _BLOCK4[(y >> 4) & 7][(x >> 5) & 3] * 512 + _COL4[y & 15][x & 31]


@functools.lru_cache(maxsize=32)
def _ps2_order(w: int, h: int, bpp: int) -> Optional[Tuple[int, ...]]:
    """For each pixel of a pre-arranged PS2 texture, where its index sits in the stored data (in pixels).
    None when the size doesn't fit the arrangement."""
    per = 32 // bpp                                  # pixels in one 32-bit word
    up_w = w // 2
    up_h = (w * h) // per // up_w if up_w else 0
    if not up_w or not up_h or up_w * up_h * per != w * h:
        return None
    bw32 = max(1, up_w // 64)
    bw = max(2, w // 64)
    where = {}
    for py in range(up_h):
        for px in range(up_w):
            where[_gs32(px, py, bw32)] = (py * up_w + px) * per
    order = []
    for y in range(h):
        for x in range(w):
            if bpp == 8:
                a = _gs8(x, y, bw)
                base, sub = a & ~3, a & 3
            else:
                a = _gs4(x, y, bw)
                base, sub = (a >> 1) & ~3, (a & 7)
            at = where.get(base)
            if at is None:
                return None
            order.append(at + sub)
    if len(set(order)) != len(order):
        return None
    return tuple(order)


def _ps2_swizzled(w: int, h: int, bpp: int) -> bool:
    """Which PS2 pictures are stored in the GS's block order: every square one, and 8-bit ones at least
    128 x 64 (one 8-bit GS page). Smaller 8-bit ones that aren't square (mipmap levels such as 64 x 32)
    and 4-bit ones that aren't square are stored row by row."""
    return w == h or (bpp == 8 and w >= 128 and h >= 64)


def decode_p3di(img: bytes) -> Tuple[int, int, bytes]:
    """Pure3D's PS2 picture: "P3DI", u32, width, height, bits per pixel, palette bytes, pixel bytes, then the
    palette (RGBA, alpha 0-128) and the pixels (4-bit: two to a byte, low nibble first). Square textures (and
    big 8-bit ones, see _ps2_swizzled) are stored in the GS's block order (see _ps2_order), others row by row. Rows are stored bottom-up."""
    if img[:4] != b"P3DI" or len(img) < 28:
        raise MediaError("not a P3DI picture")
    _k, w, h, bpp, pal_size, pix_size = struct.unpack_from("<6I", img, 4)
    if not (0 < w <= 4096 and 0 < h <= 4096):
        raise MediaError("this PS2 picture has an odd size")
    pal_raw = img[28:28 + pal_size]
    pix = img[28 + pal_size:28 + pal_size + pix_size]
    if bpp == 32:
        out = bytearray()
        for i in range(0, min(len(pix), w * h * 4), 4):
            out += bytes((pix[i], pix[i + 1], pix[i + 2], min(255, pix[i + 3] * 2)))
        out += bytes(w * h * 4 - len(out))
        return w, h, _flip(bytes(out), w, h)
    if bpp not in (4, 8):
        raise MediaError(f"{bpp}-bit PS2 pictures can't be shown")
    colors = [pal_raw[i:i + 4] for i in range(0, len(pal_raw) - 3, 4)]
    if bpp == 8 and len(colors) == 256:
        colors = [colors[_ps2_csm1(i)] for i in range(256)]
    pal = [bytes((c[0], c[1], c[2], min(255, c[3] * 2))) for c in colors]
    if bpp == 4:
        idx = [(pix[i >> 1] >> (4 * (i & 1))) & 15 if (i >> 1) < len(pix) else 0 for i in range(w * h)]
    else:
        idx = list(pix[:w * h]) + [0] * max(0, w * h - len(pix))
    order = _ps2_order(w, h, bpp) if _ps2_swizzled(w, h, bpp) else None
    if order:
        idx = [idx[j] for j in order]
    blank = b"\0\0\0\0"
    out = b"".join(pal[i] if i < len(pal) else blank for i in idx)
    return w, h, _flip(out, w, h)


def _flip(rgba: bytes, w: int, h: int) -> bytes:
    """Upside down: the console versions store pictures bottom row first."""
    row = w * 4
    return b"".join(rgba[y * row:(y + 1) * row] for y in range(h - 1, -1, -1))


def texture_png(data: bytes, index: int) -> bytes:
    """One picture from a Pure3D file, as PNG."""
    texs = textures(data)
    if not 0 <= index < len(texs):
        raise MediaError("no such picture in this file")
    return picture_png(data, texs[index])


def decode_png(png_bytes: bytes) -> Tuple[int, int, bytes]:
    """A PNG's pixels as RGBA, top row first: 8-bit grey, RGB, palette, grey+alpha and RGBA, not
    interlaced (what the PC's textures are)."""
    if png_bytes[:8] != b"\x89PNG\r\n\x1a\n":
        raise MediaError("not a PNG picture")
    p, idat, plte, trns = 8, bytearray(), b"", b""
    w = h = depth = ctype = interlace = 0
    while p + 8 <= len(png_bytes):
        n, kind = struct.unpack_from(">I4s", png_bytes, p)
        body = png_bytes[p + 8:p + 8 + n]
        if kind == b"IHDR":
            w, h, depth, ctype, _c, _f, interlace = struct.unpack(">IIBBBBB", body[:13])
        elif kind == b"PLTE":
            plte = body
        elif kind == b"tRNS":
            trns = body
        elif kind == b"IDAT":
            idat += body
        elif kind == b"IEND":
            break
        p += 12 + n
    packed = ctype in (0, 3) and depth in (1, 2, 4)
    if (depth != 8 and not packed) or interlace or ctype not in (0, 2, 3, 4, 6):
        raise MediaError(f"PNG pictures with {depth}-bit colour type {ctype} can't be read here")
    bpp = {0: 1, 2: 3, 3: 1, 4: 2, 6: 4}[ctype]
    raw = zlib.decompress(bytes(idat))
    stride = (w * depth + 7) // 8 if packed else w * bpp
    rows, prev = [], bytearray(stride)
    for y in range(h):
        f = raw[y * (stride + 1)]
        cur = bytearray(raw[y * (stride + 1) + 1:(y + 1) * (stride + 1)])
        if f == 1:
            for i in range(bpp, stride):
                cur[i] = (cur[i] + cur[i - bpp]) & 255
        elif f == 2:
            for i in range(stride):
                cur[i] = (cur[i] + prev[i]) & 255
        elif f == 3:
            for i in range(stride):
                cur[i] = (cur[i] + (((cur[i - bpp] if i >= bpp else 0) + prev[i]) >> 1)) & 255
        elif f == 4:
            for i in range(stride):
                a = cur[i - bpp] if i >= bpp else 0
                b, c = prev[i], (prev[i - bpp] if i >= bpp else 0)
                pa, pb, pc = abs(b - c), abs(a - c), abs(a + b - 2 * c)
                cur[i] = (cur[i] + (a if pa <= pb and pa <= pc else b if pb <= pc else c)) & 255
        prev = cur
        if packed:                                  # 1, 2 or 4 bits a pixel, high bits first
            per, mask = 8 // depth, (1 << depth) - 1
            cur = bytearray((cur[x // per] >> (8 - depth * (x % per + 1))) & mask for x in range(w))
            if ctype == 0:
                cur = bytearray(v * 255 // mask for v in cur)
        rows.append(cur)
    out = bytearray(w * h * 4)
    o = 0
    for row in rows:
        for x in range(w):
            if ctype == 6:
                out[o:o + 4] = row[4 * x:4 * x + 4]
            elif ctype == 2:
                out[o:o + 4] = bytes(row[3 * x:3 * x + 3]) + b"\xff"
            elif ctype == 3:
                i = row[x]
                out[o:o + 4] = bytes(plte[3 * i:3 * i + 3]) + bytes([trns[i] if i < len(trns) else 255])
            elif ctype == 0:
                out[o:o + 4] = bytes([row[x]] * 3) + b"\xff"
            else:
                out[o:o + 4] = bytes([row[2 * x]] * 3) + bytes([row[2 * x + 1]])
            o += 4
    return w, h, bytes(out)


def pixels(data: bytes, t: Texture) -> Tuple[int, int, bytes]:
    """A picture found by textures() as RGBA, top row first, the way picture_png() shows it."""
    body = data[t.offset:t.offset + t.size]
    if t.kind == "png":
        return decode_png(body)
    if t.kind == "dds":
        w, h, rgba = decode_dds(body)
        return w, h, _flip(rgba, w, h)
    if t.kind == "p3di":
        return decode_p3di(body)
    raise MediaError(f"picture format {t.format} can't be read")


def _thumb(w: int, h: int, rgba: bytes, n: int = 16) -> List[float]:
    """An n x n grey thumbnail (each cell the average of its part of the picture, laid over grey)."""
    out = []
    for ty in range(n):
        y0, y1 = ty * h // n, max(ty * h // n + 1, (ty + 1) * h // n)
        for tx in range(n):
            x0, x1 = tx * w // n, max(tx * w // n + 1, (tx + 1) * w // n)
            total = count = 0
            for y in range(y0, min(y1, h)):
                o = (y * w + x0) * 4
                for _x in range(x0, min(x1, w)):
                    r, g, b, a = rgba[o], rgba[o + 1], rgba[o + 2], rgba[o + 3]
                    grey = (299 * r + 587 * g + 114 * b) / 1000
                    total += (grey * a + 60 * (255 - a)) / 255
                    count += 1
                    o += 4
            out.append(total / count if count else 60.0)
    return out


def likeness(a: Tuple[int, int, bytes], b: Tuple[int, int, bytes]) -> float:
    """How alike two pictures are, whatever their sizes and however much lighter or darker one is: the
    correlation of their grey thumbnails, 1 the same picture, 0 or less nothing alike. The same art at
    two resolutions scores above 0.9; different pictures under one name, below 0.2."""
    n = thumb_size(a[0], a[1], b[0], b[1])
    return correlate(_thumb(*a, n=n), _thumb(*b, n=n))


def thumb_size(*sides: int) -> int:
    return max(4, min([16] + list(sides)))


def thumb(w: int, h: int, rgba: bytes, n: int) -> List[float]:
    return _thumb(w, h, rgba, n)


def correlate(x: List[float], y: List[float]) -> float:
    mx, my = sum(x) / len(x), sum(y) / len(y)
    sxy = sum((p - mx) * (q - my) for p, q in zip(x, y))
    sx = sum((p - mx) ** 2 for p in x) ** 0.5
    sy = sum((q - my) ** 2 for q in y) ** 0.5
    if sx < 1e-6 or sy < 1e-6:                     # a flat colour: alike if the colours are
        return 1.0 if abs(mx - my) < 8 else 0.0
    return sxy / (sx * sy)


# The Xbox's textures are the PC's with darker mid-tones: measured on 5,511 textures both versions have,
# one curve (the same for red, green and blue, black and white staying put) takes a PC texture to within
# 4 levels of 255 of the Xbox's copy for 98% of them. It is a gamma of 1.33: 64 -> 41, 128 -> 102, 192 -> 175.
XBOX_GAMMA = 1.33
XBOX_CURVE = bytes(round(255 * (i / 255) ** XBOX_GAMMA) for i in range(256))


def xbox_look(png_bytes: bytes) -> bytes:
    """A PC texture (a PNG) with the Xbox's tones: the same pixels through XBOX_CURVE, transparency untouched.
    A picture with a palette only has its palette changed, so it stays exactly as sharp and as small."""
    if png_bytes[:8] != b"\x89PNG\r\n\x1a\n" or len(png_bytes) < 33:
        return png_bytes
    if png_bytes[25] == 3:                                   # colour type 3: a palette
        out, p = bytearray(png_bytes[:8]), 8
        while p + 12 <= len(png_bytes):
            n = struct.unpack_from(">I", png_bytes, p)[0]
            kind, body = png_bytes[p + 4:p + 8], png_bytes[p + 8:p + 8 + n]
            if kind == b"PLTE":
                body = body.translate(XBOX_CURVE)
            out += struct.pack(">I", len(body)) + kind + body + struct.pack(">I", zlib.crc32(kind + body) & 0xFFFFFFFF)
            p += 12 + n
        return bytes(out)
    try:
        w, h, rgba = decode_png(png_bytes)
    except (MediaError, struct.error, ValueError, IndexError, zlib.error):
        return png_bytes
    px = bytearray(rgba)
    for ch in range(3):
        px[ch::4] = rgba[ch::4].translate(XBOX_CURVE)
    return png(w, h, bytes(px))


def picture_png(data: bytes, t: Texture) -> bytes:
    """A picture found by textures(), as PNG, top row first."""
    body = data[t.offset:t.offset + t.size]
    if t.kind == "png":
        return body
    if t.kind == "dds":
        w, h, rgba = decode_dds(body)
        return png(w, h, _flip(rgba, w, h))
    if t.kind == "p3di":
        return png(*decode_p3di(body))
    raise MediaError(f"picture format {t.format} can't be shown")
