// bin: xb
// va: 0x00313E20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313E20 (0x00313E20, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0041EF78[];
extern "C" Object DAT_0047AE18;
extern "C" char sub_000716D0[];

void __cdecl sub_00313E20(void)
{
    DAT_0047AE18.sub_0006F740(0, (int)DAT_0041EF78, (int)sub_000716D0, 0, 3, 4);
}
