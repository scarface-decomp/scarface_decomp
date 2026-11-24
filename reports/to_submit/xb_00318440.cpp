// bin: xb
// va: 0x00318440
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318440 (0x00318440, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0042FBAC[];
extern "C" char DAT_0042FBC0[];
extern "C" Object DAT_0048B0A8;
extern "C" char sub_001780D0[];

void __cdecl sub_00318440(void)
{
    DAT_0048B0A8.sub_0006F790((int)DAT_0042FBC0, (int)DAT_0042FBAC, (int)sub_001780D0, 0, 3, 4);
}
