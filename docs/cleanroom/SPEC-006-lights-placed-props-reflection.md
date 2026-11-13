# Clean-room spec 006: which lights reach an object, placed props at run time, the reflection, and the function guide

* **Written by:** the examiner side (see [CLEAN_ROOM.md](../CLEAN_ROOM.md)). The examiner has read published
  notes by a third party whose research was done next to leaked source code. This spec says in the examiner's
  own words what those notes report about the PC game. The implementer must not open the notes.
* **What this is:**
  1. how the game picks the lights for each object;
  2. how the placed trees, bushes and other props are kept, culled, woken and drawn while the game runs;
  3. the water reflection and the frame-time budget;
  4. the function guide's PC part: about 500 PC functions with what each does;
  5. the game's name key, checked on the Xbox.

  No code, and no function names: the implementer chooses names.
* **How sure:** **[reported]** is what the notes read out of the PC program (`Scarface.exe` 1.00.2), not
  checked here. **[checked on the Xbox]** is read from `default.xbe` with a disassembler. If the files or the
  programs disagree with this spec, they win: fix the spec in the same pull request.

---

## 1. Which lights reach an object **[reported]**

SPEC-001 has the lights' chunks and the time of day. While the game runs:

* The **light manager** (one object, 0x70 bytes) keeps light groups by **kind**, the number a light-group
  record (`0x08800007`) carries:

  | kind | kept as | what it is |
  | :--- | :--- | :--- |
  | 0 | one group | the area's own lights (`zone_lights`), tied to the time of day |
  | 1 | one group | the same for rain (`zone_rainlights`) |
  | 2 | a list | outdoor detail lights: lamps, signs |
  | 3 | a list | indoor lights |
  | 4 | a list of *templates* | not lit as they are: each light becomes a pattern to copy, used for the street lamps and the cars' headlights placed while the game runs (up to 256 copies) |

* **Each frame** it gathers the lights near the camera, within **50 units**:
  * from the kind 2 lists: lights whose fall-off type is 1 always go through the distance test; types 0 and 2
    are taken without the test when a property of the light says so, otherwise tested too; type 3 is left out;
  * every placed template copy in use whose position is within the 50 units;
  * then the area's lights, the clear-weather group or the rain group by the weather (indoors the rain group is
    preferred when there is one). The **building ambient** lights (`MiamiBuildingAmbientShape`,
    `MiamiRainyBuildingAmbientShape`) are never added here: they belong to the lit windows at night, the
    `buildinglights` world geometry.
* Indoor lights (kind 3) are not in this pass; they are chosen through **rooms**. A room is a volume. The light
  manager finds which room a point is in (or a default room), and a renderable keeps whether it is inside its
  room (SPEC-005 §4.1, `0x81` bit 0).
* For **each lit object**, the gathered lights are reduced to **at most four directional lights** plus an
  ambient colour, chosen for that object's position (and cached by position). So a lamp next to a car can light
  the car strongly without changing anything else in the city.
* On the hardware: the ambient is one render state for the whole frame; a point light becomes a hardware light
  with no fall-off (attenuation 1, 0, 0) and a range of 10,000,000.

## 2. Placed props at run time **[reported]**

The placed trees, bushes and other props (FORMATS.md, *Maps*: `instanceobject` and its `instanceposition`s)
are not each an object while the game runs. One **placed-prop manager** keeps them packed, at most 4,181 of
them, in 24 bytes each: position (height in hundredths), rotation, scale, which prop model, its starting
state, and flags (placed and switched on, in its renderable, woken up, gone).

* **Each frame**, after the simulation:
  * if the camera has moved more than **20 units** since the last full check, every placed prop is checked;
    otherwise the next **350** in turn, so the whole set is covered over a few frames;
  * the distance is measured on the **ground plane only** (x and z, not height);
  * a prop is drawn while that distance is below its model's **view distance** (the prop property
    `view_distance`, SPEC-003 §1.5) times a global draw-distance scale, plus a margin: the test is on squared
    distances with **900** added to the squared limit;
  * a prop with a starting state other than the first is given that state; one within its model's **wake-up
    radius** becomes a full state prop (it can break, move, play its states). The manager itself never fades
    or switches detail: it only adds props to drawing and takes them out.
