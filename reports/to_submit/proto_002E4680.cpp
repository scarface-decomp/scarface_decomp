// bin: proto
// va: 0x002E4680
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4680 (Proto 0x002E4680, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065500(int, int, int, int, int, int);
};

extern "C" char DAT_00402390[];
extern "C" Object DAT_0045B5E0;
extern "C" char sub_000DB610[];

void __cdecl sub_002E4680(void)
{
    DAT_0045B5E0.sub_00065500(0, (int)DAT_00402390, (int)sub_000DB610, 0, 4, 4);
}
