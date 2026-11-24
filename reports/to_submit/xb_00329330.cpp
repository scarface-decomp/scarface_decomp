// bin: xb
// va: 0x00329330
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00329330 (0x00329330, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039E22C[];
extern "C" int DAT_0045B71C;

void __cdecl sub_00329330(void)
{
    DAT_0045B71C = (int)DAT_0039E22C;
}
