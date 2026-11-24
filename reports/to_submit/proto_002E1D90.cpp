// bin: proto
// va: 0x002E1D90
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1D90 (Proto 0x002E1D90, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_003F9BFC[];
extern "C" Object DAT_0044F740;
extern "C" char sub_00066C00[];

void __cdecl sub_002E1D90(void)
{
    DAT_0044F740.sub_000654B0(0, (int)DAT_003F9BFC, (int)sub_00066C00, 0, 3, 3);
}
