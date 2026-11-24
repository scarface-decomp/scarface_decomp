// bin: xb
// va: 0x0031A940
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A940 (0x0031A940, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_004379C8[];
extern "C" Object DAT_0048E1BC;
extern "C" char sub_001BF370[];

void __cdecl sub_0031A940(void)
{
    DAT_0048E1BC.sub_0006F790(0, (int)DAT_004379C8, (int)sub_001BF370, 0, 2, 5);
}
