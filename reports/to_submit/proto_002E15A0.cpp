// bin: proto
// va: 0x002E15A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E15A0 (Proto 0x002E15A0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_003F8460;
extern "C" int DAT_0044A53C;
extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_002E15A0(void)
{
    DAT_0044A53C = sub_002014E0(DAT_003F8460, 0);
}
