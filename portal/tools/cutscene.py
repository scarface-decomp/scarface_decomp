#!/usr/bin/env python3
"""A cutscene with everybody in it, as one glTF scene.

The game keeps a cutscene (art/nis/<name>) in three places, all read here from your own copied files:

    art/nis/fsc/<name>.fsc          its script, as text: who is in it (NISResourceLoader: a name for the
                                    scene and the template to load, CharTemp_Cornelius), where each one
                                    stands (NISCharacterPosition: a position and the way they face, in
                                    degrees), which animation each plays (NISCharacterAnimation,
                                    NISVehicleAnimation) and the camera's (NISSequenceCue)
    art/nis/<name>/stream<n>.p3d    the animations, cut into pieces: <animation name>0 in stream0,
                                    <animation name>1 in stream1, and so on, one after the other
    art/characters/..., art/vehicles/...   the models: a person's file is named after the template; a
                                    vehicle's after the one joint its animation moves (sportfishing_boat)

A person's animation moves them from where the script stands them; a vehicle's and the camera's are in
the city's own coordinates. "MainCharacter" is Tony, in the suit the script changes him into
(NISSwapModel: tonynisHawaiianDrawable is art/nis/characters/tonynisHawaiian.p3d). Standard library only.
"""

from __future__ import annotations

import bisect
import math
import re
import struct
from pathlib import Path
from typing import Callable, Dict, List, Optional, Sequence, Tuple

import p3d
import p3d_gltf as G

ACTION = "Cutscene "                   # the animation's name starts with this (Blender's script looks for it)
TONY = "maincharacter"
TONY_FILES = ("tonyniswhtsuit.p3d", "tonynisblksuit.p3d", "tonynishawaiian.p3d")

_BLOCK = re.compile(r"\b(NISResourceLoader|NISCharacterPosition|NISObjectPosition|NISCharacterAnimation|"
                    r"NISVehicleAnimation|NISSequenceCue|NISSwapModel|NISWeaponAttach|NISExpAnimation)\s*\{")
_FIELD = re.compile(r'\b(\w+)\s+(?:"([^"]*)"|(-?[\d.]+(?:e-?\d+)?))\s*;')


class Script:
    """What a cutscene's script says: the cast, where they stand, what they play."""

    def __init__(self) -> None:
        self.cast: Dict[str, str] = {}                      # scene name -> template
        self.stands: Dict[str, Tuple[Tuple[float, float, float], float]] = {}     # name (lower) -> position, facing
        self.plays: Dict[str, str] = {}                     # person (lower) -> animation
        self.drives: Dict[str, str] = {}                    # vehicle (lower) -> animation
        self.camera = ""
        self.tony = ""                                      # the suit Tony is changed into (NISSwapModel)
        self.holds: Dict[str, str] = {}                     # person (lower) -> weapon template (NISWeaponAttach)
        self.faces: Dict[str, str] = {}                     # person (lower) -> their face's animation (NISExpAnimation)


def _body(text: str, start: int) -> str:
    """The text of a { } block that opens just before start, inner blocks included."""
    depth, i = 1, start
    while i < len(text) and depth:
        depth += {"{": 1, "}": -1}.get(text[i], 0)
        i += 1
    return text[start:i - 1]


