"""Pure3D to glTF (portal/tools/p3d_gltf.py): skinned characters with animations, composite models, map areas
with placed instances, Xbox and PS2 vertex data, and the .glb itself. Every file here is made up; nothing
comes from the game."""
import json
import math
import struct

import pytest

import media
import p3d_gltf as G
from test_p3d import QUAD, chunk, p3d, prim_group, text


# --------------------------------------------------------------------------- helpers

def read_glb(glb: bytes):
    magic, version, total = struct.unpack_from("<III", glb)
    assert (magic, version, total) == (0x46546C67, 2, len(glb))
    jlen, jtype = struct.unpack_from("<II", glb, 12)
    assert jtype == 0x4E4F534A and jlen % 4 == 0
    doc = json.loads(glb[20:20 + jlen])
    blen, btype = struct.unpack_from("<II", glb, 20 + jlen)
    assert btype == 0x004E4942 and doc["buffers"][0]["byteLength"] == blen
    return doc, glb[28 + jlen:28 + jlen + blen]


def values(doc, binc, i):
    acc = doc["accessors"][i]
    view = doc["bufferViews"][acc["bufferView"]]
    code = {5126: "f", 5125: "I", 5123: "H", 5121: "B"}[acc["componentType"]]
    width = {"SCALAR": 1, "VEC2": 2, "VEC3": 3, "VEC4": 4, "MAT4": 16}[acc["type"]]
    flat = struct.unpack_from(f"<{acc['count'] * width}{code}", binc, view["byteOffset"])
    return [flat[k:k + width] for k in range(0, len(flat), width)]


def export(*files, lib=(), **kw):
    library = G.Library()
    for i, data in enumerate(files):
        library.add(f"main{i}.p3d", data, main=True)
    for name, data in lib:
        library.add(name, data, main=False)
    return G.export(library, **kw)


IDENT = [1.0, 0, 0, 0, 0, 1.0, 0, 0, 0, 0, 1.0, 0]


def skeleton(name, joints):
    """joints: (name, parent, (x, y, z))"""
    kids = b"".join(chunk(0x23001, text(j) + struct.pack("<I16f", p, *IDENT, *t, 1.0)) for j, p, t in joints)
    return chunk(0x23000, text(name) + struct.pack("<IIII", 0, len(joints), 0, 0), kids)


def composite(name, skel, parts):
    """parts: (drawable, kind, joint)"""
    kids = b"".join(chunk(0x123001, struct.pack("<II", 0, 0) + text(d) + struct.pack("<II", k, j))
                    for d, k, j in parts)
    return chunk(0x123000, struct.pack("<I", 0) + text(name) + text(skel) + struct.pack("<I", len(parts)), kids)


def mesh(name, shader="paint", positions=QUAD, indices=(0, 1, 2, 3), kids=b""):
    return chunk(0x10000, text(name) + struct.pack("<II", 0, 1),
                 prim_group(shader, 1, 0x2001, positions, list(indices), kids=kids))


def uv_list(uvs, channel=0):
    flat = [v for uv in uvs for v in uv]
    return chunk(0x10007, struct.pack(f"<II{len(flat)}f", len(uvs), channel, *flat))


# --------------------------------------------------------------------------- placement records

def game_matrix(ax, ay, az):
    """The game's own rotation (default.xbe 0x243020 fed by 0x53E50), as rows for row vectors."""
    a, b, c = (math.radians(v) for v in (-ax, -ay, az))
    sa, ca, sb, cb, sc, cc = math.sin(a), math.cos(a), math.sin(b), math.cos(b), math.sin(c), math.cos(c)
    return [[cc * cb, sc * cb, -sb],
            [sa * sb * cc - ca * sc, sa * sb * sc + ca * cc, sa * cb],
            [ca * sb * cc + sa * sc, ca * sb * sc - sa * cc, ca * cb]]


def quat_matrix(q):
    x, y, z, w = q
    return [[1 - 2 * (y * y + z * z), 2 * (x * y - z * w), 2 * (x * z + y * w)],
            [2 * (x * y + z * w), 1 - 2 * (x * x + z * z), 2 * (y * z - x * w)],
            [2 * (x * z - y * w), 2 * (y * z + x * w), 1 - 2 * (x * x + y * y)]]


def record(x, y_cm, z, angles=(0, 0, 0), scale=(40, 15, 0), uniform=1):
    return list(struct.unpack("<3I", struct.pack("<3f", x, y_cm, z))) + list(angles) + list(scale) + [uniform, 0, 0]


def test_instance_record_position_height_and_scale():
    t, q, s = G.instance_trs(record(-1725.604, 605.0, -1013.845))
    assert t == pytest.approx((-1725.604, 6.05, 1013.845), abs=1e-3)       # centimetres; Z mirrored
    assert q == pytest.approx((0.0, 0.0, 0.0, 1.0)) and s == pytest.approx((1.0, 1.0, 1.0))
    assert G.instance_trs(record(0, 605.9, 0))[0][1] == pytest.approx(6.05)  # whole centimetres, as the game keeps
    assert G.instance_trs(record(0, 0, 0, scale=(24, 9, 0)))[2] == pytest.approx((0.6, 0.6, 0.6))
    assert G.instance_trs(record(0, 0, 0, scale=(18, 15, 18), uniform=0))[2] == pytest.approx((0.9, 0.75, 0.9))


