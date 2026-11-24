// bin: proto
// va: 0x002ECD50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ECD50 (Proto 0x002ECD50, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_00427AC8[];
extern "C" Object DAT_004632F4;
extern "C" char sub_001EF1D0[];

void __cdecl sub_002ECD50(void)
{
    DAT_004632F4.sub_00065460(0, (int)DAT_00427AC8, (int)sub_001EF1D0, 0, 1, 1);
}
