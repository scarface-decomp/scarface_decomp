# Clean-room spec 009: texture animations, prop-state timing, cutscene faces and lines, text bibles

* **Written by:** the examiner side (see [CLEAN_ROOM.md](../CLEAN_ROOM.md)), on 18 November 2026, answering the
  implementer's six questions. The outside research has almost nothing on these topics: it names the
  texture-animation type, lays out the prop-state chunks, and guesses at the effect's last float. Nearly
  everything below was therefore read directly from the user's US PC files and from the user's own Xbox
  `default.xbe`, in the examiner's own words. The implementer must not open the research.
* **What this is:**
  1. texture animations (type `TEX`);
  2. a prop state's animation settings, the state's own clock, and the effect's last float;
  3. the faces of cutscene people other than Tony;
  4. where an in-engine cutscene's spoken lines are, and how they are timed;
  5. text bibles, field by field;
  6. corrections to SPEC-001 to SPEC-008, and to FORMATS.md.

  No code, and no names from the research. Class names are the game's own, from the Xbox program's run-time
  type information. Function names are the work queue's.
* **How sure:**
  * **[checked]**: read from the PC files with the repository's chunk reader.
  * **[checked on the Xbox]**: read from `default.xbe` with a disassembler.
  * *(check)*: a reading not yet confirmed, which the implementer should verify.

  If the files or the program disagree with this spec, they win: fix the spec in the same pull request.

---

## 1. Texture animations (type `TEX`)

### 1.1 Where they are **[checked]**

16 animations of type `TEX` in `packages/z04` (and the same ones in their `art/ecoprops` sources):

| File | Animation | Keys | What |
| :--- | :--- | ---: | :--- |
| `babylonclub_01_shell.p3d`, `bsand_02_detail.p3d` | `TEX_sparkle_m` | 5 | the disco ball's sparkle, `sparkle.001.bmp` to `.005.bmp` |
| `downtown_region_D`, `nbeach_region_D`, `sbeach_region_D`, `babylonclub_01_detailB`, `babylonclub_03_detail`, `penthouse_01_detail`, `stripmall_01_detail` | `TEX_WaterSurfaceA_x128_gFX_PoolWaterSurfaceB`, `TEX_WaterSurfaceB_PoolWaterSurface_SmallB`, `TEX_pure3dSimpleShader1` | 20 | swimming-pool light, `CausticWaterA_x64_rgb.01.bmp` to `.20.bmp` |
| `bsand_02_detail.p3d` | `TEX_T_Tanker_CausticWaterA_x64_rgb__simple_alpha_none` | 20 | the same, `CausticWaterB` |
| `tonymansion_02_detailB.p3d` | `TEX_TMPoolSurface_water` | 82 | Tony's pool, 82 keys over 101 frames, some frames skipped |
| `islands_LOD_D.p3d` | `TEX_bodyFloatA__simple`, `TEX_bodyFloatB__simple` | 2 | two pictures that alternate, `bodyFloatA.00.bmp` / `.01.bmp` |

They play at 24 or 30 frames a second; all but the two `bodyFloat` ones are marked cyclic in their own
header.

### 1.2 The animation **[checked]**

One group, named like the animation, holding one **Entity channel** (`0x00121107`) whose parameter is `TEX`:

| Order | Type | Meaning |
| :--- | :--- | :--- |
| 1 | u32 | version (0) |
| 2 | 4 characters | parameter: `TEX` |
| 3 | u32 | key count *n* |
| 4 | *n* × u16 | key frames |
| 5 | *n* × text | the name of a texture (`0x00019000`), one per key, in the usual length-prefixed form |

There is no interpolation-mode sub-chunk, and a name can't be blended.

### 1.3 What it changes **[checked on the Xbox]**

Only the texture. A texture animation **swaps the shader's texture**. It does not move, scale or turn
texture coordinates; those come from other chunks (SPEC-008's texture offsets, the billboards' `OFF`
channel).

Each update the controller does three things:

1. It takes the frame it has reached, drops the fraction, and finds the last key at or before that frame. Before
   the first key it uses the first key; after the last key, the last key.
2. It takes that key's texture. The names are turned into textures when the file loads; a name that isn't
   loaded gives nothing, and the shader keeps whatever texture it had.
3. It gives the texture to the shader under the channel's parameter. `TEX` is the shader's base texture, the
   one SPEC-002 calls `TEX`.

### 1.4 What it changes it on **[checked] [checked on the Xbox]**

The `TEX` frame controllers (`0x00121201`, type `TEX`) sit **inside the mesh pieces** they animate. A piece's
controller list is chunk `0x00121204`, inside the piece `0x00010020`:

