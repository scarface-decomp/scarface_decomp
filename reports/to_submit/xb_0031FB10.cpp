// bin: xb
// va: 0x0031FB10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031FB10 (0x0031FB10, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003D2368[];
extern "C" Object DAT_00491FE6;
extern "C" char sub_0022C7C0[];

void __cdecl sub_0031FB10(void)
{
    DAT_00491FE6.sub_000EB3A0(55, 40, 8, 87, 49, (int)DAT_003D2368, (int)sub_0022C7C0, 128, 0, 1);
}
