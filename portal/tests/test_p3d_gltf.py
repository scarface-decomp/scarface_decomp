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
    assert sorted(p.name for p in out.iterdir()) == ["a_01.glb", "b_02.glb", "ocean.glb"]      # one sea for both
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
    assert sorted(p.name for p in (tmp_path / "blender" / "PC").iterdir()) == ["a_01.glb", "b_02.glb", "made_by.txt",
                                                                                  "made_with.json", "ocean.glb",
                                                                                  "shop_01 (inside).glb"]
    assert BX.city_current(tmp_path / "blender" / "PC")                       # made by this exporter
    assert BX.city_made(tmp_path / "blender" / "PC") == {"hour": None, "weather": "clear"}     # the sky as stored
    (tmp_path / "blender" / "PC" / "made_by.txt").unlink()
    assert not BX.city_current(tmp_path / "blender" / "PC")                   # one from before: export again
    assert job.status["written"] == 3 and job.status["done"] == 3 and not job.status["running"]
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


def test_blender_is_only_offered_what_this_copy_can_show(monkeypatch, tmp_path):
    """Open in Blender isn't offered for a file it would answer "nothing to export" for. A copy that keeps from
    a version only what the others don't have (The PC first) leaves it without Tony: its animations borrow
    him from another version, and without him anywhere the page says why instead of showing the button."""
    import blender_export as BX
    rig = skeleton("rig", [("character_root", 0, (0, 0, 0)), ("pelvis", 0, (0, 1.0, 0))])
    tri = [(0, 0, 0), (1, 0, 0), (0, 1, 0)]
    tony = p3d(rig, skin_chunk(tri, [0, 1, 2], [(1.0, 0, 0)] * 3, [0] * 3, [0, 1]))
    moves = p3d(animation("XB_Only_Dance", [("pelvis", [(0, (0, 0, 0, 1)), (30, (0, 0.6, 0, 0.8))])]))
    empty = p3d(chunk(0x10000, text("nothing_in_it") + struct.pack("<II", 0, 0)))      # a mesh with no geometry
    out, index = copied_game(tmp_path, {"cement.rcf/art/characters/pc/MCP_BlackSuitTony.p3d": tony})
    place = "Exclusive to Xbox/art/animations/XB.p3d"
    (out / place).parent.mkdir(parents=True)
    (out / place).write_bytes(moves)
    index["versions"]["xbox"] = {"files": [["cement.rcf/art/animations/XB.p3d", len(moves), "s", "only", place, None, 1]]}
    assert BX.stand_in(out, index, "xbox").name == "MCP_BlackSuitTony.p3d"              # the PC's Tony
    assert BX.cant_show(out, index, "xbox", "cement.rcf/art/animations/XB.p3d", moves) == ""
    glb, _ = BX.model_glb(out, index, "xbox", "cement.rcf/art/animations/XB.p3d", moves)
    assert [a["name"] for a in read_glb(glb)[0]["animations"]] == ["XB_Only_Dance"]
    del index["versions"]["pc"]
    assert "Tony's model isn't among your copied files" in BX.cant_show(out, index, "xbox", "x/XB.p3d", moves)
    assert BX.cant_show(out, index, "pc", "x/tony.p3d", tony) == ""
    why = BX.cant_show(out, index, "xbox", "x/empty.p3d", empty)
    assert BX.inspect(empty)["blender"] and "nothing to show from the Xbox's copy" in why
    assert BX.cant_show(out, index, "pc", "x/big.p3d", empty + bytes(BX.CHECK_MAX)) == ""   # not tried ahead of time


def test_how_much_of_the_city_each_version_has(tmp_path):
    import blender_export as BX
    out, index = copied_game(tmp_path, city_files())
    index["versions"]["xbox"] = {"files": [["cement.rcf/packages/z04/s_09_shell.p3d", 10, "s", "only", "Exclusive to Xbox/s.p3d", None, 1],
                                           ["cement.rcf/packages/z04/t_10_shell.p3d", 10, "s", "changed", "", None, 1]]}
    index["versions"]["ps2"] = {"files": []}
    assert BX.city_counts(out, index) == {"pc": 3, "xbox": 1, "ps2": 0}                 # a file not copied isn't an area


def test_open_in_blender(monkeypatch, tmp_path):
    import blender_export as BX
    server, out, index = _server(monkeypatch, tmp_path, city_files())
    launched = []
    monkeypatch.setattr(server.BX, "open_in_blender", lambda exe, files, save, work, fps=30: launched.append((exe, files, save)))
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
    # the import waits for Blender's window and runs inside it (a skeleton needs one), without the helper ball
    assert "bpy.app.timers.register(later" in script and "temp_override" in script
    assert '"disable_bone_shape": True' in script and "TEMPERANCE" in script and "read_homefile" not in script
    assert ".import-error.txt" in script and "if SAVE and shown" in script
    # people stand in their rest pose (Blender would lay the library's first animation, a chicken's, on one
    # of them), the animations are kept, and the far-away copy of a model is hidden
    assert "tidy(scene)" in script and "animation_data.action = None" in script and "use_fake_user = True" in script
    assert '("_low", "_high")' in script and "hide_set(True)" in script
    compile(script, "open_in_blender.py", "exec")


# --------------------------------------------------------------------------- props: how they start, and what they become

def state_prop(name, states):
    """A State Prop Data chunk (0x0802000D): states as (state name, [(part, shown)])."""
    kids = chunk(0x08020008, text("name") + text(name))
    for sname, shown in states:
        vis = b"".join(chunk(0x08020002, text(p) + struct.pack("<I", int(on))) for p, on in shown)
        kids += chunk(0x0802000E, text(sname) + bytes(36), vis)
    return chunk(0x0802000D, struct.pack("<I", 4) + text(name) + text(name) + struct.pack("<II", 1, len(states)), kids)


def bin_prop():
    rig = skeleton("bin", [("bin", 0, (0, 0, 0)), ("binInstance", 0, (0, 0, 0)), ("binLOD", 1, (0, 0, 0)),
                           ("binDamage", 0, (0, 0, 0))])
    parts = [("binInstanceShape", 1, 1), ("binLODShape", 1, 2), ("binDamageShape", 1, 3)]
    return p3d(rig, mesh("binInstanceShape"), mesh("binLODShape"), mesh("binDamageShape"),
               composite("bin", "bin", parts),
               state_prop("bin", [("idle", [("binInstanceShape", True), ("binLODShape", True), ("binDamageShape", False)]),
                                  ("final", [("binInstanceShape", False), ("binLODShape", False), ("binDamageShape", True)])]),
               chunk(0x8800005, text("bin") + text("bin")))


def shapes_under(doc, top):
    out, todo = [], [top]
    while todo:
        n = doc["nodes"][todo.pop()]
        if "mesh" in n:
            out.append(n["name"])
        todo += n.get("children", [])
    return sorted(out)


def test_a_prop_comes_in_as_it_starts_and_its_broken_self_beside_it():
    glb, report = export(bin_prop())
    doc, binc = read_glb(glb)
    check_references(doc, binc)
    assert report.models == ["bin", "bin (final)"]
    tops = {doc["nodes"][i]["name"]: i for i in doc["scenes"][0]["nodes"]}
    assert shapes_under(doc, tops["bin"]) == ["binInstanceShape"]              # not the far-away or the dented one
    assert shapes_under(doc, tops["bin (final)"]) == ["binDamageShape"]


def test_a_placed_prop_in_a_map_is_whole_and_detailed():
    glb, report = export(area("w_a_shell", objects=[("bin", [record(1.0, 0.0, 1.0)])]), lib=[("x_region_D.p3d", bin_prop())],
                         map_mode=True)
    doc, _ = read_glb(glb)
    placed = next(i for i, n in enumerate(doc["nodes"]) if n["name"] == "bin")
    assert report.placed == 1 and shapes_under(doc, placed) == ["binInstanceShape"]


def test_lod_parts():
    assert G.lod_parts(["treeInstanceShape", "treeLODShape", "fenceBushALODShape1"]) == {"treelodshape", "fencebushalodshape1"}
    assert G.lod_parts(["farHillLODShape"]) == set()                       # nothing else to show: kept
    assert G.lod_parts(["clodhopperShape"]) == set()


def test_the_city_on_several_cores_is_the_same(tmp_path, monkeypatch):
    import blender_export as BX
    import game_assets as GA
    out, index = copied_game(tmp_path, city_files())
    monkeypatch.setattr(GA, "out_dir", lambda bin_dir=None: out)
    assert BX.workers_wanted(False) == 1 and 1 <= BX.workers_wanted(True) <= 8
    made = {}
    for cores, n in ((False, 1), (True, 2)):
        monkeypatch.setattr(BX, "workers_wanted", lambda use_cores=True, n=n: n)
        job = BX.CityJob(tmp_path)
        job.use_cores = lambda cores=cores: cores
        assert job.start("pc", index) is None
        job._thread.join(60)
        assert job.status["workers"] == n and job.status["written"] == 3 and job.status["done"] == 3
        made[n] = {p.name: p.read_bytes() for p in (tmp_path / "blender" / "PC").glob("*.glb")}
        assert BX.city_current(tmp_path / "blender" / "PC")
    assert made[1] == made[2] and sorted(made[2]) == ["a_01.glb", "b_02.glb", "ocean.glb", "shop_01 (inside).glb"]
    assert not list((tmp_path / "blender" / "_scripts").glob("city_job_*.json"))       # tidied up


# ---- props whose model is kept in another area's file ----------------------------------------------------------

def test_files_naming_takes_the_file_with_the_model_not_one_that_only_places_it(tmp_path):
    import blender_export as BX
    (tmp_path / "next_door_shell.p3d").write_bytes(b"..woodcrateA..woodcrateAInstanceShape..")
    (tmp_path / "far_shell.p3d").write_bytes(b"..modelname\x00woodcratea..")
    (tmp_path / "other.p3d").write_bytes(b"nothing here")
    got = BX._files_naming(sorted(tmp_path.iterdir()), {"woodcratea": 3})
    assert [n for n, _d in got] == ["next_door_shell.p3d"]


def test_files_naming_falls_back_to_a_mention_and_skips_files_already_in(tmp_path):
    import blender_export as BX
    (tmp_path / "inside_dzone.p3d").write_bytes(b"..umbrellastanda..")
    (tmp_path / "mine_shell.p3d").write_bytes(b"..umbrellastanda..")
    got = BX._files_naming([[p.name, str(p)] for p in sorted(tmp_path.iterdir())], ["umbrellastanda"],
                           skip=["MINE_shell.p3d"])
    assert [n for n, _d in got] == ["inside_dzone.p3d"]
    assert BX._files_naming([tmp_path / "gone.p3d"], ["x"]) == []


def test_an_area_is_made_again_with_the_files_that_have_its_missing_props(tmp_path, monkeypatch):
    import blender_export as BX
    (tmp_path / "next_shell.p3d").write_bytes(b"crateAInstanceShape")
    seen = []

    class Lib:
        def __init__(self, parsed=None):
            self.names = []

        def add(self, name, data, main=True, keep=True):
            self.names.append((name, main))

    def export(lib, map_mode=False):
        seen.append(lib.names)
        report = G.Report()
        if ("next_shell.p3d", False) not in lib.names:
            report.unplaced["cratea"] = 2
        return b"glb%d" % len(seen), report

    monkeypatch.setattr(BX.P3G, "Library", Lib)
    monkeypatch.setattr(BX.P3G, "export", export)
    glb, report = BX.area_from_files([("a_shell.p3d", b"")], [("Common.p3d", b"")], None, [tmp_path / "next_shell.p3d"])
    assert glb == b"glb2" and not report.unplaced
    assert seen[1] == [("a_shell.p3d", True), ("Common.p3d", False), ("next_shell.p3d", False)]
    seen.clear()
    glb, _r = BX.area_from_files([("a_shell.p3d", b"")], [("Common.p3d", b"")], None, [])
    assert glb == b"glb1" and len(seen) == 1


