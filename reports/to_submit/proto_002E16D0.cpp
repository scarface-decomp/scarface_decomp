// bin: proto
// va: 0x002E16D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E16D0 (Proto 0x002E16D0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F8A9C[];
extern "C" Object DAT_0044A6EC;
extern "C" char sub_00055E60[];

void __cdecl sub_002E16D0(void)
{
    DAT_0044A6EC.sub_00065550(0, (int)DAT_003F8A9C, (int)sub_00055E60, 0, 3, 3);
}
