// bin: xb
// va: 0x0031A6C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A6C0 (0x0031A6C0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_004376F0[];
extern "C" Object DAT_0048DEA4;
extern "C" char sub_001BEDF0[];

void __cdecl sub_0031A6C0(void)
{
    DAT_0048DEA4.sub_0006F880(0, (int)DAT_004376F0, (int)sub_001BEDF0, 0, 9, 9);
}
