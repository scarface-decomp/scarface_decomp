// bin: xb
// va: 0x00314490
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314490 (0x00314490, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00422330[];
extern "C" Object DAT_00480E48;
extern "C" char sub_00077270[];

void __cdecl sub_00314490(void)
{
    DAT_00480E48.sub_0006F830(0, (int)DAT_00422330, (int)sub_00077270, 0, 2, 2);
}
