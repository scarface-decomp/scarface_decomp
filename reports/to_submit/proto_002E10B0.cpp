// bin: proto
// va: 0x002E10B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E10B0 (Proto 0x002E10B0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F72E8[];
extern "C" Object DAT_00449E2C;
extern "C" char sub_001B7A10[];

void __cdecl sub_002E10B0(void)
{
    DAT_00449E2C.sub_00065550(0, (int)DAT_003F72E8, (int)sub_001B7A10, 0, 2, 2);
}
