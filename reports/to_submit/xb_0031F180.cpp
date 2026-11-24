// bin: xb
// va: 0x0031F180
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F180 (0x0031F180, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044D9C4[];
extern "C" Object DAT_004918FC;
extern "C" char sub_00222AD0[];

void __cdecl sub_0031F180(void)
{
    DAT_004918FC.sub_0006F830(0, (int)DAT_0044D9C4, (int)sub_00222AD0, 0, 2, 2);
}
