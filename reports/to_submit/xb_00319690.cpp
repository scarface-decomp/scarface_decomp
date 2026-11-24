// bin: xb
// va: 0x00319690
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319690 (0x00319690, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00048320();
};

extern "C" Object DAT_0048C2D0;

void __cdecl sub_00319690(void)
{
    DAT_0048C2D0.sub_00048320();
}
