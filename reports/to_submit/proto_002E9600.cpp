// bin: proto
// va: 0x002E9600
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9600 (Proto 0x002E9600, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A2610[];
extern "C" int DAT_00460B88;
extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_002E9600(void)
{
    DAT_00460B88 = sub_002014E0((int)DAT_003A2610, 0);
}
