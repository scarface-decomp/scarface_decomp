"""A cutscene with everybody in it (cutscene.py): the script's cast, their places, the pieces of animation."""
import json
import math
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
    # the parts and when each runs: for the sounds, the lines and the cameras
    assert [(p["name"], p["start"]) for p in report.parts] == [("MNIS_One", 0.0), ("MNIS_Two", pytest.approx(10 / 30, abs=1e-3))]
    assert doc["scenes"][0]["extras"]["parts"] == report.parts and report.parts[0]["end"] == report.parts[1]["start"]
    assert [p["name"] for p in _r.parts] == ["MNIS_One"]
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

def face_file(*more):
    """A skin with two shapes (the lip down, the lip up) on its one primitive group, and the slider for them.
    more: chunks to put after them."""
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
    return p3d(skeleton("rig", [("Root", 0, (0, 0, 0)), ("Hip", 0, (0, 1.0, 0.5))]), skin, group, *more)


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


def test_someone_the_scene_swaps_in_comes_from_its_own_file_with_their_face():
    """SPEC-009 section 3.1: the model a script changes someone into (NISSwapModel) is in the scene's own
    static.p3d, with the shapes their face moves by; their everyday model has none."""
    from test_p3d_gltf import composite, skeleton
    frames = struct.pack("<2H", 0, 30)
    channel = chunk(0x121100, struct.pack("<I", 0) + b"EXP\0" + struct.pack("<I", 2) + frames + struct.pack("<2f", 0.0, 1.0))
    group = chunk(0x121001, struct.pack("<I", 0) + text("A___Lip_Down_Up") + struct.pack("<II", 0, 1), channel)
    anim = chunk(0x121000, struct.pack("<I", 0) + text("EXP_T_Ann0") + b"EXP\0" + struct.pack("<ffI", 30.0, 30.0, 0),
                 chunk(0x121002, struct.pack("<II", 0, 1), group))
    text_of = ('NISResourceLoader { Name "Ann"; TemplateName "CharTemp_Ann"; }; '
               'NISCharacterPosition { CharacterName "Ann"; Position { x 0; y 0; z 0; }; Facing 0; }; '
               'NISSwapModel { Character "MainCharacter"; newModel "tonynisDrawable"; }; '
               'NISSwapModel { Character "Ann"; newModel "annnisDrawable"; }; '
               'NISExpAnimation { CharacterName "Ann"; AnimationName "EXP_T_Ann"; MixerModelName "annnis_Face"; };')
    script = C.read_script(text_of)
    assert script.swaps == {"ann": "annnisDrawable"} and script.tony == "tonynis"
    static = face_file(composite("bobnisDrawable", "rig", [("nobody", 1, 0)]),
                       composite("annnisDrawable", "rig", [("faceShape", 1, 0)]))
    plain = p3d(skeleton("rig", [("Root", 0, (0, 0, 0))]))
    asked = []

    def model(kind, name):
        asked.append((kind, name))
        return {"scene": ("static.p3d", static), "person": ("ann.p3d", plain)}.get(kind)
    glb, report = C.export("T", script, [("stream0.p3d", p3d(anim))], model)
    assert ("scene", "T") in asked
    assert report.cast == [{"name": "Ann", "template": "CharTemp_Ann", "model": "annnisDrawable", "body": "", "face": "moves"}]
    doc, _b = read_glb(glb)
    assert any(c["target"]["path"] == "weights" for c in doc["animations"][0]["channels"])
    # a scene whose own file doesn't have that model: the everyday one
    glb, report = C.export("T", script, [("stream0.p3d", p3d(anim))],
                           lambda kind, name: {"scene": ("static.p3d", plain), "person": ("ann.p3d", face_file())}.get(kind))
    assert report.cast[0]["model"] == "ann.p3d" and report.cast[0]["face"] == "moves"


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



