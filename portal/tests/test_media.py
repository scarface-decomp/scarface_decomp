"""Previews of the person's own game files: sounds decoded to something a browser plays, and the pictures
inside Pure3D files decoded to PNG (PC PNG, Xbox DDS, PS2 P3DI with the GS block order). Everything here is
made up for the tests; nothing needs the game."""
import io
import struct
import wave
import zlib

import pytest

import media


# --------------------------------------------------------------------------- helpers

def png_pixels(data: bytes):
    """Width, height and RGBA rows of a PNG written by media.png (filter 0 only)."""
    assert data[:8] == b"\x89PNG\r\n\x1a\n"
    w, h = struct.unpack_from(">II", data, 16)
    off, idat = 8, b""
    while off < len(data):
        n = struct.unpack_from(">I", data, off)[0]
        kind = data[off + 4:off + 8]
        if kind == b"IDAT":
            idat += data[off + 8:off + 8 + n]
        off += 12 + n
    raw = zlib.decompress(idat)
    rows = [raw[y * (w * 4 + 1) + 1:(y + 1) * (w * 4 + 1)] for y in range(h)]
    return w, h, rows


def rsd(codec: bytes, channels: int, rate: int, body: bytes) -> bytes:
    head = b"RSD6" + codec + struct.pack("<III", channels, 16, rate) + b"****" + b"art\\sound\\x.wav\0"
    return head.ljust(media.RSD_DATA, b"\0") + body


def chunk(cid: int, head: bytes, kids: bytes = b"") -> bytes:
    return struct.pack("<III", cid, 12 + len(head), 12 + len(head) + len(kids)) + head + kids


def p3d_with(pictures) -> bytes:
    """A Pure3D file holding one Image chunk per (name, w, h, bpp, format, bytes)."""
    body = b""
    for name, w, h, bpp, fmt, data in pictures:
        n = name.encode() + b"\0"
        head = bytes([len(n)]) + n + struct.pack("<7I", 14000, w, h, bpp, 0, 0, fmt)
        body += chunk(0x19001, head, chunk(0x19002, struct.pack("<I", len(data)) + data))
    tex = chunk(0x19000, b"\x04tex\0" + struct.pack("<I", 14000), body)
    return b"P3D\xff" + struct.pack("<II", 12, 12 + len(tex)) + tex


def p3di(w: int, h: int, bpp: int, palette: bytes, pixels: bytes) -> bytes:
    return b"P3DI" + struct.pack("<6I", 13, w, h, bpp, len(palette), len(pixels)) + palette + pixels


# --------------------------------------------------------------------------- sounds

def test_ogg_and_wav_pass_through():
    ogg = b"OggS" + bytes(60)
    assert media.playable(rsd(b"OOGV", 2, 44100, ogg)) == (ogg, "audio/ogg", ".ogg")
    assert media.playable(ogg)[1] == "audio/ogg"
    wav = media._wav(b"\1\0\2\0", 1, 22050)
    assert media.playable(wav) == (wav, "audio/wav", ".wav")


def test_xbox_wma_is_offered_from_its_asf_header():
    asf = bytes.fromhex("3026B2758E66CF11A6D900AA0062CE6C") + b"rest"
    body, mime, ext = media.playable(rsd(b"WMA ", 2, 44100, b"\0" * 8 + asf))
    assert body == asf and mime == "audio/x-ms-wma" and ext == ".wma"


def test_pcm_becomes_a_wav():
    body, mime, _ = media.playable(rsd(b"PCM ", 1, 11025, struct.pack("<4h", 1, -2, 300, -400)))
    with wave.open(io.BytesIO(body)) as w:
        assert (w.getnchannels(), w.getframerate(), w.readframes(4)) == (1, 11025, struct.pack("<4h", 1, -2, 300, -400))
    assert mime == "audio/wav"


