// bin: xb
// va: 0x0031ABC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031ABC0 (0x0031ABC0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00437E0C[];
extern "C" char DAT_00437E20[];
extern "C" Object DAT_0048E3CC;
extern "C" char sub_001BF8E0[];

void __cdecl sub_0031ABC0(void)
{
    DAT_0048E3CC.sub_0006F830((int)DAT_00437E20, (int)DAT_00437E0C, (int)sub_001BF8E0, 0, 6, 7);
}
