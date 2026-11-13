#!/usr/bin/env python3
"""
Read Pure3D (.p3d) files: the chunk tree with every chunk named, the fields of the chunks for models,
skins, skeletons, shaders, textures, animations, lights, the sky, the stream graph, the shadow records, state
props, zone packages, occluders, characters and vehicles, and the models as .obj files you can open in Blender.

    python portal/tools/p3d.py FILE.p3d                 the chunk tree, with each known chunk's fields
    python portal/tools/p3d.py FILE.p3d --depth 2       only the first two levels
    python portal/tools/p3d.py FILE.p3d --obj OUT.obj   the meshes and skins as a Wavefront .obj (plain
                                                        geometry; p3d_gltf.py writes textured scenes with
                                                        skeletons, animations and maps for Blender)

A file is "P3D" 0xFF, u32 12, u32 file size, then chunks: u32 id, u32 size of the chunk's own data (with
these 12 bytes), u32 size with its sub-chunks, the data, then the sub-chunks. Text is a u8 length (padded
to keep things 4-byte aligned) and that many bytes, NUL-padded. The layouts are in docs/FORMATS.md; the
chunk names follow the Donut Team's Pure3D documentation where it has them, and a name ending in (?) is
a guess.

Your own copies, on your own computer; standard library only.
"""

from __future__ import annotations

import argparse
import math
import struct
import sys
from dataclasses import dataclass, field
from pathlib import Path
from typing import Callable, Dict, Iterator, List, Optional, Tuple

MAGIC = b"P3D\xff"

NAMES: Dict[int, str] = {
    0x7000: "History",
    0x10000: "Mesh", 0x10001: "Skin", 0x10002: "Old Primitive Group", 0x10003: "Bounding Box",
    0x10004: "Bounding Sphere", 0x10005: "Position List", 0x10006: "Normal List", 0x10007: "UV List",
    0x10008: "Colour List", 0x1000A: "Index List", 0x1000B: "Matrix List", 0x1000C: "Weight List",
    0x1000D: "Matrix Palette", 0x10010: "Packed Normal List", 0x10011: "Vertex Shader",
    0x10012: "Memory Image Vertex List", 0x10013: "Memory Image Index List",
    0x10014: "Memory Image Vertex Description", 0x10017: "Render Status", 0x1001B: "Topology (?)",
    0x1001C: "Extra Colour List (?)",
    0x10020: "Primitive Group", 0x10021: "Vertex Precision (?)",
    0x11000: "Shader", 0x11002: "Shader Texture Parameter", 0x11003: "Shader Integer Parameter",
    0x11004: "Shader Float Parameter", 0x11005: "Shader Colour Parameter",
    0x18000: "Frontend Project", 0x18001: "Frontend Screen", 0x18002: "Frontend Page",
    0x18009: "Frontend Polygon", 0x1800C: "Frontend String Hard Coded",
    0x19000: "Texture", 0x19001: "Image", 0x19002: "Image Data", 0x19005: "Sprite",
    0x22000: "Texture Font", 0x22001: "Texture Glyph List",
    0x23000: "Skeleton", 0x23001: "Skeleton Joint",
    0x121000: "Animation", 0x121001: "Animation Group", 0x121002: "Animation Group List",
    0x121004: "Animation Size", 0x121006: "Animation Header", 0x121007: "Animation Channel Count",
    0x121100: "Float1 Channel", 0x121101: "Float2 Channel", 0x121102: "Vector1DOF Channel",
    0x121103: "Vector2DOF Channel", 0x121104: "Vector3DOF Channel", 0x121105: "Quaternion Channel",
    0x121107: "Entity Channel", 0x121108: "Boolean Channel", 0x121109: "Colour Channel",
    0x12110E: "Integer Channel", 0x121110: "Channel Interpolation Mode",
    0x121111: "Compressed Quaternion Channel", 0x121112: "Compressed Quaternion Channel2",
    0x121114: "Byte Quaternion Channel (?)",
    0x121200: "Old Frame Controller", 0x121201: "Frame Controller",
    # Named after the classes that load them in the Xbox game (default.xbe's run-time type names), so
    # these are the game's own names: docs/FORMATS.md has the list and where each was found.
    0x2200: "Camera", 0x2380: "Light Group", 0x13000: "Light", 0x14000: "Locator", 0x17006: "Billboard",
    0x1001A: "Shadow Mesh", 0x10019: "Shadow Skin", 0x1580C: "Particle System",
    0x1800D: "Text Bible", 0x21000: "Expression", 0x21001: "Expression Group", 0x21002: "Expression Mixer",
    0x22002: "Image Font", 0x121202: "Multi Controller",
    0x123000: "Composite Drawable", 0x123001: "Composite Drawable Part",
    0x7010000: "Collision Object", 0x7011000: "Rigid Body", 0x7010025: "World Collision Object",
    0x8011000: "Nav Mesh", 0x8011005: "Road Graph", 0x802000D: "State Prop Data",
    0x8800000: "Character", 0x8800001: "Vehicle", 0x8800002: "Sky", 0x8800003: "World Geometry",
    0x8800004: "Zone Package", 0x8800005: "State Prop", 0x8800007: "Light Group (game)", 0x8800008: "Shadow",
    0x880000A: "Occluder", 0x8800100: "Stream Package", 0x8800101: "Stream Trigger", 0x8800102: "NIS Package",
    0x8800104: "Script File", 0x8800105: "Load Package", 0x8800108: "Cement Header", 0x8800112: "Load Package Name",
    0x8800113: "NIS Stream Data", 0x8800114: "NIS Stream Partition Info", 0x8800150: "CV Load Object",
    0x8800160: "Traffic Config", 0x8800161: "Subzone Traffic Trigger", 0x8800180: "Script Object",
    0x8800181: "Game Group", 0x8800201: "Water Shallow Area", 0x8800202: "Water Obstacle", 0x8800203: "Water Dock",
    0x9900190: "Script Object Data", 0x9900191: "Game Group Data", 0x9900192: "Script Object Property (?)",
    0x9900194: "Script Object Property Value (?)",
    # A light's sub-chunks, the draw-order key and the sky's vertex-colour sets: descriptive names of ours,
    # from the clean-room spec docs/cleanroom/SPEC-001-lights-sky-streaming.md.
    0x13001: "Light Direction", 0x13002: "Light Position", 0x13003: "Light Spot Cone",
    0x13004: "Light Casts Shadows", 0x13006: "Light Decay Range", 0x13007: "Light Decay Range Rotation",
    0x13008: "Light Illumination Kind", 0x122000: "Draw Order",
    0x121305: "Vertex Colour Sets", 0x121306: "Vertex Colour Set", 0x10F02: "Vertex Colour Amounts",
    # A state prop's parts and a zone package's entries: descriptive names of ours, from the clean-room spec
    # docs/cleanroom/SPEC-003-props-zones-xbox-blending.md.
    0x802000E: "Prop State", 0x8020002: "Part Visibility", 0x8020003: "Prop State Animation",
    0x8020008: "Prop Property", 0x802000B: "Prop State Effect", 0x8800009: "Zone Package Entry",
}
for _cid in range(0x1005002, 0x100500C):
    NAMES[_cid] = "Sound Entity"

