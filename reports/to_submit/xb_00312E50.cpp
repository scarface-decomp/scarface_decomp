// bin: xb
// va: 0x00312E50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312E50 (0x00312E50, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0041C2B4[];
extern "C" Object DAT_004748CC;
extern "C" char sub_0029A2E0[];

void __cdecl sub_00312E50(void)
{
    DAT_004748CC.sub_0006F740(0, (int)DAT_0041C2B4, (int)sub_0029A2E0, 0, 1, 2);
}
