// bin: xb
// va: 0x00319100
// what: Start-up code (a static initializer): stores the name key of "CrouchRunSpeed" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319100 (0x00319100, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B5CE4[];
extern "C" int DAT_0048BEB0;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00319100(void)
{
    DAT_0048BEB0 = sub_00244040((int)DAT_003B5CE4, 0);
}
