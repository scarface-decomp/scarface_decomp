// bin: proto
// va: 0x002E94C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E94C0 (Proto 0x002E94C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00414FE4[];
extern "C" char DAT_00414FF0[];
extern "C" Object DAT_004609D8;
extern "C" char sub_0019F5E0[];

void __cdecl sub_002E94C0(void)
{
    DAT_004609D8.sub_00065550((int)DAT_00414FF0, (int)DAT_00414FE4, (int)sub_0019F5E0, 0, 3, 3);
}
