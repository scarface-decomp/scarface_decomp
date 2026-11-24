// bin: xb
// va: 0x0031BF10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031BF10 (0x0031BF10, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0043B3A4[];
extern "C" Object DAT_0048F1D8;
extern "C" char sub_001D6CC0[];

void __cdecl sub_0031BF10(void)
{
    DAT_0048F1D8.sub_0006F880(0, (int)DAT_0043B3A4, (int)sub_001D6CC0, 0, 1, 1);
}