# ---- a place at each stage of the story, and the buildings' insides ---------------------------------------------

def staged_city():
    z, d = "cement.rcf/packages/z04/", "cement.rcf/packages/dzones/"
    return {z + "m_01_shell_TS0.p3d": area("w_wrecked"), z + "m_01_shell_TS1.p3d": area("w_rebuilt"),
            z + "m_01_detailB.p3d": area("w_always"), z + "m_01_detail_TS0.p3d": area("w_rubble"),
            z + "c_02_shell.p3d": area("w_club", objects=[("treep", [record(5.0, 0.0, 5.0)])]),
            z + "x_region_D.p3d": region("x", 1.0)[1],
            d + "town_club_dzone.p3d": area("w_seats", objects=[("treep", [record(5.0, 0.0, 5.5)])]),
            d + "town_club01owned_dzone.p3d": area("w_owned", objects=[("treep", [record(5.0, 0.0, 5.5)])]),
            d + "town_far_dzone.p3d": area("w_far", objects=[("treep", [record(900.0, 0.0, 900.0)])])}


def test_a_place_the_story_changes_is_one_stage_at_a_time(tmp_path):
    import blender_export as BX
    out, index = copied_game(tmp_path, staged_city())
    found = {a["key"]: a for a in BX.areas(out, index, "pc")}
    names = lambda key: sorted(f.rsplit("/", 1)[-1] for f in found[key]["files"])
    assert names("z04/m_01") == ["m_01_detailB.p3d", "m_01_detail_TS0.p3d", "m_01_shell_TS1.p3d"]     # as it ends up
    assert names("z04/m_01@TS0") == ["m_01_detailB.p3d", "m_01_detail_TS0.p3d", "m_01_shell_TS0.p3d"]
    assert found["z04/m_01"]["city"] and not found["z04/m_01@TS0"]["city"]
    _glb, report = BX.area_glb(out, index, "pc", "z04/m_01")
    assert "w_rebuilt" in report.models and "w_wrecked" not in report.models
    assert "w_wrecked" in BX.area_glb(out, index, "pc", "z04/m_01@TS0")[1].models


def test_the_city_has_each_inside_once_and_an_area_alone_comes_with_its_own(tmp_path):
    import blender_export as BX
    out, index = copied_game(tmp_path, staged_city())
    city = [a["file"] for a in BX.city_areas(out, index, "pc")]
    assert city == ["c_02", "m_01", "town_club (inside)", "town_far (inside)"]         # not the shop owned as well
    _glb, alone = BX.area_glb(out, index, "pc", "z04/c_02")
    assert sorted(alone.models) == ["w_club", "w_seats"] and alone.placed == 2         # the club with its seats
    _glb, in_city = BX.area_glb(out, index, "pc", "z04/c_02", insides=False)
    assert in_city.models == ["w_club"]


def test_blender_script_is_whole_and_a_saved_city_is_reused(tmp_path):
    import ast
    import os
    import blender_export as BX
    src = BX.OPEN_SCRIPT % {"files": ["a.glb", "b.glb"], "save": "city.blend", "fps": 30}
    ast.parse(src)
    assert "use_global_undo = False" in src and "bringing in area {} of {}" in src
    glb, blend = tmp_path / "a.glb", tmp_path / "city.blend"
    glb.write_bytes(b"g")
    assert not BX.saved_scene(blend, [glb])                       # not made yet
    blend.write_bytes(b"b")
    os.utime(glb, (1000, 1000))
    assert BX.saved_scene(blend, [glb])
    os.utime(glb, (4e9, 4e9))                                     # the city was exported again since
    assert not BX.saved_scene(blend, [glb])


def test_a_picture_the_game_lacks_is_dark_not_white():
    lib = G.Library()
    lib.add("car.p3d", p3d(mesh("body", shader="glassy")), main=True)
    b = G.Builder(lib)
    b.report.missing_textures.add("gone.bmp")
    import p3d_gltf
    real = p3d_gltf.shader_from_name
    p3d_gltf.shader_from_name = lambda name: {"name": name, "pddi": "", "translucent": False,
                                              "textures": [("TEX", "gone.bmp")], "ints": {"BLMD": 1}, "floats": {}, "colours": {}}
    try:
        mat = b.g.doc["materials"][b.material("glassy")]
    finally:
        p3d_gltf.shader_from_name = real
    assert mat["pbrMetallicRoughness"]["baseColorFactor"] == G.MISSING_GLASS and mat["alphaMode"] == "BLEND"


# --------------------------------------------------------------------------- lights

from test_p3d import decay, light  # noqa: E402


def sub(position=None, direction=None, shadows=1, rng=None, illumination=None, cone=None):
    """A light's sub-chunks."""
    out = b""
    if direction is not None:
        out += chunk(0x13001, struct.pack("<3f", *direction))
    if position is not None:
        out += chunk(0x13002, struct.pack("<3f", *position))
    if cone is not None:
        out += chunk(0x13003, struct.pack("<4f", *cone))
    out += chunk(0x13004, struct.pack("<I", shadows))
    if rng is not None:
        out += rng
    if illumination is not None:
        out += chunk(0x13008, struct.pack("<I", illumination))
    return out


def light_group(name, lights, kind=None, controllers=()):
    """A Light Group (0x2380) and, with a kind, its record (0x8800007)."""
    out = chunk(0x2380, text(name) + struct.pack("<I", len(lights)) + b"".join(text(n) for n in lights))
    if kind is not None:
        out += chunk(0x8800007, text(name) + text(name) + struct.pack("<II", kind, len(controllers))
                     + b"".join(text(c) for c in controllers))
    return out


def lit_area(name, *extra):
    rig = skeleton(name, [(name, 0, (0, 0, 0)), ("collapsedMesh_0", 0, (0, 0, 0))])
    return p3d(rig, mesh("collapsedMesh_0"), composite(name, name, [("collapsedMesh_0", 1, 1)]), world_geo(name), *extra)


def minus_z(q):
    """Where a node's -Z points after rotation q (glTF lights shine along their -Z)."""
    x, y, z, w = q
    return (-(2 * (x * z + w * y)), -(2 * (y * z - w * x)), -(1 - 2 * (x * x + y * y)))


def node_named(doc, name):
    return next(n for n in doc["nodes"] if n["name"] == name)


def test_a_map_area_carries_its_lights():
    lights = (
        light("lamp_a", 1, 0xFFFF8000, kids=sub((10, 3, -20), rng=decay(1, (2, 2, 2), (12.5, 7, 7))))
        + light("lamp_box", 1, 0xFF000000, kids=sub((0, 0, 0), rng=decay(2, (1, 1, 1), (4, 9, 6), rotation=0.5)))
        + light("sun", 2, 0xFF1F2D30, kids=sub((0, 0, 0), direction=(0, -0.788, -0.616), rng=decay(0, (0,) * 3, (0,) * 3)))
        + light("room_sun", 2, 0xFF808080, kids=sub((5, 2, 5), direction=(0, -1, 0), rng=decay(2, (1, 1, 1), (3, 3, 3))))
        + light("room_ambient", 0, 0xFF232530, kids=sub((5, 2, 5), rng=decay(1, (1,) * 3, (4,) * 3)))
        + light("switched_off", 1, 0xFFFFFFFF, enabled=0, kids=sub((1, 1, 1)))
        + light("darkener", 1, 0xFFFFFFFF, kids=sub((1, 1, 1), illumination=2))
        + light("spotty", 3, 0xFFFFFFFF, kids=sub((2, 2, 2), direction=(1, 0, 0), cone=(0.3, 0.6, 1.0, 9.0),
                                                   rng=decay(1, (1,) * 3, (9,) * 3))))
    groups = (light_group("interior_lights", ["lamp_a", "room_sun", "room_ambient", "lamp_box"], kind=3)
              + light_group("loose", ["sun", "switched_off", "darkener", "spotty"]))
    glb, report = export(lit_area("w_lit", lights, groups), map_mode=True)
    doc, binc = read_glb(glb)
    check_references(doc, binc)
    assert report.lights == 8 and report.gltf_lights == 4
    assert "KHR_lights_punctual" in doc["extensionsUsed"]
    table = doc["extensions"]["KHR_lights_punctual"]["lights"]

    def gl(name):
        n = node_named(doc, name)
        return n, (table[n["extensions"]["KHR_lights_punctual"]["light"]] if "extensions" in n else None)

    # where they hang: <file> lights > the light group > the light; the group's kind in extras
    top = node_named(doc, "main0 lights")
    assert top in [doc["nodes"][i] for i in node_named(doc, "main0")["children"]]
    group = node_named(doc, "interior_lights")
    assert group["extras"] == {"lightGroupKind": 3, "lightGroupRecord": "interior_lights"}
    assert [doc["nodes"][i]["name"] for i in group["children"]] == ["lamp_a", "room_sun", "room_ambient", "lamp_box"]
    assert "extras" not in node_named(doc, "loose")                   # a group with no record
    # a point light: colour 0..1, placed like the geometry (Z mirrored), range = the sphere's first number
    n, lt = gl("lamp_a")
    assert lt == {"name": "lamp_a", "type": "point", "color": [1.0, 0.502, 0.0], "intensity": G.POINT_CANDELA,
                  "range": 12.5}
    assert n["translation"] == pytest.approx([10, 3, 20]) and "rotation" not in n
    assert n["extras"]["lightGroupKind"] == 3 and n["extras"]["castsShadows"] is True
    assert n["extras"]["decayRange"] == {"shape": "sphere", "inner": [2, 2, 2], "outer": [12.5, 7, 7]}
    assert gl("lamp_box")[1]["range"] == 9.0                           # a box: its largest outer size
    assert gl("lamp_box")[0]["extras"]["decayRange"]["rotation"] == 0.5
    # the city-wide directional light (no decay range): a glTF directional light shining the way it says
    n, lt = gl("sun")
    assert lt["type"] == "directional" and lt["intensity"] == G.DIRECTIONAL_LUX and "range" not in lt
    assert lt["color"] == [round(0x1F / 255, 4), round(0x2D / 255, 4), round(0x30 / 255, 4)]
    want = (0, -0.788, 0.616)                                          # Z mirrored
    norm = math.sqrt(sum(v * v for v in want))
    assert minus_z(n["rotation"]) == pytest.approx([v / norm for v in want], abs=1e-4)
    # a directional light that lights only its decay range, an ambient light, one switched off and one that
    # takes light away: empty nodes with their settings in extras
    for name, kind in (("room_sun", "directional"), ("room_ambient", "ambient"), ("switched_off", "point"),
                       ("darkener", "point")):
        n, lt = gl(name)
        assert lt is None and n["extras"]["lightType"] == kind
    assert node_named(doc, "room_sun")["extras"]["decayRange"]["shape"] == "box"
    assert minus_z(node_named(doc, "room_sun")["rotation"]) == pytest.approx((0, -1, 0), abs=1e-6)
    assert node_named(doc, "room_ambient")["extras"]["color"] == [round(0x23 / 255, 4), round(0x25 / 255, 4),
                                                                  round(0x30 / 255, 4)]
    assert node_named(doc, "switched_off")["extras"]["enabled"] is False
    assert node_named(doc, "darkener")["extras"]["illumination"] == "takes light away"
    # a spot light keeps glTF's own cone; the game's cone numbers go in extras
    n, lt = gl("spotty")
    assert lt["type"] == "spot" and lt["spot"] == {} and lt["range"] == 9.0
    assert n["extras"]["spotCone"] == {"angles": [0.3, 0.6], "falloff": 1.0, "range": 9.0}
    assert minus_z(n["rotation"]) == pytest.approx((1, 0, 0), abs=1e-6)
    assert any("8 light(s), 4 of them as glTF lights" in line for line in report.lines())


