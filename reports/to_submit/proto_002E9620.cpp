// bin: proto
// va: 0x002E9620
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9620 (Proto 0x002E9620, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A2624[];
extern "C" int DAT_00460B8C;
extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_002E9620(void)
{
    DAT_00460B8C = sub_002014E0((int)DAT_003A2624, 0);
}
