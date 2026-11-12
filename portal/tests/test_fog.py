"""The fog by time of day (portal/tools/fog.py): the EnvironmentObjects of a compiled script, the tod object's
key hours in a .p3d, and the fog blended between them. The scripts and files here are made up in the form
the clean-room spec (docs/cleanroom/SPEC-001-lights-sky-streaming.md, section 5) describes; the numbers are
the spec's Miami table."""
import json
import struct

import pytest

import fog as F
import torque_script as TS
from test_p3d import chunk, p3d, text

HOURS = (4, 9, 12, 18, 21, 24)
# (start, end, red, green, blue) by hour: Miami, from the spec's table
CLEAR = {4: (20, 800, 23, 28, 40), 9: (25, 800, 245, 240, 160), 12: (25, 900, 200, 200, 150),
         18: (25, 800, 227, 223, 105), 21: (20, 800, 50, 35, 33), 24: (20, 800, 20, 25, 32)}
RAINY = {4: (10, 525, 16, 16, 17), 9: (20, 700, 35, 35, 23), 12: (20, 700, 35, 35, 28),
         18: (20, 600, 35, 35, 21), 21: (20, 700, 26, 21, 21), 24: (10, 500, 14, 14, 16)}


def env_script(prefix="", enabled=1, extra=""):
    """graphanims.cso as TorqueScript: an EnvironmentObject per weather and key hour, with fog and a few other
    looks the fog doesn't use."""
    out = extra
    for weather, table in (("clear", CLEAR), ("rainy", RAINY)):
        for h, (start, end, r, g, b) in table.items():
            out += (f'new EnvironmentObject("{prefix}environment_{weather}_{h}")\n{{\n    FogEnabled = {enabled};\n'
                    f'    FogStart = {start};\n    FogEnd = {end};\n    FogColor_Red = {r};\n    FogColor_Green = {g};\n'
                    f'    FogColor_Blue = {b};\n    FogColor_Alpha = 120;\n    FogClamp = 1;\n    Bloom_Strength = 2;\n'
                    f'    WindStrength = "0.5";\n}};\n')
    return out


def tod_chunk(links=True, wrap=True):
    """The tod object (class todobject) as miami_lod.p3d holds it: a script object in a game group."""
    hours = ["4", "9", "12.0", "18.0", "21.0", "24.0"]
    props = b""
    for n, h in enumerate(hours):
        whole = int(float(h))
        pairs = [(f"prelitluminancetime_{n}", h), (f"timetohold_{n}", "0"), (f"timetotransit_{n}", "200")]
        if links:
            pairs += [(f"attachedclearenvparamname_{n}", f"environment_clear_{whole}"),
                      (f"attachedrainyenvparamname_{n}", f"environment_rainy_{whole}")]
        props += b"".join(chunk(0x9900192, text(k) + struct.pack("<I", 0) + text(v)) for k, v in pairs)
    props += chunk(0x9900192, text("enableraining") + struct.pack("<I", 0) + text("0"))
    obj = chunk(0x9900190, text("tod.ds") + text("tod") + text("todobject"), props)
    if not wrap:
        return obj
    return chunk(0x9900191, text("tod.ds") + text("tod") + text("gamegroup") + struct.pack("<I", 1), obj)


def objects():
    return F.environment_objects(TS.compile_text(env_script()))


def tod():
    return F.tod_object(p3d(tod_chunk()))


def rgb(*c):
    return [round(v / 255, 4) for v in c]


def test_the_objects_come_out_of_the_compiled_script_with_hashed_names():
    found = objects()                                     # compiled: every name is stored hashed
    assert len(found) == 12
    noon = found[F.name_key("environment_clear_12")]
    assert noon["name"] == "environment_clear_12"
    assert noon["fog"] == {"FogEnabled": 1, "FogStart": 25, "FogEnd": 900, "FogColor_Red": 200, "FogColor_Green": 200,
                           "FogColor_Blue": 150, "FogColor_Alpha": 120, "FogClamp": 1}
    # the decompiled text (torque_script.py decompile) reads the same, with or without the names recovered
    raw = TS.compile_text(env_script())
    assert "stx" in TS.decompile(raw) and F.environment_objects(TS.decompile(raw)) == found
    assert F.environment_objects(env_script()) == found


def test_other_objects_and_unreadable_scripts():
    extra = 'new ScriptObject("environment_clear_99")\n{\n    FogStart = 1;\n};\n'
    assert F.name_key("environment_clear_99") not in F.environment_objects(env_script(extra=extra))
    with pytest.raises(F.FogError):
        F.environment_objects(b"\x01\x02\x03\x04" * 8)


def test_the_tod_objects_key_hours_and_links():
    props = tod()
    assert props["prelitluminancetime_2"] == "12.0" and props["enableraining"] == "0"
    assert F.key_hours(props) == [(4.0, "environment_clear_4"), (9.0, "environment_clear_9"),
                                  (12.0, "environment_clear_12"), (18.0, "environment_clear_18"),
                                  (21.0, "environment_clear_21"), (24.0, "environment_clear_24")]
    assert F.key_hours(props, "rain")[0] == (4.0, "environment_rainy_4")
    assert F.tod_object(p3d(tod_chunk(wrap=False))) == props          # not in a game group: found too
    assert F.tod_object(p3d(chunk(0x9900190, text("x.ds") + text("lamp") + text("instanceobject")))) == {}


