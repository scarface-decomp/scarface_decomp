// bin: xb
// va: 0x00317AD0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317AD0 (0x00317AD0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042F008[];
extern "C" char DAT_0042F01C[];
extern "C" Object DAT_0048A5DC;
extern "C" char sub_0015D0E0[];

void __cdecl sub_00317AD0(void)
{
    DAT_0048A5DC.sub_0006F830((int)DAT_0042F01C, (int)DAT_0042F008, (int)sub_0015D0E0, 0, 3, 3);
}
