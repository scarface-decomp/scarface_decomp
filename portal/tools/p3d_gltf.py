#!/usr/bin/env python3
"""
Turn Pure3D (.p3d) files into glTF 2.0 (.glb) scenes that Blender and other 3D programs open: models with
their textures, characters with their skeletons, skin weights and animations, guns and cars with their
moving parts, and map areas with everything the game places on them.

    python portal/tools/p3d_gltf.py OUT.glb MODEL.p3d [MORE.p3d, folders, "wild*cards.p3d" ...]
        --anim ANIM.p3d ...       animations to add; they move whichever skeleton has their joints
        --library FOLDER_OR_FILE  more .p3d files to take textures, shaders and placed models from
        --map                     the files are map areas: their world geometry, and the models that
                                  instance objects place on them (trees, lamps, benches...); without
                                  --library the shared files next to them are used (regions, miami_lod...)
        --split                   with --map: one .glb per area in the folder OUT, lined up when imported
        --lod                     with --map: keep the low-detail city (miami_lod) next to real areas
        --only NAME ...           just these models
        --list                    say what is in the files instead of writing anything

What goes where (see docs/FORMATS.md for the chunk layouts):

    a Skin (0x10001)                 a skinned mesh bound to its Skeleton (0x23000)
    a Composite Drawable (0x123000)  its skeleton's joints as nodes, each mesh hung on its joint (guns,
                                     cars, props, and the map's world geometry)
    a loose Mesh (0x10000)           a mesh node
    an Animation (0x121000)          a glTF animation on the joints with the same names
    an instance object (0x9900190)   a copy of the model its "modelname" names, at the position, angles
                                     and scale its "instanceposition" records give

Pure3D is left-handed with Y up; glTF is right-handed with Y up, so Z is mirrored (and the triangles
turned round to keep facing the right way). A character faces +Z in the result, as glTF expects.
UVs are flipped upright (Pure3D's V runs from the bottom of the picture).

PC lists, Xbox vertex buffers and PS2 vector-unit packets are all read (docs/FORMATS.md, "Models").

Your own copies, on your own computer; standard library only.
"""

from __future__ import annotations

import argparse
import json
import math
import os
import re
import struct
import sys
from array import array
from dataclasses import dataclass, field
from pathlib import Path
from typing import Dict, Iterable, List, Optional, Sequence, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parent))
import media  # noqa: E402
import p3d  # noqa: E402

MESH, SKIN, PRIM_GROUP, SHADER, SKELETON, JOINT = 0x10000, 0x10001, 0x10020, 0x11000, 0x23000, 0x23001
COMPOSITE, COMPOSITE_PROP = 0x123000, 0x123001
ANIMATION, ANIM_GROUP_LIST, ANIM_GROUP = 0x121000, 0x121002, 0x121001
CAMERA, FRAME_CONTROLLER = 0x2200, 0x121201
WORLD_GEO, STATE_PROP = 0x8800003, 0x8800005
STATE_PROP_DATA, PROP_STATE, PROP_VISIBILITY = 0x0802000D, 0x0802000E, 0x08020002
MISSING_GLASS = [0.10, 0.13, 0.15, 0.45]
MISSING_SOLID = [0.12, 0.12, 0.12, 1.0]
LOOK_ENV = "SCARFACE_TEXTURE_LOOK"       # "xbox": PC textures get the Xbox's darker mid-tones (media.xbox_look)
EXPORT_VERSION = 4                     # 3: props kept with another area. 4: one stage of each place; insides in the city
_LOD_PART = re.compile(r"lod\d*(shape\d*)?$", re.I)
SCRIPT_OBJECT, OBJECT_PROPERTY, OBJECT_BINARY = 0x9900190, 0x9900192, 0x9900194
VECTOR_CHANNELS = (0x121102, 0x121103, 0x121104)
SHADOW_PARTS = 0x20 | 0x40           # a composite part's kind: 1 a model, 0x20 a shadow mesh, 0x40 a shadow skin

Vec3 = Tuple[float, float, float]
Quat = Tuple[float, float, float, float]          # x, y, z, w
Mat4 = List[List[float]]                          # rows of a column-vector matrix


class ExportError(ValueError):
    pass


def _text(data: bytes, p: int) -> Tuple[str, int]:
    n = data[p]
    return data[p + 1:p + 1 + n].split(b"\0")[0].decode("latin-1"), p + 1 + n


# --------------------------------------------------------------------------- maths

def _identity() -> Mat4:
    return [[1.0 if i == j else 0.0 for j in range(4)] for i in range(4)]


def _mul(a: Mat4, b: Mat4) -> Mat4:
    return [[sum(a[i][k] * b[k][j] for k in range(4)) for j in range(4)] for i in range(4)]


def _trs(t: Vec3, q: Quat, s: Vec3 = (1.0, 1.0, 1.0)) -> Mat4:
    x, y, z, w = q
    r = [[1 - 2 * (y * y + z * z), 2 * (x * y - z * w), 2 * (x * z + y * w)],
         [2 * (x * y + z * w), 1 - 2 * (x * x + z * z), 2 * (y * z - x * w)],
         [2 * (x * z - y * w), 2 * (y * z + x * w), 1 - 2 * (x * x + y * y)]]
    m = [[r[i][j] * s[j] for j in range(3)] + [t[i]] for i in range(3)]
    return m + [[0.0, 0.0, 0.0, 1.0]]


def _invert(m: Mat4) -> Mat4:
    """Inverse of an affine matrix."""
    a = [row[:3] for row in m[:3]]
    det = (a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])
           + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]))
    if abs(det) < 1e-12:
        return _identity()
    inv = [[(a[(j + 1) % 3][(i + 1) % 3] * a[(j + 2) % 3][(i + 2) % 3]
             - a[(j + 1) % 3][(i + 2) % 3] * a[(j + 2) % 3][(i + 1) % 3]) / det for j in range(3)] for i in range(3)]
    t = [-sum(inv[i][k] * m[k][3] for k in range(3)) for i in range(3)]
    return [inv[i] + [t[i]] for i in range(3)] + [[0.0, 0.0, 0.0, 1.0]]


def _quat_from_rows(r: Sequence[Sequence[float]]) -> Quat:
    """Quaternion of a rotation matrix (column-vector convention), as x, y, z, w."""
    tr = r[0][0] + r[1][1] + r[2][2]
    if tr > 0:
        s = math.sqrt(tr + 1.0) * 2
        q = ((r[2][1] - r[1][2]) / s, (r[0][2] - r[2][0]) / s, (r[1][0] - r[0][1]) / s, 0.25 * s)
    elif r[0][0] > r[1][1] and r[0][0] > r[2][2]:
        s = math.sqrt(1.0 + r[0][0] - r[1][1] - r[2][2]) * 2
        q = (0.25 * s, (r[0][1] + r[1][0]) / s, (r[0][2] + r[2][0]) / s, (r[2][1] - r[1][2]) / s)
    elif r[1][1] > r[2][2]:
        s = math.sqrt(1.0 + r[1][1] - r[0][0] - r[2][2]) * 2
        q = ((r[0][1] + r[1][0]) / s, 0.25 * s, (r[1][2] + r[2][1]) / s, (r[0][2] - r[2][0]) / s)
    else:
        s = math.sqrt(1.0 + r[2][2] - r[0][0] - r[1][1]) * 2
        q = ((r[0][2] + r[2][0]) / s, (r[1][2] + r[2][1]) / s, 0.25 * s, (r[1][0] - r[0][1]) / s)
    n = math.sqrt(sum(v * v for v in q)) or 1.0
    return tuple(v / n for v in q)  # type: ignore[return-value]


def _qmul(a: Quat, b: Quat) -> Quat:
    ax, ay, az, aw = a
    bx, by, bz, bw = b
    return (aw * bx + ax * bw + ay * bz - az * by, aw * by - ax * bz + ay * bw + az * bx,
            aw * bz + ax * by - ay * bx + az * bw, aw * bw - ax * bx - ay * by - az * bz)


# Pure3D is left-handed: mirror Z to get glTF's right-handed space.
def pos(v: Sequence[float]) -> Vec3:
    return (v[0], v[1], -v[2])


def rot(q: Sequence[float]) -> Quat:
    return (-q[0], -q[1], q[2], q[3])


def joint_trs(m: Sequence[float]) -> Tuple[Vec3, Quat, Vec3]:
    """A joint's 4x4 (row vectors, rows stored in order, translation in the last row) as glTF's
    translation, rotation and scale."""
    rows = [m[0:3], m[4:7], m[8:11]]
    scale = tuple(math.sqrt(sum(v * v for v in r)) or 1.0 for r in rows)
    unit = [[v / s for v in r] for r, s in zip(rows, scale)]
    col = [[unit[j][i] for j in range(3)] for i in range(3)]       # the same rotation for column vectors
    return pos(m[12:15]), rot(_quat_from_rows(col)), scale  # type: ignore[return-value]


