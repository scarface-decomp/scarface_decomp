// bin: xb
// va: 0x00313770
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313770 (0x00313770, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0041DDF0[];
extern "C" Object DAT_00475D94;
extern "C" char sub_000608A0[];

void __cdecl sub_00313770(void)
{
    DAT_00475D94.sub_0006F790(0, (int)DAT_0041DDF0, (int)sub_000608A0, 0, 2, 2);
}
