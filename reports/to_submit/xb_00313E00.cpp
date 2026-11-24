// bin: xb
// va: 0x00313E00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313E00 (0x00313E00, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0041EF70[];
extern "C" Object DAT_0047ADEC;
extern "C" char sub_000716A0[];

void __cdecl sub_00313E00(void)
{
    DAT_0047ADEC.sub_0006F740(0, (int)DAT_0041EF70, (int)sub_000716A0, 0, 3, 3);
}
