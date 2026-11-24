// bin: proto
// va: 0x002E8A50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8A50 (Proto 0x002E8A50, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A000C[];
extern "C" int DAT_00460250;
extern "C" int __cdecl sub_00200280(int);

void __cdecl sub_002E8A50(void)
{
    DAT_00460250 = sub_00200280((int)DAT_003A000C);
}
