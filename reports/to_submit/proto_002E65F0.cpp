// bin: proto
// va: 0x002E65F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E65F0 (Proto 0x002E65F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040B5F8[];
extern "C" char DAT_0040B608[];
extern "C" Object DAT_0045D6CC;
extern "C" char sub_001583E0[];

void __cdecl sub_002E65F0(void)
{
    DAT_0045D6CC.sub_00065550((int)DAT_0040B608, (int)DAT_0040B5F8, (int)sub_001583E0, 0, 3, 3);
}
