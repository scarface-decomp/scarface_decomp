// bin: proto
// va: 0x002F8030
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F8030 (Proto 0x002F8030, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B9B10[];
extern "C" int DAT_00436E0C;

void __cdecl sub_002F8030(void)
{
    DAT_00436E0C = (int)DAT_003B9B10;
}
