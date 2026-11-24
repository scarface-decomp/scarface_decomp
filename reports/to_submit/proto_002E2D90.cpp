// bin: proto
// va: 0x002E2D90
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2D90 (Proto 0x002E2D90, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FDE30[];
extern "C" Object DAT_00453B78;
extern "C" char sub_00083420[];

void __cdecl sub_002E2D90(void)
{
    DAT_00453B78.sub_00065550(0, (int)DAT_003FDE30, (int)sub_00083420, 0, 1, 1);
}
