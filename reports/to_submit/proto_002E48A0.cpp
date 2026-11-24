// bin: proto
// va: 0x002E48A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E48A0 (Proto 0x002E48A0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_00402500[];
extern "C" Object DAT_0045B8CC;
extern "C" char sub_000DB810[];

void __cdecl sub_002E48A0(void)
{
    DAT_0045B8CC.sub_000654B0(0, (int)DAT_00402500, (int)sub_000DB810, 0, 1, 1);
}