def instance_trs(rec: Sequence[int]) -> Tuple[Vec3, Quat, Vec3]:
    """The 48-byte record an instance object's "instanceposition" holds (0x9900194: twelve 32-bit
    values) as glTF's translation, rotation and scale. The game packs it into bit fields as it loads it
    (default.xbe 0x677B0) and builds the matrix from those (0x8C540, 0x53E50), so the precision it keeps
    is kept here: height in whole centimetres, the X and Z angles in steps of 2 degrees."""
    x, y, z = (struct.unpack("<f", struct.pack("<I", rec[i] & 0xFFFFFFFF))[0] for i in range(3))
    height = max(-32768, min(32767, int(y))) * 0.01
    ax = ((rec[3] >> 1) & 0xFF) * 2
    ay = rec[4] & 0x1FF
    az = ((rec[5] >> 1) & 0xFF) * 2
    a, b, c = (math.radians(v) for v in (-ax, -ay, az))           # the game turns X and Y the other way
    qx = (math.sin(a / 2), 0.0, 0.0, math.cos(a / 2))
    qy = (0.0, math.sin(b / 2), 0.0, math.cos(b / 2))
    qz = (0.0, 0.0, math.sin(c / 2), math.cos(c / 2))
    q = _qmul(_qmul(qz, qy), qx)                                   # X first, then Y, then Z
    s0, s1, s2 = rec[6] & 0x3F, rec[7] & 0x3F, rec[8] & 0x3F
    if rec[9]:
        u = (s0 | s1 << 6 | s2 << 12) * 0.001
        scale = (u, u, u)
    else:
        scale = (s0 * 0.05, s1 * 0.05, s2 * 0.05)
    return pos((x, height, z)), rot(q), scale


# --------------------------------------------------------------------------- geometry

@dataclass
class Geometry:
    positions: List[Vec3]
    triangles: List[Tuple[int, int, int]]
    normals: Optional[List[Vec3]] = None
    uvs: List[List[Tuple[float, float]]] = field(default_factory=list)
    colours: Optional[List[int]] = None             # ARGB
    joints: Optional[List[Tuple[int, int, int, int]]] = None   # skeleton joint numbers
    weights: Optional[List[Tuple[float, float, float, float]]] = None


def _floats(data: bytes, c: p3d.Chunk, per: int, skip: int = 0) -> List[tuple]:
    s, _ = c.body
    n = struct.unpack_from("<I", data, s)[0]
    flat = array("f")
    flat.frombytes(data[s + 4 + skip:s + 4 + skip + 4 * per * n])
    if sys.byteorder != "little":
        flat.byteswap()
    return [tuple(flat[i:i + per]) for i in range(0, len(flat), per)]


def _u32s(data: bytes, c: p3d.Chunk) -> List[int]:
    s, _ = c.body
    n = struct.unpack_from("<I", data, s)[0]
    return list(struct.unpack_from(f"<{n}I", data, s + 4))


def _xbox_normal(v: int) -> Vec3:
    """D3DDECLTYPE_NORMPACKED3: x and y in 11 signed bits, z in 10."""
    x, y, z = v & 0x7FF, (v >> 11) & 0x7FF, (v >> 22) & 0x3FF
    x, y, z = x - (x >> 10) * 0x800, y - (y >> 10) * 0x800, z - (z >> 9) * 0x400
    return (x / 1023.0, y / 1023.0, z / 511.0)


def _vif_batches(blob: bytes) -> List[dict]:
    """The PS2 vertex packets of a primitive group (0x10012 after its 12-byte header): VIF codes, each
    batch a 4-quadword header (UNPACK V4-32 to address 0: the vertex count first, the third quadword
    the scales) and then one UNPACK per attribute, written every CL quadwords (STCYCL)."""
    p, out, cur = 0, [], None
    while p + 4 <= len(blob):
        code = struct.unpack_from("<I", blob, p)[0]
        cmd, num, imm = code >> 24, (code >> 16) & 0xFF, code & 0xFFFF
        p += 4
        if cmd & 0x60 == 0x60:                                         # UNPACK
            comps, bits, n = ((cmd >> 2) & 3) + 1, 32 >> (cmd & 3), num or 256
            packed = cmd & 3 == 3                                      # V4-5: 16 bits, 5-5-5-1
            size = ((16 * n if packed else bits * comps * n) + 31) // 32 * 4
            raw = blob[p:p + size]
            p += size
            if len(raw) < size:
                break
            addr = imm & 0x3FF
            if addr == 0 and comps == 4 and bits == 32 and n == 4:
                cur = {"count": struct.unpack_from("<I", raw, 0)[0], "scale": struct.unpack_from("<4f", raw, 32),
                       "attrs": {}}
                out.append(cur)
            elif cur is not None:
                if packed:
                    words = struct.unpack_from(f"<{n}H", raw)
                    vals = ints = tuple(x for w in words for x in ((w & 31) << 2, (w >> 3) & 124, (w >> 8) & 124,
                                                                (w >> 15) * 128))
                    comps = 4
                elif bits == 32:
                    vals = struct.unpack_from(f"<{n * comps}f", raw)
                    ints = struct.unpack_from(f"<{n * comps}I", raw)
                else:
                    code_ = {16: "h", 8: "b"}[bits]
                    if imm & 0x4000:
                        code_ = code_.upper()
                    vals = ints = struct.unpack_from(f"<{n * comps}{code_}", raw)
                cur["attrs"][addr] = (comps, bits, [vals[i * comps:(i + 1) * comps] for i in range(n)],
                                      [ints[i * comps] for i in range(n)])
        elif cmd == 0x20:                                              # STMASK and its word
            p += 4
        elif cmd in (0x30, 0x31):                                      # STROW, STCOL and their four words
            p += 16
        elif cmd in (0x50, 0x51):                                      # DIRECT
            p += (imm or 65536) * 16
        elif cmd == 0x4A:                                              # MPG
            p += (num or 256) * 8
    return out


