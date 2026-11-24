// bin: xb
// va: 0x0031FAE0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031FAE0 (0x0031FAE0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003D22B8[];
extern "C" Object DAT_00491FDC;
extern "C" char sub_0022C170[];

void __cdecl sub_0031FAE0(void)
{
    DAT_00491FDC.sub_000EB3A0(5, 18, 4, 56, 56, (int)DAT_003D22B8, (int)sub_0022C170, 509, 3, 0);
}
