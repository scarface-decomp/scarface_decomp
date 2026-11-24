// bin: xb
// va: 0x0031AB40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031AB40 (0x0031AB40, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00437D18[];
extern "C" char DAT_00437D20[];
extern "C" Object DAT_0048E374;
extern "C" char sub_001BF7F0[];

void __cdecl sub_0031AB40(void)
{
    DAT_0048E374.sub_0006F830((int)DAT_00437D20, (int)DAT_00437D18, (int)sub_001BF7F0, 0, 3, 3);
}
