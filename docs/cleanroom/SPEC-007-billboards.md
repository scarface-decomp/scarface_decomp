# Clean-room spec 007: billboards (the sun, flares, light glows, markers)

* **Written by:** the examiner side (see [CLEAN_ROOM.md](../CLEAN_ROOM.md)). The examiner has read published
  notes by a third party whose research was done next to leaked source code. Everything below was then
  read again, in the examiner's own words, from the US game files and the user's own Xbox `default.xbe`.
  The implementer must not open the notes.
* **What this is:** the camera-facing quads the game draws for glows and markers, chunk `0x00017006` and
  its sub-chunks. The repository knows the chunk id but leaves billboards out of every export and the
  viewer, so the sun, the moon, street-lamp flares, car lights and the mission markers are missing.
  1. where billboards are used;
  2. the chunks, field by field;
  3. how a group is drawn, and the six ways a quad can face the camera;
  4. the fading cones and the size pair;
  5. the animations that drive them;
  6. the Xbox functions, for matching;
  7. what to build.

  No code, and no function names: the implementer chooses names. The class names below are the game's own,
  from the Xbox program's run-time type information.
* **How sure:** **[checked]** was read from all 302 billboard groups in the US PC files (1.00.2) with the
  repository's chunk reader. **[checked on the Xbox]** was read from `default.xbe` with a disassembler; its
  reader takes the same layouts. *(check)* marks what is still a reading. If the files or the programs
  disagree with this spec, they win: fix the spec in the same pull request.

---

## 1. Where billboards are used **[checked]**

302 groups in 101 PC files, 686 quads in all. Every chunk and sub-chunk is version 0.

| Where | Groups | What they are |
| :--- | ---: | :--- |
| `packages/z04/Common.p3d` | 44 | the sky's sun and moon with the sun's flare stars and lens flares (SPEC-001 §3), the mission and interaction **markers** that float over people and things (`identCopInstanceShape`, `identMoneyInstanceShape`, `identGunInstanceShape` and ten more `ident*InstanceShape`, `targetBracketInstanceShape`), the waypoint shafts (`wayPointBBShaftShortShape`, `...TallShape`), generic car-light glows (`BrakeLight_glowShape`, `TailLight_glowShape`, `RedLight_glowShape`, `GreenLight_glowShape`), a rainbow, seagulls, water ripples, a blood puddle, a muzzle flash and a light beam |
| `art/vehicles/*.p3d` | 120 | tail lights and reversing lights on 30 cars (a pair each), and the flashing lights of the police car, police boat, ambulance, DEA van and SWAT van |
| other `packages/z04/*.p3d` | 75 | street-lamp flares (`streetLightFlareAShape`, `...BShape`), lamp glows, interior light glows in the clubs, bars and mansion, the drive-in's six screens (`theaterScreen1QuadShape` to `6` in `drivein_01_shell.p3d`) |
| `packages/dzones/`, `azones/`, `art/ecoprops`, `art/levels`, `art/nis` | 63 | buoy lights on the sea, building-site and railyard lamps, and a few more |

Shader names say what they look like: nearly all are `BLMD` 2, light that **adds** to what is behind
(SPEC-002 §1.2), with textures such as `flareLightA.bmp`, `flarebasecircle.bmp`, `l_lampglow.bmp`,
`glow001_mt`, `PoliceLight_RedGlow`. Drawn with ordinary blending they come out as dark squares.

---

## 2. The chunks

### 2.1 `0x00017006` Billboard group **[checked] [checked on the Xbox]**

```
u32     version (0)
text    name                 the name a composite drawable (0x00123000) uses for it
text    shader               a shader (0x00011000) in the same file, found by name
u32     cut-off group        1: the game makes the bigger group kind (below). 0 in all 302
u32     depth test           1 in 299
u32     depth write          0 in all 302
u32     occlusion test       1 only for three sky groups (2 lens flares, 1 flare star); 0 elsewhere
u32     quad count
```

The text fields are the usual Pure3D length-prefixed strings. If the shader is missing, the Xbox prints
`warning : shader "%s" not found for billboard quad group "%s"` and uses a shader named `error`.

Sub-chunks, in the order the files have them:

