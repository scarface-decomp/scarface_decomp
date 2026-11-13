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
| Check code | `POST /api/verify {"user", "pin", "id", "cpp_code", "tool_used", "what"}` | returns `matched_bytes`, `total_bytes`, `diff_details`, `verified`; `what` (optional) is a one-line, plain-English description saved with a new match |
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
| Xbox functions the specs explain, with what each does and whether it is matched | [function_guide.json](function_guide.json) |
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
* In `function_guide.json`, every function with `"status": "open"` is waiting to be matched.

When you finish a spec's work item, say so in the pull request and answer its questions in the spec's
*Questions from the implementer* section. If the files or programs disagree with a spec, they win: fix the
spec in the same pull request.

### The clean-room rule

Some of this knowledge came from outside research done next to the game's leaked source. It reaches the
project only as the specs in [docs/cleanroom](cleanroom), written in their own words, so the code written
from them is independent. If you write code from the specs:

* don't open or search for the outside research (`scarface-p3d`, its notes or name lists) or any leaked
  source, and don't paste in code from them;
* choose your own names; take names only from this repository, the game's own text and the class names in
  its run-time type information;
* note in your pull request which spec you worked from, so [CLEAN_ROOM.md](CLEAN_ROOM.md) can record it.
