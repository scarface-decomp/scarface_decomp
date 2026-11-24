// bin: xb
// va: 0x0031A6E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A6E0 (0x0031A6E0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_00437700[];
extern "C" Object DAT_0048DED0;
extern "C" char sub_001BEE70[];

void __cdecl sub_0031A6E0(void)
{
    DAT_0048DED0.sub_0006F880(0, (int)DAT_00437700, (int)sub_001BEE70, 0, 2, 2);
}
