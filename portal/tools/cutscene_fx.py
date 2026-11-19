#!/usr/bin/env python3
"""The game's particle effects in a cutscene's glTF: blood, gun fire, smoke, fire, debris and blood pools.

Written from the clean-room spec docs/cleanroom/SPEC-010-cutscene-effects-particles-grips.md:

* every effect is in packages/z04/Common.p3d, as a particle system (`<x>Shape`) or as a composite drawable
  whose parts are particle systems (`<x>`, what prop states name: section 1.1);
* a cutscene's NISCharacterEffect plays the system of its type (section 2.1) at the target's joint (the
  head for a headshot), turned to face away from the source's neck (section 2.2); a blood pool is a
  growing decal under the character (section 4.2);
* each shot of a gun plays the effects of the gun prop's "fire1" state (or "fire2" for alternate fire) at
  their offsets, a shot every FiringRate milliseconds from the weapon's template, with a tracer every
  TracerFrequency-th shot (section 3.2).

Each particle is played by particles.py and put in as its own small square: a node keyed every frame of
its life (where, how big, its turn on screen) and shrunk to nothing outside it, its colour and alpha over
life in its extras ("colours": seconds, r, g, b, a, seconds, r, g ...: five numbers a key, colours 0 to 1)
and "billboard": true. The Blender
script turns those squares to face the camera and plays the colours.
"""

from __future__ import annotations

import math
import re
import sys
from pathlib import Path
from typing import Callable, Dict, List, Optional, Sequence, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parent))
import p3d  # noqa: E402
import p3d_gltf as G  # noqa: E402
import particles as PS  # noqa: E402

FRAMES_A_SECOND = 30.0
GONE = (1e-4, 1e-4, 1e-4)
JUST_BEFORE = 1e-3                     # seconds: a particle appears and goes this sharply
MOST_PARTICLES = 40000                 # in one scene, past which effects are left out (and counted)
MOST_LOOPING = 10 * 30                 # frames a looping effect (a fire) is played when nothing stops it
MOST_WOUND_DOWN = 60 * 30              # and the longest it is played when something does
PARTICLE_PART = 4                      # a composite drawable's part of this kind is a particle system

# SPEC-010 section 2.1: an NISCharacterEffect's type -> its particle system and the size given to it
# (None: a blood pool, a decal). Gore and grenade sizes weren't found: 1.
CHARACTER_EFFECTS = {"headshot": ("fxSys_Blood_HeadshotShape", 2.0),
                     "gorebloodexplosion": ("fxSys_Blood_HeadExplodeShape", 1.0),
                     "grenadeexplosion": ("fxSys_Grenade_PersonShape", 1.0),
                     "shoteffectlight": ("fxSys_Small_ImpactBloodShape", 1.0),
                     "shoteffectheavy": ("fxSys_Large_ImpactBloodShape", 2.0),
                     "bloodpool": (None, 1.0)}
HEADSHOT_JOINT = "head"
SOURCE_JOINT = "neck"
POOL_SHADER = "blood_puddle"
POOL_GROWTH = 0.005 / 2.0              # radius added each frame (0.005 every 2 frames: section 4.2)
POOL_RADIUS = 1.9

# SPEC-010 section 3.2, for when the weapons' template script isn't in the copied files
FIRING_RATE = {"m16": 75.0, "uzi": 105.0}      # milliseconds between shots
DEFAULT_FIRING_RATE = 100.0
TRACER_EVERY = 2
TRACER = "fx_tracer"


