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


# --------------------------------------------------------------------------- the sky's colour sets

def colour_sets(sets, frames=None):
    """A mesh's vertex-colour sets (0x121305): sets as [{vertex: (r, g, b)}], each a 0x121306 holding a 0x10F02."""
    n = len(sets)
    kids = b""
    for i, amounts in enumerate(sets):
        rows = b"".join(struct.pack("<I4H", v, *rgb, 0) for v, rgb in sorted(amounts.items()))
        kids += chunk(0x121306, struct.pack("<III", 0, (frames or [0] * n)[i], 0),
                      chunk(0x10F02, struct.pack("<I", 0) + b"CLR0" + struct.pack("<I", len(amounts)) + rows))
    return chunk(0x121305, struct.pack(f"<II{n}I{n}I", 0, n, *range(n), *[7] * n), kids)


def integer_channel(frames, values, param=b"VRTX"):
    """An Integer Channel (0x12110E): the frames, then a u32 per key, no padding between them."""
    return chunk(0x12110E, struct.pack("<I", 0) + param + struct.pack(f"<I{len(frames)}H{len(values)}I", len(frames),
                                                                     *frames, *values))


def test_vertex_colour_sets_and_the_channel_that_picks_them():
    sets = colour_sets([{0: (0, 0, 0), 1: (0, 0, 0)}, {0: (104, 201, 209), 1: (104, 201, 209)}], frames=[0, 90])
    mesh = chunk(0x10000, text("skyboxShape") + struct.pack("<II", 0, 0), sets)
    data = p3d(mesh, integer_channel([40, 90, 120], [0, 1, 2]))
    m, ch = P.read_tree(data)
    assert [c.name for c in P.walk(m.children)] == ["Vertex Colour Sets", "Vertex Colour Set", "Vertex Colour Amounts",
                                                    "Vertex Colour Set", "Vertex Colour Amounts"]
    assert P.fields(data, m.children[0]) == {"version": 0, "sets": 2, "numbers": [0, 1], "unknown": [7, 7]}
    assert P.fields(data, m.children[0].children[1]) == {"version": 0, "frame": 90, "unknown": 0}
    assert P.fields(data, m.children[0].children[1].children[0]) == {"version": 0, "parameter": "CLR0", "count": 2}
    assert P.vertex_colour_sets(data, m) == [{0: (0, 0, 0), 1: (0, 0, 0)}, {0: (104, 201, 209), 1: (104, 201, 209)}]
    assert P.vertex_colour_sets(data, P.read_tree(p3d(chunk(0x10000, text("plain") + bytes(8))))[0]) == []
    # an odd number of keys: the values follow the frames straight away
    assert P.fields(data, ch) == {"version": 0, "parameter": "VRTX", "keys": 3}
    assert P.channel_keys(data, ch) == ("VRTX", [40, 90, 120], [(0,), (1,), (2,)])


# --------------------------------------------------------------------------- shadow records (SPEC-002, section 3.2)

def test_shadow_records():
    building = chunk(0x8800008, text("DevilsCay_02_shadow") + text("made_up_drawable_1") + struct.pack("<IIff", 1, 0, 0.0, 200.0))
    npc = chunk(0x8800008, text("NPC_shadow") + text("made_up_drawable_2") + struct.pack("<IIff", 0, 0, 0.0, 15.0))
    data = p3d(building, npc)
    b, n = P.read_tree(data)
    assert b.name == "Shadow"
    assert P.fields(data, b) == {"name": "DevilsCay_02_shadow", "composite drawable": "made_up_drawable_1",
                                 "building": True, "number": 0, "values": (0.0, 200.0)}
    assert P.fields(data, n)["building"] is False and P.fields(data, n)["values"] == (0.0, 15.0)
    assert "building=True" in P.dump(data)


# --------------------------------------------------------------------------- state props, zone packages, occluders,
# characters and vehicles (SPEC-003)

