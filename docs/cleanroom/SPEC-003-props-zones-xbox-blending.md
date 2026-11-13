# Clean-room spec 003: prop states, draw distances, and how the Xbox blends

* **Written by:** the examiner side (see [CLEAN_ROOM.md](../CLEAN_ROOM.md)), from published notes by a
  third party whose research was done next to leaked source code. The examiner read those notes; the
  implementer must not.
* **What this is:** a description of the game's *files* and of what the game *does* with them, in the
  examiner's own words. No code, and no names except ones this repository already has, text stored in the
  game's files (state, property, effect, world geometry and texture names), and class names the Xbox program
  itself carries (its run-time type information).
* **How sure:** **[checked]** statements were read back from the PC game files on 2026-11-13 with this
  repository's own tools (`p3d.py`, `media.py`) and small scripts that only count and compare.
  **[checked on the Xbox]** statements were read from the user's own `default.xbe` with
  `sf_binaries.BinaryImage` and a disassembler; addresses are the Xbox program's. **[reported]** statements
  describe what the PC program does; they come from the research and can't be checked from the files alone.
  *(check)* marks what is still open. If the files disagree with this spec, the files win: fix the spec in the
  same pull request.

Counts are over the 220 files in `packages/z04/` unless a section says otherwise. The Xbox's map files are the
PC's (`extracted/game_files/Exclusive to Xbox/` holds no `.p3d`), so what is checked on the PC files holds for
the Xbox's.

---

## 1. State prop data, in full

FORMATS.md has the outline of the `0x0802000D` family. This is all of it. Every one of the 1,009 in the city
was read.

### 1.1 `0x0802000D` State Prop Data **[checked]**

| Field | Seen |
| :--- | :--- |
| u32 version | 4 in all 1,009 |
| text: name | |
| text: the composite drawable's name | the same as the name in all 1,009 |
| u32 number of states | the number of `0x0802000E` sub-chunks, in all 1,009 |
| u32 number of properties | the number of `0x08020008` sub-chunks in 1,006. The three copies of `sshSignOwned` (in `cgrove_02_shell.p3d`, `nbeach_region_D.p3d` and `stripmall_01_shell.p3d`) say 6 and hold 5 |

Nothing follows the two numbers. Then come the sub-chunks: the properties first, then the states, in all
1,009. FORMATS.md has the two numbers the wrong way round ("u32 1, u32 number of states"): fix it.

**[reported]** The PC program reads the number of properties only when the version is 3 or more, and skips any
sub-chunk it doesn't know. Every file has version 4, so a reader may simply read both numbers.

The first property is always `name`, with the prop's name as its value (1,009 of 1,009). The others, with how
many props carry each:

| Property | Props | Values seen |
| :--- | ---: | :--- |
| `visibility` | 454 | `Tiny` 10, `Small` 148, `Medium` 179, `Big` 64, `Large` 18, `Huge` 35 |
| `surface_type` | 374 | |
| `hit_points` | 367 | |
| `movement` | 253 | `Person` 151, `Vehicle` 68, `Bullet` 16, `Collectable` 12, `Explosion` 4, `Static` 2 |
| `mass` | 230 | |
| `damaged_by` | 172 | |
| `wakeup_radius` | 118 | |
| `collision_test` | 97 | |
| `sway` | 81 | `Small` 5, `Normal` 64, `Extreme` 12 |
| `type` | 73 | `Effect` 36, `Door` 32, `Billboard-y` 3, `Ecoprop` 2 |
| `view_distance` | 73 | `Small` 1, `Medium` 12, `Big` 24, `Large` 31, `Huge` 5 |
| `class` | 39 | script class names (`SlotMachine`, `VideoPoker`, `ChainLinkGate`, `ai_targetable` ...) |
| `priority` | 37 | `Alpha` 35, `Scale` 2 |
| `explosion` | 29 | |
| `time_of_day` | 22 | `true` |
| `life_cycle` | 13 | `Fadeout_Short`, `Fadeout_Medium`, `Fadeout_Long`, `Fadeout`, `Reinstance` |
| `plugin_templates` | 13 | |
| `attract_type`, `script_context`, `cover`, `billboard`, `fadeout`, `destroys_tires` | 1 to 9 | |

