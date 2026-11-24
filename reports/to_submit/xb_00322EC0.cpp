// bin: xb
// va: 0x00322EC0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322EC0 (0x00322EC0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002CE560();
};

extern "C" Object DAT_004810E0;

void __cdecl sub_00322EC0(void)
{
    DAT_004810E0.sub_002CE560();
}
