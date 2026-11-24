// bin: xb
// va: 0x0031ABA0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031ABA0 (0x0031ABA0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_00437DF0[];
extern "C" char DAT_00437E00[];
extern "C" Object DAT_0048E3A0;
extern "C" char sub_001BF8D0[];

void __cdecl sub_0031ABA0(void)
{
    DAT_0048E3A0.sub_0006F880((int)DAT_00437E00, (int)DAT_00437DF0, (int)sub_001BF8D0, 0, 2, 2);
}
