// bin: xb
// va: 0x00315F10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315F10 (0x00315F10, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023ED00(int);
};

extern "C" char DAT_003A6D10[];
extern "C" char DAT_003A6F14[];
extern "C" char DAT_0042508C[];
extern "C" int DAT_004877B4;
extern "C" int DAT_004877BC;
extern "C" int DAT_004877C0;
extern "C" int DAT_004877C4;
extern "C" char sub_00182910[];
extern "C" char sub_003231D0[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00315F10(void)
{
    ((Object*)(int)&DAT_004877B4)->sub_0023ED00((int)DAT_003A6F14);
    DAT_004877B4 = (int)DAT_003A6D10;
    DAT_004877BC = (int)DAT_0042508C;
    DAT_004877C0 = 13;
    DAT_004877C4 = (int)sub_00182910;
    sub_002FBBEF((int)sub_003231D0);
}
