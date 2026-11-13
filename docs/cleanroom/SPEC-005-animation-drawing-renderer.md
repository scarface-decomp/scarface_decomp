# Clean-room spec 005: playing animations, drawing a frame, the renderer's classes

* **Written by:** the examiner side (see [CLEAN_ROOM.md](../CLEAN_ROOM.md)). The examiner has read published
  notes by a third party whose research was done next to leaked source code. This spec says in the
  examiner's own words what those notes report about the PC game. The implementer must not open the notes.
* **What this is:** what the earlier specs left out and a decomp, a remaster or a remake needs:
  1. how the game plays the animation chunks [FORMATS.md](../FORMATS.md) describes;
  2. how a prop state's animation settings, and draw-distance fading, work;
  3. how the PC builds a frame: the draw lists, their order, and which ones write depth;
  4. the renderer's classes: sizes, fields, and what each table slot does, for decompiling `renderer::`.

  No code, and no function names: the implementer chooses names (see §6). Class names are the ones in the
  programs' run-time type information.
* **How sure:** everything here is **[reported]**: the notes read it out of the PC program (`Scarface.exe`
  1.00.2). The Xbox was built by the same compiler from the same source, so layouts and slot numbers are very
  likely the same there, but this spec has not checked them on `default.xbe` *(check)*. Where a function on the
  Xbox is named by the work queue, it is given. If the files or the programs disagree with this spec, they win:
  fix the spec in the same pull request.

---

## 1. Playing an animation

