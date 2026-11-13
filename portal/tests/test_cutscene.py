"""A cutscene with everybody in it (cutscene.py): the script's cast, their places, the pieces of animation."""
import json
import struct

import pytest

import cutscene as C
import p3d_gltf as G
from test_p3d import chunk, p3d, text
from test_p3d_gltf import mesh, read_glb

SCRIPT = '''
fightBank { name "MNIS_T"; fightNode { name "init";
  NISSequenceCue { SoundName ""; CameraAnimationName "CAM_MNIS_T_Cam"; FrameBegin 0; Position { x 0; y 0; z 0; }; Facing 0; };
  NISResourceLoader { Name "DB"; TemplateName "CharTemp_Cornelius"; };
  NISResourceLoader { Name "Boat"; TemplateName "SportFishingBoatTemplate"; }; };
 fightNode { name "start";
  NISSwapModel { Character "MainCharacter"; newModel "tonynisHawaiianDrawable"; };
  NISObjectPosition { FrameBegin 0; ObjectName "Boat"; Position { x 0; y 0; z 0; }; Facing 0; };
  NISVehicleAnimation { VehicleName "Boat"; AnimationName "MNIS_T_Boat"; };
  NISCharacterPosition { CharacterName "MainCharacter"; Position { x -10.5; y 3; z 20; }; Facing 0; Clut -1; };
  NISCharacterPosition { CharacterName "DB"; Position { x 5; y 0.5; z -7; }; Facing 90; Clut -1; };
  NISCharacterAnimation { CharacterName "MainCharacter"; AnimationName "MNIS_T_Tony"; };
  NISCharacterAnimation { CharacterName "DB"; AnimationName "MNIS_T_DB"; }; };
 fightNode { name "end";
  NISCharacterPosition { CharacterName "MainCharacter"; Position { x 1; y 1; z 1; }; Facing 0; Clut -1; }; }; };
'''


def test_the_script_says_who_where_and_what():
    s = C.read_script(SCRIPT)
    assert s.cast == {"DB": "CharTemp_Cornelius", "Boat": "SportFishingBoatTemplate"}
    assert s.stands["maincharacter"] == ((-10.5, 3.0, 20.0), 0.0)          # where the scene starts him, not where it leaves him
    assert s.stands["db"] == ((5.0, 0.5, -7.0), 90.0)
    assert s.plays == {"maincharacter": "MNIS_T_Tony", "db": "MNIS_T_DB"}
    assert s.drives == {"boat": "MNIS_T_Boat"} and s.camera == "CAM_MNIS_T_Cam" and s.tony == "tonynisHawaiian"


def test_which_cutscene_a_file_belongs_to():
    assert C.scene_name("cement.rcf/art/nis/MNIS_T.p3d") == "MNIS_T"
    assert C.scene_name("cement.rcf/art/nis/MNIS_T/stream3.p3d") == "MNIS_T"
    assert C.scene_name("cement.rcf/art/nis/fsc/MNIS_T.fsc") == "MNIS_T"
    assert C.scene_name("cement.rcf/art/nis/characters/tonynisHawaiian.p3d") is None
    assert C.scene_name("cement.rcf/art/vehicles/bus.p3d") is None


def test_facing_turns_the_same_way_as_the_game():
    # facing 90 turns someone who looked along +Z to look along +X (the game's axes); glTF's Z runs the other way
    q = C.facing_rotation(90.0)
    assert q == pytest.approx(G.rot((0.0, 2 ** -0.5, 0.0, 2 ** -0.5)))
    assert C.facing_rotation(0.0) == pytest.approx((0.0, 0.0, 0.0, 1.0))


def test_nobody_to_show_is_an_error():
    with pytest.raises(G.ExportError):
        C.export("MNIS_T", C.read_script(SCRIPT), [("stream0.p3d", p3d(mesh("nothing")))], lambda kind, name: None)