def test_lights_outside_groups_and_files_without_lights():
    glb, report = export(lit_area("w_one", light("lonely", 1, 0xFF0000FF, kids=sub((1, 2, 3)))), map_mode=True)
    doc, _ = read_glb(glb)
    n = node_named(doc, "lonely")
    assert n in [doc["nodes"][i] for i in node_named(doc, "main0 lights")["children"]]
    assert "range" not in doc["extensions"]["KHR_lights_punctual"]["lights"][0]      # no decay range: no range
    doc, _ = read_glb(export(lit_area("w_none"), map_mode=True)[0])
    assert "extensions" not in doc and not any(n["name"].endswith(" lights") for n in doc["nodes"])
    # not a map export: no lights
    doc, _ = read_glb(export(p3d(mesh("box"), light("lonely", 1, 0xFF0000FF, kids=sub((1, 2, 3)))))[0])
    assert "extensions" not in doc and [n["name"] for n in doc["nodes"]] == ["box"]


# --------------------------------------------------------------------------- the daylight at an hour

ISLAND_SUN = ([0, 40, 60, 90, 120, 180, 207, 210, 229, 234, 240],
              [0x1F2D30, 0x253134, 0x3C4038, 0x5E593F, 0x636148, 0x635C36, 0x3B2919, 0x372316, 0x272927, 0x232B2B,
               0x1F2D30])


def lite_file(stepped=False):
    """A low-detail city file whose sun is moved through the day by a LITE animation, as in miami_lod.p3d."""
    frames, colours = ISLAND_SUN
    mode = chunk(0x121110, struct.pack("<II", 0, 0 if stepped else 0xFFFFFFFF))
    clr = chunk(0x121109, struct.pack("<I", 0) + b"CLR\0" + struct.pack(f"<I{len(frames)}H{len(frames)}I", len(frames),
                                                                       *frames, *[0xFF000000 | c for c in colours]),
                mode)
    dirs = [(0, -0.788, -0.616), (-0.473, -0.743, 0.473), (0, -0.788, -0.616)]
    dr = chunk(0x121104, struct.pack("<I", 0) + b"DIR\0" + struct.pack("<I3H", 3, 0, 120, 240)
               + b"".join(struct.pack("<3f", *d) for d in dirs))
    anim = chunk(0x121000, struct.pack("<I", 0) + text("LITE_MiamiSunShape") + b"LITE" + struct.pack("<ffI", 241.0, 30.0, 1),
                 chunk(0x121002, struct.pack("<II", 0, 1),
                       chunk(0x121001, struct.pack("<I", 0) + text("MiamiSunShape") + struct.pack("<II", 0, 2), clr + dr)))
    fc = chunk(0x121201, struct.pack("<I", 1) + text("LITE_MiamiSunShape") + b"LITEANIM" + struct.pack("<fI", 0, 1)
               + text("MiamiSunShape") + text("LITE_MiamiSunShape"))
    sun = light("MiamiSunShape", 2, 0xFF1F2D30, kids=sub((0, 0, 0), direction=(0, -0.788, -0.616)))
    fill = light("MiamiFillShape", 2, 0xFF060606, kids=sub((0, 0, 0), direction=(-0.863, 0.087, 0.498)))
    groups = light_group("zone_lights", ["MiamiSunShape", "MiamiFillShape"], kind=0, controllers=["LITE_MiamiSunShape"])
    return lit_area("low_LOD", sun, fill, groups, fc, anim)


def sun_at(hour, stepped=False):
    lib = G.Library()
    lib.add("miami_lod.p3d", lite_file(stepped), main=True)
    doc, _ = read_glb(G.export(lib, map_mode=True, hour=hour)[0])
    n = node_named(doc, "MiamiSunShape")
    return n, doc["extensions"]["KHR_lights_punctual"]["lights"][n["extensions"]["KHR_lights_punctual"]["light"]]


def rgb(c):
    return [round(((c >> s) & 0xFF) / 255, 4) for s in (16, 8, 0)]


def test_without_an_hour_the_lights_are_as_stored():
    n, lt = sun_at(None)
    assert lt["color"] == rgb(0x1F2D30) and "hour" not in n["extras"]
    assert minus_z(n["rotation"]) == pytest.approx((0, -0.788, 0.616), abs=1e-3)


def test_the_daylight_at_noon_and_between_keys():
    n, lt = sun_at(12)                                                 # frame 120: a key
    assert lt["color"] == rgb(0x636148) and n["extras"]["hour"] == 12
    want = (-0.473, -0.743, -0.473)                                    # Z mirrored
    norm = math.sqrt(sum(v * v for v in want))
    assert minus_z(n["rotation"]) == pytest.approx([v / norm for v in want], abs=1e-3)
    assert sun_at(2)[1]["color"] == rgb(0x222F32)                      # frame 20, halfway from 1f2d30 to 253134
    assert sun_at(24)[1]["color"] == rgb(0x1F2D30)
    assert sun_at(2, stepped=True)[1]["color"] == rgb(0x1F2D30)        # not interpolated: the key before
    lib = G.Library()
    lib.add("miami_lod.p3d", lite_file(), main=True)
    doc, _ = read_glb(G.export(lib, map_mode=True, hour=12)[0])
    fill = node_named(doc, "MiamiFillShape")                           # no frame controller: as stored
    assert "hour" not in fill["extras"]
    assert doc["extensions"]["KHR_lights_punctual"]["lights"][fill["extensions"]["KHR_lights_punctual"]["light"]][
        "color"] == rgb(0x060606)


def test_hour_on_the_command_line(tmp_path, capsys):
    (tmp_path / "miami_lod.p3d").write_bytes(lite_file())
    out = tmp_path / "city.glb"
    assert G.main([str(out), str(tmp_path / "miami_lod.p3d"), "--map", "--hour", "12"]) == 0
    doc, _ = read_glb(out.read_bytes())
    assert node_named(doc, "MiamiSunShape")["extras"]["hour"] == 12
    assert "2 light(s), 2 of them as glTF lights" in capsys.readouterr().out
    assert G.main([str(out), str(tmp_path / "miami_lod.p3d"), "--map", "--hour", "25"]) == 1
    assert G.main([str(out), str(tmp_path / "miami_lod.p3d"), "--hour", "12"]) == 1
    assert "--hour is for --map" in capsys.readouterr().err


# --------------------------------------------------------------------------- the draw-order key, strips without indices

def test_the_draw_order_key_goes_in_the_meshs_extras():
    def keyed(name, key):
        return chunk(0x10000, text(name) + struct.pack("<II", 0, 1),
                     prim_group("sky", 1, 0x2001, QUAD, [0, 1, 2, 3]) + chunk(0x122000, struct.pack("<If", 0, key)))
    rig = skeleton("sky", [("sky", 0, (0, 0, 0))])
    parts = [("skyboxShape", 1, 0), ("skybox17Shape", 1, 0), ("over", 1, 0), ("plain", 1, 0)]
    data = p3d(rig, keyed("skyboxShape", 1.0), keyed("skybox17Shape", 0.3), keyed("over", 1.5), mesh("plain"),
               composite("sky", "sky", parts), chunk(0x8800002, text("sky") + text("sky")))
    doc, _ = read_glb(export(data)[0])
    extras = {m["name"]: m.get("extras") for m in doc["meshes"]}
    assert extras == {"skyboxShape": {"drawOrder": 1.0}, "skybox17Shape": {"drawOrder": 0.3},
                      "over": {"drawOrder": 1.0}, "plain": None}                 # clamped to 0..1, as the game does
    # a model placed many times is still written once, keyed or not
    keyed_tree = p3d(skeleton("treeP", [("treeP", 0, (0, 0, 0))]), keyed("treePShape", 0.3),
                     composite("treeP", "treeP", [("treePShape", 1, 0)]))
    for tree in (keyed_tree, region("x", 1.0)[1]):
        shell = area("w_trees", objects=[("treep", [record(1.0, 0.0, 1.0), record(5.0, 0.0, 5.0)])])
        doc, _ = read_glb(export(shell, lib=[("x_region_D.p3d", tree)], map_mode=True)[0])
        assert [m["name"] for m in doc["meshes"]] == ["collapsedMesh_0", "treePShape"]


def test_a_strip_with_no_index_list():
    head = struct.pack("<I", 0) + text("sky") + struct.pack("<9I", 1, 0x2001, 4, 0, 0, 0, 1, 0, 0)
    flat = [v for p in QUAD for v in p]
    data = p3d(chunk(0x10020, head, chunk(0x10005, struct.pack("<I12f", 4, *flat))))
    g = G.geometry(data, G.p3d.read_tree(data)[0])
    assert g.triangles == [(0, 1, 2), (2, 1, 3)]


# --------------------------------------------------------------------------- one weather at a time

def with_chunks(data, *more):
    """A made-up .p3d with more chunks at the end."""
    body = data[12:] + b"".join(more)
    return b"P3D\xff" + struct.pack("<II", 12, 12 + len(body)) + body


def weather_file():
    """A low-detail city file with the clear weather's daylight (kind 0) and the rain's (kind 1)."""
    sun = light("MiamiSunShape", 2, 0xFF1F2D30, kids=sub((0, 0, 0), direction=(0, -0.788, -0.616)))
    ambient = light("MiamiAmbientShape", 0, 0xFF232530, kids=sub((0, 0, 0)))
    rainy = light("MiamiRainySunShape", 2, 0xFF101418, kids=sub((0, 0, 0), direction=(0, -1, 0)))
    groups = (light_group("zone_lights", ["MiamiSunShape", "MiamiAmbientShape"], kind=0)
              + light_group("zone_rainlights", ["MiamiRainySunShape"], kind=1))
    return lit_area("low_LOD", sun, ambient, rainy, groups)


def daylight_export(**kw):
    lib = G.Library()
    lib.add("miami_lod.p3d", weather_file(), main=True)
    glb, report = G.export(lib, map_mode=True, **kw)
    doc, _ = read_glb(glb)
    return doc, report


def test_one_weather_at_a_time():
    doc, report = daylight_export()                                    # clear weather unless asked: as the game starts
    assert "extensions" in node_named(doc, "MiamiSunShape") and report.gltf_lights == 1
    rainy = node_named(doc, "MiamiRainySunShape")
    assert "extensions" not in rainy                                   # kept as data: an empty node with extras
    assert rainy["extras"]["dataOnly"] is True and rainy["extras"]["lightType"] == "directional"
    assert node_named(doc, "zone_lights")["extras"] == {"lightGroupKind": 0, "lightGroupRecord": "zone_lights",
                                                        "weather": "clear"}
    assert node_named(doc, "zone_rainlights")["extras"] == {"lightGroupKind": 1, "lightGroupRecord": "zone_rainlights",
                                                            "weather": "rain", "dataOnly": True}
    assert any("zone_rainlights: the rain weather's daylight, kept as data only" in line for line in report.lines())
    assert "extras" not in doc["scenes"][0]                            # no weather asked for: nothing said
    doc, report = daylight_export(weather="rain")
    table = doc["extensions"]["KHR_lights_punctual"]["lights"]
    assert [lt["name"] for lt in table] == ["MiamiRainySunShape"] and report.gltf_lights == 1
    assert node_named(doc, "MiamiSunShape")["extras"]["dataOnly"] is True
    assert doc["scenes"][0]["extras"] == {"weather": "rain"}
    with pytest.raises(G.ExportError):
        daylight_export(weather="snow")


