// bin: xb
// va: 0x00315EC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315EC0 (0x00315EC0, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023ED00(int);
};

extern "C" char DAT_003A6CEC[];
extern "C" char DAT_003A6EFC[];
extern "C" char DAT_00425078[];
extern "C" int DAT_004877A0;
extern "C" int DAT_004877A8;
extern "C" int DAT_004877AC;
extern "C" int DAT_004877B0;
extern "C" char sub_00182910[];
extern "C" char sub_003231C0[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00315EC0(void)
{
    ((Object*)(int)&DAT_004877A0)->sub_0023ED00((int)DAT_003A6EFC);
    DAT_004877A0 = (int)DAT_003A6CEC;
    DAT_004877A8 = (int)DAT_00425078;
    DAT_004877AC = 4;
    DAT_004877B0 = (int)sub_00182910;
    sub_002FBBEF((int)sub_003231C0);
}
