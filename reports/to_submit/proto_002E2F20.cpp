// bin: proto
// va: 0x002E2F20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2F20 (Proto 0x002E2F20, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_003FDFB8[];
extern "C" Object DAT_00453DEC;
extern "C" char sub_00084BC0[];

void __cdecl sub_002E2F20(void)
{
    DAT_00453DEC.sub_00065460(0, (int)DAT_003FDFB8, (int)sub_00084BC0, 0, 1, 1);
}
