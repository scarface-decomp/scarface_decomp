// bin: proto
// va: 0x002EAF40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EAF40 (Proto 0x002EAF40, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A9078[];
extern "C" char DAT_003A9088[];
extern "C" int DAT_004617CC;
extern "C" int DAT_004617D0;
extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_002EAF40(void)
{
    DAT_004617CC = sub_002014E0((int)DAT_003A9088, 0);
    DAT_004617D0 = sub_002014E0((int)DAT_003A9078, 0);
}
