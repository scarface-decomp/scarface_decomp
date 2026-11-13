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
                                  (and the sea in OUT/ocean.glb)
        --lod                     with --map: keep the low-detail city (miami_lod) next to real areas, its
                                  hull marked hidden so that it doesn't cover them
        --no-ocean                with --map: no sea (else a flat sea at height 0 round the map)
        --hour H                  with --map: light the daylight for this hour (0 to 24) from its LITE
                                  animations; without it, the lights as stored (midnight). Without --map,
                                  for the sky (Common.p3d): the sun where the game puts it at that hour,
                                  and the sky's colours of that hour. Either way the scene's extras get
                                  the fog of that hour, if the game's scripts are found
        --weather clear|rain      which daylight lights the scene (the other is kept as data only), which
                                  sky and which fog; clear when not given, as the game starts
        --scripts FILE_OR_FOLDER  where the game's scripts are (scriptc/graphanims.cso for Miami,
                                  island_envobjects.cso for the islands), for the fog; without it they are
                                  looked for in the files' folder and up to three folders above it, and
                                  in a scriptc folder in any of those
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
    a Light (0x13000), with --map    a node in its light group's node; point and spot lights and the
                                     city-wide directional ones as glTF lights (KHR_lights_punctual), the
                                     rest (ambient, local directional) as empty nodes; the game's settings
                                     and the light group's kind in extras. Of the daylight (kinds 0 and
                                     1), only the weather's group are glTF lights
    a Shader (0x11000)               a material; how the game blends it (BLMD) in its extras ("blend"):
                                     light-adding (2) and darkening (3, subtracting) ones with their picture
                                     made ready for ordinary blending; a cut-out (ATST) at its ACTH; "depthWrite":
                                     false for the ones the game draws without writing depth; unlit
                                     (KHR_materials_unlit) without LIT 1
    a shadowdecal primitive group    a node of its own under its mesh's, extras {"shadowDecal": true}
    the low-detail hull, with --lod  marked {"lowDetailHull": true}, and hidden next to detailed areas
    a World Geometry (0x8800003)     its top node's extras: its kind ("worldGeometryKind") and, from its Zone
                                     Package Entry (0x8800009), "drawDistance"; one drawn only from afar
                                     (near above 0: a far-away stand-in) is marked hidden
    an instanceposition's last value the state a placed prop starts in (extras {"state": name} when not
                                     its first)
    a State Prop Data (0x802000D)    its own properties (0x8020008), but name, in the extras of each placed
                                     copy, and of the prop's top node when its file is opened on its own:
                                     {"properties": {name: value}}
    the sea, with --map              a flat surface at height 0 round the map, its settings in extras
    a Draw Order (0x122000)          the mesh's extras: {"drawOrder": key}
    a Sky (0x8800002), with --hour   its composite drawable posed by PTRN_<name> for the hour, and its
                                     meshes' vertex colours (0x121305) for the hour, picked by VRTX_<mesh>
                                     (sky_export puts a sky round a whole city)

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
import zlib
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
WORLD_GEO, STATE_PROP, ZONE_PACKAGE, ZONE_ENTRY = 0x8800003, 0x8800005, 0x8800004, 0x8800009
STATE_PROP_DATA, PROP_STATE, PROP_VISIBILITY, PROP_PROPERTY = 0x0802000D, 0x0802000E, 0x08020002, 0x08020008
MISSING_GLASS = [0.10, 0.13, 0.15, 0.45]
MISSING_SOLID = [0.12, 0.12, 0.12, 1.0]
LOOK_ENV = "SCARFACE_TEXTURE_LOOK"       # "xbox": PC textures get the Xbox's darker mid-tones (media.xbox_look)
EXPORT_VERSION = 10                    # 3: props kept with another area. 4: one stage of each place; insides in the city.
                                       # 5: map areas carry their lights. 6: the city has its sky; one weather's daylight.
                                       # 7: light-adding and darkening surfaces; the sea; shadow decals and the hull marked.
                                       # 8: a shader without LIT is unlit. 9: darkening subtracts; placed props in their
                                       # starting state; world geometry's draw distances, far-away stand-ins hidden.
                                       # 10: props carry their properties
LIGHT, LIGHT_GROUP, LIGHT_GROUP_RECORD, DRAW_ORDER, SKY = 0x13000, 0x2380, 0x8800007, 0x122000, 0x8800002
DAYLIGHT_KINDS = (0, 1)                # light group record kinds: the daylight and the same for rain (LITE animations)
WEATHER_KIND = {"clear": 0, "rain": 1}  # the daylight's kind for each weather; the game starts in clear weather
WEATHERS = tuple(WEATHER_KIND)
FRAMES_PER_HOUR = 10                   # the LITE, PTRN_sky and VRTX_ animations: 241 frames, one day, frame 0 midnight
SKY_SCALE = 2.0                        # the game draws the whole sky at twice its size
SKY_MARGIN = 1.1                       # a sky round a city reaches a tenth past its farthest corner
# The game stores only a light's colour; how bright that is on its scale isn't known. So every exported light
# gets the same intensity, in KHR_lights_punctual's units: lux for a directional light, candela for a point or
# spot light. 50,000 cd lights a surface 5 m away as strongly as the directional light's 2,000 lux
# (50,000 / 5 squared). Blender's glTF importer divides by 683 lumens per watt: a sun of about 2.9 W/m² and
# lamps of about 920 W. Change them in Blender to taste.
DIRECTIONAL_LUX = 2000.0
POINT_CANDELA = 50000.0
_LOD_PART = re.compile(r"lod\d*(shape\d*)?$", re.I)
SCRIPT_OBJECT, OBJECT_PROPERTY, OBJECT_BINARY = 0x9900190, 0x9900192, 0x9900194
VECTOR_CHANNELS = (0x121102, 0x121103, 0x121104)
SHADOW_PARTS = 0x20 | 0x40           # a composite part's kind: 1 a model, 0x20 a shadow mesh, 0x40 a shadow skin
# How see-through surfaces are drawn, the low-detail hull, shadow decals and the sea: docs/FORMATS.md, from the
# clean-room spec docs/cleanroom/SPEC-002-materials-ocean-shadows.md.
BLENDS = {1: "alpha", 2: "add", 3: "darken"}  # a shader's BLMD: 1 ordinary see-through, 2 adds light, 3 subtracts
ALPHA_TEST = 0.5                       # the cut-out's alpha when the shader has no ACTH
ACMP_GREATER = 4                       # ACMP 4: a pixel stays only if its alpha is greater (without ACMP: or equal)
NO_DEPTH_KINDS = ("decal", "nightlight", "shadowdecal")   # shader kinds the game draws without writing depth
SHADOW_DECAL_KIND = "shadowdecal"
HULL_KIND = "vertexfade"               # the low-detail hull of the city and the islands (miami_lod, islands_LOD)
HULL_FADE = (200.0, 250.0)             # see-through nearer than this, whole beyond it (metres from the camera)
HULL_CUT = round(20 / 255, 4)          # and pixels with less alpha than this are cut out
LEAF_DEPTH = round(228 / 255, 4)       # a placed prop's unlit see-through leaves hide what is behind where alpha >= this
# The sea (OceanObject "Ocean" in scriptc/missions/z04/objects_static.dso, with OceanTemplateDefault and
# OceanTuningTemplateDefault from scriptc/templates/ocean.cso, as the PC files have them): a flat surface at
# height 0. The tuning template's look replaces the object's; the foam is the object's. The names are the scripts'.
OCEAN_SHADER, OCEAN_TEXTURE = "ocean_text", "water_01.bmp"
OCEAN = {"object": "Ocean", "position": [0.0, 0.0, 0.0], "oceanTemplate": "OceanTemplateDefault",
         "tuningTemplate": "OceanTuningTemplateDefault", "DetailTextureName": "water_01.BMP",
         "FoamTextureName": "Water_Ocean_Foam.tga", "ReflectionTextureName": "skyTexture",
         "DetailOpacity": 0.225, "DetailTextureScale": 0.2, "ReflectionRedScale": 0.25,
         "ReflectionGreenScale": 0.23, "ReflectionBlueScale": 0.25, "ReflectionAlphaScale": 0.98,
         "FoamMinHeight": 0.15, "FoamMaxHeight": 1.0, "FoamMaxOpacity": 1.0, "MinWaveLength": 0.1,
         "MaxWaveLength": 12.0, "AmplitudeRatio": 0.013, "WindDirectionMean": 90.0, "WindDirectionVariance": 30.0,
         "speedScaleFactor": 1.2}
OCEAN_MARGIN = 1000.0                  # the sea reaches this far past the scene on every side: past the fog's end
                                       # (900 m at most), so with the fog on its edge can't be seen
OCEAN_TILE = 1000.0                    # the sea is made of squares this big, on a grid from the city's 0, 0

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


def draw_order(data: bytes, c: p3d.Chunk) -> Optional[float]:
    """A mesh's draw-order key: the Draw Order chunk (0x122000) right under it, clamped to 0..1 as the game
    clamps it; None when it has none (the game counts that as 0.5). The game draws the sky's parts with no
    depth test, from the highest key to the lowest, so a lower key ends up on top."""
    k = c.find(DRAW_ORDER)
    v = p3d.fields(data, k).get("draw order") if k is not None else None
    if v is None or not math.isfinite(v):
        return None
    return max(0.0, min(1.0, v))


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


def prop_properties(data: bytes, c: p3d.Chunk) -> Dict[str, str]:
    """A State Prop Data chunk's own properties (the Prop Property chunks, 0x08020008, straight under it), as
    {name: value}, texts as the file has them: visibility, movement, class ... (SPEC-003, sections 1.1 and 9). name,
    the prop's own name, is left out, and so are a state's properties. The first of two with the same name wins."""
    out: Dict[str, str] = {}
    for k in c.children:
        f = p3d.fields(data, k) if k.id == PROP_PROPERTY else {}
        if "name" in f and f["name"].lower() != "name":
            out.setdefault(f["name"], f["value"])
    return out


