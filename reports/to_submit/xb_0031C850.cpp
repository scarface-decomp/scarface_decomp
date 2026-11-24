// bin: xb
// va: 0x0031C850
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031C850 (0x0031C850, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0043E1A0[];
extern "C" char DAT_0043E1B0[];
extern "C" Object DAT_0048F7C0;
extern "C" char sub_001EE120[];

void __cdecl sub_0031C850(void)
{
    DAT_0048F7C0.sub_0006F790((int)DAT_0043E1B0, (int)DAT_0043E1A0, (int)sub_001EE120, 0, 2, 2);
}
