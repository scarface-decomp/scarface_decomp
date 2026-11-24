// bin: proto
// va: 0x002E0D90
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0D90 (Proto 0x002E0D90, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F6CD0[];
extern "C" char DAT_003F6CE0[];
extern "C" Object DAT_00449834;
extern "C" char sub_0002B3B0[];

void __cdecl sub_002E0D90(void)
{
    DAT_00449834.sub_00065550((int)DAT_003F6CE0, (int)DAT_003F6CD0, (int)sub_0002B3B0, 0, 3, 5);
}
