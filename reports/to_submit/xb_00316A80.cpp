// bin: xb
// va: 0x00316A80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316A80 (0x00316A80, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00428890[];
extern "C" char DAT_0042889C[];
extern "C" Object DAT_004899D4;
extern "C" char sub_00119950[];

void __cdecl sub_00316A80(void)
{
    DAT_004899D4.sub_0006F830((int)DAT_0042889C, (int)DAT_00428890, (int)sub_00119950, 0, 8, 10);
}
