// bin: xb
// va: 0x0031B500
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031B500 (0x0031B500, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00439CC4[];
extern "C" char DAT_00439CDC[];
extern "C" Object DAT_0048EBB8;
extern "C" char sub_001CE0C0[];

void __cdecl sub_0031B500(void)
{
    DAT_0048EBB8.sub_0006F830((int)DAT_00439CDC, (int)DAT_00439CC4, (int)sub_001CE0C0, 0, 3, 3);
}
