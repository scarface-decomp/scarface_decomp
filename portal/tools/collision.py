#!/usr/bin/env python3
"""
The game's collision: the triangle meshes characters walk on and bullets hit, read from the .p3d files.

Read from the files and the retail Xbox program alone (the examiner's question F12: the outside research
has nothing on collision, so there is no clean-room spec; reports/chunk_dispatch.json has the program's
own dispatch: CollisionObjectLoader and WorldCollisionObjectLoader hand their mesh's children to
sub_002F7550). Each map area's shell package (86 of them on the PC) holds one World Collision Object:

    0x07010025  World Collision Object   its name (the area's), u32
      0x07010001  (12 bytes, 0 in every file seen)
        0x0701000A  Collision Mesh        u32 version (5), u32, u32, its box: min x y z, max x y z
          0x07000003  vertices            u32 count, then x y z (f32) each
          0x07000006  triangles           u32 count, then four u16 each: three vertex numbers and a 3-bit
                                          mask (0 to 7) over the triangle's edges
          0x07000007  neighbours          u32 count (the triangles'), then four u16 each: the triangle across
                                          each edge (65535: none) and a number the same for the whole mesh
          0x07000008  search tree         u32 count, then that many u16 (nodes of 4: the tree the game
                                          searches; not needed to find a triangle here)
          0x07016000  triangle sets       u32 0, u32 how many sets follow:
            0x07016010  a flag set         u32 0, its name (VehicleIgnore, Walkable ...), u32 count, then
            0x07016012  a value set        count triangle numbers (u16) and count values (u16): surfaceType
                                          gives each listed triangle its surface (8, 9 ...)

Coordinates are the map's own (the exports' glTF mirrors z). Objects' collision (an animal's, a prop's:
0x07010000 with 0x07010001 > 0x07010003 > 0x07010007 primitives, and a rigid body 0x07011000) is read
only as far as its chunk list here.

    python portal/tools/collision.py FILE.p3d                  what is in it
    python portal/tools/collision.py FILE.p3d --glb out.glb    its triangles as a glTF, coloured by surface
    python portal/tools/collision.py FILE.p3d --ground X Y Z   the floor under a place (the map's x, y, z)

Standard library only (and p3d_gltf for --glb).
"""

from __future__ import annotations

import argparse
import math
import struct
import sys
from dataclasses import dataclass, field
from pathlib import Path
from typing import Dict, Iterable, List, Optional, Sequence, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parent))
import p3d  # noqa: E402

WORLD_OBJECT, OBJECT, MESH = 0x07010025, 0x07010000, 0x0701000A
VERTICES, TRIANGLES, NEIGHBOURS, TREE, SETS = 0x07000003, 0x07000006, 0x07000007, 0x07000008, 0x07016000
FLAG_SET, VALUE_SET = 0x07016010, 0x07016012
NONE = 0xFFFF
Vec3 = Tuple[float, float, float]


@dataclass
class TriangleSet:
    name: str
    values: Dict[int, int]                       # triangle number -> value
    flag: bool                                   # a flag set (0x07016010) or a value set (0x07016012)


@dataclass
class CollisionMesh:
    owner: str                                   # the World Collision Object's name
    version: int
    box: Tuple[Vec3, Vec3]
    vertices: List[Vec3]
    triangles: List[Tuple[int, int, int, int]]   # three vertex numbers and the edge mask
    neighbours: List[Tuple[int, int, int, int]] = field(default_factory=list)
    sets: Dict[str, TriangleSet] = field(default_factory=dict)
    tree: int = 0                                # how many numbers its search tree holds

    def value(self, name: str, triangle: int, default: Optional[int] = None) -> Optional[int]:
        s = self.sets.get(name)
        return s.values.get(triangle, default) if s else default

    def corners(self, t: int) -> Tuple[Vec3, Vec3, Vec3]:
        a, b, c, _m = self.triangles[t]
        return self.vertices[a], self.vertices[b], self.vertices[c]


def _body(data: bytes, c: p3d.Chunk) -> bytes:
    return data[c.body[0]:c.body[1]]


