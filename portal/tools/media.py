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
    XADP      Xbox: Xbox ADPCM (IMA ADPCM in 36-byte blocks per channel), decoded to WAV here
    VAG       PS2: PS2 ADPCM (16-byte frames of 28 samples), decoded to WAV here
    RADP      Xbox prototype: Radical's IMA ADPCM (20-byte blocks per channel), decoded to WAV here
    PCM       16-bit PCM, wrapped as WAV

Textures live in Pure3D (.p3d) files: a Texture chunk (0x19000) holds Image chunks (0x19001) whose Image
Data chunk (0x19002) is the picture:

    PC        a PNG file (format 1), shown as it is
    Xbox      a DDS file (formats 6/8/10: DXT1, DXT3, DXT5, or uncompressed), decoded to PNG here
    PS2       Pure3D's own "P3DI" image with a palette (formats 11/12: 4- or 8-bit), decoded to PNG here

    sound_info(data) / playable(data) -> (bytes, mime type, file extension)
    textures(data) -> [Texture] / texture_png(data, index) -> PNG bytes
"""

from __future__ import annotations

import functools
import io
import struct
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


def decode_xbox_adpcm(body: bytes, channels: int) -> bytes:
    """Xbox ADPCM: per channel, 36-byte blocks (int16 predictor, u8 step index, u8 0, then 32 bytes = 64
    samples, low nibble first). With two channels the headers come first and then 4-byte runs alternate."""
    if channels not in (1, 2):
        raise MediaError(f"Xbox ADPCM with {channels} channels")
    block = 36 * channels
    out = bytearray()
    for b in range(0, len(body) - block + 1, block):
        blk = body[b:b + block]
        chans = []
        for c in range(channels):
            pred, index = struct.unpack_from("<hB", blk, 4 * c)
            index = min(index, 88)
            nibbles = bytearray()
            for k in range(8):                                 # eight 4-byte runs per channel
                o = 4 * channels + 4 * (k * channels + c)
                nibbles += blk[o:o + 4]
            samples = []
            for byte in nibbles:
                for nib in (byte & 15, byte >> 4):
                    step = IMA_STEP[index]
                    diff = step >> 3
                    if nib & 1:
                        diff += step >> 2
                    if nib & 2:
                        diff += step >> 1
                    if nib & 4:
                        diff += step
                    pred = _clamp16(pred - diff if nib & 8 else pred + diff)
                    index = min(88, max(0, index + IMA_INDEX[nib]))
                    samples.append(pred)
            chans.append(samples)
        for i in range(64):
            for c in range(channels):
                out += struct.pack("<h", chans[c][i])
    return bytes(out)


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
        return _wav(decode_xbox_adpcm(body, ch), ch, rate), "audio/wav", ".wav"
    if codec == "VAG":
        return _wav(decode_vag(body, ch), ch, rate), "audio/wav", ".wav"
    if codec == "RADP":
        return _wav(decode_radp(body, ch), ch, rate), "audio/wav", ".wav"
    if codec in ("PCM", "PCMB"):
        pcm = body if codec == "PCM" else b"".join(body[i:i + 2][::-1] for i in range(0, len(body) - 1, 2))
        return _wav(pcm[:len(pcm) // (2 * ch) * 2 * ch], ch, rate), "audio/wav", ".wav"
    raise MediaError(f"the {info['codec']} codec can't be previewed")


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


def decode_p3di(img: bytes) -> Tuple[int, int, bytes]:
    """Pure3D's PS2 picture: "P3DI", u32, width, height, bits per pixel, palette bytes, pixel bytes, then the
    palette (RGBA, alpha 0-128) and the pixels (4-bit: two to a byte, low nibble first). Square textures are
    stored in the GS's block order (see _ps2_order), others row by row. Rows are stored bottom-up."""
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
    order = _ps2_order(w, h, bpp) if w == h else None
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
    t = texs[index]
    body = data[t.offset:t.offset + t.size]
    if t.kind == "png":
        return body
    if t.kind == "dds":
        w, h, rgba = decode_dds(body)
        return png(w, h, _flip(rgba, w, h))
    if t.kind == "p3di":
        return png(*decode_p3di(body))
    raise MediaError(f"picture format {t.format} can't be shown")
