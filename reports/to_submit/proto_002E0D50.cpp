// bin: proto
// va: 0x002E0D50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0D50 (Proto 0x002E0D50, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_003F6CA0[];
extern "C" char DAT_003F6CAC[];
extern "C" Object DAT_004497DC;
extern "C" char sub_0002B6F0[];

void __cdecl sub_002E0D50(void)
{
    DAT_004497DC.sub_00065460((int)DAT_003F6CAC, (int)DAT_003F6CA0, (int)sub_0002B6F0, 0, 2, 2);
}
