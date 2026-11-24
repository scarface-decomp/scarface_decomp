// bin: xb
// va: 0x00315FC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315FC0 (0x00315FC0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023EC20(int);
};

extern "C" char DAT_003A6D6C[];
extern "C" char DAT_003A6F44[];
extern "C" int DAT_004877E0;
extern "C" int DAT_004877E8;
extern "C" char sub_000DD510[];
extern "C" char sub_00323200[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00315FC0(void)
{
    ((Object*)(int)&DAT_004877E0)->sub_0023EC20((int)DAT_003A6F44);
    DAT_004877E0 = (int)DAT_003A6D6C;
    DAT_004877E8 = (int)sub_000DD510;
    sub_002FBBEF((int)sub_00323200);
}
