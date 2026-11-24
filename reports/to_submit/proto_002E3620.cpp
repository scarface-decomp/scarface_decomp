// bin: proto
// va: 0x002E3620
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3620 (Proto 0x002E3620, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_003FF640[];
extern "C" Object DAT_004597B0;
extern "C" char sub_000BB170[];

void __cdecl sub_002E3620(void)
{
    DAT_004597B0.sub_000655A0(0, (int)DAT_003FF640, (int)sub_000BB170, 0, 1, 1);
}