| Chunk | Count | What |
| :--- | :--- | :--- |
| `0x00017005` | the quad count | one quad each (§2.2) |
| `0x00017007` | 1 | the group's own placement (§2.3); in 301 of 302 it does nothing (rotation 0,0,0,1 and position 0) |
| `0x00010003`, `0x00010004` | 1 each | bounding box and bounding sphere, as on a mesh |
| `0x00122000` | 1 | the draw-order key (SPEC-001 §2), which the game clamps to 0..1. 0.5 in 296 groups |
| `0x00121204` | 0 or 1 | a list of frame controllers (§5): u32 version, u32 count, then that many `0x00121201`. 121 groups have one |

The game keeps a group as two objects. The **`BillboardObject`** is a drawable container, 0x5c bytes on the
Xbox, with a size multiplier at +0x58 that starts at 1.0. Other objects find it by the group's name. It
holds one **`BillboardQuadGroup`** (0x94 bytes) or **`BillboardCutOffQuadGroup`** (0xc8 bytes, when the
cut-off word is 1). Group fields on the Xbox: placement +0x38, the size multiplier it is drawn with +0x78
(the container copies its own in for the draw, then puts 1.0 back), depth test +0x80, depth write +0x81
and occlusion +0x82 (bytes), the quads +0x84, the occlusion number +0x90. A cut-off group also reads its
own `0x0001700A` to `0x0001700C` (§4), at +0x94 to +0xc4; no group in the files has them.

### 2.2 `0x00017005` Billboard quad **[checked] [checked on the Xbox]**

```
u32     version (0)
text    name                 what a BQG animation group is matched to (§5)
u32     cut-off quad         1: the quad can fade with the cones of §4. 1 in 202 quads
u32     world-size           1: width and height are in world units. 0: the quad keeps the same size on
                             screen however far away it is. 1 in all 686
u32     facing               a four-character code: AAX, YAX, NOAX, XAX, LXAX or LYAX (§3.2)
u32     colour               A R G B, read as one little-endian number (so the bytes are B G R A)
f32     width                the FULL width; the game halves it as it reads it
f32     height               the full height, halved the same way
f32     pull                 how far the quad is moved towards the camera (§3.3). 0 in 392 quads; 0.1 to 2.2
                             elsewhere (street-lamp flares 0.3 to 1.0), and -0.6 once
```

**Visibility is not in the record**: a quad starts shown, and only a `VIS` animation channel hides it (§5).
The second word is easy to take for visibility, but the Xbox uses it only to decide whether the size stays
constant on screen (§3.2).

Facing codes are stored as text, padded with a zero (`AAX\0`, `YAX\0`, `XAX\0`). The game turns them into
numbers (`LYAX` is 5, `LXAX` 4, `YAX` 3, `XAX` 2, `AAX` 1, `NOAX` 0), and **a code it doesn't know counts
as `AAX`**. In the PC files: `AAX` 418 quads, `YAX` 209, `NOAX` 49, `LYAX` 9, `LXAX` 1, `XAX` none.

Every quad has one `0x00017007` and one `0x00017009`. The 202 cut-off quads also have `0x0001700A` and
`0x0001700D` (200 of them) or `0x0001700B` and `0x0001700D` (the two lens flares). No file has a
`0x00017008` or a `0x0001700C`, and no plain quad has any of the cut-off chunks.

Two kinds on the Xbox: **`BillboardQuad`** (0xc4 bytes) and **`BillboardCutOffQuad`** (0x108 bytes). Fields:
shown +0x34 (byte, starts at 1), colour +0x38, placement +0x3c, half-width +0x7c, half-height +0x80, pull
+0x84, world-size +0x88 (byte), facing +0x8c, texture mode +0x90, the four texture corners +0x94 to +0xb0,
texture offset +0xb4 and +0xb8, strip frame +0xbc, strip length +0xc0. A cut-off quad adds the cones at
+0xc4 to +0xec, the size pair at +0xf0 to +0xfc and the distance fade at +0xcc, +0x100 and +0x104.

### 2.3 `0x00017007` Placement **[checked] [checked on the Xbox]**

```
u32 version; f32 rotation x, y, z, w (a quaternion); f32 position x, y, z
```

