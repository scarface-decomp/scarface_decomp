// bin: proto
// va: 0x002E2520
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2520 (Proto 0x002E2520, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_003FCF90[];
extern "C" Object DAT_00453354;
extern "C" char sub_0006C730[];

void __cdecl sub_002E2520(void)
{
    DAT_00453354.sub_000655A0(0, (int)DAT_003FCF90, (int)sub_0006C730, 0, 1, 1);
}
