// bin: xb
// va: 0x00319120
// what: Start-up code (a static initializer): stores the name key of "CrouchSpeed" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319120 (0x00319120, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B5CF4[];
extern "C" int DAT_0048BEB8;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00319120(void)
{
    DAT_0048BEB8 = sub_00244040((int)DAT_003B5CF4, 0);
}
