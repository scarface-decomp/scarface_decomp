// bin: proto
// va: 0x002E3190
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3190 (Proto 0x002E3190, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_003FE950[];
extern "C" Object DAT_00454278;
extern "C" char sub_0008D5A0[];

void __cdecl sub_002E3190(void)
{
    DAT_00454278.sub_00065460(0, (int)DAT_003FE950, (int)sub_0008D5A0, 0, 3, 3);
}
