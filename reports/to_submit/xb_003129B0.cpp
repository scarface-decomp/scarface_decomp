// bin: xb
// va: 0x003129B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003129B0 (0x003129B0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0041B768[];
extern "C" char DAT_0041B77C[];
extern "C" Object DAT_00474250;
extern "C" char sub_0002D6A0[];

void __cdecl sub_003129B0(void)
{
    DAT_00474250.sub_0006F790((int)DAT_0041B77C, (int)DAT_0041B768, (int)sub_0002D6A0, 0, 3, 3);
}
