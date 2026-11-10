"""Pure3D reading (portal/tools/p3d.py): the chunk tree, the fields of models, skins, skeletons and animations,
the compressed rotations, and .obj export. Every file here is made up; nothing comes from the game."""
import math
import struct

import pytest

import p3d as P


# --------------------------------------------------------------------------- helpers

def chunk(cid: int, head: bytes, kids: bytes = b"") -> bytes:
    return struct.pack("<III", cid, 12 + len(head), 12 + len(head) + len(kids)) + head + kids


def text(s: str) -> bytes:
    raw = s.encode() + b"\0"
    raw += b"\0" * (-(len(raw) + 1) % 4)                 # Pure3D pads text to keep 4-byte alignment
    return bytes([len(raw)]) + raw


def p3d(*chunks: bytes) -> bytes:
    body = b"".join(chunks)
    return b"P3D\xff" + struct.pack("<II", 12, 12 + len(body)) + body


def prim_group(shader: str, prim: int, vtype: int, positions, indices, memory_image=0, kids=b"") -> bytes:
    head = struct.pack("<I", 0) + text(shader) + struct.pack(
        "<9I", prim, vtype, len(positions), len(indices), 0, memory_image, 1, 0, 0)
    if not memory_image:
        flat = [x for p in positions for x in p]
        kids = (chunk(0x10005, struct.pack(f"<I{len(flat)}f", len(positions), *flat))
                + chunk(0x1000A, struct.pack(f"<I{len(indices)}I", len(indices), *indices)) + kids)
    return chunk(0x10020, head, kids)


QUAD = [(0.0, 0.0, 0.0), (1.0, 0.0, 0.0), (0.0, 1.0, 0.0), (1.0, 1.0, 0.0)]


# --------------------------------------------------------------------------- tree and fields

def test_tree_names_and_mesh_fields():
    data = p3d(chunk(0x10000, text("box") + struct.pack("<II", 0, 1),
                     prim_group("wood", 1, 0x2011, QUAD, [0, 1, 2, 3])
                     + chunk(0x10003, struct.pack("<6f", 0, 0, 0, 1, 1, 0))))
    tree = P.read_tree(data)
    assert [c.name for c in P.walk(tree)] == ["Mesh", "Primitive Group", "Position List", "Index List",
                                              "Bounding Box"]
    mesh, pg = tree[0], tree[0].children[0]
    assert P.fields(data, mesh) == {"name": "box", "version": 0, "primitive groups": 1}
    info = P.fields(data, pg)
    assert info["shader"] == "wood" and info["primitive"] == "triangle strip"
    assert info["vertex type"] == "0x2011 (position, normal, 1 UV set)"
    assert (info["vertices"], info["indices"], info["memory image"]) == (4, 4, 0)
    assert P.fields(data, mesh.children[1]) == {"min": (0.0, 0.0, 0.0), "max": (1.0, 1.0, 0.0)}
    assert "Mesh (" in P.dump(data) and "shader=wood" in P.dump(data)


def test_damaged_chunks_are_left_out():
    good = chunk(0x10017, struct.pack("<I", 1))
    bad = struct.pack("<III", 0x10000, 12, 9999)          # says it is longer than the file
    data = p3d(good, bad)
    assert [c.id for c in P.read_tree(data)] == [0x10017]
    with pytest.raises(P.P3dError):
        P.read_tree(b"not a p3d file")


def test_skin_skeleton_and_joints():
    m = [1.0, 0, 0, 0, 0, 1.0, 0, 0, 0, 0, 1.0, 0, 0.5, 2.0, -1.0, 1.0]
    data = p3d(chunk(0x23000, text("rig") + struct.pack("<IIII", 0, 2, 0, 0),
                     chunk(0x23001, text("Root") + struct.pack("<I16f", 0, *m))
                     + chunk(0x23001, text("Hip_L") + struct.pack("<I16f", 0, *m))),
               chunk(0x10001, text("tony") + struct.pack("<I", 3) + text("rig") + struct.pack("<I", 0)))
    skel, skin = P.read_tree(data)
    assert P.fields(data, skel) == {"name": "rig", "version": 0, "joints": 2}
    assert P.fields(data, skel.children[1]) == {"name": "Hip_L", "parent": 0, "position": (0.5, 2.0, -1.0)}
    assert P.fields(data, skin) == {"name": "tony", "version": 3, "skeleton": "rig", "primitive groups": 0}


def test_history_lines():
    body = struct.pack("<H", 2) + text("p3djoin version 1") + text("made up")
    data = p3d(chunk(0x7000, body))
    assert P.fields(data, P.read_tree(data)[0]) == {"lines": ["p3djoin version 1", "made up"]}


# --------------------------------------------------------------------------- animation

def test_animation_fields_and_channel_counts():
    counts = chunk(0x121007, struct.pack("<III3H", 0, 0x121105, 3, 5, 1, 2))
    anim = chunk(0x121000, struct.pack("<I", 0) + text("walk") + b"PTRN" + struct.pack("<ffI", 68.0, 30.0, 1),
                 chunk(0x121006, struct.pack("<II", 0, 1), counts))
    data = p3d(anim)
    a = P.read_tree(data)[0]
    assert P.fields(data, a) == {"version": 0, "name": "walk", "type": "PTRN", "frames": 68.0, "frame rate": 30.0,
                                 "cyclic": 1}
    assert P.fields(data, a.children[0].children[0]) == {"version": 0, "channel": "Quaternion Channel",
                                                         "channels": 3, "keys": [5, 1, 2]}


