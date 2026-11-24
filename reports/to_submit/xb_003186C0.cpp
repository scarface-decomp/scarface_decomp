// bin: xb
// va: 0x003186C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003186C0 (0x003186C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042FE7C[];
extern "C" char DAT_0042FE8C[];
extern "C" Object DAT_0048B418;
extern "C" char sub_001782B0[];

void __cdecl sub_003186C0(void)
{
    DAT_0048B418.sub_0006F830((int)DAT_0042FE8C, (int)DAT_0042FE7C, (int)sub_001782B0, 0, 3, 3);
}
