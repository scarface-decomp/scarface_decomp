// bin: xb
// va: 0x00320350
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00320350 (0x00320350, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003D33B0[];
extern "C" Object DAT_00492914;
extern "C" char sub_00233210[];

void __cdecl sub_00320350(void)
{
    DAT_00492914.sub_000EB3A0(9, 48, 16, 96, 9, (int)DAT_003D33B0, (int)sub_00233210, 509, 3, 0);
}
