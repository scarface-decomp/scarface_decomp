// bin: xb
// va: 0x00314AF0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314AF0 (0x00314AF0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_00423238[];
extern "C" Object DAT_004817D8;
extern "C" char sub_0008FC00[];

void __cdecl sub_00314AF0(void)
{
    DAT_004817D8.sub_0006F790(0, (int)DAT_00423238, (int)sub_0008FC00, 0, 1, 1);
}
