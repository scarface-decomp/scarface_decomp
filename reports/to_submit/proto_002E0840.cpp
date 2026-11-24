// bin: proto
// va: 0x002E0840
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0840 (Proto 0x002E0840, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F5AF8[];
extern "C" char DAT_003F5B00[];
extern "C" Object DAT_00446DDC;
extern "C" char sub_00022F60[];

void __cdecl sub_002E0840(void)
{
    DAT_00446DDC.sub_00065550((int)DAT_003F5B00, (int)DAT_003F5AF8, (int)sub_00022F60, 0, 3, 4);
}
