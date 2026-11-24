// bin: xb
// va: 0x00316080
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316080 (0x00316080, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023ED00(int);
};

extern "C" char DAT_003A6DDC[];
extern "C" char DAT_003A6F94[];
extern "C" char DAT_00425114[];
extern "C" int DAT_00487810;
extern "C" int DAT_00487818;
extern "C" int DAT_0048781C;
extern "C" int DAT_00487820;
extern "C" char sub_00182910[];
extern "C" char sub_00323240[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00316080(void)
{
    ((Object*)(int)&DAT_00487810)->sub_0023ED00((int)DAT_003A6F94);
    DAT_00487810 = (int)DAT_003A6DDC;
    DAT_00487818 = (int)DAT_00425114;
    DAT_0048781C = 5;
    DAT_00487820 = (int)sub_00182910;
    sub_002FBBEF((int)sub_00323240);
}
