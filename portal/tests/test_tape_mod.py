"""Adding songs to the tape player (portal/tools/tape_mod.py)."""

import struct
import sys
from pathlib import Path

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import media  # noqa: E402
import p3d  # noqa: E402
import tape_mod as T  # noqa: E402


def pstr(s):
    b = s.encode()
    return struct.pack("<I", len(b)) + b + b"\0"


def cue(*layers):
    head = pstr("tapeplayer") + struct.pack("<II", 1, 1) + pstr("tape") + struct.pack("<I", len(layers))
    return head + b"".join(layers)


def silent(name):
    return pstr(name) + T.LAYER_FLAGS + struct.pack("<III", 7, 8, 0) + struct.pack("<II", 1, 1)


def test_a_cue_reads_and_a_new_layer_fits():
    one = T.layer_record("tp_2020", "music\\tapeplayer\\tp_2020", 49909340, 2, 48000, rand=lambda n: 5, stamp=1)
    body = cue(one, silent("tp_donomar_guerra"))
    at, n, layers = T.parse_cue(body)
    assert n == 2 and layers == [("tp_2020", ["music\\tapeplayer\\tp_2020"]), ("tp_donomar_guerra", [])]
    assert struct.unpack_from("<I", body, at)[0] == 2
    longer = bytearray(body + T.layer_record("Unused_Music_3", "music\\tapeplayer\\Unused_Music_3", 400, 2, 48000))
    struct.pack_into("<I", longer, at, 3)
    assert T.parse_cue(bytes(longer))[2][-1] == ("Unused_Music_3", ["music\\tapeplayer\\Unused_Music_3"])
    with pytest.raises(T.ModError):                    # a count that doesn't match the layers
        T.parse_cue(body + T.layer_record("x", "music\\tapeplayer\\x", 4, 2, 48000))


def test_the_stock_layer_bytes():
    """tp_2020's record as the game ships it (only the ids differ from file to file)."""
    rec = T.layer_record("tp_2020", "music\\tapeplayer\\tp_2020", 0x02F98E5C, 2, 48000,
                         rand=lambda n: 0x5A565350, stamp=0x3BC2D2C0)
    assert rec.startswith(bytes.fromhex("07000000") + b"tp_2020\0" + bytes.fromhex("000000000001000000000000000000"))
    assert rec.endswith(bytes.fromhex("5c8ef902 00 02000000 80bb0000 10000000 01000000 01000000".replace(" ", "")))


def test_ogg_and_rsd():
    ogg = (b"OggS" + bytes(22) + b"\x01vorbis" + bytes(4) + bytes([2]) + struct.pack("<I", 48000) + bytes(10)
           + b"OggS\x00\x04" + struct.pack("<q", 48000 * 3) + bytes(16))
    assert T.ogg_info(ogg) == (2, 48000, 144000)
    template = b"RSD6OOGV" + struct.pack("<3I", 1, 16, 22050) + b"****" + bytes(T.RSD_HEADER - 24)
    out = T.rsd(template, ogg, "music\\tapeplayer\\tp_mine")
    info = media.sound_info(out)
    assert (info["codec"], info["channels"], info["rate"]) == ("OOGV", 2, 48000)
    assert info["source_name"].endswith("tp_mine.wav") and out[T.RSD_HEADER:] == ogg
    with pytest.raises(T.ModError):
        T.ogg_info(b"RIFF")


def bible(lines):
    keys = sorted((p3d.name_key(k), t) for k, t in lines)
    blob, starts = b"", []
    for _k, t in keys:
        starts.append(len(blob))
        blob += t.encode("utf-16-le") + b"\0\0"
    body = pstr("HUD") + b"E" + struct.pack("<3I", len(keys), media.BIBLE_MARK, len(blob))
    body += struct.pack(f"<{len(keys)}I", *[k for k, _ in keys]) + struct.pack(f"<{len(keys)}I", *starts) + blob
    body += b"\0" * ((-len(body)) % 4)
    return body


def test_the_text_bible():
    body = bible([("TAPE_PLAYER_TRACK_0_TITLE", "Yellow Pills"), ("SONG_LOCKED", "SONG LOCKED")])
    assert T.bible_body(body, []) == body
    data = b"P3D\xff" + struct.pack("<II", 12, 0)
    chunk = struct.pack("<3I", media.TEXT_BIBLE, 12 + len(body), 12 + len(body)) + body
    data = data[:4] + struct.pack("<II", 12, 12 + len(chunk)) + chunk
    tree = p3d.read_tree(data)
    assert T.rebuild(data, tree, {}) == data
    new = T.rebuild(data, tree, {tree[0].offset: T.bible_body(body, [("TAPE_PLAYER_TRACK_108_TITLE", "Italy"),
                                                                     ("TAPE_PLAYER_TRACK_0_TITLE", "Renamed")])})
    lines = dict(media.text_bible(new))
    assert lines[p3d.name_key("TAPE_PLAYER_TRACK_108_TITLE")] == "Italy"
    assert lines[p3d.name_key("TAPE_PLAYER_TRACK_0_TITLE")] == "Renamed"
    assert lines[p3d.name_key("SONG_LOCKED")] == "SONG LOCKED"
    assert [k for k, _ in media.text_bible(new)] == sorted(lines)


def test_track_numbers():
    songs = [{"layer": "tp_a"}, {"layer": "tp_b", "track": 5}, {"layer": "Unused_Music_0"}]
    assert T.numbers(songs) == {"tp_a": 108, "tp_b": 5, "Unused_Music_0": 109}
    assert T.numbers([{"layer": f"s{i}"} for i in range(20)])["s19"] == 127
    for bad in ([{"layer": f"s{i}"} for i in range(21)], [{"layer": "a b"}], [{"layer": "x", "track": 108}]):
        with pytest.raises(T.ModError):
            T.numbers(bad)
