// bin: xb
// va: 0x00316AE0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316AE0 (0x00316AE0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004288F8[];
extern "C" char DAT_00428908[];
extern "C" Object DAT_00489A58;
extern "C" char sub_00119A20[];

void __cdecl sub_00316AE0(void)
{
    DAT_00489A58.sub_0006F830((int)DAT_00428908, (int)DAT_004288F8, (int)sub_00119A20, 0, 4, 4);
}
