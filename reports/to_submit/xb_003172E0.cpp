// bin: xb
// va: 0x003172E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003172E0 (0x003172E0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042B0F8[];
extern "C" Object DAT_00489BA0;
extern "C" char sub_0011CF90[];

void __cdecl sub_003172E0(void)
{
    DAT_00489BA0.sub_0006F830(0, (int)DAT_0042B0F8, (int)sub_0011CF90, 0, 2, 2);
}
