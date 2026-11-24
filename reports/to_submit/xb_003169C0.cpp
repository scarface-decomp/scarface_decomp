// bin: xb
// va: 0x003169C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003169C0 (0x003169C0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_00428674[];
extern "C" Object DAT_00489918;
extern "C" char sub_00115320[];

void __cdecl sub_003169C0(void)
{
    DAT_00489918.sub_0006F790(0, (int)DAT_00428674, (int)sub_00115320, 0, 1, 1);
}
