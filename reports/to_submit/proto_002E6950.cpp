// bin: proto
// va: 0x002E6950
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6950 (Proto 0x002E6950, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B9A0[];
extern "C" char DAT_0040B9B8[];
extern "C" Object DAT_0045DB70;
extern "C" char sub_00159040[];

void __cdecl sub_002E6950(void)
{
    DAT_0045DB70.sub_000654B0((int)DAT_0040B9B8, (int)DAT_0040B9A0, (int)sub_00159040, 0, 2, 2);
}