def test_what_tony_wears_comes_from_the_mission_scripts():
    """A script dresses him with a call given an MCP_...Tony name; the cutscenes it names after that have him
    in those clothes, and a cutscene no script dresses takes its mission's first outfit."""
    scripts = [
        ("scriptc/missionscripts/T01/T01_functions.cso",
         'function a() {\n   stxbp("MCP_ArmyTony");\n}\nfunction b() {\n   stxdf("MNIS_TUT_Intro_Cam", "After", "NIS");\n}\n'),
        ("scriptc/missionscripts/S01c/S01c_functions.cso",
         'stxdf("MNIS_S01_2_Early", "", "NIS");\nstxbp("MCP_HawaiianTony");\n'
         "stxmb(\"Movieplayer('MNIS_S01_4_Cops_Are_Here', 'done', 'NIS')\");\n"),
        ("scriptc/missionscripts/S01a/S01a_functions.cso",
         'stxbp("MCP_BlackSuitTony");\n%which = "PAL_MNIS_S01_1_Hm_Saves_the_Day";\n'),
        ("scriptc/other.cso", 'stxdf("MNIS_A64_0_Daughter", "", "NIS");\nstxbp("MCP_Driver");\n'),
    ]
    wears = C.outfits(scripts)
    assert C.outfit_for(wears, "MNIS_TUT_Intro_Cam") == "MCP_ArmyTony"
    assert C.outfit_for(wears, "MNIS_S01_1_Hm_Saves_the_Day") == "MCP_BlackSuitTony"       # named in a variable, as PAL_
    assert C.outfit_for(wears, "mnis_s01_4_cops_are_here") == "MCP_HawaiianTony"           # inside a quoted command
    assert C.outfit_for(wears, "MNIS_S01_2_Early") == "MCP_HawaiianTony"                   # none before it: the script's first
    assert C.outfit_for(wears, "MNIS_S01_0_Tony_in_Chair") == "MCP_BlackSuitTony"          # no script names it: mission S01's first
    assert C.outfit_for(wears, "PAL_MNIS_S01_0_Tony_in_Chair") == "MCP_BlackSuitTony"
    assert C.outfit_for(wears, "MNIS_A64_0_Daughter") == "" and C.outfit_for(wears, "NIS_01_secretary") == ""
    assert C.suit_file("MCP_BlackSuitTony") == "tonynisBLKsuit" and C.suit_file("MCP_HawaiianShadesTony") == "tonynisHawaiianS"
    assert C.suit_file("MCP_BluePinSuitTony") == "tonynisBLUPINsuit" and C.suit_file("MCP_GraySuitShadesTony") == "tonynisGRYsuitS"
    assert C.suit_file("MCP_ArmyTony") == "" and C.suit_file("MCP_Driver") == ""          # no cutscene model: his everyday one
    assert C.TONY_FILES[0] == "tonynishawaiian.p3d"                                       # when nothing says


def test_a_cue_with_a_place_of_its_own_is_where_the_camera_moves_from():
    cue = '''NISSequenceCue { SoundName ""; CameraAnimationName "CAM_T"; FrameBegin 0;
               Position { x -3411; y 20; z -1704; }; Facing 90; };'''
    script = C.read_script(cue + ' NISCharacterAnimation { CharacterName "MainCharacter"; AnimationName "T_Tony"; };')
    assert script.origin == ((-3411.0, 20.0, -1704.0), 90.0) and C.where(script, []) == (-3411.0, -1704.0)
    plain = C.read_script(cue.replace("-3411", "0").replace("-1704", "0"))
    assert plain.origin is None                                                # at the map's origin: the keys are the place


def _two_hands(palm_at=(-0.33, 0.06, 0.03), palm_on="wrist_l"):
    doc = {"nodes": [
        {"name": "Root", "children": [1, 2] + ([4] if palm_on != "wrist_l" else [])},
        {"name": "Wrist_R", "translation": [0.3, 1.2, 0.0], "children": [3]},
        {"name": "Wrist_L", "translation": [0.0, 0.0, 0.0], "children": [4] if palm_on == "wrist_l" else []},
        {"name": "right_hand_attach", "translation": [0.0, 0.0, 0.0]},
        {"name": "left_hand_attach", "translation": [0.3 + palm_at[0], 1.2 + palm_at[1], palm_at[2]]}]}
    copy = G.SkeletonCopy("rig", {"root": 0, "wrist_r": 1, "wrist_l": 2, "right_hand_attach": 3, "left_hand_attach": 4},
                          [0, 1, 2, 3, 4], [])
    return doc, copy


