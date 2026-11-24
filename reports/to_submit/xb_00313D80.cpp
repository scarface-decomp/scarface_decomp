// bin: xb
// va: 0x00313D80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313D80 (0x00313D80, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0041EF44[];
extern "C" Object DAT_0047AD3C;
extern "C" char sub_00071120[];

void __cdecl sub_00313D80(void)
{
    DAT_0047AD3C.sub_0006F740(0, (int)DAT_0041EF44, (int)sub_00071120, 0, 3, 3);
}
