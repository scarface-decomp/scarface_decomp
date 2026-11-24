// bin: xb
// va: 0x00313190
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313190 (0x00313190, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041C670[];
extern "C" Object DAT_00474D0C;
extern "C" char sub_0003D960[];

void __cdecl sub_00313190(void)
{
    DAT_00474D0C.sub_0006F830(0, (int)DAT_0041C670, (int)sub_0003D960, 0, 2, 2);
}
