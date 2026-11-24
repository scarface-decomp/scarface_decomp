// bin: xb
// va: 0x00319D80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319D80 (0x00319D80, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004368F0[];
extern "C" Object DAT_0048D588;
extern "C" char sub_001BD450[];

void __cdecl sub_00319D80(void)
{
    DAT_0048D588.sub_0006F830(0, (int)DAT_004368F0, (int)sub_001BD450, 0, 1, 1);
}
