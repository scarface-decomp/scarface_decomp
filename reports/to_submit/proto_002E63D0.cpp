// bin: proto
// va: 0x002E63D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E63D0 (Proto 0x002E63D0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040B39C[];
extern "C" char DAT_0040B3B4[];
extern "C" Object DAT_0045D3E0;
extern "C" char sub_001582D0[];

void __cdecl sub_002E63D0(void)
{
    DAT_0045D3E0.sub_00065550((int)DAT_0040B3B4, (int)DAT_0040B39C, (int)sub_001582D0, 0, 3, 3);
}
