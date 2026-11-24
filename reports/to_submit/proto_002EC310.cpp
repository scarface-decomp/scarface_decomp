// bin: proto
// va: 0x002EC310
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC310 (Proto 0x002EC310, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_00427548[];
extern "C" Object DAT_00462CA0;
extern "C" char sub_001E5BB0[];

void __cdecl sub_002EC310(void)
{
    DAT_00462CA0.sub_000655A0(0, (int)DAT_00427548, (int)sub_001E5BB0, 0, 1, 1);
}