class Effects:
    """The particle systems and effect composites of the effects file (Common.p3d), found by name, and the
    nodes made for them in one scene (with a limit on how many particles go in)."""

    def __init__(self, b: G.Builder, src: Optional[G.Source]) -> None:
        self.b, self.src = b, src
        self.systems: Dict[str, p3d.Chunk] = {}
        self.composites: Dict[str, p3d.Chunk] = {}
        self.read: Dict[str, PS.System] = {}
        self.played: Dict[Tuple[str, int, float, Optional[int]], List[PS.Particle]] = {}
        self.quads: Dict[Tuple[str, int, int], int] = {}
        self.count = 0
        self.last_end = 0
        self.left_out = 0
        self.not_found: set = set()
        if src is not None:
            for c in p3d.walk(src.chunks):
                if c.id == PS.SYSTEM:
                    self.systems.setdefault(str(p3d.fields(src.data, c).get("name", "")).lower(), c)
                elif c.id == G.COMPOSITE:
                    self.composites.setdefault(G.chunk_name(src.data, c).lower(), c)

    def system(self, name: str) -> Optional[PS.System]:
        key = name.lower()
        if key not in self.read:
            c = self.systems.get(key)
            try:
                self.read[key] = PS.read_system(self.src.data, c) if c is not None else None  # type: ignore[union-attr]
            except (p3d.P3dError, KeyError, IndexError, ValueError):
                self.read[key] = None
        return self.read[key]

    def systems_of(self, name: str) -> List[str]:
        """The particle systems an effect name stands for: itself, or a composite's particle-system parts."""
        key = name.lower()
        if key in self.systems:
            return [key]
        c = self.composites.get(key)
        if c is None:
            if key + "shape" in self.systems:
                return [key + "shape"]
            return []
        out = []
        for k in c.children:
            if k.id == G.COMPOSITE_PROP:
                part, kind, _joint = G.composite_prop(self.src.data, k)  # type: ignore[union-attr]
                if kind == PARTICLE_PART or part.lower() in self.systems:
                    out.append(part.lower())
        return out

    def _quad(self, shader: str, pictures: int, picture: int) -> int:
        key = (shader.lower(), pictures, picture)
        if key not in self.quads:
            g = self.b.g
            u0, u1 = picture / pictures, (picture + 1) / pictures
            pos = [(-0.5, -0.5, 0.0), (0.5, -0.5, 0.0), (0.5, 0.5, 0.0), (-0.5, 0.5, 0.0)]
            uv = [(u0, 1.0), (u1, 1.0), (u1, 0.0), (u0, 0.0)]
            material = self.b.material(shader)
            mat = g.doc["materials"][material]
            mat["doubleSided"] = True
            mat.setdefault("alphaMode", "BLEND")
            mat.setdefault("extras", {}).update(particles=True, depthWrite=False)
            self.quads[key] = g.add("meshes", {"name": shader + " particle", "primitives": [{
                "attributes": {"POSITION": g.accessor(pos, "VEC3", bounds=True),
                               "NORMAL": g.accessor([(0.0, 0.0, 1.0)] * 4, "VEC3"),
                               "TEXCOORD_0": g.accessor(uv, "VEC2")},
                "indices": g.accessor([0, 1, 2, 0, 2, 3], "SCALAR", 5123), "material": material, "mode": 4}]})
        return self.quads[key]

    def play(self, name: str, parent: int, frame: float, tracks, later: Callable[[List[float]], List[float]],
             size: float = 1.0, frames: Optional[float] = None, seed: int = 0, label: str = "") -> int:
        """Plays an effect (a system or a composite of them) under a node from a frame of the scene: every
        particle a node, keyed over its life. frames: when it is wound down (SPEC-010 section 1.10: it stops
        making particles, and those alive live out their lives), as when its prop enters another state or the
        gun fires again; without it a one-shot plays its length and a looping one MOST_LOOPING. Returns how
        many particles went in; self.last_end is how many frames after its start the last one dies."""
        self.last_end = 0
        made = 0
        for sname in self.systems_of(name):
            system = self.system(sname)
            if system is None:
                continue
            on = MOST_LOOPING if system.loops else system.length
            if frames is not None:
                on = max(1, int(math.ceil(frames))) if system.loops else min(on, max(1, int(math.ceil(frames))))
                on = min(on, MOST_WOUND_DOWN)
            key = (sname, seed % 4, size, on)
            if key not in self.played:
                self.played[key] = PS.play(system, frames=on, seed=seed % 4, size=size)
            group = None
            self.last_end = max([self.last_end] + [p.born + len(p.looks) for p in self.played[key]])
            for p in self.played[key]:
                if self.count >= MOST_PARTICLES:
                    self.left_out += 1
                    continue
                if group is None:
                    group = self.b.g.node(label or name, parent, extras={"effect": name, "system": system.name})
                e = system.emitters[p.emitter]
                self._particle(group, e, p, frame, tracks, later, system.rate)
                self.count += 1
                made += 1
        if not self.systems_of(name):
            self.not_found.add(name)
        return made

    def _particle(self, group: int, e: PS.Emitter, p: PS.Particle, frame: float, tracks, later, rate: float) -> None:
        g = self.b.g
        first = p.looks[0]
        node = g.node(e.name, group, mesh=self._quad(e.shader, e.pictures, first.picture), scale=list(GONE))
        step = 1.0 / rate
        begin = frame / FRAMES_A_SECOND + p.born * step
        times = [begin + k * step for k in range(len(p.looks))]
        end = times[-1] + step
        sizes = [(look.size,) * 3 for look in p.looks]
        tracks.add(node, "scale", later([0.0, begin - JUST_BEFORE] + times + [end - JUST_BEFORE, end]),
                   [GONE, GONE] + sizes + [sizes[-1], GONE])
        tracks.add(node, "translation", later(times), [G.pos(look.at) for look in p.looks])
        if any(abs(look.angle - first.angle) > 1e-6 for look in p.looks):
            tracks.add(node, "rotation", later(times), [_spin(look.angle) for look in p.looks])
        elif first.angle:
            g.doc["nodes"][node]["rotation"] = list(_spin(first.angle))
        colours = [[round(t, 4)] + [round(c / 255.0, 4) for c in look.rgba] for t, look in zip(later(times), p.looks)]
        kept = [c for i, c in enumerate(colours) if i == 0 or c[1:] != colours[i - 1][1:]]
        g.doc["nodes"][node]["extras"] = {"billboard": True, "colours": [v for row in kept for v in row]}


