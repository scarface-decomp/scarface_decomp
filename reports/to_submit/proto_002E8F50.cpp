// bin: proto
// va: 0x002E8F50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8F50 (Proto 0x002E8F50, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0041425C[];
extern "C" char DAT_00414264[];
extern "C" Object DAT_00460494;
extern "C" char sub_0019B930[];

void __cdecl sub_002E8F50(void)
{
    DAT_00460494.sub_00065550((int)DAT_00414264, (int)DAT_0041425C, (int)sub_0019B930, 0, 5, 5);
}