def test_other_light_groups_are_not_weather():
    doc, _ = read_glb(export(lit_area("w_lit", light("lamp", 1, 0xFFFFFFFF, kids=sub((1, 1, 1))),
                                     light_group("interior", ["lamp"], kind=3)), map_mode=True, weather="rain")[0])
    assert node_named(doc, "interior")["extras"] == {"lightGroupKind": 3, "lightGroupRecord": "interior"}
    assert "dataOnly" not in node_named(doc, "lamp")["extras"] and "extensions" in node_named(doc, "lamp")


# --------------------------------------------------------------------------- the sky through the day

from test_p3d import colour_sets, integer_channel  # noqa: E402

SUN_OFFSET = (832.597, -0.755, -1.531)                  # the sun's offset from sun_grp (spec, section 3.3)
SUN_REST = (8.0, -755.2, 350.5)                         # the rest pose: under the ground
# made-up keys: frame, and how far sun_grp turns about the game's z axis (degrees); the key at frame 154 is
# stored with the opposite sign (the same rotation), as the real one is
SUN_KEYS = [(0, -65.1, False), (120, 50.5, False), (153, 70.0, False), (154, 72.0, True), (240, -65.5, False)]
DOME_OWN = 0xFF0A0D14                                   # the night sky
DOME_SETS = [(0, 0, 0), (104, 201, 209), (132, 149, 204), (250, 250, 250)]
HORIZON_OWN = 0xFF6080A0


def turn_z(degrees, flip=False):
    a = math.radians(degrees) / 2
    q = (0.0, 0.0, math.sin(a), math.cos(a))
    return tuple(-v for v in q) if flip else q


def day_animation(name, kind, groups):
    """An animation of 241 frames (one day); groups: (group name, channel chunks, how many)."""
    gl = b"".join(chunk(0x121001, struct.pack("<I", 0) + text(g) + struct.pack("<II", 0, k), chs) for g, chs, k in groups)
    return chunk(0x121000, struct.pack("<I", 0) + text(name) + kind + struct.pack("<ffI", 241.0, 30.0, 1),
                 chunk(0x121002, struct.pack("<II", 0, len(groups)), gl))


def keyed_channel(cid, param, keys, fmt):
    """A channel: the frames, then the values, no padding between them (an odd number of keys too)."""
    n = len(keys)
    return chunk(cid, struct.pack("<I", 1) + param + struct.pack(f"<I{n}H", n, *[f for f, _ in keys])
                 + b"".join(struct.pack(fmt, *v) for _, v in keys))


def sky_mesh(name, own, sets, key, positions):
    flat_colours = chunk(0x10008, struct.pack("<I4I", 4, *[own] * 4))
    return chunk(0x10000, text(name) + struct.pack("<II", 0, 1),
                 prim_group("skyShader", 1, 0x2021, positions, [0, 1, 2, 3], kids=flat_colours)
                 + chunk(0x122000, struct.pack("<If", 0, key)) + colour_sets([{v: s for v in range(4)} for s in sets]))


def sky_file():
    """A made-up Common.p3d: the clear sky (a dome whose colours change through the day, a horizon that keeps
    its own, the sun on sun_grp), PTRN_sky and the VRTX_ animations, and the rain sky."""
    rig = skeleton("sky", [("sky", 0, (0, 0, 0)), ("skybox", 0, (0, 0, 0)), ("sun_grp", 0, (0, 0, 0)),
                           ("sun", 2, SUN_REST), ("skybox_horizon", 0, (0, 0, 0))])
    dome = sky_mesh("skyboxShape", DOME_OWN, DOME_SETS, 1.0,
                    [(-100.0, 50.0, -100.0), (100.0, 50.0, -100.0), (-100.0, 50.0, 100.0), (100.0, 50.0, 100.0)])
    horizon = sky_mesh("skybox_horizonShape", HORIZON_OWN, [(0, 0, 0), (0, 0, 0)], 0.0,
                       [(-90.0, 0.0, -90.0), (90.0, 0.0, -90.0), (-90.0, 10.0, -90.0), (90.0, 10.0, -90.0)])
    sky = composite("sky", "sky", [("skyboxShape", 1, 1), ("skybox_horizonShape", 1, 4), ("sun", 1, 3)])
    turn = keyed_channel(0x121105, b"ROT\0", [(f, turn_z(d, flip)) for f, d, flip in SUN_KEYS], "<4f")
    offset = keyed_channel(0x121104, b"TRAN", [(0, SUN_OFFSET), (240, SUN_OFFSET)], "<3f")
    ptrn = day_animation("PTRN_sky", b"PTRN", [("sun_grp", turn, 1), ("sun", offset, 1)])
    vrtx = day_animation("VRTX_skyboxShape", b"VRTX", [("skyboxShape", integer_channel([40, 90, 120, 180], [0, 1, 2, 3]), 1)])
    vrtx2 = day_animation("VRTX_skybox_horizonShape", b"VRTX",
                          [("skybox_horizonShape", integer_channel([0, 240], [0, 1]), 1)])
    rain = (skeleton("rainy_skybox", [("rainy_skybox", 0, (0, 0, 0))]), mesh("rainy_skyShape"),
            composite("rainy_skybox", "rainy_skybox", [("rainy_skyShape", 1, 0)]))
    return p3d(rig, dome, horizon, sky, ptrn, vrtx, vrtx2, *rain,
               chunk(0x8800002, text("sky") + text("sky")), chunk(0x8800002, text("rainy_skybox") + text("rainy_skybox")))


def where(doc):
    """Every node's place in the scene (the first node of each name)."""
    out = {}

    def walk(i, m):
        n = doc["nodes"][i]
        m = G._mul(m, G._trs(tuple(n.get("translation", (0, 0, 0))), tuple(n.get("rotation", (0, 0, 0, 1))),
                             tuple(n.get("scale", (1, 1, 1)))))
        out.setdefault(n["name"], (m[0][3], m[1][3], m[2][3]))
        for c in n.get("children", []):
            walk(c, m)
    for r in doc["scenes"][0]["nodes"]:
        walk(r, G._identity())
    return out


def sun_height(doc):
    """How high the sun is over the horizon, in degrees, seen from sun_grp."""
    at = where(doc)
    x, y, z = (a - b for a, b in zip(at["sun"], at["sun_grp"]))
    return math.degrees(math.atan2(y, math.hypot(x, z)))


def height_for(turn):
    """The same worked out by hand: the sun's offset turned about the game's z axis."""
    a = math.radians(turn)
    x, y, z = SUN_OFFSET
    return math.degrees(math.atan2(x * math.sin(a) + y * math.cos(a), math.hypot(x * math.cos(a) - y * math.sin(a), z)))


def sky_at(hour=None, **kw):
    lib = G.Library()
    lib.add("Common.p3d", sky_file(), main=True)
    glb, report = G.export(lib, hour=hour, **kw)
    doc, binc = read_glb(glb)
    return doc, binc, report


def mesh_colours(doc, binc, name):
    m = next(m for m in doc["meshes"] if m["name"] == name)
    return {tuple(v[:3]) for v in values(doc, binc, m["primitives"][0]["attributes"]["COLOR_0"])}, m.get("extras")


def test_without_an_hour_the_sky_is_as_stored():
    doc, binc, report = sky_at()
    assert report.models == ["sky", "rainy_skybox"]                    # both skies, side by side, as models
    sky_top = doc["scenes"][0]["nodes"][0]
    sun = [v - t for v, t in zip(where(doc)["sun"], doc["nodes"][sky_top].get("translation", (0, 0, 0)))]
    assert sun == pytest.approx([8.0, -755.2, -350.5], abs=1e-3)       # the rest pose: under the ground (Z mirrored)
    assert mesh_colours(doc, binc, "skyboxShape") == ({(10, 13, 20)}, {"drawOrder": 1.0})
    assert [a["name"] for a in doc["animations"]] == ["PTRN_sky"]      # the day, to play
    assert "extras" not in doc["scenes"][0] and "extras" not in doc["nodes"][sky_top]
    lib = G.Library()
    lib.add("Common.p3d", sky_file(), main=True)
    assert G.export(lib)[0] == G.export(lib, hour=None, weather=None, fog=None)[0]


@pytest.mark.parametrize("hour, turn", [(0, -65.1), (6, -7.3), (12, 50.5), (15.3, 70.0), (15.4, 72.0),
                                        (20, 72.0 - 137.5 * 46 / 86), (24, -65.5)])
def test_the_sun_where_the_game_puts_it(hour, turn):
    doc, _binc, _report = sky_at(hour)
    assert sun_height(doc) == pytest.approx(height_for(turn), abs=0.01)
    assert not doc.get("animations")                                   # posed: PTRN_sky isn't played over it
    sky_top = doc["nodes"][doc["scenes"][0]["nodes"][0]]
    assert sky_top["name"] == "sky" and sky_top["extras"] == {"hour": hour}


def test_the_sun_takes_the_shorter_way_round_where_the_keys_change_sign():
    # frames 153 and 154 hold the same kind of rotation with opposite signs: half way, the sun is half way
    doc, _binc, _report = sky_at(15.35)
    assert sun_height(doc) == pytest.approx(height_for(71.0), abs=0.01)
    assert G._slerp(turn_z(70.0), turn_z(72.0, flip=True), 0.5) == pytest.approx(turn_z(71.0), abs=1e-9)


@pytest.mark.parametrize("hour, colour, picked", [
    (2, (10, 13, 20), 0.0),                     # before the first key: the first set (nothing added)
    (9, (114, 214, 229), 1.0),                  # a key: set 1 added to the night sky
    (10, (123, 197, 227), 1.3333),              # a third of the way from set 1 to set 2
    (12, (142, 162, 224), 2.0),
    (20, (255, 255, 255), 3.0),                 # after the last key: the last set, each colour kept to 255
])
def test_the_sky_colours_of_an_hour(hour, colour, picked):
    doc, binc, _report = sky_at(hour)
    assert mesh_colours(doc, binc, "skyboxShape") == ({colour}, {"drawOrder": 1.0, "hour": hour, "colourSet": picked})
    horizon, extras = mesh_colours(doc, binc, "skybox_horizonShape")
    assert horizon == {(0x60, 0x80, 0xA0)} and extras["drawOrder"] == 0.0     # the horizon keeps its own colours


def test_the_weather_picks_the_sky():
    assert sky_at(12, weather="rain")[2].models == ["rainy_skybox"]
    assert sky_at(weather="clear")[2].models == ["sky"]


def test_a_sky_round_a_whole_city():
    lib = G.Library()
    lib.add("Common.p3d", sky_file(), main=False)
    fog = {"start": 25.0, "end": 900.0, "color": [0.7843, 0.7843, 0.5882], "enabled": True}
    glb, report = G.sky_export(lib, 12, "clear", centre=(500.0, -300.0), reach=1000.0, fog=fog)
    doc, _binc = read_glb(glb)
    top = doc["nodes"][doc["scenes"][0]["nodes"][0]]
    radius = math.hypot(100, 100)                                      # the dome's reach across
    assert top["translation"] == [500.0, 0.0, -300.0]                  # on the city's middle, at height 0
    assert top["scale"] == pytest.approx([G.SKY_MARGIN * 1000 / radius] * 3)
    assert top["extras"] == {"hour": 12, "sky": "sky", "weather": "clear", "followsCamera": True}
    assert doc["scenes"][0]["extras"] == {"weather": "clear", "hour": 12, "fog": fog}
    assert report.models == ["sky"] and not doc.get("animations")
    doc, _binc = read_glb(G.sky_export(lib, None, "rain", reach=0.5)[0])
    top = doc["nodes"][doc["scenes"][0]["nodes"][0]]
    assert top["name"] == "rainy_skybox" and top["scale"] == [G.SKY_SCALE] * 3     # never smaller than the game's
    doc, _binc = read_glb(G.sky_export(lib)[0])
    assert [a["name"] for a in doc["animations"]] == ["PTRN_sky"]      # no hour: the day to play, as a model export
    with pytest.raises(G.ExportError):
        G.sky_export(G.Library(), 12)


