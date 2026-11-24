// bin: xb
// va: 0x00316730
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316730 (0x00316730, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00427908[];
extern "C" Object DAT_0048932C;
extern "C" char sub_000EEBF0[];

void __cdecl sub_00316730(void)
{
    DAT_0048932C.sub_0006F830(0, (int)DAT_00427908, (int)sub_000EEBF0, 0, 2, 2);
}
