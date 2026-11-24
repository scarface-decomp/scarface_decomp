// bin: xb
// va: 0x00319F80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319F80 (0x00319F80, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00436A20[];
extern "C" Object DAT_0048D848;
extern "C" char sub_001BD700[];

void __cdecl sub_00319F80(void)
{
    DAT_0048D848.sub_0006F830(0, (int)DAT_00436A20, (int)sub_001BD700, 0, 2, 2);
}