def test_the_names_of_the_prop_zone_and_water_chunks():
    assert {cid: P.NAMES[cid] for cid in (0x0802000E, 0x08020002, 0x08020003, 0x08020008, 0x0802000B, 0x08800009)} == {
        0x0802000E: "Prop State", 0x08020002: "Part Visibility", 0x08020003: "Prop State Animation",
        0x08020008: "Prop Property", 0x0802000B: "Prop State Effect", 0x08800009: "Zone Package Entry"}
    # the loaders' order in the Xbox program: shallow area, obstacle, dock
    assert [P.NAMES[cid] for cid in (0x08800201, 0x08800202, 0x08800203)] == ["Water Shallow Area", "Water Obstacle",
                                                                              "Water Dock"]


def prop_state(name, moves=0, after=0, frame=0.0, kids=b"", counts=(0, 0, 0, 0)):
    """A Prop State (0x0802000E): the name, then ten 4-byte values; counts: part visibilities, animations,
    properties, effects."""
    shown, anims, props, effects = counts
    return chunk(0x0802000E, text(name) + struct.pack("<6If3I", moves, after, shown, anims, 0, 0, frame, 0, props, effects),
                 kids)


def test_state_prop_data_its_states_and_what_they_hold():
    shown = chunk(0x08020002, text("gateShape") + struct.pack("<I", 1))
    anim = chunk(0x08020003, text("gateMove") + struct.pack("<3I3f", 1, 1, 0, 20.0, 0.0, 0.5))
    prop = chunk(0x08020008, text("percent_damaged") + text("50"))
    effect = chunk(0x0802000B, text("Effect") + text("dustCloud") + struct.pack("<I", 0) + text("gateJoint")
                   + struct.pack("<6fI", 0.0, 0.5, 0.0, 1.5708, 0.0, 0.0, 0) + text("gateJoint") + struct.pack("<2f", 2.0, 10.0))
    idle = prop_state("idle")
    opening = prop_state("opening", moves=1, after=2, frame=30.0, kids=shown + anim + prop + effect, counts=(1, 1, 1, 1))
    top = chunk(0x0802000D, struct.pack("<I", 4) + text("gate") + text("gate") + struct.pack("<II", 3, 1),
                chunk(0x08020008, text("name") + text("gate")) + idle + opening + prop_state("open"))
    data = p3d(top)
    t = P.read_tree(data)[0]
    assert [c.name for c in P.walk([t])] == ["State Prop Data", "Prop Property", "Prop State", "Prop State",
                                             "Part Visibility", "Prop State Animation", "Prop Property",
                                             "Prop State Effect", "Prop State"]
    # the number of states comes first, then the number of properties
    assert P.fields(data, t) == {"version": 4, "name": "gate", "composite drawable": "gate", "states": 3, "properties": 1}
    assert P.fields(data, t.children[0]) == {"name": "name", "value": "gate"}
    assert P.fields(data, t.children[1]) == {"name": "idle", "moves on": False, "next state": 0, "part visibilities": 0,
                                             "animations": 0, "0x08020004 sub-chunks": 0, "0x08020005 sub-chunks": 0,
                                             "frame": 0.0, "number": 0, "properties": 0, "effects": 0}
    st = t.children[2]
    assert P.fields(data, st) == {"name": "opening", "moves on": True, "next state": 2, "part visibilities": 1,
                                  "animations": 1, "0x08020004 sub-chunks": 0, "0x08020005 sub-chunks": 0,
                                  "frame": 30.0, "number": 0, "properties": 1, "effects": 1}
    vis, an, pr, ef = st.children
    assert P.fields(data, vis) == {"part": "gateShape", "shown": True}
    assert P.fields(data, an) == {"frame controller": "gateMove", "numbers": (1, 1, 0), "frames": (20.0, 0.0), "speed": 0.5}
    assert P.fields(data, pr) == {"name": "percent_damaged", "value": "50"}
    assert P.fields(data, ef) == {"kind": "Effect", "effect": "dustCloud", "number": 0, "joint": "gateJoint",
                                  "offset": (0.0, 0.5, 0.0), "angles": (1.5708, 0.0, 0.0), "number 2": 0,
                                  "joint 2": "gateJoint", "size": 2.0, "value": 10.0}
    assert "moves on=True" in P.dump(data) and "effect=dustCloud" in P.dump(data)


