// bin: xb
// va: 0x00313170
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313170 (0x00313170, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041C658[];
extern "C" Object DAT_00474CE0;
extern "C" char sub_0003D940[];

void __cdecl sub_00313170(void)
{
    DAT_00474CE0.sub_0006F830(0, (int)DAT_0041C658, (int)sub_0003D940, 0, 2, 2);
}
