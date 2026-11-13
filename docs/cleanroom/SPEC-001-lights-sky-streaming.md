# Clean-room spec 001: lights, time of day, the sky, the stream graph

* **Written by:** the examiner side (see [CLEAN_ROOM.md](../CLEAN_ROOM.md)), from published notes by a
  third party whose research was done next to leaked source code. The examiner read those notes; the
  implementer must not.
* **What this is:** a description of the game's *files* and of what the game *does* with them, in the
  examiner's own words. It contains no code, and no names except ones this repository already has
  (from the game's own type information, as listed in [FORMATS.md](../FORMATS.md)) or text that is
  stored in the game's files.
* **How sure:** every statement below is a claim about the retail PC files that can be checked on your
  own copy. Those marked **[checked]** were read back from the PC files (`packages/z04/*.p3d`,
  `art/levels/z04/streamgraph.p3d`) on 2026-11-12 by a small script that only walks chunks and reads the
  fields as written here: every chunk named came out exactly to its last byte. Statements marked
  *(check)* were reported but are worth confirming before relying on them. If the files disagree with this
  spec, the files win: fix the spec in the same pull request.

All chunks use the ordinary Pure3D layout (u32 id, u32 size of the data, u32 size with sub-chunks) and
ordinary Pure3D text: a u8 length, then that many bytes: the text, NUL-padded so that the length is a
multiple of 4 (the length byte itself not counted). A text whose length is already a multiple of 4 has no
NUL at all: `lobst_region` is `0c` and its twelve letters. **[checked on the stream graph]**

---

## 1. Lights

### 1.1 Light, chunk `0x00013000` **[checked]**

Fields, in order:

| Field | Type | Notes |
| :--- | :--- | :--- |
| name | text | e.g. `MiamiSunShape`, `lamp_talllight` |
| version | u32 | `0x101` in every Miami file |
| type | u32 | 0 ambient, 1 point, 2 directional, 3 spot |
| colour | u32 | `0xAARRGGBB` |
| three attenuation numbers | 3 × f32 | constant, linear, quadratic; (1, 0, 0) in every Miami file |
| enabled | u32 | 1 or 0 |

Optional sub-chunks:

| Id | Holds |
| :--- | :--- |
| `0x00013001` | direction: 3 × f32 (a unit vector, the way the light shines) |
| `0x00013002` | position: 3 × f32, in the same space as the map's geometry *(check: an interior's lights should land inside its walls)* |
| `0x00013003` | spot cone: 4 × f32 (two angles, a falloff, a range) *(check which angle is inner and which outer; whether degrees or radians)* |
| `0x00013004` | casts shadows: u32 |
| `0x00013006` | decay range: u32 shape (0 none, 1 sphere, 2 box, 3 ellipsoid), then 3 × f32 inner size, then 3 × f32 outer size; may hold `0x00013007` (one f32: a rotation about the vertical axis, radians) |
| `0x00013008` | illumination kind: u32 (0 adds light, 1 none, 2 takes light away) |

In the city's files (`packages/z04`): 1,830 lights, of which 1,105 point, 593 directional, 132 ambient and
**no spot lights**. Every light has a position (`0x00013002`) and a shadow flag (`0x00013004`), ambient and
directional ones included; directional lights have a direction. Decay ranges: 784 spheres, 972 boxes,
43 ellipsoids. **Many directional lights are local** (inside interiors, with a decay box), so a
directional light with a decay range lights only its range, not the whole city.

How the game uses the decay range: full strength inside the inner size, fading smoothly to nothing at the
outer size, nothing beyond. A sphere uses only the first of the three sizes (the radius); the box is turned
by the `0x00013007` angle first; the game handles the ellipsoid as a box.

**The decay range separates the two kinds of light.** Only the city-wide lights in `miami_lod.p3d` and
`islands_LOD.p3d` have none (31 lights: the sun, fill, ambient and building ambient for clear and rainy
weather, and a few more `LightPass_<n>_V5_...` lights in the same files); every lamp and every interior
light has one. The game only considers a light
with a decay range as a local light, and only when the decay at the viewer is above zero and the light is
within about 50 m.

### 1.2 Light group, chunk `0x00002380` **[checked]**

