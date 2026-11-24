// bin: proto
// va: 0x002E20B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E20B0 (Proto 0x002E20B0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_003F9D18[];
extern "C" Object DAT_0044FB8C;
extern "C" char sub_00067620[];

void __cdecl sub_002E20B0(void)
{
    DAT_0044FB8C.sub_00065460(0, (int)DAT_003F9D18, (int)sub_00067620, 0, 2, 2);
}
