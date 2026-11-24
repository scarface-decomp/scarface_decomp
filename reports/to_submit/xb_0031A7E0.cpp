// bin: xb
// va: 0x0031A7E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A7E0 (0x0031A7E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_004377A4[];
extern "C" char DAT_004377B8[];
extern "C" Object DAT_0048E004;
extern "C" char sub_001BEF20[];

void __cdecl sub_0031A7E0(void)
{
    DAT_0048E004.sub_0006F740((int)DAT_004377B8, (int)DAT_004377A4, (int)sub_001BEF20, 0, 2, 2);
}