def read_script(text: str) -> Script:
    s = Script()
    for m in _BLOCK.finditer(text):
        body = _body(text, m.end())
        f = {}
        for k, quoted, number in _FIELD.findall(body):
            f.setdefault(k, quoted if number == "" else float(number))
        kind = m.group(1)
        if kind == "NISResourceLoader" and f.get("Name") and f.get("TemplateName"):
            s.cast.setdefault(str(f["Name"]), str(f["TemplateName"]))
        elif kind in ("NISCharacterPosition", "NISObjectPosition"):
            who = str(f.get("CharacterName") or f.get("ObjectName") or "").lower()
            if who and who not in s.stands and all(isinstance(f.get(k), float) for k in "xyz"):
                facing = f.get("Facing")
                s.stands[who] = ((f["x"], f["y"], f["z"]), facing if isinstance(facing, float) else 0.0)
        elif kind == "NISCharacterAnimation" and f.get("CharacterName") and f.get("AnimationName"):
            s.plays.setdefault(str(f["CharacterName"]).lower(), str(f["AnimationName"]))
        elif kind == "NISVehicleAnimation" and f.get("VehicleName") and f.get("AnimationName"):
            s.drives.setdefault(str(f["VehicleName"]).lower(), str(f["AnimationName"]))
        elif kind == "NISExpAnimation" and f.get("CharacterName") and f.get("AnimationName"):
            s.faces.setdefault(str(f["CharacterName"]).lower(), str(f["AnimationName"]))
        elif kind == "NISWeaponAttach" and f.get("CharacterName") and f.get("WeaponTemplateName"):
            s.holds.setdefault(str(f["CharacterName"]).lower(), str(f["WeaponTemplateName"]))
        elif kind == "NISSwapModel" and str(f.get("Character", "")).lower() == TONY and f.get("newModel") and not s.tony:
            s.tony = re.sub(r"Drawable$", "", str(f["newModel"]), flags=re.I)
        elif kind == "NISSequenceCue" and f.get("CameraAnimationName") and not s.camera:
            s.camera = str(f["CameraAnimationName"])
    return s


def scene_name(game_path: str) -> Optional[str]:
    """The cutscene a copied file belongs to (art/nis/<name>.p3d, art/nis/<name>/stream0.p3d,
    art/nis/fsc/<name>.fsc), or None."""
    low = game_path.replace("\\", "/")
    m = re.search(r"(?:^|/)art/nis/(?:fsc/([^/]+)\.fsc|([^/]+)/(?:stream\d+|static)\.p3d|([^/]+)\.p3d)$", low, re.I)
    if not m:
        return None
    name = m.group(1) or m.group(2) or m.group(3)
    return None if name.lower() in ("characters", "fsc") else name


def facing_rotation(degrees: float) -> G.Quat:
    """The way the script faces someone (a turn about the upright axis, in degrees), as glTF's rotation."""
    a = math.radians(degrees) / 2
    return G.rot((0.0, math.sin(a), 0.0, math.cos(a)))


def _pieces(b: G.Builder, name: str) -> List[G.Ref]:
    """An animation's pieces in order: <name>0, <name>1, ... (or <name> itself when it isn't cut up)."""
    found, n = [], 0
    while True:
        ref = b.find_animation(f"{name}{n}")
        if ref is None:
            break
        found.append(ref)
        n += 1
    whole = b.find_animation(name)
    return found or ([whole] if whole else [])


class _Tracks:
    """One glTF animation gathering every actor's channels."""

    def __init__(self, b: G.Builder) -> None:
        self.b, self.channels, self.samplers = b, [], []

    def add(self, node: int, path: str, times: List[float], values: List[tuple], step: bool = False) -> None:
        keep_t, keep_v, last = [], [], -1.0
        for t, v in zip(times, values):
            if t > last + 1e-6:
                keep_t.append(t)
                keep_v.append(v)
                last = t
        if not keep_t:
            return
        if path == "rotation":                              # the short way round from each key to the next
            for i in range(1, len(keep_v)):
                if sum(a * c for a, c in zip(keep_v[i], keep_v[i - 1])) < 0:
                    keep_v[i] = tuple(-a for a in keep_v[i])
        kind = "VEC4" if path == "rotation" else "VEC3"
        self.samplers.append({"input": self.b.g.accessor([(t,) for t in keep_t], "SCALAR", bounds=True),
                              "output": self.b.g.accessor(keep_v, kind), "interpolation": "STEP" if step else "LINEAR"})
        self.channels.append({"sampler": len(self.samplers) - 1, "target": {"node": node, "path": path}})

    def weights(self, node: int, times: List[float], rows: List[List[float]]) -> None:
        """How far a mesh's shapes are on at each time (glTF: every shape's weight, key after key)."""
        if not times:
            return
        flat = [w for row in rows for w in row]
        self.samplers.append({"input": self.b.g.accessor([(t,) for t in times], "SCALAR", bounds=True),
                              "output": self.b.g.accessor(flat, "SCALAR"), "interpolation": "LINEAR"})
        self.channels.append({"sampler": len(self.samplers) - 1, "target": {"node": node, "path": "weights"}})


