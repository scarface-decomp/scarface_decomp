// bin: xb
// va: 0x00318F20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318F20 (0x00318F20, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_00431364[];
extern "C" char DAT_00431378[];
extern "C" Object DAT_0048BCB0;
extern "C" char sub_0017A6D0[];

void __cdecl sub_00318F20(void)
{
    DAT_0048BCB0.sub_0006F790((int)DAT_00431378, (int)DAT_00431364, (int)sub_0017A6D0, 0, 3, 3);
}
