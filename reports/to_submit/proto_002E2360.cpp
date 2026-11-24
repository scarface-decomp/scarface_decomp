// bin: proto
// va: 0x002E2360
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2360 (Proto 0x002E2360, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_003FCE50[];
extern "C" Object DAT_004530EC;
extern "C" char sub_0006C4E0[];

void __cdecl sub_002E2360(void)
{
    DAT_004530EC.sub_000655A0(0, (int)DAT_003FCE50, (int)sub_0006C4E0, 0, 1, 1);
}
