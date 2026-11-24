// bin: xb
// va: 0x00314350
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314350 (0x00314350, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00422224[];
extern "C" Object DAT_00480C90;
extern "C" char sub_00077130[];

void __cdecl sub_00314350(void)
{
    DAT_00480C90.sub_0006F830(0, (int)DAT_00422224, (int)sub_00077130, 0, 2, 5);
}