def slider_keys(pieces: Sequence[G.Ref]) -> Dict[str, Tuple[List[float], List[float]]]:
    """A face animation's sliders over its pieces laid end to end: {slider (lower): (times, values)}. Each
    slider is an animation group named after it, with one Float1 channel (0x121100)."""
    out: Dict[str, Tuple[List[float], List[float]]] = {}
    start = 0.0
    for ref in pieces:
        data, c = ref.data, ref.chunk
        info = p3d.fields(data, c)
        rate = info.get("frame rate") or 30.0
        gl = c.find(G.ANIM_GROUP_LIST)
        for gc in (gl.children if gl else []):
            if gc.id != G.ANIM_GROUP:
                continue
            name = p3d.fields(data, gc).get("name", "").lower()
            for ch in gc.children:
                if ch.id != 0x121100:
                    continue
                try:
                    _param, frames, values = p3d.channel_keys(data, ch)
                except (p3d.P3dError, struct.error, IndexError, KeyError):
                    continue
                times, kept = out.setdefault(name, ([], []))
                for f, v in zip(frames, values):
                    t = start + f / rate
                    if not times or t > times[-1] + 1e-6:
                        times.append(t)
                        kept.append(v[0])
        start += (info.get("frames") or 0.0) / rate
    return out


def _value_at(times: List[float], values: List[float], t: float) -> float:
    if not times or t <= times[0]:
        return values[0] if values else 0.0
    if t >= times[-1]:
        return values[-1]
    i = bisect.bisect_right(times, t)
    a, b = times[i - 1], times[i]
    return values[i - 1] + (values[i] - values[i - 1]) * ((t - a) / (b - a) if b > a else 0.0)


def shape_weights(sliders: Sequence[Tuple[str, List[Tuple[float, int]]]], count: int,
                  keys: Dict[str, Tuple[List[float], List[float]]]) -> Tuple[List[float], List[List[float]]]:
    """How far each of a mesh's shapes is on through a face animation: (times, a row of count weights per
    time). A slider's shape is fully on when the slider is at the shape's value (a lip slider at -1 is
    all the way down, at 1 all the way up), and off at 0 or on the other side."""
    times = sorted({t for name, _k in sliders for t in keys.get(name.lower(), ([], []))[0]})
    rows = []
    for t in times:
        row = [0.0] * count
        for name, ends in sliders:
            got = keys.get(name.lower())
            if not got:
                continue
            at = _value_at(got[0], got[1], t)
            for value, shape in ends:
                if 0 <= shape < count and value:
                    row[shape] = max(0.0, min(1.0, at / value))
        rows.append(row)
    return times, rows


def _length(pieces: Sequence[G.Ref]) -> float:
    """How long an animation's pieces run, laid end to end (seconds)."""
    total = 0.0
    for ref in pieces:
        info = p3d.fields(ref.data, ref.chunk)
        total += (info.get("frames") or 0.0) / (info.get("frame rate") or 30.0)
    return total


def _joint_keys(pieces: Sequence[G.Ref]) -> Tuple[Dict[str, Dict[str, Tuple[List[float], List[tuple]]]], float]:
    """{joint (lower): {"translation"|"rotation": (times, values)}} over an animation's pieces laid end to
    end, and how long they run together (seconds)."""
    out: Dict[str, Dict[str, Tuple[List[float], List[tuple]]]] = {}
    start = 0.0
    for ref in pieces:
        data, c = ref.data, ref.chunk
        info = p3d.fields(data, c)
        rate = info.get("frame rate") or 30.0
        gl = c.find(G.ANIM_GROUP_LIST)
        for gc in (gl.children if gl else []):
            if gc.id != G.ANIM_GROUP:
                continue
            joint = p3d.fields(data, gc).get("name", "").lower()
            for ch in gc.children:
                try:
                    if ch.id in p3d.QUATERNION_CHANNELS:
                        _param, frames, values = p3d.channel_keys(data, ch)
                        path, vals = "rotation", [G.rot(v) for v in values]
                    elif ch.id in G.VECTOR_CHANNELS:
                        param, frames, values = G._vector_keys(data, ch)
                        if param not in ("TRAN", "TRA"):
                            continue
                        path, vals = "translation", [G.pos(v) for v in values]
                    else:
                        continue
                except (p3d.P3dError, struct.error, IndexError, KeyError):
                    continue
                times, kept = out.setdefault(joint, {}).setdefault(path, ([], []))
                times += [start + f / rate for f in frames]
                kept += vals
        start += (info.get("frames") or 0.0) / rate
    return out, start