def test_people_stand_where_the_script_puts_them_and_play_their_pieces_end_to_end(tmp_path):
    from test_p3d_gltf import animation, skeleton, skin_chunk, values, copied_game
    rig = skeleton("rig", [("Root", 0, (0, 0, 0)), ("Hip", 0, (0, 1.0, 0.5))])
    tri = [(0, 0, 0), (1, 0, 0), (0, 1, 0)]
    person = p3d(rig, skin_chunk(tri, [0, 1, 2], [(0.75, 0.25, 0.0)] * 3, [0x01000000] * 3, [1, 0]))
    half = 2 ** -0.5
    turn = lambda n: animation(f"MNIS_T_DB{n}", [("hip", [(0, (0, 0, 0, 1)), (10, (0, half, 0, half))])])
    asked = []

    def model(kind, name):
        asked.append((kind, name))
        return ("CharTemp_Cornelius.p3d", person) if kind == "person" else None
    glb, report = C.export("MNIS_T", C.read_script(SCRIPT), [("stream0.p3d", p3d(turn(0))), ("stream1.p3d", p3d(turn(1)))], model)
    doc, binc = read_glb(glb)
    assert ("person", "CharTemp_Cornelius") in asked and ("tony", "tonynisHawaiian") in asked
    assert report.models == ["DB"] and sorted(report.missing_drawables) == ["Boat", "Tony"]      # said, not hidden
    db = next(n for n in doc["nodes"] if n["name"] == "DB")
    assert db["translation"] == pytest.approx([5.0, 0.5, 7.0])                 # Z mirrored, as everywhere
    assert db["rotation"] == pytest.approx(C.facing_rotation(90.0))
    assert [a["name"] for a in doc["animations"]] == ["Cutscene MNIS_T"]       # one, so everybody moves together
    s = doc["animations"][0]["samplers"][0]
    times = [t for (t,) in values(doc, binc, s["input"])]
    assert times == pytest.approx([0.0, 10 / 30, 20 / 30])                     # the second piece follows the first
    # through the portal: any of the cutscene's files gives the whole cutscene
    import blender_export as BX
    z = "cement.rcf/art/nis/"
    out, index = copied_game(tmp_path, {z + "MNIS_T.p3d": p3d(mesh("x")), z + "fsc/MNIS_T.fsc": SCRIPT.encode(),
                                        z + "MNIS_T/stream0.p3d": p3d(turn(0)), z + "MNIS_T/stream1.p3d": p3d(turn(1)),
                                        "cement.rcf/art/characters/npc/CharTemp_Cornelius.p3d": person})
    for path in (z + "MNIS_T.p3d", z + "MNIS_T/stream1.p3d"):
        _glb, rep = BX.model_glb(out, index, "pc", path, b"")
        assert rep.models == ["DB"] and rep.animations == ["Cutscene MNIS_T"]
    assert BX.cant_show(out, index, "pc", z + "MNIS_T.p3d", p3d(mesh("x"))) == ""


def test_a_weapon_template_is_one_of_the_weapons_models():
    models = ["M16", "M16_upgrade", "ak47", "ak47_upgrade", "chainsaw1", "colt_45", "metal_pipe", "sniper_rifle", "uzi"]
    pick = lambda t: C.weapon_model("WeaponTemplate" + t, models)
    assert [pick(t) for t in ("AK47", "MetalPipe", "Colt45", "Sniper", "Chainsaw", "M16Mortar", "uzi")] == \
        ["ak47", "metal_pipe", "colt_45", "sniper_rifle", "chainsaw1", "M16", "uzi"]
    assert pick("Banana") is None and C.weapon_model("", models) is None


def test_where_a_cutscene_happens():
    here = C.read_script(SCRIPT)
    assert C.where(here, []) == (-10.5, 20.0)                                  # where the script first stands someone
    anywhere = C.read_script('NISCharacterPosition { CharacterName "MainCharacter"; Position { x 0; y 0.1; z 0; }; Facing 0; };')
    assert C.where(anywhere, []) is None                                       # played wherever Tony is: no map
    assert C.where(C.read_script(""), []) is None


