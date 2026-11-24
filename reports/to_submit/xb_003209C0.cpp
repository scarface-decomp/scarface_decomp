// bin: xb
// va: 0x003209C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003209C0 (0x003209C0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00241970();
};

extern "C" Object DAT_004BC1E4;

void __cdecl sub_003209C0(void)
{
    DAT_004BC1E4.sub_00241970();
}
