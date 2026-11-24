// bin: proto
// va: 0x002E13D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E13D0 (Proto 0x002E13D0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_0037F850[];
extern "C" Object DAT_0044A38C;
extern "C" char sub_00043710[];

void __cdecl sub_002E13D0(void)
{
    DAT_0044A38C.sub_000D8CC0(9, 0, 0, 50, 42, (int)DAT_0037F850, (int)sub_00043710, 509, 3, 1);
}