# --------------------------------------------------------------------------- the fog in exports and in Blender

import fog as FOG  # noqa: E402
import torque_script as TS  # noqa: E402
from test_fog import env_script, tod_chunk  # noqa: E402


def game_folder(tmp_path, scripts=True):
    """packages/z04/miami_lod.p3d (the daylight and the tod object), Common.p3d and scriptc/graphanims.cso."""
    z04 = tmp_path / "game" / "packages" / "z04"
    z04.mkdir(parents=True)
    (z04 / "miami_lod.p3d").write_bytes(with_chunks(weather_file(), tod_chunk()))
    (z04 / "Common.p3d").write_bytes(sky_file())
    if scripts:
        (tmp_path / "game" / "scriptc").mkdir()
        (tmp_path / "game" / "scriptc" / "graphanims.cso").write_bytes(TS.compile_text(env_script()))
    return z04


def test_hour_weather_and_fog_on_the_command_line(tmp_path, capsys):
    z04 = game_folder(tmp_path)
    out = tmp_path / "city.glb"
    assert G.main([str(out), str(z04 / "miami_lod.p3d"), "--map", "--hour", "12"]) == 0
    extras = read_glb(out.read_bytes())[0]["scenes"][0]["extras"]
    assert extras["hour"] == 12 and extras["weather"] == "clear"         # the scripts found in game/scriptc
    assert (extras["fog"]["start"], extras["fog"]["end"], extras["fog"]["keys"][0]) == (25, 900, "environment_clear_12")
    assert G.main([str(out), str(z04 / "miami_lod.p3d"), "--map", "--hour", "2", "--weather", "rain"]) == 0
    doc = read_glb(out.read_bytes())[0]
    assert doc["scenes"][0]["extras"]["fog"]["end"] == pytest.approx(512.5)  # rain, between the 24 and the 4 key
    assert "extensions" in node_named(doc, "MiamiRainySunShape")
    assert "zone_lights: the clear weather's daylight, kept as data only" in capsys.readouterr().out
    # the sky alone, at an hour, needs no --map; its fog needs the tod object, from miami_lod.p3d
    assert G.main([str(out), str(z04 / "Common.p3d"), "--hour", "12", "--library", str(z04 / "miami_lod.p3d")]) == 0
    doc = read_glb(out.read_bytes())[0]
    assert sun_height(doc) == pytest.approx(height_for(50.5), abs=0.01) and doc["scenes"][0]["extras"]["fog"]["end"] == 900
    assert G.main([str(out), str(z04 / "Common.p3d"), "--hour", "12"]) == 0
    assert "no fog: the tod object (in miami_lod.p3d) isn't in the files used" in capsys.readouterr().out
    with pytest.raises(SystemExit):
        G.main([str(out), str(z04 / "miami_lod.p3d"), "--weather", "snow"])


def test_without_the_scripts_the_fog_is_left_out_and_said_so(tmp_path, capsys):
    z04 = game_folder(tmp_path, scripts=False)
    out = tmp_path / "city.glb"
    assert G.main([str(out), str(z04 / "miami_lod.p3d"), "--map", "--hour", "12"]) == 0
    assert read_glb(out.read_bytes())[0]["scenes"][0]["extras"] == {"weather": "clear", "hour": 12}
    assert "no fog: the game's script scriptc/graphanims.cso wasn't found (--scripts says where)" in capsys.readouterr().out
    scripts = tmp_path / "elsewhere"
    scripts.mkdir()
    (scripts / "graphanims.cso").write_bytes(TS.compile_text(env_script()))
    assert G.main([str(out), str(z04 / "miami_lod.p3d"), "--map", "--hour", "9", "--scripts", str(scripts)]) == 0
    assert read_glb(out.read_bytes())[0]["scenes"][0]["extras"]["fog"]["color"] == [round(c / 255, 4) for c in (245, 240, 160)]


class FakeWorld:
    def __init__(self):
        self.mist_settings = type("Mist", (), {"start": 5.0, "depth": 25.0, "falloff": "QUADRATIC"})()
        self.color = (0.05, 0.05, 0.05)
        self.background = type("Node", (), {"type": "BACKGROUND", "inputs": [type("In", (), {"default_value": None})()]})()
        self.node_tree = type("Tree", (), {"nodes": [self.background]})()


class FakeScene(dict):
    def __init__(self):
        super().__init__()
        self.world = None
        self.view_layers = [type("Layer", (), {"use_pass_mist": False})()]


def blender_script(monkeypatch, files):
    """The Blender script run against a stand-in for Blender's bpy (nothing imported): its functions."""
    import sys
    import types
    import blender_export as BX
    bpy = types.SimpleNamespace(app=types.SimpleNamespace(background=False, timers=types.SimpleNamespace(
        register=lambda *a, **k: None)), data=types.SimpleNamespace(worlds=types.SimpleNamespace(new=lambda name: FakeWorld())))
    monkeypatch.setitem(sys.modules, "bpy", bpy)
    ns: dict = {}
    exec(compile(BX.OPEN_SCRIPT % {"files": [str(f) for f in files], "save": None, "fps": 30}, "open_in_blender.py", "exec"), ns)
    return ns


def test_the_blender_script_shows_the_fog(tmp_path, monkeypatch):
    fog = FOG.fog_at(12, FOG.tod_object(p3d(tod_chunk())), FOG.environment_objects(env_script()))
    lib = G.Library()
    lib.add("miami_lod.p3d", weather_file(), main=True)
    (tmp_path / "foggy.glb").write_bytes(G.export(lib, map_mode=True, hour=12, fog=fog)[0])
    (tmp_path / "clear.glb").write_bytes(G.export(lib, map_mode=True)[0])
    (tmp_path / "not.glb").write_bytes(b"nothing")
    ns = blender_script(monkeypatch, [tmp_path / "clear.glb", tmp_path / "foggy.glb"])
    assert ns["fog_of"](str(tmp_path / "foggy.glb")) == fog
    assert ns["fog_of"](str(tmp_path / "clear.glb")) is None and ns["fog_of"](str(tmp_path / "not.glb")) is None
    scene = FakeScene()
    assert ns["show_fog"](scene, fog)
    mist = scene.world.mist_settings
    assert (mist.start, mist.depth, mist.falloff, mist.use_mist) == (25.0, 875.0, "LINEAR", True)
    want = [ns["linear"](c) for c in fog["color"]]
    assert scene.world.color == pytest.approx(want) and ns["linear"](1.0) == pytest.approx(1.0)
    assert scene.world.background.inputs[0].default_value == pytest.approx(want + [1.0])
    assert scene.view_layers[0].use_pass_mist is True and json.loads(scene["scarface_fog"]) == fog
    assert not ns["show_fog"](FakeScene(), None) and not ns["show_fog"](FakeScene(), dict(fog, enabled=False))
    import blender_export as BX
    script = BX.OPEN_SCRIPT % {"files": ["a.glb"], "save": "a.blend", "fps": 30}
    assert "show_fog(scene, next((f for f in (fog_of(p) for p in FILES) if f), None))" in script


def test_the_city_with_its_sky_and_fog(tmp_path, monkeypatch):
    import blender_export as BX
    import game_assets as GA
    z, files = "cement.rcf/packages/z04/", city_files()
    files.update({z + "Common.p3d": sky_file(), z + "miami_lod.p3d": with_chunks(area("low_LOD"), tod_chunk()),
                  "cement.rcf/scriptc/graphanims.cso": TS.compile_text(env_script())})
    out, index = copied_game(tmp_path, files)
    monkeypatch.setattr(GA, "out_dir", lambda bin_dir=None: out)
    folder = tmp_path / "blender" / "PC"

    def run(cores=False, **kw):
        monkeypatch.setattr(BX, "workers_wanted", lambda use_cores=True: 2 if use_cores else 1)
        job = BX.CityJob(tmp_path)
        job.use_cores = lambda: cores
        assert job.start("pc", index, **kw) is None
        job._thread.join(60)
        return job
    job = run()                                                        # as before, and the sky and the sea round the city
    assert sorted(p.name for p in folder.glob("*.glb")) == ["a_01.glb", "b_02.glb", "ocean.glb", "shop_01 (inside).glb",
                                                            "sky.glb"]
    assert job.status["notes"] == [] and job.status["written"] == 3
    doc = read_glb((folder / "sky.glb").read_bytes())[0]
    top = doc["nodes"][doc["scenes"][0]["nodes"][0]]
    lo, hi = BX._city_box(folder)
    assert top["translation"] == pytest.approx([(lo[0] + hi[0]) / 2, 0.0, (lo[2] + hi[2]) / 2])
    assert top["scale"] == [G.SKY_SCALE] * 3 and "hour" not in top["extras"]       # the made-up city is small
    assert "extras" not in read_glb((folder / "a_01.glb").read_bytes())[0]["scenes"][0]
    assert BX.city_made(folder) == {"hour": None, "weather": "clear"}
    job = run(hour=12, weather="rain")
    assert job.status["notes"] == [] and (job.status["hour"], job.status["weather"]) == (12, "rain")
    assert BX.city_made(folder) == {"hour": 12, "weather": "rain"}             # what the page compares its choice with
    doc = read_glb((folder / "sky.glb").read_bytes())[0]
    assert doc["nodes"][doc["scenes"][0]["nodes"][0]]["name"] == "rainy_skybox"
    assert doc["scenes"][0]["extras"]["fog"]["keys"][0] == "environment_rainy_12"
    area_scene = read_glb((folder / "a_01.glb").read_bytes())[0]["scenes"][0]
    assert area_scene["extras"]["fog"] == doc["scenes"][0]["extras"]["fog"] and area_scene["extras"]["hour"] == 12
    made = {p.name: p.read_bytes() for p in folder.glob("*.glb")}
    assert run(cores=True, hour=12, weather="rain").status["workers"] == 2                  # the same on several cores
    assert {p.name: p.read_bytes() for p in folder.glob("*.glb")} == made
    assert BX.CityJob(tmp_path).start("pc", index, hour=25) == "The hour is from 0 to 24."
    assert BX.CityJob(tmp_path).start("pc", index, weather="snow") == "The weather is clear or rain."
    # without the scripts or Common.p3d: the city as before, and why there is no fog or sky
    out, index = copied_game(tmp_path / "less", city_files())
    monkeypatch.setattr(GA, "out_dir", lambda bin_dir=None: out)
    job = run(hour=12)
    assert job.status["notes"] == ["No fog: the game's script scriptc/graphanims.cso isn't among the copied files.",
                                   "No sky: Common.p3d isn't among the copied files."]
    assert not (folder / "sky.glb").exists()                           # the earlier one doesn't stay
    assert BX.city_made(folder) == {"hour": 12, "weather": "clear"}
    # stopped part-way, the folder holds areas at two hours: which hour it is at isn't known any more
    stopping = BX.CityJob(tmp_path)
    stopping.use_cores = lambda: False
    options = BX.city_options
    monkeypatch.setattr(BX, "city_options", lambda *a, **k: (stopping.stop(), options(*a, **k))[1])
    assert stopping.start("pc", index, hour=6) is None
    stopping._thread.join(60)
    assert stopping.status["error"] == "Stopped." and BX.city_made(folder) is None
    (folder / BX.CITY_LOOK).write_text('{"hour": 30, "weather": "clear"}', encoding="utf-8")
    assert BX.city_made(folder) is None


