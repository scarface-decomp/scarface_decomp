"""
The names of the game's sound files and the text bibles (docs/FORMATS.md, "Sounds" and "Text bibles").
"""
import struct

import media
import p3d


def test_a_sound_is_filed_under_the_64_bit_key_of_its_path():
    # Both pairs are in docs/VERSIONS.md: the file's own header gives the path it was made from.
    assert media.sound_id("art/sound/music/tapeplayer/tp_toots_fever.rsd") == "c90ed53b0f931027"
    assert media.sound_id(r"c:\scarface\art\sound\localised\english\nis\ps2_finals\pal_mnis_s14_intro_diaz_motors_00.wav") \
        == "93caea0c3208a609"
    assert media.sound_id("Music/TapePlayer/TP_Toots_Fever") == "c90ed53b0f931027"      # case and slashes don't matter
    assert media.sound_file("music/tapeplayer/tp_toots_fever") == "art/sound/rsd/c/c90ed53b0f931027.rsd"
    assert media.subtitle_file("music/tapeplayer/tp_toots_fever") == "art/subtitles/c/c90ed53b0f931027.p3d"
    assert p3d.name_key64("") == 0 and p3d.name_key64("a") == 0x61 and p3d.name_key64("A") == 0x61


def bible(lines, in_units=False, name=b"\x07English"):
    text, starts = b"", []
    for _key, line in lines:
        starts.append(len(text) // (2 if in_units else 1))
        text += line.encode("utf-16-le") + b"\0\0"
    keys = [k for k, _ in lines]
    body = name + b"E" + struct.pack("<3I", len(lines), media.BIBLE_MARK, len(text)) \
        + struct.pack(f"<{len(keys)}I", *keys) + struct.pack(f"<{len(starts)}I", *starts) + text
    inner = struct.pack("<3I", media.TEXT_BIBLE, 12 + len(body), 12 + len(body)) + body
    outer_body = b"\x05bible"
    outer = struct.pack("<3I", 0x0001800D, 12 + len(outer_body), 12 + len(outer_body) + len(inner)) + outer_body + inner
    return b"P3D\xff" + struct.pack("<2I", 12, 12 + len(outer)) + outer


def test_a_text_bible_gives_its_lines_by_key():
    lines = sorted([(p3d.name_key("A64_GOTOHOTEL"), "Go to the hotel"), (p3d.name_key("PAUSE_RESUME"), "Résumé ¡ya!"),
                    (p3d.name_key("EMPTY"), "")])
    for in_units in (False, True):                           # line starts in bytes, or in UTF-16 units
        got = media.text_bible(bible(lines, in_units))
        assert got == lines
        assert dict(got)[p3d.name_key("a64_gotohotel")] == "Go to the hotel"     # ids are found whatever their case
    assert media.text_bible(bible(lines, name=b"\x0bLongerName\0")) == lines
    assert media.text_bible(b"P3D\xff" + struct.pack("<2I", 12, 12)) == [] and media.text_bible(b"junk") == []
    assert media.text_bible(bible(lines)[:-6]) == []         # cut short: nothing, not wrong lines
