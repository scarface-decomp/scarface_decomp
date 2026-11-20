"""Particle systems (portal/tools/particles.py): clean-room spec SPEC-010, section 1. Every file here is made
up; nothing comes from the game."""
import struct

import pytest

import particles as PS
import p3d as P
from test_anim_sampler import channel
from test_p3d import chunk, p3d, text


def anim(kind, channels, frames=30.0):
    group = chunk(0x121001, struct.pack("<I", 0) + text("grp") + struct.pack("<II", 0, len(channels)), b"".join(channels))
    return chunk(0x121000, struct.pack("<I", 0) + text("a") + kind.encode() + struct.pack("<ffI", frames, 30.0, 0),
                 chunk(0x121002, struct.pack("<II", 0, 1), group))


def colour(param, frames, argb):
    body = struct.pack("<I", 0) + param.encode().ljust(4, b"\0") + struct.pack("<I", len(frames))
    return chunk(0x121109, body + struct.pack(f"<{len(frames)}H", *frames) + struct.pack(f"<{len(argb)}I", *argb))


def emitter(name="fx_FlareShape", shader="flare", mode=60, most=10, pictures=1, settings=(), life=(), gen=None):
    head = struct.pack("<I", 0) + text(name) + text(shader) + struct.pack("<7I", mode, 1, 0, most, 0, pictures, 1)
    head += struct.pack("<4f", 0.0, 0.0, 1.0, 1.0)
    kids = anim("SPEM", list(settings)) + (anim("SPAR", list(life), 100.0) if life else b"")
    kids += gen if gen is not None else chunk(PS.POINT, struct.pack("<I3f", 0, 0.0, 0.0, 0.0))
    return chunk(PS.EMITTER, head, kids)


def system(emitters, length=5, loops=0, name="fxSys_TestShape"):
    head = struct.pack("<I", 0) + text(name) + struct.pack("<fII", 30.0, length, loops)
    head += struct.pack("<4f3fI", 0, 0, 0, -1, 0, 0, 0, len(emitters))
    return chunk(PS.SYSTEM, head, b"".join(emitters) + chunk(PS.SORT, struct.pack("<If", 0, 0.5)))


def read(*emitters, **kw):
    data = p3d(system(list(emitters), **kw))
    return PS.read_system(data, P.read_tree(data)[0])


def test_the_mode_word_in_four_parts():
    assert PS.mode_parts(60) == (0, 0, 1, 1)               # the pistol's flare: coloured over life, carried
    assert PS.mode_parts(24) == (0, 0, 2, 0)               # its smoke: fades by alpha, stays put
    assert PS.mode_parts(33) == (0, 3, 2, 0)
    assert PS.mode_parts(2 + 3 * (1 + 4 * 3 + 16 * 2)) == (2, 1, 3, 2)


def test_reading_a_system_and_its_emitter():
    s = read(emitter(settings=[channel(0x121100, "RAT", [0], [(2.0,)])]), length=5)
    assert (s.name, s.rate, s.length, s.loops, s.sort) == ("fxSys_TestShape", 30.0, 5, False, 0.5)
    (e,) = s.emitters
    assert (e.name, e.shader, e.mode, e.most, e.pictures) == ("fx_FlareShape", "flare", 60, 10, 1)
    assert (e.follow_move, e.follow_turn) == (1.0, 1.0)
    assert e.generator.kind == "point" and e.settings is not None


def test_the_count_is_the_area_under_the_rate():
    # 50 at frame 4, 0 at frame 5: half of 50 over that one frame
    rat = channel(0x121100, "RAT", [4, 5], [(50.0,), (0.0,)])
    lif = channel(0x121100, "LIF", [0], [(3.0,)])
    s = read(emitter(most=1000, settings=[rat, lif]), length=10)
    made = PS.play(s, seed=1)
    assert len(made) == 25 + 50 * 4                         # and before the first key it holds 50
    s = read(emitter(most=10, settings=[rat, lif]), length=10)
    assert len(PS.play(s, seed=1)) <= 10 + 30               # never more alive than the emitter's limit


def test_particles_age_fall_and_die():
    settings = [channel(0x121100, "RAT", [0, 1], [(2.0,), (0.0,)]), channel(0x121100, "LIF", [0], [(4.0,)]),
                channel(0x121100, "SPD", [0], [(1.0,)]), channel(0x121100, "WGT", [0], [(1.0,)]),
                channel(0x121100, "GRA", [0], [(-0.5,)]), channel(0x121100, "SIZ", [0], [(2.0,)])]
    s = read(emitter(settings=settings), length=1)
    (p,) = PS.play(s, seed=3)
    assert len(p.looks) == 4                                # born, then three steps: dead at age 4
    assert p.looks[0].at == (0.0, 0.0, 0.0)
    assert p.looks[1].at == pytest.approx((0.0, 0.5, 0.0), abs=1e-9)  # forward (+Y) by its speed, down by its weight
    assert p.looks[2].at == pytest.approx((0.0, 0.5, 0.0), abs=1e-9)  # falling now as fast as it goes up
    assert all(look.size == 2.0 for look in p.looks)


