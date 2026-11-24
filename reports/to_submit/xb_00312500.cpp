// bin: xb
// va: 0x00312500
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312500 (0x00312500, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041A958[];
extern "C" Object DAT_0047179C;
extern "C" char sub_00024A50[];

void __cdecl sub_00312500(void)
{
    DAT_0047179C.sub_0006F830(0, (int)DAT_0041A958, (int)sub_00024A50, 0, 5, 6);
}
