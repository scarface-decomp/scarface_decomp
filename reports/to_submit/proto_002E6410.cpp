// bin: proto
// va: 0x002E6410
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6410 (Proto 0x002E6410, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040B3E8[];
extern "C" char DAT_0040B404[];
extern "C" Object DAT_0045D438;
extern "C" char sub_00158300[];

void __cdecl sub_002E6410(void)
{
    DAT_0045D438.sub_00065550((int)DAT_0040B404, (int)DAT_0040B3E8, (int)sub_00158300, 0, 3, 3);
}
