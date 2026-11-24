// bin: proto
// va: 0x002E11F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E11F0 (Proto 0x002E11F0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F74F0[];
extern "C" Object DAT_00449F98;
extern "C" char sub_00039110[];

void __cdecl sub_002E11F0(void)
{
    DAT_00449F98.sub_00065550(0, (int)DAT_003F74F0, (int)sub_00039110, 0, 2, 2);
}
