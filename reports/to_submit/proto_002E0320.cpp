// bin: proto
// va: 0x002E0320
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0320 (Proto 0x002E0320, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F4E94[];
extern "C" char DAT_003F4E98[];
extern "C" Object DAT_0044695C;
extern "C" char sub_0001E840[];

void __cdecl sub_002E0320(void)
{
    DAT_0044695C.sub_00065550((int)DAT_003F4E98, (int)DAT_003F4E94, (int)sub_0001E840, 0, 2, 2);
}
