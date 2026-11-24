// bin: xb
// va: 0x0031FA40
// what: Start-up code (a static initializer): stores the name key of "CubeVan" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031FA40 (0x0031FA40, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C768C[];
extern "C" int DAT_00491F30;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_0031FA40(void)
{
    DAT_00491F30 = sub_00243FA0((int)DAT_003C768C, 0);
}
