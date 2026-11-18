"""
Virtual functions' names from another Radical game's linker map (portal/scripts/names_from_shar_map.py).
The map and program here are made up; the real ones are never in the repository.
"""
import importlib.util
import struct

from conftest import ROOT

spec = importlib.util.spec_from_file_location("names_from_shar_map", ROOT / "portal" / "scripts" / "names_from_shar_map.py")
SM = importlib.util.module_from_spec(spec)
spec.loader.exec_module(SM)

MAP = """Address  Size     Align Out     In      File    Symbol
=================================================================
00100000 00001000    40 .text
00100100 00000f00     8                 D:\\\\build\\\\ps2\\\\Release\\\\libp3d.a(camera.o)
00100100 00000020     0                         AddRef__7tEntity
00100120 00000020     0                         Release__7tEntity
00100140 00000030     0                         _._7tEntity
00100200 00000010     0                         SetFOV__7tCameraf
00100210 00000010     0                         GetFOV__7tCamera
00100220 00000010     0                         Look__7tCamerafff
00100230 00000010     0                         Look__7tCameraRCQ218RadicalMathLibrary6Vector
00100240 00000010     0                         Update__7tCamera
00100250 00000010     0                         Show__Q27Scrooby4Page
00200000 00000100     8 .data
00200000 00000028     0                         _vt$7tEntity
00200030 00000050     0                         _vt$7tCamera
00200080 00000018     0                         _vt$Q27Scrooby4Page
00200098 00000018     0                         _vt$t4List1Z7tCamera
"""


def table(*fns):
    return b"".join(struct.pack("<hhI", 0, 0, f) for f in (0x999,) + fns + (0,))


def read_from(blobs):
    def read(va, n):
        for base, data in blobs.items():
            if base <= va and va + n <= base + len(data):
                return data[va - base:va - base + n]
        return b""
    return read


ENTITY = (0x100100, 0x100120, 0x100140)
CAMERA = ENTITY + (0x100200, 0x100210, 0x100220, 0x100230, 0x100240)


def test_the_map_gives_each_slot_its_name():
    symbols, tables = SM.parse_map(MAP)
    assert symbols[0x100200] == "SetFOV__7tCameraf" and 0x100000 not in symbols          # sections and files are not symbols
    assert tables["7tCamera"] == (0x200030, 0x50)
    assert SM.class_name("7tCamera") == "tCamera" and SM.class_name("Q27Scrooby4Page") == "Scrooby::Page"
    assert SM.class_name("t4List1Z7tCamera") is None and SM.class_name("7tCam") is None
    assert SM.method_name("SetFOV__7tCameraf") == "SetFOV" and SM.method_name("Show__Q27Scrooby4Page") == "Show"
    assert SM.method_name("_._7tEntity") is None and SM.method_name("__pure_virtual") is None
    assert SM.method_name("__eq__7tCameraRC7tCamera") is None
    read = read_from({0x200000: table(*ENTITY), 0x200030: table(*CAMERA), 0x200080: table(0x100250)})
    theirs = SM.their_tables(symbols, tables, read)
    assert theirs == {"tEntity": ["AddRef", "Release", None],
                      "tCamera": ["AddRef", "Release", None, "SetFOV", "GetFOV", "Look", "Look", "Update"],
                      "Scrooby::Page": ["Show"]}
    assert SM.our_class("tCamera") == "pure3d::Camera" and SM.our_class("pddiShader") == "pure3d::pddiShader"
    assert SM.our_class("Scrooby::Page") == "pure3d::frontend::Page"
    assert SM.our_class("Scenegraph::Node") is None and SM.our_class("ActionButton") is None and SM.our_class("table") is None


def ours_and_known(cls, n, first=0x300000):
    table_ = [first + 0x10 * i for i in range(n)]
    return table_, {va: {"symbol": f"{cls}::vfunc_{i:02d}"} for i, va in enumerate(table_)}


THEIRS = {"tEntity": ["AddRef", "Release", None],
          "tCamera": ["AddRef", "Release", None, "SetFOV", "GetFOV", "Look", "Look", "Update"]}


def test_tables_of_the_same_size_line_up_from_the_start():
    cam, known = ours_and_known("pure3d::Camera", 8)
    found, stats = SM.find(THEIRS, {"pure3d::Camera": cam}, known, {})
    assert {va - 0x300000: n for va, (n, _w) in found.items()} == {
        0x00: "pure3d::Camera::AddRef", 0x10: "pure3d::Camera::Release", 0x30: "pure3d::Camera::SetFOV",
        0x40: "pure3d::Camera::GetFOV", 0x70: "pure3d::Camera::Update"}             # no destructor, no overloaded Look
    assert "both tables of virtual functions have 8 slots" in found[0x300030][1] and "Slot 3 of tCamera is SetFOV" in found[0x300030][1]
    assert stats["classes used"] == 1
    # a recorded name that says otherwise drops the whole class; one that agrees is fine
    assert SM.find(THEIRS, {"pure3d::Camera": cam}, known, {0x300040: "pure3d::Camera::Zoom"})[0] == {}
    assert len(SM.find(THEIRS, {"pure3d::Camera": cam}, known, {0x300040: "pure3d::Camera::GetFOV"})[0]) == 5
    # a table of another size, with no shared base to line up after, is left alone
    cam9, known9 = ours_and_known("pure3d::Camera", 9)
    assert SM.find(THEIRS, {"pure3d::Camera": cam9}, known9, {})[0] == {}


def test_a_class_lines_up_after_a_base_that_grew():
    ent, known = ours_and_known("pure3d::Entity", 7, 0x400000)                          # 3 slots in 2003, 7 here
    cam = ent[:7] + [0x300000 + 0x10 * i for i in range(5)]                             # its own 5 follow
    known.update({va: {"symbol": f"pure3d::Camera::vfunc_{7 + i:02d}"} for i, va in enumerate(cam[7:])})
    found, stats = SM.find(THEIRS, {"pure3d::Camera": cam, "pure3d::Entity": ent}, known, {},
                           {"pure3d::Camera": ["pure3d::Entity"], "pure3d::Entity": []})
    assert {va: n for va, (n, _w) in found.items()} == {
        0x300000: "pure3d::Camera::SetFOV", 0x300010: "pure3d::Camera::GetFOV", 0x300040: "pure3d::Camera::Update"}
    why = found[0x300000][1]
    assert "tEntity there with 3 slots, pure3d::Entity here with 7" in why and "each has 5 slots of its own" in why
    assert "Slot 3 of tCamera is SetFOV" in why and "slot 7 here" in why
    # a function filed under an unrelated class (the linker folded two the same) is not named
    known[0x300010] = {"symbol": "Other::vfunc_08"}
    assert 0x300010 not in SM.find(THEIRS, {"pure3d::Camera": cam, "pure3d::Entity": ent}, known, {},
                                   {"pure3d::Camera": ["pure3d::Entity"], "pure3d::Entity": []})[0]
