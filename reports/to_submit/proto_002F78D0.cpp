// bin: proto
// va: 0x002F78D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F78D0 (Proto 0x002F78D0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B0A74[];
extern "C" int DAT_0042FC90;

void __cdecl sub_002F78D0(void)
{
    DAT_0042FC90 = (int)DAT_003B0A74;
}