def test_ps2_vag_frames():
    # A frame with no prediction and shift 12 gives the nibbles themselves; flag 7 ends the sound.
    frame = bytes([0x0C, 0x00]) + bytes([0x21] * 14)
    end = bytes([0x00, 0x07]) + bytes(14)
    samples = media._vag_channel(frame + end + frame)
    assert samples == [1, 2] * 14
    # Prediction filter 1 (shift 0) carries the last sample on at 60/64.
    rise = media._vag_channel(bytes([0x10, 0]) + bytes([0x07] + [0] * 13))
    assert rise[:3] == [28672, 26880, 25200]


def test_ps2_vag_stereo_takes_turns_frame_by_frame():
    left = bytes([0x0C, 0x00]) + bytes([0x11] * 14)            # every sample 1
    right = bytes([0x0C, 0x00]) + bytes([0x22] * 14)           # every sample 2
    pcm = media.decode_vag((left + right) * 3, 2)
    assert struct.unpack(f"<{28 * 3 * 2}h", pcm) == (1, 2) * (28 * 3)


def test_ps2_vag_through_playable():
    frames = bytes([0x0C, 0x00]) + bytes([0x11] * 14)
    body, mime, ext = media.playable(rsd(b"VAG\0", 1, 22050, frames * 4))
    with wave.open(io.BytesIO(body)) as w:
        assert w.getnframes() == 28 * 4 and w.getframerate() == 22050
    assert (mime, ext) == ("audio/wav", ".wav")


def test_xbox_adpcm_block():
    # Predictor 1000, step index 0, then nibbles of 0: each sample moves up by step >> 3 (7 >> 3 = 0) and the
    # index stays at 0, so the sound holds still at 1000.
    block = struct.pack("<hBB", 1000, 0, 0) + bytes(32)
    pcm = media.decode_xbox_adpcm(block, 1)
    assert struct.unpack("<64h", pcm) == (1000,) * 64
    # Nibble 7 (+7/8 of a growing step) climbs until it tops out.
    climb = struct.unpack("<64h", media.decode_xbox_adpcm(struct.pack("<hBB", 0, 0, 0) + bytes([0x77] * 32), 1))
    assert all(b >= a for a, b in zip(climb, climb[1:])) and climb[-1] == 32767
    with pytest.raises(media.MediaError):
        media.decode_xbox_adpcm(block, 3)


def test_radical_adpcm_mono_block():
    # Step index 0 (step 7): nibble 0 moves by (1 * 7) >> 3 = 0, so the sound holds at 1000 for 32 samples.
    still = struct.pack("<hh", 0, 1000) + bytes(16)
    assert struct.unpack("<32h", media.decode_radp(still, 1)) == (1000,) * 32
    # Nibble 1 is +(3 * 7) >> 3 = +2 and nibble 9 is -2; the index stays at 0. Low nibble first.
    wobble = struct.pack("<hh", 0, 1000) + bytes([0x91] * 16)
    assert struct.unpack("<32h", media.decode_radp(wobble, 1)) == (1002, 1000) * 16
    # Each block starts again from its own header; a short tail is ignored.
    two = media.decode_radp(wobble + struct.pack("<hh", 0, -5) + bytes(16) + b"\x01\x02", 1)
    assert struct.unpack("<64h", two)[32:] == (-5,) * 32


def test_radical_adpcm_step_index_and_clamping():
    # Index 10 (step 19), nibble 7: +(15 * 19) >> 3 = +35, and the index moves up by 8.
    block = struct.pack("<hh", 10, 0) + bytes([0x07]) + bytes(15)
    first = struct.unpack("<32h", media.decode_radp(block, 1))[0]
    assert first == 35
    # A header index past 88 is treated as 88, and the samples stop at the 16-bit limits.
    loud = struct.unpack("<32h", media.decode_radp(struct.pack("<hh", 200, 32000) + bytes([0x77] * 16), 1))
    assert loud == (32767,) * 32
    quiet = struct.unpack("<32h", media.decode_radp(struct.pack("<hh", 88, -32000) + bytes([0xFF] * 16), 1))
    assert quiet == (-32768,) * 32


