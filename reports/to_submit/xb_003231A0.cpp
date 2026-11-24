// bin: xb
// va: 0x003231A0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003231A0 (0x003231A0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002A9290();
};

extern "C" Object DAT_00487478;

void __cdecl sub_003231A0(void)
{
    DAT_00487478.sub_002A9290();
}
