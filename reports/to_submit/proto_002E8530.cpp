// bin: proto
// va: 0x002E8530
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8530 (Proto 0x002E8530, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039DE7C[];
extern "C" int DAT_0045FF7C;
extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_002E8530(void)
{
    DAT_0045FF7C = sub_002014E0((int)DAT_0039DE7C, 0);
}
