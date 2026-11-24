// bin: xb
// va: 0x003135B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003135B0 (0x003135B0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0041DCCC[];
extern "C" Object DAT_00475B2C;
extern "C" char sub_000605E0[];

void __cdecl sub_003135B0(void)
{
    DAT_00475B2C.sub_0006F790(0, (int)DAT_0041DCCC, (int)sub_000605E0, 0, 4, 4);
}
