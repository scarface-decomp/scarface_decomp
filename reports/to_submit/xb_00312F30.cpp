// bin: xb
// va: 0x00312F30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312F30 (0x00312F30, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0041C35C[];
extern "C" Object DAT_00474A00;
extern "C" char sub_001284A0[];

void __cdecl sub_00312F30(void)
{
    DAT_00474A00.sub_0006F790(0, (int)DAT_0041C35C, (int)sub_001284A0, 0, 2, 2);
}
