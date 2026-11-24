// bin: xb
// va: 0x003193B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003193B0 (0x003193B0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023EC20(int);
};

extern "C" char DAT_003B6804[];
extern "C" char DAT_003B682C[];
extern "C" int DAT_0048BFE0;
extern "C" int DAT_0048BFE8;
extern "C" char sub_000DD510[];
extern "C" char sub_00325080[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_003193B0(void)
{
    ((Object*)(int)&DAT_0048BFE0)->sub_0023EC20((int)DAT_003B682C);
    DAT_0048BFE0 = (int)DAT_003B6804;
    DAT_0048BFE8 = (int)sub_000DD510;
    sub_002FBBEF((int)sub_00325080);
}
