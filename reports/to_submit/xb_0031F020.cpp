// bin: xb
// va: 0x0031F020
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F020 (0x0031F020, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044D8C0[];
extern "C" Object DAT_00491718;
extern "C" char sub_00222940[];

void __cdecl sub_0031F020(void)
{
    DAT_00491718.sub_0006F830(0, (int)DAT_0044D8C0, (int)sub_00222940, 0, 2, 2);
}
