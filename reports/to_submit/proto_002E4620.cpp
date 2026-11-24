// bin: proto
// va: 0x002E4620
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4620 (Proto 0x002E4620, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065500(int, int, int, int, int, int);
};

extern "C" char DAT_00402368[];
extern "C" Object DAT_0045B55C;
extern "C" char sub_000DB510[];

void __cdecl sub_002E4620(void)
{
    DAT_0045B55C.sub_00065500(0, (int)DAT_00402368, (int)sub_000DB510, 0, 2, 3);
}
