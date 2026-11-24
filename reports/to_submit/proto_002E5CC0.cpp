// bin: proto
// va: 0x002E5CC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5CC0 (Proto 0x002E5CC0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003919E8[];
extern "C" int DAT_0045CB54;
extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_002E5CC0(void)
{
    DAT_0045CB54 = sub_002014E0((int)DAT_003919E8, 0);
}
