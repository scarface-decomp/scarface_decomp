// bin: proto
// va: 0x002E0280
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0280 (Proto 0x002E0280, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F4E18[];
extern "C" char DAT_003F4E20[];
extern "C" Object DAT_00446880;
extern "C" char sub_0001E700[];

void __cdecl sub_002E0280(void)
{
    DAT_00446880.sub_00065550((int)DAT_003F4E20, (int)DAT_003F4E18, (int)sub_0001E700, 0, 5, 6);
}
