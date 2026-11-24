// bin: proto
// va: 0x002E5C00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5C00 (Proto 0x002E5C00, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040A55C[];
extern "C" char DAT_0040A56C[];
extern "C" Object DAT_0045CA40;
extern "C" char sub_001429C0[];

void __cdecl sub_002E5C00(void)
{
    DAT_0045CA40.sub_00065550((int)DAT_0040A56C, (int)DAT_0040A55C, (int)sub_001429C0, 0, 3, 3);
}
