// bin: xb
// va: 0x00312C70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312C70 (0x00312C70, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041BD6C[];
extern "C" char DAT_0041BD78[];
extern "C" Object DAT_0047448C;
extern "C" char sub_0002DDB0[];

void __cdecl sub_00312C70(void)
{
    DAT_0047448C.sub_0006F830((int)DAT_0041BD78, (int)DAT_0041BD6C, (int)sub_0002DDB0, 0, 3, 3);
}
