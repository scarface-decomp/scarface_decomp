// bin: xb
// va: 0x00314B10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314B10 (0x00314B10, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_00423254[];
extern "C" Object DAT_00481804;
extern "C" char sub_0008FC10[];

void __cdecl sub_00314B10(void)
{
    DAT_00481804.sub_0006F790(0, (int)DAT_00423254, (int)sub_0008FC10, 0, 1, 1);
}
