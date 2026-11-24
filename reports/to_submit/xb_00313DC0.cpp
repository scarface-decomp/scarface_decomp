// bin: xb
// va: 0x00313DC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313DC0 (0x00313DC0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0041EF58[];
extern "C" Object DAT_0047AD94;
extern "C" char sub_00071200[];

void __cdecl sub_00313DC0(void)
{
    DAT_0047AD94.sub_0006F740(0, (int)DAT_0041EF58, (int)sub_00071200, 0, 4, 4);
}
