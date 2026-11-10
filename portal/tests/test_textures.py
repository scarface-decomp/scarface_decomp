"""Every texture as a picture (portal/tools/textures.py): the PC's, a sharper copy of the same picture from
another version, a different picture under a PC name, and what only the other versions have; plus the
PNG reader and the likeness test it uses (portal/tools/media.py). Every file here is made up."""
import json
import struct
from pathlib import Path

import game_assets as GA
import media
import textures as T
from test_media import p3d_with


def picture(w, h, kind):
    """A made-up picture: 'ramp' brightens left to right, 'rings' is a bullseye, 'bars' has stripes."""
    out = bytearray()
    for y in range(h):
        for x in range(w):
            if kind == "ramp":
                v = int(255 * x / max(1, w - 1))
            elif kind == "rings":
                v = 255 if int(((x - w / 2) ** 2 + (y - h / 2) ** 2) ** 0.5 / (w / 6)) % 2 else 0
            else:
                v = 255 if (y * 4 // h) % 2 else 30
            out += bytes((v, v // 2, 255 - v, 255))
    return w, h, bytes(out)


def tex(name, w, h, kind):
    return (name, w, h, 32, 1, media.png(*picture(w, h, kind)))


def test_png_reader_and_likeness():
    for kind in ("ramp", "rings", "bars"):
        w, h, rgba = picture(12, 8, kind)
        assert media.decode_png(media.png(w, h, rgba)) == (w, h, rgba)
    assert media.likeness(picture(64, 64, "ramp"), picture(16, 16, "ramp")) > 0.95      # same art, two sizes
    assert media.likeness(picture(64, 64, "rings"), picture(32, 32, "bars")) < 0.5      # different art


def test_every_texture_pc_first(tmp_path):
    b = tmp_path / "binaries"
    out = b / "game_files"
    pc_file = p3d_with([tex("same.tga", 8, 8, "bars"), tex("sharp.tga", 8, 8, "ramp"), tex("diff.bmp", 8, 8, "ramp")])
    proto_file = p3d_with([tex("same.tga", 8, 8, "bars"), tex("sharp.tga", 32, 32, "ramp"),
                           tex("diff.bmp", 32, 32, "rings"), tex("only.tga", 4, 4, "bars")])
    xbox_file = p3d_with([tex("only.tga", 8, 8, "bars"), tex("xb.tga", 4, 4, "rings")])
    (out / "PC" / "art").mkdir(parents=True)
    (out / "PC" / "art" / "a.p3d").write_bytes(pc_file)
    (out / "Exclusive to Xbox" / "art").mkdir(parents=True)
    (out / "Exclusive to Xbox" / "art" / "x.p3d").write_bytes(xbox_file)
    proto_folder = b / "Scarface 2006 Prototype" / "art"                # not copied: read from its folder
    proto_folder.mkdir(parents=True)
    (proto_folder / "a.p3d").write_bytes(proto_file)
    facts = {"p3d": "textures", "tex": 64}
    index = {"versions": {
        "pc": {"files": [["cement.rcf/art/a.p3d", len(pc_file), "s1", "changed", "PC/art/a.p3d", facts, 1]]},
        "prototype": {"files": [["art/a.p3d", len(proto_file), "s2", "changed", "PC/art/a.p3d", facts, 0]]},
        "xbox": {"files": [["cement.rcf/art/x.p3d", len(xbox_file), "s3", "only", "Exclusive to Xbox/art/x.p3d", facts, 1]]}}}
    sources = {"prototype": GA.Source("prototype", b / "Scarface 2006 Prototype", "folder")}
    status: dict = {}
    T.Export(b, index, sources, status, lambda: False, log=lambda m: None).run()
    root = b / "textures"
    got = {p.relative_to(root).as_posix() for p in root.rglob("*.png")}
    assert got == {"PC/art/a/same.png", "PC/art/a/sharp.png", "PC/art/a/diff.png",
                   "Exclusive to Xbox 2006 prototype/art/a/diff.png",        # a different picture, same name
                   "Not on the PC/art/x/only.png",                           # the Xbox's and the prototype's
                   "Exclusive to Xbox/art/x/xb.png"}
    assert media.decode_png((root / "PC/art/a/sharp.png").read_bytes())[:2] == (32, 32)   # the prototype's
    assert media.decode_png((root / "PC/art/a/same.png").read_bytes())[:2] == (8, 8)
    assert media.decode_png((root / "Not on the PC/art/x/only.png").read_bytes())[:2] == (8, 8)  # the biggest
    index_txt = (root / "INDEX.txt").read_text(encoding="utf-8")
    assert "PC/art/a/sharp.png: 32x32 from the Xbox 2006 prototype" in index_txt
    assert "a different picture from the PC's diff.bmp (8x8)" in index_txt
    assert status["sharper"] == 1 and status["extra"] == 3
    # again: what the last export wrote is replaced, nothing else is touched
    (root / "mine.txt").write_text("keep me")
    T.Export(b, index, sources, {}, lambda: False, log=lambda m: None).run()
    assert {p.relative_to(root).as_posix() for p in root.rglob("*.png")} == got
    assert (root / "mine.txt").read_text() == "keep me"
    assert len(json.loads((root / T.MANIFEST).read_text())["files"]) == len(got) + 1    # sharp.png written twice


def test_the_job_needs_a_copy_first(tmp_path):
    job = T.TextureJob(tmp_path)
    assert "Copy the game files first" in job.start(None, {})
