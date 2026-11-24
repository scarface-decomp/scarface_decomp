// bin: proto
// va: 0x002E4A10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4A10 (Proto 0x002E4A10, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_00389D38;
extern "C" float DAT_0045BC8C;

void __cdecl sub_002E4A10(void)
{
    DAT_0045BC8C = DAT_00389D38;
}
