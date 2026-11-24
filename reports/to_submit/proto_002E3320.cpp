// bin: proto
// va: 0x002E3320
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3320 (Proto 0x002E3320, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_00383E44[];
extern "C" Object DAT_00458DA8;
extern "C" char sub_0008F210[];

void __cdecl sub_002E3320(void)
{
    DAT_00458DA8.sub_000D8CC0(38, 26, 25, 63, 14, (int)DAT_00383E44, (int)sub_0008F210, 80, 3, 0);
}
