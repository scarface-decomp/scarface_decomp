"""The chunk-loader registry (portal/tools/loader_registry.py, the examiner's question E6): read from a made-up
XBE with MSVC RTTI. Nothing here comes from the game."""
import struct

from conftest import make_xbe

import loader_registry as L
from sf_binaries import BinaryImage

TEXT, RDATA = 0x11000, 0x30000


def program(tmp_path):
    """StreamTriggerLoader: a constructor that writes its vtable and passes chunk id 0x08800101; a virtual
    function that compares the word PSYS and builds a Thing (writes Thing's vtable). Thing: one virtual."""
    rdata = bytearray(0x200)

    def descriptor(at, raw):
        struct.pack_into("<II", rdata, at, 0, 0)
        rdata[at + 8:at + 8 + len(raw) + 1] = raw + b"\0"
        return RDATA + at

    td_loader = descriptor(0x00, b".?AVStreamTriggerLoader@@")
    td_thing = descriptor(0x40, b".?AVThing@@")
    struct.pack_into("<5I", rdata, 0x80, 0, 0, 0, td_loader, 0)          # complete-object locators
    struct.pack_into("<5I", rdata, 0xA0, 0, 0, 0, td_thing, 0)
    vt_loader, vt_thing = RDATA + 0xC4, RDATA + 0xD4
    struct.pack_into("<3I", rdata, 0xC0, RDATA + 0x80, TEXT + 0x20, 0)
    struct.pack_into("<3I", rdata, 0xD0, RDATA + 0xA0, TEXT + 0x40, 0)
    text = bytearray(b"\xCC" * 0x80)
    ctor = bytes([0xC7, 0x01]) + struct.pack("<I", vt_loader) + b"\x68" + struct.pack("<I", 0x08800101) + b"\x58\xC3"
    text[0:len(ctor)] = ctor
    vfunc = b"\x81\x7C\x24\x04" + b"PSYS" + bytes([0xC7, 0x01]) + struct.pack("<I", vt_thing) + b"\xC3"
    text[0x20:0x20 + len(vfunc)] = vfunc
    text[0x40] = 0xC3
    call = b"\xE8" + struct.pack("<i", TEXT - (TEXT + 0x60 + 5)) + b"\xC3"           # someone calls the ctor
    text[0x60:0x60 + len(call)] = call
    return BinaryImage(make_xbe(tmp_path / "t.xbe", [(".text", TEXT, bytes(text), 0x6), (".rdata", RDATA, bytes(rdata), 0x2)]))


def test_classes_vtables_and_what_each_loader_reads_and_builds(tmp_path):
    img = program(tmp_path)
    vts = L.rtti_vtables(img)
    assert {c for c, _raw in vts.values()} == {"StreamTriggerLoader", "Thing"}
    (ld,) = L.Program(img).loaders()
    assert (ld.cls, ld.chunk_ids, ld.constructors) == ("StreamTriggerLoader", [0x08800101], [TEXT])
    (slot,) = [s for s in ld.slots if s.words or s.builds]
    assert (slot.slot, slot.words, slot.builds) == (0, ["PSYS"], ["Thing"])
    rows = L.by_chunk([ld])
    assert rows == {"0x08800101": {"name": "Stream Trigger", "loaders": ["StreamTriggerLoader"], "builds": ["Thing"]}}


def test_words_and_chunk_ids(tmp_path):
    img = program(tmp_path)
    assert L.word(0x53595350) == "PSYS" and L.word(0x00475142) == "BQG" and L.word(0x00000041) is None
    assert L.word(0x12345678) is None
    assert L.chunk_id_like(img, 0x0802000D, set())
    assert not L.chunk_id_like(img, RDATA + 4, set())           # an address in the program
    assert not L.chunk_id_like(img, 0x50, set())


def test_the_report_and_its_table(tmp_path, capsys):
    import shutil
    program(tmp_path)
    shutil.copy(tmp_path / "t.xbe", tmp_path / "default.xbe")
    out = tmp_path / "loaders.json"
    assert L.main(["--bin-dir", str(tmp_path), "--out", str(out)]) == 0
    import json
    got = json.loads(out.read_text())["versions"]["xb"]
    assert got["code_readable"] and got["by_chunk"]["0x08800101"]["loaders"] == ["StreamTriggerLoader"]
    assert L.main(["--bin-dir", str(tmp_path), "--list", "xb"]) == 0
    assert "0x08800101  Stream Trigger" in capsys.readouterr().out
