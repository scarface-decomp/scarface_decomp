// bin: proto
// va: 0x002E0920
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0920 (Proto 0x002E0920, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F60DC[];
extern "C" char DAT_003F60E4[];
extern "C" Object DAT_00446EEC;
extern "C" char sub_00024490[];

void __cdecl sub_002E0920(void)
{
    DAT_00446EEC.sub_00065550((int)DAT_003F60E4, (int)DAT_003F60DC, (int)sub_00024490, 0, 3, 3);
}
