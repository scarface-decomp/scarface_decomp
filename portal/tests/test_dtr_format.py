"""portal/tools/dtr_format.py: Scarface's AI decision trees (.dtr) come apart and go back together exactly."""
import struct

import pytest

from conftest import ROOT

import dtr_format as DT
from torque_names import name_key


def sample() -> bytes:
    strings = b"AITask_Flee\0run away\0"
    d = DT.Dtr(name_key("common"), 0x1234, programs=[[45, 2, 8, 26], [139], [140, 26]],
               nodes=[(0xFFFF, 0xFFFF, 0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0, 1, 0),
                      (0, 2, 0x101, 1, 0xFFFF, 0, 0xFFFF, 0, 100, 0),
                      (0, 0xFFFF, 0x101, 0xFFFF, 0xFFFF, 2, 0xFFFF, 0, 0, 1)],
               tasks=[(name_key("AITask_Flee"), 12), (name_key("AITask_Cower"), 0xFFFFFFFF)],
               strings=strings)
    return DT.build(d)


def test_layout_round_trip():
    raw = sample()
    assert raw[:4] == struct.pack("<I", DT.MAGIC) and DT.round_trip(raw) == (True, "rebuilt byte for byte")
    d = DT.parse(raw)
    assert d.programs == [[45, 2, 8, 26], [139], [140, 26]] and d.string_at(12) == "run away"


def test_description_names_the_tasks():
    names = {name_key("common"): "common", name_key("AITask_Flee"): "AITask_Flee"}
    text = DT.describe(sample(), "common.dtr", names)
    assert "decision tree 'common'" in text and 'AITask_Flee "run away"  value 100' in text
    assert "C: #0 [45 2 8 26]" in text and "0x" in text.split("node 2")[1]     # unknown task stays a key


@pytest.mark.parametrize("cut", [8, 0x30, 100])
def test_damaged_files_are_errors(cut):
    with pytest.raises(DT.DtrError):
        DT.parse(sample()[:cut])
    with pytest.raises(DT.DtrError):
        DT.parse(b"\0" * 4 + sample()[4:])


@pytest.mark.skipif(not list((ROOT / "binaries" / "scripts_and_data").rglob("*.dtr"))
                    if (ROOT / "binaries" / "scripts_and_data").exists() else True,
                    reason="no .dtr files in binaries/scripts_and_data")
def test_game_trees_rebuild_exactly():
    for p in (ROOT / "binaries" / "scripts_and_data").rglob("*.dtr"):
        assert DT.round_trip(p.read_bytes())[0], p


def test_sections_start_on_four_bytes():
    # an odd number of programs leaves 2 zero bytes before the program words (the prototype's tree)
    d = DT.parse(sample())
    d.programs = d.programs[:2] + [[1], [140, 26]]
    raw = DT.build(d)
    assert len(d.programs) % 2 == 0 and DT.round_trip(raw)[0]
    d.programs = d.programs[:3]
    raw = DT.build(d)
    assert raw[0x30 + 6:0x30 + 8] == b"\0\0" and DT.round_trip(raw)[0] and DT.parse(raw).programs == d.programs
