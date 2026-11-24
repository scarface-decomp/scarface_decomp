// bin: xb
// va: 0x0031BB20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031BB20 (0x0031BB20, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0043A6F4[];
extern "C" char DAT_0043A6FC[];
extern "C" Object DAT_0048EDF0;
extern "C" char sub_001D2870[];

void __cdecl sub_0031BB20(void)
{
    DAT_0048EDF0.sub_0006F790((int)DAT_0043A6FC, (int)DAT_0043A6F4, (int)sub_001D2870, 0, 2, 2);
}
