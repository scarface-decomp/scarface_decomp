"""portal/agent.py: the command-line loop a coding agent works with (next, packet, check, keep)."""
import importlib
import json
import sys
from pathlib import Path

import pytest

PORTAL = Path(__file__).resolve().parents[1]
ROOT = PORTAL.parent
sys.path.insert(0, str(PORTAL))
A = importlib.import_module("agent")


def test_next_lists_open_functions_smallest_first(monkeypatch, capsys, tmp_path):
    fns = [{"bin": "xb", "fva_int": 0x11000, "size": 40, "symbol": "Car::Honk"},
           {"bin": "xb", "fva_int": 0x11100, "size": 6, "symbol": "sub_00011100"},
           {"bin": "xb", "fva_int": 0x11200, "size": 3, "symbol": "sub_00011200"},       # matched already
           {"bin": "xb", "fva_int": 0x11300, "size": 9, "symbol": "sub_00011300"},       # waiting in to_submit
           {"bin": "pc", "fva_int": 0x401000, "size": 5, "symbol": "sub_00401000"}]
    monkeypatch.setattr(A, "functions", lambda: fns)
    monkeypatch.setattr(A, "registry", lambda: {"xb:0x00011200": {}})
    (tmp_path / "xb_00011300.cpp").write_text("// waiting", encoding="utf-8")
    monkeypatch.setattr(A, "TO_SUBMIT", tmp_path)
    assert A.main(["next", "--bin", "xb"]) == 0
    out = capsys.readouterr().out
    assert "2 open functions" in out and out.index("0x00011100") < out.index("0x00011000")
    assert "0x00011200" not in out and "0x00011300" not in out and "0x00401000" not in out
    assert A.main(["next", "--max-size", "5"]) == 0
    assert "sub_00401000" in capsys.readouterr().out


def test_functions_come_from_the_lists_when_there_is_no_queue(monkeypatch, tmp_path):
    monkeypatch.setattr(A, "QUEUE", tmp_path / "none.json")
    fns = A.functions()
    assert len(fns) > 30000 and {t["bin"] for t in fns} == {"xb", "pc", "proto"}
    assert all({"fva_int", "size", "symbol"} <= set(t) for t in fns[:50])


def test_a_work_file_says_which_function_it_is(tmp_path):
    assert A.header("// bin: xb\n// va: 0x00011000\n// what: Honks the horn once.\n// tool: some-model\n\nint x;") == {
        "bin": "xb", "va": "0x00011000", "what": "Honks the horn once.", "tool": "some-model"}
    bad = tmp_path / "f.cpp"
    bad.write_text("int x;", encoding="utf-8")
    with pytest.raises(SystemExit) as e:
        A.check(bad)
    assert "// bin:" in str(e.value)


def test_keep_wants_an_exact_match_a_description_and_who_wrote_it(monkeypatch, tmp_path, capsys):
    t = {"bin": "xb", "fva_int": 0x11000, "size": 6}
    good = {"ok": True, "is_exact": True, "matched_bytes": 6, "total_bytes": 6, "reloc_checked": 0, "reloc_unverified": 0,
            "compiled_sym": "?f@@YAXXZ", "compiled_size": 6, "flags": "/O2", "diff_details": []}
    f = tmp_path / "xb_00011000.cpp"
    monkeypatch.setattr(A, "TO_SUBMIT", tmp_path / "to_submit")
    monkeypatch.setattr(A, "ROOT", tmp_path)
    monkeypatch.setattr(A, "registry", lambda: {})
    state = {"ok": False}
    monkeypatch.setattr(A, "check", lambda path, *_: (state["ok"], dict(good, is_exact=state["ok"], matched_bytes=6 if state["ok"] else 4,
                                                                    diff_details=[] if state["ok"] else [
                                                                        {"idx": 1, "target": "C3", "compiled": "90", "status": "diff"}]),
                                                  t, f.read_text(encoding="utf-8")))
    f.write_text("// bin: xb\n// va: 0x00011000\n// what: \n// tool: \nvoid f() {}", encoding="utf-8")
    assert A.main(["keep", str(f)]) == 1 and "+0x1: original C3  yours 90" in capsys.readouterr().out      # not a match
    state["ok"] = True
    assert A.main(["keep", str(f)]) == 1 and "fill in" in capsys.readouterr().out                           # no description
    f.write_text("// bin: xb\n// va: 0x00011000\n// what: Returns straight away.\n// tool: some-model\nvoid f() {}", encoding="utf-8")
    assert A.main(["keep", str(f)]) == 0 and (tmp_path / "to_submit" / "xb_00011000.cpp").exists()
    monkeypatch.setattr(A, "registry", lambda: {"xb:0x00011000": {}})
    assert A.main(["keep", str(f)]) == 1 and "already matched" in capsys.readouterr().out


