// bin: xb
// va: 0x00319360
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319360 (0x00319360, 73 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023ED00(int);
};

extern "C" char DAT_003B67E0[];
extern "C" char DAT_003B6824[];
extern "C" char DAT_00424A08[];
extern "C" int DAT_00424A78;
extern "C" int DAT_0048BFCC;
extern "C" int DAT_0048BFD4;
extern "C" int DAT_0048BFD8;
extern "C" int DAT_0048BFDC;
extern "C" char sub_00182910[];
extern "C" char sub_00325060[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00319360(void)
{
    int t1;

    t1 = DAT_00424A78;
    ((Object*)(int)&DAT_0048BFCC)->sub_0023ED00((int)DAT_003B6824);
    DAT_0048BFCC = (int)DAT_003B67E0;
    DAT_0048BFD4 = (int)DAT_00424A08;
    DAT_0048BFD8 = t1;
    DAT_0048BFDC = (int)sub_00182910;
    sub_002FBBEF((int)sub_00325060);
}
