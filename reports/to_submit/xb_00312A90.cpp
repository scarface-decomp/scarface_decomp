// bin: xb
// va: 0x00312A90
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312A90 (0x00312A90, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041BA14[];
extern "C" char DAT_0041BA20[];
extern "C" Object DAT_00474300;
extern "C" char sub_0002D330[];

void __cdecl sub_00312A90(void)
{
    DAT_00474300.sub_0006F830((int)DAT_0041BA20, (int)DAT_0041BA14, (int)sub_0002D330, 0, 3, 3);
}
