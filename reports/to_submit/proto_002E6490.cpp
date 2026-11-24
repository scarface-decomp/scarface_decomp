// bin: proto
// va: 0x002E6490
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6490 (Proto 0x002E6490, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040B480[];
extern "C" char DAT_0040B490[];
extern "C" Object DAT_0045D4E8;
extern "C" char sub_00158340[];

void __cdecl sub_002E6490(void)
{
    DAT_0045D4E8.sub_00065550((int)DAT_0040B490, (int)DAT_0040B480, (int)sub_00158340, 0, 2, 2);
}
