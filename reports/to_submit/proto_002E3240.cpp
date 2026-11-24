// bin: proto
// va: 0x002E3240
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3240 (Proto 0x002E3240, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065500(int, int, int, int, int, int);
};

extern "C" char DAT_003FE9A4[];
extern "C" Object DAT_00454378;
extern "C" char sub_0008D670[];

void __cdecl sub_002E3240(void)
{
    DAT_00454378.sub_00065500(0, (int)DAT_003FE9A4, (int)sub_0008D670, 0, 2, 2);
}
