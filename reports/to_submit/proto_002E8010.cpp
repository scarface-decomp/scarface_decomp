// bin: proto
// va: 0x002E8010
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8010 (Proto 0x002E8010, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_004115AC[];
extern "C" Object DAT_0045FB04;
extern "C" char sub_0018B950[];

void __cdecl sub_002E8010(void)
{
    DAT_0045FB04.sub_000655A0(0, (int)DAT_004115AC, (int)sub_0018B950, 0, 7, 7);
}
