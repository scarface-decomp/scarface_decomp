// bin: proto
// va: 0x002E0DB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0DB0 (Proto 0x002E0DB0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F6CF0[];
extern "C" char DAT_003F6CFC[];
extern "C" Object DAT_00449860;
extern "C" char sub_0002B400[];

void __cdecl sub_002E0DB0(void)
{
    DAT_00449860.sub_00065550((int)DAT_003F6CFC, (int)DAT_003F6CF0, (int)sub_0002B400, 0, 3, 3);
}
