// bin: proto
// va: 0x002ECE10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ECE10 (Proto 0x002ECE10, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_00427D20[];
extern "C" Object DAT_004633FC;
extern "C" char sub_001EF820[];

void __cdecl sub_002ECE10(void)
{
    DAT_004633FC.sub_000654B0(0, (int)DAT_00427D20, (int)sub_001EF820, 0, 1, 1);
}
