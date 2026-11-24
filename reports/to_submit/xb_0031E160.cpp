// bin: xb
// va: 0x0031E160
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E160 (0x0031E160, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0044C4C4[];
extern "C" char DAT_0044C4D4[];
extern "C" Object DAT_00490738;
extern "C" char sub_002161C0[];

void __cdecl sub_0031E160(void)
{
    DAT_00490738.sub_0006F880((int)DAT_0044C4D4, (int)DAT_0044C4C4, (int)sub_002161C0, 0, 5, 5);
}
