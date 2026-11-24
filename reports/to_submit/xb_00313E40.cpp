// bin: xb
// va: 0x00313E40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313E40 (0x00313E40, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0041EF84[];
extern "C" Object DAT_0047AE44;
extern "C" char sub_00071720[];

void __cdecl sub_00313E40(void)
{
    DAT_0047AE44.sub_0006F740(0, (int)DAT_0041EF84, (int)sub_00071720, 0, 4, 4);
}
