// bin: proto
// va: 0x002E2440
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2440 (Proto 0x002E2440, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065500(int, int, int, int, int, int);
};

extern "C" char DAT_003FCF00[];
extern "C" Object DAT_00453220;
extern "C" char sub_0006C5E0[];

void __cdecl sub_002E2440(void)
{
    DAT_00453220.sub_00065500(0, (int)DAT_003FCF00, (int)sub_0006C5E0, 0, 2, 2);
}
