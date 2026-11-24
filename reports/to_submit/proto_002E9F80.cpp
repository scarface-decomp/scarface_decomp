// bin: proto
// va: 0x002E9F80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9F80 (Proto 0x002E9F80, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A3BB4[];
extern "C" int DAT_0046147C;
extern "C" int __cdecl sub_00200280(int);

void __cdecl sub_002E9F80(void)
{
    DAT_0046147C = sub_00200280((int)DAT_003A3BB4);
}
