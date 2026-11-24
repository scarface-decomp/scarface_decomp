// bin: xb
// va: 0x00313130
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313130 (0x00313130, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0041C630[];
extern "C" Object DAT_00474C88;
extern "C" char sub_0003D860[];

void __cdecl sub_00313130(void)
{
    DAT_00474C88.sub_0006F740(0, (int)DAT_0041C630, (int)sub_0003D860, 0, 1, 4);
}
