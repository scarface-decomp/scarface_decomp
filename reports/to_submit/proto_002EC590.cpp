// bin: proto
// va: 0x002EC590
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC590 (Proto 0x002EC590, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00398188[];
extern "C" int DAT_00462E38;
extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_002EC590(void)
{
    DAT_00462E38 = sub_002014E0((int)DAT_00398188, 0);
}