| Piece (file) | Its shader | Its controller |
| :--- | :--- | :--- |
| `bcdiscoballInstanceShape`, `sparkleShape` (`babylonclub_01_shell.p3d`) | `LocalShader_sparkle.001.bmp_simple_blmd2_...` | `TEX_sparkle_m` |
| `gFX_PoolWaterSurfaceBInstanceShape`, `Surface_BottomShape` and four more (`downtown_region_D.p3d`) | `GlobalShader_CausticWaterA_x64_rgb.01.bmp_simple_blmd1_...` | the three pool animations |
| `bodyFloatAinstanceShape` (`islands_LOD_D.p3d`), two pieces | `LocalShader_bodyFloatA.00.bmp_...`, `...B.00...` | `TEX_bodyFloatA__simple`, `...B__simple` |

The Xbox's mesh-piece reader reads the list and **hands every controller in it to the piece**. A
`TEX`-type controller then takes the piece's shader and works on that. This is how the target is found.

The name the controller says it drives (`sparkle_m`, `WaterSurfaceA_x128_gFX_PoolWaterSurfaceB`,
`pure3dSimpleShader1`, `TMPoolSurface_water`) is **not the name of any shader** in the US files: they are the
artists' material names. The program does also look for a shader by that name when it creates the
controller, but it finds none and leaves that part unset. Each file also has one more copy of each
controller at its top level. That copy is tied to nothing, and nothing advances it.

A shader is one object, shared by every piece that names it. Changing its texture changes them all. In
`downtown_region_D.p3d` three animations drive the same caustic-water shader, so each update the last one
to run wins *(check)*.

### 1.5 When it runs

* Like any frame controller: the frame moves on at the animation's frame rate × the controller's speed
  (§2.3). Units are the animation's own frames.
* Under a prop state, the state's settings apply (§2). The disco ball names both pieces' controllers in each
  of its states, with settings (0, 0, 0) and frames 0 to 0. By §2.2 that stops them on frame 0, so in the
  shipped game the sparkle shows `sparkle.001.bmp` and does not cycle *(check in the running game)*.
* Tony's pool has (1, 0, 0) and frames 0 to 23, at speed 1, so it cycles for ever.

---

## 2. A prop state's animation settings, and the state's clock

### 2.1 `0x08020003`, again **[checked] [checked on the Xbox]**

| Order | Type | Meaning |
| :--- | :--- | :--- |
| 1 | text | the frame controller's name |
| 2 | u32 | **repeat**: 0 = one pass; 1 = as many passes as the next word says |
| 3 | u32 | **passes**: with repeat 1, how many passes; **0 = no end**. Ignored with repeat 0 |
| 4 | u32 | **carry on**: 1 = if the controller's current frame lies inside the new range, keep it; 0 = start from the first frame |
| 5 | f32 | first frame |
| 6 | f32 | last frame (smaller than the first = play backwards) |
| 7 | f32 | speed (multiplies the animation's frame rate) |

The Xbox keeps the second and fourth words as one byte each (any non-zero is 1), and the third as a number.
In the city's files the combinations are (1, 0, 0) 81 times, (0, 0, 0) 77, (1, 1, 0) 68, (1, 1, 1) 54,
(1, 0, 1) 2 and (1, 2, 0) once. The first and last frames are equal 142 times, increase 106 times and
decrease 35 times. No speed is negative.

### 2.2 Entering a state **[checked on the Xbox]**

The state's entries go to the prop's controllers in order: the first entry to the prop's first controller,
and so on. *(check: how the prop builds that list from the names, in particular for the disco ball's two
entries that share one name.)* For each entry:

1. **First frame equal to last, and carry on 0:** the controller is taken out of the ones that advance,
   reset, put on that frame, and shown once. It stays still on that frame for as long as the state lasts.
   These are the 77 records that "don't play anything": they hold a pose.
2. **Otherwise** it is put among the ones that advance, and:
   * its speed is set;
   * its passes: repeat 0 gives one pass; repeat 1 gives the passes word, where 0 means no end;
   * its direction: first < last runs forwards; first > last runs backwards over the same frames, the range
     being stored smaller-first;
   * its starting frame. Carry on 0 starts at the entry's first frame; for a backwards entry that is the
     larger number. Carry on 1 keeps the controller's current frame when it lies between the two frames, in
     either order; otherwise it too starts at the first frame. This is how a door's `closing` (frames 10 to 0,
     (1, 1, 1)) picks up from wherever `opening` had reached.

Nothing happens to a controller when a state is **left**: only the next state's entry for it decides.

### 2.3 Advancing **[checked on the Xbox]**

Each update brings a time step, which the constants show to be in milliseconds *(check)*:

* **frames moved** = step ÷ 1000 × the animation's frame rate × speed.
* **Forwards:** the frame grows. On reaching the last frame:
  * with passes left, or no end, it wraps round: (frame − last) modulo (last − first), added to first;
  * with none left, it stops **on the last frame** and stays there.
* **Backwards:** the frame falls and wraps at the first frame the same way, stopping on the first frame (the
  smaller number) when no pass is left.
