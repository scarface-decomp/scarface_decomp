// bin: proto
// va: 0x002E76B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E76B0 (Proto 0x002E76B0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004106B8[];
extern "C" Object DAT_0045F1E8;
extern "C" char sub_0018A560[];

void __cdecl sub_002E76B0(void)
{
    DAT_0045F1E8.sub_00065550(0, (int)DAT_004106B8, (int)sub_0018A560, 0, 1, 1);
}