def ps2_geometry(data: bytes, pg: p3d.Chunk, vtype: int) -> Optional[Geometry]:
    """A PS2 primitive group: batches of up to 72 vertices (54 for skins), each a strip of its own,
    with one quadword per attribute from address 4: the UV sets first (2 floats, or 16-bit numbers
    times a scale from the header), then a colour (4 bytes or 5-5-5-1 bits, 128 for full), the normal
    (3 signed bytes over 127, or floats), the position (3 floats, or 16- or 8-bit numbers times the header's
    first scale) and for skins the matrices (palette index x 4) and weights (16-bit; the first over
    4096, each next one over 4096 times the one before). The header's scales are position, normal,
    then the UVs' (the first UV set's last; on vehicles, whose vertices also carry two extra vectors,
    the first UV set's second). The lowest bit of a vertex's U is set when the triangle that ends at
    it is not drawn: the strip starts again there."""
    vb = pg.find(0x10012)
    if not vb:
        return None
    s, e = vb.body
    batches = _vif_batches(data[s + 12:e])
    if not batches:
        return None
    pal_c = pg.find(0x1000D)
    palette = _u32s(data, pal_c) if pal_c else []
    n_uv = vtype & 0xF
    g = Geometry([], [])
    g.normals = [] if vtype & 0x10 else None
    g.colours = [] if vtype & 0x20 else None
    g.uvs = [[] for _ in range(n_uv)]
    if vtype & 0x180:
        g.joints, g.weights = [], []
    for b in batches:
        n, scale = b["count"], b["scale"]
        attrs = [b["attrs"][a] for a in sorted(b["attrs"])]
        at = max((i for i, a in enumerate(attrs) if a[0] == 3), default=None)
        if at is None or len(attrs[at][2]) < n:
            return None
        uv_scales = (scale[1], scale[3]) if vtype & 0x100000 else (scale[3], scale[2])
        uvs = [a for a in attrs[:at] if a[0] == 2][:n_uv]
        flags = [v & 1 for v in uvs[0][3]] if uvs else [0] * n
        for i, a in enumerate(uvs):
            k = 1.0 if a[1] == 32 else uv_scales[min(i, 1)]
            g.uvs[i].extend((r[0] * k, r[1] * k) for r in a[2][:n])
        base = len(g.positions)
        k = 1.0 if attrs[at][1] == 32 else scale[0]
        g.positions.extend(tuple(v * k for v in r[:3]) for r in attrs[at][2][:n])
        if g.normals is not None:
            a = attrs[at - 1] if at > 0 and attrs[at - 1][0] == 3 else None
            if a is not None:
                k = 1.0 if a[1] == 32 else 1.0 / 127
                g.normals.extend(tuple(v * k for v in r[:3]) for r in a[2][:n])
            else:
                g.normals.extend([(0.0, 1.0, 0.0)] * n)
        if g.colours is not None:
            a = next((a for a in attrs[len(uvs):at] if a[0] == 4), None)
            for r in (a[2][:n] if a else [(64, 64, 64, 128)] * n):
                c = [min(255, int(v) * 2) for v in r[:4]]
                g.colours.append(c[3] << 24 | c[0] << 16 | c[1] << 8 | c[2])
        if g.joints is not None:
            mats = next((a[2] for a in attrs[at + 1:] if a[0] == 4 and a[1] == 8), [(0, 0, 0, 0)] * n)
            wts = next((a[2] for a in attrs[at + 1:] if a[0] == 4 and a[1] == 16), [(4096, 0, 0, 0)] * n)
            for m, w in zip(mats[:n], wts[:n]):
                ws = [w[0] / 4096.0]
                for j in range(1, 4):
                    ws.append(ws[-1] * w[j] / 4096.0)
                g.joints.append(tuple(palette[i // 4] if 0 <= i // 4 < len(palette) else 0 for i in m[:4]))
                g.weights.append(tuple(ws))
        for i in range(2, n):
            if flags[i]:
                continue
            a_, b_, c_ = base + i - 2, base + i - 1, base + i
            if len({g.positions[a_], g.positions[b_], g.positions[c_]}) < 3:
                continue
            g.triangles.append((a_, b_, c_) if i % 2 == 0 else (b_, a_, c_))
    return g


def geometry(data: bytes, pg: p3d.Chunk) -> Optional[Geometry]:
    """The vertices and triangles of a primitive group: plain lists (PC; Xbox skins) or an Xbox vertex
    buffer. None for the PS2's vector-unit packets."""
    r = p3d._R(data, *pg.body)
    r.u32()
    r.text()
    prim, vtype, count = r.u32(), r.u32(), r.u32()
    kids: Dict[int, List[p3d.Chunk]] = {}
    for k in pg.children:
        kids.setdefault(k.id, []).append(k)
    idx_c = kids.get(0x1000A, [None])[0]
    if 0x10005 in kids:
        positions = [tuple(v) for v in _floats(data, kids[0x10005][0], 3)]
        n = len(positions)
        g = Geometry(positions, [])
        if 0x10006 in kids:
            g.normals = _floats(data, kids[0x10006][0], 3)
        for uv in sorted(kids.get(0x10007, []), key=lambda c: struct.unpack_from("<I", data, c.body[0] + 4)[0]):
            g.uvs.append(_floats(data, uv, 2, skip=4))
        if 0x10008 in kids:
            g.colours = _u32s(data, kids[0x10008][0])
        if 0x1000C in kids and 0x1000B in kids:
            palette = _u32s(data, kids[0x1000D][0]) if 0x1000D in kids else list(range(256))
            packed = _u32s(data, kids[0x1000B][0])
            w3 = _floats(data, kids[0x1000C][0], 3)
            g.joints, g.weights = [], []
            for m, w in zip(packed, w3):
                ids = [(m >> sh) & 0xFF for sh in (24, 16, 8, 0)]      # the last byte goes with the first weight
                ws = [w[0], w[1], w[2], max(0.0, 1.0 - w[0] - w[1] - w[2])]
                g.joints.append(tuple(palette[i] if i < len(palette) else 0 for i in ids))  # type: ignore[arg-type]
                g.weights.append(tuple(ws))  # type: ignore[arg-type]
        indices = _u32s(data, idx_c) if idx_c else list(range(n))
    elif 0x10012 in kids and count and data[kids[0x10012][0].body[0]:kids[0x10012][0].body[0] + 4] == b"\x08\x00\x10\x00":
        return ps2_geometry(data, pg, vtype)
    elif 0x10012 in kids and count:
        s, _ = kids[0x10012][0].body
        size = struct.unpack_from("<I", data, s + 8)[0]
        stride = size // count
        extra = 4 * (bool(vtype & 0x4000) + bool(vtype & 0x10000))         # more colours, after the first
        layout = 12 + (4 if vtype & 0x10 else 0) + (4 if vtype & 0x20 else 0) + extra + 8 * (vtype & 0xF)
        layout += 24 if vtype & 0x100000 else 0
        if size % count or stride != layout or vtype & 0x180:
            positions = [struct.unpack_from("<3f", data, s + 12 + i * stride) for i in range(count)] \
                if not size % count and stride >= 12 else None
            if positions is None:
                return None
            g = Geometry(positions, [])
        else:
            g = Geometry([], [])
            g.normals = [] if vtype & 0x10 else None
            g.colours = [] if vtype & 0x20 else None
            g.uvs = [[] for _ in range(vtype & 0xF)]
            for i in range(count):
                o = s + 12 + i * stride
                g.positions.append(struct.unpack_from("<3f", data, o))
                o += 12
                if vtype & 0x10:
                    g.normals.append(_xbox_normal(struct.unpack_from("<I", data, o)[0]))  # type: ignore[union-attr]
                    o += 4
                if vtype & 0x20:
                    g.colours.append(struct.unpack_from("<I", data, o)[0])  # type: ignore[union-attr]
                    o += 4
                o += extra
                for uv in g.uvs:
                    uv.append(struct.unpack_from("<2f", data, o))
                    o += 8
        if 0x10013 in kids:
            s, _ = kids[0x10013][0].body
            size = struct.unpack_from("<I", data, s + 8)[0]
            indices = list(struct.unpack_from(f"<{size // 2}H", data, s + 12))
        else:
            indices = list(range(len(g.positions)))
    else:
        return None
    n = len(g.positions)
    g.triangles = [t for t in p3d._triangles(indices, prim) if max(t) < n]
    return g


# --------------------------------------------------------------------------- the files

@dataclass
class Ref:
    source: "Source"
    chunk: p3d.Chunk

    @property
    def data(self) -> bytes:
        return self.source.data

    @property
    def name(self) -> str:
        return chunk_name(self.data, self.chunk)


@dataclass
class Source:
    label: str
    data: bytes
    main: bool
    chunks: List[p3d.Chunk]
    pictures: Dict[str, media.Texture] = field(default_factory=dict)


def composite_prop(data: bytes, c: p3d.Chunk) -> Tuple[str, int, int]:
    """A composite drawable's part (0x123001): u32 0, u32 0, the drawable's name, u32 kind, u32 joint."""
    r = p3d._R(data, *c.body)
    r.u32()
    r.u32()
    name = r.text()
    return name, r.u32(), r.u32()


def chunk_name(data: bytes, c: p3d.Chunk) -> str:
    s, _ = c.body
    if c.id in (COMPOSITE, ANIMATION, STATE_PROP_DATA):
        s += 4                                           # a version first
    return _text(data, s)[0]


KINDS = {MESH: "mesh", SKIN: "skin", SHADER: "shader", SKELETON: "skeleton", COMPOSITE: "composite",
         STATE_PROP: "stateprop", STATE_PROP_DATA: "propstates"}


def prop_states(data: bytes, c: p3d.Chunk) -> List[Tuple[str, Dict[str, bool]]]:
    """A State Prop Data chunk's states, in order: (state name, {part name (lower case): shown}). The
    first is how the prop starts ("idle"); later ones are what it becomes ("final", "damage1"): a crate
    gone, a bin dented (its DamageShape shown, its InstanceShape hidden)."""
    out = []
    for st in c.children:
        if st.id != PROP_STATE:
            continue
        name = _text(data, st.body[0])[0]
        shown = {}
        for v in st.children:
            if v.id == PROP_VISIBILITY:
                part, p = _text(data, v.body[0])
                shown[part.lower()] = bool(struct.unpack_from("<I", data, p)[0])
        out.append((name, shown))
    return out


def lod_parts(parts: Sequence[str]) -> set:
    """The low-detail stand-ins (storeInterior2LODShape beside storeInterior2InstanceShape) a composite
    carries for far away, when it has a part that isn't one."""
    low = {p.lower() for p in parts if _LOD_PART.search(p)}
    return low if len(low) < len(parts) else set()


class Library:
    """Everything in a set of .p3d files, found by name the way the game finds it (letter case doesn't
    matter). Files given first win when two have the same name, unless a lookup says which files it
    prefers (a map area's own region, for the models its instances place)."""

    def __init__(self, parsed: Optional[dict] = None) -> None:
        self.sources: List[Source] = []
        self.named: Dict[str, Dict[str, List[Ref]]] = {k: {} for k in KINDS.values()}
        self.pictures: Dict[str, Tuple[Source, media.Texture]] = {}
        self.parsed = parsed if parsed is not None else {}     # id(data) -> (chunks, pictures), shared by exports

    def add(self, label: str, data: bytes, main: bool = True, keep: bool = True) -> Source:
        """keep: remember the parsed tree for the next Library sharing `parsed` (for files used again)."""
        if id(data) in self.parsed:
            _same, chunks, pictures = self.parsed[id(data)]
        else:
            chunks, pictures = p3d.read_tree(data), media.textures(data)
            if keep:
                self.parsed[id(data)] = (data, chunks, pictures)        # holding data keeps its id unique
        src = Source(label, data, main, chunks)
        self.sources.append(src)
        for c in chunks:
            kind = KINDS.get(c.id)
            if kind:
                try:
                    self.named[kind].setdefault(chunk_name(data, c).lower(), []).append(Ref(src, c))
                except IndexError:
                    pass
        for t in pictures:
            self.pictures.setdefault(t.name.lower(), (src, t))
        return src

    def find(self, kind: str, name: str, prefer: Sequence[Source] = ()) -> Optional[Ref]:
        refs = self.named[kind].get(name.lower())
        if not refs:
            return None
        for ref in refs:
            if any(ref.source is p for p in prefer):
                return ref
        return refs[0]

    def main_chunks(self, cid: int, sources: Optional[Sequence[Source]] = None) -> Iterable[Ref]:
        for src in (sources if sources is not None else self.sources):
            if src.main:
                for c in src.chunks:
                    if c.id == cid:
                        yield Ref(src, c)

    def shaders_used(self, src: Source) -> set:
        out = set()
        for c in p3d.walk(src.chunks):
            if c.id == PRIM_GROUP:
                out.add(p3d.fields(src.data, c).get("shader", "").lower())
        return out

    def region_of(self, src: Source) -> List[Source]:
        """The region files a map area uses: the *_region.p3d defining most of its shaders, and the
        *_region_D.p3d next to it, which holds the region's placed models (trees and the like)."""
        used = self.shaders_used(src)
        best, score = None, 0
        for other in self.sources:
            stem = Path(other.label).stem.lower()
            if not stem.endswith("_region"):
                continue
            n = sum(1 for c in other.chunks if c.id == SHADER and chunk_name(other.data, c).lower() in used)
            if n > score:
                best, score = other, n
        if best is None:
            return []
        want = Path(best.label).stem.lower() + "_d"
        return [best] + [o for o in self.sources if Path(o.label).stem.lower() == want]


def shader_info(data: bytes, c: p3d.Chunk) -> dict:
    f = p3d.fields(data, c)
    info = {"name": f.get("name", ""), "pddi": f.get("pddi shader", ""), "translucent": bool(f.get("translucent")),
            "textures": [], "ints": {}, "floats": {}, "colours": {}}
    for k in c.children:
        kf = p3d.fields(data, k)
        if k.id == 0x11002:
            info["textures"].append((kf["parameter"], kf["texture"]))
        elif k.id == 0x11003:
            info["ints"][kf["parameter"]] = kf["value"]
        elif k.id == 0x11004:
            info["floats"][kf["parameter"]] = kf["value"]
        elif k.id == 0x11005:
            info["colours"][kf["parameter"]] = int(kf["argb"], 16)
    return info


_SHADER_NAME = re.compile(r"^(?:Global|Region|Local)Shader_(.+?\.(?:tga|bmp|png))", re.I)
_SHADER_FLAG = re.compile(r"_(blmd|mcbv|lit|alpha|atst|alum|2sid)(\d+)", re.I)


def shader_from_name(name: str) -> Optional[dict]:
    """The map's shared shaders are named after what they do, for example
    GlobalShader_g_hedge.tga_simple_blmd1_mcbv0_lit1_alpha1_atst1_alum1_2sid0; read that when the
    shader itself is in a file not given."""
    m = _SHADER_NAME.match(name)
    if not m:
        return None
    ints = {k.upper(): int(v) for k, v in _SHADER_FLAG.findall(name)}
    return {"name": name, "pddi": "", "translucent": bool(ints.get("ALPHA")), "textures": [("TEX", m.group(1))],
            "ints": ints, "floats": {}, "colours": {}}


# --------------------------------------------------------------------------- glTF

class Gltf:
    def __init__(self) -> None:
        self.doc: dict = {"asset": {"version": "2.0", "generator": "scarface_decomp portal/tools/p3d_gltf.py"},
                          "scene": 0, "scenes": [{"name": "Scene", "nodes": []}], "nodes": [], "meshes": [],
                          "materials": [], "textures": [], "images": [], "samplers": [], "accessors": [],
                          "bufferViews": [], "buffers": [], "skins": [], "animations": []}
        self.bin = bytearray()
        self.used_extensions: set = set()

    def _view(self, blob: bytes, target: Optional[int] = None) -> int:
        while len(self.bin) % 4:
            self.bin.append(0)
        view = {"buffer": 0, "byteOffset": len(self.bin), "byteLength": len(blob)}
        if target:
            view["target"] = target
        self.bin += blob
        self.doc["bufferViews"].append(view)
        return len(self.doc["bufferViews"]) - 1

    def accessor(self, rows: Sequence, kind: str, ctype: int = 5126, normalized: bool = False,
                 bounds: bool = False, target: Optional[int] = None) -> int:
        """rows: one tuple per element, or plain numbers for SCALAR."""
        code = {5126: "f", 5125: "I", 5123: "H", 5121: "B"}[ctype]
        nested = bool(rows) and isinstance(rows[0], (tuple, list))
        flat = array(code, (v for row in rows for v in row) if nested else rows)
        if sys.byteorder != "little":
            flat.byteswap()
        acc = {"bufferView": self._view(flat.tobytes(), target), "componentType": ctype, "count": len(rows),
               "type": kind}
        if normalized:
            acc["normalized"] = True
        if bounds and rows:
            cols = list(zip(*rows)) if nested else [rows]
            acc["min"] = [min(c) for c in cols]
            acc["max"] = [max(c) for c in cols]
        self.doc["accessors"].append(acc)
        return len(self.doc["accessors"]) - 1

    def add(self, key: str, item: dict) -> int:
        self.doc.setdefault(key, []).append(item)
        return len(self.doc[key]) - 1

    def node(self, name: str, parent: Optional[int] = None, **kw) -> int:
        n = {"name": name}
        n.update({k: v for k, v in kw.items() if v is not None})
        i = self.add("nodes", n)
        if parent is None:
            self.doc["scenes"][0]["nodes"].append(i)
        else:
            self.doc["nodes"][parent].setdefault("children", []).append(i)
        return i

    def image(self, name: str, png: bytes) -> int:
        return self.add("images", {"name": name, "mimeType": "image/png", "bufferView": self._view(png)})

    def glb(self) -> bytes:
        doc = {k: v for k, v in self.doc.items() if v != [] or k in ("scenes", "nodes")}
        while len(self.bin) % 4:
            self.bin.append(0)
        doc["buffers"] = [{"byteLength": len(self.bin)}]
        if self.used_extensions:
            doc["extensionsUsed"] = sorted(self.used_extensions)
        js = json.dumps(doc, separators=(",", ":")).encode()
        js += b" " * (-len(js) % 4)
        total = 12 + 8 + len(js) + 8 + len(self.bin)
        return (struct.pack("<III", 0x46546C67, 2, total) + struct.pack("<II", len(js), 0x4E4F534A) + js
                + struct.pack("<II", len(self.bin), 0x004E4942) + bytes(self.bin))


# --------------------------------------------------------------------------- building a scene

@dataclass
class Report:
    models: List[str] = field(default_factory=list)
    animations: List[str] = field(default_factory=list)
    placed: int = 0
    unplaced: Dict[str, int] = field(default_factory=dict)        # model name -> instances left out
    missing_textures: set = field(default_factory=set)
    missing_drawables: set = field(default_factory=set)
    unread_groups: int = 0
    at_origin: int = 0
    unmatched_animations: int = 0

    def lines(self) -> List[str]:
        out = [f"{len(self.models)} model(s)" + (": " + ", ".join(self.models[:12]) + (" ..." if len(self.models) > 12 else "")
                                                 if self.models else "")]
        if self.animations:
            out.append(f"{len(self.animations)} animation(s): " + ", ".join(self.animations[:12])
                       + (" ..." if len(self.animations) > 12 else ""))
        if self.placed or self.unplaced:
            out.append(f"{self.placed} placed instance(s)")
        if self.unplaced:
            out.append(f"{sum(self.unplaced.values())} instance(s) of {len(self.unplaced)} model(s) not in the files "
                       "given (add the region's _D file and miami_lod_D.p3d with --library): "
                       + ", ".join(sorted(self.unplaced)[:20]))
        if self.at_origin:
            out.append(f"{self.at_origin} instance(s) left at (0, 0, 0), never placed, left out")
        if self.unmatched_animations:
            out.append(f"{self.unmatched_animations} animation(s) move joints not in this export (a vehicle file "
                       "holds the animations of the people getting in, for example): left out")
        if self.missing_textures:
            out.append(f"{len(self.missing_textures)} texture(s) not in the files given: "
                       + ", ".join(sorted(self.missing_textures)[:12]))
        if self.missing_drawables:
            out.append(f"{len(self.missing_drawables)} part(s) that aren't models (light flares, particles) or aren't in "
                       "these files, left out: " + ", ".join(sorted(self.missing_drawables)[:12]))
        if self.unread_groups:
            out.append(f"{self.unread_groups} primitive group(s) in a form not read, left out")
        return out


@dataclass
class SkeletonCopy:
    name: str
    nodes: Dict[str, int]            # joint name (lower case) -> node
    order: List[int]                 # nodes in joint order
    world: List[Mat4]                # rest pose, glTF space


class Builder:
    def __init__(self, lib: Library) -> None:
        self.lib = lib
        self.g = Gltf()
        self.report = Report()
        self.materials: Dict[str, int] = {}
        self.textures: Dict[str, Optional[int]] = {}
        self.meshes: Dict[Tuple[int, int], Optional[int]] = {}
        self.copies: List[SkeletonCopy] = []
        self.sampler: Optional[int] = None

    # materials

    def texture(self, name: str) -> Optional[int]:
        key = name.lower()
        if key in self.textures:
            return self.textures[key]
        found = self.lib.pictures.get(key)
        index = None
        if found:
            try:
                png = media.picture_png(found[0].data, found[1])
            except (media.MediaError, struct.error, ValueError, IndexError):
                png = None
            if png and found[1].kind == "png" and os.environ.get(LOOK_ENV) == "xbox":
                png = media.xbox_look(png)       # the PC keeps its textures as PNGs; the consoles' are left alone
            if png:
                if self.sampler is None:
                    self.sampler = self.g.add("samplers", {"magFilter": 9729, "minFilter": 9987,
                                                           "wrapS": 10497, "wrapT": 10497})
                index = self.g.add("textures", {"sampler": self.sampler, "source": self.g.image(name, png)})
        else:
            self.report.missing_textures.add(name)
        self.textures[key] = index
        return index

    def material(self, shader: str) -> int:
        key = shader.lower()
        if key in self.materials:
            return self.materials[key]
        ref = self.lib.find("shader", shader)
        info = shader_info(ref.data, ref.chunk) if ref else shader_from_name(shader)
        mat: dict = {"name": shader, "pbrMetallicRoughness": {"metallicFactor": 0.0, "roughnessFactor": 1.0}}
        if info:
            ints = info["ints"]
            tex = next((t for p, t in info["textures"] if p == "TEX"), None)
            if tex:
                ti = self.texture(tex)
                if ti is not None:
                    mat["pbrMetallicRoughness"]["baseColorTexture"] = {"index": ti}
                elif tex in self.report.missing_textures:
                    # a picture the game doesn't have either (the cars' windscreens and undersides): dark
                    # glass or dark metal, not a glaring white sheet
                    glass = bool(ints.get("BLMD") or info["translucent"])
                    mat["pbrMetallicRoughness"]["baseColorFactor"] = MISSING_GLASS if glass else MISSING_SOLID
            if ints.get("2SID"):
                mat["doubleSided"] = True
            if ints.get("ATST"):
                mat["alphaMode"], mat["alphaCutoff"] = "MASK", 0.5
            elif ints.get("BLMD") or info["translucent"]:
                mat["alphaMode"] = "BLEND"
            if ints.get("LIT") == 0 and "LIT" in ints:
                mat["extensions"] = {"KHR_materials_unlit": {}}
                self.g.used_extensions.add("KHR_materials_unlit")
        self.materials[key] = self.g.add("materials", mat)
        return self.materials[key]

    # meshes

    def mesh(self, ref: Ref, skinned_to: Optional[Dict[int, int]] = None) -> Optional[int]:
        """A glTF mesh for a Mesh or Skin chunk (one primitive per primitive group). For a skin,
        skinned_to maps skeleton joint numbers to the skin's joint list."""
        key = (id(ref.source), ref.chunk.offset)
        if key in self.meshes and skinned_to is None:
            return self.meshes[key]
        prims = []
        for pg in (k for k in ref.chunk.children if k.id == PRIM_GROUP):
            try:
                geo = geometry(ref.data, pg)
            except (struct.error, IndexError, ValueError):
                geo = None
            shader = p3d.fields(ref.data, pg).get("shader", "")
            if geo is None:
                self.report.unread_groups += 1
                continue
            if not geo.triangles:
                continue
            attrs = {"POSITION": self.g.accessor([pos(v) for v in geo.positions], "VEC3", bounds=True, target=34962)}
            if geo.normals and len(geo.normals) == len(geo.positions):
                attrs["NORMAL"] = self.g.accessor([_unit(pos(v)) for v in geo.normals], "VEC3", target=34962)
            for i, uv in enumerate(geo.uvs[:2]):
                if len(uv) == len(geo.positions):
                    attrs[f"TEXCOORD_{i}"] = self.g.accessor([(u, 1.0 - v) for u, v in uv], "VEC2", target=34962)
            if geo.colours and len(geo.colours) == len(geo.positions):
                attrs["COLOR_0"] = self.g.accessor([((c >> 16) & 255, (c >> 8) & 255, c & 255, (c >> 24) & 255)
                                                    for c in geo.colours], "VEC4", 5121, normalized=True, target=34962)
            if skinned_to is not None and geo.joints and geo.weights:
                joints, weights = [], []
                for js, ws in zip(geo.joints, geo.weights):
                    pairs = [(skinned_to.get(j, 0), w) for j, w in zip(js, ws)]
                    total = sum(w for _, w in pairs) or 1.0
                    joints.append([j if w > 0 else 0 for j, w in pairs])
                    weights.append([w / total for _, w in pairs])
                big = max(max(j) for j in joints) > 255
                attrs["JOINTS_0"] = self.g.accessor(joints, "VEC4", 5123 if big else 5121, target=34962)
                attrs["WEIGHTS_0"] = self.g.accessor(weights, "VEC4", target=34962)
            flat = [i for a, b, c in geo.triangles for i in (a, c, b)]      # turned round for the mirroring
            big = len(geo.positions) > 65535
            prims.append({"attributes": attrs, "indices": self.g.accessor(flat, "SCALAR", 5125 if big else 5123,
                                                                          target=34963),
                          "material": self.material(shader), "mode": 4})
        index = self.g.add("meshes", {"name": ref.name, "primitives": prims}) if prims else None
        if skinned_to is None:
            self.meshes[key] = index
        return index

    # skeletons

    def skeleton(self, ref: Ref, parent: Optional[int], name: str = "") -> SkeletonCopy:
        joints = [k for k in ref.chunk.children if k.id == JOINT]
        nodes: List[int] = []
        world: List[Mat4] = []
        names: Dict[str, int] = {}
        group = self.g.node(name or ref.name, parent)
        for i, j in enumerate(joints):
            r = p3d._R(ref.data, *j.body)
            jname, par = r.text(), r.u32()
            m = r.floats(16)
            t, q, s = joint_trs(m)
            up = nodes[par] if 0 <= par < i else group
            extra = {"scale": list(s)} if any(abs(v - 1.0) > 1e-5 for v in s) else {}
            n = self.g.node(jname, up, translation=list(t), rotation=list(q), **extra)
            nodes.append(n)
            local = _trs(t, q, s)
            world.append(_mul(world[par], local) if 0 <= par < i else local)
            names.setdefault(jname.lower(), n)
        copy = SkeletonCopy(ref.name, names, nodes, world)
        copy.group = group  # type: ignore[attr-defined]
        self.copies.append(copy)
        return copy

    def skin(self, ref: Ref, skel: SkeletonCopy, parent: Optional[int]) -> Optional[int]:
        ibm = [[_invert(w)[r][c] for c in range(4) for r in range(4)] for w in skel.world]
        joint_map = {i: i for i in range(len(skel.order))}
        mesh = self.mesh(ref, joint_map)
        if mesh is None:
            return None
        skin = self.g.add("skins", {"name": ref.name, "joints": skel.order,
                                    "inverseBindMatrices": self.g.accessor(ibm, "MAT4"),
                                    "skeleton": skel.group})  # type: ignore[attr-defined]
        return self.g.node(ref.name, parent, mesh=mesh, skin=skin)

    # models

    def states_of(self, ref: Ref, name: str) -> List[Tuple[str, Dict[str, bool]]]:
        """The states of the prop a composite drawable is the model of (none for most)."""
        cache = self.__dict__.setdefault("_states", {})
        key = id(ref.chunk)
        if key not in cache:
            cache[key] = self._states_of(ref, name)
        return cache[key]

    def _states_of(self, ref: Ref, name: str) -> List[Tuple[str, Dict[str, bool]]]:
        data = self.lib.find("propstates", name, (ref.source,))
        if data is None:
            for refs in self.lib.named["stateprop"].values():
                for sp in refs:
                    p = _text(sp.data, sp.chunk.body[0])[1]
                    if _text(sp.data, p)[0].lower() == name.lower():
                        data = self.lib.find("propstates", sp.name, (sp.source,))
                        break
                if data is not None:
                    break
        return prop_states(data.data, data.chunk) if data is not None else []

    def composite(self, ref: Ref, parent: Optional[int] = None, label: str = "", state: int = 0, **place) -> int:
        """A composite drawable: its skeleton's joints, with each part (a mesh or a skin) on its joint.
        Its skeleton and parts are looked for in its own file first. Only the parts shown in the prop's
        state are put in (the first state: how the game starts it, before anything breaks it), and only the
        full-detail ones: the low-detail stand-ins for far away are left out."""
        r = p3d._R(ref.data, *ref.chunk.body)
        r.u32()
        name, skel_name = r.text(), r.text()
        own = (ref.source,)
        parts = [composite_prop(ref.data, k) for k in ref.chunk.children if k.id == COMPOSITE_PROP]
        hidden = lod_parts([p for p, kind, _j in parts if not kind & SHADOW_PARTS])
        states = self.states_of(ref, name)
        if states:
            shown = states[min(state, len(states) - 1)][1]
            hidden |= {p for p, on in shown.items() if not on}
        sref = self.lib.find("skeleton", skel_name, own)
        if sref:
            copy = self.skeleton(sref, parent, label or name)
            top = copy.group  # type: ignore[attr-defined]
        else:
            copy = None
            top = self.g.node(label or name, parent)
        if place:
            self.g.doc["nodes"][top].update({k: list(v) for k, v in place.items()})
        for k in ref.chunk.children:
            if k.id != COMPOSITE_PROP:
                continue
            part, kind, joint = composite_prop(ref.data, k)
            if kind & SHADOW_PARTS or part.lower() in hidden:
                continue                                        # shadow volumes, far-away and broken versions
            at = copy.order[joint] if copy and 0 <= joint < len(copy.order) else top
            mref = self.lib.find("mesh", part, own)
            if mref:
                mesh = self.mesh(mref)
                if mesh is not None:
                    self.g.node(part, at, mesh=mesh)
                continue
            sk = self.lib.find("skin", part, own)
            if sk and copy:
                self.skin(sk, copy, top)
                continue
            inner = self.lib.find("composite", part, own)
            if inner and inner.chunk is not ref.chunk:
                self.composite(inner, at)
                continue
            self.report.missing_drawables.add(part)
        return top

    def skinned_model(self, ref: Ref, parent: Optional[int] = None) -> Optional[int]:
        r = p3d._R(ref.data, *ref.chunk.body)
        name = r.text()
        r.u32()
        skel_name = r.text()
        sref = self.lib.find("skeleton", skel_name, (ref.source,))
        if not sref:
            self.report.missing_drawables.add(skel_name)
            return None
        copy = self.skeleton(sref, parent, name)
        self.skin(ref, copy, copy.group)  # type: ignore[attr-defined]
        return copy.group  # type: ignore[attr-defined]

    # cameras

    def camera(self, ref: Ref, anim: Optional[Ref] = None) -> int:
        """A camera node (glTF looks down -Z), moved and turned by its animation if it has one."""
        cam = camera_chunk(ref.data, ref.chunk)
        aspect = 4 / 3                                       # the game's screen
        yfov = 2 * math.atan(math.tan(max(0.01, min(3.0, cam["fov"])) / 2) / aspect)
        ci = self.g.add("cameras", {"name": cam["name"], "type": "perspective", "perspective": {
            "aspectRatio": aspect, "yfov": yfov, "znear": max(0.001, cam["near"]),
            "zfar": max(cam["far"], cam["near"] + 1)}})
        node = self.g.node(cam["name"] or "camera", None, camera=ci, translation=pos(cam["position"]),
                           rotation=camera_rotation(cam["look"], cam["up"]))
        if anim is not None:
            self.camera_animation(anim, node)
        self.report.models.append(cam["name"] or "camera")
        return node

    def camera_animation(self, ref: Ref, node: int) -> bool:
        data, c = ref.data, ref.chunk
        info = p3d.fields(data, c)
        rate = info.get("frame rate") or 30.0
        keys: Dict[str, Tuple[List[int], List[tuple]]] = {}
        for ch in p3d.walk(c.children):
            if ch.id in VECTOR_CHANNELS:
                try:
                    param, frames, vals = _vector_keys(data, ch)
                except (p3d.P3dError, struct.error, IndexError, KeyError):
                    continue
                if frames:
                    keys[param] = (frames, vals)
        channels, samplers = [], []

        def add(times: List[float], out: List[tuple], kind: str, path: str) -> None:
            samplers.append({"input": self.g.accessor([(t,) for t in times], "SCALAR", bounds=True),
                             "output": self.g.accessor(out, kind), "interpolation": "LINEAR"})
            channels.append({"sampler": len(samplers) - 1, "target": {"node": node, "path": path}})

        def rising(frames: List[int]) -> List[int]:
            out, last = [], -1
            for f in frames:
                if f > last:
                    out.append(f)
                    last = f
            return out

        if "TRAN" in keys:
            frames, vals = keys["TRAN"]
            fs = rising(frames)
            add([f / rate for f in fs], [pos(_at(frames, vals, f)) for f in fs], "VEC3", "translation")
        if "LOOK" in keys:
            look = keys["LOOK"]
            up = keys.get("UP", ([0], [(0.0, 1.0, 0.0)]))
            fs = rising(sorted(set(look[0]) | set(up[0])))
            out, prev = [], None
            for f in fs:
                q = camera_rotation(_at(*look, f), _at(*up, f))
                if prev and sum(a * b for a, b in zip(q, prev)) < 0:
                    q = tuple(-a for a in q)
                out.append(q)
                prev = q
            add([f / rate for f in fs], out, "VEC4", "rotation")
        if not channels:
            return False
        self.g.add("animations", {"name": info.get("name") or "camera", "channels": channels, "samplers": samplers})
        self.report.animations.append(info.get("name") or "camera")
        return True


    # animations

    def animation(self, ref: Ref) -> bool:
        data, c = ref.data, ref.chunk
        info = p3d.fields(data, c)
        rate = info.get("frame rate") or 30.0
        groups = []
        gl = c.find(ANIM_GROUP_LIST)
        for gc in (gl.children if gl else []):
            if gc.id == ANIM_GROUP:
                groups.append((p3d.fields(data, gc).get("name", "").lower(), gc))
        if not groups or not self.copies:
            return False
        best = max(self.copies, key=lambda cp: sum(n in cp.nodes for n, _ in groups))
        if not any(n in best.nodes for n, _ in groups):
            return False
        channels, samplers = [], []
        for gname, gc in groups:
            node = best.nodes.get(gname)
            if node is None:
                continue
            for ch in gc.children:
                if ch.id not in p3d.QUATERNION_CHANNELS and ch.id not in VECTOR_CHANNELS:
                    continue
                try:
                    param, frames, values = p3d.channel_keys(data, ch)
                except (p3d.P3dError, struct.error, IndexError):
                    continue
                if not frames:
                    continue
                if ch.id in p3d.QUATERNION_CHANNELS:
                    path, out, prev = "rotation", [], None
                    for v in values:
                        q = rot(v)
                        if prev and sum(a * b for a, b in zip(q, prev)) < 0:
                            q = tuple(-a for a in q)
                        out.append(q)
                        prev = q
                    kind = "VEC4"
                else:
                    if param not in ("TRAN", "TRA"):
                        continue
                    path, kind = "translation", "VEC3"
                    out = [pos(v) for v in _vector_keys(data, ch)[2]]
                keep, last = [], -1
                for i, f in enumerate(frames):                       # glTF wants the times to rise
                    if f > last:
                        keep.append(i)
                        last = f
                times = [frames[i] / rate for i in keep]
                samplers.append({"input": self.g.accessor([(t,) for t in times], "SCALAR", bounds=True),
                                 "output": self.g.accessor([out[i] for i in keep], kind), "interpolation": "LINEAR"})
                channels.append({"sampler": len(samplers) - 1, "target": {"node": node, "path": path}})
        if not channels:
            return False
        self.g.add("animations", {"name": info.get("name") or "animation", "channels": channels, "samplers": samplers})
        self.report.animations.append(info.get("name") or "animation")
        return True


def _vector_keys(data: bytes, ch: p3d.Chunk) -> Tuple[str, List[int], List[Vec3]]:
    """A vector channel's (parameter, key frames, x y z per key): a Vector1DOF or Vector2DOF channel's
    moving components put back with its constants."""
    param, frames, values = p3d.channel_keys(data, ch)
    if ch.id not in (0x121102, 0x121103):
        return param, frames, [tuple(v) for v in values]  # type: ignore[misc]
    f = p3d.fields(data, ch)
    mapping, const = f["mapping"], f["constants"]
    moving = [mapping] if ch.id == 0x121102 else [i for i in range(3) if i != mapping]
    full = []
    for v in values:
        xyz = list(const)
        for i, val in zip(moving, v):
            xyz[i] = val
        full.append(tuple(xyz))
    return param, frames, full  # type: ignore[return-value]


def _at(frames: List[int], values: List[tuple], f: float) -> tuple:
    """A channel's value at frame f, in a straight line between its keys (held before the first and after
    the last)."""
    if f <= frames[0] or len(frames) == 1:
        return values[0]
    for i in range(1, len(frames)):
        if f <= frames[i]:
            a, b = frames[i - 1], frames[i]
            t = (f - a) / (b - a) if b > a else 1.0
            return tuple(x + (y - x) * t for x, y in zip(values[i - 1], values[i]))
    return values[-1]


def _cross(a: Sequence[float], b: Sequence[float]) -> Vec3:
    return (a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0])


def camera_rotation(look: Sequence[float], up: Sequence[float]) -> Quat:
    """glTF's rotation for a camera looking along look (a direction, Pure3D's space) with up above it: a
    glTF camera looks down its -Z with +Y up."""
    z = _unit(tuple(-v for v in pos(look)))                              # type: ignore[arg-type]
    x = _cross(pos(up), z)
    if math.sqrt(sum(v * v for v in x)) < 1e-9:                          # looking straight along up
        x = _cross((0.0, 0.0, 1.0) if abs(z[1]) > 0.9 else (0.0, 1.0, 0.0), z)
    x = _unit(x)
    y = _cross(z, x)
    return _quat_from_rows([[x[0], y[0], z[0]], [x[1], y[1], z[1]], [x[2], y[2], z[2]]])


def frame_controller(data: bytes, c: p3d.Chunk) -> Tuple[str, str, str]:
    """A Frame Controller (0x121201): (its type, what it drives, the animation it plays). Version, name,
    type (CAM, PTRN ...), "ANIM", two numbers, then the driven object's name and the animation's."""
    _name, p = _text(data, c.body[0] + 4)
    kind = data[p:p + 4].rstrip(b"\0").decode("latin-1")
    target, p = _text(data, p + 16)
    anim, _p = _text(data, p)
    return kind, target.rstrip("\0"), anim.rstrip("\0")


def _cameras(lib: "Library", b: "Builder") -> set:
    """Every camera in the main files, with the animation its frame controller plays (or the file's only
    camera animation). Returns those animations, so they aren't tried on skeletons."""
    cams = list(lib.main_chunks(CAMERA))
    moves = {}
    for ref in lib.main_chunks(ANIMATION):
        if (p3d.fields(ref.data, ref.chunk).get("type") or "").upper() == "CAM":
            moves[ref.name.lower()] = ref
    links = {}
    for ref in lib.main_chunks(FRAME_CONTROLLER):
        try:
            kind, target, anim = frame_controller(ref.data, ref.chunk)
        except (struct.error, IndexError, UnicodeDecodeError):
            continue
        if kind.upper() == "CAM":
            links[target.lower()] = anim.lower()
    for ref in cams:
        try:
            name = camera_chunk(ref.data, ref.chunk)["name"].lower()
        except (struct.error, IndexError):
            continue
        anim = moves.get(links.get(name, "")) or moves.get("cam_" + name)
        if anim is None and len(moves) == 1 and len(cams) == 1:
            anim = next(iter(moves.values()))
        b.camera(ref, anim)
    return {id(r.chunk) for r in moves.values()}


def camera_chunk(data: bytes, c: p3d.Chunk) -> dict:
    """A Camera chunk (0x2200): name, version, field of view (radians, across), aspect, near and far
    clip, position, look direction and up."""
    name, p = _text(data, c.body[0])
    v = struct.unpack_from("<I13f", data, p)
    return {"name": name, "fov": v[1], "aspect": v[2], "near": v[3], "far": v[4],
            "position": v[5:8], "look": v[8:11], "up": v[11:14]}


def _unit(v: Vec3) -> Vec3:
    n = math.sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2])
    return (v[0] / n, v[1] / n, v[2] / n) if n > 1e-12 else (0.0, 1.0, 0.0)


