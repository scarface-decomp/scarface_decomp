// bin: xb
// va: 0x0031EF50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031EF50 (0x0031EF50, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003D19B8[];
extern "C" Object DAT_00491540;
extern "C" char sub_00222300[];

void __cdecl sub_0031EF50(void)
{
    DAT_00491540.sub_000EB3A0(50, 36, 29, 83, 3, (int)DAT_003D19B8, (int)sub_00222300, 80, 0, 0);
}
