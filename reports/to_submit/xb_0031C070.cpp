// bin: xb
// va: 0x0031C070
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031C070 (0x0031C070, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0043B7BC[];
extern "C" char DAT_0043B7C8[];
extern "C" Object DAT_0048F268;
extern "C" char sub_001D75D0[];

void __cdecl sub_0031C070(void)
{
    DAT_0048F268.sub_0006F790((int)DAT_0043B7C8, (int)DAT_0043B7BC, (int)sub_001D75D0, 0, 3, 3);
}
