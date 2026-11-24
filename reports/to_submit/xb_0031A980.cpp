// bin: xb
// va: 0x0031A980
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A980 (0x0031A980, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004379FC[];
extern "C" Object DAT_0048E214;
extern "C" char sub_001BF420[];

void __cdecl sub_0031A980(void)
{
    DAT_0048E214.sub_0006F830(0, (int)DAT_004379FC, (int)sub_001BF420, 0, 2, 2);
}
