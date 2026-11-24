// bin: xb
// va: 0x00321010
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00321010 (0x00321010, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002427E0(int);
};

extern "C" Object DAT_004BDCC8;

void __cdecl sub_00321010(void)
{
    DAT_004BDCC8.sub_002427E0(0);
}
