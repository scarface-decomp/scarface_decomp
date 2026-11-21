"""portal/agent.py: the command-line loop a coding agent works with (next, packet, check, keep)."""
import importlib
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
