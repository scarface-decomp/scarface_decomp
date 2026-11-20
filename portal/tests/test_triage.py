"""Ranking unmatched functions (portal/tools/triage.py, the examiner's question E13). Made-up code."""
from conftest import make_xbe

import triage as T
from sf_binaries import BinaryImage


def test_easy_wide_reaching_work_first():
    plain = {"x87": 0, "fields": 0, "branches": 0}
    hard = {"x87": 12, "fields": 20, "branches": 10}
    assert T.score(20, plain, False, 0) > T.score(20, hard, False, 0)       # floating point and structs cost
    assert T.score(200, plain, True, 0) > T.score(200, plain, False, 0)     # a matched twin to port
    assert T.score(10, plain, False, 40) > T.score(10, plain, False, 0)     # one body, many classes
    assert T.score(10, plain, False, 0) > T.score(400, plain, False, 0)


def test_features_of_code(tmp_path):
    # fld dword [ecx+8] ; fstp dword [ecx+0Ch] ; call +0 ; jne +0 ; ret
    code = bytes.fromhex("D9 41 08 D9 59 0C E8 00 00 00 00 75 00 C3")
    img = BinaryImage(make_xbe(tmp_path / "t.xbe", [(".text", 0x11000, code, 0x6)]))
    assert T.features(img, 0x11000, len(code)) == {"instructions": 5, "x87": 2, "calls": 1, "branches": 1, "fields": 2}