def _spin(angle: float) -> Tuple[float, float, float, float]:
    return (0.0, 0.0, math.sin(angle / 2.0), math.cos(angle / 2.0))


def facing(direction: Sequence[float]) -> Tuple[float, float, float, float]:
    """The glTF rotation that turns an effect's forward (the game's +Z, glTF's -Z in its own space) to a
    direction (glTF's space)."""
    d = _unit(direction)
    f = (0.0, 0.0, -1.0)
    dot = sum(a * b for a, b in zip(f, d))
    if dot < -0.999999:
        return (0.0, 1.0, 0.0, 0.0)
    axis = (f[1] * d[2] - f[2] * d[1], f[2] * d[0] - f[0] * d[2], f[0] * d[1] - f[1] * d[0])
    q = (axis[0], axis[1], axis[2], 1.0 + dot)
    n = math.sqrt(sum(c * c for c in q)) or 1.0
    return tuple(c / n for c in q)  # type: ignore[return-value]


def _unit(v: Sequence[float]) -> Tuple[float, float, float]:
    n = math.sqrt(sum(c * c for c in v)) or 1.0
    return (v[0] / n, v[1] / n, v[2] / n)


def angles_turn(angles: Sequence[float]) -> Tuple[float, float, float, float]:
    """A prop effect's angles (radians about x, y and z, the game's space) as glTF's rotation: x first."""
    def about(axis: int, a: float) -> Tuple[float, float, float, float]:
        q = [0.0, 0.0, 0.0, math.cos(a / 2.0)]
        q[axis] = math.sin(a / 2.0)
        return tuple(q)  # type: ignore[return-value]
    q = (0.0, 0.0, 0.0, 1.0)
    for axis in (0, 1, 2):
        q = _qmul(about(axis, angles[axis]), q)
    return G.rot(q)


def _qmul(a: Sequence[float], b: Sequence[float]) -> Tuple[float, float, float, float]:
    ax, ay, az, aw = a
    bx, by, bz, bw = b
    return (aw * bx + ax * bw + ay * bz - az * by, aw * by - ax * bz + ay * bw + az * bx,
            aw * bz + ax * by - ay * bx + az * bw, aw * bw - ax * bx - ay * by - az * bz)