def _camera_keys(pieces: Sequence[G.Ref]) -> Dict[str, Tuple[List[float], List[tuple]]]:
    """The camera's place and the way it looks over the pieces: {"translation"|"rotation": (times, values)}."""
    out: Dict[str, Tuple[List[float], List[tuple]]] = {"translation": ([], []), "rotation": ([], [])}
    start = 0.0
    for ref in pieces:
        data, c = ref.data, ref.chunk
        info = p3d.fields(data, c)
        rate = info.get("frame rate") or 30.0
        keys: Dict[str, Tuple[List[int], List[tuple]]] = {}
        for ch in p3d.walk(c.children):
            if ch.id in G.VECTOR_CHANNELS:
                try:
                    param, frames, vals = G._vector_keys(data, ch)
                except (p3d.P3dError, struct.error, IndexError, KeyError):
                    continue
                if frames:
                    keys[param] = (frames, vals)
        if "TRAN" in keys:
            frames, vals = keys["TRAN"]
            out["translation"][0].extend(start + f / rate for f in frames)
            out["translation"][1].extend(G.pos(v) for v in vals)
        if "LOOK" in keys:
            look = keys["LOOK"]
            up = keys.get("UP", ([0], [(0.0, 1.0, 0.0)]))
            for f in sorted(set(look[0]) | set(up[0])):
                out["rotation"][0].append(start + f / rate)
                out["rotation"][1].append(G.camera_rotation(G._at(*look, f), G._at(*up, f)))
        start += (info.get("frames") or 0.0) / rate
    return out


HAND = "right_hand_attach"             # the joint a person's weapon hangs on
# A weapon's model has its grip at its own origin, its barrel along its own forward axis (its muzzle joint
# says so) and its top upwards. In the hand it lies another way round: the barrel along the hand joint's
# sideways axis, towards the fingers, and its top along the joint's forward axis. Measured from the
# cutscenes: someone with a rifle keeps the other hand a fixed 0.34 m along that sideways axis from the hand
# joint (a rifle's length from grip to handguard), and through every rifle scene looked at, "up" in the
# world is close to the joint's forward axis.
GRIP = (0.5, -0.5, -0.5, 0.5)                                    # as glTF's rotation