[FORMATS.md](../FORMATS.md#animations) has the chunks. What the game does with them:

### 1.1 Finding the keys

* A channel's key times are whole frame numbers (u16). To get a value at a frame, the game finds the last key
  at or before that frame and the one after it.
* Before the first key the channel holds its first value; after the last key, its last value.
* Between two keys it blends linearly by where the frame falls between them, **unless** the channel's
  Channel Interpolation Mode (`0x00121110`) says not to (value 0). Then it holds the earlier key's value until
  the next key: a step. With no mode chunk the channel blends.

### 1.2 Each kind of channel

* **Float1** (`0x00121100`) and **Float2** (`0x00121101`): one or two floats per key, blended each on its own.
  Float2's layout is Float1's with two floats per key.
* **Vector1DOF / 2DOF / 3DOF**: as FORMATS.md says. The components that don't move come from the three
  constants; only the moving ones are keyed and blended.
* **Quaternion** (and the two compressed forms, once unpacked): blended along the sphere (slerp), always the
  shorter way: if the two keys point into opposite halves (their four-way dot product is negative), the second
  is negated first. When the keys are almost the same (dot above about 0.9995) a straight blend is used, and
  the result is scaled back to length 1. The shorter-way rule matters in the game's own data. The sun's turning
  joint in the time-of-day animation has keys whose sign flips between frames 153 and 154, and without the rule
  the sun would swing the long way round at about 15:20.
* **Colour** (`0x00121109`): each of the four bytes of the `0xAARRGGBB` word blended on its own.
* **Integer** (`0x0012110E`): the integers blended as if they were floats.
* **Boolean** (`0x00121108`): after the parameter comes a u16, the starting state (1 on, anything else off);
  then the key count and the frame numbers, and **no values at all**. Every key toggles the state: at a frame,
  the state is the starting state flipped once for each key at or before it.
* **Entity** (`0x00121107`), and string and event channels: the notes don't decode them *(check)*.

A channel's sub-chunks after its keys may hold the interpolation mode; anything else there is skipped.

### 1.3 The animation as a whole

* The Animation chunk's two floats are its length in frames and its frame rate.
* Looping (the cyclic u32 is 1): a frame past the end wraps round (the remainder after dividing by the length;
  a negative one is brought back into range). Not looping: frames are kept between 0 and the length.
* A group belongs to a joint by **name** (the group's name matched to the joint's, through the game's name
  key), not by its position in the list.
* The header chunks `0x00121006`/`0x00121007` only tell the loader how much to set aside; nothing reads them
  for playback.

### 1.4 The frame controller (`0x00121201`)

After the `ANIM` word: a **float**, the frame the controller starts its animation at (an offset), then a u32
that is always 1, then the name of what it drives and the name of the animation. FORMATS.md calls the float
and the u32 "two u32"; the first is a float.

---

## 2. Prop states and fading

### 2.1 A prop state's animation settings (`0x08020003`)

SPEC-003 §1.4 left the three u32 open. Their meaning:

| field | meaning |
| :--- | :--- |
| first u32 | the animation loops (1) or not (0) |
| second u32 | how many times it plays before it stops; 0 seems to mean no limit *(check)* |
| third u32 | when it stops, it stays on its last frame (1) or not (0) |
| the three floats | the first and last frame of the part of the animation to play, and the speed, as SPEC-003 says |

That fits the values SPEC-003 counted: `idle` (1, 0, 0) loops for ever; `opening` and `closing` (1, 1, 1)
play once and hold their last frame, so a door that has opened stays open. SPEC-003's 77 records with a first
u32 of 0 and frames 0 to 0 don't play anything.

The Prop State Effect's last float (SPEC-003 §1.6) is still not known *(check)*.

### 2.2 Draw distances and fading

Every drawable piece a renderable puts on screen (an *element*) has three numbers: the nearest distance it is
drawn at (default 0), the farthest (default 100), and the width of the band it fades in (default 10). Each
frame, for a renderable with distance testing on:

1. The distance is from the camera to the renderable's position. Some kinds (world geometry) measure from
   another point they keep instead. The distance is multiplied by the camera's scale factor if that is below 1
   (a zoomed view counts as nearer).
2. Normally only the first element is looked at; a renderable can be set to look at all of them (a chain of
   levels of detail). It can also be set to use the last element's farthest distance for all of them.
3. An element is hidden when the distance is at or past its farthest distance, or below its nearest, or its
   bounding sphere is outside the camera's view, or an occluder hides it completely.
4. If fading is on, the element fades in a band at its far edge: the fade amount (0 = solid, 1 = gone) is
   `(distance - (far - band)) / band` while that is between 0 and 1. With a nearest distance above 0 it also
   fades at the near edge: `(band + near - distance) / band`, in range. In a level-of-detail chain the first
   element never fades; the others fade out at their far edge as above, and in at their near edge over half the
   band: `(near + band/2 - distance) / (band/2)`.
5. The renderable as a whole has its own fade too, moved towards a target at a set rate (it can be told to fade
   in or out over so many milliseconds). The element's final amount is `amount × (1 - whole) + whole`, using
   the larger of its two whole-renderable fades.
6. An element whose amount rises above 0 is moved to the fading draw lists (§3) and drawn see-through by that
   amount; when it drops back to 0 it returns to the solid ones.

---

## 3. How the PC draws a frame

### 3.1 Material class: each piece's layer

When a mesh piece is loaded the game gives it a *layer*, a number for its material class. It is worked out
from the shader's kind (FORMATS.md's shader table), whether it is lit, its blend mode and its alpha test.
Blended means a blend mode of 1, 2, 3 or 7.

| shader kind | condition | layer |
| :--- | :--- | :--- |
| any | the piece's own kind is 2, 4 or 8 | 1 |
| untextured, vertex-fade | | 33 |
| specular | | 5 |
| specular with vertex colours (`MCBV`) | | 6 |
| foam | | 29 |
| night light | | 3 |
| shadow decal | | 37 |
| decal | blend 2 or 3 | 21 |
| decal | other | 22 |
| environment | | 26 |
| simple, lit | alpha test, not blended | 13 |
| simple, lit | not blended | 11 |
| simple, lit | blend 2 or 3 | 14 |
| simple, lit | other blend | 12 |
| simple, unlit | not blended | 7 |
| simple, unlit | blend 2 or 3 | 10 |
| simple, unlit | other blend | 8 |
| `cbvlit` | alpha test, not blended | 17 |
| `cbvlit` | not blended | 15 |
| `cbvlit` | blend 2 or 3 | 18 |
| `cbvlit` | other blend | 16 |
| layered | lit | 20 |
| layered | unlit | 19 |

