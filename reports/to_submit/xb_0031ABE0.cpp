// bin: xb
// va: 0x0031ABE0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031ABE0 (0x0031ABE0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_00437E2C[];
extern "C" char DAT_00437E40[];
extern "C" Object DAT_0048E3F8;
extern "C" char sub_001BF980[];

void __cdecl sub_0031ABE0(void)
{
    DAT_0048E3F8.sub_0006F740((int)DAT_00437E40, (int)DAT_00437E2C, (int)sub_001BF980, 0, 3, 3);
}