PRIMITIVES = {0: "triangle list", 1: "triangle strip", 2: "line list", 3: "line strip", 4: "points"}
VERTEX_BITS = ((0x2000, "position"), (0x0010, "normal"), (0x0020, "colour"), (0x0080, "matrix indices"),
               (0x0100, "weights"))
QUATERNION_CHANNELS = (0x121105, 0x121111, 0x121112, 0x121114)
COLOUR_CHANNEL = 0x121109
BOOLEAN_CHANNEL, ENTITY_CHANNEL = 0x121108, 0x121107
INTEGER_CHANNEL = 0x12110E
COLOUR_SETS, COLOUR_SET, COLOUR_AMOUNTS = 0x121305, 0x121306, 0x10F02
LIGHT_TYPES = {0: "ambient", 1: "point", 2: "directional", 3: "spot"}
DECAY_SHAPES = {0: "none", 1: "sphere", 2: "box", 3: "ellipsoid"}
ILLUMINATION = {0: "adds light", 1: "none", 2: "takes light away"}
# The state a placed copy of a prop starts in: the last of its instanceposition's twelve numbers is n for the
# n-th of these, 0 for the prop's own first state (SPEC-003, section 2). The prop's state of that name, letter
# case ignored, is the one; a prop without one starts in its first state.
START_STATES = ("idle", "final", "damage_1", "damage_2", "damage_3", "damage_4", "explosion", "open", "opening",
                "closed", "closing")


class P3dError(ValueError):
    pass


@dataclass
class Chunk:
    id: int
    offset: int
    head: int                   # size of the chunk's own data, with the 12-byte header
    total: int                  # with its sub-chunks
    depth: int
    children: List["Chunk"] = field(default_factory=list)

    @property
    def name(self) -> str:
        return NAMES.get(self.id, "")

    @property
    def body(self) -> Tuple[int, int]:
        """(start, end) of the chunk's own data."""
        return self.offset + 12, self.offset + self.head

    def find(self, cid: int) -> Optional["Chunk"]:
        return next((c for c in self.children if c.id == cid), None)


def read_tree(data: bytes, max_chunks: int = 500_000) -> List[Chunk]:
    """The top-level chunks, each with its sub-chunks. Damaged parts are left out."""
    if data[:4] != MAGIC or len(data) < 12:
        raise P3dError("not a Pure3D file")
    count = [0]

    def walk(off: int, end: int, depth: int) -> List[Chunk]:
        out: List[Chunk] = []
        while off + 12 <= end and count[0] < max_chunks:
            cid, head, total = struct.unpack_from("<III", data, off)
            if total < 12 or head < 12 or head > total or off + total > end:
                break
            count[0] += 1
            c = Chunk(cid, off, head, total, depth)
            if head < total and depth < 32:
                c.children = walk(off + head, off + total, depth + 1)
            out.append(c)
            off += total
        return out

    end = min(struct.unpack_from("<I", data, 8)[0], len(data))
    return walk(12, end, 0)