def _channel(cid, param, frames, values: bytes, extra=b""):
    return chunk(cid, struct.pack("<I", 1) + param + extra + struct.pack(f"<I{len(frames)}H", len(frames), *frames)
                 + values, chunk(0x121110, struct.pack("<Ii", 0, -1)))


def test_rotation_channels_full_and_compressed():
    half = math.sqrt(0.5)
    full = _channel(0x121105, b"ROT\0", [0, 3], struct.pack("<8f", 0, 0, 0, 1, 0, 0, half, half))
    short = _channel(0x121112, b"ROT\0", [0, 3], struct.pack("<6h", 0, 0, 0, 0, 0, 23170))
    byte = _channel(0x121114, b"ROT\0", [0, 3], struct.pack("<6b", 0, 0, 0, 0, 0, 90) + b"\0\0")
    group = chunk(0x121001, struct.pack("<I", 0) + text("Knee_L") + struct.pack("<II", 5, 3), full + short + byte)
    data = p3d(group)
    g = P.read_tree(data)[0]
    assert P.fields(data, g) == {"version": 0, "name": "Knee_L", "group id": 5, "channels": 3}
    assert P.fields(data, g.children[0].children[0]) == {"version": 0, "interpolate": True}
    for c, tolerance in zip(g.children, (1e-6, 1e-4, 0.01)):
        param, frames, values = P.channel_keys(data, c)
        assert (param, frames) == ("ROT", [0, 3])
        assert values[0] == pytest.approx((0, 0, 0, 1), abs=tolerance)
        assert values[1] == pytest.approx((0, 0, half, half), abs=tolerance)   # w is worked out from x, y, z


def test_translation_channels():
    v3 = _channel(0x121104, b"TRAN", [0, 10], struct.pack("<6f", 1, 2, 3, 4, 5, 6))
    one = chunk(0x121102, struct.pack("<I", 0) + b"TRAN" + struct.pack("<H3f", 2, 0.5, 1.5, 0.0)
                + struct.pack("<I2H2f", 2, 0, 60, -0.25, 0.75))
    data = p3d(v3, one)
    t3, t1 = P.read_tree(data)
    assert P.channel_keys(data, t3) == ("TRAN", [0, 10], [(1, 2, 3), (4, 5, 6)])
    assert P.fields(data, t1) == {"version": 0, "parameter": "TRAN", "mapping": 2, "constants": (0.5, 1.5, 0.0),
                                  "keys": 2}
    assert P.channel_keys(data, t1) == ("TRAN", [0, 60], [(-0.25,), (0.75,)])


# --------------------------------------------------------------------------- geometry

def test_strip_and_list_triangles():
    assert P._triangles([0, 1, 2, 3], 1) == [(0, 1, 2), (2, 1, 3)]          # every other one turned round
    assert P._triangles([0, 1, 2, 2, 3, 4], 1) == [(0, 1, 2), (3, 2, 4)]        # the joins are dropped
    assert P._triangles([0, 1, 2, 2, 1, 3], 0) == [(0, 1, 2), (2, 1, 3)]
    assert P._triangles([0, 1, 2], 4) == []


def test_obj_from_plain_lists_and_an_xbox_memory_image():
    plain = chunk(0x10000, text("pc") + struct.pack("<II", 0, 1), prim_group("a", 0, 0x2011, QUAD, [0, 1, 2]))
    stride = 24                                            # position, packed normal, UV
    vb = b"".join(struct.pack("<3f", *p) + b"\0" * 12 for p in QUAD)
    ib = struct.pack("<4H", 0, 1, 2, 3)
    images = (chunk(0x10012, struct.pack("<III", 0x20001, 0, len(vb)) + vb)
              + chunk(0x10013, struct.pack("<III", 0x20001, 0, len(ib)) + ib))
    xbox = chunk(0x10000, text("xb") + struct.pack("<II", 0, 1),
                 prim_group("b", 1, 0x2011, QUAD, [0] * 4, memory_image=1, kids=images))
    ps2 = chunk(0x10000, text("ps") + struct.pack("<II", 0, 1),
                prim_group("c", 1, 0x2011, QUAD, [], memory_image=1, kids=chunk(0x10012, bytes(12))))
    obj = P.to_obj(p3d(plain, xbox, ps2))
    lines = obj.splitlines()
    assert "o pc" in lines and "o xb" in lines and "o ps" in lines
    assert lines.count("v 1.000000 1.000000 0.000000") == 2
    assert "f 1 2 3" in lines                              # the list
    assert "f 5 6 7" in lines and "f 7 6 8" in lines       # the strip, numbered after the first four vertices
    assert any("left out" in line for line in lines)       # a group it can't read is named, not drawn
    assert len(vb) == stride * len(QUAD)
