"""
The check of everything the exports make (portal/scripts/check_exports.py): the report it writes.
"""
import importlib.util

from conftest import ROOT

spec = importlib.util.spec_from_file_location("check_exports", ROOT / "portal" / "scripts" / "check_exports.py")
CE = importlib.util.module_from_spec(spec)
spec.loader.exec_module(CE)


def test_the_report_counts_what_went_in_and_lists_what_did_not():
    scenes = [{"name": "NIS_A", "cast": [{"name": "Tony", "model": "tony.p3d", "body": "moves", "face": "moves"},
                                         {"name": "Clerk", "template": "CharTemp_Clerk", "model": "", "body": "", "face": ""}],
               "props": ["doors"], "left_out": ["Clerk", "glowShape"], "sound": True, "lines": 3},
              {"name": "NIS_B", "error": "that cutscene's animations aren't in your copied game files"}]
    areas = [{"name": "z04/a_01", "placed": 10, "unplaced": {"fencea": 2}, "at_origin": 1, "missing_drawables": ["x"],
              "missing_textures": ["l_drinksA.bmp"], "unread": 0},
             {"name": "z04/empty", "error": "nothing in these files to export"}]
    text = CE.report("pc", scenes, areas)
    assert "| people in them | 2 |" in text and "| faces that move | 1 |" in text and "| scenes' own props | 1 |" in text
    assert "* `NIS_B`: that cutscene's animations" in text and "* `NIS_A`: Clerk (`CharTemp_Clerk`)" in text
    assert "| props placed | 10 |" in text and "| props not placed (their model not found) | 2 |" in text
    assert "* `fencea`: 2" in text and "* `z04/empty`: nothing in these files to export" in text


def test_without_copied_files_it_says_so(tmp_path, monkeypatch, capsys):
    monkeypatch.setattr(CE.GA, "out_dir", lambda bin_dir=None: tmp_path)
    assert CE.main([]) == 2
    assert "Copy your game files first" in capsys.readouterr().out
