// bin: xb
// va: 0x00312930
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312930 (0x00312930, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0041B72C[];
extern "C" char DAT_0041B730[];
extern "C" Object DAT_004741A0;
extern "C" char sub_0002D4F0[];

void __cdecl sub_00312930(void)
{
    DAT_004741A0.sub_0006F880((int)DAT_0041B730, (int)DAT_0041B72C, (int)sub_0002D4F0, 0, 3, 3);
}
