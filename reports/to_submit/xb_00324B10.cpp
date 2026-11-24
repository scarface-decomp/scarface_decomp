// bin: xb
// va: 0x00324B10
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324B10 (0x00324B10, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001204E0();
};

extern "C" Object DAT_0048ABB4;

void __cdecl sub_00324B10(void)
{
    DAT_0048ABB4.sub_001204E0();
}
