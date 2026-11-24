// bin: xb
// va: 0x0031F480
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F480 (0x0031F480, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044DCA0[];
extern "C" Object DAT_00491D1C;
extern "C" char sub_00222E10[];

void __cdecl sub_0031F480(void)
{
    DAT_00491D1C.sub_0006F830(0, (int)DAT_0044DCA0, (int)sub_00222E10, 0, 2, 2);
}
