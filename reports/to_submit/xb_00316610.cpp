// bin: xb
// va: 0x00316610
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316610 (0x00316610, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0042783C[];
extern "C" Object DAT_004891A0;
extern "C" char sub_000EEB00[];

void __cdecl sub_00316610(void)
{
    DAT_004891A0.sub_0006F790(0, (int)DAT_0042783C, (int)sub_000EEB00, 0, 2, 2);
}
