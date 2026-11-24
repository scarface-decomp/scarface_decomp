// bin: xb
// va: 0x00329400
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00329400 (0x00329400, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002CE560();
};

extern "C" Object DAT_004C0430;

void __cdecl sub_00329400(void)
{
    DAT_004C0430.sub_002CE560();
}
