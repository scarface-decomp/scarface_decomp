"""Which class an object is (portal/tools/vtypes.py), on made-up code: constructors, what is really built,
typed globals."""
import struct
import sys
from pathlib import Path

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import vtypes as V  # noqa: E402

capstone = pytest.importorskip("capstone")


class Sec:
    def __init__(self, code, name):
        self.is_code, self.name = code, name


class FakeImage:
    def __init__(self, mem):
        self.mem = mem

    def read(self, va, n):
        for base, b in self.mem.items():
            if base <= va and va + n <= base + len(b):
                return b[va - base:va - base + n]
        return None

    def section_of(self, va):
        if 0x1000 <= va < 0x2000:
            return Sec(True, ".text")
        if 0x6000 <= va < 0x8000:
            return Sec(False, ".data")
        return None


class FakeImg:
    def __init__(self, mem):
        self.img = FakeImage(mem)


class FakeRtti:
    vtables = {0x5100: ("A", 0, [0x1F00]), 0x5200: ("B", 0, [0x1F00, 0x1F10])}
    bases = {"A": [], "B": [("A", 0)]}


def u32(v):
    return struct.pack("<I", v)


def call(at, target):
    return b"\xE8" + struct.pack("<i", target - (at + 5))


FUNCS = {
    0x1000: b"\x56\x8B\xF1\xC7\x06" + u32(0x5100) + b"\x8B\xC6\x5E\xC3",            # A::A: returns this
    0x1100: b"\x56\x8B\xF1" + call(0x1103, 0x1000) + b"\xC7\x06" + u32(0x5200) + b"\x8B\xC6\x5E\xC3",   # B::B
    0x1200: b"\xB9" + u32(0x6000) + call(0x1205, 0x1100) + b"\xA3" + u32(0x7000) + b"\xC3",   # g = B at 0x6000
    0x1300: b"\x56\x8B\xF1\xC7\x06" + u32(0x5200) + b"\xC7\x06" + u32(0x5100) + b"\x5E\xC3",  # ~B, ~A inlined
}


def facts():
    mem = {a: b + b"\xCC" * 8 for a, b in FUNCS.items()}
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    return V.Facts(md, FakeImg(mem), FakeRtti(), {a: len(b) for a, b in FUNCS.items()})


def test_only_the_derived_class_is_built():
    fx = facts()
    built = V.instantiated(fx)
    assert built == {"B": [0x1100]}            # A::A only runs as B's base; 0x1300 is a destructor
    assert V.returns_this(fx, 0x1000) and not V.returns_this(fx, 0x1200)


def test_a_global_holding_a_constructors_result_is_typed():
    fx = facts()
    typed = V.typed_globals(fx, V.instantiated(fx))
    assert typed == {0x7000: ("B", "new + constructor", "0x0000120A")}


def test_family_leaf_needs_every_long_enough_vtable_to_agree():
    cands = [("B", 0x5200, [0x1F00, 0x1F10]), ("C", 0x5300, [0x1F00, 0x1F20])]
    assert V.family_leaf(cands, {0}) == {0: 0x1F00}
    assert V.family_leaf(cands, {1}) is None
    assert V.family_leaf(cands, {5}) is None


def test_data_names_are_checked():
    import names as NAMES
    good = {"schema": NAMES.SCHEMA, "names": {},
            "data": {"xb:0x0047B354": {"name": "g_globalNamespace", "type": "Namespace*", "by": "me", "why": "GetGlobalNamespace returns it."}}}
    assert NAMES.problems(good) == []
    bad = {"schema": NAMES.SCHEMA, "names": {},
           "data": {"xb:0x47B354": {"name": "DAT_0047B354", "by": "", "why": "x"}}}
    assert len(NAMES.problems(bad)) == 1
    bad["data"] = {"xb:0x0047B354": {"name": "DAT_0047B354", "by": "", "why": "x"}}
    assert len(NAMES.problems(bad)) == 3
