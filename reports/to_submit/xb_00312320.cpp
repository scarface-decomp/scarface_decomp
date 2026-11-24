// bin: xb
// va: 0x00312320
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312320 (0x00312320, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023EC20(int);
};

extern "C" char DAT_0039E57C[];
extern "C" char DAT_0039E5B0[];
extern "C" int DAT_004716E8;
extern "C" int DAT_004716F0;
extern "C" char sub_000229C0[];
extern "C" char sub_00322620[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00312320(void)
{
    ((Object*)(int)&DAT_004716E8)->sub_0023EC20((int)DAT_0039E5B0);
    DAT_004716E8 = (int)DAT_0039E57C;
    DAT_004716F0 = (int)sub_000229C0;
    sub_002FBBEF((int)sub_00322620);
}
