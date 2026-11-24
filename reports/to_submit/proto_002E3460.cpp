// bin: proto
// va: 0x002E3460
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3460 (Proto 0x002E3460, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FF37C[];
extern "C" char DAT_003FF388[];
extern "C" Object DAT_00459548;
extern "C" char sub_000BABD0[];

void __cdecl sub_002E3460(void)
{
    DAT_00459548.sub_00065550((int)DAT_003FF388, (int)DAT_003FF37C, (int)sub_000BABD0, 0, 3, 6);
}
