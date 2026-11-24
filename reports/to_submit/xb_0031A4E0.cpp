// bin: xb
// va: 0x0031A4E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A4E0 (0x0031A4E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00437468[];
extern "C" char DAT_0043747C[];
extern "C" Object DAT_0048DC68;
extern "C" char sub_001BEB10[];

void __cdecl sub_0031A4E0(void)
{
    DAT_0048DC68.sub_0006F830((int)DAT_0043747C, (int)DAT_00437468, (int)sub_001BEB10, 0, 2, 2);
}
