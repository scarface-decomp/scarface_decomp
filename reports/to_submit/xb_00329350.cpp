// bin: xb
// va: 0x00329350
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00329350 (0x00329350, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002D45A0();
};

extern "C" Object DAT_004BFF08;

void __cdecl sub_00329350(void)
{
    DAT_004BFF08.sub_002D45A0();
}
