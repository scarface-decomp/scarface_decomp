// bin: xb
// va: 0x00312D30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312D30 (0x00312D30, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041C1D8[];
extern "C" Object DAT_00474740;
extern "C" char sub_0002EB20[];

void __cdecl sub_00312D30(void)
{
    DAT_00474740.sub_0006F830(0, (int)DAT_0041C1D8, (int)sub_0002EB20, 0, 2, 2);
}
