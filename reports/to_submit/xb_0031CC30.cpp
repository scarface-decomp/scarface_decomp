// bin: xb
// va: 0x0031CC30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031CC30 (0x0031CC30, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0043E904[];
extern "C" char DAT_0043E920[];
extern "C" Object DAT_0048FC10;
extern "C" char sub_001EEA00[];

void __cdecl sub_0031CC30(void)
{
    DAT_0048FC10.sub_0006F790((int)DAT_0043E920, (int)DAT_0043E904, (int)sub_001EEA00, 0, 2, 2);
}
