// bin: proto
// va: 0x002E73B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E73B0 (Proto 0x002E73B0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004101CC[];
extern "C" char DAT_004101D4[];
extern "C" Object DAT_0045EEFC;
extern "C" char sub_00189F90[];

void __cdecl sub_002E73B0(void)
{
    DAT_0045EEFC.sub_00065550((int)DAT_004101D4, (int)DAT_004101CC, (int)sub_00189F90, 0, 3, 3);
}