* **"Hold the last frame" needs no flag:** a controller that has run out of passes always stays on its end
  frame. The fourth word is about starting (§2.2), not stopping.
* **A frame past the animation's last key:** the frame is used as it is. Every channel's key search gives
  its last key for any frame at or after it, so the animation sits on its last value until the state's range
  wraps.
  * The disco ball's `final` state (frames 0 to 19 of a 5-frame animation, speed 0.02, (1, 0, 0)) moves
    through frames 0 to 4, holds frame 4's pose from 4 to 19 (25 seconds), then starts again
    *(check in the running game)*.
  * The tanker's water (frames 0 to 22 of a 20-frame texture animation) shows its last texture from frame
    19 to 22 before it wraps.
* **Negative speed:** none in the files. The forward rule would carry the frame below the first frame with no
  wrap, and each step first pulls the frame back into the range. So a negative speed does not run an
  animation backwards; a reversed pair of frames does.

### 2.4 The state's own clock **[checked on the Xbox]**

* **The clock:** separate from its animations, a prop state counts time from the moment it was entered, at
  **30 a second** (the step × 0.03).
* **Moving on:** the state's "moves on" word and frame (FORMATS.md's `0x0802000E`) work on this clock, not on
  any animation's frame. When the clock passes the frame, the prop goes to the named state, and the time
  past the frame is carried into the new state's clock. A door whose `opening` lasts 30 moves on after one
  second whatever its animation's speed.

### 2.5 The Prop State Effect's last float (`0x0802000B`) **[checked] [checked on the Xbox]**

* **What it is:** **the time, on the state's clock (§2.4), at which the effect starts.** Each update the
  program starts every effect whose time lies from the clock's previous value (included) up to its new value
  (not included). So an effect at 0 starts on the first update.
* **In the city's files:** 0 in 927 effects, and 1 to 90 in the rest. For example, the disco ball's `final`
  sends glass and dust at 25 (0.83 s after it breaks), and `smDoorC`'s `half_wrecked` sends wood at 7 and 20.

The chunk's other fields, as the Xbox program uses them:

| File order | Meaning |
| :--- | :--- |
| text | must be `Effect`, or the effect is skipped |
| text | the effect's name |
| u32 | how the effect is placed: 0 = at the joint named next, or at the prop when no joint has that name; 1 = relative to the prop; 2 = as given. 0 in every file *(check: 1 and 2)* |
| text | that joint |
| 3 × f32, 3 × f32 | an offset and angles, applied before the joint or the prop |
| u32 | how the effect is started; three kinds, 0 in every file *(check)* |
| text | a second joint, used by the starting kind |
| f32 | size, multiplied by the prop's own scale |
| f32 | the start time, above |

---

## 3. Cutscene faces of people other than Tony

### 3.1 There is no separate face model **[checked]**

A name like `sheffieldnis_Face` (`MixerModelName` in a script's `NISExpAnimation`) is not a model. It is the
name of two chunks in the cutscene's **own `static.p3d`** (`art/nis/<scene>/static.p3d`), stored next to the
person's cutscene model. `NIS_03_sheffield/static.p3d` holds two people this way, Sheffield and `sbabenis`:

| Chunk | Name | What |
| :--- | :--- | :--- |
| `0x00023000` | `sheffieldnisSkeleton` | 43 joints |
| `0x00010001` | `sheffieldnis_meshShape` | the head-and-body skin, with 13 shapes (`0x00121305`, as FORMATS.md says) |
| `0x00010000` | `sheffieldnis_LeyeShape`, `..._ReyeShape`, `..._UpteethShape`, `..._LowteethShape` | eyes and teeth |
| `0x00021001` | `sheffieldnis_Face` | the expression group: the sliders |
| `0x00021002` | `sheffieldnis_Face` | the expression mixer: ties the group to the skin |
| `0x00123000` | `sheffieldnisDrawable` | the model the script swaps in (`NISSwapModel` `newModel`): the skin on joint 0, the teeth and eyes on joints 15 to 18 |

So `static.p3d` is not just a small file for the loader: it carries the people the scene swaps in. Tony's
suits are the exception: they live in `art/nis/characters/`.

### 3.2 How the face is tied to the person **[checked] [checked on the Xbox]**

* **Group and mixer:** they share the name. The mixer names the skin and the group, and the program finds
  both **by name**. When the group is missing it prints
  `Warning : can't find expression group '%s' for mixer '%s'`.
* **No joint:** none is involved. The shapes move the skin's own vertices, and the skeleton then moves the
  skin as usual. The eyes and teeth simply hang on their joints.

The mixer (`0x00021002`) has no sub-chunks:

| Order | Type | Meaning |
| :--- | :--- | :--- |
| 1 | u32 | version (0) |
| 2 | text | name (`sheffieldnis_Face`) |
| 3 | u32 | 3 in every file seen *(check: a kind)* |
| 4 | text | the skin it works on (`sheffieldnis_meshShape`) |
| 5 | text | the expression group (`sheffieldnis_Face`) |

The group (`0x00021001`) is FORMATS.md's layout. Note that after its count come *count* u32, before the
expressions:

| Order | Type | Meaning |
| :--- | :--- | :--- |
| 1 | u32 | 0 |
| 2 | text | name |
| 3 | text | the mesh |
| 4 | u32 | count (the number of sliders) |
| 5 | count × u32 | one number per slider: Sheffield's are 0, 0, 1, 2, 0, 0, 0, 0, 0 and Tony's all 0 *(check: what they are)* |
| children | `0x00021000` | the expressions (sliders), as FORMATS.md says |

### 3.3 Their animation is the same kind **[checked]**

* **The kind:** the same as Tony's. `EXP_NIS_03_sheffield_sheffield0` (in `stream0.p3d`) is type `EXP`, one
  group per slider named after it, each with one Float1 channel (`0x00121100`) whose parameter is `STE`.
* **Sliders and shapes:** mapped exactly as FORMATS.md's *Faces* says (each expression's values, and the
  shape fully on at each value).
