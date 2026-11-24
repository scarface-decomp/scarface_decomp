// bin: xb
// va: 0x003149A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003149A0 (0x003149A0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_004230C8[];
extern "C" Object DAT_004815AC;
extern "C" char sub_0008F1E0[];

void __cdecl sub_003149A0(void)
{
    DAT_004815AC.sub_0006F790(0, (int)DAT_004230C8, (int)sub_0008F1E0, 0, 2, 3);
}