def test_where_a_joint_is_through_the_animation():
    """joint_world: a joint's place and turn in the space of the spot someone stands on, through the joints
    above it and their keys (SPEC-010 section 2.2 aims a hit from the shooter's neck to the joint hit)."""
    doc, copy = _two_hands()
    at, turn = C.joint_world(doc, copy, {}, "left_hand_attach", 0.0)
    assert at == pytest.approx((-0.03, 1.26, 0.03)) and turn == (0.0, 0.0, 0.0, 1.0)
    half = math.sqrt(0.5)                                     # the wrist turned a quarter about up at 1 s
    keys = {"wrist_r": {"rotation": ([0.0, 1.0], [(0, 0, 0, 1), (0, half, 0, half)])}}
    doc["nodes"][3]["translation"] = [0.0, 0.0, 0.1]
    assert C.joint_world(doc, copy, keys, "right_hand_attach", 0.5)[0] == pytest.approx((0.3, 1.2, 0.1))
    assert C.joint_world(doc, copy, keys, "right_hand_attach", 1.0)[0] == pytest.approx((0.4, 1.2, 0.0))
    assert C.joint_world(doc, copy, keys, "nowhere", 1.0) is None


def test_handguns_hang_as_their_model_lies_and_long_guns_are_turned():
    grip = {"name": "grip", "children": [1]}
    for reach, long in ((0.22, False), (0.44, False), (0.45, True), (0.68, True)):
        doc = {"nodes": [dict(grip), {"name": "colt", "children": [2]}, {"name": "muzzle_position", "translation": [0.0, 0.07, reach]}]}
        m = C._muzzle(doc, 0)
        assert (math.sqrt(sum(c * c for c in m)) >= C.LONG) is long
    assert C._muzzle({"nodes": [{"name": "grip", "children": [1]}, {"name": "pipe"}]}, 0) is None


def test_the_spot_someone_stands_on_for_finding_their_room():
    here = C.read_script('NISCharacterPosition { CharacterName "MainCharacter"; Position { x 906; y 3.7; z -739; }; Facing 0; };')
    assert C.floor_spot(here) == (906.0, 3.7, -739.0)
    cue = C.read_script('NISSequenceCue { CameraAnimationName "CAM"; Position { x -3411; y 20; z -1704; }; Facing 0; };')
    assert C.floor_spot(cue) == (-3411.0, 20.0, -1704.0)                       # nobody placed: where the cue is
    assert C.floor_spot(C.read_script('NISSequenceCue { CameraAnimationName "CAM"; };')) is None
    near = C.read_script('NISCharacterPosition { CharacterName "MainCharacter"; Position { x -0.1; y 0; z -1.5; }; Facing 0; };')
    assert C.floor_spot(near) is None                                          # played wherever Tony is: no room of its own


def test_the_floor_is_looked_for_under_the_feet_not_under_the_scripts_spot():
    """A scene's cast is often given one spot, and the animation's first pose walks each of them from it:
    the clerk behind his desk stands metres from the spot, on a floor of his own."""
    keys = {"Motion_Root": {"translation": ([0.0], [(0.0, 0.0, 0.0)])},
            "Character_Root": {"translation": ([0.0, 1.0], [(1.0, 0.3, -2.0), (5.0, 0.3, 5.0)])},
            "Hip": {"translation": ([0.0], [(9.0, 9.0, 9.0)])}}
    assert C._first_step(keys, C.facing_rotation(0.0)) == pytest.approx((1.0, -2.0))
    quarter = (0.0, 0.7071067811865476, 0.0, 0.7071067811865476)                # a quarter turn about the upright axis
    assert C._first_step(keys, quarter) == pytest.approx((-2.0, -1.0))
    assert C._first_step({}, quarter) == (0.0, 0.0)


