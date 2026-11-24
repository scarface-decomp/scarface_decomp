// bin: proto
// va: 0x002E8710
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8710 (Proto 0x002E8710, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00412DC0[];
extern "C" char DAT_00412DC8[];
extern "C" Object DAT_004600EC;
extern "C" char sub_00193510[];

void __cdecl sub_002E8710(void)
{
    DAT_004600EC.sub_00065550((int)DAT_00412DC8, (int)DAT_00412DC0, (int)sub_00193510, 0, 3, 3);
}
