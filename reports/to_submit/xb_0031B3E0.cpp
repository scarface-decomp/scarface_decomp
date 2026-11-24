// bin: xb
// va: 0x0031B3E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031B3E0 (0x0031B3E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00439C6C[];
extern "C" char DAT_00439C74[];
extern "C" Object DAT_0048EB08;
extern "C" char sub_001CDFE0[];

void __cdecl sub_0031B3E0(void)
{
    DAT_0048EB08.sub_0006F830((int)DAT_00439C74, (int)DAT_00439C6C, (int)sub_001CDFE0, 0, 3, 3);
}
