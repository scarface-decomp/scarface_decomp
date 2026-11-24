// bin: xb
// va: 0x00316310
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316310 (0x00316310, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023EB20(int);
};

extern "C" char DAT_003A9328[];
extern "C" char DAT_003A9368[];
extern "C" int DAT_004879DC;
extern "C" int DAT_004879E4;
extern "C" char sub_000E8540[];
extern "C" char sub_003232F0[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00316310(void)
{
    ((Object*)(int)&DAT_004879DC)->sub_0023EB20((int)DAT_003A9368);
    DAT_004879DC = (int)DAT_003A9328;
    DAT_004879E4 = (int)sub_000E8540;
    sub_002FBBEF((int)sub_003232F0);
}
