// bin: xb
// va: 0x00312280
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312280 (0x00312280, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041A060[];
extern "C" Object DAT_00471684;
extern "C" char sub_00020AA0[];

void __cdecl sub_00312280(void)
{
    DAT_00471684.sub_0006F830(0, (int)DAT_0041A060, (int)sub_00020AA0, 0, 2, 2);
}
