// bin: xb
// va: 0x00318900
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318900 (0x00318900, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004300E0[];
extern "C" char DAT_004300FC[];
extern "C" Object DAT_0048B730;
extern "C" char sub_00178530[];

void __cdecl sub_00318900(void)
{
    DAT_0048B730.sub_0006F830((int)DAT_004300FC, (int)DAT_004300E0, (int)sub_00178530, 0, 3, 3);
}
