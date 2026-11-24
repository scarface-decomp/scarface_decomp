// bin: xb
// va: 0x0031EFC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031EFC0 (0x0031EFC0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0044D700[];
extern "C" char DAT_0044D710[];
extern "C" Object DAT_004916C0;
extern "C" char sub_002225E0[];

void __cdecl sub_0031EFC0(void)
{
    DAT_004916C0.sub_0006F740((int)DAT_0044D710, (int)DAT_0044D700, (int)sub_002225E0, 0, 4, 4);
}