class Ground:
    """The map's surfaces in a scene being built, for standing people on. A script places someone a few
    centimetres off the floor (the game sets them on the ground itself); height() finds the floor."""

    def __init__(self, b: G.Builder) -> None:
        self.g = b.g
        self.upto = len(b.g.doc["nodes"])                    # the map is what was there before the cast
        self._world: Dict[int, List[List[float]]] = {}
        self._parent: Optional[Dict[int, int]] = None
        self._tris: Dict[Tuple[int, int], List[Tuple[G.Vec3, G.Vec3, G.Vec3]]] = {}

    def _matrix(self, i: int) -> List[List[float]]:
        if i in self._world:
            return self._world[i]
        nodes = self.g.doc["nodes"]
        if self._parent is None:
            self._parent = {c: k for k, n in enumerate(nodes[:self.upto]) for c in n.get("children", [])}
        n = nodes[i]
        if "matrix" in n:
            m = [[n["matrix"][c * 4 + r] for c in range(4)] for r in range(4)]
        else:
            x, y, z, w = n.get("rotation", (0.0, 0.0, 0.0, 1.0))
            sx, sy, sz = n.get("scale", (1.0, 1.0, 1.0))
            tx, ty, tz = n.get("translation", (0.0, 0.0, 0.0))
            m = [[(1 - 2 * (y * y + z * z)) * sx, 2 * (x * y - z * w) * sy, 2 * (x * z + y * w) * sz, tx],
                 [2 * (x * y + z * w) * sx, (1 - 2 * (x * x + z * z)) * sy, 2 * (y * z - x * w) * sz, ty],
                 [2 * (x * z - y * w) * sx, 2 * (y * z + x * w) * sy, (1 - 2 * (x * x + y * y)) * sz, tz],
                 [0.0, 0.0, 0.0, 1.0]]
        up = self._parent.get(i)
        if up is not None:
            p = self._matrix(up)
            m = [[sum(p[r][k] * m[k][c] for k in range(4)) for c in range(4)] for r in range(4)]
        self._world[i] = m
        return m

    def _read(self, index: int, code: str, width: int) -> List:
        acc = self.g.doc["accessors"][index]
        view = self.g.doc["bufferViews"][acc["bufferView"]]
        at = view.get("byteOffset", 0) + acc.get("byteOffset", 0)
        flat = struct.unpack_from(f"<{acc['count'] * width}{code}", self.g.bin, at)
        return [flat[k:k + width] for k in range(0, len(flat), width)] if width > 1 else list(flat)

    def height(self, x: float, y: float, z: float, reach: float = 0.5) -> Optional[float]:
        """The height of the map's surface at x, z that is nearest to y, within reach; None when there is
        none (no map, or nothing under the spot)."""
        doc = self.g.doc
        best: Optional[float] = None
        for i, n in enumerate(doc["nodes"][:self.upto]):
            if "mesh" not in n or "skin" in n:
                continue
            m = None
            for pi, prim in enumerate(doc["meshes"][n["mesh"]]["primitives"]):
                acc = doc["accessors"][prim["attributes"]["POSITION"]]
                if prim.get("mode", 4) != 4 or "indices" not in prim or "min" not in acc:
                    continue
                m = m or self._matrix(i)
                lo, hi = acc["min"], acc["max"]
                corners = [[sum(m[r][k] * v for k, v in enumerate((cx, cy, cz))) + m[r][3] for r in range(3)]
                           for cx in (lo[0], hi[0]) for cy in (lo[1], hi[1]) for cz in (lo[2], hi[2])]
                if not (min(c[0] for c in corners) <= x <= max(c[0] for c in corners)
                        and min(c[2] for c in corners) <= z <= max(c[2] for c in corners)
                        and min(c[1] for c in corners) - reach <= y <= max(c[1] for c in corners) + reach):
                    continue
                key = (i, pi)
                if key not in self._tris:
                    pts = [tuple(sum(m[r][k] * v for k, v in enumerate(p)) + m[r][3] for r in range(3))
                           for p in self._read(prim["attributes"]["POSITION"], "f", 3)]
                    ia = doc["accessors"][prim["indices"]]
                    idx = self._read(prim["indices"], {5123: "H", 5125: "I", 5121: "B"}[ia["componentType"]], 1)
                    self._tris[key] = [(pts[idx[k]], pts[idx[k + 1]], pts[idx[k + 2]])
                                       for k in range(0, len(idx) - 2, 3)]
                for a, b_, c in self._tris[key]:
                    if (min(a[0], b_[0], c[0]) > x or max(a[0], b_[0], c[0]) < x
                            or min(a[2], b_[2], c[2]) > z or max(a[2], b_[2], c[2]) < z):
                        continue
                    ux, uy, uz = b_[0] - a[0], b_[1] - a[1], b_[2] - a[2]
                    vx, vy, vz = c[0] - a[0], c[1] - a[1], c[2] - a[2]
                    den = ux * vz - vx * uz
                    if abs(den) < 1e-12:
                        continue                             # a wall: no height of its own here
                    s = ((x - a[0]) * vz - vx * (z - a[2])) / den
                    t = (ux * (z - a[2]) - (x - a[0]) * uz) / den
                    if s < -1e-6 or t < -1e-6 or s + t > 1 + 1e-6:
                        continue
                    h = a[1] + s * uy + t * vy
                    if abs(h - y) <= reach and (best is None or abs(h - y) < abs(best - y)):
                        best = h
        return best
WEAPON = re.compile(r"^WeaponTemplate", re.I)


def weapon_model(template: str, models: Sequence[str]) -> Optional[str]:
    """The model a weapon template stands for, among the weapons file's models: WeaponTemplateMetalPipe is
    metal_pipe, WeaponTemplateSniper is sniper_rifle, WeaponTemplateM16Mortar is the M16."""
    flat = lambda t: re.sub(r"[^a-z0-9]", "", t.lower())
    want = flat(WEAPON.sub("", template))
    if not want:
        return None
    by = {flat(m): m for m in models}
    if want in by:
        return by[want]
    longer = sorted((k for k in by if k.startswith(want)), key=len)
    if longer:
        return by[longer[0]]
    shorter = sorted((k for k in by if want.startswith(k)), key=len, reverse=True)
    return by[shorter[0]] if shorter else None


