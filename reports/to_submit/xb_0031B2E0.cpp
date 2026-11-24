// bin: xb
// va: 0x0031B2E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031B2E0 (0x0031B2E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00438A90[];
extern "C" char DAT_00438AA4[];
extern "C" Object DAT_0048EA54;
extern "C" char sub_001C8840[];

void __cdecl sub_0031B2E0(void)
{
    DAT_0048EA54.sub_0006F830((int)DAT_00438AA4, (int)DAT_00438A90, (int)sub_001C8840, 0, 3, 3);
}
