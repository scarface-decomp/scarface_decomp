// bin: xb
// va: 0x00316980
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316980 (0x00316980, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_00428634[];
extern "C" Object DAT_004898C0;
extern "C" char sub_001152F0[];

void __cdecl sub_00316980(void)
{
    DAT_004898C0.sub_0006F880(0, (int)DAT_00428634, (int)sub_001152F0, 0, 1, 1);
}
