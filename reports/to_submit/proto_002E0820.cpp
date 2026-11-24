// bin: proto
// va: 0x002E0820
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0820 (Proto 0x002E0820, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F5AD8[];
extern "C" char DAT_003F5AE8[];
extern "C" Object DAT_00446DB0;
extern "C" char sub_00022F40[];

void __cdecl sub_002E0820(void)
{
    DAT_00446DB0.sub_00065550((int)DAT_003F5AE8, (int)DAT_003F5AD8, (int)sub_00022F40, 0, 3, 3);
}
