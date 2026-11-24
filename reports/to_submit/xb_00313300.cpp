// bin: xb
// va: 0x00313300
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313300 (0x00313300, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041D2D8[];
extern "C" Object DAT_004757D4;
extern "C" char sub_0004E1F0[];

void __cdecl sub_00313300(void)
{
    DAT_004757D4.sub_0006F830(0, (int)DAT_0041D2D8, (int)sub_0004E1F0, 0, 4, 4);
}
