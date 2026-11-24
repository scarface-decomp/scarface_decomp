// bin: proto
// va: 0x002E0860
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0860 (Proto 0x002E0860, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F5B10[];
extern "C" char DAT_003F5B1C[];
extern "C" Object DAT_00446E08;
extern "C" char sub_00022F90[];

void __cdecl sub_002E0860(void)
{
    DAT_00446E08.sub_00065550((int)DAT_003F5B1C, (int)DAT_003F5B10, (int)sub_00022F90, 0, 3, 3);
}