* **Drawing:** all the copies of one prop model are one instanced renderable. Each copy has its matrix and
  bounding sphere; each frame every copy is tested against the camera's view and the occluders, then all the
  visible copies are drawn in **one call** (lists 72 to 74, SPEC-005 §3.2). A model has up to three detail
  levels, chosen by distance bands worked out from its view distance; the destroyed look is a separate mesh.
  Limits: 894 copies drawn at once and 103 instanced renderables (warnings from 850 and 97).
* **Wind:** a model's sway (a number 0 to 5 in its template's flags, giving 0, 0.5, 1, 4, 50 or 200) sets the
  wind strength for its copies; the wind's direction (degrees) and a second setting come from the renderer's
  global wind. Copies with sway 0 don't move.
* **Packed values:** height is kept times 100; a per-axis scale times 20; a uniform scale times 1000 (kept
  between 0.001 and 65); a tint in fifteenths.

**[checked on the Xbox]** The Xbox has the same manager. Its constructor is `sub_0008C860` (1,122 bytes): it
sets the 350-a-frame count and makes room for 4,181 placed props. Its scan is `sub_0008E8F0` (2,171 bytes),
which uses the 900 margin, heights in hundredths (0.01), and two more squared distances the PC has too: 1,600
(40 units) and 62,500 (250 units), for attract points (places characters are drawn to, such as parking). The
manager's fields sit at **different offsets** on the Xbox (the 350 is at 0x25C0, not the PC's 0x2D90), so
take its layout from the Xbox code, not from the PC.

## 3. The reflection, and the frame-time budget **[reported]**

* **The water reflection** is drawn before the main frame, by the gameplay scene: the sky is drawn mirrored
  (one axis flipped) without fog; then, into the reflection target, the sky again and the instanced trees of
  list 72 in a single pass, also without fog. The functions that draw the sky and list 72 take an optional
  extra matrix put in front of every piece's own; only the reflection uses it.
* **The frame-time budget:** at the end of every frame the draw list measures how long the frame took, smooths
  it over many frames, and compares it with a budget of **33.3 ms** (30 frames a second). From that it
  publishes a number from 0 (on budget) to 1 (far over) that the distance and detail code reads, so draw
  distances shrink when the frame runs slow and grow back when it recovers. A switch can turn this off (the
  number stays 0).

**[checked on the Xbox]** The end of the Xbox's frame-drawing function (`renderer::Display_List::vfunc_09`,
from `0x00045329`) gives the exact numbers:

1. The frame's time in milliseconds is the timer's difference since the last frame times 0.001.
2. A running average is kept (it starts at 33.3): `average = average × 0.9 + frame time × 0.1`.
3. `t` is the average, but never less than 33.3.
4. The over-budget number is `1 − 33.3 / t`: 0 at 30 frames a second or faster, rising towards 1 as frames
   slow. A frame rate estimate, `(1 − over) × 30`, is kept beside it.
5. When the switch (a byte at `0x0041C921`) is off, the over-budget number is set to 0.
6. Then `1 − over × 0.5` is passed on (`sub_0025D760`): a scale from 1 down to 0.5 for the distance and detail
   code.

## 4. The function guide's PC part **[reported]**

[function_guide.json](../function_guide.json) now lists, besides the Xbox functions of SPEC-004 and SPEC-005
§4.1, about **500 PC functions** (`"bin": "pc"`), each with its address and what it does in the examiner's
words: the renderer core (render manager, scenes, canvas, handles), the draw list and its 84 lists' drawing
functions, every kind of renderable (loaders, constructors, updates, displays), the light manager, occluders,
the placed-prop manager and instance objects, and the render context's calls (depth, colour and stencil
writes, fog, lights, matrix stacks, extensions). Constructors, destructors and simple getters are included
because they pin down class layouts.

