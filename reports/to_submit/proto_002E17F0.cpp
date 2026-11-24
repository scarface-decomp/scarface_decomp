// bin: proto
// va: 0x002E17F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E17F0 (Proto 0x002E17F0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F8B50[];
extern "C" Object DAT_0044A878;
extern "C" char sub_00055F60[];

void __cdecl sub_002E17F0(void)
{
    DAT_0044A878.sub_00065550(0, (int)DAT_003F8B50, (int)sub_00055F60, 0, 2, 2);
}
