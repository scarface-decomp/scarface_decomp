// bin: xb
// va: 0x0031BCE0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031BCE0 (0x0031BCE0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0043AC34[];
extern "C" char DAT_0043AC40[];
extern "C" Object DAT_0048EF7C;
extern "C" char sub_001D3460[];

void __cdecl sub_0031BCE0(void)
{
    DAT_0048EF7C.sub_0006F880((int)DAT_0043AC40, (int)DAT_0043AC34, (int)sub_001D3460, 0, 2, 2);
}
