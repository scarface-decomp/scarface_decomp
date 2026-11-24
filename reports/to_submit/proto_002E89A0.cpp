// bin: proto
// va: 0x002E89A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E89A0 (Proto 0x002E89A0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004138B0[];
extern "C" char DAT_004138C4[];
extern "C" Object DAT_00460190;
extern "C" char sub_001978D0[];

void __cdecl sub_002E89A0(void)
{
    DAT_00460190.sub_00065550((int)DAT_004138C4, (int)DAT_004138B0, (int)sub_001978D0, 0, 3, 3);
}
