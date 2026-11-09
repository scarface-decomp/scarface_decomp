"""Downloads (portal/tools/downloads.py): order, layout, and the verified-only choice."""
import io
import zipfile

import conftest  # noqa: F401  (puts tools/ on the path)
import downloads as DL
import registry_outputs as RO


def reg_and_queue():
    def task(b, va, sym, size=4):
        return {"bin": b, "fva_int": va, "va": f"0x{va:08X}", "symbol": sym, "size": size}
    queue = [task("xb", 0x3000, "core::C::c"), task("xb", 0x1000, "core::A::a"), task("xb", 0x2000, "core::B::b"),
             task("pc", 0x5000, "sub_00005000")]
    reg = {"compiler": "cl 13.10", "entries": {
        "xb:0x00002000": {"bin": "xb", "va": "0x00002000", "size": 4, "symbol": "core::B::b", "code": "int B::b() { return 2; }",
                          "verified_by": "Ana", "flags": "/O2"}}}
    return reg, queue


def test_functions_are_in_address_order_with_gaps_marked():
    reg, queue = reg_and_queue()
    files = DL.function_files(reg, queue, ["xb"], False, RO.write_outputs, RO.BIN_INFO)
    text = files["xbox/Original_Binary_Order_Xbox.cpp"]
    a, b, c = text.index("[TODO] 0x00001000"), text.index("[VERIFIED] core::B::b"), text.index("[TODO] 0x00003000")
    assert a < b < c and "1 of 3 functions matched" in text and "NOT COMPLETE" in text
    assert "xbox/by_class/core/B.cpp" in files and not any(k.startswith("pc/") for k in files)


def test_verified_only_keeps_order_and_drops_gaps():
    reg, queue = reg_and_queue()
    files = DL.function_files(reg, queue, ["xb", "pc"], True, RO.write_outputs, RO.BIN_INFO, by_class=False)
    assert list(files) == ["xbox/Original_Binary_Order_Xbox.cpp"]          # nothing verified on PC
    assert "[TODO]" not in files["xbox/Original_Binary_Order_Xbox.cpp"] and "int B::b()" in files["xbox/Original_Binary_Order_Xbox.cpp"]


def test_zip_and_txt_layout():
    files = {"xbox/a.cpp": "A\n", "xbox/b/c.cpp": "C\n"}
    z = zipfile.ZipFile(io.BytesIO(DL.to_zip(files, "pack")))
    assert z.namelist() == ["pack/xbox/a.cpp", "pack/xbox/b/c.cpp"] and z.read("pack/xbox/b/c.cpp") == b"C\n"
    txt = DL.to_txt(files, "TITLE", ["intro"])
    assert txt.index("CONTENTS (2 files") < txt.index("FILE 1 of 2: xbox/a.cpp") < txt.index("FILE 2 of 2: xbox/b/c.cpp")


def test_scripts_keep_the_game_folders_and_only_1to1_when_asked():
    assert DL.script_out_name("xbox/scriptc/missions/m.cso") == "xbox/scriptc/missions/m.cs"
    assert DL.script_out_name("xbox/main.cs.dso") == "xbox/main.cs"
    assert DL.script_out_name("xbox/ai/common.dtr") == "xbox/ai/common.dtr.txt"
    items = [{"path": "xbox/a.cso", "version": "xbox", "ext": "CSO"}, {"path": "xbox/b.cso", "version": "xbox", "ext": "CSO"},
             {"path": "prototype/a.cso", "version": "prototype", "ext": "CSO"}, {"path": "xbox/t.cs", "version": "xbox", "ext": "CS"}]
    detail = lambda rel: {"ok": True, "format": "TorqueScript", "decompiled_code": f"// code of {rel}"}  # noqa: E731
    exact = {"xbox/a.cso": True, "xbox/b.cso": False, "prototype/a.cso": True}
    files, stats = DL.script_files(items, detail, exact, False, ["xbox"])
    assert list(files) == ["xbox/a.cs", "xbox/b.cs", "xbox/t.cs"] and stats["not_exact"] == 1
    assert "1:1 (decompiled" in files["xbox/a.cs"] and "NOT 1:1" in files["xbox/b.cs"] and "original TorqueScript source" in files["xbox/t.cs"]
    files, stats = DL.script_files(items, detail, exact, True)
    assert list(files) == ["xbox/a.cs", "prototype/a.cs", "xbox/t.cs"] and stats["left_out"] == 1


def test_source_files_put_the_address_order_files_first(tmp_path):
    (tmp_path / "include").mkdir()
    (tmp_path / "include" / "x.h").write_text("// header")
    (tmp_path / "Original_Binary_Order_Xbox.cpp").write_text("// GENERATED from reports/verified_registry.json\n// [TODO] x")
    files = DL.source_files(tmp_path, False, lambda: {})
    assert list(files) == ["Original_Binary_Order_Xbox.cpp", "include/x.h"]
    files = DL.source_files(tmp_path, True, lambda: {"Original_Binary_Order_Xbox.cpp": "// verified"})
    assert files["Original_Binary_Order_Xbox.cpp"] == "// verified" and "include/x.h" in files