# --------------------------------------------------------------------------- what to export

def _composite_parts(lib: Library) -> set:
    """Names of everything some composite drawable hangs on a joint."""
    used = set()
    for refs in lib.named["composite"].values():
        for ref in refs:
            for k in ref.chunk.children:
                if k.id == COMPOSITE_PROP:
                    try:
                        used.add(composite_prop(ref.data, k)[0].lower())
                    except (IndexError, struct.error):
                        pass
    return used


def _has_model(lib: Library, ref: Ref) -> bool:
    """Whether a composite drawable has a part worth showing (not only a shadow)."""
    for k in ref.chunk.children:
        if k.id == COMPOSITE_PROP:
            name, kind, _joint = composite_prop(ref.data, k)
            if not kind & SHADOW_PARTS and any(lib.find(t, name) for t in ("mesh", "skin", "composite")):
                return True
    return False


def instance_objects(src: Source) -> List[Tuple[str, List[List[int]]]]:
    """(model name, records) for every instance object in a file: script objects (0x9900190) of class
    instanceobject, whose "modelname" property names the model and whose "instanceposition"
    properties (binary, 0x9900194) each place one copy."""
    out = []
    for top in src.chunks:
        if top.id != 0x9900191:
            continue
        for obj in p3d.walk(top.children):
            if obj.id != SCRIPT_OBJECT:
                continue
            p = obj.body[0]
            strings = []
            for _ in range(3):
                t, p = _text(src.data, p)
                strings.append(t)
            if strings[2].lower() != "instanceobject":
                continue
            model, records = "", []
            for prop in obj.children:
                if prop.id != OBJECT_PROPERTY:
                    continue
                pname, q = _text(src.data, prop.body[0])
                ptype = struct.unpack_from("<I", src.data, q)[0]
                if pname.lower() == "modelname" and ptype == 0:
                    model = _text(src.data, q + 4)[0]
                elif pname.lower() == "instanceposition":
                    for b in prop.children:
                        if b.id == OBJECT_BINARY and b.head - 12 >= 48:
                            records.append(list(struct.unpack_from("<12I", src.data, b.body[0])))
            if model and records:
                out.append((model, records))
    return out


