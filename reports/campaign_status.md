# Campaign status (symcov-hinted Xbox functions, symcov import, Hit & Run names)

Kept by the orchestrator at each lane merge. Counts are for the campaign's own functions; the project-wide
count is `python portal/verify.py --status`. A function is listed under "matched" only after the merge gate
printed `MATCH` or `VERIFIED` for it. Nothing here is recorded in the portal yet: that is the owner's step.

| | functions |
|---|---:|
| **Matched under the rules** | 73 |
| Bytes matched | 79 |
| `MATCH-PENDING` (byte-exact, fails a [match] rule) | 1 |
| Byte-exact, kept out by the checker (see below) | 5 |
| Parked below 100% | 1 |

## Matched under the rules

Lane `stl-lib` (merged): 0x00012450, 0x00014FC0, 0x00015FD0, 0x00016910, 0x000169D0, 0x00029CE0, 0x00029D30,
0x0007F600, 0x000C4380, 0x000C47B0, 0x000C4AC0, 0x000EAA10, 0x000EAC60, 0x000EAD50, 0x0010C1F0, 0x001E9290
(`<algorithm>` instantiations; verified with the `// verify:` command in each file, because
`agent.py check` cannot select a template instantiation), 0x000B8790, 0x000C4360, 0x00242D30, 0x00242D50,
0x00292230, 0x002C6A20, 0x002C6A50, 0x002CCCB0, and three that the compiler emits by itself from the
declaration in the file: 0x00012380 (`vector constructor iterator`), 0x00025400 (`vector destructor
iterator`, emitted only without `/EHsc`, so its unit was built without it) and 0x00026740 (`floorf`, the
`<math.h>` inline). The array and pointer globals in those three files exist only to make the compiler emit
the function; their names (`g_00012380`, `g_00025400`, `g_FloorF`) are not globals of the game.

Lane `hint-small` (merged): 46 small game functions, every one printing `MATCH` from `agent.py check`:
0x00011910, 0x0002EAA0, 0x0003DBD0, 0x00063880, 0x000643F0, 0x0006F9C0, 0x00096810, 0x0009ACA0, 0x000A5670,
0x000A6D40, 0x000AB410, 0x000AB430, 0x000CA160, 0x000E7920, 0x0013CE60, 0x001522C0 (named
`CameraTransition::CameraTransition` from the vtable it installs), 0x0015D790, 0x001649B0, 0x00164A10,
0x00164A40, 0x00167CF0, 0x00177F80, 0x0017AC20, 0x0017AC30, 0x001C4640, 0x001D3C50, 0x001D3C70, 0x001F0540,
0x00211990, 0x00213510, 0x00244170, 0x00247FD0, 0x00269B30, 0x00269B50, 0x0027DE20, 0x00283FE0, 0x0029C290, 0x002A08A0, 0x002A0900, 0x002BE6A0, 0x002CE740, 0x002D37A0, 0x002D37B0,
0x002D37C0, 0x002D37D0, 0x002D37E0. The other game's name is recorded in each file's `// tool:` line only.

Open finishing work in these 46 (no [match] rule fires, the checker forced the shape):
- 0x0003DBD0 and 0x00244170 declare `sqrt` by hand, and 0x00244170 writes the length out instead of calling
  an inline `Length()`: `<math.h>` and an inline helper give the same bytes, but each leaves a second function
  in the object file, which `agent.py check` refuses.
- 0x000A6D40 and 0x000CA160 are constructors written as functions that return `this`, because a
  constructor of an address-named class cannot carry the `sub_XXXXXXXX` name the verifier looks for.
- 0x001522C0 declares slot 0 as `vfunc_00(int)` like its matched classmate, not as a virtual destructor.

## Byte-exact, kept out by the checker

`python portal/verify.py <file> --va <va> --bin xb --match <name>` prints `VERIFIED` for all five; they are in
`reports/parked/` because `agent.py check` refuses an object file with more than one function.

| function | bytes | unchecked addresses | what is needed |
|---|---|---:|---|
| 0x00013AA0 vector times scalar | 55/55 | 0 | checker selects by name (the inline constructor is a second function) |
| 0x001527F0 `BlendCamera::vfunc_44` | 24/24 | 0 | same |
| 0x001C2520 `HUDImageDisplay::vfunc_45` | 18/18 | 1 | `reports/names.json`: 0x00193D50 = `HUDElement2::vfunc_45` (the list calls it `HUDSubtitle::vfunc_45`; RTTI disagrees) |
| 0x001CC0E0 `PauseMenuPageMain::vfunc_45` | 18/18 | 1 | `reports/names.json`: 0x001CA7F0 = `PauseMenuPage::vfunc_45` |
| 0x001E9170 delete of a global object | 39/39 | 2 | names for the destructor 0x001E8B80 and `operator delete` 0x00027600; `delete` also emits `??_G` |

