// bin: proto
// va: 0x002ECE30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ECE30 (Proto 0x002ECE30, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00427D3C[];
extern "C" Object DAT_00463428;
extern "C" char sub_001EF740[];

void __cdecl sub_002ECE30(void)
{
    DAT_00463428.sub_00065550(0, (int)DAT_00427D3C, (int)sub_001EF740, 0, 2, 2);
}
