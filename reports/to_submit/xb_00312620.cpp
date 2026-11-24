// bin: xb
// va: 0x00312620
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312620 (0x00312620, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041AA50[];
extern "C" Object DAT_00471928;
extern "C" char sub_00024BE0[];

void __cdecl sub_00312620(void)
{
    DAT_00471928.sub_0006F830(0, (int)DAT_0041AA50, (int)sub_00024BE0, 0, 1, 2);
}
