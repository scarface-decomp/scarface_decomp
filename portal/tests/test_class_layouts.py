"""reports/j10_6_class_layouts_xb.json: the Xbox game's classes from its own run-time type information
(vtable, slot count, bases, constructors, size). The rows below are re-derived from default.xbe when the
game file is here, so a stale or wrong file fails."""
import json
import struct
import sys

import conftest

sys.path.insert(0, str(conftest.PORTAL / "tools"))

LAYOUTS = conftest.ROOT / "reports" / "j10_6_class_layouts_xb.json"
ROWS = {   # class: (vtable, slots, bases in hierarchy order, constructors, sizeof)
    "GameGroup": (0x39F394, 32, ["GameSet", "GameSetObject", "ScriptObject", "ConsoleObject"], [0x28F70, 0x28FA0], 0x40),
    "pure3d::d3dExtTODFactor": (0x3D6A3C, 19, ["pure3d::pddiExtTODFactor", "pure3d::pddiExtension"], [], 4),
    "pure3d::d3dContext": (0x3D6B9C, 132, ["pure3d::pddiBaseContext", "pure3d::pddiRenderContext", "pure3d::pddiObject"], [0x26B2F0], 0x550),
    "pure3d::Entity": (0x3D4C80, 7, ["content::LoadObject", "core::IRefCount"], [0x242DA0], None),
}


def classes():
    d = json.loads(LAYOUTS.read_text(encoding="utf-8"))
    assert d["schema"] == "j10_6_class_layouts/1" and d["binary"] == "default.xbe"
    return {c["class"]: c for c in d["classes"]}


def test_the_file_has_the_checked_rows():
    c = classes()
    assert len(c) == 2352
    for name, (vt, slots, bases, ctors, size) in ROWS.items():
        row = c[name]
        assert int(row["vtable"], 16) == vt and row["slots"] == slots, name
        assert [b["name"] for b in row["bases"]] == bases, name
        assert [int(x, 16) for x in row["ctors"]] == ctors, name
        assert row["sizeof"] == size, name


@conftest.needs_xbox
def test_the_rows_come_from_the_games_own_type_information():
    """TypeDescriptor -> complete-object locator -> vtable and its slots; the hierarchy descriptor's base list."""
    import queue_builder as QB
    from sf_binaries import BinaryImage
    img = BinaryImage(conftest.ROOT / "binaries" / "default.xbe")
    code = img.code_sections()

    def u32(va):
        return struct.unpack("<I", img.read(va, 4))[0]

    def in_code(va):
        return any(s.va <= va < s.va + s.raw_size for s in code)

    def td_name(td):
        raw = img.read(td + 8, 256).split(b"\0")[0].decode("ascii")
        return QB.demangle_rtti(raw)

    c = classes()
    for name, (vt, slots, bases, _ctors, _size) in ROWS.items():
        col = u32(vt - 4)
        sig, off, _cd, td, chd = struct.unpack("<5I", img.read(col, 20))
        assert sig == 0 and off == 0 and td_name(td) == name, name
        n = 0
        while in_code(u32(vt + 4 * n)) and n < 512:
            n += 1
        assert n == slots == c[name]["slots"], name
        _sig, _attr, nbases, bca = struct.unpack("<4I", img.read(chd, 16))
        got = [td_name(u32(u32(bca + 4 * i))) for i in range(1, nbases)]
        assert got == bases, name
