// bin: xb
// va: 0x0031F960
// what: Start-up code (a static initializer): stores the name key of "CivilianInterior" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F960 (0x0031F960, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B5B30[];
extern "C" int DAT_00491F14;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_0031F960(void)
{
    DAT_00491F14 = sub_00243FA0((int)DAT_003B5B30, 0);
}
