// bin: xb
// va: 0x0031C310
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031C310 (0x0031C310, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043C19C[];
extern "C" Object DAT_0048F678;
extern "C" char sub_001E57A0[];

void __cdecl sub_0031C310(void)
{
    DAT_0048F678.sub_0006F830(0, (int)DAT_0043C19C, (int)sub_001E57A0, 0, 6, 8);
}