Always 32 bytes. On a quad it places the quad inside its group; 230 quads are turned, the rest are not. On
a group it places the whole group. Only one group's placement does anything: one in `bsand_02_detail.p3d`
is moved to (-3773.0, 11.25, -8172.7). Its rotation, (0, 0, 0, -1), is no turn at all.

### 2.4 `0x00017009` Texture corners **[checked] [checked on the Xbox]**

```
u32     version
u32     random u             1: pick a new random u offset (0 to 1) every time the quad is drawn
u32     random v             1: the same for v
f32     u, v  four times     the texture coordinates of the four corners, in the order the corners are
                             built (§3.2): (-w,-h), (+w,-h), (+w,+h), (-w,+h)
f32     u, v                 a texture offset added to all four
```

Always 52 bytes. The two words set the texture mode: random u only 3, random v only 4, both 5. Both are 0
in every file, and so is the offset. The corners are (0,0) (1,0) (1,1) (0,1) in 528 quads and the same
upside down, (0,1) (1,1) (1,0) (0,0), in 108; a few pull them in by a hundredth to keep the texture's edge
off the quad.

### 2.5 `0x00017008` Texture strip **[checked on the Xbox]**

For a texture holding several frames side by side. Not in any US file, so only in outline:

```
u32 version; u32 random; u16 frames; u16 first frame
```

The game makes each frame 1/frames of the texture's width and keeps the frame number no higher than the
frame count. Random 0 sets texture mode 1: the frame comes from the quad's `FSF` channel (§5). Random 1
sets mode 2: a random frame every time the quad is drawn.

### 2.6 The cut-off chunks **[checked] [checked on the Xbox]**

Read only when the quad's (or group's) cut-off word is 1, except `0x0001700D`, which the game reads for any
quad. A writer must not put `0x0001700D` on a plain quad: the plain kind has no room for it.

```
0x0001700A  facing cone  u32 version; u32 which (BOTH, VERT or HRZT); f32 four angles, in radians
0x0001700B  view cone    the same layout
0x0001700C  distance     u32 version; u32 kind (LINE or anything else); f32 near; f32 far
0x0001700D  size pair    u32 version; f32 a, b, c, d
```

* **Which:** `BOTH` means 3 (both cones), `VERT` 1 and `HRZT` 2; any other word, 0 (no cone). All the files
  have `BOTH`.
* **The four angles** are an inner and an outer angle for the up-and-down cone, then the same for the
  side-to-side cone. The game keeps their **cosines**, not the angles. In the files:

  | Facing cone (degrees) | Quads | Used by |
  | :--- | ---: | :--- |
  | 20, 30, 35, 65 | 123 | car tail lights and reversing lights, `TailLight_glowShape` |
  | 60, 90, 60, 90 | 24 | lamp glows in the city |
  | 80, 90, 80, 90 | 22 | glows in the side areas; the sun's two flare stars |
  | 50, 90, 50, 90 | 14 | the DEA and SWAT vans' lights, some lamps, a spare pair of lens-flare quads |
  | 70, 90, 70, 90 | 6 | the ambulance's lights |
  | others | 11 | 90/90 (3 quads), 45/90 (2), and one each of 30/90, 20/90, 20/25, 50/70, 25/35/75/90 (`BrakeLight_glowShape`), 40/70/65/90 (`fxBB_GlowShape`) |

  The view cone is only on the sky's two lens flares: 10, 90, 10, 90 and 10, 60, 10, 60.

* **Distance (`0x0001700C`):** `LINE` gives 1 nearer than *near*, 0 at *far* and beyond, and a straight
  line between. Any other kind gives 1 always. Not used in the US files.
* **Size pair:** (1, 1, 1, 1) in 200 quads. The two flare stars have 1.0 twice then 1.3 twice, and
  1.6 twice then 1.8 twice: §4 turns these into a size multiplier of 1.3 and 2.88.

---

## 3. Drawing a group

### 3.1 Each quad, each frame **[checked on the Xbox]**

Every quad of a group goes into a single list of triangles, two per quad, drawn in one call with the
group's shader. First it works out **the group's fade**:

