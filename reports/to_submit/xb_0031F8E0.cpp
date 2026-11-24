// bin: xb
// va: 0x0031F8E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F8E0 (0x0031F8E0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003D1C48[];
extern "C" Object DAT_00491EE4;
extern "C" char sub_00223CE0[];

void __cdecl sub_0031F8E0(void)
{
    DAT_00491EE4.sub_000EB3A0(45, 31, 19, 71, 12, (int)DAT_003D1C48, (int)sub_00223CE0, 80, 0, 0);
}