def test_check_picks_the_target_among_several_functions(monkeypatch):
    """An inline helper, <math.h> or 'delete' adds a second function to the object file. Without the
    portal's queue the target is still picked: by --match, the file's '// verify:' line, or its address name."""
    t = {"bin": "xb", "fva_int": 0x13AA0, "size": 55, "flags": "/O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4"}
    assert A.selection(t, "// bin: xb\n") == ("sub_00013AA0", None)
    assert A.selection(dict(t, match_substr="Honk@Car"), "") == ("Honk@Car", None)
    line = "// verify: python portal/verify.py x.cpp --va 0x13AA0 --bin xb --match '?$_Sort@' --flags \"/O2 /Ot /Oy /G6 /Gd /GR /Zp4\"\n"
    assert A.selection(t, line) == ("?$_Sort@", ["/O2 /Ot /Oy /G6 /Gd /GR /Zp4"])
    assert A.selection(t, line, match="??_I") == ("??_I", ["/O2 /Ot /Oy /G6 /Gd /GR /Zp4"])
    assert A.selection(t, "", flags=t["flags"] + " /arch:SSE")[1] == [t["flags"] + " /arch:SSE"]
    with pytest.raises(SystemExit):
        A.selection(t, "", flags="/O2 /FI evil.h")


def test_packet_hints_come_from_the_functions_own_instructions():
    # push ebp; mov ebp, esp; and esp, -8; ... ret
    assert any("8 bytes" in h for h in A.codegen_hints("xb", bytes.fromhex("558BEC83E4F8C3")))
    # fsqrt next to an SSE move: write sqrt() on doubles
    assert any("sqrt()" in h for h in A.codegen_hints("xb", bytes.fromhex("D9FAF30F1045 08C3".replace(" ", ""))))
    assert A.codegen_hints("xb", bytes.fromhex("C3")) == []


def test_who_gives_each_person_an_order_of_their_own_near_the_top():
    rows = list(range(100))
    a, b = A.spread(rows, "alice"), A.spread(rows, "bob")
    assert a != b and a == A.spread(rows, "Alice ") and A.spread(rows, "") == rows
    assert sorted(a[:A.WINDOW]) == list(range(A.WINDOW))            # still the top of the list first


def _entry(code, size=40, what="", symbol="sub_00011000"):
    return {"code": code, "size": size, "what": what, "symbol": symbol}


def test_describe_picks_matched_functions_without_one_explained_calls_first():
    entries = {
        "xb:0x00011000": _entry("int f() { return sub_00012000() + sub_00013000(); }"),   # one call unexplained
        "xb:0x00011100": _entry("int g() { return sub_00012000(); }"),                    # its call is explained
        "xb:0x00011200": _entry("int h() { return 1; }", what="Returns one."),             # described already
        "xb:0x00011300": _entry("int i() { return 2; }", size=4),                          # too small to be worth it
        "xb:0x00012000": _entry("int j() { return 3; }", what="Returns three."),
        "proto:0x00011000": _entry("int k() { return 4; }"),
    }
    names = {"xb:0x00012000": {"name": "Three"}}
    batch = A.describe_batch(entries, names, "xb", 10)
    assert [k for k, _, _ in batch] == ["xb:0x00011100", "xb:0x00011000"]
    assert batch[0][2] == [("xb:0x00012000", "Three", "Returns three.")]
    assert A.describe_batch(entries, names, "xb", 10, skip={"xb:0x00011100"})[0][0] == "xb:0x00011000"