* 1 to start with.
* An extension of the renderer's, which the program looks up by the id `0x00200300` and whose class is
  `d3dExtTODFactor` (a time-of-day factor), holds a number *k*. With the occlusion word set, the fade is
  §3.4's fraction × (1 − *k*). Without it, the fade is 1 − *k*, but only when the extension says it is
  switched on. *(check: what sets k, and when it is on. A likely reading: glows fade out by day.)*
* × the group's own cones: 1 for a plain group, §4 on the group's frame for a cut-off group (none in the
  files).

Then, for each quad:

1. Skip it if it is hidden (§5).
2. Work out its world placement: its own placement, then the group's, then wherever the group's model
   sits (for the sky, SPEC-001 §3: the sky turns with the sun joint and is drawn at twice its size).
3. Start with **fade** = the group's fade and **size** = the container's size multiplier (1.0). A cut-off
   quad then works both out again by §4: the fade is multiplied, and the size is replaced.
4. Skip it if fade is 0 or less, or size is 0.
5. Build its four corners by its facing (§3.2), using half-width × size and half-height × size.
6. Texture coordinates: the four corners plus the offset (§2.4).
7. Colour: if fade isn't 1 (within 0.00001), multiply **all four bytes, alpha too,** by fade.

Before drawing, the group sets depth writing to its depth-write word. If its depth-test word is 0, it makes
the depth comparison always pass. It also switches one more render setting off for the draw *(check: it
looks like fog)*. Afterwards it puts all three back. With the files' values, glows are hidden behind walls
but never hide anything themselves. The three sky groups with the occlusion test draw with no depth test
and fade by §3.4 instead.

### 3.2 The six ways to face the camera **[checked on the Xbox]**

A flat quad has corners (-w,-h,0), (+w,-h,0), (+w,+h,0), (-w,+h,0) in the frame it is built in.

* **`AAX`, all axes (418 quads):** the classic sprite. Take the quad's world position, apply the pull
  (§3.3), and set the corners off from it in the directions that point right and up on the screen. If the
  world-size word is 0, w and h are first multiplied by the quad's distance in front of the camera, so it
  keeps one size on screen. The markers, the car lights and all the sky but one flare star are `AAX`.
* **`NOAX`, no axis (49):** doesn't turn at all: the flat quad in its world placement. Ripples, the blood
  puddle, seagulls and some wall-mounted glows.
* **`YAX`, the up axis (209):** stays upright and turns only about the world's up (y) direction to face the
  camera, like a cardboard tree. The game builds a turn whose forward axis is the level direction from the
  camera to the quad, (dx, 0, dz) made unit length, with up (0, 1, 0). It applies the quad's own rotation
  first and that turn second, then moves the result to the quad's world position. The parent's rotation
  and scale are not used, only its position. Then it builds the flat quad in that frame. Interior glows,
  the waypoint shafts and one sun flare star use it.
* **`XAX`, the x axis:** the same about the world's x axis *(check: nothing in the US files uses it)*.
* **`LYAX`, its own y axis (9):** turns about the quad's own y axis, as placed and animated, by the angle
  that best faces the camera. The game takes the camera direction in the quad's own x/z plane and finds the
  angle from its x axis, signed by which side of the plane the camera is on. Then it builds the flat quad.
  The muzzle flash, the mansion's lamp flares and a statue's glow use it.
* **`LXAX`, its own x axis (1):** the same about its own x axis *(check)*. Only the light beam
  `fx_BB_BeamShape`.

### 3.3 The pull **[checked on the Xbox]**

* `AAX`: the centre moves towards the camera by the pull, along the line between them.
* The other kinds: every corner moves by the pull along the built frame's **-z** axis. For `YAX` that axis
  points at the camera.

The pull keeps a glow in front of the lamp or light it sits on, so the lamp's own mesh doesn't cut it.

### 3.4 The occlusion test (the sun's flares) **[checked on the Xbox, in outline]**

A group with the occlusion word set measures how much of the sun can be seen. Each such group carries a
number of its own (+0x90) for the hardware's visibility test *(check: handed out as the sky loads)*. Each
frame the game:

1. puts the first quad's centre into camera space;
2. builds a square around it, ±0.1 × its depth;
3. projects the square to the screen and takes its area in pixels;
4. multiplies that area by the multisampling's samples per pixel (1, 2, 4 or 9) and by 0.95, giving the
   pixel count to expect;
