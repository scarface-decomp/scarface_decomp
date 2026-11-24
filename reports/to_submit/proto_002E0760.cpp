// bin: proto
// va: 0x002E0760
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0760 (Proto 0x002E0760, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_003F5A34[];
extern "C" char DAT_003F5A48[];
extern "C" Object DAT_00446CA8;
extern "C" char sub_00022E20[];

void __cdecl sub_002E0760(void)
{
    DAT_00446CA8.sub_000654B0((int)DAT_003F5A48, (int)DAT_003F5A34, (int)sub_00022E20, 0, 2, 2);
}
