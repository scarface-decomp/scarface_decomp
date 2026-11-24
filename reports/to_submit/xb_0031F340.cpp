// bin: xb
// va: 0x0031F340
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F340 (0x0031F340, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044DB48[];
extern "C" Object DAT_00491B64;
extern "C" char sub_00222CD0[];

void __cdecl sub_0031F340(void)
{
    DAT_00491B64.sub_0006F830(0, (int)DAT_0044DB48, (int)sub_00222CD0, 0, 2, 2);
}
