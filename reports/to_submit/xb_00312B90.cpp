// bin: xb
// va: 0x00312B90
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312B90 (0x00312B90, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041BCA0[];
extern "C" char DAT_0041BCB0[];
extern "C" Object DAT_00474358;
extern "C" char sub_0002DCF0[];

void __cdecl sub_00312B90(void)
{
    DAT_00474358.sub_0006F830((int)DAT_0041BCB0, (int)DAT_0041BCA0, (int)sub_0002DCF0, 0, 2, 3);
}
