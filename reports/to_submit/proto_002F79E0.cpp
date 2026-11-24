// bin: proto
// va: 0x002F79E0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F79E0 (Proto 0x002F79E0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003834C4[];
extern "C" int DAT_0043444C;

void __cdecl sub_002F79E0(void)
{
    DAT_0043444C = (int)DAT_003834C4;
}
