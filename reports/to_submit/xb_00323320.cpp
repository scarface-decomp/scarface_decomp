// bin: xb
// va: 0x00323320
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323320 (0x00323320, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004879E8;

void __cdecl sub_00323320(void)
{
    DAT_004879E8 = -0x22222223;
}
