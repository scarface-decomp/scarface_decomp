// bin: proto
// va: 0x002E19A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E19A0 (Proto 0x002E19A0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003816FC[];
extern "C" Object DAT_0044B590;
extern "C" char sub_0005E310[];

void __cdecl sub_002E19A0(void)
{
    DAT_0044B590.sub_000D8CC0(3, 18, 33, 69, 45, (int)DAT_003816FC, (int)sub_0005E310, 196, 0, 0);
}
