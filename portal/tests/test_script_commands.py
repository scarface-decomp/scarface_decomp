"""
Script commands and the functions behind them (portal/tools/script_commands.py), on a made-up Xbox program:
no game bytes.
"""
import json
import struct

from conftest import make_xbe

import script_commands as SC
from sf_binaries import BinaryImage

TEXT, DATA = 0x11000, 0x400000


def stub(most, fewest, handler, name_va, cls_va=0, record=0x480000, ctor_at=0x11F00, at=0):
    """The start-up code that registers one command, as the compiler writes it."""
    def push(v):
        return bytes([0x6A, v]) if v < 0x80 else b"\x68" + struct.pack("<I", v)
    code = push(most) + push(fewest) + push(0) + b"\x68" + struct.pack("<I", handler) + b"\x68" + struct.pack("<I", name_va)
    code += push(cls_va) if not cls_va else b"\x68" + struct.pack("<I", cls_va)
    code += b"\xB9" + struct.pack("<I", record)
    here = TEXT + at + len(code)
    return code + b"\xE8" + struct.pack("<i", ctor_at - (here + 5)) + b"\xC3"


def program(tmp_path, entries, strings):
    """entries: (most, fewest, handler, name, class or "")."""
    data = bytearray()
    where = {}
    for s in strings:
        where[s] = DATA + len(data)
        data += s.encode() + b"\0"
    code = bytearray()
    for most, fewest, handler, name, cls in entries:
        while len(code) % 16:
            code += b"\xCC"
        code += stub(most, fewest, handler, where[name], where[cls] if cls else 0, at=len(code))
    code += b"\xCC" * (0x1000 - len(code))
    return make_xbe(tmp_path / "default.xbe", [(".text", TEXT, bytes(code), 0x6), (".data", DATA, bytes(data), 0x1),
                                               ("D3D", 0x500000, b"\xC3" * 64, 0x6)])


def test_commands_are_read_from_the_start_up_code(tmp_path):
    path = program(tmp_path, [(2, 2, 0x11800, "DBChangeDirtyCash", ""),
                              (3, 2, 0x11810, "AddHealth", "CharacterObject"),
                              (1, 1, 0x11820, "GetGameTime", ""),
                              (1, 1, 0x500010, "InALibrary", ""),            # not the game's own code: left out
                              (1, 2, 0x11830, "FewestAboveMost", "")],
                   ["DBChangeDirtyCash", "AddHealth", "CharacterObject", "GetGameTime", "InALibrary", "FewestAboveMost"])
    found = SC.find(BinaryImage(path))
    assert [(c.script_name, c.handler, c.fewest, c.most) for c in found] == [
        ("DBChangeDirtyCash", 0x11800, 2, 2), ("CharacterObject::AddHealth", 0x11810, 2, 3), ("GetGameTime", 0x11820, 1, 1)]
    assert found[1].function_name == "Script::CharacterObject_AddHealth" and found[0].at == TEXT


def test_names_go_to_unnamed_functions_only(tmp_path):
    cmds = [SC.Command("", "DBChangeDirtyCash", 0x11800, 2, 2, 0x11000),
            SC.Command("CharacterObject", "AddHealth", 0x11810, 2, 3, 0x11020),
            SC.Command("", "OverlayNextItem", 0x11820, 1, 1, 0x11040),
            SC.Command("", "OverlayPrevItem", 0x11820, 1, 1, 0x11060),        # the same do-nothing function
            SC.Command("", "Named", 0x11830, 1, 1, 0x11080),
            SC.Command("", "Missing", 0x11840, 1, 1, 0x110A0)]
    functions = {0x11800: {"symbol": "sub_00011800"}, 0x11810: {"symbol": "sub_00011810"},
                 0x11820: {"symbol": "sub_00011820"}, 0x11830: {"symbol": "Collidable::vfunc_04"}}
    names, counts = SC.names_for(cmds, functions, "xb")
    assert counts == {"named": 3, "has a name already": 1, "not in the work queue": 1, "shared by several commands": 1}
    assert names["xb:0x00011800"] == {
        "name": "Script::DBChangeDirtyCash", "by": SC.BY,
        "why": "The start-up code at 0x00011000 registers this function as the script command DBChangeDirtyCash (1 argument)."}
    assert names["xb:0x00011810"]["name"] == "Script::CharacterObject_AddHealth"
    assert "CharacterObject::AddHealth (0 to 1 arguments)" in names["xb:0x00011810"]["why"]
    assert names["xb:0x00011820"]["why"].endswith("Also registered as OverlayPrevItem.")
    assert SC.NAMES.problems({"schema": SC.NAMES.SCHEMA, "names": names}) == []      # the form check_repo wants


def test_a_persons_name_is_never_replaced(tmp_path):
    mine = {"name": "Cash::Add", "by": "Alice", "why": "It adds to the dirty cash total."}
    data = {"schema": SC.NAMES.SCHEMA, "names": {"xb:0x00011800": dict(mine),
                                                 "xb:0x00011900": {"name": "Script::Taken", "by": "Bob", "why": "A guess from its strings."}}}
    new = {"xb:0x00011800": {"name": "Script::DBChangeDirtyCash", "by": SC.BY, "why": "w" * 12},
           "xb:0x00011810": {"name": "Script::GetGameTime", "by": SC.BY, "why": "w" * 12},
           "xb:0x00011820": {"name": "Script::Taken", "by": SC.BY, "why": "w" * 12}}
    assert SC.merge(data, new) == 1
    assert data["names"]["xb:0x00011800"] == mine and "xb:0x00011820" not in data["names"]
    assert list(data["names"]) == sorted(data["names"])
    assert SC.merge(data, new) == 0                                                 # nothing new the second time
    new["xb:0x00011810"] = dict(new["xb:0x00011810"], why="A better sentence.")
    assert SC.merge(data, new) == 1                                                 # its own names it keeps current


def test_command_line_writes_the_names(tmp_path, monkeypatch, capsys):
    program(tmp_path, [(2, 2, 0x11800, "DBChangeDirtyCash", "")], ["DBChangeDirtyCash"])
    root = tmp_path / "project"
    (root / "reports").mkdir(parents=True)
    (root / "reconstructed_src").mkdir()
    (root / "reconstructed_src" / SC.RO.BIN_INFO["xb"][0]).write_text(
        "// x, every function in address order\n// [TODO] 0x00011800 sub_00011800 (12 B)\n", encoding="utf-8")
    monkeypatch.setattr(SC, "ROOT", root)
    assert SC.main(["--bin-dir", str(tmp_path)]) == 0
    assert "1 names would be added" in capsys.readouterr().out and not (root / "reports" / "names.json").exists()
    assert SC.main(["--bin-dir", str(tmp_path), "--write"]) == 0
    saved = json.loads((root / "reports" / "names.json").read_text(encoding="utf-8"))
    assert saved["schema"] == SC.NAMES.SCHEMA and saved["names"]["xb:0x00011800"]["name"] == "Script::DBChangeDirtyCash"
    assert SC.main(["--bin-dir", str(tmp_path), "--list", "xb"]) == 0
    assert capsys.readouterr().out.strip().endswith("0x00011800  DBChangeDirtyCash")
    assert SC.main(["--bin-dir", str(tmp_path / "nowhere")]) == 1
