// bin: proto
// va: 0x002E32E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E32E0 (Proto 0x002E32E0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_003FE9E4[];
extern "C" Object DAT_00454454;
extern "C" char sub_0008D870[];

void __cdecl sub_002E32E0(void)
{
    DAT_00454454.sub_00065460(0, (int)DAT_003FE9E4, (int)sub_0008D870, 0, 3, 3);
}
