// bin: xb
// va: 0x0031EFA0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031EFA0 (0x0031EFA0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0044D6E4[];
extern "C" char DAT_0044D6F0[];
extern "C" Object DAT_00491694;
extern "C" char sub_00222400[];

void __cdecl sub_0031EFA0(void)
{
    DAT_00491694.sub_0006F740((int)DAT_0044D6F0, (int)DAT_0044D6E4, (int)sub_00222400, 0, 5, 8);
}
