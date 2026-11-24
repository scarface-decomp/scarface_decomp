// bin: xb
// va: 0x00312EF0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312EF0 (0x00312EF0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041C32C[];
extern "C" Object DAT_004749A8;
extern "C" char sub_002A9290[];

void __cdecl sub_00312EF0(void)
{
    DAT_004749A8.sub_0006F830(0, (int)DAT_0041C32C, (int)sub_002A9290, 0, 1, 2);
}
