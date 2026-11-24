// bin: proto
// va: 0x002E1EF0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1EF0 (Proto 0x002E1EF0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_003F9C64[];
extern "C" Object DAT_0044F924;
extern "C" char sub_000673A0[];

void __cdecl sub_002E1EF0(void)
{
    DAT_0044F924.sub_00065460(0, (int)DAT_003F9C64, (int)sub_000673A0, 0, 4, 4);
}