def test_describe_keep_takes_only_good_new_descriptions(monkeypatch, tmp_path):
    entries = {"xb:0x00011000": _entry("x"), "xb:0x00011100": _entry("y", what="Already."), "xb:0x00011200": _entry("z")}
    data = {"schema": "scarface_descriptions_v1", "by": "Claude for bob", "descriptions": {
        "xb:0x00011000": {"what": "Turns the car's headlights on or off."},
        "xb:0x00011100": {"what": "Something new."},
        "xb:0x00011200": {"what": "Calls sub_00012340(DAT_00450000, 0x20, 8)."},
        "xb:0x0FFFFFF0": {"what": "Nothing there."}}}
    good, bad = A.check_descriptions(data, entries)
    assert good == {"xb:0x00011000": {"what": "Turns the car's headlights on or off.", "how": "read"}}
    assert {k for k, _ in bad} == {"xb:0x00011100", "xb:0x00011200", "xb:0x0FFFFFF0"}
    assert A.check_descriptions(dict(data, by=""), entries)[1][0][0] == "file"
    # kept where submit_descriptions.py looks, merged with what is waiting there already
    monkeypatch.setattr(A, "registry", lambda: entries)
    monkeypatch.setattr(A, "TO_SUBMIT", tmp_path / "to_submit")
    monkeypatch.setattr(A, "ROOT", tmp_path)
    f = tmp_path / "descriptions_bob.json"
    f.write_text(json.dumps(data), encoding="utf-8")
    assert A.main(["describe-keep", str(f)]) == 1                      # some were turned down
    kept = json.loads((tmp_path / "to_submit" / "descriptions_bob.json").read_text(encoding="utf-8"))
    assert kept["by"] == "Claude for bob" and list(kept["descriptions"]) == ["xb:0x00011000"]


def test_packet_gives_a_lead_to_a_class_from_published_research(monkeypatch, tmp_path):
    (tmp_path / "reports").mkdir()
    (tmp_path / "reports" / "class_hints_xb.json").write_text(json.dumps({"hints": [
        ["0x000C6F10", "SaveGameManagerFlowClient", "callers", "0x00484D60"],
        ["0x00011000", "Weapon", "vtable", "0x00412000"]]}))
    monkeypatch.setattr(A, "ROOT", tmp_path)
    monkeypatch.setattr(A, "_CLASS_HINTS", None)
    lead = A.class_hint("xb", 0x000C6F10)
    assert "SaveGameManagerFlowClient" in lead and "0x00484D60" in lead and "may be a helper" in lead
    assert "virtual table" in A.class_hint("xb", 0x00011000)
    assert A.class_hint("xb", 0x00012345) == "" and A.class_hint("pc", 0x000C6F10) == ""


def test_the_class_leads_file_is_what_it_says():
    root = Path(__file__).resolve().parents[2]
    hints = json.loads((root / "reports" / "class_hints_xb.json").read_text(encoding="utf-8"))
    pairs = json.loads((root / "reports" / "pairing_xb_pc_study.json").read_text(encoding="utf-8"))
    assert hints["count"] == len(hints["hints"]) == sum(hints["by"].values())
    assert pairs["paired"] == len(pairs["pairs"]) == sum(pairs["by"].values())
    twin = {x: y for x, y, _size, _how in pairs["pairs"]}
    assert all(twin.get(x) == pc and by in ("vtable", "ctor/vtref", "callers") and cls for x, cls, by, pc in hints["hints"])
    assert all(0x401000 <= int(y, 16) < 0x72EADC for y in twin.values())     # the PC game's own code, nothing after it


