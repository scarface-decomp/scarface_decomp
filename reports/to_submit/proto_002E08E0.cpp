// bin: proto
// va: 0x002E08E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E08E0 (Proto 0x002E08E0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F5B74[];
extern "C" Object DAT_00446EB8;
extern "C" char sub_00023030[];

void __cdecl sub_002E08E0(void)
{
    DAT_00446EB8.sub_00065550(0, (int)DAT_003F5B74, (int)sub_00023030, 0, 2, 3);
}