World geometry of the special kinds is placed differently: low-detail hulls and night cards made of untextured
or vertex-fade shaders go to 33; underwater pieces to 34; `cbvlit` decals to 23 (blend 2 or 3) or 24 (blend 1);
interior floors that are blend 1 and unlit to 25; other night cards to 4.

### 3.2 The 84 draw lists

At draw time a piece's layer, whether it is fading, lit, light-adding and so on pick one of 84 lists. Each list
holds pieces that need the same render settings at the same point in the frame, so the settings change once per
list. What they hold:

| lists | what |
| :--- | :--- |
| 46, 47, 76 | the sky and things fixed to the camera: drawn without depth test or depth writes, without fog, moved with the camera so they never come nearer |
| 59, 2 | the low-detail city skyline (untextured, vertex-fade) |
| 49, 50, 52, 53, 54; fading 51, 55, 56 | most of the city as it streams in |
| 21-24, 26-30, 35-39, 43; fading 25, 31, 32, 40, 41, 44, 45 | buildings by material class |
| 42, 43 (fading 44, 45) | two-layer interior surfaces |
| 33, 34 | interior floors, blended, unlit |
| 13, 15 (fading 14, 16) | shiny roads and ground; drawn twice (before and after the shadow volumes) |
| 3, 4, 17, 18, 75 (fading 5, 6, 19, 20) | decals |
| 7, 8, 77 | shadow decals (SPEC-003 §8, SPEC-004 §4) |
| 61-64 | stencil shadow volumes and projected shadows |
| 9, 10 | reflections: drawn only where the stencil holds 1 |
| 11, 12 | night lights and night cards, drawn without fog |
| 72, 73, 74 | trees and bushes drawn many times over (instancing); 72 in two or three passes, 73 in two |
| 65, 66; 0, 1 | water below and at the surface; foam (0, 1) is never drawn on the PC |
| 78-81 | underwater |
| 67-71, 82, 83 | pieces with their own light sets |
| 58 | depth only, no colour: fills the depth buffer |
| 60 | only its first piece is ever drawn |
| 48, 57 | unused |

Blended lists such as 37 and 38 are sorted **far to near** by their distance from the camera before they are
drawn.

### 3.3 The order of a frame

One group of lists, (B): 36, 42, 73, 52, 53, then 49, 67, 69, 82, then 54, then 68 and 83, and the decal pass
of step 9. It is drawn early when the camera is outdoors and last when the camera is inside a building, so
from inside the interior comes first and the outside world after it.

1. With fog off and nothing written to the frame's alpha: the sky, 46 and 47.
2. 59.
3. *(B)* 36, 42, 73, 52; then the whole frame's **alpha is set to 1**; then 53.
4. 21, 26, 22, 27, 28, 35, 43.
5. 74.
6. Reflections 9 and 10, through the stencil (equal to 1), without fog and without depth or alpha writes.
7. 13, 15.
8. 78, 79.
9. *(B)* Without depth writes: the decals 3, 17, 18, 4, 75. Then 33, 34, then the projected shadows 62.
10. The shadow decals 7, 8, 77 (SPEC-004 §4), without depth writes, when there are any and they are switched on.
11. *(B)* 49, 67, 69, 82.
12. When a depth fill is wanted: 58, depth only; then list 60's first piece.
13. 2; 14, 16; without depth writes 5, 19, 20, 6.
14. Without depth writes and without fog: night lights, 11.
15. 72 (two passes; one in the reflection view).
16. 44, 25, 26, 22, 32, 31, 40; 80, 81; 23; 29, 50.
17. Without depth writes: night cards, 12.
18. *(B)* 54. Then 51.
19. Colour without alpha from here on; the skidmarks draw themselves; the stencil is cleared.
20. *(B)* 68, 83.
21. 71; the stencil shadow volumes 61, 63, 64, tinted dark grey (`0xFF191919`); then 15 and 13 again.
22. When indoors: group (B) here.
23. 41, 45; 38, 37; without depth writes 39, 30, 24.
24. The decal renderable draws itself; water below, 65; 70; water surface, 66; then the gunfire tracers without depth writes.
25. 55, 56.
26. Without fog: 76, the camera-fixed pieces, when switched on.
27. The full-screen effects, when switched on.