def test_the_page_hears_which_hour_and_weather_the_exported_city_is_at(monkeypatch, tmp_path):
    """The Game files tab's areas reply says the hour and weather of the city in extracted/blender/, kept
    beside it, so the page can say when Open in Blender would open the city at another time than it asks for."""
    server, _out, index = _server(monkeypatch, tmp_path, city_files())
    monkeypatch.setattr(server.BLENDER, "use_cores", lambda: False)
    monkeypatch.setattr(server.BLENDER, "busy", lambda: "")
    sent = []

    class Fake:
        _allowed = lambda self: True  # noqa: E731
        path = "/api/game-files/areas?version=pc"

        def _json(self, obj, code=200):
            sent.append((code, obj))

    server.Handler.do_GET(Fake())
    assert sent[-1][1]["city_made"] is None and sent[-1][1]["city_files"] == 0      # nothing exported yet
    server.Handler.post_game_files_blender(Fake(), {"version": "pc", "hour": 18, "weather": "rain"})
    server.BLENDER._thread.join(60)
    server.Handler.do_GET(Fake())
    reply = sent[-1][1]
    assert reply["city_made"] == {"hour": 18.0, "weather": "rain"} and reply["city_files"] == 4 and reply["city_current"]
    assert (reply["city"]["hour"], reply["city"]["weather"]) == (18.0, "rain")
    assert reply["city"]["notes"][0].startswith("No fog: ")


def test_the_portal_asks_for_the_city_at_an_hour_in_a_weather(monkeypatch, tmp_path):
    server, _out, _index = _server(monkeypatch, tmp_path, city_files())
    asked, sent = [], []
    monkeypatch.setattr(server.BLENDER, "start", lambda version, index, hour=None, weather="clear":
                        asked.append((version, hour, weather)) or None)

    class Fake:
        def _json(self, obj, code=200):
            sent.append((code, obj))
    for body in ({"version": "pc"}, {"version": "pc", "hour": "18.5", "weather": "rain"}, {"version": "pc", "hour": ""}):
        server.Handler.post_game_files_blender(Fake(), body)
        assert sent[-1][0] == 200
    assert asked == [("pc", None, "clear"), ("pc", 18.5, "rain"), ("pc", None, "clear")]
    server.Handler.post_game_files_blender(Fake(), {"version": "pc", "hour": "dusk"})
    assert sent[-1] == (400, {"ok": False, "error": "The hour is from 0 to 24."}) and len(asked) == 3


# --------------------------------------------------------------------------- see-through surfaces, the low-detail hull,
# the sea and shadow decals (the clean-room spec docs/cleanroom/SPEC-002-materials-ocean-shadows.md)

def shader_chunk(name, kind="simple", ints=(), floats=(), tex=None):
    """A Shader (0x11000) of a kind with integer settings (0x11003), float settings (0x11004) and a texture."""
    kids = chunk(0x11002, b"TEX\0" + text(tex)) if tex else b""
    kids += b"".join(chunk(0x11003, k.encode().ljust(4, b"\0") + struct.pack("<I", v)) for k, v in ints)
    kids += b"".join(chunk(0x11004, k.encode().ljust(4, b"\0") + struct.pack("<f", v)) for k, v in floats)
    return chunk(0x11000, text(name) + struct.pack("<I", 0) + text(kind)
                 + struct.pack("<4I", 0, 0, 0, len(ints) + len(floats) + bool(tex)), kids)


def picture(name, w, h, rgba):
    """A Texture (0x19000) holding a PC picture (a PNG)."""
    png = media.png(w, h, rgba)
    return chunk(0x19000, text(name) + struct.pack("<4I", 14000, w, h, 32),
                 chunk(0x19001, text(name) + struct.pack("<7I", 14000, w, h, 32, 0, 1, 1),
                       chunk(0x19002, struct.pack("<I", len(png)) + png)))


def image_pixels(doc, binc, mat):
    img = doc["images"][doc["textures"][mat["pbrMetallicRoughness"]["baseColorTexture"]["index"]]["source"]]
    view = doc["bufferViews"][img["bufferView"]]
    return media.decode_png(binc[view["byteOffset"]:view["byteOffset"] + view["byteLength"]])[2]


def by_name(doc):
    return {m["name"]: m for m in doc["materials"]}


GLOW = bytes([0, 0, 0, 255, 200, 100, 50, 255, 255, 255, 255, 255, 0, 0, 0, 255])     # black, orange, white, black


def test_light_adding_and_darkening_surfaces():
    skid = bytes([20, 20, 20, 255, 125, 125, 125, 175, 255, 255, 255, 255, 0, 0, 0, 0])
    shaders = [shader_chunk("flare", ints=[("BLMD", 2)], tex="flare.bmp"), shader_chunk("skid", ints=[("BLMD", 3)], tex="skid.bmp"),
               shader_chunk("glass", ints=[("BLMD", 1)], tex="flare.bmp"), shader_chunk("wall", tex="flare.bmp"),
               shader_chunk("lost", ints=[("BLMD", 2)], tex="gone.bmp")]
    data = p3d(picture("flare.bmp", 2, 2, GLOW), picture("skid.bmp", 2, 2, skid), *shaders,
               *(mesh("m_" + s, shader=s) for s in ("flare", "skid", "glass", "wall", "lost")))
    doc, binc = read_glb(export(data)[0])
    check_references(doc, binc)
    mats = by_name(doc)
    add = mats["flare"]
    assert add["alphaMode"] == "BLEND" and add["extras"] == {"blend": "add", "depthWrite": False}
    px = image_pixels(doc, binc, add)
    assert px[0:4] == bytes(4)                                         # black adds nothing: it lets what is behind through
    assert px[4:8] == bytes([255, 128, 64, 200])                       # its brightness as alpha, its colour divided by it
    assert px[8:12] == bytes([255, 255, 255, 255])
    dark = mats["skid"]
    assert dark["alphaMode"] == "BLEND" and dark["extras"] == {"blend": "darken"}
    px = image_pixels(doc, binc, dark)                                  # black, alpha 1 - brightness: what is behind x brightness
    assert [px[i:i + 4] for i in range(0, 16, 4)] == [bytes([0, 0, 0, 235]), bytes([0, 0, 0, 130]), bytes(4), bytes([0, 0, 0, 255])]
    assert mats["glass"]["alphaMode"] == "BLEND" and mats["glass"]["extras"] == {"blend": "alpha"}
    assert "extras" not in mats["wall"] and "alphaMode" not in mats["wall"]
    assert mats["lost"]["pbrMetallicRoughness"]["baseColorFactor"] == [0.0, 0.0, 0.0, 0.0]   # no picture: nothing, no dark square
    assert len(doc["images"]) == 3                                     # flare.bmp as it is (glass, wall) and made ready twice
    assert G.blend_of({"ints": {"BLMD": 7}}) == 7 and G.blend_of({"ints": {"BLMD": 0}}) is None


def test_cut_outs_use_the_shaders_own_alpha():
    edge = bytes([255, 255, 255, 153, 255, 255, 255, 154, 255, 255, 255, 255, 255, 255, 255, 0])
    shaders = [shader_chunk("hedge", ints=[("BLMD", 1), ("ATST", 1), ("ACMP", 4)], floats=[("ACTH", 0.2)], tex="flare.bmp"),
               shader_chunk("fence", ints=[("ATST", 1), ("ACMP", 4)], tex="flare.bmp"),
               shader_chunk("sparks", ints=[("BLMD", 2), ("ATST", 1), ("ACMP", 4)], floats=[("ACTH", 0.6)], tex="edge.bmp"),
               shader_chunk("sparks_or_equal", ints=[("BLMD", 2), ("ATST", 1)], floats=[("ACTH", 0.6)], tex="edge.bmp")]
    data = p3d(picture("flare.bmp", 2, 2, GLOW), picture("edge.bmp", 2, 2, edge), *shaders,
               *(mesh("m_" + s, shader=s) for s in ("hedge", "fence", "sparks", "sparks_or_equal")))
    doc, binc = read_glb(export(data)[0])
    mats = by_name(doc)
    assert mats["hedge"]["alphaMode"] == "MASK" and mats["hedge"]["alphaCutoff"] == pytest.approx(0.2)   # its ACTH
    assert mats["fence"]["alphaMode"] == "MASK" and mats["fence"]["alphaCutoff"] == 0.5                  # none: 0.5
    # a light-adding cut-out: blended, with the cut-out in its picture, greater than ACTH (ACMP 4), or equal too without ACMP
    assert mats["sparks"]["alphaMode"] == "BLEND" and "alphaCutoff" not in mats["sparks"]
    assert image_pixels(doc, binc, mats["sparks"])[3::4] == bytes([0, 255, 255, 0])
    assert image_pixels(doc, binc, mats["sparks_or_equal"])[3::4] == bytes([255, 255, 255, 0])
    named = G.shader_from_name("GlobalShader_g_hedge.tga_simple_blmd1_mcbv0_lit1_alpha1_atst1_alum1_2sid0")
    assert G.alpha_test(named) == (0.5, False) and named["pddi"] == "simple"


def test_what_the_game_draws_without_writing_depth():
    kinds = [("grime", "decal", 1), ("window", "nightlight", 2), ("blob", "shadowdecal", 1), ("glow", "simple", 2),
             ("pane", "simple", 1), ("road", "cbvlit", 0)]
    shaders = [shader_chunk(n, k, ints=[("BLMD", b)] if b else []) for n, k, b in kinds]
    doc, _ = read_glb(export(p3d(*shaders, *(mesh("m_" + n, shader=n) for n, _k, _b in kinds)))[0])
    depth = {m["name"]: m.get("extras", {}).get("depthWrite", True) for m in doc["materials"]}
    assert depth == {"grime": False, "window": False, "blob": False, "glow": False, "pane": True, "road": True}
    # a shader known only by its name: the kind is in the name
    decal = G.shader_from_name("LocalShader_shadowdecal.TGA_shadowdecal_blmd1_mcbv0_lit0_alpha1_atst0_alum0_2sid0")
    assert decal["pddi"] == "shadowdecal" and not G.draws_depth(decal) and G.draws_depth(None)
    # the sky: drawn without writing depth too
    doc, _binc, _report = sky_at()
    assert doc["materials"] and all(m["extras"]["depthWrite"] is False for m in doc["materials"])


def leafy_region():
    """A region's _D file: a tree whose leaves are unlit and see-through, and a bush whose leaves are lit."""
    return p3d(shader_chunk("leaves", ints=[("BLMD", 1)]), shader_chunk("lit_leaves", ints=[("BLMD", 1), ("LIT", 1)]),
               skeleton("palm", [("palm", 0, (0, 0, 0))]), mesh("palmShape", shader="leaves"),
               composite("palm", "palm", [("palmShape", 1, 0)]),
               skeleton("bush", [("bush", 0, (0, 0, 0))]), mesh("bushShape", shader="lit_leaves"),
               composite("bush", "bush", [("bushShape", 1, 0)]))


