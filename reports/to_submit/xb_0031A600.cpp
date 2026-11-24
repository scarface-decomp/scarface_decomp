// bin: xb
// va: 0x0031A600
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A600 (0x0031A600, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004375E8[];
extern "C" char DAT_004375FC[];
extern "C" Object DAT_0048DDC8;
extern "C" char sub_001BED20[];

void __cdecl sub_0031A600(void)
{
    DAT_0048DDC8.sub_0006F830((int)DAT_004375FC, (int)DAT_004375E8, (int)sub_001BED20, 0, 2, 2);
}
