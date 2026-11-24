// bin: xb
// va: 0x00312600
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312600 (0x00312600, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0041AA30[];
extern "C" Object DAT_004718FC;
extern "C" char sub_00024BB0[];

void __cdecl sub_00312600(void)
{
    DAT_004718FC.sub_0006F790(0, (int)DAT_0041AA30, (int)sub_00024BB0, 0, 2, 2);
}
