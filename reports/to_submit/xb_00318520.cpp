// bin: xb
// va: 0x00318520
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318520 (0x00318520, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0042FCA4[];
extern "C" char DAT_0042FCC0[];
extern "C" Object DAT_0048B1DC;
extern "C" char sub_001781D0[];

void __cdecl sub_00318520(void)
{
    DAT_0048B1DC.sub_0006F880((int)DAT_0042FCC0, (int)DAT_0042FCA4, (int)sub_001781D0, 0, 2, 2);
}