def test_the_leaves_of_placed_props_come_twice():
    shell = area("w_a_shell", objects=[("palm", [record(1.0, 0.0, 1.0)]), ("bush", [record(2.0, 0.0, 2.0)])], shader="leaves")
    doc, binc = read_glb(export(shell, lib=[("x_region_D.p3d", leafy_region())], map_mode=True)[0])
    check_references(doc, binc)
    mats = doc["materials"]

    def prims(name):
        node = next(n for n in doc["nodes"] if n["name"] == name and "mesh" in n)
        return doc["meshes"][node["mesh"]]["primitives"]
    core, colour = prims("palmShape")
    assert core["attributes"] == colour["attributes"] and core["indices"] == colour["indices"]       # the same vertices
    assert mats[core["material"]]["alphaMode"] == "MASK" and mats[core["material"]]["alphaCutoff"] == pytest.approx(228 / 255, abs=1e-4)
    assert mats[core["material"]]["extras"] == {"blend": "alpha", "leaves": "depth"}                 # the solid core hides
    assert mats[colour["material"]]["alphaMode"] == "BLEND"
    assert mats[colour["material"]]["extras"] == {"blend": "alpha", "depthWrite": False, "leaves": "colour"}
    assert len(prims("bushShape")) == 1                                # lit leaves: drawn once
    ground = prims("collapsedMesh_0")                                  # the same shader on the area's own ground: once
    assert len(ground) == 1 and mats[ground[0]["material"]]["name"] == "leaves"


def hull_file():
    """A made-up miami_lod.p3d: the low-detail hull (a vertexfade shader) and the daylight."""
    rig = skeleton("low_LOD", [("low_LOD", 0, (0, 0, 0)), ("collapsedMesh_0", 0, (0, 0, 0))])
    return p3d(shader_chunk("pure3dVertexFadeShader1", "vertexfade", ints=[("BLMD", 1), ("LIT", 1)]), rig,
               mesh("collapsedMesh_0", "pure3dVertexFadeShader1"), composite("low_LOD", "low_LOD", [("collapsedMesh_0", 1, 1)]),
               world_geo("low_LOD"), light("MiamiSunShape", 2, 0xFF1F2D30, kids=sub((0, 0, 0), direction=(0, -1, 0))),
               light_group("zone_lights", ["MiamiSunShape"], kind=0))


def test_the_low_detail_hull_doesnt_cover_the_detailed_areas(tmp_path):
    lib = G.Library()
    lib.add("miami_lod.p3d", hull_file(), main=True)
    lib.add("a_shell.p3d", area("shells_a"), main=True)
    glb, report = G.export(lib, map_mode=True, lod=True)
    doc, _ = read_glb(glb)
    assert node_named(doc, "low_LOD")["extras"] == {"lowDetailHull": True, "hidden": True}
    assert "extras" not in node_named(doc, "shells_a")
    assert "hidden" not in json.dumps([node_named(doc, n) for n in ("miami_lod", "miami_lod lights", "zone_lights")])
    assert "extensions" in node_named(doc, "MiamiSunShape")            # the daylight still lights the scene
    hull = by_name(doc)["pure3dVertexFadeShader1"]
    assert hull["extras"] == {"blend": "alpha", "lowDetailHull": True, "fade": [200.0, 250.0], "fadeCutoff": 0.0784}
    assert any("low-detail hull, marked hidden" in line for line in report.lines())
    alone = G.Library()
    alone.add("miami_lod.p3d", hull_file(), main=True)
    assert node_named(read_glb(G.export(alone, map_mode=True)[0])[0], "low_LOD")["extras"] == {"lowDetailHull": True}
    assert node_named(read_glb(G.export(alone, map_mode=True, beside_detail=True)[0])[0], "low_LOD")["extras"]["hidden"]
    # split: the hull's own file is hidden too, since the areas it would cover come in beside it
    (tmp_path / "miami_lod.p3d").write_bytes(hull_file())
    (tmp_path / "a_01_shell.p3d").write_bytes(area("shells_a"))
    out = tmp_path / "out"
    assert G.main([str(out), str(tmp_path / "*.p3d"), "--map", "--split", "--lod"]) == 0
    assert sorted(p.name for p in out.iterdir()) == ["a_01.glb", "miami_lod.glb", "ocean.glb"]
    assert node_named(read_glb((out / "miami_lod.glb").read_bytes())[0], "low_LOD")["extras"]["hidden"] is True


def common_file():
    """A made-up Common.p3d: the sky, and the sea's shader (ocean_text) with its picture."""
    water = bytes([0, 0, 255, 255, 255, 255, 255, 255, 0, 0, 255, 255, 255, 255, 255, 255])
    return with_chunks(sky_file(), shader_chunk("ocean_text", tex="water_01.bmp"), picture("water_01.bmp", 2, 2, water))


def sea_of(doc):
    node = node_named(doc, "Ocean")
    return node, doc["meshes"][node["mesh"]]["primitives"][0]


def test_the_sea_round_a_map():
    shell = area("shells_a", at=(100.0, 5.0, -200.0))                 # in glTF's space: x 100 to 101, z 200
    glb, report = export(shell, lib=[("Common.p3d", common_file())], map_mode=True, ocean=True, hour=12)
    doc, binc = read_glb(glb)
    check_references(doc, binc)
    node, prim = sea_of(doc)
    assert doc["scenes"][0]["nodes"][-1] == doc["nodes"].index(node)  # a node of its own, after the map
    pts = values(doc, binc, prim["attributes"]["POSITION"])
    assert {p[1] for p in pts} == {0.0}                                # flat, at height 0
    xs, zs = [p[0] for p in pts], [p[2] for p in pts]
    assert min(xs) <= 100 - G.OCEAN_MARGIN and max(xs) >= 101 + G.OCEAN_MARGIN       # past the map on every side
    assert min(zs) <= 200 - G.OCEAN_MARGIN and max(zs) >= 200 + G.OCEAN_MARGIN
    assert all(v % G.OCEAN_TILE == 0 for v in xs + zs)                 # squares on a grid from 0, 0: seas line up
    assert values(doc, binc, prim["attributes"]["NORMAL"])[0] == (0.0, 1.0, 0.0)
    assert {u for u, _v in values(doc, binc, prim["attributes"]["TEXCOORD_0"])} == {0.0, 200.0}   # every 5 m, whole in a square
    mat = doc["materials"][prim["material"]]
    assert mat["name"] == "ocean_text" and mat["alphaMode"] == "BLEND" and "KHR_materials_unlit" in mat["extensions"]
    assert mat["extras"] == {"ocean": True, "blend": "alpha"}
    sky = [round(c / 255, 4) for c in (142, 162, 224)]                 # the made-up dome at noon (the sky's tests)
    sea = [round(t * s, 4) for t, s in zip((0.25, 0.23, 0.25), sky)]   # the reflection's tint times the sky
    extras = node["extras"]
    assert extras["seaColour"] == sea and extras["skyColour"] == sky and (extras["hour"], extras["weather"]) == (12, "clear")
    assert (extras["ocean"], extras["height"], extras["picture"]) == (True, 0.0, "water_01.bmp")
    assert (extras["DetailOpacity"], extras["DetailTextureScale"], extras["ReflectionAlphaScale"]) == (0.225, 0.2, 0.98)
    assert (extras["tuningTemplate"], extras["FoamMinHeight"], extras["AmplitudeRatio"]) == ("OceanTuningTemplateDefault", 0.15, 0.013)
    px = image_pixels(doc, binc, mat)                                  # the picture at 0.225 over the sea's colour, alpha 0.98
    assert px[0:4] == bytes([round(c * 255 * (1 - 0.225) + v * 0.225) for c, v in zip(sea, (0, 0, 255))] + [250])
    assert any(line.startswith("the sea: 3,000 by 3,000 m at height 0") for line in report.lines())
    # without an hour the sky is as stored (the night); in rain, the rain sky's
    node, _prim = sea_of(read_glb(export(shell, lib=[("Common.p3d", common_file())], map_mode=True, ocean=True)[0])[0])
    assert node["extras"]["skyColour"] == [round(c / 255, 4) for c in (10, 13, 20)] and "hour" not in node["extras"]
    node, _prim = sea_of(read_glb(export(shell, lib=[("Common.p3d", common_file())], map_mode=True, ocean=True,
                                         weather="rain")[0])[0])
    assert node["extras"]["skyColour"] == [1.0, 1.0, 1.0]
    # without Common.p3d: a plain sea in the tint; and left out unless asked for
    doc, _ = read_glb(export(shell, map_mode=True, ocean=True)[0])
    node, prim = sea_of(doc)
    assert node["extras"]["skyColour"] is None and node["extras"]["picture"] is None
    assert doc["materials"][prim["material"]]["pbrMetallicRoughness"]["baseColorFactor"] == [0.25, 0.23, 0.25, 0.98]
    assert not any(n["name"] == "Ocean" for n in read_glb(export(shell, map_mode=True)[0])[0]["nodes"])
    assert not any(n["name"] == "Ocean" for n in read_glb(export(p3d(mesh("box")), ocean=True)[0])[0]["nodes"])   # not a map


def test_the_sea_on_the_command_line_and_in_the_portal(tmp_path):
    import blender_export as BX
    (tmp_path / "a_01_shell.p3d").write_bytes(area("shells_a"))
    (tmp_path / "Common.p3d").write_bytes(common_file())
    out = tmp_path / "a.glb"
    assert G.main([str(out), str(tmp_path / "a_01_shell.p3d"), "--map"]) == 0
    node, _prim = sea_of(read_glb(out.read_bytes())[0])
    assert node["extras"]["picture"] == "water_01.bmp"                 # Common.p3d beside it, as for the regions
    assert G.main([str(out), str(tmp_path / "a_01_shell.p3d"), "--map", "--no-ocean"]) == 0
    assert not any(n["name"] == "Ocean" for n in read_glb(out.read_bytes())[0]["nodes"])
    files = city_files()
    files["cement.rcf/packages/z04/Common.p3d"] = common_file()
    game, index = copied_game(tmp_path, files)
    doc, _ = read_glb(BX.area_glb(game, index, "pc", "z04/a_01")[0])  # an area by itself comes with the sea
    assert node_named(doc, "Ocean")["extras"]["ocean"] is True
    doc, _ = read_glb(BX.area_glb(game, index, "pc", "z04/a_01", ocean=False)[0])
    assert not any(n["name"] == "Ocean" for n in doc["nodes"])
    path = "cement.rcf/packages/z04/a_01_shell.p3d"                    # a map file opened by itself too
    doc, _ = read_glb(BX.model_glb(game, index, "pc", path, files[path])[0])
    assert node_named(doc, "Ocean")


def test_the_city_has_one_sea_and_can_go_without(tmp_path, monkeypatch):
    import blender_export as BX
    import game_assets as GA
    files = city_files()
    files["cement.rcf/packages/z04/Common.p3d"] = common_file()
    out, index = copied_game(tmp_path, files)
    monkeypatch.setattr(GA, "out_dir", lambda bin_dir=None: out)
    folder = tmp_path / "blender" / "PC"

    def run(**kw):
        job = BX.CityJob(tmp_path)
        job.use_cores = lambda: False
        assert job.start("pc", index, **kw) is None
        job._thread.join(60)
        return job
    job = run(hour=12)
    assert job.status["ocean"] is True and not any(n.startswith("No sea") for n in job.status["notes"])
    doc, binc = read_glb((folder / "ocean.glb").read_bytes())
    node, prim = sea_of(doc)
    lo, hi = BX._city_box(folder)                                      # what the areas fill, the sea not counted
    pts = values(doc, binc, prim["attributes"]["POSITION"])
    assert min(p[0] for p in pts) <= lo[0] - G.OCEAN_MARGIN and max(p[0] for p in pts) >= hi[0] + G.OCEAN_MARGIN
    assert min(p[2] for p in pts) <= lo[2] - G.OCEAN_MARGIN and max(p[2] for p in pts) >= hi[2] + G.OCEAN_MARGIN
    assert node["extras"]["hour"] == 12 and node["extras"]["picture"] == "water_01.bmp"
    assert not any(n["name"] == "Ocean" for n in read_glb((folder / "a_01.glb").read_bytes())[0]["nodes"])  # one sea, not one each
    assert BX._glb_box((folder / "ocean.glb").read_bytes()) is None
    job = run(ocean=False)                                             # left out: and the one from before goes
    assert job.status["ocean"] is False and not (folder / "ocean.glb").exists() and (folder / "sky.glb").exists()


