// bin: proto
// va: 0x002E1600
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1600 (Proto 0x002E1600, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00380114[];
extern "C" int DAT_0044A54C;
extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_002E1600(void)
{
    DAT_0044A54C = sub_002014E0((int)DAT_00380114, 0);
}
