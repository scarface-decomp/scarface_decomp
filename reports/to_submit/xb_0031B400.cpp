// bin: xb
// va: 0x0031B400
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031B400 (0x0031B400, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00439C84[];
extern "C" char DAT_00439C8C[];
extern "C" Object DAT_0048EB34;
extern "C" char sub_001CE040[];

void __cdecl sub_0031B400(void)
{
    DAT_0048EB34.sub_0006F830((int)DAT_00439C8C, (int)DAT_00439C84, (int)sub_001CE040, 0, 3, 3);
}
