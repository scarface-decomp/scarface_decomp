// bin: xb
// va: 0x00316020
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316020 (0x00316020, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023EC20(int);
};

extern "C" char DAT_003A6D88[];
extern "C" char DAT_003A6F70[];
extern "C" int DAT_004877F8;
extern "C" int DAT_00487800;
extern "C" char sub_000DD510[];
extern "C" char sub_00323220[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00316020(void)
{
    ((Object*)(int)&DAT_004877F8)->sub_0023EC20((int)DAT_003A6F70);
    DAT_004877F8 = (int)DAT_003A6D88;
    DAT_00487800 = (int)sub_000DD510;
    sub_002FBBEF((int)sub_00323220);
}
