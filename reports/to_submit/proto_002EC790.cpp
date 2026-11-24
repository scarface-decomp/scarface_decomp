// bin: proto
// va: 0x002EC790
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC790 (Proto 0x002EC790, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003AB1A0[];
extern "C" Object DAT_00462EBC;
extern "C" char sub_001E6750[];

void __cdecl sub_002EC790(void)
{
    DAT_00462EBC.sub_000D8CC0(42, 29, 16, 66, 12, (int)DAT_003AB1A0, (int)sub_001E6750, 80, 0, 0);
}
