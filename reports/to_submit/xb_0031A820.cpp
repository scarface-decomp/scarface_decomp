// bin: xb
// va: 0x0031A820
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A820 (0x0031A820, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004377DC[];
extern "C" char DAT_004377F4[];
extern "C" Object DAT_0048E05C;
extern "C" char sub_001BF000[];

void __cdecl sub_0031A820(void)
{
    DAT_0048E05C.sub_0006F830((int)DAT_004377F4, (int)DAT_004377DC, (int)sub_001BF000, 0, 3, 3);
}
