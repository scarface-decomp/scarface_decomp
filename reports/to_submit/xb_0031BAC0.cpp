// bin: xb
// va: 0x0031BAC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031BAC0 (0x0031BAC0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043A530[];
extern "C" char DAT_0043A53C[];
extern "C" Object DAT_0048ED98;
extern "C" char sub_001D27D0[];

void __cdecl sub_0031BAC0(void)
{
    DAT_0048ED98.sub_0006F830((int)DAT_0043A53C, (int)DAT_0043A530, (int)sub_001D27D0, 0, 2, 2);
}
