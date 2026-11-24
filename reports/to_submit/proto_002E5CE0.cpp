// bin: proto
// va: 0x002E5CE0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5CE0 (Proto 0x002E5CE0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003919F4[];
extern "C" int DAT_0045CB5C;
extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_002E5CE0(void)
{
    DAT_0045CB5C = sub_002014E0((int)DAT_003919F4, 0);
}
