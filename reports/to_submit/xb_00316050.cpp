// bin: xb
// va: 0x00316050
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316050 (0x00316050, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023EC20(int);
};

extern "C" char DAT_003A6DC0[];
extern "C" char DAT_003A6F80[];
extern "C" int DAT_00487804;
extern "C" int DAT_0048780C;
extern "C" char sub_00239EC0[];
extern "C" char sub_00323230[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00316050(void)
{
    ((Object*)(int)&DAT_00487804)->sub_0023EC20((int)DAT_003A6F80);
    DAT_00487804 = (int)DAT_003A6DC0;
    DAT_0048780C = (int)sub_00239EC0;
    sub_002FBBEF((int)sub_00323230);
}
