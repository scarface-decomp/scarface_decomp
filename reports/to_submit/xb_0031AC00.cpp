// bin: xb
// va: 0x0031AC00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031AC00 (0x0031AC00, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00437E4C[];
extern "C" char DAT_00437E5C[];
extern "C" Object DAT_0048E424;
extern "C" char sub_001BF9B0[];

void __cdecl sub_0031AC00(void)
{
    DAT_0048E424.sub_0006F830((int)DAT_00437E5C, (int)DAT_00437E4C, (int)sub_001BF9B0, 0, 9, 9);
}
