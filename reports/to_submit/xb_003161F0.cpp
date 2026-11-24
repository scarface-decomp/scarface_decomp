// bin: xb
// va: 0x003161F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003161F0 (0x003161F0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023EB20(int);
};

extern "C" char DAT_003A8E70[];
extern "C" char DAT_003A8E98[];
extern "C" int DAT_0048791C;
extern "C" int DAT_00487924;
extern "C" char sub_000E99C0[];
extern "C" char sub_003232C0[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_003161F0(void)
{
    ((Object*)(int)&DAT_0048791C)->sub_0023EB20((int)DAT_003A8E98);
    DAT_0048791C = (int)DAT_003A8E70;
    DAT_00487924 = (int)sub_000E99C0;
    sub_002FBBEF((int)sub_003232C0);
}
