// bin: xb
// va: 0x00316690
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316690 (0x00316690, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0042788C[];
extern "C" Object DAT_00489250;
extern "C" char sub_000EEB80[];

void __cdecl sub_00316690(void)
{
    DAT_00489250.sub_0006F790(0, (int)DAT_0042788C, (int)sub_000EEB80, 0, 3, 3);
}
