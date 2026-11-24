// bin: proto
// va: 0x002E3660
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3660 (Proto 0x002E3660, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_00384CD4[];
extern "C" Object DAT_00459814;
extern "C" char sub_000BBC60[];

void __cdecl sub_002E3660(void)
{
    DAT_00459814.sub_000D8CC0(32, 25, 11, 60, 21, (int)DAT_00384CD4, (int)sub_000BBC60, 509, 3, 1);
}
