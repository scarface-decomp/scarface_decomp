// bin: xb
// va: 0x00313540
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313540 (0x00313540, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00048320();
};

extern "C" Object DAT_00475970;

void __cdecl sub_00313540(void)
{
    DAT_00475970.sub_00048320();
}
