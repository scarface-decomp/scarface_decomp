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


def test_functions_reached_only_by_a_closing_jump(tmp_path):
    code = bytearray(b"\xCC" * 0x400)

    def put(at, b):
        code[at:at + len(b)] = b
    put(0x000, b"\xB8\x01\x00\x00\x00" + rel(0xE9, TEXT + 0x005, TEXT + 0x040))      # a known function ends in a jump
    put(0x040, b"\x33\xC0\xC3")                                                      # ... to this one, found
    put(0x080, b"\x90" + rel(0xE9, TEXT + 0x081, TEXT + 0x0C4))                      # target not on a 16-byte line
    put(0x0C4, b"\xC3")
    # the target follows an instruction that only ends in the byte CC: a jump inside one function
    put(0x100, b"\x90" + rel(0xE9, TEXT + 0x101, TEXT + 0x140) + b"\x90" * 0x37 + b"\x8B\x45\xCC" + b"\xC3")
    put(0x180, b"\x90" + rel(0xE9, TEXT + 0x181, TEXT + 0x000))                      # target already known
    # the bytes E9 xx xx xx xx inside a `mov eax, value`: not an instruction
    put(0x1C0, b"\xB8" + rel(0xE9, TEXT + 0x1C1, TEXT + 0x200)[:4] + b"\x90\xC3")
    put(0x200, b"\xC3")
    put(0x240, rel(0xE9, TEXT + 0x240, TEXT + 0x280))                                # the jump is in no known function
    put(0x280, b"\xC3")
    path = make_xbe(tmp_path / "default.xbe", [(".text", TEXT, bytes(code), 0x6), (".data", DATA, bytes(16), 0x1)])
    im = H.Img(BinaryImage(path))
    known = {TEXT + 0x000, TEXT + 0x080, TEXT + 0x100, TEXT + 0x180, TEXT + 0x1C0}
    assert H.closing_jump_targets(im, known, set()) == {TEXT + 0x040: TEXT + 0x000}
    # a library function's jumps are not followed, and nothing inside a library's stretch is taken
    assert H.closing_jump_targets(im, known, {TEXT + 0x000}) == {}


def test_functions_whose_address_is_only_handed_on(tmp_path):
    code = bytearray(b"\xCC" * 0x400)

    def put(at, b):
        code[at:at + len(b)] = b
    put(0x000, b"\x68" + u32(TEXT + 0x040) + b"\xC3")                    # push offset f: found
    put(0x040, b"\x33\xC0\xC3")
    put(0x080, b"\xC7\x46\x08" + u32(TEXT + 0x0C0) + b"\xC3")            # mov [esi+8], offset f: found
    put(0x0C0, b"\x33\xC0\xC3")
    put(0x100, b"\x68" + u32(TEXT + 0x144) + b"\xC3")                    # target not on a 16-byte line
    put(0x144, b"\xC3")
    put(0x180, b"\x68" + u32(TEXT + 0x000) + b"\xC3")                    # target already known
    put(0x1C0, b"\x3D" + u32(TEXT + 0x200) + b"\xC3")                    # cmp eax, value: not handed on
    put(0x200, b"\xC3")
    put(0x240, b"\x68" + u32(TEXT + 0x280) + b"\xC3")                    # the push is in no known function
    put(0x280, b"\xC3")
    # the address is the middle of an instruction's bytes, not its last four
    put(0x2C0, b"\xC7\x05" + u32(TEXT + 0x300) + u32(1) + b"\xC3")
    put(0x300, b"\xC3")
    path = make_xbe(tmp_path / "default.xbe", [(".text", TEXT, bytes(code), 0x6), (".data", DATA, bytes(16), 0x1)])
    im = H.Img(BinaryImage(path))
    known = {TEXT + 0x000, TEXT + 0x080, TEXT + 0x100, TEXT + 0x180, TEXT + 0x1C0, TEXT + 0x2C0}
    assert H.address_taken_targets(im, known, set()) == {TEXT + 0x040: TEXT + 0x000, TEXT + 0x0C0: TEXT + 0x080}
    # nothing a library function hands on is taken
    assert H.address_taken_targets(im, known, {TEXT + 0x000, TEXT + 0x080}) == {}
