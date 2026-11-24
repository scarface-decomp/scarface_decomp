// bin: xb
// va: 0x003233B0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003233B0 (0x003233B0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0010F9F0();
};

extern "C" Object DAT_00489700;

void __cdecl sub_003233B0(void)
{
    DAT_00489700.sub_0010F9F0();
}
