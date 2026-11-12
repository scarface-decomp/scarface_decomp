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


# --------------------------------------------------------------------------- lights, the sky, the stream graph

def light(name, kind, argb, enabled=1, kids=b""):
    """A Light chunk (0x13000): name, version 0x101, type, colour, attenuation (1, 0, 0), enabled."""
    return chunk(0x13000, text(name) + struct.pack("<III3fI", 0x101, kind, argb, 1.0, 0.0, 0.0, enabled), kids)


def decay(shape, inner, outer, rotation=None):
    kids = chunk(0x13007, struct.pack("<f", rotation)) if rotation is not None else b""
    return chunk(0x13006, struct.pack("<I6f", shape, *inner, *outer), kids)


def test_a_light_and_its_sub_chunks():
    kids = (chunk(0x13001, struct.pack("<3f", 0, -0.788, -0.616)) + chunk(0x13002, struct.pack("<3f", 10, 3, -20))
            + chunk(0x13003, struct.pack("<4f", 0.5, 0.75, 1.0, 8.0)) + chunk(0x13004, struct.pack("<I", 1))
            + decay(2, (1, 2, 3), (4, 5, 6), rotation=0.25) + chunk(0x13008, struct.pack("<I", 2)))
    data = p3d(light("MiamiSunShape", 3, 0xFF1F2D30, kids=kids))
    lt = P.read_tree(data)[0]
    assert [c.name for c in P.walk([lt])] == ["Light", "Light Direction", "Light Position", "Light Spot Cone",
                                               "Light Casts Shadows", "Light Decay Range",
                                               "Light Decay Range Rotation", "Light Illumination Kind"]
    assert P.fields(data, lt) == {"name": "MiamiSunShape", "version": 0x101, "type": "spot", "argb": "ff1f2d30",
                                  "attenuation": (1.0, 0.0, 0.0), "enabled": True}
    direction, position, cone, shadows, rng, illum = lt.children
    assert P.fields(data, direction) == {"direction": (0.0, -0.788, -0.616)}
    assert P.fields(data, position) == {"position": (10.0, 3.0, -20.0)}
    assert P.fields(data, cone) == {"angles": (0.5, 0.75), "falloff": 1.0, "range": 8.0}
    assert P.fields(data, shadows) == {"casts shadows": True}
    assert P.fields(data, rng) == {"shape": "box", "inner": (1.0, 2.0, 3.0), "outer": (4.0, 5.0, 6.0)}
    assert P.fields(data, rng.children[0]) == {"rotation": 0.25}
    assert P.fields(data, illum) == {"illumination": "takes light away"}
    whole = P.light(data, lt)                               # the light and its sub-chunks together
    assert whole["direction"] == (0.0, -0.788, -0.616) and whole["position"] == (10.0, 3.0, -20.0)
    assert whole["spot cone"]["angles"] == (0.5, 0.75) and whole["casts shadows"] is True
    assert whole["decay range"] == {"shape": "box", "inner": (1.0, 2.0, 3.0), "outer": (4.0, 5.0, 6.0),
                                    "rotation": 0.25}
    assert whole["illumination"] == "takes light away"
    assert "type=spot" in P.dump(data) and "argb=ff1f2d30" in P.dump(data)


def test_light_types_and_a_bare_light():
    for kind, name in ((0, "ambient"), (1, "point"), (2, "directional"), (3, "spot"), (9, 9)):
        data = p3d(light("l", kind, 0, enabled=0))
        info = P.light(data, P.read_tree(data)[0])
        assert info["type"] == name and info["enabled"] is False
        assert "position" not in info and "decay range" not in info


