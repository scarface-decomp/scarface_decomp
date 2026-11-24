// bin: xb
// va: 0x00315FF0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315FF0 (0x00315FF0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023EC20(int);
};

extern "C" char DAT_003A6DA4[];
extern "C" char DAT_003A6F58[];
extern "C" int DAT_004877EC;
extern "C" int DAT_004877F4;
extern "C" char sub_000DD510[];
extern "C" char sub_00323210[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00315FF0(void)
{
    ((Object*)(int)&DAT_004877EC)->sub_0023EC20((int)DAT_003A6F58);
    DAT_004877EC = (int)DAT_003A6DA4;
    DAT_004877F4 = (int)sub_000DD510;
    sub_002FBBEF((int)sub_00323210);
}
