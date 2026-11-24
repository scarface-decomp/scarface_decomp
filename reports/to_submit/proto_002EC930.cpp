// bin: proto
// va: 0x002EC930
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC930 (Proto 0x002EC930, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003AB5B8[];
extern "C" Object DAT_00462F4A;
extern "C" char sub_001EBC00[];

void __cdecl sub_002EC930(void)
{
    DAT_00462F4A.sub_000D8CC0(4, 4, 47, 84, 7, (int)DAT_003AB5B8, (int)sub_001EBC00, 8, 0, 1);
}
