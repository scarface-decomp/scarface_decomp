// bin: xb
// va: 0x00318480
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318480 (0x00318480, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0042FBEC[];
extern "C" char DAT_0042FBFC[];
extern "C" Object DAT_0048B100;
extern "C" char sub_00178170[];

void __cdecl sub_00318480(void)
{
    DAT_0048B100.sub_0006F790((int)DAT_0042FBFC, (int)DAT_0042FBEC, (int)sub_00178170, 0, 2, 2);
}
