// bin: proto
// va: 0x002E3C40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3C40 (Proto 0x002E3C40, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_003FFA90;
extern "C" int DAT_00459D08;
extern "C" int __cdecl sub_00200280(int);

void __cdecl sub_002E3C40(void)
{
    DAT_00459D08 = sub_00200280(DAT_003FFA90);
}
