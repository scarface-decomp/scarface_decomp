#!/usr/bin/env python3
"""The game's particle effects, read and played the way the game plays them.

Written from the clean-room spec docs/cleanroom/SPEC-010-cutscene-effects-particles-grips.md, section 1:

* a Particle System (0x1580C) has a frame rate (30), a length in its frames, a loop flag and its emitters;
* an Emitter (0x15900) names its shader and holds a mode word (how its particles turn, change picture,
  change colour and follow the emitter), the most particles alive at once, the pictures across its texture,
  a start angle and spread, and how much live particles follow the emitter's movement and turning;
* the emitter's SPEM animation gives its settings over the effect's time (rate, life, speed, size, spin,
  weight, gravity, movement factor, colour, alpha, place, turn), its SPAR animation the curves over a
  particle's life (sampled into twenty steps), and its generator (point 0x15B00, plane 0x15B01, sphere
  0x15B02) where new particles start and which way they go;
* each step the emitter adds the area under its rate between the last frame and this one to a running
  count and makes that many whole particles; each particle then ages, falls by its weight times the
  gravity, moves by its speed times the speed curve, all times the movement factor, and grows by the size
  curve.

Points the spec leaves open, and what is done here until they are settled (marked "(check)" there):
a plane generator's rectangle lies across the forward axis (+Y) and a sphere generator's particles start
anywhere in its ball, both with the point generator's spreads; a looping system's time wraps at its length.

    system = read_system(data, chunk)              # a 0x1580C chunk of a parsed .p3d file
    for p in play(system, frames=30, seed=1): ...  # every particle: its birth frame and its look each frame

Standard library only.
"""

from __future__ import annotations

import math
import random
import sys
from dataclasses import dataclass, field
from pathlib import Path
from typing import Dict, List, Optional, Sequence, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parent))
import anim_sampler as A  # noqa: E402
import p3d  # noqa: E402

SYSTEM, EMITTER, POINT, PLANE, SPHERE, SORT = 0x1580C, 0x15900, 0x15B00, 0x15B01, 0x15B02, 0x122000
GENERATORS = {POINT: "point", PLANE: "plane", SPHERE: "sphere"}
GENERATOR_FLOATS = p3d.PARTICLE_GENERATOR_FLOATS
LIFE_STEPS = 20                        # a particle's life curves are sampled at 0, 5, ... 95 percent
LIFE_FRAMES = 100.0                    # a SPAR animation's length: its frame is the percent of life
FRAMES_A_SECOND = 30.0


# --------------------------------------------------------------------------- reading

def mode_parts(word: int) -> Tuple[int, int, int, int]:
    """An emitter's mode word as its four parts (SPEC-010 section 1.4): turning (0 spin, 1 spin times the
    spin curve, 2 along its movement), texture picture (0 random kept, 1 cycling, 2 from the curve, 3 a new
    random one every picture time), colour (0 kept, 1 colour curve, 2 alpha curve, 3 both) and space (0 stays
    where born, 1 carried with the emitter, 2 turned with it, 3 both)."""
    return p3d.particle_mode(word)


@dataclass
class Generator:
    kind: str                                    # point, plane or sphere
    values: Dict[str, float]                     # the chunk's own floats, by their channel's name
    animation: Optional[A.Animation] = None

    def value(self, name: str, frame: float) -> float:
        got = _first_group(self.animation, name, frame)
        return float(got[0]) if got is not None else float(self.values.get(name, 0.0))


@dataclass
class Emitter:
    name: str
    shader: str
    mode: int
    most: int                                    # the most particles alive at once
    pictures: int                                # pictures side by side across the texture
    picture_time: int                            # frames each picture lasts, for the cycling modes
    angle: float
    angle_spread: float
    follow_move: float
    follow_turn: float
    settings: Optional[A.Animation] = None       # SPEM
    life: Dict[str, List[tuple]] = field(default_factory=dict)   # SPAR, each curve at its twenty steps
    generator: Optional[Generator] = None

    @property
    def parts(self) -> Tuple[int, int, int, int]:
        return mode_parts(self.mode)

    def setting(self, name: str, frame: float, default=None):
        got = _first_group(self.settings, name, frame)
        return got if got is not None else default


@dataclass
class System:
    name: str
    rate: float                                  # its frames a second (30)
    length: int                                  # in its frames
    loops: bool
    emitters: List[Emitter]
    sort: Optional[float] = None


def _first_group(anim: Optional[A.Animation], name: str, frame: float):
    """A channel of an animation's first group, at a frame (the emitter's settings are in its first group)."""
    if anim is None or not anim.groups:
        return None
    channels = next(iter(anim.groups.values()))
    ch = channels.get(name)
    return ch.at(frame) if ch is not None else None


