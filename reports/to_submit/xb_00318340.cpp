// bin: xb
// va: 0x00318340
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318340 (0x00318340, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0042FA88[];
extern "C" char DAT_0042FA98[];
extern "C" Object DAT_0048AF48;
extern "C" char sub_00178040[];

void __cdecl sub_00318340(void)
{
    DAT_0048AF48.sub_0006F880((int)DAT_0042FA98, (int)DAT_0042FA88, (int)sub_00178040, 0, 2, 2);
}
