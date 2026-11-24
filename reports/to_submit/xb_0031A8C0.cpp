// bin: xb
// va: 0x0031A8C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A8C0 (0x0031A8C0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00437854[];
extern "C" Object DAT_0048E138;
extern "C" char sub_001BF120[];

void __cdecl sub_0031A8C0(void)
{
    DAT_0048E138.sub_0006F830(0, (int)DAT_00437854, (int)sub_001BF120, 0, 2, 2);
}
