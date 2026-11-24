// bin: xb
// va: 0x003293D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003293D0 (0x003293D0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002CE560();
};

extern "C" Object DAT_004C01D8;

void __cdecl sub_003293D0(void)
{
    DAT_004C01D8.sub_002CE560();
}
