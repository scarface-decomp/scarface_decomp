// bin: xb
// va: 0x003192C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003192C0 (0x003192C0, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023ED00(int);
};

extern "C" char DAT_003B6798[];
extern "C" char DAT_003B681C[];
extern "C" char DAT_00431D58[];
extern "C" int DAT_0048BFA4;
extern "C" int DAT_0048BFAC;
extern "C" int DAT_0048BFB0;
extern "C" int DAT_0048BFB4;
extern "C" char sub_00182910[];
extern "C" char sub_00325070[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_003192C0(void)
{
    ((Object*)(int)&DAT_0048BFA4)->sub_0023ED00((int)DAT_003B681C);
    DAT_0048BFA4 = (int)DAT_003B6798;
    DAT_0048BFAC = (int)DAT_00431D58;
    DAT_0048BFB0 = 11;
    DAT_0048BFB4 = (int)sub_00182910;
    sub_002FBBEF((int)sub_00325070);
}
