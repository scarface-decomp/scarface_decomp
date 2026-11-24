// bin: proto
// va: 0x002E8510
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8510 (Proto 0x002E8510, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039DE70[];
extern "C" int DAT_0045FF78;
extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_002E8510(void)
{
    DAT_0045FF78 = sub_002014E0((int)DAT_0039DE70, 0);
}