def test_the_cast_on_their_map_with_a_weapon_in_hand():
    from test_p3d_gltf import animation, area, composite, skeleton, skin_chunk
    rig = skeleton("rig", [("Root", 0, (0, 0, 0)), ("right_hand_attach", 0, (0.5, 1.0, 0))])
    tri = [(0, 0, 0), (1, 0, 0), (0, 1, 0)]
    person = p3d(rig, skin_chunk(tri, [0, 1, 2], [(0.75, 0.25, 0.0)] * 3, [0x01000000] * 3, [1, 0]))
    guns = p3d(skeleton("metal_pipe", [("metal_pipe", 0, (0, 0, 0))]), mesh("metal_pipeShape"),
               composite("metal_pipe", "metal_pipe", [("metal_pipeShape", 1, 0)]))
    script = C.read_script('''
      NISResourceLoader { Name "Thug1"; TemplateName "CharTemp_Columbia01"; };
      NISCharacterPosition { CharacterName "Thug1"; Position { x 100; y 5; z -200; }; Facing 0; Clut -1; };
      NISCharacterPosition { CharacterName "Hector"; Position { x 101; y 5; z -200; }; Facing 0; Clut -1; };
      NISCharacterAnimation { CharacterName "Thug1"; AnimationName "T_Thug1"; };
      NISCharacterAnimation { CharacterName "Hector"; AnimationName "T_Hector"; };
      NISWeaponAttach { CharacterName "Thug1"; WeaponTemplateName "WeaponTemplateMetalPipe"; FrameBegin 0; };''')
    assert script.holds == {"thug1": "WeaponTemplateMetalPipe"}
    asked = []

    def model(kind, name):
        asked.append((kind, name))
        return {"person": ("p.p3d", person), "weapons": ("guns.p3d", guns)}.get(kind)
    streams = [("stream0.p3d", p3d(animation("T_Thug10", [("root", [(0, (0, 0, 0, 1))])])))]
    glb, report = C.export("T", script, streams, model, area=[("a_01_shell.p3d", area("w_street"))])
    doc, _ = read_glb(glb)
    names = [n["name"] for n in doc["nodes"]]
    assert "w_street" in report.models and "Thug1" in report.models and "hector" in report.models    # the street, and the cast on it
    assert ("person", "CharTemp_hector") in asked                             # nobody loaded him: his template has his name
    hand = next(n for n in doc["nodes"] if n["name"] == "right_hand_attach" and "children" in n)
    grip = doc["nodes"][hand["children"][0]]                                  # the turn that lays it along the hand, top up
    assert grip["name"] == "Thug1's grip" and grip["rotation"] == pytest.approx([0.5, -0.5, -0.5, 0.5])
    assert "Thug1's metal_pipe" in [doc["nodes"][c]["name"] for c in grip["children"]]
    assert names.count("right_hand_attach") == 2 and not report.missing_drawables
    assert [a["name"] for a in doc["animations"]] == ["Cutscene T"]           # the map's own animations don't come first


def test_which_cutscene_the_game_plays_next():
    hashed = lambda name: "stx" + name.lower()[:5]
    scripts = ['''
function stxaaaa::stxbbbb(%x)
{
    stxplay("MNIS_MB4A_0_Babylon_Intro", "M_B4A_SiegeNIS", "NIS");
}

function stxm_b4a()
{
    stxplay("MNIS_MB4A_0_Empty_the_Club", "Stage1Go", "NIS", "", "", "", "", 0);
}

function stxstage()
{
    stxsay("go");
}
''']
    assert C.plays_next(scripts, hashed) == {"mnis_mb4a_0_babylon_intro": "mnis_mb4a_0_empty_the_club"}
    assert C.plays_next([], hashed) == {}


