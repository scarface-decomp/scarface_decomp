// bin: proto
// va: 0x002E2700
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2700 (Proto 0x002E2700, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FD104[];
extern "C" Object DAT_004535E8;
extern "C" char sub_0006C860[];

void __cdecl sub_002E2700(void)
{
    DAT_004535E8.sub_00065550(0, (int)DAT_003FD104, (int)sub_0006C860, 0, 2, 2);
}