def life_table(anim: A.Animation, name: str) -> Optional[List[tuple]]:
    """A life curve sampled at its twenty steps (0, 5, ... 95 percent of life), or None without it."""
    if not anim.groups:
        return None
    ch = next(iter(anim.groups.values())).get(name)
    if ch is None or not ch.frames:
        return None
    return [ch.at(LIFE_FRAMES * i / LIFE_STEPS) for i in range(LIFE_STEPS)]


def read_emitter(data: bytes, c: p3d.Chunk) -> Emitter:
    f = p3d.fields(data, c)
    e = Emitter(f["name"], f["shader"], f["mode"], max(1, f["most"]), max(1, f["pictures"]), max(1, f["picture time"]),
                f["start angle"], f["angle spread"], f["follow move"], f["follow turn"])
    for k in c.children:
        if k.id == A.ANIMATION:
            anim = A.Animation(data, k)
            if anim.kind.upper() == "SPAR":
                for name in ("SPOL", "SZOL", "SNOL", "WEOL", "COOL", "ALOL", "TEOL"):
                    table = life_table(anim, name)
                    if table is not None:
                        e.life[name] = table
            else:                                            # SPEM
                e.settings = anim
        elif k.id in GENERATORS:
            g = p3d.fields(data, k)
            anim_chunk = k.find(A.ANIMATION)
            e.generator = Generator(GENERATORS[k.id], {n: g[n] for n in GENERATOR_FLOATS[k.id]},
                                    A.Animation(data, anim_chunk) if anim_chunk is not None else None)
    return e


def read_system(data: bytes, c: p3d.Chunk) -> System:
    f = p3d.fields(data, c)
    emitters = [read_emitter(data, k) for k in c.children if k.id == EMITTER]
    sort = c.find(SORT)
    return System(f["name"], f["frame rate"] or FRAMES_A_SECOND, f["length"], f["loops"] == 1, emitters,
                  p3d.fields(data, sort).get("draw order") if sort is not None else None)


def systems(data: bytes, tree: Optional[List[p3d.Chunk]] = None) -> Dict[str, p3d.Chunk]:
    """{name (lower): chunk} of every particle system in a file."""
    tree = p3d.read_tree(data) if tree is None else tree
    out = {}
    for c in p3d.walk(tree):
        if c.id == SYSTEM:
            out.setdefault(p3d.fields(data, c).get("name", "").lower(), c)
    return out


# --------------------------------------------------------------------------- playing

@dataclass
class Look:
    """A particle at one frame: where it is (in the effect's own space), its size (the square's side), its
    turn on screen (radians), its colour (r, g, b, a from 0 to 255) and which picture of the texture."""
    at: Tuple[float, float, float]
    size: float
    angle: float
    rgba: Tuple[int, int, int, int]
    picture: int


@dataclass
class Particle:
    emitter: int
    born: int                                    # the effect's frame it was born at
    looks: List[Look] = field(default_factory=list)   # one each frame from its birth


def area(ch: Optional[A.Channel], a: float, b: float) -> float:
    """What a step from frame a to frame b adds to an emitter's count: the area under a float channel
    (SPEC-010 section 1.7), straight lines between keys (rectangles for a stepped channel). A step that starts
    before the first key counts whole at the first key's value, even the part after that key; one that starts
    at or after the last key counts whole at the last key's value."""
    if ch is None or not ch.frames or b <= a:
        return 0.0
    if a < ch.frames[0]:
        return float(ch.values[0][0]) * (b - a)
    if a >= ch.frames[-1]:
        return float(ch.values[-1][0]) * (b - a)
    cuts = [a] + [float(k) for k in ch.frames if a < k < b] + [b]
    total = 0.0
    for x, y in zip(cuts, cuts[1:]):
        if ch.steps:
            total += float(ch.at(x)[0]) * (y - x)
        else:
            total += (float(ch.at(x)[0]) + float(ch.at(y)[0])) * 0.5 * (y - x)
    return total


def _rate_channel(e: Emitter) -> Optional[A.Channel]:
    if e.settings is None or not e.settings.groups:
        return None
    return next(iter(e.settings.groups.values())).get("RAT")


def _spread(rng: random.Random) -> float:
    return rng.uniform(-1.0, 1.0)


def _turn(q: Sequence[float], v: Sequence[float]) -> Tuple[float, float, float]:
    x, y, z, w = q
    tx, ty, tz = 2 * (y * v[2] - z * v[1]), 2 * (z * v[0] - x * v[2]), 2 * (x * v[1] - y * v[0])
    return (v[0] + w * tx + y * tz - z * ty, v[1] + w * ty + z * tx - x * tz, v[2] + w * tz + x * ty - y * tx)