* **The differences:** the people other than Tony have **9 sliders** with no left and right (`E___Brow_Angry`,
  `H___Eye_Blink`, ...) and 13 shapes. Tony has 14 sliders (`..._Left`, `..._Right`).

A face that stays still is one whose model, group and mixer were not read from the scene's `static.p3d`.

---

## 4. A cutscene's spoken lines

### 4.1 They are named by the script **[checked]**

Every subtitled cutscene line is a script call on a track, at a frame of the cutscene:

```
NISScriptFunctionCallTrack
{
    FrameBegin 136;
    ScriptFunctionCall "SubtitleManager_LocalisedDialogueEvent( ^nis\\\\MNIS_A23_0_Intro_to_Tranq_02^, 0, 2600 );";
};
```

* **How many:** 474 such calls in the 189 scripts (`art/nis/fsc/*.fsc`).
* **The name:** between `^` marks. The file doubles the backslashes twice, so the name is
  `nis\MNIS_A23_0_Intro_to_Tranq_02`.
* **The end:** each scene ends with a call to `SubtitleManager_ClearDialogueEvents();`.

### 4.2 Which file holds a line's text **[checked] [checked on the Xbox]**

The program puts `localised\english\` in front of the name (its format text is `localised\%s\%s`, with
`english`). The line's subtitle file is the usual one for that path: `art/subtitles/<x>/<16 hex>.p3d`, named by
the 64-bit name key of the path in lower case (`media.subtitle_file`). For example, the path
`localised\english\nis\MNIS_A23_0_Intro_to_Tranq_01` gives `art/subtitles/c/c8c7f4b0e0999977.p3d`, which
reads "Tony the Colombians have hit back hard."

* 404 of the 473 calls read this way have their file; **69 have none** *(check: those lines may have no text
  in the US version)*.
* No `.rsd` has these names: the speech itself is in the scene's single track (`..._00`), and the lines are
  only text.

### 4.3 Timing **[checked on the Xbox]**

| Where | Meaning |
| :--- | :--- |
| `FrameBegin` | the cutscene frame at which the line is queued *(check: 30 frames a second)* |
| first number | when the line's first caption appears, in milliseconds after it is queued (0 in every call) |
| second number | how long the whole line stays up, in milliseconds |
| an optional fourth argument | a priority; 10 when absent *(check: what it decides)* |

The subtitle file's two s32 (FORMATS.md: "two s32 (-1)") are the same two times: when a value is greater than
0 it **replaces** the script's number. All cutscene lines have −1 and −1, so the script decides. 45 subtitle
files carry their own times instead: phone calls, such as 2500 and 61500, or 2210 and 34200.

### 4.4 A line becomes captions **[checked on the Xbox]**

* **Splitting:** a line is cut into captions of at most **80 characters**:
  * `#` ends a caption **and moves to the next speaker**;
  * `@` ends a caption, with the same speaker;
  * otherwise, when more than 80 characters remain, the cut goes at the last `.`, `!` or `?` within the 80;
    if there is none, at the last `,` or `;`; if none, at the last space.
* **Timing:** each caption gets a share of the line's time in proportion to its number of characters. The
  first starts at the first number, and each next one when the one before ends.
