// bin: xb
// va: 0x0031AB00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031AB00 (0x0031AB00, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00437CA8[];
extern "C" char DAT_00437CB0[];
extern "C" Object DAT_0048E348;
extern "C" char sub_001BF770[];

void __cdecl sub_0031AB00(void)
{
    DAT_0048E348.sub_0006F830((int)DAT_00437CB0, (int)DAT_00437CA8, (int)sub_001BF770, 0, 3, 3);
}
