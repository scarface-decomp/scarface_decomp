// bin: xb
// va: 0x0031A700
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A700 (0x0031A700, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_00437710[];
extern "C" Object DAT_0048DEFC;
extern "C" char sub_001BEE90[];

void __cdecl sub_0031A700(void)
{
    DAT_0048DEFC.sub_0006F880(0, (int)DAT_00437710, (int)sub_001BEE90, 0, 2, 2);
}
