// bin: xb
// va: 0x00313690
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313690 (0x00313690, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041DD68[];
extern "C" Object DAT_00475C60;
extern "C" char sub_000607E0[];

void __cdecl sub_00313690(void)
{
    DAT_00475C60.sub_0006F830(0, (int)DAT_0041DD68, (int)sub_000607E0, 0, 2, 2);
}
