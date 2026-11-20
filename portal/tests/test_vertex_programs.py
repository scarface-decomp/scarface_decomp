"""The vertex-program reader (portal/tools/vertex_programs.py)."""

import struct
import sys
from pathlib import Path

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import vertex_programs as V  # noqa: E402

XBE = Path(__file__).resolve().parents[2] / "binaries" / "default.xbe"

# Two instructions as the game stores them: the unlit colour, then the lit program's doubling (final).
COLOUR = (0x0, 0x0052E61B, 0x0836186C, 0x2070F818)
DOUBLE = (0x0, 0x0060001A, 0x8400106A, 0x1E80E819)


def blob(*words):
    return struct.pack("<HH", V.TYPE, len(words)) + b"".join(struct.pack("<4I", *w) for w in words)


def test_instructions():
    assert V.instruction(COLOUR) == ["mul oD0, v3, c[55]"]
    assert V.instruction(DOUBLE) == ["add r8.xyz & oD0.xyz, r8.xyzz, r8.xyzz"]


def test_a_program_and_what_it_reads():
    p = V.read_program(blob(COLOUR, DOUBLE), 0, 0x1000)
    assert p.count == 2 and p.reads() == [55]
    assert p.assembly() == ["  0  mul oD0, v3, c[55]", "  1  add r8.xyz & oD0.xyz, r8.xyzz, r8.xyzz"]


def test_not_a_program():
    with pytest.raises(ValueError):                       # the final mark on the first of two
        V.read_program(blob(DOUBLE, COLOUR), 0)
    with pytest.raises(ValueError):                       # a first word that isn't 0
        V.read_program(blob((1,) + DOUBLE[1:]), 0)
    with pytest.raises(ValueError):
        V.read_program(b"\x00\x00\x01\x00", 0)


@pytest.mark.skipif(not XBE.exists(), reason="needs your own copy of the game (binaries/default.xbe)")
def test_the_games_programs():
    from sf_binaries import BinaryImage
    found = {p.address: p for p in V.programs(BinaryImage(str(XBE)))}
    assert len(found) == 16
    cbvlit = "\n".join(found[0x45E3D0].assembly())
    assert "add r8.xyz, r8.xyzz, r8.xyzz" in cbvlit and "mul r8.xyz, r8.xyzz, v3.xyzz" in cbvlit
    assert "add r8.xyz & oD0.xyz, r8.xyzz, r8.xyzz" in "\n".join(found[0x45E008].assembly())
    assert "mul oD0, v3, c[55]" in "\n".join(found[0x45DF20].assembly())
