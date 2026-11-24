// bin: xb
// va: 0x00318D20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318D20 (0x00318D20, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00430CF4[];
extern "C" char DAT_00430D10[];
extern "C" Object DAT_0048BC14;
extern "C" char sub_00179DE0[];

void __cdecl sub_00318D20(void)
{
    DAT_0048BC14.sub_0006F830((int)DAT_00430D10, (int)DAT_00430CF4, (int)sub_00179DE0, 0, 3, 3);
}
