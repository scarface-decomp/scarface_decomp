// bin: xb
// va: 0x003206B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003206B0 (0x003206B0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023EC20(int);
};

extern "C" char DAT_003D3C50[];
extern "C" char DAT_003D3C74[];
extern "C" int DAT_00492BEC;
extern "C" int DAT_00492BF4;
extern "C" char sub_0023A8F0[];
extern "C" char sub_00329290[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_003206B0(void)
{
    ((Object*)(int)&DAT_00492BEC)->sub_0023EC20((int)DAT_003D3C74);
    DAT_00492BEC = (int)DAT_003D3C50;
    DAT_00492BF4 = (int)sub_0023A8F0;
    sub_002FBBEF((int)sub_00329290);
}
