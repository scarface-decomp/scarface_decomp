// bin: proto
// va: 0x002E9C20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9C20 (Proto 0x002E9C20, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00417B3C[];
extern "C" char DAT_00417B4C[];
extern "C" Object DAT_00460E4C;
extern "C" char sub_001B4390[];

void __cdecl sub_002E9C20(void)
{
    DAT_00460E4C.sub_00065550((int)DAT_00417B4C, (int)DAT_00417B3C, (int)sub_001B4390, 0, 2, 2);
}
