// bin: proto
// va: 0x002E3200
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3200 (Proto 0x002E3200, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065500(int, int, int, int, int, int);
};

extern "C" char DAT_003FE98C[];
extern "C" Object DAT_00454320;
extern "C" char sub_0008D630[];

void __cdecl sub_002E3200(void)
{
    DAT_00454320.sub_00065500(0, (int)DAT_003FE98C, (int)sub_0008D630, 0, 2, 2);
}
