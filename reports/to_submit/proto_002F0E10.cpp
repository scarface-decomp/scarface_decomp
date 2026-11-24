// bin: proto
// va: 0x002F0E10
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0E10 (Proto 0x002F0E10, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00031F20();
};

extern "C" Object DAT_004493E0;

void __cdecl sub_002F0E10(void)
{
    DAT_004493E0.sub_00031F20();
    DAT_004493E0.sub_00031F20();
}