def name_key(text: str, start: int = 0) -> int:
    """The game's 32-bit key for a name: what it finds objects by once a file is loaded (clean-room spec
    docs/cleanroom/SPEC-006, section 5; the Xbox's function is at 0x00243FA0). No text gives start back.
    Otherwise h is start without its top bit, and for each character, taken as a signed byte:
    h = (h * 65599) & 0x7FFFFFFF, the character + 0x20 if it is below 'a', h ^= the character; the top bit
    is set at the end. The folding is blind: it turns A-Z into a-z, and shifts digits, '.' and '_' too, so
    names that differ only in letter case have the same key. The .p3d files themselves keep names as
    text; the keys are in the compiled scripts (a name written stx........) and the AI trees (.dtr)."""
    if not text:
        return start & 0xFFFFFFFF
    h = start & 0x7FFFFFFF
    for c in text.encode("latin-1", "replace"):
        h = (h * 65599) & 0x7FFFFFFF
        if c >= 0x80:
            c -= 0x100                                       # a signed byte
        if c < 0x61:
            c += 0x20
        h = (h ^ c) & 0xFFFFFFFF
    return h | 0x80000000


def walk(chunks: List[Chunk]) -> Iterator[Chunk]:
    for c in chunks:
        yield c
        yield from walk(c.children)


# --------------------------------------------------------------------------- fields

class _R:
    """Reads a chunk's fields in order."""

    def __init__(self, data: bytes, start: int, end: int):
        self.d, self.p, self.end = data, start, end

    def u32(self) -> int:
        v = struct.unpack_from("<I", self.d, self.p)[0]
        self.p += 4
        return v

    def f32(self) -> float:
        v = struct.unpack_from("<f", self.d, self.p)[0]
        self.p += 4
        return v

    def floats(self, n: int) -> Tuple[float, ...]:
        v = struct.unpack_from(f"<{n}f", self.d, self.p)
        self.p += 4 * n
        return v

    def fourcc(self) -> str:
        v = self.d[self.p:self.p + 4].rstrip(b"\0 ").decode("latin-1")
        self.p += 4
        return v

    def text(self) -> str:
        n = self.d[self.p]
        v = self.d[self.p + 1:self.p + 1 + n].split(b"\0")[0].decode("latin-1")
        self.p += 1 + n
        return v

    def left(self) -> int:
        return self.end - self.p


def _vertex_type(v: int) -> str:
    parts = [name for bit, name in VERTEX_BITS if v & bit]
    if v & 0xF:
        parts.append(f"{v & 0xF} UV set{'s' if v & 0xF > 1 else ''}")
    return ", ".join(parts)


def _counted(r: _R) -> dict:
    return {"count": r.u32()}


def _mesh(r: _R) -> dict:
    return {"name": r.text(), "version": r.u32(), "primitive groups": r.u32()}


def _skin(r: _R) -> dict:
    return {"name": r.text(), "version": r.u32(), "skeleton": r.text(), "primitive groups": r.u32()}


def _prim_group(r: _R) -> dict:
    out = {"version": r.u32(), "shader": r.text()}
    prim, vtype = r.u32(), r.u32()
    out.update({"primitive": PRIMITIVES.get(prim, prim), "vertex type": f"{vtype:#x} ({_vertex_type(vtype)})",
                "vertices": r.u32(), "indices": r.u32(), "matrices": r.u32()})
    if r.left() >= 4:
        out["memory image"] = r.u32()
    return out


def _uv_list(r: _R) -> dict:
    return {"count": r.u32(), "channel": r.u32()}


def _box(r: _R) -> dict:
    return {"min": tuple(round(x, 4) for x in r.floats(3)), "max": tuple(round(x, 4) for x in r.floats(3))}


def _sphere(r: _R) -> dict:
    c = r.floats(3)
    return {"centre": tuple(round(x, 4) for x in c), "radius": round(r.f32(), 4)}


def _memory_image(r: _R) -> dict:
    return {"header": f"{r.u32():#x} {r.u32():#x}", "bytes": r.u32()}


def _skeleton(r: _R) -> dict:
    return {"name": r.text(), "version": r.u32(), "joints": r.u32()}


def _joint(r: _R) -> dict:
    name, parent = r.text(), r.u32()
    m = r.floats(16)
    return {"name": name, "parent": parent, "position": tuple(round(x, 4) for x in m[12:15])}


def _shader(r: _R) -> dict:
    return {"name": r.text(), "version": r.u32(), "pddi shader": r.text(), "translucent": r.u32(),
            "vertex needs": hex(r.u32()), "vertex mask": hex(r.u32()), "parameters": r.u32()}


def _shader_tex(r: _R) -> dict:
    return {"parameter": r.fourcc(), "texture": r.text()}


def _shader_int(r: _R) -> dict:
    return {"parameter": r.fourcc(), "value": r.u32()}


def _shader_float(r: _R) -> dict:
    return {"parameter": r.fourcc(), "value": round(r.f32(), 4)}


def _shader_colour(r: _R) -> dict:
    return {"parameter": r.fourcc(), "argb": f"{r.u32():08x}"}


def _texture(r: _R) -> dict:
    return {"name": r.text(), "version": r.u32(), "width": r.u32(), "height": r.u32(), "bpp": r.u32()}


def _image(r: _R) -> dict:
    return {"name": r.text(), "version": r.u32(), "width": r.u32(), "height": r.u32(), "bpp": r.u32(),
            "palettized": r.u32(), "alpha": r.u32(), "format": r.u32()}


def _animation(r: _R) -> dict:
    return {"version": r.u32(), "name": r.text(), "type": r.fourcc(), "frames": r.f32(), "frame rate": r.f32(),
            "cyclic": r.u32()}


