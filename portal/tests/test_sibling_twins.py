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


def stubs(tmp_path, name, numbers, ids=None, forward=None):
    """A program of three-instruction library stubs, one for each kernel function number in `numbers`
    (`mov eax, [cell]; mov eax, [eax]; ret`), with the import table the header points at. `forward` adds
    two forwarders (`jmp`) to the first and the last stub."""
    table = 0x400000
    code = bytearray(b"\xCC" * 0x400)
    where = {}
    for n, number in enumerate(numbers):
        at = 0x40 * (n + 1)
        code[at:at + 8] = b"\xA1" + struct.pack("<I", table + 4 * n) + b"\x8B\x00\xC3"
        where[number] = TEXT + at
    at = 0
    for number in numbers:
        code[at:at + 5] = rel(0xE8, TEXT + at, where[number])
        at += 5
    if forward:
        for n, number in enumerate((numbers[0], numbers[-1])):
            spot = 0x200 + 0x40 * n
            code[spot:spot + 5] = rel(0xE9, TEXT + spot, where[number])
            where["to", number] = TEXT + spot
            code[at:at + 5] = rel(0xE8, TEXT + at, TEXT + spot)
            at += 5
    code[at] = 0xC3
    cells = b"".join(struct.pack("<I", 0x80000000 + number) for number in numbers) + bytes(4)
    sections = [(".text", TEXT, bytes(code), 0x6), (".data", table, cells + bytes(0x40), 0x1)]
    if ids:
        sections.append((".XTLID", 0x500000, b"".join(struct.pack("<II", i, where[k]) for i, k in ids), 0x1))
    path = make_xbe(tmp_path / name, sections)
    raw = bytearray(path.read_bytes())
    struct.pack_into("<I", raw, 0x158, table ^ ST.KERNEL_KEYS[0])
    path.write_bytes(bytes(raw))
    return BinaryImage(path), where


def test_a_stub_is_told_by_the_kernel_function_it_reaches(tmp_path):
    """Two library functions that are the same bytes apart from one import cell: the number goes to the one
    that reaches the same kernel function, and to none when this program has only the other one."""
    mine, at = stubs(tmp_path, "default.xbe", [356, 156])
    theirs, there = stubs(tmp_path, "sibling.xbe", [156, 7, 356], ids=[(0x100029, 356), (0x2000B5, 156)])
    assert ST.kernel_cells(mine) == {0x400000: 356, 0x400004: 156}
    a, b = ST.shapes(mine, ST.own_starts(mine)), ST.shapes(theirs, ST.own_starts(theirs))
    assert a[at[356]][0] == a[at[156]][0] == b[there[7]][0]                    # one shape for all of them
    assert ST.library_ids(a, theirs, b) == {}                                 # by shape alone: nothing to tell
    assert ST.library_ids(a, theirs, b, mine) == {at[356]: [(0x10, 0x29)], at[156]: [(0x20, 0xB5)]}
    only, at1 = stubs(tmp_path, "one.xbe", [356])                             # one stub: its shape is unique here
    c = ST.shapes(only, ST.own_starts(only))
    wrong = ST.library_ids(c, theirs, b)
    assert sorted(wrong[at1[356]]) == [(0x10, 0x29), (0x20, 0xB5)]            # by shape: both numbers land on it
    assert ST.library_ids(c, theirs, b, only) == {at1[356]: [(0x10, 0x29)]}  # by what it reaches: its own


def test_a_forwarder_is_told_by_what_it_calls(tmp_path):
    mine, at = stubs(tmp_path, "default.xbe", [356, 156], forward=True)
    theirs, there = stubs(tmp_path, "sibling.xbe", [156, 356], forward=True,
                          ids=[(0x20016C, ("to", 156)), (0x20016D, ("to", 356))])
    a, b = ST.shapes(mine, ST.own_starts(mine)), ST.shapes(theirs, ST.own_starts(theirs))
    assert a[at["to", 356]][0] == a[at["to", 156]][0]
    got = ST.library_ids(a, theirs, b, mine)
    assert got[at["to", 156]] == [(0x20, 0x16C)] and got[at["to", 356]] == [(0x20, 0x16D)]


def test_open_shared_functions_by_class():
    report = {"functions": {"xb": [{"va": "0x00011000", "size": 40}, {"va": "0x00011100", "size": 300},
                                   {"va": "0x00011200", "size": 64}, {"va": "0x00011300", "size": 90},
                                   {"va": "0x00011400", "size": 20}]}}
    tasks = [{"bin": "xb", "fva_int": 0x11000, "symbol": "core::File::vfunc_04"},
             {"bin": "xb", "fva_int": 0x11100, "symbol": "pure3d::Texture::vfunc_02"},
             {"bin": "xb", "fva_int": 0x11200, "symbol": "core::File::vfunc_05"},
             {"bin": "xb", "fva_int": 0x11300, "symbol": "sub_00011300"},
             {"bin": "proto", "fva_int": 0x11400, "symbol": "core::File::vfunc_09"}]
    rows = ST.open_by_class(report, tasks, {"xb:0x00011200"})                   # one of File's is matched already
    assert rows == [{"class": "pure3d::Texture", "open": 1, "bytes": 300, "functions": ["0x00011100"]},
                    {"class": "core::File", "open": 1, "bytes": 40, "functions": ["0x00011000"]},
                    {"class": "", "open": 1, "bytes": 90, "functions": ["0x00011300"]}]
