// bin: proto
// va: 0x002E4780
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4780 (Proto 0x002E4780, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_00402424[];
extern "C" Object DAT_0045B740;
extern "C" char sub_000DB730[];

void __cdecl sub_002E4780(void)
{
    DAT_0045B740.sub_000654B0(0, (int)DAT_00402424, (int)sub_000DB730, 0, 3, 3);
}
