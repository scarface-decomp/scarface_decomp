// bin: proto
// va: 0x002E26E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E26E0 (Proto 0x002E26E0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FD0EC[];
extern "C" Object DAT_004535BC;
extern "C" char sub_0006C840[];

void __cdecl sub_002E26E0(void)
{
    DAT_004535BC.sub_00065550(0, (int)DAT_003FD0EC, (int)sub_0006C840, 0, 2, 2);
}
