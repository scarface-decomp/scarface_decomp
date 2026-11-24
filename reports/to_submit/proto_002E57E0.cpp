// bin: proto
// va: 0x002E57E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E57E0 (Proto 0x002E57E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00409A64[];
extern "C" char DAT_00409A7C[];
extern "C" Object DAT_0045C564;
extern "C" char sub_001418D0[];

void __cdecl sub_002E57E0(void)
{
    DAT_0045C564.sub_00065550((int)DAT_00409A7C, (int)DAT_00409A64, (int)sub_001418D0, 0, 3, 6);
}
