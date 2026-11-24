// bin: proto
// va: 0x002E4920
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4920 (Proto 0x002E4920, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00389124[];
extern "C" int DAT_0045B958;
extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_002E4920(void)
{
    DAT_0045B958 = sub_002014E0((int)DAT_00389124, 0);
}