def test_a_missions_cutscenes_are_joined_in_the_order_its_script_names_them():
    scripts = [
        ("cement.rcf/scriptc/missionscripts/A51/A51_objects.dso", 'new x("a") { nis = "MNIS_A51_9_Late"; };'),
        ("cement.rcf/scriptc/missionscripts/A51/A51_functions.cso",
         'play("MNIS_AMB_Dies");\nplay("MNIS_A51_3_Boats");\nplay("MNIS_A51_0_Intro");\nplay("PAL_MNIS_A51_0_Intro");\n'
         'play("MNIS_A51_2_Heli_Alt");\nplay("MNIS_A51_2_Heli");\nplay("MNIS_Not_Copied");\nplay("MNIS_A51_0_Intro");\n'),
        ("cement.rcf/scriptc/missionscripts/B02/B02_functions.cso", 'play("MNIS_B02_Only");'),
        ("cement.rcf/scriptc/other.cso", 'play("MNIS_A51_0_Intro"); play("MNIS_B02_Only");'),
    ]
    known = {n.lower(): n for n in ("MNIS_A51_0_Intro", "MNIS_A51_2_Heli", "MNIS_A51_2_Heli_Alt", "MNIS_A51_3_Boats",
                                    "MNIS_A51_9_Late", "MNIS_B02_Only", "MNIS_AMB_Dies")}
    # each cutscene once, by the stage in its name, the one without a stage last; the second version and
    # the one not copied left out; a mission with one cutscene is that cutscene already
    assert C.mission_films(scripts, known) == {
        "A51": ["MNIS_A51_0_Intro", "MNIS_A51_2_Heli", "MNIS_A51_3_Boats", "MNIS_A51_9_Late", "MNIS_AMB_Dies"]}


def test_a_script_says_when_weapons_are_held_and_fired_and_when_props_change():
    script = C.read_script(
        'NISWeaponAttach { CharacterName "Cuban3"; WeaponTemplateName "WeaponTemplateAK47"; FrameBegin 600; }; '
        'NISWeaponAttach { CharacterName "Cuban3"; WeaponTemplateName "WeaponTemplateColt45"; FrameBegin 0; }; '
        'NISWeaponAttach { CharacterName "Tony"; WeaponTemplateName "WeaponTemplateM16Mortar"; FrameBegin 98; }; '
        'NISWeaponFire { CharacterName "Cuban3"; IsSecondaryWeapon 1; FrameBegin 182; FrameEnd 237; }; '
        'NISWeaponFire { CharacterName "Cuban3"; FrameBegin 700; }; '
        'NISStatePropState { StatePropName "OfficeDoors"; StateName "idle"; FrameBegin 0; }; '
        'NISStatePropState { StatePropName "OfficeDoors"; StateName "final"; FrameBegin 642; }; '
        'NISStatePropState { StatePropName "OfficeDoors"; StateName "damage1"; FrameBegin 625; }; '
        'NISStatePropState { StatePropName "OfficeDoors"; StateName "final"; FrameBegin 0; };')      # how the scene leaves it
    assert script.holds_at == {"cuban3": [(0, "WeaponTemplateColt45"), (600, "WeaponTemplateAK47")],
                               "tony": [(98, "WeaponTemplateM16Mortar")]}
    assert script.fires == {"cuban3": [(182, 237, True), (700, 706, False)]}
    assert script.prop_states == {"OfficeDoors": [(0, "idle"), (625, "damage1"), (642, "final")]}


def test_a_muzzle_flash_is_made_once_and_a_prop_placed_from_text_is_read():
    b = G.Builder(G.Library())
    first = C._flash_mesh(b)
    assert C._flash_mesh(b) == first and b.g.doc["meshes"][first]["name"] == "muzzle flash"
    material = b.g.doc["materials"][b.g.doc["meshes"][first]["primitives"][0]["material"]]
    assert material["extras"] == {"blend": "add", "depthWrite": False}
    line = b"\x00tmDoorCGroup\x00tmDoorC\x00-2220.523 20.538 -1702.431 0 350 0 1 1 1 0 final\x00"
    m = C.PLACED.search(line)
    assert m.group(1) == b"tmDoorC" and [float(v) for v in m.groups()[1:]] == [-2220.523, 20.538, -1702.431, 0.0, 350.0, 0.0]


def test_a_scenes_own_props_are_read_and_stand_in_for_the_maps():
    script = C.read_script('NISRenderableTrack { RenderableName "doors"; CompositeDrawableName "closet_doors"; }; '
                           'NISRenderableAnimationTrack { RenderableName "doors"; AnimationName "NIS_X_doors"; };')
    assert script.renderables == {"doors": "closet_doors"} and script.renderable_moves == {"doors": "NIS_X_doors"}
    b = G.Builder(G.Library())
    area = b.g.node("area")
    placed = b.g.node("area instances", area)
    near = b.g.node("tmdoorgun", placed, translation=[10.0, 21.5, 5.0])            # 1.3 m above the doors' hinge
    far = b.g.node("lamp", placed, translation=[13.0, 20.0, 5.0])
    above = b.g.node("upstairs", placed, translation=[10.0, 25.0, 5.0])
    root = b.g.node("scene")
    joint = b.g.node("L_door_anim", root, translation=[10.1, 20.2, 5.1])
    copy = type("Copy", (), {"nodes": {"L_door_anim": joint}})()
    assert C._hide_map_props_at(b, copy) == 1
    assert b.g.doc["nodes"][placed]["children"] == [far, above]
    assert b.g.doc["nodes"][near]["extras"] == {"hidden": True}


