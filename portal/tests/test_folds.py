"""Folded functions (portal/tools/folds.py, the examiner's question E2): one body in several classes'
vtables. A made-up program."""
import struct

from conftest import make_xbe

import folds as F
from sf_binaries import BinaryImage


def test_a_body_in_two_classes_vtables_is_folded(tmp_path):
    rdata = bytearray(0x200)
    for at, raw in ((0x00, b".?AVOne@@"), (0x40, b".?AVTwo@@")):
        rdata[at + 8:at + 8 + len(raw) + 1] = raw + b"\0"
    struct.pack_into("<5I", rdata, 0x80, 0, 0, 0, 0x30000, 0)
    struct.pack_into("<5I", rdata, 0xA0, 0, 0, 0, 0x30040, 0)
    struct.pack_into("<4I", rdata, 0xC0, 0x30080, 0x11000, 0x11010, 0)      # One: shared, its own
    struct.pack_into("<3I", rdata, 0xD0, 0x300A0, 0x11000, 0)               # Two: shared
    text = b"\xC3" + b"\xCC" * 15 + b"\x33\xC0\xC3" + b"\xCC" * 13
    img = BinaryImage(make_xbe(tmp_path / "t.xbe", [(".text", 0x11000, text, 0x6), (".rdata", 0x30000, bytes(rdata), 0x2)]))
    assert F.folded(img) == {0x11000: [("One", 0), ("Two", 0)]}
