// bin: proto
// va: 0x002F1750
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1750 (Proto 0x002F1750, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045A0EC;

void __cdecl sub_002F1750(void)
{
    DAT_0045A0EC = -0x22222223;
}
