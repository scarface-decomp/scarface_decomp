// bin: xb
// va: 0x00313F80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313F80 (0x00313F80, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0041F000[];
extern "C" Object DAT_0047AFFC;
extern "C" char sub_000718E0[];

void __cdecl sub_00313F80(void)
{
    DAT_0047AFFC.sub_0006F740(0, (int)DAT_0041F000, (int)sub_000718E0, 0, 4, 4);
}
