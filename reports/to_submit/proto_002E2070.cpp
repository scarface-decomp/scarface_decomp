// bin: proto
// va: 0x002E2070
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2070 (Proto 0x002E2070, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_003F9CFC[];
extern "C" Object DAT_0044FB34;
extern "C" char sub_00066990[];

void __cdecl sub_002E2070(void)
{
    DAT_0044FB34.sub_000654B0(0, (int)DAT_003F9CFC, (int)sub_00066990, 0, 2, 2);
}
