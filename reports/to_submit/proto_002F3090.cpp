// bin: proto
// va: 0x002F3090
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3090 (Proto 0x002F3090, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00105140();
    void sub_00291040();
};

extern "C" Object DAT_0045CD68;
extern "C" Object DAT_0045CD78;
extern "C" Object DAT_0045CD94;

void __cdecl sub_002F3090(void)
{
    DAT_0045CD94.sub_00105140();
    DAT_0045CD78.sub_00291040();
    DAT_0045CD68.sub_00291040();
}
