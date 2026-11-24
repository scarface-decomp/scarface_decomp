// bin: xb
// va: 0x00319B40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319B40 (0x00319B40, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00436448[];
extern "C" char DAT_0043645C[];
extern "C" Object DAT_0048D3FC;
extern "C" char sub_001BCE80[];

void __cdecl sub_00319B40(void)
{
    DAT_0048D3FC.sub_0006F830((int)DAT_0043645C, (int)DAT_00436448, (int)sub_001BCE80, 0, 2, 3);
}
