// bin: proto
// va: 0x002E6570
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6570 (Proto 0x002E6570, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B564[];
extern "C" char DAT_0040B578[];
extern "C" Object DAT_0045D61C;
extern "C" char sub_001583B0[];

void __cdecl sub_002E6570(void)
{
    DAT_0045D61C.sub_000655A0((int)DAT_0040B578, (int)DAT_0040B564, (int)sub_001583B0, 0, 2, 2);
}
