// bin: xb
// va: 0x00317BB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317BB0 (0x00317BB0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042F0DC[];
extern "C" char DAT_0042F0F0[];
extern "C" Object DAT_0048A710;
extern "C" char sub_0015D320[];

void __cdecl sub_00317BB0(void)
{
    DAT_0048A710.sub_0006F830((int)DAT_0042F0F0, (int)DAT_0042F0DC, (int)sub_0015D320, 0, 3, 3);
}
