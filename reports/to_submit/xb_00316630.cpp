// bin: xb
// va: 0x00316630
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316630 (0x00316630, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0042784C[];
extern "C" Object DAT_004891CC;
extern "C" char sub_000EEB20[];

void __cdecl sub_00316630(void)
{
    DAT_004891CC.sub_0006F790(0, (int)DAT_0042784C, (int)sub_000EEB20, 0, 2, 2);
}
