// bin: xb
// va: 0x0031C770
// what: Start-up code (a static initializer): stores the name key of "PlayerObjCol" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031C770 (0x0031C770, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039DD08[];
extern "C" int DAT_0048F784;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031C770(void)
{
    DAT_0048F784 = sub_00244040((int)DAT_0039DD08, 0);
}
