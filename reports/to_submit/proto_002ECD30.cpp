// bin: proto
// va: 0x002ECD30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ECD30 (Proto 0x002ECD30, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00427AAC[];
extern "C" Object DAT_004632C8;
extern "C" char sub_001EF1B0[];

void __cdecl sub_002ECD30(void)
{
    DAT_004632C8.sub_00065550(0, (int)DAT_00427AAC, (int)sub_001EF1B0, 0, 2, 2);
}
