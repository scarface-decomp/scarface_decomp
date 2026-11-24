// bin: xb
// va: 0x00312BF0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312BF0 (0x00312BF0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0041BCFC[];
extern "C" char DAT_0041BD0C[];
extern "C" Object DAT_004743DC;
extern "C" char sub_0002E0D0[];

void __cdecl sub_00312BF0(void)
{
    DAT_004743DC.sub_0006F790((int)DAT_0041BD0C, (int)DAT_0041BCFC, (int)sub_0002E0D0, 0, 2, 2);
}
