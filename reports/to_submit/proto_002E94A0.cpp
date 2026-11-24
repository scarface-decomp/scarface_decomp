// bin: proto
// va: 0x002E94A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E94A0 (Proto 0x002E94A0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_00414FC8[];
extern "C" char DAT_00414FD8[];
extern "C" Object DAT_004609AC;
extern "C" char sub_0019F770[];

void __cdecl sub_002E94A0(void)
{
    DAT_004609AC.sub_000654B0((int)DAT_00414FD8, (int)DAT_00414FC8, (int)sub_0019F770, 0, 2, 2);
}
