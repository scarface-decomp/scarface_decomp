// bin: proto
// va: 0x002E1980
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1980 (Proto 0x002E1980, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8D30(int, int, int);
};

extern "C" Object DAT_0044AF51;
extern "C" char sub_0005D050[];

void __cdecl sub_002E1980(void)
{
    DAT_0044AF51.sub_000D8D30(44, (int)sub_0005D050, 0);
}
