// bin: proto
// va: 0x002E3130
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3130 (Proto 0x002E3130, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065500(int, int, int, int, int, int);
};

extern "C" char DAT_003FE938[];
extern "C" Object DAT_004541F4;
extern "C" char sub_0008D510[];

void __cdecl sub_002E3130(void)
{
    DAT_004541F4.sub_00065500(0, (int)DAT_003FE938, (int)sub_0008D510, 0, 1, 1);
}
