// bin: proto
// va: 0x002E4760
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4760 (Proto 0x002E4760, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_00402410[];
extern "C" Object DAT_0045B714;
extern "C" char sub_000DB710[];

void __cdecl sub_002E4760(void)
{
    DAT_0045B714.sub_000654B0(0, (int)DAT_00402410, (int)sub_000DB710, 0, 2, 2);
}
