// bin: xb
// va: 0x003145B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003145B0 (0x003145B0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003A3354[];
extern "C" Object DAT_00480FC8;
extern "C" char sub_00078EA0[];

void __cdecl sub_003145B0(void)
{
    DAT_00480FC8.sub_000EB3A0(16, 8, 2, 38, 39, (int)DAT_003A3354, (int)sub_00078EA0, 509, 3, 1);
}
