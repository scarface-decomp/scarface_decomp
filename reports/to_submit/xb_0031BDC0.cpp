// bin: xb
// va: 0x0031BDC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031BDC0 (0x0031BDC0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043B064[];
extern "C" Object DAT_0048F084;
extern "C" char sub_001D35B0[];

void __cdecl sub_0031BDC0(void)
{
    DAT_0048F084.sub_0006F830(0, (int)DAT_0043B064, (int)sub_001D35B0, 0, 1, 1);
}
