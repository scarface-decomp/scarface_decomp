// bin: xb
// va: 0x00313230
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313230 (0x00313230, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041C6CC[];
extern "C" Object DAT_00474DE8;
extern "C" char sub_0003D9E0[];

void __cdecl sub_00313230(void)
{
    DAT_00474DE8.sub_0006F830(0, (int)DAT_0041C6CC, (int)sub_0003D9E0, 0, 5, 5);
}
