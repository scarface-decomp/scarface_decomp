// bin: xb
// va: 0x00312FB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312FB0 (0x00312FB0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0041C3B4[];
extern "C" Object DAT_00474AB0;
extern "C" char sub_0029A2E0[];

void __cdecl sub_00312FB0(void)
{
    DAT_00474AB0.sub_0006F740(0, (int)DAT_0041C3B4, (int)sub_0029A2E0, 0, 1, 1);
}