def test_fades_and_effects_are_read_and_effects_go_on_the_joint_at_their_frame():
    script = C.read_script(
        'NISResourceLoader { Name "Ann"; TemplateName "CharTemp_Ann"; }; '
        'NISCharacterPosition { CharacterName "Ann"; Position { x 0; y 0; z 0; }; Facing 0; }; '
        'NISFade { FrameBegin 1560; FadeInFrames 30; DurationFrames 0; FadeOutFrames 0; Red 0; Green 0; Blue 0; }; '
        'NISFade { FrameBegin 0; FadeInFrames 0; DurationFrames 0; FadeOutFrames 30; Red 255; Green 0; Blue 0; }; '
        'NISCharacterEffect { CharacterName "Ann"; EffectType "GoreBloodExplosion"; JointName "Hip"; '
        'SourceCharacterName "Tony"; FrameBegin 60; }; '
        'NISCharacterEffect { CharacterName "Nobody"; EffectType "ShotEffectHeavy"; JointName "Hip"; FrameBegin 5; };')
    assert script.fades == [(0, 0, 0, 30, (1.0, 0.0, 0.0)), (1560, 30, 0, 0, (0.0, 0.0, 0.0))]
    assert script.effects == [("ann", "GoreBloodExplosion", "Hip", 60, "tony"), ("nobody", "ShotEffectHeavy", "Hip", 5, "")]
    glb, report = C.export("T", script, [], lambda kind, name: ("ann.p3d", face_file()) if kind == "person" else None)
    doc, binc = read_glb(glb)
    fades = report.parts[0]["fades"]
    assert fades[1] == {"at": 52.0, "in": 1.0, "hold": 0.0, "out": 0.0, "colour": [0.0, 0.0, 0.0],
                        "keys": [[52.0, 0.0], [53.0, 1.0]]}            # the scene's end: to black, and it stays
    assert fades[0]["keys"] == [[0.0, 1.0], [1.0, 0.0]]                # red, clearing over a second
    assert doc["scenes"][0]["extras"]["parts"][0]["fades"] == fades
    burst = next(i for i, n in enumerate(doc["nodes"]) if n["name"] == "GoreBloodExplosion on ann")
    holder = next(n for n in doc["nodes"] if burst in n.get("children", []))
    assert holder["name"] == "Hip"                                            # on the joint the script names
    ch = next(c for c in doc["animations"][0]["channels"] if c["target"]["node"] == burst)
    sm = doc["animations"][0]["samplers"][ch["sampler"]]
    from test_p3d_gltf import values
    assert [t for (t,) in values(doc, binc, sm["input"])] == pytest.approx([0.0, 2.0, 70 / 30])
    assert sm["interpolation"] == "STEP"
    assert not any(n["name"].endswith("on nobody") for n in doc["nodes"])      # nobody of that name: nothing


def test_a_props_effects_have_a_look_and_a_length_by_their_kind():
    fire, smoke, blast, wood = (C._prop_effect_look(k, 1.0) for k in
                                ("epFire_Burning", "epSmoke_Lingering", "epExplosion_Generic", "epDebris_Wood"))
    assert fire[2] and fire[3] == 60 * 30                    # adds light, burns on through the scene
    assert not smoke[2] and smoke[1][3] < 0.5 and smoke[3] == 8 * 30
    assert blast[3] == 20 and wood[3] == 15 and C._prop_effect_look("epFire_BurningStop", 1.0)[3] == 10 * 30
    assert C._prop_effect_look("epDebris_Wood", 2.0)[0] == 2 * wood[0]          # the effect's size scales it
    b = G.Builder(G.Library())
    assert C._burst_mesh(b, 0.5, (1.0, 0.5, 0.0, 1.0), True) == C._burst_mesh(b, 0.5, (1.0, 0.5, 0.0, 1.0), True)


