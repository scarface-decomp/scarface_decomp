// bin: xb
// va: 0x00319DA0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319DA0 (0x00319DA0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004368FC[];
extern "C" Object DAT_0048D5B4;
extern "C" char sub_001BD460[];

void __cdecl sub_00319DA0(void)
{
    DAT_0048D5B4.sub_0006F830(0, (int)DAT_004368FC, (int)sub_001BD460, 0, 1, 1);
}