@pytest.mark.parametrize("hour, start, end, colour", [
    (12, 25, 900, (200, 200, 150)),                         # the spec's checks: noon, 4 a.m. and 9 a.m.
    (4, 20, 800, (23, 28, 40)),
    (9, 25, 800, (245, 240, 160)),
    (10.5, 25, 850, (222.5, 220, 155)),                     # halfway from 9 to 12
    (15, 25, 850, (213.5, 211.5, 127.5)),                   # halfway from 12 to 18
])
def test_fog_at_key_hours_and_between_them(hour, start, end, colour):
    fog = F.fog_at(hour, tod(), objects())
    assert (fog["start"], fog["end"]) == pytest.approx((start, end))
    assert fog["color"] == pytest.approx(rgb(*colour), abs=1e-4)
    assert fog["enabled"] is True and fog["alpha"] == 120 and fog["clamp"] == 1
    assert fog["weather"] == "clear" and fog["place"] == "miami" and fog["hour"] == hour


def test_the_hours_go_round_past_midnight():
    two = F.fog_at(2, tod(), objects())                     # between the 24 key (as 0) and the 4 key
    assert two["keys"] == ["environment_clear_24", "environment_clear_4"] and two["blend"] == 0.5
    assert two["color"] == pytest.approx(rgb(21.5, 26.5, 36), abs=1e-4) and two["end"] == 800
    late = F.fog_at(22.5, tod(), objects())                 # between 21 and 24
    assert late["keys"] == ["environment_clear_21", "environment_clear_24"]
    assert late["color"] == pytest.approx(rgb(35, 30, 32.5), abs=1e-4)
    for midnight in (0, 24):                                # 24 is 0: the 24 key's own fog
        fog = F.fog_at(midnight, tod(), objects())
        assert fog["color"] == rgb(20, 25, 32) and fog["blend"] == 0.0


def test_rain_takes_the_rainy_objects():
    fog = F.fog_at(12, tod(), objects(), "rain")
    assert (fog["start"], fog["end"], fog["color"]) == (20, 700, rgb(35, 35, 28))   # the spec's check for rain
    assert F.fog_at(2, tod(), objects(), "rain")["end"] == pytest.approx(512.5)    # 500 at 24, 525 at 4
    with pytest.raises(F.FogError):
        F.fog_at(12, tod(), objects(), "snow")


def test_the_islands_objects_and_what_is_missing():
    islands = F.environment_objects(TS.compile_text(env_script(prefix="island_")))
    assert F.fog_at(12, tod(), islands) is None                     # Miami's names aren't there
    fog = F.fog_at(12, tod(), islands, islands=True)
    assert fog["keys"][0] == "island_environment_clear_12" and fog["place"] == "islands"
    assert F.fog_at(12, F.tod_object(p3d(tod_chunk(links=False))), objects()) is None
    assert F.fog_at(12, {}, objects()) is None
    off = F.environment_objects(TS.compile_text(env_script(enabled=0)))
    assert F.fog_at(12, tod(), off)["enabled"] is False


def test_finding_the_scripts(tmp_path):
    game = tmp_path / "game"
    (game / "scriptc").mkdir(parents=True)
    (game / "scriptc" / "graphanims.cso.cs").write_text("// decompiled")
    assert F.find_scripts([game]) == {"miami": game / "scriptc" / "graphanims.cso.cs"}
    (game / "scriptc" / "GraphAnims.cso").write_bytes(b"x")                 # the compiled one is preferred
    (game / "scriptc" / "island_envobjects.cso").write_bytes(b"x")
    assert F.find_scripts([game]) == {"miami": game / "scriptc" / "GraphAnims.cso",
                                      "islands": game / "scriptc" / "island_envobjects.cso"}
    assert F.find_scripts([game / "scriptc" / "island_envobjects.cso", tmp_path / "nowhere"]) == {
        "islands": game / "scriptc" / "island_envobjects.cso"}


def test_command_line(tmp_path, capsys):
    (tmp_path / "miami_lod.p3d").write_bytes(p3d(tod_chunk()))
    (tmp_path / "graphanims.cso").write_bytes(TS.compile_text(env_script()))
    (tmp_path / "graphanims.cso.cs").write_text(env_script(), encoding="latin-1")
    for script in ("graphanims.cso", "graphanims.cso.cs"):
        assert F.main([str(tmp_path / "miami_lod.p3d"), str(tmp_path / script), "--hour", "12"]) == 0
        fog = json.loads(capsys.readouterr().out)
        assert (fog["start"], fog["end"]) == (25, 900)
    assert F.main([str(tmp_path / "miami_lod.p3d"), str(tmp_path / "graphanims.cso"), "--hour", "25"]) == 1
    (tmp_path / "empty.p3d").write_bytes(p3d())
    assert F.main([str(tmp_path / "empty.p3d"), str(tmp_path / "graphanims.cso"), "--hour", "1"]) == 1
    assert "no tod object" in capsys.readouterr().err