What the game does with each property isn't covered here *(check)*; the exports only carry them.

### 1.2 `0x0802000E` Prop State **[checked]**

The state's name, then exactly 40 bytes in all 1,612 states: ten 4-byte values.

| # | Field | Seen |
| :--- | :--- | :--- |
| 1 | u32: the state moves on by itself | 1 in 107 states, 0 in 1,505 |
| 2 | u32: the state it moves on to, by its place in the prop's list of states, counting from 0 | always a state the prop has |
| 3 | u32: number of `0x08020002` sub-chunks (part visibility) | |
| 4 | u32: number of `0x08020003` sub-chunks (animations, §1.4) | 0 to 6 |
| 5 | u32: number of `0x08020004` sub-chunks | 0 in all |
| 6 | u32: number of `0x08020005` sub-chunks | 0 in all |
| 7 | f32: a frame | 0 in 1,492; else 10, 12, 20, 25, 30 (51 states), 35 ... 90, 100, 200, 400, 700 |
| 8 | u32 | 0 in all |
| 9 | u32: number of `0x08020008` sub-chunks (properties, §1.5) | 0 to 2 |
| 10 | u32: number of `0x0802000B` sub-chunks (effects, §1.6) | 0 to 11 |

Each count matches the state's sub-chunks of that kind in all 1,612. `0x08020004` and `0x08020005` never occur
in the files; a reader can skip them.

How fields 1, 2 and 7 work together, from the props that use them: a state with field 1 set is a passing one.
When its animation reaches the frame in field 7, the prop moves on to the state in field 2.

| Prop | States (field 1, field 2, field 7) |
| :--- | :--- |
| `smGateA`, `smDoorA` and the like | `idle` (0, 0, 0), `opening` (1, **2**, 30), `open` (0, 0, 0), `closing` (1, **0**, 30): opening ends open, closing ends idle |
| `sshGate` | `closed`, `opening` (1, 2, 90), `open`, `closing` (1, 0, 90) |
| `treeL`, `TreeQ`, `treeMangrove` | `idle`, `shake` (1, **0**, 30): a tree shakes, then stands still again |
| `theaterScreen` | `day`, `night` (1, 2, 200), `screen3` (1, 3, 200) ... `screen6` (1, **1**, 200): the night pictures go round and round |
| `wayPoint` | `discTurningOn` (1, 2, 30) ends in `discOn` |