def test_cutscenes_played_back_to_back_come_as_one(tmp_path):
    from test_p3d_gltf import animation, skeleton, skin_chunk, values, copied_game
    import blender_export as BX
    rig = skeleton("rig", [("Root", 0, (0, 0, 0)), ("Hip", 0, (0, 1.0, 0.5))])
    tri = [(0, 0, 0), (1, 0, 0), (0, 1, 0)]
    person = p3d(rig, skin_chunk(tri, [0, 1, 2], [(0.75, 0.25, 0.0)] * 3, [0x01000000] * 3, [1, 0]))
    half = 2 ** -0.5
    turn = lambda name: p3d(animation(name + "0", [("hip", [(0, (0, 0, 0, 1)), (10, (0, half, 0, half))])]))
    fsc = lambda who: (f'NISResourceLoader {{ Name "{who}"; TemplateName "CharTemp_X"; }}; '
                       f'NISCharacterPosition {{ CharacterName "{who}"; Position {{ x 0; y 0; z 0; }}; Facing 0; }}; '
                       f'NISCharacterAnimation {{ CharacterName "{who}"; AnimationName "{who}_move"; }};').encode()
    z = "cement.rcf/art/nis/"
    out, index = copied_game(tmp_path, {
        z + "fsc/MNIS_One.fsc": fsc("Ann"), z + "MNIS_One/stream0.p3d": turn("Ann_move"),
        z + "fsc/PAL_MNIS_One.fsc": fsc("Ann"), z + "PAL_MNIS_One/stream0.p3d": turn("Ann_move"),
        z + "fsc/MNIS_Two.fsc": fsc("Bob"), z + "MNIS_Two/stream0.p3d": turn("Bob_move"),
        "cement.rcf/art/characters/npc/CharTemp_X.p3d": person})
    BX._NEXT.clear()
    real = BX.plays_next
    BX.plays_next = lambda o, i, v: {"mnis_one": "mnis_two"}
    try:
        listed = BX.cutscenes(out, index, "pc")
        assert [(c["name"], c["then"], c["follows"]) for c in listed] == [("MNIS_One", ["MNIS_Two"], False),
                                                                           ("MNIS_Two", [], True)]      # the PAL copy isn't listed
        glb, report = BX.cutscene_glb(out, index, "pc", "MNIS_One")
        alone, _r = BX.cutscene_glb(out, index, "pc", "MNIS_One", join=False)
    finally:
        BX.plays_next = real
    doc, binc = read_glb(glb)
    assert report.models == ["Ann", "Bob"] and [a["name"] for a in doc["animations"]] == ["Cutscene MNIS_One"]
    ann = next(i for i, n in enumerate(doc["nodes"]) if n["name"] == "Ann")
    bob = next(i for i, n in enumerate(doc["nodes"]) if n["name"] == "Bob")
    anim = doc["animations"][0]

    def track(node, path):
        ch = next(c for c in anim["channels"] if c["target"] == {"node": node, "path": path})
        sm = anim["samplers"][ch["sampler"]]
        return [t for (t,) in values(doc, binc, sm["input"])], values(doc, binc, sm["output"]), sm["interpolation"]
    third = 10 / 30
    times, sizes, how = track(ann, "scale")                                    # Ann is there for the first part
    assert times == pytest.approx([0.0, third]) and sizes[0] == pytest.approx((1, 1, 1)) and sizes[1][0] < 0.01 and how == "STEP"
    times, sizes, _how = track(bob, "scale")                                   # Bob from when the second begins
    assert times == pytest.approx([0.0, third]) and sizes[0][0] < 0.01 and sizes[1] == pytest.approx((1, 1, 1))
    hip = next(c["target"]["node"] for c in anim["channels"] if c["target"]["path"] == "rotation"
               and doc["nodes"][c["target"]["node"]]["name"] == "Hip" and track(c["target"]["node"], "rotation")[0][0] > 0.1)
    assert track(hip, "rotation")[0] == pytest.approx([third, 2 * third])      # his moves start when hers end
    assert len(read_glb(alone)[0]["animations"][0]["channels"]) == 1           # by itself: no one to show or hide


