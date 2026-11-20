"""Child-chunk dispatch loops (portal/tools/chunk_dispatch.py, the examiner's question F3), on made-up code
shaped like the compiler's switch lowering."""
import struct

from conftest import make_xbe

import chunk_dispatch as D
from sf_binaries import BinaryImage

TEXT = 0x11000


def rel(at, to):
    return struct.pack("<i", to - (at + 5))


def program(tmp_path):
    """At 0x11000: call current_id (0x11400); cmp eax, 0x121201; ja L2; je CASE_FC; sub eax, 0x10003;
    je CASE_BOX; dec eax; jne DEFAULT; (CASE_SPHERE) ... L2: cmp eax, 0x122000; je CASE_SORT; ret.
    At 0x11100: a jump table: call current_id; sub eax, 0x15B00; cmp eax, 2; ja DEFAULT; jmp [eax*4+table]."""
    code = bytearray(b"\xCC" * 0x500)

    def put(at, raw):
        code[at - TEXT:at - TEXT + len(raw)] = raw
    a = TEXT
    put(a, b"\xE8" + rel(a, 0x11400))                                   # call current_id
    put(a + 5, b"\x3D" + struct.pack("<I", 0x121201))                   # cmp eax, 0x121201
    put(a + 10, b"\x77" + bytes([0x30 - 12]))                           # ja +  -> 0x11030
    put(a + 12, b"\x74" + bytes([0x50 - 14]))                           # je    -> 0x11050 (frame controller)
    put(a + 14, b"\x2D" + struct.pack("<I", 0x10003))                   # sub eax, 0x10003
    put(a + 19, b"\x74" + bytes([0x60 - 21]))                           # je    -> 0x11060 (bounding box)
    put(a + 21, b"\x48")                                                # dec eax
    put(a + 22, b"\x75" + bytes([0x80 - 24]))                           # jne   -> 0x11080 (default)
    put(a + 24, b"\xE8" + rel(a + 24, 0x11410) + b"\xC3")               # bounding sphere: call
    put(a + 0x30, b"\x3D" + struct.pack("<I", 0x122000) + b"\x74" + bytes([0x70 - 0x37]) + b"\xC3")
    put(a + 0x50, b"\xE8" + rel(a + 0x50, 0x11420) + b"\xC3")
    put(a + 0x60, b"\xC3")
    put(a + 0x70, b"\xC3")
    put(a + 0x80, b"\xC3")
    b = TEXT + 0x100
    put(b, b"\xE8" + rel(b, 0x11400))
    put(b + 5, b"\x2D" + struct.pack("<I", 0x15B00))                    # sub eax, 0x15B00
    put(b + 10, b"\x83\xF8\x02")                                        # cmp eax, 2
    put(b + 13, b"\x77" + bytes([0x40 - 15]))                           # ja default
    put(b + 15, b"\xFF\x24\x85" + struct.pack("<I", 0x30000))           # jmp [eax*4 + 0x30000]
    for i, t in enumerate((0x11120, 0x11128, 0x11130)):
        put(t, b"\xC3")
    put(0x11140, b"\xC3")
    put(0x11400, b"\x33\xC0\xC3")
    put(0x11410, b"\xC3")
    put(0x11420, b"\xC3")
    table = struct.pack("<3I", 0x11120, 0x11128, 0x11130)
    return BinaryImage(make_xbe(tmp_path / "t.xbe", [(".text", TEXT, bytes(code), 0x6), (".rdata", 0x30000, table, 0x2)]))


def test_a_compare_and_subtract_chain(tmp_path):
    img = program(tmp_path)
    found = {d.site: d for d in D.dispatches(img, 0x11400)}
    one = found[TEXT]
    assert [(c.id, c.at) for c in one.cases] == [(0x10003, 0x11060), (0x10004, 0x11018), (0x121201, 0x11050),
                                                 (0x122000, 0x11070)]
    assert [c.calls for c in one.cases if c.id == 0x121201] == [[0x11420]]


def test_a_jump_table(tmp_path):
    img = program(tmp_path)
    found = {d.site: d for d in D.dispatches(img, 0x11400)}
    two = found[TEXT + 0x100]
    assert [(c.id, c.at) for c in two.cases] == [(0x15B00, 0x11120), (0x15B01, 0x11128), (0x15B02, 0x11130)]
