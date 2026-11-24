// bin: xb
// va: 0x0031FAB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031FAB0 (0x0031FAB0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003D2288[];
extern "C" Object DAT_00491FC8;
extern "C" char sub_0022BCF0[];

void __cdecl sub_0031FAB0(void)
{
    DAT_00491FC8.sub_000EB3A0(44, 33, 23, 34, 4, (int)DAT_003D2288, (int)sub_0022BCF0, 208, 0, 1);
}