def where(script: Script, streams: Sequence[Tuple[str, bytes]]) -> Optional[Tuple[float, float]]:
    """Where in the city a cutscene happens (the map's own x and z): where the script first stands
    someone, or else where its camera starts. None for a scene with no place of its own (the ones played
    wherever Tony happens to be are set at 0, 0, 0)."""
    for at, _facing in script.stands.values():
        if abs(at[0]) + abs(at[2]) > 1.0:
            return at[0], at[2]
    if script.stands:                                        # everyone at 0, 0: played wherever Tony is
        return None
    if script.camera:
        lib = G.Library()
        for label, data in streams:
            lib.add(label, data, main=False)
        for ref in _pieces(G.Builder(lib), script.camera):
            for ch in p3d.walk(ref.chunk.children):
                if ch.id in G.VECTOR_CHANNELS:
                    try:
                        param, frames, vals = G._vector_keys(ref.data, ch)
                    except (p3d.P3dError, struct.error, IndexError, KeyError):
                        continue
                    if param == "TRAN" and vals and abs(vals[0][0]) + abs(vals[0][2]) > 1.0:
                        return vals[0][0], vals[0][2]
    return None


GONE = (1e-4, 1e-4, 1e-4)              # the size of someone whose part of a joined cutscene isn't playing
PLAY = re.compile(r'\b\w+\("((?:PAL_)?M?NIS_\w+)"\s*(?:,\s*"([\w:]*)")?')


def plays_next(texts: Sequence[str], hashed: Callable[[str], str]) -> Dict[str, str]:
    """Which cutscene the game starts as soon as another ends: {cutscene (lower): the next (lower)}.
    texts: the game's mission scripts, decompiled. A script starts a cutscene with a call whose first
    argument is its name and whose second names the function to run when it is over; where that
    function's first act with a cutscene is to start another, the two play back to back. hashed gives
    the form a function's name has in the compiled scripts."""
    starts: Dict[str, List[str]] = {}                       # function (lower) -> the cutscenes it starts
    calls: List[Tuple[str, str]] = []                       # (cutscene, the function run after it)
    for text in texts:
        for part in re.split(r"(?m)^function ", text)[1:]:
            fn = part.split("(", 1)[0].strip().split("::")[-1].lower()
            for m in PLAY.finditer(part):
                starts.setdefault(fn, []).append(m.group(1).lower())
                if m.group(2):
                    calls.append((m.group(1).lower(), m.group(2)))
    out: Dict[str, str] = {}
    for scene, after in calls:
        for key in (after.lower(), hashed(after).lower()):
            then = starts.get(key)
            if then and then[0] != scene:
                out.setdefault(scene, then[0])
                break
    return out


