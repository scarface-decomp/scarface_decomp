// bin: xb
// va: 0x0031F0C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F0C0 (0x0031F0C0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0044D934[];
extern "C" Object DAT_004917F4;
extern "C" char sub_00222990[];

void __cdecl sub_0031F0C0(void)
{
    DAT_004917F4.sub_0006F790(0, (int)DAT_0044D934, (int)sub_00222990, 0, 2, 2);
}
