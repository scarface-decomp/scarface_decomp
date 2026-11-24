// bin: xb
// va: 0x0031F800
// what: Start-up code (a static initializer): stores the name key of "GameGlobalMortarSet" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F800 (0x0031F800, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D1AF0[];
extern "C" int DAT_00491EA4;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031F800(void)
{
    DAT_00491EA4 = sub_00244040((int)DAT_003D1AF0, 0);
}
