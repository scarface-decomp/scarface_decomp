// bin: proto
// va: 0x002F17F0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F17F0 (Proto 0x002F17F0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000F85A0();
};

extern "C" Object DAT_0045BB90;

void __cdecl sub_002F17F0(void)
{
    DAT_0045BB90.sub_000F85A0();
}