The frame's **alpha channel is a mask**. Step 3 fills it with 1; from then on nearly every pass leaves alpha
alone. Only the passes meant to cut into the mask write it.

### 3.4 What writes depth

Only these draw **without** writing depth: the sky (46, 47, also without depth test), the decals (3, 17, 18, 4,
75 and fading 5, 19, 20, 6), the shadow decals (7, 8, 77), reflections (9, 10), night lights (11), night cards
(12), the light-adding lists 39, 30, 24, and the tracers. **Everything else writes depth**, blended lists
included. This agrees with SPEC-002 §1.4.

Two kinds of shader set depth writing themselves rather than leaving it to the list:

* **Leaves** on placed trees and bushes (SPEC-002 §1.5): the blended colour pass is drawn **without** depth
  writes, and a second pass writes **depth only**, where alpha is at least 228.
* The **low-detail hull** around a building (SPEC-002 §1.6) sits in list 2. Drawn as solid, it can show as an
  invisible box that hides what is behind it (the boathouse is one place it shows): it must fade like the rest
  of list 2, not be drawn solid.

---

## 4. The renderer's classes (PC layouts)

For decompiling `renderer::` and for a remake's scene code. Offsets are from the start of the object; the
vtable pointer is at 0.

### 4.1 `renderer::Renderable` (0x84 bytes), the base of everything drawn

| offset | what |
| :--- | :--- |
| 0x04 | reference count |
| 0x08 | the object's key (from its name) |
| 0x14 | its matrix (4x4 floats, 0x40 bytes) |
| 0x54 | its *type mask*: which kind of renderable it is (§4.3); -1 when made |
| 0x58, 0x5C, 0x60 | its elements: start, end, and end of the space set aside; each element is 0x30 bytes (§4.2) |
| 0x64 | a running number, unique to each renderable, from a global counter |
| 0x68 | the rate its whole-renderable fade moves at (a step of 1000 divided by this per second) |
| 0x6C, 0x70 | the whole-renderable fade and a second one; the larger counts (0 solid, 1 gone) |
| 0x74 | where the fade is heading (1 when made) |
| 0x78 | time since it was last drawn |
| 0x7C | the scene it belongs to (5 when made) |
| 0x80 | flags: 0x01 distance test, 0x02 fading on, 0x04 fading out (not in), 0x08 a handle holds it, 0x10 visible, 0x40 the last element's far distance for all, 0x80 bounds from the pose (state props) |
| 0x81 | flags: 0x01 the camera is inside its room, 0x02 the matrix changed |

Its 16 table slots:

