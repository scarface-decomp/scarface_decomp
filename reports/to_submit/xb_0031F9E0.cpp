// bin: xb
// va: 0x0031F9E0
// what: Start-up code (a static initializer): stores the name key of "GangMember" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F9E0 (0x0031F9E0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B5B6C[];
extern "C" int DAT_00491F24;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_0031F9E0(void)
{
    DAT_00491F24 = sub_00243FA0((int)DAT_003B5B6C, 0);
}