* **The speaker number:** a count goes up at each `#` and is kept with each caption *(check: whether it
  changes the caption's colour or side)*. Phone calls use `#` between speakers ("Hello? #Hey, Rico, ...").

### 4.5 A second layout of the subtitle chunk **[checked]**

* **What differs:** about 40 subtitle files (`e/e249f589b10010…` and others) store the language name's
  length as a **u16**, not a u32. The name follows with its terminating zero, without padding, and then the
  rest as usual.
* **At least one file** (`1/1328f5dd05930a95.p3d`) is different again: a 16-bit length, the path
  `vocal/english/tony/death_00_01`, the two s32, then the text as 8-bit characters. `f/f332c0701b6d3a70.p3d`
  and `…71.p3d` also start with a 16-bit length and may be the same kind.
* *(check whether the game reads either.)*

---

## 5. Text bibles **[checked: all 140 bibles in the PC files] [checked on the Xbox]**

### 5.1 `0x0001800D` text bible

| Order | Type | Meaning |
| :--- | :--- | :--- |
| 1 | text | the bible's name (`HINTS`) |
| 2 | u32 | how many languages (1 in all 140) |
| 3 | text | the languages' letters, one per language (`E` in all 140) |
| children | `0x0001800E` | one per language |

### 5.2 `0x0001800E` one language

| Order | Type | Meaning |
| :--- | :--- | :--- |
| 1 | text | the bible's name again |
| 2 | **1 byte** | the language letter (`E`). It is not padded, so every number after it starts at an odd offset |
| 3 | u32 | line count *n* |
| 4 | u32 | `0x0001003F` = 65599, the multiplier of the game's name key. All 140 have it. The Xbox keeps it, but its look-up uses its own fixed key and never reads it |
| 5 | u32 | the text's size **in bytes** |
| 6 | *n* × u32 | each line's key, ascending: the 32-bit name key of the line's id (`p3d.name_key`) |
| 7 | *n* × u32 | where each line starts, **in bytes** from the start of the text. The Xbox halves this to index the 16-bit text |
| 8 | text size | UTF-16, little-endian. Each line ends with a 16-bit 0; the lines lie in key order |

The chunk ends exactly where the text does (140 of 140).

### 5.3 Using it **[checked on the Xbox] [checked]**

* **Finding a line:** the program keeps every bible loaded. It finds a line by taking its id's key and
  searching each bible's sorted keys in turn; the first bible that has it wins.
* **Bracketed names:** a line can name another line between square brackets. In the PC files there are 211,
  all for buttons (`Press [BUTTON_GRAPHIC_X] to equip this weapon.`). The bracketed id is a line of its own:
  `BUTTON_GRAPHIC_X` is `¶Enter·` in `global_textbible_E.p3d`, and `BUTTON_TEXT_RIGHT_ANALOG` is "the Mouse" in
  `platform_textbible_E.p3d`. The program reads the name between `[` and `]` (turning any character above
  255 into `?`) and looks it up in all the bibles *(check: how the result is put into the line, and what the
  `¶` and `·` marks do)*.
* **Several languages in one file:** the format allows them, one `0x0001800E` per letter listed in the
  `0x0001800D`. The US files have one each.

---

## 6. Corrections to SPEC-001 to SPEC-008, and to FORMATS.md

The old specs are not rewritten; these are the corrections and the answers to their open items.

| Where | What it says | What is right |
| :--- | :--- | :--- |
| SPEC-005 §2.1, third u32 | "when it stops, it stays on its last frame (1) or not (0)" | It decides where the controller **starts** on entering the state (§2.2). Stopping on the end frame always happens (§2.3). The old reading came from the research's naming of that field, which the Xbox program contradicts. |
| SPEC-005 §2.1, second u32 *(check)* | 0 "seems to mean no limit" | Confirmed, but only with the first u32 at 1. With 0 there is one pass and this word is ignored (§2.1). |
| SPEC-005 §2.1, last paragraph | the 77 records with frames 0 to 0 "don't play anything" | They hold the prop still on that frame: the pose is applied once, and the animation doesn't advance (§2.2). |
| SPEC-005 §2.1, SPEC-003 §1.6 *(check)* | the Prop State Effect's last float is not known | It is the effect's start time on the state's clock, in thirtieths of a second (§2.5). |
| SPEC-005 §1.2 *(check)* | the Entity channel is not decoded | Decoded: §1.2 and §1.3. The value at a frame is the key at or before it; no blending. |
| SPEC-005 §1.3 | a looping frame "wraps round (the remainder after dividing by the length)" | A frame controller's default range is frame 0 to **length − 1** (reset sets it so), and it wraps from there back to 0: the remainder after dividing by length − 1. This answers SPEC-005's open question: the sky's 241-frame animation runs from 0 to 240 and jumps straight back to 0. Frame 240 and frame 0 are the same moment; nothing is held for an extra frame, and nothing blends from the last key to the first. Under a prop state the range is the state's own (§2.3), and the animation's own looping flag is not used. |
| FORMATS.md, Prop State | a passing state moves on "when its animation reaches the frame" | It moves on when **the state's own clock** (30 a second) reaches the frame, whatever the animation's speed (§2.4). |
| FORMATS.md, Prop State Animation | "no code was found that reads them back" | Found (§2.2, and §7's function list). |
| FORMATS.md, Cutscenes | `static.p3d` holds "small files for the game's loader" | It also holds the people the scene swaps in, with their faces (§3.1). |
| FORMATS.md, Subtitles | "two s32 (-1)" | Two times in milliseconds that override the script's (§4.3), and 41 files use a 16-bit name length (§4.5). |
| FORMATS.md, Text bibles | "a language letter"; "where each line starts" | The letter is one byte, unpadded; the starts are in bytes; `0x0001003F` is 65599 (§5.2). |

Nothing else in the research contradicts SPEC-001 to SPEC-008, as far as the examiner found while checking
those specs' remaining *(check)* items against it. The research has nothing on most of them.

---

## 7. Xbox functions **[checked on the Xbox]**

For matching, by work-queue name. All are in [function_guide.json](../function_guide.json).

| Function | Bytes | What it does |
| :--- | ---: | :--- |
| `pure3d::TextureAnimationController::vfunc_09` (`0x002A7F70`) | 149 | each update: the texture at the frame goes to the shader (§1.3) |
| `pure3d::ShaderAnimationController::vfunc_07` (`0x002A80A0`) | 102 | given an object: a mesh piece's shader, or a shader itself, becomes the target |
| `sub_002A8160` | 41 | sets the target shader directly |
| `pure3d::DefaultFrameControllerHandler::vfunc_05` (`0x00274A50`) | 1734 | makes a frame controller of the chunk's type; for `TEX` it also looks for a shader by the driven name |
| `sub_000511F0` | 39 | finds a shader by name in the loaded objects |
| `sub_0025AC40` | 297 | reads a controller list (`0x00121204`) and gives each controller to its owner (§1.4) |
| `sub_00287020` | 199 | a channel's key search: the keys either side of a frame |
| `sub_00287CE0` | 47 | an Entity channel's value at a frame |
| `sub_00281400` | 622 | applies a prop state's animation settings (§2.2) |
| `pure3d::prop::StateProp::vfunc_08` (`0x00281940`) | 698 | a prop's update: the state's clock, moving on, effects (§2.4) |
| `sub_002816F0` | 122 | starts the effects due between two clock values |
| `sub_00280CC0` | 773 | places and starts one state's effects (§2.5) |
| `sub_00275E40` | 812 | moves a frame on by direction, passes and range (§2.3) |
| `sub_002761A0` | 70 | turns a time step into frames (÷ 1000 × frame rate × speed) |
| `pure3d::SimpleFrameController::vfunc_08` (`0x00273390`) | 97 | advances a controller |
| `pure3d::SimpleFrameController::vfunc_14` (`0x00273C80`) | 96 | sets the frame, kept inside the range |
| `pure3d::SimpleFrameController::vfunc_16` (`0x00273CE0`) | 149 | sets the range |
| `pure3d::SimpleFrameController::vfunc_18` (`0x00273460`) | 91 | sets the direction kind |
| `pure3d::SimpleFrameController::vfunc_20` (`0x002734C0`) | 91 | sets the number of passes |
| `pure3d::SimpleFrameController::vfunc_25` (`0x00273D80`) | 73 | resets: range 0 to length − 1, speed 1, frame 0 |
| `pure3d::AnimationFrameController::vfunc_22` (`0x00273210`) | 300 | how many frames are left to play |
| `sub_002763A0`, `sub_00276C40` | 57, 89 | put a controller among the ones that advance, take it out |
| `pure3d::prop::StatePropDataLoader::vfunc_06` (`0x0026ECB0`) | 2606 | reads a prop's data, including the effect fields of §2.5 |
| `sub_000CA6A0` | 124 | the script call `SubtitleManager_LocalisedDialogueEvent` (§4.2) |
| `sub_000CB870`, `sub_000CB2F0` | 141, 272 | queue a dialogue line |
| `SubtitleManager::SubtitleFlowClient::vfunc_02` (`0x000CB650`) | 541 | the subtitle queue's update |
| `sub_000CAC50` | 584 | cuts a line into captions and times them (§4.4) |
| `sub_000CA8E0` | 129 | the caption-cutting character classes |
| `pure3d::TextBibleLoader::vfunc_06` (`0x0026E620`), `sub_0024DD60` | 43, 461 | load a text bible (§5.1) |
| `sub_0024D490` | 286 | reads one language (§5.2) |
| `sub_0024D900` | 120 | finds a line by its id in all the bibles |
| `sub_0024D9B0` | 156 | reads a bracketed id inside a line |
| `sub_0028E5D0`, `sub_0028E550` | 64, 35 | a language's key search; a line's text from its index |
| `pure3d::VertexOffsetExpressionMixerLoader::vfunc_06` (`0x002706F0`) | 424 | reads an expression mixer (§3.2) |

---

## 8. What to build

For the implementer. Choose your own names; keep each step small.

1. **`p3d.py`:** read the expression mixer `0x00021002` (§3.2) and the expression group's per-slider numbers. Read the
   text bible's one-byte language letter, and its starts in bytes (§5.2); test it on a real bible
   (`textbible/HINTS_textbible_E.p3d`: 113 lines). Read the subtitle chunk's two times, and both of §4.5's
   layouts.
2. **Prop states in the exports and the sampler:** name and use the three words as §2.1 says.
   * Freeze the first-equals-last entries on their frame (§2.2).
   * Run first > last backwards.
   * Wrap at the state's last frame, and stop on the end frame when the passes run out (§2.3).
   * Use carry on when one state follows another.
3. **The state's clock:** move a passing state on by its clock, not its animation (§2.4), and give each effect
   its start time (§2.5) in the exports' extras.
4. **Texture animations:** in the glTF and Blender exports, give the pieces in §1.4 their texture sequence,
   frame by frame (as a texture-swap animation in the extras, or as separate materials keyed in Blender), and
   follow §1.5 for what a prop state does to it.
5. **Cutscene faces:** read every swapped-in person from the scene's `static.p3d` (§3.1). Find the mixer named
   by `MixerModelName`, and through it the skin and the group, so every face in a cutscene moves as Tony's
   does (§3.3).
6. **Cutscene lines:** gather each scene's `SubtitleManager_LocalisedDialogueEvent` calls. Turn each into
   captions with times (§4.2 to §4.4), and show them in the portal's cutscene view and as subtitles in an
   export (an `.srt` beside the video or glTF).
7. **FORMATS.md:** put §1.2, §2, §3.1 and §3.2, §4 and §5 into their sections in your own words, and correct
   the lines §6 lists.
8. **Decomp:** match §7's functions, small ones first (`sub_000511F0`, `sub_002A8160`, `sub_00287CE0`,
   `sub_0028E550`, `sub_002763A0`), each with its guide entry's description.

### Questions from the implementer, and answers

*(none yet)*

*From the implementer, 18 November 2026, after reading the whole spec and before building §8:*

* **Checked on the PC's files, and they agree.** §5: `media.text_bible` (written before this spec) reads
  all 114 bibles I could find by name, with their keys ascending; `textbible/HINTS_textbible_E.p3d` has 113
  lines and `BUTTON_GRAPHIC_X` is `¶Enter·`. §4.1 and §4.2: 189 scripts, 474 calls, and the example path
  gives `art/subtitles/c/c8c7f4b0e0999977.p3d`, which is there; 405 of the 474 have a file (the spec says 404
  of 473: one call apart, not looked into). §2.1: over `z04`, `dzones` and `azones` (612 records, a wider set
  than the spec's) the same six combinations of the three words occur and no others, and no speed is negative.
* **Built from §2 (§8 step 2, the export half):** `p3d._prop_animation` names the three words;
  `p3d_gltf.prop_play` and `played` write a prop's animation as its starting state plays it: passes,
  backwards, a held pose for equal frames, the last key held to the end of the range, and looping only for
  repeat 1 with passes 0. On the Babylon Club the disco ball is unchanged (13.3 s, looping), the doors are now
  held on their closed frame instead of swinging once, and `bsand_02`'s fan and film reel loop.
* **Not built yet from §2:** carry on, which needs more than the starting state (the exports play only that
  one); the state's clock moving a prop on (§2.4) and the effects' start times in the extras (§2.5); the
  animation sampler. Steps 1 and 3 to 8 are not started.
* **A question.** §2.2 says a state's entries go to the prop's controllers in order, with the name matching
  left as *(check)*. The export matches by the entry's name, through the Frame Controller of that name to its
  animation. For the disco ball's two `TEX_sparkle_m` entries that gives one answer for both. Is there a file
  where order and name disagree?

*From the implementer, 18 November 2026, on §4 (§8 step 6, and the subtitle part of step 1):*

* **Built:** `media.subtitle_entries` (both lengths of §4.5's first layout, and the two times of §4.3);
  `cutscene.spoken_lines`, `split_line`, `captions` and `srt`; `blender_export.cutscene_captions`; the portal
  writes `<scene>.srt` beside a cutscene it opens in Blender.
* **Not checked on the game's files.** The founder's copied game files were no longer on the computer when
  this was written (the project folder had been set up again), so the new code is tested only on files made
  up from this spec's layouts and its own example. Earlier the same day, with the files there, the example
  path gave its subtitle file and 405 of 474 calls had one. The first run on real files should be looked at.
* **Not built:** §4.5's 8-bit layout; the speaker number is kept with each caption but nothing is done with
  it; a caption in a scene the export joins on after another does not have the earlier scenes' length added;
  the portal's cutscene view does not show the captions yet.
* **Question:** §4.4 says "when more than 80 characters remain". For a run of exactly 80 with no place to
  cut, I keep it whole. Does the game count the 80 before or after the `#` and `@` marks are taken out?

*From the implementer, 18 November 2026, later, with the copied game files back on the computer:*

* **§4 checked on real files.** `blender_export.cutscene_captions` gives captions for 114 of the PC's 187
  cutscenes; `MNIS_A23_0_Intro_to_Tranq` starts "Tony the Colombians have hit back hard." at 0.0 s.
* **Not in the spec, read from the game's files: a cutscene's sound.** The scene's sound script
  (`art/sound/scripts/localised/english/nis/<scene>.p3d`) names one sound for the whole scene; 183 of 187
  PC cutscenes have it and its length matches the scene's. Written up in `docs/FORMATS.md` ("A cutscene's
  sound") and built as `media.stream_names`, `blender_export.cutscene_sounds` and `write_sounds`. The few
  sound scripts that name several sounds (2, 4, 6 and 10) are placed one after the other, which is a guess.
* **Built from §3 (§8 step 5):** `cutscene.read_script` keeps every character's `NISSwapModel`; the export takes
  a swapped-in person's model from the scene's `static.p3d` (the composite named by `newModel`), so the
  expression group there works their face. The mixer chunk itself is not read: the group names its mesh,
  which was enough in every scene. On the PC's 186 readable cutscenes: 450 people, every body moves, 85 use
  their cutscene model, 140 faces move (before: Tony's only). 292 people have no `NISExpAnimation` in their
  script and no shapes on their model, so their faces stay still in the export, as the files have it.
* **Built from §1 (§8 step 4), 19 November 2026:** `p3d_gltf.texture_keys` reads §1.2's Entity channel;
  `texture_controllers` reads a mesh piece's controller list (§1.4); `Builder.texture_animation` puts the
  animation on the piece's material (extras `textureAnimation`: frame rate, length, cyclic, each key's frame and
  texture). glTF cannot swap a texture over time, so the Blender script writes an image sequence beside the
  scene (one picture per scene frame, the key at or before the frame with the fraction dropped, §1.3). On the
  PC files: Tony's pool's 82 keys and the disco ball's 5 go in. A key whose picture is in another area's file
  (the caustics, kept in the regions') is taken from there. Not followed: §1.5's prop-state settings, so the
  disco ball's sparkle cycles here where §1.5 says the shipped game holds frame 0 *(the founder asked for it to
  cycle; worth checking in the running game)*.
* **Found while building it:** instance objects (`0x9900190` of class `instanceobject`) can stand at the top
  of a file, not only in a group (`0x9900191`). They were not read: Tony's hot tub, and 3,240 props on the PC
  (most on South Beach: `sbeachn_05` 1,275, `sbeachn_03` 1,010, `sbeachn_01` 625). Written up in FORMATS.md.

*Answers from the examiner, 19 November 2026, to the two questions above:*

* **Order or name (§2.2)?** By position only [checked on the Xbox]. On entering a state the game walks the
  prop's own list of frame controllers and gives controller *i* the state's entry *i*; it never compares
  names. So where an entry's name and its place disagree, the place wins. Where that list comes from was not
  traced *(check: read as the prop's frame controllers in the order the file gives them)*, and the scan for
  a disagreeing file could not be run (the founder's computer was offline). Keep matching by name, but have
  the export report any prop whose *i*-th entry does not name its *i*-th controller: if none is reported,
  the two ways agree on every shipped file, the disco ball's two `TEX_sparkle_m` entries included.
* **The 80 characters (§4.4): before or after the marks?** Before: the count runs over the stored text with
  `#` and `@` still in it [checked on the Xbox]. In detail:
  * the rest of the line is kept whole when (the text's stored length − the caption's first position + 1) is
    at most 80 *(check: whether the stored length counts a closing zero; if it does not, a run of exactly 80
    is cut)*;
  * otherwise the game looks at the 80 characters from the caption's first; the first `#` or `@` among them
    ends the caption just before it; failing that, the last `.`, `!` or `?`, then the last `,` or `;`, then
    the last space, and the caption includes that character;
  * the next caption starts after it, skipping one `#` or `@` there (a `#` also moves the speaker on);
  * the time share uses the caption's own length (first to last character, inclusive).

*From the implementer, 19 November 2026, on the two answers above:*

* **Order or name.** `p3d_gltf.prop_order_mismatches` and `portal/scripts/check_prop_order.py` list every
  entry whose name is not the controller in its place (the controllers read as those of the file that the
  prop's entries name, in file order). Not yet run on the PC's files.
* **The 80 characters.** `cutscene.caption_spans` now counts over the stored text, marks included, keeps the
  rest whole only when (stored length − first + 1) ≤ 80, skips one mark after a cut, and shares the time by
  each caption's stored length. **A question:** read literally, a remainder short enough to be kept whole
  keeps any `#` or `@` inside it, so `Hello?#Hey.` would be one caption with the mark showing. The export
  still ends a caption at a mark inside a short remainder. Does the game check for marks before the length?
