// bin: proto
// va: 0x002E11D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E11D0 (Proto 0x002E11D0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F74D0[];
extern "C" Object DAT_00449F6C;
extern "C" char sub_000390E0[];

void __cdecl sub_002E11D0(void)
{
    DAT_00449F6C.sub_00065550(0, (int)DAT_003F74D0, (int)sub_000390E0, 0, 2, 2);
}