5. asks the graphics hardware's visibility test, under the group's number, how many pixels passed the depth
   test;
6. divides that count by the expected count and clamps the result to 0..1.

The group's fade takes that fraction (§3.1). So the flares vanish when a building passes in front of the
sun, even though they are drawn without a depth test. *(check: whether the count read is this frame's or
the last one's.)* A remake can do the same with an occlusion query, or by sampling the depth buffer around
the sun.

---

## 4. The cones and the size pair **[checked on the Xbox]**

A cut-off quad's fade and size, each frame:

1. *dir* = the quad's world position minus the camera's position, made unit length. If the distance is
   under 0.00001, *dir* is (0, 0, 0).
2. **One cone** in a frame *M* (*M*'s z axis and, for the up-and-down cone, its y axis; for the side-to-side
   cone, its x axis): project *dir* onto *M*'s z axis and onto the second axis, add the two projections,
   make the sum unit length, and take *c*, its dot product with *dir*. So *c* measures how close *dir*
   lies to the plane of those two axes (1 when it lies in it). With the stored cosines *ci* (inner) and
   *co* (outer):

   * *c* > *ci*: 1
   * *co* < *c* ≤ *ci*: 1 − (*c* − *ci*) / (*co* − *ci*)
   * *c* ≤ *co*: 0

   A cone the "which" word doesn't include gives 1.
3. The **facing cone** (`0x0001700A`) uses the quad's own world frame: is the camera in front of the light?
   This is why a car's tail light glows only from behind the car. The **view cone** (`0x0001700B`) uses the
   camera's frame: how near the middle of the view is the quad? This is why the lens flares fade towards
   the edge of the screen.
4. *P* = facing up-and-down × view up-and-down; *Q* = facing side-to-side × view side-to-side.
5. **Fade** = the fade it came in with × *P* × *Q* × the distance fade (`0x0001700C`; 1 without one).
6. **Size** = (*b* + (*a* − *b*) × *P*) × (*d* + (*c* − *d*) × *Q*), with *a* to *d* from `0x0001700D`.
   With the files' values that is always 1, 1.3 or 2.88.

A plain quad does none of this: fade and size stay as they came (§3.1).

---

## 5. Animations: `BQG` **[checked] [checked on the Xbox]**

A group's frame controllers (`0x00121201`, type `BQG`; the program's class for them is
`BillboardQuadGroupAnimationController`) play an animation (`0x00121000`, type `BQG`) whose
groups are named after quads. Each animation group drives the quad of the same name. In all 121 cases the
controller is named `BQG_` + the billboard group's name. The channels, by parameter name:

| Channel | Kind | Sets |
| :--- | :--- | :--- |
| `VIS` | Boolean | shown (§2.2). The only thing that hides a quad |
| `TRAN` | Vector (2 or 3 moving parts) | the quad's position in its group |
| `ROT` | Quaternion | the quad's rotation |
| `WDT`, `HGT` | Float1 | width, height, as full values that the game halves |
| `DIST` | Float1 | the pull |
| `CLR` | Colour | the colour |
| `FSF` | Integer | the strip frame (§2.5), kept no higher than the frame count |
| `OFF` | Float2 | the texture offset |

Every `BQG` animation in the PC files (122) has `VIS`, `CLR`, `WDT`, `HGT`, `DIST`, `FSF` and `OFF`. Nine
also have `TRAN` and `ROT`: the four moving sky groups and five of the drive-in's screens. Lengths, at 30
frames a second: 11 frames for the vehicle lights (58 animations), 21 for the buoys (16), 2 (11), 201 (14,
the drive-in), 241 for the sky (5, a whole day as SPEC-001 §1.4). Three are cyclic: `BQG_sunShape`,
`BQG_fx_BBStarShape`, `BQG_identInteractInstanceShape`. The sun's colour through the day and the moon
showing only at night are both `BQG` channels (SPEC-001 §3).

---

## 6. The Xbox functions **[checked on the Xbox]**

For matching, by work-queue name. All are in [function_guide.json](../function_guide.json).

