// bin: proto
// va: 0x002E6270
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6270 (Proto 0x002E6270, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040B22C[];
extern "C" char DAT_0040B24C[];
extern "C" Object DAT_0045D1FC;
extern "C" char sub_00158C30[];

void __cdecl sub_002E6270(void)
{
    DAT_0045D1FC.sub_00065550((int)DAT_0040B24C, (int)DAT_0040B22C, (int)sub_00158C30, 0, 5, 11);
}
