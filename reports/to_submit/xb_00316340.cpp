// bin: xb
// va: 0x00316340
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316340 (0x00316340, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004276B4[];
extern "C" Object DAT_004879EC;
extern "C" char sub_000EA4C0[];

void __cdecl sub_00316340(void)
{
    DAT_004879EC.sub_0006F830(0, (int)DAT_004276B4, (int)sub_000EA4C0, 0, 0, 1);
}
