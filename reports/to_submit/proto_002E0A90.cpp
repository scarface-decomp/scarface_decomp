// bin: proto
// va: 0x002E0A90
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0A90 (Proto 0x002E0A90, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F66C8[];
extern "C" char DAT_003F66D8[];
extern "C" Object DAT_00449574;
extern "C" char sub_0002A860[];

void __cdecl sub_002E0A90(void)
{
    DAT_00449574.sub_00065550((int)DAT_003F66D8, (int)DAT_003F66C8, (int)sub_0002A860, 0, 3, 3);
}
