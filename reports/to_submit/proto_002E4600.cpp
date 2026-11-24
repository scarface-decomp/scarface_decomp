// bin: proto
// va: 0x002E4600
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4600 (Proto 0x002E4600, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040235C[];
extern "C" Object DAT_0045B530;
extern "C" char sub_000DB4B0[];

void __cdecl sub_002E4600(void)
{
    DAT_0045B530.sub_00065550(0, (int)DAT_0040235C, (int)sub_000DB4B0, 0, 3, 4);
}
