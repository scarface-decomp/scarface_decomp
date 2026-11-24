// bin: xb
// va: 0x003162E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003162E0 (0x003162E0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023EBB0(int);
};

extern "C" char DAT_003A8EC0[];
extern "C" char DAT_003A9344[];
extern "C" int DAT_004879D0;
extern "C" int DAT_004879D8;
extern "C" char sub_000EA2F0[];
extern "C" char sub_00323310[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_003162E0(void)
{
    ((Object*)(int)&DAT_004879D0)->sub_0023EBB0((int)DAT_003A8EC0);
    DAT_004879D0 = (int)DAT_003A9344;
    DAT_004879D8 = (int)sub_000EA2F0;
    sub_002FBBEF((int)sub_00323310);
}
