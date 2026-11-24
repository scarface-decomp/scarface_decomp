// bin: proto
// va: 0x002F2FF0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2FF0 (Proto 0x002F2FF0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001B7A10();
};

extern "C" Object DAT_0045CC08;

void __cdecl sub_002F2FF0(void)
{
    DAT_0045CC08.sub_001B7A10();
}
