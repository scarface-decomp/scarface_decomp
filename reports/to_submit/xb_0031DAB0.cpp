// bin: xb
// va: 0x0031DAB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031DAB0 (0x0031DAB0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00447A04[];
extern "C" char DAT_00447A10[];
extern "C" Object DAT_004904C0;
extern "C" char sub_00208B10[];

void __cdecl sub_0031DAB0(void)
{
    DAT_004904C0.sub_0006F830((int)DAT_00447A10, (int)DAT_00447A04, (int)sub_00208B10, 0, 2, 2);
}