def test_packet_gives_a_lead_from_a_published_fix(monkeypatch, tmp_path):
    (tmp_path / "reports").mkdir()
    (tmp_path / "reports" / "fusionfix_leads_xb.json").write_text(json.dumps({"functions": [
        {"xb": "0x00023EC0", "hooks": [{"kind": "call", "name": "findObject", "file": "HUD.ixx", "line": 336}]},
        {"xb": "0x00177180", "hooks": [{"kind": "start", "name": "UpdateRageBar", "file": "FramerateVigilante.ixx", "line": 88},
                                       {"kind": "patch", "name": "", "file": "Input.ixx", "line": 309, "note": "walk key"}]}]}))
    monkeypatch.setattr(A, "ROOT", tmp_path)
    monkeypatch.setattr(A, "_FIX_LEADS", None)
    lead = A.fix_lead("xb", 0x00023EC0)
    assert "calls this function as `findObject` (HUD.ixx line 336)" in lead and lead.endswith("Check it against the code.")
    both = A.fix_lead("xb", 0x00177180)
    assert "hooks this function's start with its own `UpdateRageBar`" in both
    assert "changes something inside this function (Input.ixx line 309: walk key)" in both
    assert A.fix_lead("xb", 0x00012345) == "" and A.fix_lead("pc", 0x00023EC0) == ""
    monkeypatch.setattr(A, "_FIX_LEADS", None)
    monkeypatch.setattr(A, "ROOT", tmp_path / "nothing here")
    assert A.fix_lead("xb", 0x00023EC0) == ""


def test_packet_gives_a_lead_from_a_sibling_game(monkeypatch, tmp_path):
    (tmp_path / "reports").mkdir()
    (tmp_path / "reports" / "sibling_twins.json").write_text(json.dumps({"functions": {
        "xb": [{"va": "0x002C70E0", "size": 5204, "in": {"crash": "0x00212340", "hulk": None}}],
        "proto": [{"va": "0x00011D70", "size": 36, "in": {"crash": "0x000D9C70"}}]}}))
    monkeypatch.setattr(A, "ROOT", tmp_path)
    monkeypatch.setattr(A, "_SIBLING_LEADS", None)
    lead = A.sibling_lead("xb", 0x002C70E0)
    assert "Crash Tag Team Racing (at 0x00212340); The Incredible Hulk: Ultimate Destruction." in lead
    assert A.sibling_lead("proto", 0x00011D70).count("at 0x000D9C70") == 1
    assert A.sibling_lead("xb", 0x00011D70) == "" and A.sibling_lead("pc", 0x002C70E0) == ""
    monkeypatch.setattr(A, "_SIBLING_LEADS", None)
    monkeypatch.setattr(A, "ROOT", tmp_path / "nothing here")
    assert A.sibling_lead("xb", 0x002C70E0) == ""


def test_packet_gives_a_lead_from_the_streaming_bug_report(monkeypatch, tmp_path):
    (tmp_path / "reports").mkdir()
    (tmp_path / "reports" / "recomp_leads_xb.json").write_text(json.dumps({"functions": [
        {"xb": "0x00093590", "size": 58, "pc": "0x004B7F70", "role": "Picks a free streaming slot.",
         "how_sure": "sure", "evidence": "sizes 58/58"}]}))
    monkeypatch.setattr(A, "ROOT", tmp_path)
    monkeypatch.setattr(A, "_RECOMP_LEADS", None)
    lead = A.recomp_lead("xb", 0x93590)
    assert "0x004B7F70, sure" in lead and "Picks a free streaming slot." in lead and "GAME_BUGS.md" in lead
    assert A.recomp_lead("xb", 0x93591) == "" and A.recomp_lead("pc", 0x93590) == ""
    monkeypatch.setattr(A, "_RECOMP_LEADS", None)
    monkeypatch.setattr(A, "ROOT", tmp_path / "nothing here")
    assert A.recomp_lead("xb", 0x93590) == ""
