// bin: proto
// va: 0x002E3500
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3500 (Proto 0x002E3500, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_003FF41C[];
extern "C" char DAT_003FF430[];
extern "C" Object DAT_00459624;
extern "C" char sub_000BACE0[];

void __cdecl sub_002E3500(void)
{
    DAT_00459624.sub_000655A0((int)DAT_003FF430, (int)DAT_003FF41C, (int)sub_000BACE0, 0, 2, 2);
}
