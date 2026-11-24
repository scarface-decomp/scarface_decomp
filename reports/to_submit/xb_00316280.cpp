// bin: xb
// va: 0x00316280
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316280 (0x00316280, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023EC20(int);
};

extern "C" char DAT_003A8F70[];
extern "C" char DAT_003A8F88[];
extern "C" int DAT_004879A0;
extern "C" int DAT_004879A8;
extern "C" char sub_000E9C10[];
extern "C" char sub_003232E0[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00316280(void)
{
    ((Object*)(int)&DAT_004879A0)->sub_0023EC20((int)DAT_003A8F88);
    DAT_004879A0 = (int)DAT_003A8F70;
    DAT_004879A8 = (int)sub_000E9C10;
    sub_002FBBEF((int)sub_003232E0);
}
