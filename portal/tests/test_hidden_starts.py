"""
Functions only the program's own tables point at (portal/tools/hidden_starts.py), on a made-up Xbox program.
"""
import struct

from conftest import make_xbe

import hidden_starts as H
from sf_binaries import BinaryImage

TEXT, DATA = 0x11000, 0x400000


def u32(v):
    return struct.pack("<I", v)


def rel(op, at, target):
    return bytes([op]) + struct.pack("<i", target - (at + 5))


def program(tmp_path):
    code = bytearray(b"\xCC" * 0x1000)

    def put(at, b):
        code[at:at + len(b)] = b
    table, end = DATA + 0x10, DATA + 0x20
    # the C runtime's loop over the C++ start-up table
    put(0x000, b"\xBE" + u32(table) + b"\x8B\xC6" + b"\xBF" + u32(end) + b"\xC3")
    put(0x100, b"\xC3")                                     # two static initializers
    put(0x110, b"\xC3")
    put(0x200, b"\xFF\x74\x24\x04" + rel(0xE8, TEXT + 0x204, TEXT + 0x280)[0:5] + b"\xC3")    # atexit
    put(0x280, b"\xC3")                                     # _onexit
    for i in range(10):                                     # push stub; call atexit
        at = 0x300 + 16 * i
        put(at, b"\x68" + u32(TEXT + 0x500) + rel(0xE8, TEXT + at + 5, TEXT + 0x200))
    put(0x500, b"\xC3")                                     # the destructor stub
    put(0x600, b"\xB8" + u32(DATA + 0x40) + rel(0xE9, TEXT + 0x605, TEXT + 0x700))   # EH stub
    put(0x650, b"\xC3")                                     # an unwind funclet
    put(0x700, b"\xC3")                                     # __CxxFrameHandler
    data = bytearray(0x100)
    data[0x10:0x20] = u32(0) + u32(TEXT + 0x100) + u32(TEXT + 0x110) + u32(0)
    data[0x40:0x4C] = u32(H.EH_MAGIC) + u32(1) + u32(DATA + 0x60)
    data[0x60:0x68] = u32(0xFFFFFFFF) + u32(TEXT + 0x650)
    path = make_xbe(tmp_path / "default.xbe", [(".text", TEXT, bytes(code), 0x6), (".data", DATA, bytes(data), 0x1)])
    return H.Img(BinaryImage(path))


def test_start_up_table_atexit_stubs_and_eh(tmp_path):
    im = program(tmp_path)
    assert H.initializer_tables(im) == [(DATA + 0x10, DATA + 0x20)]
    assert H.initializers(im) == {TEXT + 0x100, TEXT + 0x110}
    assert H.find_atexit(im) == TEXT + 0x200
    assert H.atexit_stubs(im, TEXT + 0x200) == {TEXT + 0x500}
    assert H.eh(im, TEXT + 0x700) == ({TEXT + 0x600}, {TEXT + 0x650})
