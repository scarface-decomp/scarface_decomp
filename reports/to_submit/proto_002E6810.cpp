// bin: proto
// va: 0x002E6810
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6810 (Proto 0x002E6810, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040B840[];
extern "C" char DAT_0040B84C[];
extern "C" Object DAT_0045D9B8;
extern "C" char sub_00158640[];

void __cdecl sub_002E6810(void)
{
    DAT_0045D9B8.sub_00065550((int)DAT_0040B84C, (int)DAT_0040B840, (int)sub_00158640, 0, 2, 2);
}
