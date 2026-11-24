// bin: xb
// va: 0x0031A4C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A4C0 (0x0031A4C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043744C[];
extern "C" char DAT_00437458[];
extern "C" Object DAT_0048DC3C;
extern "C" char sub_001BEB00[];

void __cdecl sub_0031A4C0(void)
{
    DAT_0048DC3C.sub_0006F830((int)DAT_00437458, (int)DAT_0043744C, (int)sub_001BEB00, 0, 2, 2);
}
