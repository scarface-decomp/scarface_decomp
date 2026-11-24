// bin: xb
// va: 0x00320680
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00320680 (0x00320680, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023EC20(int);
};

extern "C" char DAT_003D3C50[];
extern "C" char DAT_003D3C68[];
extern "C" int DAT_00492BF8;
extern "C" int DAT_00492C00;
extern "C" char sub_0023A8D0[];
extern "C" char sub_003292A0[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00320680(void)
{
    ((Object*)(int)&DAT_00492BF8)->sub_0023EC20((int)DAT_003D3C68);
    DAT_00492BF8 = (int)DAT_003D3C50;
    DAT_00492C00 = (int)sub_0023A8D0;
    sub_002FBBEF((int)sub_003292A0);
}
