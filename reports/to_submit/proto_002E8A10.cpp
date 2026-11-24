// bin: proto
// va: 0x002E8A10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8A10 (Proto 0x002E8A10, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037EA84[];
extern "C" int DAT_00460248;
extern "C" int __cdecl sub_00200280(int);

void __cdecl sub_002E8A10(void)
{
    DAT_00460248 = sub_00200280((int)DAT_0037EA84);
}
