// bin: xb
// va: 0x0031BD20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031BD20 (0x0031BD20, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0043AC64[];
extern "C" char DAT_0043AC74[];
extern "C" Object DAT_0048EFD4;
extern "C" char sub_001D34A0[];

void __cdecl sub_0031BD20(void)
{
    DAT_0048EFD4.sub_0006F790((int)DAT_0043AC74, (int)DAT_0043AC64, (int)sub_001D34A0, 0, 2, 2);
}
