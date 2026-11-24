// bin: proto
// va: 0x002EA4E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EA4E0 (Proto 0x002EA4E0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A525C[];
extern "C" int DAT_004616B8;
extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_002EA4E0(void)
{
    DAT_004616B8 = sub_002014E0((int)DAT_003A525C, 0);
}
