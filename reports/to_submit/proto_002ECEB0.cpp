// bin: proto
// va: 0x002ECEB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ECEB0 (Proto 0x002ECEB0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00427D88[];
extern "C" Object DAT_004634D8;
extern "C" char sub_001EF920[];

void __cdecl sub_002ECEB0(void)
{
    DAT_004634D8.sub_00065550(0, (int)DAT_00427D88, (int)sub_001EF920, 0, 2, 6);
}