# ---- faces: the shapes a head can be pulled into, and the sliders that work them --------------------------------

def face_file():
    """A skin with two shapes (the lip down, the lip up) on its one primitive group, and the slider for them."""
    from test_p3d_gltf import skeleton
    tri = [(0, 0, 0), (1, 0, 0), (0, 1, 0)]
    flat = [v for p in tri for v in p]
    w3 = [0.75, 0.25, 0.0] * 3
    kids = (chunk(0x10005, struct.pack("<I9f", 3, *flat)) + chunk(0x1000A, struct.pack("<I3I", 3, 0, 1, 2))
            + chunk(0x1000C, struct.pack("<I9f", 3, *w3)) + chunk(0x1000B, struct.pack("<I3I", 3, *[0x01000000] * 3))
            + chunk(0x1000D, struct.pack("<I2I", 2, 1, 0)))
    head = struct.pack("<I", 0) + text("skin") + struct.pack("<9I", 0, 0x2181, 3, 3, 2, 0, 1, 0, 0)
    offsets = lambda rows: chunk(0x10F00, struct.pack("<I", 0) + b"POS\0" + struct.pack("<I", len(rows))
                                 + b"".join(struct.pack("<I3f", v, *d) for v, d in rows))
    sets = chunk(0x121305, struct.pack("<II2I2I", 0, 2, 0, 1, 1, 1),
                 chunk(0x121306, struct.pack("<3I", 0, 0, 0), offsets([(2, (0.0, -0.5, 0.25))]))
                 + chunk(0x121306, struct.pack("<3I", 0, 1, 0), offsets([(2, (0.0, 0.5, 0.0)), (1, (0.1, 0.0, 0.0))])))
    skin = chunk(0x10001, text("faceShape") + struct.pack("<I", 3) + text("rig") + struct.pack("<I", 1),
                 chunk(0x10020, head, kids) + sets)
    slider = chunk(0x21000, struct.pack("<I", 0) + text("A___Lip_Down_Up") + struct.pack("<I2f2I", 2, -1.0, 1.0, 0, 1))
    group = chunk(0x21001, struct.pack("<I", 0) + text("Face") + text("faceShape") + struct.pack("<I", 1), slider)
    return p3d(skeleton("rig", [("Root", 0, (0, 0, 0)), ("Hip", 0, (0, 1.0, 0.5))]), skin, group)


def test_a_faces_shapes_go_in_named_after_their_sliders():
    from test_p3d_gltf import export, values
    glb, _report = export(face_file())
    doc, binc = read_glb(glb)
    mesh = next(m for m in doc["meshes"] if m["name"] == "faceShape")
    assert mesh["weights"] == [0.0, 0.0] and mesh["extras"]["targetNames"] == ["A___Lip_Down_Up -", "A___Lip_Down_Up +"]
    down, up = mesh["primitives"][0]["targets"]
    assert values(doc, binc, down["POSITION"]) == [(0, 0, 0), (0, 0, 0), pytest.approx((0.0, -0.5, -0.25))]     # Z mirrored
    assert values(doc, binc, up["POSITION"])[1:] == [pytest.approx((0.1, 0, 0)), pytest.approx((0, 0.5, 0))]


def test_a_slider_turns_its_shapes_on():
    sliders = [("A___Lip", [(-1.0, 0), (1.0, 1)]), ("H___Blink", [(1.0, 2)])]
    keys = {"a___lip": ([0.0, 1.0], [-1.0, 1.0]), "h___blink": ([0.5], [0.5])}
    times, rows = C.shape_weights(sliders, 3, keys)
    assert times == [0.0, 0.5, 1.0]
    assert rows[0] == pytest.approx([1.0, 0.0, 0.5])             # the lip all the way down
    assert rows[1] == pytest.approx([0.0, 0.0, 0.5])             # half-way: neither shape
    assert rows[2] == pytest.approx([0.0, 1.0, 0.5])             # all the way up
    assert C.shape_weights(sliders, 3, {}) == ([], [])