def test_shadow_decals_go_in_a_node_of_their_own():
    name = "LocalShader_shadowdecal.TGA_shadowdecal_blmd1_mcbv0_lit0_alpha1_atst0_alum0_2sid0"
    decal = shader_chunk(name, "shadowdecal", ints=[("BLMD", 1)])
    piece = chunk(0x10000, text("collapsedMesh_details_0") + struct.pack("<II", 0, 2),
                  prim_group("paint", 1, 0x2001, QUAD, [0, 1, 2, 3]) + prim_group(name, 1, 0x2001, QUAD, [0, 1, 2, 3]))
    rig = skeleton("w_d", [("w_d", 0, (0, 0, 0)), ("collapsedMesh_details_0", 0, (5.0, 0.0, 5.0))])
    glb, report = export(p3d(decal, rig, piece, composite("w_d", "w_d", [("collapsedMesh_details_0", 1, 1)]), world_geo("w_d")),
                         map_mode=True)
    doc, binc = read_glb(glb)
    check_references(doc, binc)
    node = next(n for n in doc["nodes"] if n["name"] == "collapsedMesh_details_0" and "mesh" in n)
    assert [doc["materials"][p["material"]]["name"] for p in doc["meshes"][node["mesh"]]["primitives"]] == ["paint"]
    shadow = doc["nodes"][node["children"][0]]                         # under its mesh: it goes where the mesh goes
    assert shadow["name"] == "collapsedMesh_details_0 shadow decal" and shadow["extras"] == {"shadowDecal": True}
    m = doc["meshes"][shadow["mesh"]]
    assert m["extras"] == {"shadowDecal": True} and len(m["primitives"]) == 1
    assert doc["materials"][m["primitives"][0]["material"]]["extras"] == {"blend": "alpha", "depthWrite": False, "shadowDecal": True}
    assert report.shadow_decals == 1 and any("the PC game never shows them" in line for line in report.lines())
    # a mesh that is nothing but a shadow decal (the blobs under the cars and the people): the node itself
    doc, _ = read_glb(export(p3d(decal, mesh("vehicleShadowDecalShape", shader=name)))[0])
    assert node_named(doc, "vehicleShadowDecalShape")["extras"] == {"shadowDecal": True}


# ---- the Blender scene: the game's blending, depth and groups, from the extras the importer keeps -----------------

class FakeSocket:
    def __init__(self, node, name):
        self.node, self.name, self.links, self.default_value = node, name, [], None


class FakeSockets(list):
    def __getitem__(self, key):
        return next(s for s in self if s.name == key) if isinstance(key, str) else list.__getitem__(self, key)


NODE_SOCKETS = {                       # the sockets of the shader nodes the script meets or makes: inputs, outputs
    "OUTPUT_MATERIAL": (["Surface", "Volume"], []), "TEX_IMAGE": (["Vector"], ["Color", "Alpha"]),
    "BSDF_PRINCIPLED": (["Base Color", "Alpha"], ["BSDF"]), "ShaderNodeEmission": (["Color", "Strength"], ["Emission"]),
    "ShaderNodeVectorMath": (["Vector", "Vector_001"], ["Vector"]), "ShaderNodeBsdfTransparent": (["Color"], ["BSDF"]),
    "ShaderNodeAddShader": (["Shader", "Shader_001"], ["Shader"]), "ShaderNodeMath": (["Value", "Value_001"], ["Value"]),
    "ShaderNodeLightPath": ([], ["Is Camera Ray", "Is Shadow Ray"]),
    "ShaderNodeMixShader": (["Fac", "Shader", "Shader_001"], ["Shader"]),
}


class FakeNode:
    def __init__(self, kind):
        self.type = kind
        ins, outs = NODE_SOCKETS[kind]
        self.inputs = FakeSockets(FakeSocket(self, n) for n in ins)
        self.outputs = FakeSockets(FakeSocket(self, n) for n in outs)


class FakeNodes(list):
    def new(self, kind):
        self.append(FakeNode(kind))
        return self[-1]


class FakeLinks:
    def new(self, a, b):                                               # an input takes one link
        b.links[:] = [type("Link", (), {"from_socket": a, "to_socket": b})()]


class FakeMaterial(dict):
    """A material as Blender's glTF importer leaves it: its extras as custom properties, an image into a
    Principled BSDF into the output."""
    def __init__(self, name, **extras):
        super().__init__(extras)
        self.name = name
        self.node_tree = type("Tree", (), {})()
        self.node_tree.nodes = FakeNodes(FakeNode(k) for k in ("OUTPUT_MATERIAL", "TEX_IMAGE", "BSDF_PRINCIPLED"))
        self.node_tree.links = FakeLinks()
        out, pic, bsdf = self.node_tree.nodes
        self.node_tree.links.new(pic.outputs["Color"], bsdf.inputs["Base Color"])
        self.node_tree.links.new(bsdf.outputs["BSDF"], out.inputs["Surface"])

    def surface(self):
        return self.node_tree.nodes[0].inputs["Surface"].links[0].from_socket.node

    def picture(self):
        return self.node_tree.nodes[1]


class FakeObject(dict):
    def __init__(self, name, children=(), **props):
        super().__init__(props)
        self.name, self.children, self.users_collection = name, list(children), []


class FakeLinked(list):
    def __init__(self, owner):
        super().__init__()
        self.owner = owner

    def link(self, o):
        self.append(o)
        o.users_collection.append(self.owner)

    def unlink(self, o):
        self.remove(o)
        o.users_collection.remove(self.owner)


class FakeCollection:
    layers: list = []

    def __init__(self, name):
        self.name, self.objects = name, FakeLinked(self)
        self.children = type("Children", (list,), {"link": lambda s, c: (s.append(c), FakeCollection.layers.append(
            type("Layer", (), {"collection": c, "exclude": False})()))})()


def test_the_blender_scene_draws_them_as_the_game_does(monkeypatch):
    import sys
    import types
    import blender_export as BX
    glow, skid, decal = FakeMaterial("flare", blend="add", depthWrite=0), FakeMaterial("skid", blend="darken"), \
        FakeMaterial("blob", blend="alpha", depthWrite=False, shadowDecal=1)
    pane, wall = FakeMaterial("pane", blend="alpha"), FakeMaterial("wall")
    layers: list = []
    monkeypatch.setattr(FakeCollection, "layers", layers)
    bpy = types.SimpleNamespace(
        app=types.SimpleNamespace(background=False, timers=types.SimpleNamespace(register=lambda *a, **k: None)),
        data=types.SimpleNamespace(materials=[glow, skid, decal, pane, wall], collections=types.SimpleNamespace(new=FakeCollection)),
        context=types.SimpleNamespace(view_layer=types.SimpleNamespace(layer_collection=types.SimpleNamespace(children=layers))))
    monkeypatch.setitem(sys.modules, "bpy", bpy)
    ns: dict = {}
    exec(compile(BX.OPEN_SCRIPT % {"files": [], "save": None, "fps": 30}, "open_in_blender.py", "exec"), ns)
    joint = FakeObject("collapsedMesh_0", [FakeObject("collapsedMesh_0.001")])
    hull = FakeObject("low_LOD", [joint], lowDetailHull=1, hidden=1)
    shadow, sea, street = FakeObject("x shadow decal", shadowDecal=1), FakeObject("Ocean", ocean=1), FakeObject("shells_a")
    scene = types.SimpleNamespace(collection=FakeCollection("Scene Collection"))
    everything = [hull, joint, joint.children[0], shadow, sea, street]
    for o in everything:
        scene.collection.objects.link(o)
    scene.objects = list(everything)
    layers.clear()
    ns["game_looks"](scene)

    def into(socket):                                                  # the node a socket's link comes from
        return socket.links[0].from_socket.node
    # adds light: Emission (the picture's colour x its alpha) added to a Transparent BSDF; casts no shadow
    pick = glow.surface()
    assert pick.type == "ShaderNodeMixShader" and into(pick.inputs[0]).type == "ShaderNodeLightPath"
    assert pick.inputs[0].links[0].from_socket.name == "Is Shadow Ray" and into(pick.inputs[2]).type == "ShaderNodeBsdfTransparent"
    both = into(pick.inputs[1])
    assert both.type == "ShaderNodeAddShader" and into(both.inputs[0]).type == "ShaderNodeBsdfTransparent"
    light = into(both.inputs[1])
    times = into(light.inputs["Color"])
    assert light.type == "ShaderNodeEmission" and times.type == "ShaderNodeVectorMath" and times.operation == "MULTIPLY"
    assert [s.links[0].from_socket.name for s in times.inputs] == ["Color", "Alpha"] and into(times.inputs[0]) is glow.picture()
    assert (glow.surface_render_method, glow.blend_method, glow.show_transparent_back, glow.use_transparency_overlap,
            glow.shadow_method) == ("BLENDED", "BLEND", True, True, "NONE")
    # darkens: a Transparent BSDF in the colour of 1 minus the made picture's alpha (its brightness): a multiply
    through = skid.surface()
    left = into(through.inputs["Color"])
    assert through.type == "ShaderNodeBsdfTransparent" and left.type == "ShaderNodeMath" and left.operation == "SUBTRACT"
    assert left.inputs[0].default_value == 1.0 and left.inputs[1].links[0].from_socket.name == "Alpha"
    assert skid.blend_method == "BLEND" and not hasattr(skid, "shadow_method")    # it writes depth in the game: no more
    # drawn without writing depth: blended, every layer, no shadow; what it was is kept inside
    assert decal.surface().type == "ShaderNodeMixShader" and into(decal.surface().inputs[1]).type == "BSDF_PRINCIPLED"
    assert decal.blend_method == "BLEND" and decal.shadow_method == "NONE"
    # ordinary see-through and solid surfaces: as the importer made them
    for mat in (pane, wall):
        assert mat.surface().type == "BSDF_PRINCIPLED" and not hasattr(mat, "blend_method")
    # the groups: shadow decals and the sea shown, the hull (with everything under it) switched off
    made = {c.collection.name: c for c in layers}
    assert sorted(made) == ["Low-detail hull", "Sea", "Shadow decals"]
    assert list(made["Shadow decals"].collection.objects) == [shadow] and list(made["Sea"].collection.objects) == [sea]
    assert list(made["Low-detail hull"].collection.objects) == [hull, joint, joint.children[0]]
    assert made["Low-detail hull"].exclude is True and not made["Sea"].exclude and not made["Shadow decals"].exclude
    assert street.users_collection == [scene.collection] and hull.users_collection == [made["Low-detail hull"].collection]
    script = BX.OPEN_SCRIPT % {"files": ["a.glb"], "save": "a.blend", "fps": 30}
    assert "game_looks(scene)" in script


def test_the_portal_can_leave_the_sea_out_of_the_city(monkeypatch, tmp_path):
    server, _out, _index = _server(monkeypatch, tmp_path, city_files())
    asked, sent = [], []
    monkeypatch.setattr(server.BLENDER, "start", lambda version, index, hour=None, weather="clear", ocean=True:
                        asked.append(ocean) or None)

    class Fake:
        def _json(self, obj, code=200):
            sent.append((code, obj))
    for body in ({"version": "pc"}, {"version": "pc", "ocean": False}, {"version": "pc", "ocean": "no"}):
        server.Handler.post_game_files_blender(Fake(), body)
    assert asked == [True, False, True] and all(code == 200 for code, _obj in sent)     # only a real false leaves it out
