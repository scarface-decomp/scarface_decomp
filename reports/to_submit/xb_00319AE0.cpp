// bin: xb
// va: 0x00319AE0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319AE0 (0x00319AE0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00436350[];
extern "C" char DAT_00436358[];
extern "C" Object DAT_0048D3A4;
extern "C" char sub_001BCD50[];

void __cdecl sub_00319AE0(void)
{
    DAT_0048D3A4.sub_0006F830((int)DAT_00436358, (int)DAT_00436350, (int)sub_001BCD50, 0, 3, 3);
}
