// bin: proto
// va: 0x002E0CB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0CB0 (Proto 0x002E0CB0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F6C0C[];
extern "C" char DAT_003F6C1C[];
extern "C" Object DAT_00449700;
extern "C" char sub_0002B320[];

void __cdecl sub_002E0CB0(void)
{
    DAT_00449700.sub_00065550((int)DAT_003F6C1C, (int)DAT_003F6C0C, (int)sub_0002B320, 0, 2, 3);
}
