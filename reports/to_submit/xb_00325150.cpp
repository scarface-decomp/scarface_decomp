// bin: xb
// va: 0x00325150
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325150 (0x00325150, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0009A770();
};

extern "C" Object DAT_0048C2A0;

void __cdecl sub_00325150(void)
{
    DAT_0048C2A0.sub_0009A770();
}
