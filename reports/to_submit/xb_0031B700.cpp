// bin: xb
// va: 0x0031B700
// what: Start-up code (a static initializer): stores the name key of "M16_upgrade2" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031B700 (0x0031B700, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C5D78[];
extern "C" int DAT_0048ECCC;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_0031B700(void)
{
    DAT_0048ECCC = sub_00243FA0((int)DAT_003C5D78, 0);
}
