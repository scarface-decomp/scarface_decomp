// bin: xb
// va: 0x00329390
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00329390 (0x00329390, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003DFD60[];
extern "C" int DAT_00463230;

void __cdecl sub_00329390(void)
{
    DAT_00463230 = (int)DAT_003DFD60;
}
