// bin: xb
// va: 0x00319310
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319310 (0x00319310, 73 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023ED00(int);
};

extern "C" char DAT_003B67BC[];
extern "C" char DAT_003B6824[];
extern "C" char DAT_00424A08[];
extern "C" int DAT_00424A78;
extern "C" int DAT_0048BFB8;
extern "C" int DAT_0048BFC0;
extern "C" int DAT_0048BFC4;
extern "C" int DAT_0048BFC8;
extern "C" char sub_00182910[];
extern "C" char sub_00325050[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00319310(void)
{
    int t1;

    t1 = DAT_00424A78;
    ((Object*)(int)&DAT_0048BFB8)->sub_0023ED00((int)DAT_003B6824);
    DAT_0048BFB8 = (int)DAT_003B67BC;
    DAT_0048BFC0 = (int)DAT_00424A08;
    DAT_0048BFC4 = t1;
    DAT_0048BFC8 = (int)sub_00182910;
    sub_002FBBEF((int)sub_00325050);
}
