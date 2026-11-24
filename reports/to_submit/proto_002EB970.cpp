// bin: proto
// va: 0x002EB970
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB970 (Proto 0x002EB970, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003AA5D8;
extern "C" float DAT_00461FA0;

void __cdecl sub_002EB970(void)
{
    DAT_00461FA0 = DAT_003AA5D8;
}
