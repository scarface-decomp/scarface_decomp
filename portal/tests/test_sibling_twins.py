"""
Functions two programs share and a program's own list of library functions (portal/tools/sibling_twins.py),
on made-up Xbox programs.
"""
import struct

from conftest import make_xbe

import sibling_twins as ST
from sf_binaries import BinaryImage

TEXT, DATA = 0x11000, 0x400000


def rel(op, at, target):
    return bytes([op]) + struct.pack("<i", target - (at + 5))


def program(tmp_path, name, base, order, ids=None):
    """A program whose functions are laid out in `order`, each on its own 0x40 line, all called from the first
    line. `ids` adds a .XTLID section of (id, function name)."""
    bodies = {
        # loads a global, adds to it, stores it: 22 bytes with three addresses in them
        "long": lambda g: b"\xA1" + struct.pack("<I", g) + b"\x05" + struct.pack("<I", 7)
                          + b"\xA3" + struct.pack("<I", g + 4) + b"\x8B\x0D" + struct.pack("<I", g + 8) + b"\xC3",
        "other": lambda g: b"\x8B\x44\x24\x04\x8B\x4C\x24\x08\x03\xC1\x0F\xAF\xC1\x2B\xC1\x40\x40\x40\xC3",
        "short": lambda g: b"\x33\xC0\xC3",
        "lib": lambda g: b"\x6A\x00\xFF\x74\x24\x08\xFF\x15" + struct.pack("<I", g + 0x20) + b"\x33\xC0\x40\x48\xC2\x04\x00",
    }
    code = bytearray(b"\xCC" * 0x400)
    where = {}
    for n, fn in enumerate(order):
        at = 0x40 * (n + 1)
        body = bodies[fn](DATA + base)
        code[at:at + len(body)] = body
        where[fn] = TEXT + at
    at = 0
    for fn in order:                                            # the caller: one call to each, then ret
        code[at:at + 5] = rel(0xE8, TEXT + at, where[fn])
        at += 5
    code[at] = 0xC3
    sections = [(".text", TEXT, bytes(code), 0x6), (".data", DATA, bytes(0x100), 0x1)]
    if ids:
        sections.append((".XTLID", 0x500000, b"".join(struct.pack("<II", i, where[fn]) for i, fn in ids), 0x1))
    return BinaryImage(make_xbe(tmp_path / name, sections)), where


def test_functions_two_programs_share(tmp_path):
    mine, at = program(tmp_path, "default.xbe", 0x00, ["long", "short", "other"])
    theirs, there = program(tmp_path, "sibling.xbe", 0x40, ["other", "lib", "long", "short"])
    a = ST.shapes(mine, ST.own_starts(mine))
    b = ST.shapes(theirs, ST.own_starts(theirs))
    assert a[at["long"]][1] == 22 and a[at["long"]][0] == b[there["long"]][0]      # other addresses, same shape
    found = ST.twins(a, {"sib": b})
    # the three-byte function is in both programs but says nothing; the caller differs
    assert found == {at["long"]: {"size": 22, "in": {"sib": there["long"]}},
                     at["other"]: {"size": 19, "in": {"sib": there["other"]}}}
    assert ST.twins(a, {"sib": b}, min_size=20) == {at["long"]: {"size": 22, "in": {"sib": there["long"]}}}


def test_a_shape_the_sibling_has_twice_gives_no_address(tmp_path):
    mine, at = program(tmp_path, "default.xbe", 0x00, ["long"])
    theirs, there = program(tmp_path, "sibling.xbe", 0x40, ["long"])
    b = ST.shapes(theirs, ST.own_starts(theirs))
    b[0x999000] = b[there["long"]]
    assert ST.twins(ST.shapes(mine, ST.own_starts(mine)), {"sib": b})[at["long"]]["in"] == {"sib": None}


def test_a_programs_own_list_of_library_functions(tmp_path):
    mine, at = program(tmp_path, "default.xbe", 0x00, ["long", "lib"])
    theirs, there = program(tmp_path, "sibling.xbe", 0x40, ["lib", "other"],
                            ids=[(0x20090, "lib"), (0x10004, "other")])
    assert ST.xtl_ids(mine) == []
    assert ST.xtl_ids(theirs) == [(2, 0x90, there["lib"]), (1, 4, there["other"])]
    a = ST.shapes(mine, ST.own_starts(mine))
    b = ST.shapes(theirs, ST.own_starts(theirs))
    assert ST.library_ids(a, theirs, b) == {at["lib"]: [(2, 0x90)]}        # "other" is not in this program
    rows = ST.merge_library_ids({"one": {at["lib"]: [(2, 0x90)]}, "two": {at["lib"]: [(2, 0x90), (2, 0x91)]}},
                                {at["lib"]: "Sleep"})
    assert rows == [{"va": f"0x{at['lib']:08X}", "ids": [{"library": 2, "number": 0x90}, {"library": 2, "number": 0x91}],
                     "from": ["one", "two"], "name": "Sleep"}]
