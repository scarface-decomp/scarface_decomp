// bin: proto
// va: 0x002E5730
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5730 (Proto 0x002E5730, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003914F0[];
extern "C" int DAT_0045C4D4;
extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_002E5730(void)
{
    DAT_0045C4D4 = sub_002014E0((int)DAT_003914F0, 0);
}
