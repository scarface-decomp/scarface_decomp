// bin: xb
// va: 0x00318620
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318620 (0x00318620, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0042FDB8[];
extern "C" char DAT_0042FDC8[];
extern "C" Object DAT_0048B33C;
extern "C" char sub_00178250[];

void __cdecl sub_00318620(void)
{
    DAT_0048B33C.sub_0006F880((int)DAT_0042FDC8, (int)DAT_0042FDB8, (int)sub_00178250, 0, 2, 2);
}
