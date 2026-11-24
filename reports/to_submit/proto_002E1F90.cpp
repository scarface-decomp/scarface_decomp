// bin: proto
// va: 0x002E1F90
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1F90 (Proto 0x002E1F90, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_003F9CA0[];
extern "C" Object DAT_0044FA00;
extern "C" char sub_00067480[];

void __cdecl sub_002E1F90(void)
{
    DAT_0044FA00.sub_00065460(0, (int)DAT_003F9CA0, (int)sub_00067480, 0, 4, 4);
}
