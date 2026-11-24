// bin: proto
// va: 0x002ECD90
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ECD90 (Proto 0x002ECD90, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_00427B08[];
extern "C" Object DAT_0046334C;
extern "C" char sub_001EF250[];

void __cdecl sub_002ECD90(void)
{
    DAT_0046334C.sub_00065460(0, (int)DAT_00427B08, (int)sub_001EF250, 0, 3, 3);
}
