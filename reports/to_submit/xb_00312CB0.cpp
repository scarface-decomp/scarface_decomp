// bin: xb
// va: 0x00312CB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312CB0 (0x00312CB0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041BDA0[];
extern "C" char DAT_0041BDB0[];
extern "C" Object DAT_004744E4;
extern "C" char sub_0002E040[];

void __cdecl sub_00312CB0(void)
{
    DAT_004744E4.sub_0006F830((int)DAT_0041BDB0, (int)DAT_0041BDA0, (int)sub_0002E040, 0, 4, 4);
}
