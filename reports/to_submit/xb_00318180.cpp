// bin: xb
// va: 0x00318180
// what: Start-up code (a static initializer): stores the name key of "Entry1" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318180 (0x00318180, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B576C[];
extern "C" int DAT_0048AE00;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00318180(void)
{
    DAT_0048AE00 = sub_00243FA0((int)DAT_003B576C, 0);
}