@pytest.mark.parametrize("angles", [(0, 90, 0), (10, 0, 0), (0, 0, 30), (176, 46, 178), (358, 308, 0)])
def test_instance_rotation_is_the_games_matrix_mirrored(angles):
    _t, q, _s = G.instance_trs(record(0, 0, 0, angles))
    kept = (angles[0] // 2 * 2, angles[1], angles[2] // 2 * 2)               # X and Z are kept in 2-degree steps
    rows = game_matrix(*kept)
    col = [[rows[j][i] for j in range(3)] for i in range(3)]                  # the same matrix for column vectors
    flip = [1, 1, -1]
    want = [[col[i][j] * flip[i] * flip[j] for j in range(3)] for i in range(3)]
    got = quat_matrix(q)
    for i in range(3):
        assert got[i] == pytest.approx(want[i], abs=1e-6)


# --------------------------------------------------------------------------- characters

def skin_chunk(positions, indices, weights, matrices, palette):
    flat = [v for p in positions for v in p]
    w3 = [v for w in weights for v in w]
    kids = (chunk(0x10005, struct.pack(f"<I{len(flat)}f", len(positions), *flat))
            + chunk(0x1000A, struct.pack(f"<I{len(indices)}I", len(indices), *indices))
            + chunk(0x1000C, struct.pack(f"<I{len(w3)}f", len(weights), *w3))
            + chunk(0x1000B, struct.pack(f"<I{len(matrices)}I", len(matrices), *matrices))
            + chunk(0x1000D, struct.pack(f"<I{len(palette)}I", len(palette), *palette)))
    head = struct.pack("<I", 0) + text("suit") + struct.pack("<9I", 0, 0x2181, len(positions), len(indices), 2, 0, 1, 0, 0)
    return chunk(0x10001, text("tony") + struct.pack("<I", 3) + text("rig") + struct.pack("<I", 1),
                 chunk(0x10020, head, kids))


def animation(name, groups):
    """groups: (joint name, [(frame, (x, y, z, w))])"""
    gl = b""
    for jname, keys in groups:
        frames = struct.pack(f"<{len(keys)}H", *[f for f, _ in keys])
        frames += b"\0" * (-len(frames) % 4)
        vals = b"".join(struct.pack("<4f", *v) for _, v in keys)
        ch = chunk(0x121105, struct.pack("<I", 1) + b"ROT\0" + struct.pack("<I", len(keys)) + frames + vals)
        gl += chunk(0x121001, struct.pack("<I", 0) + text(jname) + struct.pack("<II", 0, 1), ch)
    return chunk(0x121000, struct.pack("<I", 0) + text(name) + b"PTRN" + struct.pack("<ffI", 10.0, 30.0, 1),
                 chunk(0x121002, struct.pack("<II", 0, len(groups)), gl))


def test_a_skinned_character_with_an_animation():
    rig = skeleton("rig", [("Root", 0, (0, 0, 0)), ("Hip", 0, (0, 1.0, 0.5))])
    tri = [(0, 0, 0), (1, 0, 0), (0, 1, 0)]
    # the matrix list's last byte goes with the first weight: palette slot 1 (joint 0) then slot 0 (joint 1)
    skin = skin_chunk(tri, [0, 1, 2], [(0.75, 0.25, 0.0)] * 3, [0x01000000] * 3, [1, 0])
    half = math.sqrt(0.5)
    anim = animation("Wave", [("hip", [(0, (0, 0, 0, 1)), (30, (0, half, 0, half))]), ("Nobody", [(0, (0, 0, 0, 1))])])
    glb, report = export(p3d(rig, skin, anim))
    doc, binc = read_glb(glb)
    assert report.models == ["tony"] and report.animations == ["Wave"]
    sk = doc["skins"][0]
    names = [doc["nodes"][j]["name"] for j in sk["joints"]]
    assert names == ["Root", "Hip"]
    hip = doc["nodes"][sk["joints"][1]]
    assert hip["translation"] == pytest.approx([0, 1.0, -0.5])                # Z mirrored
    ibm = values(doc, binc, sk["inverseBindMatrices"])
    assert ibm[1][12:15] == pytest.approx((0, -1.0, 0.5))                     # inverse of the rest pose
    node = next(n for n in doc["nodes"] if n.get("skin") == 0)
    prim = doc["meshes"][node["mesh"]]["primitives"][0]
    joints = values(doc, binc, prim["attributes"]["JOINTS_0"])
    weights = values(doc, binc, prim["attributes"]["WEIGHTS_0"])
    assert joints[0][:2] == (0, 1) and weights[0][:2] == pytest.approx((0.75, 0.25))
    assert values(doc, binc, prim["indices"]) == [(0,), (2,), (1,)]          # turned round for the mirroring
    a = doc["animations"][0]
    assert len(a["channels"]) == 1 and a["channels"][0]["target"] == {"node": sk["joints"][1], "path": "rotation"}
    s = a["samplers"][0]
    assert [t for (t,) in values(doc, binc, s["input"])] == pytest.approx([0.0, 1.0])
    assert values(doc, binc, s["output"])[1] == pytest.approx((0, -half, 0, half))   # mirrored: -x, -y


def test_rotations_keep_to_the_short_way_round():
    rig = skeleton("rig", [("Root", 0, (0, 0, 0))])
    anim = animation("Spin", [("Root", [(0, (0, 0, 0, 1)), (10, (0, 0, 0, -1))])])
    doc, binc = read_glb(export(p3d(rig, composite("thing", "rig", [("box", 1, 0)]), mesh("box"), anim))[0])
    out = values(doc, binc, doc["animations"][0]["samplers"][0]["output"])
    assert out[1] == pytest.approx((0, 0, 0, 1))


# --------------------------------------------------------------------------- models

def test_a_composite_model_hangs_its_parts_on_joints_and_drops_shadows():
    rig = skeleton("car", [("car", 0, (0, 0, 0)), ("door", 0, (1.0, 0.5, 2.0))])
    data = p3d(rig, mesh("doorShape"), mesh("bodyShape"), mesh("shadowShape"),
               composite("car", "car", [("bodyShape", 1, 0), ("doorShape", 1, 1), ("shadowShape", 0x20, 0)]))
    glb, report = export(data)
    doc, _ = read_glb(glb)
    assert report.models == ["car"]
    door = next(n for n in doc["nodes"] if n["name"] == "door")
    assert door["translation"] == pytest.approx([1.0, 0.5, -2.0])
    assert [doc["nodes"][c]["name"] for c in door["children"]] == ["doorShape"]
    assert not any(n["name"] == "shadowShape" for n in doc["nodes"])
    assert len(doc["meshes"]) == 2


def test_several_models_are_set_out_side_by_side():
    data = p3d(mesh("a"), mesh("b", positions=[(x * 3, y, z) for x, y, z in QUAD]))
    doc, _ = read_glb(export(data)[0])
    tops = [doc["nodes"][i] for i in doc["scenes"][0]["nodes"]]
    assert [n["name"] for n in tops] == ["a", "b"]
    assert tops[1]["translation"][0] >= 1.0 + 0.25


def test_textures_go_in_with_the_material():
    pixels = bytes([255, 0, 0, 255]) * 4
    png = media.png(2, 2, pixels)
    tex = chunk(0x19000, text("red.tga") + struct.pack("<4I", 14000, 2, 2, 32),
                chunk(0x19001, text("red.tga") + struct.pack("<7I", 14000, 2, 2, 32, 0, 0, 1),
                      chunk(0x19002, struct.pack("<I", len(png)) + png)))
    shader = chunk(0x11000, text("paint") + struct.pack("<I", 0) + text("simple") + struct.pack("<4I", 0, 0, 0, 2),
                   chunk(0x11002, b"TEX\0" + text("red.tga"))
                   + chunk(0x11003, b"2SID" + struct.pack("<I", 1)) + chunk(0x11003, b"LIT\0" + struct.pack("<I", 0)))
    uvs = uv_list([(0, 0), (1, 0), (0, 1), (1, 1)])
    doc, binc = read_glb(export(p3d(tex, shader, mesh("box", kids=uvs)))[0])
    mat = doc["materials"][0]
    assert mat["doubleSided"] and "KHR_materials_unlit" in mat["extensions"]
    assert doc["extensionsUsed"] == ["KHR_materials_unlit"]
    img = doc["images"][doc["textures"][mat["pbrMetallicRoughness"]["baseColorTexture"]["index"]]["source"]]
    view = doc["bufferViews"][img["bufferView"]]
    assert binc[view["byteOffset"]:view["byteOffset"] + view["byteLength"]] == png
    prim = doc["meshes"][0]["primitives"][0]
    assert values(doc, binc, prim["attributes"]["TEXCOORD_0"])[2] == pytest.approx((0, 0))    # V flipped


def test_a_map_shader_missing_from_the_files_is_read_from_its_name():
    info = G.shader_from_name("GlobalShader_g_hedge.tga_simple_blmd1_mcbv0_lit1_alpha1_atst1_alum1_2sid0")
    assert info["textures"] == [("TEX", "g_hedge.tga")]
    assert info["ints"]["ATST"] == 1 and info["ints"]["2SID"] == 0
    assert G.shader_from_name("cabriolet_mt") is None


# --------------------------------------------------------------------------- maps

def object_group(objects):
    """objects: (model name, [record, ...])"""
    kids = b""
    for model, recs in objects:
        props = chunk(0x9900192, text("modelname") + struct.pack("<I", 0) + text(model))
        for rec in recs:
            props += chunk(0x9900192, text("instanceposition") + struct.pack("<II", 2, 3),
                           chunk(0x9900194, struct.pack("<12I", *rec)))
        kids += chunk(0x9900190, text("objects.ds") + text(model + "_set") + text("instanceobject"), props)
    return chunk(0x9900191, text("objects.ds") + text("instances") + text("gamegroup") + struct.pack("<I", 1), kids)


def world_geo(name):
    return chunk(0x8800003, text(name) + text(name) + struct.pack("<I", 0))


def area(name, at=(100.0, 5.0, -200.0), objects=(), shader="paint"):
    rig = skeleton(name, [(name, 0, (0, 0, 0)), ("collapsedMesh_0", 0, at)])
    return p3d(rig, mesh("collapsedMesh_0", shader), composite(name, name, [("collapsedMesh_0", 1, 1)]),
               world_geo(name), object_group(objects))


def region(prefix, tree_width):
    """A region (its shaders) and its _D file (the models its areas place)."""
    shader = chunk(0x11000, text(f"RegionShader_{prefix}") + struct.pack("<I", 0) + text("simple")
                   + struct.pack("<4I", 0, 0, 0, 0))
    tree = skeleton("treeP", [("treeP", 0, (0, 0, 0))])
    pts = [(x * tree_width, y, z) for x, y, z in QUAD]
    return p3d(shader), p3d(tree, mesh("treePShape", positions=pts), composite("treeP", "treeP", [("treePShape", 1, 0)]))


def test_a_map_area_with_its_world_geometry_and_placed_models():
    shell = area("shells_a", objects=[("treep", [record(10.0, 250.0, 20.0, (0, 90, 0)), record(0, 0, 0)]),
                                      ("lamppost", [record(1.0, 0.0, 1.0)])])
    reg, reg_d = region("x", 1.0)
    glb, report = export(shell, lib=[("x_region.p3d", reg), ("x_region_D.p3d", reg_d)], map_mode=True)
    doc, _ = read_glb(glb)
    assert report.models == ["shells_a"] and report.placed == 1 and report.at_origin == 1
    assert report.unplaced == {"lamppost": 1}
    piece = next(n for n in doc["nodes"] if n["name"] == "collapsedMesh_0" and "translation" in n)
    assert piece["translation"] == pytest.approx([100.0, 5.0, 200.0])
    tree = next(n for n in doc["nodes"] if n["name"] == "treep")
    assert tree["translation"] == pytest.approx([10.0, 2.5, -20.0])
    assert quat_matrix(tree["rotation"])[0] == pytest.approx([0, 0, 1], abs=1e-6)   # the game's -90 about Y, mirrored
    top = doc["nodes"][doc["scenes"][0]["nodes"][0]]
    assert top["name"] == "main0"


def test_placed_models_come_from_the_areas_own_region():
    # both regions have a "treeP"; the area uses region y's shader, so region y's tree (2 m wide) is placed
    shell = area("shells_b", objects=[("treep", [record(1.0, 0.0, 1.0)])], shader="RegionShader_y")
    rx, rx_d = region("x", 1.0)
    ry, ry_d = region("y", 2.0)
    lib = [("x_region.p3d", rx), ("x_region_D.p3d", rx_d), ("y_region.p3d", ry), ("y_region_D.p3d", ry_d)]
    doc, binc = read_glb(export(shell, lib=lib, map_mode=True)[0])
    tree = next(n for n in doc["nodes"] if n["name"] == "treePShape")
    pos = doc["accessors"][doc["meshes"][tree["mesh"]]["primitives"][0]["attributes"]["POSITION"]]
    assert pos["max"][0] == pytest.approx(2.0)


def test_low_detail_city_is_left_out_next_to_the_real_areas():
    lod = area("low_LOD_1", at=(0, 0, 0))
    lib = G.Library()
    lib.add("miami_lod.p3d", lod, main=True)
    lib.add("a_shell.p3d", area("shells_a"), main=True)
    _glb, report = G.export(lib, map_mode=True)
    assert report.models == ["shells_a"]
    _glb, report = G.export(lib, map_mode=True, lod=True)
    assert report.models == ["low_LOD_1", "shells_a"]
    only = G.Library()
    only.add("miami_lod.p3d", lod, main=True)
    assert G.export(only, map_mode=True)[1].models == ["low_LOD_1"]


def test_area_names_for_split_exports():
    from pathlib import Path
    assert G._area(Path("stripmall_01_detailB.p3d")) == "stripmall_01"
    assert G._area(Path("stripmall_01_shell.p3d")) == "stripmall_01"
    assert G._area(Path("cargoShip_01_shell_CS0.p3d")) == "cargoShip_01"
    assert G._area(Path("havana_cabanaCigar_dzone.p3d")) == "havana_cabanaCigar"


# --------------------------------------------------------------------------- console vertex data

def test_xbox_vertex_buffer_with_packed_normals_and_colours():
    def normpacked(x, y, z):
        return (round(x * 1023) & 0x7FF) | (round(y * 1023) & 0x7FF) << 11 | (round(z * 511) & 0x3FF) << 22
    verts = b""
    for i, (x, y, z) in enumerate(QUAD):
        verts += struct.pack("<3fII2f", x, y, z, normpacked(-1.0, 0, 0), 0xFF102030, i * 0.25, 0.5)
    body = struct.pack("<III", 0x20001, 0, len(verts)) + verts
    idx = struct.pack("<4H", 0, 1, 2, 3)
    kids = chunk(0x10012, body) + chunk(0x10013, struct.pack("<III", 0x20001, 0, len(idx)) + idx)
    head = struct.pack("<I", 0) + text("x") + struct.pack("<9I", 1, 0x2031, 4, 4, 0, 1, 1, 0, 0)
    data = p3d(chunk(0x10020, head, kids))
    g = G.geometry(data, G.p3d.read_tree(data)[0])
    assert g.positions[3] == pytest.approx((1, 1, 0)) and g.normals[0] == pytest.approx((-1, 0, 0), abs=0.01)
    assert g.colours[0] == 0xFF102030 and g.uvs[0][2] == pytest.approx((0.5, 0.5))
    assert len(g.triangles) == 2


def vif_unpack(addr, comps, bits, rows, mask=False, unsigned=False):
    vn, vl = comps - 1, {32: 0, 16: 1, 8: 2}[bits]
    cmd = 0x60 | (0x10 if mask else 0) | vn << 2 | vl
    code = {32: "f" if isinstance(rows[0][0], float) else "i", 16: "h", 8: "b"}[bits]
    if unsigned:
        code = code.upper()
    raw = b"".join(struct.pack(f"<{comps}{code}", *r) for r in rows)
    raw += b"\0" * (-len(raw) % 4)
    imm = addr | 0x8000 | (0x4000 if unsigned else 0)
    return struct.pack("<I", cmd << 24 | len(rows) << 16 | imm) + raw


def test_ps2_vertex_packets():
    pos = [(0, 0, 0), (1000, 0, 0), (0, 1000, 0), (1000, 1000, 0), (2000, 0, 0)]
    # the lowest bit of a U set: no triangle ends at that vertex (the strip starts again there)
    uvs = [(0.0, 0.0), (0.25, 0.0), (0.0, 0.25), (0.25, 0.25), (0.5, 0.0)]
    uv_rows = []
    for i, (u, v) in enumerate(uvs):
        bits = struct.unpack("<I", struct.pack("<f", u))[0]
        if i == 4:
            bits |= 1
        uv_rows.append((struct.unpack("<f", struct.pack("<I", bits))[0], v))
    header = struct.pack("<4I", len(pos), 1, 0, 0) + bytes(16) + struct.pack("<4f", 0.001, 1 / 127, 0, 0) + bytes(16)
    blob = struct.pack("<I", 0x6C048000) + header                        # UNPACK V4-32, 4 quadwords to address 0
    blob += struct.pack("<I", 0x01000103)                                # STCYCL: one quadword in three
    blob += vif_unpack(4, 2, 32, uv_rows, mask=True)
    blob += vif_unpack(5, 3, 8, [(0, 0, 127)] * 5, mask=True)
    blob += vif_unpack(6, 3, 16, pos, mask=True)
    body = struct.pack("<III", 0x100008, 0, len(blob)) + blob
    head = struct.pack("<I", 0) + text("x") + struct.pack("<9I", 1, 0x2011, 5, 0, 0, 1, 1, 0, 0)
    data = p3d(chunk(0x10020, head, chunk(0x10012, body)))
    g = G.geometry(data, G.p3d.read_tree(data)[0])
    assert g.positions[1] == pytest.approx((1.0, 0, 0)) and g.normals[0] == pytest.approx((0, 0, 1.0))
    assert g.uvs[0][1] == pytest.approx((0.25, 0.0))
    assert g.triangles == [(0, 1, 2), (2, 1, 3)]                         # the last vertex starts a new strip


def test_ps2_skin_weights_cascade():
    # weights (0.6, 0.2, 0.2) are stored as 0.6, then 0.2 / 0.6, then 0.2 / 0.2, each over 4096
    header = struct.pack("<4I", 3, 7, 0, 0) + bytes(16) + struct.pack("<4f", 0.001, 1 / 127, 0, 0) + bytes(16)
    blob = struct.pack("<I", 0x6C048000) + header + struct.pack("<I", 0x01000105)
    blob += vif_unpack(4, 2, 32, [(0.0, 0.0)] * 3, mask=True)
    blob += vif_unpack(5, 3, 8, [(0, 127, 0)] * 3, mask=True)
    blob += vif_unpack(6, 3, 16, [(0, 0, 0), (1000, 0, 0), (0, 1000, 0)], mask=True)
    blob += vif_unpack(7, 4, 8, [(4, 8, 0, 8)] * 3, unsigned=True)
    blob += vif_unpack(8, 4, 16, [(2458, 1365, 4096, 0)] * 3)
    body = struct.pack("<III", 0x100008, 0, len(blob)) + blob
    head = struct.pack("<I", 0) + text("x") + struct.pack("<9I", 1, 0x2191, 3, 0, 3, 1, 1, 0, 0)
    pal = chunk(0x1000D, struct.pack("<4I", 3, 7, 9, 11))
    data = p3d(chunk(0x10020, head, chunk(0x10012, body) + pal))
    g = G.geometry(data, G.p3d.read_tree(data)[0])
    assert g.joints[0] == (9, 11, 7, 11)
    assert g.weights[0][:3] == pytest.approx((0.6, 0.2, 0.2), abs=1e-3)


# --------------------------------------------------------------------------- the command line

def test_command_line_writes_a_glb(tmp_path, capsys):
    (tmp_path / "box.p3d").write_bytes(p3d(mesh("box")))
    out = tmp_path / "box.glb"
    assert G.main([str(out), str(tmp_path / "*.p3d")]) == 0
    doc, _ = read_glb(out.read_bytes())
    assert doc["nodes"][0]["name"] == "box"
    assert G.main([str(tmp_path / "x.glb"), str(tmp_path / "*.p3d"), "--list"]) == 0
    assert not (tmp_path / "x.glb").exists()
    assert "1 model(s): box" in capsys.readouterr().out


def test_command_line_splits_a_map_by_area(tmp_path):
    for name in ("a_01_shell", "a_01_detail", "b_02_shell"):
        (tmp_path / f"{name}.p3d").write_bytes(area("w_" + name))
    out = tmp_path / "out"
    assert G.main([str(out), str(tmp_path), "--map", "--split"]) == 0
    assert sorted(p.name for p in out.iterdir()) == ["a_01.glb", "b_02.glb"]
    doc, _ = read_glb((out / "a_01.glb").read_bytes())
    assert [doc["nodes"][i]["name"] for i in doc["scenes"][0]["nodes"]] == ["a_01_detail", "a_01_shell"]


def test_nothing_to_export_is_said_plainly(tmp_path, capsys):
    (tmp_path / "empty.p3d").write_bytes(p3d(chunk(0x10017, struct.pack("<I", 1))))
    assert G.main([str(tmp_path / "e.glb"), str(tmp_path / "empty.p3d")]) == 1
    assert "nothing in these files" in capsys.readouterr().err


# --------------------------------------------------------------------------- the portal

def test_portal_hands_over_a_copied_file_for_blender(monkeypatch, tmp_path):
    import importlib
    import sys
    from conftest import PORTAL
    sys.path.insert(0, str(PORTAL))
    server = importlib.import_module("decomp_portal_server")
    files = city_files()
    rig = skeleton("rig", [("Root", 0, (0, 0, 0)), ("Hip", 0, (0, 1.0, 0.5))])
    tri = [(0, 0, 0), (1, 0, 0), (0, 1, 0)]
    files["cement.rcf/packages/characters/pc/tony.p3d"] = p3d(rig, skin_chunk(tri, [0, 1, 2], [(1.0, 0, 0)] * 3,
                                                                             [0] * 3, [0, 1]))
    files["cement.rcf/art/animations/GEN_Wave.p3d"] = p3d(animation("Wave", [("Hip", [(0, (0, 0, 0, 1))])]))
    out, index = copied_game(tmp_path, files)
    monkeypatch.setattr(server.GA, "out_dir", lambda bin_dir=None: out)
    monkeypatch.setattr(server.GAME_FILES, "index", lambda: index)
    sent = []

    class Fake:
        client_address = ("127.0.0.1", 5)
        headers = {}
        _send_model = server.Handler._send_model
        _send_area = server.Handler._send_area

        def _send(self, code, body, ctype, extra=None):
            sent.append((code, ctype, body, extra))

        def _json(self, obj, code=200):
            sent.append((code, "json", obj, None))

    def ask(**q):
        server.Handler.get_game_file_preview(Fake(), "model", lambda k, d="": q.get(k, d))
        return sent[-1]

    code, ctype, body, extra = ask(version="pc", path="cement.rcf/art/box.p3d")
    assert code == 200 and ctype == "model/gltf-binary" and 'filename="box.glb"' in extra["Content-Disposition"]
    assert read_glb(body)[0]["nodes"][0]["name"] == "box"
    code, _, body, _ = ask(version="pc", path="cement.rcf/packages/z04/a_01_shell.p3d")
    doc, _ = read_glb(body)
    assert code == 200 and any(n["name"] == "treep" for n in doc["nodes"])      # placed from the region's _D file
    code, _, body, _ = ask(version="pc", path="cement.rcf/packages/characters/pc/tony.p3d")
    assert [a["name"] for a in read_glb(body)[0]["animations"]] == ["Wave"]     # the game's animations come along
    assert ask(version="pc", path="cement.rcf/nope.p3d")[0] == 404


def test_files_beside_a_copied_file(tmp_path):
    import game_assets as GA
    (tmp_path / "PC" / "z04").mkdir(parents=True)
    for n in ("a_shell.p3d", "x_region.p3d", "x_region_D.p3d", "notes.txt"):
        (tmp_path / "PC" / "z04" / n).write_bytes(b"12345")
    rows = [[f"cement.rcf/packages/z04/{n}", 5, "s", "only", f"PC/z04/{n}", None, 1]
            for n in ("a_shell.p3d", "x_region.p3d", "x_region_D.p3d", "notes.txt")]
    rows.append(["cement.rcf/packages/z04/deeper/y_region.p3d", 5, "s", "only", "PC/z04/x_region.p3d", None, 1])
    index = {"versions": {"pc": {"files": rows}}}
    found = GA.files_beside(tmp_path, index, "pc", "cement.rcf/packages/z04/a_shell.p3d", ("*_region.p3d", "*_REGION_d.p3d"))
    assert [p.name for p in found] == ["x_region.p3d", "x_region_D.p3d"]


# --------------------------------------------------------------------------- whole areas and the whole city

def copied_game(tmp_path, files):
    """A copied PC version: {game path: bytes} -> (out dir, index)."""
    out = tmp_path / "game_files"
    rows = []
    for path, data in files.items():
        place = "PC/" + path
        (out / place).parent.mkdir(parents=True, exist_ok=True)
        (out / place).write_bytes(data)
        rows.append([path, len(data), "s", "only", place, None, 1])
    return out, {"versions": {"pc": {"files": rows}}}


def city_files():
    _reg, reg_d = region("x", 1.0)
    z = "cement.rcf/packages/z04/"
    return {z + "a_01_shell.p3d": area("w_a_shell", objects=[("treep", [record(1.0, 0.0, 1.0)])]),
            z + "a_01_detail.p3d": area("w_a_detail"),
            z + "b_02_shell.p3d": area("w_b"),
            z + "x_region_D.p3d": reg_d,
            z + "miami_lod.p3d": area("low_LOD"),
            "cement.rcf/packages/azones/shop_01_pocket.p3d": area("w_shop"),
            "cement.rcf/art/box.p3d": p3d(mesh("box"))}


def test_map_areas_in_the_copied_files(tmp_path):
    import blender_export as BX
    out, index = copied_game(tmp_path, city_files())
    found = BX.areas(out, index, "pc")
    assert [(a["key"], len(a["files"])) for a in found] == [("z04/a_01", 2), ("z04/b_02", 1), ("azones/shop_01", 1)]
    glb, report = BX.area_glb(out, index, "pc", "z04/a_01")
    doc, _ = read_glb(glb)
    assert sorted(report.models) == ["w_a_detail", "w_a_shell"] and report.placed == 1      # the tree from x_region_D
    with pytest.raises(G.ExportError):
        BX.area_glb(out, index, "pc", "z04/nowhere")


def test_the_whole_city_one_file_per_area(tmp_path):
    import blender_export as BX
    out, index = copied_game(tmp_path, city_files())
    job = BX.CityJob(tmp_path)
    import game_assets as GA
    real_out = GA.out_dir
    GA.out_dir = lambda bin_dir=None: out
    try:
        assert job.start("pc", index) is None
        job._thread.join(10)
    finally:
        GA.out_dir = real_out
    assert sorted(p.name for p in (tmp_path / "blender" / "PC").iterdir()) == ["a_01.glb", "b_02.glb"]
    assert job.status["written"] == 2 and job.status["done"] == 2 and not job.status["running"]
    assert BX.CityJob(tmp_path).start("pc", {"versions": {}}).startswith("None of the city")
    assert BX.CityJob(tmp_path).start("wii", index) == "Pick a version."


def test_portal_hands_over_a_whole_area(monkeypatch, tmp_path):
    import importlib
    import sys
    from conftest import PORTAL
    sys.path.insert(0, str(PORTAL))
    server = importlib.import_module("decomp_portal_server")
    out, index = copied_game(tmp_path, city_files())
    monkeypatch.setattr(server.GA, "out_dir", lambda bin_dir=None: out)
    monkeypatch.setattr(server.GAME_FILES, "index", lambda: index)
    sent = []

    class Fake:
        client_address = ("127.0.0.1", 5)
        headers = {}
        _send_area = server.Handler._send_area

        def _send(self, code, body, ctype, extra=None):
            sent.append((code, ctype, body, extra))

        def _json(self, obj, code=200):
            sent.append((code, "json", obj, None))

    server.Handler.get_game_file_preview(Fake(), "model", lambda k, d="": {"version": "pc", "area": "z04/a_01"}.get(k, d))
    code, ctype, body, extra = sent[-1]
    assert code == 200 and ctype == "model/gltf-binary" and 'filename="a_01.glb"' in extra["Content-Disposition"]
    server.Handler.get_game_file_preview(Fake(), "model", lambda k, d="": {"version": "pc", "area": "z04/zz"}.get(k, d))
    assert sent[-1][0] == 404 and "isn't in your copied game files" in sent[-1][2]["error"]


# --------------------------------------------------------------------------- cameras

def check_references(doc, binc):
    """Every index in the document points at something that is there, and every accessor fits its view."""
    n = {k: len(doc.get(k, [])) for k in ("nodes", "meshes", "cameras", "skins", "accessors", "bufferViews",
                                          "materials", "textures", "images")}
    for node in doc["nodes"]:
        for k, total in (("mesh", n["meshes"]), ("camera", n["cameras"]), ("skin", n["skins"])):
            assert node.get(k, 0) < max(total, 1)
        assert all(c < n["nodes"] for c in node.get("children", []))
    width = {"SCALAR": 1, "VEC2": 2, "VEC3": 3, "VEC4": 4, "MAT4": 16}
    for acc in doc["accessors"]:
        view = doc["bufferViews"][acc["bufferView"]]
        size = {5126: 4, 5125: 4, 5123: 2, 5121: 1}[acc["componentType"]] * width[acc["type"]]
        assert acc.get("byteOffset", 0) + acc["count"] * size <= view["byteLength"]
        assert view["byteOffset"] + view["byteLength"] <= len(binc)
    for a in doc.get("animations", []):
        for ch in a["channels"]:
            assert ch["target"]["node"] < n["nodes"] and ch["sampler"] < len(a["samplers"])
        for s in a["samplers"]:
            times = [t for (t,) in values(doc, binc, s["input"])]
            assert times == sorted(set(times))                                # rising
            assert doc["accessors"][s["input"]]["count"] == doc["accessors"][s["output"]]["count"]


def camera_file(name, fov, position, look, up, moves=None):
    """A Camera chunk, and its move: (parameter, chunk id, [(frame, value)]) channels, played by a frame
    controller as in frontend/prebuilt/*.p3d."""
    cam = chunk(0x2200, text(name) + struct.pack("<I13f", 2, fov, 1.0, 0.1, 1000.0, *position, *look, *up))
    if not moves:
        return p3d(cam)
    group = b""
    for param, cid, keys in moves:
        frames = struct.pack(f"<{len(keys)}H", *[f for f, _ in keys])
        frames += b"\0" * (-len(frames) % 4)
        width = 3 if cid == 0x121104 else 1
        vals = b"".join(struct.pack(f"<{width}f", *v) for _, v in keys)
        group += chunk(cid, struct.pack("<I", 0) + param.encode().ljust(4, b"\0") + struct.pack("<I", len(keys))
                       + frames + vals)
    anim = chunk(0x121000, struct.pack("<I", 0) + text("CAM_" + name) + b"CAM\0" + struct.pack("<ffI", 60.0, 30.0, 0),
                 chunk(0x121002, struct.pack("<II", 0, 1),
                       chunk(0x121001, struct.pack("<I", 0) + text("CAM_" + name) + struct.pack("<II", 0, len(moves)),
                             group)))
    fc = chunk(0x121201, struct.pack("<I", 1) + text("CAM_" + name) + b"CAM\0ANIM" + struct.pack("<fI", 0, 1)
               + text(name) + text("CAM_" + name))
    return p3d(anim, cam, fc)


def test_a_camera_and_its_move():
    # the end of the game: looking down at Tony and rising (frontend/prebuilt/TonyEndGameCam.p3d)
    down = (0.0, -1.0, 0.0)
    glb, report = export(camera_file("cameraShape1", math.radians(40), (0, 3, -1), down, (0, 0, 1), [
        ("TRAN", 0x121104, [(0, (0, 3, -1)), (30, (0, 6, -1))]),
        ("LOOK", 0x121104, [(0, down), (60, (0, 0, 1))]),
        ("UP", 0x121104, [(0, (0, 0, 1)), (30, (0, 0, 1)), (60, (0, 1, 0))]),
        ("FOV", 0x121100, [(0, (0.7,))])]))
    doc, binc = read_glb(glb)
    check_references(doc, binc)
    assert report.models == ["cameraShape1"] and report.animations == ["CAM_cameraShape1"]
    cam = doc["cameras"][0]
    assert cam["type"] == "perspective" and cam["perspective"]["yfov"] == pytest.approx(
        2 * math.atan(math.tan(math.radians(20)) * 3 / 4))                  # the game's 40 degrees across, 4:3
    node = doc["nodes"][0]
    assert node["camera"] == 0 and node["translation"] == pytest.approx([0, 3, 1])     # Z mirrored

    def forward(q):                                                  # where a glTF camera looks: its -Z
        x, y, z, w = q
        return (-(2 * (x * z + w * y)), -(2 * (y * z - w * x)), -(1 - 2 * (x * x + y * y)))
    assert forward(node["rotation"]) == pytest.approx((0, -1, 0), abs=1e-6)
    a = doc["animations"][0]
    paths = {ch["target"]["path"]: a["samplers"][ch["sampler"]] for ch in a["channels"]}
    assert set(paths) == {"translation", "rotation"}
    assert values(doc, binc, paths["translation"]["output"])[-1] == pytest.approx((0, 6, 1))
    rot = paths["rotation"]
    assert [t for (t,) in values(doc, binc, rot["input"])] == pytest.approx([0, 1, 2])   # LOOK's and UP's keys
    assert forward(values(doc, binc, rot["output"])[-1]) == pytest.approx((0, 0, -1), abs=1e-6)  # +Z mirrored


def test_a_camera_without_a_move_and_a_one_axis_move():
    glb, _ = export(camera_file("TestCam1", 0.7, (2, 0.1, 2), (0, 0, 1), (0, 1, 0)))
    doc, binc = read_glb(glb)
    assert "animations" not in doc and doc["nodes"][0]["translation"] == pytest.approx([2, 0.1, -2])
    assert G.camera_rotation((0, 0, 1), (0, 1, 0)) == pytest.approx((0, 0, 0, 1), abs=1e-6)   # the game's +Z is -Z
    assert all(math.isfinite(v) for v in G.camera_rotation((0, 1, 0), (0, 1, 0)))  # looking straight up


# --------------------------------------------------------------------------- what a file holds, and Blender

def _server(monkeypatch, tmp_path, files):
    import importlib
    import sys
    from conftest import PORTAL
    sys.path.insert(0, str(PORTAL))
    server = importlib.import_module("decomp_portal_server")
    out, index = copied_game(tmp_path, files)
    monkeypatch.setattr(server.GA, "out_dir", lambda bin_dir=None: out)
    monkeypatch.setattr(server.GAME_FILES, "index", lambda: index)
    monkeypatch.setattr(server.GAME_FILES, "bin_dir", tmp_path)
    monkeypatch.setattr(server.BLENDER, "bin_dir", tmp_path)
    monkeypatch.setattr(server, "HOST", "127.0.0.1")
    return server, out, index


def _subtitle(text, language="English"):
    lang = language.encode()
    body = struct.pack("<I", len(lang)) + lang + b"\0" * (((len(lang) + 4) & ~3) - len(lang))
    utf16 = text.encode("utf-16-le") + b"\0\0"
    return p3d(chunk(media.SUBTITLE, body + struct.pack("<iiI", -1, -1, len(utf16) // 2) + utf16))


def test_what_a_file_holds(monkeypatch, tmp_path):
    import blender_export as BX
    rig = skeleton("rig", [("character_root", 0, (0, 0, 0)), ("pelvis", 0, (0, 1.0, 0))])
    tri = [(0, 0, 0), (1, 0, 0), (0, 1, 0)]
    tony = p3d(rig, skin_chunk(tri, [0, 1, 2], [(1.0, 0, 0)] * 3, [0] * 3, [0, 1]))
    moves = p3d(animation("GEN_WA_Bench_Order", [("pelvis", [(0, (0, 0, 0, 1)), (30, (0, 0.6, 0, 0.8))])]))
    files = {"cement.rcf/art/characters/pc/MCP_BlackSuitTony.p3d": tony,
             "cement.rcf/art/animations/WA_Sitting.p3d": moves,
             "frontend.rcf/frontend/prebuilt/TonyEndGameCam.p3d": camera_file("cam", 0.6, (0, 3, 0), (0, -1, 0), (0, 0, 1)),
             "sound2.rcf/art/subtitles/f/f7ca25caf057c712.p3d": _subtitle("You want a war with me?"),
             "sound2.rcf/art/sound/rsd/f/f7ca25caf057c712.rsd": b"RSD6PCM " + bytes(0x800)}
    assert BX.inspect(moves)["what"].startswith("1 animation (shown on Tony")
    assert BX.inspect(files["frontend.rcf/frontend/prebuilt/TonyEndGameCam.p3d"])["kind"] == "camera"
    info = BX.inspect(files["sound2.rcf/art/subtitles/f/f7ca25caf057c712.p3d"])
    assert info["kind"] == "subtitles" and not info["blender"] and info["lines"] == [
        {"language": "English", "text": "You want a war with me?"}]
    assert BX.inspect(b"P3D\xff" + bytes(8))["blender"] is False
    server, out, index = _server(monkeypatch, tmp_path, files)
    sent = []

    class Fake:
        client_address = ("127.0.0.1", 5)
        headers = {}
        _send_model = server.Handler._send_model

        def _send(self, code, body, ctype, extra=None):
            sent.append((code, ctype, body))

        def _json(self, obj, code=200):
            sent.append((code, "json", obj))

    def ask(what, **q):
        server.Handler.get_game_file_preview(Fake(), what, lambda k, d="": q.get(k, d))
        return sent[-1]
    got = ask("inspect", version="pc", path="sound2.rcf/art/subtitles/f/f7ca25caf057c712.p3d")[2]
    assert got["sound"] == "sound2.rcf/art/sound/rsd/f/f7ca25caf057c712.rsd"           # the sound it goes with
    got = ask("subtitles", version="pc", path="sound2.rcf/art/sound/rsd/f/f7ca25caf057c712.rsd")[2]
    assert got["lines"][0]["text"] == "You want a war with me?"
    assert ask("subtitles", version="pc", path="sound2.rcf/art/sound/rsd/0/nothing.rsd")[2]["lines"] == []
    # an animation file comes with Tony to show it on; a camera file is a camera
    code, ctype, body = ask("model", version="pc", path="cement.rcf/art/animations/WA_Sitting.p3d")
    doc, _ = read_glb(body)
    assert code == 200 and [a["name"] for a in doc["animations"]] == ["GEN_WA_Bench_Order"]
    assert any(n.get("skin") is not None for n in doc["nodes"])
    code, _, body = ask("model", version="pc", path="frontend.rcf/frontend/prebuilt/TonyEndGameCam.p3d")
    assert code == 200 and read_glb(body)[0]["cameras"][0]["name"] == "cam"


def test_open_in_blender(monkeypatch, tmp_path):
    import blender_export as BX
    server, out, index = _server(monkeypatch, tmp_path, city_files())
    launched = []
    monkeypatch.setattr(server.BX, "open_in_blender", lambda exe, files, save, work: launched.append((exe, files, save)))
    sent = []

    class Fake:
        client_address = ("127.0.0.1", 5)
        headers = {}
        _local_only = server.Handler._local_only

        def _json(self, obj, code=200):
            sent.append((code, obj))

    def post(**body):
        server.Handler.post_game_files_open_in_blender(Fake(), body)
        return sent[-1]
    monkeypatch.setattr(server.BX, "find_blender", lambda bin_dir: None)
    code, obj = post(version="pc", path="cement.rcf/art/box.p3d")
    assert code == 404 and obj["need_blender"] and not launched
    exe = tmp_path / "Blender 4.2" / "blender.exe"
    exe.parent.mkdir()
    exe.write_bytes(b"MZ")
    monkeypatch.setattr(server.BX, "find_blender", lambda bin_dir: exe)
    code, obj = post(version="pc", path="cement.rcf/art/box.p3d")
    assert code == 200 and obj["saved"].endswith("Opened/box.blend")
    glb = launched[-1][1][0]
    assert glb.name == "box.glb" and read_glb(glb.read_bytes())[0]["nodes"][0]["name"] == "box"
    code, obj = post(version="pc", area="z04/a_01")
    assert code == 200 and launched[-1][1][0].name == "a_01.glb"
    assert post(version="pc", city=True)[0] == 404                                     # nothing exported yet
    (tmp_path / "blender" / "PC").mkdir(parents=True, exist_ok=True)
    for n in ("a_01", "b_02"):
        (tmp_path / "blender" / "PC" / f"{n}.glb").write_bytes(b"glTF")
    code, obj = post(version="pc", city=True)
    assert code == 200 and obj["files"] == 2 and launched[-1][2].name == "PC city.blend"
    Fake.client_address = ("192.168.1.9", 5)
    assert post(version="pc", city=True)[0] == 403
    # where Blender is, when it isn't found
    assert BX.remember_blender(tmp_path, str(tmp_path / "nope.exe"))
    assert BX.remember_blender(tmp_path, str(exe.parent)) is None
    monkeypatch.setattr(BX.shutil, "which", lambda name: None)
    assert BX.find_blender(tmp_path) == exe


def test_the_blender_script_imports_and_saves(tmp_path, monkeypatch):
    import blender_export as BX
    started = []
    monkeypatch.setattr(BX.subprocess, "Popen", lambda args, **kw: started.append(args))
    BX.open_in_blender(tmp_path / "blender.exe", [tmp_path / "a.glb", tmp_path / "b.glb"], tmp_path / "city.blend",
                       tmp_path / "_scripts")
    args = started[-1]
    assert args[0].endswith("blender.exe") and args[1] == "--python"
    script = open(args[2], encoding="utf-8").read()
    compile(script, "open_in_blender.py", "exec")                                       # valid Python for Blender
    assert "import_scene.gltf" in script and "save_as_mainfile" in script and "a.glb" in script
