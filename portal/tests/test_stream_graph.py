"""The stream graph (portal/tools/stream_graph.py): the triggers of streamgraph.p3d and what is loaded at a place.
Every file here is made up; nothing comes from the game."""
import struct

import pytest

import stream_graph as S
from test_p3d import chunk, p3d, short_text, stream_trigger, text


def square(x0, z0, x1, z1):
    return [(x0, z0), (x1, z0), (x1, z1), (x0, z1)]


def city():
    """Two areas whose triggers overlap between x 5 and 10, a third far off, and an L-shaped one."""
    a = stream_trigger("loadTrigger", "a_01_shell", square(0, 0, 10, 10),
                       [("miami_lod", "Global_S"), ("miami_lod_d", "Global_D"), ("a_01_shell", "Shell"),
                        ("a_01_detail", "Detail")])
    b = stream_trigger("loadTrigger_1", "b_02_shell", square(5, 0, 15, 10),
                       [("miami_lod", "Global_S"), ("b_02_shell", "Shell"), ("b_02_detail", "Detail"),
                        ("b_02_detailB", "Detail")], tx=short_text)
    c = stream_trigger("loadTrigger_2", "c_03_shell", square(100, 0, 110, 10), [("c_03_shell", "Shell")])
    ell = stream_trigger("loadTrigger_3", "l_04_shell", [(0, 50), (20, 50), (20, 60), (10, 60), (10, 70), (0, 70)],
                         [("l_04_shell", "Shell")])
    pkgs = b"".join(chunk(0x8800100, text(n) + struct.pack("<I", i + 5))
                    for i, n in enumerate(("a_01_shell", "b_02_shell", "c_03_shell")))
    return p3d(pkgs, a, b, c, ell)


def test_the_triggers_and_packages():
    found = S.triggers(city())
    assert [t.name for t in found] == ["loadTrigger", "loadTrigger_1", "loadTrigger_2", "loadTrigger_3"]
    a = found[0]
    assert (a.subzone, a.height, len(a.points)) == ("a_01_shell", 13.0, 4)
    assert a.points[1] == (10.0, 12.4, 0.0)                           # x, y (the base), z
    assert a.packages[2] == ("a_01_shell", "Shell")
    assert (a.regions, a.flag) == (["a_region", "b_region"], 0)
    assert S.packages(city()) == {"a_01_shell": 5, "b_02_shell": 6, "c_03_shell": 7}


def test_what_is_loaded_inside_one_trigger_and_where_two_overlap():
    found = S.triggers(city())
    one = S.loaded_at(found, 2, 5)
    assert one.inside and [t.name for t in one.triggers] == ["loadTrigger"]
    assert ("b_02_shell", "Shell") not in one.packages
    both = S.loaded_at(found, 7, 5)
    assert both.inside and [t.name for t in both.triggers] == ["loadTrigger", "loadTrigger_1"]
    assert both.packages == [("miami_lod", "Global_S"), ("miami_lod_d", "Global_D"), ("a_01_shell", "Shell"),
                             ("a_01_detail", "Detail"), ("b_02_shell", "Shell"), ("b_02_detail", "Detail"),
                             ("b_02_detailB", "Detail")]                # the union, miami_lod once
    assert both.by_slot()["Detail"] == ["a_01_detail", "b_02_detail", "b_02_detailB"]
    edge = S.loaded_at(found, 10, 5)                                   # on a's edge, inside b
    assert [t.name for t in edge.triggers] == ["loadTrigger", "loadTrigger_1"]


def test_outside_every_trigger_the_nearest_stands_in():
    found = S.triggers(city())
    near_b = S.loaded_at(found, 50, 5)                                 # 35 from b, 50 from c
    assert not near_b.inside and [t.name for t in near_b.triggers] == ["loadTrigger_1"]
    assert ("b_02_shell", "Shell") in near_b.packages
    near_c = S.loaded_at(found, 90, 12)
    assert [t.name for t in near_c.triggers] == ["loadTrigger_2"]
    assert S.loaded_at([], 0, 0).packages == []


def test_a_concave_outline():
    ell = S.triggers(city())[3]
    assert S.contains(ell, 5, 65) and S.contains(ell, 15, 55)
    assert not S.contains(ell, 15, 65)                                 # the notch of the L
    assert S.distance(ell, 15, 65) == pytest.approx(5.0)
    assert S.loaded_at(S.triggers(city()), 15, 65).inside is False


def test_command_line(tmp_path, capsys):
    f = tmp_path / "streamgraph.p3d"
    f.write_bytes(city())
    assert S.main([str(f), "--at", "7", "5"]) == 0
    out = capsys.readouterr().out
    assert "inside 2 trigger(s): loadTrigger (a_01_shell), loadTrigger_1 (b_02_shell)" in out
    assert "  Shell: a_01_shell, b_02_shell" in out
    assert S.main([str(f), "--at", "50", "5"]) == 0
    assert "inside no trigger; the nearest: loadTrigger_1" in capsys.readouterr().out
    assert S.main([str(f)]) == 0
    out = capsys.readouterr().out
    assert out.startswith("3 stream package(s), 4 trigger(s)") and "subzone=c_03_shell" in out
    (tmp_path / "empty.p3d").write_bytes(p3d())
    assert S.main([str(tmp_path / "empty.p3d")]) == 1
