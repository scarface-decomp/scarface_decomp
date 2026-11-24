// bin: proto
// va: 0x002F1800
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1800 (Proto 0x002F1800, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000FB880();
};

extern "C" Object DAT_0045BCC0;

void __cdecl sub_002F1800(void)
{
    DAT_0045BCC0.sub_000FB880();
}
