// bin: xb
// va: 0x0031BBA0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031BBA0 (0x0031BBA0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043A888[];
extern "C" char DAT_0043A890[];
extern "C" Object DAT_0048EE48;
extern "C" char sub_001D2B00[];

void __cdecl sub_0031BBA0(void)
{
    DAT_0048EE48.sub_0006F830((int)DAT_0043A890, (int)DAT_0043A888, (int)sub_001D2B00, 0, 2, 2);
}
