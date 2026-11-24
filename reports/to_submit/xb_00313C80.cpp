// bin: xb
// va: 0x00313C80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313C80 (0x00313C80, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0041EF00[];
extern "C" Object DAT_0047ABDC;
extern "C" char sub_00070F10[];

void __cdecl sub_00313C80(void)
{
    DAT_0047ABDC.sub_0006F790(0, (int)DAT_0041EF00, (int)sub_00070F10, 0, 4, 4);
}
