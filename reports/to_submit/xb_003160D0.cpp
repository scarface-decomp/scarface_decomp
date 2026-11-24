// bin: xb
// va: 0x003160D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003160D0 (0x003160D0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023EC20(int);
};

extern "C" char DAT_003A6440[];
extern "C" char DAT_003A8D10[];
extern "C" int DAT_004878D4;
extern "C" int DAT_004878DC;
extern "C" char sub_000E9860[];
extern "C" char sub_00323280[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_003160D0(void)
{
    ((Object*)(int)&DAT_004878D4)->sub_0023EC20((int)DAT_003A6440);
    DAT_004878D4 = (int)DAT_003A8D10;
    DAT_004878DC = (int)sub_000E9860;
    sub_002FBBEF((int)sub_00323280);
}