def character_effect(kind: str) -> Optional[Tuple[Optional[str], float]]:
    """(particle system or None for a blood pool, size) of an NISCharacterEffect's type; None if unknown."""
    return CHARACTER_EFFECTS.get(re.sub(r"[^a-z]", "", kind.lower()))


def pool_keys(frame: float) -> Tuple[List[float], List[Tuple[float, float, float]]]:
    """A blood pool's size over time from the frame it starts (seconds, scale): it grows by POOL_GROWTH each
    frame to POOL_RADIUS, and then stays."""
    start = frame / FRAMES_A_SECOND
    full = start + POOL_RADIUS / POOL_GROWTH / FRAMES_A_SECOND
    times = [0.0, max(0.0, start - JUST_BEFORE), start, full]
    return times, [GONE, GONE, (1e-3, 1.0, 1e-3), (POOL_RADIUS, 1.0, POOL_RADIUS)]


def pool_mesh(b: G.Builder) -> int:
    """A blood pool: a flat square one unit across each way from its middle, the game's blood_puddle shader."""
    made = getattr(b, "_pool", None)
    if made is None:
        g = b.g
        pos = [(-1.0, 0.0, -1.0), (1.0, 0.0, -1.0), (1.0, 0.0, 1.0), (-1.0, 0.0, 1.0)]
        material = b.material(POOL_SHADER)
        mat = g.doc["materials"][material]
        mat.setdefault("alphaMode", "BLEND")
        mat.setdefault("extras", {}).update(depthWrite=False)
        made = g.add("meshes", {"name": "blood pool", "primitives": [{
            "attributes": {"POSITION": g.accessor(pos, "VEC3", bounds=True),
                           "NORMAL": g.accessor([(0.0, 1.0, 0.0)] * 4, "VEC3"),
                           "TEXCOORD_0": g.accessor([(0.0, 0.0), (1.0, 0.0), (1.0, 1.0), (0.0, 1.0)], "VEC2")},
            "indices": g.accessor([0, 2, 1, 0, 3, 2], "SCALAR", 5123), "material": material, "mode": 4}]})
        b._pool = made                                       # type: ignore[attr-defined]
    return made


def shot_frames(begin: int, end: int, rate_ms: float) -> List[float]:
    """The frames a gun fires on while its fire control is held from begin to end: the first at begin, then
    one every FiringRate milliseconds."""
    every = max(rate_ms, 1.0) / 1000.0 * FRAMES_A_SECOND
    out, f = [], float(begin)
    while f < end:
        out.append(f)
        f += every
    return out


def firing_rate(template: str, rates: Dict[str, float]) -> float:
    """A weapon template's milliseconds between shots: from its script (rates, by template name in lower
    case), else by the kind of gun its name says."""
    low = template.lower()
    if low in rates:
        return rates[low]
    for kind, ms in FIRING_RATE.items():
        if kind in low:
            return ms
    return DEFAULT_FIRING_RATE


def weapon_settings(script) -> Dict[str, Dict]:
    """{template name (lower): {"FiringRate", "TracerFrequency" ..., "texts": [its words]}} from the weapons'
    template script (scriptc/templates/weapons.cso, compiled bytes or decompiled text): every object that
    sets FiringRate."""
    try:
        import fog as F
        import torque_ast as AST
        import torque_script as TS
        from torque_names import name_key
        from torque_parse import parse
        text = TS.decompile(script) if isinstance(script, (bytes, bytearray)) else str(script)
        tree = parse(text)
    except Exception:
        return {}
    wanted = {name_key(n): n for n in ("FiringRate", "TracerFrequency", "MaxNumTracers")}
    out: Dict[str, Dict[str, float]] = {}
    for obj in F._objects(tree):
        name = F._word(obj.name_expr)
        values: Dict = {}
        texts = [F._word(slot.value) for slot in obj.slots if isinstance(slot.value, AST.StrConst)]
        for slot in obj.slots:
            prop = wanted.get(name_key(slot.slot))
            v = F._number(slot.value)
            if prop and v is not None and slot.index is None:
                values[prop] = v
        if name and "FiringRate" in values:
            values["texts"] = texts                          # its words, one of them its model's name
            out.setdefault(name.lower(), values)
    return out