def test_radical_adpcm_stereo_rows():
    # Both headers first, then rows of one byte per channel: left low, right low, left high, right high.
    block = struct.pack("<hhhh", 0, 100, 0, -100) + bytes([0x91, 0x19] * 16)
    frames = struct.unpack("<64h", media.decode_radp(block, 2))
    assert frames[:4] == (102, -102, 100, -100)
    assert frames == (102, -102, 100, -100) * 16
    with pytest.raises(media.MediaError):
        media.decode_radp(block, 3)


def test_radical_adpcm_through_playable():
    block = struct.pack("<hhhh", 0, 100, 0, -100) + bytes([0x91, 0x19] * 16)
    data, mime, ext = media.playable(rsd(b"RADP", 2, 24000, block * 3))
    assert (mime, ext) == ("audio/wav", ".wav")
    with wave.open(io.BytesIO(data)) as w:
        assert (w.getnchannels(), w.getframerate(), w.getnframes()) == (2, 24000, 96)


def test_unknown_sounds_are_refused():
    with pytest.raises(media.MediaError):
        media.playable(b"not a sound")
    with pytest.raises(media.MediaError):
        media.playable(rsd(b"ZZZZ", 1, 22050, bytes(64)))


# --------------------------------------------------------------------------- pictures

def test_png_writer_round_trips():
    rgba = bytes(range(16)) * 2
    w, h, rows = png_pixels(media.png(2, 4, rgba))
    assert (w, h) == (2, 4) and b"".join(rows) == rgba


def test_textures_found_in_a_pure3d_file():
    pc = media.png(2, 2, bytes([255, 0, 0, 255]) * 4)
    data = p3d_with([("a.bmp", 2, 2, 32, 1, pc), ("b.tga", 4, 4, 8, 12, p3di(4, 4, 8, bytes(1024), bytes(16)))])
    texs = media.textures(data)
    assert [(t.name, t.kind, t.width) for t in texs] == [("a.bmp", "png", 2), ("b.tga", "p3di", 4)]
    assert media.texture_png(data, 0) == pc
    with pytest.raises(media.MediaError):
        media.texture_png(data, 5)


def test_a_lone_picture_is_a_list_of_one():
    pc = media.png(3, 1, bytes(12))
    assert [(t.kind, t.width, t.height) for t in media.textures(pc)] == [("png", 3, 1)]
    assert media.textures(b"nothing") == []


def test_dxt1_block():
    # Two colours, pure red (0xF800) and pure blue (0x001F); index 0 everywhere but the last pixel (1).
    block = struct.pack("<HHI", 0xF800, 0x001F, 1 << 30)
    rgba = media.decode_dxt(block, 4, 4, 1)
    assert rgba[:4] == bytes([255, 0, 0, 255]) and rgba[-4:] == bytes([0, 0, 255, 255])


def test_xbox_dds_is_shown_the_right_way_up():
    head = bytearray(128)
    head[:4] = b"DDS "
    struct.pack_into("<II", head, 12, 4, 4)                       # height, width
    struct.pack_into("<I4s", head, 80, 4, b"DXT1")
    # One 4x4 block, rows 0-2 red and row 3 blue in storage; stored bottom row first, so blue is on top.
    blk = struct.pack("<HHI", 0xF800, 0x001F, 0x55000000)
    data = p3d_with([("x", 4, 4, 32, 6, bytes(head) + blk)])
    _w, _h, rows = png_pixels(media.texture_png(data, 0))
    assert rows[0][:4] == bytes([0, 0, 255, 255]) and rows[3][:4] == bytes([255, 0, 0, 255])


def test_csm1_palette_order():
    assert [media._ps2_csm1(i) for i in range(32)] == list(range(8)) + list(range(16, 24)) + list(range(8, 16)) + list(range(24, 32))