def test_a_fade_as_the_game_plays_it():
    """SPEC-010 section 5: black with no hold ends a scene (in longer than out) or starts one; any other fade
    goes in, holds (for ever when negative) and goes out, in straight lines."""
    black = (0.0, 0.0, 0.0)
    assert C.fade_keys(30, 0, 0, black) == [(0, 0.0), (30, 1.0)]
    assert C.fade_keys(0, 0, 15, black) == [(0, 1.0), (15, 0.0)]
    assert C.fade_keys(10, -1, 5, black) == [(0, 0.0), (10, 1.0)]         # no hold: longer in, the end
    white = (1.0, 1.0, 1.0)
    assert C.fade_keys(2, 3, 4, white) == [(0, 0.0), (2, 1.0), (5, 1.0), (9, 0.0)]
    assert C.fade_keys(2, -1, 4, white) == [(0, 0.0), (2, 1.0)]           # held for ever
    assert C.fade_keys(10, 20, 10, black) == [(0, 0.0), (10, 1.0), (30, 1.0), (40, 0.0)]


def _effects_file():
    """A made-up effects file: the gore system, four particles that fly off forwards."""
    from test_particles import channel as ch, emitter, system
    settings = [ch(0x121100, "RAT", [0, 1], [(8.0,), (0.0,)]), ch(0x121100, "LIF", [0], [(5.0,)]),
                ch(0x121100, "SPD", [0], [(0.1,)]), ch(0x121100, "SIZ", [0], [(0.2,)])]
    return p3d(system([emitter(settings=settings, most=20)], length=3, name="fxSys_Blood_HeadExplodeShape"))


def test_a_character_effect_plays_the_games_particles_away_from_the_shooter():
    script = C.read_script(
        'NISResourceLoader { Name "Ann"; TemplateName "CharTemp_Ann"; }; '
        'NISResourceLoader { Name "Bob"; TemplateName "CharTemp_Bob"; }; '
        'NISCharacterPosition { CharacterName "Ann"; Position { x 0; y 0; z 0; }; Facing 0; }; '
        'NISCharacterPosition { CharacterName "Bob"; Position { x 0; y 0; z 5; }; Facing 0; }; '
        'NISCharacterEffect { CharacterName "Ann"; EffectType "GoreBloodExplosion"; JointName "Hip"; '
        'SourceCharacterName "Bob"; FrameBegin 60; };')
    files = {"person": ("ann.p3d", face_file()), "effects": ("Common.p3d", _effects_file())}
    glb, report = C.export("T", script, [], lambda kind, name: files.get(kind))
    doc, binc = read_glb(glb)
    place = next(i for i, n in enumerate(doc["nodes"]) if n["name"] == "GoreBloodExplosion on ann")
    group = doc["nodes"][doc["nodes"][place]["children"][0]]
    assert group["extras"] == {"effect": "fxSys_Blood_HeadExplodeShape", "system": "fxSys_Blood_HeadExplodeShape"}
    particles = [doc["nodes"][i] for i in group["children"]]
    assert len(particles) == 4 and all(p["extras"]["billboard"] for p in particles)
    colours = particles[0]["extras"]["colours"]
    assert colours[:5] == [2.0, 1.0, 1.0, 1.0, 1.0]                   # born at frame 60: white, seen whole
    from test_p3d_gltf import values
    scale = next(c for c in doc["animations"][0]["channels"] if c["target"]["node"] == group["children"][0]
                 and c["target"]["path"] == "scale")
    times = [t for (t,) in values(doc, binc, doc["animations"][0]["samplers"][scale["sampler"]]["input"])]
    assert times[0] == 0.0 and times[2] == pytest.approx(2.0) and times[-1] == pytest.approx(2.0 + 5 / 30)
    # turned so the particles fly from Bob (at z 5, the game's space: glTF's -5) through Ann
    q = doc["nodes"][place].get("rotation")
    assert q is not None
    forward = C._qturn(q, (0.0, 0.0, -1.0))
    assert forward[2] > 0.5                                          # towards glTF +z: away from Bob


