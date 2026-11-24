// bin: xb
// va: 0x00318BC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318BC0 (0x00318BC0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_00430404[];
extern "C" char DAT_00430420[];
extern "C" Object DAT_0048BAF8;
extern "C" char sub_00178810[];

void __cdecl sub_00318BC0(void)
{
    DAT_0048BAF8.sub_0006F880((int)DAT_00430420, (int)DAT_00430404, (int)sub_00178810, 0, 3, 3);
}
