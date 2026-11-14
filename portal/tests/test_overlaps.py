"""Functions whose bytes run over the start of another one: which of the two is wrong (sf_binaries.settle_overlaps)."""
from conftest import make_xbe

import queue_builder as QB
import sf_binaries as SB

TEXT = 0x11000


def image(tmp_path):
    code = bytearray(b"\xCC" * 0x200)

    def put(at, data):
        code[at:at + len(data)] = data

    put(0x00, bytes.fromhex("83E904E938000000"))        # 0x11000  sub ecx, 4; jmp 0x11040: a thunk
    put(0x10, bytes.fromhex("33C0C3"))                  # 0x11010  xor eax, eax; ret      (in a virtual table)
    put(0x40, bytes.fromhex("8BC1C3"))                  # 0x11040  mov eax, ecx; ret      (only the thunk jumps here)
    put(0x100, bytes.fromhex("68C283C000" "33C0C3"))    # 0x11100  push 0x00C083C2; xor eax, eax; ret
    put(0x180, bytes.fromhex("B801000000" "C3"))        # 0x11180  mov eax, 1; ret
    p = make_xbe(tmp_path / "t.xbe", [(".text", TEXT, bytes(code), 0x6), (".data", 0x30000, b"\0" * 16, 0x7)])
    return SB.BinaryImage(p)


def test_a_thunk_measured_over_the_next_function_is_measured_again(tmp_path):
    img = image(tmp_path)
    assert SB.function_extent(img, 0x11000, set()).size == 0x43          # it followed the jump into 0x11040
    sizes = {0x11000: 0x43, 0x11010: 3, 0x11040: 3}
    new, drop = SB.settle_overlaps(img, sizes, certain={0x11010}, called=set(), proven=set())
    assert new == {0x11000: 8} and drop == set()
    # nothing vouches for 0x11010: it is left alone;  a size an exact match proved is never changed
    assert SB.settle_overlaps(img, sizes, set(), set(), set()) == ({}, set())
    assert SB.settle_overlaps(img, sizes, {0x11010}, set(), proven={0x11000}) == ({}, set())
    # a call target standing right after padding is as good as a table entry
    assert SB.settle_overlaps(img, sizes, set(), called={0x11010}, proven=set())[0] == {0x11000: 8}


def test_a_start_in_the_middle_of_an_instruction_is_not_a_function(tmp_path):
    img = image(tmp_path)
    assert SB.instruction_starts(img, 0x11100, 8) == {0x11100: 5, 0x11105: 2, 0x11107: 1}
    sizes = {0x11100: 8, 0x11101: 3, 0x11180: 6}
    new, drop = SB.settle_overlaps(img, sizes, certain=set(), called={0x11101}, proven=set())
    assert (new, drop) == ({}, {0x11101})
    # ... unless something vouches for it: a virtual table, or an exact match
    assert SB.settle_overlaps(img, sizes, {0x11101}, set(), set())[1] == set()
    assert SB.settle_overlaps(img, sizes, set(), {0x11101}, proven={0x11101})[1] == set()
    # a start on an instruction of the function around it is left alone (it may be a second way in)
    assert SB.settle_overlaps(img, {0x11100: 8, 0x11105: 3}, set(), {0x11105}, set()) == ({}, set())


def test_an_older_queue_is_settled_once(tmp_path):
    img = image(tmp_path)

    def task(va, size, **more):
        return dict({"id": f"xb_{va:08X}", "bin": "xb", "fva_int": va, "size": size, "hint": f"Called directly; {size} bytes.",
                     "lookalikes": 0, "lookalike_group": "g"}, **more)

    tasks = [task(0x11000, 0x43), task(0x11010, 3), task(0x11040, 3), task(0x11100, 8), task(0x11101, 3), task(0x11180, 6)]
    said = []
    # 0x11010 is matched already (proven): the thunk ends before it
    kept = QB.settle_queue(tasks, {"xb": img}, {"xb:0x00011010"}, progress=said.append)
    by = {t["fva_int"]: t for t in kept}
    assert sorted(by) == [0x11000, 0x11010, 0x11040, 0x11100, 0x11180]
    assert by[0x11000]["size"] == 8 and by[0x11000]["hint"] == "Called directly; 8 bytes." and by[0x11000]["tier"] == "TIER_1_QUICK"
    assert all("lookalikes" not in t for t in kept)                      # the look-alike groups are worked out again
    assert "1 functions measured again" in said[0] and "1 false starts" in said[0]
    again = QB.settle_queue(kept, {"xb": img}, {"xb:0x00011010"})
    assert [t["size"] for t in again] == [t["size"] for t in kept] and len(again) == len(kept)
