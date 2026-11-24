// bin: xb
// va: 0x0031F140
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F140 (0x0031F140, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044D984[];
extern "C" Object DAT_004918A4;
extern "C" char sub_00222AA0[];

void __cdecl sub_0031F140(void)
{
    DAT_004918A4.sub_0006F830(0, (int)DAT_0044D984, (int)sub_00222AA0, 0, 2, 2);
}
