// bin: xb
// va: 0x003173C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003173C0 (0x003173C0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042B1A4[];
extern "C" Object DAT_00489CD4;
extern "C" char sub_0011D130[];

void __cdecl sub_003173C0(void)
{
    DAT_00489CD4.sub_0006F830(0, (int)DAT_0042B1A4, (int)sub_0011D130, 0, 1, 1);
}
