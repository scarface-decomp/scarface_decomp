// bin: xb
// va: 0x00319220
// what: Start-up code (a static initializer): stores the name key of "MainPlayerWeaponGunUpSpeed" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319220 (0x00319220, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B5D84[];
extern "C" int DAT_0048BEF8;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00319220(void)
{
    DAT_0048BEF8 = sub_00244040((int)DAT_003B5D84, 0);
}
