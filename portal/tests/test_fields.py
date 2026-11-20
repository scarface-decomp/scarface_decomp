"""Class fields from the program's addField calls (portal/tools/fields.py)."""

import json
import sys
from pathlib import Path

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import fields as F  # noqa: E402
import torque_script as TS  # noqa: E402

XBE = Path(__file__).resolve().parents[2] / "binaries" / "default.xbe"


def test_field_names_feed_the_name_dictionary(tmp_path):
    report = {"classes": {"TapeTrack": {"fields": [{"name": "LayerName"}]}}, "unowned": [{"name": "FOV"}]}
    p = tmp_path / "fields.json"
    p.write_text(json.dumps(report))
    assert TS.field_names(p) == ["LayerName", "FOV"]
    assert TS.field_names(tmp_path / "none.json") == []


@pytest.fixture(scope="module")
def report():
    if not XBE.exists():
        pytest.skip("needs your own copy of the game (binaries/default.xbe)")
    from sf_binaries import BinaryImage
    return F.harvest(BinaryImage(str(XBE)))


def fields(report, cls):
    return {f["name"]: f for f in report["classes"][cls]["fields"]}


def test_types_are_the_programs_own(report):
    assert report["types"]["1"] == "TypeS16" and report["types"]["4"] == "TypeBool"
    assert report["types"]["8"] == "TypeString" and report["types"]["16"] == "TypeSTE"


def test_every_call_is_read(report):
    n = sum(len(c["fields"]) for c in report["classes"].values()) + len(report["unowned"])
    assert n == 2389 and len(report["unowned"]) <= 3


def test_tape_track(report):
    """The examiner's hand decoding (A7.2): every field, type and offset."""
    t = fields(report, "TapeTrack")
    assert {k: (v["type"], v["offset"]) for k, v in t.items()} == {
        "WasPlayed": ("TypeBool", 0x20), "IsUnlocked": ("TypeBool", 0x21), "UnlockList": ("TypeS16", 0x22),
        "Title": ("TypeString", 0x24), "LayerName": ("TypeString", 0x28)}
    assert report["classes"]["TapeTrack"]["size"] == 0x2C
    m = fields(report, "TapeMixTape")
    assert m["Editable"]["offset"] == 0x3C and m["Title"]["offset"] == 0x40
    assert [m[f"TrackIndex{i}"]["offset"] for i in range(12)] == list(range(0x24, 0x3C, 2))


def test_instance_object(report):
    """J3.4: modelName and attractName by offset; the rest kept by setters."""
    i = fields(report, "InstanceObject")
    assert (i["modelName"]["type"], i["modelName"]["offset"]) == ("TypeSTE", 0x20)
    assert i["attractName"]["offset"] == 0x24
    assert {k: i[k]["setter_va"] for k in ("instancePosition", "noCollision", "interior", "doNotCull",
                                         "attractEnabled", "staticCollision", "noSway", "priority")} == {
        "instancePosition": "0x001D0AE0", "noCollision": "0x001D0720", "interior": "0x001D0750",
        "doNotCull": "0x001D04E0", "attractEnabled": "0x001D04E0", "staticCollision": "0x001D0510",
        "noSway": "0x001D0510", "priority": "0x001D06F0"}
    assert all(i[k]["offset"] is None for k in ("noCollision", "priority"))


def test_weapon_decal_template(report):
    """H10.1: a 0x28-byte block per surface: shaders at +0/+4, sizes at +8/+C."""
    w = fields(report, "WeaponDecalTemplate")
    for surface, base in (("Concrete", 0x24), ("Dirt", 0x4C), ("Wood", 0x74), ("Metal", 0x9C), ("Blood", 0xC4),
                          ("Glass", 0x164)):
        assert w[f"{surface}ShaderName1"]["offset"] == base and w[f"{surface}ShaderName2"]["offset"] == base + 4
        assert w[f"{surface}DecalSize1"]["offset"] == base + 8


def test_environment_object(report):
    """H2.5: the TOD block is the object + 0x30."""
    e = fields(report, "EnvironmentObject")
    for name, block in (("FogEnabled", 0x04), ("FogStart", 0x18), ("CbvLitBlendValue", 0xEC),
                        ("LODRedScaler", 0x134), ("ColourFX_Saturation", 0x70)):
        assert e[name]["offset"] == 0x30 + block, name
