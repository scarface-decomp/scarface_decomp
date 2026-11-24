// bin: proto
// va: 0x002E8D70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8D70 (Proto 0x002E8D70, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00413B98[];
extern "C" char DAT_00413BA4[];
extern "C" Object DAT_00460308;
extern "C" char sub_0019AD40[];

void __cdecl sub_002E8D70(void)
{
    DAT_00460308.sub_00065550((int)DAT_00413BA4, (int)DAT_00413B98, (int)sub_0019AD40, 0, 2, 2);
}
