// bin: proto
// va: 0x002E3150
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3150 (Proto 0x002E3150, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_003FE940[];
extern "C" Object DAT_00454220;
extern "C" char sub_0008D520[];

void __cdecl sub_002E3150(void)
{
    DAT_00454220.sub_000654B0(0, (int)DAT_003FE940, (int)sub_0008D520, 0, 2, 2);
}
