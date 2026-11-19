# Clean-room spec 011: which stream trigger applies, unloading, and frame controllers

* **Written by:** the examiner side (see [CLEAN_ROOM.md](../CLEAN_ROOM.md)), on 19 November 2026, answering
  the implementer's first and fourth questions of that day (stream trigger heights and flags; how each
  frame-controller type plays). Read from the user's own Xbox `default.xbe`, and the PC files at hand, in
  the examiner's own words. The outside research was not used.
* **What this is:**
  1. how the game picks the stream trigger that applies at a place, using its height and its last number;
  2. what is loaded and unloaded when the trigger changes;
  3. the frame controller chunk's fields, its five cycle modes, and the types;
  4. corrections to SPEC-001 §4.2 and SPEC-005 §1.4;
  5. the Xbox functions read.
* **How sure:** **[checked]** read from the PC files; **[checked on the Xbox]** read from `default.xbe`;
  *(check)* not yet confirmed. The founder's computer was offline for most of this work, so the data counts
  below cover only the files at hand.

---

## 1. Which stream trigger applies **[checked on the Xbox]**

### 1.1 What the game keeps of a trigger

From SPEC-001 §4.2's fields, the game keeps:

* the outline's points on the ground (x, z), as whole numbers of tenths of a unit from the outline's
  smallest x and z (in a coarser step if the outline is too big for that);
* the outline's box in x and z, in whole units;
* a **base height**: the **average of the points' y**, kept in tenths (cut down, not rounded);
* the **height**, kept in tenths the same way;
* the two region names, turned into region numbers (24 means none);
* the **last number** as a yes/no: 0 = no, anything else = yes. Call it **"gives way"** (below).

### 1.2 Is a point inside a trigger?

All three must hold:

1. **x and z** inside the box, and inside the outline (the usual crossing count: a line from the point
   crossing the outline an odd number of times);
2. **y between the base and base + height**, both ends included;
3. ... except that a height of (almost) zero, 0.00001 or less either way, means **no limit in height**.

So a trigger is an upright prism: its outline, from its base up to base + height. Trigger 448 with height
10 covers only the ten units above its base; standing upstairs puts you above it, and so outside it.

### 1.3 One trigger at a time

**Only one trigger applies at a time: the current one.** The game does not take the union of every
trigger around you. Each update, with the player's position (or the camera's *(check which)*):

1. If there is a current trigger and the point is still inside it:
   * if it does **not** give way, it stays current. Nothing else is looked at, even if the point is inside
     other triggers too;
   * if it **does** give way, the game looks for another trigger that holds the point (step 2). If one is
     found it becomes current; if none, this one stays.
2. Otherwise the game looks through the list for a trigger that holds the point. It starts at the trigger
   it last found and goes back towards the start of the list, then from the start forwards *(check: the
   exact order of the two passes)*. The first one found becomes current.
3. If no trigger holds the point, nothing changes: what was loaded stays loaded.

So the current trigger is "sticky": overlapping triggers do not take over while you are still inside the
one you entered. Only one trigger in the stream graph gives way.

**For an exporter that wants one fixed answer per place:** the first trigger in the file's order whose
prism holds the point, preferring any other over the one that gives way. Coming in from a different side
in the game can give a different but overlapping trigger; their lists are mostly the same.

## 2. Loading and unloading **[checked on the Xbox]**

Each package has a wanted mark. When the current trigger changes:

1. every package of the **old** trigger is marked "unload";
2. every package of the **new** trigger is marked "load" (so one in both is left "load");
3. then each package marked:
   * "load" and not loaded is asked for, its priority set by its slot;
   * "unload" and loaded is **unloaded straight away**;
   and the mark is cleared.

So **what is loaded is exactly the current trigger's package list**, and a package unloads as soon as you
pass into a trigger that does not list it. The two region names do not load anything here *(check what
uses the region numbers)*.

**Interiors:** `packages/dzones/*_dzone.p3d` (furniture and props inside buildings) do not appear in the stream
graph at all: the mission script `scriptc/missions/z04/dzone_triggers.dso` loads them by its own trigger
outlines (SPEC-001 §4.3). If a room's furniture is missing, check the dzone triggers as well as the
stream trigger.

---

## 3. Frame controllers (`0x00121201`)

### 3.1 The chunk **[checked on the Xbox]**

