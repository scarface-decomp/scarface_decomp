# SPEC-013: leads from the 2003 sister game: compiler settings by library, and what the two games still share

**Examiner:** Claude (AI assistant) for RRutherrfordd, 2026-11-23.
**Outside material read:** the leaked development tree of *The Simpsons: Hit & Run* (2003), from the
founder's computer. For this spec: its Xbox project files and release build logs (the game and 14
libraries), and two counts made by script over its source text (class declarations, text literals). No
function body was read for this spec, and no name from the tree is used below.
**For the implementer:** build from this page, the repository and your own copy of the game. Do not open
that tree, its build outputs (maps, symbol files, objects) or anything else in it.

Everything here is a **lead to test on Scarface**, not a fact about Scarface. The sister game was built
three years earlier with the previous compiler (Visual C++ 7.0; Scarface's is 7.1), so its machine code
is not comparable. Its settings are worth trying where a Scarface function refuses to match.

## 1. What the two games still share

Counted by script: a class counts as shared when the sister game's source declares a class whose name,
with the engine's old one-letter or three-letter prefix removed and case ignored, equals the last part of
a class name in `default.xbe`'s run-time type information (`reports/classes.json`, the `xb:` entries).

| Layer, in Scarface's own terms | Shared classes | Their functions in `classes.json` | Verified | Open |
| :--- | ---: | ---: | ---: | ---: |
| Drawing layer (`pure3d::` classes other than the backend) | 102 | 298 | 237 | 61 |
| Graphics backend (`pure3d::d3d…`, `pure3d::pddi…`) | 39 | 199 | 176 | 23 |
| Core layer (`core::`: files, drives, controllers, memory) | 32 | 161 | 104 | 57 |
| Front end (`pure3d::frontend::`) | 12 | 24 | 16 | 8 |
| Sound, music, movie, physics, animation, content loading, the older script library | 22 | 54 | 36 | 18 |
| The game's own code (coincidences such as `Character`) | 18 | 88 | 76 | 12 |

Read with care: the same name does not prove the same code, and `classes.json` counts only functions
already tied to a class (3,993 of the Xbox program's functions). Name matches against the sister game's
tools and sample programs are left out.

* About 210 of the Xbox program's 1,173 named classes have an ancestor in the 2003 engine, all of them
  engine classes. **Scarface's game code is new**: nothing in the sister game explains it.
* Most of the shared engine part is already verified (569 of 736 functions; 167 open).
* The largest open group is the **file layer**: `core::InstanceDrive` (18 of 30 open),
  `core::CementLibrary` (6 of 12), `core::File` (3 of 19), `core::XboxSaveDrive` (3 of 10),
  `core::XboxDrive`, `core::Drive`, `core::DriveThread` and the request classes. A behaviour spec for it
  is the next piece of work on the examiner's side (§4).
* Text shared with the 2003 source (messages kept in release builds) is thin: 324 literals of 30,544.
  125 of them are libpng's and zlib's own messages; 35 belong to a text parser for animation
  parameters (`Unexpected token "%s", expected …`, `Ran out of space for …`); the rest are controller
  input names (`LeftStickX`, `DPadDown`, `XBoxStandard`) and save-drive text (`SaveImage.xbx`).

## 2. How the 2003 Xbox release build was compiled

From the build logs' own command lines. Options the logs share everywhere: `/O2 /GF /MT /Gy /W3 /Zi`.
No log shows a `/G` processor switch or a `/Zp` packing switch.

| Library, in Scarface's own terms | Inlining | `/arch:SSE` | `/GR` | `/EHsc` | `/GS` | Other |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| The game's own code | `/Ob1` | no | yes | yes | yes | `/Zc:forScope`; one precompiled header forced into every file; 246 per-file overrides (not examined) |
| Drawing layer | `/Ob2` | yes | yes | yes | yes | |
| Graphics backend | `/Ob2` | yes | **no** | yes | yes | 90 per-file overrides (not examined) |
| Core layer | `/Ob2` | yes | yes | **no** | yes | |
| Math | `/Ob2` | yes | **no** | yes | yes | |
| Skeleton posing | `/Ob2` | no | yes | yes | yes | |
| Character animation | `/Ob1` | no | yes | yes | yes | |
| Physics, front end, content loading | `/Ob1` | yes | yes | yes | yes | automatic precompiled header |
| The older script library | `/Ob1` | no | yes | yes | yes | |
| Movie, music, sound | `/Ob1` | no | yes | **no** | **no** | `/Og /Oi /Ot /Oy` written out; movie and music add `/Zc:forScope` |
| zlib, libpng (C code) | `/Ob2` | yes | no | yes | yes | |

## 3. What to try, and what is already known not to carry over

1. **`/Ob1` for game code.** The project compiles with `/O2`, which means `/Ob2`: the compiler may
   expand any small function. Under `/Ob1` it expands only functions marked `inline` or defined inside
   their class. Try `/Ob1` on game-code functions (`0x11010` to `0x2331C0`) whose only difference is a
   callee expanded in our build and called in the game. If it fixes a family, it is the game's setting.
2. **`/Ob1` against `/Ob2` by library.** The table splits the engine in two. Where a library function
   fails on the same symptom the other way round (the game expanded a callee we call), keep `/Ob2`;
   where it fails as in item 1, try `/Ob1`. Record which library ranges settle on which.
3. **`/arch:SSE` by library, not by function.** The project adds it when a function uses an `xmm`
   register. Under that switch the compiler also changes float compares and conversions in functions
   that never touch `xmm`. Try it on drawing, backend, core, math, physics and front-end functions that
   fail only in floating-point code, and try removing it for animation and script-library functions.
4. **No `/EHsc` in the core layer**, nor in movie, music and sound. The project has met one unit built
   that way; this says which libraries to expect it in.
5. **`/GS`.** If no verified Xbox function carries the stack-cookie check, Scarface dropped it; say so
   in METHODOLOGY.md and close this item.
6. **Already refuted for Scarface:** the backend was built without `/GR` in 2003, but Scarface's
   backend classes have run-time type information (`pure3d::d3dContext`, `pure3d::d3dDisplay` and the
   rest), so that setting changed. Treat every cell of §2 the same way: a lead until a match confirms it.
7. **Already known in the repository and unchanged by this spec:** the Xbox program's Microsoft library
   code keeps `push ebp` frames and x87 arithmetic (METHODOLOGY.md); that is not a sign of `/Oy-`.

Report back, per library address range: which of `/Ob1`, `/Ob2`, `/arch:SSE`, `/EHsc` verified more
functions than the default list, with counts. The answer goes into this spec.

## 5. Results on Scarface (implementer, 2026-11-23)

Worked from this page, the repository and `default.xbe` only. Script: `portal/scripts/flag_study.py`.
Each function is put in a library by its class (the call graph, the registry and `reports/names.json`;
game code is everything below `0x2331C0`); spans are where 90% of that library's verified functions lie.
The default list is the project's: `/O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4`, plus `/arch:SSE` where a
function's own instructions need it.

**Verified functions** (the 5,570 of 24 bytes or more that have a library; the compiler-made start-up
and shutdown stubs left out), recompiled from their recorded C++ with one switch changed. "Broke" means it
matches with its recorded flags and no longer does with the change.

| Library | Span | Verified | `/Ob1` added: broke | `/arch:SSE` toggled: broke | `/EHsc` removed: broke |
| :--- | :--- | ---: | ---: | ---: | ---: |
| Game code | 0x0298B0–0x213EA0 | 4,571 | 0 | 306 (305 need it, 1 needs it off) | 0 |
| Drawing | 0x254DC0–0x2A7280 | 362 | 0 | 7 (all need it off) | 0 |
| Graphics backend | 0x2640A0–0x2C5470 | 148 | 0 | 6 (all off) | 0 |
| Core | 0x247BD0–0x2C0030 | 99 | 0 | 2 (all off) | 0 |
| Math | 0x242EB0–0x244100 | 8 | 0 | 1 (off) | 0 |
| Front end | 0x248A70–0x28E3C0 | 44 | 0 | 1 (off) | 0 |
| Physics (`ravenphysics::`) | 0x2E4D00–0x2EEB60 | 39 | 0 | 1 (off) | 0 |
| Content loading | 0x23FA10–0x240C50 | 19 | 0 | 0 | 0 |
| `fight::` | 0x239EE0–0x23E8B0 | 55 | 0 | 0 | 0 |
| `om::` | 0x2CEA90–0x2D04D0 | 19 | 0 | 0 | 0 |
| Sound (`audio::`) | 0x2D0EA0–0x2DD640 | 197 | 0 | 2 (all off) | 0 |
| Movie | 0x2E2AD0–0x2E3530 | 9 | 0 | 0 | 0 |

**Failing functions**: every open library function of up to 160 bytes (1,206), and every open game
function of up to 160 bytes that has x87 float code but none of the instructions that need `/arch:SSE`
(208), tried with the starter code's candidates under the same four flag sets.

| | Default matches | `/Ob1`: new matches | `/arch:SSE` toggled: new matches (closer / further) | `/EHsc` removed: new matches |
| :--- | ---: | ---: | ---: | ---: |
| Libraries (1,206) | 18 | 0 | 0 (14 / 106) | 0 |
| Game code, float (208) | 0 | 0 | 0 (3 / 10) | 0 |

What this says, per item of §3:

1. and 2. **`/Ob1` against `/Ob2`: no answer from this test.** No verified function in any library changes
   under `/Ob1`: none of their matched sources depends on the compiler expanding a callee on its own. The
   starter code calls everything it calls, so it can't show it either. Settling it needs a failing function
   whose only difference is an expanded callee; none is known yet. (The project's submission rules don't
   accept `/Ob1` today; that would change only if such a function matches with it.)
3. **`/arch:SSE` is the game code's switch, not the libraries'.** Every verified library function whose
   bytes depend on the switch (20 in seven libraries) matches only without it, and 14 of 120 failing
   library functions whose bytes moved came closer with it. The 2003 table had it on for drawing, backend,
   core, math, physics and front end: in Scarface it is off there. In game code 305 verified functions need
   it and one (`0xD8D70`, which passes a `-1.0f` constant and has no float compare) needs it off; the 305
   are spread through the whole game range, so the game is built with it, perhaps with per-file
   exceptions. This agrees with what METHODOLOGY.md already says (`cmov` and `fcomi` occur only in game
   code) and with the verifier's rule (it tries the switch only where a function's instructions need it).
   Adding it to game functions that don't use SSE-only instructions matched none of 208.
4. **`/EHsc`: no verified function in any library changes without it**, and no failing one matches
   without it. Functions whose code depends on it are the few with destructor clean-up; none of those is
   among the verified library functions yet. Still open; the one unit the project met built without it
   stays the only case.
   **Closed 2026-11-24** (examiner's round Q32–Q43, re-checked): no game or engine function sets up an
   exception frame, and every verified Xbox function, retail and prototype, matches with `/EHsc`
   removed. The Xbox default list no longer has it.
5. **`/GS` is not used.** Neither `default.xbe` nor `game.xbe` holds a stack-cookie check function
   (`cmp ecx, [cookie]; jne; ret`), any of the C runtime's cookie names, or a cookie load in a prologue;
   the 11 `cmp ecx, [address]; jne` sequences in `default.xbe` are ordinary compares. Recorded in
   METHODOLOGY.md; closed.

Side findings. Re-verified with their own flags, 13 verified game functions (all `std::sort`/heap template
instantiations, e.g. `0x29CE0`) match every byte but call another template instantiation that has no
address name, so a fresh check marks one call as unchecked; they were recorded before that check was
strict. The 18 library functions the starter code now matches under the default list (with `__cdecl` for
`__stdcall` where two clean-ups were merged) are added for recording.

## 4. Next on the examiner's side

A behaviour spec for the file layer named in §1 (drives, the request queue and its thread, files, the
archive reader, the Xbox save drive), written from the sister game's source and then checked function by
function against `default.xbe`. Only what the Xbox program confirms will be in it.
