// bin: proto
// va: 0x002E1BD0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1BD0 (Proto 0x002E1BD0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F96D0[];
extern "C" Object DAT_0044B858;
extern "C" char sub_0005E900[];

void __cdecl sub_002E1BD0(void)
{
    DAT_0044B858.sub_00065550(0, (int)DAT_003F96D0, (int)sub_0005E900, 0, 2, 2);
}
