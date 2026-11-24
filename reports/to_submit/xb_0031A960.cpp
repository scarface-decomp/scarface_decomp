// bin: xb
// va: 0x0031A960
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A960 (0x0031A960, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004379E0[];
extern "C" Object DAT_0048E1E8;
extern "C" char sub_001BF400[];

void __cdecl sub_0031A960(void)
{
    DAT_0048E1E8.sub_0006F830(0, (int)DAT_004379E0, (int)sub_001BF400, 0, 2, 2);
}
