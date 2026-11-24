// bin: xb
// va: 0x00319060
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319060 (0x00319060, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_00431654[];
extern "C" char DAT_00431664[];
extern "C" Object DAT_0048BE10;
extern "C" char sub_0017AC10[];

void __cdecl sub_00319060(void)
{
    DAT_0048BE10.sub_0006F880((int)DAT_00431664, (int)DAT_00431654, (int)sub_0017AC10, 0, 2, 2);
}
