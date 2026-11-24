// bin: xb
// va: 0x00313790
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313790 (0x00313790, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0041DE00[];
extern "C" Object DAT_00475DC0;
extern "C" char sub_000608C0[];

void __cdecl sub_00313790(void)
{
    DAT_00475DC0.sub_0006F880(0, (int)DAT_0041DE00, (int)sub_000608C0, 0, 3, 3);
}
