// bin: xb
// va: 0x003161A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003161A0 (0x003161A0, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023ED00(int);
};

extern "C" char DAT_003A8E30[];
extern "C" char DAT_003A8E88[];
extern "C" char DAT_00427244[];
extern "C" int DAT_00487908;
extern "C" int DAT_00487910;
extern "C" int DAT_00487914;
extern "C" int DAT_00487918;
extern "C" char sub_000E7970[];
extern "C" char sub_003232B0[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_003161A0(void)
{
    ((Object*)(int)&DAT_00487908)->sub_0023ED00((int)DAT_003A8E88);
    DAT_00487908 = (int)DAT_003A8E30;
    DAT_00487910 = (int)DAT_00427244;
    DAT_00487914 = 6;
    DAT_00487918 = (int)sub_000E7970;
    sub_002FBBEF((int)sub_003232B0);
}