def starting_state(states: Sequence[Tuple[str, Dict[str, bool]]], number: int) -> int:
    """Which of a prop's states (prop_states) a placed copy starts in, by its place in the list, from the last of
    its instanceposition's twelve numbers (p3d.start_state, SPEC-003 section 2): the state with that name, letter
    case ignored. The first state (0) for 0, for a number off the list, or when the prop has no state of that name."""
    name = p3d.start_state(number)
    if not isinstance(name, str):
        return 0
    return next((i for i, (s, _shown) in enumerate(states) if s.lower() == name.lower()), 0)


def lod_parts(parts: Sequence[str]) -> set:
    """The low-detail stand-ins (storeInterior2LODShape beside storeInterior2InstanceShape) a composite
    carries for far away, when it has a part that isn't one."""
    low = {p.lower() for p in parts if _LOD_PART.search(p)}
    return low if len(low) < len(parts) else set()


OFFSET_SETS, OFFSET_SET, POSITION_OFFSETS = 0x121305, 0x121306, 0x10F00
EXPRESSION_GROUP, EXPRESSION = 0x21001, 0x21000


def position_offsets(data: bytes, c: p3d.Chunk) -> Dict[int, Dict[int, Dict[int, Vec3]]]:
    """The shapes a mesh or skin can be pulled into (a face's raised lip, a closed eye):
    {shape number: {primitive group number: {vertex: how far it moves (x, y, z)}}}. The chunk holds a set
    list (0x121305); each set (0x121306: u32 0, the shape's number, the primitive group's) holds position
    offsets (0x10F00: u32 0, "POS", a count, then per entry a vertex number and three floats)."""
    out: Dict[int, Dict[int, Dict[int, Vec3]]] = {}
    sets = c.find(OFFSET_SETS)
    for k in (sets.children if sets else []):
        if k.id != OFFSET_SET or k.body[1] - k.body[0] < 12:
            continue
        _zero, shape, group = struct.unpack_from("<3I", data, k.body[0])
        for o in k.children:
            if o.id != POSITION_OFFSETS or o.body[1] - o.body[0] < 12:
                continue
            if data[o.body[0] + 4:o.body[0] + 7] != b"POS":
                continue
            n = struct.unpack_from("<I", data, o.body[0] + 8)[0]
            if o.body[0] + 12 + 16 * n > o.body[1]:
                continue
            moved = out.setdefault(shape, {}).setdefault(group, {})
            for i in range(n):
                v, x, y, z = struct.unpack_from("<I3f", data, o.body[0] + 12 + 16 * i)
                moved[v] = (x, y, z)
    return out


def expressions(src: "Source", mesh: str) -> List[Tuple[str, List[Tuple[float, int]]]]:
    """The sliders that work a mesh's shapes (an expression group, 0x21001: u32 0, its name, the mesh's
    name, a count; each expression 0x21000: u32 0, its name, a count, that many slider values, that many
    shape numbers): [(slider name, [(the value at which a shape is fully on, the shape's number)])]."""
    out = []
    for c in src.chunks:
        if c.id != EXPRESSION_GROUP:
            continue
        try:
            r = p3d._R(src.data, *c.body)
            r.u32()
            r.text()
            if r.text().lower() != mesh.lower():
                continue
            for k in c.children:
                if k.id != EXPRESSION:
                    continue
                r = p3d._R(src.data, *k.body)
                r.u32()
                name, n = r.text(), r.u32()
                values = r.floats(n)
                out.append((name, list(zip(values, [r.u32() for _ in range(n)]))))
        except (struct.error, IndexError):
            continue
    return out


def shape_names(sliders: Sequence[Tuple[str, List[Tuple[float, int]]]], count: int) -> List[str]:
    """A name for each shape, from the slider that works it: "D___Frown_Smile -" and "D___Frown_Smile +"
    for a slider with a shape at each end."""
    names = [f"shape {i}" for i in range(count)]
    for name, keys in sliders:
        for value, shape in keys:
            if 0 <= shape < count:
                names[shape] = name if len(keys) == 1 else f"{name} {'-' if value < 0 else '+'}"
    return names


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
_SHADER_KIND = re.compile(r"^_([a-z]+)_blmd\d", re.I)


def shader_from_name(name: str) -> Optional[dict]:
    """The map's shared shaders are named after what they do, for example
    GlobalShader_g_hedge.tga_simple_blmd1_mcbv0_lit1_alpha1_atst1_alum1_2sid0 (the texture, the shader
    kind, then the settings); read that when the shader itself is in a file not given."""
    m = _SHADER_NAME.match(name)
    if not m:
        return None
    ints = {k.upper(): int(v) for k, v in _SHADER_FLAG.findall(name)}
    kind = _SHADER_KIND.match(name[m.end():])
    return {"name": name, "pddi": kind.group(1).lower() if kind else "", "translucent": bool(ints.get("ALPHA")),
            "textures": [("TEX", m.group(1))], "ints": ints, "floats": {}, "colours": {}}


def blend_of(info: Optional[dict]) -> Optional[str]:
    """How a shader puts its surface over what is behind it (its BLMD): "alpha" (1, ordinary see-through),
    "add" (2, adds light), "darken" (3, takes its colour away: SPEC-003, section 8.1), the number for any other,
    None when it is solid (0 or none)."""
    blmd = (info or {}).get("ints", {}).get("BLMD")
    return BLENDS.get(blmd, blmd) if blmd else None


def alpha_test(info: dict) -> Optional[Tuple[float, bool]]:
    """A cut-out shader's test (ATST 1): (the alpha a pixel is compared with, ACTH or else 0.5; whether it must
    be greater, ACMP 4, rather than greater or equal). None without the test."""
    if not info["ints"].get("ATST"):
        return None
    cut = info["floats"].get("ACTH")
    cut = cut if isinstance(cut, (int, float)) and math.isfinite(cut) else ALPHA_TEST
    return float(cut), info["ints"].get("ACMP") == ACMP_GREATER


def draws_depth(info: Optional[dict]) -> bool:
    """Whether the game writes depth for a shader's surfaces: not for the decal, nightlight and shadowdecal
    kinds, nor for surfaces that add light (BLMD 2)."""
    if not info:
        return True
    return (info.get("pddi") or "").lower() not in NO_DEPTH_KINDS and info["ints"].get("BLMD") != 2


def is_lit(info: Optional[dict]) -> bool:
    """Whether the scene's lights light a shader's surfaces: only with LIT 1. A shader without LIT is unlit, as
    is a name that says lit0: in the PC's packages/z04 every shader named lit0 has no LIT setting and every
    one named lit1 has LIT 1 (SPEC-002's answers). Without the shader's settings at all, lit."""
    return not info or bool(info["ints"].get("LIT"))


def is_leaf(info: Optional[dict]) -> bool:
    """An unlit see-through shader without a cut-out (BLMD 1, no LIT, no ATST): on a placed prop (the trees and
    bushes) the game draws it twice, see Builder.mesh."""
    if not info:
        return False
    ints = info["ints"]
    return ints.get("BLMD") == 1 and not is_lit(info) and not ints.get("ATST")


def _passes(alpha: int, cut: Optional[Tuple[float, bool]]) -> bool:
    if cut is None:
        return True
    return alpha / 255 > cut[0] if cut[1] else alpha / 255 >= cut[0]


def added_light(rgba: bytes, cut: Optional[Tuple[float, bool]] = None) -> bytes:
    """A light-adding (BLMD 2) picture made ready for ordinary see-through blending: each pixel's alpha is its
    brightness (the largest of its red, green and blue) and its colour is divided by that. Blended as usual
    (colour x alpha + what is behind x (1 - alpha)) it puts its own colour on top, and black leaves what is
    behind alone. The picture's own alpha is used only for the cut-out (cut, see alpha_test): pixels that fail
    it are left out (alpha 0)."""
    out = bytearray(len(rgba))
    for i in range(0, len(rgba) - 3, 4):
        r, g, b, a = rgba[i], rgba[i + 1], rgba[i + 2], rgba[i + 3]
        m = max(r, g, b)
        if m and _passes(a, cut):
            out[i], out[i + 1], out[i + 2], out[i + 3] = round(r * 255 / m), round(g * 255 / m), round(b * 255 / m), m
    return bytes(out)


def darkening(rgba: bytes, cut: Optional[Tuple[float, bool]] = None) -> bytes:
    """A darkening (BLMD 3) picture made ready for ordinary see-through blending. The game takes the picture's colour
    away from what is behind (what is behind minus the colour, not below 0; alpha plays no part: SPEC-003, section
    8.1). Here the picture is black, with an alpha of its brightness (the largest of its red, green and blue), so
    what is behind ends up times 1 minus that brightness: close to subtracting it where what is behind is bright,
    and black darkens nothing. The picture's own alpha is used only for the cut-out (cut): pixels that fail it
    darken nothing."""
    out = bytearray(len(rgba))
    for i in range(0, len(rgba) - 3, 4):
        if _passes(rgba[i + 3], cut):
            out[i + 3] = max(rgba[i], rgba[i + 1], rgba[i + 2])
    return bytes(out)


