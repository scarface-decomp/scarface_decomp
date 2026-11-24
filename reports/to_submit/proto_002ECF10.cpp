// bin: proto
// va: 0x002ECF10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ECF10 (Proto 0x002ECF10, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00427DC8[];
extern "C" Object DAT_0046355C;
extern "C" char sub_001EF910[];

void __cdecl sub_002ECF10(void)
{
    DAT_0046355C.sub_00065550(0, (int)DAT_00427DC8, (int)sub_001EF910, 0, 1, 1);
}
