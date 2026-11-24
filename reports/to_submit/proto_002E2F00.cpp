// bin: proto
// va: 0x002E2F00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2F00 (Proto 0x002E2F00, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_003FDFA4[];
extern "C" Object DAT_00453DC0;
extern "C" char sub_00084C80[];

void __cdecl sub_002E2F00(void)
{
    DAT_00453DC0.sub_00065460(0, (int)DAT_003FDFA4, (int)sub_00084C80, 0, 2, 2);
}
