// bin: xb
// va: 0x0031F500
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F500 (0x0031F500, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044DD10[];
extern "C" Object DAT_00491DCC;
extern "C" char sub_00222E80[];

void __cdecl sub_0031F500(void)
{
    DAT_00491DCC.sub_0006F830(0, (int)DAT_0044DD10, (int)sub_00222E80, 0, 2, 2);
}
