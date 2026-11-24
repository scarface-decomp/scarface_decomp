// bin: xb
// va: 0x00313110
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313110 (0x00313110, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041C61C[];
extern "C" Object DAT_00474C5C;
extern "C" char sub_0003D840[];

void __cdecl sub_00313110(void)
{
    DAT_00474C5C.sub_0006F830(0, (int)DAT_0041C61C, (int)sub_0003D840, 0, 2, 2);
}