| Field | Type | Meaning |
|---|---|---|
| version | u32 | 1 in the files at hand |
| name | text | e.g. `PSYS_fxSys_PistolUzi_MuzzleFlashShape` |
| type | 4 characters | what it drives (§3.3) |
| cycle mode | 4 characters | `FWD`, `BACK`, `FDBK`, `BKFD`, `HOLD`, or anything else (§3.2) |
| cycles | u32 (version 1) or f32 (version 0) | how many times to play, when "for ever" is 0 |
| for ever | u32 | not 0: no end (the cycles above are ignored) |
| target | text | what it drives (a shader, a mesh, a particle system, …) |
| animation | text | the animation it plays |

Every controller in the files at hand has the mode word `ANIM` (not one of the five), cycles 0 and
for ever 1: 165 of them (125 `PSYS`, 27 `BQG`, 7 `PTRN`, 5 `VRTX`, 1 `PVIS`) *(check the rest of the game's
files, which were out of reach; SPEC-005 found the "for ever" word always 1)*.

### 3.2 The cycle modes **[checked on the Xbox]**

| Word | Mode | How it plays |
|---|---|---|
| anything else (`ANIM`) | 0 | **as the animation says:** forwards; at the end it wraps round if the animation's cyclic word is 1, otherwise it stops on the last frame |
| `HOLD` | 1 | does not move: stays on its frame |
| `FWD` | 2 | forwards, wrapping, for its cycles (or for ever) |
| `BACK` | 3 | backwards, wrapping, for its cycles (or for ever) |
| `FDBK` | 4 | forwards, then back (ping-pong): at an end the frame bounces back by the amount it overshot and the direction turns |
| `BKFD` | 5 | the same, starting backwards |

Time: frames move by (step in milliseconds × 0.001 × the animation's frame rate × the controller's speed).
With a number of cycles, the controller works out its total time (the range's length × cycles, doubled for
the two ping-pong modes) and stops when that runs out. The range is the whole animation unless a prop
state sets it (SPEC-009 §2).

**So, for the shipped files:** a controller not driven by a prop state loops exactly when its animation's
cyclic word is 1, and otherwise plays once and holds its last frame. No ping-pong is used. Office TVs, the
hot tub's water and other scenery: read the animation's cyclic word. Under a prop state, SPEC-009 §2's
rules take over (the state sets the range, passes, direction and speed).

### 3.3 The types **[checked on the Xbox: the type words the loader checks, and the class each check makes]**

| Type | The game's class | Drives |
|---|---|---|
| `PTRN` | (checked by `pure3d::CharacterController`) | a skeleton's pose (SPEC-005) |
| `TEX` | `TextureAnimationController` | a shader's texture (SPEC-009 §1) |
| `SHAD` | `ShaderAnimationController` | a shader's values (channels `FLT1`, `VECT`, `ROT`, `BOOL`) |
| `VRTX` | `VertexAnimController` | a mesh's vertices |
| `PSYS` | a particle controller | a particle system (SPEC-010) |
| `BQG` | `BillboardQuadGroupAnimationController` | a billboard group (SPEC-007 §5) |
| `CAM` | `CameraAnimationController` | a camera |
| `LITE` | `LightAnimationController` | a light |
| `EXP` | `ExpressionAnimationController` | a face (SPEC-009 §3) |
| `PVIS` | `CompDrawVisibilityAnimationController` | which parts of a composite are shown |
| `EFX` | — | an effect *(check)* |
| `PVRT` | — | accepted by the loader *(check what)* |

All of them share the timing of §3.2; they differ only in what they write.

### 3.4 Prop states and the order question

SPEC-009's answer stands: a state's entries reach the prop's controllers **by position**. Nothing in the
controller chunk changes that.

---

## 4. Corrections to earlier specs

| Spec | Was | Now |
|---|---|---|
| SPEC-001 §4.2 | "What is loaded at a place is the union of every trigger whose outline contains it." | Only one trigger applies: the current one (§1.3), and what is loaded is exactly its list (§2). |
| SPEC-001 §4.2 | height: "how tall the trigger is" | the prism runs from the points' average y up by the height; a height of 0 means no limit (§1.2) |
| SPEC-001 §4.2 | last number: meaning not known | "gives way": while you are inside it, any other trigger holding you takes over (§1.3) |
| SPEC-005 §1.4 | after `ANIM`: a float, the frame the controller starts at, then a u32 that is always 1 | `ANIM` is the cycle mode (meaning "as the animation says"); then the number of cycles (a u32 in version 1, a float in version 0), then "for ever" (§3.1) |

---

## 5. Xbox functions read

