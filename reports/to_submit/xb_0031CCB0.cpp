// bin: xb
// va: 0x0031CCB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031CCB0 (0x0031CCB0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0043E9A4[];
extern "C" char DAT_0043E9C0[];
extern "C" Object DAT_0048FCC0;
extern "C" char sub_001EEA60[];

void __cdecl sub_0031CCB0(void)
{
    DAT_0048FCC0.sub_0006F790((int)DAT_0043E9C0, (int)DAT_0043E9A4, (int)sub_001EEA60, 0, 2, 2);
}
