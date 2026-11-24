// bin: proto
// va: 0x002E2010
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2010 (Proto 0x002E2010, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_003F9CD4[];
extern "C" Object DAT_0044FAB0;
extern "C" char sub_00067510[];

void __cdecl sub_002E2010(void)
{
    DAT_0044FAB0.sub_00065460(0, (int)DAT_003F9CD4, (int)sub_00067510, 0, 3, 4);
}
