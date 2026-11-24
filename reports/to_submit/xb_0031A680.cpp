// bin: xb
// va: 0x0031A680
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A680 (0x0031A680, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_00437678[];
extern "C" Object DAT_0048DE78;
extern "C" char sub_0027A200[];

void __cdecl sub_0031A680(void)
{
    DAT_0048DE78.sub_0006F790(0, (int)DAT_00437678, (int)sub_0027A200, 0, 1, 1);
}
