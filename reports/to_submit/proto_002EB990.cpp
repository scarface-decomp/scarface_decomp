// bin: proto
// va: 0x002EB990
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB990 (Proto 0x002EB990, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003AA5DC;
extern "C" float DAT_00461FA4;

void __cdecl sub_002EB990(void)
{
    DAT_00461FA4 = DAT_003AA5DC;
}
