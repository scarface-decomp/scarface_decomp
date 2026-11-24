// bin: proto
// va: 0x002E6790
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6790 (Proto 0x002E6790, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040B7CC[];
extern "C" char DAT_0040B7D8[];
extern "C" Object DAT_0045D908;
extern "C" char sub_001585A0[];

void __cdecl sub_002E6790(void)
{
    DAT_0045D908.sub_00065550((int)DAT_0040B7D8, (int)DAT_0040B7CC, (int)sub_001585A0, 0, 3, 3);
}
