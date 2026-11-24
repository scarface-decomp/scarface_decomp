// bin: proto
// va: 0x002F11D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F11D0 (Proto 0x002F11D0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00031F20();
};

extern "C" Object DAT_0044AE4C;

void __cdecl sub_002F11D0(void)
{
    DAT_0044AE4C.sub_00031F20();
    DAT_0044AE4C.sub_00031F20();
}
