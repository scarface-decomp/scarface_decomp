// bin: proto
// va: 0x002E36E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E36E0 (Proto 0x002E36E0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FF900[];
extern "C" Object DAT_0045982C;
extern "C" char sub_000BE770[];

void __cdecl sub_002E36E0(void)
{
    DAT_0045982C.sub_00065550(0, (int)DAT_003FF900, (int)sub_000BE770, 0, 2, 11);
}
