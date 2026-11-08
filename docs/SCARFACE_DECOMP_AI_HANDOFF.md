# Scarface: The World Is Yours — brief for AI assistants

You are helping write C++ that compiles, with the original compiler, to exactly the same machine code
as a function in the 2006 game. The portal at `http://localhost:8085` serves this file at
`/download/ai-handoff`. The full rules are in `docs/METHODOLOGY.md`.

## What you are given for each function

* the target: binary (`pc` = `Scarface.exe` 1.00.2, `xb` = Xbox `default.xbe`), address, exact size
  in bytes;
* the original bytes and their disassembly;
* a symbol name, such as `content::Stats::vfunc_03` (class and vtable slot from RTTI) or
  `sub_001CDC80` (no name known).

## What to return

One ` ```cpp ` block containing a complete translation unit that compiles on its own:

* declare every type, global and callee the function needs (stub declarations are fine);
* define **the target function out of line**, with the given name, so it can be found in the `.obj`
  (`Stats::vfunc_03` must be a member `vfunc_03` of class `Stats` in namespace `content`);
* keep other functions out of line only if they are needed; inline helpers are fine.

## How it is checked

Compiled with `cl.exe` 13.10.3052 (Visual C++ Toolkit 2003, MSVC 7.1):
`/nologo /c /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4` (PC functions are also tried with `/G7`).
It counts as VERIFIED only if:

1. the compiled function has **exactly** the original's length and bytes, apart from the 4-byte fields
   the linker fills in;
2. those fields check out: internal jumps land at the same offsets, data you define has the same bytes
   as what the original points at, and a symbol named for an address (`DAT_00439DA4`,
   `sub_00412340`) is that address;
3. **no 2006 address appears as a number**. Write `extern "C" char DAT_00439DA4;` and use
   `&DAT_00439DA4`, not `0x00439DA4`;
4. it is **plain C++**: no `__asm`, `_emit`, `__declspec(naked)`, section/segment pragmas,
   `#pragma comment`, `__pragma`, `_Pragma`, or byte arrays standing in for code.

A partial match is reported as `matched / total` bytes with a per-byte diff; use it to iterate.

## Code generation facts (measured on this compiler)

* After a one-argument `__cdecl` call: `pop ecx` if the function returns nothing, `add esp, 4` if it
  returns the call's result. `f(x);` and `return f(x);` are different functions.
* Don't add `#pragma optimize("s")`: it makes the compiler push memory operands directly
  (`push dword ptr [ecx+8]`), which the game does not do.
* `/G7` (PC only) shows up as `add [mem], 1` instead of `inc`, `cmp [mem], 0` instead of
  load + `test`, and `lea esp,[esp+0]` padding before loops.
* A call with no `mov ecx, ...` before it is a free function, not a member.
* `lea esi,[ecx+N]` followed by work through `esi` is usually an inline method of the member object at
  `+N`.
* A `bool` result of `!f()` is `neg al / sbb eax,eax / inc eax`.
* `call [eax+N]` is vtable slot `N/4`; declare enough virtual functions before it for the slot to line
  up.
* A vtable's destructor slot is the scalar deleting destructor (`if (flags & 1) delete`).
* Field types decide instruction widths. Declare the struct with the right types and offsets instead of
  casting `this`.
* `test al,al / jns` with the "return 0" block first comes from `if (x & 0x80) return 0; return y;`.

## Do not

* invent results or claim a match: only the compiler's verdict counts;
* change the target's name or signature to make it "fit" another function;
* rely on PC addresses outside `0x006DDC00`–`0x0072EADC` (not readable in the PC file). Use the Xbox
  copy of the function instead.
