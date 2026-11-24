// bin: proto
// va: 0x002E2E60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2E60 (Proto 0x002E2E60, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FDF50[];
extern "C" Object DAT_00453CE4;
extern "C" char sub_00084B40[];

void __cdecl sub_002E2E60(void)
{
    DAT_00453CE4.sub_00065550(0, (int)DAT_003FDF50, (int)sub_00084B40, 0, 4, 5);
}
