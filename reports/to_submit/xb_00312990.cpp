// bin: xb
// va: 0x00312990
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312990 (0x00312990, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0041B758[];
extern "C" char DAT_0041B760[];
extern "C" Object DAT_00474224;
extern "C" char sub_0002D5C0[];

void __cdecl sub_00312990(void)
{
    DAT_00474224.sub_0006F790((int)DAT_0041B760, (int)DAT_0041B758, (int)sub_0002D5C0, 0, 3, 3);
}
