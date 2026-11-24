// bin: xb
// va: 0x00318F00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318F00 (0x00318F00, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_00431344[];
extern "C" char DAT_00431354[];
extern "C" Object DAT_0048BC84;
extern "C" char sub_0017A6B0[];

void __cdecl sub_00318F00(void)
{
    DAT_0048BC84.sub_0006F790((int)DAT_00431354, (int)DAT_00431344, (int)sub_0017A6B0, 0, 3, 3);
}
