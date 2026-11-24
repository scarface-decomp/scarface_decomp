// bin: xb
// va: 0x003187A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003187A0 (0x003187A0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0042FF84[];
extern "C" char DAT_0042FF9C[];
extern "C" Object DAT_0048B54C;
extern "C" char sub_00178F00[];

void __cdecl sub_003187A0(void)
{
    DAT_0048B54C.sub_0006F790((int)DAT_0042FF9C, (int)DAT_0042FF84, (int)sub_00178F00, 0, 2, 2);
}
