// bin: proto
// va: 0x002E49F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E49F0 (Proto 0x002E49F0, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;
extern "C" float DAT_0045BC88;

void __cdecl sub_002E49F0(void)
{
    DAT_0045BC88 = DAT_0037CE50;
}
