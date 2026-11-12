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
    assert "Thug1's metal_pipe" in [doc["nodes"][c]["name"] for c in hand["children"]]
    assert names.count("right_hand_attach") == 2 and not report.missing_drawables
    assert [a["name"] for a in doc["animations"]] == ["Cutscene T"]           # the map's own animations don't come first