def test_an_old_state_prop_data_has_no_number_of_properties():
    data = p3d(chunk(0x0802000D, struct.pack("<I", 2) + text("crate") + text("crate") + struct.pack("<I", 1)))
    assert P.fields(data, P.read_tree(data)[0]) == {"version": 2, "name": "crate", "composite drawable": "crate", "states": 1}


def test_short_prop_and_zone_chunks_are_read_without_throwing():
    for cid, body in ((0x0802000E, text("idle") + b"\x01\x00"), (0x0802000B, text("Effect") + text("dust")),
                      (0x08020003, text("gateMove") + struct.pack("<I", 1)), (0x0880000A, struct.pack("<3f", 1, 2, 3)),
                      (0x0802000D, struct.pack("<I", 4) + text("gate"))):
        data = p3d(chunk(cid, body))
        assert P.fields(data, P.read_tree(data)[0]) == {}
    # a zone package entry that says six floats and holds three: the ones it has
    data = p3d(chunk(0x08800009, text("cut") + struct.pack("<I3f", 6, 1.0, 2.0, 3.0)))
    assert P.fields(data, P.read_tree(data)[0]) == {"name": "cut", "floats": 6, "near": 1.0, "far": 2.0, "fade": 3.0}
    # a character with only three of its texts: no shaders
    data = p3d(chunk(0x08800000, text("man") + text("manShape") + text("")))
    assert P.fields(data, P.read_tree(data)[0]) == {"name": "man", "model": "manShape", "low-detail model": "", "shaders": []}


def zone_entry(name, near, far, fade, x=0.0, minus_z=0.0):
    """A Zone Package Entry (0x08800009): the file keeps the reference point's z with its sign flipped."""
    return chunk(0x08800009, text(name) + struct.pack("<I6f", 6, near, far, fade, 0.0, x, minus_z))


def test_zone_package_entries_give_each_world_geometrys_draw_distance():
    zone = chunk(0x08800004, text("area_a") + struct.pack("<I", 2) + text("fake_dock") + text("shells_a"),
                 zone_entry("fake_dock", 83.9, 388.8, 5.0, 120.5, 300.25) + zone_entry("shells_a", 0.0, 10000.0, 15.0))
    data = p3d(zone, chunk(0x08800003, text("low_LOD_a") + text("low_LOD_a") + struct.pack("<I", 3)))
    z, geo = P.read_tree(data)
    assert [c.name for c in z.children] == ["Zone Package Entry", "Zone Package Entry"]
    assert P.fields(data, z) == {"name": "area_a", "world geometry": ["fake_dock", "shells_a"]}
    assert P.fields(data, z.children[0]) == {"name": "fake_dock", "floats": 6, "near": 83.9, "far": 388.8, "fade": 5.0,
                                             "value": 0.0, "point": (120.5, -300.25)}       # the sign put back
    none = P.fields(data, z.children[1])["point"]
    assert none == (0.0, 0.0) and math.copysign(1.0, none[1]) == 1.0                         # no minus zero
    assert P.fields(data, geo) == {"name": "low_LOD_a", "composite drawable": "low_LOD_a", "kind": 3}


def test_occluders():
    data = p3d(chunk(0x0880000A, struct.pack("<6fIf3f", 10.0, 2.0, -30.0, 0.0, 0.0, 1.0, 0, 0.0, 2.25, 10.0, 56.05)))
    occ = P.read_tree(data)[0]
    assert occ.name == "Occluder" and occ.head == 12 + 44
    assert P.fields(data, occ) == {"position": (10.0, 2.0, -30.0), "facing": (0.0, 0.0, 1.0), "number": 0, "value": 0.0,
                                   "sizes": (2.25, 10.0, 56.05)}


