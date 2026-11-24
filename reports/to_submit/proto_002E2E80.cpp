// bin: proto
// va: 0x002E2E80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2E80 (Proto 0x002E2E80, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FDF5C[];
extern "C" Object DAT_00453D10;
extern "C" char sub_00084BA0[];

void __cdecl sub_002E2E80(void)
{
    DAT_00453D10.sub_00065550(0, (int)DAT_003FDF5C, (int)sub_00084BA0, 0, 2, 2);
}
