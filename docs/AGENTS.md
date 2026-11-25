# Instructions for AI agents

Read [SCARFACE_DECOMP_AI_HANDOFF.md](SCARFACE_DECOMP_AI_HANDOFF.md) first: it explains what a matching
function is, what the verifier accepts and the code generation facts for this compiler. The rules in
[docs/METHODOLOGY.md](METHODOLOGY.md) are the ones the verifier enforces.

## Working through the local portal

The portal (`python portal/decomp_portal_server.py`, default `http://127.0.0.1:8085`) is the only thing that
can record a function as verified. Every request that changes something needs the contributor's
`user` (handle) and `pin`; ask the person you are working for, and never store or print the PIN.

| Step | Request | Notes |
| :--- | :--- | :--- |
| Find work | `GET /api/queue?tier=TIER_1_QUICK&page=1&limit=80` | also `q=` (symbol or address), `sort=SIZE_ASC` |
| Read a task | `GET /api/task?id=<id>` | `target_hex`, `disasm_lines`, `size`, `symbol`, `starter_cpp` |
| Claim it | `POST /api/claim {"user", "pin", "id"}` | a timed lease; fails if someone else holds it |
| Check code | `POST /api/verify {"user", "pin", "id", "cpp_code", "tool_used", "what"}` | returns `matched_bytes`, `total_bytes`, `diff_details`, `verified`; `what` (optional) is a one-line, plain-English description saved with a new match; `match` (optional) picks the compiled function by part of its symbol (a template instantiation, a compiler helper) and `flags` (optional) drops some of the function's flags or adds `/arch:SSE` |
| Describe a rebuilt function | `POST /api/describe {"user", "pin", "id", "what"}` | sets or clears its one-line description (at most 160 characters), credited to you |
| Give up | `POST /api/cancel {"user", "pin", "id", "cpp_code"}` | releases the claim and keeps your best partial attempt |
| decomp.me target | `GET /api/decompme?id=<id>` | `obj_b64` (COFF target), `fields` for `POST https://decomp.me/api/scratch`, `existing_url` |
| Remember a scratch | `POST /api/decompme {"id", "slug"}` | or `{"id", "create": true}` to have the portal create it |

Without the portal, `python portal/verify.py file.cpp --va 0x... --bin pc|xb --show-diff` applies the same
rules but records nothing.

## Rules

* Only the compiler's verdict counts. Never report a function as matched unless `verified` is `true`.
* Claim before you work on a function, and cancel when you stop, so nobody duplicates the effort.
* Plain C++ only: no inline assembly, `_emit`, `naked` functions, section pragmas or byte arrays.
* No 2006 addresses as numbers: use address-named externs such as `extern "C" char DAT_00439DA4;`.
* Don't edit `reports/verified_registry.json` or the generated files (`Original_Binary_Order_*.cpp`,
  `reconstructed_src/pc/`, `reconstructed_src/xbox/`) by hand.

## What the project knows, beyond matching

For decompiling, remastering or remaking the game, start from these. Everything here was checked on the game's
own files or programs, or written up through the clean room ([CLEAN_ROOM.md](CLEAN_ROOM.md)).