def _anim_count(r: _R) -> dict:
    return {"version": r.u32(), "count": r.u32()}


def _channel_count(r: _R) -> dict:
    ver, cid, n = r.u32(), r.u32(), r.u32()
    keys = struct.unpack_from(f"<{n}H", r.d, r.p) if r.left() >= 2 * n else ()
    return {"version": ver, "channel": NAMES.get(cid, hex(cid)), "channels": n, "keys": list(keys)}


def _group(r: _R) -> dict:
    return {"version": r.u32(), "name": r.text(), "group id": r.u32(), "channels": r.u32()}


def _channel(r: _R) -> dict:
    return {"version": r.u32(), "parameter": r.fourcc(), "keys": r.u32()}


def _dof_channel(r: _R) -> dict:
    """Vector1DOF and Vector2DOF: only one or two of x, y, z move; the rest stay at the constants."""
    ver, param = r.u32(), r.fourcc()
    mapping = struct.unpack_from("<H", r.d, r.p)[0]
    r.p += 2
    const = r.floats(3)
    return {"version": ver, "parameter": param, "mapping": mapping, "constants": tuple(round(x, 4) for x in const),
            "keys": r.u32()}


def _bool_channel(r: _R) -> dict:
    """A Boolean channel (0x121108; clean-room spec SPEC-005, section 1.2): u32 version, the parameter, a u16
    starting state (1 on), u32 keys, the keys' frames, and no values: every key flips the state."""
    ver, param = r.u32(), r.fourcc()
    start = struct.unpack_from("<H", r.d, r.p)[0]
    r.p += 2
    return {"version": ver, "parameter": param, "starts on": start == 1, "keys": r.u32()}


def _frame_controller(r: _R) -> dict:
    """A Frame Controller (0x121201): u32 version, its name, 4 characters type (CAM, PTRN, LITE ...), the word
    ANIM, a float (the frame its animation starts at: SPEC-005, section 1.4; 0 in every PC file), a u32 (1),
    then the name of what it drives and the animation it plays."""
    ver, name, kind, word = r.u32(), r.text(), r.fourcc(), r.fourcc()
    offset, number = r.f32(), r.u32()
    return {"version": ver, "name": name, "type": kind, "word": word, "frame offset": round(offset, 4),
            "number": number, "drives": r.text(), "animation": r.text()}


def _interp(r: _R) -> dict:
    return {"version": r.u32(), "interpolate": r.u32() != 0}


def _history(r: _R) -> dict:
    n = struct.unpack_from("<H", r.d, r.p)[0]
    r.p += 2
    lines = []
    for _ in range(n):
        if r.left() < 1:
            break
        lines.append(r.text())
    return {"lines": lines}


def _one_u32(r: _R) -> dict:
    return {"value": r.u32()}


def _composite(r: _R) -> dict:
    return {"version": r.u32(), "name": r.text(), "skeleton": r.text(), "parts": r.u32()}


def _composite_part(r: _R) -> dict:
    r.u32()
    r.u32()
    name = r.text()
    kind = r.u32()
    return {"drawable": name, "kind": {1: "model", 0x20: "shadow mesh", 0x40: "shadow skin"}.get(kind, kind),
            "joint": r.u32()}


def _two_names(r: _R) -> dict:
    return {"name": r.text(), "drawable": r.text()}


def _world_geo(r: _R) -> dict:
    """name, the composite drawable's name, u32 kind (SPEC-003, section 4: 0, or 1 shadowed_, 3 low_LOD_,
    5 underwater_, 6 cbvlitdecals_, 7 interiorfloors_, 8 cardsnight_, after how the names start)."""
    return {"name": r.text(), "composite drawable": r.text(), "kind": r.u32()}


def _zone(r: _R) -> dict:
    name, n = r.text(), r.u32()
    return {"name": name, "world geometry": [r.text() for _ in range(n) if r.left() > 0]}


def _name_only(r: _R) -> dict:
    return {"name": r.text()}


def _script_object(r: _R) -> dict:
    return {"file": r.text(), "name": r.text(), "class": r.text()}


def _game_group(r: _R) -> dict:
    return {"file": r.text(), "name": r.text(), "class": r.text(), "count": r.u32()}


def _object_property(r: _R) -> dict:
    name, kind = r.text(), r.u32()
    if kind == 0:
        return {"name": name, "value": r.text()}
    return {"name": name, "type": kind}


def start_state(number: int):
    """The name of the state a placed copy starts in, from the last of its instanceposition's twelve numbers
    (START_STATES): None for 0 (the prop's own first state), the number itself when it isn't on the list."""
    if not number:
        return None
    return START_STATES[number - 1] if 1 <= number <= len(START_STATES) else number


def _property_value(r: _R) -> dict:
    """An instance object's "instanceposition": twelve 32-bit values (see p3d_gltf.instance_trs). The last names
    the state the copy starts in ("state", see start_state), left out when it is the prop's first."""
    if r.left() < 48:
        return {"bytes": r.left()}
    x, y, z = r.floats(3)
    v = [r.u32() for _ in range(9)]
    out = {"position": (round(x, 3), round(y / 100, 2), round(z, 3)), "angles": tuple(v[0:3]),
           "scale": round((v[3] | v[4] << 6 | v[5] << 12) / 1000, 3) if v[6] else tuple(round(a * 0.05, 2) for a in v[3:6])}
    state = start_state(v[8])
    if state is not None:
        out["state"] = state
    return out