To use one on the Xbox, find the same function in `default.xbe`: the portal pairs PC and Xbox functions where
it can (a PC task's twin), class methods share their class name and table slot, and the strings, constants and
calls a function uses usually make it easy to recognise. Each PC entry's `what_it_does` holds whatever the
Xbox twin should do too, unless the specs say the Xbox differs.

## 5. The game's name key **[checked on the Xbox]**

Objects in the game files are found by a 32-bit key made from their name. The Xbox's function is
`sub_00243FA0` (75 bytes), called through `sub_00244040` (matched already). Given the text and a starting
value:

1. No text, or empty text: the starting value comes back unchanged.
2. Otherwise `h` = the starting value with its top bit cleared. For each character, taken as a signed byte:
   `h = (h × 65599) & 0x7FFFFFFF`; if the character is below `a` (0x61) add 0x20 to it; then `h = h XOR c`.
3. At the end the top bit is set: `h | 0x80000000`.

Like the archive hash (SPEC-004 §1), the folding is blind: it turns `A`–`Z` into `a`–`z`, but shifts digits,
`.`, `_` and the rest too. Keys of the same name in different letter case are the same.

## 6. Engine functions from a list only (lower confidence)

The research also lists about 230 more PC functions of the engine itself, by name only, with no notes: the
chunk reader and load manager, inventories, file handlers, picture loaders and factories, shaders' settings,
mesh pieces (plain, optimised, streamed, skinned, with vertex animation), skeletons and poses, composite
drawables, billboards, fonts, locators, textures, particle emitters, matrices and rotations, memory. The
function guide has them (`"confidence": "low"`), each with what it does as far as its place and kind show. They
are a map for finding things, not facts: check each one against the code before relying on it. PC-only parts
(Direct3D, DirectInput, the Windows code) are left out.

---

## 7. What to build

For the implementer. Choose your own names; keep each step small.

1. **`p3d.py`:** a `name_key(text, start=0)` as §5, tested against the keys the game files carry, and
   used wherever the tools match objects by name. **Done** (`p3d.name_key`; see the answers below for where
   the files do and don't carry keys).
2. **Placed props:** use §2 in the city export and viewer: the view distance per model (with the draw-distance
   scale 1), the ground-plane distance, the 900 margin, and the sway number in the extras.
3. **Lights in the viewer:** gather the lights near a point as §1 and light each object with at most four plus
   ambient, so a remastered city looks like the game's at night.
4. **The reflection:** if the viewer draws water, mirror the sky and the trees as §3 into it.
5. **Decomp:** use [function_guide.json](../function_guide.json) to find and match Xbox functions; put a
   one-line `what` on each match from its entry; match the Xbox name key `sub_00243FA0` first, since much
   else calls it.

### Questions from the implementer, and answers

*From the implementer, after building item 1 (checked on the PC's files and the Xbox's program):*

* **The `.p3d` files carry no name keys.** Item 1 asked for a test against "an animation group's joint, a
  light's key in a light group, a prop's model-name key". Nine PC files of different kinds (two city areas,
  `Common.p3d`, the stream graph, an interior, a character, a vehicle, the weapons, a cutscene's stream) were
  searched for the key of every name in them: none is stored. An animation group (`0x121001`) has its
  joint's name as text and a u32 0 after it. The files keep names; the game makes the keys when it loads
  them. The keys that *are* in files are the compiled scripts' (a name written `stx` and eight letters is its
  key) and the AI trees' (`.dtr`); `torque_names.name_key` now uses `p3d.name_key`, and the tests check the
  two agree.
* **A character above 0x7F counts as below `a`.** §5 says "taken as a signed byte" and "below `a`: add 0x20".
  The Xbox's function compares the byte as a signed character first (`cmp cl, 0x61` / `jge`), so 0xE9 is -23,
  below `a`, and 0x20 is added before the XOR. The scripts' key in this repository did it the other way
  round for such bytes (no names in the game's files have any, so nothing changed); it is corrected.
* **`sub_00243FA0` is matched** from §5: `reports/to_submit/xb_00243FA0.cpp`, 75 of 75 bytes with
  `portal/verify.py`. Its second argument is the starting value, as §5 says.