def sea_picture(rgba: bytes, colour: Sequence[float], opacity: float, alpha: float) -> bytes:
    """The sea's picture: the detail texture laid over the sea's colour (0..1 each) at opacity, with one alpha."""
    out = bytearray(len(rgba))
    base = [c * 255 * (1 - opacity) for c in colour[:3]]
    a = round(max(0.0, min(1.0, alpha)) * 255)
    for i in range(0, len(rgba) - 3, 4):
        for k in range(3):
            out[i + k] = max(0, min(255, round(base[k] + rgba[i + k] * opacity)))
        out[i + 3] = a
    return bytes(out)


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

    def light(self, light: dict) -> int:
        """A KHR_lights_punctual light; a node takes it with extensions={"KHR_lights_punctual": {"light": i}}."""
        lights = self.doc.setdefault("extensions", {}).setdefault("KHR_lights_punctual", {"lights": []})["lights"]
        lights.append(light)
        self.used_extensions.add("KHR_lights_punctual")
        return len(lights) - 1

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
    lights: int = 0                                               # light nodes, glTF lights or not
    gltf_lights: int = 0                                          # of them, the ones that are glTF lights
    shadow_decals: int = 0                                        # primitive groups with a shadowdecal shader
    box: Optional[Tuple[List[float], List[float]]] = None         # a map export's geometry: lowest, highest corner
    notes: List[str] = field(default_factory=list)                # the weather, the sky, the fog, the sea

    def lines(self) -> List[str]:
        out = [f"{len(self.models)} model(s)" + (": " + ", ".join(self.models[:12]) + (" ..." if len(self.models) > 12 else "")
                                                 if self.models else "")]
        if self.lights:
            out.append(f"{self.lights} light(s), {self.gltf_lights} of them as glTF lights (the rest, such as ambient "
                       "lights, as empty nodes with their settings in extras)")
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
        if self.shadow_decals:
            out.append(f"{self.shadow_decals} shadow decal(s), each in a node of its own marked shadowDecal (the Xbox "
                       "draws them, darkening what is under them by their coverage; the PC is reported not to show them)")
        return out + self.notes


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
        self.hour: Optional[float] = None          # set: the sky's pose and colours are those of this hour
        self.posed: set = set()                    # the animations a pose was taken from (id of the chunk)
        self._animations: Optional[Dict[str, List[Ref]]] = None
        self.shaped: Dict[int, list] = {}          # glTF mesh with shapes -> the sliders that work them
        self.prop = False                          # set while a placed prop goes in (its leaves: see mesh)
        self.decals: Dict[tuple, int] = {}         # a mesh's key -> the glTF mesh of its shadow decals
        self._shaders: Dict[str, Optional[dict]] = {}

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

    def made_texture(self, name: str, look: str, make, variant: str = "") -> Optional[int]:
        """A texture made from one of the game's pictures by make(rgba) -> rgba (added_light, darkening, the
        sea's), once for each look (and variant: a cut-out's test). None when the picture isn't in the files or
        can't be read. The picture is read as texture() reads it (with the Xbox's tones if asked)."""
        key = f"{name.lower()}|{look}|{variant}"
        if key in self.textures:
            return self.textures[key]
        found, made = self.lib.pictures.get(name.lower()), None
        if found is None:
            self.report.missing_textures.add(name)
        else:
            try:
                picture = media.picture_png(found[0].data, found[1])
                if found[1].kind == "png" and os.environ.get(LOOK_ENV) == "xbox":
                    picture = media.xbox_look(picture)
                w, h, rgba = media.decode_png(picture)
                made = media.png(w, h, make(rgba)) if w and h else None
            except (media.MediaError, struct.error, ValueError, IndexError, zlib.error):
                made = None
        index = None
        if made:
            if self.sampler is None:
                self.sampler = self.g.add("samplers", {"magFilter": 9729, "minFilter": 9987, "wrapS": 10497,
                                                       "wrapT": 10497})
            index = self.g.add("textures", {"sampler": self.sampler, "source": self.g.image(f"{name} ({look})", made)})
        self.textures[key] = index
        return index

    def shader(self, shader: str) -> Optional[dict]:
        """A shader's settings (shader_info), found in the files by name, else read from its name."""
        key = shader.lower()
        if key not in self._shaders:
            ref = self.lib.find("shader", shader)
            self._shaders[key] = shader_info(ref.data, ref.chunk) if ref else shader_from_name(shader)
        return self._shaders[key]

    def material(self, shader: str, leaf: str = "") -> int:
        """The glTF material for a shader. How the game puts a see-through surface over what is behind it (its
        BLMD) goes in the material's extras ("blend"): ordinary see-through (1) is glTF's BLEND; a surface that
        adds light (2) or darkens (3, subtracting) gets its picture made ready for ordinary blending (added_light,
        darkening) so it neither comes out as a black square nor hides what is behind. A cut-out (ATST) is
        glTF's MASK at the shader's ACTH (0.5 without one); a light-adding or darkening one has the cut-out in
        its made picture instead. Shaders drawn without writing depth (draws_depth) say so ("depthWrite":
        false), shadow decals and the low-detail hull are marked. A shader that isn't lit (is_lit: no LIT 1)
        is unlit (KHR_materials_unlit). leaf: "colour" or "depth" for the two parts of a placed prop's leaves
        (see mesh)."""
        key = shader.lower() + (f"|leaf {leaf}" if leaf else "")
        if key in self.materials:
            return self.materials[key]
        info = self.shader(shader)
        name = shader + {"": "", "colour": " (leaves)", "depth": " (leaves, solid core)"}[leaf]
        mat: dict = {"name": name, "pbrMetallicRoughness": {"metallicFactor": 0.0, "roughnessFactor": 1.0}}
        extras: dict = {}
        if info:
            ints = info["ints"]
            blend = blend_of(info)
            look = blend if blend in ("add", "darken") else None
            cut = alpha_test(info)
            tex = next((t for p, t in info["textures"] if p == "TEX"), None)
            if tex and look:
                ti = self.made_texture(tex, look, lambda rgba: (added_light if look == "add" else darkening)(rgba, cut),
                                       str(cut) if cut else "")
            elif tex:
                ti = self.texture(tex)
            if tex:
                if ti is not None:
                    mat["pbrMetallicRoughness"]["baseColorTexture"] = {"index": ti}
                elif tex in self.report.missing_textures:
                    # a picture the game doesn't have either (the cars' windscreens and undersides): dark
                    # glass or dark metal, not a glaring white sheet. Light to add or a darkening with no
                    # picture: nothing at all, not a dark square.
                    glass = bool(ints.get("BLMD") or info["translucent"])
                    mat["pbrMetallicRoughness"]["baseColorFactor"] = (
                        [0.0, 0.0, 0.0, 0.0] if look else MISSING_GLASS if glass else MISSING_SOLID)
            if not tex and (ints.get("BLMD") or info["translucent"]):
                # a see-through layer with no picture of its own: the glass laid over a tower's walls, which
                # the game makes shine with the sky's reflection. Without this it is a white sheet over them.
                mat["pbrMetallicRoughness"]["baseColorFactor"] = MISSING_GLASS
            if ints.get("2SID"):
                mat["doubleSided"] = True
            if look:
                mat["alphaMode"] = "BLEND"                      # the cut-out, if any, is in the made picture
            elif leaf == "depth":
                mat["alphaMode"], mat["alphaCutoff"] = "MASK", LEAF_DEPTH
            elif cut:
                mat["alphaMode"], mat["alphaCutoff"] = "MASK", cut[0]
            elif ints.get("BLMD") or info["translucent"]:
                mat["alphaMode"] = "BLEND"
            if not is_lit(info):                                # no LIT 1: not lit by the scene's lights
                mat["extensions"] = {"KHR_materials_unlit": {}}
                self.g.used_extensions.add("KHR_materials_unlit")
            if blend:
                extras["blend"] = blend
            kind = (info.get("pddi") or "").lower()
            if not draws_depth(info) or leaf == "colour":
                extras["depthWrite"] = False
            if kind == SHADOW_DECAL_KIND:
                extras["shadowDecal"] = True
            if kind == HULL_KIND:
                extras.update(lowDetailHull=True, fade=list(HULL_FADE), fadeCutoff=HULL_CUT)
            if leaf:
                extras["leaves"] = leaf
        if extras:
            mat["extras"] = extras
        self.materials[key] = self.g.add("materials", mat)
        return self.materials[key]

    # meshes

    def _mesh_key(self, ref: Ref) -> tuple:
        return (id(ref.source), ref.chunk.offset) + (("prop",) if self.prop else ())

    def place_mesh(self, ref: Ref, name: str, parent: Optional[int]) -> Optional[int]:
        """A Mesh chunk's node under parent (see mesh); its shadow decals, if it has any, in a node of their own
        under it ("<name> shadow decal", extras {"shadowDecal": true}), or as the node itself when the mesh is
        nothing else. None when nothing in it can be shown."""
        mesh = self.mesh(ref)
        decal = self.decals.get(self._mesh_key(ref))
        if mesh is None:
            return self.g.node(name, parent, mesh=decal, extras={"shadowDecal": True}) if decal is not None else None
        node = self.g.node(name, parent, mesh=mesh)
        if decal is not None:
            self.g.node(name + " shadow decal", node, mesh=decal, extras={"shadowDecal": True})
        return node

    def mesh(self, ref: Ref, skinned_to: Optional[Dict[int, int]] = None) -> Optional[int]:
        """A glTF mesh for a Mesh or Skin chunk (one primitive per primitive group). For a skin,
        skinned_to maps skeleton joint numbers to the skin's joint list. The primitive groups drawn with a
        shadowdecal shader go in a glTF mesh of their own (self.decals; place_mesh puts it in), so they can be
        shown or hidden together. On a placed prop (self.prop), the game draws an unlit see-through shader
        without a cut-out (is_leaf: the leaves of the trees and bushes) twice: once for its colour, blended, not
        writing depth, and once writing depth only where the alpha is at least 228/255. Here that is two
        primitives on the same vertices: the colour, see-through and marked as not writing depth, and a
        cut-out at 228/255 for the solid core of each leaf (which draws its colour too: there it is nearly
        opaque)."""
        key = self._mesh_key(ref)
        if key in self.meshes and skinned_to is None:
            return self.meshes[key]
        prims = []
        decal_prims = []
        tinted = self.sky_colours(ref) if self.hour is not None and ref.chunk.id == MESH else None
        first = 0                                    # the mesh's number of the group's first vertex
        try:
            shapes = position_offsets(ref.data, ref.chunk)
        except struct.error:
            shapes = {}
        count = max(shapes) + 1 if shapes else 0
        still: Dict[int, int] = {}                   # vertices -> an accessor of that many unmoved vertices
        for number, pg in enumerate(k for k in ref.chunk.children if k.id == PRIM_GROUP):
            try:
                geo = geometry(ref.data, pg)
            except (struct.error, IndexError, ValueError):
                geo = None
            shader = p3d.fields(ref.data, pg).get("shader", "")
            if geo is None:
                self.report.unread_groups += 1
                continue
            if tinted is not None:
                geo.colours = add_colours(geo.colours, tinted[1], first, len(geo.positions))
            first += len(geo.positions)
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
            indices = self.g.accessor(flat, "SCALAR", 5125 if big else 5123, target=34963)
            info = self.shader(shader)
            if (info or {}).get("pddi", "").lower() == SHADOW_DECAL_KIND and not count and skinned_to is None:
                decal_prims.append({"attributes": attrs, "indices": indices, "material": self.material(shader),
                                    "mode": 4})
                continue
            if self.prop and skinned_to is None and not count and is_leaf(info):
                prims.append({"attributes": dict(attrs), "indices": indices, "material": self.material(shader, "depth"),
                              "mode": 4})
                prims.append({"attributes": attrs, "indices": indices, "material": self.material(shader, "colour"),
                              "mode": 4})
                continue
            prims.append({"attributes": attrs, "indices": indices, "material": self.material(shader), "mode": 4})
            if count:                                # every group lists every shape, moved by it or not
                n = len(geo.positions)
                targets = []
                for shape in range(count):
                    moved = shapes.get(shape, {}).get(number)
                    if not moved or max(moved) >= n:
                        if n not in still:
                            still[n] = self.g.accessor([(0.0, 0.0, 0.0)] * n, "VEC3", bounds=True)
                        targets.append({"POSITION": still[n]})
                        continue
                    rows = [(0.0, 0.0, 0.0)] * n
                    for v, d in moved.items():
                        rows[v] = pos(d)
                    targets.append({"POSITION": self.g.accessor(rows, "VEC3", bounds=True)})
                prims[-1]["targets"] = targets
        index = None
        if prims:
            item: dict = {"name": ref.name, "primitives": prims}
            if count:
                sliders = expressions(ref.source, ref.name)
                item["weights"] = [0.0] * count
                item["extras"] = {"targetNames": shape_names(sliders, count)}
                self.shaped[len(self.g.doc["meshes"])] = sliders
            order = draw_order(ref.data, ref.chunk)
            if order is not None:
                item.setdefault("extras", {})["drawOrder"] = order
            if tinted is not None:
                item.setdefault("extras", {}).update({"hour": self.hour, "colourSet": tinted[0]})
            index = self.g.add("meshes", item)
        if decal_prims:
            self.decals[key] = self.g.add("meshes", {"name": ref.name + " shadow decal", "primitives": decal_prims,
                                                     "extras": {"shadowDecal": True}})
            self.report.shadow_decals += len(decal_prims)
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
            data = self.prop_data(ref, name)
            cache[key] = prop_states(data.data, data.chunk) if data is not None else []
        return cache[key]

    def properties_of(self, ref: Ref, name: str) -> Dict[str, str]:
        """The own properties (prop_properties) of the prop a composite drawable is the model of ({} for most)."""
        cache = self.__dict__.setdefault("_properties", {})
        key = id(ref.chunk)
        if key not in cache:
            data = self.prop_data(ref, name)
            cache[key] = prop_properties(data.data, data.chunk) if data is not None else {}
        return cache[key]

    def prop_data(self, ref: Ref, name: str) -> Optional[Ref]:
        """The State Prop Data (0x0802000D) of the prop a composite drawable is the model of: one of the same name,
        or the one a State Prop naming the drawable names. None for most."""
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
        return data

    def mark_prop(self, top: int, ref: Ref, name: str, state: int = 0) -> None:
        """A prop's node says in its extras the state it is in, when not its first ({"state": name}), and the prop's
        own properties ({"properties": {name: value}}), when it has any."""
        extras: dict = {}
        states = self.states_of(ref, name)
        if 0 < state < len(states):
            extras["state"] = states[state][0]
        props = self.properties_of(ref, name)
        if props:
            extras["properties"] = dict(props)
        if extras:
            self.g.doc["nodes"][top].setdefault("extras", {}).update(extras)

    def composite(self, ref: Ref, parent: Optional[int] = None, label: str = "", state: int = 0, **place) -> int:
        """A composite drawable: its skeleton's joints, with each part (a mesh or a skin) on its joint.
        Its skeleton and parts are looked for in its own file first. Only the parts shown in the prop's
        state are put in (state: its place in the prop's list; the first by default, how the game starts a
        prop before anything breaks it, unless a placed copy says otherwise: starting_state), and only the
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
                self.place_mesh(mref, part, at)
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

    # lights

    def lights(self, src: Source, parent: int, hour: Optional[float] = None, weather: str = "clear") -> int:
        """A map file's lights (0x13000) under a node of their own ("<file> lights"), each in a node for its
        light group (0x2380), whose extras give the kind its record (0x8800007) says. With an hour, the
        daylight's lights are lit for it (see daylight). The clear weather's daylight (kind 0) and the rain's
        (kind 1) are alternatives: only the weather's group are glTF lights, the other's lights are empty
        nodes with their settings in extras, marked dataOnly. Returns how many lights went in."""
        found, groups, records = file_lights(src)
        if not found:
            return 0
        if hour is not None:
            daylight(src, found, records, hour)
        top = self.g.node(Path(src.label).stem + " lights", parent)
        done = set()
        for group in groups:
            rec = records.get(group["name"].lower())
            extras: Optional[dict] = None
            other = False
            if rec:
                extras = {"lightGroupKind": rec["kind"], "lightGroupRecord": rec["name"]}
                if rec["kind"] in DAYLIGHT_KINDS:
                    extras["weather"] = WEATHERS[rec["kind"]]
                    other = rec["kind"] != WEATHER_KIND[weather]
                    if other:
                        extras["dataOnly"] = True
                        self.report.notes.append(f"{group['name']}: the {WEATHERS[rec['kind']]} weather's daylight, kept "
                                                 f"as data only (this export is in {weather} weather)")
            node = self.g.node(group["name"], top, extras=extras)
            for name in group["lights"]:
                key = name.lower()
                if key in found and key not in done:
                    done.add(key)                               # a light in two groups goes in once, in the first
                    self.light(found[key], node, rec["kind"] if rec else None, data_only=other)
        for key, info in found.items():
            if key not in done:
                self.light(info, top)
        return len(found)

    def light(self, info: dict, parent: int, kind: Optional[int] = None, data_only: bool = False) -> int:
        """One light (p3d.light's dictionary) as a node at its position (mirrored like the map's geometry),
        turned so that its -Z points the way it shines. It is a glTF light (KHR_lights_punctual) when it is
        a point or spot light, or a directional light without a decay range (a city-wide one), and is on and
        adds light; a point or spot light's range is its decay range's outer size. The rest are empty nodes:
        ambient lights, directional lights that light only their decay range (glTF's have no range), lights
        switched off or that take light away, and (data_only) the daylight of the weather not chosen. Every
        light node has the game's settings in extras."""
        kind_ = info.get("type")
        argb = int(info.get("argb") or "0", 16)
        colour = [round(((argb >> s) & 0xFF) / 255, 4) for s in (16, 8, 0)]
        decay = info.get("decay range")
        local = bool(decay) and decay.get("shape") != "none"
        extras: dict = {"lightType": kind_, "color": colour, "enabled": bool(info.get("enabled"))}
        for key, name in (("casts shadows", "castsShadows"), ("illumination", "illumination"), ("hour", "hour")):
            if key in info:
                extras[name] = info[key]
        for key, name in (("decay range", "decayRange"), ("spot cone", "spotCone")):
            if info.get(key):
                extras[name] = {k: list(v) if isinstance(v, tuple) else v for k, v in info[key].items()}
        if kind is not None:
            extras["lightGroupKind"] = kind
        if data_only:
            extras["dataOnly"] = True
        place = {}
        if _finite(info.get("position")):
            place["translation"] = list(pos(info["position"]))
        if kind_ in ("directional", "spot") and _finite(info.get("direction")):
            place["rotation"] = list(camera_rotation(info["direction"], (0.0, 1.0, 0.0)))
        ext = None
        lit = info.get("enabled") and info.get("illumination", "adds light") == "adds light" and not data_only
        if lit and (kind_ in ("point", "spot") or (kind_ == "directional" and not local)):
            light: dict = {"name": info.get("name", ""), "type": kind_, "color": colour,
                           "intensity": DIRECTIONAL_LUX if kind_ == "directional" else POINT_CANDELA}
            reach = decay_reach(decay) if local else None
            if kind_ != "directional" and reach:
                light["range"] = reach
            if kind_ == "spot":
                light["spot"] = {}       # glTF's own cone: which of the game's two angles is which isn't known
            ext = {"KHR_lights_punctual": {"light": self.g.light(light)}}
            self.report.gltf_lights += 1
        self.report.lights += 1
        return self.g.node(info.get("name") or "light", parent, extensions=ext, extras=extras, **place)

    # the sky through the day

    def find_animation(self, name: str, prefer: Sequence[Source] = ()) -> Optional[Ref]:
        """An animation (0x121000) in any of the library's files by its name (letter case ignored), from the
        preferred files first."""
        if self._animations is None:
            self._animations = {}
            for src in self.lib.sources:
                for c in src.chunks:
                    if c.id == ANIMATION:
                        try:
                            self._animations.setdefault(chunk_name(src.data, c).lower(), []).append(Ref(src, c))
                        except IndexError:
                            continue
        refs = self._animations.get(name.lower(), [])
        return next((r for r in refs if any(r.source is p for p in prefer)), refs[0] if refs else None)

    def sky_colours(self, ref: Ref) -> Optional[Tuple[float, Dict[int, Vec3]]]:
        """For a mesh with vertex-colour sets (0x121305), at self.hour: (the set number its animation
        VRTX_<mesh name> gives, with its fraction; what to add to each vertex's own colour, blended between
        the two sets either side of that number). None for a mesh without sets or without the animation."""
        sets = p3d.vertex_colour_sets(ref.data, ref.chunk)
        anim = self.find_animation("VRTX_" + ref.name, (ref.source,)) if sets else None
        if anim is None:
            return None
        frame = max(0.0, min(24.0, self.hour or 0.0)) * FRAMES_PER_HOUR
        picked = None
        for ch in p3d.walk(anim.chunk.children):
            if ch.id != p3d.INTEGER_CHANNEL:
                continue
            try:
                _param, frames, values = p3d.channel_keys(ref.data, ch)
            except (p3d.P3dError, struct.error, IndexError):
                continue
            if frames and len(values) == len(frames):
                picked = _sample(frames, values, frame, _smooth(ref.data, ch))[0]
                break
        if picked is None:
            return None
        picked = max(0.0, min(float(len(sets) - 1), picked))
        low = int(math.floor(picked))
        high, t = min(low + 1, len(sets) - 1), picked - low
        out: Dict[int, Vec3] = {}
        for v in set(sets[low]) | set(sets[high]):
            a, b = sets[low].get(v, (0, 0, 0)), sets[high].get(v, (0, 0, 0))
            out[v] = tuple(x + (y - x) * t for x, y in zip(a, b))  # type: ignore[assignment]
        return round(picked, 4), out

    def pose(self, copy: SkeletonCopy, ref: Ref, frame: float) -> List[str]:
        """Put a skeleton copy in the pose an animation (a PTRN one) gives at a frame: each group's rotation,
        along the shorter arc between keys, and translation on its joint's node. Returns the joints moved."""
        data, c = ref.data, ref.chunk
        gl = c.find(ANIM_GROUP_LIST)
        moved = []
        for gc in (gl.children if gl else []):
            if gc.id != ANIM_GROUP:
                continue
            name = p3d.fields(data, gc).get("name", "")
            node = copy.nodes.get(name.lower())
            if node is None:
                continue
            n = self.g.doc["nodes"][node]
            for ch in gc.children:
                try:
                    if ch.id in p3d.QUATERNION_CHANNELS:
                        _param, frames, values = p3d.channel_keys(data, ch)
                        if frames and len(values) == len(frames):
                            n["rotation"] = list(rot(_quat_at(frames, values, frame, _smooth(data, ch))))
                    elif ch.id in VECTOR_CHANNELS:
                        param, frames, values = _vector_keys(data, ch)
                        if frames and param in ("TRAN", "TRA") and len(values) == len(frames):
                            n["translation"] = list(pos(_sample(frames, values, frame, _smooth(data, ch))))
                except (p3d.P3dError, struct.error, IndexError, KeyError):
                    continue
            moved.append(name)
        return moved

    def sky(self, ref: Ref, parent: Optional[int] = None, **place) -> int:
        """A sky's composite drawable. With self.hour, its skeleton is posed for that hour by the animation
        PTRN_<its name> (frame hour x 10: the sun, its flares and the moon where the game puts them; the rest
        pose has the sun under the ground) and its meshes get the colours of that hour (see sky_colours).
        Returns its top node."""
        top = self.composite(ref, parent, **place)
        for node in _under(self.g.doc, top):                # the game draws the sky without writing depth
            for prim in self.g.doc["meshes"][node["mesh"]]["primitives"] if "mesh" in node else []:
                self.g.doc["materials"][prim["material"]].setdefault("extras", {})["depthWrite"] = False
        if self.hour is None:
            return top
        copy = next((cp for cp in self.copies if getattr(cp, "group", None) == top), None)
        anim = self.find_animation("PTRN_" + ref.name, (ref.source,))
        if copy is not None and anim is not None:
            self.pose(copy, anim, max(0.0, min(24.0, self.hour)) * FRAMES_PER_HOUR)
            self.posed.add(id(anim.chunk))
        self.g.doc["nodes"][top].setdefault("extras", {})["hour"] = self.hour
        return top

    # the sea

    def sky_colour(self, weather: str = "clear") -> Optional[Tuple[float, float, float]]:
        """The colour of the weather's sky (0..1 each): the average vertex colour of its mesh drawn first (the
        highest draw-order key: the clear sky's dome, skyboxShape, one flat colour), with the colour set of
        self.hour added if there is an hour (sky_colours), else as stored (the night sky). None when the
        library has no sky for the weather."""
        pick = next((comp for comp, name in skies(self.lib, main_only=False).items()
                     if is_rain_sky(name) == (weather == "rain")), None)
        ref = self.lib.find("composite", pick) if pick else None
        if ref is None:
            return None
        best: Optional[Tuple[float, Ref]] = None
        for k in ref.chunk.children:
            if k.id != COMPOSITE_PROP:
                continue
            mref = self.lib.find("mesh", composite_prop(ref.data, k)[0], (ref.source,))
            if mref is not None:
                key = draw_order(mref.data, mref.chunk)
                key = 0.5 if key is None else key                  # the game counts no key as 0.5
                if best is None or key > best[0]:
                    best = (key, mref)
        if best is None:
            return None
        dome = best[1]
        tinted = self.sky_colours(dome) if self.hour is not None else None
        total, n, first = [0.0, 0.0, 0.0], 0, 0
        for pg in (k for k in dome.chunk.children if k.id == PRIM_GROUP):
            try:
                geo = geometry(dome.data, pg)
            except (struct.error, IndexError, ValueError):
                geo = None
            if geo is None:
                continue
            count = len(geo.positions)
            colours = geo.colours if geo.colours and len(geo.colours) == count else [0xFFFFFFFF] * count
            if tinted is not None:
                colours = add_colours(colours, tinted[1], first, count)
            first += count
            for c in colours:
                for i, s in enumerate((16, 8, 0)):
                    total[i] += (c >> s) & 0xFF
            n += len(colours)
        return tuple(round(t / n / 255, 4) for t in total) if n else None  # type: ignore[return-value]

    def sea(self, lo: Sequence[float], hi: Sequence[float], weather: str = "clear", parent: Optional[int] = None) -> int:
        """The sea (OCEAN): flat, at height 0, reaching OCEAN_MARGIN past the box lo..hi (glTF's space) on every
        side, made of OCEAN_TILE squares on a grid from 0, 0 so that seas made for different scenes line up. Its
        picture is ocean_text's (water_01.bmp) repeating every 1 / DetailTextureScale metres, laid at
        DetailOpacity over the sea's colour: the reflection's tint times the sky's colour (sky_colour, for the
        hour if there is one; white without a sky in the files). It is see-through at ReflectionAlphaScale
        (0.98) and unlit (its colour is the sky's, reflected). The node's extras hold the settings. Returns
        its node."""
        x0 = math.floor((lo[0] - OCEAN_MARGIN) / OCEAN_TILE) * OCEAN_TILE
        x1 = math.ceil((hi[0] + OCEAN_MARGIN) / OCEAN_TILE) * OCEAN_TILE
        z0 = math.floor((lo[2] - OCEAN_MARGIN) / OCEAN_TILE) * OCEAN_TILE
        z1 = math.ceil((hi[2] + OCEAN_MARGIN) / OCEAN_TILE) * OCEAN_TILE
        repeats = round(OCEAN_TILE * OCEAN["DetailTextureScale"])      # whole repeats a square: no seams
        positions: List[Vec3] = []
        uvs: List[Tuple[float, float]] = []
        flat: List[int] = []
        nx, nz = int(round((x1 - x0) / OCEAN_TILE)), int(round((z1 - z0) / OCEAN_TILE))
        for i in range(nx):
            for j in range(nz):
                ax, az = x0 + i * OCEAN_TILE, z0 + j * OCEAN_TILE
                base = len(positions)
                for dx, dz in ((0, 0), (1, 0), (0, 1), (1, 1)):
                    positions.append((ax + dx * OCEAN_TILE, 0.0, az + dz * OCEAN_TILE))
                    uvs.append((float(dx * repeats), float(dz * repeats)))
                flat += [base, base + 2, base + 1, base + 1, base + 2, base + 3]      # facing up
        sky = self.sky_colour(weather)
        tint = (OCEAN["ReflectionRedScale"], OCEAN["ReflectionGreenScale"], OCEAN["ReflectionBlueScale"])
        colour = [round(t * s, 4) for t, s in zip(tint, sky or (1.0, 1.0, 1.0))]
        alpha = OCEAN["ReflectionAlphaScale"]
        ref = self.lib.find("shader", OCEAN_SHADER)
        info = shader_info(ref.data, ref.chunk) if ref else None
        picture = next((t for p, t in (info or {}).get("textures", []) if p == "TEX"), OCEAN_TEXTURE)
        ti = self.made_texture(picture, "sea", lambda rgba: sea_picture(rgba, colour, OCEAN["DetailOpacity"], alpha),
                               f"{colour}") if picture.lower() in self.lib.pictures else None
        pbr: dict = {"metallicFactor": 0.0, "roughnessFactor": 1.0}
        if ti is not None:
            pbr["baseColorTexture"] = {"index": ti}
        else:
            pbr["baseColorFactor"] = colour + [alpha]
        mat = self.g.add("materials", {"name": ref.name if ref else OCEAN_SHADER, "pbrMetallicRoughness": pbr,
                                       "alphaMode": "BLEND", "extensions": {"KHR_materials_unlit": {}},
                                       "extras": {"ocean": True, "blend": "alpha"}})
        self.g.used_extensions.add("KHR_materials_unlit")
        attrs = {"POSITION": self.g.accessor(positions, "VEC3", bounds=True, target=34962),
                 "NORMAL": self.g.accessor([(0.0, 1.0, 0.0)] * len(positions), "VEC3", target=34962),
                 "TEXCOORD_0": self.g.accessor(uvs, "VEC2", target=34962)}
        mesh = self.g.add("meshes", {"name": OCEAN["object"], "primitives": [{
            "attributes": attrs, "indices": self.g.accessor(flat, "SCALAR", 5125 if len(positions) > 65535 else 5123,
                                                             target=34963), "material": mat, "mode": 4}]})
        extras = {"ocean": True, "height": 0.0, "seaColour": colour, "skyColour": list(sky) if sky else None,
                  "weather": weather, "picture": picture if ti is not None else None}
        if self.hour is not None:
            extras["hour"] = self.hour
        extras.update(OCEAN)
        when = f"at {self.hour:g} h" if self.hour is not None else "as stored"
        self.report.notes.append(f"the sea: {x1 - x0:,.0f} by {z1 - z0:,.0f} m at height 0, tinted by "
                                 + (f"the {weather} sky {when}" if sky else "white (no sky in the files)")
                                 + (f", with {picture}" if ti is not None else f", without {picture} (not in the files)"))
        return self.g.node(OCEAN["object"], parent, mesh=mesh, extras=extras)


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


def _finite(v: Optional[Sequence[float]]) -> bool:
    return bool(v) and all(math.isfinite(x) for x in v)  # type: ignore[union-attr]


# --------------------------------------------------------------------------- lights

def file_lights(src: Source) -> Tuple[Dict[str, dict], List[dict], Dict[str, dict]]:
    """A file's lights (p3d.light, by name in lower case, in file order), its light groups (0x2380:
    name, lights) and its light group records (0x8800007: name, light group, kind, frame controllers), the
    records by their light group's name in lower case."""
    lights: Dict[str, dict] = {}
    groups: List[dict] = []
    records: Dict[str, dict] = {}
    for c in src.chunks:
        if c.id == LIGHT:
            info = p3d.light(src.data, c)
            if info:
                lights.setdefault(info["name"].lower(), info)
        elif c.id == LIGHT_GROUP:
            f = p3d.fields(src.data, c)
            if f:
                groups.append(f)
        elif c.id == LIGHT_GROUP_RECORD:
            f = p3d.fields(src.data, c)
            if f:
                records.setdefault(f["light group"].lower(), f)
    return lights, groups, records


def decay_reach(decay: Optional[dict]) -> Optional[float]:
    """How far a light's decay range reaches, for glTF's range: its outer size (a sphere's first number, the
    radius; a box's or an ellipsoid's largest). None without one."""
    if not decay or decay.get("shape") == "none":
        return None
    outer = decay.get("outer") or ()
    reach = outer[0] if decay.get("shape") == "sphere" and outer else max(outer, default=0.0)
    return reach if math.isfinite(reach) and reach > 0 else None


def _sample(frames: List[int], values: List[tuple], f: float, smooth: bool = True) -> tuple:
    """A channel's value at frame f: in a straight line between its keys, or (smooth False) the last key's."""
    if smooth:
        return _at(frames, values, f)
    held = values[0]
    for k, v in zip(frames, values):
        if k <= f:
            held = v
    return held


def _smooth(data: bytes, ch: p3d.Chunk) -> bool:
    """Whether a channel is interpolated between its keys (its Channel Interpolation Mode, 0x121110; yes
    without one)."""
    mode = ch.find(0x121110)
    return p3d.fields(data, mode).get("interpolate", True) if mode is not None else True


def _slerp(a: Sequence[float], b: Sequence[float], t: float) -> Quat:
    """The rotation a fraction t of the way from quaternion a to b, along the shorter arc: q and -q are the
    same rotation, and the PTRN_sky keys change sign between two keys."""
    dot = sum(x * y for x, y in zip(a, b))
    if dot < 0:
        b, dot = [-y for y in b], -dot
    if dot > 0.9995:
        q = [x + (y - x) * t for x, y in zip(a, b)]
    else:
        theta = math.acos(min(1.0, dot))
        s = math.sin(theta)
        wa, wb = math.sin((1 - t) * theta) / s, math.sin(t * theta) / s
        q = [wa * x + wb * y for x, y in zip(a, b)]
    n = math.sqrt(sum(v * v for v in q)) or 1.0
    return tuple(v / n for v in q)  # type: ignore[return-value]


def _quat_at(frames: List[int], values: List[tuple], f: float, smooth: bool = True) -> Quat:
    """A quaternion channel's rotation at frame f: along the shorter arc between its keys (held before the
    first and after the last), or (smooth False) the last key's."""
    if smooth:
        for i in range(1, len(frames)):
            a, b = frames[i - 1], frames[i]
            if a < f <= b:
                return _slerp(values[i - 1], values[i], (f - a) / (b - a))
    held = _sample(frames, values, f, False)
    return _slerp(held, held, 0.0)                       # the key itself, made unit length


def add_colours(colours: Optional[List[int]], amounts: Dict[int, Sequence[float]], first: int, count: int) -> List[int]:
    """Vertex colours (0xAARRGGBB) with amounts added to their red, green and blue, each kept to 255: the
    sky's colour sets add to the mesh's own colours (the night sky). amounts are by the mesh's vertex number,
    first being the number of colours[0]. A primitive group without colours starts from black."""
    out = []
    for i in range(count):
        c = colours[i] if colours and i < len(colours) else 0xFF000000
        add = amounts.get(first + i, (0, 0, 0))
        rgb = [min(255, max(0, round(((c >> s) & 0xFF) + a))) for s, a in zip((16, 8, 0), add)]
        out.append((c & 0xFF000000) | rgb[0] << 16 | rgb[1] << 8 | rgb[2])
    return out


def daylight(src: Source, lights: Dict[str, dict], records: Dict[str, dict], hour: float) -> List[str]:
    """Light the daylight for an hour (0 to 24). The records of the daylight and of the rain (kinds 0 and 1)
    name a frame controller (0x121201, type LITE) per light, which plays an animation of 241 frames, one
    day (frame 0 midnight, frame 120 noon), on it: its CLR channel (Colour) gives the light's colour and its
    DIR channel (vector) the way it shines, sampled at frame hour x 10. The values the lights store are
    the midnight ones. Changes the lights in place and returns the names of those changed."""
    frame = max(0.0, min(24.0, hour)) * FRAMES_PER_HOUR
    controllers: Dict[str, p3d.Chunk] = {}
    anims: Dict[str, p3d.Chunk] = {}
    for c in src.chunks:
        try:
            if c.id == FRAME_CONTROLLER:
                controllers.setdefault(_text(src.data, c.body[0] + 4)[0].lower(), c)
            elif c.id == ANIMATION:
                anims.setdefault(chunk_name(src.data, c).lower(), c)
        except IndexError:
            continue
    changed = []
    for rec in records.values():
        if rec.get("kind") not in DAYLIGHT_KINDS:
            continue
        for name in rec.get("frame controllers", []):
            fc = controllers.get(name.lower())
            if fc is None:
                continue
            try:
                kind, target, anim = frame_controller(src.data, fc)
            except (struct.error, IndexError, UnicodeDecodeError):
                continue
            info, a = lights.get(target.lower()), anims.get(anim.lower())
            if kind.upper() != "LITE" or info is None or a is None:
                continue
            got = False
            for ch in p3d.walk(a.children):
                if ch.id != p3d.COLOUR_CHANNEL and ch.id not in VECTOR_CHANNELS:
                    continue
                try:
                    if ch.id == p3d.COLOUR_CHANNEL:
                        param, frames, values = p3d.channel_keys(src.data, ch)
                    else:
                        param, frames, values = _vector_keys(src.data, ch)
                except (p3d.P3dError, struct.error, IndexError, KeyError):
                    continue
                if not frames or len(values) != len(frames):
                    continue
                mode = ch.find(0x121110)
                smooth = p3d.fields(src.data, mode).get("interpolate", True) if mode is not None else True
                v = _sample(frames, values, frame, smooth)
                if param == "CLR" and ch.id == p3d.COLOUR_CHANNEL:
                    info["argb"] = "".join(f"{max(0, min(255, round(x))):02x}" for x in v)
                    got = True
                elif param == "DIR" and _finite(v) and any(v):
                    info["direction"] = tuple(v)
                    got = True
            if got:
                info["hour"] = hour
                changed.append(info["name"])
    return changed


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
    return [comp for _name, comp, _kind in world_geometries(src)] if src.main else []


def world_geometries(src: Source) -> List[Tuple[str, str, int]]:
    """A file's World Geometry chunks (0x8800003) as (name, the composite drawable's name, kind). The kind goes with
    how the name starts (SPEC-003, section 4): 0, or 1 shadowed_, 3 low_LOD_, 5 underwater_, 6 cbvlitdecals_,
    7 interiorfloors_, 8 cardsnight_; 0 when a damaged chunk ends before it."""
    out = []
    for c in src.chunks:
        if c.id != WORLD_GEO:
            continue
        r = p3d._R(src.data, *c.body)
        try:
            name, comp = r.text(), r.text()
        except IndexError:
            continue
        out.append((name, comp, r.u32() if r.left() >= 4 else 0))
    return out


def zone_entries(src: Source) -> Dict[str, dict]:
    """The draw distances of a file's world geometry: {World Geometry name in lower case: its Zone Package Entry's
    fields} (0x8800009 under a Zone Package, 0x8800004; p3d.fields). The first entry for a name wins."""
    out: Dict[str, dict] = {}
    for c in src.chunks:
        if c.id != ZONE_PACKAGE:
            continue
        for k in c.children:
            f = p3d.fields(src.data, k) if k.id == ZONE_ENTRY else {}
            if f.get("name") and "fade" in f:
                out.setdefault(f["name"].lower(), f)
    return out


def draw_distance(entry: Optional[dict]) -> Optional[dict]:
    """A world geometry's drawDistance extras from its Zone Package Entry (zone_entries): near, far and fade, and
    "from", the point the distance is measured from, at height 0 in glTF's space, when the entry has one (the game
    measures from the world geometry itself when it hasn't). None without an entry. The game draws it while the
    camera is farther than near and nearer than far, fading over fade (SPEC-003, section 3.2, reported)."""
    if not entry:
        return None
    out = {k: float(entry[k]) for k in ("near", "far", "fade")}
    x, z = entry.get("point") or (0.0, 0.0)
    if x or z:
        out["from"] = [v + 0.0 for v in pos((x, 0.0, z))]       # + 0.0: no minus zero
    return out


def skies(lib: Library, main_only: bool = True) -> Dict[str, str]:
    """The skies in the library's (main) files: {composite drawable's name in lower case: the Sky chunk's
    (0x8800002) name}. Common.p3d has sky and rainy_skybox."""
    out: Dict[str, str] = {}
    for src in lib.sources:
        if main_only and not src.main:
            continue
        for c in src.chunks:
            if c.id == SKY:
                f = p3d.fields(src.data, c)
                if f.get("composite drawable"):
                    out.setdefault(f["composite drawable"].lower(), f["name"])
    return out


def is_rain_sky(name: str) -> bool:
    """A sky whose name starts rainy_ is the rain's; the game starts it faded out."""
    return name.lower().startswith("rainy_")


def _scene_extras(b: Builder, hour: Optional[float], weather: Optional[str], fog: Optional[dict]) -> None:
    """An export made with an hour or a weather says so in its scene's extras, with the fog of that hour."""
    if hour is None and weather is None:
        return
    extras: dict = {"weather": weather or "clear"}
    if hour is not None:
        extras["hour"] = hour
    if fog:
        extras["fog"] = fog
    b.g.doc["scenes"][0]["extras"] = extras


def export(lib: Library, map_mode: bool = False, only: Sequence[str] = (), anims: Sequence[Ref] = (),
           lod: bool = False, hour: Optional[float] = None, weather: Optional[str] = None,
           fog: Optional[dict] = None, also=None, ocean: bool = False, beside_detail: bool = False) -> Tuple[bytes, Report]:
    """The glTF (.glb) for the library's main files, and a report of what went in.
    also: called with the Builder once the files are in, to put more into the same scene (a cutscene's
    people on the map they stand on).
    ocean: with map_mode, the sea round the map (Builder.sea), when there is map geometry.
    beside_detail: the low-detail hull is exported for a scene whose detailed areas are in other files (a split
    export with lod): its nodes are marked hidden, as when the detailed areas are in this one.

    Models (the default): every skin with its skeleton, every composite drawable that isn't a map's
    world geometry (a prop's with its properties in its extras: Builder.mark_prop), and every mesh no
    composite uses, side by side. A sky (Common.p3d) with an hour is
    posed and coloured for it (Builder.sky); with a weather, only that weather's sky goes in.
    Map (map_mode): per file, its world geometry (WorldGeo 0x8800003 names a composite drawable whose
    meshes sit in world space; its top node's extras give its kind, "worldGeometryKind", and its zone package
    entry's draw distance, "drawDistance", see draw_distance; one the game draws only when the camera is
    farther than its near distance is marked "hidden": true), a copy of each model its instance objects place,
    each in the state its record names (starting_state) and with the prop's properties (Builder.mark_prop), and its
    lights (see Builder.lights; hour lights the daylight for that hour, 0 to 24; weather, "clear" or "rain",
    picks the daylight, clear when not given). Low-detail files (miami_lod, islands_LOD) are left out when
    there's anything else, unless lod is set: then their world geometry (the low-detail hull) is marked
    {"lowDetailHull": true, "hidden": true}, so that it doesn't cover the detailed areas (the game fades it
    out near the camera). With ocean, the sea round all of it.
    With an hour or a weather, the scene's extras say which, with fog (fog.fog_at) if given."""
    if weather is not None and weather not in WEATHER_KIND:
        raise ExportError(f"the weather is clear or rain, not {weather!r}")
    b = Builder(lib)
    b.hour = hour
    wanted = {n.lower() for n in only}
    if map_mode:
        mains = [src for src in lib.sources if src.main]
        detailed = any(not _is_lod(src) and _world_geo(lib, src) for src in mains)
        if not lod and detailed:
            mains = [src for src in mains if not _is_lod(src)]
        groups = []
        for src in mains:
            geos = [g for g in world_geometries(src) if not wanted or g[1].lower() in wanted]
            placing = [(m, r) for m, r in instance_objects(src) if not wanted or m.lower() in wanted]
            if not geos and not placing:
                continue
            group = b.g.node(Path(src.label).stem)
            groups.append(group)
            prefer = [src] + lib.region_of(src)
            hull = _is_lod(src)
            zones = zone_entries(src)
            far_off = []                                        # drawn only from afar: hidden
            for geo, comp, kind in geos:
                cref = lib.find("composite", comp, prefer)
                if cref:
                    top = b.composite(cref, group)
                    b.report.models.append(comp)
                    mark: dict = {"worldGeometryKind": kind}
                    dist = draw_distance(zones.get(geo.lower()))
                    if dist:
                        mark["drawDistance"] = dist
                        if dist["near"] > 0:
                            mark["hidden"] = True
                            far_off.append(geo)
                    if hull:
                        mark["lowDetailHull"] = True
                        if detailed or beside_detail:
                            mark["hidden"] = True
                    b.g.doc["nodes"][top].setdefault("extras", {}).update(mark)
                else:
                    b.report.missing_drawables.add(comp)
            if hull and geos and (detailed or beside_detail):
                b.report.notes.append(f"{Path(src.label).stem}: the low-detail hull, marked hidden (lowDetailHull): next to "
                                      "the detailed areas it would cover them")
            if far_off:
                stem = Path(src.label).stem
                b.report.notes.append(f"{stem}: {len(far_off)} far-away stand-in(s), marked hidden: the game draws them "
                                      "only when the camera is farther than their near distance (drawDistance): "
                                      + ", ".join(far_off[:12]) + (" ..." if len(far_off) > 12 else ""))
            if placing:
                placed = b.g.node(Path(src.label).stem + " instances", group)
                b.prop = True                                   # placed props: their leaves (see Builder.mesh)
                for model, records in placing:
                    mref = _model_for(lib, model, prefer)
                    if not mref:
                        b.report.unplaced[model] = b.report.unplaced.get(model, 0) + len(records)
                        continue
                    states = b.states_of(mref, mref.name)
                    for rec in records:
                        if not any(rec[:3]):
                            b.report.at_origin += 1             # never moved from (0, 0, 0): left out
                            continue
                        t, q, sc = instance_trs(rec)
                        start = starting_state(states, rec[11])
                        top = b.composite(mref, placed, model, state=start, translation=t, rotation=q, scale=sc)
                        b.mark_prop(top, mref, mref.name, start)  # its state when not the first, its properties
                        b.report.placed += 1
                b.prop = False
            if not wanted:
                b.lights(src, group, hour, weather or "clear")
        pts: List[List[float]] = []
        for group in groups:
            _bounds(b, group, _identity(), pts)
        if pts:
            b.report.box = ([min(p[i] for p in pts) for i in range(3)], [max(p[i] for p in pts) for i in range(3)])
        if ocean and b.report.box:
            b.sea(b.report.box[0], b.report.box[1], weather or "clear")
    else:
        parts = _composite_parts(lib)
        world = {c.lower() for src in lib.sources for c in _world_geo(lib, src)}
        sky_names = skies(lib)
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
            if name.lower() in sky_names:
                if weather is not None and is_rain_sky(sky_names[name.lower()]) != (weather == "rain"):
                    continue                                    # the other weather's sky
                tops.append((name, b.sky(ref)))
                continue
            tops.append((name, b.composite(ref)))
            b.mark_prop(tops[-1][1], ref, name)                 # the prop's properties, if it is one
            states = b.states_of(ref, name)                     # what it becomes: beside it, kept apart
            for i, (state, shown) in enumerate(states[1:], 1):
                if shown != states[0][1] and any(shown.values()):
                    label = f"{name} ({state})"
                    tops.append((label, b.composite(ref, label=label, state=i)))
        for ref in lib.main_chunks(MESH):
            name = ref.name
            if (wanted and name.lower() not in wanted) or (not wanted and name.lower() in parts):
                continue
            node = b.place_mesh(ref, name, None)                # with its shadow decals, if any
            if node is not None:
                tops.append((name, node))
        _lay_out(b, tops)
        b.report.models = [n for n, _ in tops]
    camera_moves = _cameras(lib, b) if not map_mode else set()
    for ref in list(anims) + list(lib.main_chunks(ANIMATION)):
        if id(ref.chunk) in camera_moves or id(ref.chunk) in b.posed:
            continue                                            # a posed sky holds its hour's pose: not played
        if not b.animation(ref):
            b.report.unmatched_animations += 1
    if also is not None:
        also(b)
    _scene_extras(b, hour, weather, fog)
    if not b.g.doc["scenes"][0]["nodes"]:
        raise ExportError("nothing in these files to export" + (" (is it a map area? try --map)" if not map_mode and
                                                                 any(_world_geo(lib, s) for s in lib.sources) else ""))
    return b.g.glb(), b.report


def sky_export(lib: Library, hour: Optional[float] = None, weather: str = "clear", centre: Sequence[float] = (0.0, 0.0),
               reach: float = 0.0, fog: Optional[dict] = None) -> Tuple[bytes, Report]:
    """The sky for a whole city's scene, from the library's files (Common.p3d): the weather's Sky
    (0x8800002; a rainy_ one for rain), its composite drawable posed and coloured for the hour (Builder.sky),
    or without an hour as stored, with its PTRN_ animation to play the day. The game draws the sky at twice
    its size and moves it with the camera (across, not up), so it is always round the viewer. A scene has no
    camera to follow, so the sky stands at centre (x and z in glTF's space, height 0), made big enough to
    reach a tenth past reach (from centre to the city's farthest corner), and at least twice its size. The
    scene's extras say the weather and the hour, with the fog if given."""
    if weather not in WEATHER_KIND:
        raise ExportError(f"the weather is clear or rain, not {weather!r}")
    pick = next(((comp, name) for comp, name in skies(lib, main_only=False).items()
                 if is_rain_sky(name) == (weather == "rain")), None)
    ref = lib.find("composite", pick[0]) if pick else None
    if pick is None or ref is None:
        raise ExportError(f"no sky for {weather} weather in these files (Common.p3d has the game's)")
    b = Builder(lib)
    b.hour = hour
    top = b.sky(ref)
    pts: List[List[float]] = []
    _bounds(b, top, _identity(), pts)
    radius = max((math.hypot(p[0], p[2]) for p in pts), default=0.0)
    scale = max(SKY_SCALE, SKY_MARGIN * reach / radius) if radius > 0 else SKY_SCALE
    node = b.g.doc["nodes"][top]
    node.update(translation=[float(centre[0]), 0.0, float(centre[1])], scale=[scale] * 3)
    node.setdefault("extras", {}).update({"sky": pick[1], "weather": weather, "followsCamera": True})
    if hour is None:
        anim = b.find_animation("PTRN_" + ref.name, (ref.source,))
        if anim is not None:
            b.animation(anim)
    b.report.models.append(pick[1])
    _scene_extras(b, hour, weather, fog)
    return b.g.glb(), b.report


def sea_export(lib: Library, lo: Sequence[float], hi: Sequence[float], hour: Optional[float] = None,
               weather: str = "clear") -> Tuple[bytes, Report]:
    """The sea alone (Builder.sea) round the box lo..hi (glTF's space), for a scene made of several files (the
    whole city, a split export), whose areas then go without one each: its picture and the sky's colour for the
    hour and weather come from the library's files (Common.p3d)."""
    if weather not in WEATHER_KIND:
        raise ExportError(f"the weather is clear or rain, not {weather!r}")
    b = Builder(lib)
    b.hour = hour
    b.sea(lo, hi, weather)
    b.report.models.append(OCEAN["object"])
    return b.g.glb(), b.report


def lod_tod(lib: Library, islands: bool = False) -> Dict[str, str]:
    """The tod object's properties (fog.tod_object) from the low-detail city's file in the library:
    miami_lod.p3d's, or for the islands islands_LOD.p3d's if it has one."""
    import fog as FOG
    for stem in (("islands_lod", "miami_lod") if islands else ("miami_lod",)):
        for src in lib.sources:
            if Path(src.label).stem.lower() == stem:
                tod = FOG.tod_object(src.data, src.chunks)
                if tod:
                    return tod
    return {}


def scene_fog(lib: Library, scripts: Dict[str, Path], hour: float, weather: str = "clear") -> Tuple[Optional[dict], str]:
    """The fog for an export's hour and weather (fog.fog_at), and "" or why there is none. scripts: from
    fog.find_scripts. The islands' fog when the export's own files are islands_LOD.p3d (and not
    miami_lod.p3d), else Miami's."""
    import fog as FOG
    mains = {Path(s.label).stem.lower() for s in lib.sources if s.main}
    islands = "islands_lod" in mains and "miami_lod" not in mains
    script = scripts.get("islands" if islands else "miami")
    if script is None:
        return None, f"no fog: the game's script scriptc/{FOG.ISLAND_SCRIPT if islands else FOG.MIAMI_SCRIPT} wasn't found"
    tod = lod_tod(lib, islands)
    if not tod:
        return None, "no fog: the tod object (in miami_lod.p3d) isn't in the files used"
    try:
        found = FOG.fog_at(hour, tod, FOG.read_objects(Path(script)), weather, islands)
    except (OSError, FOG.FogError) as e:
        return None, f"no fog: {e}"
    if found is None:
        return None, f"no fog: {Path(script).name} has none of the EnvironmentObjects the tod object names"
    return found, ""


def _under(doc: dict, node: int) -> Iterable[dict]:
    """A node and every node under it."""
    todo = [node]
    while todo:
        n = doc["nodes"][todo.pop()]
        yield n
        todo += n.get("children", [])


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
OCEAN_FILE = "ocean.glb"               # a split export's (and the whole city's) sea, beside the areas


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
    ap.add_argument("--lod", action="store_true",
                    help="with --map, keep the low-detail city too (next to real areas, marked hidden)")
    ap.add_argument("--no-ocean", action="store_true",
                    help="with --map, leave the sea out (else a flat sea at height 0 round the map; with --split, "
                         "one ocean.glb beside the areas)")
    ap.add_argument("--split", action="store_true",
                    help="with --map, one .glb per map area in the folder OUT (they line up when imported together)")
    ap.add_argument("--hour", type=float, default=None,
                    help="with --map, light the daylight (in miami_lod.p3d, islands_LOD.p3d) for this hour, 0 to 24; "
                         "without it the lights are as the files store them, at midnight. Without --map, for the sky "
                         "(Common.p3d): the sun and the sky's colours of that hour. Adds that hour's fog to "
                         "the scene's extras when the game's scripts are found")
    ap.add_argument("--weather", choices=WEATHERS, default=None,
                    help="clear (when not given, as the game starts) or rain: which daylight lights the scene (the "
                         "other is kept as data only), which sky and which fog")
    ap.add_argument("--scripts", type=Path, nargs="*", default=None,
                    help="the game's scripts for the fog with --hour: scriptc/graphanims.cso (Miami), "
                         "island_envobjects.cso (the islands), or a folder holding them or a scriptc folder; "
                         "without it they are looked for in the files' folder and up to three folders above it, and in "
                         "a scriptc folder in any of those")
    ap.add_argument("--only", nargs="*", default=[], help="just these models")
    ap.add_argument("--list", action="store_true", help="say what would be exported, write nothing")
    a = ap.parse_args(argv)
    try:
        if a.hour is not None and not 0 <= a.hour <= 24:
            raise ExportError("--hour is from 0 to 24")
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
        scripts: Dict[str, Path] = {}
        if a.hour is not None:
            import fog as FOG
            near = [] if a.scripts is not None else \
                sorted({p for f in mains for p in [f.resolve().parent] + list(f.resolve().parents)[1:4]})
            scripts = FOG.find_scripts(a.scripts if a.scripts is not None else near)
        cache: Dict[Path, bytes] = {}
        parsed: dict = {}
        empty = 0
        boxes: List[Tuple[List[float], List[float]]] = []
        detail_split = a.split and any(not all("_lod" in f.stem.lower() for f in g) for g in groups)

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
            if a.hour is not None and not a.map and not skies(lib):
                raise ExportError("--hour is for --map, or for the sky (Common.p3d)")
            fog, no_fog = scene_fog(lib, scripts, a.hour, a.weather or "clear") if a.hour is not None else (None, "")
            hull_only = all("_lod" in f.stem.lower() for f in group)
            try:
                glb, report = export(lib, a.map, a.only, refs, a.lod, a.hour, a.weather, fog,
                                     ocean=a.map and not a.split and not a.no_ocean,
                                     beside_detail=detail_split and hull_only)
            except ExportError:
                if a.split:
                    empty += 1                                  # a region, a shared file: no area of its own
                    continue
                raise
            out = a.out / (_area(group[0]) + ".glb") if a.split else a.out
            if a.split:
                print(f"== {out.name}")
            if no_fog:
                report.notes.append(no_fog + (" (--scripts says where)" if "wasn't found" in no_fog else ""))
            for line in report.lines():
                print(line)
            if not a.list:
                out.write_bytes(glb)
                print(f"wrote {out} ({len(glb):,} bytes)")
            if report.box:
                boxes.append(report.box)
        if a.split and a.map and not a.no_ocean and boxes:     # one sea for all the areas, which line up with it
            lib = Library(parsed)
            for f in extra:
                lib.add(f.name, read(f), main=False)
            lo = [min(bx[0][i] for bx in boxes) for i in range(3)]
            hi = [max(bx[1][i] for bx in boxes) for i in range(3)]
            glb, report = sea_export(lib, lo, hi, a.hour, a.weather or "clear")
            print(f"== {OCEAN_FILE}")
            for line in report.lines()[1:]:
                print(line)
            if not a.list:
                (a.out / OCEAN_FILE).write_bytes(glb)
                print(f"wrote {a.out / OCEAN_FILE} ({len(glb):,} bytes)")
        if a.split and empty:
            print(f"({empty} file group(s) with no map area of their own, such as regions and shared files, used "
                  "only for what the areas need)")
    except (OSError, p3d.P3dError, ExportError) as e:
        print(f"p3d_gltf: {e}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