# Lights, the draw-order key, the sky and the stream graph: docs/FORMATS.md, from the clean-room spec
# docs/cleanroom/SPEC-001-lights-sky-streaming.md.

def _vec3(r: _R) -> Tuple[float, float, float]:
    return tuple(round(x, 4) for x in r.floats(3))  # type: ignore[return-value]


def _texts(r: _R, n: int) -> List[str]:
    return [r.text() for _ in range(n) if r.left() > 0]


def _light(r: _R) -> dict:
    """name, version, type (0 ambient, 1 point, 2 directional, 3 spot), colour 0xAARRGGBB, the constant,
    linear and quadratic attenuation, enabled."""
    name, version, kind, argb = r.text(), r.u32(), r.u32(), r.u32()
    return {"name": name, "version": version, "type": LIGHT_TYPES.get(kind, kind), "argb": f"{argb:08x}",
            "attenuation": _vec3(r), "enabled": r.u32() != 0}


def _light_direction(r: _R) -> dict:
    return {"direction": _vec3(r)}                           # a unit vector: the way the light shines


def _light_position(r: _R) -> dict:
    return {"position": _vec3(r)}                            # the same space as the map's geometry


def _spot_cone(r: _R) -> dict:
    """Two angles, a falloff and a range (which angle is the inner one, and in what unit, isn't known)."""
    a, b, falloff, reach = r.floats(4)
    return {"angles": (round(a, 4), round(b, 4)), "falloff": round(falloff, 4), "range": round(reach, 4)}


def _casts_shadows(r: _R) -> dict:
    return {"casts shadows": r.u32() != 0}


def _decay_range(r: _R) -> dict:
    """u32 shape (0 none, 1 sphere, 2 box, 3 ellipsoid), the inner size, the outer size (3 floats each)."""
    shape = r.u32()
    return {"shape": DECAY_SHAPES.get(shape, shape), "inner": _vec3(r), "outer": _vec3(r)}


def _decay_rotation(r: _R) -> dict:
    return {"rotation": round(r.f32(), 4)}                   # about the vertical axis, radians


def _illumination(r: _R) -> dict:
    v = r.u32()
    return {"illumination": ILLUMINATION.get(v, v)}


def _light_group(r: _R) -> dict:
    name, n = r.text(), r.u32()
    return {"name": name, "lights": _texts(r, n)}


def _light_group_record(r: _R) -> dict:
    """The game's light group (SFLightGroupLoader): name, the light group's name, the kind (what the group
    is for), then the names of its frame controllers."""
    name, group, kind, n = r.text(), r.text(), r.u32(), r.u32()
    return {"name": name, "light group": group, "kind": kind, "frame controllers": _texts(r, n)}


def _draw_order(r: _R) -> dict:
    return {"version": r.u32(), "draw order": round(r.f32(), 4)}


def _sky(r: _R) -> dict:
    return {"name": r.text(), "composite drawable": r.text()}


def _colour_sets(r: _R) -> dict:
    """A mesh's vertex-colour sets: u32 version, u32 count n, n u32 (0, 1, 2 ...), n u32 (meaning not known);
    the sets follow as sub-chunks."""
    version, n = r.u32(), r.u32()
    numbers = [r.u32() for _ in range(n)]
    return {"version": version, "sets": n, "numbers": numbers, "unknown": [r.u32() for _ in range(n)]}


def _colour_set(r: _R) -> dict:
    return {"version": r.u32(), "frame": r.u32(), "unknown": r.u32()}


def _colour_amounts(r: _R) -> dict:
    return {"version": r.u32(), "parameter": r.fourcc(), "count": r.u32()}


def _stream_package(r: _R) -> dict:
    return {"name": r.text(), "number": r.u32()}             # what the number means isn't known


def _stream_trigger(r: _R) -> dict:
    """name, subzone, height, the outline's points (x, y, z), the packages and the slot each goes in, then
    two region names and a number (what those three mean isn't known)."""
    name, subzone, height, n = r.text(), r.text(), round(r.f32(), 4), r.u32()
    points = [_vec3(r) for _ in range(n)]
    packages = _texts(r, r.u32())
    slots = _texts(r, r.u32())
    out = {"name": name, "subzone": subzone, "height": height, "points": points, "packages": packages,
           "slots": slots}
    if r.left() > 0:
        out["regions"] = _texts(r, 2)
        out["flag"] = r.u32()
    return out


# The shadow records: docs/FORMATS.md, from the clean-room spec docs/cleanroom/SPEC-002-materials-ocean-shadows.md.

def _shadow(r: _R) -> dict:
    """A Shadow record (ShadowLoader, 0x8800008): name, the composite drawable's name (its parts are shadow
    meshes), u32 1 for a building's shadow, then a u32 and two floats whose meanings aren't known (0, 0.0, and
    200.0 for the buildings or 15.0 for NPC_shadow in every Miami file)."""
    name, drawable, building = r.text(), r.text(), r.u32()
    number = r.u32()
    return {"name": name, "composite drawable": drawable, "building": building != 0, "number": number,
            "values": (round(r.f32(), 4), round(r.f32(), 4))}


