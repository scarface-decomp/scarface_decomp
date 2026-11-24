// bin: xb
// va: 0x0031C2D0
// what: Start-up code (a static initializer): stores the name key of "CubeVan" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031C2D0 (0x0031C2D0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C768C[];
extern "C" int DAT_0048F5BC;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_0031C2D0(void)
{
    DAT_0048F5BC = sub_00243FA0((int)DAT_003C768C, 0);
}
