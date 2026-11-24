// bin: proto
// va: 0x002E5390
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5390 (Proto 0x002E5390, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038F4CC[];
extern "C" int DAT_0045C274;
extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_002E5390(void)
{
    DAT_0045C274 = sub_002014E0((int)DAT_0038F4CC, 0);
}