def export(name: str, script: Script, streams: Sequence[Tuple[str, bytes]],
           model: Callable[[str, str], Optional[Tuple[str, bytes]]],
           area: Sequence[Tuple[str, bytes]] = (), library: Sequence[Tuple[str, bytes]] = (),
           then: Sequence[Tuple[str, Script, Sequence[Tuple[str, bytes]]]] = ()) -> Tuple[bytes, G.Report]:
    """The cutscene as a .glb. streams: its stream files (name, bytes) in order. model(kind, name) hands
    over a model's file (name, bytes) or None: kind "person" with a template's name, "tony" with his
    suit's, "vehicle" with the name of the joint its animation moves, or "weapons".
    area: the files of the map where it happens, and library the shared files they need (see
    blender_export.area_from_files): the cast then stands on the street or in the room.
    then: the cutscenes the game plays straight after it (name, script, streams), joined on: each one's
    cast is there only while its own part plays."""
    lib = G.Library()
    have = set()
    for label, data in area:
        if label.lower() not in have:
            have.add(label.lower())
            lib.add(label, data, main=True)
    for label, data in library:
        if label.lower() not in have:
            have.add(label.lower())
            lib.add(label, data, main=False)
    for part in [streams] + [st for _n, _s, st in then]:
        for label, data in part:
            lib.add(label, data, main=False)
    found: List[str] = []

    def cast(b: G.Builder) -> None:
        b._animations = None                                 # the stream files came after the map's
        tracks = _Tracks(b)
        ground = Ground(b)
        loaded: Dict[str, Optional[G.Source]] = {}
        scenes = [(name, script)] + [(n, s) for n, s, _st in then]
        spans = []
        start = 0.0
        for n, sc in scenes:
            went_in, nodes, length = _cast(b, lib, n, sc, model, tracks, loaded, start, ground)
            found.extend(went_in)
            spans.append((nodes, start, start + length))
            start += length
        if len(scenes) > 1:                                  # each cast is there for its own part only
            for i, (nodes, begin, end) in enumerate(spans):
                times, sizes = [begin], [(1.0, 1.0, 1.0)]
                if begin > 0:
                    times, sizes = [0.0] + times, [GONE] + sizes
                if i < len(spans) - 1:
                    times, sizes = times + [end], sizes + [GONE]
                for node in nodes:
                    tracks.add(node, "scale", times, sizes, step=True)
        b.report.models += found
        if tracks.channels:
            # The only animation in the file. Blender plays a file's first animation and parks the rest: with
            # the map's own (a door swinging) ahead of it, everybody stood with their arms out.
            b.g.doc["animations"] = [{"name": ACTION + name, "channels": tracks.channels, "samplers": tracks.samplers}]
            b.report.animations = [ACTION + name]
    glb, report = G.export(lib, map_mode=True, also=cast)
    if not found:
        raise G.ExportError("none of this cutscene's people or vehicles are in your copied game files")
    return glb, report


def _person(b: G.Builder, lib: G.Library, src: G.Source, spot: int, label: str) -> Optional[G.SkeletonCopy]:
    """Someone's model from their file, under spot: their skeleton, or None when nothing went in. A file
    with a composite drawable that holds the body (Tony's cutscene suits) is put in whole, eyes and teeth
    on their joints; otherwise the full-detail skins on their skeleton."""
    skin_names = {G.chunk_name(src.data, c).lower() for c in src.chunks if c.id == G.SKIN}
    for c in src.chunks:
        if c.id != G.COMPOSITE:
            continue
        parts = [G.composite_prop(src.data, k)[0].lower() for k in c.children if k.id == G.COMPOSITE_PROP]
        if any(p in skin_names for p in parts):
            before = len(b.copies)
            b.composite(G.Ref(src, c), spot, label + " skeleton")
            if len(b.copies) > before:
                return b.copies[before]
    skins = [c for c in src.chunks if c.id == G.SKIN]
    full = [c for c in skins if "_low" not in G.chunk_name(src.data, c).lower()] or skins
    copy, placed = None, False
    for c in full:
        r = p3d._R(src.data, *c.body)
        r.text()
        r.u32()
        skel_name = r.text()
        if copy is None:
            sref = lib.find("skeleton", skel_name, (src,))
            if not sref:
                break
            copy = b.skeleton(sref, spot, label + " skeleton")
        if b.skin(G.Ref(src, c), copy, copy.group) is not None:    # type: ignore[attr-defined]
            placed = True
    return copy if placed else None