Five states move on to themselves (`TreeP`'s `idle`, for one).

State names seen: `idle` 921, `final` 391, `new state` 69, `shake` 36, `open` 30, `closing` 30, `opening` 29,
`day` 19, `night` 19, `lockOn` 12, `damage1` 6, `closed` 4, `damage_1` 3, and 34 more.

### 1.3 `0x08020002` Part Visibility **[checked]**

As FORMATS.md has it: the part's name, u32 shown (1) or hidden (0). 2,851 of the 3,031 name a mesh in the same
file.

### 1.4 `0x08020003` Prop State Animation **[checked]**

A text, then three u32 and three f32: 24 bytes after the text in all 283.

* **The text** names a Frame Controller (`0x00121201`) in the same file, in all 283. In 280 of them there is an
  Animation (`0x00121000`) of the same name too (`BQG_identCopInstanceShape` in `Common.p3d`, for one).
* **The three f32** are two frame numbers and a speed. Both frames lie within the animation's frame count in
  274 of the 280. The first may be larger than the second (`wayPoint`'s `beamTurningOn` runs from 20 to 0), or
  equal to it, as in `discOn` (20 to 20) and `beamYellowOn` (23 to 23). The speed is 1 nearly always; 0.7, 0.5
  and 0.3 also occur.
* **The three u32:** the first is 0 or 1. All 77 with 0 are alike: the other two u32 are 0, the frames run
  from 0 to 0, and the speed is 1. They come in `idle` (38 times), `day`, `night`, `screen3` to `screen6`,
  `final`, `open`, `closed` and a few more, as if that state doesn't run the animation. The second is 0, 1 or
  2; the third 0 or 1. Common combinations: `idle` (1, 0, 0) 52 times; `open`, `opening` and `closing` (1, 1, 1) 47 times and (1, 1, 0) 29;
  `lockOn` (1, 1, 0) 11.

**[checked on the Xbox]** The Xbox's State Prop Data loader is found through the run-time type name
`StatePropDataLoader`; its loading function is at `0x0026ECB0`, and this sub-chunk's case is at `0x0026F0ED`. It
keeps each one in 28 bytes: the name's key, then the first u32 as a yes-or-no byte, the second as a number, the
third as a yes-or-no byte, then the two frames and the speed. What each one does wasn't found: no code was found
that reads them back *(check)*. A reader names them neutrally and keeps their values.

### 1.5 `0x08020008` Prop Property **[checked]**

Two texts: the property's name and its value. Under `0x0802000D` they are the prop's own (§1.1). Under a
state: `percent_damaged` 796, `collision_on` 105, `damaged_by` 25, `life_time` 1, `no_collision` 1. One prop
and one state each have a property with an empty name.

### 1.6 `0x0802000B` Prop State Effect **[checked]**

An effect the state sets off. All 1,593 have exactly this, with nothing after it:

| Field | Seen |
| :--- | :--- |
| text | `Effect` in all |
| text: the effect | 61 names: `epDebris_Dust` 345, `epDebris_Metal` 237, `epDebris_Wood` 166, `epDebris_Glass` 111, `epDebris_Foliage` 78, `epExplosion_Electric` 54 ... `fxSYS_WaterSurface_Sparkles`, `epFire_Burning` |
| u32 | 0 in all |
| text: a joint | a joint of the prop's skeleton in 1,539 |
| 3 f32: an offset from the joint | (0, 0, 0) 297 times, (0, 1, 0) 235, (0, 0.5, 0) 234; nearly always straight up |
| 3 f32: angles, in radians | (0, 0, 0) in 1,476; else values like 1.5708 (90°), 0.7854 (45°), 3.1416 |
| u32 | 0 in all |
| text | the same joint again, in all |
| f32: a size | 1 in 773; the others 0.1 to 10, and 0 in 3 |
| f32 | 0 in 1,471; else 0.4 to 90 (10, 4, 3, 20, 5 most often). What it is isn't known *(check)* |

57 of the 61 effect names are composite drawables in `Common.p3d`. The other four are
`fxSYS_Generic_Shack_Explode`, `epWater_DripSplash`, `epWaterfall_LrgeA` and `ambientFX_Blowing_Newspapers`.
Effects belong mostly to `final` states (1,287 effects): the debris when a prop breaks. Also `idle` 145, `shake`
78, `damage1` 22. The exports don't show effects.

---

## 2. A placed prop's starting state

**[checked]** The last of the twelve numbers of an `instanceposition` (`0x09900194`; FORMATS.md calls it *e*)
is 0 in 47,597 of the 47,631 placements, 1 in 20, 8 in 13, 2 in 1. It names the state that copy starts in, from
a fixed list in the program. 0 means the prop's own first state.

| Number | State | Number | State |
| ---: | :--- | ---: | :--- |
| 1 | `idle` | 7 | `explosion` |
| 2 | `final` | 8 | `open` |
| 3 | `damage_1` | 9 | `opening` |
| 4 | `damage_2` | 10 | `closed` |
| 5 | `damage_3` | 11 | `closing` |
| 6 | `damage_4` | | |

**[checked on the Xbox]** The function at `0x00314890` turns these eleven names, in this order, into keys
(through `0x00244040`, with 0 as the second argument). It stores them one after another at `0x004815E8` to
`0x00481610`, so number *n* is the *n*-th of them.

**[checked]** The files agree. Every placement with 8 is a door or gate whose prop has an `open` state:
`tmdoora` 6 times, `doordoubleb` twice, `tigatea` twice, and `doordoublea`, `doorvelveta` and `phelevatordoor`
once each. Every one with 1 is a prop with an `idle` state, and the one with 2 is `tmrailinga`, which has
`final`. The number isn't the state's place in the prop's own list: `tmdoora`'s states are `idle`, `opening`,
`closing` and `open`. The state is found by its name, with letter case ignored. A prop without a state of that
name starts in its first state.

---

## 3. Zone packages: each world geometry's draw distance

### 3.1 The chunks **[checked]**

`0x08800004` Zone Package is as FORMATS.md has it (the area's name, a count, that many World Geometry names).
After it come one `0x08800009` sub-chunk per name listed: the same names, in all 152.

`0x08800009` Zone Package Entry (420 in the city):

| Field | Seen |
| :--- | :--- |
| text: a World Geometry's name | always one in the same file |
| u32 number of floats | 6 in all 420 |
| f32 near | 0 in 412; the others are in the table below |
| f32 far | 10000 (177), 500 (46), 700 (27), 600, 1000, 800, 400, 100, 300 ...; the smallest 10 |
| f32 fade | 5 (209), 15 (116), 10 (76), 20 (9); 1 to 100 |
| f32 | 0 in all |
| f32 x of a reference point | |
| f32 the reference point's z, with its sign flipped | both 0 in 49 |

The sign was checked against the geometry. With the sixth number negated, the point (*x*, *z*) lies within 5
units of the box round the world geometry's meshes, joints added, in 303 of the 359 that have a point. Without
the negation it does in 17, and all 17 fit both ways. The rest lie near their geometry, not in it: skylines,
for example.

### 3.2 What the game does with them

**[reported]** The PC program reads these when it loads the zone package. A world geometry is drawn only while
the camera is farther than *near* and nearer than *far*, and it fades over *fade*. The distance is measured from
the reference point (at height 0) when there is one, else from the world geometry itself. The list of names
before the sub-chunks isn't used by the game. Exactly how the fade runs *(check)*.

**[checked]** The files fit this. The entries with a *near* above 0 are all far-away stand-ins, which must
vanish when the real thing is close:

| World geometry | File | near | far |
| :--- | :--- | ---: | ---: |
| `fadeout_bankwindows` | `cgrove_01_shell.p3d` | 40.8 | 300 |
| `fadeout_hotelwindows` | `cgrove_01_shell.p3d` | 70 | 300 |
| `fake_dock` | `sbeachn_04_detail.p3d` | 83.9 | 388.8 |
| `fake_bridge` | `sbeachn_04_shell.p3d` | 88.3 | 926.8 |
| `cargo_LOD` | `FountainRock_01_shell.p3d` | 112.4 | 10000 |
| `fake_tunnel` | `sbeachn_02_shell.p3d` | 211 | 743 |
| `low_LOD_1sbeachn_07` | `miami_lod.p3d` | 581 | 10000 |
| `low_LOD_fr_lod` | `islands_LOD.p3d` | 1370.4 | 5000 |

The smallest *far* values belong to interiors and close-up detail, such as `babylonclub_02_detail` (30),
`lxrbank01d_lod_1` (35) and `uginbar`'s `shadowed_decals` (30.3). Two world geometries are never drawn unless
the camera is within 10 of their point: `unused_delete` (`DevilsCay_02_shell.p3d`) and `delete_me_grp`
(`tranq_03_detail.p3d`).

---

## 4. World Geometry kinds **[checked]**

The u32 at the end of `0x08800003` (FORMATS.md: "flags") goes with the start of the world geometry's name:

| Value | World geometries | Names start |
| ---: | ---: | :--- |
| 0 | 331 | anything else (`shells_`, `details_`, `skyline_`, `fake_` ...) |
| 1 | 16 | `shadowed_` |
| 3 | 3 | `low_LOD_` |
| 5 | 47 | `underwater_` |
| 6 | 12 | `cbvlitdecals_` |
| 7 | 9 | `interiorfloors_` |
| 8 | 2 | `cardsnight_` |

No other value occurs. How each kind is drawn isn't covered here.

---

## 5. Occluders, `0x0880000A` **[checked]**

1,022 in 31 files, each exactly 44 bytes with no name and no sub-chunks:

| Field | Seen |
| :--- | :--- |
| 3 f32: a position | in the map's space |
| 3 f32: the way it faces | a unit vector with y 0 in all |
| u32 | 0 in 1,021, 1 in 1 |
| f32 | 0 in all |
| 3 f32: sizes | for example 2.249, 10, 56.05: the box's full width along the world's X, Y and Z (below) |

**How the Xbox makes the box [checked on the Xbox].** The loader is found through the run-time type name
`OccluderLoader`; its loading function is at `0x00047AF0`.

* It names each occluder `OccluderObject_<n>`, counting up.
* It reads the fields in the order above.
* The box is lined up with the world's axes: the position minus half of each size, to the position plus half of
  it (the 0.5 at `0x0039D580`). Then it puts the box's bottom at a height of −1 (the −1.0 at `0x0039D65C`).
  So a box reaches from just below the ground up to the position's height plus half the second size.
* The way it faces doesn't turn the box. It keeps it as an angle, the arctangent of its x over its z.
* It keeps the u32 as two yes-or-no flags: 1 sets both, 2 sets only the first. Only 0 and 1 occur in the files.
* It skips the f32 that is always 0.
* Then it registers the occluder (`0x00047480`) in a list of up to 256.

For the first occluder in `DevilsCay_03_shell.p3d` (position −3247.4, 13.8, −10240.3; sizes 2.249, 10, 56.05),
that is a box 2.25 wide in X and 56 long in Z, from −1 to 18.8 high: a wall along the Z axis.

**[reported]** Occluders are invisible. The game uses them only to skip drawing what is hidden behind them.

---

## 6. Characters and vehicles, `0x08800000` and `0x08800001` **[checked]**

Each holds exactly eleven texts and nothing else. The 323 characters were read in `art/characters/**` and the
144 vehicles in `art/vehicles/`.

1. the name;
2. the model: a skin for a character (`AA_Female_01_meshShape`), a composite drawable for a vehicle
   (`albatross`);
3. its low-detail model (`AA_Female_01_lowshape`, `albatross_LOD`), empty in 21 characters;
4. to 11. eight shader names. The unused ones are empty: in the file, an empty text is the 4 bytes
   `03 00 00 00`, which FORMATS.md read as "u32 3". Characters use 0 to 3 of them (`AA_Female_01_SG`), vehicles 1
   to 6 (`albatross_mt`, `amphib_plane_clut2_mt`, `antique_racervehicleShader`).

FORMATS.md's rows ("then nine u32 (3 in every file seen)"; "the paint shaders' names, then three u32") are to be
replaced by this. **[reported]** The game finds those shaders by name. What it does with them isn't covered
here *(check)*.

---

## 7. The water chunks' names **[checked on the Xbox]**

The Xbox program's loader classes for the three water chunks are known from their run-time type names. Each
class's virtual table is used next to the chunk id it handles, at `0x0014D487`, `0x0014D4C2` and `0x0014D4FD`:

| Id | Class |
| :--- | :--- |
| `0x08800201` | `WaterDataShallowAreaLoader` |
| `0x08800202` | `WaterDataObstacleLoader` |
| `0x08800203` | `WaterDataDockLoader` |

`p3d.py` has the first and the last swapped: `0x08800201` must be "Water Shallow Area" and `0x08800203` must be
"Water Dock". FORMATS.md's loader table lists them in the wrong order too. **[checked]** `0x08800201` chunks
are the only ones with sub-chunks: `0x08800200`, 5 to 27 each, in `miami_lod.p3d` and `islands_LOD.p3d`. They
are named like `transform245_ShallowWaterArea3`; the other two like `transform245_WaterObstacle7` and
`transform246_CallBoatArea19`.

---

## 8. Two questions answered from the Xbox program

### 8.1 How `BLMD` 3 darkens: it subtracts **[checked on the Xbox]**

SPEC-002 left this open. In `default.xbe`:

* A shader's `BLMD` setting goes to a setter found through the shader's table of settings. For one shader
  kind, the `BLMD` entry is at `0x0045F688`, and its function is filled in at `0x00320E68`. That setter
  (`0x0029A390`) stores the value at offset `0x18` and calls `0x0029A2F0`. That copies it to offset `0x1C`, with
  one exception: when the value is 0 and the number at offset `0x38` isn't 0, it writes 1 instead.
* `0x00282950` takes the number at offset `0x1C` and uses it to pick one of eight 16-byte entries at
  `0x0045C188`. Each entry holds a byte (blending on or off), the blend equation, and the source and destination
  factors as indexes. It hands them to `0x00282820`, which sets the render states. The indexes go through a
  table at `0x0045C208` that holds Direct3D's blend factor values in this order: zero, one, source colour,
  1 minus source colour, destination colour, 1 minus destination colour, source alpha, 1 minus source alpha,
  destination alpha, 1 minus destination alpha, source alpha saturated, and two more.

The eight entries (`0x8006` is Direct3D's "add" equation, `0x800B` its "reverse subtract"):

| `BLMD` | Blending | Equation | Source factor | Destination factor | So the colour is |
| ---: | :--- | :--- | :--- | :--- | :--- |
| 0 | off | add | one | zero | the surface's |
| 1 | on | add | source alpha | 1 minus source alpha | ordinary see-through |
| 2 | on | add | one | one | what is behind **plus** the surface's colour; alpha plays no part |
| 3 | on | reverse subtract | one | one | what is behind **minus** the surface's colour (not below 0); alpha plays no part |
| 4 | on | add | destination colour | zero | what is behind times the surface's colour |
| 5 | on | add | destination colour | source colour | twice what is behind times the surface's colour |
| 6 | on | add | destination colour | source alpha | |
| 7 | on | reverse subtract | source alpha | source alpha | |

Only 0 to 3 occur in the files. Mode 2 is what SPEC-002 found for the light-adding surfaces. Mode 3
subtracts; it doesn't multiply.

**[checked]** The pictures agree. `r_tonymsn_shadow_circle.bmp` (`tonymansion_region.p3d`, 32 × 32, opaque) is
a soft grey disc, 72 out of 255 in the middle, on black corners. Subtracted, it is a round shadow with no edge.
Multiplied, it would be a black square. `SkidMark_Asphalt.bmp` (`Common.p3d`) is grey 7 to 20 all over:
subtracted, a faint mark on the road; multiplied, nearly black.

**The PC has the same table [checked in the PC program's data].** The PC program's code is encrypted in
`Scarface.exe`, so its use of the table can't be followed. Its data isn't encrypted, though. At `0x007EC848`
(`.data`) there are the same eight 16-byte entries, with Direct3D 9's numbers for the equations (1 add, 3 reverse
subtract):

* entry 0: off, add, one, zero;
* entry 1: add, source alpha, 1 minus source alpha;
* entries 2 and 3: add and reverse subtract, each with one and one;
* entries 4 to 7: as on the Xbox.

Straight after the entries (`0x007EC8C8`) comes the table of blend factors, in the Xbox's order, with Direct3D
9's numbers: 1, 2, 3, 4, 9, 10, 5, 6, 7, 8, 11 and two more. So `BLMD` 3 subtracts on the PC too. The table is
checked; that the PC program picks its entries the way the Xbox does is assumed.

### 8.2 Shadow decals on the Xbox: drawn **[checked on the Xbox]**

SPEC-002 reported that the PC never shows the shadow decals. The Xbox does show them:

* **The world geometry loader.** It is found through the run-time type name `WorldGeoLoader`; its loading
  function is at `0x00056720`. It gives every primitive whose shader is of the `shadowdecal` kind its own
  draw-list number, 37 (`0x00056943`). The same loader uses other numbers for the other kinds: 29 for `foam`,
  33 for `vertexfade` and `untextured`, and so on.
* **The display list.** Its class is `Display_List`, and its adding function is at `0x00043730`. It sends
  number 37 to list 7 or list 8 (the jump table at `0x00043C68`, case at `0x00043ACB`).
* **The frame.** The frame's drawing function (`0x000449F0`) calls `0x00042AB0` at `0x00044D2F`, which draws
  everything in lists 7 and 8. It does so whenever either list holds anything and the byte at `0x0041C922` is
  set. That byte is 1 in the file, and no code in the program writes it.
* **The pass.** `0x00042AB0` wraps the drawing in a render-context extension's begin and end: id `0x108`, class
  `d3dExtStaticShadowGen`. Its end (`0x002A34A0`) puts the result on the frame with a full-screen quad, in two
  passes:
  * first with blending "zero, 1 minus source alpha": the frame times 1 minus the coverage, once however many
    decals overlap;
  * then a pass that writes alpha only.

  Read in full, that end works like this. The decals are drawn into the alpha of a picture of their own (the
  texture at offset `0x14` of the extension and its surface at `0x18`). The begin cleared that alpha to 0 with
  the Xbox's alpha-only clear and writes nothing but alpha.

  1. The coverage is multiplied by the frame's own alpha.
  2. The frame becomes the frame times (1 − coverage × 0.647). The full-screen quad's alpha is the texture's
     alpha times the texture factor, which `0x0032CD10` sets to 0.65 × 255, truncated to 165 (the float at
     `0x0045FCBC` times the 255.0 at `0x003A0FC4`). The texture stage multiplies the two: alpha operation
     *modulate*, texture and texture factor. The blending is "zero, 1 minus source alpha". Pixels whose alpha
     is 0 are skipped (alpha test "greater than 0").
  3. A pass that writes alpha only.

  So **a shadow decal darkens what is under it by at most about 65 %** (165 out of 255), however dark its
  texture. What the frame's alpha holds at step 1 isn't settled *(check)*.

So on the Xbox, shadow decals darken what is under them by their coverage, and overlapping decals don't darken
twice. That is what SPEC-002 said they were meant to do. Why the PC doesn't show them is outside this spec.

---

## 9. What to build

1. **`p3d.py`.**
   * Names, ours: `0x0802000E` "Prop State", `0x08020002` "Part Visibility", `0x08020003` "Prop State
     Animation", `0x08020008` "Prop Property", `0x0802000B` "Prop State Effect", `0x08800009` "Zone Package
     Entry". Fix `0x08800201` to "Water Shallow Area" and `0x08800203` to "Water Dock" (§7).
   * Field readers (`p3d.fields`) for `0x0802000D`, `0x0802000E`, `0x08020002`, `0x08020003`, `0x08020008`,
     `0x0802000B`, `0x08800009`, `0x0880000A`, `0x08800000` and `0x08800001`, as §1, §3, §5 and §6 lay them
     out. Use neutral names where the meaning is open.
   * The `0x09900194` reader also gives the starting state's name (§2), or nothing for 0.
   * Keep reading short or damaged chunks without throwing, as the other readers do.
2. **Placed props start in their starting state** (§2), in `p3d_gltf.py`. When the prop has a state of that
   name, with letter case ignored, its parts are shown as that state has them. Otherwise it gets the first state,
   as now. The copy's node says `{"state": "<name>"}` in its extras when that isn't the first state. A prop's
   file opened on its own is unchanged.
3. **Draw distances on world geometry** (§3), in the map export. Each world geometry's top node gets in its
   extras the near, far and fade of its zone package entry, and the reference point when there is one. The
   point goes through the same conversion as every other position, at height 0. The node's extras also give
   the world geometry's kind (§4) as its number.
4. **Far-away stand-ins are hidden.** A world geometry whose *near* is above 0 gets `"hidden": true` in its
   extras, as the low-detail hull does, and the report says so once per file. This covers the `fake_` ones,
   `cargo_LOD`, the `fadeout_` windows and the two `low_LOD_` ones. **Open in Blender** already hides nodes
   marked this way. Check that it does for these too.
5. **`BLMD` 3 subtracts** (§8.1). `p3d_gltf.darkening` makes the picture black with an alpha of its
   brightness, the largest of its red, green and blue. It was 1 minus its luminance. Blended as usual, what is
   behind ends up times (1 minus the brightness). That is close to subtracting the brightness where what is
   behind is bright, and black still darkens nothing. The cut-out stays as it is. The Blender material (a
   Transparent BSDF of 1 minus the picture's alpha) stays as it is, but now means 1 minus the brightness: fix
   its comment. The extras keep `"blend": "darken"`. Bump `EXPORT_VERSION` so exports made before are made
   again. The portal's 3D view needs no change: it draws these with ordinary blending.
6. **FORMATS.md.**
   * Correct the `0x0802000D` and `0x0802000E` rows, add rows for the new chunks, and fix the
     Character/Vehicle rows, the World Geometry kinds and the water loaders' order.
   * In the instance record, say what *e* is.
   * In the blend-mode table, replace "darkens; exactly how isn't known" with what §8.1 found on the Xbox, and
     the 3 row of the export table with the new picture.
   * Point to this spec where its facts are used, as the SPEC-001 and SPEC-002 sections do.
7. **Tests** on made-up files for every reader and for items 2 to 5. Keep each file's line endings as they are.
8. **Prop properties in the exports.** A placed copy's node gets the prop's own properties in its extras, as
   `"properties": {"<name>": "<value>", ...}`, texts as the file has them. These are the `0x08020008`
   sub-chunks straight under its `0x0802000D` (§1.1), leaving out `name`, which is the prop's name. A prop's file
   opened on its own gets them on the prop's top node. A state's own properties (§1.5) aren't carried. **Open in
   Blender** gets them as custom properties through the importer, with nothing more to do: check that.
9. **Shadow decals** (§8.2).
   * The export's report line says the Xbox draws them and the PC is reported not to, instead of "the PC game
     never shows them".
   * FORMATS.md's [Shadows](../FORMATS.md#shadows) section says so too, with the 0.65 left marked
     *(check)*.
   * The exports stay as they are: the decals stay shown, as black see-through surfaces.
10. **FORMATS.md** also gets §8.1's PC table, in the "On the Xbox" paragraph under the blend modes.
11. **Tests** on made-up files for item 8, and the report line in item 9. Keep each file's line endings.

---

## 10. Answers to the implementer's questions

1. *A kind on every world geometry, not only those with a zone package entry?* Yes, as built.
2. *Should a far-away stand-in stay hidden when its area is exported on its own?* Yes. The game hides it whenever
   the camera is closer than *near* to its point, and an area on its own is looked at from close by. It stays one
   tick away in Blender.
3. *Should the prop properties go into the exports?* Yes: work item 8.
4. *Starting-state numbers 12 to 15 get the first state?* Yes. The game keeps 4 bits, and no file uses them.
5. *The names for the open fields?* Fine as built.
6. *Two zone package entries for one world geometry: the first wins?* Fine; no file has two.
7. *The number of properties read only from version 3 on?* Yes, as §1.1 reports.
8. *Should the later-state copies of a prop opened on its own carry the properties too?* No need: they stand
   beside the prop, which has them.
9. *Is the 0.65 a limit on how far shadow decals darken?* Still open, as §8.2 says; the exports don't depend on
   it.

---

## 11. Part 3: what to build from the new answers

1. **Shadow decals darken by at most 65 %** (§8.2). In every export, a material made from a `shadowdecal` shader
   gets its alpha multiplied by 0.647 (165 / 255): `baseColorFactor`'s alpha, the texture unchanged. Blended as
   usual over what is behind, the black decal then leaves at least 35 % of it, as the Xbox does. Overlapping
   decals still darken twice in an export, unlike the game: say so where FORMATS.md describes the decals. The
   exports' report line and FORMATS.md's Shadows section give the limit, and the *(check)* on it goes.
2. **Occluders in map exports** (§5). Each occluder becomes a node:
   * the box the Xbox makes, as a unit cube's mesh moved and scaled into place;
   * the position, converted as every other position is;
   * extras `{"occluder": {"facing": [x, y, z], "flags": <the u32>}, "hidden": true}`.

   One cube mesh is shared by all of them, with an untextured see-through material. **Open in Blender** puts them
   in an *Occluders* collection of their own, switched off, drawn as wireframe. The portal's 3D view already
   leaves hidden nodes out. The report says how many there are once per file.
3. **FORMATS.md:** the occluder row and paragraph (the box, the flags), the Xbox's 0.65 limit in the Shadows
   section, and the Xbox's way of keeping the Prop State Animation's three numbers.
4. Bump `EXPORT_VERSION` (now 10) once for items 1 and 2.
5. **Tests** on made-up files for items 1 and 2. Keep each file's line endings.
