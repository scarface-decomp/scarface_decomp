// bin: xb
// va: 0x00316B00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316B00 (0x00316B00, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00428918[];
extern "C" char DAT_00428934[];
extern "C" Object DAT_00489A84;
extern "C" char sub_00119A50[];

void __cdecl sub_00316B00(void)
{
    DAT_00489A84.sub_0006F830((int)DAT_00428934, (int)DAT_00428918, (int)sub_00119A50, 0, 5, 5);
}
