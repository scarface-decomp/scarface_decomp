// bin: xb
// va: 0x00315400
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315400 (0x00315400, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004248CC[];
extern "C" Object DAT_00486FA4;
extern "C" char sub_000CA670[];

void __cdecl sub_00315400(void)
{
    DAT_00486FA4.sub_0006F830(0, (int)DAT_004248CC, (int)sub_000CA670, 0, 2, 2);
}
