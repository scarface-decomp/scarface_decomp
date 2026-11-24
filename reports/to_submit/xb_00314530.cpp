// bin: xb
// va: 0x00314530
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314530 (0x00314530, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_004223A0[];
extern "C" Object DAT_00480F24;
extern "C" char sub_000772D0[];

void __cdecl sub_00314530(void)
{
    DAT_00480F24.sub_0006F880(0, (int)DAT_004223A0, (int)sub_000772D0, 0, 1, 1);
}