@pytest.mark.parametrize("size", [16, 32, 64, 128, 256])
def test_ps2_8bit_order_matches_the_known_formula(size):
    """The GS-based order agrees with the formula PS2 texture tools have used for years."""
    w = h = size
    expect = []
    for y in range(h):
        for x in range(w):
            block = (y & ~0xF) * w + (x & ~0xF) * 2
            swap = (((y + 2) >> 2) & 1) * 4
            py = (((y & ~3) >> 1) + (y & 1)) & 7
            column = py * w * 2 + ((x + swap) & 7) * 4
            expect.append(block + column + ((y >> 1) & 1) + ((x >> 2) & 2))
    assert media._ps2_order(w, h, 8) == tuple(expect)


@pytest.mark.parametrize("size", [32, 64, 128, 256])
def test_ps2_4bit_order_is_a_full_shuffle(size):
    order = media._ps2_order(size, size, 4)
    assert order is not None and sorted(order) == list(range(size * size))


def _store(order, picture):
    stored = [0] * len(picture)
    for i, j in enumerate(order):
        stored[j] = picture[i]
    return stored


def test_ps2_square_picture_unshuffles_and_flips():
    w = h = 32
    picture = [(x // 4 + y) % 256 for y in range(h) for x in range(w)]     # each pixel its own palette entry
    stored = _store(media._ps2_order(w, h, 8), picture)
    palette = b"".join(bytes([i, 255 - i, 0, 0x80]) for i in range(256))
    stored_palette = b"".join(palette[media._ps2_csm1(i) * 4:media._ps2_csm1(i) * 4 + 4] for i in range(256))
    data = p3di(w, h, 8, stored_palette, bytes(stored))
    gw, gh, rgba = media.decode_p3di(data)
    rows = [rgba[y * w * 4:(y + 1) * w * 4] for y in range(h)]
    for y in range(h):                                                      # bottom row first
        want = b"".join(bytes([v, 255 - v, 0, 255]) for v in picture[(h - 1 - y) * w:(h - y) * w])
        assert rows[y] == want


def test_ps2_4bit_picture():
    w = h = 32
    picture = [(x + y) % 16 for y in range(h) for x in range(w)]
    stored = _store(media._ps2_order(w, h, 4), picture)
    packed = bytes(stored[i] | (stored[i + 1] << 4) for i in range(0, len(stored), 2))
    palette = b"".join(bytes([i * 16, 0, 0, 0x40]) for i in range(16))
    _w, _h, rgba = media.decode_p3di(p3di(w, h, 4, palette, packed))
    assert rgba[:4] == bytes([picture[(h - 1) * w] * 16, 0, 0, 0x80])       # alpha 0x40 of 0x80 is half
    assert rgba[-4:] == bytes([picture[w - 1] * 16, 0, 0, 0x80])


def test_ps2_non_square_pictures_are_row_by_row():
    w, h = 8, 4
    palette = b"".join(bytes([i, i, i, 0x80]) for i in range(256))
    stored_palette = b"".join(palette[media._ps2_csm1(i) * 4:media._ps2_csm1(i) * 4 + 4] for i in range(256))
    _w, _h, rgba = media.decode_p3di(p3di(w, h, 8, stored_palette, bytes(range(32))))
    assert rgba[:4] == bytes([24, 24, 24, 255]) and rgba[-4:] == bytes([7, 7, 7, 255])


def test_big_8bit_ps2_pictures_that_arent_square_are_in_block_order_too():
    w, h = 128, 64
    picture = [(x // 2 + y) % 256 for y in range(h) for x in range(w)]
    stored = _store(media._ps2_order(w, h, 8), picture)
    palette = b"".join(bytes([i, i, i, 0x80]) for i in range(256))
    stored_palette = b"".join(palette[media._ps2_csm1(i) * 4:media._ps2_csm1(i) * 4 + 4] for i in range(256))
    _w, _h, rgba = media.decode_p3di(p3di(w, h, 8, stored_palette, bytes(stored)))
    assert rgba[:4 * w:4] == bytes(picture[(h - 1) * w:])                   # bottom row first
    assert not media._ps2_swizzled(64, 32, 8) and not media._ps2_swizzled(256, 128, 4)


def test_odd_ps2_pictures_are_refused():
    with pytest.raises(media.MediaError):
        media.decode_p3di(p3di(0, 4, 8, b"", b""))
    with pytest.raises(media.MediaError):
        media.decode_p3di(p3di(4, 4, 16, b"", bytes(32)))
    with pytest.raises(media.MediaError):
        media.decode_p3di(b"nope")


# --------------------------------------------------------------------------- the portal's endpoints

def test_portal_previews_only_copied_files_for_this_computer(monkeypatch, tmp_path):
    import importlib
    import sys
    from conftest import PORTAL
    sys.path.insert(0, str(PORTAL))
    server = importlib.import_module("decomp_portal_server")
    snd = tmp_path / "x.rsd"
    snd.write_bytes(rsd(b"PCM ", 1, 8000, struct.pack("<2h", 5, -5)))
    pic = tmp_path / "t.p3d"
    pic.write_bytes(p3d_with([("w.bmp", 1, 1, 32, 1, media.png(1, 1, bytes(4)))]))
    files = {("pc", "art/x.rsd"): snd, ("ps2", "art/t.p3d"): pic}
    monkeypatch.setattr(server.GAME_FILES, "file_path", lambda v, p: files.get((v, p)))

    sent = []

    class Fake:
        client_address = ("127.0.0.1", 5)
        headers = {}

        def _send(self, code, body, ctype, extra=None):
            sent.append((code, ctype, body))

        def _json(self, obj, code=200):
            sent.append((code, "json", obj))

    def ask(what, peer="127.0.0.1", headers=None, **q):
        f = Fake()
        f.client_address = (peer, 5)
        f.headers = headers or {}
        server.Handler.get_game_file_preview(f, what, lambda k, d="": q.get(k, d))
        return sent[-1]

    code, ctype, body = ask("sound", version="pc", path="art/x.rsd")
    assert code == 200 and ctype == "audio/wav" and body[:4] == b"RIFF"
    code, _, obj = ask("pictures", version="ps2", path="art/t.p3d")
    assert obj["pictures"] == [{"i": 0, "name": "w.bmp", "width": 1, "height": 1, "kind": "png"}]
    assert ask("picture", version="ps2", path="art/t.p3d", i="0")[1] == "image/png"
    assert ask("picture", version="ps2", path="art/t.p3d", i="9")[0] == 415
    assert ask("sound", version="pc", path="art/other.rsd")[0] == 404
    assert ask("sound", peer="192.168.1.20", version="pc", path="art/x.rsd")[0] == 403
    assert ask("sound", headers={"Sec-Fetch-Site": "cross-site"}, version="pc", path="art/x.rsd")[0] == 403


def test_file_on_disk_stays_inside_the_copy(tmp_path):
    import game_assets as GA
    (tmp_path / "Xbox" / "art").mkdir(parents=True)
    (tmp_path / "Xbox" / "art" / "a.rsd").write_bytes(b"12345")
    index = {"versions": {"xbox": {"files": [["art/a.rsd", 5, "s", "only", "Xbox/art/a.rsd", None, 1],
                                             ["art/b.rsd", 5, "s", "only", "../../etc/passwd", None, 1],
                                             ["art/c.rsd", 9, "s", "only", "Xbox/art/a.rsd", None, 1],
                                             ["art/d.rsd", 5, "s", "only", "", None, 0]]}}}
    assert GA.file_on_disk(tmp_path, index, "xbox", "art/a.rsd") == tmp_path / "Xbox" / "art" / "a.rsd"
    assert GA.file_on_disk(tmp_path, index, "xbox", "art/b.rsd") is None       # outside the folder
    assert GA.file_on_disk(tmp_path, index, "xbox", "art/c.rsd") is None       # changed since
    assert GA.file_on_disk(tmp_path, index, "xbox", "art/d.rsd") is None       # never copied
    assert GA.file_on_disk(tmp_path, index, "pc", "art/a.rsd") is None
