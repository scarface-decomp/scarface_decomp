// bin: proto
// va: 0x002E2130
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2130 (Proto 0x002E2130, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_003F9D44[];
extern "C" Object DAT_0044FC3C;
extern "C" char sub_00067780[];

void __cdecl sub_002E2130(void)
{
    DAT_0044FC3C.sub_00065460(0, (int)DAT_003F9D44, (int)sub_00067780, 0, 2, 2);
}
