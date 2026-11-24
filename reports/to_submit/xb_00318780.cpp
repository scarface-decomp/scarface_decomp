// bin: xb
// va: 0x00318780
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318780 (0x00318780, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0042FF60[];
extern "C" char DAT_0042FF74[];
extern "C" Object DAT_0048B520;
extern "C" char sub_00178EE0[];

void __cdecl sub_00318780(void)
{
    DAT_0048B520.sub_0006F790((int)DAT_0042FF74, (int)DAT_0042FF60, (int)sub_00178EE0, 0, 2, 2);
}
