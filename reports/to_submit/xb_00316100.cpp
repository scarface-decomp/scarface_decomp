// bin: xb
// va: 0x00316100
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316100 (0x00316100, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023ED00(int);
};

extern "C" char DAT_003A8D2C[];
extern "C" char DAT_003A8D4C[];
extern "C" char DAT_00427190[];
extern "C" int DAT_004878E0;
extern "C" int DAT_004878E8;
extern "C" int DAT_004878EC;
extern "C" int DAT_004878F0;
extern "C" char sub_00184ED0[];
extern "C" char sub_00323290[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00316100(void)
{
    ((Object*)(int)&DAT_004878E0)->sub_0023ED00((int)DAT_003A8D4C);
    DAT_004878E0 = (int)DAT_003A8D2C;
    DAT_004878E8 = (int)DAT_00427190;
    DAT_004878EC = 4;
    DAT_004878F0 = (int)sub_00184ED0;
    sub_002FBBEF((int)sub_00323290);
}