| Function | Bytes | What it does |
| :--- | ---: | :--- |
| `sub_00279660` | 78 | turns a facing code into its number (§2.2) |
| `sub_002796B0` | 52 | turns `BOTH`/`VERT`/`HRZT` into 3/1/2 (matched) |
| `sub_002796F0` | 648 | one pair of cones in a frame (§4, step 2) |
| `sub_00279980` | 84 | the distance fade (`LINE`) |
| `sub_002799E0` | 353 | builds a flat quad in a frame, with the pull (`NOAX`, and the end of the four turning kinds) |
| `sub_00279B50` | 293 | builds an `AAX` quad |
| `sub_00279C80`, `sub_00279D30` | 175 each | `XAX` and `YAX`: build the turn, then the flat quad |
| `sub_00279DE0`, `sub_00279F90` | 419, 406 | `LXAX` and `LYAX` |
| `sub_0027A130` | 208 | picks the strip frame (random or given) and sets the texture offset |
| `sub_0027A260`, `sub_0027A950` | 187, 127 | the two quad kinds' constructors |
| `sub_0027A350` | 1528 | one quad, each frame: §3.1 steps 2 to 7 |
| `pure3d::BillboardCutOffQuad::vfunc_08` (`0x0027A9D0`) | 433 | a cut-off quad's fade and size (§4) |
| `pure3d::BillboardObject::vfunc_10` (`0x0027B010`) | 87 | the container's draw: puts the group's placement on the matrix stack, lends the group its size multiplier, draws, puts 1.0 back |
| `pure3d::BillboardQuadGroup::vfunc_17` (`0x0027A210`) | 9 | a plain group's own cones: always 1 |
| `sub_0027B0A0` | 1744 | reads one quad (§2.2 to §2.6) |
| `sub_0027BC00` | 1294 | the occlusion test (§3.4) |
| `sub_0027C110` | 96 | the loader's constructor (chunk `0x00017006`) |
| `sub_0027C1B0`, `sub_0027C560` | 75, 161 | the two group kinds' constructors |
| `pure3d::BillboardQuadGroup::vfunc_08` (`0x0027C2C0`) | 663 | draws a group (§3.1) |
| `sub_0027C670` | 1672 | reads a group (§2.1) |
| `pure3d::BillboardObjectLoader::vfunc_06` (`0x0027CD00`) | 118 | makes the container and reads the group into it |
| `pure3d::BillboardQuadGroupAnimationController::vfunc_09` (`0x002A8190`) | 583 | the `BQG` controller: writes the channels into the quads (§5) |

Not looked at yet: `pure3d::BillboardQuad::vfunc_07` (1166 bytes, in both quad kinds),
`pure3d::BillboardQuadGroup::vfunc_10` and `vfunc_13` (96 and 540), and
`pure3d::BillboardCutOffQuadGroup::vfunc_17` (460; by its place in the table, the group's own cones).

---

## 7. What to build

For the implementer. Choose your own names; keep each step small.

1. **`p3d.py`:** read `0x00017006` and every sub-chunk in §2 (give the sub-chunks descriptive names in
   `NAMES`, as with SPEC-001's), with a test on `Common.p3d`'s sky groups: six groups, sizes as the files
   give them (the sun's quad is 556.6 wide).
2. **FORMATS.md:** a *Billboards* section from §2, §3.2 and §5 in your own words, and take `0x00017006` out
   of anything that says billboards aren't exported.
3. **glTF and Blender export:** export each billboard group as quads with the shader's texture, marked as
   billboards in the extras (facing code, world-size, pull, cones). Put the sky's sun, flare stars, lens
   flares and moon on their joints, and the street-lamp flares and car lights on their models, so a
   remaster has them in place.
4. **The viewer:** draw billboards as §3 with additive blending for `BLMD` 2, the cones of §4, and the
   `BQG` animations of §5. That gives the sun's colour through the day, the moon at night, flashing police
   lights and blinking buoys. The sun's flares should fade when something covers the sun (§3.4).
5. **Decomp:** match §6's functions, small ones first (`sub_00279660`, `sub_00279980`, the constructors,
   `sub_0027C110`), with each match's description from its guide entry.

### Questions from the implementer, and answers

*(none yet)*
