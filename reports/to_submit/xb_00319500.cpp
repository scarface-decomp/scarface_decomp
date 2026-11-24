// bin: xb
// va: 0x00319500
// what: Start-up code (a static initializer): stores the name key of "EHE_SYSTEM_HUD" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319500 (0x00319500, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B9604[];
extern "C" int DAT_0048C1C4;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00319500(void)
{
    DAT_0048C1C4 = sub_00244040((int)DAT_003B9604, 0);
}
