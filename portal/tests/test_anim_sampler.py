"""The animation sampler (portal/tools/anim_sampler.py): clean-room spec SPEC-005, sections 1.1 to 1.3."""
import math
import struct

import pytest

import anim_sampler as A
import p3d as P
from test_p3d import chunk, p3d, text


def channel(cid, parameter, frames, values, step=False, before=b""):
    """A channel chunk: frames, then each key's numbers packed with the format for its kind."""
    fmt = {0x121100: "f", 0x121101: "2f", 0x121104: "3f", 0x121105: "4f", 0x121102: "f", 0x121103: "2f"}[cid]
    body = struct.pack("<I", 0) + parameter.encode().ljust(4, b"\0") + before + struct.pack("<I", len(frames))
    body += struct.pack(f"<{len(frames)}H", *frames) + b"".join(struct.pack("<" + fmt, *v) for v in values)
    kids = chunk(0x121110, struct.pack("<II", 0, 0)) if step else b""
    return chunk(cid, body, kids)


def animation(name, groups, frames=30.0, rate=30.0, cyclic=0):
    made = b"".join(chunk(0x121001, struct.pack("<I", 0) + text(g) + struct.pack("<II", 0, 1), b"".join(chs))
                    for g, chs in groups)
    return chunk(0x121000, struct.pack("<I", 0) + text(name) + b"PTRN" + struct.pack("<ffI", frames, rate, cyclic),
                 chunk(0x121002, struct.pack("<II", 0, len(groups)), made))


def load(*chunks):
    data = p3d(*chunks)
    return A.animations(data)


def test_before_between_and_after_the_keys():
    (a,) = load(animation("move", [("Hip", [channel(0x121104, "TRAN", [10, 20], [(0, 0, 0), (10, 20, -30)])])]))
    assert a.value("Hip", "TRAN", 0) == (0, 0, 0)                 # before the first key: its value
    assert a.value("Hip", "TRAN", 15) == pytest.approx((5, 10, -15))
    assert a.value("Hip", "TRAN", 12.5) == pytest.approx((2.5, 5, -7.5))
    assert a.value("Hip", "TRAN", 29) == (10, 20, -30)             # after the last: its value
    assert a.value("hIP", "TRAN", 20) == (10, 20, -30)             # a group is found by the game's name key
    assert a.value("Hip", "ROT", 5) is None and a.value("Knee", "TRAN", 5) is None


def test_a_channel_told_not_to_blend_steps():
    (a,) = load(animation("blink", [("Lid", [channel(0x121100, "VAL", [0, 10, 20], [(1,), (5,), (9,)], step=True)])]))
    assert [a.value("Lid", "VAL", f) for f in (0, 9.9, 10, 19, 20, 25)] == [(1,), (1,), (5,), (5,), (9,), (9,)]
    assert a.channel("Lid", "VAL").steps


def test_a_quaternion_turns_the_shorter_way():
    half = math.sqrt(0.5)
    # the same turn written with the opposite sign at the next key, as the game's sun has between frames 153 and 154
    keys = [(0.0, 0.0, 0.0, 1.0), (0.0, -half, 0.0, -half)]
    (a,) = load(animation("sun", [("sun_grp", [channel(0x121105, "ROT", [153, 154], keys)])], frames=241, cyclic=1))
    mid = a.value("sun_grp", "ROT", 153.5)
    assert mid == pytest.approx((0.0, math.sin(math.pi / 8), 0.0, math.cos(math.pi / 8)))     # a quarter turn's half
    assert sum(x * x for x in mid) == pytest.approx(1.0)
    assert sum(x * y for x, y in zip(mid, keys[0])) > 0.9          # it stays by the first key: not the long way round
    assert A.slerp((0, 0, 0, 1), (0, 0, 0, -1), 0.3) == pytest.approx((0, 0, 0, 1))   # the same turn: nothing moves
    near = A.slerp((0, 0, 0, 1), (0, 0.01, 0, math.sqrt(1 - 0.0001)), 0.5)             # almost the same: a straight blend
    assert near == pytest.approx((0, 0.005, 0, 1.0), abs=1e-4) and sum(x * x for x in near) == pytest.approx(1.0)