def test_life_curves_size_and_alpha():
    settings = [channel(0x121100, "RAT", [0, 1], [(2.0,), (0.0,)]), channel(0x121100, "LIF", [0], [(10.0,)]),
                channel(0x121100, "SIZ", [0], [(1.0,)])]
    life = [channel(0x121100, "SZOL", [0, 100], [(1.0,), (3.0,)]),
            colour("COOL", [0, 50], [0xFFFF0000, 0xFF0000FF])]
    s = read(emitter(mode=3 * 4, settings=settings, life=life), length=1)   # colour from the curve
    (p,) = PS.play(s, seed=1)
    assert p.looks[5].size == pytest.approx(1.0 + 2.0 * 0.5)
    assert p.looks[1].rgba[:3] == (204, 0, 51)              # the curve at 10 percent: a fifth of the way
    assert p.looks[9].rgba[:3] == (0, 0, 255)               # past half its life: the second key's colour


def test_a_looping_system_goes_on_for_as_long_as_asked():
    settings = [channel(0x121100, "RAT", [0], [(1.0,)]), channel(0x121100, "LIF", [0], [(2.0,)])]
    s = read(emitter(settings=settings), length=5, loops=1)
    assert s.loops
    assert len(PS.play(s, frames=30, seed=1)) == 30
    assert len(PS.play(s, frames=30, seed=1, rate=0.0)) == 0   # the rate multiplier at 0 stops it


def test_a_sphere_generator_starts_particles_on_the_sphere():
    gen = chunk(PS.SPHERE, struct.pack("<I2f", 0, 2.0, 0.0))
    settings = [channel(0x121100, "RAT", [0, 1], [(20.0,), (0.0,)]), channel(0x121100, "LIF", [0], [(2.0,)])]
    s = read(emitter(most=50, settings=settings, gen=gen), length=1)
    for p in PS.play(s, seed=2):
        assert sum(c * c for c in p.looks[0].at) <= 4.0 + 1e-9    # anywhere in the ball


def test_the_rate_is_held_flat_outside_its_keys():
    rat = PS.A.Channel(*_one_channel(channel(0x121100, "RAT", [4, 5], [(50.0,), (0.0,)])))
    assert PS.area(rat, 0.0, 1.0) == 50.0                     # before the first key: its value, the whole step
    assert PS.area(rat, 3.5, 4.5) == 50.0                     # even the part after the key
    assert PS.area(rat, 4.0, 5.0) == 25.0                     # between keys: straight lines
    assert PS.area(rat, 5.0, 6.0) == 0.0                      # at or after the last: its value


def _one_channel(made):
    data = p3d(made)
    return data, P.read_tree(data)[0]


def test_a_spray_goes_up_the_emitters_y_within_its_half_angles():
    import math
    gen = chunk(PS.POINT, struct.pack("<I3f", 0, 0.1745, 0.1745, 0.0))
    settings = [channel(0x121100, "RAT", [0], [(40.0,)]), channel(0x121100, "LIF", [0], [(2.0,)]),
                channel(0x121100, "SPD", [0], [(1.0,)])]
    s = read(emitter(most=100, settings=settings, gen=gen), length=1)
    ways = [p.looks[1].at for p in PS.play(s, seed=5)]
    assert len(ways) == 40
    for x, y, z in ways:
        assert y > math.cos(0.1745 * math.sqrt(2)) - 1e-6         # within 10 degrees each way, of up
        assert abs(math.atan2(x, y)) <= 0.1745 + 1e-6 and abs(math.atan2(z, y)) <= 0.1745 + 0.02


def test_one_steps_particles_are_spread_along_the_emitters_way():
    settings = [channel(0x121100, "RAT", [0], [(4.0,)]), channel(0x121100, "LIF", [0], [(9.0,)]),
                channel(0x121104, "TRA", [0, 1], [(0.0, 0.0, 0.0), (4.0, 0.0, 0.0)])]
    s = read(emitter(most=100, settings=settings), length=1)
    xs = sorted(round(p.looks[0].at[0], 3) for p in PS.play(s, seed=1) if p.born == 0)
    assert xs == [1.0, 2.0, 3.0, 4.0]                       # a quarter of the way, half, three quarters, there
