// bin: proto
// va: 0x002DFE50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002DFE50 (Proto 0x002DFE50, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_0037CFA4[];
extern "C" Object DAT_00446528;
extern "C" char sub_00017940[];

void __cdecl sub_002DFE50(void)
{
    DAT_00446528.sub_000D8CC0(21, 24, 10, 59, 31, (int)DAT_0037CFA4, (int)sub_00017940, 64, 0, 0);
}