# State props, zone packages, occluders, characters and vehicles: docs/FORMATS.md, from the clean-room spec
# docs/cleanroom/SPEC-003-props-zones-xbox-blending.md. A field whose meaning is open is a "number" (u32) or a
# "value" (f32), as in the shadow record.

def _state_prop_data(r: _R) -> dict:
    """State Prop Data (0x0802000D): u32 version (4), name, the composite drawable's name, u32 number of states,
    u32 number of properties (the game reads it from version 3 on). The properties (0x08020008) follow, then the
    states (0x0802000E)."""
    version, name, drawable, states = r.u32(), r.text(), r.text(), r.u32()
    out = {"version": version, "name": name, "composite drawable": drawable, "states": states}
    if version >= 3 and r.left() >= 4:
        out["properties"] = r.u32()
    return out


def _prop_state(r: _R) -> dict:
    """A Prop State (0x0802000E): its name, then ten 4-byte values: u32 whether it moves on by itself, u32 the
    state it moves on to (its place in the prop's list of states, from 0), u32 the number of Part Visibility
    (0x08020002), Prop State Animation (0x08020003), 0x08020004 and 0x08020005 sub-chunks, f32 a frame (a state
    that moves on does so when its animation reaches it), u32 (0 in every file), u32 the number of Prop Property
    (0x08020008) and Prop State Effect (0x0802000B) sub-chunks."""
    name = r.text()
    moves, after, shown, anims, n4, n5 = r.u32(), r.u32(), r.u32(), r.u32(), r.u32(), r.u32()
    return {"name": name, "moves on": moves != 0, "next state": after, "part visibilities": shown, "animations": anims,
            "0x08020004 sub-chunks": n4, "0x08020005 sub-chunks": n5, "frame": round(r.f32(), 4), "number": r.u32(),
            "properties": r.u32(), "effects": r.u32()}


def _part_visibility(r: _R) -> dict:
    return {"part": r.text(), "shown": r.u32() != 0}


def _prop_animation(r: _R) -> dict:
    """A Prop State Animation (0x08020003): the name of a Frame Controller (0x00121201) in the same file, three u32
    whose meanings aren't settled (the first and the third 0 or 1, the second 0, 1 or 2), then two frames (the
    first may be the larger) and a speed."""
    name = r.text()
    numbers = (r.u32(), r.u32(), r.u32())
    first, last, speed = r.floats(3)
    return {"frame controller": name, "numbers": numbers, "frames": (round(first, 4), round(last, 4)),
            "speed": round(speed, 4)}


def _prop_property(r: _R) -> dict:
    return {"name": r.text(), "value": r.text()}


def _prop_effect(r: _R) -> dict:
    """A Prop State Effect (0x0802000B), an effect the state sets off: a text (Effect in every file), the effect's
    name, u32 (0), a joint of the prop's skeleton, an offset from it (3 floats), angles in radians (3 floats), u32
    (0), the joint again, a size, and a float whose meaning isn't known."""
    return {"kind": r.text(), "effect": r.text(), "number": r.u32(), "joint": r.text(), "offset": _vec3(r),
            "angles": _vec3(r), "number 2": r.u32(), "joint 2": r.text(), "size": round(r.f32(), 4),
            "value": round(r.f32(), 4)}