| Need | Where |
| :--- | :--- |
| Every file format: archives, `.p3d` models, skins, skeletons, animations, maps, lights, sky, fog, the sea, shadows, sounds, videos, scripts | [FORMATS.md](FORMATS.md) |
| Reading them in code | `portal/tools/p3d.py` (chunks), `portal/tools/rcf.py` (archives, by path through the game's name hash), `portal/tools/textures.py`, `portal/tools/script_*.py` / `torque_*.py` (scripts) |
| Models, characters with skins and animations, cameras, whole map areas to glTF and Blender | `portal/tools/p3d_gltf.py`, `portal/tools/blender_export.py`; the portal's **Open in Blender** and **In Blender** ([FORMATS.md, Exporting to Blender](FORMATS.md#exporting-to-blender)) |
| How the game plays animations (keys, steps, slerp, looping, toggles, frame controllers) | [SPEC-005 §1](cleanroom/SPEC-005-animation-drawing-renderer.md#1-playing-an-animation) |
| How the game draws a frame (draw lists, order, depth writes, fading by distance) | [SPEC-005 §2–3](cleanroom/SPEC-005-animation-drawing-renderer.md#3-how-the-pc-draws-a-frame), [SPEC-002](cleanroom/SPEC-002-materials-ocean-shadows.md) (see-through surfaces, the sea, shadows) |
| Lights, time of day, the sky, which areas stream in where | [SPEC-001](cleanroom/SPEC-001-lights-sky-streaming.md) |
| Props and their states, draw distances, occluders, how the Xbox blends | [SPEC-003](cleanroom/SPEC-003-props-zones-xbox-blending.md) |
| The renderer's classes: sizes, fields, what each table slot does | [SPEC-005 §4](cleanroom/SPEC-005-animation-drawing-renderer.md#4-the-renderers-classes-pc-layouts) |
| Which lights reach an object; placed props (trees, bushes) at run time: culling, waking, wind; the water reflection; the frame-time budget | [SPEC-006](cleanroom/SPEC-006-lights-placed-props-reflection.md) |
| Billboards: the sun and its flares, the moon, street-lamp and car-light glows, mission markers; how each kind faces the camera, fades and animates | [SPEC-007](cleanroom/SPEC-007-billboards.md) |
| The horizon's colour through the day; the cars' dents (per-vertex damage); the cut-scene package's file entry; the exporter's notes | [SPEC-008](cleanroom/SPEC-008-horizon-dents.md) |
| Texture animations (`TEX`); a prop state's animation settings, clock and effect times; cutscene faces of people other than Tony; where cutscene lines (subtitles) are and how they are timed; text bibles; corrections to SPEC-005 and FORMATS.md | [SPEC-009](cleanroom/SPEC-009-texture-anims-prop-states-cutscene-text.md) |
| Particle effects (`0x1580C`, emitters, generators, life curves); cutscene effects, gun fire, blood marks, fades; two-handed grips | [SPEC-010](cleanroom/SPEC-010-cutscene-effects-particles-grips.md) |
| Which stream trigger applies at a place and what unloads; frame controllers' cycle modes and types | [SPEC-011](cleanroom/SPEC-011-streaming-frame-controllers.md) |
| The game's name key (how objects are found by name) | [SPEC-006 §5](cleanroom/SPEC-006-lights-placed-props-reflection.md#5-the-games-name-key-checked-on-the-xbox) |
| What functions do: the Xbox ones the specs cover, about 500 PC ones (renderer, draw list, lights, placed props, render calls) and about 230 engine ones marked low confidence, whose Xbox twins do the same | [function_guide.json](function_guide.json) |
| Names given so far, and why | `reports/names.json`, [NAMES.md](NAMES.md) |
| The game's versions and what differs | [VERSIONS.md](VERSIONS.md), [GAME_VERSIONS.md](GAME_VERSIONS.md), [PS2.md](PS2.md) |

### Open work from the specs

* [SPEC-004 §5](cleanroom/SPEC-004-xbox-functions.md#5-what-to-build): five Xbox functions still to match
  (`sub_00282950`, `sub_00282820`, `sub_002828C0`, `sub_00042AB0`, `occlude::OccluderLoader::vfunc_06`); the
  spec says what each does, step by step.
* [SPEC-005 §6](cleanroom/SPEC-005-animation-drawing-renderer.md#6-what-to-build): Boolean and Float2
  animation channels, an animation sampler, `STEP` and visibility in the glTF export, prop-state animation
  settings, draw distances and depth writes in the city export and viewer, FORMATS.md sections, and one-line
  descriptions for `renderer::` functions.
* [SPEC-006 §7](cleanroom/SPEC-006-lights-placed-props-reflection.md#7-what-to-build): the name key in
  `p3d.py`, placed props' view distances and wind in the city export, lights per object, the reflection.
* [SPEC-007 §7](cleanroom/SPEC-007-billboards.md#7-what-to-build): billboards in `p3d.py`, FORMATS.md,
  the glTF and Blender exports and the viewer; then the Xbox billboard functions of its §6.
* [SPEC-008 §4](cleanroom/SPEC-008-horizon-dents.md#4-what-to-build): texture-offset sets and dents in
  `p3d.py`, FORMATS.md, the horizon by the hour in the sky, dents as morph targets in the car exports.
* [SPEC-009 §8](cleanroom/SPEC-009-texture-anims-prop-states-cutscene-text.md#8-what-to-build): the
  mixer and text-bible fields in `p3d.py`, prop states and their clock in the exports, texture animations,
  every cutscene face, cutscene subtitles; it also corrects SPEC-005 §2.1 and §1.3 (its §6).
* [SPEC-010 §10](cleanroom/SPEC-010-cutscene-effects-particles-grips.md#10-what-to-build): particle
  chunks in `p3d.py`, a particle player, cutscene effects, gun fire and fades in the exports.
* [SPEC-011 §6](cleanroom/SPEC-011-streaming-frame-controllers.md#6-what-to-build): one stream trigger
  at a time in the exports, dzone triggers for interiors, frame controller cycle modes; it corrects
  SPEC-001 §4.2 and SPEC-005 §1.4 (its §4).
* In `function_guide.json`, every function with `"status": "open"` is waiting to be matched.

When you finish a spec's work item, say so in the pull request and answer its questions in the spec's
*Questions from the implementer* section. If the files or programs disagree with a spec, they win: fix the
spec in the same pull request.

### The clean-room rule

Some of this knowledge came from research done next to the game's leaked source. Until 25 November 2026 it
reached the project only as the specs in [docs/cleanroom](cleanroom), written in their own words. Leaked
source and leaked symbol files still reach it only that way. If you write code from the specs:

* don't open or search for leaked source or leaked symbol files, and don't paste in code from them.
  Since 25 November 2026 the published research itself (`scarface-p3d`, its notes and name lists, and
  tools built on it) is open to read: check it against the game, credit it, and copy code only where
  its licence allows;
* choose your own names, or take them from this repository, the game's own text and the class names in its
  run-time type information. A name from published research is allowed once you have checked it against the
  code: record it in `reports/names.json` with the research as its source (`by`, `why`) and name the
  research in [CREDITS.md](CREDITS.md). Never a name from leaked source or leaked symbol files;
* note in your pull request which spec you worked from, so [CLEAN_ROOM.md](CLEAN_ROOM.md) can record it.
