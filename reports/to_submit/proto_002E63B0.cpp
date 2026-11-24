// bin: proto
// va: 0x002E63B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E63B0 (Proto 0x002E63B0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040B380[];
extern "C" char DAT_0040B38C[];
extern "C" Object DAT_0045D3B4;
extern "C" char sub_001582C0[];

void __cdecl sub_002E63B0(void)
{
    DAT_0045D3B4.sub_00065550((int)DAT_0040B38C, (int)DAT_0040B380, (int)sub_001582C0, 0, 2, 2);
}
