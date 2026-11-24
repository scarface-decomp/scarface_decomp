// bin: proto
// va: 0x002E66D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E66D0 (Proto 0x002E66D0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040B6F8[];
extern "C" char DAT_0040B714[];
extern "C" Object DAT_0045D800;
extern "C" char sub_00158500[];

void __cdecl sub_002E66D0(void)
{
    DAT_0045D800.sub_00065550((int)DAT_0040B714, (int)DAT_0040B6F8, (int)sub_00158500, 0, 3, 3);
}
