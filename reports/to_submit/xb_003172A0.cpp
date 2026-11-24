// bin: xb
// va: 0x003172A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003172A0 (0x003172A0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042B0D0[];
extern "C" Object DAT_00489B48;
extern "C" char sub_0011CF00[];

void __cdecl sub_003172A0(void)
{
    DAT_00489B48.sub_0006F830(0, (int)DAT_0042B0D0, (int)sub_0011CF00, 0, 3, 3);
}
