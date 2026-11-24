// bin: proto
// va: 0x002E3600
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3600 (Proto 0x002E3600, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FF618[];
extern "C" Object DAT_00459784;
extern "C" char sub_000BB150[];

void __cdecl sub_002E3600(void)
{
    DAT_00459784.sub_00065550(0, (int)DAT_003FF618, (int)sub_000BB150, 0, 2, 2);
}
