// bin: xb
// va: 0x00312910
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312910 (0x00312910, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0041B718[];
extern "C" char DAT_0041B724[];
extern "C" Object DAT_00474174;
extern "C" char sub_0002D660[];

void __cdecl sub_00312910(void)
{
    DAT_00474174.sub_0006F790((int)DAT_0041B724, (int)DAT_0041B718, (int)sub_0002D660, 0, 3, 3);
}
