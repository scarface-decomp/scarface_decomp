// bin: proto
// va: 0x002E0780
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0780 (Proto 0x002E0780, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_003F5A54[];
extern "C" char DAT_003F5A68[];
extern "C" Object DAT_00446CD4;
extern "C" char sub_00022E30[];

void __cdecl sub_002E0780(void)
{
    DAT_00446CD4.sub_000654B0((int)DAT_003F5A68, (int)DAT_003F5A54, (int)sub_00022E30, 0, 2, 2);
}
