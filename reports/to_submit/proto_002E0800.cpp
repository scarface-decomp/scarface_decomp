// bin: proto
// va: 0x002E0800
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0800 (Proto 0x002E0800, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F5AC0[];
extern "C" char DAT_003F5ACC[];
extern "C" Object DAT_00446D84;
extern "C" char sub_00022F10[];

void __cdecl sub_002E0800(void)
{
    DAT_00446D84.sub_00065550((int)DAT_003F5ACC, (int)DAT_003F5AC0, (int)sub_00022F10, 0, 4, 4);
}
