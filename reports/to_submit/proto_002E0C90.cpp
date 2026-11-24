// bin: proto
// va: 0x002E0C90
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0C90 (Proto 0x002E0C90, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F6BF4[];
extern "C" char DAT_003F6BFC[];
extern "C" Object DAT_004496D4;
extern "C" char sub_0002B310[];

void __cdecl sub_002E0C90(void)
{
    DAT_004496D4.sub_00065550((int)DAT_003F6BFC, (int)DAT_003F6BF4, (int)sub_0002B310, 0, 2, 2);
}
