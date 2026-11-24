// bin: xb
// va: 0x0031D1D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031D1D0 (0x0031D1D0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043FD64[];
extern "C" char DAT_0043FD7C[];
extern "C" Object DAT_0049032C;
extern "C" char sub_001FD3B0[];

void __cdecl sub_0031D1D0(void)
{
    DAT_0049032C.sub_0006F830((int)DAT_0043FD7C, (int)DAT_0043FD64, (int)sub_001FD3B0, 0, 4, 4);
}
