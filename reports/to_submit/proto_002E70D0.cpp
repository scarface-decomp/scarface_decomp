// bin: proto
// va: 0x002E70D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E70D0 (Proto 0x002E70D0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003985E8[];
extern "C" Object DAT_0045E080;
extern "C" char sub_0016F750[];

void __cdecl sub_002E70D0(void)
{
    DAT_0045E080.sub_000D8CC0(50, 36, 7, 81, 1, (int)DAT_003985E8, (int)sub_0016F750, 509, 0, 1);
}
