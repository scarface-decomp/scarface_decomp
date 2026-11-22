"""portal/tools/similar.py: instruction-shape tokens, the bounded edit distance and the neighbour search."""

import sys
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "portal" / "tools"))

import similar as SIM  # noqa: E402

pytest.importorskip("capstone")

# mov eax,[esp+4]; add ecx,0x64; push esi; mov esi,[ecx]; ... ; ret 4   (return a 12-byte member by value)
VEC_AT_64 = bytes.fromhex("8B442404 83C164 56 8B31 8BD0 8932 8B7104 897204 8B4908 894A08 5E C20400".replace(" ", ""))
VEC_AT_24 = VEC_AT_64.replace(bytes.fromhex("83C164"), bytes.fromhex("83C124"))
RET_DAT = bytes.fromhex("B8A49D4300C3")          # mov eax, offset DAT; ret


def test_tokens_ignore_registers_offsets_and_addresses():
    assert SIM.tokens(VEC_AT_64) == SIM.tokens(VEC_AT_24)
    assert SIM.tokens(RET_DAT) == ["mov r,i", "ret"]
    assert SIM.tokens(bytes.fromhex("8B442404"))[0] == "mov r,m32s"


def test_memory_operands_say_what_they_are_based_on():
    member = SIM.tokens(bytes.fromhex("8B4118 C3".replace(" ", "")))        # mov eax,[ecx+0x18]: this->m_Field18
    arg = SIM.tokens(bytes.fromhex("8B442404 8B4018 C3".replace(" ", "")))  # mov eax,[esp+4]; mov eax,[eax+0x18]
    glob = SIM.tokens(bytes.fromhex("A13CD18500 8B4018 C3".replace(" ", "")))  # mov eax,[DAT]; mov eax,[eax+0x18]
    call_imp = SIM.tokens(bytes.fromhex("FF1528F07200"))                   # call [import]
    call_vt = SIM.tokens(bytes.fromhex("FF5004"))                          # call [eax+4]: a virtual call
    assert member == ["mov r,m32", "ret"]
    assert arg[0] == "mov r,m32s" and glob[0] == "mov r,m32a" and arg[1] == glob[1] == "mov r,m32"
    assert call_imp == ["call m32a"] and call_vt == ["call m32"]
    assert SIM.tokens(bytes.fromhex("8B4508"))[0] == "mov r,m32s"           # mov eax,[ebp+8]


@pytest.mark.parametrize("a,b", [("kitten", "sitting"), ("", "abc"), ("abc", "abc"), ("flaw", "lawn")])
def test_distance_matches_the_textbook(a, b, monkeypatch):
    import builtins
    real = builtins.__import__

    def no_rapidfuzz(name, *args, **kw):              # check the pure-Python fallback too
        if name.startswith("rapidfuzz"):
            raise ImportError
        return real(name, *args, **kw)

    want = {("kitten", "sitting"): 3, ("", "abc"): 3, ("abc", "abc"): 0, ("flaw", "lawn"): 2}[(a, b)]
    assert SIM.distance([ord(c) for c in a], [ord(c) for c in b]) == want
    monkeypatch.setattr(builtins, "__import__", no_rapidfuzz)
    assert SIM.distance([ord(c) for c in a], [ord(c) for c in b]) == want
    assert SIM.distance([ord(c) for c in a], [ord(c) for c in b], limit=want) == want
    if want:
        assert SIM.distance([ord(c) for c in a], [ord(c) for c in b], limit=want - 1) == want


def test_similarity_floor_cuts_off():
    assert SIM.similarity([1, 2, 3, 4], [1, 2, 3, 4]) == 1.0
    assert SIM.similarity([1, 2, 3, 4], [1, 2, 9, 4]) == 0.75
    assert SIM.similarity([1, 2, 3, 4], [9, 9, 9, 9], floor=0.5) == 0.0


def test_nearest_prefers_the_same_shape_and_skips_itself():
    idx = SIM.Index({}, [])
    items = []
    for key, code in (("xb:0x00000024", VEC_AT_24), ("xb:0x00000099", RET_DAT), ("xb:0x00000064", VEC_AT_64)):
        seq = idx.encode(SIM.tokens(code), grow=True)
        items.append({"key": key, "symbol": key, "size": len(code), "seq": seq, "ported": 0, "digest": key})
    idx = SIM.Index(idx.vocab, items)
    got = idx.nearest(idx.encode(SIM.tokens(VEC_AT_64)), k=3, exclude=["xb:0x00000064"], floor=0.5)
    assert [it["key"] for _, it in got] == ["xb:0x00000024"] and got[0][0] == 1.0