def _zone_entry(r: _R) -> dict:
    """A Zone Package Entry (0x08800009, one per World Geometry its zone package lists): the World Geometry's name,
    u32 number of floats (6), then near, far and fade (the world geometry is drawn while the camera is farther
    than near and nearer than far), a float (0 in every file), the x of the point the distance is measured from
    and that point's z with its sign flipped. "point" is (x, z) with the sign put back; (0, 0) means none."""
    name, n = r.text(), r.u32()
    v = [round(x, 4) for x in r.floats(max(0, min(n, r.left() // 4)))]
    out: dict = {"name": name, "floats": n}
    out.update(zip(("near", "far", "fade", "value"), v))
    if len(v) >= 6:
        out["point"] = (v[4], 0.0 - v[5])
    if len(v) > 6:
        out["more"] = v[6:]
    return out


def _occluder(r: _R) -> dict:
    """An Occluder (0x0880000A): a position, the way it faces (a unit vector), u32 (0 in all but one), f32 (0), and
    three sizes (which axis each runs along isn't settled)."""
    return {"position": _vec3(r), "facing": _vec3(r), "number": r.u32(), "value": round(r.f32(), 4), "sizes": _vec3(r)}


def _model_record(r: _R) -> dict:
    """A Character (0x08800000) or Vehicle (0x08800001): eleven texts. The name, the model (a skin for a character,
    a composite drawable for a vehicle), its low-detail model (may be empty), then eight shader names, the unused
    ones empty."""
    return {"name": r.text(), "model": r.text(), "low-detail model": r.text(), "shaders": _texts(r, 8)}


def light(data: bytes, c: Chunk) -> dict:
    """A Light chunk (0x13000) with what its sub-chunks say, as one dictionary: the Light's own fields,
    then "direction", "position", "spot cone", "casts shadows", "decay range" (shape, inner, outer, and the
    "rotation" of a sub-chunk 0x13007 under it) and "illumination", for the sub-chunks it has."""
    out = fields(data, c)
    if not out:
        return {}
    for k in c.children:
        f = fields(data, k)
        if not f:
            continue
        if k.id == 0x13003:
            out["spot cone"] = f
        elif k.id == 0x13006:
            rot = k.find(0x13007)
            if rot:
                f.update(fields(data, rot))
            out["decay range"] = f
        elif k.id in (0x13001, 0x13002, 0x13004, 0x13008):
            out.update(f)
    return out


def vertex_colour_sets(data: bytes, mesh: Chunk) -> List[Dict[int, Tuple[int, int, int]]]:
    """A mesh's vertex-colour sets (0x121305 right under it), in order: for each set (0x121306), what its
    0x10F02 adds to each vertex, {vertex number: (r, g, b)}. The sky's meshes have them; the animation
    VRTX_<mesh name> picks the set shown at each hour. [] for a mesh without them."""
    sets = mesh.find(COLOUR_SETS)
    out: List[Dict[int, Tuple[int, int, int]]] = []
    for s in (sets.children if sets else []):
        if s.id != COLOUR_SET:
            continue
        amounts: Dict[int, Tuple[int, int, int]] = {}
        k = s.find(COLOUR_AMOUNTS)
        info = fields(data, k) if k is not None else {}
        if info.get("parameter") == "CLR0":
            start, end = k.body
            p = start + 12
            for _ in range(info["count"]):
                if p + 12 > end:
                    break
                v, red, green, blue, _zero = struct.unpack_from("<I4H", data, p)
                amounts[v] = (red, green, blue)
                p += 12
        out.append(amounts)
    return out


FIELDS: Dict[int, Callable[[_R], dict]] = {
    0x7000: _history,
    0x10000: _mesh, 0x10001: _skin, 0x10020: _prim_group, 0x10003: _box, 0x10004: _sphere,
    0x10005: _counted, 0x10006: _counted, 0x10007: _uv_list, 0x10008: _counted, 0x1000A: _counted,
    0x1000B: _counted, 0x1000C: _counted, 0x1000D: _counted, 0x10010: _counted, 0x10017: _one_u32,
    0x10012: _memory_image, 0x10013: _memory_image,
    0x11000: _shader, 0x11002: _shader_tex, 0x11003: _shader_int, 0x11004: _shader_float, 0x11005: _shader_colour,
    0x19000: _texture, 0x19001: _image,
    0x23000: _skeleton, 0x23001: _joint,
    0x121000: _animation, 0x121002: _anim_count, 0x121006: _anim_count, 0x121007: _channel_count,
    0x121001: _group, 0x121110: _interp, 0x121108: _bool_channel, 0x121201: _frame_controller,
    0x123000: _composite, 0x123001: _composite_part, 0x8800003: _world_geo, 0x8800004: _zone,
    0x8800005: _two_names, 0x8800112: _name_only, 0x9900190: _script_object, 0x9900191: _game_group,
    0x9900192: _object_property, 0x9900194: _property_value,
    0x13000: _light, 0x13001: _light_direction, 0x13002: _light_position, 0x13003: _spot_cone,
    0x13004: _casts_shadows, 0x13006: _decay_range, 0x13007: _decay_rotation, 0x13008: _illumination,
    0x2380: _light_group, 0x8800007: _light_group_record, 0x122000: _draw_order, 0x8800002: _sky,
    0x8800100: _stream_package, 0x8800101: _stream_trigger, 0x8800008: _shadow,
    COLOUR_SETS: _colour_sets, COLOUR_SET: _colour_set, COLOUR_AMOUNTS: _colour_amounts,
    0x802000D: _state_prop_data, 0x802000E: _prop_state, 0x8020002: _part_visibility, 0x8020003: _prop_animation,
    0x8020008: _prop_property, 0x802000B: _prop_effect, 0x8800009: _zone_entry, 0x880000A: _occluder,
    0x8800000: _model_record, 0x8800001: _model_record,
}
for _cid in (0x121100, 0x121101, 0x121104, 0x121107, COLOUR_CHANNEL, INTEGER_CHANNEL) + QUATERNION_CHANNELS:
    FIELDS[_cid] = _channel
FIELDS[0x121102] = FIELDS[0x121103] = _dof_channel


def fields(data: bytes, c: Chunk) -> dict:
    """The fields of a chunk whose layout is known; {} for the rest (or a chunk too short for its layout)."""
    fn = FIELDS.get(c.id)
    if not fn:
        return {}
    try:
        return fn(_R(data, *c.body))
    except (struct.error, IndexError):
        return {}


# --------------------------------------------------------------------------- animation values

def channel_keys(data: bytes, c: Chunk) -> Tuple[str, List[int], List[tuple]]:
    """(parameter, key frames, values) of an animation channel. Quaternions come back as (x, y, z, w),
    a Colour channel's 0xAARRGGBB values as (a, r, g, b) from 0 to 255, an Integer channel's as (n,); a
    Vector1DOF or Vector2DOF channel gives only its moving components (see its mapping and constants).
    A Boolean channel has no values in the file: each key flips the state, so the value given for a key is
    (the state from that key on,), and its fields say what it is before the first ("starts on"). An Entity
    channel's values are names, (name,) per key: the texture a surface shows from that frame on."""
    r = _R(data, *c.body)
    if c.id in (0x121102, 0x121103):
        info = _dof_channel(r)
        param, n = info["parameter"], info["keys"]
    elif c.id == BOOLEAN_CHANNEL:
        info = _bool_channel(r)
        n = info["keys"]
        frames = list(struct.unpack_from(f"<{n}H", data, r.p))
        state, states = info["starts on"], []
        for _ in frames:
            state = not state
            states.append((state,))
        return info["parameter"], frames, states
    else:
        r.u32()                                              # version
        param, n = r.fourcc(), r.u32()
    frames = list(struct.unpack_from(f"<{n}H", data, r.p))
    r.p += 2 * n
    if c.id == 0x121105:                                     # four floats
        vals = [r.floats(4) for _ in range(n)]
    elif c.id in (0x121112, 0x121114):                       # x, y, z as int16 or int8; w >= 0 from them
        fmt, scale = ("<3h", 32767.0) if c.id == 0x121112 else ("<3b", 127.0)
        step = struct.calcsize(fmt)
        vals = []
        for i in range(n):
            x, y, z = (v / scale for v in struct.unpack_from(fmt, data, r.p + i * step))
            vals.append((x, y, z, math.sqrt(max(0.0, 1.0 - x * x - y * y - z * z))))
    elif c.id in (0x121100, 0x121101, 0x121102, 0x121103, 0x121104):
        size = {0x121100: 1, 0x121101: 2, 0x121102: 1, 0x121103: 2, 0x121104: 3}[c.id]
        vals = [r.floats(size) for _ in range(n)]
    elif c.id == COLOUR_CHANNEL:                             # the frames, then a u32 0xAARRGGBB per key
        vals = [tuple((v >> s) & 0xFF for s in (24, 16, 8, 0)) for v in struct.unpack_from(f"<{n}I", data, r.p)]
    elif c.id == INTEGER_CHANNEL:                            # the frames, then a u32 per key, no padding between
        vals = [(v,) for v in struct.unpack_from(f"<{n}I", data, r.p)]
    elif c.id == ENTITY_CHANNEL:                             # the frames, then a name per key
        vals = [(r.text(),) for _ in range(n)]
    else:
        raise P3dError(f"no reader for {NAMES.get(c.id, hex(c.id))}")
    return param, frames, vals


# --------------------------------------------------------------------------- geometry

def _triangles(indices: List[int], prim: int) -> List[Tuple[int, int, int]]:
    if prim == 0:
        return [tuple(indices[i:i + 3]) for i in range(0, len(indices) - 2, 3)]  # type: ignore[misc]
    if prim != 1:
        return []
    out = []
    for i in range(len(indices) - 2):
        a, b, c = indices[i:i + 3]
        if a == b or b == c or a == c:
            continue
        out.append((a, b, c) if i % 2 == 0 else (b, a, c))
    return out


def _gltf():
    import p3d_gltf                      # reads the Xbox's and the PS2's vertex data too; it imports this module
    return p3d_gltf


def to_obj(data: bytes) -> str:
    """Every mesh and skin in the file as Wavefront .obj text (positions and faces), one object each, from
    the PC's lists, the Xbox's vertex buffers or the PS2's vertex packets."""
    lines = ["# from a Pure3D file by portal/tools/p3d.py"]
    base = 1
    for c in walk(read_tree(data)):
        if c.id not in (0x10000, 0x10001):
            continue
        name = fields(data, c).get("name", "mesh")
        lines.append(f"o {name}")
        for pg in (k for k in c.children if k.id == 0x10020):
            try:
                g = _gltf().geometry(data, pg)
            except (struct.error, IndexError, ValueError):
                g = None
            if not g:
                lines.append(f"# {fields(data, pg).get('shader', '')}: in a form not read, left out")
                continue
            positions, tris = g.positions, g.triangles
            lines.append(f"g {name}_{fields(data, pg).get('shader', '')}")
            lines += [f"v {x:.6f} {y:.6f} {z:.6f}" for x, y, z in positions]
            lines += [f"f {a + base} {b + base} {cc + base}" for a, b, cc in tris]
            base += len(positions)
    return "\n".join(lines) + "\n"


# --------------------------------------------------------------------------- printing

def _show(v) -> str:
    if isinstance(v, list) and len(v) > 12:
        return "[" + ", ".join(map(str, v[:12])) + f", ... {len(v)} in all]"
    return str(v)


def dump(data: bytes, depth: int = 99) -> str:
    lines = []
    for c in walk(read_tree(data)):
        if c.depth >= depth:
            continue
        info = fields(data, c)
        label = c.name or "?"
        extra = "  ".join(f"{k}={_show(v)}" for k, v in info.items())
        lines.append(f"{'  ' * c.depth}{c.id:#010x} {label} ({c.total:,} bytes)" + (f"  {extra}" if extra else ""))
    return "\n".join(lines)


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description="Show what is inside a Pure3D (.p3d) file.")
    ap.add_argument("file", type=Path)
    ap.add_argument("--depth", type=int, default=99, help="how many levels of the tree to show")
    ap.add_argument("--obj", type=Path, help="write the meshes and skins to this .obj file")
    a = ap.parse_args(argv)
    try:
        data = a.file.read_bytes()
        read_tree(data)
    except (OSError, P3dError) as e:
        print(f"{a.file}: {e}", file=sys.stderr)
        return 1
    if a.obj:
        a.obj.write_text(to_obj(data), encoding="utf-8")
        print(f"wrote {a.obj}")
    else:
        print(dump(data, a.depth))
    return 0


if __name__ == "__main__":
    sys.exit(main())