def _model_for(lib: Library, name: str, prefer: Sequence[Source]) -> Optional[Ref]:
    """The model an instance object names: a composite drawable of that name, or a state prop's."""
    ref = lib.find("composite", name, prefer)
    if ref:
        return ref
    sp = lib.find("stateprop", name, prefer)
    if sp:
        p = _text(sp.data, sp.chunk.body[0])[1]
        return lib.find("composite", _text(sp.data, p)[0], (sp.source,) + tuple(prefer))
    return None


def _is_lod(src: Source) -> bool:
    return "_lod" in Path(src.label).stem.lower()


def _world_geo(lib: Library, src: Source) -> List[str]:
    out = []
    for ref in lib.main_chunks(WORLD_GEO, [src]):
        r = p3d._R(ref.data, *ref.chunk.body)
        r.text()
        out.append(r.text())
    return out


def export(lib: Library, map_mode: bool = False, only: Sequence[str] = (), anims: Sequence[Ref] = (),
           lod: bool = False) -> Tuple[bytes, Report]:
    """The glTF (.glb) for the library's main files, and a report of what went in.

    Models (the default): every skin with its skeleton, every composite drawable that isn't a map's
    world geometry, and every mesh no composite uses, side by side.
    Map (map_mode): per file, its world geometry (WorldGeo 0x8800003 names a composite drawable whose
    meshes sit in world space) and a copy of each model its instance objects place. Low-detail files
    (miami_lod, islands_LOD) are left out when there's anything else, unless lod is set."""
    b = Builder(lib)
    wanted = {n.lower() for n in only}
    if map_mode:
        mains = [src for src in lib.sources if src.main]
        if not lod and any(not _is_lod(src) and _world_geo(lib, src) for src in mains):
            mains = [src for src in mains if not _is_lod(src)]
        for src in mains:
            comps = [c for c in _world_geo(lib, src) if not wanted or c.lower() in wanted]
            placing = [(m, r) for m, r in instance_objects(src) if not wanted or m.lower() in wanted]
            if not comps and not placing:
                continue
            group = b.g.node(Path(src.label).stem)
            prefer = [src] + lib.region_of(src)
            for comp in comps:
                cref = lib.find("composite", comp, prefer)
                if cref:
                    b.composite(cref, group)
                    b.report.models.append(comp)
                else:
                    b.report.missing_drawables.add(comp)
            if not placing:
                continue
            placed = b.g.node(Path(src.label).stem + " instances", group)
            for model, records in placing:
                mref = _model_for(lib, model, prefer)
                if not mref:
                    b.report.unplaced[model] = b.report.unplaced.get(model, 0) + len(records)
                    continue
                for rec in records:
                    if not any(rec[:3]):
                        b.report.at_origin += 1             # never moved from (0, 0, 0): left out
                        continue
                    t, q, sc = instance_trs(rec)
                    b.composite(mref, placed, model, translation=t, rotation=q, scale=sc)
                    b.report.placed += 1
    else:
        parts = _composite_parts(lib)
        world = {c.lower() for src in lib.sources for c in _world_geo(lib, src)}
        tops: List[Tuple[str, int]] = []
        for ref in lib.main_chunks(SKIN):
            name = ref.name
            if (wanted and name.lower() not in wanted) or (not wanted and name.lower() in parts):
                continue
            top = b.skinned_model(ref)
            if top is not None:
                tops.append((name, top))
        for ref in lib.main_chunks(COMPOSITE):
            name = ref.name
            if (wanted and name.lower() not in wanted) or (not wanted and name.lower() in world):
                continue
            if not wanted and not _has_model(lib, ref):
                continue
            tops.append((name, b.composite(ref)))
            states = b.states_of(ref, name)                     # what it becomes: beside it, kept apart
            for i, (state, shown) in enumerate(states[1:], 1):
                if shown != states[0][1] and any(shown.values()):
                    label = f"{name} ({state})"
                    tops.append((label, b.composite(ref, label=label, state=i)))
        for ref in lib.main_chunks(MESH):
            name = ref.name
            if (wanted and name.lower() not in wanted) or (not wanted and name.lower() in parts):
                continue
            mesh = b.mesh(ref)
            if mesh is not None:
                tops.append((name, b.g.node(name, None, mesh=mesh)))
        _lay_out(b, tops)
        b.report.models = [n for n, _ in tops]
    camera_moves = _cameras(lib, b) if not map_mode else set()
    for ref in list(anims) + list(lib.main_chunks(ANIMATION)):
        if id(ref.chunk) in camera_moves:
            continue
        if not b.animation(ref):
            b.report.unmatched_animations += 1
    if not b.g.doc["scenes"][0]["nodes"]:
        raise ExportError("nothing in these files to export" + (" (is it a map area? try --map)" if not map_mode and
                                                                 any(_world_geo(lib, s) for s in lib.sources) else ""))
    return b.g.glb(), b.report


