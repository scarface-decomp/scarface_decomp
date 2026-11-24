// bin: xb
// va: 0x0031C3B0
// what: Start-up code (a static initializer): stores the name key of "On_Spawner_Create" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031C3B0 (0x0031C3B0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C866C[];
extern "C" int DAT_0048F6DC;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031C3B0(void)
{
    DAT_0048F6DC = sub_00244040((int)DAT_003C866C, 0);
}