Calls from one `<algorithm>` instantiation to another are relocations the verifier leaves unchecked (37 in
all); the targets were compared by hand in the lane, not by a tool.

## MATCH-PENDING

| function | file | rule | why |
|---|---|---|---|
| 0x00299510 `count_bits_32` | `reports/parked/xb_00299510.cpp` | R17 | dummy `__fastcall` parameter fakes a `/GL` register convention |

## RULE-EXCEPTION

| function | rule | reason |
|---|---|---|
| 0x002CCCB0 `adler32` | R32 (layout) | zlib 1.2.1's own source layout is kept |

## Parked

| function | best | wall |
|---|---|---|
| 0x002C6FC0 zlib `updatewindow` | 22/277 bytes per file | `/GL` register convention: retail takes `out` in `eax` |

Both `/GL` functions were reproduced exactly in a throwaway experiment (2026-11-19): the honest source,
compiled with `cl /GL` and linked with `link /LTCG`, gives 277/277 bytes for `updatewindow` and 25/25 for
`count_bits_32` with no dummy parameter. The wall is the verifier, not the source.

## Symcov import (lane `symcov-data`, merged)

Made by `tools/symcov_import.c` from the symcov report of `default.xbe` (3,903 rows, 1,856 in `.text`).
Running it again changes nothing.

| import | result |
|---|---|
| Library reclassification | 164 queued functions moved to `reports/library_functions.json` (XAPILIB, C and C++ runtime, XGRAPHICS stubs, WMA). 33 RAD Bink / Ooura FFT rows and 77 CRT-named rows outside a library block stay queued |
| Missing starts | 585 of 1,039 accepted: 556 into `reports/extra_function_starts.json`, 29 into the library list. 454 rejected, 366 of them because the report's start is the tail of a longer function |
| Names | 564 into `reports/names.json` with `by: "symcov: <build>"`: 158 Microsoft library in `.text`, 383 in the library sections, 23 zlib / libpng / Ooura FFT. 9 more wait for their start to appear in the address-order list |
| Hints | 520 in `reports/symcov_hints.json` (77 unique, 443 link-order); never names |

Xbox queue by a real `queue_builder` run: 11,285 before, 11,677 after (164 out, 556 in).

Open: the 366 tail starts are real function starts the project does not list, with sizes the report cannot
give; the Ooura FFT names (`cftf1st` and others) are the lane's judgement; `pytest` is not installed on
this machine, so the project's test suite was not run (29 tests that need no fixtures passed in a stand-in).

## Hit & Run bridge (lane `shar-bridge`, merged)

Made by `tools/shar_bridge.c`: names from the link map of Hit & Run's 10 July 2003 PS2 prototype, carried to
Hit & Run's retail Xbox program (built two weeks later) and from there to Scarface Xbox. Running it again
changes nothing.

| | result |
|---|---|
| Names in `reports/names.json` | 20 (pure3d 13, core 5, math 2), each with two agreeing signals on the first hop and identical code or slot-plus-arguments on the second |
| Hints in `reports/shar_bridge_hints.json` | 35 one-signal candidates; never names |
| Agreement with names already recorded | chains that pass the naming rule: 14 agree, 0 disagree; of the 45 names from `names_from_shar_map.py` the bridge reaches 19 and agrees on all 19 |
| Disagreements (not written) | 0x00011930, 0x000E6570, 0x001DECC0 |

Measured on the way: 2,734 Hit & Run Xbox functions of 24 bytes or more get a PS2 name (1,495 with two or
more signals). Between the two Xbox programs 533 such functions are identical with addresses masked: 419
library (388 already named) and 114 game or engine. Only 137 Hit & Run classes pair with a Scarface class,
and 15 of those keep the same number of virtual functions.

Open: identical code on the second hop was never tested against a known name (none of its 114 functions had
one); strings and constants on the second hop were wrong once (0x000E6570) and now only make hints.

## Tool gaps found

- `msvc_verify.uses_sse()` retries `/arch:SSE` only for `xmm`; functions that use `cmov` need it too.
- `agent.py check` refuses any object file with more than one function when the queue file
  (`reports/full_remaining_queue.json`) is absent; inline helpers, `<math.h>`, return-by-temporary and
  `delete` all add one. It steers workers away from the real source.
- A non-virtual call to an RTTI-named base virtual (`Base::vfunc_NN`) cannot be checked: the verifier reads
  names from `reports/names.json` only.
- `agent.py check` / `keep` cannot select a template instantiation or a compiler helper (no `--match`) and
  always compiles with `/EHsc`, so `submit_matches.py` will not take the 18 files that carry a `// verify:`
  line as they are.
- The verifier has no whole-program (`/GL` + `/LTCG`) mode.
- `queue_builder` silently drops an extra start that lies inside another start's measured extent.
- The address-order files are only regenerated with the new starts where the queue file exists.
