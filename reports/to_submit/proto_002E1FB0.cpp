// bin: proto
// va: 0x002E1FB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1FB0 (Proto 0x002E1FB0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_003F9CAC[];
extern "C" Object DAT_0044FA2C;
extern "C" char sub_000674B0[];

void __cdecl sub_002E1FB0(void)
{
    DAT_0044FA2C.sub_00065460(0, (int)DAT_003F9CAC, (int)sub_000674B0, 0, 3, 3);
}