def _curve(table: Optional[List[tuple]], life: float, blend: bool = True, default: float = 1.0) -> float:
    if not table:
        return default
    x = max(0.0, min(0.999999, life)) * LIFE_STEPS
    i = int(x)
    v = float(table[i][0])
    if blend and i + 1 < len(table):
        v += (float(table[i + 1][0]) - v) * (x - i)
    return v


def _clamp(v: float) -> int:
    return int(max(0, min(255, round(v))))


@dataclass
class _Live:
    emitter: int
    born: int
    age: float
    life: float
    at: List[float]
    velocity: Tuple[float, float, float]
    up: float
    weight: float
    birth_size: float
    size: float
    spin: float
    angle: float
    rgb: Tuple[int, int, int]
    alpha: int
    offset: Tuple[float, float, float, float]    # its own random colour and alpha offset
    picture: int
    record: Particle


def _birth(e: Emitter, n: int, frame: float, born: int, rng: random.Random, size: float, speed: float,
           record: Particle) -> _Live:
    g = e.generator
    hosp = g.value("HOSP", frame) if g else 0.0
    vesp = g.value("VESP", frame) if g else 0.0
    # SPEC-010 section 1.7: forward is the emitter's +Y; each spread is a half-angle, the two independent
    h = math.pi / 2 + _spread(rng) * hosp
    v = math.pi / 2 + _spread(rng) * vesp
    direction = (math.sin(v) * math.cos(h), math.sin(v) * math.sin(h), math.cos(v))
    at = (0.0, 0.0, 0.0)
    if g is not None and g.kind == "plane":                # a rectangle across the forward axis
        at = (g.value("WDT", frame) * 0.5 * _spread(rng), 0.0, g.value("HGT", frame) * 0.5 * _spread(rng))
    elif g is not None and g.kind == "sphere":             # a ball of the radius
        while True:
            p = (_spread(rng), _spread(rng), _spread(rng))
            if sum(c * c for c in p) <= 1.0:
                break
        radius = g.value("RAD", frame)
        at = (p[0] * radius, p[1] * radius, p[2] * radius)
    rdva = g.value("RDVA", frame) if g else 0.0
    if rdva:                                               # a random way along its own direction
        k = rdva * _spread(rng)
        at = (at[0] + direction[0] * k, at[1] + direction[1] * k, at[2] + direction[2] * k)
    place = e.setting("TRA", frame)
    turn = e.setting("ROT", frame)
    if turn is not None:
        direction = _turn(turn, direction)
        at = _turn(turn, at)
    if place is not None:
        at = (at[0] + place[0], at[1] + place[1], at[2] + place[2])

    def num(name: str, default: float = 0.0) -> float:
        v = e.setting(name, frame)
        return float(v[0]) if v is not None else default
    go = (num("SPD") + num("SPDV") * _spread(rng)) * speed
    clr = e.setting("CLR", frame, (255, 255, 255, 255))
    clrv = e.setting("CLRV", frame, (0,))
    if len(clrv) >= 4:                                     # a colour each way
        offset = (clrv[1] * _spread(rng), clrv[2] * _spread(rng), clrv[3] * _spread(rng), num("ALPV") * _spread(rng))
    else:                                                  # one number (the game's files): the same for all three
        shade = float(clrv[0]) * _spread(rng)
        offset = (shade, shade, shade, num("ALPV") * _spread(rng))
    rgb = tuple(_clamp(c + o) for c, o in zip(clr[1:], offset))
    alpha = _clamp(num("ALP", 255.0) + offset[3])
    birth_size = max(0.0, (num("SIZ") + num("SIZV") * _spread(rng)) * size)
    return _Live(n, born, 0.0, max(1.0, num("LIF", 1.0) + num("LIFV") * _spread(rng)), list(at),
                 tuple(c * go for c in direction), 0.0,                # type: ignore[arg-type]
                 num("WGT") + num("WGTV") * _spread(rng), birth_size, birth_size, num("SPI") + num("SPIV") * _spread(rng),
                 e.angle + e.angle_spread * _spread(rng), rgb, alpha, offset,  # type: ignore[arg-type]
                 rng.randrange(e.pictures), record)


