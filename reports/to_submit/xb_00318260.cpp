// bin: xb
// va: 0x00318260
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318260 (0x00318260, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042F8F8[];
extern "C" Object DAT_0048AE68;
extern "C" char sub_00177E80[];

void __cdecl sub_00318260(void)
{
    DAT_0048AE68.sub_0006F830(0, (int)DAT_0042F8F8, (int)sub_00177E80, 0, 1, 1);
}