def _bounds(b: Builder, node: int, m: Mat4, out: List[List[float]]) -> None:
    n = b.g.doc["nodes"][node]
    local = _trs(tuple(n.get("translation", (0, 0, 0))), tuple(n.get("rotation", (0, 0, 0, 1))),
                 tuple(n.get("scale", (1, 1, 1))))
    m = _mul(m, local)
    if "mesh" in n:
        for prim in b.g.doc["meshes"][n["mesh"]]["primitives"]:
            acc = b.g.doc["accessors"][prim["attributes"]["POSITION"]]
            for corner in ((x, y, z) for x in (acc["min"][0], acc["max"][0]) for y in (acc["min"][1], acc["max"][1])
                           for z in (acc["min"][2], acc["max"][2])):
                w = [sum(m[i][k] * (corner + (1,))[k] for k in range(4)) for i in range(3)]
                out.append(w)
    for c in n.get("children", []):
        _bounds(b, c, m, out)


def _lay_out(b: Builder, tops: List[Tuple[str, int]]) -> None:
    """Put several models side by side along X instead of on top of each other."""
    if len(tops) < 2:
        return
    x = 0.0
    for _name, node in tops:
        pts: List[List[float]] = []
        _bounds(b, node, _identity(), pts)
        if not pts:
            continue
        lo, hi = min(p[0] for p in pts), max(p[0] for p in pts)
        n = b.g.doc["nodes"][node]
        t = list(n.get("translation", (0.0, 0.0, 0.0)))
        t[0] += x - lo
        n["translation"] = t
        x += (hi - lo) + max(0.25, 0.2 * (hi - lo))


