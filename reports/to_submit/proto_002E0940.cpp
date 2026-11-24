// bin: proto
// va: 0x002E0940
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0940 (Proto 0x002E0940, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F60EC[];
extern "C" char DAT_003F60FC[];
extern "C" Object DAT_00446F18;
extern "C" char sub_000244C0[];

void __cdecl sub_002E0940(void)
{
    DAT_00446F18.sub_00065550((int)DAT_003F60FC, (int)DAT_003F60EC, (int)sub_000244C0, 0, 3, 3);
}
