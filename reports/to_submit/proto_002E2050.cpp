// bin: proto
// va: 0x002E2050
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2050 (Proto 0x002E2050, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_003F9CEC[];
extern "C" Object DAT_0044FB08;
extern "C" char sub_00067590[];

void __cdecl sub_002E2050(void)
{
    DAT_0044FB08.sub_00065460(0, (int)DAT_003F9CEC, (int)sub_00067590, 0, 3, 3);
}
