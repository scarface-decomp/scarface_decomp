#!/usr/bin/env python3
"""
Read Pure3D (.p3d) files: the chunk tree with every chunk named, the fields of the chunks for models,
skins, skeletons, shaders, textures and animations, and the models as .obj files you can open in Blender.

    python portal/tools/p3d.py FILE.p3d                 the chunk tree, with each known chunk's fields
    python portal/tools/p3d.py FILE.p3d --depth 2       only the first two levels
    python portal/tools/p3d.py FILE.p3d --obj OUT.obj   the meshes and skins as a Wavefront .obj
                                                        (PC and Xbox files; the PS2's are packed for its
                                                        vector unit, see docs/FORMATS.md)

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
    0x10014: "Memory Image Vertex Description", 0x10017: "Render Status", 0x10019: "Shadow Skin (?)",
    0x1001B: "Topology (?)", 0x10020: "Primitive Group", 0x10021: "Vertex Precision (?)",
    0x11000: "Shader", 0x11002: "Shader Texture Parameter", 0x11003: "Shader Integer Parameter",
    0x11004: "Shader Float Parameter", 0x11005: "Shader Colour Parameter",
    0x14000: "Old Locator",
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
}

PRIMITIVES = {0: "triangle list", 1: "triangle strip", 2: "line list", 3: "line strip", 4: "points"}
VERTEX_BITS = ((0x2000, "position"), (0x0010, "normal"), (0x0020, "colour"), (0x0080, "matrix indices"),
               (0x0100, "weights"))
QUATERNION_CHANNELS = (0x121105, 0x121111, 0x121112, 0x121114)


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
    0x121001: _group, 0x121110: _interp,
}
for _cid in (0x121100, 0x121101, 0x121104) + QUATERNION_CHANNELS:
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
    """(parameter, key frames, values) of an animation channel. Quaternions come back as (x, y, z, w);
    a Vector1DOF or Vector2DOF channel gives only its moving components (see its mapping and constants)."""
    r = _R(data, *c.body)
    if c.id in (0x121102, 0x121103):
        info = _dof_channel(r)
        param, n = info["parameter"], info["keys"]
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


def primitive_geometry(data: bytes, pg: Chunk) -> Optional[Tuple[List[tuple], List[Tuple[int, int, int]]]]:
    """(positions, triangles) of a primitive group stored as plain lists (PC, some Xbox) or as an Xbox
    memory image (a vertex buffer that starts each vertex with its position, and 16-bit indices).
    None for the PS2's vector-unit packets."""
    info = fields(data, pg)
    n, prim = info.get("vertices", 0), next((k for k, v in PRIMITIVES.items() if v == info.get("primitive")), -1)
    pos_c, idx_c = pg.find(0x10005), pg.find(0x1000A)
    if pos_c and idx_c:
        s, _ = pos_c.body
        count = struct.unpack_from("<I", data, s)[0]
        flat = struct.unpack_from(f"<{3 * count}f", data, s + 4)
        positions = [flat[i:i + 3] for i in range(0, len(flat), 3)]
        s, _ = idx_c.body
        k = struct.unpack_from("<I", data, s)[0]
        indices = list(struct.unpack_from(f"<{k}I", data, s + 4))
        return positions, _triangles(indices, prim)
    vb, ib = pg.find(0x10012), pg.find(0x10013)
    if vb and ib and n:
        s, _ = vb.body
        size = struct.unpack_from("<I", data, s + 8)[0]
        if size % n:
            return None
        stride = size // n
        positions = [struct.unpack_from("<3f", data, s + 12 + i * stride) for i in range(n)]
        s, _ = ib.body
        size = struct.unpack_from("<I", data, s + 8)[0]
        indices = list(struct.unpack_from(f"<{size // 2}H", data, s + 12))
        return positions, _triangles(indices, prim)
    return None


def to_obj(data: bytes) -> str:
    """Every mesh and skin in the file as Wavefront .obj text (positions and faces), one object each."""
    lines = ["# from a Pure3D file by portal/tools/p3d.py"]
    base = 1
    for c in walk(read_tree(data)):
        if c.id not in (0x10000, 0x10001):
            continue
        name = fields(data, c).get("name", "mesh")
        lines.append(f"o {name}")
        for pg in (k for k in c.children if k.id == 0x10020):
            geo = primitive_geometry(data, pg)
            if not geo:
                lines.append(f"# {fields(data, pg).get('shader', '')}: stored for the PS2's vector unit, left out")
                continue
            positions, tris = geo
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