def test_characters_and_vehicles_are_eleven_texts():
    assert text("") == b"\x03\x00\x00\x00"                  # an empty text, which once looked like a u32 3
    person = chunk(0x08800000, text("woman_01") + text("woman_01Shape") + text("woman_01_low") + text("woman_01_SG")
                   + text("") * 7)
    car = chunk(0x08800001, text("plane") + text("plane") + text("plane_LOD") + text("plane_mt") + text("plane_glass")
                + text("") * 6)
    data = p3d(person, car)
    p, c = P.read_tree(data)
    assert (p.name, c.name) == ("Character", "Vehicle")
    assert P.fields(data, p) == {"name": "woman_01", "model": "woman_01Shape", "low-detail model": "woman_01_low",
                                 "shaders": ["woman_01_SG"] + [""] * 7}
    assert P.fields(data, c) == {"name": "plane", "model": "plane", "low-detail model": "plane_LOD",
                                 "shaders": ["plane_mt", "plane_glass"] + [""] * 6}


def test_an_instance_record_names_the_state_its_copy_starts_in():
    def record(state):
        return struct.pack("<3f9I", 1.0, 250.0, 2.0, 0, 90, 0, 40, 15, 0, 1, 0, state)
    data = p3d(*(chunk(0x09900194, record(n)) for n in (0, 1, 8, 11, 12)))
    first, idle, opened, closing, odd = (P.fields(data, c) for c in P.read_tree(data))
    assert "state" not in first and first["position"] == (1.0, 2.5, 2.0)    # 0: the prop's own first state
    assert (idle["state"], opened["state"], closing["state"], odd["state"]) == ("idle", "open", "closing", 12)
    assert [P.start_state(n) for n in range(12)] == [None, "idle", "final", "damage_1", "damage_2", "damage_3",
                                                     "damage_4", "explosion", "open", "opening", "closed", "closing"]


# ---- Boolean, Float2 and Entity channels; the frame controller (clean-room spec SPEC-005, sections 1.2 and 1.4) ----

def test_a_boolean_channel_has_no_values_every_key_flips_it():
    import p3d as P
    c = chunk(0x121108, struct.pack("<I", 0) + b"DFEN" + struct.pack("<HI3H", 1, 3, 5, 9, 20))
    data = p3d(c)
    ch = P.read_tree(data)[0]
    assert P.fields(data, ch) == {"version": 0, "parameter": "DFEN", "starts on": True, "keys": 3}
    assert P.channel_keys(data, ch) == ("DFEN", [5, 9, 20], [(False,), (True,), (False,)])      # on until frame 5
    off = p3d(chunk(0x121108, struct.pack("<I", 0) + b"VIS\0" + struct.pack("<HI1H", 0, 1, 12)))
    assert P.channel_keys(off, P.read_tree(off)[0]) == ("VIS", [12], [(True,)])                # off, then on from 12


def test_float2_and_entity_channels():
    import p3d as P
    f2 = p3d(chunk(0x121101, struct.pack("<I", 0) + b"OFF\0" + struct.pack("<I2H4f", 2, 0, 30, 0.0, 0.0, 1.0, 0.5)))
    assert P.channel_keys(f2, P.read_tree(f2)[0]) == ("OFF", [0, 30], [(0.0, 0.0), (1.0, 0.5)])
    ent = p3d(chunk(0x121107, struct.pack("<I", 0) + b"TEX\0" + struct.pack("<I2H", 2, 0, 1) + text("water.01.bmp") + text("water.02.bmp")))
    assert P.channel_keys(ent, P.read_tree(ent)[0]) == ("TEX", [0, 1], [("water.01.bmp",), ("water.02.bmp",)])


def test_the_frame_controllers_first_number_is_a_frame():
    import p3d as P
    data = p3d(chunk(0x121201, struct.pack("<I", 1) + text("PTRN_door") + b"PTRNANIM" + struct.pack("<fI", 12.5, 1)
                     + text("door") + text("PTRN_door_opening")))
    assert P.fields(data, P.read_tree(data)[0]) == {
        "version": 1, "name": "PTRN_door", "type": "PTRN", "word": "ANIM", "frame offset": 12.5, "number": 1,
        "drives": "door", "animation": "PTRN_door_opening"}
