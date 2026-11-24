// bin: xb
// va: 0x00319820
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319820 (0x00319820, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_00435F08[];
extern "C" char DAT_00435F24[];
extern "C" Object DAT_0048D168;
extern "C" char sub_001BC8E0[];

void __cdecl sub_00319820(void)
{
    DAT_0048D168.sub_0006F790((int)DAT_00435F24, (int)DAT_00435F08, (int)sub_001BC8E0, 0, 4, 4);
}
