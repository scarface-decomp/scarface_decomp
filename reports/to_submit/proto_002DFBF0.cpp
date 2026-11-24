// bin: proto
// va: 0x002DFBF0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002DFBF0 (Proto 0x002DFBF0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_0037CF04[];
extern "C" Object DAT_0044149C;
extern "C" char sub_000167E0[];

void __cdecl sub_002DFBF0(void)
{
    DAT_0044149C.sub_000D8CC0(19, 22, 28, 57, 33, (int)DAT_0037CF04, (int)sub_000167E0, 509, 0, 0);
}
