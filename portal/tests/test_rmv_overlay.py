"""The PS2's movies (portal/tools/rmv.py) and code overlays (portal/tools/ps2_overlay.py), on made-up files."""
import struct
import wave

import pytest

import ps2_binary as PB
import ps2_overlay as OV
import rmv as RMV


# --------------------------------------------------------------------------- movies

def make_rmv(video: bytes, sound: bytes, w=640, h=336, frames=3, fps100=2997) -> bytes:
    start = 0x800
    vend = start + ((len(video) + 0x7FF) & ~0x7FF)
    head = bytearray(b"rmvps212" + struct.pack("<HHIIII", w, h, frames, vend + len(sound), start, 1))
    head += struct.pack("<16I", vend, *([0] * 15)) + struct.pack("<16I", len(sound), *([0] * 15))
    head += struct.pack("<I", fps100)
    head = bytes(head).ljust(start, b"\xad")
    return head + video.ljust(vend - start, b"\xad") + sound


def vag_rsd(frames: bytes, channels=2, rate=48000) -> bytes:
    head = b"RSD6VAG " + struct.pack("<III", channels, 16, rate) + b"****movie.wav\0"
    return head.ljust(0x800, b"\0") + frames


def test_rmv_header():
    data = make_rmv(b"\x01" * 100, vag_rsd(b""))
    info = RMV.read_header(data[:RMV.HEADER])
    assert (info.width, info.height, info.frames, info.fps) == (640, 336, 3, 29.97)
    assert info.video_start == 0x800 and info.video_end == 0x1000 and info.file_size == len(data)
    assert info.tracks == [(0x1000, 0x800)]
    assert info.seconds == pytest.approx(3 / 29.97)
    with pytest.raises(RMV.RmvError):
        RMV.read_header(b"RIFF" + bytes(200))


def test_rmv_split_into_ipu_and_sound(tmp_path):
    video = bytes(range(1, 200)) * 30                        # ends in a byte that isn't padding
    left = bytes([0x0C, 0]) + bytes([0x11] * 14)
    right = bytes([0x0C, 0]) + bytes([0x22] * 14)
    movie = tmp_path / "intro.rmv"
    movie.write_bytes(make_rmv(video, vag_rsd((left + right) * 2)))
    made = RMV.split(movie, tmp_path / "out")
    assert [p.name for p in made] == ["intro.ipu", "intro.rsd", "intro.wav"]
    ipu = made[0].read_bytes()
    assert ipu[:4] == b"ipum" and struct.unpack_from("<IHHI", ipu, 4) == (len(video) + 8, 640, 336, 3)
    assert ipu[16:] == video                                 # the 0xAD padding is gone
    with wave.open(str(made[2])) as w:
        assert (w.getnchannels(), w.getframerate(), w.getnframes()) == (2, 48000, 56)
    assert RMV.main([str(movie), "--info"]) == 0


def test_padding_is_only_dropped_at_the_end(tmp_path):
    video = b"\xad" * 5000 + b"\x01" + b"\xad" * 10
    movie = tmp_path / "m.rmv"
    movie.write_bytes(make_rmv(video, vag_rsd(b"")))
    ipu = RMV.split(movie, tmp_path, wav=False)[0].read_bytes()
    assert ipu[16:] == b"\xad" * 5000 + b"\x01"


# --------------------------------------------------------------------------- overlays

LOAD = 0x845480


def make_overlay(code_words, data: bytes = b"", ctors=(), name=b"Test.bin", number=7, load=LOAD, bss=0):
    text = bytes(0x40) + b"".join(struct.pack("<I", w) for w in code_words)
    text = text.ljust((len(text) + 15) & ~15, b"\0")
    ctor_at = load + 0x40 + len(text) + len(data)
    table = b"".join(struct.pack("<I", c) for c in ctors)
    dsize = len(data) + len(table)
    head = b"MWo3" + struct.pack("<7I", number, load, len(text), dsize, bss, ctor_at, ctor_at + len(table))
    head += name.ljust(0x20, b"\0")
    return head + text + data + table


def jal(target):
    return (3 << 26) | ((target >> 2) & 0x03FFFFFF)


JR_RA, NOP = 0x03E00008, 0


def test_overlay_header_calls_and_constructors():
    fn = LOAD + 0x80                                         # the first function, after 0x40 zero bytes of code
    data = make_overlay([0x27BDFFF0, jal(0x100008), NOP, jal(fn), NOP, JR_RA, 0x27BD0010],
                        data=b"hello\0\0\0", ctors=[fn])
    ov = OV.read_header(data)
    assert (ov.number, ov.load, ov.name, ov.bss_size) == (7, LOAD, "Test.bin", 0)
    assert ov.text == (LOAD + 0x40, ov.text_size) and ov.data[0] == LOAD + 0x40 + ov.text_size
    assert OV.constructors(data) == [fn]
    inside, outside = OV.calls(data)
    assert inside == [fn] and outside == [0x100008]
    assert OV.check(data, {0x100008}) == (1, 1) and OV.check(data, {0x100010}) == (0, 1)
    with pytest.raises(OV.OverlayError):
        OV.read_header(data[:-4])                            # sizes no longer add up
    with pytest.raises(OV.OverlayError):
        OV.read_header(b"ELF" + data[3:])


def test_overlay_as_an_elf_the_ps2_reader_opens(tmp_path):
    data = make_overlay([0x27BDFFF0, NOP, JR_RA, 0x27BD0010], bss=0x80)
    elf = tmp_path / "t.elf"
    elf.write_bytes(OV.to_elf(data))
    img = PB.Ps2Image(elf)
    assert img.read(LOAD, len(data)) == data                 # the whole file sits at its load address
    assert img.word(LOAD + 0x80) == 0x27BDFFF0                # code starts after 0x40 zero bytes
    assert img.entry == LOAD + 0x40
    assert OV.main([str(tmp_path / "missing.bin")]) == 1
