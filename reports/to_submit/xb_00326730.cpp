// bin: xb
// va: 0x00326730
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326730 (0x00326730, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002CE560();
};

extern "C" Object DAT_0048F17C;

void __cdecl sub_00326730(void)
{
    DAT_0048F17C.sub_002CE560();
}
