// bin: proto
// va: 0x002E3520
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3520 (Proto 0x002E3520, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_003FF444[];
extern "C" char DAT_003FF458[];
extern "C" Object DAT_00459650;
extern "C" char sub_000BACF0[];

void __cdecl sub_002E3520(void)
{
    DAT_00459650.sub_000655A0((int)DAT_003FF458, (int)DAT_003FF444, (int)sub_000BACF0, 0, 2, 2);
}
