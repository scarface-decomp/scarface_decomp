// bin: xb
// va: 0x0031B670
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031B670 (0x0031B670, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043A1D4[];
extern "C" char DAT_0043A1E8[];
extern "C" Object DAT_0048EC00;
extern "C" char sub_001CF010[];

void __cdecl sub_0031B670(void)
{
    DAT_0048EC00.sub_0006F830((int)DAT_0043A1E8, (int)DAT_0043A1D4, (int)sub_001CF010, 0, 3, 3);
}
