// bin: xb
// va: 0x0031C0B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031C0B0 (0x0031C0B0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0043B800[];
extern "C" char DAT_0043B810[];
extern "C" Object DAT_0048F2C0;
extern "C" char sub_001D7380[];

void __cdecl sub_0031C0B0(void)
{
    DAT_0048F2C0.sub_0006F790((int)DAT_0043B810, (int)DAT_0043B800, (int)sub_001D7380, 0, 2, 2);
}
