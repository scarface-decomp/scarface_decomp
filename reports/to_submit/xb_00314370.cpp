// bin: xb
// va: 0x00314370
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314370 (0x00314370, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_00422234[];
extern "C" Object DAT_00480CBC;
extern "C" char sub_000771B0[];

void __cdecl sub_00314370(void)
{
    DAT_00480CBC.sub_0006F790(0, (int)DAT_00422234, (int)sub_000771B0, 0, 2, 2);
}
