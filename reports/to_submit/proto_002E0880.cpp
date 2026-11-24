// bin: proto
// va: 0x002E0880
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0880 (Proto 0x002E0880, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F5B2C[];
extern "C" char DAT_003F5B3C[];
extern "C" Object DAT_00446E34;
extern "C" char sub_00022FB0[];

void __cdecl sub_002E0880(void)
{
    DAT_00446E34.sub_00065550((int)DAT_003F5B3C, (int)DAT_003F5B2C, (int)sub_00022FB0, 0, 2, 2);
}
