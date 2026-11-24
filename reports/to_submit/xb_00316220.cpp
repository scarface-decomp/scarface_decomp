// bin: xb
// va: 0x00316220
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316220 (0x00316220, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023EB20(int);
};

extern "C" char DAT_003A8E70[];
extern "C" char DAT_003A8EB4[];
extern "C" int DAT_00487928;
extern "C" int DAT_00487930;
extern "C" char sub_000E99F0[];
extern "C" char sub_003232A0[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00316220(void)
{
    ((Object*)(int)&DAT_00487928)->sub_0023EB20((int)DAT_003A8EB4);
    DAT_00487928 = (int)DAT_003A8E70;
    DAT_00487930 = (int)sub_000E99F0;
    sub_002FBBEF((int)sub_003232A0);
}
