// bin: xb
// va: 0x00312BD0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312BD0 (0x00312BD0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0041BCE4[];
extern "C" char DAT_0041BCEC[];
extern "C" Object DAT_004743B0;
extern "C" char sub_0002E0C0[];

void __cdecl sub_00312BD0(void)
{
    DAT_004743B0.sub_0006F790((int)DAT_0041BCEC, (int)DAT_0041BCE4, (int)sub_0002E0C0, 0, 2, 2);
}
