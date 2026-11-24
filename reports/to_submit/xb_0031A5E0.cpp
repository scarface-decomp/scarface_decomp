// bin: xb
// va: 0x0031A5E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A5E0 (0x0031A5E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004375C8[];
extern "C" char DAT_004375D8[];
extern "C" Object DAT_0048DD9C;
extern "C" char sub_001BED00[];

void __cdecl sub_0031A5E0(void)
{
    DAT_0048DD9C.sub_0006F830((int)DAT_004375D8, (int)DAT_004375C8, (int)sub_001BED00, 0, 3, 3);
}
