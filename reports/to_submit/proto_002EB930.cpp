// bin: proto
// va: 0x002EB930
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB930 (Proto 0x002EB930, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037F540;
extern "C" float DAT_00461F98;

void __cdecl sub_002EB930(void)
{
    DAT_00461F98 = DAT_0037F540;
}
