// bin: xb
// va: 0x00317AF0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317AF0 (0x00317AF0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042F028[];
extern "C" char DAT_0042F03C[];
extern "C" Object DAT_0048A608;
extern "C" char sub_0015D110[];

void __cdecl sub_00317AF0(void)
{
    DAT_0048A608.sub_0006F830((int)DAT_0042F03C, (int)DAT_0042F028, (int)sub_0015D110, 0, 3, 3);
}
