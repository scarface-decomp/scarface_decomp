// bin: xb
// va: 0x00319860
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319860 (0x00319860, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00435F4C[];
extern "C" char DAT_00435F54[];
extern "C" Object DAT_0048D1C0;
extern "C" char sub_001BC860[];

void __cdecl sub_00319860(void)
{
    DAT_0048D1C0.sub_0006F830((int)DAT_00435F54, (int)DAT_00435F4C, (int)sub_001BC860, 0, 3, 3);
}