def test_effect_helpers():
    import cutscene_fx as CFX
    assert CFX.shot_frames(0, 10, 105.0) == pytest.approx([0.0, 3.15, 6.3, 9.45])
    assert CFX.firing_rate("WeaponTemplateUzi", {}) == 105.0
    assert CFX.firing_rate("WeaponTemplateM16Mortar", {"weapontemplatem16mortar": 80.0}) == 80.0
    assert CFX.character_effect("ShotEffectHeavy") == ("fxSys_Large_ImpactBloodShape", 2.0)
    assert CFX.character_effect("BloodPool") == (None, 1.0) and CFX.character_effect("Sneeze") is None
    times, sizes = CFX.pool_keys(30)
    assert times[2] == 1.0 and times[3] == pytest.approx(1.0 + 1.9 / 0.0025 / 30) and sizes[3] == (1.9, 1.0, 1.9)
    for way in ((1.0, 0.0, 0.0), (0.0, 1.0, 0.0), (0.0, 0.0, 1.0), (0.0, 0.0, -1.0)):
        assert C._qturn(CFX.facing(way), (0.0, 0.0, -1.0)) == pytest.approx(way, abs=1e-6)


def test_a_gun_fires_its_own_effects_shot_by_shot():
    """SPEC-010 section 3: while the fire control is held, a shot every FiringRate milliseconds (105 for an
    Uzi), each playing the gun's fire1 effects at their place on it; a tracer every second bullet."""
    from test_p3d_gltf import composite, mesh, prop_property, skeleton, skin_chunk
    from test_particles import channel as ch, emitter, system
    rig = skeleton("rig", [("Root", 0, (0, 0, 0)), ("right_hand_attach", 0, (0.5, 1.0, 0))])
    tri = [(0, 0, 0), (1, 0, 0), (0, 1, 0)]
    person = p3d(rig, skin_chunk(tri, [0, 1, 2], [(0.75, 0.25, 0.0)] * 3, [0x01000000] * 3, [1, 0]))
    flash = chunk(0x0802000B, text("Effect") + text("fxSys_PistolUzi_MuzzleFlash") + struct.pack("<I", 0) + text("uzi")
                  + struct.pack("<6fI", 0.0, 0.0, 0.3, 0.0, 0.0, 0.0, 0) + text("uzi") + struct.pack("<2f", 1.0, 0.0))
    states = prop_property("name", "uzi")
    for sname, kids in (("idle", b""), ("fire1", flash)):
        states += chunk(0x0802000E, text(sname) + struct.pack("<6If3I", 0, 0, 0, 0, 0, 0, 0.0, 0, 0, 0), kids)
    guns = p3d(skeleton("uzi", [("uzi", 0, (0, 0, 0)), ("muzzle_position", 0, (0, 0, 0.3))]), mesh("uziShape"),
               composite("uzi", "uzi", [("uziShape", 1, 0)]),
               chunk(0x0802000D, struct.pack("<I", 4) + text("uzi") + text("uzi") + struct.pack("<II", 2, 1), states))
    settings = [ch(0x121100, "RAT", [0, 1], [(2.0,), (0.0,)]), ch(0x121100, "LIF", [0], [(2.0,)]),
                ch(0x121100, "SIZ", [0], [(0.1,)])]
    effects = p3d(system([emitter(settings=settings)], length=2, loops=1, name="fxSys_PistolUzi_MuzzleFlashShape"),
                  skeleton("fx", [("fx", 0, (0, 0, 0))]),
                  composite("fxSys_PistolUzi_MuzzleFlash", "fx", [("fxSys_PistolUzi_MuzzleFlashShape", 4, 0)]),
                  skeleton("fx_tracer", [("fx_tracer", 0, (0, 0, 0))]), mesh("tracerShape"),
                  composite("fx_tracer", "fx_tracer", [("tracerShape", 1, 0)]))
    script = C.read_script('''
      NISResourceLoader { Name "Cuban"; TemplateName "CharTemp_Cuban"; };
      NISCharacterPosition { CharacterName "Cuban"; Position { x 0; y 0; z 0; }; Facing 0; };
      NISWeaponAttach { CharacterName "Cuban"; WeaponTemplateName "WeaponTemplateUzi"; FrameBegin 0; };
      NISWeaponFire { CharacterName "Cuban"; FrameBegin 30; FrameEnd 40; IsSecondaryWeapon 0; };''')
    files = {"person": ("p.p3d", person), "weapons": ("guns.p3d", guns), "effects": ("Common.p3d", effects)}
    glb, _report = C.export("T", script, [], lambda kind, name: files.get(kind))
    doc, _ = read_glb(glb)
    names = [n["name"] for n in doc["nodes"]]
    shots = sorted(n for n in names if n.startswith("fxSys_PistolUzi_MuzzleFlash (shot"))
    assert len(shots) == 4                                   # frames 30, 33.15, 36.3 and 39.45
    anchor = next(n for n in doc["nodes"] if n["name"] == "Cuban's fxSys_PistolUzi_MuzzleFlash")
    assert anchor["translation"] == pytest.approx([0.0, 0.0, -0.3])   # at its offset on the gun
    # the flash loops (2 frames, one particle a round) until the next shot winds it down: two rounds in the
    # 3.15 frames between shots, and one for the last, cut short when the trigger is let go at frame 40
    assert sum(1 for n in doc["nodes"] if (n.get("extras") or {}).get("billboard")) == 3 * 2 + 1
    assert "Cuban's tracers" in names and "Cuban's muzzle flash" not in names