def test_looping_wraps_and_playing_once_clamps():
    once, = load(animation("door", [("Door", [channel(0x121100, "VAL", [0, 20], [(0,), (20,)])])], frames=21))
    assert [once.value("Door", "VAL", f) for f in (-5, 10, 21, 99)] == [(0,), (10,), (20,), (20,)]
    loop, = load(animation("fan", [("Fan", [channel(0x121100, "VAL", [0, 20], [(0,), (20,)])])], frames=20, cyclic=1))
    assert loop.value("Fan", "VAL", 25) == (5,) and loop.value("Fan", "VAL", -5) == (15,)       # round and round
    assert loop.frame_at(seconds=1.0) == pytest.approx(10.0) and once.frame_at(seconds=5.0) == 21.0
    assert A.wrap(5, 0, True) == 0.0


def test_a_boolean_channel_flips_at_each_key():
    on = chunk(0x121108, struct.pack("<I", 0) + b"VIS\0" + struct.pack("<HI2H", 1, 2, 10, 20))
    off = chunk(0x121108, struct.pack("<I", 0) + b"GLOW" + struct.pack("<HI1H", 0, 1, 5))
    (a,) = load(animation("lamp", [("Lamp", [on, off])]))
    assert [a.value("Lamp", "VIS", f) for f in (0, 9, 10, 19, 20, 30)] == [True, True, False, False, True, True]
    assert [a.value("Lamp", "GLOW", f) for f in (0, 5, 30)] == [False, True, True]


def test_the_other_kinds_of_channel():
    one = channel(0x121102, "TRAN", [0, 10], [(0,), (4,)], before=struct.pack("<H3f", 1, 7.0, 0.0, 9.0))     # only y moves
    two = channel(0x121103, "SCAL", [0, 10], [(0, 0), (2, 6)], before=struct.pack("<H3f", 0, 5.0, 0.0, 0.0))  # x stays
    colour = chunk(0x121109, struct.pack("<I", 0) + b"CLR\0" + struct.pack("<I2H2I", 2, 0, 10, 0xFF000000, 0xFF64C8FF))
    whole = chunk(0x12110E, struct.pack("<I", 0) + b"VRTX" + struct.pack("<I2H2I", 2, 0, 10, 2, 4))
    shown = chunk(0x121107, struct.pack("<I", 0) + b"TEX\0" + struct.pack("<I2H", 2, 0, 10) + text("a.bmp") + text("b.bmp"))
    shift = channel(0x121101, "OFF", [0, 10], [(0, 0), (1, 0.5)])
    (a,) = load(animation("mix", [("Thing", [one, two, colour, whole, shown, shift])]))
    assert a.value("Thing", "TRAN", 5) == pytest.approx((7.0, 2.0, 9.0))          # the constants fill what doesn't move
    assert a.value("Thing", "SCAL", 5) == pytest.approx((5.0, 1.0, 3.0))
    assert a.value("Thing", "CLR", 5) == pytest.approx((255, 50, 100, 127.5))     # each byte on its own
    assert a.value("Thing", "VRTX", 5) == pytest.approx((3.0,))                   # integers blend as floats
    assert [a.value("Thing", "TEX", f) for f in (0, 9, 10)] == ["a.bmp", "a.bmp", "b.bmp"]      # the last name at or before
    assert a.value("Thing", "OFF", 5) == pytest.approx((0.5, 0.25))


def test_what_an_animation_says_about_itself():
    (a,) = load(animation("PTRN_sky", [("sun", [channel(0x121100, "VAL", [0], [(1,)])])], frames=241.0, rate=30.0, cyclic=1))
    assert (a.name, a.kind, a.length, a.rate, a.loops) == ("PTRN_sky", "PTRN", 241.0, 30.0, True)
