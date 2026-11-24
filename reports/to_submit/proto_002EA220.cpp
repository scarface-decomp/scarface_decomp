// bin: proto
// va: 0x002EA220
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EA220 (Proto 0x002EA220, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004194B0[];
extern "C" char DAT_004194C8[];
extern "C" Object DAT_00461630;
extern "C" char sub_001C1E60[];

void __cdecl sub_002EA220(void)
{
    DAT_00461630.sub_00065550((int)DAT_004194C8, (int)DAT_004194B0, (int)sub_001C1E60, 0, 4, 4);
}
