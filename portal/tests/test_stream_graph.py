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


def test_one_trigger_applies_where_two_overlap():
    """SPEC-011 sections 1.3 and 2: no union; the first trigger in the file's order that holds the place,
    and exactly its packages."""
    found = S.triggers(city())
    one = S.loaded_at(found, 2, 5)
    assert one.inside and [t.name for t in one.triggers] == ["loadTrigger"]
    assert ("b_02_shell", "Shell") not in one.packages
    both = S.loaded_at(found, 7, 5)
    assert both.inside and [t.name for t in both.triggers] == ["loadTrigger"]
    assert both.packages == [("miami_lod", "Global_S"), ("miami_lod_d", "Global_D"), ("a_01_shell", "Shell"),
                             ("a_01_detail", "Detail")]
    assert both.by_slot()["Detail"] == ["a_01_detail"]
    assert [t.name for t in S.loaded_at(found, 12, 5).triggers] == ["loadTrigger_1"]


def test_a_trigger_is_an_upright_prism():
    """SPEC-011 section 1.2: from the average height of its points up by its height, both ends in; a
    height of 0 means no limit."""
    low = stream_trigger("loadTrigger_low", "a", square(0, 0, 10, 10), [("downstairs", "Detail")], height=10.0, base=0.0)
    high = stream_trigger("loadTrigger_high", "a", square(0, 0, 10, 10), [("upstairs", "Detail")], height=5.0, base=10.04)
    tall = stream_trigger("loadTrigger_tall", "a", square(20, 0, 30, 10), [("street", "Shell")], height=0.0, base=3.0)
    found = S.triggers(p3d(low, high, tall))
    assert found[1].base == 10.0 and found[1].top == 15.0              # kept in tenths, cut down
    assert found[2].top is None
    assert S.loaded_at(found, 5, 5, 4.0).packages == [("downstairs", "Detail")]
    assert S.loaded_at(found, 5, 5, 10.0).packages == [("downstairs", "Detail")]   # its roof is in it too
    assert S.loaded_at(found, 5, 5, 12.0).packages == [("upstairs", "Detail")]
    assert S.loaded_at(found, 5, 5).packages == [("downstairs", "Detail")]        # without a height: the first
    assert S.contains(found[2], 25, 5, -500.0) and S.contains(found[2], 25, 5, 9000.0)


def test_the_trigger_that_gives_way_comes_last():
    """SPEC-011 section 1.3: the one trigger whose last number isn't 0 gives way to any other holding you."""
    gives = stream_trigger("loadTrigger_big", "a", square(0, 0, 100, 100), [("big", "Shell")], flag=1)
    room = stream_trigger("loadTrigger_room", "b", square(10, 10, 20, 20), [("room", "Shell")])
    found = S.triggers(p3d(gives, room))
    assert found[0].gives_way and not found[1].gives_way
    assert S.loaded_at(found, 15, 15).packages == [("room", "Shell")]
    assert S.loaded_at(found, 50, 50).packages == [("big", "Shell")]


def test_the_zone_scripts_triggers():
    """The dzone and azone scripts' own outlines (SPEC-001 section 4.3), as the decompiler writes them."""
    text = """new stxddnhlkdj("nbeach_dzTriggers")
{
    new stxgpjhamho("luxBank_dzTrigger")
    {
        stxngcbeklm = 5;
        stxcbiedpki = "0 0 0";
        stxdbiedpki = "10 0 0";
        stxabiedpki = "10 0 10";
        stxbbiedpki = "0 0 10";
        stxgbiedpki = "0 0 0";
        stxncchodbl = "0.0";
        stxopplcgel = "LoadDzone('nbeach_luxBank_dzone');";
        stxeliilhjo = "UnloadDzone('nbeach_luxBank_dzone');";
        stxeobamfnj = "nbeach_region_D";
    };
    new stxgpjhamho("empty") { stxngcbeklm = 0; };
};"""
    found = S.script_triggers(text)
    assert [(t.name, t.packages, len(t.points)) for t in found] == [("luxBank_dzTrigger", ["nbeach_luxBank_dzone"], 5)]
    assert S.script_loaded_at(found, 5, 5) == ["nbeach_luxBank_dzone"]
    assert S.script_loaded_at(found, 15, 5) == []


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
    assert "the trigger that applies: loadTrigger (a_01_shell)" in out
    assert "  Shell: a_01_shell\n" in out
    assert S.main([str(f), "--at", "50", "5"]) == 0
    assert "inside no trigger; the nearest: loadTrigger_1" in capsys.readouterr().out
    assert S.main([str(f)]) == 0
    out = capsys.readouterr().out
    assert out.startswith("3 stream package(s), 4 trigger(s)") and "subzone=c_03_shell" in out
    (tmp_path / "empty.p3d").write_bytes(p3d())
    assert S.main([str(tmp_path / "empty.p3d")]) == 1


def test_above_every_prism_the_buildings_own_trigger():
    """SPEC-011 section 1.3: where no prism holds you, the current trigger stays. Upstairs above a street
    trigger that stops at 10, you came up through its neighbour that has no height limit (Jerry's office)."""
    street = stream_trigger("loadTrigger_448", "cgrove_01_shell", square(0, 0, 50, 50),
                            [("cgrove_01_shell", "Shell"), ("bank_02_shell", "Shell"), ("bank_02_detail", "Detail")],
                            height=10.0, base=0.0)
    near = stream_trigger("loadTrigger_233", "cgrove_01_shell", square(-20, 0, -1, 50),
                          [("cgrove_01_shell", "Shell"), ("bank_02_shell", "Shell")], height=0.0)
    stairs = stream_trigger("loadTrigger_400", "bank_02_shell", square(0, 40, 20, 80),
                            [("bank_02_shell", "Shell"), ("bank_02_detail", "Detail"), ("bank_02_detailb", "Detail")],
                            height=0.0)
    found = S.triggers(p3d(street, near, stairs))
    upstairs = S.loaded_at(found, 5, 25, 13.8)
    assert not upstairs.inside and [t.name for t in upstairs.triggers] == ["loadTrigger_400"]
    assert ("bank_02_detailb", "Detail") in upstairs.packages
    assert [t.name for t in S.loaded_at(found, 5, 25, 6.0).triggers] == ["loadTrigger_448"]
    # with no neighbour reaching the height, the one under you stays
    alone = S.triggers(p3d(street, near))
    assert [t.name for t in S.loaded_at(alone, 5, 25, 13.8).triggers] == ["loadTrigger_448"]
    assert S.touches(found[0], found[2]) and not S.touches(found[1], found[2])