def test_the_weapons_template_script_gives_each_guns_rate():
    import cutscene_fx as CFX
    text = ('new WeaponTemplate(WeaponTemplateUzi) { FiringRate = 105; TracerFrequency = "2"; };\n'
            'new WeaponTemplate(WeaponTemplateM16) { FiringRate = 75; };\nnew Thing(Other) { Speed = 3; };')
    assert CFX.weapon_settings(text) == {"weapontemplateuzi": {"FiringRate": 105.0, "TracerFrequency": 2.0, "texts": ["2"]},
                                         "weapontemplatem16": {"FiringRate": 75.0, "texts": []}}
    named = 'new WeaponTemplate(WeaponTemplateM16Mortar) { FiringRate = 110; Look = "M16_upgrade2"; };'
    texts = CFX.weapon_settings(named)["weapontemplatem16mortar"]["texts"]
    assert C.weapon_model("WeaponTemplateM16Mortar", ["M16", "M16_upgrade2"], texts) == "M16_upgrade2"
    assert C.weapon_model("WeaponTemplateM16Mortar", ["M16", "M16_upgrade2"]) == "M16"   # without the script
    assert CFX.weapon_settings("this is not a script {") == {}


def test_a_hit_while_the_last_still_sprays_adds_nothing_new():
    """SPEC-010 section 1.9: played again while the last is alive, the effect is only moved."""
    hit = lambda f: (f'NISCharacterEffect {{ CharacterName "Ann"; EffectType "GoreBloodExplosion"; JointName "Hip"; '
                     f'FrameBegin {f}; }}; ')
    script = C.read_script('NISResourceLoader { Name "Ann"; TemplateName "CharTemp_Ann"; }; '
                           'NISCharacterPosition { CharacterName "Ann"; Position { x 0; y 0; z 0; }; Facing 0; }; '
                           + hit(60) + hit(62) + hit(90))
    files = {"person": ("ann.p3d", face_file()), "effects": ("Common.p3d", _effects_file())}
    glb, _report = C.export("T", script, [], lambda kind, name: files.get(kind))
    doc, _ = read_glb(glb)
    assert sum(1 for n in doc["nodes"] if n["name"] == "GoreBloodExplosion on ann") == 2   # 60 and 90, not 62


def test_a_cutscene_that_streams_round_its_camera():
    """NISDriveWorldStreamer Enable 1 (examiner H5.3): the world loads round the camera, not the player."""
    on = C.read_script('NISDriveWorldStreamer { Enable 1; }; NISCharacterAnimation { CharacterName "A"; AnimationName "x"; };')
    assert on.streams_by_camera
    assert not C.read_script('NISDriveWorldStreamer { Enable 1; }; NISDriveWorldStreamer { Enable 0; };').streams_by_camera
    assert not C.read_script("").streams_by_camera
    assert C.camera_path(C.read_script(""), []) == []
    cue = C.read_script('NISSequenceCue { CameraAnimationName "CAM_T"; Position { x -3411; y 20; z -1704; }; Facing 90; };')
    assert C.camera_path(cue, []) == [(-3411.0, 20.0, -1704.0)]
