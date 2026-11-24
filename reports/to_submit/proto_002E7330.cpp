// bin: proto
// va: 0x002E7330
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7330 (Proto 0x002E7330, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00410188[];
extern "C" char DAT_00410190[];
extern "C" Object DAT_0045EE78;
extern "C" char sub_00189F00[];

void __cdecl sub_002E7330(void)
{
    DAT_0045EE78.sub_00065550((int)DAT_00410190, (int)DAT_00410188, (int)sub_00189F00, 0, 3, 3);
}
