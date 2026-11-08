# Verification methodology

This is the exact procedure behind every `VERIFIED` count in this project. The portal
(`portal/decomp_portal_server.py`), the command-line checker (`portal/verify.py`) and the bulk re-verifier
(`portal/scripts/reverify_all.py`) all call the same code in `portal/tools/msvc_verify.py`, so they cannot disagree.

## 1. Target binaries

| File | Build | Image base | Code the project works on |
| :--- | :--- | :--- | :--- |
| `Scarface.exe` | Retail PC 1.00.2 | `0x00400000` | `0x006DDC00`–`0x0072EADC` only. The rest of the PC `.text` section is not stored as plain x86 code in the file, so it cannot be compared; those functions are worked from the Xbox build. |
| `default.xbe` | Retail Xbox | `0x00010000` | `.text`, `0x00011000`–`0x0032947C`. The other code sections (`D3D`, `D3DX`, `XGRPH`, `DSOUND`, `WMADEC`, `BINK*`, `XPP`) are Microsoft XDK and RAD Bink library code, not game code, and are not in the queue. |
| `game.xbe` | April 20, 2006 Xbox prototype | `0x00010000` | Optional, unreleased code: queued, verified and saved like the others (`--bin proto`, `reconstructed_src/proto/`), counted on its own row. |

The registry records the SHA-256 of each binary it was verified against
(`reports/verified_registry.json` → `binaries`).

XBE sections are classified by name, not by flags: the XBE header marks almost every section
executable, `.rdata` and `.data` included.

## 2. Compiler

* `cl.exe` **13.10.3052** (Microsoft Visual C++ Toolkit 2003, MSVC 7.1). The game's PE header says
  linker 7.10 and it imports `MSVCR71.dll`. Before the 2026-11-08 reset, all 1,036 functions verified
  then matched with 13.10.3052.
