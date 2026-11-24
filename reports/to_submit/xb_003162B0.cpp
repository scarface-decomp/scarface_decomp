// bin: xb
// va: 0x003162B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003162B0 (0x003162B0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023EB20(int);
};

extern "C" char DAT_003A9328[];
extern "C" char DAT_003A935C[];
extern "C" int DAT_004879C4;
extern "C" int DAT_004879CC;
extern "C" char sub_00184F10[];
extern "C" char sub_00323300[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_003162B0(void)
{
    ((Object*)(int)&DAT_004879C4)->sub_0023EB20((int)DAT_003A935C);
    DAT_004879C4 = (int)DAT_003A9328;
    DAT_004879CC = (int)sub_00184F10;
    sub_002FBBEF((int)sub_00323300);
}
