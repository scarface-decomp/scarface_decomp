// bin: xb
// va: 0x00319F20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319F20 (0x00319F20, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004369CC[];
extern "C" Object DAT_0048D7C4;
extern "C" char sub_001BD670[];

void __cdecl sub_00319F20(void)
{
    DAT_0048D7C4.sub_0006F830(0, (int)DAT_004369CC, (int)sub_001BD670, 0, 2, 2);
}
