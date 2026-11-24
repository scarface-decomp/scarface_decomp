// bin: proto
// va: 0x002E9E20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9E20 (Proto 0x002E9E20, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004180D8[];
extern "C" char DAT_004180F4[];
extern "C" Object DAT_00461008;
extern "C" char sub_001B4A50[];

void __cdecl sub_002E9E20(void)
{
    DAT_00461008.sub_00065550((int)DAT_004180F4, (int)DAT_004180D8, (int)sub_001B4A50, 0, 3, 3);
}
