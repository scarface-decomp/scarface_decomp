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
* **Toolkit 1.01 (`cl.exe` 13.10.3077) is accepted too.** Microsoft released it in July 2004 to match the
  build number of Visual Studio .NET 2003 and says it has no compilation-related behaviour changes from 1.0.
  On 450 game functions (small and large), both builds gave the same result for every one. Each registry
  entry records the build that verified it (`compiler`), so a difference can be traced if one ever appears.
  Later compilers (Visual Studio .NET 2003 SP1's 13.10.6030, Visual C++ 2005 and newer) are refused by
  `setup_msvc71.py`.
* **Open question for the Xbox build.** `default.xbe` lists XDK 5849 libraries. The
  [Halo 2 decompilation](https://github.com/kirklandsig/halo2-decompiled), built with the same XDK,
  reports that its compiler is `cl` 13.10.3077 and that the game used `/LTCG` with `/O1` or `/O2` per
  file. The Xbox functions verified here are all small, where 3052 and 3077 can produce the same code.
  If medium or large Xbox functions refuse to match, test them with the XDK compiler (if you have it
  lawfully; it is not redistributable), with `/O1`, and look for signs of link-time code generation,
  such as functions that take arguments in registers other than `ecx`.
* Default flags: `/nologo /c /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4` on PC; the same without `/EHsc` on the
  two Xbox programs (see the `/EHsc` note below).
* PC only: when `/G6` does not match, the same code is tried with `/G7`. Before the reset, 14 of the 155 verified PC
  functions needed `/G7`. Xbox code is checked with `/G6` only (see the notes in section 5). The
  registry stores the flags that matched.
* Xbox only (retail and prototype): a function whose own instructions use the SSE registers
  (`movss xmm0, ...`), a conditional move (`cmov`) or an `fcomi`-style compare is also tried with
  `/arch:SSE` added. The compiler writes none of these without that flag (it targets the Pentium III
  then, and compares with `fcom` / `fnstsw` otherwise), and the console's Pentium III has them. In the
  Xbox program, conditional moves and `fcomi` occur only in the game's own code (below 0x2335F6);
  `0x00012450`, `0x000C4380` and `0x0010C1F0` use `cmov` or `fcomi` without any `xmm` and match only with the flag. Functions that use
  none of them are never tried with it. `msvc_verify.flag_options` holds this rule, and the
  portal, `portal/verify.py`, `portal/agent.py` and the re-verifier all use it.
  By library (SPEC-013 §5, `portal/scripts/flag_study.py`): the game's own code is built with
  `/arch:SSE` (305 verified functions need it, one needs it off), the engine libraries without it (every
  one of the 20 verified library functions whose bytes depend on the switch matches only without it).
* No `/GS`: neither Xbox program has the stack-cookie check or loads a cookie in any function, so the
  switch was off (SPEC-013 §5). `/Ob1` changed no verified Xbox function.
* Public C libraries inside the engine (zlib, libpng) are matched from their published source, kept
  unchanged under `reconstructed_src/include/`, compiled as C: a submission may add `/TC` to the
  function's flags. zlib 1.2.1's whole decompression side matches this way with
  `/TC /O2 /Ot /Oy /G6 /Gd /Zp4`, and so do 98 functions of libpng 1.2.8 in its default configuration
  (no configuration macro set). A proposal is the include of the published file plus a `// verify:` line
  whose `--match` names the function. Three things the checker needs for such code: the library's
  functions and tables named in `reports/names.json` (a call into another file is checked through the
  name); the C library's underscore names (`_iob`, `_setjmp3`) found for the compiler's `__iob`,
  `__setjmp3`; and the flag masks a library writes as numbers listed in
  `reports/numbers_not_addresses.json` where they fall in the program's address range.
* A function that ends in a call that never comes back has no `ret`, and the padding byte after it was
  measured as its last byte. The checker leaves that one `int3` out when the compiled function is one
  byte shorter and does not end in a return (libpng's `png_error`, `png_chunk_error`).
* Register arguments do not by themselves show link-time code generation: with `/O2` this compiler
  already passes arguments in registers to a `static` function whose address is never taken. zlib's
  `crc32` (0x002C6E60) and its static helper (0x002C6B80, arguments in EAX, ECX and EDX) match from an
  ordinary single-file compile.
* Link-time code generation: there is no evidence of it. SPEC-014 §5.5 once read register arguments as
  proof of it; the examiner withdrew that on 25 November 2026, after the save drive's text converter
  (0x002BFA00, arguments in ECX and EAX) and its caller matched from one ordinary file. A function that
  takes an argument in a register is one only its own file can see (`static`, or a `static` template):
  write it in the same file as its callers and the compiler picks the registers itself.
  `reports/exam_regarg_xb.json` lists 55 such leads (seven of them false).
* No `/EHsc` on Xbox: the game and engine code has no C++ exception frame (no function sets the
  exception list at `fs:[0]`; the 49 exception stubs belong to a Microsoft library), and all 22,626
  verified Xbox functions (11,678 retail, 10,948 prototype) still match with the switch removed. New
  Xbox tasks are queued without it; a function whose bytes do show a frame keeps it. Tasks queued
  earlier are also tried without it.
* **decomp.me has the same compiler.** Its `msvc7.1` compiler (platform *Windows (9x/NT)*) gave 100%
  on two functions verified here before the reset, one PC (`CementLibrary::vfunc_05`, 39 B, `/G7`) and one Xbox
  (`sub_0001EF60`, 7 B), checked on 2026-11-08. It compiles as C unless `/TP` is passed, so the
  portal's decomp.me button adds `/TP`. The target it sends is built by `portal/tools/decompme.py`: the game's
  bytes plus COFF relocations named `_sub_XXXXXXXX` / `_DAT_XXXXXXXX`, the same names MSVC gives
  `extern "C"` declarations. Those relocations were checked against MSVC's own for 243 verified
  functions (all offsets and types agree). A decomp.me score is a helper; the portal decides.
* `portal/scripts/setup_msvc71.py` installs `bin/`, `include/` and `lib/` from your own `VCToolkitSetup.exe`.
  On Linux the compiler runs under wibo (`portal/scripts/setup_wibo.py`; all 16,096
  recorded matches came out the same under it), on macOS under Wine (32-bit prefix). `SCARFACE_MSVC_BIN` overrides the
  location, `SCARFACE_WIBO` names a wibo binary, `SCARFACE_USE_WINE=1` forces Wine.

## 3. Function boundaries

Sizes are measured, never estimated. `portal/tools/sf_binaries.py` walks the original function with Capstone
(recursive descent: every branch, conditional jump and switch jump table, including MSVC's byte index
tables) and stops at returns, tail jumps and the next known function start. Known starts are call
targets plus vtable entries found through the MSVC RTTI complete-object locators.

**When two functions overlap.** A walk can follow a jump out of its function and measure it over the next
one (an 8-byte thunk came out as 9,000 bytes), and a "call target" can be data that happened to read as a
call. `sf_binaries.settle_overlaps` decides the cases it can prove:

* a function measured past a start that is certainly a function (a vtable entry, a start proven by an
  exact match, or a call target standing directly after a return or padding) is measured again and has to
  end before that start;
* a start that only a call vouches for, off the 16-byte boundary functions are placed on (over 99% of
  matched functions sit on one), that falls inside an instruction of the function around it, is dropped;
* a `ret N` where N is not a multiple of 4 marks bytes that are not a function.

Matched functions are never resized or dropped. On the three builds this re-measured 100 functions and
removed 63 false starts; 135 overlaps remain that neither rule can decide.

**Starts no call reaches.** `portal/tools/hidden_starts.py` reads the ones the program's own tables give
(static initializers, atexit stubs, adjustors), the ones reached only by another function's closing jump,
and the ones whose address is only handed on (`push offset f`, `mov [..], offset f`: a thread's entry
function, a callback). The last kind added 128 starts to the retail Xbox build and 583 to the prototype.

The queue (`portal/tools/queue_builder.py`, written to `reports/full_remaining_queue.json`) is rebuilt from the
binaries, so a task's size is the real size of the original function. Virtual methods are named after
their class and slot (`content::Stats::vfunc_03`); other functions are `sub_<address>`.

## 4. The rule for VERIFIED

A submission counts only if all of the following hold:

1. **It compiles** with the compiler and flags above.
2. **The right function is compared.** The target is chosen by its decorated name
   (`vfunc_03@Stats@content@`, `??_GStats@@` for a destructor slot, `?$ConcreteClassRep@VFEObject@@@`
   for a template). If the name is ambiguous the check stops; it never falls back to another function.
   One exception, because the name cannot work: an adjustor thunk (`sub ecx, N; jmp method`) is emitted
   by the compiler under the name of the method it jumps to (`?method@Class@@W3AEXXZ`), never under its
   own vtable slot. When no emitted function carries the target's name and exactly one is such a thunk,
   that thunk is compared.
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
   * a C++ name that `reports/names.json` ties to an address may be used instead of the address name:
     the name is read back from the decorated symbol (`?Reload@Weapon@@QAEXXZ` is `Weapon::Reload`) and
     the address is checked the same way. Constructors, operators and templates are not read back and
     keep address names;
   * a call to a function the same file compiles into a section of its own (a template instantiation, or a
     member the compiler writes itself, such as `operator=`) is checked by its code: the original must
     hold the same bytes at the called address, linker-filled addresses aside. The linker may have
     folded several identical functions into that one;
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
* **A function that starts `push ebp; mov ebp, esp`** was built with frame pointers kept. Put
  `#pragma optimize("y", off)` above it. When such a function does nothing but jump to another
  (`push ebp; mov ebp, esp; pop ebp; jmp X`), it hands its own arguments on: the frame is there
  because the source names a parameter (`void f(int a) { g(a); }`).
* **SSE setters and getters** (`movss xmm0, [esp+4]; movss [ecx+N], xmm0`) are plain `float` code
  under `/arch:SSE` (section 2).
* **x87 next to SSE in the game's code.** Under `/arch:SSE` the console still has no doubles in SSE,
  so `sqrt`, `sin`, `cos` and `atan2` (which take doubles) stay on the x87: the game's code has
  `fsqrt` 258 times and `sqrtss` never. Write `(float)sqrt(x*x + y*y + z*z)` with the double
  `sqrt`, not `sqrtf`, and keep `/arch:SSE`. A called function's `float` result arrives in `ST0`
  and reaches an `xmm` register through the stack (`fstp [esp]; movss xmm0, [esp]`); mixed x87 and
  SSE in one function is normal.
* **`push ebp; mov ebp, esp; and esp, -8`** in the game's Xbox code is a local that needs 8-byte
  alignment (a `double`, an `__int64`), not a flag change.
* **Engine libraries on the Xbox** (pure3d, core, audio, physics, from 0x239CA2) were built without
  `/arch:SSE`: x87 only, `(int)f` through `_ftol`, compares through `fnstsw`. Their plain
  `push ebp; mov ebp, esp` frames match with the usual flags, so a frame there is not a sign of `/Oy-`.
* **One bit of a byte** (`mov al, [ecx+N]; shr al, 6; and al, 1; ret`) is a one-bit bitfield member
  returned as `bool`; `(m >> 6) & 1` on a whole byte compiles differently.
* **`neg eax; sbb eax, eax; neg eax`** is `x != 0` written out; ending in `inc eax` it is `x == 0`.
  `xor eax, eax; test r, r; setne al` is the same comparison in a function that returns `int`.
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
* **Adjustor thunks have no source.** `83 E9 04 E9 rel32` (`sub ecx, 4; jmp`) appears when a class has
  two bases that both declare a virtual function and the class overrides it; the second base's vtable
  points at the thunk. A body that subtracts from `this` compiles to `add ecx, -4` (`83 C1 FC`) and can
  never match. Declare the two bases, the override and a constructor (so the vtables are emitted) and
  the compiler writes the thunk itself.
* **Out-of-line definitions.** A method defined inside the class body is inline and usually not
  emitted at all. Define the target out of line.
* **Prefer real types to casts.** Field types decide instruction widths (`mov byte ptr` vs
  `mov dword ptr`); write the struct, not `*(int*)((char*)this + 0x14)`.
* **A loop whose test stays at the top** (`test; je out; body; jmp top`) where `/O2` would normally turn
  it round (test at the bottom): the condition is read through an inline helper that hands it back through
  a pointer (`inline void IsRunning(const Thread* t, bool* out)`), inside `for (;;) { ...; if (!running)
  break; ... }`. `while (t->m_Running)`, `volatile`, `goto` and an inline that returns the value all
  compile to the turned-round loop. (0x283AF0)
* **A member of a member, or a pointer to it?** `thread->m_FirstFiber.m_Owner = x` addresses the field
  from the outer object (`[esi+10h]`) and lets the compiler see which stores cannot overlap; through
  `Fiber* first = &thread->m_FirstFiber` every access goes through the pointer (`[edi+8]`) and a test of
  a field it has just zeroed stays in. The same holds for `m_Hold[i].m_Count` against a
  `HoldRecord* hold = &m_Hold[i]`: only the first gives `lea ecx,[eax+9]; shl ecx,4`. (0x283C90,
  0x283F50, 0x2C1620)
* **The same value in two registers** (`mov eax,[owner]; mov edx,eax`) in a function expanded with a
  fixed argument: the expanded function passes that value on to an inline helper of its own
  (`RemoveFiber(fiber->m_Owner, fiber)`). Written with a local instead, the standalone function is the
  same bytes and the expanded copy is not. (0x283B10 inside 0x283D20)
* **A constructor's base-class stores.** Two plain stores to one member with nothing between them lose
  the first one. Where the original keeps both (a base class's table, then the class's own), write each
  base's constructor as an inline helper on a small struct of its own and call it with a cast
  (`ConstructSafeRefCount((SafeRefCountPart*)&m_Table0C)`). (0x2C1B00)

* **A function defined earlier in the same file is known to the compiler.** If it writes no memory, a
  call to it does not make the compiler reload what it read through pointers before the call; declared
  only, the same call does, and one reload can change which register every later value gets. When a
  function is close but its registers are swapped, define the small functions it calls in the same file.
  (0x2C09C0 with 0x2BF730: 447 to 1,070 of 1,279 bytes)
* **Stores are not always in source order.** A store of an argument that was just loaded into a scratch
  register can come out ahead of earlier stores of constants. Write a constructor's members in their
  declared order before trying anything else. (0x2AB470)

The idioms of this game's own source (how its authors wrote flag getters, constructors, request
posting and failure exits) are kept as a numbered list in [cleanroom/IDIOMS.md](cleanroom/IDIOMS.md).

## 6. Re-verification

`portal/scripts/reverify_all.py` compiles every claim in `reconstructed_src/` (hand-written files and the
`imported/` sweep files) plus every portal-verified entry in the registry, applies the rule above, and
rewrites `reports/verified_registry.json`, `reports/reverify_report.md` and the generated files
(`Original_Binary_Order_*.cpp`, `pc/`, `xbox/`). Run it after changing a header, the verifier or the
binaries. A function that stops matching drops out of the count.

## 7. What this does not show

* **Matched is not readable.** Most matched code was written by language models or by the project's
  starter generator and accepted because it passed the rule in section 4. Nearly all of it still uses
  address names and offset names. `portal/tools/readability.py` counts what is left to name;
  `reports/progress.json` reports "readable" separately from "verified".
* **Nothing is linked or run.** Each function is proven against the original bytes on its own. No
  matched code is linked into a program, and no test calls a matched function and checks its result.
* **Unchecked externals exist.** A reference to an ordinary external (an import, `operator delete`) is
  counted and reported, not proven.
* **Function boundaries are not all settled** (section 3).
* **The reference is the original program.** A matching decompilation reads the binary, so it is not
  a clean-room reimplementation; see [CLEAN_ROOM.md](CLEAN_ROOM.md) for what that term covers here.
