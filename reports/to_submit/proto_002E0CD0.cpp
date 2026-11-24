// bin: proto
// va: 0x002E0CD0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0CD0 (Proto 0x002E0CD0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F6C2C[];
extern "C" char DAT_003F6C40[];
extern "C" Object DAT_0044972C;
extern "C" char sub_0002B360[];

void __cdecl sub_002E0CD0(void)
{
    DAT_0044972C.sub_00065550((int)DAT_003F6C40, (int)DAT_003F6C2C, (int)sub_0002B360, 0, 2, 2);
}
