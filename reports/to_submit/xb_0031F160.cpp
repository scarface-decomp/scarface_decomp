// bin: xb
// va: 0x0031F160
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F160 (0x0031F160, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F7E0(int, int, int, int, int, int);
};

extern "C" char DAT_0044D9A0[];
extern "C" Object DAT_004918D0;
extern "C" char sub_00222AC0[];

void __cdecl sub_0031F160(void)
{
    DAT_004918D0.sub_0006F7E0(0, (int)DAT_0044D9A0, (int)sub_00222AC0, 0, 1, 1);
}
