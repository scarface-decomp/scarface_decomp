// bin: xb
// va: 0x00318E40
// what: Start-up code (a static initializer): stores the name key of "inv_isWeapon" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318E40 (0x00318E40, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B45E0[];
extern "C" int DAT_0048BC78;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00318E40(void)
{
    DAT_0048BC78 = sub_00244040((int)DAT_003B45E0, 0);
}
