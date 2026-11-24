// bin: xb
// va: 0x0031A800
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A800 (0x0031A800, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004377C0[];
extern "C" char DAT_004377D4[];
extern "C" Object DAT_0048E030;
extern "C" char sub_001BEF40[];

void __cdecl sub_0031A800(void)
{
    DAT_0048E030.sub_0006F830((int)DAT_004377D4, (int)DAT_004377C0, (int)sub_001BEF40, 0, 8, 8);
}
