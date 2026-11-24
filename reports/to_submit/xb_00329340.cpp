// bin: xb
// va: 0x00329340
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00329340 (0x00329340, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D68A4[];
extern "C" int DAT_0045EDF0;

void __cdecl sub_00329340(void)
{
    DAT_0045EDF0 = (int)DAT_003D68A4;
}
