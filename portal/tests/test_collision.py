"""Collision meshes (portal/tools/collision.py, the examiner's question F12). A made-up file."""
import struct

import collision as C
from test_p3d import chunk, p3d, text


def floor_file():
    """A World Collision Object holding one mesh: a 10 x 10 floor at y 2 (two triangles), its sets."""
    verts = [(0.0, 2.0, 0.0), (10.0, 2.0, 0.0), (10.0, 2.0, 10.0), (0.0, 2.0, 10.0)]
    tris = [(0, 1, 2, 7), (0, 2, 3, 3)]
    head = struct.pack("<3I6f", 5, 0, 0, 0, 2, 0, 10, 2, 10)
    kids = chunk(C.VERTICES, struct.pack("<I", 4) + b"".join(struct.pack("<3f", *v) for v in verts))
    kids += chunk(C.TRIANGLES, struct.pack("<I", 2) + b"".join(struct.pack("<4H", *t) for t in tris))
    kids += chunk(C.NEIGHBOURS, struct.pack("<I", 2) + struct.pack("<4H", 0xFFFF, 1, 0xFFFF, 6978)
                  + struct.pack("<4H", 0, 0xFFFF, 0xFFFF, 6978))
    kids += chunk(C.TREE, struct.pack("<I", 4) + struct.pack("<4H", 0x8000, 0, 0, 2))
    walk = struct.pack("<I", 0) + text("Walkable") + struct.pack("<I", 1) + struct.pack("<2H", 1, 0)
    surf = struct.pack("<I", 0) + text("surfaceType") + struct.pack("<I", 2) + struct.pack("<4H", 0, 1, 4, 9)
    kids += chunk(C.SETS, struct.pack("<II", 0, 2), chunk(C.FLAG_SET, walk) + chunk(C.VALUE_SET, surf))
    mesh = chunk(C.MESH, head, kids)
    return p3d(chunk(C.WORLD_OBJECT, text("room_01_shell") + struct.pack("<I", 1),
                     chunk(0x07010001, struct.pack("<3I", 0, 0, 0), mesh)))


def test_reading_a_world_collision_object():
    (m,) = C.meshes(floor_file())
    assert (m.owner, m.version, len(m.vertices), m.triangles) == ("room_01_shell", 5, 4, [(0, 1, 2, 7), (0, 2, 3, 3)])
    assert m.box == ((0.0, 2.0, 0.0), (10.0, 2.0, 10.0)) and m.tree == 4
    assert m.neighbours[0] == (0xFFFF, 1, 0xFFFF, 6978)
    assert m.sets["Walkable"].flag and m.sets["Walkable"].values == {1: 0}
    assert not m.sets["surfaceType"].flag and m.sets["surfaceType"].values == {0: 4, 1: 9}
    assert m.value("surfaceType", 1) == 9 and m.value("surfaceType", 5, -1) == -1


def test_the_floor_under_a_place_and_a_ray():
    found = C.meshes(floor_file())
    h = C.ground(found, 7.0, 3.0, 2.0)                       # over the first triangle (x > z)
    assert h is not None and abs(h.at[1] - 2.0) < 1e-6 and h.triangle == 0 and h.surface == 3 and not h.walkable
    h = C.ground(found, 2.0, 3.0, 7.0)                       # over the second
    assert h.triangle == 1 and h.surface == 8 and h.walkable and not h.vehicle_ignore
    assert C.ground(found, 20.0, 3.0, 5.0) is None           # off the floor
    assert C.ground(found, 5.0, 1.0, 5.0, above=0.5) is None  # below it
    side = C.ray(found, (5.0, 5.0, 5.0), (0.0, -2.0, 0.0), 2.5)
    assert side is None                                       # 3 down, but the ray is 2.5 long
    assert C.ray(found, (5.0, 5.0, 5.0), (0.0, -1.0, 0.0), 3.5).distance == 3.0


def test_the_collision_as_gltf():
    import json
    glb = C.to_glb(C.meshes(floor_file()))
    n = struct.unpack("<I", glb[12:16])[0]
    doc = json.loads(glb[20:20 + n])
    node = next(x for x in doc["nodes"] if x["name"] == "room_01_shell collision")
    assert node["extras"] == {"collision": True, "triangles": 2, "sets": {"Walkable": 1, "surfaceType": 2},
                              "surfaces": {"3": 1, "8": 1}}
    assert doc["accessors"][doc["meshes"][0]["primitives"][0]["attributes"]["POSITION"]]["count"] == 6


def test_the_games_rule_for_surfaces():
    """The examiner's answer to F12: the low byte, less 1 (0 and 1 both Default), in 5 bits."""
    assert [C.surface_code(v) for v in (0, 1, 2, 9, 22, 30, 0xFF00, 0x0103)] == [0, 0, 1, 8, 21, 29, 0, 2]
    text = ('new stxddnhlkdj("CollisionSurfaceTypeGroup")\n{\n    new stxfiphfnbj("DefaultSurfaceType")\n    {\n'
            '    };\n    new stxfiphfnbj("GrassSurfaceType")\n    {\n    };\n};\nnew Other("x") {};')
    assert C.surface_names(text) == ["Default", "Grass"]
    assert C.surface_names("nothing here") == []


def test_vehicle_ignore_is_membership():
    m = C.meshes(floor_file())[0]
    m.sets["VehicleIgnore"] = C.TriangleSet("VehicleIgnore", {1: 0}, True)      # value 0, still ignored
    assert m.vehicle_ignore(1) and not m.vehicle_ignore(0)
