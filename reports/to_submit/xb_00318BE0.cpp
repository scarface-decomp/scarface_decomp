// bin: xb
// va: 0x00318BE0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318BE0 (0x00318BE0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00430430[];
extern "C" char DAT_00430448[];
extern "C" Object DAT_0048BB24;
extern "C" char sub_00178830[];

void __cdecl sub_00318BE0(void)
{
    DAT_0048BB24.sub_0006F830((int)DAT_00430448, (int)DAT_00430430, (int)sub_00178830, 0, 4, 4);
}
