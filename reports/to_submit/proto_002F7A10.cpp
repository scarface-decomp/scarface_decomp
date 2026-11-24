// bin: proto
// va: 0x002F7A10
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F7A10 (Proto 0x002F7A10, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00291040();
};

extern "C" Object DAT_00490C74;

void __cdecl sub_002F7A10(void)
{
    DAT_00490C74.sub_00291040();
}