name (text), u32 count, then that many light names (text). The lights themselves are separate `0x00013000`
chunks in the same file. Every light in the city's files belongs to a group.

### 1.3 Light group record, chunk `0x08800007` (`SFLightGroupLoader`) **[checked]**

name (text), light group name (text), u32 **kind**, u32 count, then that many frame controller names
(text). The kind says what the group is for. In the Miami files:

| Kind | How many | Where | What |
| :--- | ---: | :--- | :--- |
| 0 | 2 | `miami_lod.p3d`, `islands_LOD.p3d` | the daylight (`zone_lights`): ambient, sun, fill, building ambient |
| 1 | 2 | the same two files | the same four lights for rain (`zone_rainlights`) |
| 2 | 30 | mostly `*_detail.p3d` / `*_detailB.p3d`, a few `*_shell.p3d` | outdoor night lights (signs, a petrol station, a theatre front) |
| 3 | 116 | `*_shell.p3d` (including the mansion's `_TS0` to `_TS3`) | one group per interior |
| 4 | 1 | `Common.p3d` | light templates: `lamp_talllight`, `lamp_shortlight`, `vehicle_headlight` |

The building ambient light (`MiamiBuildingAmbientShape`) is left out of the light the world is lit with;
it belongs to the lit windows at night.

### 1.4 The daylight changes with the time of day **[checked: 241 frames, 30 per second, the tags]**

The kind 0 and kind 1 groups each name four frame controllers (`0x00121201`), one per light, named
`LITE_<light name>`. Each points at
the light and at an animation (`0x00121000`) of type `LITE`. These animations are **241 frames, one day**
(frame 0 = midnight, frame 120 = noon, one frame per six minutes).

* The channel tags in these animations are four bytes padded with a **NUL**, not a space: `CLR` + NUL
  (`0x00524C43`) for the colour, `DIR` + NUL (`0x00524944`) for the direction. Also present but flat:
  `PARM` (a 3-number vector channel).
* Colour keys are a COLOUR channel (`0x00121109`: u32 version, u32 tag, u32 count, then all the u16
  frame numbers, then all the `0xAARRGGBB` values: two arrays, not interleaved, and **no padding between
  them even when the count is odd** **[checked on all 427 colour and 326 vector channels of the city-wide
  and sky files]**). Direction keys are a
  3-number vector channel (`0x00121104`: the same, with 3 × f32 per key). Either may hold an
  interpolation-mode sub-chunk (`0x00121110`).
* **The values stored in the `0x00013000` chunks are the midnight ones** (the last frame exported). To
  light the city for another hour, sample the animation.

What that gives in `miami_lod.p3d`, as a check:

| Light | Stored (midnight) | Noon (frame 120) |
| :--- | :--- | :--- |
| `MiamiAmbientShape` | ambient 35, 37, 48 **[checked]** | 63, 52, 31 |
| `MiamiBuildingAmbientShape` | ambient 21, 25, 28 **[checked]** | 52, 44, 27 |
| `MiamiSunShape` | directional 31, 45, 48 shining along (0, −0.788, −0.616) **[checked]** | 99, 97, 72 shining along (−0.473, −0.743, 0.473) |
| `MiamiFillShape` | directional 6, 6, 6 shining along (−0.863, 0.087, 0.498) **[checked]** | unchanged |

The rain group's four are `MiamiRainyAmbientShape`, `MiamiRainyBuildingAmbientShape`, `MiamiRainySunShape`
and `MiamiRainyFillShape`. (`islands_LOD.p3d`'s sun at noon shines along (−0.5, −0.707, 0.5).) The direction is always the way the
light shines (§1.1). Sun colour key frames in `islands_LOD.p3d`,
as a further check: frames 0, 40, 60, 90, 120, 180, 207, 210, 229, 234, 240 hold `1f2d30`, `253134`,
`3c4038`, `5e593f`, `636148`, `635c36`, `3b2919`, `372316`, `272927`, `232b2b`, `1f2d30`.

### 1.5 Frame controller `0x00121201` as these files use it

u32 version (1), name (text), u32 type (`LITE` here), u32 `ANIM`, then f32 0 and u32 1 *(check: the order
of these two cannot be told apart from the data; both are constant)*, then the target's name (the light)
and the animation's name (text).

---

## 2. The draw-order key, chunk `0x00122000` **[checked for the sky meshes]**

The chunk listed under "Ids seen but not worked out" in FORMATS.md: u32 version (0), then one f32, a
**draw-order key** for the mesh or billboard group it belongs to. The game clamps it to 0..1; a mesh
without one counts as 0.5.

It matters for the sky (§3), which is drawn with depth testing and depth writing off: its parts are drawn
**from the highest key to the lowest**, so a lower key ends up on top. The clear sky's meshes:

| Mesh | Key | What it is |
| :--- | ---: | :--- |
| `skyboxShape` | 1.0 | the dome, drawn first |
| `skybox16Shape` | 0.9 | untextured |
| `skybox17Shape`, `skybox18Shape` | 0.3, 0.2 | two cloud layers (`Cloud_variant_001.tga`) |
| `skybox2Shape`, `skybox_horizonShape` | 0.0 | the horizon gradient, drawn last, on top |

The rain sky's meshes: `rainy_skyShape` and `rainy_sky2Shape` 0.5, `rainy_sky3Shape` and `rainy_sky4Shape` 0.6.
The chunk sits directly under the mesh (`0x00010000`) it belongs to.

Without the key, the dome can be drawn over the clouds and the gradient and the sky becomes one flat colour.
The billboard groups carry the key too (sun 0.5, the two flare stars 0.3 and 0.7, the lens quads 0.1, 0.4
and 0.2), but the game does not sort those.

---

## 3. The sky

### 3.1 Sky record, chunk `0x08800002` (`SkyLoader`) **[checked]**

name (text), composite drawable name (text). `Common.p3d` has two: `sky` → composite `sky` (6 meshes and 6
billboard groups), and `rainy_skybox` → composite `rainy_skybox` (6 meshes). A name starting `rainy_` is
the rain sky; the game starts it faded out and cross-fades between the two with the weather.

### 3.2 How it is drawn

* The whole sky is scaled **2×**.
* The sky box meshes move with the camera **horizontally** (they take the camera's x and z, height stays 0),
  so the sky turns with the camera but doesn't rise with it. They are drawn before everything else, with
  depth testing, depth writing and fog off, ordered by §2.
* The billboard groups (the sun, its two flare stars, two lens flares, the moon; there are no stars) take
  the camera's whole position: they sit at infinity. They are drawn near the end of the frame.
* The sky is never culled by distance.

### 3.3 Where the sun is: one turning joint **[checked]**

The `sky` composite's skeleton (`0x00023000`) has 14 joints, each with its parent's index: `sky` (the root),
`skybox`, `sun_grp`, then hanging from `sun_grp` the six billboard joints `sun`, `fxSys_SunFlare`,
`p3dBillboardQuadGroup1`, `p3dBillboardQuadGroup2`, `fxSys_SunFlare1` and `p3dBillboardQuadGroup3` (which of
the last ones is the moon is not known *(check)*), then `skybox16`, `skybox2`, `skybox17`, `skybox18` and
`skybox_horizon` under the root. The pose animation `PTRN_sky` (`0x00121000`, type `PTRN`, **241 frames at
30 a second: one day, frame = hour × 10, like the lights**) has two groups:

* `sun_grp`: a quaternion channel (`0x00121105`, tag `ROT`, four floats per key in the order x, y, z, w,
  as `p3d.channel_keys` returns them) with 21 keys, at frames 0, 22, 44, 66, 89, 90, 106, 116, 120, 125, 131,
  139, 149, 153, 154, 169, 180, 199, 217, 235 and 240;
* `sun`: a vector channel (`0x00121104`, tag `TRAN`) with two equal keys, (832.597, −0.755, −1.531): the
  sun's offset from `sun_grp`, which is also its rest offset.

**The skeleton's rest pose puts the sun about 755 m below the ground** (at (8.0, −755.2, 350.5)): a viewer
that doesn't play `PTRN_sky` draws the sun underground. Played at frame = hour × 10, the keys take the sun
(`sun_grp`'s rotation applied to the `sun` offset, in the game's coordinates, y up) to these heights above
the horizon:

| Hour | 0 | 2.2 | 4.4 | 6.6 | 8.9 | 10.6 | 12.0 | 13.1 | 13.9 | 14.9 | 16.9 | 18.0 | 19.9 | 21.7 | 23.5 |
| :--- | --: | --: | --: | --: | --: | --: | --: | --: | --: | --: | --: | --: | --: | --: | --: |
| Degrees | −65.1 | −60.4 | −38.3 | −12.8 | 13.2 | 34.7 | 50.5 | 65.1 | 72.0 | 66.1 | 32.1 | 12.0 | −19.9 | −48.1 | −65.5 |

Sunrise is about 7.7 h, sunset about 18.7 h.
Between two of the keys (frames 153 and 154) the quaternion changes sign (the same rotation): interpolate
along the shorter arc, or the sun jumps across the sky around 15:20.

### 3.4 The sky's colours **[checked]**

Five of the six sky meshes carry a vertex-colour animation. Their prim groups are triangle strips **with no
index list**, so a reader must handle a prim group without indices.

* `0x00121305` under the mesh (`0x00010000`): u32 version, u32 set count n, n × u32 (0, 1, 2 ... in every sky
  mesh), n × u32 (unknown); then n × `0x00121306` (u32 version, u32 frame, u32 unknown), each holding a
  `0x00010F02`: u32 version, the tag `CLR0`, u32 count, then count × (u32 vertex index, u16 r, u16 g, u16 b,
  u16 0). The count is every vertex of the mesh (65 for the dome, 47 for the clouds, 23 and 22 for the
  horizon meshes).
* These are **amounts added to the mesh's own vertex colours**, not replacements. The mesh's own colours
  are the night sky (the dome is `0x0a0d14`, dark blue); the first set is all zeros.
* Each set is one colour for every vertex (all entries equal): the dome really is one flat colour; the
  look of the sky comes from the other meshes.
* Which set is shown is chosen by the animation `VRTX_<mesh name>` (`0x00121000`, type `VRTX`, 241 frames at
  30 a second), which has one integer channel (`0x0012110E`, tag `VRTX`: u32 version, the tag, u32 count,
  the u16 frame numbers, then a u32 value per key, no padding) giving **the index of the set** at each key
  frame. Before the first key the first value holds. It is not linear in the time of day:

| Animation | Key frames → set |
| :--- | :--- |
| `VRTX_skyboxShape` | 40, 90, 120, 180, 210, 240 → 0, 1, 2, 3, 4, 5 |
| `VRTX_skybox17Shape` | 40, 41, 90, 210, 240 → 0, 1, 2, 3, 4 |
| `VRTX_skybox18Shape` | 40, 90, 210, 240 → 0, 1, 2, 3 |
| `VRTX_skybox2Shape`, `VRTX_skybox_horizonShape` | 0, 240 → 0, 1 |

  Keeping the fraction of the sampled index and blending the two neighbouring sets makes the sky
  cross-fade instead of jumping. At noon the dome is on set 2.
* The dome's six sets: (0, 0, 0), (104, 201, 209), (132, 149, 204), (104, 177, 112), (4, 3, 11),
  (0, 0, 0). Added to (10, 13, 20), the second is the familiar Miami sky blue. The cloud layers:
  `skybox17Shape` (0, 0, 0), (2, 2, 1), (122, 127, 85), (122, 127, 85), (0, 0, 0); `skybox18Shape` (0, 0, 0),
  (104, 109, 70), (104, 109, 70), (0, 0, 0). The two horizon meshes' colour sets are all zero, but
  their sets also move the texture across a strip of colours by the hour: the horizon does change colour
  (corrected in [SPEC-008 §1](SPEC-008-horizon-dents.md#1-the-horizons-colour-by-the-hour-checked)).

---

## 4. The stream graph: which areas are loaded where

`art/levels/z04/streamgraph.p3d` says which packages the game keeps loaded at each place in the city. The
text in this file is the padded kind described at the top (for example `0c`, then `loadTrigger` and one NUL).

### 4.1 Stream package, chunk `0x08800100` (`StreamPackage`) **[checked]**

216 of them: package name (text, lower case, no `.p3d`), then a u32 *(meaning unknown; values from 5 to
65535, one per package)*.

### 4.2 Stream trigger, chunk `0x08800101` (`StreamTrigger`) **[checked: all 297 read to the last byte with these fields]**

297 of them. Fields, in order:

| Field | Type | Notes |
| :--- | :--- | :--- |
| name | text | `loadTrigger`, `loadTrigger_100` ... |
| subzone | text | the area this trigger belongs to, e.g. `bsand_02_shell` |
| height | f32 | how tall the trigger is (13 for the street-level ones) |
| point count | u32 | |
| points | count × 3 × f32 | x, y, z: a closed outline on the ground; y is its base (all points of a trigger share it, e.g. 12.4) |
| package count | u32 | |
| packages | count × text | what must be loaded while you are inside |
| slot count | u32 | always equal to the package count |
| slots | count × text | the slot each package goes in, in the same order |
| two region names | 2 × text | two `<name>_region` packages, never empty, e.g. `fountainrock_region` and `lobst_region`; in 290 of 297 one of them is also among the trigger's `Region_S` packages. Meaning not known (perhaps the regions to have ready next) |
| last number | u32 | 0 in 296 triggers, 1 in one; meaning not known |

The slots: `Global_S` / `Global_D` (the city-wide backdrop and the models it places: `miami_lod`,
`miami_lod_d`, or the islands' `islands_lod`, `islands_lod_d`), `Region_S` / `Region_D` (a region's shaders
and textures, and its models), `Shell` (an area's streets and large buildings), `Detail` (the small things
on top of a shell; one shell can have several, `_detail`, `_detailB` ...), `ZoneAnimation`
(`packages/ZoneAnimations/<name>_anim`).

**What is loaded at a place is the union of every trigger whose outline contains it.** Triggers overlap;
usually three to six shells and three to eight details are loaded at once: the area you stand in and its
neighbours. Outside every trigger, the nearest one is a good stand-in. The coordinates are the map's own
(the same as the geometry, before any mirroring an exporter does).

### 4.3 What the stream graph does not cover

* `packages/azones/*_pocket.p3d` (32): loaded by the mission script
  `scriptc/missions/z04/azone_triggers.dso` when the player crosses its trigger outlines. Some of them are
  outdoor ground (for example the plaza in front of the North Beach bank is in `sbeachn_02_pocket.p3d`), so
  a city built only from the stream graph has holes there. The repository's map export already includes the
  pockets.
* `packages/dzones/*_dzone.p3d` (135): the furniture and props of interiors, loaded by the triggers in
  `scriptc/missions/z04/dzone_triggers.dso`; business-state variants (`01owned`, `02damaged`,
  `03destroyed`, `04condemned`).
* Conditional areas: `tonymansion_01_shell_TS0` to `TS3` (the mansion as it is rebuilt), and
  `cargoShip_01_shell_CS0` / `CS1`; the game picks one.

---

## 5. Fog by time of day **[checked]**

* The fog values are not in any `.p3d`. They are `EnvironmentObject` objects created by the compiled script
  `scriptc/graphanims.cso` (the islands: `scriptc/island_envobjects.cso`, objects named
  `island_environment_...`), named `environment_clear_<hour>` and `environment_rainy_<hour>` for the hours
  4, 9, 12, 18, 21 and 24. The repository's own script decompiler (`portal/tools/torque_script.py
  decompile`, which recovers the property names from the game's files) shows them as
  `new EnvironmentObject("environment_clear_12") { FogStart = 25; FogEnd = 900; ... }`. The fog properties:
  `FogEnabled`, `FogStart`, `FogEnd`, `FogColor_Red`, `FogColor_Green`, `FogColor_Blue`, `FogColor_Alpha`
  (meaning not known; 95 to 150), `FogClamp` (meaning not known). The same objects set about fifty more
  looks (`Bloom_*`, `ColourFX_*`, `DOF*`, `PrelitLuminance_*`, `Window*`, `WindStrength` ...), not covered
  here. The `*_xbox.cso` variants differ only in the clamp value.

  | Object | Miami: start–end, colour | Islands: start–end, colour |
  | :--- | :--- | :--- |
  | `..._clear_4` | 20–800, (23, 28, 40) | 20–700, (25, 30, 40) |
  | `..._clear_9` | 25–800, (245, 240, 160) | 20–800, (205, 200, 132) |
  | `..._clear_12` | 25–900, (200, 200, 150) | 20–800, (190, 190, 145) |
  | `..._clear_18` | 25–800, (227, 223, 105) | 20–800, (217, 213, 100) |
  | `..._clear_21` | 20–800, (50, 35, 33) | 20–800, (65, 45, 43) |
  | `..._clear_24` | 20–800, (20, 25, 32) | 20–600, (20, 25, 32) |
  | `..._rainy_4` | 10–525, (16, 16, 17) | 2–550, (16, 18, 21) |
  | `..._rainy_9` | 20–700, (35, 35, 23) | 2–500, (36, 40, 35) |
  | `..._rainy_12` | 20–700, (35, 35, 28) | 2–550, (35, 35, 33) |
  | `..._rainy_18` | 20–600, (35, 35, 21) | 2–500, (44, 43, 35) |
  | `..._rainy_21` | 20–700, (26, 21, 21) | 2–500, (28, 21, 21) |
  | `..._rainy_24` | 10–500, (14, 14, 16) | 2–550, (14, 16, 18) |

  Fog is on (`FogEnabled = 1`) in all 24.
* The six key hours come from the script object `tod` (class `todobject`) in `packages/z04/miami_lod.p3d`
  (an ordinary script object block, `0x09900190`, whose `0x09900192` properties `p3d.fields` reads), key
  N = 0 to 5: `prelitluminancetime_N` (the hour: 4, 9, 12.0, 18.0, 21.0, 24.0), `timetohold_N` (0, 20, 0, 40,
  120, 40), `timetotransit_N` (200, 360, 700, 340, 260, 200), `attachedclearenvparamname_N` and
  `attachedrainyenvparamname_N` (**the names of that hour's two `EnvironmentObject`s**, e.g.
  `environment_clear_4` / `environment_rainy_4`: the link between the hours and the fog objects is in the
  data). The same object sets the starting time (`settimeofdayhour` 18, `settimeofdayminute` 00), the
  clock's speed (`timeofdayspeed` 2000), `pausetimeofday` 0, and the weather: `enableraining` 0,
  `rainpercentage` 1, `rainstarttransitframes` 50, `rainendtransitframes` 50. How hold and transit turn into
  time is not known: blending straight from one key hour to the next by the clock is the plain reading. The
  hours go round: 24 is also 0, so 2 a.m. lies between the 24 and the 4 key.
* What the game does with the values: plain linear fog by distance from the camera along the view
  direction (depth), from the start to the end distance, in the fog colour. The sky, the night lights and
  decals are drawn without fog.
* As a check, clear weather in Miami: noon is 25 to 900 m in (200, 200, 150); 4 a.m. is 20 to 800 m in
  (23, 28, 40); 9 a.m. 25 to 800 m in (245, 240, 160). Rain: noon 20 to 700 m in (35, 35, 28).

---

## 6. Which weather's lights

`miami_lod.p3d` and `islands_LOD.p3d` each hold two complete sets of daylight: the light group record of
kind 0 (`zone_lights`: clear weather) and of kind 1 (`zone_rainlights`: rain), four lights each, sun included.
They are alternatives, not layers: the game is in one weather at a time, and **it starts in clear weather**
(`enableraining` 0 in the `tod` object, §5); rain fades in and out over 50 frames
(`rainstarttransitframes`, `rainendtransitframes`). A scene should be lit by one of the two groups, matching
its fog (§5) and its sky (the `sky` composite for clear weather, `rainy_skybox` for rain, §3.1).

---

## Suggested work for the implementer

In priority order. Each needs tests on made-up files (no game files in CI), like the rest of `portal/tools`.

1. `p3d.py`: name and read the chunks in §1 to §4 (`0x00013000` with its sub-chunks, `0x00002380`,
   `0x08800007`, `0x00122000`, `0x08800002`, `0x08800100`, `0x08800101`), each to a plain dictionary.
2. `p3d_gltf.py`: map exports carry the lights, as glTF `KHR_lights_punctual` (point, spot, directional),
   placed like the geometry they belong to; ambient lights and the light-group kind go in `extras`. Use the
   decay range's outer size as a point light's `range`. Optionally an hour option that samples the `LITE`
   animations for the daylight (§1.4).
3. Carry the draw-order key (§2) into the export as `extras` on the mesh, and use it wherever the repository
   draws the sky itself.
4. A reader for `streamgraph.p3d` (§4) that lists the triggers and answers "what is loaded at x, z".
5. `docs/FORMATS.md`: describe all of the above in the house style, move `0x00122000` and lights out of the
   "not worked out" and "known gaps" lists, and credit this spec.

### Part 2 (after the first implementation was merged)

6. **One weather at a time** (§6): exports light the scene with the clear-weather group by default and the
   rain group only when asked (for example a weather option), the other group kept only as data; the sky
   and fog follow the same choice.
7. **The sky through the day** (§3.3, §3.4): with an hour, pose the sky's skeleton from `PTRN_sky` (shorter
   arc between keys) so the sun, flares and moon are where the game puts them, and give the sky meshes the
   colours of that hour (their own colours plus the sampled set, blending the two neighbouring sets).
   Without an hour, keep today's behaviour. Wherever the repository builds a whole city scene for Blender,
   put the sky in it, centred on the city and scaled to surround it, and say that the game moves it with the
   camera.
8. **Fog** (§5): read the fog for an hour and a weather (Miami or the islands) from the decompiled
   `EnvironmentObject`s, using `tod`'s key hours and its links to the objects, blending straight between
   key hours; put it in the export (for example in the scene's `extras`), and have the Blender scene the
   repository builds show it (for example as the world's mist from start to end distance, in the fog
   colour). Without the game's scripts, leave fog out and say so.
9. `docs/FORMATS.md` and the tests for all of it.

---

## Questions from the implementer, and answers

Asked by the implementer on 2026-11-12; answered by the examiner from the PC files where they could be.

| Question | Answer |
| :--- | :--- |
| Is text padded with the length byte counted? | No: the text alone is padded to a multiple of 4 (top of this spec, now corrected). |
| Spot cone: which angle is inner, and degrees or radians? | Not known, and there are no spot lights in the city's files to check against. Keep the numbers in `extras`. |
| Box and ellipsoid decay sizes: distances from the centre or whole sizes? | Not known yet *(check: compare an interior's light boxes with its walls)*. |
| Does a light without `0x00013008` add light? | Yes as far as can be told: no light in the city's files has that chunk. |
| Padding after the u16 frame numbers when the count is odd? | None (§1.4, checked). |
| "From" or "along" for the direction? | Along: the way the light shines (§1.1, §1.4 now say so). |
| Is frame = hour × 10 right for the `LITE` animations? | Yes: 241 frames for 24 hours is (number of frames − 1) × hour / 24 = hour × 10. How the game blends between keys is not known; straight lines are a reasonable reading. |
| Local directional lights as empty nodes? | Yes: they light only their decay range, which glTF can't express. |

### Part 2: questions from the implementer, and answers

| Question | Answer |
| :--- | :--- |
| Does `islands_LOD.p3d` have its own `tod` object? | Yes, with the same hours, linked straight to `island_environment_clear_<hour>` and `island_environment_rainy_<hour>` (checked). |
| Do the colour sets' vertex numbers run across the whole mesh or restart per primitive group? | Not settled; with the whole-mesh reading, the dome's and the clouds' first vertices come out exactly as §3.4 adds up (checked at noon and midnight). |
| How is a sky linked to `PTRN_sky`; does `rainy_skybox` have `PTRN_` or `VRTX_` animations? | By name is what the files support. The rain sky has no animations of its own (the only rain animations in `Common.p3d` are particle effects): it looks the same all day (checked). |
| Can a `VRTX` channel carry an interpolation-mode chunk? | None of the five in `Common.p3d` do; honouring one if present is right. |
| Padding after the frames in a quaternion channel with an odd key count? | None: `PTRN_sky`'s 21 keys read this way give exactly the heights in §3.3 (checked). |
| Fog blending when `FogEnabled` differs; blending alpha and clamp? | Fog is on in all 24 objects, so it never differs in the game's files. Alpha and clamp: their meaning isn't known; keeping them as blended data is fine. |
| Can the colour amounts go past 255? Are the fog colours screen (sRGB) colours? | Not in the sky's files: the largest sum is 216. The fog colours are 0 to 255 numbers in the scripts; treating them as screen colours is the plain reading. |
| The 1.1 margin round a city; the islands' fog for the islands? | The margin is the implementer's choice (the game has none: it moves the sky with the camera). The islands have their own fog (above), so a scene of the islands should use it. |
