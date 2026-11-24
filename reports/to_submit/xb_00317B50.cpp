// bin: xb
// va: 0x00317B50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317B50 (0x00317B50, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042F080[];
extern "C" char DAT_0042F098[];
extern "C" Object DAT_0048A68C;
extern "C" char sub_0015D220[];

void __cdecl sub_00317B50(void)
{
    DAT_0048A68C.sub_0006F830((int)DAT_0042F098, (int)DAT_0042F080, (int)sub_0015D220, 0, 7, 7);
}
