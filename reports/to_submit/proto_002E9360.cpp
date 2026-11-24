// bin: proto
// va: 0x002E9360
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9360 (Proto 0x002E9360, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_00414EDC[];
extern "C" char DAT_00414EE8[];
extern "C" Object DAT_00460820;
extern "C" char sub_0019F680[];

void __cdecl sub_002E9360(void)
{
    DAT_00460820.sub_000654B0((int)DAT_00414EE8, (int)DAT_00414EDC, (int)sub_0019F680, 0, 3, 3);
}
