// bin: xb
// va: 0x003293A0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003293A0 (0x003293A0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A5BF8[];
extern "C" int DAT_004633AC;

void __cdecl sub_003293A0(void)
{
    DAT_004633AC = (int)DAT_003A5BF8;
}
