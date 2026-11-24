// bin: xb
// va: 0x00312800
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312800 (0x00312800, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_0039F37C[];
extern "C" Object DAT_00473FA8;
extern "C" char sub_00028E50[];

void __cdecl sub_00312800(void)
{
    DAT_00473FA8.sub_000EB3A0(18, 22, 9, 60, 37, (int)DAT_0039F37C, (int)sub_00028E50, 32, 0, 1);
}
