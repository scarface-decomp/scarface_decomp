// bin: xb
// va: 0x0031F910
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F910 (0x0031F910, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003D1E88[];
extern "C" Object DAT_00491F0C;
extern "C" char sub_00228D00[];

void __cdecl sub_0031F910(void)
{
    DAT_00491F0C.sub_000EB3A0(49, 35, 21, 33, 17, (int)DAT_003D1E88, (int)sub_00228D00, 208, 0, 0);
}