| slot | what it does |
| :--- | :--- |
| 0-2 | add a reference, release one, get the count |
| 3 | destructor: every kind overrides it and frees its own drawables |
| 4, 5 | copying (a stub, and the base entity's copy) |
| 6, 7 | set and get the name: empty in the released game, which keeps no names |
| 8 | show or hide (sets flag 0x10 and adds or removes every element's draw-list entries) |
| 9 | the per-frame update before drawing: animation, wind, skinning and ageing happen in the kinds that override it; empty in the base |
| 10 | the per-frame visibility, distance and fade work of §2.2, putting visible elements into the draw lists; kinds that cull their own pieces (world geometry, instances) override it |
| 11 | draw straight away, outside the draw lists: only for scenes other than gameplay; empty in the base |
| 12 | set the matrix (copies it, marks it changed) |
| 13 | get the position (the matrix's last row) |
| 14 | take every element out of the draw lists |
| 15 | give another point to measure distance from; the base has none (returns false), world geometry gives its own |

On the Xbox these are `renderer::Renderable::vfunc_00` to `vfunc_15`, and each kind's override is
`renderer::<kind>::vfunc_<slot>`.

### 4.2 An element (0x30 bytes) and a draw-list entry

An element is: nearest distance (+0x00, default 0), farthest (+0x04, default 100), fade band (+0x08,
default 10), then its draw-list membership (+0x0C, 0x20 bytes), and a byte, *it is fading* (+0x2C).

The draw list (`renderer::Display_List`) keeps one array of entries of 0x70 bytes each. An entry holds its
links in its list, a copy of the world matrix at the time it was added (+0x08), two sort numbers (+0x48: from
the container, or 0, 0.5 or 1 by layer; +0x4C: its depth from the camera, worked out before sorting), the
piece and its container (+0x50, +0x54), the shader it is grouped by (+0x58), the membership that owns it
(+0x5C; none means it is dropped once the frame is drawn), and its list (+0x60). The lists themselves are an
array of 84 heads of 12 bytes at +0x30 of the draw list, with a byte per list at +0x3C saying it needs
sorting.

### 4.3 The kinds of renderable

| class | size | type mask | its own fields |
| :--- | :--- | :--- | :--- |
| `ZonePkgRenderable` | 0x90 | 0x8000 | an array of world geometries (start, end, space) at 0x84 |
| `WorldGeoRenderable` | 0xA0 | | see SPEC-003 |
| `PropRenderable` | 0x84 | 0x8 | none |
| `StatePropRenderable` | | | the state prop (SPEC-003) |
| `InstanceRenderable` | 0x88 | 0x200 | its instance container at 0x84 |
| `CharacterRenderable` | 0xBC | 0x20 | the drawable hierarchy at 0x84; eight shaders at 0x88; its position at 0xB0 |
| `VehicleRenderable` | 0xC0 | 0x4000 | eight shaders at 0x84, how many at 0xA4; the model and its low-detail model, and their containers, at 0xB0 to 0xBC |
| `DecalRenderable` | 0x88 | 0x2000 | its container at 0x84 |
| `SkidmarkRenderable` | 0x88 | 0x100000 | its container at 0x84 (not as an element) |
| `TraceFireRenderable` | 0x8C | 0x2 | the tracers (0x4C bytes each) at 0x84, how many at 0x88 |
| `OceanRenderable` | 0x88 | 0x40 | its container at 0x84; no distance test or fade |
| `WakeRenderable` | 0x88 | 0x80 | its container at 0x84; no distance test; drawn from 0 to 1000 with a band of 100 |
| `RainRenderable` | 0x454 | 0x800 | its own particle state |
| `MaskRenderable` | 0x84 | 0x1000 | none |
| `ParticleEffectRenderable` | 0xA8 | 0x4 | the particle system at 0x84, its emitter at 0x88; draws through the particle system, not slot 10 |
| `NISRenderable` | 0x90 | 0x20000 | its position at 0x84 (cutscenes); no distance test |
| `PlugInRenderable` | 0x88 | 0x40000 | a plug-in at 0x84 whose first slot draws |

Their pieces: a *container* holds a sort number at 0x3C (decals and skidmarks 0, the ocean 0.5, wakes 0.89,
vehicles their position each frame) and its pieces from 0x44. A *piece* (`...Primitive`) has its layer at 0x0C
and its bounding sphere at 0x28. The ocean's piece is layer 27 with a sphere re-centred on the camera (radius
100,000); wakes are layer 30 and keep 40 segments; instances are layers 40 to 42 and carry their shape, two
low-detail shapes, a detail scale of 10, how much they sway in the wind, and their box.

### 4.4 The scenes and the manager

* `renderer::RenderManager` (0x104 bytes): an array of 4 scenes at 0x04, the canvas at 0x10, *set up* at 0x18,
  *sky on* at 0x19, the interior manager at 0x1C, the decal system at 0x20, the two skies at 0x28 and 0x2C, the
  decal, skidmark and tracer renderables at 0x30 to 0x38, the player's renderable at 0x3C. Switching the sky on
  or off fades the second sky over 3 seconds.
* `renderer::Scene` (0x1C bytes): its renderables (start, end) at 0x04, *on* at 0x10, its number at 0x14 (a
  renderable added to it takes this number), and which type masks it takes at 0x18 (all, in the game's four).
  `renderer::GamePlayScene` (0x24) adds the draw list at 0x20.
* `renderer::RenderableHandle` (12 bytes): holds a renderable (and sets its flag 0x08) and that renderable's
  running number (+0x64), set to -1 once the renderable is gone, so a stale handle can tell.

### 4.5 Fog fading

The canvas keeps a fog target and the time left to reach it. Each frame it moves the fog's start, end and clamp
towards the target by the fraction `frame time / time left`, and snaps to it when the time runs out.

---

## 5. The PS2 program

For the PS2 lane (`portal/tools/ps2_*.py`):

* The PS2 program keeps class names and tables (run-time type information) much as the PC and Xbox do, so
  `renderer::` and `pure3d::` classes can be found by name there too *(check)*.
* The chunk loaders are registered from a table; the chunk ids are the same as on the PC, and the script-object
  and renderer chunks have the **same layouts** on both. Only a handful of ids appear on one platform alone.
* Compressed `.p3d` files (marked `P3DZ`) are a feature of the engine, but **no shipped file uses it**: there
  is nothing to decompress.

---

## 6. What to build

For the implementer. Names are yours to choose; avoid copying names from anywhere but this repository and the
game's own text and type information. Keep each step small; open questions in a pull request.

1. **`p3d.py`:** read the Boolean channel (§1.2: u16 starting state, keys, no values) and the Float2 channel,
   and read the frame controller's first number as a float, the frame offset (§1.4). Update FORMATS.md's
   animation table to match.
2. **An animation sampler** in `portal/tools` (or in `p3d_gltf.py`): the value of any channel at any frame,
   exactly as §1.1 to §1.3 say: steps when the interpolation mode is 0, the shorter-way slerp, Boolean
   toggles, looping or clamping. Test it on the time-of-day sun (the sign flip between frames 153 and 154)
   and on a door's `opening`.
3. **glTF export:** a channel with interpolation mode 0 uses glTF's `STEP`; Boolean channels become a
   visibility (scale 0 or 1 with `STEP`), named after their parameter; an animation's looping and frame rate go
   in its extras.
4. **Prop states:** name SPEC-003's three u32 by §2.1 (loops, play count, hold last frame) in `p3d.py`, the
   exports' extras and FORMATS.md.
5. **The city export and viewer:** draw distances and fades as §2.2 (an element's near, far and band are
   already in the data); depth writes as §3.4: decals, shadow decals, night lights and cards, light-adding
   surfaces and the sky don't write depth; leaves in two passes; the low-detail hull fades, never solid.
6. **FORMATS.md:** a short "How the game draws a frame" section from §3, and the renderer classes of §4 in
   their own section, marked as PC layouts not yet checked on the Xbox.
7. **Decomp notes:** for the `renderer::` classes in the Xbox work queue, add a one-line *what it does* from §4
   to `reports/names.json` (`why` field) where the slot's purpose is clear, without inventing names.

### Questions from the implementer, and answers

*(none yet)*
