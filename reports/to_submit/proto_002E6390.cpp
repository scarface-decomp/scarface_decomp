// bin: proto
// va: 0x002E6390
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6390 (Proto 0x002E6390, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B358[];
extern "C" char DAT_0040B370[];
extern "C" Object DAT_0045D388;
extern "C" char sub_001582B0[];

void __cdecl sub_002E6390(void)
{
    DAT_0045D388.sub_000654B0((int)DAT_0040B370, (int)DAT_0040B358, (int)sub_001582B0, 0, 2, 2);
}
