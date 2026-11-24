// bin: xb
// va: 0x0031BD00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031BD00 (0x0031BD00, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0043AC4C[];
extern "C" char DAT_0043AC58[];
extern "C" Object DAT_0048EFA8;
extern "C" char sub_001D3470[];

void __cdecl sub_0031BD00(void)
{
    DAT_0048EFA8.sub_0006F790((int)DAT_0043AC58, (int)DAT_0043AC4C, (int)sub_001D3470, 0, 2, 2);
}