def _step(e: Emitter, p: _Live, frame: float, t: float, rng: random.Random) -> bool:
    """Moves a live particle on by t frames (SPEC-010 section 1.8). False once it has died."""
    p.age += t
    if p.age >= p.life:
        return False
    life = p.age / p.life
    turning, picture, colour, _space = e.parts
    gra = e.setting("GRA", frame)
    dra = e.setting("DRA", frame)
    p.up += _curve(e.life.get("WEOL"), life) * p.weight * (float(gra[0]) if gra else 0.0) * t
    k = _curve(e.life.get("SPOL"), life)
    move = (float(dra[0]) if dra else 1.0) * t
    p.at = [p.at[0] + p.velocity[0] * k * move, p.at[1] + (p.velocity[1] * k + p.up) * move,
            p.at[2] + p.velocity[2] * k * move]
    p.size = p.birth_size * _curve(e.life.get("SZOL"), life)
    if turning == 0:
        p.angle += p.spin * t
    elif turning == 1:
        p.angle += p.spin * _curve(e.life.get("SNOL"), life) * t
    else:                                                    # along its movement on screen: left to the drawing
        p.angle = 0.0
    if picture == 1:
        p.picture = int(p.age // e.picture_time) % e.pictures
    elif picture == 2:
        p.picture = int(_curve(e.life.get("TEOL"), life, blend=False, default=p.picture)) % e.pictures
    elif picture == 3 and int(p.age // e.picture_time) != int((p.age - t) // e.picture_time):
        p.picture = rng.randrange(e.pictures)
    i = min(LIFE_STEPS - 1, int(life * LIFE_STEPS))
    if colour in (1, 3) and e.life.get("COOL"):
        c = e.life["COOL"][i]
        p.rgb = tuple(_clamp(v + o) for v, o in zip(c[1:], p.offset[:3]))  # type: ignore[assignment]
    if colour in (2, 3) and e.life.get("ALOL"):
        p.alpha = _clamp(float(e.life["ALOL"][i][0]) + p.offset[3])
    return True


def _look(p: _Live) -> Look:
    return Look((p.at[0], p.at[1], p.at[2]), p.size, p.angle, p.rgb + (p.alpha,), p.picture)  # type: ignore[arg-type]


def play(system: System, frames: Optional[int] = None, seed: int = 0, size: float = 1.0, rate: float = 1.0,
         speed: float = 1.0, most: int = 5000) -> List[Particle]:
    """Every particle the system makes, and how each looks each frame of its life, in the system's frames
    from its start. frames: how long it makes particles (a one-shot's own length by default; a looping one
    wraps its time at its length). size, rate and speed are the game's multipliers (SPEC-010 section 1.9).
    most: no more particles than this in all."""
    rng = random.Random(seed)
    on = system.length if frames is None else frames
    out: List[Particle] = []
    live: List[_Live] = []
    counts = [0.0] * len(system.emitters)
    rates = [_rate_channel(e) for e in system.emitters]
    f = 0
    while f < on or live:
        if f > on + 10 * FRAMES_A_SECOND:                    # nothing lives this long in the game's effects
            break
        if system.loops and system.length > 0:
            frame = float(f % system.length)
        else:
            frame = float(min(f, system.length))
        # those alive move on, and the dead go
        still = []
        for p in live:
            if _step(system.emitters[p.emitter], p, frame, 1.0, rng):
                p.record.looks.append(_look(p))
                still.append(p)
        live = still
        if f < on:
            for n, e in enumerate(system.emitters):
                a, b = frame, frame + 1.0
                if system.loops and system.length > 0 and b > system.length:
                    got = area(rates[n], a, float(system.length)) + area(rates[n], 0.0, b - system.length)
                else:
                    got = area(rates[n], a, b)
                counts[n] += got * rate
                make = int(counts[n])
                counts[n] -= make
                alive = sum(1 for p in live if p.emitter == n)
                make = max(0, min(make, e.most - alive, most - len(out)))
                for _ in range(make):
                    record = Particle(n, f)
                    p = _birth(e, n, frame, f, rng, size, speed, record)
                    record.looks.append(_look(p))
                    out.append(record)
                    live.append(p)
        f += 1
    return out


def main(argv: Optional[List[str]] = None) -> int:
    import argparse
    ap = argparse.ArgumentParser(description="A particle system's particles, as the game makes them.")
    ap.add_argument("file", type=Path)
    ap.add_argument("system", nargs="?", help="the system's name (all of them without one)")
    a = ap.parse_args(argv)
    data = a.file.read_bytes()
    found = systems(data)
    for name, c in found.items():
        if a.system and name != a.system.lower():
            continue
        s = read_system(data, c)
        made = play(s, seed=1)
        last = max((p.born + len(p.looks) for p in made), default=0)
        print(f"{s.name}: {len(s.emitters)} emitters, {s.length} frames, {'loops' if s.loops else 'once'}, "
              f"{len(made)} particles, over after {last} frames")
        for e in s.emitters:
            print(f"  {e.name}: shader {e.shader}, mode {e.mode} {e.parts}, most {e.most}, pictures {e.pictures}, "
                  f"generator {e.generator.kind if e.generator else 'none'}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
