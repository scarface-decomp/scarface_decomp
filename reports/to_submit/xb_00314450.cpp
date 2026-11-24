// bin: xb
// va: 0x00314450
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314450 (0x00314450, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_00422308[];
extern "C" Object DAT_00480DF0;
extern "C" char sub_00077250[];

void __cdecl sub_00314450(void)
{
    DAT_00480DF0.sub_0006F880(0, (int)DAT_00422308, (int)sub_00077250, 0, 1, 1);
}
