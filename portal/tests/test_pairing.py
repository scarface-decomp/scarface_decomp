"""Pairing a function with its twin in another build (portal/tools/pairing.py, the examiner's question E1).
Every program here is made up."""
import struct

from conftest import make_xbe

import pairing as P
from sf_binaries import BinaryImage

F = P.Function


def test_shape_text_calls_order_and_loose():
    a = {0x100: F(0x100, 40, "s1", "l1", [0x200, 0x300]), 0x200: F(0x200, 8, "s9", "l2"),
         0x300: F(0x300, 8, "s8", "l3"), 0x400: F(0x400, 30, "x", "lx", texts=("Hello",)),
         0x500: F(0x500, 30, "s5", "l5"), 0x510: F(0x510, 20, "aa", "la"), 0x520: F(0x520, 20, "ab", "lb"),
         0x600: F(0x600, 30, "s6", "l6"), 0x700: F(0x700, 40, "q", "lq")}
    b = {0x1100: F(0x1100, 40, "s1", "l1", [0x1200, 0x1300]), 0x1200: F(0x1200, 8, "t9", "l2"),
         0x1300: F(0x1300, 8, "t8", "l3"), 0x1400: F(0x1400, 31, "y", "ly", texts=("Hello",)),
         0x1500: F(0x1500, 30, "s5", "l5"), 0x1510: F(0x1510, 20, "ba", "la"), 0x1520: F(0x1520, 20, "bb", "lb"),
         0x1600: F(0x1600, 30, "s6", "l6"), 0x1700: F(0x1700, 40, "r", "lq")}
    got = P.pair(a, b)
    assert got[0x100] == (0x1100, "shape")
    assert got[0x200] == (0x1200, "calls") and got[0x300] == (0x1300, "calls")      # by their place in the calls
    assert got[0x400] == (0x1400, "text")                                          # the same strings
    assert got[0x510] == (0x1510, "order") and got[0x520] == (0x1520, "order")     # between 0x500 and 0x600
    assert got[0x700] == (0x1700, "loose shape")
    assert len(set(y for y, _h in got.values())) == len(got)                       # nothing paired twice


def test_a_shape_found_twice_pairs_nothing_by_shape():
    a = {1: F(1, 40, "s", "l"), 2: F(2, 40, "s", "l")}
    b = {11: F(11, 40, "s", "l")}
    assert P.pair(a, b) == {}


def test_describing_code_sets_addresses_aside(tmp_path):
    # mov eax, [0x30000] ; push 0x30010 (a string) ; call +0 ; ret     at two different places, same shape
    def code(text_va, call_rel):
        return (b"\xA1" + struct.pack("<I", 0x30000) + b"\x68" + struct.pack("<I", text_va) + b"\xE8"
                + struct.pack("<i", call_rel) + b"\xC3")
    data = b"\0" * 16 + b"Hello world\0" + b"\0" * 4
    text = code(0x30010, 0) + code(0x30010, 0x40)
    img = BinaryImage(make_xbe(tmp_path / "t.xbe", [(".text", 0x11000, text, 0x6), (".rdata", 0x30000, data, 0x2)]))
    one, two = P.describe(img, 0x11000, 16), P.describe(img, 0x11010, 16)
    assert one.shape == two.shape and one.texts == ("Hello world",)
    assert one.calls == [0x11000 + 15] and two.calls == [0x11010 + 15 + 0x40]


def test_the_projects_function_list(tmp_path):
    p = tmp_path / "list.cpp"
    p.write_text("// x\n// [TODO] 0x00011000 sub_00011000 (81 B)\n// [VERIFIED] sub_000114F0 (0x000114F0, 11 B)\n"
                 "// [VERIFIED] Thing::Do (0x00011500, 6 B)\n")
    assert P.listed(p) == {0x11000: (81, False), 0x114F0: (11, True), 0x11500: (6, True)}