# --------------------------------------------------------------------------- command line

MAP_LIBRARY = ("*_region.p3d", "*_region_D.p3d", "*_lod.p3d", "*_lod_D.p3d", "Common.p3d")


def _files(paths: Sequence[Path]) -> List[Path]:
    """Files, folders (every .p3d inside) and wildcards (for Windows, whose shell leaves them alone)."""
    out: List[Path] = []
    for p in paths:
        if any(ch in str(p) for ch in "*?["):
            out += sorted(q for q in Path(p.anchor or ".").glob(str(p.relative_to(p.anchor)) if p.anchor else str(p))
                          if q.is_file())
        elif p.is_dir():
            out += sorted(q for q in p.rglob("*") if q.suffix.lower() == ".p3d")
        else:
            out.append(p)
    seen, unique = set(), []
    for p in out:
        if p.resolve() not in seen:
            seen.add(p.resolve())
            unique.append(p)
    return unique


def map_library(files: Sequence[Path]) -> List[Path]:
    """For a map export with no --library: the shared files in the map areas' own folders (the regions'
    shaders and placed models, the low-detail city's global shaders and placed models)."""
    out: List[Path] = []
    for folder in sorted({f.parent for f in files}):
        for pattern in MAP_LIBRARY:
            out += sorted(q for q in folder.glob(pattern) if q.is_file())
    return out