def _counted(raw: bytes, fmt: str) -> List[tuple]:
    n = struct.unpack_from("<I", raw)[0]
    size = struct.calcsize("<" + fmt)
    n = min(n, (len(raw) - 4) // size)
    return [struct.unpack_from("<" + fmt, raw, 4 + i * size) for i in range(n)]


def _triangle_set(raw: bytes, flag: bool) -> TriangleSet:
    n = raw[4]
    name = raw[5:5 + n].split(b"\0")[0].decode("latin-1")
    o = 5 + n
    count = struct.unpack_from("<I", raw, o)[0]
    o += 4
    count = min(count, (len(raw) - o) // 4)
    tris = struct.unpack_from(f"<{count}H", raw, o)
    vals = struct.unpack_from(f"<{count}H", raw, o + 2 * count)
    return TriangleSet(name, dict(zip(tris, vals)), flag)


def read_mesh(data: bytes, c: p3d.Chunk, owner: str = "") -> CollisionMesh:
    head = _body(data, c)
    version = struct.unpack_from("<I", head)[0]
    box = struct.unpack_from("<6f", head, 12) if len(head) >= 36 else (0.0,) * 6
    m = CollisionMesh(owner, version, (tuple(box[:3]), tuple(box[3:])), [], [])  # type: ignore[arg-type]
    for k in c.children:
        raw = _body(data, k)
        if k.id == VERTICES:
            m.vertices = [tuple(v) for v in _counted(raw, "3f")]         # type: ignore[misc]
        elif k.id == TRIANGLES:
            m.triangles = _counted(raw, "4H")                             # type: ignore[assignment]
        elif k.id == NEIGHBOURS:
            m.neighbours = _counted(raw, "4H")                            # type: ignore[assignment]
        elif k.id == TREE:
            m.tree = struct.unpack_from("<I", raw)[0]
        elif k.id == SETS:
            for s in k.children:
                if s.id in (FLAG_SET, VALUE_SET):
                    ts = _triangle_set(_body(data, s), s.id == FLAG_SET)
                    m.sets[ts.name] = ts
    return m


def meshes(data: bytes, tree: Optional[List[p3d.Chunk]] = None) -> List[CollisionMesh]:
    """Every collision mesh in a file, with the name of the object holding it."""
    tree = p3d.read_tree(data) if tree is None else tree
    out = []

    def walk(cs, owner):
        for c in cs:
            name = owner
            if c.id in (WORLD_OBJECT, OBJECT):
                raw = _body(data, c)
                name = raw[1:1 + raw[0]].split(b"\0")[0].decode("latin-1") if raw else owner
            if c.id == MESH:
                out.append(read_mesh(data, c, name))
            else:
                walk(c.children, name)
    walk(tree, "")
    return out


# --------------------------------------------------------------------------- questions

def _sub(a: Vec3, b: Vec3) -> Vec3:
    return (a[0] - b[0], a[1] - b[1], a[2] - b[2])


def _cross(a: Vec3, b: Vec3) -> Vec3:
    return (a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0])


def _dot(a: Vec3, b: Vec3) -> float:
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]


def hit(origin: Vec3, way: Vec3, tri: Tuple[Vec3, Vec3, Vec3]) -> Optional[float]:
    """How far along way (in its own lengths) the line from origin meets a triangle, either side; None if not."""
    a, b, c = tri
    e1, e2 = _sub(b, a), _sub(c, a)
    p = _cross(way, e2)
    det = _dot(e1, p)
    if abs(det) < 1e-12:
        return None
    inv = 1.0 / det
    s = _sub(origin, a)
    u = _dot(s, p) * inv
    if u < -1e-7 or u > 1 + 1e-7:
        return None
    q = _cross(s, e1)
    v = _dot(way, q) * inv
    if v < -1e-7 or u + v > 1 + 1e-7:
        return None
    t = _dot(e2, q) * inv
    return t if t >= 0 else None


@dataclass
class Hit:
    at: Vec3
    distance: float
    mesh: CollisionMesh
    triangle: int

    @property
    def surface(self) -> Optional[int]:
        return self.mesh.value("surfaceType", self.triangle)

    @property
    def walkable(self) -> bool:
        return self.triangle in self.mesh.sets.get("Walkable", TriangleSet("", {}, True)).values


