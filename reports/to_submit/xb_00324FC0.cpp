// bin: xb
// va: 0x00324FC0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324FC0 (0x00324FC0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002A9290();
};

extern "C" Object DAT_0048BF38;

void __cdecl sub_00324FC0(void)
{
    DAT_0048BF38.sub_002A9290();
}