* **Open question for the Xbox build.** `default.xbe` lists XDK 5849 libraries. The
  [Halo 2 decompilation](https://github.com/kirklandsig/halo2-decompiled), built with the same XDK,
  reports that its compiler is `cl` 13.10.3077 and that the game used `/LTCG` with `/O1` or `/O2` per
  file. The Xbox functions verified here are all small, where 3052 and 3077 can produce the same code.
  If medium or large Xbox functions refuse to match, test them with the XDK compiler (if you have it
  lawfully; it is not redistributable), with `/O1`, and look for signs of link-time code generation,
  such as functions that take arguments in registers other than `ecx`.
* Default flags for every target: `/nologo /c /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4`.
* PC only: when `/G6` does not match, the same code is tried with `/G7`. Before the reset, 14 of the 155 verified PC
  functions needed `/G7`. Xbox code is checked with `/G6` only (see the notes in section 5). The
  registry stores the flags that matched.
* **decomp.me has the same compiler.** Its `msvc7.1` compiler (platform *Windows (9x/NT)*) gave 100%
  on two functions verified here before the reset, one PC (`CementLibrary::vfunc_05`, 39 B, `/G7`) and one Xbox
  (`sub_0001EF60`, 7 B), checked on 2026-11-08. It compiles as C unless `/TP` is passed, so the
  portal's decomp.me button adds `/TP`. The target it sends is built by `portal/tools/decompme.py`: the game's
  bytes plus COFF relocations named `_sub_XXXXXXXX` / `_DAT_XXXXXXXX`, the same names MSVC gives
  `extern "C"` declarations. Those relocations were checked against MSVC's own for 243 verified
  functions (all offsets and types agree). A decomp.me score is a helper; the portal decides.
* `portal/scripts/setup_msvc71.py` installs `bin/`, `include/` and `lib/` from your own `VCToolkitSetup.exe`.
  On Linux and macOS the compiler runs under Wine (32-bit prefix). `SCARFACE_MSVC_BIN` overrides the
  location.

## 3. Function boundaries

Sizes are measured, never estimated. `portal/tools/sf_binaries.py` walks the original function with Capstone
(recursive descent: every branch, conditional jump and switch jump table, including MSVC's byte index
tables) and stops at returns, tail jumps and the next known function start. Known starts are call
targets plus vtable entries found through the MSVC RTTI complete-object locators.

The queue (`portal/tools/queue_builder.py`, written to `reports/full_remaining_queue.json`) is rebuilt from the
binaries, so a task's size is the real size of the original function. Virtual methods are named after
their class and slot (`content::Stats::vfunc_03`); other functions are `sub_<address>`.

## 4. The rule for VERIFIED

A submission counts only if all of the following hold:

1. **It compiles** with the compiler and flags above.
2. **The right function is compared.** The target is chosen by its decorated name
   (`vfunc_03@Stats@content@`, `??_GStats@@` for a destructor slot, `?$ConcreteClassRep@VFEObject@@@`
   for a template). If the name is ambiguous the check stops; it never falls back to another function.
3. **Same length.** The compiled function is exactly as long as the original.
4. **Same bytes.** Every byte matches, except the 4-byte fields the linker fills in (COFF relocations).
5. **Relocations are checked wherever possible:**
   * a reference into the same function must point at the same offset as in the original;
   * data defined in the submission (constants, vtables, string literals) must have the same bytes as
     the data the original points at; pointer slots inside that data are skipped because the linker
     fills them;
   * absolute symbols such as `__except_list` (the `fs:[0]` SEH chain) must have the same value;
   * a symbol named after an address (`DAT_00439DA4`, `sub_00412340`, `g_007F5A70`, decorated or
     `extern "C"`) must refer to exactly that address;
   * one external symbol must mean one address throughout the function.

   References that cannot be checked (an ordinary external such as `operator delete`) are counted and
   shown as "N external relocation(s) unchecked".
6. **No hard-coded 2006 addresses.** A number that is an address inside the original image, with no
   relocation, blocks VERIFIED even when the bytes match. Name it instead:

   ```cpp
   // blocked: return 0x00439DA4;
   extern "C" char DAT_00439DA4;
   void* __cdecl sub_001CDC80(void) { return &DAT_00439DA4; }
   ```
7. **Plain C++** (`portal/tools/cpp_policy.py`, checked on the source and on the `/E` preprocessed output):
   no `__asm`/`_asm`, `_emit`, `__declspec(naked)`, `__declspec(allocate)`/`code_seg`, section or segment
   pragmas, `#pragma comment`, `#import`/`#using`, `__pragma`/`_Pragma`, or includes outside the project.
   `#pragma optimize` is allowed, but see the notes below before using it.

`reports/reverify_report.md` lists every claimed function with its status and the reason:

| Status | Meaning |
| :--- | :--- |
| `VERIFIED` | all rules above hold |
| `MATCH_HARDCODED_ADDR` | bytes match, but a 2006 address is written as a number |
| `MISMATCH` | compiled, but length, bytes or a relocation differ |
| `POLICY` | uses a construct that is not allowed |
| `COMPILE_ERROR` | does not compile |
| `UNMAPPED` | the target function could not be picked out of the object file |
| `NO_CODE` | only a comment, no C++ |
| `NO_TARGET` | the address cannot be compared (PC address outside the readable range, or no binary) |

## 5. Code generation notes (measured with 13.10.3052)

These were each confirmed by compiling variants and comparing against the game.

* **`pop ecx` vs `add esp, 4`.** After a call that pushed one argument, `/O2` cleans up with `pop ecx`
  (`59`) when the function returns nothing, and with `add esp, 4` (`83 C4 04`) when it returns the
  call's result. `return f(x);` and `f(x);` are therefore different functions.
  (`core::DriveThread::vfunc_00` matches only as `void`.)
* **Do not reach for `#pragma optimize("s")`.** It does not just change `add esp` into `pop ecx`; it
  makes the compiler push memory operands directly (`FF 71 08 push dword ptr [ecx+8]` instead of
  `8B 41 08 50`), which the game's PC code does not do.
* **`/G7` markers** (PC): `add dword ptr [esi+4], 1` instead of `inc`; `cmp dword ptr [esi+20h], 0`
  instead of a load and `test`; loop heads padded with `8D A4 24 00 00 00 00` (`lea esp,[esp]`) where
  `/G6` uses `8D 9B 00 00 00 00`. On Xbox, `/G7` turns the final `inc eax` of a bool into `add eax, 1`,
  which the Xbox build does not have.
* **Free function or member?** A call with no `mov ecx, ...` before it is a free (`__cdecl`) function.
* **Inlined helpers on a member object.** `lea esi,[ecx+0Ch]` followed by calls and field accesses
  through `esi` is a small inline method of the member object at `+0Ch` (for example a lock's
  `Lock(); ++refs; Unlock();`), not three statements on `this`.
* **Branch layout.** `test al,al / jns` with the "return 0" block first comes from
  `if (flags & 0x80) return 0; return name;`.
* **`!b` as a return value.** A `bool` result of `!f()` compiles to `neg al / sbb eax,eax / inc eax`.
* **Vtable slots must be exact.** `call dword ptr [eax+13Ch]` is slot 79. Declare enough virtual
  functions before it (placeholders are fine) for the slot to line up.
* **Destructor slots.** A vtable's destructor entry is the *scalar deleting destructor* (`??_G`):
  `if (flags & 1) operator delete(this)` around the inlined destructor body.
* **Out-of-line definitions.** A method defined inside the class body is inline and usually not
  emitted at all. Define the target out of line.
* **Prefer real types to casts.** Field types decide instruction widths (`mov byte ptr` vs
  `mov dword ptr`); write the struct, not `*(int*)((char*)this + 0x14)`.

## 6. Re-verification

`portal/scripts/reverify_all.py` compiles every claim in `reconstructed_src/` (hand-written files and the
`imported/` sweep files) plus every portal-verified entry in the registry, applies the rule above, and
rewrites `reports/verified_registry.json`, `reports/reverify_report.md` and the generated files
(`Original_Binary_Order_*.cpp`, `pc/`, `xbox/`). Run it after changing a header, the verifier or the
binaries. A function that stops matching drops out of the count.
