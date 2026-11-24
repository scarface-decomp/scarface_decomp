// bin: xb
// va: 0x00319CA0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319CA0 (0x00319CA0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004366D0[];
extern "C" char DAT_004366D8[];
extern "C" Object DAT_0048D504;
extern "C" char sub_001BD200[];

void __cdecl sub_00319CA0(void)
{
    DAT_0048D504.sub_0006F830((int)DAT_004366D8, (int)DAT_004366D0, (int)sub_001BD200, 0, 3, 3);
}
