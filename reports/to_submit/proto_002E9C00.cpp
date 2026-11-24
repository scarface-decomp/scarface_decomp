// bin: proto
// va: 0x002E9C00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9C00 (Proto 0x002E9C00, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065500(int, int, int, int, int, int);
};

extern "C" char DAT_00417B18[];
extern "C" char DAT_00417B2C[];
extern "C" Object DAT_00460E20;
extern "C" char sub_001B4380[];

void __cdecl sub_002E9C00(void)
{
    DAT_00460E20.sub_00065500((int)DAT_00417B2C, (int)DAT_00417B18, (int)sub_001B4380, 0, 2, 2);
}
