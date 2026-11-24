// bin: proto
// va: 0x002E3B10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3B10 (Proto 0x002E3B10, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00385328[];
extern "C" int DAT_00459CB4;
extern "C" int __cdecl sub_00200280(int);

void __cdecl sub_002E3B10(void)
{
    DAT_00459CB4 = sub_00200280((int)DAT_00385328);
}
