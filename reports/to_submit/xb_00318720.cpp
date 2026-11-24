// bin: xb
// va: 0x00318720
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318720 (0x00318720, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042FEE0[];
extern "C" char DAT_0042FEF4[];
extern "C" Object DAT_0048B49C;
extern "C" char sub_00178E60[];

void __cdecl sub_00318720(void)
{
    DAT_0048B49C.sub_0006F830((int)DAT_0042FEF4, (int)DAT_0042FEE0, (int)sub_00178E60, 0, 3, 4);
}
