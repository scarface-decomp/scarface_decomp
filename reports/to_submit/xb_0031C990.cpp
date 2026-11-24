// bin: xb
// va: 0x0031C990
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031C990 (0x0031C990, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043E2CC[];
extern "C" char DAT_0043E2E0[];
extern "C" Object DAT_0048F978;
extern "C" char sub_001CE090[];

void __cdecl sub_0031C990(void)
{
    DAT_0048F978.sub_0006F830((int)DAT_0043E2E0, (int)DAT_0043E2CC, (int)sub_001CE090, 0, 2, 2);
}
