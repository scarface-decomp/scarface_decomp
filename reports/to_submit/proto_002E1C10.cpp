// bin: proto
// va: 0x002E1C10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1C10 (Proto 0x002E1C10, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F96E8[];
extern "C" Object DAT_0044B8B0;
extern "C" char sub_0005E940[];

void __cdecl sub_002E1C10(void)
{
    DAT_0044B8B0.sub_00065550(0, (int)DAT_003F96E8, (int)sub_0005E940, 0, 2, 2);
}
