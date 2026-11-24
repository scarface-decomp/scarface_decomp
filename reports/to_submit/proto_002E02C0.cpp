// bin: proto
// va: 0x002E02C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E02C0 (Proto 0x002E02C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F4E4C[];
extern "C" char DAT_003F4E5C[];
extern "C" Object DAT_004468D8;
extern "C" char sub_0001E7B0[];

void __cdecl sub_002E02C0(void)
{
    DAT_004468D8.sub_00065550((int)DAT_003F4E5C, (int)DAT_003F4E4C, (int)sub_0001E7B0, 0, 5, 5);
}
