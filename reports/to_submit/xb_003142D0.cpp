// bin: xb
// va: 0x003142D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003142D0 (0x003142D0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004221D4[];
extern "C" Object DAT_00480BE0;
extern "C" char sub_00076FE0[];

void __cdecl sub_003142D0(void)
{
    DAT_00480BE0.sub_0006F830(0, (int)DAT_004221D4, (int)sub_00076FE0, 0, 2, 2);
}
