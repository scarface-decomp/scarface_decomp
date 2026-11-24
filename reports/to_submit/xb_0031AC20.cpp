// bin: xb
// va: 0x0031AC20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031AC20 (0x0031AC20, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_00437E68[];
extern "C" char DAT_00437E84[];
extern "C" Object DAT_0048E450;
extern "C" char sub_001BFA80[];

void __cdecl sub_0031AC20(void)
{
    DAT_0048E450.sub_0006F740((int)DAT_00437E84, (int)DAT_00437E68, (int)sub_001BFA80, 0, 4, 4);
}