| Address | Name (work queue) | What it does |
|---|---|---|
| `0x0947F0` | `StreamTriggerLoader::vfunc_06` | reads a stream trigger |
| `0x093F40` | `sub_00093F40` | builds a trigger: packed outline, box, base and height |
| `0x094340` | `sub_00094340` | is a point inside a trigger |
| `0x090990` | `sub_00090990` | picks the trigger that applies |
| `0x090C90` | `sub_00090C90` | changes the current trigger |
| `0x093AA0` | `sub_00093AA0` | marks a trigger's packages to load or unload |
| `0x093C70` | `sub_00093C70` | loads or unloads the marked packages |
| `0x094710` | `sub_00094710` | goes through a trigger's packages |
| `0x273A20` | `pure3d::FrameControllerLoader::vfunc_06` | reads a frame controller's start |
| `0x274A50` | `pure3d::DefaultFrameControllerHandler::vfunc_05` | reads the rest and makes the controller by type |
| `0x2739A0` | `pure3d::DefaultFrameControllerHandler::vfunc_04` | which types it takes |
| `0x273460` | `pure3d::SimpleFrameController::vfunc_18` | sets the cycle mode |
| `0x2734C0` | `pure3d::SimpleFrameController::vfunc_20` | sets the number of cycles |
| `0x273390` | `pure3d::SimpleFrameController::vfunc_08` | moves the frame on |
| `0x2761A0` | `sub_002761A0` | passes the step to the advance |
| `0x273210` | `pure3d::AnimationFrameController::vfunc_22` | the controller's total time by mode |

The advance itself, `sub_00275E40`, is already in the guide from SPEC-009.

---

## 6. What to build

1. In the map and cutscene exports, pick the stream trigger by §1 (prism test; one trigger; the "gives way"
   one last), and load exactly its list. Drop the union.
2. For interiors, add the dzone triggers' packages (SPEC-001 §4.3) for places inside them.
3. `p3d.py`: read the frame controller as §3.1 (mode word, cycles, for ever).
4. In the exports, loop a scene controller only when its animation is cyclic (mode `ANIM`); support the
   five other modes even though the shipped files don't use them.
5. FORMATS.md: §3.1 and the trigger fields, in your own words.
6. Match the §5 functions, small ones first.

---

## Questions from the implementer, and answers

*From the implementer, 19 November 2026, after building §6 steps 1 to 5 and running them on the PC's files:*

* **Built.** `stream_graph.py`: the prism test (§1.2: box, crossing count on the outline counted in tenths,
  the base and height in tenths cut down, height 0 no limit), one trigger (§1.3: the first in file order
  whose prism holds the place, `loadTrigger_258`, the one that gives way, last), and exactly its list (§2).
  The zone scripts' triggers (`dzone_triggers.dso`: 61, `azone_triggers.dso`: 27) are read from the
  decompiled scripts and their packages added. `p3d.py` reads the frame controller by §3.1;
  `p3d_gltf.controller_play` plays the five modes of §3.2 (mode 0 left to the animation's cyclic word).
  `check_frame_controllers.py` and a test (run with the game's files) look at every controller.
* **On the PC's files:** all **588** frame controllers are `ANIM`, 0 cycles, for ever, version 1 (160 `PTRN`,
  131 `PSYS`, 121 `BQG`, 80 `TEX`, 38 `VRTX`, 31 `PVIS`, 20 `LITE`, 7 `CAM`). All 6,652 prop state effects
  (`0x0802000B`) have 0 in both their "number" fields, so whichever is SPEC-010 §1.10's start-kind, every
  shipped effect is held on its joint.
* **Jerry's office** (`NIS_10_jerry`, Tony at x −1375, y 13.8, z 431.5): `loadTrigger_448` holds the place on
  the ground but stops at 10, so **no prism holds it**, and by §1.3 the game keeps what it had. The
  furniture there (desks, chairs, books: `luxurybank_02_detailB`) is only in `loadTrigger_400`'s list
  (subzone `luxurybank_02_shell`, no height limit, 26 units away at the back of the bank). The dzone script
  adds `cgrove_branchBank_dzone` there (plants, ashtrays, cameras), not furniture. The export now takes,
  above every prism, the nearest trigger of the building round it (a shell the ground triggers list that is
  not their own subzone) that reaches the height: `loadTrigger_400`.
* **Questions.** (a) Is that right for the bank: does the way upstairs pass through `loadTrigger_400`, so
  `luxurybank_02_detailB` is still loaded in Jerry's office? (b) The point fed to §1.3: the player's or the
  camera's? A cutscene's camera can stand in another trigger from the people. (c) The coarser outline step
  when an outline is too wide for tenths: how is it chosen? The export uses width / 32767. (d) §6 step 6
  (matching the §5 functions) needs the compiler, which runs on the founder's computer; not done here.