def _area(path: Path) -> str:
    """A map area's name: stripmall_01_detailB.p3d -> stripmall_01."""
    return re.sub(r"_(shell|detail[a-z]?|pocket|dzone)(_[a-z0-9]+)?$", "", path.stem, flags=re.I)


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description="Turn Pure3D (.p3d) files into a glTF (.glb) scene for Blender.")
    ap.add_argument("out", type=Path, help="the .glb file to write (a folder with --split)")
    ap.add_argument("files", type=Path, nargs="+", help=".p3d files, folders or wildcards to export")
    ap.add_argument("--anim", type=Path, nargs="*", default=[], help="animation files to add")
    ap.add_argument("--library", type=Path, nargs="*", default=None,
                    help="more .p3d files or folders to take textures, shaders and placed models from")
    ap.add_argument("--map", action="store_true", help="export map areas with their placed instances")
    ap.add_argument("--lod", action="store_true", help="with --map, keep the low-detail city too")
    ap.add_argument("--split", action="store_true",
                    help="with --map, one .glb per map area in the folder OUT (they line up when imported together)")
    ap.add_argument("--only", nargs="*", default=[], help="just these models")
    ap.add_argument("--list", action="store_true", help="say what would be exported, write nothing")
    a = ap.parse_args(argv)
    try:
        mains = _files(a.files)
        if not mains:
            raise ExportError("no .p3d files there")
        extra = _files(a.library) if a.library is not None else (map_library(mains) if a.map else [])
        anims = _files(a.anim)
        groups = [mains]
        if a.split:
            if not a.map:
                raise ExportError("--split is for --map")
            by: Dict[str, List[Path]] = {}
            for f in mains:
                by.setdefault(_area(f), []).append(f)
            groups = [g for g in by.values() if a.lod or not all("_lod" in f.stem.lower() for f in g)]
            if len(groups) < len(by):
                print(f"({len(by) - len(groups)} low-detail city file group(s) left out; --lod keeps them)")
            if not a.list:
                a.out.mkdir(parents=True, exist_ok=True)
        cache: Dict[Path, bytes] = {}
        parsed: dict = {}
        empty = 0

        def read(f: Path) -> bytes:
            if f not in cache:
                cache[f] = f.read_bytes()
            return cache[f]

        for group in groups:
            lib = Library(parsed)
            mine = {f.resolve() for f in group}
            for f in group:
                lib.add(f.name, read(f), main=True)
            refs = []
            for f in anims:
                src = lib.add(f.name, read(f), main=False)
                refs += [Ref(src, c) for c in src.chunks if c.id == ANIMATION]
            for f in extra:
                if f.resolve() not in mine:
                    lib.add(f.name, read(f), main=False)
            try:
                glb, report = export(lib, a.map, a.only, refs, a.lod)
            except ExportError:
                if a.split:
                    empty += 1                                  # a region, a shared file: no area of its own
                    continue
                raise
            out = a.out / (_area(group[0]) + ".glb") if a.split else a.out
            if a.split:
                print(f"== {out.name}")
            for line in report.lines():
                print(line)
            if not a.list:
                out.write_bytes(glb)
                print(f"wrote {out} ({len(glb):,} bytes)")
        if a.split and empty:
            print(f"({empty} file group(s) with no map area of their own, such as regions and shared files, used "
                  "only for what the areas need)")
    except (OSError, p3d.P3dError, ExportError) as e:
        print(f"p3d_gltf: {e}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
