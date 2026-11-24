// bin: xb
// va: 0x00314960
// what: Start-up code (a static initializer): stores the name key of "WeaponPU" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314960 (0x00314960, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A427C[];
extern "C" int DAT_0048157C;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00314960(void)
{
    DAT_0048157C = sub_00243FA0((int)DAT_003A427C, 0);
}
