// bin: xb
// va: 0x00313E80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313E80 (0x00313E80, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0041EF98[];
extern "C" Object DAT_0047AE9C;
extern "C" char sub_00070CE0[];

void __cdecl sub_00313E80(void)
{
    DAT_0047AE9C.sub_0006F790(0, (int)DAT_0041EF98, (int)sub_00070CE0, 0, 2, 2);
}
