// bin: xb
// va: 0x0031AD40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031AD40 (0x0031AD40, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00438458[];
extern "C" char DAT_0043846C[];
extern "C" Object DAT_0048E518;
extern "C" char sub_001C32E0[];

void __cdecl sub_0031AD40(void)
{
    DAT_0048E518.sub_0006F830((int)DAT_0043846C, (int)DAT_00438458, (int)sub_001C32E0, 0, 6, 6);
}