def test_the_face_moves_in_a_cutscene():
    from test_p3d_gltf import values
    frames = struct.pack("<2H", 0, 30)
    channel = chunk(0x121100, struct.pack("<I", 0) + b"EXP\0" + struct.pack("<I", 2) + frames + struct.pack("<2f", 0.0, 1.0))
    group = chunk(0x121001, struct.pack("<I", 0) + text("A___Lip_Down_Up") + struct.pack("<II", 0, 1), channel)
    anim = chunk(0x121000, struct.pack("<I", 0) + text("EXP_T_Ann0") + b"EXP\0" + struct.pack("<ffI", 30.0, 30.0, 0),
                 chunk(0x121002, struct.pack("<II", 0, 1), group))
    script = C.read_script('NISResourceLoader { Name "Ann"; TemplateName "CharTemp_Ann"; }; '
                           'NISCharacterPosition { CharacterName "Ann"; Position { x 0; y 0; z 0; }; Facing 0; }; '
                           'NISExpAnimation { CharacterName "Ann"; AnimationName "EXP_T_Ann"; MixerModelName "Face"; };')
    assert script.faces == {"ann": "EXP_T_Ann"}
    glb, _r = C.export("T", script, [("stream0.p3d", p3d(anim))], lambda kind, name: ("ann.p3d", face_file()) if kind == "person" else None)
    doc, binc = read_glb(glb)
    ch = next(c for c in doc["animations"][0]["channels"] if c["target"]["path"] == "weights")
    assert doc["nodes"][ch["target"]["node"]]["name"] == "faceShape"
    sm = doc["animations"][0]["samplers"][ch["sampler"]]
    assert [t for (t,) in values(doc, binc, sm["input"])] == pytest.approx([0.0, 1.0])
    assert [w for (w,) in values(doc, binc, sm["output"])] == pytest.approx([0.0, 0.0, 0.0, 1.0])     # the lip rises


def test_people_are_stood_on_the_maps_floor():
    """The script puts someone a few centimetres off the floor; the map's surface nearest to that height, under
    the spot, is where they stand. A ceiling, a floor far below, or no map at all changes nothing."""
    b = G.Builder(G.Library())
    def slab(name, y, at=(0.0, 0.0)):
        x, z = at
        quad = [(x - 5, y, z - 5), (x + 5, y, z - 5), (x - 5, y, z + 5), (x + 5, y, z + 5)]
        prim = {"attributes": {"POSITION": b.g.accessor(quad, "VEC3", bounds=True)},
                "indices": b.g.accessor([0, 1, 2, 2, 1, 3], "SCALAR", 5123), "mode": 4}
        b.g.node(name, mesh=b.g.add("meshes", {"name": name, "primitives": [prim]}))
    slab("floor", 16.245)
    slab("cellar", 12.0)
    slab("ceiling", 19.0)
    slab("next door", 3.0, at=(50.0, 0.0))
    moved = b.g.node("lifted", translation=[0.0, 0.1, 0.0])
    b.g.doc["nodes"][moved]["children"] = [len(b.g.doc["nodes"])]
    slab("step", 16.3, at=(20.0, 0.0))                                        # under a node that lifts it to 16.4
    ground = C.Ground(b)
    assert ground.height(1.0, 16.2127, -2.0) == pytest.approx(16.245)
    assert ground.height(1.0, 12.3, -2.0) == pytest.approx(12.0)              # the nearest one to where they are
    assert ground.height(1.0, 17.5, -2.0) is None                             # nothing within reach
    assert ground.height(21.0, 16.2, 1.0) == pytest.approx(16.4)
    assert ground.height(200.0, 16.2, 0.0) is None and C.Ground(G.Builder(G.Library())).height(0, 0, 0) is None

