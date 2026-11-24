// bin: xb
// va: 0x0031BB00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031BB00 (0x0031BB00, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043A6D4[];
extern "C" char DAT_0043A6E4[];
extern "C" Object DAT_0048EDC4;
extern "C" char sub_001D2840[];

void __cdecl sub_0031BB00(void)
{
    DAT_0048EDC4.sub_0006F830((int)DAT_0043A6E4, (int)DAT_0043A6D4, (int)sub_001D2840, 0, 4, 4);
}
