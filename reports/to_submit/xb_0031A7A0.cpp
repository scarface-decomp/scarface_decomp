// bin: xb
// va: 0x0031A7A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A7A0 (0x0031A7A0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00437774[];
extern "C" char DAT_00437784[];
extern "C" Object DAT_0048DFAC;
extern "C" char sub_001BEEE0[];

void __cdecl sub_0031A7A0(void)
{
    DAT_0048DFAC.sub_0006F830((int)DAT_00437784, (int)DAT_00437774, (int)sub_001BEEE0, 0, 2, 2);
}
