// bin: proto
// va: 0x002E1850
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1850 (Proto 0x002E1850, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_003F8B88[];
extern "C" Object DAT_0044A8FC;
extern "C" char sub_00055FA0[];

void __cdecl sub_002E1850(void)
{
    DAT_0044A8FC.sub_000654B0(0, (int)DAT_003F8B88, (int)sub_00055FA0, 0, 2, 2);
}