def test_light_group_and_its_record():
    group = chunk(0x2380, text("zone_lights") + struct.pack("<I", 2) + text("MiamiSunShape") + text("MiamiFillShape"))
    record = chunk(0x8800007, text("zone_lights") + text("zone_lights") + struct.pack("<II", 0, 2)
                   + text("LITE_MiamiSunShape") + text("LITE_MiamiFillShape"))
    data = p3d(group, record)
    g, r = P.read_tree(data)
    assert (g.name, r.name) == ("Light Group", "Light Group (game)")
    assert P.fields(data, g) == {"name": "zone_lights", "lights": ["MiamiSunShape", "MiamiFillShape"]}
    assert P.fields(data, r) == {"name": "zone_lights", "light group": "zone_lights", "kind": 0,
                                 "frame controllers": ["LITE_MiamiSunShape", "LITE_MiamiFillShape"]}


def test_draw_order_and_sky():
    mesh = chunk(0x10000, text("skybox17Shape") + struct.pack("<II", 0, 0), chunk(0x122000, struct.pack("<If", 0, 0.3)))
    sky = chunk(0x8800002, text("rainy_skybox") + text("rainy_skybox"))
    data = p3d(mesh, sky)
    m, s = P.read_tree(data)
    assert m.children[0].name == "Draw Order"
    assert P.fields(data, m.children[0]) == {"version": 0, "draw order": 0.3}
    assert s.name == "Sky" and P.fields(data, s) == {"name": "rainy_skybox", "composite drawable": "rainy_skybox"}


def short_text(s: str) -> bytes:
    """Text padded to 4 bytes without counting its length byte, as streamgraph.p3d's "0c loadTrigger NUL"."""
    raw = s.encode() + b"\0"
    raw += b"\0" * (-len(raw) % 4)
    return bytes([len(raw)]) + raw


def stream_trigger(name, subzone, outline, packages, height=13.0, base=12.4, regions=("a_region", "b_region"),
                   flag=0, tx=text):
    """A Stream Trigger (0x8800101): outline as (x, z), packages as (package, slot)."""
    head = tx(name) + tx(subzone) + struct.pack("<fI", height, len(outline))
    head += b"".join(struct.pack("<3f", x, base, z) for x, z in outline)
    head += struct.pack("<I", len(packages)) + b"".join(tx(p) for p, _ in packages)
    head += struct.pack("<I", len(packages)) + b"".join(tx(s) for _, s in packages)
    head += b"".join(tx(r) for r in regions) + struct.pack("<I", flag)
    return chunk(0x8800101, head)


@pytest.mark.parametrize("tx", [text, short_text])
def test_stream_package_and_trigger(tx):
    pkg = chunk(0x8800100, tx("bsand_02_shell") + struct.pack("<I", 65535))
    trig = stream_trigger("loadTrigger_100", "bsand_02_shell", [(0, 0), (10, 0), (10, 10)],
                          [("miami_lod", "Global_S"), ("bsand_02_shell", "Shell")],
                          regions=("fountainrock_region", "lobst_region"), flag=1, tx=tx)
    data = p3d(pkg, trig)
    p, t = P.read_tree(data)
    assert (p.name, t.name) == ("Stream Package", "Stream Trigger")
    assert P.fields(data, p) == {"name": "bsand_02_shell", "number": 65535}
    assert P.fields(data, t) == {
        "name": "loadTrigger_100", "subzone": "bsand_02_shell", "height": 13.0,
        "points": [(0.0, 12.4, 0.0), (10.0, 12.4, 0.0), (10.0, 12.4, 10.0)],
        "packages": ["miami_lod", "bsand_02_shell"], "slots": ["Global_S", "Shell"],
        "regions": ["fountainrock_region", "lobst_region"], "flag": 1}


def test_colour_channel_keys():
    frames = [0, 40, 120]
    argb = [0xFF1F2D30, 0xFF253134, 0xFF636148]
    ch = chunk(0x121109, struct.pack("<I", 0) + b"CLR\0" + struct.pack(f"<I{len(frames)}H{len(argb)}I", len(frames),
                                                                        *frames, *argb))
    data = p3d(ch)
    c = P.read_tree(data)[0]
    assert P.fields(data, c) == {"version": 0, "parameter": "CLR", "keys": 3}
    assert P.channel_keys(data, c) == ("CLR", [0, 40, 120], [(255, 31, 45, 48), (255, 37, 49, 52), (255, 99, 97, 72)])
