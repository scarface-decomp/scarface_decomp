// bin: proto
// va: 0x002ECEF0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ECEF0 (Proto 0x002ECEF0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_00427DA8[];
extern "C" Object DAT_00463530;
extern "C" char sub_001EF8E0[];

void __cdecl sub_002ECEF0(void)
{
    DAT_00463530.sub_000655A0(0, (int)DAT_00427DA8, (int)sub_001EF8E0, 0, 1, 1);
}
