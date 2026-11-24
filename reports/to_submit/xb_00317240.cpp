// bin: xb
// va: 0x00317240
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317240 (0x00317240, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0042AFD4[];
extern "C" char DAT_0042AFF0[];
extern "C" Object DAT_00489AF0;
extern "C" char sub_0011CB50[];

void __cdecl sub_00317240(void)
{
    DAT_00489AF0.sub_0006F740((int)DAT_0042AFF0, (int)DAT_0042AFD4, (int)sub_0011CB50, 0, 2, 2);
}
