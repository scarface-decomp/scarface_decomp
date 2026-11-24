// bin: proto
// va: 0x002ECF30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ECF30 (Proto 0x002ECF30, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00427DDC[];
extern "C" Object DAT_00463588;
extern "C" char sub_001EFA50[];

void __cdecl sub_002ECF30(void)
{
    DAT_00463588.sub_00065550(0, (int)DAT_00427DDC, (int)sub_001EFA50, 0, 4, 4);
}
