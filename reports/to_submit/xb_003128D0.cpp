// bin: xb
// va: 0x003128D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003128D0 (0x003128D0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041B698[];
extern "C" char DAT_0041B6A8[];
extern "C" Object DAT_00474148;
extern "C" char sub_0002D360[];

void __cdecl sub_003128D0(void)
{
    DAT_00474148.sub_0006F830((int)DAT_0041B6A8, (int)DAT_0041B698, (int)sub_0002D360, 0, 3, 3);
}
