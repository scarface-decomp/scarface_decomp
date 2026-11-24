// bin: proto
// va: 0x002E07C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E07C0 (Proto 0x002E07C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F5A8C[];
extern "C" char DAT_003F5A98[];
extern "C" Object DAT_00446D2C;
extern "C" char sub_00022E50[];

void __cdecl sub_002E07C0(void)
{
    DAT_00446D2C.sub_00065550((int)DAT_003F5A98, (int)DAT_003F5A8C, (int)sub_00022E50, 0, 2, 2);
}
