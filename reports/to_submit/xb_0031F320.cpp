// bin: xb
// va: 0x0031F320
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F320 (0x0031F320, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044DB20[];
extern "C" Object DAT_00491B38;
extern "C" char sub_00222CB0[];

void __cdecl sub_0031F320(void)
{
    DAT_00491B38.sub_0006F830(0, (int)DAT_0044DB20, (int)sub_00222CB0, 0, 2, 2);
}
