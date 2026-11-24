// bin: xb
// va: 0x00313F20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313F20 (0x00313F20, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0041EFD8[];
extern "C" Object DAT_0047AF78;
extern "C" char sub_00070D00[];

void __cdecl sub_00313F20(void)
{
    DAT_0047AF78.sub_0006F790(0, (int)DAT_0041EFD8, (int)sub_00070D00, 0, 2, 2);
}
