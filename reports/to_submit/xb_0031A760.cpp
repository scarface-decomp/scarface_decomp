// bin: xb
// va: 0x0031A760
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A760 (0x0031A760, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0043773C[];
extern "C" char DAT_00437750[];
extern "C" Object DAT_0048DF54;
extern "C" char sub_001BEEC0[];

void __cdecl sub_0031A760(void)
{
    DAT_0048DF54.sub_0006F880((int)DAT_00437750, (int)DAT_0043773C, (int)sub_001BEEC0, 0, 2, 2);
}
