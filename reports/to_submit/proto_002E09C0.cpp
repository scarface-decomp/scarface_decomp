// bin: proto
// va: 0x002E09C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E09C0 (Proto 0x002E09C0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_0037E9D8[];
extern "C" Object DAT_004493D8;
extern "C" char sub_00026930[];

void __cdecl sub_002E09C0(void)
{
    DAT_004493D8.sub_000D8CC0(15, 20, 6, 55, 37, (int)DAT_0037E9D8, (int)sub_00026930, 96, 0, 1);
}
