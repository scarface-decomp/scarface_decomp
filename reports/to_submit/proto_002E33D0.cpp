// bin: proto
// va: 0x002E33D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E33D0 (Proto 0x002E33D0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003847E4[];
extern "C" Object DAT_00459510;
extern "C" char sub_000B8B40[];

void __cdecl sub_002E33D0(void)
{
    DAT_00459510.sub_000D8CC0(12, 42, 27, 88, 52, (int)DAT_003847E4, (int)sub_000B8B40, 197, 0, 1);
}