def _cast(b: G.Builder, lib: G.Library, name: str, script: Script,
          model: Callable[[str, str], Optional[Tuple[str, bytes]]], tracks: _Tracks,
          loaded: Dict[str, Optional[G.Source]], start: float,
          ground: Optional[Ground] = None) -> Tuple[List[str], List[int], float]:
    """Puts one cutscene's people, vehicles and camera into b's scene, its animations beginning at start
    (seconds): who went in, their nodes, and how long it runs."""
    root = b.g.node(name)
    left_out: List[str] = []
    went_in: List[str] = []
    nodes: List[int] = []
    length = 0.0

    def later(times: List[float]) -> List[float]:
        return [start + t for t in times] if start else times

    def source(kind: str, wanted: str) -> Optional[G.Source]:
        key = kind + ":" + wanted.lower()
        if key not in loaded:
            got = model(kind, wanted)
            try:
                loaded[key] = lib.add(got[0], got[1], main=False) if got else None
            except p3d.P3dError:
                loaded[key] = None
        return loaded[key]

    people = [(who, anim) for who, anim in script.plays.items()]
    for who in script.cast:                                  # loaded and stood somewhere, but playing nothing
        if who.lower() not in script.plays and who.lower() not in script.drives and who.lower() in script.stands:
            people.append((who.lower(), ""))
    cast = {k.lower(): v for k, v in script.cast.items()}
    for who, anim in people:
        # someone the script doesn't load was already in the game: their template has their name
        src = source("tony", script.tony) if who == TONY else source("person", cast.get(who) or "CharTemp_" + who)
        label = "Tony" if who == TONY else next((k for k in script.cast if k.lower() == who), who)
        if src is None:
            left_out.append(label)
            continue
        at, facing = script.stands.get(who, ((0.0, 0.0, 0.0), 0.0))
        stand = list(G.pos(at))
        floor = ground.height(*stand) if ground is not None and who in script.stands else None
        if floor is not None:                                # on the floor, not the few centimetres in it
            stand[1] = floor
        spot = b.g.node(label, root, translation=stand, rotation=list(facing_rotation(facing)))
        before = len(b.g.doc["nodes"])
        copy = _person(b, lib, src, spot, label)
        if copy is None:
            b.g.doc["nodes"][root]["children"].remove(spot)
            left_out.append(label)
            continue
        went_in.append(label)
        nodes.append(spot)
        hand = copy.nodes.get(HAND)
        if who in script.holds and hand is not None:
            guns = source("weapons", "")
            names = [G.chunk_name(guns.data, c) for c in guns.chunks if c.id == G.COMPOSITE] if guns else []
            wanted = weapon_model(script.holds[who], names)
            gref = lib.find("composite", wanted, (guns,)) if wanted and guns else None
            if gref:
                b.composite(gref, b.g.node(label + "'s grip", hand, rotation=list(GRIP)), label + "'s " + wanted)
            else:
                left_out.append(label + "'s " + WEAPON.sub("", script.holds[who]))
        if who in script.faces:                              # the lips, brows and eyelids
            sliding = slider_keys(_pieces(b, script.faces[who]))
            for i in range(before, len(b.g.doc["nodes"])):
                mesh = b.g.doc["nodes"][i].get("mesh")
                if mesh in b.shaped and sliding:
                    count = len(b.g.doc["meshes"][mesh]["weights"])
                    times, rows = shape_weights(b.shaped[mesh], count, sliding)
                    tracks.weights(i, later(times), rows)
        if anim:
            keys, ran = _joint_keys(_pieces(b, anim))
            length = max(length, ran)
            for joint, paths in keys.items():
                node = copy.nodes.get(joint)
                if node is not None:
                    for path, (times, values) in paths.items():
                        tracks.add(node, path, later(times), values)
    for who, anim in script.drives.items():
        label = next((k for k in script.cast if k.lower() == who), who)
        keys, ran = _joint_keys(_pieces(b, anim))
        length = max(length, ran)
        joint = next(iter(keys), "")
        src = source("vehicle", joint) if joint else None
        cref = None
        if src is not None:
            cref = next((G.Ref(src, c) for c in src.chunks if c.id == G.COMPOSITE and G._has_model(lib, G.Ref(src, c))), None)
        if cref is None:
            left_out.append(label)
            continue
        mover = b.g.node(label, root)
        b.composite(cref, mover)
        went_in.append(label)
        nodes.append(b.g.node(label + " in the scene", root))
        b.g.doc["nodes"][root]["children"].remove(mover)     # under a node of its own, to be shown and hidden
        b.g.doc["nodes"][nodes[-1]]["children"] = [mover]
        for path, (times, values) in keys[joint].items():
            tracks.add(mover, path, later(times), values)
    if script.camera:
        pieces = _pieces(b, script.camera)
        if pieces:
            length = max(length, _length(pieces))
            ci = b.g.add("cameras", {"name": script.camera, "type": "perspective",
                                     "perspective": {"aspectRatio": 4 / 3, "yfov": 0.75, "znear": 0.1, "zfar": 5000.0}})
            cam = b.g.node(script.camera, root, camera=ci)
            for path, (times, values) in _camera_keys(pieces).items():
                tracks.add(cam, path, later(times), values)
            went_in.append("camera")
    for label in left_out:
        b.report.missing_drawables.add(label)
    return went_in, nodes, length
