// bin: xb
// va: 0x003233C0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003233C0 (0x003233C0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00114DB0();
};

extern "C" Object DAT_00489830;

void __cdecl sub_003233C0(void)
{
    DAT_00489830.sub_00114DB0();
}
