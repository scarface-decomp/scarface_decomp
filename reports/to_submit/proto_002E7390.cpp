// bin: proto
// va: 0x002E7390
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7390 (Proto 0x002E7390, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004101B0[];
extern "C" char DAT_004101B8[];
extern "C" Object DAT_0045EED0;
extern "C" char sub_00189F60[];

void __cdecl sub_002E7390(void)
{
    DAT_0045EED0.sub_00065550((int)DAT_004101B8, (int)DAT_004101B0, (int)sub_00189F60, 0, 3, 3);
}