def ray(found: Sequence[CollisionMesh], origin: Vec3, way: Vec3, length: float) -> Optional[Hit]:
    """The nearest collision triangle a ray meets within length (the map's coordinates), or None. way need
    not be of unit length; it is made so."""
    n = math.sqrt(_dot(way, way)) or 1.0
    d = (way[0] / n, way[1] / n, way[2] / n)
    end = (origin[0] + d[0] * length, origin[1] + d[1] * length, origin[2] + d[2] * length)
    lo = tuple(min(origin[i], end[i]) for i in range(3))
    hi = tuple(max(origin[i], end[i]) for i in range(3))
    best: Optional[Hit] = None
    for m in found:
        (bx0, by0, bz0), (bx1, by1, bz1) = m.box
        if bx1 < lo[0] or bx0 > hi[0] or by1 < lo[1] or by0 > hi[1] or bz1 < lo[2] or bz0 > hi[2]:
            continue
        for t in range(len(m.triangles)):
            tri = m.corners(t)
            if max(p[0] for p in tri) < lo[0] or min(p[0] for p in tri) > hi[0] or \
                    max(p[2] for p in tri) < lo[2] or min(p[2] for p in tri) > hi[2]:
                continue
            k = hit(origin, d, tri)
            if k is not None and k <= length and (best is None or k < best.distance):
                best = Hit((origin[0] + d[0] * k, origin[1] + d[1] * k, origin[2] + d[2] * k), k, m, t)
    return best


def ground(found: Sequence[CollisionMesh], x: float, y: float, z: float, above: float = 0.5,
           reach: float = 50.0) -> Optional[Hit]:
    """The floor under a place: the first collision surface straight down from a little above it."""
    return ray(found, (x, y + above, z), (0.0, -1.0, 0.0), reach + above)


# --------------------------------------------------------------------------- glTF, for looking at it

SURFACE_COLOURS = [(0.6, 0.6, 0.6), (0.8, 0.5, 0.3), (0.4, 0.6, 0.9), (0.5, 0.8, 0.4), (0.9, 0.8, 0.3),
                   (0.7, 0.4, 0.8), (0.9, 0.4, 0.4), (0.3, 0.8, 0.8), (0.95, 0.6, 0.7), (0.5, 0.5, 0.9),
                   (0.6, 0.9, 0.6), (0.9, 0.7, 0.5)]


def to_glb(found: Sequence[CollisionMesh]) -> bytes:
    """The collision as a glTF: one mesh each, its triangles coloured by surface type, the walkable ones
    lighter; the glTF's z mirrored like the other exports'. Each node's extras say "collision": true."""
    import p3d_gltf as G
    b = G.Builder(G.Library())
    g = b.g
    root = g.node("Collision", None, extras={"collision": True})
    mat = g.add("materials", {"name": "collision", "doubleSided": True,
                              "pbrMetallicRoughness": {"baseColorFactor": [1, 1, 1, 0.6], "metallicFactor": 0},
                              "alphaMode": "BLEND"})
    for m in found:
        if not m.triangles:
            continue
        pos, col = [], []
        for t, (a, bb, c, _mask) in enumerate(m.triangles):
            surface = m.value("surfaceType", t, 0) or 0
            r, gg, bl = SURFACE_COLOURS[surface % len(SURFACE_COLOURS)]
            k = 1.0 if m.value("Walkable", t) is not None else 0.6
            for v in (a, c, bb):                                       # mirrored: the winding turns round
                pos.append(G.pos(m.vertices[v]))
                col.append((r * k, gg * k, bl * k, 1.0))
        mesh = g.add("meshes", {"name": (m.owner or "collision") + " collision", "primitives": [{
            "attributes": {"POSITION": g.accessor(pos, "VEC3", bounds=True), "COLOR_0": g.accessor(col, "VEC4")},
            "material": mat, "mode": 4}]})
        g.node((m.owner or "collision") + " collision", root, mesh=mesh,
               extras={"collision": True, "triangles": len(m.triangles),
                       "sets": {k: len(v.values) for k, v in m.sets.items()}})
    return g.glb()


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("file", type=Path)
    ap.add_argument("--glb", type=Path, help="write the collision as a glTF here")
    ap.add_argument("--ground", type=float, nargs=3, metavar=("X", "Y", "Z"), help="the floor under this place")
    a = ap.parse_args(argv)
    data = a.file.read_bytes()
    found = meshes(data)
    if not found:
        print(f"{a.file.name}: no collision mesh in it")
        return 1
    for m in found:
        sets = ", ".join(f"{k} ({len(v.values)}{'' if v.flag else ' values'})" for k, v in m.sets.items())
        print(f"{m.owner or '?'}: {len(m.vertices)} vertices, {len(m.triangles)} triangles; sets: {sets or 'none'}")
    if a.ground:
        h = ground(found, *a.ground)
        print("no floor under it" if h is None else
              f"floor at y {h.at[1]:.3f} ({h.distance:.3f} down), surface {h.surface}, walkable: {h.walkable}")
    if a.glb:
        a.glb.write_bytes(to_glb(found))
        print(f"written {a.glb}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
