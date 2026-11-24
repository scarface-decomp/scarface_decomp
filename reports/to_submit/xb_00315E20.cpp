// bin: xb
// va: 0x00315E20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315E20 (0x00315E20, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023ED00(int);
};

extern "C" char DAT_003A6CA4[];
extern "C" char DAT_003A6ED0[];
extern "C" char DAT_00425050[];
extern "C" int DAT_00487778;
extern "C" int DAT_00487780;
extern "C" int DAT_00487784;
extern "C" int DAT_00487788;
extern "C" char sub_00182910[];
extern "C" char sub_00323260[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00315E20(void)
{
    ((Object*)(int)&DAT_00487778)->sub_0023ED00((int)DAT_003A6ED0);
    DAT_00487778 = (int)DAT_003A6CA4;
    DAT_00487780 = (int)DAT_00425050;
    DAT_00487784 = 2;
    DAT_00487788 = (int)sub_00182910;
    sub_002FBBEF((int)sub_00323260);
}
