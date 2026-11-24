// bin: xb
// va: 0x00315F60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315F60 (0x00315F60, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023EC20(int);
};

extern "C" char DAT_003A6D34[];
extern "C" char DAT_003A6F24[];
extern "C" int DAT_004877C8;
extern "C" int DAT_004877D0;
extern "C" char sub_000DD510[];
extern "C" char sub_003231E0[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00315F60(void)
{
    ((Object*)(int)&DAT_004877C8)->sub_0023EC20((int)DAT_003A6F24);
    DAT_004877C8 = (int)DAT_003A6D34;
    DAT_004877D0 = (int)sub_000DD510;
    sub_002FBBEF((int)sub_003231E0);
}
