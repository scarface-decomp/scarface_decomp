// bin: xb
// va: 0x00312C50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312C50 (0x00312C50, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041BD4C[];
extern "C" char DAT_0041BD5C[];
extern "C" Object DAT_00474460;
extern "C" char sub_0002DD60[];

void __cdecl sub_00312C50(void)
{
    DAT_00474460.sub_0006F830((int)DAT_0041BD5C, (int)DAT_0041BD4C, (int)sub_0002DD60, 0, 3, 5);
}
